#include<Servo.h>
#define servo1 3
#define servo3 5
#define servo4 6
#define servo5 7
#define echoPin 8
#define trigPin 9
long distance;
long duration;
Servo myservo1, myservo3, myservo4, myservo5;

void setup(){
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
myservo1.attach(servo1); //dasar
myservo3.attach(servo3); //atas bawah 
myservo4.attach(servo4); //clamp1
myservo5.attach(servo5); //clamp2

myservo1.write(0);
myservo3.write(100);
myservo4.write(0);
myservo5.write(0);
}

void loop(){ 
ultra();
int putih = digitalRead(A0);
int hitam = digitalRead(A1);
myservo4.write(90);
myservo5.write(90);
myservo1.write(40);
myservo3.write(0);
if(distance == 3){
 if(putih == 0 && hitam == 1){
 myservo1.write(87);
 delay(1000);
 myservo3.write(90);
 delay(1000);
 myservo4.write(0);
 myservo5.write(0);
 delay(1000);
 myservo3.write(0);
 delay(1000);
 myservo1.write(25);
 delay(1000);
 myservo3.write(90);
 delay(1000);
 myservo4.write(90);
 myservo5.write(90);
 delay(1000);
 }
 else if(putih == 1 && hitam == 1){
  myservo1.write(87);
 delay(1000);
 myservo3.write(90);
 delay(1000);
 myservo4.write(0);
 myservo5.write(0);
 delay(1000);
 myservo3.write(0);
 delay(1000);
 myservo1.write(65);
 delay(1000);
 myservo3.write(90);
 delay(1000);
 myservo4.write(90);
 myservo5.write(90);
 delay(1000);
 }
 else{
  myservo4.write(90);
myservo5.write(90);
myservo1.write(50);
myservo3.write(0);
 }
}
}
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
