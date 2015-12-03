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

const float positiveLow     = 1.012;
const int   positiveLowADC  = 58;
const float positiveHigh    = 13.82;
const int   postiiveHighADC = 822;

const float negativeLow     = 13.62; //1.044;
const int   negativeLowADC  = 960;
const float negativeHigh    = 1.044; //13.56;
const int   negativeHighADC = 8;



void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); //Output led high while in setup mode

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.write("ECE 322 Supply");
  lcd.setCursor(0, 1);
  lcd.write("Nick McComb");

  delay(2000);
  
  lcd.setCursor(0, 1);
  lcd.write("nickmccomb.net");
  
  delay(2000);

  lcd.clear();  //Clear the screen

  digitalWrite(13, LOW); //Output led low when exiting setup mode

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(200); //Random timing ness

  rawRectVoltage = analogRead(A0);
  rawPositiveVoltage = analogRead(A1);
  rawNegativeVoltage = analogRead(A2);

  //(positiveHighADC - positiveLowADC) //ADC travel
  //(positiveHigh - positiveLow) //Voltage Travel
  //(VoltsTravel / ADCs) = Volts per ADC

  //ADCS per Volt

  //Volts per ADC count



  positiveVoltage = rawPositiveVoltage * ((positiveHigh - positiveLow) / (postiiveHighADC - positiveLowADC));
  negativeVoltage = rawNegativeVoltage * ((negativeHigh - negativeLow) / (negativeHighADC - negativeLowADC));
  
  //Final "adjustments"
  negativeVoltage = ((13.6 - negativeVoltage) * -1) - .1;
  
  positiveVoltage += .1;
  
  //lcd.clear();  //Clear the display

  lcd.setCursor(0, 0);
  lcd.print("V-");

  lcd.setCursor(0, 1);
  lcd.print(negativeVoltage, 1);
  
  if(negativeVoltage > -10.0)
    lcd.print(" ");

  lcd.setCursor(6, 0);
  lcd.print("V+");

  lcd.setCursor(6 , 1);
  lcd.print(positiveVoltage, 1);

  if(positiveVoltage < 10.0)
    lcd.print(" ");

  lcd.setCursor(13, 0);
  lcd.print("ECE");
  
  lcd.setCursor(13, 1);
  lcd.print("322");
  
}
