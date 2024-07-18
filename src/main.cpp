#include <Arduino.h>
#include "wifi.h"
#include "website.h"
#include "display.h"

int conditionMain = 0;

void setup()
{
  Serial.begin(115200);
  inializationWifi();
  inializationWebsite();
  inializationLCD();
  inializationTelegram();

  if (isConnectedWifi())
  {
    conditionMain = 1;
  }

  if (checkFromRom())
  {
    if (checkTelegram(botToken))
    {
      conditionMain = 2;
    }
  }

  // put your setup code here, to run once:
}

void loop()
{
  switch (conditionMain)
  {
  case 0:
    display("sambungkan ke wifi esp32");
    executeWifi();
    if (isConnectedWifi())
    {
      conditionMain = 1;
    }
    break;
  case 1:
    display("Masuk ke website dengan url : " + ip);
    executeWebsite();
    if (isSubmited())
    {
      conditionMain = 2;
    }

    break;
  case 2:
    display("sudah terhubung telegram");
    executeTelegram();
    break;
  }
  // put your main code here, to run repeatedly:
}
