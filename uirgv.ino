
//Bibs
#include<Wire.h>

#include <Adafruit_NeoPixel.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

//Variablen & Stuff


const int SW_pin = 2; 
const int X_pin = 0; 
const int Y_pin = 1;

 int ebene = 0;
int spalte =0;



#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN      6
#define NUMPIXELS 10
#define DELAYVAL 500

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup(){

//LCD
lcd.begin(16,2);
lcd.setRGB(colorR, colorG, colorB);

//Joystick Pins
pinMode(SW_pin, INPUT);
digitalWrite(SW_pin, HIGH);
Serial.begin(9600);

//RGB
pixels.begin();

}


void loop(){

lcd_test();
joystick_test();
RGB_test();

Serial.println(checkjoystick_oben());

  
}



boolean checkjoystick_oben(){

if(analogRead(Y_pin)>600){

return true;
  
}else{

return false;  
}
}


boolean checkjoystick_unten(){

if(analogRead(Y_pin)<400){

return true;
    
}else{

return false;  
}
}

boolean checkjoystick_rechts(){

if(analogRead(X_pin)<400){

return true;
    
}else{

return false;  
}
}


boolean checkjoystick_links(){

if(analogRead(X_pin)>600){

return true;
  
}else{

return false;  
}
}

























void joystick_test(){

Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);
  
}

void lcd_test(){

  lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
  lcd.print("Hello World!"); // Print the string "Hello World!"
  lcd.setCursor(2, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("LCD tutorial");



  
}

void RGB_test(){
  pixels.clear();
pixels.setBrightness(10);
pixels.setPixelColor(0, pixels.Color(255, 255, 255));
pixels.setPixelColor(1, pixels.Color(255, 0, 0));
pixels.setPixelColor(2, pixels.Color(0, 255, 0));
pixels.setPixelColor(3, pixels.Color(0, 0, 255));
pixels.setPixelColor(4, pixels.Color(255, 0, 255));
pixels.setPixelColor(5, pixels.Color(255, 255, 0));
for(int a = 6; a<10; a++){
  pixels.setPixelColor(a, pixels.Color(0, 255, 255));
}


pixels.show();
}
