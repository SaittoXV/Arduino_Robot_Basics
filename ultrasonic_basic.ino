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
