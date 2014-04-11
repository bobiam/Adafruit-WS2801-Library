#include "SPI.h"
#include "Adafruit_WS2801.h"
/*
  ws2808play - a collection of patterns written for a 5x5 square, by Bob Eells (!Bob) for a display he built for Flipside 2014.
  Intention is to have the square rotated 45 degrees (diamond display) - some patterns (smiley face, for example) are only upright on a diagonal.
  pods are laid out in rows, back and forth.  Pod 24 is north.  The diagram looks like:
  
  24 23 22 21 20
  15 16 17 18 19
  14 13 12 11 10
  05 06 07 08 09
  04 03 02 01 00
  
  Modified heavily from the original Adafruit WS2801 example below.
  
  LICENSE: Just do it.  Take it, use it, make something pretty with it.
  I make no claim to it, and no claim that it's suitable for your or any other purposes.
  It does seem to make the lights blink nicely though.  If you need a formal license, use BSD or contact me 
  and I'll probably release it under whatever nonexclusive license you need.  
*/
/*****************************************************************************
Example sketch for driving Adafruit WS2801 pixels!


  Designed specifically to work with the Adafruit RGB Pixels!
  12mm Bullet shape ----> https://www.adafruit.com/products/322
  12mm Flat shape   ----> https://www.adafruit.com/products/738
  36mm Square shape ----> https://www.adafruit.com/products/683

  These pixels use SPI to transmit the color data, and have built in
  high speed PWM drivers for 24 bit color per pixel
  2 pins are required to interface

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!
uint8_t dataPin  = 2;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 3;    // Green wire on Adafruit Pixels

// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply

// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
int totalLEDs = 25;
Adafruit_WS2801 strip = Adafruit_WS2801(totalLEDs, dataPin, clockPin);

//frequently used named colors
uint32_t orangered = Color(255,69,0);
uint32_t orange = Color(255,165,0);
uint32_t black = Color(0,0,0);
uint32_t red = Color(255,0,0);
uint32_t green = Color(0,255,0);
uint32_t blue = Color(0,0,255);
uint32_t yellow = Color(255,255,0);
uint32_t seagreen = Color(84,255,159);
uint32_t indigo = Color(75,0,130);
uint32_t violet = Color(238,130,238);
uint32_t white = Color(255,255,255);

// Optional: leave off pin numbers to use hardware SPI
// (pinout is then specific to each board and can't be changed)
//Adafruit_WS2801 strip = Adafruit_WS2801(25);

// For 36mm LED pixels: these pixels internally represent color in a
// different format.  Either of the above constructors can accept an
// optional extra parameter: WS2801_RGB is 'conventional' RGB order
// WS2801_GRB is the GRB order required by the 36mm pixels.  Other
// than this parameter, your code does not need to do anything different;
// the library will handle the format change.  Examples:
//Adafruit_WS2801 strip = Adafruit_WS2801(25, dataPin, clockPin, WS2801_GRB);
//Adafruit_WS2801 strip = Adafruit_WS2801(25, WS2801_GRB);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see debugs    
  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
}


void loop() {
  fade(red,orange,100,100);
  fade(orange,yellow,100,100);
  fade(yellow,green,100,100);
  fade(green,blue,100,100);
  fade(blue,indigo,100,100);
  fade(indigo,violet,100,100);
  fade(violet,red,100,100);
  
  spinner(red,blue,150,30);
  bang(black, red, 250, false, 1000);  
  smiley(black, yellow, 250, false, 1000);  
  fireRand(100);
  waterRand(100);
  fireRand(50);
  waterRand(50);  
  fireRand(10);
  waterRand(10);  
  primaryBars();
  flashlight(5000);  
  colorWipe(Color(255, 0, 0), 50);
  colorWipe(Color(0, 255, 0), 50);
  colorWipe(Color(0, 0, 255), 50);  
  bulls(red,green,blue,250,20);  
  spiral(orangered, blue, 50, false, 0);
  spiral(orangered, blue, 50, true, 0);  
  smiley(green, blue, 50, false, 0);
  smiley(blue ,green, 50, false, 0);    
  spiral(orangered, blue, 50, false, 0);
  spiral(blue ,orangered, 50, false, 0);  
  spiral(orangered, blue, 50, true, 0);
  spiral(blue ,orangered, 50, true, 0);    
  spiral(orangered, blue, 50, false, 0);
  spiral(orangered, blue, 50, true, 0);  
  spiral(blue ,orangered, 50, false, 0);    
  spiral(blue ,orangered, 50, true, 0);    
  ants(Color(0,255,0),Color(0,0,0),500);  
  clock(10, Color(0,0,255), Color(0,255,0), 50);
  allBlink(10, Color(255,0,0), Color(0,0,0), 500);
  randommy();
  ants(Color(0,0,255),Color(255,0,0),500);
  ants(Color(0,0,255),Color(255,0,0),250);  
  ants(Color(0,0,255),Color(255,0,0),125);    
  ants(Color(0,0,255),Color(255,0,0),75);
  ants(Color(0,0,255),Color(255,0,0),37);  
  ants(Color(0,0,255),Color(255,0,0),18);    
  ants(Color(0,0,255),Color(255,0,0),9);
  ants(Color(0,0,255),Color(255,0,0),4);
  ants(Color(0,0,255),Color(255,0,0),2);
  ants(Color(0,0,255),Color(255,0,0),1);
  ants(Color(0,0,255),Color(255,0,0),0);
  rainbow(20);
  rainbowCycle(20);
  
}

//BE - fade entire strand from *c1* to *c2* in *steps* increments with *wait* delay.
void fade(uint32_t c1, uint32_t c2, double steps, int wait)
{
  //get the rgb values for each color
  byte ret[3];
  double c1_r,c1_g,c1_b,c2_r,c2_g,c2_b;
  double delta_r, delta_g, delta_b;
  
  decodeColor(c1,ret);
  c1_r = ret[0];
  c1_g = ret[1];
  c1_b = ret[2];

  decodeColor(c2,ret);
  c2_r = ret[0];
  c2_g = ret[1];
  c2_b = ret[2];

  //build a precise temp color off the starting color
  double tmpC_r = c1_r;
  double tmpC_g = c1_g;
  double tmpC_b = c1_b;
  
  ringSet(Color(tmpC_r,tmpC_g,tmpC_b));
  delay(wait);

  if(c1_r < c2_r)
  {
    delta_r = (c2_r - c1_r) / steps;
  }else{
    delta_r = -1 * ( (c1_r - c2_r)/steps);
  }
  if(c1_g < c2_g)
  {
    delta_g = (c2_g - c1_g) / steps;
  }else{
    delta_g = -1 * ( (c1_g - c2_g)/steps);
  }
  if(c1_b < c2_b)
  {
    delta_b = (c2_b - c1_b) / steps;
  }else{
    delta_b = -1 * ( (c1_b - c2_b)/steps);
  }     
  
  for(int i=0;i<steps;i++)
  {
    tmpC_r += delta_r;
    tmpC_g += delta_g;
    tmpC_b += delta_b;
    Serial.print("Step ");
    Serial.print(i);
    Serial.print(" of: ");
    Serial.println(steps);
    Serial.print("r:");
    Serial.print(tmpC_r);
    Serial.print("g:");
    Serial.print(tmpC_g);
    Serial.print("b:");
    Serial.println(tmpC_b);
    ringSet(Color(tmpC_r,tmpC_g,tmpC_b));
    delay(wait);
    
  }
}

//BE - warm color palette
void fireRand(int loops)
{
  uint32_t colors[] = {black,red,orangered,yellow};
  int colorCount = 4;
  int maxWait = 150;
  paletteRand(colors,colorCount,maxWait,loops);
}

//BE - cool color palette
void waterRand(int loops)
{
  uint32_t colors[] = {black,blue,seagreen};
  int colorCount = 4;
  int maxWait = 150;
  paletteRand(colors,colorCount,maxWait,loops);
}

//BE - this might come in useful for seeing in the dark.
void flashlight(int wait)
{
  ringSet(white);
  delay(wait);
}

//BE - this was called OMGBP in L2C.  (Oh My GOD, PONIES!)
void primaryBars()
{
  int rows = 5;
  int cols = 5;
  int pixel = 0;
  uint32_t colors[] = {red, orangered, yellow, green, blue, indigo, violet};
  
  for(int h=0;h<20;h++)
  {
    pixel = 0;
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<cols;j++)
      {
        strip.setPixelColor(pixel,colors[(i)]);
        Serial.print("Setting pixel ");
        Serial.print(pixel);
        Serial.print(" to ");
        Serial.println(colors[i]);
        pixel++;      
      }
      strip.show();
    }
    delay(100);
    uint32_t temp = colors[0];
    colors[0] = colors[1];
    colors[1] = colors[2];
    colors[2] = colors[3];
    colors[3] = colors[4];
    colors[4] = colors[5];
    colors[5] = colors[6];
    colors[6] = temp;
  }
} 

//BE - say cheese.
void smiley(uint32_t bc, uint32_t fc, uint8_t wait, boolean reverse, int enddelay )
{
  int pixels[] = {22,14,12,10,9,0,1,2,19,3};
  int pixelCount = 10;
  colorByNumber(pixels, pixelCount, bc, fc, wait, reverse, enddelay);
}

//BE - nice animated spiral
void spiral(uint32_t bc, uint32_t fc, uint8_t wait, boolean reverse, int enddelay )
{
  int pixels[] = {12,17,18,11,8,7,6,13,16,23,22,21,20,19,10,9,0,1,2,3,4,5,14,15,24};
  int pixelCount = 25;
  colorByNumber(pixels, pixelCount, bc, fc, wait, reverse, enddelay);
}

//BE - Either bullseye, or bullshit, whichever your preference.  Bulls is intentionally truncated.
void bulls(uint32_t c1, uint32_t c2, uint32_t c3, uint8_t wait, int loops)
{
  ringSet(Color(0,0,0));
  int smallRing[] = {12};
  int medRing[] = {6,7,8,11,13,18,17,16};
  int bigRing[] = {0,1,2,3,4,5,14,15,24,23,22,21,20,19,10,9};
  int smallCount = 1;
  int medCount = 8;
  int bigCount = 16;

  for(int i=0;i<loops+1;i++)
  {
    setPixelGroup(smallRing, smallCount, c1);
    delay(wait);
    setPixelGroup(medRing, medCount, c1);
    setPixelGroup(smallRing, smallCount, c2);
    delay(wait);
    setPixelGroup(bigRing, bigCount, c1);
    setPixelGroup(medRing, medCount, c2);
    setPixelGroup(smallRing, smallCount, c3);
    delay(wait);
    setPixelGroup(bigRing, bigCount, c2);
    setPixelGroup(medRing, medCount, c3);
    setPixelGroup(smallRing, smallCount, c1);
    delay(wait);  
    setPixelGroup(bigRing, bigCount, c3);
    setPixelGroup(medRing, medCount, c1);
    setPixelGroup(smallRing, smallCount, c2);
    delay(wait);  
    setPixelGroup(bigRing, bigCount, c1);
    setPixelGroup(medRing, medCount, c2);
    setPixelGroup(smallRing, smallCount, c3);
    delay(wait);  
  }
}

//BE - should have called this propellor, I think.  It spins a line.
void spinner(uint32_t bgc, uint32_t fgc, uint8_t wait, int loops)
{
  ringSet(bgc);
  int frame1[] = {0,8,12,16,24};
  int frame2[] = {10,11,12,13,14};
  int frame3[] = {20,18,12,6,4};
  int frame4[] = {22,17,12,7,2};

  for(int i=0;i<loops+1;i++)
  {
    setPixelGroup(frame1, 5, fgc);
    delay(wait);
    ringSet(bgc);    
    setPixelGroup(frame2, 5, fgc);
    delay(wait);  
    ringSet(bgc);
    setPixelGroup(frame3, 5, fgc);
    delay(wait); 
    ringSet(bgc);    
    setPixelGroup(frame4, 5, fgc);
    delay(wait); 
    ringSet(bgc);    
  }
}




//BE - todo - send segments around the ring.  I've always hated this pattern.  
//Nevermind.  You do it if you want it.
void clock(uint8_t loops, uint32_t c, uint32_t c2, uint8_t wait ){
  int i,j;
  //segment initial is 0 to (numPixels/2), with wrap at numPixels.
  int bottom,top;
  bottom = 0;  
  top = strip.numPixels()/2;  

  for(j=0;j<loops;j++)
  {
    for(i=0;i<strip.numPixels();i++)
    {
  
    }  
  }
}

//BE - where would we be without the blink tag?
void allBlink(uint8_t blinks, uint32_t c, uint32_t c2, uint8_t wait ){
  for(int i=0;i<blinks;i++)
  {
    ringSet(c);
    delay(wait);
    ringSet(c2);
    delay(wait);
  }
}

//BE - this writes a random number of pods (0-255) to a random color, in a random order, with a random wait (0-200ms)
void randommy()
{
  for(int i=0;i<random(0,255);i++)
  {
    strip.setPixelColor(random(0,strip.numPixels()),Color(random(0,255),random(0,255),random(0,255)));
    delay(random(0,200));  
    strip.show();
  }
}

//BE - alternate pods between two colors
void ants(uint32_t c1, uint32_t c2, uint8_t wait){
  int i,j;
  for(j=0;j<40;j++)
  {
    for(i=0; i< strip.numPixels(); i++)
    {
      if(j%2)
      {     
        if(i % 2)
        {
          strip.setPixelColor(i,c1);
        }else{
          strip.setPixelColor(i,c2);
        }
      }else{
        if((i+1) % 2)
        {
          strip.setPixelColor(i,c1);
        }else{
          strip.setPixelColor(i,c2);
        }
      }
    }
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 255));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}
// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 256 / strip.numPixels()) + j) % 256) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// BE
// fill the dots one after the other with said color
// good for testing purposes and color wipes inbetween patterns.
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

// fill the dots all at once with said color
// good for testing purposes
void ringSet(uint32_t c) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
  }
  strip.show();  
}


/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

//BE - sometimes it's useful to get the RGB values back when passing colors to and fro.
void decodeColor(uint32_t c, byte ret[])
{
  int r,g,b;
  
  b = c & 255;
  g = c >>= 8;
  r = c >> 8;
  
  ret[0] = r;
  ret[1] = g;
  ret[2] = b;  
}

//BE - pass an array of pixels to this and it'll draw them out in order, with *wait* in ms between each pixel.
//reverse draws it backwards, useful for animation.
void colorByNumber(int pixels[],int pixelCount, uint32_t bc, uint32_t fc, uint8_t wait, boolean reverse, int enddelay)
{
  int i;
  //set bgcolor
  ringSet(bc);
  if(reverse)
  {
    for(i=0;i<pixelCount;i++)
    {
      Serial.print("i is: ");
      Serial.print(i);
      Serial.print("pixels[i] is ");
      Serial.println(pixels[i]);
      
      strip.setPixelColor(pixels[i],fc);
      strip.show();   // write all the pixels out
      delay(wait);   
    }  
  }else{
    for(i=pixelCount;i>-1;i--)
    {
      Serial.print("i is: ");
      Serial.print(i);
      Serial.print("pixels[i] is ");
      Serial.println(pixels[i]);
      
      strip.setPixelColor(pixels[i],fc);
      strip.show();   // write all the pixels out
      delay(wait);   
    }
  } 
  delay(enddelay);
}

//BE - take an array of pixels and set them all to given color.
//you probably want to do a colorWipe or ringSet to a background color first.
void setPixelGroup(int pixels[],int pixelCount, uint32_t c)
{
  int i;
  for(i=0;i<pixelCount;i++)
  {
    strip.setPixelColor(pixels[i],c);
  }
  strip.show();
}

//BE - gotta sign your work.
void bang(uint32_t bc, uint32_t fc, uint8_t wait, boolean reverse, int enddelay )
{
  int pixels[] = {24,23,15,16,17,13,12,8,9,1,0};
  int pixelCount = 11;
  colorByNumber(pixels, pixelCount, bc, fc, wait, reverse, enddelay);  
}

