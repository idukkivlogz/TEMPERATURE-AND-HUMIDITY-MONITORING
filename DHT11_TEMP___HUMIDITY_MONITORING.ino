#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define DHT11
#define DHTPIN 2         // Pin where the DHT11 is connected
#define DHTTYPE DHT11    // Sensor type

DHT dht(DHTPIN, DHTTYPE);

// Set up the LCD: I2C address 0x27 is most common. Try 0x3F if 0x27 doesn’t work
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the backlight
  dht.begin();         // Start the DHT sensor
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  // Check if readings are valid
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor error    ");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");

  delay(2000); // Wait 2 seconds before next update
}
e
