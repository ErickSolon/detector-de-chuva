#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define LED 5

DHT dht(DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    pinMode(LED, OUTPUT);
  
    lcd.init(); 
    lcd.backlight();
    dht.begin();
}

void loop()
{
  sensorTemperaturaUmidade();
}

void sensorTemperaturaUmidade() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if(umidade >= 70) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp.: " + String(temperatura) + String(" C"));
  lcd.setCursor(0, 1);
  lcd.print("Umidade: " + String(umidade) + String("%"));
  delay(3000); 
}
