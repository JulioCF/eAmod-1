/****************************************************************************!
*                            _                                               *
*                           / \                         _                    *
*                   ___    / _ \   _ __ ___   ____  ___| |                   *
*                  / _ \  / /_\ \ | '_ ` _ \./  _ \/  _  |                   *
*                 |  __/ /  ___  \| | | | | |  (_) ) (_) |                   *
*                  \___|/__/   \__\_| |_| |_|\____/\_____/                   *
*                                                                            *
*                               eAmod Script                                 *
*                                                                            *
* \file src/plugins/@lootalot                                                *
*                                                                            *
* Autoloots item in x by x Range.                                            *
* A Plug-In that allows the player to collect a number of items around.      *
* \author shellTeMP                                                          *
* \date 07/12/2018                                                           *
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common/HPMi.h"
#include "common/mmo.h"
#include "common/socket.h"
#include "common/malloc.h"
#include "common/nullpo.h"
#include "common/mapindex.h"
#include "common/strlib.h"
#include "common/utils.h"
#include "common/cbasetypes.h"
#include "common/timer.h"
#include "common/showmsg.h"
#include "common/conf.h"
#include "common/db.h"
#include "common/sql.h"

#include "map/atcommand.h"
#include "map/battle.h"
#include "map/clif.h"
#include "map/map.h"
#include "map/pc.h"
#include "map/skill.h"
#include "map/itemdb.h"

#include "common/HPMDataCheck.h"

HPExport struct hplugin_info pinfo = {
	"@lootalot",		// Plugin name
	SERVER_TYPE_MAP,	// Which server types this plugin works with?
	"1.0",				// Plugin version
	HPM_VERSION,		// HPM Version (don't change, macro is automatically updated)
};

int lootalot_range = 3;		//x BY x Range

struct area_p_data {
	bool lootalot;
	bool in_process;
};

struct area_p_data* adb_search(struct map_session_data* sd){
	struct area_p_data *data;
	if( !(data = getFromMSD(sd,0)) ) {
		CREATE(data,struct area_p_data,1);
		addToMSD(sd,data,0,true);
	}
	return data;
}

/*==========================================
 * @lootalot
 *------------------------------------------*/
ACMD(lootalot) {
	struct area_p_data *data;
	data = adb_search(sd);
	if (data->lootalot) {
		data->lootalot = false;
		clif->message(fd, "Loot a Lot is now off.");
		return true;
	}
	data->lootalot = true;
	clif->message(fd, "Loot a Lot is now on.");
	
	return true;
}


int lootalot_item(struct map_session_data *sd,struct flooritem_data *fitem){
	struct area_p_data *data;
	data = adb_search(sd);
	if (data->lootalot && data->in_process==false){
		data->in_process = true;
		map->foreachinrange(skill->greed, &fitem->bl, lootalot_range, BL_ITEM, &sd->bl);
		hookStop();
		data->in_process = false;
		return 1;
	}
	return 1;
}

void lootalot_range_setting(const char *val) {
	int value = atoi(val);
	if (value < 1 || value > 10){ ShowError("'lootalot_range' is set to %d,(Min:1,Max:10)", value); return; }	//1 to 9 Range.
	lootalot_range = value;
	ShowDebug("lootalot_Range set to %d",lootalot_range);
}

/* run when server starts */
HPExport void plugin_init (void) {
    addAtcommand("lootalot",lootalot);
	addHookPre("pc->takeitem",lootalot_item);
}

HPExport void server_online (void) {
	ShowInfo ("'%s' Plugin by Dastgir/Hercules. Version '%s'\n",pinfo.name,pinfo.version);
}

HPExport void server_preinit (void) {
	addBattleConf("lootalot_range",lootalot_range_setting);
}
