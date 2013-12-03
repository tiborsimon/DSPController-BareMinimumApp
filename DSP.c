#include "GLUE.h"

//==========================================================//
//    D I G I T A L   S I G N A L   P R O C E S S I N G     //
//==========================================================//
// 															//
//                                                          //
//                                                          //
//==========================================================//

void process(void) {
    
    float outL = GLUE_volume*leftIn;
	float outR = -rightIn;
    
    rightOut1 = outR;
	leftOut1  = outL;
	rightOut2 = outR;
	leftOut2  = outL;
	rightOut3 = outR;
	leftOut3  = outL;
	rightOut4 = outR;
	leftOut4  = outL;
	 
}
