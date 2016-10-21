/**
 * The code running when you first get the Denbit.
 */

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

const long millis_on  = 1000;
const long millis_off = 500;

byte led_state = 0;

// Store the last time the led changed
unsigned long last_change = 0;

void setup() {
  // Start the Over The Air programming.
  denbit.OTAsetup();
}

void loop() {
  // Check for any Over The Air updates.
  denbit.OTAhandle();

  unsigned long now = millis();

  if (led_state) {
    if (now - last_change >= millis_on) {
      last_change = now;
      led_state = LOW;
    }
  } else {
    if (now - last_change >= millis_off) {
      last_change = now;
      led_state = HIGH;
    }
  }

  // Blink the green led of the RGB led :)
  digitalWrite(14, led_state);

  // Turn on the led above the switch if pushed
  if (digitalRead(2)) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
  
  if (digitalRead(16)) {
    digitalWrite(12, LOW); 
  } else {
    digitalWrite(12, HIGH); 
  }
}

