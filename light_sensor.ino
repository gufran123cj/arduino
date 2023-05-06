// C++ code
//
int sensorValue = 0;
int LED_ACTIVATION_VALUE = 800;
int SERIAL_OUTPUT_FREQUENCY = 500;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(A0);
  // print the sensor reading so you know its range
  Serial.print("LIGHT SENSOR: ");
  Serial.println(sensorValue);
  if (sensorValue > LED_ACTIVATION_VALUE) {
     digitalWrite(9, LOW);
     Serial.println("LED STATUS: OFF");
     delay(SERIAL_OUTPUT_FREQUENCY);
  }
     
   else {
    digitalWrite(9, HIGH);
  Serial.println("LED STATUS: ON");
     delay(SERIAL_OUTPUT_FREQUENCY);
    
  }   
 
  
}
