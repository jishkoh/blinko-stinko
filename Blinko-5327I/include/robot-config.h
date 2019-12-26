using namespace vex;

/*
   ______    ___   ____  _____  ________  _____   ______   
 .' ___  | .'   `.|_   \|_   _||_   __  ||_   _|.' ___  |  
/ .'   \_|/  .-.  \ |   \ | |    | |_ \_|  | | / .'   \_|  
| |       | |   | | | |\ \| |    |  _|     | | | |   ____  
\ `.___.'\\  `-'  /_| |_\   |_  _| |_     _| |_\ `.___]  | 
 `.____ .' `.___.'|_____|\____||_____|   |_____|`._____.'  
                                                           
*/
// Brain
extern brain Brain;

 // Controller
extern controller Controller;

 // Base motor configuration
extern motor lf;
extern motor lb;
extern motor rf;
extern motor rb;

// Lift motor configuration
extern motor lifr;
extern motor lifl;

// Slammer configuration
extern motor slam;

/*
 ________  _____  _____  ____  _____   ______  _________  _____   ___   ____  _____   ______   
|_   __  ||_   _||_   _||_   \|_   _|.' ___  ||  _   _  ||_   _|.'   `.|_   \|_   _|.' ____ \  
  | |_ \_|  | |    | |    |   \ | | / .'   \_||_/ | | \_|  | | /  .-.  \ |   \ | |  | (___ \_| 
  |  _|     | '    ' |    | |\ \| | | |           | |      | | | |   | | | |\ \| |   _.____`.  
 _| |_       \ \__/ /    _| |_\   |_\ `.___.'\   _| |_    _| |_\  `-'  /_| |_\   |_ | \____) | 
|_____|       `.__.'    |_____|\____|`.____ .'  |_____|  |_____|`.___.'|_____|\____| \______.' 
                                                                                               
*/
void vexcodeInit(void);
void rightBaseCtrl(void);
void leftBaseCtrl(void);
void slammerCtrl(void);
void liftCtrl(void);
void flipTask(void);

/*
  ______   _________  _______  _____  _____   ______  _________  
.' ____ \ |  _   _  ||_   __ \|_   _||_   _|.' ___  ||  _   _  | 
| (___ \_||_/ | | \_|  | |__) | | |    | | / .'   \_||_/ | | \_| 
 _.____`.     | |      |  __ /  | '    ' | | |           | |     
| \____) |   _| |_    _| |  \ \_ \ \__/ /  \ `.___.'\   _| |_    
 \______.'  |_____|  |____| |___| `.__.'    `.____ .'  |_____|   
                                                                 
*/
// Slam Structure
typedef struct
{
  int upvel = 100;
  int downvel = 75;
  bool hold = true;
}slam_t;

// Lift Structure
typedef struct
{
  int upvel = 100;
  int downvel = 75;
  bool hold = true;
}lif_t;

/*
   ______  _____       ___   ______        _       _____     
 .' ___  ||_   _|    .'   `.|_   _ \      / \     |_   _|    
/ .'   \_|  | |     /  .-.  \ | |_) |    / _ \      | |      
| |   ____  | |   _ | |   | | |  __'.   / ___ \     | |   _  
\ `.___]  |_| |__/ |\  `-'  /_| |__) |_/ /   \ \_  _| |__/ | 
 `._____.'|________| `.___.'|_______/|____| |____||________| 
                                                             
*/
