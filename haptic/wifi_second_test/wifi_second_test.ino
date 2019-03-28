
#include <Wire.h>


#include <SPI.h>
#include <WiFi101.h>

#include <Servo.h>
/*
#define SECRET_SSID "Juanes"
#define SECRET_PASS "juanes25"
*/
#define SECRET_SSID "SmartFactory"
#define SECRET_PASS "1qaz!QAZ"

char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(169,254,244,237/16);  // numeric IP for Google (no DNS)
//char server[] = "www.google.com";    // name address for Google (using DNS)

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;







/*Servomotors
*/

int myData;
int analogOutPin = 6;
int analogOutPin1 = 7;
int analogOutPin2 = 8;
int analogOutPin3 = 9;
int analogOutPin4 = 10;
int analogOutPin5 = 11;
int analogOutPin6 = 12;

char buf[1024];


void setup() {

  pinMode(analogOutPin, OUTPUT);
  pinMode(analogOutPin1, OUTPUT);
  pinMode(analogOutPin2, OUTPUT);
  pinMode(analogOutPin3, OUTPUT);
  pinMode(analogOutPin4, OUTPUT);
  pinMode(analogOutPin5, OUTPUT);
  pinMode(analogOutPin6, OUTPUT);
  
  Serial.begin(115200);

  /*

  // wait for serial port to open on native usb devices
  while (!Serial) {
    delay(1);
  }
  */


    // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }
  
  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  
  
  Serial.println("Connected to wifi");
  printWiFiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 8080)) {
    Serial.println("connected to server");
    client.println("values");
  }

  
  
  Serial.println("Adafruit VL6180x test!");
  if (! vl.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
  Serial.println("Sensor found!");


    servo1.attach(2);
    servo2.attach(3);
  }

void loop() {
  if (Serial.available() > 0) {

    myData = Serial.read();

    if (myData == '1') {  //pattern 5

      Serial.println(myData);
  // change the analog out value:
  
  for (int i = 160; i <= 230; i++) {
    analogWrite(analogOutPin, i);
    delay(10);
  }
  
  int g = 0;
  for (int i = 230; i >= 0; i--) {
    analogWrite(analogOutPin, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin1, g);
      g++;
    }
 delay(10);
 }

   for (int i = 160; i <= 230; i++) {
    analogWrite(analogOutPin1, i);
    delay(10);
  }
  
  g = 0;
  for (int i = 230; i >= 0; i--) {
    analogWrite(analogOutPin1, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin2, g);
      g++;
    }
 delay(10);
 }
   for (int i = 160; i <= 230; i++) {
    analogWrite(analogOutPin2, i);
    delay(10);
  }
  
 g = 0;
  for (int i = 230; i >= 0; i--) {
    analogWrite(analogOutPin2, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin3, g);
      g++;
    }
 delay(10);
 } 
    for (int i = 160; i <= 230; i++) {
    analogWrite(analogOutPin3, i*0.6);
    delay(10);
  }
  
g = 0;
  for (int i = 230; i >= 0; i--) {
    analogWrite(analogOutPin3, i*0.6);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin4, g);
      g++;
    }
 delay(10);
 }
  for (int i = 160; i <= 230; i++) {
    analogWrite(analogOutPin4, i);
    delay(10);
  }
  
  g = 0;
  for (int i = 230; i >= 0; i--) {
    analogWrite(analogOutPin4, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin5, g);
      g++;
    }
 delay(10);
 }
   for (int i = 160; i <= 230; i++) {
    analogWrite(analogOutPin5, i);
    delay(10);
  }
  
 g = 0;
  for (int i = 230; i >= 0; i--) {
    analogWrite(analogOutPin5, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin6, g);
      g++;
    }
    delay(10);
  } 
    for (int i = 160; i <= 230; i++) {
    analogWrite(analogOutPin6, i*0.6);
    delay(10);
  }
  
g = 0;
  for (int i = 230; i >= 0; i--) {
    analogWrite(analogOutPin6, i*0.6);
  }

//    if (i < 160 || i > 0) {
//      analogWrite(analogOutPin4, g);
//      g++;
//    }
 delay(10);
 }
 

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
