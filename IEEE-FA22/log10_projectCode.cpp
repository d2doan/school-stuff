// Project: Automatic Soap Dispenser with 3 Modes 
// Team Name: log10 (UCSD)
// Team Members: Diana Doan, Rana Singh, Peter Li, Philip Pincenci
// Last Edited: 11-28-22

#include <Servo.h>

// intializing pins for buttons 
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;

Servo servo1;
Servo servo2;

int state1 = 0; //Stores the state of button1
int state2 = 0; //Stores the state of button2
int state3 = 0; //Stores the state of button3
int pos = 0;
int new_pos = 0;

// Sizes correlate to different volumes of soap
int small = 5; 
int med = 10;
int large = 20;

void setup() {
  Serial.begin(9600); // for general debugging
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  servo1.attach(9); //pins for motors
  servo2.attach(10);
  servo1.write(0);
  servo2.write(0);
}

void loop() {
  state1 = digitalRead(button1);
  state2 = digitalRead(button2);
  state3 = digitalRead(button3);

  if (state1 == HIGH) {
    new_pos = pos + small;
  } else if (state2 == HIGH) {
    new_pos = pos + med;
  } else if (state3 == HIGH) {
    new_pos = pos + large;
  }

  if (new_pos <= 180) {
    for(int i = pos; i <= new_pos; i++)    
    {                                
      servo1.write(i);             
      servo2.write(180-i);             
      delay(15);                       
    }
    pos = new_pos;
  } else {
    Serial.print("Exceeded 180!");
    for(int i = pos; i <= 180; i++)    
    {                                
      servo1.write(i);             
      servo2.write(180-i);             
      delay(15);                       
    }
    // resetting wheel
    for(int i = 180; i >= 0; i--)    
    {                                
      servo1.write(i);             
      servo2.write(180-i);             
      delay(15);                       
    }
    exit(0);
  }

}



