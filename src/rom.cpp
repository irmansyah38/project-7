#include "rom.h"

#define EEPROM_SIZE 512
#define addressBotToken 1
#define addressChatID 2

void inializationRom()
{
  EEPROM.begin(EEPROM_SIZE);
}

bool checkFromRom()
{
  String token;
  EEPROM.get(addressBotToken, token);

  if (token.length() >= 127)
  {
    return false;
  }
  else
  {
    botToken = token;
    EEPROM.get(addressChatID, chatID);
    return true;
  }
}

void saveTelegramToRom(String token, String chatid)
{
  EEPROM.put(addressBotToken, token);
  EEPROM.put(addressChatID, chatid);
  EEPROM.commit();
}

void endRom()
{
  EEPROM.end();
}