#include <Adafruit_CircuitPlayground.h>
#include "BreathingLight.h"
#include "SlightlyBreath.h"

#define RECEIVE_OUTPUT    A4
#define RECEIVE_INPUT     A2

int flag = 0;  // To identify if the current loop finished when connecting two parts
int m = 0;  // Brightness value
int n = 0;  // Another flag that helps to identify whether the brightness should be increased or decreased

void setup() {

  // initiate the board
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(RECEIVE_OUTPUT, OUTPUT);
  pinMode(RECEIVE_INPUT, INPUT);

  // Make output pin always high
  digitalWrite(RECEIVE_OUTPUT, HIGH);

}


void loop() {

  int state = digitalRead(RECEIVE_INPUT);

  // Make the brightness value and color change when two parts connect to each other
  if (state == HIGH) {
    breath();
    delay(15);
  }

  else {
    slightBreath();
    delay(30);
  }

}
