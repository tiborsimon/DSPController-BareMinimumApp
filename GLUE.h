#ifndef _GLUE_H_
#define _GLUE_H_

#include "tt.h"
#include "DSPController.h"

//========================================================================//
//        G L U E   V A R I A B L E   D E C L A R A T I O N S             //
//========================================================================//
//                                                                        //
//  The GLUE variables connect the interface code to the DSP code. They   //
//  can be used to control the DSP algorithm and to transfer parameters.  //
//                                                                        //
//  You should declare GLUE variables in this file as an extern variable  //
//  and define/initialize them in the INTERFACE.c file, than you can use  //
//  them in arbitrari files.                                              //
//                                                                        //
//========================================================================//
//                                                                        //
//  Typical workflow:                                                     //
//                                                                        //
//      1. Declare the variable in this file (GLUE.h)                     //
//      2. Define the variable in the INTERFACE.c file                    //
//      3. Update the variable in the INTERFACE.c file                    //
//      4. Use the variable in the DSP.c file                             //
//                                                                        //
//========================================================================//
//                                                                        //
//  Example:                                                              //
//                                                                        //
//     extern float GLUE_volume;                                          //
//      |            |                                                    //
//      |            *--------- use the GLUE_.. notation                  //
//      |                                                                 //
//      *---------------------- declare the variable as an extern         //
//                              variable                                  //
//                                                                        //
//========================================================================//

extern float GLUE_volume;


#endif
