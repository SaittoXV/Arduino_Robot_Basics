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
  
  int detect_far_left = digitalRead(far_Left_Sensor);
  int detect_left = digitalRead(left_Sensor);
  int detect_middle = digitalRead(middle_Sensor);
  int detect_right = digitalRead(right_Sensor);
  int detect_far_right = digitalRead(far_Right_Sensor);

  //Junction
 if (detect_far_left == HIGH && detect_left == HIGH && detect_middle == HIGH && detect_right == HIGH && detect_far_right == HIGH)
  {
    Serial.println("Junction");
    forward(100, 100);
  }
  //Right
  else if((detect_right == HIGH && detect_far_right == HIGH) || detect_far_right == HIGH)
  {
    Serial.println("Right");
    right(40,120);
    delay(100);
  }
  //Small Right
  else if(detect_right == HIGH && detect_middle == HIGH)
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
    delay(100);
  }
  //Small Left
  else if(detect_left == HIGH && detect_middle == HIGH)
  {
    Serial.println("Small Left");
    left(100,50);
    delay(50);
  }
  //Forward
  else if(detect_middle == HIGH)
  {
    Serial.println("Forward");
    forward(100, 100);
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
