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
* src/char/int_storage.h                                                     *
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

#ifndef _INT_STORAGE_H_
#define _INT_STORAGE_H_

struct storage_data;
struct guild_storage;

int inter_storage_init(void);
void inter_storage_final(void);
int inter_storage_save(void);
int inter_guild_storage_save(void);
int inter_storage_delete(int account_id);
int inter_guild_storage_delete(int guild_id);
int inter_storage_parse_frommap(int fd);

extern char storage_txt[1024];
extern char guild_storage_txt[1024];

//Exported for use in the TXT-SQL converter.
bool storage_fromstr(char* str, int* account_id, struct storage_data* p);
int guild_storage_fromstr(char *str,struct guild_storage *p);

bool storage_load(int account_id, struct storage_data* storage);
bool storage_save(int account_id, struct storage_data* storage);

#endif /* _INT_STORAGE_H_ */
