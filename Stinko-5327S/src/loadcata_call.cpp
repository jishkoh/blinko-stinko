#include "vex.h"

// These three lines exactly!
using namespace vex;
using signature = vision::signature;
using code = vision::code;

bool loadState = false;
double cataThresh = 0.90;

/*
  _____       ___        _       ______       ______       _     _________     _       
 |_   _|    .'   `.     / \     |_   _ `.   .' ___  |     / \   |  _   _  |   / \      
   | |     /  .-.  \   / _ \      | | `. \ / .'   \_|    / _ \  |_/ | | \_|  / _ \     
   | |   _ | |   | |  / ___ \     | |  | | | |          / ___ \     | |     / ___ \    
  _| |__/ |\  `-'  /_/ /   \ \_  _| |_.' / \ `.___.'\ _/ /   \ \_  _| |_  _/ /   \ \_  
 |________| `.___.'|____| |____||______.'   `.____ .'|____| |____||_____||____| |____| 
                                                                                       
*/


// In case you need it!

void forceCata(void)
{
  tcat.startRotateFor(vex::directionType::fwd, 75, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
  bcat.rotateFor(vex::directionType::fwd, 75, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
  wait(250, msec);
}


void loadCata(void)
{
  // Start rotating catapult
  tcat.spin(vex::directionType::fwd, 100, vex::percentUnits::pct);
  bcat.spin(vex::directionType::fwd, 100, vex::percentUnits::pct);
  
  // Let it rotate if already loaded
  wait(500, msec);
  
  // Check if torque is high enough
  if (!loadState)
  {
    while(!loadState && tcat.torque(vex::torqueUnits::Nm) < cataThresh)
    {
      wait(10, msec);
    }

    loadState = true;

  }
  else if (loadState) 
  {
    wait(250, msec);

    loadState = false;
  }

  tcat.stop(vex::brakeType::hold);
  bcat.stop(vex::brakeType::hold);

  wait(250, msec);
}