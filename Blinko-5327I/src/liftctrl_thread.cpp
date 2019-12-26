#include "vex.h"
//#include "structure.cpp"

// These three lines exactly!
using namespace vex;
using signature = vision::signature;
using code = vision::code;

/*
  _____     _____  ________  _________  
 |_   _|   |_   _||_   __  ||  _   _  | 
   | |       | |    | |_ \_||_/ | | \_| 
   | |   _   | |    |  _|       | |     
  _| |__/ | _| |_  _| |_       _| |_    
 |________||_____||_____|     |_____|   
                                        
*/
// Create an instance of lif_t struct
volatile lif_t lift;

// Function that controls the lift, called in a thread
void liftCtrl(void)
{
  while (true)
  {
    if (Controller.ButtonL1.pressing() && !Controller.ButtonL2.pressing())
    {
      lift.hold = false;
      lifr.spin(vex::directionType::fwd, lift.upvel, vex::velocityUnits::pct);
      lifl.spin(vex::directionType::fwd, lift.upvel, vex::velocityUnits::pct);
    }
    else if (Controller.ButtonL2.pressing() && !Controller.ButtonL1.pressing())
    {
      lift.hold = false;
      lifr.spin(vex::directionType::rev, lift.downvel, vex::velocityUnits::pct);
      lifl.spin(vex::directionType::rev, lift.downvel, vex::velocityUnits::pct);
    }
    else if (!lift.hold)
    {
      lifr.stop(vex::brakeType::brake);
      lifl.stop(vex::brakeType::brake);
      wait(75, msec);
      lifr.stop(vex::brakeType::hold);
      lifl.stop(vex::brakeType::hold);
      lift.hold = true;
    }
  }
}