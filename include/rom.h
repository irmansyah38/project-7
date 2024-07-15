#ifndef ROM_H
#define ROM_H

#include <EEPROM.h>
#include "telegram.h"

void inializationRom();
void checkFromRom();
void saveTelegramToRom();

#endif