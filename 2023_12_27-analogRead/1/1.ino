const int SENSOR_PIN = A5;
const int LED_PIN = 5;

float PARROT_TO_VOLTS = 204.6;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int data = analogRead(SENSOR_PIN);
  //Serial.println(data/PARROT_TO_VOLTS);
  Serial.println(255-data/4);
  analogWrite(LED_PIN,255-data/4);
}
