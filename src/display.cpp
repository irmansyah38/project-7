#include "display.h"

int displayLength = 16; // 16 characters per line

LiquidCrystal_I2C lcd(0x27, displayLength, 2);

int start = 0;
unsigned long previousMillis = 0;
const long interval = 350; // Interval at which to scroll the text
String lastSentance;

bool isSentanceSame(String sentance)
{
  if (sentance == lastSentance)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void deleteDisplayLine(int row)
{
  lcd.setCursor(0, row);
  lcd.print("                ");
}

void display(String sentance)
{
  int textLength = sentance.length();

  if (textLength <= 16)
  {

    if (isSentanceSame(sentance))
    {
      return;
    }
    else
    {
      deleteDisplayLine(0);
      lcd.setCursor(0, 0);
      lcd.print(sentance);
    }
  }
  else
  {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;

      // Clear the display
      deleteDisplayLine(0);

      // Display the part of the text that fits on the screen
      lcd.setCursor(0, 0);
      lcd.print(sentance.substring(start, start + displayLength));

      // Move the starting point
      start++;

      // Reset start position if it reaches the end of the text
      if (start > textLength)
      {
        start = 0;
      }
    }
  }
}

void inializationLCD()
{
  lcd.init();
  lcd.backlight();
}