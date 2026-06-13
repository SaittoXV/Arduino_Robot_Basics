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
int flipNumber = 1;
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
    buzzer_beep();
    move_backward();

    //------------[Inser Code Below]-------------

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
    analogWrite(E1, 100);
    digitalWrite(M1, LOW);
    analogWrite(E2, 100);
    digitalWrite(M2, LOW);
    delay(1000);
}

void move_forward()
{
    analogWrite(E1, 100);
    digitalWrite(M1, HIGH);
    analogWrite(E2, 100);
    digitalWrite(M2, HIGH);
    delay(100);
}

void turn_right()
{
    analogWrite(E1, 100);
    digitalWrite(M1, HIGH);
    analogWrite(E2, 100);
    digitalWrite(M2, LOW);
    delay(500);
}

void alternate_left_right(int flip)
{
    int oppositeNumber = 1 - flip;
    analogWrite(E1, 100);
    digitalWrite(M1, oppositeNumber);
    analogWrite(E2, 100);
    digitalWrite(M2, !oppositeNumber);
    delay(500);
}
