/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Arduino MKR1000
  to connect your project to Blynk.

  Note: This requires WiFi101 library
    from http://librarymanager/all#WiFi101

  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

int analogOutPin = 6;
int analogOutPin1 = 7;
int analogOutPin2 = 8;
int analogOutPin3 = 1;
int analogOutPin4 = 4;
int analogOutPin5 = 5; //port 1 
int analogOutPin6 = 0; //port 12 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9ad04efb8fc54a2fb008f0441035fc9b";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Industrial Robotics Lab";
char pass[] = "robotics";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

BLYNK_WRITE(V0) // V5 is the number of Virtual Pin  
{
//  int pinValue = param.asInt();
//  if (pinValue = 1)
  {
    Serial.println("Pin0");
analogWrite(analogOutPin, 100);
delay(1000);
Serial.println("Pin1");
analogWrite(analogOutPin1, 100);
delay(1000);
Serial.println("Pin2");
analogWrite(analogOutPin, 0);
analogWrite(analogOutPin2, 100);
delay(1000);
Serial.println("Pin3");
analogWrite(analogOutPin1, 0);
analogWrite(analogOutPin3, 100);
delay(1000);
Serial.println("Pin4");
analogWrite(analogOutPin2, 0);
analogWrite(analogOutPin4, 100);
delay(1000);
Serial.println("Pin5");
analogWrite(analogOutPin3, 0);
analogWrite(analogOutPin5, 100);
delay(1000);
Serial.println("Pin6");
analogWrite(analogOutPin4, 0);
analogWrite(analogOutPin6, 100);
delay(1000);
analogWrite(analogOutPin5, 0);
delay(1000);
analogWrite(analogOutPin6, 0);  }

}

BLYNK_WRITE(V1) // V5 is the number of Virtual Pin  
{
//  int pinValue_0 = param.asInt();
//  if (pinValue_0 = 1) 
{
  for (int i = 0; i <= 100; i++) {
analogWrite(analogOutPin, i);
delay(10);
}

int g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin, i);
if (i < 50 || i > 0) {
analogWrite(analogOutPin1, g);
g++;
}
delay(10);
}

for (int i = 50; i <= 100; i++) {
analogWrite(analogOutPin1, i);
delay(10);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin1, i);
if (i < 50 || i > 0) {
analogWrite(analogOutPin2, g);
g++;
}
delay(10);
}
for (int i = 50; i <= 100; i++) {
analogWrite(analogOutPin2, i);
delay(10);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin2, i);
if (i < 50 || i > 0) {
analogWrite(analogOutPin3, g);
g++;
}
delay(10);
} 
for (int i = 50; i <= 100; i++) {
analogWrite(analogOutPin3, i);
delay(10);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin3, i);
if (i < 50 || i > 0) {
analogWrite(analogOutPin4, g);
g++;
}
delay(10);
}
for (int i = 50; i <= 100; i++) {
analogWrite(analogOutPin4, i);
delay(10);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin4, i);
if (i < 50 || i > 0) {
analogWrite(analogOutPin5, g);
g++;
}
delay(5);
}
for (int i = 50; i <= 100; i++) {
analogWrite(analogOutPin5, i);
delay(5);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin5, i);
if (i < 50 || i > 0) {
analogWrite(analogOutPin6, g);
g++;
}
delay(5);
} 
for (int i = 0; i <= 100; i++) {
analogWrite(analogOutPin6, i);
delay(5);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin6, i);
delay(5);
}  
  }
}
BLYNK_WRITE(V2) // V5 is the number of Virtual Pin  
{
 Serial.println("Hello");
analogWrite(analogOutPin, 100);
delay(3000);
analogWrite(analogOutPin, 0);
delay(100);
Serial.println("Pin0 ready");
analogWrite(analogOutPin6, 100);
delay(3000);
analogWrite(analogOutPin6, 0);
delay(100);
Serial.println("Pin6 ready");
analogWrite(analogOutPin1, 100);
delay(3000);
analogWrite(analogOutPin1, 0);
delay(100);
Serial.println("Pin1 ready");
analogWrite(analogOutPin5, 100);
delay(3000);
analogWrite(analogOutPin5, 0);
delay(100);
Serial.println("Pin5 ready");

analogWrite(analogOutPin2, 100);
delay(3000);
analogWrite(analogOutPin2, 0);
delay(100);
Serial.println("Pin2 ready");
analogWrite(analogOutPin4, 100);
delay(3000);
analogWrite(analogOutPin4, 0);
delay(100);
Serial.println("Pin4 ready");
analogWrite(analogOutPin3, 100);
delay(3000);
analogWrite(analogOutPin3, 0);
delay(100);
Serial.println("Pin3 ready"); 
}
BLYNK_WRITE(V3) {
 Serial.println("Hello");
analogWrite(analogOutPin6, 80);
delay(500);
analogWrite(analogOutPin6, 0);
delay(100);
Serial.println("Pin0 ready");
analogWrite(analogOutPin5, 80);
delay(500);
analogWrite(analogOutPin5, 0);
delay(100);
Serial.println("Pin6 ready");
analogWrite(analogOutPin4, 80);
delay(500);
analogWrite(analogOutPin4, 0);
delay(100);
Serial.println("Pin1 ready");
analogWrite(analogOutPin3, 80);
delay(500);
analogWrite(analogOutPin3, 0);
delay(100);
Serial.println("Pin5 ready");

analogWrite(analogOutPin2, 80);
delay(500);
analogWrite(analogOutPin2, 0);
delay(100);
Serial.println("Pin2 ready");
analogWrite(analogOutPin1, 80);
delay(500);
analogWrite(analogOutPin1, 0);
delay(100);
Serial.println("Pin4 ready");
analogWrite(analogOutPin, 80);
delay(500);
analogWrite(analogOutPin, 0);
delay(100);
Serial.println("Pin3 ready"); 

}

BLYNK_WRITE(V4) {
 Serial.println("Hello");
analogWrite(analogOutPin6, 80);
delay(500);
analogWrite(analogOutPin6, 0);
delay(100);
Serial.println("Pin0 ready");
analogWrite(analogOutPin5, 80);
delay(500);
analogWrite(analogOutPin5, 0);
delay(100);
Serial.println("Pin6 ready");
analogWrite(analogOutPin4, 80);
delay(500);
analogWrite(analogOutPin4, 0);
delay(100);
Serial.println("Pin1 ready");
analogWrite(analogOutPin3, 80);
delay(500);
analogWrite(analogOutPin3, 0);
delay(100);
Serial.println("Pin5 ready");

analogWrite(analogOutPin2, 80);
delay(500);
analogWrite(analogOutPin2, 0);
delay(100);
Serial.println("Pin2 ready");
analogWrite(analogOutPin1, 80);
delay(500);
analogWrite(analogOutPin1, 0);
delay(100);
Serial.println("Pin4 ready");
analogWrite(analogOutPin, 80);
delay(500);
analogWrite(analogOutPin, 0);
delay(100);
Serial.println("Pin3 ready"); 

}

BLYNK_WRITE(V5) {
int i = 0;  
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin6, i);
analogWrite(analogOutPin, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin6, 80 - i);
analogWrite(analogOutPin, 80 - i);
analogWrite(analogOutPin1, i);
analogWrite(analogOutPin5, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin5, 80 - i);
analogWrite(analogOutPin1, 80 - i);
analogWrite(analogOutPin4, i);
analogWrite(analogOutPin2, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin4, 80 - i);
analogWrite(analogOutPin2, 80 - i);
analogWrite(analogOutPin3, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin3, 80 - i);
delay(15);
}
}

BLYNK_WRITE(V6) {
int i = 0;  
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin3, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin3, 80 - i);
analogWrite(analogOutPin2, i);
analogWrite(analogOutPin4, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin2, 80 - i);
analogWrite(analogOutPin4, 80 - i);
analogWrite(analogOutPin5, i);
analogWrite(analogOutPin1, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin5, 80 - i);
analogWrite(analogOutPin1, 80 - i);
analogWrite(analogOutPin6, i);
analogWrite(analogOutPin, i);
delay(15);
}
for (i = 30; i <= 80; i ++) {
analogWrite(analogOutPin6, 80 - i);
analogWrite(analogOutPin, 80 - i);
delay(15);
}
}

BLYNK_WRITE(V7) {
int i = 0;
for (i = 30; i<= 80; i++) {
  analogWrite(analogOutPin, i);
  delay(10);
}
for (i = 30; i<= 80; i++) {
  analogWrite(analogOutPin6, i);
  delay(10);
}
for (i = 30; i<= 80; i++) {
  analogWrite(analogOutPin1, i);
  delay(10);
}
for (i = 30; i<= 80; i++) {
  analogWrite(analogOutPin5, i);
  delay(10);
}
for (i = 30; i<= 80; i++) {
  analogWrite(analogOutPin2, i);
  delay(10);
}
for (i = 30; i<= 80; i++) {
  analogWrite(analogOutPin4, i);
  delay(10);
}
for (i = 30; i<= 80; i++) {
  analogWrite(analogOutPin3, i);
  delay(10);
}
}
void loop()
{
  Blynk.run();
}
