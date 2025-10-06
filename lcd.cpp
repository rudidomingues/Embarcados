#include <LiquidCrystal.h>

// Configura pinos RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Ola, IFSC!");
  delay(2000);
  lcd.clear();
  lcd.print("Sistemas");
  lcd.setCursor(0, 1);
  lcd.print("Embarcados 🚀");
}

void loop() {
  // Alternar mensagens
  delay(3000);
  lcd.clear();
  lcd.print("LCD 16x2 ativo!");
  delay(3000);
  lcd.clear();
  lcd.print("Arduino SLO 💚");
}
