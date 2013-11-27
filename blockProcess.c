#include "tt.h"
#include "DSPController.h"

// Place the audio processing algorith here. The input and output are given
// as unsigned integer pointers.
void processBlock(float *input, float *output) {
    
    output[L] =  input[L];
    output[R] = -input[R];
    
}
