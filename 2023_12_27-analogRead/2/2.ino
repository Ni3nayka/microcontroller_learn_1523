const int SENSOR_PIN = A0;
const int LED_PIN_1 = 5;
const int LED_PIN_2 = 6;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int data = analogRead(SENSOR_PIN);
  data = map(data, 11,816, 255,0);
  Serial.println(data);
  analogWrite(LED_PIN_1,data);
  analogWrite(LED_PIN_2,255-data);
}
