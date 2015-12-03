// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


float rectifiedVoltage = 0.0;
float positiveVoltage = 0.0;
float negativeVoltage = 0.0;

int rawRectVoltage = 0;
int rawNegativeVoltage = 0;
int rawPositiveVoltage = 0;

const float positiveLow     = 1.01;
const int   positiveLowADC  = 77;
const float positiveHigh    = 19.7;
const int   postiiveHighADC = 777;

const float negativeLow     = 1.01;
const int   negativeLowADC  = 777;
const float negativeHigh    = 19.7;
const int   negativeHighADC = 77;



void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);  
  digitalWrite(13, HIGH); //Output led high while in setup mode
  
  lcd.begin(16, 2);
  
  lcd.setCursor(0,0);
  lcd.write("ECE 322 Supply");
  lcd.setCursor(0, 1);
  lcd.write("Nick McComb");
 
  delay(500); 
  
  digitalWrite(13, LOW); //Output led low when exiting setup mode
  
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50); //Random timing ness
  
  rawRectVoltage = analogRead(A0);
  rawPositiveVoltage = analogRead(A1);
  rawNegativeVoltage = analogRead(A2);
  
  //(positiveHighADC - positiveLowADC) //ADC travel
  //(positiveHigh - positiveLow) //Voltage Travel
  
  //(VoltsTravel / ADCs) = Volts per ADC
  
  //ADCS per Volt

  //Volts per ADC count
  
  positiveVoltage = rawPositiveVoltage * ((positiveHigh - positiveLow) / (postiiveHighADC - positiveLowADC));
  
  lcd.setCursor(0 , 0);
  lcd.print("rect");
  
  lcd.setCursor(5, 0);
  lcd.print("v+");

  lcd.setCursor(10, 0);
  lcd.print("v-");
  
  
  lcd.setCursor(0 , 1);
  lcd.print(rawRectVoltage);
  
  lcd.setCursor(5 , 1);
  lcd.print(rawPositiveVoltage);
  
  lcd.setCursor(10, 1);
  lcd.print(rawNegativeVoltage);
  
}
