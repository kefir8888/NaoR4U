
int myData;
int analogOutPin = 6;
int analogOutPin1 = 7;
int analogOutPin2 = 8;
int analogOutPin3 = 9;
int analogOutPin4 = 10;
int analogOutPin5 = 11;
int analogOutPin6 = 12;
void setup() {
  // initialize serial communications at 9600 bps:
  pinMode(analogOutPin, OUTPUT);
  pinMode(analogOutPin1, OUTPUT);
  pinMode(analogOutPin2, OUTPUT);
  pinMode(analogOutPin3, OUTPUT);
  pinMode(analogOutPin4, OUTPUT);
  pinMode(analogOutPin5, OUTPUT);
  pinMode(analogOutPin6, OUTPUT);

  Serial.begin(9600);
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
  }
}


