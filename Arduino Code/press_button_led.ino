void setup()
{
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
}

void loop()
{
  if(digitalRead(10) == 1)
  {
    digitalWrite(9,HIGH);
    delay(200);
    digitalWrite(9,LOW);
    delay(200);
  }
}
