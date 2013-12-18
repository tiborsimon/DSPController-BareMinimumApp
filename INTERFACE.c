#include "GLUE.h"

//========================================================================//
//                    I N T E R F A C E   L O G I C                       //
//========================================================================//
//                                                                        //
//  This  file  contains  all of the  interface functionalities. You can  //
//  implement  your custom  interface  application  by writing code with  //
//  the DSPController API inside the two functions defined below.          //
//                                                                        //
//========================================================================//


//========================================================================//
//  STEP 1 - Define the variables and symbols                             //
//========================================================================//
//                                                                        //
//  Define local and GLUE variables and give them initial values          //
//                                                                        //
//========================================================================//

// Defined symbols
#define DEFAULT_GLUE_VOLUME     0.5f
#define MAX_VOLUME              60

// Local variables
int volume = 30;

// GLUE variables
float GLUE_volume = DEFAULT_GLUE_VOLUME;


//========================================================================//
//  STEP 2 - Initialize the interface and the data structures             //
//========================================================================//
//                                                                        //
//  Initialize the  DSPController  with  API functions  and set up  your  //
//  data structures. This function will be called once before the signal  //
//  processing starts.                                                    //
//                                                                        //
//========================================================================//

void initInterface(void) {
    
    DSPController_init( FS_48KHZ | ENCODER_VELOCITY_ON );
    
}


//========================================================================//
//  STEP 3 - Write your interface logic                                   //
//========================================================================//
//                                                                        //
//  With the DSPConroller API  create an event based  state machine that  //
//  interacts the user by processing the input events, and by displaying  //
//  data on the outputs (LCD/LED bars).                                   //
//                                                                        //
//  You can update or read  the GLUE variables here,  to control the DSP  //
//  code or update the displays according to the audio input.             //
//                                                                        //
//  This function will be  called  periodically  from the main loop as a  //
//  low priority function, therefore you are free to put some processing  //
//  heavy code here (i.e. sprintf(), LCD handling API functions).         //
//                                                                        //
//========================================================================//

void updateInterface(void) {
    
    int temp_volume = DSPController_get_encoder(3);
    
    if(temp_volume != 0) {
        volume += temp_volume;
        
        if (volume < 0) volume = 0;
        if (volume >  MAX_VOLUME) volume =  MAX_VOLUME;
        
        GLUE_volume = (float)(volume)/(float)MAX_VOLUME; 
    }
    
    DSPController_lcd_top("Bare minimum app");
    DSPController_lcd_bottom("Volume     [%02d]",volume);

}
