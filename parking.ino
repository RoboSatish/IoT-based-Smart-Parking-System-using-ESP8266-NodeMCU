
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define ir_enter 2
#define ir_back  4
 
#define ir_car1 5 
#define ir_car2 6
#define ir_car3 7
#define ir_car4 8

void Read_Sensor();
int total;


int val;


int S1=0, S2=0, S3=0, S4=0 ;
int flag1=0, flag2=0; 
int slot = 6;  
Servo myservo;


void setup()

{
Serial.begin(9600);
delay(10);
pinMode(ir_car1, INPUT);
pinMode(ir_car2, INPUT);
pinMode(ir_car3, INPUT);
pinMode(ir_car4, INPUT);
pinMode(ir_enter, INPUT);
pinMode(ir_back, INPUT);

 myservo.attach(3); 
 slot = slot-total; 


 lcd.init();
  lcd.backlight();
  lcd.setCursor (0, 1);
  lcd.print(" Welcome  ");
  lcd.setCursor (0, 2);
  //lcd.print(" ");
  delay (5000);
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("   Ishan S Pawar  ");
  lcd.setCursor (0, 1);
  lcd.print("    Car  Parking  ");
  lcd.setCursor (0, 2);
  lcd.print("       System     ");
  delay (5000);
  lcd.clear();

}
void loop()
{
 
 Read_Sensor();

  lcd.setCursor (0, 1);
   if(S1==1)
   {
    lcd.print("S1:Full ");
    Serial.println("S1:Fill ");
   
   }
  else
   {
  
    Serial.println("S1:Empty ");
    lcd.print("S1:Empty");
   }
 
 lcd.setCursor (11, 1);
  if(S2==1)
   {
    
  
   Serial.println("S2:Fill ");
   lcd.print("S2:Full");
    }
  else
   {
 
  Serial.println("S2:empty ");
  lcd.print("S2:Empty");
    }
 
 lcd.setCursor (0, 2);
  if(S3==1)
   {
   
    Serial.println("S3:Fill ");
    lcd.print("S3:Full ");
    }
  else
   {
  
    Serial.println("S3:empty ");
    lcd.print("S3:Empty");
    }
 
  lcd.setCursor (11, 2);
  if(S4==1)
   {
    
    Serial.println("S4:Fill ");
    lcd.print("S4:Full ");
    }
  else
   {
 
  Serial.println("S4:Empty ");
  lcd.print("S4:Empty");
    }


     if(digitalRead(ir_enter)==1)
   {
    Serial.println("Gate ENtry ON");
   
    }
  else
   {
    Serial.println("Gate OFF");
  
    }

total = S1+S2+S3+S4;

  if(digitalRead (ir_enter) == 0) 
   {
    if(total <4)
    {
      Serial.print("Total is:");
      Serial.println(total);
      int pos;
     
  for (pos = 0; pos <= 180; pos += 1) 
  {
    myservo.write(pos);              
    delay(15);   
     
  }
  delay(5000);
 
  for (pos = 180; pos >= 30; pos -= 1) 
  { 
     myservo.write(pos);              
    delay(15);      
   
  }
    }else {
      lcd.setCursor (0, 0);
      lcd.print(" Sorry Parking Full ");
      delay(1000);
      lcd.clear();
    }
  
   }

   if(digitalRead (ir_back) == 0) 
   {
  
      int pos;
     
  for (pos = 0; pos <= 180; pos += 1) 
  {
    myservo.write(pos);              
    delay(15);   
     
  }
  delay(5000);
 
  for (pos = 180; pos >= 30; pos -= 1) 
  { 
     myservo.write(pos);              
    delay(15);      
   
  }
 
  
   }

}

 
void Read_Sensor()
{
 S1=0, S2=0, S3=0, S4=0;
 if(digitalRead(ir_car1) == 0){S1=1;} 
 if(digitalRead(ir_car2) == 0){S2=1;} 
 if(digitalRead(ir_car3) == 0){S3=1;} 
 if(digitalRead(ir_car4) == 0){S4=1;} 
}