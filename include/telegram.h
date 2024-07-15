#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

extern String botToken;
extern String chatID;

void inializationTelegram();
bool checkTelegram(String token);
void executeTelegram();
#endif