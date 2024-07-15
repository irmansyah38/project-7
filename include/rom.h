#ifndef ROM_H
#define ROM_H

#include <EEPROM.h>
#include "telegram.h"

void inializationRom();
bool checkFromRom();
void saveTelegramToRom();
void endRom();

#endif