#include "GLUE.h"

//========================================================================//
//                    I N T E R F A C E   L O G I C                       //
//========================================================================//
//                                                                        //
//  This  file  contains  all of the  interface functionalities. You can  //
//  implement  your custom  interface  application  by writing code with  //
//  the DSPController API inside the two function defined below.          //
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

// Local variables
int k = 0;

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
    
    DSPController_init();
    DSPController_assembler_engage();
    
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
    
    unsigned char e = DSPController_get_event();
        
    if(0 != e) {
        DSPController_lcd_top("hello: %d",e);
        DSPController_lcd_bottom("hello: %d",k++);
        
        if (e == DSPC_EVENT_E1_SHORT) GLUE_volume = 0.9f;
        if (e == DSPC_EVENT_E3_SHORT) GLUE_volume = 0.2f;
    }

}
