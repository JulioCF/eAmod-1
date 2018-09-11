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
* src/map/channel.h                                                          *
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

#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "../common/mmo.h"
#include "../common/db.h"

#define MAX_USER_CHANNELS 4

enum {
	CHN_MAIN,
	CHN_VENDING,
	CHN_BATTLEGROUND,
	CHN_GAMEMASTER,
	CHN_USER,
	CHN_SERVER,
};

struct channel_data {
	unsigned int channel_id;
	char name[NAME_LENGTH];
	char pass[NAME_LENGTH];
	// Channel Settings
	short type; // Main, Vending, Battleground, Other
	unsigned long color;
	int op, users;
	// User Database
	DBMap* users_db;
};

extern struct channel_data *server_channel[];
extern const unsigned long channel_color[];

void channel_list(struct map_session_data *sd);
bool channel_create(struct map_session_data *sd, const char* name, const char* pass, short type, short color, int op);
void channel_join(struct map_session_data *sd, const char* name, const char* pass, bool invite);
void channel_leave(struct map_session_data *sd, const char* name, bool msg);
void channel_message(struct map_session_data *sd, const char* channel, const char* message);
int channel_invite_accept(struct map_session_data *sd);
void channel_invite_clear(struct map_session_data *sd);

void do_init_channel(void);
void do_final_channel(void);

#endif /* _CHANNEL_H_ */
