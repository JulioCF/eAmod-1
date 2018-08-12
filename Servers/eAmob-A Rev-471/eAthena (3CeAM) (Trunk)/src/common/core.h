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
******************************************************************************
* src/common/core.h                                                          *
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

#ifndef	_CORE_H_
#define	_CORE_H_

extern int arg_c;
extern char **arg_v;

/// @see E_CORE_ST
extern int runflag;
extern char *SERVER_NAME;
extern char SERVER_TYPE;

extern int parse_console(const char* buf);
extern const char *get_svn_revision(void);
extern int do_init(int,char**);
extern void set_server_type(void);
extern void do_abort(void);
extern void do_final(void);

/// The main loop continues until runflag is CORE_ST_STOP
enum E_CORE_ST
{
	CORE_ST_STOP = 0,
	CORE_ST_RUN,
	CORE_ST_LAST
};

/// Called when a terminate signal is received. (Ctrl+C pressed)
/// If NULL, runflag is set to CORE_ST_STOP instead.
extern void (*shutdown_callback)(void);

#endif /* _CORE_H_ */
