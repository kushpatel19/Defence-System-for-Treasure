//Team : The Titans
//Kush Patel  
//Door 1- numeric password (123)
//Door 2-Detecting proper distence by ulrasonic sensor (60-70 cm)
//Door 3-Choosing the gate of Bulb (gate-2)
//Door 4-Detecting Temperature (40-50 Celsius)
//AT THE END MELODIOUS SOUND
//otherwise alarm buzzer rang

#include <Servo.h>
#define buzz 4
#define echoPin 11 
#define trigPin 12 
#define Bulb 2


//Variables
int code;     	
int key;
int G=1;
int Y=2;
int R=3;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
long duration; 
int distance; 



void setup()
{
  
  Serial.begin(9600);   
  pinMode(buzz, OUTPUT);
  pinMode(Bulb, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(10, OUTPUT);
  
  servo_1.attach(13, 500, 2500);
  servo_2.attach(10);
  servo_3.attach(2);
  servo_4.attach(3);  
  
}


void loop()
{
  digitalWrite(Bulb,LOW);
  Serial.println("Welcome to the way of Tresure!");
  Serial.println("Enter the code of door-1 ");     
  
  while (Serial.available()==0) {          
    while (Serial.available()==0){}
    code = Serial.parseInt();                   
    digitalWrite(Bulb,LOW);
    // Door - 1
  if (code==123){
      Serial.print("Correct");
      Serial.println("  ");
      Serial.println("Go Ahead");
      digitalWrite(Bulb,LOW);
      
      for (pos1 = 0; pos1 <= 90; pos1 += 1) {
         servo_1.write(pos1);
         delay(15);
         digitalWrite(Bulb,LOW);
        }
     
      digitalWrite(Bulb,LOW);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2; 
 
      Serial.print("Initial Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
        delay(10000);
    
      digitalWrite(Bulb,LOW);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2; 
      Serial.print("Final Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
  
        //Door - 2
      if (distance > 60 && distance <70){
         for (pos2 = 0; pos2 <= 90; pos2 += 1) { 
            servo_2.write(pos2);   
            delay(15);
            digitalWrite(Bulb,LOW);
           }
         digitalWrite(Bulb,LOW);
         Serial.print("Good!");
         Serial.print("You are on the right way");
         Serial.println("  ");
         Serial.println("Go Ahead and Get your treasure");
         Serial.println("You Got the Treasure");
         
         Serial.println("(1 for gate(G)) , (2 for gate(Y)) and (3 for gate(R)) ");
         Serial.println("Enter the gate number:");
         while (Serial.available()==0){  
           while (Serial.available()==0){}
           key = Serial.parseInt(); 
           digitalWrite(Bulb,LOW);
      
           //Door - 3
         if (key==Y) {
            digitalWrite(Bulb,HIGH);
            delay(5000);
            for (pos3 = 0; pos3 <= 90; pos3 += 1) {
               servo_3.write(pos3);
               delay(15); 
              }
            
          
            digitalWrite(Bulb,LOW);
            Serial.print("Excellent!!!");
            Serial.println("  ");
            Serial.println("Let's escape");
             
            float temp= ((analogRead(A0) * (5.0/1024))-0.5)/0.01;
            Serial.println("Initial Temperature is:");
            Serial.println(temp);
            delay (10000);
            temp= ((analogRead(A0) * (5.0/1024))-0.5)/0.01;
            Serial.println("Final Temperature is:");
            Serial.println(temp);
             
               //Door - 4
              if (temp>40 && temp<50) {
                for (pos4 = 0; pos4 <= 90; pos4 += 1) {
                   servo_4.write(pos4);
                   delay(15);
                   digitalWrite(Bulb,LOW);
                  }
                digitalWrite(Bulb,LOW);
                noTone(8);
                tone(6, 880, 200); 
                delay(600); 
                noTone(6);
                tone(7, 988, 500); 
                delay(800); 
                noTone(7);
                tone(8, 1047, 300); 
                delay(1000);
                Serial.print("YOU ARE MARVELLOUS!!!!");
               }
           
              else{
                digitalWrite(Bulb,LOW);
                Serial.print("You died");
                Serial.println("  ");
                Serial.println("You lost the Treasure");
                digitalWrite(buzz,HIGH);
                delay(5000);
                digitalWrite(buzz,LOW);
               }
             }
         
          
         else{
             digitalWrite(Bulb,LOW);
             Serial.print("You died");
             Serial.println("  ");
             Serial.println("You lost the Treasure");
             digitalWrite(buzz,HIGH);
             delay(5000);
             digitalWrite(buzz,LOW);
            }
          }
         }
       
       
      else{
       digitalWrite(Bulb,LOW);
       Serial.print("incorrect");
       Serial.println("  ");
       Serial.println("You missed the Treasure");
       digitalWrite(buzz,HIGH);
       delay(5000);
       digitalWrite(buzz,LOW);
      }
    }
  else{
     digitalWrite(Bulb,LOW);
     Serial.print("incorrect");
     Serial.println("  ");
     Serial.println("You missed the Treasure");
     digitalWrite(buzz,HIGH);
     delay(5000);
     digitalWrite(buzz,LOW);
    }
   }
  
}
