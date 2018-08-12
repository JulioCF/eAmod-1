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
* src/char_sql/int_mercenary.                                                *
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

#ifndef _INT_MERCENARY_SQL_H_
#define _INT_MERCENARY_SQL_H_

struct s_mercenary;

int inter_mercenary_sql_init(void);
void inter_mercenary_sql_final(void);
int inter_mercenary_parse_frommap(int fd);

// Mercenary Owner Database
bool mercenary_owner_fromsql(int char_id, struct mmo_charstatus *status);
bool mercenary_owner_tosql(int char_id, struct mmo_charstatus *status);
bool mercenary_owner_delete(int char_id);

bool mapif_mercenary_delete(int merc_id);

#endif /* _INT_MERCENARY_SQL_H_ */
