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
* src/login/ipban_txt.c                                                      *
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

#include "../common/cbasetypes.h"
#include "../common/strlib.h"
#include "login.h"
#include "ipban.h"
#include <stdlib.h>
#include <string.h>

void ipban_init(void)
{
}

void ipban_final(void)
{
}

bool ipban_check(uint32 ip)
{
	return false;
}

void ipban_log(uint32 ip)
{
}

bool ipban_config_read(const char* key, const char* value)
{
	// login server settings
	if( strcmpi(key, "ipban.enable") == 0 )
		login_config.ipban = (bool)config_switch(value);
	else
	if( strcmpi(key, "ipban.dynamic_pass_failure_ban") == 0 )
		login_config.dynamic_pass_failure_ban = (bool)config_switch(value);
	else
	if( strcmpi(key, "ipban.dynamic_pass_failure_ban_interval") == 0 )
		login_config.dynamic_pass_failure_ban_interval = atoi(value);
	else
	if( strcmpi(key, "ipban.dynamic_pass_failure_ban_limit") == 0 )
		login_config.dynamic_pass_failure_ban_limit = atoi(value);
	else
	if( strcmpi(key, "ipban.dynamic_pass_failure_ban_duration") == 0 )
		login_config.dynamic_pass_failure_ban_duration = atoi(value);
	else
		return false;

	return true;
}

