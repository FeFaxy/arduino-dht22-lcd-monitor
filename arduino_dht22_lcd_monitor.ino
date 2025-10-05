#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float tC = dht.readTemperature();
  float tF = dht.readTemperature(true); // Fahrenheit

  if (isnan(h) || isnan(tC)) return;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T:"); 
  lcd.print(tC,1); lcd.write((uint8_t)223); lcd.print("C ");
  lcd.print(tF,1); lcd.write((uint8_t)223); lcd.print("F");

  lcd.setCursor(0,1);
  lcd.print("H:"); lcd.print(h,1); lcd.print("%");

  delay(2000);
}
