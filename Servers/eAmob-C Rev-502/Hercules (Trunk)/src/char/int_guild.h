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
* src/char/int_guild.h                                                       *
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

#ifndef _CHAR_INT_GUILD_H_
#define _CHAR_INT_GUILD_H_

enum {
	GS_BASIC = 0x0001,
	GS_MEMBER = 0x0002,
	GS_POSITION = 0x0004,
	GS_ALLIANCE = 0x0008,
	GS_EXPULSION = 0x0010,
	GS_SKILL = 0x0020,
	GS_EMBLEM = 0x0040,
	GS_CONNECT = 0x0080,
	GS_LEVEL = 0x0100,
	GS_MES = 0x0200,
	GS_MASK = 0x03FF,
	GS_BASIC_MASK = (GS_BASIC | GS_EMBLEM | GS_CONNECT | GS_LEVEL | GS_MES),
	GS_REMOVE = 0x8000,
};

struct guild;
struct guild_castle;

int inter_guild_parse_frommap(int fd);
int inter_guild_sql_init(void);
void inter_guild_sql_final(void);
int inter_guild_leave(int guild_id,int account_id,int char_id);
int mapif_parse_BreakGuild(int fd,int guild_id);
int inter_guild_broken(int guild_id);
int inter_guild_sex_changed(int guild_id,int account_id,int char_id, short gender);
int inter_guild_charname_changed(int guild_id,int account_id, int char_id, char *name);
int inter_guild_CharOnline(int char_id, int guild_id);
int inter_guild_CharOffline(int char_id, int guild_id);

#endif /* _CHAR_INT_GUILD_H_ */
