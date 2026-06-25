#define BLYNK_TEMPLATE_ID   "TMPL3J_xrfAVf"
#define BLYNK_TEMPLATE_NAME "AQUALEAF"
#define BLYNK_DEVICE_NAME   "AQUALEAF"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 26
#define DHTTYPE DHT11
#define RELAY_PIN 27
#define RAIN_PIN 25
#define SOIL_PIN 34

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

int pumpStatus = 0;
int manualPumpControl = 0;

BlynkTimer timer;

void sendSensorData() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(SOIL_PIN);
  int rain = digitalRead(RAIN_PIN);

  int soilPercent = map(soil, 0, 4095, 100, 0);

  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
  Blynk.virtualWrite(V2, soilPercent);
  Blynk.virtualWrite(V3, rain);
  Blynk.virtualWrite(V12, manualPumpControl);

  float soilPH = random(55, 75) / 10.0;
  String nutrition = (soilPH < 6.0) ? "Add Lime" : "Balanced";
  String growth = (temp > 28) ? "Fast Growth" : "Normal Growth";
  String compost = (soilPercent < 30) ? "Add Compost" : "No Compost";

  Blynk.virtualWrite(V4, soilPH);
  Blynk.virtualWrite(V5, nutrition);
  Blynk.virtualWrite(V6, growth);
  Blynk.virtualWrite(V7, compost);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temp); lcd.print(" H:"); lcd.print(hum);
  lcd.setCursor(0, 1);
  lcd.print("Soil:"); lcd.print(soilPercent); lcd.print("%");
}

void controlPump() {
  int soil = analogRead(SOIL_PIN);
  int soilPercent = map(soil, 0, 4095, 100, 0);
  if (manualPumpControl == 1) {
    digitalWrite(RELAY_PIN, LOW);
    pumpStatus = 1;
  } else {
    if (soilPercent < 30) {
      digitalWrite(RELAY_PIN, LOW);
      pumpStatus = 1;
    } else if (soilPercent > 75) {
      digitalWrite(RELAY_PIN, HIGH);
      pumpStatus = 0;
    }
  }
}

BLYNK_WRITE(V12) {
  manualPumpControl = param.asInt();
  controlPump();
}

BLYNK_CONNECTED() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Blynk Ready ✅");
  delay(1500);
}

void setup() {
  Serial.begin(115200);
  Wire.begin(33, 32);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  pinMode(RAIN_PIN, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  lcd.setCursor(0, 1);
  lcd.print("Blynk Connecting");
  timer.setInterval(2000L, sendSensorData);
  timer.setInterval(5000L, controlPump);
}

void loop() {
  Blynk.run();
  timer.run();
}