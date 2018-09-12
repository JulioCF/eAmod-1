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
* src/map/vending.h                                                          *
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

#ifndef	_VENDING_H_
#define	_VENDING_H_

#include "../common/cbasetypes.h"
//#include "map.h"
struct map_session_data;
struct s_search_store_search;

struct s_vending {
	short index;
	short amount;
	unsigned int value;
};

void vending_closevending(struct map_session_data* sd);
void vending_openvending(struct map_session_data* sd, const char* message, const uint8* data, int count);
void vending_vendinglistreq(struct map_session_data* sd, int id);
void vending_purchasereq(struct map_session_data* sd, int aid, int uid, const uint8* data, int count);
bool vending_search(struct map_session_data* sd, unsigned short nameid);
bool vending_searchall(struct map_session_data* sd, const struct s_search_store_search* s);

#endif /* _VENDING_H_ */
