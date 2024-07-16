#ifndef WIFI_H
#define WIFI_H

#include <WiFiManager.h>

extern String ip;

void inializationWifi();
void executeWifi();
bool isConnectedWifi();

#endif
