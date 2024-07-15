#ifndef ROM_H
#define ROM_H

#include <EEPROM.h>
#include "telegram.h"

void inializationRom();
bool checkFromRom();
void saveTelegramToRom(String token, String chatid);
void endRom();

#endif