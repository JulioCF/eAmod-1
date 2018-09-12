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

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "nullpo.h"
#include "../common/showmsg.h"
// #include "logs.h" // ?z????A??

static void nullpo_info_core(const char *file, int line, const char *func,
                             const char *fmt, va_list ap);

/*======================================
 * Null?`?F?b?N ?y?? ?????o??
 *--------------------------------------*/
int nullpo_chk_f(const char *file, int line, const char *func, const void *target,
                 const char *fmt, ...)
{
	va_list ap;

	if(target != NULL)
		return 0;

	va_start(ap, fmt);
	nullpo_info_core(file, line, func, fmt, ap);
	va_end(ap);
	return 1;
}

int nullpo_chk(const char *file, int line, const char *func, const void *target)
{
	if(target != NULL)
		return 0;

	nullpo_info_core(file, line, func, NULL, NULL);
	return 1;
}


/*======================================
 * nullpo?????o??(?O???do?????????b?p)
 *--------------------------------------*/
void nullpo_info_f(const char *file, int line, const char *func,
                   const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	nullpo_info_core(file, line, func, fmt, ap);
	va_end(ap);
}

void nullpo_info(const char *file, int line, const char *func)
{
	nullpo_info_core(file, line, func, NULL, NULL);
}


/*======================================
 * nullpo?????o??(Main)
 *--------------------------------------*/
static void nullpo_info_core(const char *file, int line, const char *func,
                             const char *fmt, va_list ap)
{
	if(file == NULL)
		file = "??";

	func =
	    func == NULL    ? (read_message("svn_version_mes3")):
	    func[0] == '\0' ? (read_message("svn_version_mes3")):
	    func;

	ShowMessage("--- nullpo info --------------------------------------------\n");
	ShowMessage(read_message("Source.common.nullpo_info_core"), file, line, func);
	if(fmt != NULL) {
		if(fmt[0] != '\0') {
			vprintf(fmt, ap);

			// ?O?????s???????m?F
			if(fmt[strlen(fmt)-1] != '\n')
				ShowMessage("\n");
		}
	}
	ShowMessage("--- end nullpo info ----------------------------------------\n");

	// ????????nullpo???O???t?@?C????????o??????
	// ????E??o?l??????v??A??????B
}
