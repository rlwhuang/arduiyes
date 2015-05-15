#include <TimerOne.h>
#define DIM 5
#define DIM1 (DIM-1)
typedef byte Frame[DIM];
#include "frames.h"

byte row = 0;
byte *curFrame;
int curFrameIdx;

// col[xx] of leds - anodes
// these are the arduino pins assigned to each column
int cols[DIM] = {12, 11, 10, 9, 8};

// row[xx] of leds - cathodes
// these are the arduino pins assigned to each row
int rows[DIM] = {7, 6, 5, 4, 3};

Frame blankFrame =
{ B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

char animation;

// blank the screen
void clearLeds() {
  curFrame = blankFrame;
}

// select a frame to display
// idx = 0 -> FRAMDECNT-1
void setFrame(int idx) {
  curFrame = Frames[idx];
}

// Interrupt routine
// each time display() is called, it turns off the previous row
// and turns on the next row
byte bitMask = B00000011;
void display() {
  digitalWrite(rows[row], HIGH);  // Turn whole previous row off

  if (bitMask == B00010000) {
    bitMask = B00000011;  // light the right 2 columns (pins 9,8)
    // increment row and wrap if necessary
    if (++row == DIM) {
      row = 0;
    }
  }
  else if (bitMask == B00000011) {
    bitMask = B00001100;  // light the middle 2 columns (pins 11,10)
  }
  else { // bitMaskIdx == B00001100
    bitMask = B00010000;  // light the leftmost column (pin 12)
  }

  // direct port manipulation.
  // PORTB is a pseudo variable for digital pins 8 to 13 The two high bits (6 & 7) map to the crystal pins and are not usable
  // the bottom 5 bits are our columns.  We don't want to change the other bits,
  // so we first mask the bits we ignore, and then set the bits we want to light
  PORTB &= B11100000;
  PORTB |= curFrame[row] & bitMask;

  digitalWrite(rows[row], LOW); // Turn whole row on at once (for equal lighting times)
}


void setup() {
  Serial.begin(9600);
  int i;
  // sets the pins as output
  for (i = 0; i < DIM; i++) {
    pinMode(cols[i], OUTPUT);
    pinMode(rows[i], OUTPUT);
  }
  // set up cols and rows (set display to dark)
  for (i = 0; i < DIM; i++) {
    digitalWrite(cols[i], LOW);
  }
  for (i = 0; i < DIM; i++) {
    digitalWrite(rows[i], HIGH);
  }
  clearLeds();
  Timer1.initialize(1000);
  Timer1.attachInterrupt(display);
  curFrameIdx = -1;
}

void loop() {
  if (Serial.available() > 0) {
    animation = Serial.read();
  }
  
  // increment the frame index and wrap if necessary
  //  if (++curFrameIdx == FRAMECNT) {
  //    curFrameIdx = 0;
  //  }
  //
  //  // select frame for display
  //  setFrame(curFrameIdx);

  if (animation == '0') {
    //if (++curFrameIdx == FRAMECNT) {
    //  curFrameIdx = 0;
    //}
    //setFrame(curFrameIdx);

    for (int x = 0; x < 4; x++) {
      setFrame(x);
      delay(400); // kinda weird
    }

  }
  
  else if (animation == '1') {
    setFrame(3);
    delay(400);
    clearLeds();
    delay(400);
    setFrame(3);
  }
  
  else if (animation == '2') {
    setFrame(2);
    delay(400);
    clearLeds();
    delay(400);
    setFrame(2);
  }

  else if (animation == '3') {
    setFrame(0);
    delay(400);
    clearLeds();
    delay(400);
    setFrame(0);
  }
  
  else if (animation == '4') {
    setFrame(1);
    delay(400);
    clearLeds();
    delay(400);
    setFrame(1);
  }

  else if (animation == '5') {
    setFrame(4);
    delay(400);
    clearLeds();
    setFrame(5);
    delay(400);
    clearLeds();
    setFrame(6);
    delay(400);
    clearLeds();
  }

  else if (animation == '6') {
    setFrame(7);
    delay(400);
    clearLeds();
    setFrame(8);
    delay(400);
    clearLeds();
    setFrame(9);
    delay(400);
    clearLeds();
  }

  else if (animation == '7') {
    setFrame(10);
    delay(400);
    clearLeds();
    setFrame(11);
    delay(400);
    clearLeds();
    setFrame(12);
    delay(400);
    clearLeds();
  }

  else if (animation == '8') {
    setFrame(13);
    delay(400);
    clearLeds();
    setFrame(14);
    delay(400);
    clearLeds();
    setFrame(15);
    delay(400);
    clearLeds();
  }
  
  else if (animation == '9') {
    setFrame(16);
    delay(400);
    clearLeds();
    setFrame(17);
    delay(400);
    clearLeds();
    setFrame(18);
    delay(400);
    clearLeds();
    setFrame(19);
    delay(400);
    clearLeds();
  }
  
  else if (animation == 'X') {
    setFrame(20);
    delay(400);
    clearLeds();
    setFrame(21);
    delay(400);
    clearLeds();
    setFrame(22);
    delay(400);
    clearLeds();
    setFrame(23);
    delay(400);
    clearLeds();
  }

  else if (animation == 'V') {
    setFrame(24);
    delay(400);
    clearLeds();
    setFrame(25);
    delay(400);
    clearLeds();
    setFrame(26);
    delay(400);
    clearLeds();
  }
  
delay(400); // wait time between frames in ms

}



