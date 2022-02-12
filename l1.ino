#include<Servo.h>
Servo bot;
int x,y,r,k=0;
void servo()
{
  bot.write(130);
  delay(1000);
  bot.write(0);
  
  }
void backward()
{
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
   digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  delay(5000);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
   digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  delay(5000);
  
  }
  void right()
  {
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
   digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  }
  void left()
  {
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
   digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  }
  void front()
  {
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
   digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  }
  void stopb()
  {
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
   digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  }
  void setup()
  {
        pinMode(9,OUTPUT);
pinMode(13,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);  
pinMode(10,OUTPUT);
pinMode(12,OUTPUT);
analogWrite(6,200);
analogWrite(5,200);

bot.attach(8);
  Serial.begin(9600);

    }
 void loop()
 {
  if(k==1)
  {Serial.begin(9600);
  k=0;
  }
  if(Serial.available()>0)
  {
    if(Serial.read()=='X')
    {
      x=Serial.parseInt();
    if(Serial.read()=='Y')
    {
      y=Serial.parseInt();
    if(Serial.read()=='R')
    {
      r=Serial.parseInt();
      }
    }
  
  if (x<250)
  {
    left();
  }
  if(x>350)
  {
    right();
  }
  if(x>250 && x<350)
  {
    if(r>40 &&r<70)
    {front();}
  }
  if(x<350 && x>250 && r>70 )
  {
    stopb();
    servo();
    Serial.end();
    backward();
    k=1;
    
    }
    
  }}}
  

