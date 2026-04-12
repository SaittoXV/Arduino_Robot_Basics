void setup()
{
  pinMode(9,OUTPUT);
  
  for(int i=0;i<5;i++)
  {
    digitalWrite(9,HIGH);
    delay(1000);
    digitalWrite(9,LOW);
    delay(1000);
  }
}

void loop()
{
  
}
