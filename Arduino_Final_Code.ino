#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensor1_pin = A0;
const int sensor2_pin = A1;
const int sensor3_pin = A2;
const int sensor4_pin = A3;

const int buzzerPin = 8;

const int pumpPin = 4;
const int solenoidPin = 3;

const int value_to_display_1 = 100;
const int value_to_display_2 = 300;
const int value_to_display_3 = 300;
const int value_to_display_4 = 300;

int sensor1Value = 0;
int sensor2Value = 0;
int sensor3Value = 0;
int sensor4Value = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();  
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  pinMode(pumpPin , OUTPUT);
  digitalWrite(pumpPin, LOW);
  pinMode(solenoidPin , OUTPUT);
  digitalWrite(solenoidPin, LOW);
}

void loop() {
  sensor1Value = analogRead(sensor1_pin);
  sensor2Value = analogRead(sensor2_pin);
  sensor3Value = analogRead(sensor3_pin);
  sensor4Value = analogRead(sensor4_pin);

  if(sensor4Value > value_to_display_4)
  {
    Serial.println("Water Level : 100 % ");
    lcd.setCursor(0,0);
    lcd.print("   WATER LEVEL  ");
    lcd.setCursor(0,1);
    lcd.print("      100 %     ");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(pumpPin , LOW);
    digitalWrite(solenoidPin , LOW);
  }

  else if(sensor3Value > value_to_display_3)
  {
    Serial.println("Water Level : 75 % ");
    lcd.setCursor(0,0);
    lcd.print("   WATER LEVEL ");
    lcd.setCursor(0,1);
    lcd.print("      75 %      ");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(solenoidPin , HIGH);
    delay(1000);
    digitalWrite(pumpPin , HIGH);
  }

else if(sensor2Value > value_to_display_2)
  {
    Serial.println("Water Level : 50 % ");
    lcd.setCursor(0,0);
    lcd.print("   WATER LEVEL ");
    lcd.setCursor(0,1);
    lcd.print("      50 %      ");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(solenoidPin , HIGH);
    delay(1000);
    digitalWrite(pumpPin , HIGH);
  }

else if(sensor1Value > value_to_display_1)
  {
    Serial.println("Water Level : 25 % ");
    lcd.setCursor(0,0);
    lcd.print("   WATER LEVEL ");
    lcd.setCursor(0,1);
    lcd.print("      25 %      ");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(solenoidPin , HIGH);
    delay(1000);
    digitalWrite(pumpPin , HIGH);
  }

else
  {
    Serial.println("Water Level : 0 % ");
    lcd.setCursor(0,0);
    lcd.print("   WATER LEVEL ");
    lcd.setCursor(0,1);
    lcd.print("      0 %       ");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(solenoidPin , HIGH);
    delay(1000);
    digitalWrite(pumpPin , HIGH);
  }

delay(1000);
}