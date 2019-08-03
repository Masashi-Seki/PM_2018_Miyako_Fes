/*
  Tokyo Metropolitan University
  Code of the projection show at Miyako fest.

  Code of the controller of floor.
  Written by Masashi Seki

  2018.10.30 Tue.
*/

#include "button.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            19 //A5
#define NUMPIXELS      16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

double rate = 0.2; //brightness of LED

int buttonState[16];
int color[16][3] = {
  /*{0, 0, 255},
    {0, 255, 0},
    {255, 255, 0},
    {255, 0, 255},
    {0, 255, 255},
    {0, 255, 70},
    {255, 183, 76},
    {221, 132, 22},
    {67, 135, 233},
    {149, 255, 101},
    {255, 255, 255},
    {255, 49, 25},
    {156, 167, 22},
    {168, 239, 175},
    {244, 250, 37},
    {225, 0, 178},
  */
  {0 * rate, 0 * rate, 255 * rate},
  {0 * rate, 255 * rate, 0 * rate},
  {255 * rate, 255 * rate, 0 * rate},
  {255 * rate, 0 * rate, 255 * rate},
  {0 * rate, 255 * rate, 255 * rate},
  {0 * rate, 255 * rate, 70 * rate},
  {255 * rate, 183 * rate, 76 * rate},
  {221 * rate, 132 * rate, 22 * rate},
  {67 * rate, 135 * rate, 233 * rate},
  {149 * rate, 255 * rate, 101 * rate},
  {255 * rate, 255 * rate, 255 * rate},
  {255 * rate, 49 * rate, 25 * rate},
  {156 * rate, 167 * rate, 22 * rate},
  {168 * rate, 239 * rate, 175 * rate},
  {244 * rate, 250 * rate, 37 * rate},
  {225 * rate, 0 * rate, 178 * rate},
};

int push1;
int push2;
byte getData;

void setup() {

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin();

  LED_blink(); //LED blink

  for (int i = 0; i < 19; i++) {
    if (i != 13)
      pinMode(i, INPUT_PULLUP);
  }

  Serial.begin(9600);
  reset_LED();
}

void loop() {
  push1 = 0;
  push2 = 0;

  //ボタンチェック
  push1 = buttonCheck();

  if (push1 != 0) {
    delay(50);
    push2 = buttonCheck();
    if (push1 == push2) {
      //ボタン押された時の処理

      if (push2 == 0x01) Serial.write(0x01);
      else if (push2 == 0x02) Serial.write(0x02);
      else if (push2 == 0x03) Serial.write(0x03);
      else if (push2 == 0x04) Serial.write(0x04);
      else if (push2 == 0x05) Serial.write(0x05);
      else if (push2 == 0x06) Serial.write(0x06);
      else if (push2 == 0x07) Serial.write(0x07);
      else if (push2 == 0x08) Serial.write(0x08);
      else if (push2 == 0x09) Serial.write(0x09);
      else if (push2 == 0x0A) Serial.write(0x0A);
      else if (push2 == 0x0B) Serial.write(0x0B);
      else if (push2 == 0x0C) Serial.write(0x0C);
      else if (push2 == 0x0D) Serial.write(0x0D);
      else if (push2 == 0x0E) Serial.write(0x0E);
      else if (push2 == 0x0F) Serial.write(0x0F);
      else if (push2 == 0x10) Serial.write(0x10);

      /*
            if (push2 == 0x01) Serial.write(0x01);
            if (push2 == 0x02) Serial.write(0x02);
            if (push2 == 0x03) Serial.write(0x03);
            if (push2 == 0x04) Serial.write(0x04);
            if (push2 == 0x05) Serial.write(0x05);
            if (push2 == 0x06) Serial.write(0x06);
            if (push2 == 0x07) Serial.write(0x07);
            if (push2 == 0x08) Serial.write(0x08);
            if (push2 == 0x09) Serial.write(0x09);
            if (push2 == 0x0A) Serial.write(0x0A);
            if (push2 == 0x0B) Serial.write(0x0B);
            if (push2 == 0x0C) Serial.write(0x0C);
            if (push2 == 0x0D) Serial.write(0x0D);
            if (push2 == 0x0E) Serial.write(0x0E);
            if (push2 == 0x0F) Serial.write(0x0F);
            if (push2 == 0x10) Serial.write(0x10);
      */
    }
  }

  //受信データチェック
  if (Serial.available() > 0) {
    getData = 0;
    getData = Serial.read();

    if (getData == 0x01) off_LED(0x01);
    else if (getData == 0x02) off_LED(0x02);
    else if (getData == 0x03) off_LED(0x03);
    else if (getData == 0x04) off_LED(0x04);
    else if (getData == 0x05) off_LED(0x05);
    else if (getData == 0x06) off_LED(0x06);
    else if (getData == 0x07) off_LED(0x07);
    else if (getData == 0x08) off_LED(0x08);
    else if (getData == 0x09) off_LED(0x09);
    else if (getData == 0x0A) off_LED(0x0A);
    else if (getData == 0x0B) off_LED(0x0B);
    else if (getData == 0x0C) off_LED(0x0C);
    else if (getData == 0x0D) off_LED(0x0D);
    else if (getData == 0x0E) off_LED(0x0E);
    else if (getData == 0x0F) off_LED(0x0F);
    else if (getData == 0x10) off_LED(0x10);

    else if (getData == 0xFF) reset_LED();
    else if (getData == 0xFE) allOff_LED();
    else if (getData == 0xFD) flash_LED(0x04);
    else if (getData == 0xFC) on_LED(0x04);
    //else if (getData == 0xFB) LED_blink();
  }

  delay(1);
}

void reset_LED() {
  for (int i = 0; i < 16; i++)
    pixels.setPixelColor(i, pixels.Color(color[i][0], color[i][1], color[i][2]));
  pixels.show();
}

void allOff_LED() {
  for (int i = 0; i < 16; i++)
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
}

void off_LED(int no) {
  pixels.setPixelColor(no - 1, pixels.Color(0, 0, 0));
  pixels.show();
}

void on_LED(int no) {
  pixels.setPixelColor(no - 1, pixels.Color(color[no - 1][0], color[no - 1][1], color[no - 1][2]));
  pixels.show();
}

void flash_LED(int no) {
  for (int i = 0; i < 7; i++) {

    pixels.setPixelColor(no - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);

    pixels.setPixelColor(no - 1, pixels.Color(color[no - 1][0], color[no - 1][1], color[no - 1][2]));
    pixels.show();
    delay(50);
  }
}

int buttonCheck() {
  int push = 0;
  if (digitalRead(B1) == LOW) push = 1;
  else if (digitalRead(B2) == LOW) push = 2;
  else if (digitalRead(B3) == LOW) push = 3;
  else if (digitalRead(B4) == LOW) push = 4;
  else if (digitalRead(B5) == LOW) push = 5;
  else if (digitalRead(B6) == LOW) push = 6;
  else if (digitalRead(B7) == LOW) push = 7;
  else if (digitalRead(B8) == LOW) push = 8;
  else if (digitalRead(B9) == LOW) push = 9;
  else if (digitalRead(B10) == LOW) push = 10;
  else if (digitalRead(B11) == LOW) push = 11;
  else if (digitalRead(B12) == LOW) push = 12;
  else if (digitalRead(B13) == LOW) push = 13;
  else if (digitalRead(B14) == LOW) push = 14;
  else if (digitalRead(B15) == LOW) push = 15;
  else if (digitalRead(B16) == LOW) push = 16;
  return push;
}

void LED_blink() {
  for (int i = 0; i < 3; i++) {
    for (int i = 0; i < 16; i++)
      pixels.setPixelColor(i, pixels.Color(0, 20, 20)); //green
    pixels.show();
    delay(500);

    for (int i = 0; i < 16; i++)
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(500);
  }
}
