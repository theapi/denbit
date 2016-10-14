/**
 * The minimum required to have a denbit 
 * that can be programmed over WiFi
 */

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

void setup() {
  // Start the Over The Air programming.
  denbit.OTAsetup();
}

void loop() {
  // Check for any Over The Air updates.
  denbit.OTAhandle();

}

