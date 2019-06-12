#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#include "U8glib.h"
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

Servo myServo;

int strip = 8;
//int green = 7;
//int red = 6;
//String password;
int tries = 3;
boolean loggedIn = false;

int potpin = 0;
int val;

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);
 
void setup(){
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(strip, OUTPUT);
  myServo.attach(5);
  val = 0;
  myServo.write(val);
  u8g.setFont(u8g_font_helvB12);
  u8g.setColorIndex(1);
}

void loop(){
  u8g.firstPage();  
  do {
    belong();
  } while( u8g.nextPage() );
  
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter; 
  
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if(content.substring(1) == "B7 F1 86 11" || content.substring(1) == "D7 7D 57 34"){
    Serial.println("Authorized access");
    Serial.println();
    digitalWrite(strip, HIGH);
    
    tries = 3;
    Serial.println("Hi, welcome back friend :P !");
    val = 130;
    myServo.write(val);
    loggedIn = true;

    u8g.firstPage();
    do {  
      draw();    
    } while( u8g.nextPage() );
    delay(1000); 
      u8g.firstPage();
    do {  
      draw2();    
    } while( u8g.nextPage() ); 
    delay(1000);
      u8g.firstPage();
    do {  
      draw3();    
    } while( u8g.nextPage() );
    delay(1000); 
      u8g.firstPage();
    do {  
      draw4();    
    } while( u8g.nextPage() ); 
    delay(1000);
      u8g.firstPage();
    do {  
      draw5();    
    } while( u8g.nextPage() );
    delay(1000); 
      u8g.firstPage();
    do {  
      draw6();    
    } while( u8g.nextPage() ); 
    delay(1000);
      u8g.firstPage();
    do {  
    draw7();    
    } while( u8g.nextPage() );
    delay(1000); 
      u8g.firstPage();
    do {  
      draw8();    
    } while( u8g.nextPage() ); 
    delay(1000); 
      u8g.firstPage();
    do {  
    draw9();    
    } while( u8g.nextPage() );
    delay(1000); 
    
      u8g.firstPage();
    do {  
      draw10();    
    } while( u8g.nextPage() ); 
    delay(1000); 
      u8g.firstPage();
    do {  
      draw11();    
    } while( u8g.nextPage() );
    delay(1000); 
        u8g.firstPage();
    do {  
      draw12();    
    } while( u8g.nextPage() );
    delay(1000); 
        u8g.firstPage();
    do {  
      draw13();     
    } while( u8g.nextPage() );
    delay(1000); 
          u8g.firstPage();
    do {  
      draw14();    
    } while( u8g.nextPage() );
    delay(1000); 
          u8g.firstPage();
    do {  
      draw15();    
    } while( u8g.nextPage() );
    delay(1000); 
    u8g.firstPage();
    do {  
     draw16();    
    } while( u8g.nextPage() );
    
    digitalWrite(strip, LOW);
    val = 0;
    myServo.write(val);
    loggedIn = false;
    
    delay(2000);
    
  }else{
    Serial.println("Access denied");
    tries--;
    digitalWrite(strip, LOW);
    if(tries == 0){
    exit(0);
    }else{
    u8g.firstPage();
    do {  
      drawDenied();    
    } while( u8g.nextPage() );
      Serial.println("WRONG PASSWORD, KSSSST!");
    }
    Serial.println(tries, Serial.print("Tries left: "));  
    delay(3000);
  }
}

void draw(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:15");   
}

void draw2(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:14");    
}

void draw3(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:13");    
}

void draw4(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:12");
}

void draw5(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:11");   
}

void draw6(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:10");  
}

void draw7(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:09");  
}

void draw8(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:08");  
}

void draw9(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:07"); 
}

void draw10(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:06");  
}
void draw11(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:05"); 
}

void draw12(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:04");  
}

void draw13(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:03"); 
}

void draw14(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:02");  
}

void draw15(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "locks in: 00:01");  
}

void draw16(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 15, 15, "Your Packzy");
  u8g.drawStr( 10, 30, "is now locked.");  
}

void drawDenied(){
  u8g.setFont(u8g_font_helvB12);
  u8g.drawStr( 5, 15, "Access Denied!");
  u8g.drawStr( 13, 30, "Try again pls.");  
}

void belong(){
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 25, 15, "This Pakzy");
  u8g.drawStr( 0, 30, "Belongs to Wenyi");  
}
