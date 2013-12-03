#include "GLUE.h"





// Define local variables
int k = 0;


// Define GLUE variables
float GLUE_volume = 0.5f;



//==========================================================
//  INIT INTERFACE                                          
//==========================================================
void initInterface(void) {
    
    DSPController_init();
    DSPController_assembler_engage();
    
}





//==========================================================
//  UPDATE INTERFACE                                        
//==========================================================
void updateInterface(void) {
    
    
    unsigned char e = DSPController_get_event();
        
    if(0 != e) {
        DSPController_lcd_top("hello: %d",e);
        DSPController_lcd_bottom("hello: %d",k++);
        
        if (e == DSPC_EVENT_E1_SHORT) GLUE_volume = 0.9f;
        if (e == DSPC_EVENT_E3_SHORT) GLUE_volume = 0.2f;
    }
        
        
}
