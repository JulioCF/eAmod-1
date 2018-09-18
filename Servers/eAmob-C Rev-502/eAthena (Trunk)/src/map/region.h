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
* src/map/region.h                                                           *
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
#ifndef _REGION_H_
#define _REGION_H_

#include "../common/mmo.h"

#define REGION_NAME_LENGTH 48

struct region_data {
	int region_id;
	char name[REGION_NAME_LENGTH];
	int maps, users;
	int guild_id;

	int bonus_bexp, bonus_jexp, bonus_drop;
	struct script_code *script;
};

struct DBMap* region_get_db(void);
struct region_data* region_search(int region_id);
void region_set_guild(int region_id, int guild_id);

void do_init_region(void);
void do_final_region(void);

#endif /* _REGION_H_ */
