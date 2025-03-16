char switchstate;
#include "DFRobotDFPlayerMini.h"

// Create the Player object
DFRobotDFPlayerMini player;
void setup() {
  
 Serial.begin(115200);//init uno communication
 Serial1.begin(9600);//init gsm communication
 Serial2.begin(9600);// init df player communication

 if (player.begin(Serial2)) {
   // Set volume to maximum (0 to 30).
  player.volume(30);
  }   else {
  }
 
}

void loop() {
 
 //communicate with uno
  while(Serial.available()>0){
  switchstate=Serial.read();
  delay(15);

  if(switchstate=='0'){
   
    player.play(1);
   }
   else if (switchstate=='1'){
    player.play(2);
   }
   else if (switchstate=='2'){
    player.play(3);
   }
   else if (switchstate=='3'){
    player.play(4);
   }
   else if (switchstate=='4'){
    player.play(5);
   }
   else if (switchstate=='5'){
    player.play(6);
   }
   else if (switchstate=='6'){
    player.play(7);
   }
   else if (switchstate=='7'){
    player.play(8);
    
   }
   else if (switchstate=='8'){
    player.play(9);
   }
   else if (switchstate=='9'){
    player.play(10);
   }
   else if (switchstate=='A'){
    Serial1.println("AT");
    Serial1.println("ATD+ +8801979280250;");
   }
   else if (switchstate=='B'){
    Serial1.println("AT");
    Serial1.println("ATD+ +8801717159202;");
   }
   else if (switchstate=='C'){
  Serial1.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  Serial1.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  Serial1.println("AT+CMGS=\"+8801979280250\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  Serial1.print("I am arduino"); //text content
 updateSerial();
  Serial1.write(26);
  }
  }
}
void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    Serial1.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(Serial1.available()) 
  {
    Serial.write(Serial1.read());//Forward what Software Serial received to Serial Port
  }
}
