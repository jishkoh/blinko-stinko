#include "vex.h"

// These three lines exactly!
using namespace vex;
using signature = vision::signature;
using code = vision::code;

// Start here! 

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller = controller(primary);

// Base motor configuration
motor lf = motor(PORT1, ratio18_1, false);
motor lb = motor(PORT2, ratio18_1, false);
motor rf = motor(PORT3, ratio18_1, true);
motor rb = motor(PORT4, ratio18_1, true);

// Intake motor configuration
motor intk = motor(PORT5, ratio18_1, false);

// Catapult motor configuration
motor tcat = motor(PORT6, ratio18_1, false);
motor bcat = motor(PORT7, ratio18_1, true);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}