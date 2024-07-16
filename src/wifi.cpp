#include "wifi.h"

WiFiManager wm;

String ip;

void inializationWifi()
{
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
                       // put your setup code here, to run once:
  wm.setConfigPortalBlocking(false);
  wm.setConfigPortalTimeout(60);
  // automatically connect using saved credentials if they exist
  // If connection fails it starts an access point with the specified name
  if (wm.autoConnect("AutoConnectAP"))
  {
    Serial.println("connected...yeey :)");
  }
  else
  {
    Serial.println("Configportal running");
  }
}

void executeWifi()
{
  wm.process();
  // put your main code here, to run repeatedly:
}

bool isConnectedWifi()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    ip = WiFi.localIP().toString();
    return true;
  }
  else
  {
    return false;
  }
}
