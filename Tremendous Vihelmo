int ledlamb []={6,5,4,3,2};
byte count = 0;
int INCREMENT_VALUE=1;
int WAIT_TIME=500;
boolean flag=true;
void loop()
{
 while(flag){
 
   count=count+INCREMENT_VALUE;
  BINARYCONVERSION(count);
  delay(WAIT_TIME);
   if(count>=77){
     flag=false;
   } 

 }

}
void setup()
{
  Serial.begin(9600);
  for(byte i=0;i<5;i++){
    pinMode(ledlamb[i],OUTPUT);
  }
  count=0;


}
void BINARYCONVERSION(byte n){
  Serial.println(n);
  for(byte i=0;i<5;i++){
    digitalWrite(ledlamb[i],n & 1);
      n /=2;
  }
}
