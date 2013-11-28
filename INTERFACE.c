#include "GLUE.h"


void initInterface(void) {
    
    DSPController_init();
    DSPController_assembler_engage();
    
}

int k = 0;


void updateInterface(void) {
    
    
    unsigned char e = DSPController_get_event();
        
    if(0 != e) {
        DSPController_lcd_top("hello: %d",e);
        DSPController_lcd_bottom("hello: %d",k++);
    }
        
        
}
