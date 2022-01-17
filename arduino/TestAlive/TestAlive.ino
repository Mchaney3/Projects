void setup() {
  Serial.begin(115200);
  
}

void loop() {
  Serial.print(millis());
  Serial.println(" Alive");
  delay(1000);
}
