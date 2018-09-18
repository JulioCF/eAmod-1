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
* src/common/nullpo.c                                                        *
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

#include "nullpo.h"
#include "showmsg.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/// Checks for and reports NULL pointers.
/// Used by nullpo_ret* macros.
int nullpo_chk(const char* file, int line, const char* func, const void* target, const char* targetname)
{
	if( target )
	{
		return 0;
	}

	file =
		( file == NULL ) ? "??" : file;

	func =
		( func == NULL ) ? "unknown" :
		( func[0] == 0 ) ? "unknown" : func;

	ShowDebug("--- nullpo info --------------------------------------------\n");
	ShowDebug("%s:%d: target '%s' in func '%s'\n", file, line, targetname, func);
	ShowDebug("--- end nullpo info ----------------------------------------\n");
	return 1;
}
