#include "telegram.h"

String botToken;
String chatID;

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

const unsigned long BOT_MTBS = 1000;
unsigned long bot_lasttime;

void inializationTelegram()
{
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
}

void processMessage(String comannd)
{
  if (comannd == "/start")
  {
    String welcome = "Welcome\n";
    welcome += "Use the following commands to control your outputs.\n\n";
    welcome += "/led_on to turn GPIO ON \n";
    welcome += "/led_off to turn GPIO OFF \n";
    welcome += "/state to request current GPIO state \n";
    bot.sendMessage(chatID, welcome, "");
  }
}

void handleNewMessages(int numNewMessages)
{

  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++)
  {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != chatID)
    {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }

    // Print the received message
    String command = bot.messages[i].text;
    Serial.println(command);

    processMessage(command);
  }
}

bool checkTelegram(String token)
{
  bot.updateToken(token);
  if (bot.getMe())
  {
    return true;
  }
  else
  {
    return false;
  }
}

void executeTelegram()
{
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}
