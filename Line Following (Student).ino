// Motor
int right_Direction = 10;
int right_Speed = 11;
int left__Direction = 5;
int left_Speed = 3;

//Infra-Red Sensor LSS05
int S1 = A1;
int S2 = A2;
int S3 = A3;
int S4 = A4;
int S5 = A5;

/* ---------------------- SETUP FUNCTION ---------------------- */
void setup()
{
  //Motor


  //Infra-Red Sensor


  Serial.begin(9600);
}

/* ---------------------- LOOP FUNCTION ---------------------- */
void loop()
{
  
  int detect_S1 = digitalRead(S1);
  int detect_S2 = digitalRead(S2);
  int detect_S3 = digitalRead(S3);
  int detect_S4 = digitalRead(S4);
  int detect_S5 = digitalRead(S5);

  //Start Code Here

  
}

/* ---------------------- FORWARD FUNCTION ---------------------- */
void forward()
{
  //Right Motor
  digitalWrite(right_Direction,LOW);
  analogWrite(right_Speed,100);
  
  //Left Motor
  digitalWrite(left__Direction,LOW);
  analogWrite(left_Speed,100);
}

/* ---------------------- RIGHT FUNCTION ---------------------- */
void right(int speed_Right, int speed_Left)
{
  //Right Motor
  digitalWrite(right_Direction,LOW);
  analogWrite(right_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left__Direction,LOW);
  analogWrite(left_Speed,speed_Left);
}

/* ---------------------- LEFT FUNCTION ---------------------- */
void left(int speed_Right, int speed_Left)
{
  //Right Motor
  digitalWrite(right_Direction,LOW);
  analogWrite(right_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left__Direction,LOW);
  analogWrite(left_Speed,speed_Left);
}

/* ---------------------- STOP FUNCTION ---------------------- */
void stop()
{
  //Right Motor
  digitalWrite(right_Direction,LOW);
  analogWrite(right_Speed,LOW);
  
  //Left Motor
  digitalWrite(left__Direction,LOW);
  analogWrite(left_Speed,LOW);
}
