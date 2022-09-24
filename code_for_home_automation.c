

float x,y;             //TEMP
#define trigPin 12     //ULTRA
#define echoPin 10
int ledPin= 13;  
int duration, distance; //ULTRA
 
#include<Servo.h>     //servo   
Servo my;              //servo

char val;                     //bluetooth

void setup() {
 Serial.begin(9600); 
 pinMode(2,INPUT); //IR  GATE FIRST
 pinMode(3,INPUT);
 my.attach(11);     //servo   
 
 pinMode(4, OUTPUT);    //IR GATE FIRST
 
 
 pinMode(7,OUTPUT);              //TEM
 pinMode(8,INPUT);            //pir 1
 pinMode(9,OUTPUT);           //LED 1
 // pinMode(10,INPUT);          //pir 2
  //pinMode(11,OUTPUT);             //LED2
 pinMode(trigPin, OUTPUT); //12  PIN  ULTRA
 pinMode(echoPin, INPUT);  //10 PIN ULTRA
 pinMode(ledPin, OUTPUT);  //13 PIN  ULTRA
                                        


   pinMode(3,OUTPUT);             //bluetooth
}



void loop() {
 x=analogRead(0);                 //TEMP
  y=((x/1024)*5)*100;
  Serial.println(y);
  delay(500);
  
  if(y>44)
  {
  digitalWrite(7,1);
  }
  else
  {
  digitalWrite(7,0);
  delay(500);
  }
                                   //TEMP
  

if(digitalRead(8)==HIGH)                  //pir
 {
  digitalWrite(9,HIGH);
  }
 else
{ digitalWrite(9,LOW);}
 
  
 
 
  digitalWrite(trigPin, HIGH);           //ULTRA
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = (duration/2) / 29.1;

  if (distance >= 10 || distance <= 0) 
  {
  // Serial.println("no object detected");
 
 
   digitalWrite(ledPin,LOW);
   }
  else 
  {
  Serial.println("object detected \n");
 Serial.print("distance= ");
             
  Serial.print(distance);       
   digitalWrite(ledPin,HIGH);
  }                                              //ULTRA
if(digitalRead(2)==HIGH)        //gate first        
 {
  my.write(0);          //servo
  
  
  }
 else
 {
  my.write(90);             //servo
 }

 analogRead(5);             //ldr
  float a = analogRead(5);   
 Serial.println(a);
  

   if (a <=200) {

    digitalWrite(4,1);               
   Serial.println("LDR is DARK, LED is ON");
    
  
   }
  else {

    digitalWrite(4,0);         
    Serial.println("-----");
    
    
  }                                        //ldr

 

if (Serial.available())                                       //bluetooth
{
  val = Serial.read();
  Serial.println(val);

  
  if(val == 'TV')
  digitalWrite(3,HIGH);
  
  else if(val == 'tv')
  digitalWrite(3,LOW);

  }                                                           //bluetooth


}
