#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2);
const int startwire  = 2;
const int endwire = 3;
const int buzzer = 4;
int start, endl;
void setup(void)
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(startwire, INPUT_PULLUP);
  pinMode(startwire, INPUT_PULLUP);
}
void loop(void)
{  
  start = digitalRead(startwire);
  endl = digitalRead(endwire); 
  Serial.print(start);
  Serial.print("\n");
  Serial.print(endl);  
  if (start == LOW && endl== LOW ){
    digitalWrite(buzzer, HIGH);
    delay(1000); 
    digitalWrite(buzzer, LOW); 
    LCD.setCursor(0,0);
    LCD.print("Try Again" );   
    Serial.print("Try Again");        
  }
  else if (start == HIGH && endl== LOW){
    LCD.setCursor(0,0);
    LCD.print("CONGRATS");
    Serial.print("CONGRATS");
  }
 delay(1000); 
}
