const int LED = 13;
const int BUTTON = 4;
  
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED, INPUT);
  Serial.begin(9600);
}

void loop() {
  int data = digitalRead(BUTTON);
  Serial.println(data);
  digitalWrite(LED, data); 
}
