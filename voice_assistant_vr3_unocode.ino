#include <SoftwareSerial.h>

#include "VoiceRecognitionV3.h"
VR myVR(2,3);    // 2:RX 3:TX, you can choose your favorite pins.

uint8_t record[7]; // save record
uint8_t buf[64];

int group = 0;
#define switchRecord        (0)
#define group0Record1       (1) 
#define group0Record2       (2) 
#define group0Record3       (3) 
#define group0Record4       (4) 
#define group0Record5       (5) 
#define group0Record6       (6) 
#define group1Record1       (7) 
#define group1Record2       (8) 
#define group1Record3       (9) 
#define group1Record4       (10) 
#define group1Record5       (11) 
#define group1Record6       (12) 
void setup()
{
  /** initialize */
  myVR.begin(9600);
  Serial.begin(115200);
  
// Serial.println("Elechouse Voice Recognition V3 Module\r\nMulti Commands sample");
 
    if(myVR.clear() == 0){
   // Serial.println("Recognizer cleared.");
  }else{
   // Serial.println("Not find VoiceRecognitionModule.");
   // Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  record[0] = switchRecord;
  record[1] = group0Record1;
  record[2] = group0Record2;
  record[3] = group0Record3;
  record[4] = group0Record4;
  record[5] = group0Record5;
  record[6] = group0Record6;
  group = 0;
  if(myVR.load(record, 7) >= 0){
    printRecord(record, 7);
  //  Serial.println(F("loaded."));
   }
}
void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case switchRecord:
        Serial.println('0');
      
        if(group == 0){
          group = 1;
         myVR.clear();
          record[0] = switchRecord;
          record[1] = group1Record1;
          record[2] = group1Record2;
          record[3] = group1Record3;
          record[4] = group1Record4;
          record[5] = group1Record5;
          record[6] = group1Record6;
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
           // Serial.println(F("loaded."));
            //    Serial.println('y');
           if(myVR.load((uint8_t)group1Record1) >= 0){
    //  Serial.println("onRecord1 loaded");
      }     
}
         }else{
          group = 0;
         myVR.clear();
          record[0] = switchRecord;
          record[1] = group0Record1;
          record[2] = group0Record2;
          record[3] = group0Record3;
          record[4] = group0Record4;
          record[5] = group0Record5;
          record[6] = group0Record6;
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
    //       Serial.println(F("loaded."));
      //         Serial.println('x');
   }
        }
        break;
         case group0Record1:
        Serial.println('1');
        // megaSerial.println('1');
        break;
      case group0Record2:
               Serial.println('2');
              //  megaSerial.println('2');
        break;
        case group0Record3:
        Serial.println('3');
     //    megaSerial.println('3');
        break;
      case group0Record4:
                Serial.println('4');
            //     megaSerial.println('4');
        break;
        case group0Record5:
        Serial.println('5');
       //  megaSerial.println('5');
        break;
      case group0Record6:
                Serial.println('6');
//                 megaSerial.println('6');

        break;
        case group1Record1:
        Serial.println('7');
       //  megaSerial.println('7');
        break;
      case group1Record2:
                Serial.println('8');
         //        megaSerial.println('8');
        break;
        case group1Record3:
        Serial.println('9');
       //  megaSerial.println('9');
        break;
      case group1Record4:
                Serial.println('A');
         //        megaSerial.println('A');
        break;
        case group1Record5:
        Serial.println('B');
     //    megaSerial.println('B');
        break;
      case group1Record6:
                Serial.println('C');
         //        megaSerial.println('C');
        break;
      default:
     //   Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
}
void printSignature(uint8_t *buf, int len)
{
  int i;
  for(i=0; i<len; i++){
    if(buf[i]>0x19 && buf[i]<0x7F){
    //  Serial.write(buf[i]);
    }
    else{
   //   Serial.print("[");
   //   Serial.print(buf[i], HEX);
   //   Serial.print("]");
    }
  }
}
void printVR(uint8_t *buf)
{
 // Serial.println("VR Index\tGroup\tRecordNum\tSignature");
 // Serial.print(buf[2], DEC);
 // Serial.print("\t\t");

  if(buf[0] == 0xFF){
  //  Serial.print("NONE");
  }
  else if(buf[0]&0x80){
  //  Serial.print("UG ");
   // Serial.print(buf[0]&(~0x80), DEC);
  }
  else{
  //  Serial.print("SG ");
   // Serial.print(buf[0], DEC);
  }
 // Serial.print("\t");
 // Serial.print(buf[1], DEC);
 // Serial.print("\t\t");
  if(buf[3]>0){
    printSignature(buf+4, buf[3]);
  }
  else{
  //  Serial.print("NONE");
  }
  //Serial.println();
}
void printRecord(uint8_t *buf, uint8_t len)
{
 // Serial.print(F("Record: "));
  for(int i=0; i<len; i++){
  //  Serial.print(buf[i], DEC);
  //  Serial.print(", ");
  }
}
