
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//initialize light colors pins
int red = 9;
int green = 8;
//initialize the deactivation/detonation wires
int inDead = 6;
int inGood = 7;


void setup() {
//initialize LCD 
  lcd.begin(16, 2);
  
  //set the  pins modes
    pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(inDead, INPUT);
  pinMode(inGood, INPUT);
  
  digitalWrite(red, HIGH);
  
//two hour loop
     for(long i=7200; i>=0 && digitalRead(inDead)!=0 && digitalRead(inGood)!=0;i--){
       //reset the LCD cursor to the beginning of the line to overwrite previous value
         lcd.setCursor(9, 0);
         //print the time
      lcd.print(i); 
      //delay 1 second 
      delay(1000);
     }
    //when loop breaks
     if(digitalRead(inGood)==0){
       //deacticvation wire was disconnected
           lcd.setCursor(0, 0);
      lcd.print("Bomb deactivated."); 
    //turn on green light
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      //game won
     }
     else{
        //detonation wire was disconnected
       lcd.setCursor(0, 0);
      lcd.print("Boom!"); 
      //game over
     }
}

void loop() {
 //nothing to loop through
}
    
  


