#include <LiquidCrystal.h>
int inputPin1 = 2;
volatile int score=0;
int i=5;
long start;
LiquidCrystal lcd(12,11,5,4,3,8);
void setup() {
  lcd.begin(16,2);
  pinMode(inputPin1,INPUT);
  attachInterrupt(digitalPinToInterrupt(inputPin1), press, FALLING);
  play();
  detachInterrupt(digitalPinToInterrupt(inputPin1));
}
void loop() {
  
}
void play()
{
  start = millis();
  while (i>=0)
  {
   if((millis()-start)>=1000)
    {
      lcd.setCursor(0,0);
      lcd.print("Time Remaining:");
      lcd.print(i--);
      start+=1000;
    } 
  }
}
void press()
{
 lcd.setCursor(0,7);
 score=score+1;
 lcd.print("Score: ");
 lcd.print(score); 
}

