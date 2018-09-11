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
* src/map/irc-bot.h                                                          *
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


#ifndef _MAP_IRC_BOT_H_
#define _MAP_IRC_BOT_H_

#define IRC_NICK_LENGTH 40
#define IRC_IDENT_LENGTH 40
#define IRC_HOST_LENGTH 63
#define IRC_FUNC_LENGTH 30
#define IRC_MESSAGE_LENGTH 500

struct hChSysCh;

struct irc_func {
	char name[IRC_FUNC_LENGTH];
	void (*func)(int, char*, char*, char*, char*);
};

struct irc_bot_interface {
	int fd;
	bool isIn, isOn;
	int64 last_try;
	unsigned char fails;
	uint32 ip;
	unsigned short port;
	/* */
	struct hChSysCh *channel;
	/* */
	struct {
		struct irc_func **list;
		unsigned int size;
	} funcs;
	/* */
	void (*init) (bool minimal);
	void (*final) (void);
	/* */
	int (*parse) (int fd);
	void (*parse_sub) (int fd, char *str);
	void (*parse_source) (char *source, char *nick, char *ident, char *host);
	/* */
	struct irc_func* (*func_search) (char* function_name);
	/* */
	int (*connect_timer) (int tid, int64 tick, int id, intptr_t data);
	int (*identify_timer) (int tid, int64 tick, int id, intptr_t data);
	int (*join_timer) (int tid, int64 tick, int id, intptr_t data);
	/* */
	void (*send)(char *str);
	void (*relay) (char *name, const char *msg);
	/* */
	void (*pong) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*privmsg) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*userjoin) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*userleave) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*usernick) (int fd, char *cmd, char *source, char *target, char *msg);
};

struct irc_bot_interface *ircbot;

void ircbot_defaults(void);

#endif /* _MAP_IRC_BOT_H_ */
