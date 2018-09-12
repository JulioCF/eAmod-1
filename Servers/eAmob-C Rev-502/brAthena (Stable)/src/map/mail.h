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
* src/map/mail.h                                                             *
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


#ifndef _MAIL_H_
#define _MAIL_H_

#include "../common/mmo.h"

void mail_clear(struct map_session_data *sd);
int mail_removeitem(struct map_session_data *sd, short flag);
int mail_removezeny(struct map_session_data *sd, short flag);
unsigned char mail_setitem(struct map_session_data *sd, int idx, int amount);
bool mail_setattachment(struct map_session_data *sd, struct mail_message *msg);
void mail_getattachment(struct map_session_data* sd, int zeny, struct item* item);
int mail_openmail(struct map_session_data *sd);
void mail_deliveryfail(struct map_session_data *sd, struct mail_message *msg);
bool mail_invalid_operation(struct map_session_data *sd);

#endif /* _MAIL_H_ */
