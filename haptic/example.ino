/* -----------------------------------------------------------------------------
 * Example .ino file for arduino, compiled with CmdMessenger.h and
 * CmdMessenger.cpp in the sketch directory. 
 *----------------------------------------------------------------------------*/

#include "CmdMessenger.h"

/* Define available CmdMessenger commands */
enum {
    who_are_you,
    my_name_is,
    sum_two_ints,
    sum_is,
    error,
};

/* Initialize CmdMessenger -- this should match PyCmdMessenger instance */
const int BAUD_RATE = 9600;
CmdMessenger c = CmdMessenger(Serial,',',';','/');

int my_Data;
int analogOutPin = 6;
int analogOutPin1 = 7;
int analogOutPin2 = 8;
int analogOutPin3 = 9;
int analogOutPin4 = 10;
int analogOutPin5 = 11;
int analogOutPin6 = 12;
int g =0; 

/* Create callback functions to deal with incoming messages */

/* callback */
void on_who_are_you(void){

      g = 0;
  for (int i = 170; i >= 40; i--) {
    analogWrite(analogOutPin6, i);
    /*if (i < 50 || i > 0) {
    analogWrite(analogOutPin1, g);
      g++;
    }*/
 delay(3);
 }
    for (int i = 80; i <= 130; i++) {
    analogWrite(analogOutPin6, i);
    delay(3);
  }
  
  g = 0;
  for (int i = 130; i >= 0; i--) {
    analogWrite(analogOutPin6, i);
    if (i < 80 || i > 0) {
      analogWrite(analogOutPin5, g);
      g++;
    }
 delay(3);
 }

   for (int i = 80; i <= 110; i++) {
    analogWrite(analogOutPin5, i);
    delay(3);
  }
  
  g = 0;
  for (int i = 110; i >= 0; i--) {
    analogWrite(analogOutPin5, i);
    if (i < 50 || i > 0) {
      analogWrite(analogOutPin4, g);
      g++;
    }
 delay(3);
 }
   for (int i = 50; i <= 110; i++) {
    analogWrite(analogOutPin4, i);
    delay(3);
  }
  
 g = 0;
  for (int i = 110; i >= 0; i--) {
    analogWrite(analogOutPin4, i);
    if (i < 50 || i > 0) {
      analogWrite(analogOutPin3, g);
      g++;
    }
 delay(3);
 } 
    for (int i = 50; i <= 110; i++) {
    analogWrite(analogOutPin3, i);
    delay(3);
  }
  
g = 0;
  for (int i = 110; i >= 0; i--) {
    analogWrite(analogOutPin3, i);
    if (i < 80 || i > 0) {
      analogWrite(analogOutPin2, g);
      g++;
    }
 delay(3);
 }
  for (int i = 80; i <= 170; i++) {
    analogWrite(analogOutPin2, i);
    delay(3);
  }
  
  g = 0;
  for (int i = 170; i >= 40; i--) {
    analogWrite(analogOutPin2, i);
    /*if (i < 50 || i > 0) {
    analogWrite(analogOutPin1, g);
      g++;
    }*/
 delay(3);
 }
  /* for (int i = 50; i <= 110; i++) {
    analogWrite(analogOutPin1, i);
    delay(8);
  }
  
 g = 0;
  for (int i = 110; i >= 0; i--) {
    analogWrite(analogOutPin1, i);
    if (i < 60 || i > 0) {
      analogWrite(analogOutPin, g);
      g++;
    }
    delay(10);
  } 
    for (int i = 60; i <= 110; i++) {
    analogWrite(analogOutPin, i);
    delay(10);
  }
  
g = 0;
  for (int i = 110; i >= 0; i--) {
    analogWrite(analogOutPin, i);
    delay(10);
  }

//    if (i < 80 || i > 0) {
//      analogWrite(analogOutPin4, g);
//      g++;
//    }
/*  
  for (int i = 160; i <= 250; i++) {
    analogWrite(analogOutPin6, i);
    delay(10);
  }
  
  g = 0;
  for (int i = 250; i >= 0; i--) {
    analogWrite(analogOutPin6, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin5, g);
      g++;
    }
 delay(10);
 }

   for (int i = 160; i <= 250; i++) {
    analogWrite(analogOutPin5, i);
    delay(10);
  }
  
  g = 0;
  for (int i = 250; i >= 0; i--) {
    analogWrite(analogOutPin5, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin4, g);
      g++;
    }
 delay(10);
 }
   for (int i = 160; i <= 250; i++) {
    analogWrite(analogOutPin4, i);
    delay(10);
  }
  
 g = 0;
  for (int i =250; i >= 0; i--) {
    analogWrite(analogOutPin4, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin3, g);
      g++;
    }
 delay(10);
 } 
    for (int i = 160; i <= 250; i++) {
    analogWrite(analogOutPin3, i);
    delay(10);
  }
  
g = 0;
  for (int i = 250; i >= 0; i--) {
    analogWrite(analogOutPin3, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin2, g);
      g++;
    }
 delay(10);
 }
  for (int i = 160; i <= 250; i++) {
    analogWrite(analogOutPin2, i);
    delay(10);
  }
  
  g = 0;
  for (int i = 250; i >= 0; i--) {
    analogWrite(analogOutPin2, i);
    if (i < 160 || i > 0) {
      analogWrite(analogOutPin1, g);
      g++;
    }
 delay(10);
 }
 /*
   for (int i = 160; i <= 250; i++) {
    analogWrite(analogOutPin1, i);
    delay(10);
  }
  
 g = 0;
  for (int i = 125; i >= 0; i--) {
    analogWrite(analogOutPin1, i);
    if (i < 80 || i > 0) {
      analogWrite(analogOutPin, g);
      g++;
    }
    delay(10);
  } 
    for (int i = 80; i <= 125; i++) {
    analogWrite(analogOutPin, i);
    delay(10);
  }
/*  
g = 0;
  for (int i = 125; i >= 0; i--) {
    analogWrite(analogOutPin, i);
  }

//    if (i < 80 || i > 0) {
//      analogWrite(analogOutPin4, g);
//      g++;
//    }
 delay(10);
 }
  }*/
}

void on_my_name_is(void){
  analogWrite(analogOutPin5, 200);
  delay(300);             // wait for 4s
  analogWrite(analogOutPin5, 0);
}


/* callback */
void on_sum_two_ints(void){
   analogWrite(analogOutPin4, 200);
  delay(300);             // wait for 4s
  analogWrite(analogOutPin4, 0);

}

void on_sum_is(void){
    analogWrite(analogOutPin3, 200);
  delay(300);             // wait for 4s
  analogWrite(analogOutPin2, 0);
}


/* callback */
void on_error(void){
    analogWrite(analogOutPin2, 200);
  delay(300);             // wait for 4s
  analogWrite(analogOutPin2, 0);
}


/* Attach callbacks for CmdMessenger commands */
void attach_callbacks(void) { 
  
    c.attach(who_are_you,on_who_are_you);
    c.attach(sum_two_ints,on_sum_two_ints);
    c.attach(sum_is,on_sum_is);
    c.attach(error, on_error);
}

void setup() {
    Serial.begin(BAUD_RATE);
    attach_callbacks();    
}

void loop() {
    c.feedinSerialData();
}
