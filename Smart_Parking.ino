/*                      JANUARY 2020 TALPAY
                          SMART PARKING
*******************************************************************
  LINK PINS:
  1. TCRT5000 2 NUMBERED DİJİTAL INPUT
  2. TCRT5000 3 NUMBERED DİJİTAL INPUT
  3. TCRT5000 4 NUMBERED DİJİTAL INPUT
  4. TCRT5000 5 NUMBERED DİJİTAL INPUT
  5. TCRT5000 9 NUMBERED DİJİTAL INPUT
  6. TCRT5000 7 NUMBERED DİJİTAL INPUT
  1. HC-SR04 TRİG PİNİ 8 NUMBERED DİJİTAL INPUT
  1. HC-SR04 ECHO PİNİ 11 NUMBERED DİJİTAL INPUT
  2. HC-SR04 TRİG PİNİ 12 NUMBERED DİJİTAL INPUT
  2. HC-SR04 ECHO PİNİ 13 NUMBERED DİJİTAL INPUT
  İ2C SDA OUTPUT SDA INPUT
  İ2C SCL OUTPUT SCL INPUT

*******************************************************************
  REQUIRED LIBRARIES:
  https://drive.google.com/drive/folders/1lbWke6nUA_uwdeEAiIYWk615UTyRzZgS
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define trigPin 8
#define echoPin 11
#define trigPin1 12
#define echoPin1 13

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servos;
Servo servot;

void setup() {
  Serial.begin(9600);
  lcd.begin();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  servos.attach(10);
  servot.attach(6);
}

void loop() {
  /************************************ÖLÇÜMLERİN YAPILMASI*************************************************************/
  int sensorValue = digitalRead(2);
  int sensorValue1 = digitalRead(3);
  int sensorValue2 = digitalRead(4);
  int sensorValue3 = digitalRead(5);
  int sensorValue4 = digitalRead(9);
  int sensorValue5 = digitalRead(7);

  long sure, mesafe;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure / 2) / 29.1;

  long sure1, mesafe1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  sure1 = pulseIn(echoPin1, HIGH);
  mesafe1 = (sure1 / 2) / 29.1;

  /************************************ÖLÇÜMLERİN SERİ PORTA YAZILMASI*************************************************************/
  Serial.print("sensor1=");
  Serial.println(sensorValue);
  Serial.print("sensor2=");
  Serial.println(sensorValue1);
  Serial.print("sensor3=");
  Serial.println(sensorValue2);
  Serial.print("sensor4=");
  Serial.println(sensorValue3);
  Serial.print("sensor5=");
  Serial.println(sensorValue4);
  Serial.print("sensor6=");
  Serial.println(sensorValue5);
  Serial.print("mesafe1=");
  Serial.println(mesafe);
  Serial.print("mesafe2=");
  Serial.println(mesafe1);
  Serial.println("  ");

  /***********************************SERVO MOTOR KONTROLÜ*************************************************************/
  if (mesafe < 5) {
    servos.write(0);
  }

  if (mesafe >= 5) {
    servos.write(90);
  }

  if (mesafe1 < 5) {
    servot.write(90);
  }

  if (mesafe1 >= 5) {
    servot.write(0);
  }

  /********************************************************************1.KISIM*************************************************************/
  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    servos.write(90);
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  D  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  D  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  D  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  D  B  B");
  }

  /********************************************************************2.KISIM*************************************************************/
  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  B  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  B  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  B  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  D  B  B  B");
  }

  /********************************************************************3.KISIM*************************************************************/
  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  D  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  D  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  D  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  D  B  B");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  B  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  B  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  B  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  D  B  B  B  B");
  }

  /********************************************************************4.KISIM*************************************************************/
  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  D  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  D  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  D  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  D  B  B");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  B  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  B  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  B  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  D  B  B  B");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  D  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  D  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  D  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  D  B  B");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  B  D  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  B  D  B");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  B  B  D");
  }

  if (sensorValue == 0 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("D  B  B  B  B  B");
  }

  /********************************************************************5.KISIM*************************************************************/
  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  D  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  D  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  D  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  D  B  B");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  B  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  B  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  B  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  D  B  B  B");
  }


  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  D  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  D  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  D  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  D  B  B");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  B  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  B  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  B  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 0 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  D  B  B  B  B");
  }


  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  D  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  D  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  D  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  D  B  B");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  B  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  B  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  B  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 0 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  D  B  B  B");
  }


  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 0) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  D  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  D  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  D  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 0 and sensorValue4 == 1 and sensorValue5 == 1) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  D  B  B");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  B  D  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 0 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  B  D  B");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 0 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  B  B  D");
  }

  if (sensorValue == 1 and sensorValue1 == 1 and sensorValue2 == 1 and sensorValue3 == 1 and sensorValue4 == 1 and sensorValue5 == 1 ) {
    lcd.clear();
    lcd.print("1  2  3  4  5  6");
    lcd.setCursor(0, 1);
    lcd.print("B  B  B  B  B  B");
  }

  delay(500);
}
