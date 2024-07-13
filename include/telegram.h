#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

extern String botToken;
extern String chatID;

void inializationTelegram();
void handleNewMessages(int numNewMessages);
#endif