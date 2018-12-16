#ifndef BREATHINGLIGHT_H
#define BREATHINGLIGHT_H

// Window yellow RGB 254, 88, 2
// Light yellow RGB 254, 153, 23
// Light blue RGB 1, 242, 243

extern int m;
extern int n;
extern int flag;

void breath() {

  // Smooth the light change when the two parts connect to each other
  // If the current loop doesn't finish at the time, keep decreasing the brightness value until it becomes zero.
  if (m == 0 & flag == 0) {
    flag = 1;
    n = 0;
  }

  else if (m > 0 & flag == 0) {
    m -= 1;
    CircuitPlayground.setBrightness(m);
    CircuitPlayground.strip.show();
  }

  else {
    // Set the color
    for (int i = 0; i < 10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, 254, 88, 2); //Window Yellow
    }

    // Breathing light
    if (m == 240) {
      n = 1;
      m -= 1;
    }
    else if (n == 0) {
      CircuitPlayground.setBrightness(m);
      m += 1;
    }
    else if (n == 1 & m == 0) {
      n = 0;
    }
    else if (n == 1) {
      CircuitPlayground.setBrightness(m);
      m -= 1;
    }
    CircuitPlayground.strip.show();

  }
  // delay 5 milliseconds
  delay(5);

}

# endif
