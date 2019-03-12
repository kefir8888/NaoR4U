/*
  WiFi Web Server LED Blink

  A simple web server that lets you blink an LED via the web.
  This sketch will create a new access point (with no password).
  It will then launch a new server and print out the IP address
  to the Serial monitor. From there, you can open that address in a web browser
  to turn on and off the LED on pin 13.

  If the IP address of your shield is yourAddress:
    http://yourAddress/H turns the LED on
    http://yourAddress/L turns it off

  created 25 Nov 2012
  by Tom Igoe
  adapted to WiFi AP by Adafruit
 */

#include <SPI.h>
#include <WiFi101.h>

int led =  LED_BUILTIN;
int myData;
int analogOutPin = 6;
int analogOutPin1 = 7;
int analogOutPin2 = 8;
int analogOutPin3 = 9;
int analogOutPin4 = 10;
int analogOutPin5 = 11;
int analogOutPin6 = 12;

char buf[1024];

char ssid[] = "test"; // created AP name
char pass[] = "test";      // AP password (needed only for WEP, must be exactly 10 or 26 characters in length)
int keyIndex = 0;                // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
//  Serial.begin(9600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }

  Serial.println("Access Point Web Server");

  pinMode(led, OUTPUT);      // set the LED pin mode

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // by default the local IP address of will be 192.168.1.1
  // you can override it with the following:
  // WiFi.config(IPAddress(10, 0, 0, 1));

  // print the network name (SSID);
  Serial.print("Creating access point named: ");
  Serial.println(ssid);

  // Create open network. Change this line if you want to create an WEP network:
  status = WiFi.beginAP(ssid);
  if (status != WL_AP_LISTENING) {
    Serial.println("Creating access point failed");
    // don't continue
    while (true);
  }

  // wait 10 seconds for connection:
  delay(10000);

  // start the web server on port 80
  server.begin();

  // you're connected now, so print out the status
  printWifiStatus();


  pinMode(analogOutPin, OUTPUT);
  pinMode(analogOutPin1, OUTPUT);
  pinMode(analogOutPin2, OUTPUT);
  pinMode(analogOutPin3, OUTPUT);
  pinMode(analogOutPin4, OUTPUT);
  pinMode(analogOutPin5, OUTPUT);
  pinMode(analogOutPin6, OUTPUT);
  
  Serial.begin(115200); 
  
//  while (!Serial) {
//    delay(1);
//  }
//  Serial.println("Adafruit VL6180x test!");
//  if (! vl.begin()) {
//    Serial.println("Failed to find sensor");
//    while (1);
//  }
//  Serial.println("Sensor found!");
//
//
//    servo1.attach(2);
//    servo2.attach(3);
//}
}


//void loop() {
//  if (Serial.available() > 0) {
//
//    myData = Serial.read();f
//
//    if (myData == '1') {  //pattern 5
//
//      Serial.println(myData);
//  // change the analog out value:
//  
//  for (int i = 160; i <= 230; i++) {
//    analogWrite(analogOutPin, i);
//    delay(10);
//  }
//  
//  int g = 0;
//  for (int i = 230; i >= 0; i--) {
//    analogWrite(analogOutPin, i);
//    if (i < 160 || i > 0) {
//      analogWrite(analogOutPin1, g);
//      g++;
//    }
// delay(10);
// }
//
//   for (int i = 160; i <= 230; i++) {
//    analogWrite(analogOutPin1, i);
//    delay(10);
//  }
//  
//  g = 0;
//  for (int i = 230; i >= 0; i--) {
//    analogWrite(analogOutPin1, i);
//    if (i < 160 || i > 0) {
//      analogWrite(analogOutPin2, g);
//      g++;
//    }
// delay(10);
// }
//   for (int i = 160; i <= 230; i++) {
//    analogWrite(analogOutPin2, i);
//    delay(10);
//  }
//  
// g = 0;
//  for (int i = 230; i >= 0; i--) {
//    analogWrite(analogOutPin2, i);
//    if (i < 160 || i > 0) {
//      analogWrite(analogOutPin3, g);
//      g++;
//    }
// delay(10);
// } 
//    for (int i = 160; i <= 230; i++) {
//    analogWrite(analogOutPin3, i*0.6);
//    delay(10);
//  }
//  
//g = 0;
//  for (int i = 230; i >= 0; i--) {
//    analogWrite(analogOutPin3, i*0.6);
//    if (i < 160 || i > 0) {
//      analogWrite(analogOutPin4, g);
//      g++;
//    }
// delay(10);
// }
//  for (int i = 160; i <= 230; i++) {
//    analogWrite(analogOutPin4, i);
//    delay(10);
//  }
//  
//  g = 0;
//  for (int i = 230; i >= 0; i--) {
//    analogWrite(analogOutPin4, i);
//    if (i < 160 || i > 0) {
//      analogWrite(analogOutPin5, g);
//      g++;
//    }
// delay(10);
// }
//   for (int i = 160; i <= 230; i++) {
//    analogWrite(analogOutPin5, i);
//    delay(10);
//  }
//  
// g = 0;
//  for (int i = 230; i >= 0; i--) {
//    analogWrite(analogOutPin5, i);
//    if (i < 160 || i > 0) {
//      analogWrite(analogOutPin6, g);
//      g++;
//    }
//    delay(10);
//  } 
//    for (int i = 160; i <= 230; i++) {
//    analogWrite(analogOutPin6, i*0.6);
//    delay(10);
//  }
//  
//g = 0;
//  for (int i = 230; i >= 0; i--) {
//    analogWrite(analogOutPin6, i*0.6);
//  }
//
////    if (i < 160 || i > 0) {
////      analogWrite(analogOutPin4, g);
////      g++;
////    }
// delay(10);
// }
//  }
//}
 
void loop() {

  // compare the previous status to the current status
  if (status != WiFi.status()) {
    // it has changed update the variable
    status = WiFi.status();

    if (status == WL_AP_CONNECTED) {
      byte remoteMac[6];

      // a device has connected to the AP
      Serial.print("Device connected to AP, MAC address: ");
      WiFi.APClientMacAddress(remoteMac);
      Serial.print(remoteMac[5], HEX);
      Serial.print(":");
      Serial.print(remoteMac[4], HEX);
      Serial.print(":");
      Serial.print(remoteMac[3], HEX);
      Serial.print(":");
      Serial.print(remoteMac[2], HEX);
      Serial.print(":");
      Serial.print(remoteMac[1], HEX);
      Serial.print(":");
      Serial.println(remoteMac[0], HEX);
    } else {
      // a device has disconnected from the AP, and we are back in listening mode
      Serial.println("Device disconnected from AP");
    }
  }
  
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client"); 
//      digitalWrite(led, HIGH);
//  delay(250); 
//  digitalWrite(LED_BUILTIN, LOW);// print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/A\">here</a> to start wave 1<br>");
            client.print("Click <a href=\"/B\">here</a> to start wave 2<br>");
            client.print("Click <a href=\"/C\">here</a> to start wave 3<br>");
            client.print("Click <a href=\"/D\">here</a> to start wave 4<br>");
            client.print("Click <a href=\"/E\">here</a> to start wave 5<br>");
            client.print("Click <a href=\"/F\">here</a> to start wave 6<br>");
            client.print("Click <a href=\"/G\">here</a> to start wave 7<br>");
            client.print("Click <a href=\"/H\">here</a> to start wave 8<br>");
            client.print("Click <a href=\"/I\">here</a> to start wave 9<br>");
            client.print("Click <a href=\"/J\">here</a> to start wave 10<br>");
//            client.print("Click <a href=\"/L\">here</a> turn the LED off<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /A")) {



for (int i = 100; i <= 140; i++) {
analogWrite(analogOutPin, i);
delay(10);
}

int g = 0;
for (int i = 140; i >= 0; i--) {
analogWrite(analogOutPin, i);
if (i < 70 || i > 0) {
analogWrite(analogOutPin1, g);
g++;
}
delay(10);
}

for (int i = 70; i <= 100; i++) {
analogWrite(analogOutPin1, i);
delay(10);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin1, i);
if (i < 60 || i > 0) {
analogWrite(analogOutPin2, g);
g++;
}
delay(10);
}
for (int i = 60; i <= 100; i++) {
analogWrite(analogOutPin2, i);
delay(10);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin2, i);
if (i < 75 || i > 0) {
analogWrite(analogOutPin3, g);
g++;
}
delay(10);
} 
for (int i = 75; i <= 130; i++) {
analogWrite(analogOutPin3, i);
delay(10);
}

g = 0;
for (int i = 130; i >= 0; i--) {
analogWrite(analogOutPin3, i);
if (i < 60 || i > 0) {
analogWrite(analogOutPin4, g);
g++;
}
delay(10);
}
for (int i = 60; i <= 100; i++) {
analogWrite(analogOutPin4, i);
delay(10);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin4, i);
if (i < 60 || i > 0) {
analogWrite(analogOutPin5, g);
g++;
}
delay(5);
}
for (int i = 60; i <= 100; i++) {
analogWrite(analogOutPin5, i);
delay(5);
}

g = 0;
for (int i = 100; i >= 0; i--) {
analogWrite(analogOutPin5, i);
if (i < 80 || i > 0) {
analogWrite(analogOutPin6, g);
g++;
}
delay(5);
} 
for (int i = 80; i <= 120; i++) {
analogWrite(analogOutPin6, i);
delay(5);
}

g = 0;
for (int i = 120; i >= 0; i--) {
analogWrite(analogOutPin6, i);
delay(5);
}
         
}
if (currentLine.endsWith("GET /B")) {

          
analogWrite(analogOutPin, 0);

for (int i = 50; i <= 100; i++) {

analogWrite(analogOutPin4, i);
analogWrite(analogOutPin2, i);

digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}


for (int i = 100; i >=40; i--) {
analogWrite(analogOutPin4, i);
analogWrite(analogOutPin2, i);
digitalWrite(led, HIGH);
delay(50);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}

for (int i = 50; i <= 100; i++) {

analogWrite(analogOutPin5, i);
analogWrite(analogOutPin1, i);

digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}


for (int i = 100; i >=40; i--) {
analogWrite(analogOutPin5, i);
analogWrite(analogOutPin1, i);
digitalWrite(led, HIGH);
delay(50);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}

for (int i = 50; i <= 100; i++) {

analogWrite(analogOutPin6, i);
analogWrite(analogOutPin, i);

digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}


for (int i = 100; i >=40; i--) {
analogWrite(analogOutPin6, i);
analogWrite(analogOutPin, i);
digitalWrite(led, HIGH);
delay(50);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}

        }
 if (currentLine.endsWith("GET /C")) {

          
analogWrite(analogOutPin, 0);

for (int i = 50; i <= 100; i++) {

analogWrite(analogOutPin4, i);
analogWrite(analogOutPin2, i);

digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}

for (int i = 100; i >= 40; i--) {

analogWrite(analogOutPin4, i);
analogWrite(analogOutPin2, i);

digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}
}
  
  if (currentLine.endsWith("GET /D")) {

 

  
  }
    if (currentLine.endsWith("GET /E")) {
      analogWrite(analogOutPin, 0);

for (int i = 50; i <= 100; i++) {

analogWrite(analogOutPin4, i);
analogWrite(analogOutPin2, i);

digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}

for (int i = 100; i >= 40; i--) {

analogWrite(analogOutPin4, i);
analogWrite(analogOutPin2, i);

digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
Serial.println(i);
delay(3);
}
  
  }
    if (currentLine.endsWith("GET /F")) {
      //Тут можно вставить волну
  
  }
    if (currentLine.endsWith("GET /G")) {
  //Тут можно вставить волну
  }
    if (currentLine.endsWith("GET /H")) {
  //Тут можно вставить волну
  }
    if (currentLine.endsWith("GET /I")) {
  //Тут можно вставить волну
  }
    if (currentLine.endsWith("GET /J")) {
  //Тут можно вставить волну//Тут можно вставить волну
  }
 
       
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWifiStatus() {
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
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);

}
