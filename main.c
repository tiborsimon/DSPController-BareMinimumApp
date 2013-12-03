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

void SetupIRQ12(void) ;

void main(void)
{
    
	INIT_SHARC;
    
    initInterface();
    
    while(1) {
        updateInterface();   
    }
    
}
