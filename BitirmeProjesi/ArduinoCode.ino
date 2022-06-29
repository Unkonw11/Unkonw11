
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

IRsend irsend;
int pwmPin = 6;
int value = 0;

void setup()
{
  pinMode(pwmPin,OUTPUT);
  Serial.begin(9600);
}
 
void loop() {

while(Serial.available()>0)
  {
    switch(Serial.read()){

      case '1' : irsend.sendNEC(0xFFC03F, 32);
                 break;
       
        delay(500);
      case '2' : irsend.sendNEC(0xFF40BF, 32);
          break;

      case'3':
               value=value+25;
               if( value >=255){
                value=255;
               }
               analogWrite(pwmPin,value);
               delay(30);
               break;

      case '4' : 
                 value=value-25;
                 if (value<=0){
                  value=0;
                 }
                 analogWrite(pwmPin,value);
                 delay(30);
                 
                
          break;
      default: break;    
              
          
    }
  }
  
  
   
}
