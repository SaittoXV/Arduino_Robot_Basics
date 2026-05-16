//MOTOR DRIVER L289P

//Buzzer
int Buzzer_Pin = 4;

//Ultrasonic Sensor
int Trig_Pin = 10;
int Echo_Pin = 11;
float duration, distance;

// Motor 1
int E1 = 10;
int M1 = 12;

// Motor 2
int E2 = 11;
int M2 = 13;

void setup()
{
  pinMode(Buzzer_Pin, OUTPUT);

  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  Serial.begin(9600);

  pinMode(M1, OUTPUT);
  pinMode(E1, OUTPUT);

  pinMode(M2, OUTPUT);
  pinMode(E2, OUTPUT);  
}

void loop()
{
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);

  
  duration = pulseIn(Echo_Pin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if(distance < 15){
    //Make buzzer beep
    digitalWrite(Buzzer_Pin, HIGH);
    delay(100);
    digitalWrite(Buzzer_Pin, LOW);
    delay(100);

    //Reverse the robot
    digitalWrite(M1,LOW);
    analogWRite(E1, 100);

    digitalWrite(M2, LOW);
    analogWrite(E2, 100);
  }
  else
  {
    digitalWrite(M1,HIGH);
    analogWRite(E1, 100);

    digitalWrite(M2, HIGH);
    analogWrite(E2, 100);
  }

  delay(100);
  
}
