#include <LiquidCrystal.h>
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
int relay = 8;
int buzzer = 7;
char data;
void setup () {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode (relay, OUTPUT);
  pinMode (buzzer, OUTPUT);
}
void loop () {
  if (Serial.available() > 0) {
    data = Serial.read();
    if (data == 'A') {
      digitalWrite (relay, HIGH);
      digitalWrite (buzzer, HIGH);
      Serial.println("Bulb is ON");
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print ("ON");
      delay (1000);
    }
    if (data == 'B') {
      digitalWrite (relay, LOW);
      digitalWrite (buzzer, LOW);
      Serial.println("Bulb is OFF");
      lcd.clear();
      lcd.setCursor(8, 1);
      lcd.print ("OFF");
      delay (1000);
    }
  }
}
