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
* src/config/secure.h                                                        *
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
#ifndef _CONFIG_SECURE_H_
#define _CONFIG_SECURE_H_

/**
 * rAthena configuration file (http://rathena.org)
 * For detailed guidance on these check http://rathena.org/wiki/SRC/config/
 **/

/**
 * @INFO: This file holds optional security settings
 **/

/**
 * Optional NPC Dialog Timer
 * When enabled all npcs dialog will 'timeout' if user is on idle for longer than the amount of seconds allowed
 * - On 'timeout' the npc dialog window changes its next/menu to a 'close' button
 * @values
 * - ? : Desired idle time in seconds (e.g. 10)
 * - 0 : Disabled
 **/
#define SECURE_NPCTIMEOUT 0

/**
 * (Secure) Optional NPC Dialog Timer
 * @requirement : SECURE_NPCTIMEOUT must be enabled
 * Minimum Interval Between timeout checks in seconds
 * Default: 1s
 **/
#define SECURE_NPCTIMEOUT_INTERVAL 1

#endif // _CONFIG_SECURE_H_
