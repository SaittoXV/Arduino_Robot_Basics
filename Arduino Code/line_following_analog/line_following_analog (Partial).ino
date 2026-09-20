/**TEACHING
1. Create a Line Follow Function
2. Create logic for pressing Button
3. Found One Junction Logic
4. Create Turn Left + Right at Junction Function
5. Multiple Junction Challenge**/


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
const int Button = 2;

int Junction = 0;

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

  //----- Set Button -----
  pinMode(Button,INPUT);

  Serial.begin(9600);

  while(true)
  {
    if(digitalRead(Button) == HIGH)
    {
      break;
    }
  }
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
    analogWrite(E2, 100);
    digitalWrite(M2, LOW);
}


void turn_right_junction()
{
  turn_right();
  delay(250);

  while (digitalRead(CS) == LOW)
  {
    turn_right();
  }
}

void turn_left()
{
    analogWrite(E1, 100);
    digitalWrite(M1, LOW);
    analogWrite(E2, 100);
    digitalWrite(M2, HIGH);
}

void turn_left_junction()
{
  turn_left();
  delay(250);

  while (digitalRead(CS) == LOW)
  {
    turn_left();
  }
}

void stop_brake()
{
    analogWrite(E1, 0);
    digitalWrite(M1, LOW);
    analogWrite(E2, 0);
    digitalWrite(M2, LOW);
    delay(1000);
}

void line_follow()
{
  int detect_left = digitalRead(LS);
  int detect_center = digitalRead(CS);
  int detect_right = digitalRead(RS);

  if(detect_left == HIGH)
  {
    Serial.println("Detect Line on Left");
    turn_left();
  }
  else if (detect_right == HIGH)
  {
    Serial.println("Detect Line on Right");
    turn_right();
  }
    else if (detect_center == HIGH)
  {
    Serial.println("Detect Line on Center");
    move_forward();
  }
  
}

void junction_detect()
{
    

}

void loop()
{
  int detect_left = digitalRead(LS);
  int detect_center = digitalRead(CS);
  int detect_right = digitalRead(RS);
  
  if(detect_left == HIGH && detect_center == HIGH && detect_right == HIGH)
  {
    Junction++;
    junction_detect();
  }
  else
  {
      line_follow();
  }
}
