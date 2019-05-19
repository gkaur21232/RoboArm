#include <Servo.h>
const int SW_pin = 4;
const int X_pin = 0;
const int Y_pin = 2;

int xservo = 9;
int yservo = 10;
int x_degree = 90;
int y_degree = 90;
int tolerance = 50;

Servo myservo_x;
Servo myservo_y;
void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin,INPUT);
  myservo_x.attach(xservo);
  myservo_x.write(x_degree); 
  myservo_y.attach(yservo);
  myservo_y.write(y_degree);
  digitalWrite(SW_pin, HIGH);  
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int sw = digitalRead(SW_pin);    
  int x = analogRead(X_pin);
  delay(100);
  int y = analogRead(Y_pin);
  
  if(x < 519 - tolerance ) 
  {
    if(x_degree < 180)
    {
      x_degree+=10;
    }
  }
  if(x > 519 + tolerance )
  {
    if(x_degree > 0)
    {
      x_degree-=10;
    }
  }
if(y <519 - tolerance ) 
  {
    if(y_degree < 180 )
    {
      y_degree+=10;
    }
  }
  if(y > 519 + tolerance )
  {
    if(y_degree > 0 )
    {
      y_degree-=10;
    }
  }  
 
 myservo_x.write(x_degree);
 myservo_y.write(y_degree);
}
