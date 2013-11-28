///////////////////////////////////////////////////////////////////////////////////////
//NAME:     main.c (Block-based Talkthrough)
//DATE:     7/15/04
//PURPOSE:  Talkthrough framework for sending and receiving samples to the AD1835.
//
//USAGE:    This file contains the main routine calls functions to set up the talkthrough
//          routine.
//
////////////////////////////////////////////////////////////////////////////////////////
#include "tt.h"
#include "DSPController.h"

void SetupIRQ12(void);

void main(void)
{
    
	InitPLL ();
	SetupIRQ12 () ;
    // Need to initialize DAI because the sport signals
    // need to be routed
    InitDAI();

    // This function will configure the codec on the kit
    Init1835viaSPI();

    // Finally setup the sport to receive / transmit the data
    InitSPORT();

    interrupt (SIG_SP0,receive);
    // interrupt (SIG_IRQ1, Irq1ISR) ;
    // interrupt (SIG_IRQ2, Irq2ISR) ;
    
    
    DSPController_init();
    int i=0,k=0;
    
    // Be in infinite loop and do nothing until done.
    for(;;)
    {
        
        
        DSPController_tick();
        
        
        
        unsigned char e = DSPController_get_event();
        
        if(0 != e) {
            DSPController_lcd_top("hello: %d",e);
            DSPController_lcd_bottom("hello: %d",k++);
        }
        
        
        
        for(i=0;i<496;i++) {
	     	asm volatile("nop;");
	    }
	    
	    /*
	    while(blockReady) {
	     	processBlock(src_pointer[int_cntr]);   
	    }
	    */
        
	    
    }
    
}
