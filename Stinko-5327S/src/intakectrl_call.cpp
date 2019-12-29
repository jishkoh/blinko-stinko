#include "vex.h"

// These three lines exactly!
using namespace vex;
using signature = vision::signature;
using code = vision::code;

/*
 _____  ____  _____  _________     _       ___  ____   ________  
|_   _||_   \|_   _||  _   _  |   / \     |_  ||_  _| |_   __  | 
  | |    |   \ | |  |_/ | | \_|  / _ \      | |_/ /     | |_ \_| 
  | |    | |\ \| |      | |     / ___ \     |  __'.     |  _| _  
 _| |_  _| |_\   |_    _| |_  _/ /   \ \_  _| |  \ \_  _| |__/ | 
|_____||_____|\____|  |_____||____| |____||____||____||________| 
                                                                 
*/

volatile int intakeState = 0;

void intakeCtrlFwd(void)
{
  if (intakeState == 0 || intakeState == -1)
  {
    intk.spin(vex::directionType::fwd, 100, vex::percentUnits::pct);
    intakeState = 1;
  }
  else if (intakeState == 1)
  {
    intk.stop(vex::brakeType::coast);
    intakeState = 0;
  }
  wait(250, msec);
}

void intakeCtrlRev(void)
{
  if (intakeState == 0 || intakeState == 1)
  {
    intk.spin(vex::directionType::rev, 100, vex::percentUnits::pct);
    intakeState = -1;
  }
  else if (intakeState == -1)
  {
    intk.stop(vex::brakeType::coast);
    intakeState = 0;
  }
  wait(250, msec);
}

void intakeStop(void)
{
  intk.stop(vex::brakeType::coast);
  intakeState = 0;
  wait(250, msec);
}