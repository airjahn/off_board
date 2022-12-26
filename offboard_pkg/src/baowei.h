//
// File: baowei.h
//
// Code generated for Simulink model 'baowei'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Fri Jul  3 16:21:10 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_baowei_h_
#define RTW_HEADER_baowei_h_
#include <cmath>
#include <string.h>
#include <stddef.h>
#ifndef baowei_COMMON_INCLUDES_
# define baowei_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // baowei_COMMON_INCLUDES_

#include "baowei_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// External inputs (root inport signals with default storage)
typedef struct {
  real32_T CUR_POS_X;                  // '<Root>/CUR_POS_X'
  real32_T CUR_POS_Y;                  // '<Root>/CUR_POS_Y'
  real32_T SP_POS_X;                   // '<Root>/SP_POS_X'
  real32_T SP_POS_Y;                   // '<Root>/SP_POS_Y'
  real32_T SP_R;                       // '<Root>/SP_R'
  real32_T SP_WD;                      // '<Root>/SP_WD'
  real32_T K1;                         // '<Root>/K1'
  real32_T K2;                         // '<Root>/K2'
} ExtU_baowei_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real32_T SP_VEL_X;                   // '<Root>/SP_VEL_X'
  real32_T SP_VEL_Y;                   // '<Root>/SP_VEL_Y'
} ExtY_baowei_T;

// Real-time Model Data Structure
struct tag_RTM_baowei_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model baowei
class baoweiModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_baowei_T baowei_U;

  // External outputs
  ExtY_baowei_T baowei_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  baoweiModelClass();

  // Destructor
  ~baoweiModelClass();

  // Real-Time Model get method
  RT_MODEL_baowei_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_baowei_T baowei_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'baowei'

#endif                                 // RTW_HEADER_baowei_h_

//
// File trailer for generated code.
//
// [EOF]
//
