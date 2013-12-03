///////////////////////////////////////////////////////////////////////////////////////
//NAME:     SPORTisr.c (Block-based Talkthrough)
//DATE:     7/15/04
//PURPOSE:  Talkthrough framework for sending and receiving samples to the AD1835.
//
//USAGE:    This file contains SPORT0 Interrupt Service Routine. Three buffers are used
//          for this example. One is filled by the ADC, another is sent to the DAC, and
//          the final buffer is processed. Each buffer rotates between these functions
//          upon each SP0 interrupt received.
///////////////////////////////////////////////////////////////////////////////////////
/*
   Here is the mapping between the SPORTS and the DACS
   ADC -> DSP  : SPORT0A : IIS
   DSP -> DAC1 : SPORT1A : IIS
   DSP -> DAC2 : SPORT1B : IIS
   DSP -> DAC3 : SPORT2A : IIS
   DSP -> DAC4 : SPORT2B : IIS
*/

#include "tt.h"
#include <stdio.h>
#include "DSPController.h"

#define RIGHT  0
#define LEFT   1




float inLeft  , inRight;
float out1Left, out1Right;
float out2Left, out2Right;
float out3Left, out3Right;
float out4Left, out4Right;

int inLeft_i  , inRight_i;
int out1Left_i, out1Right_i;
int out2Left_i, out2Right_i;
int out3Left_i, out3Right_i;
int out4Left_i, out4Right_i;


int mode1RegSPisr, mode1RegSPisr2;

int isProcessing=0;

//If the processing takes too long, the program will be stuck in this infinite loop.
void ProcessingTooLong()
{
    while(1);
}

bool channelCheck;

void receive(int sig_int)
{
    //    if(isProcessing){  ProcessingTooLong();}
	if (1==isProcessing	){
			asm volatile(
	     			"%0 = mode1;\n\t"
		     		: "=d" (mode1RegSPisr): :);//PEYEN
	}

	if (0==isProcessing	){
			asm volatile(
	     			"%0 = mode1;\n\t"
	     			: "=d" (mode1RegSPisr2): :);//PEYEN
	}


    channelCheck = !!((*pDAI_PIN_STAT)&DAI_PB14);

    // GET input samples
	if ( channelCheck	){   //így kompatibilis a 4.0-s VisualDSP-vel
		inRight_i = (int) Block_A[RIGHT];  
	    inLeft_i  = (int) Block_A[LEFT];  
	} else{
		inLeft_i  = (int) Block_A[RIGHT];
	 	inRight_i = (int) Block_A[LEFT];   
	}

    inRight = (float)inRight_i / (float)SCALE;        
    inLeft  = (float)inLeft_i  / (float)SCALE;

    // prefill outputs
    out1Left  = inLeft;
    out1Right = inRight;
    out2Left  = inLeft;
    out2Right = inRight;
    out3Left  = inLeft;
    out3Right = inRight;
    out4Left  = inLeft;
    out4Right = inRight;

    // DSPController TICK
    DSPController_tick();

    // Signal Processing
    isProcessing = 1;
    process();
    isProcessing = 0;


	// convert and scale
    out1Left_i  = (unsigned int)(out1Left  * SCALE);
    out1Right_i = (unsigned int)(out1Right * SCALE);

    out2Left_i  = (unsigned int)(out2Left  * SCALE);
    out2Right_i = (unsigned int)(out2Right * SCALE);

    out3Left_i  = (unsigned int)(out3Left  * SCALE);
    out3Right_i = (unsigned int)(out3Right * SCALE);

    out4Left_i  = (unsigned int)(out4Left  * SCALE);
    out4Right_i = (unsigned int)(out4Right * SCALE);

    #define SATURATE(in,sat) if ((in)>(sat)) in = sat; if ((in)<(-sat)) in = -sat;

	SATURATE(out1Left_i ,0x007FFFFF);
	SATURATE(out1Right_i,0x007FFFFF);

    SATURATE(out2Left_i ,0x007FFFFF);
    SATURATE(out2Right_i,0x007FFFFF);

    SATURATE(out3Left_i ,0x007FFFFF);
    SATURATE(out3Right_i,0x007FFFFF);

    SATURATE(out4Left_i ,0x007FFFFF);
    SATURATE(out4Right_i,0x007FFFFF);



    //adó reg.-be írás
    if ( channelCheck   ){  //így kompatibilis a 4.0-s VisualDSP-vel
        #ifdef DAC1
            *pTXSP1A = out1Right_i;
            *pTXSP1A = out1Left_i;
        #endif
        
        #ifdef DAC2
            *pTXSP1B = out2Right_i;
            *pTXSP1B = out2Left_i;
        #endif
        
        #ifdef DAC3
            *pTXSP2A = out3Right_i;
            *pTXSP2A = out3Left_i;
        #endif
            
        #ifdef DAC4
            *pTXSP2B = out4Right_i;
            *pTXSP2B = out4Left_i;
        #endif    
    } else {
        #ifdef DAC1
            *pTXSP1A = out1Left_i;
            *pTXSP1A = out1Right_i;
        #endif
        
        #ifdef DAC2
            *pTXSP1B = out2Left_i;
            *pTXSP1B = out2Right_i;
        #endif
            
        #ifdef DAC3
            *pTXSP2A = out3Left_i;
            *pTXSP2A = out3Right_i;
        #endif
            
        #ifdef DAC4
            *pTXSP2B = out4Left_i;
            *pTXSP2B = out4Right_i;
        #endif    
    }   

}
