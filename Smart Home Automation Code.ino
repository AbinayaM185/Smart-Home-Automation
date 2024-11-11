int pirPin = 2;             // Pin connected to the PIR sensor
int ledPin = 9;    
int led2=6;         // Pin connected to the LED
const int flamePin = A2;    // Pin connected to the flame sensor
const int buzPin = 10;      // Pin connected to the buzzer
const int threshold = 200;  
const int ldrPin=8; // Threshold for flame detection
const int ldrThres=5000;
unsigned long motionDetectedTime = 0;  // Variable to store the last motion detection time
unsigned long autoOffDelay = 500;     // Time in milliseconds (e.g., 5000ms = 5 seconds)

void setup() {
  // Initialize the PIR sensor pin as input
  pinMode(pirPin, INPUT);
  
  // Initialize the LED pin as output
  pinMode(ledPin, OUTPUT);

  // Initialize the flame sensor pin as input
  pinMode(flamePin, INPUT);
  
  // Initialize the buzzer pin as output
  pinMode(buzPin, OUTPUT);

  pinMode(led2,OUTPUT);
  
  // Start serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the state of the PIR sensor
  int sensorValue = digitalRead(pirPin);
   // Check if motion is detected
  if (sensorValue == HIGH) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected: LED ON");
    
    // Update the time when motion was last detected
    motionDetectedTime = millis();
  }

  // Check if enough time has passed since the last motion was detected
  if (millis() - motionDetectedTime > autoOffDelay) {
    // Turn off the LED if no motion is detected within the auto-off delay
    digitalWrite(ledPin, LOW);
    Serial.println("No motion for a while: LED OFF");
  }
  
  // Read the flame sensor value
  int flameSensorValue = analogRead(flamePin);
  
  // Check for flame detection
  if (flameSensorValue <=threshold) {
    Serial.println(flameSensorValue);
    Serial.println("Flame Detected");
   // digitalWrite(ledPin, HIGH); // Turn on LED for flame detection
    tone(buzPin, 100);          // Activate the buzzer
    delay(1000);                 // Keep the buzzer on for 1 second
  } else {
    Serial.println(flameSensorValue);
    Serial.println("No Flame Detected");
    noTone(buzPin);              // Turn off the buzzer
  }

  int ldrval=digitalRead(ldrPin);
  if(ldrval<ldrThres)
  {
    Serial.print("ldrvalue:");
    Serial.println(ldrval);
    digitalWrite(led2,HIGH);
  }
  else{
    Serial.print("ldrvalue:");
    Serial.println(ldrval);
    digitalWrite(led2,LOW);
  }

 
  
  // Short delay to avoid unnecessary fast loops
  delay(1000); // Increased delay to stabilize the readings
}
