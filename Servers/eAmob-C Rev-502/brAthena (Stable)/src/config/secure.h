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
 * Tempo de habilitação no diálogo para npcs.
 * Quando habilitado, todos os diálogos com npcs são desabilitados conforme número de segundos.
 * - ? : Tempo em segundos (ex: 10)
 * - 0 : Disabilitado
 **/
#define SECURE_NPCTIMEOUT 0

/**
 * Tempo de intervalo no diálogo para npcs.
 * Default: 1s
 **/
#define SECURE_NPCTIMEOUT_INTERVAL 1

#endif // _CONFIG_SECURE_H_
