//========================================================================//
//                   B A R E   M I N I M U M   A P P                      //
//========================================================================//
//                                                                        //
//  This project contains a basic echo application with volume control.   //
//  The project shows how to use the DSPController API.                   //
//                                                                        //
//------------------------------------------------------------------------//
//                                                                        //
//  Created by Tibor Simon <tiborsimon90@gmail.com>                       //
//  2013.12.10.                                                           //
//                                                                        //
//  BME VIK MIT DSP Laboratory                                            //
//                                                                        //
//========================================================================//

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
