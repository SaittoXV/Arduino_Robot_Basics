const int red_led = 2;
const int yellow_led = 3;
const int green_led = 4;
const int button = 8;
int current_led = red_led;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(red_led,OUTPUT);
  pinMode(yellow_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(button,OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (digitalRead(button) == 1)
  {
      digitalWrite(current_led,HIGH);
      delay(100);
      digitalWrite(current_led,LOW);
  
      Serial.println(current_led);
      if(current_led == red_led && digitalRead(button) == 0)
      {
        current_led = yellow_led;
      }
      else if(current_led == yellow_led && digitalRead(button) == 0)
      {
        current_led = green_led;
      }
      else if (current_led == green_led && digitalRead(button) == 0)
      {
        current_led = red_led;
      }
  }
}
