#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(34, 16, 2);

float value;
const int analogIn = A0;
int humiditysensorOutput = 0;
// Defining Variables
int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;
int buttonNew;
int buttonState=0;
int lastbuttonvalue=0;
char LCD_LANGUAGE = 'E';
unsigned long lastUpdateTime = 0; // last time readings were updated
unsigned long updateInterval = 200; // update interval in milliseconds
boolean isturkish = false;

void setup(){
     lcd.init();
     lcd.backlight();
     Serial.begin(9600);
     pinMode(A0, INPUT);
  	 pinMode(2, INPUT);
}

void loop(){
    buttonNew = digitalRead(2);
	RawValue = analogRead(analogIn);
    Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
    tempC = (Voltage-500) * 0.1; // 500 is the offset
    tempF = (tempC * 1.8) + 32; // convert to F
    humiditysensorOutput = analogRead(A0);  	
  
   if (lastbuttonvalue==0 && buttonNew==1) {
    isturkish = !isturkish;
     if (isturkish){
       LCD_LANGUAGE = 'E';
     }
     else if(!isturkish  ){
       LCD_LANGUAGE = 'T';
     }
   } 
    lastbuttonvalue=buttonNew;
  unsigned long currentTime = millis();
  
  if (currentTime - lastUpdateTime >= updateInterval) {
    updateReadings();    
    lastUpdateTime = currentTime;
  }   
}
void updateReadings() {
  
  if (isturkish && LCD_LANGUAGE == 'E' ) {
    lcd.setCursor(0,0);
	lcd.print("TEM(F):" );
  	lcd.print(tempF);
    lcd.print(" EN " );
    lcd.setCursor(0,1);
  } else if (!isturkish && LCD_LANGUAGE == 'T' ) {
    lcd.setCursor(0,0);
    lcd.print("SIC(C):");
    lcd.print(tempC);
    lcd.print(" TR ");
    lcd.setCursor(0,1);
  }
    
    humiditysensorOutput = analogRead(A0);
	lcd.print("HUM(%):"); // Printing out Humidity Percentage
    lcd.print(map(humiditysensorOutput, 0, 1023, 10, 70)); 

}



