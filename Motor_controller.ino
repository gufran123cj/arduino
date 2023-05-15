// C++ code
//
//const int potPin = A0;
const int enable = 9;
int button_one_state=0;
int button_two_state=0;
const int in1 = 8;//for left
const int in2 = 7;//for right
int direction = 0;
int button_left = 3;
int button_right = 2;
int speed_ratio = 256/4;
int speed_value = 0;
int display_count=0;

int a = 11; 
int b = 10;
int c = 4;
int d = 5;
int e = 6;
int f = 12;
int g = 13;

void setup()
{
  pinMode(button_right,INPUT);
  pinMode(button_left,INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  sevensegment();
  
}

void loop()
{
   button_one_state = digitalRead(button_left);
   button_two_state = digitalRead(button_right);
  
  	if(button_one_state ==HIGH && speed_value+speed_ratio <=255 )
  {
      if((direction==1 || direction==0)){
        speed_value = speed_value + speed_ratio;
        analogWrite(in2,speed_value);
        display_count++;
        direction = 1;
        sevensegment();    
      }
      else if(speed_value-speed_ratio >=0 && direction==2){
      speed_value = speed_value - speed_ratio;
    analogWrite(in1,speed_value);
    display_count++;
    if(speed_value == 0){
      direction = 0;
    }
    sevensegment();     
      }
      
  }
  
  if(button_two_state ==HIGH && speed+changeAmount <=255)
  {
    if((direction==1 || direction==0)){
    speed_value = speed_value + speed_ratio;
    analogWrite(in1,speed_value);
    display_count--;
    direction = 2;
    sevensegment();
      else if(speed_value-speed_ratio >=0 && direction==1)){
      speed_value = speed_value - speed_ratio;
    analogWrite(in2,speed_value);
    display_count--;
    if(speed_value == 0){
      direction = 0;
    }
    sevensegment();
  }
      
           }
    
    }
  
  }
  
  delay(3000);
  
}



void sevensegment()
{
  if(display_count == 1 || display_count == -1){
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  }
  if(display_count == 2 || display_count == -2){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  }
  if(display_count == 3 || display_count == -3){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  }
  if(display_count == 4 || display_count == -4){
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if(display_count == 0)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
  }
  
}
