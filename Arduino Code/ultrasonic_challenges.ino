//------------Challenge Map Route-------------
/*
     ________
             |
Start +----> |
___     +    |
   |    |    | 
   |    |    |________________
   |    ↓                     |
   |         +-------->  End  |
   |__________________________|

*/

//------------Set Arduino Pin Number-------------
const int trigPin = 8;
const int echoPin = 7;
const int buzzerPin = 4;
const int E1 = 10; //LEFT MOTOR
const int M1 = 12;
const int E2 = 11; //RIGHT MOTOR
const int M2 = 13;

//------------Set Distance Number-------------
const int distanceDetect = 20;
const int motorSpeed = 150;
int objectDetect = 0;
float duration, distance;

void setup() 
{
  //------------Setup Motor Pin-------------
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);

  //------------Setup Ultrasonic Pin-------------
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //------------Setup Buzzer Pin-------------
  pinMode(buzzerPin, OUTPUT);

  //------------Setup Serial Monitor-------------
  Serial.begin(9600);
}

void loop() 
{
  //------------Start Trigger Pin-------------
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //------------Calculate Distance-------------
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  //------------Check Distance-------------
  if(distance < distanceDetect)
  {
    objectDetect =++;
    buzzer_beep();
    if(objectDetect == 1)
    {
      turn_right();
    }
    else if(objectDetect == 2)
    {
      turn_left();
    }
    else
    {
      stop_brake();
    }
  }
  else
  {
    move_forward();
  }

}

void buzzer_beep()
{
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
}

void move_backward()
{
    analogWrite(E1, motorSpeed);
    digitalWrite(M1, LOW);
    analogWrite(E2, motorSpeed);
    digitalWrite(M2, LOW);
    delay(1000);
}

void move_forward()
{
    analogWrite(E1, motorSpeed);
    digitalWrite(M1, HIGH);
    analogWrite(E2, motorSpeed);
    digitalWrite(M2, HIGH);
}

void turn_right()
{
    analogWrite(E1, 100);
    digitalWrite(M1, HIGH);
    analogWrite(E2, 100);
    digitalWrite(M2, LOW);
    delay(250);
}

void turn_left()
{
    analogWrite(E1, 100);
    digitalWrite(M1, LOW);
    analogWrite(E2, 100);
    digitalWrite(M2, HIGH);
    delay(250);
}

void stop_brake()
{
    analogWrite(E1, 0);
    digitalWrite(M1, LOW);
    analogWrite(E2, 0);
    digitalWrite(M2, HIGH);
    delay(250);
}

