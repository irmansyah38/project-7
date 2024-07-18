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

  if (isConnectedWifi())
  {
    conditionMain = 1;
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
    break;
  }
  // put your main code here, to run repeatedly:
}
