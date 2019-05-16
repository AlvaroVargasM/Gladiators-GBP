#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <stdlib.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

void setup() {       
  lcd.begin(16,2);
  lcd.backlight();         
  Serial.begin(9600); 
  lcd.setCursor(0,0);
  lcd.print("Gladiators Stats");
  lcd.setCursor(0,1);
  lcd.print("ASTAR |  BCKTNG");
}

int input,num;
int buff[50];
int info[12];
int infoIndex=0;
int j=-1;

int calc(){
    int num=0,x=0;
    for(x;x<=j;x++)
    
          num=num+(buff[x]-48)*pow(10,j-x);

          if(num>100) num++;
    return num;
}

void loop() {
  
  if(Serial.available()>0){
            
      input = Serial.read();
      
      if(input==','){
            num=calc();
            j=-1;

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Recieving: "+ String(num));
            delay(850);
            
            if(num==0){
              
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Res: "+String(info[0])+" vs "+String(info[1]));
              lcd.setCursor(0,1);
              lcd.print("Age: "+String(info[2])+" vs "+String(info[3]));
              delay(4000);
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Int: "+String(info[4])+" vs "+String(info[5]));
              lcd.setCursor(0,1);
              lcd.print("Cond: "+String(info[6])+" vs "+String(info[7]));
              delay(4000);
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("UpStr: "+String(info[7])+" vs "+String(info[8]));
              lcd.setCursor(0,1);
              lcd.print("DwStr: "+String(info[9])+" vs "+String(info[10]));
              delay(4000);

              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Gladiators Stats");
              lcd.setCursor(0,1);
              lcd.print("ASTAR |  BCKTNG");
            }else{
              info[infoIndex] = num;
              infoIndex++;
            }
        }else{
            j++;
            buff[j]=input;
        }
        
    }
}
