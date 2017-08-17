#include <LiquidCrystal.h>
int count = 0;                                          
char input[12];                                         
boolean flag = 0; 
const int pwm = 2 ; //initializing pin 2 as pwm
//const int in_1 = 8 ;
//const int in_2 = 9 ; // flag =0
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
   Serial.begin(9600); 
   //pinMode(pwm,OUTPUT) ; //we have to set PWM pin as output
  // pinMode(in_1,OUTPUT) ; //Logic pins are also set as output
   //pinMode(in_2,OUTPUT) ;   // begin serial port with baud rate 9600bps
  lcd.begin(16, 2);
   
}
void loop()
{
   if(Serial.available())
   {
      count = 0;
      while(Serial.available() && count < 12)          
      {
         input[count] = Serial.read();
         count;
         delay(100);
      }
      Serial.print(input);                             
      delay(1000);
      if((input[0] ^ input[2] ^ input[4] ^ input[6] ^ input[8] == input[10]) && 
         (input[1] ^ input[3] ^ input[5] ^ input[7] ^ input[9] == input[11]))
 
              Serial.println(" hello rajasthan ");
            
      else
            Serial.println("Error");
    Serial.print(input);                             // Print RFID tag number 
      if((input[0] ^ input[2] ^ input[4] ^ input[6] ^ input[8] == input[10]) && 
         (input[1] ^ input[3] ^ input[5] ^ input[7] ^ input[9] == input[11]))
           lcd.setCursor(0,0);
           lcd.print(" Rajasthan Hakathon");
           
           delay(2000);
           lcd.setCursor(0,1);
           lcd.print("It is awsm");
           
           
            
   }else
                lcd.print("");           
   }   


     
