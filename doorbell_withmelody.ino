#define doo  1000
#define re   1122
#define mi   1260
#define fa   1335
#define sol  1498
#define la   1681
#define si   1887
#define dom  2000

int SOUND_DURATION = 1000;//playing music
int SILENCE_DURATION = 500;//duration playing music
int MELODY [] = {1,1,5,5,6,6,5,0,4,4,3,3,2,2,1};
int melody_counter=0;
void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT); //buzzer
  pinMode(6, INPUT); //button
}

void loop()
{
  int a= digitalRead(6);
  Serial.println(a);
  if(a==1)
  {
    for(int melody_counter=0; melody_counter<sizeof(MELODY); melody_counter++){
      if(MELODY[melody_counter]==0){
        delay(SOUND_DURATION);// silence duration
      }
      if(MELODY[melody_counter]==1){//low do
  
     tone(5, doo,SOUND_DURATION);
     delay(SILENCE_DURATION);
  }
      if(MELODY[melody_counter]==2){//re
  
     tone(5, re,SOUND_DURATION);
     delay(SILENCE_DURATION);
  }
      if(MELODY[melody_counter]==3){//mi
  
     tone(5, mi,SOUND_DURATION);
     delay(SILENCE_DURATION);
  }
      if(MELODY[melody_counter]==4){//fa
  
     tone(5, fa,SOUND_DURATION);
     delay(SILENCE_DURATION);
  }
      if(MELODY[melody_counter]==5){//sol
  
     tone(5, sol,SOUND_DURATION);
     delay(SILENCE_DURATION);
  }
      if(MELODY[melody_counter]==6){//la
  
     tone(5, la,SOUND_DURATION);
     delay(SILENCE_DURATION);
  }
      if(MELODY[melody_counter]==7){//si
  
     tone(5, si,SOUND_DURATION);
     delay(SILENCE_DURATION);
  }
      if(MELODY[melody_counter]==6){//high do
  
        tone(5, dom,SOUND_DURATION);
        delay(SILENCE_DURATION);}
  }//for
}//if


    
    
    
    
    
}//loop 
