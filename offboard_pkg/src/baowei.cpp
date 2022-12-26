//
// File: baowei.cpp
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
#include "baowei.h"
#include "baowei_private.h"

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  // real32_T y;
  // real32_T tmp;
  // real32_T tmp_0;
  // if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
  //   y = (rtNaNF);
  // } else {
  //   tmp = std::abs(u0);
  //   tmp_0 = std::abs(u1);
  //   if (rtIsInfF(u1)) {
  //     if (tmp > 1.0F) {
  //       y = 1.0F;
  //     } else if (tmp > 1.0F) {
  //       if (u1 > 0.0F) {
  //         y = (rtInfF);
  //       } else {
  //         y = 0.0F;
  //       }
  //     } else if (u1 > 0.0F) {
  //       y = 0.0F;
  //     } else {
  //       y = (rtInfF);
  //     }
  //   } else if (tmp_0 == 0.0F) {
  //     y = 1.0F;
  //   } else if (tmp_0 == 1.0F) {
  //     if (u1 > 0.0F) {
  //       y = u0;
  //     } else {
  //       y = 1.0F / u0;
  //     }
  //   } else if (u1 == 2.0F) {
  //     y = u0 * u0;
  //   } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
  //     y = std::sqrt(u0);
  //   } else if ((u0 < 0.0F) && (u1 > std::floor(u1))) {
  //     y = (rtNaNF);
  //   } else {
  //     y = std::pow(u0, u1);
  //   }
  // }

  return 0;
}

// Model step function
void baoweiModelClass::step()
{
  real32_T rtb_cos;
  real32_T rtb_sin;
  real32_T rtb_r;
  real32_T rtb_Sum5;

  // Sum: '<Root>/Sum' incorporates:
  //   Inport: '<Root>/CUR_POS_X'
  //   Inport: '<Root>/SP_POS_X'

  rtb_cos = baowei_U.CUR_POS_X - baowei_U.SP_POS_X;

  // Sum: '<Root>/Sum1' incorporates:
  //   Inport: '<Root>/CUR_POS_Y'
  //   Inport: '<Root>/SP_POS_Y'

  rtb_sin = baowei_U.CUR_POS_Y - baowei_U.SP_POS_Y;

  // Sqrt: '<Root>/r' incorporates:
  //   Fcn: '<Root>/Fcn'
  //   Fcn: '<Root>/Fcn1'
  //   Sum: '<Root>/Sum6'

  rtb_r = std::sqrt(rtb_cos*rtb_cos +rtb_sin*rtb_sin);

  // Product: '<Root>/sin'
  rtb_sin /= rtb_r;

  // Product: '<Root>/cos'
  rtb_cos /= rtb_r;

  // Sum: '<Root>/Sum5' incorporates:
  //   Inport: '<Root>/SP_R'

  rtb_Sum5 = baowei_U.SP_R - rtb_r;

  // Product: '<Root>/k2*r*wd*sin' incorporates:
  //   Inport: '<Root>/K2'
  //   Inport: '<Root>/SP_WD'
  //   Product: '<Root>/k2rwdcos'

  rtb_r = baowei_U.K2 * rtb_r * baowei_U.SP_WD;

  // Outport: '<Root>/SP_VEL_X' incorporates:
  //   Inport: '<Root>/K1'
  //   Product: '<Root>/k1(R-r)*cos'
  //   Product: '<Root>/k2*r*wd*sin'
  //   Sum: '<Root>/Sum4'

  baowei_Y.SP_VEL_X = rtb_cos * rtb_Sum5 * baowei_U.K1 - rtb_r * rtb_sin;

  // Outport: '<Root>/SP_VEL_Y' incorporates:
  //   Inport: '<Root>/K1'
  //   Product: '<Root>/k1*��R-r��*sin'
  //   Product: '<Root>/k2rwdcos'
  //   Sum: '<Root>/Sum3'

  baowei_Y.SP_VEL_Y = baowei_U.K1 * rtb_Sum5 * rtb_sin +rtb_r * rtb_cos;
}

// Model initialize function
void baoweiModelClass::initialize()
{
  // Registration code

  // initialize non-finites
 // rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
 // rtmSetErrorStatus((&baowei_M), (NULL));

  // external inputs
  (void)memset(&baowei_U, 0, sizeof(ExtU_baowei_T));

  // external outputs
  (void) memset((void *)&baowei_Y, 0,
                sizeof(ExtY_baowei_T));
}

// Model terminate function
void baoweiModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
baoweiModelClass::baoweiModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
baoweiModelClass::~baoweiModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_baowei_T * baoweiModelClass::getRTM()
{
  return (&baowei_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
