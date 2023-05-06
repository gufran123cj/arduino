#define green 13
#define red 12
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialize the LCD module with the appropriate number of columns and rows
LiquidCrystal_I2C lcd(34,16,2);

const int trigPin(9); 
const int echoPin(10); 
const int buzzPin(11);

int BUZZER_LED_FREQ_MAX = 1000;
int BUZZER_LED_FREQ_MIN = 10;
int UPDATE_FREQ_BUZZER = 200;
int UPDATE_FREQ_LCD = 200;
int DIST_MAX = 100;
int DIST_MIN = 10;
long duration; 
int CURRENT_DIST;
int CURRENT_FREQ = 0;


void setup() { 
 lcd.init( );
 lcd.backlight();
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 pinMode(buzzPin, OUTPUT); 
 pinMode(green,OUTPUT);
 pinMode(red,OUTPUT);
} 

void loop() { 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
 CURRENT_DIST = duration*0.034/2; 
 lcd.setCursor(0,0); 
 delay(10);
 double a = (CURRENT_DIST)-(DIST_MIN);
 double b =(DIST_MAX) - (DIST_MIN);
 double c = a/b;
 double x= (BUZZER_LED_FREQ_MAX)-(BUZZER_LED_FREQ_MIN);
 double d = (c) * (x);
 int CURRENT_FREQ = (d) +  (BUZZER_LED_FREQ_MIN);
  
    boolean flag= true;

  
 if((CURRENT_DIST< DIST_MAX)&&(CURRENT_DIST >DIST_MIN)) {  
 digitalWrite(red,HIGH);
 delay(UPDATE_FREQ_BUZZER);
 flag= true;
 digitalWrite(buzzPin,HIGH); 
 delay(CURRENT_FREQ);
 digitalWrite(buzzPin,LOW);
 delay(CURRENT_FREQ);
 lcd_screen(flag,CURRENT_FREQ);
 lcd.clear();
 } 
 else if (CURRENT_DIST>DIST_MAX) { 
 digitalWrite(buzzPin, HIGH);
 delay(UPDATE_FREQ_BUZZER); 
 digitalWrite(red,LOW);
 lcd_screen(flag,CURRENT_FREQ);
 lcd.clear();
 flag=false;
 } 
} 

boolean lcd_screen(boolean flag,int CURRENT_FREQ){
  if(flag==true)
 {
 lcd.print("Distance: "); 
 lcd.print(CURRENT_DIST); 
 lcd.print(" cm"); 
 lcd.setCursor(0,1); 
 lcd.print("FREQUENCY:");
 lcd.print(CURRENT_FREQ);
 lcd.print(" ms");
 delay(UPDATE_FREQ_LCD); 
 }
  else {
  lcd.print("Distance: "); 
 lcd.print(CURRENT_DIST); 
 lcd.print(" cm");
 lcd.setCursor(0,1); 
 lcd.print("FREQUENCY:");
 lcd.print(CURRENT_FREQ);
 lcd.print(" ms");  
 delay(UPDATE_FREQ_LCD);
  }

return flag;

}
