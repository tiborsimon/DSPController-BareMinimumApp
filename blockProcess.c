#include "tt.h"
#include "DSPController.h"

// Place the audio processing algorith here. The input and output are given
// as unsigned integer pointers.
void processBlock(float *input, float *output) {
    
    output[L] =  input[L];
    output[R] = -input[R];
    
    float outL = 0.5*leftIn;
	float outR = -rightIn;
    
    rightOut1 = outR;
	 leftOut1 = outL;
	rightOut2 = outR;
	 leftOut2 = outL;
	rightOut3 = outR;
	 leftOut3 = outL;
	rightOut4 = outR;
	 leftOut4 = outL;
    
}
