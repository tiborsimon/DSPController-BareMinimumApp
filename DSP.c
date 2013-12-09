#include "GLUE.h"

//========================================================================//
//          D I G I T A L   S I G N A L   P R O C E S S I N G             //
//========================================================================//
//                                                                        //
//  In this file you can  implement your  DSP algorithm  by writing your  //
//  code iside the process() function. You will get  access to 10 global  //
//  variables  that represent  the  actual input and output samples. The  //
//  input variables contain the new left and right samples come from the  //
//  AD converter  before the  process() function is  called.  The output  //
//  variables  will  be  sent to  the  DA concerter  after the process()  //
//  function returned.                                                    //
//                                                                        //
//  After every ADC interrupt  the process() function  will be called as  //
//  one of  the highest  priority processing  function.  Your task is to  //
//  fill up the output  variables  with  new  data  calculated according  //
//  to  the  input  samples  and/or you algorithm,  otherwise the  input  //
//  samples will be mirrored to te outputs.                               //
//                                                                        //
//========================================================================//
//                                                                        //
//  Global sample variables you can use:                                  //
//                                                                        //
//         INPUTS              OUTPUTS                                    //
//             inLeft              out1Left    out3Left                   //
//             inRight             out1Right   out3Right                  //
//                                 out2Left    out4Left                   //
//                                 out2Right   out4Right                  //
//                                                                        //
//========================================================================//

void process(void) {

    //====================================================================
    // PREPARE THE WORKING VARIABLES
    //====================================================================
    float left  = inLeft;
    float right = inRight;


    //====================================================================
    // DSP ALGORITHM
    //====================================================================
    left *= GLUE_volume;
    right *= GLUE_volume;


    //====================================================================
    // FILL OUTPUT VARIABLES
    //====================================================================
    out1Left  = left;
    out1Right = right;
    out2Left  = left;
    out2Right = right;
    out3Left  = left;
    out3Right = right;
    out4Left  = left;
    out4Right = right;

}
