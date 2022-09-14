void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2,INPUT);
}
void loop()
{
  intruder();
  temp();
}




void intruder()
{
  int motion = digitalRead(2);
  if (motion)
  {
  	Serial.println("Motion Detected");
  	warning(5);
  }
  
}

void temp()
{
  double a = analogRead(A1);
  double t = (((a/1024)*5)-0.5)*100;
  if (t>50)
  {
    warning(7);
  }
}

void warning(int time)
{
  for (int i=0;i<time;i++)
  {
  	digitalWrite(13,HIGH);
    tone(10,5000);
  	delay(1000);
  	digitalWrite(13,LOW);
    noTone(10);
  	delay(1000);  
  }
}