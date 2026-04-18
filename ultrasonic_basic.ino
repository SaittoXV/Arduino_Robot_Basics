// HC-SR04 simple example without libraries
const int trigPin = 12;
const int echoPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // read echo
  unsigned long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30 ms
  if (duration == 0) {
    Serial.println("Out of range");
  } else {
    float distanceCm = duration * 0.0343 / 2.0;
    Serial.print(distanceCm, 1);
    Serial.println(" cm");
  }

  delay(200);
}


// -----------------------------------------------------------
const int trig_pin = 9;
const int echo_pin = 10;
float duration,duration_second, sound_speed,distance;


void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

}


void loop() {

  // put your main code here, to run repeatedly:

  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);


  duration = pulseIn(echo_pin, HIGH);
  Serial.print("Duration Pulse: ");
  Serial.println(duration);

  duration_second = duration*0.000001;
  sound_speed = 343.0*100.0;
  distance = (duration_second*sound_speed)/2;

  Serial.println(duration_second);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

} 
