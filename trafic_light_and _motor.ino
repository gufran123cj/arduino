int LED_WAIT_DURATION_MIN = 2000;
int LED_WAIT_DURATION_MAX = 6000;
int sensorValue = 0;
int LED_ON_DURATION_MIN = 2000;
int LED_ON_DURATION_MAX = 6000;
int counter=0;
int counter1=0;

int LIGHT_SENSOR_OUTPUT_INTERVAL = 1000;

int LED_WAIT_DURATION=0;
int LED_ON_DURATION=0;
int LED_status;

int MOTOR = 6;

void setup() {
  
  pinMode(MOTOR, OUTPUT);
  pinMode(A3, INPUT);   //Red LED Sensor Pin
  pinMode(5, OUTPUT);   //red LED Pin
  Serial.begin(9600);
}

void loop() {
  
  LED_WAIT_DURATION = random(LED_WAIT_DURATION_MIN, LED_WAIT_DURATION_MAX);
  LED_ON_DURATION= random(LED_ON_DURATION_MIN,LED_ON_DURATION_MAX); 
  sensorValue= analogRead(A3);
  Serial.println(sensorValue);
  digitalWrite(5, HIGH);
  LED_status=digitalRead(5);
  
  
  
  if((50 <= analogRead(A3) < 1000) && (LED_status==HIGH)){
    digitalWrite(MOTOR,HIGH);    
    Serial.print("LED is turned ON for ");
    Serial.print(LED_WAIT_DURATION); 
    Serial.print(" milliseconds.");
    OutputHigh(counter);
    delay(LED_WAIT_DURATION);   
  }
  else{
    digitalWrite(MOTOR,LOW);
    Serial.print("LED is turned OFF for" );
    Serial.print(LED_WAIT_DURATION); 
    Serial.print( "milliseconds.");
    Outputlow(counter1);
    delay(LED_WAIT_DURATION);   
    
  }
  
  delay(LED_ON_DURATION);
  digitalWrite(5, LOW);
  LED_status=digitalRead(5);
  
  if((500 <= analogRead(A3) < 1000) && (LED_status==HIGH)){
    digitalWrite(MOTOR,HIGH);    
    Serial.print("LED is turned ON for ");
    Serial.print(LED_WAIT_DURATION); 
    Serial.print(" milliseconds.");
    OutputHigh(counter);
    delay(LED_WAIT_DURATION);   
  }
  else{
    digitalWrite(MOTOR,LOW);
    Serial.print("LED is turned OFF for" );
    Serial.print(LED_WAIT_DURATION); 
    Serial.print( "milliseconds.");
    Outputlow(counter1);
    delay(LED_WAIT_DURATION);     
  } 
  delay(LED_ON_DURATION);

}

void Outputlow(int counter1){  
    while(counter1<LED_WAIT_DURATION){
        Serial.println("Light sensor output is "+(sensorValue));      
        counter1=counter1+LIGHT_SENSOR_OUTPUT_INTERVAL;
    }
  }

void OutputHigh(int counter){
	while(counter<LED_WAIT_DURATION){
        Serial.println("Light sensor output is"+(sensorValue));      
        counter=counter+LIGHT_SENSOR_OUTPUT_INTERVAL;
    
}
