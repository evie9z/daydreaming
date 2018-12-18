#include <Adafruit_CircuitPlayground.h>
#include "BreathingLight.h"
#include "SlightlyBreath.h"

#define SEND_OUTPUT    A4
#define SEND_INPUT     A2

int flag = 0;  // To identify if the current loop finished when connecting two parts
int m = 0;  // Brightness value
int n = 0;  // Another flag that helps to identify whether the brightness should be increased or decreased

void setup() {

  // initiate the board
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(SEND_OUTPUT, OUTPUT);
  pinMode(SEND_INPUT, INPUT);

  // Make output pin always high
  digitalWrite(SEND_OUTPUT, HIGH);
  
}


void loop() {

  int state = digitalRead(SEND_INPUT);

  // Make the brightness value and color change when two parts connect to each other
  if (state == HIGH) {
    breath();
  }
  else {
    slightBreath();
  }
  
}
