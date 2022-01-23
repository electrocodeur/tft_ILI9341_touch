/* ECRAN        |STM32
                |
   VCC          |3.3V
   GND          |GND
   CS           |PA4
   RESET        |PA2
   DC           |PA3
   SDI(MOSI)    |PA7
   SCK          |PA5
   LED          |3.3V
   SDO(MISO)    |PA6
   T_CLK        |PB13
   T_CS         |PB12
   T_DIN        |PB15
   T_DO         |PB14
   T_IRQ        |PA8
*/
#include "URTouch.h"
URTouch  myTouch( PB13, PB12, PB15, PB14, PA8);
//                T_CLK T_CS  T_DIN T_DO  T_IRQ
#include "SPI.h"
#include "Adafruit_GFX_AS.h"
#include "Adafruit_ILI9341_STM.h"

// Pinout for Maple Mini (// For the Adafruit shield, these are the default)
#define TFT_CS       PA4 //  13 // PB4                  
#define TFT_DC       PA3 // 12 // PA15                
#define TFT_RST      PA2 // 14 // PB3  

Adafruit_ILI9341_STM tft = Adafruit_ILI9341_STM(TFT_CS, TFT_DC, TFT_RST); // Use hardware SPI

void setup() {
  Serial.begin(9600);
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(1);
  tft.setTextSize(4);
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_EXTREME);
  tft.setTextColor(ILI9341_BLUE);
  tft.setCursor(1, 80);
  tft.println("ELECTROCODEUR");
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_DARKGREY);
  tft.setCursor(1, 150);
  tft.println("Powered by STM32");
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(30);
  tft.setCursor(210, 40);
  tft.println(".");
}


void loop(void) {
  myTouch.read();
  int x = myTouch.getX();
  int y = myTouch.getY();
  Serial.print("  x : ");
  Serial.println(x);
  Serial.print("  y : ");
  Serial.println(y);
  delay(100);
}
