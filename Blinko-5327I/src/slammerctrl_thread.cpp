#include "vex.h"
//#include "structure.cpp"

// These three lines exactly!
using namespace vex;
using signature = vision::signature;
using code = vision::code;

/*
  ______   _____          _       ____    ____  ____    ____  ________  _______     
.' ____ \ |_   _|        / \     |_   \  /   _||_   \  /   _||_   __  ||_   __ \    
| (___ \_|  | |         / _ \      |   \/   |    |   \/   |    | |_ \_|  | |__) |   
 _.____`.   | |   _    / ___ \     | |\  /| |    | |\  /| |    |  _| _   |  __ /    
| \____) | _| |__/ | _/ /   \ \_  _| |_\/_| |_  _| |_\/_| |_  _| |__/ | _| |  \ \_  
 \______.'|________||____| |____||_____||_____||_____||_____||________||____| |___| 
                                                                                    
*/
// Create an instance of slam_t struct
volatile slam_t slam_obj;

// Function that controls the slammer, called in a thread
void slammerCtrl(void)
{
  while (true)
  {
    if (Controller.ButtonR1.pressing() && !Controller.ButtonR2.pressing())
    {
      slam_obj.hold = false;
      slam.spin(vex::directionType::fwd, slam_obj.upvel, vex::velocityUnits::pct);
    }
    else if (Controller.ButtonR2.pressing() && !Controller.ButtonR1.pressing())
    {
      slam_obj.hold = false;
      slam.spin(vex::directionType::rev, slam_obj.downvel, vex::velocityUnits::pct);
    }
    else if (!slam_obj.hold) // when slam_obj.hold == false
    {
      // Brake and hold function
      slam.stop(vex::brakeType::brake);
      wait(75, msec);
      slam.stop(vex::brakeType::hold);
      slam_obj.hold = true;
    }
  }
}