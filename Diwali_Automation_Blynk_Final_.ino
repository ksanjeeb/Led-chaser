#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define LED 16

char ssid[] = "PUT UR SSID";
char pass[] = "WIFI PASSWORD";
char auth[] = "AUTH TOKEN FROM BLYNK";
int temp ;
int sec = 100;

//----------------------- function-1 for led lights---------------------------------------------    
void p1(){
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    Serial.println("All Glowing");
  }
void p2(){
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    Serial.println("pattern1");
  }
void p3(){
    digitalWrite(14,LOW);
    delay(sec);
    digitalWrite(12,LOW);
    delay(sec);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    delay(sec);
    digitalWrite(12,HIGH);
    delay(sec);
    digitalWrite(13,HIGH);
    delay(sec);
    Serial.println("pattern2");
  }
 void p4(){
    digitalWrite(14,LOW);
    delay(sec);
    digitalWrite(12,LOW);
    delay(sec);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(12,HIGH);
    delay(sec);
    digitalWrite(14,HIGH);
    delay(sec);
    Serial.println("pattern3");
  }
void p5(){
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(sec);
    Serial.println("pattern4");
    }
 void p6(){
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(sec);
    Serial.println("pattern5");
    }
  void p7(){
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    Serial.println("pattern6");
    }
  void p8(){
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(sec);
    Serial.println("pattern7");
    }
  void p9(){
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(sec);
    digitalWrite(14,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(sec);
    digitalWrite(14,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(sec);
    Serial.println("pattern8");
    }
 //---------------------------------------blynk write mode----------------------------------------------


// -------------------------------------------------------------------------------------------------------
BLYNK_WRITE(V0) {
  int v = param.asInt();
  switch ( param.asInt())
  {
    case 1:
    temp = 1;
    break;
     
    case 2:
    temp = 2;
    break;
    
    case 3: 
    temp = 3;
    break;
    
    case 4:
    temp = 4;
    break; 
    
    case 5:
    temp = 5; 
    break;
    
    case 6:
    temp = 6; 
    break;
    
    case 7:
    temp = 7;
    break; 
    
    case 8: 
    temp = 8;
    break;
    
    case 9: 
    temp = 9;
    break;

    case 10: 
    temp = 10;
    break;
    
    default:
      Serial.println("Unknown item selected");
  }
}
//-----------------------------------delay ------------------------------------------------------------
BLYNK_WRITE(V2)
{
  sec = param.asInt();
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  pinMode(14,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(LED,OUTPUT); 
}

void loop()
{
    Blynk.run();
    Serial.println(temp);
    Serial.println(sec);
    if(temp == 1)
    {
      p1();
    }
    else if(temp ==2)
    {
      p2();
    }
    else if(temp ==3)
    {
      p3();
    }
    else if(temp ==4)
    {
      p4();
    }
    else if(temp ==5)
    {
      p5();
    }
    else if(temp ==6)
    {
      p6();
    }
    else if(temp ==7)
    {
      p7();
    }
    else if(temp ==8)
    {
      p8();
    }
    else if(temp ==9)
    {
      p9();
    }
    else if(temp == 10)
    {
      p9();p2();p3();p4();p9();p5();p6();p7();p8();p9();p3();p4();
      Serial.println("Random");
    }
 }
