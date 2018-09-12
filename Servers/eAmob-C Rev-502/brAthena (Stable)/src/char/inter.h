/****************************************************************************!
*                            _                                               *
*                           / \                         _                    *
*                   ___    / _ \   _ __ ___   ____  ___| |                   *
*                  / _ \  / /_\ \ | '_ ` _ \./  _ \/  _  |                   *
*                 |  __/ /  ___  \| | | | | |  (_) ) (_) |                   *
*                  \___|/__/   \__\_| |_| |_|\____/\_____/                   *
*                                                                            *
*                            eAmod Source File                               *
*                                                                            *
******************************************************************************
* src/char/inter.h                                                           *
******************************************************************************
* Copyright (c) eAmod Dev Team                                               *
* Copyright (c) rAthena Dev Team                                             *
* Copyright (c) brAthena Dev Team                                            *
* Copyright (c) Hercules Dev Team                                            *
* Copyright (c) 3CeAM Dev Team                                               *
* Copyright (c) Athena Dev Teams                                             *
*                                                                            *
* Licensed under GNU GPL                                                     *
* For more information read the LICENSE file in the root of the emulator     *
*****************************************************************************/

#ifndef _INTER_SQL_H_
#define _INTER_SQL_H_

struct accreg;
#include "../common/sql.h"

int inter_init_sql(const char* file);
void inter_final(void);
int inter_parse_frommap(int fd);
int inter_mapif_init(int fd);
int mapif_send_gmaccounts(void);
int mapif_disconnectplayer(int fd, int account_id, int char_id, int reason);

int inter_log(char* fmt,...);

#define inter_cfgName "conf/inter_brathena.conf"

extern unsigned int party_share_level;
extern unsigned int party_family_share_level;

extern Sql* sql_handle;
extern Sql* lsql_handle;

extern char tmp_db_name[32];

int inter_accreg_tosql(int account_id, int char_id, struct accreg* reg, int type);

uint64 inter_chk_lastuid(int8 flag, uint64 value);
#ifdef NSI_UNIQUE_ID
	#define updateLastUid(val_) inter_chk_lastuid(1, val_)
	#define dbUpdateUid(handler_)\
	{ \
		uint64 unique_id_ = inter_chk_lastuid(0, 0); \
		if(unique_id_ && SQL_ERROR == Sql_Query(handler_, "UPDATE `interreg` SET `value`='%"PRIu64"' WHERE `varname`='unique_id'", unique_id_)) \
				Sql_ShowDebug(handler_);\
	}
#else
	#define dbUpdateUid(handler_)
	#define updateLastUid(val_)
#endif
#endif /* _INTER_SQL_H_ */
