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

  Serial.begin(9600);
}

void loop()
{
  int detect_far_left = analogRead(far_Left_Sensor);
  int detect_left = analogRead(left_Sensor);
  int detect_middle = analogRead(middle_Sensor);
  int detect_right = analogRead(right_Sensor);
  int detect_far_right = analogRead(far_Right_Sensor);
  
  if (detect_far_left == LOW && detect_left == LOW && detect_middle == LOW && detect_right == LOW && detect_far_right == LOW)
  {
    Serial.println("Stop");
  }
  else if (detect_far_left != LOW && detect_left != LOW && detect_middle != LOW && detect_right != LOW && detect_far_right != LOW)
  {
    Serial.println("Stop");
  }
  else if (detect_left == LOW && detect_middle == LOW && detect_right == LOW)
  {
    Serial.println("Forward");
  }
  else if(detect_right == LOW && detect_far_right == LOW)
  {
    Serial.println("Right");
  }
  else if(detect_far_left == LOW && detect_left == LOW)
  {
    Serial.println("Left");
  }
  else if(detect_far_right == LOW)
  {
    Serial.println("Small Right");
  }
  else if(detect_far_left == LOW)
  {
    Serial.println("Small Left");
  }
  else
  {
    Serial.println("Stop");
  }

}

void forward(int speed_Right, int speed_Left)
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,speed_Left);
}

void backward(int speed_Right,int speed_Left)
{
  //Right Motor
  digitalWrite(right_Motor_Direction,HIGH);
  analogWrite(right_Motor_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,HIGH);
  analogWrite(left_Motor_Speed,speed_Left);
}

void right(int speed_Right, int speed_Left)
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,speed_Left);
}

void left(int speed_Right, int speed_Left)
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,speed_Right);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,speed_Left);
  
}

void stop()
{
  //Right Motor
  digitalWrite(right_Motor_Direction,LOW);
  analogWrite(right_Motor_Speed,LOW);
  
  //Left Motor
  digitalWrite(left_Motor_Direction,LOW);
  analogWrite(left_Motor_Speed,LOW);
  
}