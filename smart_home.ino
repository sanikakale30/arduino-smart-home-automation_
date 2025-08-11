// Smart Home Automation with Motion + Light Control

#define PIR_PIN 2       // Motion sensor input
#define RELAY_PIN 3     // Relay output
#define LDR_PIN A0      // LDR sensor input

int ldrValue = 0;
bool lightOn = false;
unsigned long lastMotionTime = 0;
const unsigned long lightDelay = 10000; // 10 seconds delay before turning off

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);
  ldrValue = analogRead(LDR_PIN);
  
  Serial.print("Motion: ");
  Serial.print(motionDetected);
  Serial.print(" | LDR: ");
  Serial.println(ldrValue);

  // Light condition check (adjust threshold as per environment)
  if (motionDetected && ldrValue < 500) {
    digitalWrite(RELAY_PIN, HIGH);
    lightOn = true;
    lastMotionTime = millis();
  }

  // Auto turn off after delay
  if (lightOn && millis() - lastMotionTime > lightDelay) {
    digitalWrite(RELAY_PIN, LOW);
    lightOn = false;
  }
}
