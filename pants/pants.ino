//based on the DFRobot-Adafruit source code for LED Strips found here: 
//http://www.dfrobot.com/wiki/index.php/Digital_RGB_LED_Weatherproof_Strip_60_LED-(1M)_SKU:FIT0356

#include <Adafruit_NeoPixel.h>

#define PIN_A 9     //The signal pin connected with Arduino    
#define PIN_B 10
#define LED_COUNT 60 // the amount of the leds of your strip(60 LEDs per meter)

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN_A, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledz = Adafruit_NeoPixel(LED_COUNT, PIN_B, NEO_GRB + NEO_KHZ800);
char state;

void setup()
{
  Serial.begin(9600);
  leds.begin();  // Call this to start up the LED strip.
  ledz.begin();  // Call this to start up the LED strip.
  clearLEDs();   // This function, defined below, turns all LEDs off...
  leds.show();   // ...but the LEDs don't actually update until you call this.
  ledz.show();
}

void loop()
{

  if (Serial.available() > 0) {
    state = Serial.read();
    Serial.println(state);
  }

  if (state == '1') {
    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    ledz.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      rainbow(i);
      delay(50);  // Delay between rainbow slides
    }
  }   // turn the LED on (HIGH is the voltage level)

  else if (state == '2') {

    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    ledz.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      shirley(i);
      delay(50);  // Delay between rainbow slides
    }
  }

  else if (state == '3') {

    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    ledz.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      nan(i);
      delay(50);  // Delay between rainbow slides
    }
  }

  else if (state == '4') {

    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    ledz.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      zz(i);
      delay(50);  // Delay between rainbow slides
    }
  }

  else if (state == '5') {
    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    ledz.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      greenspan(i);
      delay(50);  // Delay between rainbow slides
    }
  }

  else if (state == '6') {
    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      jingyi(i);
      delay(50);  // Delay between rainbow slides
    }
  }

  else if (state == '7') {
    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    ledz.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      nicole(i);
      delay(50);  // Delay between rainbow slides
    }
  }
  
    else if (state == '8') {
    clearLEDs();   // This function, defined below, turns all LEDs off...
    leds.show();
    ledz.show();
    for (int i = 0; i < LED_COUNT; i++)
    {
      richard(i);
      delay(50);  // Delay between rainbow slides
    }
  }
}


// Sets all LEDs to off, but DOES NOT update the display;
// call leds.show() to actually turn them off after this.
void clearLEDs()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
    ledz.setPixelColor(i, 0);
  }
}


// Prints a rainbow on the ENTIRE LED strip.
//  The rainbow begins at a specified position.
// ROY G BIV!
void rainbow(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, rainbowOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, rainbowOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}

void nan(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, nanOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, nanOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}

void shirley(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, shirleyOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, shirleyOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}

void zz(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, zzOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, zzOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}

void greenspan(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, greenspanOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, greenspanOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}

void jingyi(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, jingyiOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, jingyiOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}

void nicole(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, nicoleOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, nicoleOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}


void richard(byte startPosition)
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, richardOrder((rainbowScale * (i + startPosition)) % 192));
    ledz.setPixelColor(i, richardOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
  ledz.show();
}

// Input a value 0 to 191 to get a color value.
// The colors are a transition red->yellow->green->aqua->blue->fuchsia->red...
//  Adapted from Wheel function in the Adafruit_NeoPixel library example sketch
uint32_t shirleyOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0x66, 0x00, 0xFF);
    return ledz.Color(0x66, 0x00, 0xFF);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0x00, 0xFF, 0xFF);
    return ledz.Color(0x00, 0xFF, 0xFF);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    return leds.Color(0x66, 0x00, 0xFF);
    return ledz.Color(0x66, 0x00, 0xFF);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    //return leds.Color(0, 0xFF - position * 8, 0xFF);
    return leds.Color(0x00, 0xFF, 0xFF);
    return ledz.Color(0x00, 0xFF, 0xFF);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    //return leds.Color(position * 8, 0, 0xFF);
    return leds.Color(0x66, 0x00, 0xFF);
    return ledz.Color(0x66, 0x00, 0xFF);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    //return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return leds.Color(0x00, 0xFF, 0xFF);
    return ledz.Color(0x00, 0xFF, 0xFF);
  }
}

uint32_t rainbowOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0xFF, position * 8, 0);
    return ledz.Color(0xFF, position * 8, 0);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0xFF - position * 8, 0xFF, 0);
    return ledz.Color(0xFF - position * 8, 0xFF, 0);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    return leds.Color(0, 0xFF, position * 8);
    return ledz.Color(0, 0xFF, position * 8);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    return leds.Color(0, 0xFF - position * 8, 0xFF);
    return ledz.Color(0, 0xFF - position * 8, 0xFF);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    return leds.Color(position * 8, 0, 0xFF);
    return ledz.Color(position * 8, 0, 0xFF);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return ledz.Color(0xFF, 0x00, 0xFF - position * 8);
  }
}

uint32_t nanOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0x00, 0x5A, 0x96);
    return ledz.Color(0x00, 0x5A, 0x96);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0x00, 0x8F, 0xC5);
    return ledz.Color(0x00, 0x8F, 0xC5);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    //return leds.Color(0, 0xFF, position * 8);
    return leds.Color(0x00, 0xCE, 0xD7);
    return ledz.Color(0x00, 0xCE, 0xD7);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    //return leds.Color(0, 0xFF - position * 8, 0xFF);
    return leds.Color(0x26, 0xF7, 0xDB);
    return ledz.Color(0x26, 0xF7, 0xDB);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    //return leds.Color(position * 8, 0, 0xFF);
    return leds.Color(0xCD, 0xFC, 0xD8);
    return ledz.Color(0xCD, 0xFC, 0xD8);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    //return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return leds.Color(0x66, 0xFC, 0x99);
    return ledz.Color(0x66, 0xFC, 0x99);
  }
}

uint32_t zzOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0xA8, 0x3A, 0x7F);
    return ledz.Color(0xA8, 0x3A, 0x7F);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0xD5, 0x79, 0xC2);
    return ledz.Color(0xD5, 0x79, 0xC2);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    //return leds.Color(0, 0xFF, position * 8);
    return leds.Color(0xE2, 0x33, 0xFF);
    return ledz.Color(0xE2, 0x33, 0xFF);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    //return leds.Color(0, 0xFF - position * 8, 0xFF);
    return leds.Color(0xA2, 0x81, 0xB0);
    return ledz.Color(0xA2, 0x81, 0xB0);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    //return leds.Color(position * 8, 0, 0xFF);
    return leds.Color(0xFF, 0x00, 0x99);
    return ledz.Color(0xFF, 0x00, 0x99);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    //return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return leds.Color(0x57, 0x06, 0x8C);
    return ledz.Color(0x57, 0x06, 0x8C);
  }
}

uint32_t greenspanOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0x1A, 0xFF, 0x00);
    return ledz.Color(0x1A, 0xFF, 0x00);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0xCC, 0xE3, 0x00);
    return ledz.Color(0xCC, 0xE3, 0x00);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    //return leds.Color(0, 0xFF, position * 8);
    return leds.Color(0xAD, 0xDB, 0x00);
    return ledz.Color(0xAD, 0xDB, 0x00);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    //return leds.Color(0, 0xFF - position * 8, 0xFF);
    return leds.Color(0x1A, 0xB5, 0x00);
    return ledz.Color(0x1A, 0xB5, 0x00);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    //return leds.Color(position * 8, 0, 0xFF);
    return leds.Color(0x00, 0x79, 0x00);
    return ledz.Color(0x00, 0x79, 0x00);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    //return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return leds.Color(0x60, 0xBF, 0x00);
    return ledz.Color(0x60, 0xBF, 0x00);
  }
}


uint32_t jingyiOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0xFF, 0x00, 0x00);
    return ledz.Color(0xFF, 0x00, 0x00);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0x00, 0xFF, 0x00);
    return ledz.Color(0x00, 0xFF, 0x00);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    //return leds.Color(0, 0xFF, position * 8);
    return leds.Color(0x00, 0x20, 0x57);
    return ledz.Color(0x00, 0x20, 0x57);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    //return leds.Color(0, 0xFF - position * 8, 0xFF);
    return leds.Color(0xFF, 0x00, 0x00);
    return ledz.Color(0xFF, 0x00, 0x00);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    //return leds.Color(position * 8, 0, 0xFF);
    return leds.Color(0x00, 0xFF, 0x00);
    return ledz.Color(0x00, 0xFF, 0x00);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    //return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return leds.Color(0x00, 0x20, 0x57);
    return ledz.Color(0x00, 0x20, 0x57);
  }
}


uint32_t richardOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0x2B, 0x2B, 0x2B);
    return ledz.Color(0x2B, 0x2B, 0x2B);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0x48, 0x48, 0x48);
    return ledz.Color(0x48, 0x48, 0x48);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    //return leds.Color(0, 0xFF, position * 8);
    return leds.Color(0x75, 0x75, 0x75);
    return ledz.Color(0x75, 0x75, 0x75);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    //return leds.Color(0, 0xFF - position * 8, 0xFF);
    return leds.Color(0xFF, 0x00, 0x00);
    return ledz.Color(0xFF, 0x00, 0x00);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    //return leds.Color(position * 8, 0, 0xFF);
    return leds.Color(0xFF, 0xFF, 0xFF);
    return ledz.Color(0xFF, 0xFF, 0xFF);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    //return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return leds.Color(0x48, 0x48, 0x48);
    return ledz.Color(0x48, 0x48, 0x48);
  }
}
  
  
uint32_t nicoleOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0xEE, 0xEE, 0xEE);
    return ledz.Color(0xEE, 0xEE, 0xEE);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0xFF, 0xFF, 0x00);
    return ledz.Color(0xFF, 0xFF, 0x00);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    //return leds.Color(0, 0xFF, position * 8);
    return leds.Color(0xCC, 0x99, 0x00);
    return ledz.Color(0xCC, 0x99, 0x00);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    //return leds.Color(0, 0xFF - position * 8, 0xFF);
    return leds.Color(0xEE, 0xEE, 0xEE);
    return ledz.Color(0xEE, 0xEE, 0xEE);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    //return leds.Color(position * 8, 0, 0xFF);
    return leds.Color(0xFF, 0xFF, 0x00);
    return ledz.Color(0xFF, 0xFF, 0x00);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    //return leds.Color(0xFF, 0x00, 0xFF - position * 8);
    return leds.Color(0xCC, 0x99, 0x00);
    return ledz.Color(0xCC, 0x99, 0x00);
  }
}


