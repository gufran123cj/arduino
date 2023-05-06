#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialize the LCD module with the appropriate number of columns and rows
LiquidCrystal_I2C lcd(34,16,2);

//for turkısh letter byte customize(Ç)
byte customChar[8] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};


void setup() {
  
  //lcd.createChar(0, customChar); // ö
  lcd.init();
  lcd.backlight();
}

void loop() {
 
  static char LCD_ROW_1 [] = "This text is for row 0 and longer than 16 characters.";
  static char LCD_ROW_2 [] = "ABCD EFGH       "; 
  static int messageLength = sizeof(LCD_ROW_1) - 2; // Subtract 1 to exclude the null terminator
  static int messageLength1 = sizeof(LCD_ROW_2) - 2;
  static char SCROLL_DIRECTION= 'R';
  int SCROLL_WAIT = 200;
  boolean SCROLL_FLAG = true;
  
  while(SCROLL_FLAG==true){
   if( SCROLL_DIRECTION== 'L'){
    
  static int scrollPosition = 0;
  lcd.setCursor(0, 0); // Set the cursor to the first row of the LCD
  for (int i = scrollPosition; i < scrollPosition + 16; i++) {
    lcd.write(LCD_ROW_1[i % messageLength]); // Write the i-th character of the message, wrapping around to the beginning if necessary
  }
  lcd.setCursor(0, 1); // Set the cursor to the second row of the LCD
  for (int i = scrollPosition ; i < scrollPosition + 16; i++) {
    lcd.write(LCD_ROW_2[i % messageLength1]); // Write the i-th character of the message, wrapping around to the beginning if necessary
  }
  delay(SCROLL_WAIT); // Wait for a short period before scrolling left
  scrollPosition++;
  if (scrollPosition >= messageLength) {
    scrollPosition = 0; // Start over at the beginning of the message
  }
  }
    else if(SCROLL_DIRECTION= 'R'){
   int swap=LCD_ROW_1[messageLength]; 
  lcd.setCursor(0,0);
  for(int j=0 ; j<=15; j++){
  lcd.print(LCD_ROW_1[j]);    
  }
  lcd.setCursor(0,0);
  delay(SCROLL_WAIT);
  for(int i =messageLength ;i>0; i--){
    LCD_ROW_1[i]=LCD_ROW_1[i-1];    
  }
  LCD_ROW_1[0]=swap;
            
  int swap1=LCD_ROW_2[messageLength1]; 
  lcd.setCursor(0,1);
  for(int j=0 ; j<=15; j++){
  lcd.print(LCD_ROW_2[j]);    
  }
  lcd.setCursor(0,1);
  delay(SCROLL_WAIT);
  for(int i =messageLength1 ;i>0; i--){
    LCD_ROW_2[i]=LCD_ROW_2[i-1];    
  }
  LCD_ROW_2[0]=swap1;
  
}
 
  
  
  }
}
  
  

  
  
