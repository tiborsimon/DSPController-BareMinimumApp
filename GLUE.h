#ifndef _GLUE_H_
#define _GLUE_H_

#include "tt.h"
#include "DSPController.h"


//==========================================================//
//   G L U E   V A R I A B L E   D E C L A R A T I O N S    //
//==========================================================//
// 															//
//  The GLUE variables connect the  interface code to the   //
//  DSP code. They can be  used for controlling  the  DSP   //
//  algorithm, transfer                                     //
//                                                          //
//==========================================================//
// 															//
//  Example:                                                //
//                                                          //
// 		extern float GLUE_volume;                           //
//       |            |                                     // 
//       |            *--------- use the GLUE_.. notation   //
//       |                                                  //
//       *---------------------- declare the  variable as   //
//                               an extern variable         //
//                                                          // 
//==========================================================//

extern float GLUE_volume;


#endif
