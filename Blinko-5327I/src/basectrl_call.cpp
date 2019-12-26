#include "vex.h"

// These three lines exactly!
using namespace vex;
using signature = vision::signature;
using code = vision::code;

// Truespeed array for joystick adjustment
int TRUESPEED[] = {0,  3,  3,  3,  3,  3, 10, 10, 10, 10,
                   10, 10, 10, 10, 12, 12, 12, 12, 12, 12,
                   14, 14, 14, 14, 14, 14, 20, 20, 20, 20,
                   20, 20, 20, 25, 25, 25, 25, 25, 25, 25, 
                   30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
                   45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
                   55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
                   66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
                   79, 79, 79, 79, 79, 79, 79, 79, 79, 79,
                   89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
                   95, 95, 95, 99, 99, 99, 99,104,104,104,
                   107,107,107,113,113,113,113,113,116,116,
                   116,116,123,123,123,127,127,127};

/*
 _______     _____   ______  ____  ____  _________  
|_   __ \   |_   _|.' ___  ||_   ||   _||  _   _  | 
  | |__) |    | | / .'   \_|  | |__| |  |_/ | | \_| 
  |  __ /     | | | |   ____  |  __  |      | |     
 _| |  \ \_  _| |_\ `.___]  |_| |  | |_    _| |_    
|____| |___||_____|`._____.'|____||____|  |_____|   
                                                                               
*/
// Controls right side of base, in callback
void rightBaseCtrl(void)
{
  if (Controller.Axis2.value() >= 0)
    {
        rf.spin(vex::directionType::fwd, (TRUESPEED[Controller.Axis2.value()]*1.575), vex::velocityUnits::rpm);
        rb.spin(vex::directionType::fwd, (TRUESPEED[Controller.Axis2.value()]*1.575), vex::velocityUnits::rpm);
    }
    else if (Controller.Axis2.value() < 0)
    {
        rf.spin(vex::directionType::rev, (TRUESPEED[-Controller.Axis2.value()]*1.575), vex::velocityUnits::rpm);
        rb.spin(vex::directionType::rev, (TRUESPEED[-Controller.Axis2.value()]*1.575), vex::velocityUnits::rpm);
    }
}

/*
  _____     ________  ________  _________  
 |_   _|   |_   __  ||_   __  ||  _   _  | 
   | |       | |_ \_|  | |_ \_||_/ | | \_| 
   | |   _   |  _| _   |  _|       | |     
  _| |__/ | _| |__/ | _| |_       _| |_    
 |________||________||_____|     |_____|   
                                           
*/
// Controls left side of base, in callback
void leftBaseCtrl(void)
{
  if (Controller.Axis3.value() >= 0)
    {
        lf.spin(vex::directionType::fwd, (TRUESPEED[Controller.Axis3.value()]*1.575), vex::velocityUnits::rpm);
        lb.spin(vex::directionType::fwd, (TRUESPEED[Controller.Axis3.value()]*1.575), vex::velocityUnits::rpm);
    }
    else if (Controller.Axis3.value() < 0)
    {
        lf.spin(vex::directionType::rev, (TRUESPEED[-Controller.Axis3.value()]*1.575), vex::velocityUnits::rpm);
        lb.spin(vex::directionType::rev, (TRUESPEED[-Controller.Axis3.value()]*1.575), vex::velocityUnits::rpm);
    }
}
