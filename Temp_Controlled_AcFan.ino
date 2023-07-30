int tempin = A0; // the output pin of TMP36
int temp;
int cel;
int tempmin = 26; // Set the minimum temperature to turn on the fan
int relay = 9; // Use PWM pin 9 for fan speed control

void setup() {
  pinMode(tempin, INPUT);
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  analogWrite(relay, 255); // Start the fan at 100% speed
}

void loop() {
  temp = analogRead(tempin);
  cel = (temp - 20) * 0.48828125; // Adjusting for offset temperature (approximately 20)

  Serial.print("Temperature: ");
  Serial.print(cel); // Printing temperature on Serial Monitor
  Serial.write(176); // Degree symbol
  Serial.println("C");

  if (cel < tempmin) {
    analogWrite(relay, 0); // Turn off the fan
    Serial.println("Fan OFF");
  } else {
    int fanSpeed = map(cel, tempmin, 40, 0, 255); // Map temperature to fan speed range (26°C to 40°C)
    analogWrite(relay, fanSpeed); // Adjust fan speed based on temperature
    Serial.print("Fan Speed: ");
    Serial.print(map(fanSpeed, 0, 255, 0, 100)); // Convert fanSpeed to percentage
    Serial.println("%");
  }

  delay(3000);
}
