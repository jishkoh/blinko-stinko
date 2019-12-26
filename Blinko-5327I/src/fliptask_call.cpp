#include "vex.h"
//#include "structure.cpp"

// These three lines exactly!
using namespace vex;
using signature = vision::signature;
using code = vision::code;

/*
 ________  _____     _____  _______   
|_   __  ||_   _|   |_   _||_   __ \  
  | |_ \_|  | |       | |    | |__) | 
  |  _|     | |   _   | |    |  ___/  
 _| |_     _| |__/ | _| |_  _| |_     
|_____|   |________||_____||_____|    
                                      
*/
void flipTask(void)
{
  slam.rotateFor(vex::directionType::fwd, 135, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
  wait(250, msec);
  slam.rotateFor(vex::directionType::rev, 135, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
}