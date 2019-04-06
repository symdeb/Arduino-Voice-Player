#include "DFPlayer_Mini_Mp3.h"


 void setup()
 {

   pinMode(3, OUTPUT); 
   pinMode(6, OUTPUT); 
   pinMode(9, OUTPUT); 
   
  pinMode(A0, INPUT);  
      
  pinMode(A2, INPUT);       
  pinMode(A5, INPUT);       

   // put your setup code here, to run once:
   
   Serial.begin(9600);
   mp3_set_serial (Serial); //set Serial for DFPlayer-mini mp3 module
   mp3_set_volume (30);
   mp3_stop ();
 
}

void loop()
{
   int sound;

   Serial.print("Start Test, silence about 3, maximum about 300,  GND = 1024 \n");

  
   /* LED ON */
   digitalWrite(3,0);
   digitalWrite(6,0); 
   digitalWrite(9,0); 

  int V0, V1, V2;
  unsigned long V0max = 0, V1max = 0 , V2max = 0;
  char result[200];
 
  /* Sample the AC signal on the ADC input to find the maxiumm aplitude */
    
  for (int x = 0; x < 100; x ++)
  {
    V0 = analogRead(A0);
    delay(10);
    V1 = analogRead(A2);
    delay(10);
    V2 = analogRead(A5);
    delay(10);
    if (V0 > 0) V0max += V0;
    if (V1 > 0) V1max += V1;
    if (V2 > 0) V2max += V2;
  }
 
  /* LED off */
   digitalWrite(3,1);
   digitalWrite(6,1); 
   digitalWrite(9,1); 

    long R0= 10240 - (V0max / 10);
    sprintf(result, "%09d ", 10240 - (V0max/ 10));
    Serial.print(result);
   
    long R1= 10240 - (V1max / 10);
    sprintf(result, "%09d ", R1);
    Serial.print(result);
    
    long R2= 10240 - (V2max / 10);
    sprintf(result, "%09d ", R2);
    Serial.print(result);


    long total = R0 + R1 + R2;
    sprintf(result, "%09d ", total);
    Serial.print(result);
    Serial.print("\n");

   /* Play asound */
   /* if (total < 500) sound = 1;*/
   if (total < 2000)  sound = 1;
   else if (total < 3000) sound = 1;
   else if (total < 4000) sound = 2;
   else if (total < 5000) sound = 2;
   else if (total < 6000) sound = 3;
   else if (total < 7000) sound = 3;
   else sound = 4;

   Serial.print("\nsound = ");
   Serial.print(sound);
   Serial.print("\n");

   mp3_set_volume(30);
   mp3_play (sound);   
   delay (10000);
   
   mp3_stop();
   
}
