#include<SoftwareSerial.h>
#include<stdlib.h>

SoftwareSerial esp(2,3);
#define SSID "njfi"
#define PASS "adminnjfi"
#define IP "184.106.153.149"
 char getw='a';
char rec[200];
int soil =A1;
void setup() {
               pinMode(12,OUTPUT);
               pinMode(soil,INPUT);
           
              Serial.begin(9600);
              esp.begin(9600);
              esp.println("AT");
              delay(1000);
              
              if(esp.find("OK"))
              {
                Serial.println("initializing....");
               }
                boolean tr;
                //do {
                  //tr = connectWiFi();}
              // while(true==tr);
                    
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(12,HIGH);
            String soil1=String(analogRead(soil));
              server();
              datapost(soil1,"400");
              dataget();
             
//esp.println("AT+CIPCLOSE");

           
}
   void datapost(String soil,String workstatus)
   {
     String getstr = "GET https://api.thingspeak.com/update?api_key=NR7P972HWDR72PU3&field1="; //200&field2=12"
       getstr +=soil+"&field2";
       getstr +=workstatus;
              String getstr2 ="AT+CIPSEND=";
              
               int i=getstr.length();
               i=i+2;
               getstr2 += String(i);
                esp.print(getstr2);
                esp.print("\r\n");
                delay(2000);
                if(esp.find(">"))
                {
                 esp.println(getstr);
                }
delay(2000);
    }

void server()
{
   String cmd="AT+CIPSTART=\"TCP\",\"";
              cmd +="184.106.153.149";
              cmd +="\",80";
              esp.println(cmd);
              delay(1000);
              if(esp.find("CONNECT"))
              {
                Serial.println("connected with server");
                
                }
            else if (esp.find("ERROR"))
            {
              Serial.println("failed to connect with server");
              }
  }
boolean connectWiFi()
{
  esp.println("AT+CWMODE=1");//WiFi STA mode - if '3' it is both client and AP
  delay(2000);
  //Connect to Router with AT+CWJAP="SSID","Password";
  // Check if connected with AT+CWJAP?
  String cmd="AT+CWJAP=\""; // Join accespoint
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  esp.println(cmd);
  delay(6000);
  if(esp.find(""))
  {
    Serial.println("RECEIVED: OK");
    return true;
  }
  else
  {
    Serial.println("RECEIVED: Error");
    return false;
  }

  cmd = "AT+CIPMUX=0";// Set Single connection
  esp.println( cmd );
  delay(100);
  if( esp.find( "ERROR") )
  {
    Serial.print( "RECEIVED: Error" );
    return false;
  }
}
void dataget()
{
   String getstr1 = "GET https://api.thingspeak.com/channels/284126/feeds.json?api_key=NPELCUHGSJ1ERTMB&results=1HTTP/1.1"; 
       //getstr +=soil+"&field2";
       //getstr +=workstatus;
              String getstr2 ="AT+CIPSEND=";
              
               int i=getstr1.length();
               i=i+2;
               getstr2 += String(i);
                esp.print(getstr2);
                esp.print("\r\n");
               
                delay(2000);
                esp.print(getstr1);
                esp.print("\r\n");
                delay(100);
             
              if(esp.find("feeds"))
              {
                 String rec= String(esp.readString());
               int len= rec.length();
              
               Serial.println(rec);
               char value[3];
               int h=0;
               for(i=0;i<len;i++)
               if(rec[i]==':')
               Serial.println(rec[i+1]);
              
               
               }
               }
//delay(2000);
    


  
  
