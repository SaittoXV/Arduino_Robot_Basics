// Motor
int right_Motor_Direction = 10;
int right_Motor_Speed = 11;
int left_Motor_Direction = 5;
int left_Motor_Speed = 3;

//Infra-Red Sensor LSS05
int far_Left_Sensor = A1;
int left_Sensor = A2;
int middle_Sensor = A3;
int right_Sensor = A4;
int far_Right_Sensor = A5;

// Button Pin
int button_Pin = 7;
// Junction Count
int junction_Count = 0;

/* ---------------------- SETUP FUNCTION ---------------------- */
void setup()
{
  //Motor
  pinMode(right_Motor_Direction,OUTPUT);
  pinMode(right_Motor_Speed,OUTPUT);
  pinMode(left_Motor_Direction,OUTPUT);
  pinMode(left_Motor_Speed,OUTPUT);

  //Infra-Red Sensor
  pinMode(far_Left_Sensor,INPUT);
  pinMode(left_Sensor,INPUT);
  pinMode(middle_Sensor,INPUT);
  pinMode(right_Sensor,INPUT);
  pinMode(far_Right_Sensor,INPUT);

  //Button
  pinMode(button_Pin,INPUT);

  Serial.begin(9600);

  int read_Button = digitalRead(button_Pin);

  while(read_Button == LOW)
  {
    read_Button = digitalRead(button_Pin);
  }
}

/* ---------------------- LOOP FUNCTION ---------------------- */
void loop()
{

  // Read Line Sensor 
  int detect_far_left = digitalRead(far_Left_Sensor);
  int detect_left = digitalRead(left_Sensor);
  int detect_middle = digitalRead(middle_Sensor);
  int detect_right = digitalRead(right_Sensor);
  int detect_far_right = digitalRead(far_Right_Sensor);

  //Junction
 if (detect_far_left == HIGH && detect_left == HIGH && detect_middle == HIGH && detect_right == HIGH && detect_far_right == HIGH)
  {
    Serial.println("Junction");
    
    junction_Count = junction_Count+1;
    forward();
    stop();
    delay(100);

    junction(junction_Count);

  }
  //Right
  else if((detect_right == HIGH && detect_far_right == HIGH) || detect_far_right == HIGH)
  {
    Serial.println("Right");
    right(40,120);
    delay(90);
  }
  //Small Right
  else if((detect_right == HIGH && detect_middle == HIGH) || detect_right == HIGH)
  {
    Serial.println("Small Right");
    right(50,100);
    delay(50);
  }
  //Left
  else if((detect_far_left == HIGH && detect_left == HIGH) || detect_far_left == HIGH )
  {
    Serial.println("Left");
    left(120,40);
    delay(90);
  }
  //Small Left
  else if((detect_left == HIGH && detect_middle == HIGH) || detect_left == HIGH)
  {
    Serial.println("Small Left");
    left(100,50);
    delay(50);
  }
  //Forward
  else if(detect_middle == HIGH)
  {
    Serial.println("Forward");
    forward();
  }

}

/* ---------------------- FORWARD FUNCTION ---------------------- */
void forward()
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,100);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,100);

  delay(50);
}

/* ---------------------- RIGHT FUNCTION ---------------------- */
void right(int speed_Right, int speed_Left)
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,speed_Left);
}

/* ---------------------- TURN RIGHT FUNCTION ---------------------- */
void turn_Right()
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,0);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,100);

  delay(750);
}

/* ---------------------- LEFT FUNCTION ---------------------- */
void left(int speed_Right, int speed_Left)
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,speed_Left);
  
}

/* ---------------------- TURN LEFT FUNCTION ---------------------- */
void turn_Left()
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,100);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,0);

  delay(750);
}

/* ---------------------- STOP FUNCTION ---------------------- */
void stop()
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,LOW);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,LOW);
  
}

/* ---------------------- JUNCTION FUNCTION ---------------------- */
void junction(int junction_Count)
{
  if(junction_Count == 1)
  {
    forward();
  }
  else if(junction_Count == 2)
  {
    turn_Left();
  }
  else if(junction_Count == 3)
  {
    turn_Left();
  }
  else if(junction_Count == 4)
  {
    turn_Right();
  }
  else if(junction_Count == 5)
  {
    forward();
  }

}
