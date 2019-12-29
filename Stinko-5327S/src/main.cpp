/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Jish                                             */
/*    Created:      Wed Dec 25 2019                                           */
/*    Description:  5327S Code                                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]            [Port(s)]
// Controller           controller        N/A            
// lf                   Base: Left Front  1     
// lb                   Base: Left Back   2     
// rf                   Base: Right Front 3
// rb                   Base: Right Back  4
// intk                 Intake            5 
// tcat                 Catapult: Top     6
// bcat                 Catapult: Bot     7
// ---- END VEXCODE CONFIGURED DEVICES ----

// Include all source files
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

/*
 _______  _______     ________        _   _____  _____  _________    ___   ____  _____  
|_   __ \|_   __ \   |_   __  |      / \ |_   _||_   _||  _   _  | .'   `.|_   \|_   _| 
  | |__) | | |__) |    | |_ \_|     / _ \  | |    | |  |_/ | | \_|/  .-.  \ |   \ | |   
  |  ___/  |  __ /     |  _| _     / ___ \ | '    ' |      | |    | |   | | | |\ \| |   
 _| |_    _| |  \ \_  _| |__/ |  _/ /   \ \_\ \__/ /      _| |_   \  `-'  /_| |_\   |_  
|_____|  |____| |___||________| |____| |____|`.__.'      |_____|   `.___.'|_____|\____| 

*/
void pre_auton(void) 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}


/*
      _   _____  _____  _________    ___   ____  _____   ___   ____    ____   ___   _____  _____   ______   
     / \ |_   _||_   _||  _   _  | .'   `.|_   \|_   _|.'   `.|_   \  /   _|.'   `.|_   _||_   _|.' ____ \  
    / _ \  | |    | |  |_/ | | \_|/  .-.  \ |   \ | | /  .-.  \ |   \/   | /  .-.  \ | |    | |  | (___ \_| 
   / ___ \ | '    ' |      | |    | |   | | | |\ \| | | |   | | | |\  /| | | |   | | | '    ' |   _.____`.  
 _/ /   \ \_\ \__/ /      _| |_   \  `-'  /_| |_\   |_\  `-'  /_| |_\/_| |_\  `-'  /  \ \__/ /   | \____) | 
|____| |____|`.__.'      |_____|   `.___.'|_____|\____|`.___.'|_____||_____|`.___.'    `.__.'     \______.' 

*/
void autonomous(void)
{
  // Autonomous user code to be called in competition
}


/*
 _____  _____   ______   ________  _______     
|_   _||_   _|.' ____ \ |_   __  ||_   __ \    
  | |    | |  | (___ \_|  | |_ \_|  | |__) |   
  | '    ' |   _.____`.   |  _| _   |  __ /    
   \ \__/ /   | \____) | _| |__/ | _| |  \ \_  
    `.__.'     \______.'|________||____| |___| 

*/
void usercontrol(void)
{
  // I don't use this, but it's good to include it in case you need it!
}



/*
 ____    ____       _       _____  ____  _____  
|_   \  /   _|     / \     |_   _||_   \|_   _| 
  |   \/   |      / _ \      | |    |   \ | |   
  | |\  /| |     / ___ \     | |    | |\ \| |   
 _| |_\/_| |_  _/ /   \ \_  _| |_  _| |_\   |_  
|_____||_____||____| |____||_____||_____|\____| 

*/
int main() 
{ 
  // These lines are important for a competition ready robot!
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Callbacks
  Controller.Axis3.changed(leftBaseCtrl);
  Controller.Axis2.changed(rightBaseCtrl);
  Controller.ButtonL1.pressed(intakeCtrlFwd);
  Controller.ButtonL2.pressed(intakeCtrlRev);
  Controller.ButtonR1.pressed(loadCata);
  Controller.ButtonR2.pressed(intakeStop);
  Controller.ButtonA.pressed(forceCata);

  // Threads
  

  // This usually goes at the end to prevent int main from exiting
  while (true) {
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(tcat.torque(torqueUnits::Nm));
    wait(100, msec);
    Brain.Screen.clearScreen();
  }
}
 