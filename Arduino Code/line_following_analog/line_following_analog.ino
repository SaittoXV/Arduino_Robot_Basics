//------ Motor Variable -----
const int E1 = 10;
const int M1 = 12;
const int E2 = 11;
const int M2 = 13;

//----- Line Following Variable -----
const int CS = A2;
const int LS = A0;
const int RS = A4;

const int motorSpeed = 120;

void setup()
{
  //----- Set Motor ------
  pinMode(E1,OUTPUT);
  pinMode(M1,OUTPUT);
  pinMode(E2,OUTPUT);
  pinMode(M2,OUTPUT);

  //----- Set Line Following ------
  pinMode(CS,INPUT);
  pinMode(LS,INPUT);
  pinMode(RS,INPUT);

  Serial.begin(9600);
}

//------------Set Action Functions-------------

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
    analogWrite(E2, 0);
    digitalWrite(M2, LOW);
}

void turn_left()
{
    analogWrite(E1, 0);
    digitalWrite(M1, LOW);
    analogWrite(E2, 100);
    digitalWrite(M2, HIGH);
}

void stop_brake()
{
    analogWrite(E1, 0);
    digitalWrite(M1, LOW);
    analogWrite(E2, 0);
    digitalWrite(M2, HIGH);
    delay(1000);
}


void loop()
{
  int detect_left = digitalRead(LS);
  int detect_center = digitalRead(CS);
  int detect_right = digitalRead(RS);

  if(detect_left == HIGH)
  {
    Serial.println("Detect Line on Left");
    turn_left();
    delay(100);
  }
  else if (detect_right == HIGH)
  {
    Serial.println("Detect Line on Right");
    turn_right();
    delay(100);
  }
    else if (detect_center == HIGH)
  {
    Serial.println("Detect Line on Center");
    move_forward();
    delay(100);
  }

  
}
