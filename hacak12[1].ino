int trigger=11 ;
int echo=12;
int trigger1=9;
int echo1=10;
int lr=6;
int rimo=5;
int rimo1=4;
int lmo=3;
int lmo1=2;
int cutter;
int c;
int m1=7;
int m2=8;
int mo=A1;
int m=0;
int mode;
int mot1=5;
int mot2=6;
void setup()
{
Serial.begin(9600);
pinMode(mot1,OUTPUT);
pinMode(mot2,OUTPUT);
pinMode(rimo,OUTPUT);
pinMode(rimo1,OUTPUT);
pinMode(lmo,OUTPUT);
pinMode(lmo1,OUTPUT);
pinMode(cutter,OUTPUT);
pinMode(echo,INPUT);
pinMode(echo1,INPUT);
pinMode(trigger,OUTPUT);
pinMode(trigger1,OUTPUT);
pinMode(lr,INPUT);
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(mo,INPUT);
Serial.begin(9600);
mode=0;
}
void loop()
{ 
  if(mode==1){
  
  long x,y;
 digitalWrite(trigger,LOW);
  delayMicroseconds(2);
   digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  x=pulseIn(echo,HIGH);
  y=x/29/2;
  Serial.println(y);
   long u,v;
  digitalWrite(trigger1,LOW);
  delayMicroseconds(2);
   digitalWrite(trigger1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger1,LOW);
  delayMicroseconds(2);
  u=pulseIn(echo1,HIGH);
  v=u/29/2;
  Serial.println(y);
  Serial.println(v);
 c=digitalRead(lr);
Serial.println(c);
if(c==HIGH)
  {  
    digitalWrite(cutter,HIGH);
}
else
  {
    digitalWrite(cutter,LOW);
  }
    digitalWrite(rimo,HIGH);
    digitalWrite(lmo,HIGH);
    digitalWrite(rimo1,LOW);
    digitalWrite(lmo1,LOW);
 if(y<10)
  {
    digitalWrite(rimo,LOW);
    digitalWrite(lmo,LOW);
    digitalWrite(rimo1,LOW);
    digitalWrite(lmo1,LOW);
    Serial.print("stop");
    if(v<10)
    {
        digitalWrite(rimo,HIGH);
        digitalWrite(rimo1,LOW);
        digitalWrite(lmo,LOW);
        digitalWrite(lmo1,HIGH);
        delay(2000);
        Serial.println("right");
     }
    delay(1000);
   }
   
   
  }
      else{
            char stat=Serial.read();
    if(stat=='F')
    {
      Serial.print("forward");
      digitalWrite(mot1,HIGH);
      digitalWrite(mot2,LOW);
      
      }else if(stat=='B')
      {
        Serial.print("back");
        }else if(stat=='L')
        {
          Serial.print("Left");
          }else if(stat=='R')
          {
            Serial.print("right");
            }else
            {digitalWrite(mot1,LOW);
      digitalWrite(mot2,LOW);
              Serial.println("stop");}
    
  delay(2000);
        
      }
    
 
}


  
  

 

