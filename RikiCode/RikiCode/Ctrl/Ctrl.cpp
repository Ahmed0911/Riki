//
// File: Ctrl.cpp
//
// Code generated for Simulink model 'Ctrl'.
//
// Model version                  : 1.618
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sat May 28 17:08:13 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Texas Instruments->TMS470
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Ctrl.h"
#include "Ctrl_private.h"

// Named constants for Chart: '<S1>/Chart'
#define Ctrl_IN_AutoMode               ((uint8_T)1U)
#define Ctrl_IN_End                    ((uint8_T)1U)
#define Ctrl_IN_GotoWaypoint           ((uint8_T)2U)
#define Ctrl_IN_GreenOff               ((uint8_T)1U)
#define Ctrl_IN_GreenOn                ((uint8_T)2U)
#define Ctrl_IN_Idle                   ((uint8_T)3U)
#define Ctrl_IN_InitOrbitBezSecera     ((uint8_T)4U)
#define Ctrl_IN_InitSegment            ((uint8_T)5U)
#define Ctrl_IN_ManualMode             ((uint8_T)2U)
#define Ctrl_IN_NO_ACTIVE_CHILD        ((uint8_T)0U)
#define Ctrl_IN_NextWaypoint           ((uint8_T)6U)
#define Ctrl_IN_Off                    ((uint8_T)1U)
#define Ctrl_IN_On                     ((uint8_T)2U)
#define Ctrl_IN_Orbit                  ((uint8_T)7U)
#define Ctrl_IN_RateMode               ((uint8_T)3U)
#define Ctrl_IN_RedOff                 ((uint8_T)1U)
#define Ctrl_IN_RedOn                  ((uint8_T)2U)
#define Ctrl_IN_RollPitchMode          ((uint8_T)4U)
#define Ctrl_IN_VelocityMode           ((uint8_T)5U)
#define Ctrl_Ts                        (0.0025F)

// Exported block parameters
real32_T AltKp = 0.03F;                // Variable: AltKp
                                       //  Referenced by: '<S21>/Proportional Gain'

real32_T AltRateBias = 0.65F;          // Variable: AltRateBias
                                       //  Referenced by:
                                       //    '<S13>/Bias1'
                                       //    '<S80>/Bias1'

real32_T AltRateKi = 0.01F;            // Variable: AltRateKi
                                       //  Referenced by:
                                       //    '<S20>/Integral Gain'
                                       //    '<S86>/Integral Gain'

real32_T AltRateKp = 0.05F;            // Variable: AltRateKp
                                       //  Referenced by:
                                       //    '<S20>/Proportional Gain'
                                       //    '<S86>/Proportional Gain'

real32_T FilterK[100] = { 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F } ;       // Variable: FilterK
                                       //  Referenced by: '<S2>/Discrete FIR Filter'


real32_T PosKp = 0.1F;                 // Variable: PosKp
                                       //  Referenced by:
                                       //    '<S30>/Proportional Gain'
                                       //    '<S31>/Proportional Gain'

real32_T RollPitchKp = 10.0F;          // Variable: RollPitchKp
                                       //  Referenced by:
                                       //    '<S28>/Proportional Gain'
                                       //    '<S33>/Proportional Gain'
                                       //    '<S73>/Proportional Gain'
                                       //    '<S76>/Proportional Gain'
                                       //    '<S93>/Proportional Gain'
                                       //    '<S96>/Proportional Gain'

real32_T RollPitchMax = 30.0F;         // Variable: RollPitchMax
                                       //  Referenced by:
                                       //    '<S15>/Scale roll1'
                                       //    '<S17>/Scale roll2'
                                       //    '<S65>/Scale roll1'
                                       //    '<S66>/Scale roll2'
                                       //    '<S82>/Scale roll1'
                                       //    '<S83>/Scale roll2'

real32_T RollPitchRateKd = 5.0E-5F;    // Variable: RollPitchRateKd
                                       //  Referenced by:
                                       //    '<S27>/Derivative Gain'
                                       //    '<S32>/Derivative Gain'
                                       //    '<S58>/Derivative Gain'
                                       //    '<S60>/Derivative Gain'
                                       //    '<S72>/Derivative Gain'
                                       //    '<S75>/Derivative Gain'
                                       //    '<S92>/Derivative Gain'
                                       //    '<S95>/Derivative Gain'

real32_T RollPitchRateKi = 0.002F;     // Variable: RollPitchRateKi
                                       //  Referenced by:
                                       //    '<S27>/Integral Gain'
                                       //    '<S32>/Integral Gain'
                                       //    '<S58>/Integral Gain'
                                       //    '<S60>/Integral Gain'
                                       //    '<S72>/Integral Gain'
                                       //    '<S75>/Integral Gain'
                                       //    '<S92>/Integral Gain'
                                       //    '<S95>/Integral Gain'

real32_T RollPitchRateKp = 0.0007F;    // Variable: RollPitchRateKp
                                       //  Referenced by:
                                       //    '<S27>/Proportional Gain'
                                       //    '<S32>/Proportional Gain'
                                       //    '<S58>/Proportional Gain'
                                       //    '<S60>/Proportional Gain'
                                       //    '<S72>/Proportional Gain'
                                       //    '<S75>/Proportional Gain'
                                       //    '<S92>/Proportional Gain'
                                       //    '<S95>/Proportional Gain'

real32_T RollPitchRateMax = 200.0F;    // Variable: RollPitchRateMax
                                       //  Referenced by:
                                       //    '<S51>/Scale roll2'
                                       //    '<S52>/Scale roll2'
                                       //    '<S28>/Saturate'
                                       //    '<S33>/Saturate'
                                       //    '<S73>/Saturate'
                                       //    '<S76>/Saturate'
                                       //    '<S93>/Saturate'
                                       //    '<S96>/Saturate'

real32_T VelKi = 0.02F;                // Variable: VelKi
                                       //  Referenced by:
                                       //    '<S36>/Integral Gain'
                                       //    '<S37>/Integral Gain'
                                       //    '<S99>/Integral Gain'
                                       //    '<S100>/Integral Gain'

real32_T VelKp = 0.15F;                // Variable: VelKp
                                       //  Referenced by:
                                       //    '<S36>/Proportional Gain'
                                       //    '<S37>/Proportional Gain'
                                       //    '<S99>/Proportional Gain'
                                       //    '<S100>/Proportional Gain'

real32_T VelMax = 6.0F;                // Variable: VelMax
                                       //  Referenced by:
                                       //    '<S18>/Gain'
                                       //    '<S18>/Gain1'
                                       //    '<S84>/Gain'
                                       //    '<S84>/Gain1'

real32_T YawKp = 3.0F;                 // Variable: YawKp
                                       //  Referenced by:
                                       //    '<S42>/Proportional Gain'
                                       //    '<S105>/Proportional Gain'

real32_T YawRateKi = 0.000213867097F;  // Variable: YawRateKi
                                       //  Referenced by:
                                       //    '<S41>/Integral Gain'
                                       //    '<S62>/Integral Gain'
                                       //    '<S78>/Integral Gain'
                                       //    '<S104>/Integral Gain'

real32_T YawRateKp = 0.00321759842F;   // Variable: YawRateKp
                                       //  Referenced by:
                                       //    '<S41>/Proportional Gain'
                                       //    '<S62>/Proportional Gain'
                                       //    '<S78>/Proportional Gain'
                                       //    '<S104>/Proportional Gain'

real32_T YawRateMax = 180.0F;          // Variable: YawRateMax
                                       //  Referenced by:
                                       //    '<S53>/Scale roll2'
                                       //    '<S67>/Scale roll2'
                                       //    '<S42>/Saturate'
                                       //    '<S105>/Saturate'


//
// Output and update for atomic system:
//    '<S19>/Correct Yaw1'
//    '<S85>/Correct Yaw1'
//
void Ctrl_CorrectYaw1(real32_T rtu_u, B_CorrectYaw1_Ctrl_T *localB)
{
  // MATLAB Function 'Ctrl/AutoCtrl/Yaw Controller/Correct Yaw1': '<S40>:1'
  // '<S40>:1:3'
  localB->y = rtu_u - (real32_T)floor((real_T)(rtu_u / 360.0F)) * 360.0F;
  if (localB->y > 180.0F) {
    // '<S40>:1:4'
    // '<S40>:1:5'
    localB->y -= 360.0F;
  }
}

// Function for Chart: '<S1>/Chart'
void CtrlModelClass::Ctrl_SelectMode(void)
{
  boolean_T sf_internal_predicateOutput;

  // MATLAB Function 'SelectMode': '<S4>:176'
  // Graphical Function 'SelectMode': '<S4>:176'
  // '<S4>:315:1'
  if (!(Ctrl_Y.ActualMode > 10)) {
    // Inport: '<Root>/Thr'
    if ((Ctrl_U.Thr < 400.0F) && (Ctrl_DW.Mode != 5)) {
      // '<S4>:186:1'
      sf_internal_predicateOutput = true;
    } else {
      // '<S4>:186:1'
      sf_internal_predicateOutput = false;
    }

    // End of Inport: '<Root>/Thr'
    if (sf_internal_predicateOutput) {
      // '<S4>:186:1'
      // '<S4>:185:1'
      Ctrl_DW.Mode = 0U;
    } else {
      // Inport: '<Root>/Mode'
      // '<S4>:184:1'
      if (Ctrl_U.Mode < 600U) {
        // Inport: '<Root>/ModeCode'
        // '<S4>:227:1'
        Ctrl_DW.Mode = Ctrl_U.ModeCode;
      } else {
        // '<S4>:219:1'
        if (Ctrl_U.Mode < 1300U) {
          // '<S4>:229:1'
          Ctrl_DW.Mode = 4U;
        } else {
          // '<S4>:230:1'
          Ctrl_DW.Mode = 5U;
        }
      }

      // End of Inport: '<Root>/Mode'
    }
  }
}

// Function for Chart: '<S1>/Chart'
void CtrlModelClass::Ctrl_CalculateTrajSegment(uint8_T index1, uint8_T index2,
  real32_T velocity)
{
  real32_T dPLen;
  real32_T scale;
  real32_T absxk;
  real32_T t;

  // MATLAB Function 'CalculateTrajSegment': '<S4>:300'
  // '<S4>:300:2'
  // '<S4>:300:3'
  // '<S4>:300:4'
  // '<S4>:300:5'
  scale = 1.17549435E-38F;

  // Inport: '<Root>/Waypoints'
  Ctrl_DW.P1[0] = Ctrl_U.Waypoints[index1 - 1];
  Ctrl_DW.dPdT[0] = Ctrl_U.Waypoints[index2 - 1] - Ctrl_DW.P1[0];
  absxk = (real32_T)fabs((real_T)Ctrl_DW.dPdT[0]);
  if (absxk > 1.17549435E-38F) {
    dPLen = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.17549435E-38F;
    dPLen = t * t;
  }

  // Inport: '<Root>/Waypoints'
  Ctrl_DW.P1[1] = Ctrl_U.Waypoints[index1 + 8];
  Ctrl_DW.dPdT[1] = Ctrl_U.Waypoints[index2 + 8] - Ctrl_DW.P1[1];
  absxk = (real32_T)fabs((real_T)Ctrl_DW.dPdT[1]);
  if (absxk > scale) {
    t = scale / absxk;
    dPLen = dPLen * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    dPLen += t * t;
  }

  // Inport: '<Root>/Waypoints'
  Ctrl_DW.P1[2] = Ctrl_U.Waypoints[index1 + 17];
  Ctrl_DW.dPdT[2] = Ctrl_U.Waypoints[index2 + 17] - Ctrl_DW.P1[2];
  absxk = (real32_T)fabs((real_T)Ctrl_DW.dPdT[2]);
  if (absxk > scale) {
    t = scale / absxk;
    dPLen = dPLen * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    dPLen += t * t;
  }

  dPLen = scale * (real32_T)sqrt((real_T)dPLen);

  // '<S4>:300:6'
  Ctrl_DW.Ttotal = dPLen / velocity;

  // '<S4>:300:7'
  Ctrl_DW.dPdT[0] /= Ctrl_DW.Ttotal;
  Ctrl_DW.dPdT[1] /= Ctrl_DW.Ttotal;
  Ctrl_DW.dPdT[2] /= Ctrl_DW.Ttotal;
}

// Function for Chart: '<S1>/Chart'
void CtrlModelClass::Ctrl_SystemLogic(const real32_T
  TmpSignalConversionAtSFunctionI[3])
{
  real32_T a;
  real32_T b_a;
  int32_T tmp;
  int32_T tmp_0;

  // During 'SystemLogic': '<S4>:12'
  Ctrl_SelectMode();
  if (Ctrl_DW.is_SystemLogic == Ctrl_IN_Off) {
    // During 'Off': '<S4>:14'
    if (Ctrl_DW.Mode == 1) {
      // Transition: '<S4>:17'
      Ctrl_B.Off = false;
      Ctrl_DW.is_SystemLogic = Ctrl_IN_On;

      // Entry 'On': '<S4>:143'
      Ctrl_DW.ModeOld = Ctrl_DW.Mode;
      Ctrl_DW.is_On = Ctrl_IN_ManualMode;
      Ctrl_B.ManualMode = true;

      // Entry 'ManualMode': '<S4>:208'
      Ctrl_Y.ActualMode = 1U;
    } else if (Ctrl_DW.Mode == 2) {
      // Transition: '<S4>:89'
      Ctrl_B.Off = false;
      Ctrl_DW.is_SystemLogic = Ctrl_IN_On;

      // Entry 'On': '<S4>:143'
      Ctrl_DW.ModeOld = Ctrl_DW.Mode;
      Ctrl_DW.is_On = Ctrl_IN_RateMode;
      Ctrl_B.RateMode = true;

      // Entry 'RateMode': '<S4>:13'
      Ctrl_Y.ActualMode = 2U;
    } else if (Ctrl_DW.Mode == 3) {
      // Transition: '<S4>:90'
      Ctrl_B.Off = false;
      Ctrl_DW.is_SystemLogic = Ctrl_IN_On;

      // Entry 'On': '<S4>:143'
      Ctrl_DW.ModeOld = Ctrl_DW.Mode;
      Ctrl_DW.is_On = Ctrl_IN_RollPitchMode;
      Ctrl_B.RollPitchMode = true;

      // Entry 'RollPitchMode': '<S4>:87'
      Ctrl_Y.ActualMode = 3U;
    } else if (Ctrl_DW.Mode == 4) {
      // Transition: '<S4>:133'
      Ctrl_B.Off = false;
      Ctrl_DW.is_SystemLogic = Ctrl_IN_On;

      // Entry 'On': '<S4>:143'
      Ctrl_DW.ModeOld = Ctrl_DW.Mode;
      Ctrl_DW.is_On = Ctrl_IN_VelocityMode;
      Ctrl_B.VelocityMode = true;

      // Entry 'VelocityMode': '<S4>:88'
      Ctrl_Y.ActualMode = 4U;
    } else {
      if (Ctrl_DW.Mode == 5) {
        // Transition: '<S4>:209'
        Ctrl_B.Off = false;
        Ctrl_DW.is_SystemLogic = Ctrl_IN_On;

        // Entry 'On': '<S4>:143'
        Ctrl_DW.ModeOld = Ctrl_DW.Mode;
        Ctrl_DW.is_On = Ctrl_IN_AutoMode;
        Ctrl_B.AutoMode = true;

        // Entry Internal 'AutoMode': '<S4>:283'
        // Transition: '<S4>:286'
        Ctrl_DW.is_AutoMode = Ctrl_IN_Idle;

        // Entry 'Idle': '<S4>:301'
        Ctrl_DW.wayIndex = 1U;
        Ctrl_Y.ActualMode = 5U;
      }
    }
  } else {
    // During 'On': '<S4>:143'
    if (Ctrl_DW.Mode != Ctrl_DW.ModeOld) {
      // Transition: '<S4>:144'
      // Exit Internal 'On': '<S4>:143'
      // Exit Internal 'AutoMode': '<S4>:283'
      Ctrl_DW.is_AutoMode = Ctrl_IN_NO_ACTIVE_CHILD;
      Ctrl_B.AutoMode = false;
      Ctrl_DW.is_On = Ctrl_IN_NO_ACTIVE_CHILD;
      Ctrl_B.ManualMode = false;
      Ctrl_B.RateMode = false;
      Ctrl_B.RollPitchMode = false;
      Ctrl_B.VelocityMode = false;
      Ctrl_DW.is_SystemLogic = Ctrl_IN_Off;
      Ctrl_B.Off = true;

      // Entry 'Off': '<S4>:14'
      Ctrl_Y.ActualMode = 0U;
    } else {
      switch (Ctrl_DW.is_On) {
       case Ctrl_IN_AutoMode:
        // During 'AutoMode': '<S4>:283'
        switch (Ctrl_DW.is_AutoMode) {
         case Ctrl_IN_End:
          // During 'End': '<S4>:303'
          // Transition: '<S4>:291'
          Ctrl_DW.is_AutoMode = Ctrl_IN_Idle;

          // Entry 'Idle': '<S4>:301'
          Ctrl_DW.wayIndex = 1U;
          Ctrl_Y.ActualMode = 5U;
          break;

         case Ctrl_IN_GotoWaypoint:
          // During 'GotoWaypoint': '<S4>:302'
          if (Ctrl_DW.Time > Ctrl_DW.Ttotal) {
            // Transition: '<S4>:290'
            Ctrl_DW.is_AutoMode = Ctrl_IN_NextWaypoint;
            Ctrl_DW.temporalCounter_i1 = 0U;

            // Entry 'NextWaypoint': '<S4>:304'
            tmp = (int32_T)(Ctrl_DW.wayIndex + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Ctrl_DW.wayIndex = (uint8_T)tmp;
          } else if (Ctrl_U.ExecuteWaypoints == 10U) {
            // Transition: '<S4>:322'
            //  Abort Command
            Ctrl_DW.is_AutoMode = Ctrl_IN_Idle;

            // Entry 'Idle': '<S4>:301'
            Ctrl_DW.wayIndex = 1U;
            Ctrl_Y.ActualMode = 5U;
          } else {
            Ctrl_B.AutoRef[0] = Ctrl_DW.dPdT[0] * Ctrl_DW.Time + Ctrl_DW.P1[0];
            Ctrl_B.AutoRef[1] = Ctrl_DW.dPdT[1] * Ctrl_DW.Time + Ctrl_DW.P1[1];
            Ctrl_B.AutoRef[2] = Ctrl_DW.dPdT[2] * Ctrl_DW.Time + Ctrl_DW.P1[2];
            Ctrl_DW.Time += Ctrl_Ts;
          }
          break;

         case Ctrl_IN_Idle:
          // Inport: '<Root>/ExecuteWaypoints' incorporates:
          //   Inport: '<Root>/WayCnt'

          // During 'Idle': '<S4>:301'
          if ((Ctrl_U.ExecuteWaypoints == 1U) && (Ctrl_U.WayCnt > 0)) {
            // Transition: '<S4>:287'
            Ctrl_DW.is_AutoMode = Ctrl_IN_InitSegment;

            // Entry 'InitSegment': '<S4>:296'
            tmp = (int32_T)(10U + Ctrl_DW.wayIndex);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Ctrl_Y.ActualMode = (uint8_T)tmp;
            tmp = (int32_T)(Ctrl_DW.wayIndex + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            // Inport: '<Root>/TrajZNEVParams'
            Ctrl_CalculateTrajSegment(Ctrl_DW.wayIndex, (uint8_T)tmp,
              Ctrl_U.TrajZNEVParams[3]);
            Ctrl_DW.Time = 0.0F;
            tmp = (int32_T)(Ctrl_DW.wayIndex + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            tmp_0 = (int32_T)(Ctrl_DW.wayIndex + 1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            // Inport: '<Root>/Waypoints'
            Ctrl_B.AutoRefAng = (real32_T)atan2((real_T)(Ctrl_U.Waypoints[tmp +
              17] - Ctrl_U.Waypoints[Ctrl_DW.wayIndex + 17]), (real_T)
              (Ctrl_U.Waypoints[tmp_0 + 8] - Ctrl_U.Waypoints[Ctrl_DW.wayIndex +
               8]));
          } else if (Ctrl_U.ExecuteWaypoints == 2U) {
            // Transition: '<S4>:289'
            Ctrl_DW.is_AutoMode = Ctrl_IN_InitOrbitBezSecera;

            // Inport: '<Root>/TrajZNEVParams'
            // Entry 'InitOrbitBezSecera': '<S4>:306'
            a = TmpSignalConversionAtSFunctionI[1] - Ctrl_U.TrajZNEVParams[1];
            b_a = TmpSignalConversionAtSFunctionI[2] - Ctrl_U.TrajZNEVParams[2];
            Ctrl_DW.OrbRadius = a * a + b_a * b_a;
            Ctrl_DW.OrbRadius = (real32_T)sqrt((real_T)Ctrl_DW.OrbRadius);

            // Inport: '<Root>/TrajZNEVParams'
            Ctrl_DW.OrbPhi = (real32_T)atan2((real_T)
              (TmpSignalConversionAtSFunctionI[2] - Ctrl_U.TrajZNEVParams[2]),
              (real_T)(TmpSignalConversionAtSFunctionI[1] -
                       Ctrl_U.TrajZNEVParams[1]));
            Ctrl_DW.OrbdPhidT = Ctrl_U.TrajZNEVParams[3] / Ctrl_DW.OrbRadius;

            //  phi per second to match speed V
          } else {
            // Inport: '<Root>/Waypoints'
            Ctrl_B.AutoRef[0] = Ctrl_U.Waypoints[0];
            Ctrl_B.AutoRef[1] = Ctrl_U.Waypoints[9];
            Ctrl_B.AutoRef[2] = Ctrl_U.Waypoints[18];

            //  Altitude, N, E
            Ctrl_B.AutoRefAng = -2000.0F;

            //  disable
          }

          // End of Inport: '<Root>/ExecuteWaypoints'
          break;

         case Ctrl_IN_InitOrbitBezSecera:
          // During 'InitOrbitBezSecera': '<S4>:306'
          // Transition: '<S4>:295'
          Ctrl_DW.is_AutoMode = Ctrl_IN_Orbit;
          break;

         case Ctrl_IN_InitSegment:
          // During 'InitSegment': '<S4>:296'
          // Transition: '<S4>:288'
          Ctrl_DW.is_AutoMode = Ctrl_IN_GotoWaypoint;
          break;

         case Ctrl_IN_NextWaypoint:
          // During 'NextWaypoint': '<S4>:304'
          if (Ctrl_DW.temporalCounter_i1 >= 1000) {
            // Inport: '<Root>/WayCnt'
            // Transition: '<S4>:294'
            //  Optional delay
            if (Ctrl_DW.wayIndex > Ctrl_U.WayCnt) {
              // Transition: '<S4>:293'
              Ctrl_DW.is_AutoMode = Ctrl_IN_End;
            } else {
              // Transition: '<S4>:313'
              Ctrl_DW.is_AutoMode = Ctrl_IN_InitSegment;

              // Entry 'InitSegment': '<S4>:296'
              tmp = (int32_T)(10U + Ctrl_DW.wayIndex);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              Ctrl_Y.ActualMode = (uint8_T)tmp;
              tmp = (int32_T)(Ctrl_DW.wayIndex + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              // Inport: '<Root>/TrajZNEVParams'
              Ctrl_CalculateTrajSegment(Ctrl_DW.wayIndex, (uint8_T)tmp,
                Ctrl_U.TrajZNEVParams[3]);
              Ctrl_DW.Time = 0.0F;
              tmp = (int32_T)(Ctrl_DW.wayIndex + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              tmp_0 = (int32_T)(Ctrl_DW.wayIndex + 1U);
              if ((uint32_T)tmp_0 > 255U) {
                tmp_0 = 255;
              }

              // Inport: '<Root>/Waypoints'
              Ctrl_B.AutoRefAng = (real32_T)atan2((real_T)(Ctrl_U.Waypoints[tmp
                + 17] - Ctrl_U.Waypoints[Ctrl_DW.wayIndex + 17]), (real_T)
                (Ctrl_U.Waypoints[tmp_0 + 8] - Ctrl_U.Waypoints[Ctrl_DW.wayIndex
                 + 8]));
            }
          }
          break;

         default:
          // Inport: '<Root>/TrajZNEVParams'
          // During 'Orbit': '<S4>:305'
          Ctrl_B.AutoRef[0] = Ctrl_U.TrajZNEVParams[0];
          Ctrl_B.AutoRef[1] = (real32_T)cos((real_T)Ctrl_DW.OrbPhi) *
            Ctrl_DW.OrbRadius + Ctrl_U.TrajZNEVParams[1];
          Ctrl_B.AutoRef[2] = (real32_T)sin((real_T)Ctrl_DW.OrbPhi) *
            Ctrl_DW.OrbRadius + Ctrl_U.TrajZNEVParams[2];
          Ctrl_DW.OrbPhi += Ctrl_DW.OrbdPhidT * Ctrl_Ts;
          Ctrl_B.AutoRefAng = Ctrl_DW.OrbPhi + 3.14159274F;
          while (Ctrl_B.AutoRefAng > 6.2831853071795862) {
            Ctrl_B.AutoRefAng -= 6.28318548F;
          }
          break;
        }
        break;

       case Ctrl_IN_ManualMode:
        // During 'ManualMode': '<S4>:208'
        break;

       case Ctrl_IN_RateMode:
        // During 'RateMode': '<S4>:13'
        break;

       case Ctrl_IN_RollPitchMode:
        // During 'RollPitchMode': '<S4>:87'
        break;

       default:
        // During 'VelocityMode': '<S4>:88'
        break;
      }
    }
  }
}

// Model step function
void CtrlModelClass::step()
{
  int32_T j;
  int32_T cff;
  real32_T rtb_DiscreteFIRFilter;
  real32_T rtb_Gain;
  real32_T rtb_Rudder;
  real32_T rtb_Thr;
  real32_T rtb_Aileron;
  real32_T rtb_Elevator;
  real32_T rtb_IntegralGain_ah;
  real32_T rtb_Add4_n;
  real32_T rtb_ZeroGain_p2;
  boolean_T rtb_NotEqual_a;
  real32_T rtb_SignDeltaU_on;
  real32_T rtb_IntegralGain_c;
  real32_T rtb_Gain1;
  real32_T rtb_Saturate_l;
  real32_T rtb_IntegralGain_cm;
  real32_T rtb_SignDeltaU_je;
  real32_T rtb_IntegralGain_b;
  real32_T rtb_IntegralGain_i;
  real32_T rtb_SignDeltaU_h;
  real32_T rtb_Saturate_cr;
  real32_T rtb_FilterCoefficient_i;
  real32_T rtb_FilterCoefficient_j;
  real32_T rtb_SignDeltaU_f;
  real32_T rtb_Saturate_ej;
  real32_T rtb_DeadZone_n;
  real32_T rtb_Add1_j;
  real32_T rtb_SignPreIntegrator_g;
  boolean_T rtb_NotEqual_ac;
  boolean_T rtb_NotEqual_dy;
  boolean_T rtb_NotEqual_ga;
  boolean_T rtb_NotEqual_d;
  real32_T alt;
  real32_T TmpSignalConversionAtSFunctionI[3];
  int8_T rtb_Add4_b;

  // Outputs for Atomic SubSystem: '<Root>/Ctrl'
  // MATLAB Function: '<S2>/MATLAB Function' incorporates:
  //   Inport: '<Root>/Pressure0'
  //   Inport: '<Root>/PressureAbs'

  // MATLAB Function 'Ctrl/AltCalculator/MATLAB Function': '<S12>:1'
  if ((Ctrl_U.PressureAbs < 10000.0F) || (Ctrl_U.PressureAbs > 150000.0F)) {
    // '<S12>:1:3'
    //  pressure not valid?
    // '<S12>:1:4'
    alt = 0.0F;
  } else {
    // '<S12>:1:6'
    alt = (1.0F - (real32_T)pow((real_T)(Ctrl_U.PressureAbs / Ctrl_U.Pressure0),
            (real_T)0.190294951F)) * 44330.0F;
  }

  // End of MATLAB Function: '<S2>/MATLAB Function'

  // DiscreteFir: '<S2>/Discrete FIR Filter'
  rtb_DiscreteFIRFilter = alt * FilterK[0];
  cff = 1;
  for (j = Ctrl_DW.DiscreteFIRFilter_circBuf; j < 99; j++) {
    rtb_DiscreteFIRFilter += Ctrl_DW.DiscreteFIRFilter_states[j] * FilterK[cff];
    cff++;
  }

  for (j = 0; j < Ctrl_DW.DiscreteFIRFilter_circBuf; j++) {
    rtb_DiscreteFIRFilter += Ctrl_DW.DiscreteFIRFilter_states[j] * FilterK[cff];
    cff++;
  }

  // End of DiscreteFir: '<S2>/Discrete FIR Filter'

  // Gain: '<S2>/Gain' incorporates:
  //   Delay: '<S2>/Delay'
  //   Sum: '<S2>/Sum'

  rtb_Gain = (rtb_DiscreteFIRFilter - Ctrl_DW.Delay_DSTATE[0]) *
    Ctrl_P.Gain_Gain_f1;

  // SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport5' incorporates:
  //   Chart: '<S1>/Chart'
  //   Inport: '<Root>/FlatXe'

  TmpSignalConversionAtSFunctionI[0] = rtb_DiscreteFIRFilter;
  TmpSignalConversionAtSFunctionI[1] = Ctrl_U.FlatXe[0];
  TmpSignalConversionAtSFunctionI[2] = Ctrl_U.FlatXe[1];

  // Chart: '<S1>/Chart'
  // Gateway: Ctrl/Chart
  if (Ctrl_DW.temporalCounter_i1 < 1023U) {
    Ctrl_DW.temporalCounter_i1++;
  }

  if (Ctrl_DW.temporalCounter_i2 < 127U) {
    Ctrl_DW.temporalCounter_i2++;
  }

  // During: Ctrl/Chart
  if (Ctrl_DW.is_active_c1_Ctrl == 0U) {
    // Entry: Ctrl/Chart
    Ctrl_DW.is_active_c1_Ctrl = 1U;

    // Entry Internal: Ctrl/Chart
    // Entry 'SystemLogic': '<S4>:12'
    Ctrl_DW.Mode = 0U;

    // Entry Internal 'SystemLogic': '<S4>:12'
    // Transition: '<S4>:16'
    Ctrl_DW.is_SystemLogic = Ctrl_IN_Off;
    Ctrl_B.Off = true;

    // Outport: '<Root>/ActualMode'
    // Entry 'Off': '<S4>:14'
    Ctrl_Y.ActualMode = 0U;

    // Entry Internal 'LEDs': '<S4>:191'
    // Transition: '<S4>:194'
    Ctrl_DW.is_LEDs = Ctrl_IN_Off;

    // Entry 'Off': '<S4>:192'
    Ctrl_Y.LEDs[0] = false;
    Ctrl_Y.LEDs[1] = false;
    Ctrl_Y.LEDs[2] = false;

    // Entry Internal 'Off': '<S4>:192'
    // Transition: '<S4>:199'
    Ctrl_DW.is_Off = Ctrl_IN_RedOn;
    Ctrl_DW.temporalCounter_i2 = 0U;

    // Entry 'RedOn': '<S4>:197'
    Ctrl_Y.LEDs[0] = true;
  } else {
    Ctrl_SystemLogic(TmpSignalConversionAtSFunctionI);

    // During 'LEDs': '<S4>:191'
    if (Ctrl_DW.is_LEDs == Ctrl_IN_Off) {
      // During 'Off': '<S4>:192'
      if (Ctrl_DW.is_SystemLogic == Ctrl_IN_On) {
        // Transition: '<S4>:195'
        // Exit Internal 'Off': '<S4>:192'
        Ctrl_DW.is_Off = Ctrl_IN_NO_ACTIVE_CHILD;
        Ctrl_DW.is_LEDs = Ctrl_IN_On;

        // Entry 'On': '<S4>:193'
        Ctrl_Y.LEDs[0] = false;
        Ctrl_Y.LEDs[1] = false;
        Ctrl_Y.LEDs[2] = false;

        // Entry Internal 'On': '<S4>:193'
        // Transition: '<S4>:203'
        Ctrl_DW.is_On_b = Ctrl_IN_GreenOn;
        Ctrl_DW.temporalCounter_i2 = 0U;

        // Entry 'GreenOn': '<S4>:206'
        Ctrl_Y.LEDs[1] = true;
      } else if (Ctrl_DW.is_Off == Ctrl_IN_RedOff) {
        // During 'RedOff': '<S4>:198'
        if (Ctrl_DW.temporalCounter_i2 >= 100) {
          // Transition: '<S4>:201'
          Ctrl_DW.is_Off = Ctrl_IN_RedOn;
          Ctrl_DW.temporalCounter_i2 = 0U;

          // Entry 'RedOn': '<S4>:197'
          Ctrl_Y.LEDs[0] = true;
        }
      } else {
        // During 'RedOn': '<S4>:197'
        if (Ctrl_DW.temporalCounter_i2 >= 100) {
          // Transition: '<S4>:200'
          Ctrl_DW.is_Off = Ctrl_IN_RedOff;
          Ctrl_DW.temporalCounter_i2 = 0U;

          // Entry 'RedOff': '<S4>:198'
          Ctrl_Y.LEDs[0] = false;
        }
      }
    } else {
      // During 'On': '<S4>:193'
      if (Ctrl_DW.is_SystemLogic == Ctrl_IN_Off) {
        // Transition: '<S4>:196'
        // Exit Internal 'On': '<S4>:193'
        Ctrl_DW.is_On_b = Ctrl_IN_NO_ACTIVE_CHILD;
        Ctrl_DW.is_LEDs = Ctrl_IN_Off;

        // Entry 'Off': '<S4>:192'
        Ctrl_Y.LEDs[0] = false;
        Ctrl_Y.LEDs[1] = false;
        Ctrl_Y.LEDs[2] = false;

        // Entry Internal 'Off': '<S4>:192'
        // Transition: '<S4>:199'
        Ctrl_DW.is_Off = Ctrl_IN_RedOn;
        Ctrl_DW.temporalCounter_i2 = 0U;

        // Entry 'RedOn': '<S4>:197'
        Ctrl_Y.LEDs[0] = true;
      } else if (Ctrl_DW.is_On_b == Ctrl_IN_GreenOff) {
        // During 'GreenOff': '<S4>:205'
        if (Ctrl_DW.temporalCounter_i2 >= 100) {
          // Transition: '<S4>:204'
          Ctrl_DW.is_On_b = Ctrl_IN_GreenOn;
          Ctrl_DW.temporalCounter_i2 = 0U;

          // Entry 'GreenOn': '<S4>:206'
          Ctrl_Y.LEDs[1] = true;
        }
      } else {
        // During 'GreenOn': '<S4>:206'
        if (Ctrl_DW.temporalCounter_i2 >= 100) {
          // Transition: '<S4>:202'
          Ctrl_DW.is_On_b = Ctrl_IN_GreenOff;
          Ctrl_DW.temporalCounter_i2 = 0U;

          // Entry 'GreenOff': '<S4>:205'
          Ctrl_Y.LEDs[1] = false;
        }
      }
    }
  }

  // Gain: '<S5>/Gain3' incorporates:
  //   Constant: '<S5>/Constant3'
  //   Inport: '<Root>/Rudder'
  //   Sum: '<S5>/Subtract3'

  rtb_Rudder = (Ctrl_U.Rudder - Ctrl_P.Constant3_Value_b) * Ctrl_P.Gain3_Gain_f;

  // Saturate: '<S5>/Saturation3'
  if (rtb_Rudder > Ctrl_P.Saturation3_UpperSat) {
    rtb_Rudder = Ctrl_P.Saturation3_UpperSat;
  } else {
    if (rtb_Rudder < Ctrl_P.Saturation3_LowerSat) {
      rtb_Rudder = Ctrl_P.Saturation3_LowerSat;
    }
  }

  // End of Saturate: '<S5>/Saturation3'

  // Gain: '<S5>/Gain' incorporates:
  //   Constant: '<S5>/Constant'
  //   Inport: '<Root>/Thr'
  //   Sum: '<S5>/Subtract'

  rtb_Thr = (Ctrl_U.Thr - Ctrl_P.Constant_Value_pb) * Ctrl_P.Gain_Gain_g;

  // Saturate: '<S5>/Saturation'
  if (rtb_Thr > Ctrl_P.Saturation_UpperSat) {
    rtb_Thr = Ctrl_P.Saturation_UpperSat;
  } else {
    if (rtb_Thr < Ctrl_P.Saturation_LowerSat) {
      rtb_Thr = Ctrl_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S5>/Saturation'

  // Gain: '<S5>/Gain1' incorporates:
  //   Constant: '<S5>/Constant1'
  //   Inport: '<Root>/Aileron'
  //   Sum: '<S5>/Subtract1'

  rtb_Aileron = (Ctrl_U.Aileron - Ctrl_P.Constant1_Value_g) *
    Ctrl_P.Gain1_Gain_b;

  // Saturate: '<S5>/Saturation1'
  if (rtb_Aileron > Ctrl_P.Saturation1_UpperSat) {
    rtb_Aileron = Ctrl_P.Saturation1_UpperSat;
  } else {
    if (rtb_Aileron < Ctrl_P.Saturation1_LowerSat) {
      rtb_Aileron = Ctrl_P.Saturation1_LowerSat;
    }
  }

  // End of Saturate: '<S5>/Saturation1'

  // Gain: '<S5>/Gain2' incorporates:
  //   Constant: '<S5>/Constant2'
  //   Inport: '<Root>/Elevator'
  //   Sum: '<S5>/Subtract2'

  rtb_Elevator = (Ctrl_U.Elevator - Ctrl_P.Constant2_Value_c) *
    Ctrl_P.Gain2_Gain_k;

  // Saturate: '<S5>/Saturation2'
  if (rtb_Elevator > Ctrl_P.Saturation2_UpperSat) {
    rtb_Elevator = Ctrl_P.Saturation2_UpperSat;
  } else {
    if (rtb_Elevator < Ctrl_P.Saturation2_LowerSat) {
      rtb_Elevator = Ctrl_P.Saturation2_LowerSat;
    }
  }

  // End of Saturate: '<S5>/Saturation2'

  // Outputs for Enabled SubSystem: '<S1>/AutoCtrl' incorporates:
  //   EnablePort: '<S3>/Enable'

  if (Ctrl_B.AutoMode) {
    if (!Ctrl_DW.AutoCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S20>/Integrator'
      Ctrl_DW.Integrator_DSTATE_dl = Ctrl_P.Integrator_IC;

      // InitializeConditions for DiscreteIntegrator: '<S37>/Integrator'
      Ctrl_DW.Integrator_DSTATE_id = Ctrl_P.Integrator_IC_k;

      // InitializeConditions for DiscreteIntegrator: '<S36>/Integrator'
      Ctrl_DW.Integrator_DSTATE_ba = Ctrl_P.Integrator_IC_h;

      // InitializeConditions for DiscreteIntegrator: '<S32>/Integrator'
      Ctrl_DW.Integrator_DSTATE_l = Ctrl_P.Integrator_IC_m;

      // InitializeConditions for DiscreteIntegrator: '<S32>/Filter'
      Ctrl_DW.Filter_DSTATE_pa = Ctrl_P.Filter_IC;

      // InitializeConditions for DiscreteIntegrator: '<S27>/Integrator'
      Ctrl_DW.Integrator_DSTATE_j = Ctrl_P.Integrator_IC_l;

      // InitializeConditions for DiscreteIntegrator: '<S27>/Filter'
      Ctrl_DW.Filter_DSTATE_n = Ctrl_P.Filter_IC_d;

      // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' 
      Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j = 1U;

      // InitializeConditions for DiscreteIntegrator: '<S41>/Integrator'
      Ctrl_DW.Integrator_DSTATE_di = Ctrl_P.Integrator_IC_o;
      Ctrl_DW.AutoCtrl_MODE = true;
    }

    // Gain: '<S21>/Proportional Gain' incorporates:
    //   Sum: '<S13>/Sum1'

    rtb_SignDeltaU_f = (Ctrl_B.AutoRef[0] - rtb_DiscreteFIRFilter) * AltKp;

    // Saturate: '<S21>/Saturate'
    if (rtb_SignDeltaU_f > Ctrl_P.DiscretePIDController2_UpperSat) {
      rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController2_UpperSat;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController2_LowerSat) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController2_LowerSat;
      }
    }

    // Gain: '<S13>/Scale Vel' incorporates:
    //   Saturate: '<S21>/Saturate'

    Ctrl_B.VertVelRef5 = Ctrl_P.ScaleVel_Gain * rtb_SignDeltaU_f;

    // Saturate: '<S13>/Fix Faulty Baro'
    if (rtb_Gain > Ctrl_P.FixFaultyBaro_UpperSat) {
      rtb_Gain1 = Ctrl_P.FixFaultyBaro_UpperSat;
    } else if (rtb_Gain < Ctrl_P.FixFaultyBaro_LowerSat) {
      rtb_Gain1 = Ctrl_P.FixFaultyBaro_LowerSat;
    } else {
      rtb_Gain1 = rtb_Gain;
    }

    // Sum: '<S13>/Sum3' incorporates:
    //   Saturate: '<S13>/Fix Faulty Baro'

    rtb_IntegralGain_ah = Ctrl_B.VertVelRef5 - rtb_Gain1;

    // Sum: '<S20>/Sum' incorporates:
    //   DiscreteIntegrator: '<S20>/Integrator'
    //   Gain: '<S20>/Proportional Gain'

    rtb_Add4_n = AltRateKp * rtb_IntegralGain_ah + Ctrl_DW.Integrator_DSTATE_dl;

    // Saturate: '<S20>/Saturate'
    if (rtb_Add4_n > Ctrl_P.DiscretePIDController1_UpperSat) {
      rtb_Gain1 = Ctrl_P.DiscretePIDController1_UpperSat;
    } else if (rtb_Add4_n < Ctrl_P.DiscretePIDController1_LowerSat) {
      rtb_Gain1 = Ctrl_P.DiscretePIDController1_LowerSat;
    } else {
      rtb_Gain1 = rtb_Add4_n;
    }

    // Bias: '<S13>/Bias1' incorporates:
    //   Saturate: '<S20>/Saturate'

    Ctrl_B.VertVelOut5 = rtb_Gain1 + AltRateBias;

    // Gain: '<S22>/ZeroGain'
    rtb_ZeroGain_p2 = Ctrl_P.ZeroGain_Gain * rtb_Add4_n;

    // DeadZone: '<S22>/DeadZone'
    if (rtb_Add4_n > Ctrl_P.DiscretePIDController1_UpperSat) {
      rtb_Add4_n -= Ctrl_P.DiscretePIDController1_UpperSat;
    } else if (rtb_Add4_n >= Ctrl_P.DiscretePIDController1_LowerSat) {
      rtb_Add4_n = 0.0F;
    } else {
      rtb_Add4_n -= Ctrl_P.DiscretePIDController1_LowerSat;
    }

    // End of DeadZone: '<S22>/DeadZone'

    // RelationalOperator: '<S22>/NotEqual'
    rtb_NotEqual_a = (rtb_ZeroGain_p2 != rtb_Add4_n);

    // Signum: '<S22>/SignDeltaU'
    if (rtb_Add4_n < 0.0F) {
      rtb_Add4_n = -1.0F;
    } else {
      if (rtb_Add4_n > 0.0F) {
        rtb_Add4_n = 1.0F;
      }
    }

    // End of Signum: '<S22>/SignDeltaU'

    // Gain: '<S20>/Integral Gain'
    rtb_IntegralGain_ah *= AltRateKi;

    // Signum: '<S22>/SignPreIntegrator'
    if (rtb_IntegralGain_ah < 0.0F) {
      rtb_Saturate_l = -1.0F;
    } else if (rtb_IntegralGain_ah > 0.0F) {
      rtb_Saturate_l = 1.0F;
    } else {
      rtb_Saturate_l = rtb_IntegralGain_ah;
    }

    // DataTypeConversion: '<S22>/DataTypeConv2' incorporates:
    //   Signum: '<S22>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Saturate_l, (real_T)256.0F);

    // DataTypeConversion: '<S22>/DataTypeConv1'
    if (rtb_Add4_n < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_Add4_n;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S22>/DataTypeConv1'

    // Switch: '<S20>/Switch' incorporates:
    //   Constant: '<S20>/Constant'
    //   DataTypeConversion: '<S22>/DataTypeConv2'
    //   Logic: '<S22>/AND'
    //   RelationalOperator: '<S22>/Equal'

    if (rtb_NotEqual_a && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_ZeroGain_p2 = Ctrl_P.Constant_Value;
    } else {
      rtb_ZeroGain_p2 = rtb_IntegralGain_ah;
    }

    // End of Switch: '<S20>/Switch'

    // Saturate: '<S13>/Limit Output'
    if (Ctrl_B.VertVelOut5 > Ctrl_P.LimitOutput_UpperSat) {
      rtb_Add4_n = Ctrl_P.LimitOutput_UpperSat;
    } else if (Ctrl_B.VertVelOut5 < Ctrl_P.LimitOutput_LowerSat) {
      rtb_Add4_n = Ctrl_P.LimitOutput_LowerSat;
    } else {
      rtb_Add4_n = Ctrl_B.VertVelOut5;
    }

    // End of Saturate: '<S13>/Limit Output'

    // Gain: '<S31>/Proportional Gain' incorporates:
    //   Inport: '<Root>/FlatXe'
    //   Sum: '<S16>/Sum2'

    rtb_SignDeltaU_f = (Ctrl_B.AutoRef[1] - Ctrl_U.FlatXe[0]) * PosKp;

    // Saturate: '<S31>/Saturate'
    if (rtb_SignDeltaU_f > Ctrl_P.DiscretePIDController2_UpperS_o) {
      rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController2_UpperS_o;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController2_LowerS_e) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController2_LowerS_e;
      }
    }

    // Sum: '<S18>/Sum2' incorporates:
    //   Gain: '<S18>/Gain'
    //   Inport: '<Root>/FlatVe'
    //   Saturate: '<S31>/Saturate'

    rtb_IntegralGain_ah = VelMax * rtb_SignDeltaU_f - Ctrl_U.FlatVe[0];

    // Sum: '<S37>/Sum' incorporates:
    //   DiscreteIntegrator: '<S37>/Integrator'
    //   Gain: '<S37>/Proportional Gain'

    rtb_SignDeltaU_on = VelKp * rtb_IntegralGain_ah +
      Ctrl_DW.Integrator_DSTATE_id;

    // Saturate: '<S37>/Saturate'
    if (rtb_SignDeltaU_on > Ctrl_P.DiscretePIDController2_UpperS_d) {
      rtb_IntegralGain_c = Ctrl_P.DiscretePIDController2_UpperS_d;
    } else if (rtb_SignDeltaU_on < Ctrl_P.DiscretePIDController2_LowerS_h) {
      rtb_IntegralGain_c = Ctrl_P.DiscretePIDController2_LowerS_h;
    } else {
      rtb_IntegralGain_c = rtb_SignDeltaU_on;
    }

    // End of Saturate: '<S37>/Saturate'

    // Gain: '<S35>/Gain1' incorporates:
    //   Inport: '<Root>/RPY'

    rtb_Gain1 = Ctrl_P.Gain1_Gain * Ctrl_U.RPY[2];

    // Trigonometry: '<S18>/Trigonometric Function'
    rtb_Saturate_l = (real32_T)sin((real_T)rtb_Gain1);
    rtb_Gain1 = (real32_T)cos((real_T)rtb_Gain1);

    // Gain: '<S30>/Proportional Gain' incorporates:
    //   Inport: '<Root>/FlatXe'
    //   Sum: '<S16>/Sum1'

    rtb_SignDeltaU_f = (Ctrl_B.AutoRef[2] - Ctrl_U.FlatXe[1]) * PosKp;

    // Saturate: '<S30>/Saturate'
    if (rtb_SignDeltaU_f > Ctrl_P.DiscretePIDController1_UpperS_b) {
      rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController1_UpperS_b;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController1_LowerS_m) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController1_LowerS_m;
      }
    }

    // Sum: '<S18>/Sum1' incorporates:
    //   Gain: '<S18>/Gain1'
    //   Inport: '<Root>/FlatVe'
    //   Saturate: '<S30>/Saturate'

    rtb_IntegralGain_cm = VelMax * rtb_SignDeltaU_f - Ctrl_U.FlatVe[1];

    // Sum: '<S36>/Sum' incorporates:
    //   DiscreteIntegrator: '<S36>/Integrator'
    //   Gain: '<S36>/Proportional Gain'

    rtb_SignDeltaU_je = VelKp * rtb_IntegralGain_cm +
      Ctrl_DW.Integrator_DSTATE_ba;

    // Saturate: '<S36>/Saturate'
    if (rtb_SignDeltaU_je > Ctrl_P.DiscretePIDController1_UpperS_g) {
      rtb_IntegralGain_b = Ctrl_P.DiscretePIDController1_UpperS_g;
    } else if (rtb_SignDeltaU_je < Ctrl_P.DiscretePIDController1_LowerS_p) {
      rtb_IntegralGain_b = Ctrl_P.DiscretePIDController1_LowerS_p;
    } else {
      rtb_IntegralGain_b = rtb_SignDeltaU_je;
    }

    // End of Saturate: '<S36>/Saturate'

    // Gain: '<S33>/Proportional Gain' incorporates:
    //   Gain: '<S17>/Scale roll2'
    //   Inport: '<Root>/RPY'
    //   Product: '<S18>/Product2'
    //   Product: '<S18>/Product3'
    //   Sum: '<S17>/Sum3'
    //   Sum: '<S18>/Add1'

    rtb_SignDeltaU_f = ((rtb_Gain1 * rtb_IntegralGain_b - rtb_IntegralGain_c *
                         rtb_Saturate_l) * RollPitchMax - Ctrl_U.RPY[0]) *
      RollPitchKp;

    // Saturate: '<S33>/Saturate'
    if (rtb_SignDeltaU_f > RollPitchRateMax) {
      rtb_SignDeltaU_f = RollPitchRateMax;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController1_LowerS_g) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController1_LowerS_g;
      }
    }

    // Sum: '<S17>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'
    //   Saturate: '<S33>/Saturate'

    rtb_IntegralGain_i = rtb_SignDeltaU_f - Ctrl_U.dRPY[0];

    // Gain: '<S32>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S32>/Filter'
    //   Gain: '<S32>/Derivative Gain'
    //   Sum: '<S32>/SumD'

    rtb_FilterCoefficient_i = (RollPitchRateKd * rtb_IntegralGain_i -
      Ctrl_DW.Filter_DSTATE_pa) * Ctrl_P.DiscretePIDController_N;

    // Sum: '<S32>/Sum' incorporates:
    //   DiscreteIntegrator: '<S32>/Integrator'
    //   Gain: '<S32>/Proportional Gain'

    rtb_SignDeltaU_h = (RollPitchRateKp * rtb_IntegralGain_i +
                        Ctrl_DW.Integrator_DSTATE_l) + rtb_FilterCoefficient_i;

    // Saturate: '<S32>/Saturate'
    if (rtb_SignDeltaU_h > Ctrl_P.DiscretePIDController_UpperSatu) {
      rtb_Saturate_cr = Ctrl_P.DiscretePIDController_UpperSatu;
    } else if (rtb_SignDeltaU_h < Ctrl_P.DiscretePIDController_LowerSatu) {
      rtb_Saturate_cr = Ctrl_P.DiscretePIDController_LowerSatu;
    } else {
      rtb_Saturate_cr = rtb_SignDeltaU_h;
    }

    // End of Saturate: '<S32>/Saturate'

    // Gain: '<S28>/Proportional Gain' incorporates:
    //   Gain: '<S15>/Scale roll1'
    //   Inport: '<Root>/RPY'
    //   Product: '<S18>/Product'
    //   Product: '<S18>/Product1'
    //   Sum: '<S15>/Sum3'
    //   Sum: '<S18>/Add'

    rtb_SignDeltaU_f = (((0.0F - rtb_IntegralGain_c * rtb_Gain1) -
                         rtb_Saturate_l * rtb_IntegralGain_b) * RollPitchMax -
                        Ctrl_U.RPY[1]) * RollPitchKp;

    // Saturate: '<S28>/Saturate'
    if (rtb_SignDeltaU_f > RollPitchRateMax) {
      rtb_SignDeltaU_f = RollPitchRateMax;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController1_LowerS_n) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController1_LowerS_n;
      }
    }

    // Sum: '<S15>/Sum1' incorporates:
    //   Inport: '<Root>/dRPY'
    //   Saturate: '<S28>/Saturate'

    rtb_IntegralGain_b = rtb_SignDeltaU_f - Ctrl_U.dRPY[1];

    // Gain: '<S27>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S27>/Filter'
    //   Gain: '<S27>/Derivative Gain'
    //   Sum: '<S27>/SumD'

    rtb_FilterCoefficient_j = (RollPitchRateKd * rtb_IntegralGain_b -
      Ctrl_DW.Filter_DSTATE_n) * Ctrl_P.DiscretePIDController_N_h;

    // Sum: '<S27>/Sum' incorporates:
    //   DiscreteIntegrator: '<S27>/Integrator'
    //   Gain: '<S27>/Proportional Gain'

    rtb_Gain1 = (RollPitchRateKp * rtb_IntegralGain_b +
                 Ctrl_DW.Integrator_DSTATE_j) + rtb_FilterCoefficient_j;

    // Saturate: '<S27>/Saturate'
    if (rtb_Gain1 > Ctrl_P.DiscretePIDController_UpperSa_g) {
      rtb_Saturate_l = Ctrl_P.DiscretePIDController_UpperSa_g;
    } else if (rtb_Gain1 < Ctrl_P.DiscretePIDController_LowerSa_o) {
      rtb_Saturate_l = Ctrl_P.DiscretePIDController_LowerSa_o;
    } else {
      rtb_Saturate_l = rtb_Gain1;
    }

    // End of Saturate: '<S27>/Saturate'

    // DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
    //   Inport: '<Root>/RPY'

    if (Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j != 0) {
      Ctrl_DW.DiscreteTimeIntegrator_DSTATE_f = Ctrl_U.RPY[2];
    }

    rtb_IntegralGain_c = Ctrl_DW.DiscreteTimeIntegrator_DSTATE_f;

    // End of DiscreteIntegrator: '<S19>/Discrete-Time Integrator'

    // Switch: '<S19>/Switch' incorporates:
    //   Gain: '<S43>/Gain'

    if (Ctrl_B.AutoRefAng > Ctrl_P.Switch_Threshold) {
      rtb_IntegralGain_c = Ctrl_P.Gain_Gain * Ctrl_B.AutoRefAng;
    }

    // End of Switch: '<S19>/Switch'

    // MATLAB Function: '<S19>/Correct Yaw1' incorporates:
    //   Inport: '<Root>/RPY'
    //   Sum: '<S19>/Sum3'

    Ctrl_CorrectYaw1(rtb_IntegralGain_c - Ctrl_U.RPY[2], &Ctrl_B.sf_CorrectYaw1);

    // Gain: '<S42>/Proportional Gain'
    rtb_SignDeltaU_f = YawKp * Ctrl_B.sf_CorrectYaw1.y;

    // Saturate: '<S42>/Saturate'
    if (rtb_SignDeltaU_f > YawRateMax) {
      rtb_SignDeltaU_f = YawRateMax;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController3_LowerSat) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController3_LowerSat;
      }
    }

    // Sum: '<S19>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'
    //   Saturate: '<S42>/Saturate'

    rtb_IntegralGain_c = rtb_SignDeltaU_f - Ctrl_U.dRPY[2];

    // Sum: '<S41>/Sum' incorporates:
    //   DiscreteIntegrator: '<S41>/Integrator'
    //   Gain: '<S41>/Proportional Gain'

    rtb_SignDeltaU_f = YawRateKp * rtb_IntegralGain_c +
      Ctrl_DW.Integrator_DSTATE_di;

    // Saturate: '<S41>/Saturate'
    if (rtb_SignDeltaU_f > Ctrl_P.DiscretePIDController_UpperS_gi) {
      rtb_Saturate_ej = Ctrl_P.DiscretePIDController_UpperS_gi;
    } else if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController_LowerSa_i) {
      rtb_Saturate_ej = Ctrl_P.DiscretePIDController_LowerSa_i;
    } else {
      rtb_Saturate_ej = rtb_SignDeltaU_f;
    }

    // End of Saturate: '<S41>/Saturate'

    // Sum: '<S14>/Add1'
    rtb_Add1_j = ((rtb_Add4_n - rtb_Saturate_cr) + rtb_Saturate_l) +
      rtb_Saturate_ej;

    // Sum: '<S14>/Add2'
    rtb_SignPreIntegrator_g = ((rtb_Add4_n - rtb_Saturate_cr) - rtb_Saturate_l)
      - rtb_Saturate_ej;

    // Sum: '<S14>/Add3'
    rtb_DeadZone_n = ((rtb_Add4_n + rtb_Saturate_cr) + rtb_Saturate_l) -
      rtb_Saturate_ej;

    // Sum: '<S14>/Add4'
    rtb_Add4_n = ((rtb_Add4_n + rtb_Saturate_cr) - rtb_Saturate_l) +
      rtb_Saturate_ej;

    // Saturate: '<S23>/Limit3'
    if (rtb_DeadZone_n > Ctrl_P.Limit3_UpperSat) {
      rtb_DeadZone_n = Ctrl_P.Limit3_UpperSat;
    } else {
      if (rtb_DeadZone_n < Ctrl_P.Limit3_LowerSat) {
        rtb_DeadZone_n = Ctrl_P.Limit3_LowerSat;
      }
    }

    // Sum: '<S23>/Subtract' incorporates:
    //   Constant: '<S23>/Constant'
    //   Gain: '<S23>/Gain'
    //   Saturate: '<S23>/Limit3'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_f * rtb_DeadZone_n + Ctrl_P.Constant_Value_p;

    // Saturate: '<S24>/Limit3'
    if (rtb_Add1_j > Ctrl_P.Limit3_UpperSat_k) {
      rtb_Add1_j = Ctrl_P.Limit3_UpperSat_k;
    } else {
      if (rtb_Add1_j < Ctrl_P.Limit3_LowerSat_i) {
        rtb_Add1_j = Ctrl_P.Limit3_LowerSat_i;
      }
    }

    // Sum: '<S24>/Subtract' incorporates:
    //   Constant: '<S24>/Constant'
    //   Gain: '<S24>/Gain'
    //   Saturate: '<S24>/Limit3'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_a * rtb_Add1_j + Ctrl_P.Constant_Value_a;

    // Saturate: '<S25>/Limit3'
    if (rtb_SignPreIntegrator_g > Ctrl_P.Limit3_UpperSat_m) {
      rtb_SignPreIntegrator_g = Ctrl_P.Limit3_UpperSat_m;
    } else {
      if (rtb_SignPreIntegrator_g < Ctrl_P.Limit3_LowerSat_ih) {
        rtb_SignPreIntegrator_g = Ctrl_P.Limit3_LowerSat_ih;
      }
    }

    // Sum: '<S25>/Subtract' incorporates:
    //   Constant: '<S25>/Constant'
    //   Gain: '<S25>/Gain'
    //   Saturate: '<S25>/Limit3'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_j * rtb_SignPreIntegrator_g +
      Ctrl_P.Constant_Value_j;

    // Saturate: '<S26>/Limit3'
    if (rtb_Add4_n > Ctrl_P.Limit3_UpperSat_a) {
      rtb_Add4_n = Ctrl_P.Limit3_UpperSat_a;
    } else {
      if (rtb_Add4_n < Ctrl_P.Limit3_LowerSat_n) {
        rtb_Add4_n = Ctrl_P.Limit3_LowerSat_n;
      }
    }

    // Sum: '<S26>/Subtract' incorporates:
    //   Constant: '<S26>/Constant'
    //   Gain: '<S26>/Gain'
    //   Saturate: '<S26>/Limit3'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_b * rtb_Add4_n + Ctrl_P.Constant_Value_p4;

    // Gain: '<S29>/ZeroGain'
    rtb_Add4_n = Ctrl_P.ZeroGain_Gain_p * rtb_Gain1;

    // DeadZone: '<S29>/DeadZone'
    if (rtb_Gain1 > Ctrl_P.DiscretePIDController_UpperSa_g) {
      rtb_Gain1 -= Ctrl_P.DiscretePIDController_UpperSa_g;
    } else if (rtb_Gain1 >= Ctrl_P.DiscretePIDController_LowerSa_o) {
      rtb_Gain1 = 0.0F;
    } else {
      rtb_Gain1 -= Ctrl_P.DiscretePIDController_LowerSa_o;
    }

    // End of DeadZone: '<S29>/DeadZone'

    // RelationalOperator: '<S29>/NotEqual'
    rtb_NotEqual_a = (rtb_Add4_n != rtb_Gain1);

    // Signum: '<S29>/SignDeltaU'
    if (rtb_Gain1 < 0.0F) {
      rtb_Gain1 = -1.0F;
    } else {
      if (rtb_Gain1 > 0.0F) {
        rtb_Gain1 = 1.0F;
      }
    }

    // End of Signum: '<S29>/SignDeltaU'

    // Gain: '<S27>/Integral Gain'
    rtb_IntegralGain_b *= RollPitchRateKi;

    // Gain: '<S34>/ZeroGain'
    rtb_Add4_n = Ctrl_P.ZeroGain_Gain_px * rtb_SignDeltaU_h;

    // DeadZone: '<S34>/DeadZone'
    if (rtb_SignDeltaU_h > Ctrl_P.DiscretePIDController_UpperSatu) {
      rtb_SignDeltaU_h -= Ctrl_P.DiscretePIDController_UpperSatu;
    } else if (rtb_SignDeltaU_h >= Ctrl_P.DiscretePIDController_LowerSatu) {
      rtb_SignDeltaU_h = 0.0F;
    } else {
      rtb_SignDeltaU_h -= Ctrl_P.DiscretePIDController_LowerSatu;
    }

    // End of DeadZone: '<S34>/DeadZone'

    // RelationalOperator: '<S34>/NotEqual'
    rtb_NotEqual_ac = (rtb_Add4_n != rtb_SignDeltaU_h);

    // Signum: '<S34>/SignDeltaU'
    if (rtb_SignDeltaU_h < 0.0F) {
      rtb_SignDeltaU_h = -1.0F;
    } else {
      if (rtb_SignDeltaU_h > 0.0F) {
        rtb_SignDeltaU_h = 1.0F;
      }
    }

    // End of Signum: '<S34>/SignDeltaU'

    // Gain: '<S32>/Integral Gain'
    rtb_IntegralGain_i *= RollPitchRateKi;

    // Gain: '<S38>/ZeroGain'
    rtb_Add4_n = Ctrl_P.ZeroGain_Gain_e * rtb_SignDeltaU_je;

    // DeadZone: '<S38>/DeadZone'
    if (rtb_SignDeltaU_je > Ctrl_P.DiscretePIDController1_UpperS_g) {
      rtb_SignDeltaU_je -= Ctrl_P.DiscretePIDController1_UpperS_g;
    } else if (rtb_SignDeltaU_je >= Ctrl_P.DiscretePIDController1_LowerS_p) {
      rtb_SignDeltaU_je = 0.0F;
    } else {
      rtb_SignDeltaU_je -= Ctrl_P.DiscretePIDController1_LowerS_p;
    }

    // End of DeadZone: '<S38>/DeadZone'

    // RelationalOperator: '<S38>/NotEqual'
    rtb_NotEqual_dy = (rtb_Add4_n != rtb_SignDeltaU_je);

    // Signum: '<S38>/SignDeltaU'
    if (rtb_SignDeltaU_je < 0.0F) {
      rtb_SignDeltaU_je = -1.0F;
    } else {
      if (rtb_SignDeltaU_je > 0.0F) {
        rtb_SignDeltaU_je = 1.0F;
      }
    }

    // End of Signum: '<S38>/SignDeltaU'

    // Gain: '<S36>/Integral Gain'
    rtb_IntegralGain_cm *= VelKi;

    // Gain: '<S39>/ZeroGain'
    rtb_Add4_n = Ctrl_P.ZeroGain_Gain_g * rtb_SignDeltaU_on;

    // DeadZone: '<S39>/DeadZone'
    if (rtb_SignDeltaU_on > Ctrl_P.DiscretePIDController2_UpperS_d) {
      rtb_SignDeltaU_on -= Ctrl_P.DiscretePIDController2_UpperS_d;
    } else if (rtb_SignDeltaU_on >= Ctrl_P.DiscretePIDController2_LowerS_h) {
      rtb_SignDeltaU_on = 0.0F;
    } else {
      rtb_SignDeltaU_on -= Ctrl_P.DiscretePIDController2_LowerS_h;
    }

    // End of DeadZone: '<S39>/DeadZone'

    // RelationalOperator: '<S39>/NotEqual'
    rtb_NotEqual_ga = (rtb_Add4_n != rtb_SignDeltaU_on);

    // Signum: '<S39>/SignDeltaU'
    if (rtb_SignDeltaU_on < 0.0F) {
      rtb_SignDeltaU_on = -1.0F;
    } else {
      if (rtb_SignDeltaU_on > 0.0F) {
        rtb_SignDeltaU_on = 1.0F;
      }
    }

    // End of Signum: '<S39>/SignDeltaU'

    // Gain: '<S37>/Integral Gain'
    rtb_IntegralGain_ah *= VelKi;

    // Gain: '<S44>/ZeroGain'
    rtb_Add4_n = Ctrl_P.ZeroGain_Gain_n * rtb_SignDeltaU_f;

    // DeadZone: '<S44>/DeadZone'
    if (rtb_SignDeltaU_f > Ctrl_P.DiscretePIDController_UpperS_gi) {
      rtb_SignDeltaU_f -= Ctrl_P.DiscretePIDController_UpperS_gi;
    } else if (rtb_SignDeltaU_f >= Ctrl_P.DiscretePIDController_LowerSa_i) {
      rtb_SignDeltaU_f = 0.0F;
    } else {
      rtb_SignDeltaU_f -= Ctrl_P.DiscretePIDController_LowerSa_i;
    }

    // End of DeadZone: '<S44>/DeadZone'

    // RelationalOperator: '<S44>/NotEqual'
    rtb_NotEqual_d = (rtb_Add4_n != rtb_SignDeltaU_f);

    // Signum: '<S44>/SignDeltaU'
    if (rtb_SignDeltaU_f < 0.0F) {
      rtb_SignDeltaU_f = -1.0F;
    } else {
      if (rtb_SignDeltaU_f > 0.0F) {
        rtb_SignDeltaU_f = 1.0F;
      }
    }

    // End of Signum: '<S44>/SignDeltaU'

    // Gain: '<S41>/Integral Gain'
    rtb_IntegralGain_c *= YawRateKi;

    // Update for DiscreteIntegrator: '<S20>/Integrator'
    Ctrl_DW.Integrator_DSTATE_dl += Ctrl_P.Integrator_gainval * rtb_ZeroGain_p2;

    // Signum: '<S39>/SignPreIntegrator'
    if (rtb_IntegralGain_ah < 0.0F) {
      rtb_Saturate_l = -1.0F;
    } else if (rtb_IntegralGain_ah > 0.0F) {
      rtb_Saturate_l = 1.0F;
    } else {
      rtb_Saturate_l = rtb_IntegralGain_ah;
    }

    // DataTypeConversion: '<S39>/DataTypeConv2' incorporates:
    //   Signum: '<S39>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Saturate_l, (real_T)256.0F);

    // DataTypeConversion: '<S39>/DataTypeConv1'
    if (rtb_SignDeltaU_on < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_SignDeltaU_on;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S39>/DataTypeConv1'

    // Switch: '<S37>/Switch' incorporates:
    //   Constant: '<S37>/Constant'
    //   DataTypeConversion: '<S39>/DataTypeConv2'
    //   Logic: '<S39>/AND'
    //   RelationalOperator: '<S39>/Equal'

    if (rtb_NotEqual_ga && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_IntegralGain_ah = Ctrl_P.Constant_Value_hp;
    }

    // End of Switch: '<S37>/Switch'

    // Update for DiscreteIntegrator: '<S37>/Integrator'
    Ctrl_DW.Integrator_DSTATE_id += Ctrl_P.Integrator_gainval_g *
      rtb_IntegralGain_ah;

    // Signum: '<S38>/SignPreIntegrator'
    if (rtb_IntegralGain_cm < 0.0F) {
      rtb_IntegralGain_ah = -1.0F;
    } else if (rtb_IntegralGain_cm > 0.0F) {
      rtb_IntegralGain_ah = 1.0F;
    } else {
      rtb_IntegralGain_ah = rtb_IntegralGain_cm;
    }

    // DataTypeConversion: '<S38>/DataTypeConv2' incorporates:
    //   Signum: '<S38>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_IntegralGain_ah, (real_T)256.0F);

    // DataTypeConversion: '<S38>/DataTypeConv1'
    if (rtb_SignDeltaU_je < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_SignDeltaU_je;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S38>/DataTypeConv1'

    // Switch: '<S36>/Switch' incorporates:
    //   Constant: '<S36>/Constant'
    //   DataTypeConversion: '<S38>/DataTypeConv2'
    //   Logic: '<S38>/AND'
    //   RelationalOperator: '<S38>/Equal'

    if (rtb_NotEqual_dy && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_IntegralGain_cm = Ctrl_P.Constant_Value_h;
    }

    // End of Switch: '<S36>/Switch'

    // Update for DiscreteIntegrator: '<S36>/Integrator'
    Ctrl_DW.Integrator_DSTATE_ba += Ctrl_P.Integrator_gainval_i *
      rtb_IntegralGain_cm;

    // Signum: '<S34>/SignPreIntegrator'
    if (rtb_IntegralGain_i < 0.0F) {
      rtb_IntegralGain_cm = -1.0F;
    } else if (rtb_IntegralGain_i > 0.0F) {
      rtb_IntegralGain_cm = 1.0F;
    } else {
      rtb_IntegralGain_cm = rtb_IntegralGain_i;
    }

    // DataTypeConversion: '<S34>/DataTypeConv2' incorporates:
    //   Signum: '<S34>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_IntegralGain_cm, (real_T)256.0F);

    // DataTypeConversion: '<S34>/DataTypeConv1'
    if (rtb_SignDeltaU_h < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_SignDeltaU_h;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S34>/DataTypeConv1'

    // Switch: '<S32>/Switch' incorporates:
    //   Constant: '<S32>/Constant'
    //   DataTypeConversion: '<S34>/DataTypeConv2'
    //   Logic: '<S34>/AND'
    //   RelationalOperator: '<S34>/Equal'

    if (rtb_NotEqual_ac && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_IntegralGain_i = Ctrl_P.Constant_Value_e;
    }

    // End of Switch: '<S32>/Switch'

    // Update for DiscreteIntegrator: '<S32>/Integrator'
    Ctrl_DW.Integrator_DSTATE_l += Ctrl_P.Integrator_gainval_p *
      rtb_IntegralGain_i;

    // Update for DiscreteIntegrator: '<S32>/Filter'
    Ctrl_DW.Filter_DSTATE_pa += Ctrl_P.Filter_gainval * rtb_FilterCoefficient_i;

    // Signum: '<S29>/SignPreIntegrator'
    if (rtb_IntegralGain_b < 0.0F) {
      rtb_IntegralGain_cm = -1.0F;
    } else if (rtb_IntegralGain_b > 0.0F) {
      rtb_IntegralGain_cm = 1.0F;
    } else {
      rtb_IntegralGain_cm = rtb_IntegralGain_b;
    }

    // DataTypeConversion: '<S29>/DataTypeConv2' incorporates:
    //   Signum: '<S29>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_IntegralGain_cm, (real_T)256.0F);

    // DataTypeConversion: '<S29>/DataTypeConv1'
    if (rtb_Gain1 < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_Gain1;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S29>/DataTypeConv1'

    // Switch: '<S27>/Switch' incorporates:
    //   Constant: '<S27>/Constant'
    //   DataTypeConversion: '<S29>/DataTypeConv2'
    //   Logic: '<S29>/AND'
    //   RelationalOperator: '<S29>/Equal'

    if (rtb_NotEqual_a && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_IntegralGain_b = Ctrl_P.Constant_Value_b;
    }

    // End of Switch: '<S27>/Switch'

    // Update for DiscreteIntegrator: '<S27>/Integrator'
    Ctrl_DW.Integrator_DSTATE_j += Ctrl_P.Integrator_gainval_d *
      rtb_IntegralGain_b;

    // Update for DiscreteIntegrator: '<S27>/Filter'
    Ctrl_DW.Filter_DSTATE_n += Ctrl_P.Filter_gainval_l * rtb_FilterCoefficient_j;

    // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
    Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j = 0U;

    // DeadZone: '<S19>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End) {
      rtb_IntegralGain_b = rtb_Rudder - Ctrl_P.DeadZone_End;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start) {
      rtb_IntegralGain_b = 0.0F;
    } else {
      rtb_IntegralGain_b = rtb_Rudder - Ctrl_P.DeadZone_Start;
    }

    // End of DeadZone: '<S19>/Dead Zone'

    // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
    //   Gain: '<S19>/Scale roll2'

    Ctrl_DW.DiscreteTimeIntegrator_DSTATE_f += Ctrl_P.Scaleroll2_Gain *
      rtb_IntegralGain_b * Ctrl_P.DiscreteTimeIntegrator_gainval;

    // Signum: '<S44>/SignPreIntegrator'
    if (rtb_IntegralGain_c < 0.0F) {
      rtb_IntegralGain_i = -1.0F;
    } else if (rtb_IntegralGain_c > 0.0F) {
      rtb_IntegralGain_i = 1.0F;
    } else {
      rtb_IntegralGain_i = rtb_IntegralGain_c;
    }

    // DataTypeConversion: '<S44>/DataTypeConv2' incorporates:
    //   Signum: '<S44>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_IntegralGain_i, (real_T)256.0F);

    // DataTypeConversion: '<S44>/DataTypeConv1'
    if (rtb_SignDeltaU_f < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_SignDeltaU_f;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S44>/DataTypeConv1'

    // Switch: '<S41>/Switch' incorporates:
    //   Constant: '<S41>/Constant'
    //   DataTypeConversion: '<S44>/DataTypeConv2'
    //   Logic: '<S44>/AND'
    //   RelationalOperator: '<S44>/Equal'

    if (rtb_NotEqual_d && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_IntegralGain_c = Ctrl_P.Constant_Value_d;
    }

    // End of Switch: '<S41>/Switch'

    // Update for DiscreteIntegrator: '<S41>/Integrator'
    Ctrl_DW.Integrator_DSTATE_di += Ctrl_P.Integrator_gainval_dg *
      rtb_IntegralGain_c;
  } else {
    if (Ctrl_DW.AutoCtrl_MODE) {
      Ctrl_DW.AutoCtrl_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S1>/AutoCtrl'

  // Outputs for Enabled SubSystem: '<S1>/ManualCtrl' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (Ctrl_B.ManualMode) {
    // Gain: '<S6>/Gain'
    rtb_IntegralGain_ah = Ctrl_P.Gain_Gain_ae * rtb_Thr;

    // Gain: '<S6>/Gain1'
    rtb_ZeroGain_p2 = Ctrl_P.Gain1_Gain_e * rtb_Aileron;

    // Gain: '<S6>/Gain2'
    rtb_SignDeltaU_on = Ctrl_P.Gain2_Gain * rtb_Elevator;

    // Gain: '<S6>/Gain3'
    rtb_IntegralGain_c = Ctrl_P.Gain3_Gain * rtb_Rudder;

    // Sum: '<S45>/Add1'
    rtb_Gain1 = ((rtb_IntegralGain_ah - rtb_ZeroGain_p2) + rtb_SignDeltaU_on) +
      rtb_IntegralGain_c;

    // Sum: '<S45>/Add2'
    rtb_IntegralGain_cm = ((rtb_IntegralGain_ah - rtb_ZeroGain_p2) -
      rtb_SignDeltaU_on) - rtb_IntegralGain_c;

    // Sum: '<S45>/Add3'
    rtb_SignDeltaU_je = ((rtb_IntegralGain_ah + rtb_ZeroGain_p2) +
                         rtb_SignDeltaU_on) - rtb_IntegralGain_c;

    // Sum: '<S45>/Add4'
    rtb_IntegralGain_ah = ((rtb_IntegralGain_ah + rtb_ZeroGain_p2) -
      rtb_SignDeltaU_on) + rtb_IntegralGain_c;

    // Saturate: '<S46>/Limit3'
    if (rtb_SignDeltaU_je > Ctrl_P.Limit3_UpperSat_l) {
      rtb_SignDeltaU_je = Ctrl_P.Limit3_UpperSat_l;
    } else {
      if (rtb_SignDeltaU_je < Ctrl_P.Limit3_LowerSat_g) {
        rtb_SignDeltaU_je = Ctrl_P.Limit3_LowerSat_g;
      }
    }

    // Sum: '<S46>/Subtract' incorporates:
    //   Constant: '<S46>/Constant'
    //   Gain: '<S46>/Gain'
    //   Saturate: '<S46>/Limit3'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_m * rtb_SignDeltaU_je +
      Ctrl_P.Constant_Value_c;

    // Saturate: '<S47>/Limit3'
    if (rtb_Gain1 > Ctrl_P.Limit3_UpperSat_b) {
      rtb_Gain1 = Ctrl_P.Limit3_UpperSat_b;
    } else {
      if (rtb_Gain1 < Ctrl_P.Limit3_LowerSat_k) {
        rtb_Gain1 = Ctrl_P.Limit3_LowerSat_k;
      }
    }

    // Sum: '<S47>/Subtract' incorporates:
    //   Constant: '<S47>/Constant'
    //   Gain: '<S47>/Gain'
    //   Saturate: '<S47>/Limit3'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_c * rtb_Gain1 + Ctrl_P.Constant_Value_i;

    // Saturate: '<S48>/Limit3'
    if (rtb_IntegralGain_cm > Ctrl_P.Limit3_UpperSat_o) {
      rtb_IntegralGain_cm = Ctrl_P.Limit3_UpperSat_o;
    } else {
      if (rtb_IntegralGain_cm < Ctrl_P.Limit3_LowerSat_d) {
        rtb_IntegralGain_cm = Ctrl_P.Limit3_LowerSat_d;
      }
    }

    // Sum: '<S48>/Subtract' incorporates:
    //   Constant: '<S48>/Constant'
    //   Gain: '<S48>/Gain'
    //   Saturate: '<S48>/Limit3'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_e * rtb_IntegralGain_cm +
      Ctrl_P.Constant_Value_o;

    // Saturate: '<S49>/Limit3'
    if (rtb_IntegralGain_ah > Ctrl_P.Limit3_UpperSat_c) {
      rtb_IntegralGain_ah = Ctrl_P.Limit3_UpperSat_c;
    } else {
      if (rtb_IntegralGain_ah < Ctrl_P.Limit3_LowerSat_f) {
        rtb_IntegralGain_ah = Ctrl_P.Limit3_LowerSat_f;
      }
    }

    // Sum: '<S49>/Subtract' incorporates:
    //   Constant: '<S49>/Constant'
    //   Gain: '<S49>/Gain'
    //   Saturate: '<S49>/Limit3'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_bq * rtb_IntegralGain_ah +
      Ctrl_P.Constant_Value_ew;
  }

  // End of Outputs for SubSystem: '<S1>/ManualCtrl'

  // Outputs for Enabled SubSystem: '<S1>/Off' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (Ctrl_B.Off) {
    // Constant: '<S7>/Constant1'
    Ctrl_B.PWM2 = Ctrl_P.Constant1_Value;

    // Constant: '<S7>/Constant2'
    Ctrl_B.PWM1 = Ctrl_P.Constant2_Value;

    // Constant: '<S7>/Constant3'
    Ctrl_B.PWM3 = Ctrl_P.Constant3_Value;

    // Constant: '<S7>/Constant4'
    Ctrl_B.PWM4 = Ctrl_P.Constant4_Value;
  }

  // End of Outputs for SubSystem: '<S1>/Off'

  // Outputs for Enabled SubSystem: '<S1>/RateCtrl' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (Ctrl_B.RateMode) {
    if (!Ctrl_DW.RateCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S60>/Integrator'
      Ctrl_DW.Integrator_DSTATE_fa = Ctrl_P.Integrator_IC_e;

      // InitializeConditions for DiscreteIntegrator: '<S60>/Filter'
      Ctrl_DW.Filter_DSTATE_p = Ctrl_P.Filter_IC_f;

      // InitializeConditions for DiscreteIntegrator: '<S58>/Integrator'
      Ctrl_DW.Integrator_DSTATE_g = Ctrl_P.Integrator_IC_j;

      // InitializeConditions for DiscreteIntegrator: '<S58>/Filter'
      Ctrl_DW.Filter_DSTATE_h = Ctrl_P.Filter_IC_c;

      // InitializeConditions for DiscreteIntegrator: '<S62>/Integrator'
      Ctrl_DW.Integrator_DSTATE_p = Ctrl_P.Integrator_IC_a;
      Ctrl_DW.RateCtrl_MODE = true;
    }

    // Gain: '<S8>/Gain'
    rtb_IntegralGain_i = Ctrl_P.Gain_Gain_cu * rtb_Thr;

    // Sum: '<S52>/Sum' incorporates:
    //   Gain: '<S52>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_ah = RollPitchRateMax * rtb_Aileron - Ctrl_U.dRPY[0];

    // Gain: '<S60>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S60>/Filter'
    //   Gain: '<S60>/Derivative Gain'
    //   Sum: '<S60>/SumD'

    rtb_ZeroGain_p2 = (RollPitchRateKd * rtb_IntegralGain_ah -
                       Ctrl_DW.Filter_DSTATE_p) *
      Ctrl_P.DiscretePIDController_N_hm;

    // Sum: '<S60>/Sum' incorporates:
    //   DiscreteIntegrator: '<S60>/Integrator'
    //   Gain: '<S60>/Proportional Gain'

    rtb_SignDeltaU_on = (RollPitchRateKp * rtb_IntegralGain_ah +
                         Ctrl_DW.Integrator_DSTATE_fa) + rtb_ZeroGain_p2;

    // Saturate: '<S60>/Saturate'
    if (rtb_SignDeltaU_on > Ctrl_P.DiscretePIDController_UpperSa_h) {
      rtb_FilterCoefficient_i = Ctrl_P.DiscretePIDController_UpperSa_h;
    } else if (rtb_SignDeltaU_on < Ctrl_P.DiscretePIDController_LowerSa_k) {
      rtb_FilterCoefficient_i = Ctrl_P.DiscretePIDController_LowerSa_k;
    } else {
      rtb_FilterCoefficient_i = rtb_SignDeltaU_on;
    }

    // End of Saturate: '<S60>/Saturate'

    // Sum: '<S51>/Sum' incorporates:
    //   Gain: '<S51>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_c = RollPitchRateMax * rtb_Elevator - Ctrl_U.dRPY[1];

    // Gain: '<S58>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S58>/Filter'
    //   Gain: '<S58>/Derivative Gain'
    //   Sum: '<S58>/SumD'

    rtb_Gain1 = (RollPitchRateKd * rtb_IntegralGain_c - Ctrl_DW.Filter_DSTATE_h)
      * Ctrl_P.DiscretePIDController_N_p;

    // Sum: '<S58>/Sum' incorporates:
    //   DiscreteIntegrator: '<S58>/Integrator'
    //   Gain: '<S58>/Proportional Gain'

    rtb_IntegralGain_cm = (RollPitchRateKp * rtb_IntegralGain_c +
      Ctrl_DW.Integrator_DSTATE_g) + rtb_Gain1;

    // Saturate: '<S58>/Saturate'
    if (rtb_IntegralGain_cm > Ctrl_P.DiscretePIDController_UpperSa_n) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController_UpperSa_n;
    } else if (rtb_IntegralGain_cm < Ctrl_P.DiscretePIDController_LowerS_io) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController_LowerS_io;
    } else {
      rtb_SignDeltaU_h = rtb_IntegralGain_cm;
    }

    // End of Saturate: '<S58>/Saturate'

    // DeadZone: '<S53>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End_o) {
      rtb_IntegralGain_b = rtb_Rudder - Ctrl_P.DeadZone_End_o;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start_c) {
      rtb_IntegralGain_b = 0.0F;
    } else {
      rtb_IntegralGain_b = rtb_Rudder - Ctrl_P.DeadZone_Start_c;
    }

    // End of DeadZone: '<S53>/Dead Zone'

    // Sum: '<S53>/Sum' incorporates:
    //   Gain: '<S53>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_SignDeltaU_je = YawRateMax * rtb_IntegralGain_b - Ctrl_U.dRPY[2];

    // Sum: '<S62>/Sum' incorporates:
    //   DiscreteIntegrator: '<S62>/Integrator'
    //   Gain: '<S62>/Proportional Gain'

    rtb_IntegralGain_b = YawRateKp * rtb_SignDeltaU_je +
      Ctrl_DW.Integrator_DSTATE_p;

    // Saturate: '<S62>/Saturate'
    if (rtb_IntegralGain_b > Ctrl_P.DiscretePIDController_UpperSa_b) {
      rtb_FilterCoefficient_j = Ctrl_P.DiscretePIDController_UpperSa_b;
    } else if (rtb_IntegralGain_b < Ctrl_P.DiscretePIDController_LowerSa_a) {
      rtb_FilterCoefficient_j = Ctrl_P.DiscretePIDController_LowerSa_a;
    } else {
      rtb_FilterCoefficient_j = rtb_IntegralGain_b;
    }

    // End of Saturate: '<S62>/Saturate'

    // Sum: '<S50>/Add1'
    rtb_SignDeltaU_f = ((rtb_IntegralGain_i - rtb_FilterCoefficient_i) +
                        rtb_SignDeltaU_h) + rtb_FilterCoefficient_j;

    // Sum: '<S50>/Add2'
    rtb_Add4_n = ((rtb_IntegralGain_i - rtb_FilterCoefficient_i) -
                  rtb_SignDeltaU_h) - rtb_FilterCoefficient_j;

    // Sum: '<S50>/Add3'
    rtb_Saturate_l = ((rtb_IntegralGain_i + rtb_FilterCoefficient_i) +
                      rtb_SignDeltaU_h) - rtb_FilterCoefficient_j;

    // Sum: '<S50>/Add4'
    rtb_IntegralGain_i = ((rtb_IntegralGain_i + rtb_FilterCoefficient_i) -
                          rtb_SignDeltaU_h) + rtb_FilterCoefficient_j;

    // Saturate: '<S54>/Limit3'
    if (rtb_Saturate_l > Ctrl_P.Limit3_UpperSat_d) {
      rtb_Saturate_l = Ctrl_P.Limit3_UpperSat_d;
    } else {
      if (rtb_Saturate_l < Ctrl_P.Limit3_LowerSat_ku) {
        rtb_Saturate_l = Ctrl_P.Limit3_LowerSat_ku;
      }
    }

    // Sum: '<S54>/Subtract' incorporates:
    //   Constant: '<S54>/Constant'
    //   Gain: '<S54>/Gain'
    //   Saturate: '<S54>/Limit3'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_h * rtb_Saturate_l + Ctrl_P.Constant_Value_g;

    // Saturate: '<S55>/Limit3'
    if (rtb_SignDeltaU_f > Ctrl_P.Limit3_UpperSat_a1) {
      rtb_SignDeltaU_f = Ctrl_P.Limit3_UpperSat_a1;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.Limit3_LowerSat_e) {
        rtb_SignDeltaU_f = Ctrl_P.Limit3_LowerSat_e;
      }
    }

    // Sum: '<S55>/Subtract' incorporates:
    //   Constant: '<S55>/Constant'
    //   Gain: '<S55>/Gain'
    //   Saturate: '<S55>/Limit3'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_ce * rtb_SignDeltaU_f +
      Ctrl_P.Constant_Value_ev;

    // Saturate: '<S56>/Limit3'
    if (rtb_Add4_n > Ctrl_P.Limit3_UpperSat_g) {
      rtb_Add4_n = Ctrl_P.Limit3_UpperSat_g;
    } else {
      if (rtb_Add4_n < Ctrl_P.Limit3_LowerSat_j) {
        rtb_Add4_n = Ctrl_P.Limit3_LowerSat_j;
      }
    }

    // Sum: '<S56>/Subtract' incorporates:
    //   Constant: '<S56>/Constant'
    //   Gain: '<S56>/Gain'
    //   Saturate: '<S56>/Limit3'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_cc * rtb_Add4_n + Ctrl_P.Constant_Value_k;

    // Saturate: '<S57>/Limit3'
    if (rtb_IntegralGain_i > Ctrl_P.Limit3_UpperSat_j) {
      rtb_IntegralGain_i = Ctrl_P.Limit3_UpperSat_j;
    } else {
      if (rtb_IntegralGain_i < Ctrl_P.Limit3_LowerSat_o) {
        rtb_IntegralGain_i = Ctrl_P.Limit3_LowerSat_o;
      }
    }

    // Sum: '<S57>/Subtract' incorporates:
    //   Constant: '<S57>/Constant'
    //   Gain: '<S57>/Gain'
    //   Saturate: '<S57>/Limit3'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_hp * rtb_IntegralGain_i +
      Ctrl_P.Constant_Value_n;

    // Gain: '<S59>/ZeroGain'
    rtb_IntegralGain_i = Ctrl_P.ZeroGain_Gain_e0 * rtb_IntegralGain_cm;

    // DeadZone: '<S59>/DeadZone'
    if (rtb_IntegralGain_cm > Ctrl_P.DiscretePIDController_UpperSa_n) {
      rtb_IntegralGain_cm -= Ctrl_P.DiscretePIDController_UpperSa_n;
    } else if (rtb_IntegralGain_cm >= Ctrl_P.DiscretePIDController_LowerS_io) {
      rtb_IntegralGain_cm = 0.0F;
    } else {
      rtb_IntegralGain_cm -= Ctrl_P.DiscretePIDController_LowerS_io;
    }

    // End of DeadZone: '<S59>/DeadZone'

    // RelationalOperator: '<S59>/NotEqual'
    rtb_NotEqual_a = (rtb_IntegralGain_i != rtb_IntegralGain_cm);

    // Signum: '<S59>/SignDeltaU'
    if (rtb_IntegralGain_cm < 0.0F) {
      rtb_IntegralGain_cm = -1.0F;
    } else {
      if (rtb_IntegralGain_cm > 0.0F) {
        rtb_IntegralGain_cm = 1.0F;
      }
    }

    // End of Signum: '<S59>/SignDeltaU'

    // Gain: '<S58>/Integral Gain'
    rtb_IntegralGain_c *= RollPitchRateKi;

    // Gain: '<S61>/ZeroGain'
    rtb_IntegralGain_i = Ctrl_P.ZeroGain_Gain_c * rtb_SignDeltaU_on;

    // DeadZone: '<S61>/DeadZone'
    if (rtb_SignDeltaU_on > Ctrl_P.DiscretePIDController_UpperSa_h) {
      rtb_SignDeltaU_on -= Ctrl_P.DiscretePIDController_UpperSa_h;
    } else if (rtb_SignDeltaU_on >= Ctrl_P.DiscretePIDController_LowerSa_k) {
      rtb_SignDeltaU_on = 0.0F;
    } else {
      rtb_SignDeltaU_on -= Ctrl_P.DiscretePIDController_LowerSa_k;
    }

    // End of DeadZone: '<S61>/DeadZone'

    // RelationalOperator: '<S61>/NotEqual'
    rtb_NotEqual_ac = (rtb_IntegralGain_i != rtb_SignDeltaU_on);

    // Signum: '<S61>/SignDeltaU'
    if (rtb_SignDeltaU_on < 0.0F) {
      rtb_SignDeltaU_on = -1.0F;
    } else {
      if (rtb_SignDeltaU_on > 0.0F) {
        rtb_SignDeltaU_on = 1.0F;
      }
    }

    // End of Signum: '<S61>/SignDeltaU'

    // Gain: '<S60>/Integral Gain'
    rtb_IntegralGain_ah *= RollPitchRateKi;

    // Gain: '<S63>/ZeroGain'
    rtb_IntegralGain_i = Ctrl_P.ZeroGain_Gain_ez * rtb_IntegralGain_b;

    // DeadZone: '<S63>/DeadZone'
    if (rtb_IntegralGain_b > Ctrl_P.DiscretePIDController_UpperSa_b) {
      rtb_IntegralGain_b -= Ctrl_P.DiscretePIDController_UpperSa_b;
    } else if (rtb_IntegralGain_b >= Ctrl_P.DiscretePIDController_LowerSa_a) {
      rtb_IntegralGain_b = 0.0F;
    } else {
      rtb_IntegralGain_b -= Ctrl_P.DiscretePIDController_LowerSa_a;
    }

    // End of DeadZone: '<S63>/DeadZone'

    // RelationalOperator: '<S63>/NotEqual'
    rtb_NotEqual_dy = (rtb_IntegralGain_i != rtb_IntegralGain_b);

    // Signum: '<S63>/SignDeltaU'
    if (rtb_IntegralGain_b < 0.0F) {
      rtb_IntegralGain_b = -1.0F;
    } else {
      if (rtb_IntegralGain_b > 0.0F) {
        rtb_IntegralGain_b = 1.0F;
      }
    }

    // End of Signum: '<S63>/SignDeltaU'

    // Gain: '<S62>/Integral Gain'
    rtb_SignDeltaU_je *= YawRateKi;

    // Signum: '<S61>/SignPreIntegrator'
    if (rtb_IntegralGain_ah < 0.0F) {
      rtb_Saturate_l = -1.0F;
    } else if (rtb_IntegralGain_ah > 0.0F) {
      rtb_Saturate_l = 1.0F;
    } else {
      rtb_Saturate_l = rtb_IntegralGain_ah;
    }

    // DataTypeConversion: '<S61>/DataTypeConv2' incorporates:
    //   Signum: '<S61>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Saturate_l, (real_T)256.0F);

    // DataTypeConversion: '<S61>/DataTypeConv1'
    if (rtb_SignDeltaU_on < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_SignDeltaU_on;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S61>/DataTypeConv1'

    // Switch: '<S60>/Switch' incorporates:
    //   Constant: '<S60>/Constant'
    //   DataTypeConversion: '<S61>/DataTypeConv2'
    //   Logic: '<S61>/AND'
    //   RelationalOperator: '<S61>/Equal'

    if (rtb_NotEqual_ac && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_IntegralGain_ah = Ctrl_P.Constant_Value_jl;
    }

    // End of Switch: '<S60>/Switch'

    // Update for DiscreteIntegrator: '<S60>/Integrator'
    Ctrl_DW.Integrator_DSTATE_fa += Ctrl_P.Integrator_gainval_a *
      rtb_IntegralGain_ah;

    // Update for DiscreteIntegrator: '<S60>/Filter'
    Ctrl_DW.Filter_DSTATE_p += Ctrl_P.Filter_gainval_f * rtb_ZeroGain_p2;

    // Signum: '<S59>/SignPreIntegrator'
    if (rtb_IntegralGain_c < 0.0F) {
      rtb_IntegralGain_i = -1.0F;
    } else if (rtb_IntegralGain_c > 0.0F) {
      rtb_IntegralGain_i = 1.0F;
    } else {
      rtb_IntegralGain_i = rtb_IntegralGain_c;
    }

    // DataTypeConversion: '<S59>/DataTypeConv2' incorporates:
    //   Signum: '<S59>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_IntegralGain_i, (real_T)256.0F);

    // DataTypeConversion: '<S59>/DataTypeConv1'
    if (rtb_IntegralGain_cm < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_IntegralGain_cm;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S59>/DataTypeConv1'

    // Switch: '<S58>/Switch' incorporates:
    //   Constant: '<S58>/Constant'
    //   DataTypeConversion: '<S59>/DataTypeConv2'
    //   Logic: '<S59>/AND'
    //   RelationalOperator: '<S59>/Equal'

    if (rtb_NotEqual_a && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_IntegralGain_c = Ctrl_P.Constant_Value_aw;
    }

    // End of Switch: '<S58>/Switch'

    // Update for DiscreteIntegrator: '<S58>/Integrator'
    Ctrl_DW.Integrator_DSTATE_g += Ctrl_P.Integrator_gainval_h *
      rtb_IntegralGain_c;

    // Update for DiscreteIntegrator: '<S58>/Filter'
    Ctrl_DW.Filter_DSTATE_h += Ctrl_P.Filter_gainval_h * rtb_Gain1;

    // Signum: '<S63>/SignPreIntegrator'
    if (rtb_SignDeltaU_je < 0.0F) {
      rtb_Gain1 = -1.0F;
    } else if (rtb_SignDeltaU_je > 0.0F) {
      rtb_Gain1 = 1.0F;
    } else {
      rtb_Gain1 = rtb_SignDeltaU_je;
    }

    // DataTypeConversion: '<S63>/DataTypeConv2' incorporates:
    //   Signum: '<S63>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Gain1, (real_T)256.0F);

    // DataTypeConversion: '<S63>/DataTypeConv1'
    if (rtb_IntegralGain_b < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_IntegralGain_b;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S63>/DataTypeConv1'

    // Switch: '<S62>/Switch' incorporates:
    //   Constant: '<S62>/Constant'
    //   DataTypeConversion: '<S63>/DataTypeConv2'
    //   Logic: '<S63>/AND'
    //   RelationalOperator: '<S63>/Equal'

    if (rtb_NotEqual_dy && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_SignDeltaU_je = Ctrl_P.Constant_Value_nm;
    }

    // End of Switch: '<S62>/Switch'

    // Update for DiscreteIntegrator: '<S62>/Integrator'
    Ctrl_DW.Integrator_DSTATE_p += Ctrl_P.Integrator_gainval_c *
      rtb_SignDeltaU_je;
  } else {
    if (Ctrl_DW.RateCtrl_MODE) {
      Ctrl_DW.RateCtrl_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S1>/RateCtrl'

  // Outputs for Enabled SubSystem: '<S1>/RollPitchCtrl' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (Ctrl_B.RollPitchMode) {
    if (!Ctrl_DW.RollPitchCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S75>/Integrator'
      Ctrl_DW.Integrator_DSTATE_i = Ctrl_P.Integrator_IC_g;

      // InitializeConditions for DiscreteIntegrator: '<S75>/Filter'
      Ctrl_DW.Filter_DSTATE_o = Ctrl_P.Filter_IC_b;

      // InitializeConditions for DiscreteIntegrator: '<S72>/Integrator'
      Ctrl_DW.Integrator_DSTATE_o1 = Ctrl_P.Integrator_IC_p;

      // InitializeConditions for DiscreteIntegrator: '<S72>/Filter'
      Ctrl_DW.Filter_DSTATE_d = Ctrl_P.Filter_IC_i;

      // InitializeConditions for DiscreteIntegrator: '<S78>/Integrator'
      Ctrl_DW.Integrator_DSTATE_b = Ctrl_P.Integrator_IC_lt;
      Ctrl_DW.RollPitchCtrl_MODE = true;
    }

    // Gain: '<S9>/Gain'
    rtb_IntegralGain_i = Ctrl_P.Gain_Gain_mu * rtb_Thr;

    // Gain: '<S76>/Proportional Gain' incorporates:
    //   Gain: '<S66>/Scale roll2'
    //   Inport: '<Root>/RPY'
    //   Sum: '<S66>/Sum3'

    rtb_SignDeltaU_f = (RollPitchMax * rtb_Aileron - Ctrl_U.RPY[0]) *
      RollPitchKp;

    // Saturate: '<S76>/Saturate'
    if (rtb_SignDeltaU_f > RollPitchRateMax) {
      rtb_SignDeltaU_f = RollPitchRateMax;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController1_LowerS_d) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController1_LowerS_d;
      }
    }

    // Sum: '<S66>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'
    //   Saturate: '<S76>/Saturate'

    rtb_IntegralGain_ah = rtb_SignDeltaU_f - Ctrl_U.dRPY[0];

    // Gain: '<S75>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S75>/Filter'
    //   Gain: '<S75>/Derivative Gain'
    //   Sum: '<S75>/SumD'

    rtb_ZeroGain_p2 = (RollPitchRateKd * rtb_IntegralGain_ah -
                       Ctrl_DW.Filter_DSTATE_o) *
      Ctrl_P.DiscretePIDController_N_i;

    // Sum: '<S75>/Sum' incorporates:
    //   DiscreteIntegrator: '<S75>/Integrator'
    //   Gain: '<S75>/Proportional Gain'

    rtb_SignDeltaU_on = (RollPitchRateKp * rtb_IntegralGain_ah +
                         Ctrl_DW.Integrator_DSTATE_i) + rtb_ZeroGain_p2;

    // Saturate: '<S75>/Saturate'
    if (rtb_SignDeltaU_on > Ctrl_P.DiscretePIDController_UpperSa_p) {
      rtb_FilterCoefficient_i = Ctrl_P.DiscretePIDController_UpperSa_p;
    } else if (rtb_SignDeltaU_on < Ctrl_P.DiscretePIDController_LowerSa_b) {
      rtb_FilterCoefficient_i = Ctrl_P.DiscretePIDController_LowerSa_b;
    } else {
      rtb_FilterCoefficient_i = rtb_SignDeltaU_on;
    }

    // End of Saturate: '<S75>/Saturate'

    // Gain: '<S73>/Proportional Gain' incorporates:
    //   Gain: '<S65>/Scale roll1'
    //   Inport: '<Root>/RPY'
    //   Sum: '<S65>/Sum3'

    rtb_SignDeltaU_f = (RollPitchMax * rtb_Elevator - Ctrl_U.RPY[1]) *
      RollPitchKp;

    // Saturate: '<S73>/Saturate'
    if (rtb_SignDeltaU_f > RollPitchRateMax) {
      rtb_SignDeltaU_f = RollPitchRateMax;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController1_Lower_de) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController1_Lower_de;
      }
    }

    // Sum: '<S65>/Sum1' incorporates:
    //   Inport: '<Root>/dRPY'
    //   Saturate: '<S73>/Saturate'

    rtb_IntegralGain_c = rtb_SignDeltaU_f - Ctrl_U.dRPY[1];

    // Gain: '<S72>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S72>/Filter'
    //   Gain: '<S72>/Derivative Gain'
    //   Sum: '<S72>/SumD'

    rtb_Gain1 = (RollPitchRateKd * rtb_IntegralGain_c - Ctrl_DW.Filter_DSTATE_d)
      * Ctrl_P.DiscretePIDController_N_hn;

    // Sum: '<S72>/Sum' incorporates:
    //   DiscreteIntegrator: '<S72>/Integrator'
    //   Gain: '<S72>/Proportional Gain'

    rtb_IntegralGain_cm = (RollPitchRateKp * rtb_IntegralGain_c +
      Ctrl_DW.Integrator_DSTATE_o1) + rtb_Gain1;

    // Saturate: '<S72>/Saturate'
    if (rtb_IntegralGain_cm > Ctrl_P.DiscretePIDController_UpperSa_i) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController_UpperSa_i;
    } else if (rtb_IntegralGain_cm < Ctrl_P.DiscretePIDController_LowerSa_p) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController_LowerSa_p;
    } else {
      rtb_SignDeltaU_h = rtb_IntegralGain_cm;
    }

    // End of Saturate: '<S72>/Saturate'

    // DeadZone: '<S67>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End_h) {
      rtb_IntegralGain_b = rtb_Rudder - Ctrl_P.DeadZone_End_h;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start_l) {
      rtb_IntegralGain_b = 0.0F;
    } else {
      rtb_IntegralGain_b = rtb_Rudder - Ctrl_P.DeadZone_Start_l;
    }

    // End of DeadZone: '<S67>/Dead Zone'

    // Sum: '<S67>/Sum' incorporates:
    //   Gain: '<S67>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_SignDeltaU_je = YawRateMax * rtb_IntegralGain_b - Ctrl_U.dRPY[2];

    // Sum: '<S78>/Sum' incorporates:
    //   DiscreteIntegrator: '<S78>/Integrator'
    //   Gain: '<S78>/Proportional Gain'

    rtb_IntegralGain_b = YawRateKp * rtb_SignDeltaU_je +
      Ctrl_DW.Integrator_DSTATE_b;

    // Saturate: '<S78>/Saturate'
    if (rtb_IntegralGain_b > Ctrl_P.DiscretePIDController_UpperSa_k) {
      rtb_FilterCoefficient_j = Ctrl_P.DiscretePIDController_UpperSa_k;
    } else if (rtb_IntegralGain_b < Ctrl_P.DiscretePIDController_LowerSa_f) {
      rtb_FilterCoefficient_j = Ctrl_P.DiscretePIDController_LowerSa_f;
    } else {
      rtb_FilterCoefficient_j = rtb_IntegralGain_b;
    }

    // End of Saturate: '<S78>/Saturate'

    // Sum: '<S64>/Add1'
    rtb_SignDeltaU_f = ((rtb_IntegralGain_i - rtb_FilterCoefficient_i) +
                        rtb_SignDeltaU_h) + rtb_FilterCoefficient_j;

    // Sum: '<S64>/Add2'
    rtb_Add4_n = ((rtb_IntegralGain_i - rtb_FilterCoefficient_i) -
                  rtb_SignDeltaU_h) - rtb_FilterCoefficient_j;

    // Sum: '<S64>/Add3'
    rtb_Saturate_l = ((rtb_IntegralGain_i + rtb_FilterCoefficient_i) +
                      rtb_SignDeltaU_h) - rtb_FilterCoefficient_j;

    // Sum: '<S64>/Add4'
    rtb_IntegralGain_i = ((rtb_IntegralGain_i + rtb_FilterCoefficient_i) -
                          rtb_SignDeltaU_h) + rtb_FilterCoefficient_j;

    // Saturate: '<S68>/Limit3'
    if (rtb_Saturate_l > Ctrl_P.Limit3_UpperSat_b5) {
      rtb_Saturate_l = Ctrl_P.Limit3_UpperSat_b5;
    } else {
      if (rtb_Saturate_l < Ctrl_P.Limit3_LowerSat_jv) {
        rtb_Saturate_l = Ctrl_P.Limit3_LowerSat_jv;
      }
    }

    // Sum: '<S68>/Subtract' incorporates:
    //   Constant: '<S68>/Constant'
    //   Gain: '<S68>/Gain'
    //   Saturate: '<S68>/Limit3'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_o * rtb_Saturate_l +
      Ctrl_P.Constant_Value_p42;

    // Saturate: '<S69>/Limit3'
    if (rtb_SignDeltaU_f > Ctrl_P.Limit3_UpperSat_gu) {
      rtb_SignDeltaU_f = Ctrl_P.Limit3_UpperSat_gu;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.Limit3_LowerSat_dd) {
        rtb_SignDeltaU_f = Ctrl_P.Limit3_LowerSat_dd;
      }
    }

    // Sum: '<S69>/Subtract' incorporates:
    //   Constant: '<S69>/Constant'
    //   Gain: '<S69>/Gain'
    //   Saturate: '<S69>/Limit3'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_d * rtb_SignDeltaU_f +
      Ctrl_P.Constant_Value_co;

    // Saturate: '<S70>/Limit3'
    if (rtb_Add4_n > Ctrl_P.Limit3_UpperSat_kf) {
      rtb_Add4_n = Ctrl_P.Limit3_UpperSat_kf;
    } else {
      if (rtb_Add4_n < Ctrl_P.Limit3_LowerSat_du) {
        rtb_Add4_n = Ctrl_P.Limit3_LowerSat_du;
      }
    }

    // Sum: '<S70>/Subtract' incorporates:
    //   Constant: '<S70>/Constant'
    //   Gain: '<S70>/Gain'
    //   Saturate: '<S70>/Limit3'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_i * rtb_Add4_n + Ctrl_P.Constant_Value_oi;

    // Saturate: '<S71>/Limit3'
    if (rtb_IntegralGain_i > Ctrl_P.Limit3_UpperSat_n) {
      rtb_IntegralGain_i = Ctrl_P.Limit3_UpperSat_n;
    } else {
      if (rtb_IntegralGain_i < Ctrl_P.Limit3_LowerSat_b) {
        rtb_IntegralGain_i = Ctrl_P.Limit3_LowerSat_b;
      }
    }

    // Sum: '<S71>/Subtract' incorporates:
    //   Constant: '<S71>/Constant'
    //   Gain: '<S71>/Gain'
    //   Saturate: '<S71>/Limit3'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_m5 * rtb_IntegralGain_i +
      Ctrl_P.Constant_Value_awg;

    // Gain: '<S74>/ZeroGain'
    rtb_IntegralGain_i = Ctrl_P.ZeroGain_Gain_b * rtb_IntegralGain_cm;

    // DeadZone: '<S74>/DeadZone'
    if (rtb_IntegralGain_cm > Ctrl_P.DiscretePIDController_UpperSa_i) {
      rtb_IntegralGain_cm -= Ctrl_P.DiscretePIDController_UpperSa_i;
    } else if (rtb_IntegralGain_cm >= Ctrl_P.DiscretePIDController_LowerSa_p) {
      rtb_IntegralGain_cm = 0.0F;
    } else {
      rtb_IntegralGain_cm -= Ctrl_P.DiscretePIDController_LowerSa_p;
    }

    // End of DeadZone: '<S74>/DeadZone'

    // RelationalOperator: '<S74>/NotEqual'
    rtb_NotEqual_a = (rtb_IntegralGain_i != rtb_IntegralGain_cm);

    // Signum: '<S74>/SignDeltaU'
    if (rtb_IntegralGain_cm < 0.0F) {
      rtb_IntegralGain_cm = -1.0F;
    } else {
      if (rtb_IntegralGain_cm > 0.0F) {
        rtb_IntegralGain_cm = 1.0F;
      }
    }

    // End of Signum: '<S74>/SignDeltaU'

    // Gain: '<S72>/Integral Gain'
    rtb_IntegralGain_c *= RollPitchRateKi;

    // Gain: '<S77>/ZeroGain'
    rtb_IntegralGain_i = Ctrl_P.ZeroGain_Gain_o * rtb_SignDeltaU_on;

    // DeadZone: '<S77>/DeadZone'
    if (rtb_SignDeltaU_on > Ctrl_P.DiscretePIDController_UpperSa_p) {
      rtb_SignDeltaU_on -= Ctrl_P.DiscretePIDController_UpperSa_p;
    } else if (rtb_SignDeltaU_on >= Ctrl_P.DiscretePIDController_LowerSa_b) {
      rtb_SignDeltaU_on = 0.0F;
    } else {
      rtb_SignDeltaU_on -= Ctrl_P.DiscretePIDController_LowerSa_b;
    }

    // End of DeadZone: '<S77>/DeadZone'

    // RelationalOperator: '<S77>/NotEqual'
    rtb_NotEqual_ac = (rtb_IntegralGain_i != rtb_SignDeltaU_on);

    // Signum: '<S77>/SignDeltaU'
    if (rtb_SignDeltaU_on < 0.0F) {
      rtb_SignDeltaU_on = -1.0F;
    } else {
      if (rtb_SignDeltaU_on > 0.0F) {
        rtb_SignDeltaU_on = 1.0F;
      }
    }

    // End of Signum: '<S77>/SignDeltaU'

    // Gain: '<S75>/Integral Gain'
    rtb_IntegralGain_ah *= RollPitchRateKi;

    // Gain: '<S79>/ZeroGain'
    rtb_IntegralGain_i = Ctrl_P.ZeroGain_Gain_d * rtb_IntegralGain_b;

    // DeadZone: '<S79>/DeadZone'
    if (rtb_IntegralGain_b > Ctrl_P.DiscretePIDController_UpperSa_k) {
      rtb_IntegralGain_b -= Ctrl_P.DiscretePIDController_UpperSa_k;
    } else if (rtb_IntegralGain_b >= Ctrl_P.DiscretePIDController_LowerSa_f) {
      rtb_IntegralGain_b = 0.0F;
    } else {
      rtb_IntegralGain_b -= Ctrl_P.DiscretePIDController_LowerSa_f;
    }

    // End of DeadZone: '<S79>/DeadZone'

    // RelationalOperator: '<S79>/NotEqual'
    rtb_NotEqual_dy = (rtb_IntegralGain_i != rtb_IntegralGain_b);

    // Signum: '<S79>/SignDeltaU'
    if (rtb_IntegralGain_b < 0.0F) {
      rtb_IntegralGain_b = -1.0F;
    } else {
      if (rtb_IntegralGain_b > 0.0F) {
        rtb_IntegralGain_b = 1.0F;
      }
    }

    // End of Signum: '<S79>/SignDeltaU'

    // Gain: '<S78>/Integral Gain'
    rtb_SignDeltaU_je *= YawRateKi;

    // Signum: '<S77>/SignPreIntegrator'
    if (rtb_IntegralGain_ah < 0.0F) {
      rtb_Saturate_l = -1.0F;
    } else if (rtb_IntegralGain_ah > 0.0F) {
      rtb_Saturate_l = 1.0F;
    } else {
      rtb_Saturate_l = rtb_IntegralGain_ah;
    }

    // DataTypeConversion: '<S77>/DataTypeConv2' incorporates:
    //   Signum: '<S77>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Saturate_l, (real_T)256.0F);

    // DataTypeConversion: '<S77>/DataTypeConv1'
    if (rtb_SignDeltaU_on < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_SignDeltaU_on;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S77>/DataTypeConv1'

    // Switch: '<S75>/Switch' incorporates:
    //   Constant: '<S75>/Constant'
    //   DataTypeConversion: '<S77>/DataTypeConv2'
    //   Logic: '<S77>/AND'
    //   RelationalOperator: '<S77>/Equal'

    if (rtb_NotEqual_ac && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_IntegralGain_ah = Ctrl_P.Constant_Value_is;
    }

    // End of Switch: '<S75>/Switch'

    // Update for DiscreteIntegrator: '<S75>/Integrator'
    Ctrl_DW.Integrator_DSTATE_i += Ctrl_P.Integrator_gainval_l *
      rtb_IntegralGain_ah;

    // Update for DiscreteIntegrator: '<S75>/Filter'
    Ctrl_DW.Filter_DSTATE_o += Ctrl_P.Filter_gainval_i * rtb_ZeroGain_p2;

    // Signum: '<S74>/SignPreIntegrator'
    if (rtb_IntegralGain_c < 0.0F) {
      rtb_IntegralGain_i = -1.0F;
    } else if (rtb_IntegralGain_c > 0.0F) {
      rtb_IntegralGain_i = 1.0F;
    } else {
      rtb_IntegralGain_i = rtb_IntegralGain_c;
    }

    // DataTypeConversion: '<S74>/DataTypeConv2' incorporates:
    //   Signum: '<S74>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_IntegralGain_i, (real_T)256.0F);

    // DataTypeConversion: '<S74>/DataTypeConv1'
    if (rtb_IntegralGain_cm < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_IntegralGain_cm;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S74>/DataTypeConv1'

    // Switch: '<S72>/Switch' incorporates:
    //   Constant: '<S72>/Constant'
    //   DataTypeConversion: '<S74>/DataTypeConv2'
    //   Logic: '<S74>/AND'
    //   RelationalOperator: '<S74>/Equal'

    if (rtb_NotEqual_a && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_IntegralGain_c = Ctrl_P.Constant_Value_cx;
    }

    // End of Switch: '<S72>/Switch'

    // Update for DiscreteIntegrator: '<S72>/Integrator'
    Ctrl_DW.Integrator_DSTATE_o1 += Ctrl_P.Integrator_gainval_dk *
      rtb_IntegralGain_c;

    // Update for DiscreteIntegrator: '<S72>/Filter'
    Ctrl_DW.Filter_DSTATE_d += Ctrl_P.Filter_gainval_o * rtb_Gain1;

    // Signum: '<S79>/SignPreIntegrator'
    if (rtb_SignDeltaU_je < 0.0F) {
      rtb_Gain1 = -1.0F;
    } else if (rtb_SignDeltaU_je > 0.0F) {
      rtb_Gain1 = 1.0F;
    } else {
      rtb_Gain1 = rtb_SignDeltaU_je;
    }

    // DataTypeConversion: '<S79>/DataTypeConv2' incorporates:
    //   Signum: '<S79>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Gain1, (real_T)256.0F);

    // DataTypeConversion: '<S79>/DataTypeConv1'
    if (rtb_IntegralGain_b < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_IntegralGain_b;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S79>/DataTypeConv1'

    // Switch: '<S78>/Switch' incorporates:
    //   Constant: '<S78>/Constant'
    //   DataTypeConversion: '<S79>/DataTypeConv2'
    //   Logic: '<S79>/AND'
    //   RelationalOperator: '<S79>/Equal'

    if (rtb_NotEqual_dy && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_SignDeltaU_je = Ctrl_P.Constant_Value_kd;
    }

    // End of Switch: '<S78>/Switch'

    // Update for DiscreteIntegrator: '<S78>/Integrator'
    Ctrl_DW.Integrator_DSTATE_b += Ctrl_P.Integrator_gainval_m *
      rtb_SignDeltaU_je;
  } else {
    if (Ctrl_DW.RollPitchCtrl_MODE) {
      Ctrl_DW.RollPitchCtrl_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S1>/RollPitchCtrl'

  // Outputs for Enabled SubSystem: '<S1>/VelocityCtrl' incorporates:
  //   EnablePort: '<S10>/Enable'

  if (Ctrl_B.VelocityMode) {
    if (!Ctrl_DW.VelocityCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S86>/Integrator'
      Ctrl_DW.Integrator_DSTATE = Ctrl_P.Integrator_IC_p4;

      // InitializeConditions for DiscreteIntegrator: '<S100>/Integrator'
      Ctrl_DW.Integrator_DSTATE_d = Ctrl_P.Integrator_IC_g2;

      // InitializeConditions for DiscreteIntegrator: '<S99>/Integrator'
      Ctrl_DW.Integrator_DSTATE_o = Ctrl_P.Integrator_IC_et;

      // InitializeConditions for DiscreteIntegrator: '<S95>/Integrator'
      Ctrl_DW.Integrator_DSTATE_m = Ctrl_P.Integrator_IC_c;

      // InitializeConditions for DiscreteIntegrator: '<S95>/Filter'
      Ctrl_DW.Filter_DSTATE = Ctrl_P.Filter_IC_e;

      // InitializeConditions for DiscreteIntegrator: '<S92>/Integrator'
      Ctrl_DW.Integrator_DSTATE_e = Ctrl_P.Integrator_IC_b;

      // InitializeConditions for DiscreteIntegrator: '<S92>/Filter'
      Ctrl_DW.Filter_DSTATE_c = Ctrl_P.Filter_IC_l;

      // InitializeConditions for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' 
      Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

      // InitializeConditions for DiscreteIntegrator: '<S104>/Integrator'
      Ctrl_DW.Integrator_DSTATE_f = Ctrl_P.Integrator_IC_g4;
      Ctrl_DW.VelocityCtrl_MODE = true;
    }

    // Bias: '<S80>/Bias'
    rtb_SignDeltaU_h = rtb_Thr + Ctrl_P.Bias_Bias;

    // DeadZone: '<S80>/Dead Zone'
    if (rtb_SignDeltaU_h > Ctrl_P.DeadZone_End_b) {
      rtb_SignDeltaU_h -= Ctrl_P.DeadZone_End_b;
    } else if (rtb_SignDeltaU_h >= Ctrl_P.DeadZone_Start_p) {
      rtb_SignDeltaU_h = 0.0F;
    } else {
      rtb_SignDeltaU_h -= Ctrl_P.DeadZone_Start_p;
    }

    // End of DeadZone: '<S80>/Dead Zone'

    // Gain: '<S80>/Scale Vel'
    Ctrl_B.VertVelRef = Ctrl_P.ScaleVel_Gain_a * rtb_SignDeltaU_h;

    // Saturate: '<S80>/Fix Faulty Baro'
    if (rtb_Gain > Ctrl_P.FixFaultyBaro_UpperSat_d) {
      rtb_Gain1 = Ctrl_P.FixFaultyBaro_UpperSat_d;
    } else if (rtb_Gain < Ctrl_P.FixFaultyBaro_LowerSat_o) {
      rtb_Gain1 = Ctrl_P.FixFaultyBaro_LowerSat_o;
    } else {
      rtb_Gain1 = rtb_Gain;
    }

    // Sum: '<S80>/Sum3' incorporates:
    //   Saturate: '<S80>/Fix Faulty Baro'

    rtb_SignDeltaU_h = Ctrl_B.VertVelRef - rtb_Gain1;

    // Sum: '<S86>/Sum' incorporates:
    //   DiscreteIntegrator: '<S86>/Integrator'
    //   Gain: '<S86>/Proportional Gain'

    rtb_FilterCoefficient_j = AltRateKp * rtb_SignDeltaU_h +
      Ctrl_DW.Integrator_DSTATE;

    // Saturate: '<S86>/Saturate'
    if (rtb_FilterCoefficient_j > Ctrl_P.DiscretePIDController1_UpperS_l) {
      rtb_Gain1 = Ctrl_P.DiscretePIDController1_UpperS_l;
    } else if (rtb_FilterCoefficient_j < Ctrl_P.DiscretePIDController1_LowerS_b)
    {
      rtb_Gain1 = Ctrl_P.DiscretePIDController1_LowerS_b;
    } else {
      rtb_Gain1 = rtb_FilterCoefficient_j;
    }

    // Bias: '<S80>/Bias1' incorporates:
    //   Saturate: '<S86>/Saturate'

    Ctrl_B.VertVelOut = rtb_Gain1 + AltRateBias;

    // Gain: '<S87>/ZeroGain'
    rtb_Thr = Ctrl_P.ZeroGain_Gain_f * rtb_FilterCoefficient_j;

    // DeadZone: '<S87>/DeadZone'
    if (rtb_FilterCoefficient_j > Ctrl_P.DiscretePIDController1_UpperS_l) {
      rtb_FilterCoefficient_j -= Ctrl_P.DiscretePIDController1_UpperS_l;
    } else if (rtb_FilterCoefficient_j >= Ctrl_P.DiscretePIDController1_LowerS_b)
    {
      rtb_FilterCoefficient_j = 0.0F;
    } else {
      rtb_FilterCoefficient_j -= Ctrl_P.DiscretePIDController1_LowerS_b;
    }

    // End of DeadZone: '<S87>/DeadZone'

    // RelationalOperator: '<S87>/NotEqual'
    rtb_NotEqual_a = (rtb_Thr != rtb_FilterCoefficient_j);

    // Signum: '<S87>/SignDeltaU'
    if (rtb_FilterCoefficient_j < 0.0F) {
      rtb_FilterCoefficient_j = -1.0F;
    } else {
      if (rtb_FilterCoefficient_j > 0.0F) {
        rtb_FilterCoefficient_j = 1.0F;
      }
    }

    // End of Signum: '<S87>/SignDeltaU'

    // Gain: '<S86>/Integral Gain'
    rtb_SignDeltaU_h *= AltRateKi;

    // Signum: '<S87>/SignPreIntegrator'
    if (rtb_SignDeltaU_h < 0.0F) {
      rtb_Gain1 = -1.0F;
    } else if (rtb_SignDeltaU_h > 0.0F) {
      rtb_Gain1 = 1.0F;
    } else {
      rtb_Gain1 = rtb_SignDeltaU_h;
    }

    // DataTypeConversion: '<S87>/DataTypeConv2' incorporates:
    //   Signum: '<S87>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Gain1, (real_T)256.0F);

    // DataTypeConversion: '<S87>/DataTypeConv1'
    if (rtb_FilterCoefficient_j < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_FilterCoefficient_j;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S87>/DataTypeConv1'

    // Switch: '<S86>/Switch' incorporates:
    //   Constant: '<S86>/Constant'
    //   DataTypeConversion: '<S87>/DataTypeConv2'
    //   Logic: '<S87>/AND'
    //   RelationalOperator: '<S87>/Equal'

    if (rtb_NotEqual_a && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_Thr = Ctrl_P.Constant_Value_n4;
    } else {
      rtb_Thr = rtb_SignDeltaU_h;
    }

    // End of Switch: '<S86>/Switch'

    // Saturate: '<S80>/Limit Output'
    if (Ctrl_B.VertVelOut > Ctrl_P.LimitOutput_UpperSat_h) {
      rtb_FilterCoefficient_j = Ctrl_P.LimitOutput_UpperSat_h;
    } else if (Ctrl_B.VertVelOut < Ctrl_P.LimitOutput_LowerSat_f) {
      rtb_FilterCoefficient_j = Ctrl_P.LimitOutput_LowerSat_f;
    } else {
      rtb_FilterCoefficient_j = Ctrl_B.VertVelOut;
    }

    // End of Saturate: '<S80>/Limit Output'

    // Gain: '<S10>/Gain2'
    rtb_SignDeltaU_h = Ctrl_P.Gain2_Gain_j * rtb_Elevator;

    // Gain: '<S98>/Gain1' incorporates:
    //   Inport: '<Root>/RPY'

    rtb_Elevator = Ctrl_P.Gain1_Gain_k * Ctrl_U.RPY[2];

    // Trigonometry: '<S84>/Trigonometric Function1'
    rtb_IntegralGain_ah = (real32_T)sin((real_T)rtb_Elevator);
    rtb_ZeroGain_p2 = (real32_T)cos((real_T)rtb_Elevator);

    // Sum: '<S84>/Sum2' incorporates:
    //   Gain: '<S84>/Gain'
    //   Inport: '<Root>/FlatVe'
    //   Product: '<S84>/Product6'
    //   Product: '<S84>/Product7'
    //   Sum: '<S84>/Add3'

    rtb_SignDeltaU_on = (rtb_SignDeltaU_h * rtb_ZeroGain_p2 -
                         rtb_IntegralGain_ah * rtb_Aileron) * VelMax -
      Ctrl_U.FlatVe[0];

    // Sum: '<S100>/Sum' incorporates:
    //   DiscreteIntegrator: '<S100>/Integrator'
    //   Gain: '<S100>/Proportional Gain'

    rtb_IntegralGain_c = VelKp * rtb_SignDeltaU_on + Ctrl_DW.Integrator_DSTATE_d;

    // Saturate: '<S100>/Saturate'
    if (rtb_IntegralGain_c > Ctrl_P.DiscretePIDController2_UpperS_i) {
      rtb_Gain1 = Ctrl_P.DiscretePIDController2_UpperS_i;
    } else if (rtb_IntegralGain_c < Ctrl_P.DiscretePIDController2_LowerS_a) {
      rtb_Gain1 = Ctrl_P.DiscretePIDController2_LowerS_a;
    } else {
      rtb_Gain1 = rtb_IntegralGain_c;
    }

    // End of Saturate: '<S100>/Saturate'

    // Trigonometry: '<S84>/Trigonometric Function'
    rtb_IntegralGain_b = (real32_T)cos((real_T)rtb_Elevator);
    rtb_Elevator = (real32_T)sin((real_T)rtb_Elevator);

    // Sum: '<S84>/Sum1' incorporates:
    //   Gain: '<S84>/Gain1'
    //   Inport: '<Root>/FlatVe'
    //   Product: '<S84>/Product4'
    //   Product: '<S84>/Product5'
    //   Sum: '<S84>/Add2'

    rtb_ZeroGain_p2 = (rtb_SignDeltaU_h * rtb_IntegralGain_ah + rtb_ZeroGain_p2 *
                       rtb_Aileron) * VelMax - Ctrl_U.FlatVe[1];

    // Sum: '<S99>/Sum' incorporates:
    //   DiscreteIntegrator: '<S99>/Integrator'
    //   Gain: '<S99>/Proportional Gain'

    rtb_IntegralGain_ah = VelKp * rtb_ZeroGain_p2 + Ctrl_DW.Integrator_DSTATE_o;

    // Saturate: '<S99>/Saturate'
    if (rtb_IntegralGain_ah > Ctrl_P.DiscretePIDController1_UpperS_n) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController1_UpperS_n;
    } else if (rtb_IntegralGain_ah < Ctrl_P.DiscretePIDController1_LowerS_e) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController1_LowerS_e;
    } else {
      rtb_SignDeltaU_h = rtb_IntegralGain_ah;
    }

    // End of Saturate: '<S99>/Saturate'

    // Gain: '<S83>/Scale roll2' incorporates:
    //   Product: '<S84>/Product2'
    //   Product: '<S84>/Product3'
    //   Sum: '<S84>/Add1'
    //   Trigonometry: '<S84>/Trigonometric Function'

    Ctrl_B.RollRef = (rtb_IntegralGain_b * rtb_SignDeltaU_h - rtb_Gain1 *
                      rtb_Elevator) * RollPitchMax;

    // Gain: '<S96>/Proportional Gain' incorporates:
    //   Inport: '<Root>/RPY'
    //   Sum: '<S83>/Sum3'

    rtb_SignDeltaU_f = (Ctrl_B.RollRef - Ctrl_U.RPY[0]) * RollPitchKp;

    // Saturate: '<S96>/Saturate'
    if (rtb_SignDeltaU_f > RollPitchRateMax) {
      Ctrl_B.dRollRef = RollPitchRateMax;
    } else if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController1_Lower_pq) {
      Ctrl_B.dRollRef = Ctrl_P.DiscretePIDController1_Lower_pq;
    } else {
      Ctrl_B.dRollRef = rtb_SignDeltaU_f;
    }

    // End of Saturate: '<S96>/Saturate'

    // Sum: '<S83>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_Aileron = Ctrl_B.dRollRef - Ctrl_U.dRPY[0];

    // Gain: '<S95>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S95>/Filter'
    //   Gain: '<S95>/Derivative Gain'
    //   Sum: '<S95>/SumD'

    rtb_IntegralGain_cm = (RollPitchRateKd * rtb_Aileron - Ctrl_DW.Filter_DSTATE)
      * Ctrl_P.DiscretePIDController_N_n;

    // Sum: '<S95>/Sum' incorporates:
    //   DiscreteIntegrator: '<S95>/Integrator'
    //   Gain: '<S95>/Proportional Gain'

    rtb_SignDeltaU_je = (RollPitchRateKp * rtb_Aileron +
                         Ctrl_DW.Integrator_DSTATE_m) + rtb_IntegralGain_cm;

    // Saturate: '<S95>/Saturate'
    if (rtb_SignDeltaU_je > Ctrl_P.DiscretePIDController_UpperS_ii) {
      Ctrl_B.RollOut = Ctrl_P.DiscretePIDController_UpperS_ii;
    } else if (rtb_SignDeltaU_je < Ctrl_P.DiscretePIDController_LowerS_ok) {
      Ctrl_B.RollOut = Ctrl_P.DiscretePIDController_LowerS_ok;
    } else {
      Ctrl_B.RollOut = rtb_SignDeltaU_je;
    }

    // End of Saturate: '<S95>/Saturate'

    // Gain: '<S82>/Scale roll1' incorporates:
    //   Product: '<S84>/Product'
    //   Product: '<S84>/Product1'
    //   Sum: '<S84>/Add'
    //   Trigonometry: '<S84>/Trigonometric Function'

    Ctrl_B.PitchRef = ((0.0F - rtb_Gain1 * rtb_IntegralGain_b) - rtb_Elevator *
                       rtb_SignDeltaU_h) * RollPitchMax;

    // Gain: '<S93>/Proportional Gain' incorporates:
    //   Inport: '<Root>/RPY'
    //   Sum: '<S82>/Sum3'

    rtb_SignDeltaU_f = (Ctrl_B.PitchRef - Ctrl_U.RPY[1]) * RollPitchKp;

    // Saturate: '<S93>/Saturate'
    if (rtb_SignDeltaU_f > RollPitchRateMax) {
      Ctrl_B.dPitchRef = RollPitchRateMax;
    } else if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController1_LowerS_f) {
      Ctrl_B.dPitchRef = Ctrl_P.DiscretePIDController1_LowerS_f;
    } else {
      Ctrl_B.dPitchRef = rtb_SignDeltaU_f;
    }

    // End of Saturate: '<S93>/Saturate'

    // Sum: '<S82>/Sum1' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_b = Ctrl_B.dPitchRef - Ctrl_U.dRPY[1];

    // Gain: '<S92>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S92>/Filter'
    //   Gain: '<S92>/Derivative Gain'
    //   Sum: '<S92>/SumD'

    rtb_IntegralGain_i = (RollPitchRateKd * rtb_IntegralGain_b -
                          Ctrl_DW.Filter_DSTATE_c) *
      Ctrl_P.DiscretePIDController_N_g;

    // Sum: '<S92>/Sum' incorporates:
    //   DiscreteIntegrator: '<S92>/Integrator'
    //   Gain: '<S92>/Proportional Gain'

    rtb_FilterCoefficient_i = (RollPitchRateKp * rtb_IntegralGain_b +
      Ctrl_DW.Integrator_DSTATE_e) + rtb_IntegralGain_i;

    // Saturate: '<S92>/Saturate'
    if (rtb_FilterCoefficient_i > Ctrl_P.DiscretePIDController_UpperSa_m) {
      Ctrl_B.PitchOut = Ctrl_P.DiscretePIDController_UpperSa_m;
    } else if (rtb_FilterCoefficient_i < Ctrl_P.DiscretePIDController_LowerS_a3)
    {
      Ctrl_B.PitchOut = Ctrl_P.DiscretePIDController_LowerS_a3;
    } else {
      Ctrl_B.PitchOut = rtb_FilterCoefficient_i;
    }

    // End of Saturate: '<S92>/Saturate'

    // DiscreteIntegrator: '<S85>/Discrete-Time Integrator' incorporates:
    //   Inport: '<Root>/RPY'

    if (Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
      Ctrl_DW.DiscreteTimeIntegrator_DSTATE = Ctrl_U.RPY[2];
    }

    // MATLAB Function: '<S85>/Correct Yaw1' incorporates:
    //   DiscreteIntegrator: '<S85>/Discrete-Time Integrator'
    //   Inport: '<Root>/RPY'
    //   Sum: '<S85>/Sum3'

    Ctrl_CorrectYaw1(Ctrl_DW.DiscreteTimeIntegrator_DSTATE - Ctrl_U.RPY[2],
                     &Ctrl_B.sf_CorrectYaw1_l);

    // Gain: '<S105>/Proportional Gain'
    rtb_SignDeltaU_f = YawKp * Ctrl_B.sf_CorrectYaw1_l.y;

    // Saturate: '<S105>/Saturate'
    if (rtb_SignDeltaU_f > YawRateMax) {
      rtb_SignDeltaU_f = YawRateMax;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.DiscretePIDController3_LowerS_f) {
        rtb_SignDeltaU_f = Ctrl_P.DiscretePIDController3_LowerS_f;
      }
    }

    // Sum: '<S85>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'
    //   Saturate: '<S105>/Saturate'

    rtb_Gain1 = rtb_SignDeltaU_f - Ctrl_U.dRPY[2];

    // Sum: '<S104>/Sum' incorporates:
    //   DiscreteIntegrator: '<S104>/Integrator'
    //   Gain: '<S104>/Proportional Gain'

    rtb_Elevator = YawRateKp * rtb_Gain1 + Ctrl_DW.Integrator_DSTATE_f;

    // Saturate: '<S104>/Saturate'
    if (rtb_Elevator > Ctrl_P.DiscretePIDController_UpperS_nb) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController_UpperS_nb;
    } else if (rtb_Elevator < Ctrl_P.DiscretePIDController_LowerSa_m) {
      rtb_SignDeltaU_h = Ctrl_P.DiscretePIDController_LowerSa_m;
    } else {
      rtb_SignDeltaU_h = rtb_Elevator;
    }

    // End of Saturate: '<S104>/Saturate'

    // Sum: '<S81>/Add1'
    rtb_SignDeltaU_f = ((rtb_FilterCoefficient_j - Ctrl_B.RollOut) +
                        Ctrl_B.PitchOut) + rtb_SignDeltaU_h;

    // Sum: '<S81>/Add2'
    rtb_Add4_n = ((rtb_FilterCoefficient_j - Ctrl_B.RollOut) - Ctrl_B.PitchOut)
      - rtb_SignDeltaU_h;

    // Sum: '<S81>/Add3'
    rtb_Saturate_l = ((rtb_FilterCoefficient_j + Ctrl_B.RollOut) +
                      Ctrl_B.PitchOut) - rtb_SignDeltaU_h;

    // Sum: '<S81>/Add4'
    rtb_FilterCoefficient_j = ((rtb_FilterCoefficient_j + Ctrl_B.RollOut) -
      Ctrl_B.PitchOut) + rtb_SignDeltaU_h;

    // Saturate: '<S88>/Limit3'
    if (rtb_Saturate_l > Ctrl_P.Limit3_UpperSat_p) {
      rtb_Saturate_l = Ctrl_P.Limit3_UpperSat_p;
    } else {
      if (rtb_Saturate_l < Ctrl_P.Limit3_LowerSat_it) {
        rtb_Saturate_l = Ctrl_P.Limit3_LowerSat_it;
      }
    }

    // Sum: '<S88>/Subtract' incorporates:
    //   Constant: '<S88>/Constant'
    //   Gain: '<S88>/Gain'
    //   Saturate: '<S88>/Limit3'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_oa * rtb_Saturate_l + Ctrl_P.Constant_Value_l;

    // Saturate: '<S89>/Limit3'
    if (rtb_SignDeltaU_f > Ctrl_P.Limit3_UpperSat_e) {
      rtb_SignDeltaU_f = Ctrl_P.Limit3_UpperSat_e;
    } else {
      if (rtb_SignDeltaU_f < Ctrl_P.Limit3_LowerSat_l) {
        rtb_SignDeltaU_f = Ctrl_P.Limit3_LowerSat_l;
      }
    }

    // Sum: '<S89>/Subtract' incorporates:
    //   Constant: '<S89>/Constant'
    //   Gain: '<S89>/Gain'
    //   Saturate: '<S89>/Limit3'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_hh * rtb_SignDeltaU_f +
      Ctrl_P.Constant_Value_bv;

    // Saturate: '<S90>/Limit3'
    if (rtb_Add4_n > Ctrl_P.Limit3_UpperSat_lo) {
      rtb_Add4_n = Ctrl_P.Limit3_UpperSat_lo;
    } else {
      if (rtb_Add4_n < Ctrl_P.Limit3_LowerSat_gb) {
        rtb_Add4_n = Ctrl_P.Limit3_LowerSat_gb;
      }
    }

    // Sum: '<S90>/Subtract' incorporates:
    //   Constant: '<S90>/Constant'
    //   Gain: '<S90>/Gain'
    //   Saturate: '<S90>/Limit3'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_do * rtb_Add4_n + Ctrl_P.Constant_Value_f;

    // Saturate: '<S91>/Limit3'
    if (rtb_FilterCoefficient_j > Ctrl_P.Limit3_UpperSat_i) {
      rtb_FilterCoefficient_j = Ctrl_P.Limit3_UpperSat_i;
    } else {
      if (rtb_FilterCoefficient_j < Ctrl_P.Limit3_LowerSat_d4) {
        rtb_FilterCoefficient_j = Ctrl_P.Limit3_LowerSat_d4;
      }
    }

    // Sum: '<S91>/Subtract' incorporates:
    //   Constant: '<S91>/Constant'
    //   Gain: '<S91>/Gain'
    //   Saturate: '<S91>/Limit3'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_bo * rtb_FilterCoefficient_j +
      Ctrl_P.Constant_Value_d3;

    // Gain: '<S94>/ZeroGain'
    rtb_SignDeltaU_h = Ctrl_P.ZeroGain_Gain_fc * rtb_FilterCoefficient_i;

    // DeadZone: '<S94>/DeadZone'
    if (rtb_FilterCoefficient_i > Ctrl_P.DiscretePIDController_UpperSa_m) {
      rtb_FilterCoefficient_i -= Ctrl_P.DiscretePIDController_UpperSa_m;
    } else if (rtb_FilterCoefficient_i >= Ctrl_P.DiscretePIDController_LowerS_a3)
    {
      rtb_FilterCoefficient_i = 0.0F;
    } else {
      rtb_FilterCoefficient_i -= Ctrl_P.DiscretePIDController_LowerS_a3;
    }

    // End of DeadZone: '<S94>/DeadZone'

    // RelationalOperator: '<S94>/NotEqual'
    rtb_NotEqual_a = (rtb_SignDeltaU_h != rtb_FilterCoefficient_i);

    // Signum: '<S94>/SignDeltaU'
    if (rtb_FilterCoefficient_i < 0.0F) {
      rtb_FilterCoefficient_i = -1.0F;
    } else {
      if (rtb_FilterCoefficient_i > 0.0F) {
        rtb_FilterCoefficient_i = 1.0F;
      }
    }

    // End of Signum: '<S94>/SignDeltaU'

    // Gain: '<S92>/Integral Gain'
    rtb_IntegralGain_b *= RollPitchRateKi;

    // Gain: '<S97>/ZeroGain'
    rtb_SignDeltaU_h = Ctrl_P.ZeroGain_Gain_bv * rtb_SignDeltaU_je;

    // DeadZone: '<S97>/DeadZone'
    if (rtb_SignDeltaU_je > Ctrl_P.DiscretePIDController_UpperS_ii) {
      rtb_SignDeltaU_je -= Ctrl_P.DiscretePIDController_UpperS_ii;
    } else if (rtb_SignDeltaU_je >= Ctrl_P.DiscretePIDController_LowerS_ok) {
      rtb_SignDeltaU_je = 0.0F;
    } else {
      rtb_SignDeltaU_je -= Ctrl_P.DiscretePIDController_LowerS_ok;
    }

    // End of DeadZone: '<S97>/DeadZone'

    // RelationalOperator: '<S97>/NotEqual'
    rtb_NotEqual_ac = (rtb_SignDeltaU_h != rtb_SignDeltaU_je);

    // Signum: '<S97>/SignDeltaU'
    if (rtb_SignDeltaU_je < 0.0F) {
      rtb_SignDeltaU_je = -1.0F;
    } else {
      if (rtb_SignDeltaU_je > 0.0F) {
        rtb_SignDeltaU_je = 1.0F;
      }
    }

    // End of Signum: '<S97>/SignDeltaU'

    // Gain: '<S95>/Integral Gain'
    rtb_Aileron *= RollPitchRateKi;

    // Gain: '<S101>/ZeroGain'
    rtb_SignDeltaU_h = Ctrl_P.ZeroGain_Gain_ph * rtb_IntegralGain_ah;

    // DeadZone: '<S101>/DeadZone'
    if (rtb_IntegralGain_ah > Ctrl_P.DiscretePIDController1_UpperS_n) {
      rtb_IntegralGain_ah -= Ctrl_P.DiscretePIDController1_UpperS_n;
    } else if (rtb_IntegralGain_ah >= Ctrl_P.DiscretePIDController1_LowerS_e) {
      rtb_IntegralGain_ah = 0.0F;
    } else {
      rtb_IntegralGain_ah -= Ctrl_P.DiscretePIDController1_LowerS_e;
    }

    // End of DeadZone: '<S101>/DeadZone'

    // RelationalOperator: '<S101>/NotEqual'
    rtb_NotEqual_dy = (rtb_SignDeltaU_h != rtb_IntegralGain_ah);

    // Signum: '<S101>/SignDeltaU'
    if (rtb_IntegralGain_ah < 0.0F) {
      rtb_IntegralGain_ah = -1.0F;
    } else {
      if (rtb_IntegralGain_ah > 0.0F) {
        rtb_IntegralGain_ah = 1.0F;
      }
    }

    // End of Signum: '<S101>/SignDeltaU'

    // Gain: '<S99>/Integral Gain'
    rtb_ZeroGain_p2 *= VelKi;

    // Gain: '<S102>/ZeroGain'
    rtb_SignDeltaU_h = Ctrl_P.ZeroGain_Gain_em * rtb_IntegralGain_c;

    // DeadZone: '<S102>/DeadZone'
    if (rtb_IntegralGain_c > Ctrl_P.DiscretePIDController2_UpperS_i) {
      rtb_IntegralGain_c -= Ctrl_P.DiscretePIDController2_UpperS_i;
    } else if (rtb_IntegralGain_c >= Ctrl_P.DiscretePIDController2_LowerS_a) {
      rtb_IntegralGain_c = 0.0F;
    } else {
      rtb_IntegralGain_c -= Ctrl_P.DiscretePIDController2_LowerS_a;
    }

    // End of DeadZone: '<S102>/DeadZone'

    // RelationalOperator: '<S102>/NotEqual'
    rtb_NotEqual_ga = (rtb_SignDeltaU_h != rtb_IntegralGain_c);

    // Signum: '<S102>/SignDeltaU'
    if (rtb_IntegralGain_c < 0.0F) {
      rtb_IntegralGain_c = -1.0F;
    } else {
      if (rtb_IntegralGain_c > 0.0F) {
        rtb_IntegralGain_c = 1.0F;
      }
    }

    // End of Signum: '<S102>/SignDeltaU'

    // Gain: '<S100>/Integral Gain'
    rtb_SignDeltaU_on *= VelKi;

    // Gain: '<S106>/ZeroGain'
    rtb_SignDeltaU_h = Ctrl_P.ZeroGain_Gain_ei * rtb_Elevator;

    // DeadZone: '<S106>/DeadZone'
    if (rtb_Elevator > Ctrl_P.DiscretePIDController_UpperS_nb) {
      rtb_Elevator -= Ctrl_P.DiscretePIDController_UpperS_nb;
    } else if (rtb_Elevator >= Ctrl_P.DiscretePIDController_LowerSa_m) {
      rtb_Elevator = 0.0F;
    } else {
      rtb_Elevator -= Ctrl_P.DiscretePIDController_LowerSa_m;
    }

    // End of DeadZone: '<S106>/DeadZone'

    // RelationalOperator: '<S106>/NotEqual'
    rtb_NotEqual_d = (rtb_SignDeltaU_h != rtb_Elevator);

    // Signum: '<S106>/SignDeltaU'
    if (rtb_Elevator < 0.0F) {
      rtb_Elevator = -1.0F;
    } else {
      if (rtb_Elevator > 0.0F) {
        rtb_Elevator = 1.0F;
      }
    }

    // End of Signum: '<S106>/SignDeltaU'

    // Gain: '<S104>/Integral Gain'
    rtb_Gain1 *= YawRateKi;

    // Update for DiscreteIntegrator: '<S86>/Integrator'
    Ctrl_DW.Integrator_DSTATE += Ctrl_P.Integrator_gainval_o * rtb_Thr;

    // Signum: '<S102>/SignPreIntegrator'
    if (rtb_SignDeltaU_on < 0.0F) {
      rtb_Thr = -1.0F;
    } else if (rtb_SignDeltaU_on > 0.0F) {
      rtb_Thr = 1.0F;
    } else {
      rtb_Thr = rtb_SignDeltaU_on;
    }

    // DataTypeConversion: '<S102>/DataTypeConv2' incorporates:
    //   Signum: '<S102>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Thr, (real_T)256.0F);

    // DataTypeConversion: '<S102>/DataTypeConv1'
    if (rtb_IntegralGain_c < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_IntegralGain_c;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S102>/DataTypeConv1'

    // Switch: '<S100>/Switch' incorporates:
    //   Constant: '<S100>/Constant'
    //   DataTypeConversion: '<S102>/DataTypeConv2'
    //   Logic: '<S102>/AND'
    //   RelationalOperator: '<S102>/Equal'

    if (rtb_NotEqual_ga && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_SignDeltaU_on = Ctrl_P.Constant_Value_fy;
    }

    // End of Switch: '<S100>/Switch'

    // Update for DiscreteIntegrator: '<S100>/Integrator'
    Ctrl_DW.Integrator_DSTATE_d += Ctrl_P.Integrator_gainval_dj *
      rtb_SignDeltaU_on;

    // Signum: '<S101>/SignPreIntegrator'
    if (rtb_ZeroGain_p2 < 0.0F) {
      rtb_Thr = -1.0F;
    } else if (rtb_ZeroGain_p2 > 0.0F) {
      rtb_Thr = 1.0F;
    } else {
      rtb_Thr = rtb_ZeroGain_p2;
    }

    // DataTypeConversion: '<S101>/DataTypeConv2' incorporates:
    //   Signum: '<S101>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Thr, (real_T)256.0F);

    // DataTypeConversion: '<S101>/DataTypeConv1'
    if (rtb_IntegralGain_ah < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_IntegralGain_ah;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S101>/DataTypeConv1'

    // Switch: '<S99>/Switch' incorporates:
    //   Constant: '<S99>/Constant'
    //   DataTypeConversion: '<S101>/DataTypeConv2'
    //   Logic: '<S101>/AND'
    //   RelationalOperator: '<S101>/Equal'

    if (rtb_NotEqual_dy && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_ZeroGain_p2 = Ctrl_P.Constant_Value_gz;
    }

    // End of Switch: '<S99>/Switch'

    // Update for DiscreteIntegrator: '<S99>/Integrator'
    Ctrl_DW.Integrator_DSTATE_o += Ctrl_P.Integrator_gainval_iz *
      rtb_ZeroGain_p2;

    // Signum: '<S97>/SignPreIntegrator'
    if (rtb_Aileron < 0.0F) {
      rtb_Thr = -1.0F;
    } else if (rtb_Aileron > 0.0F) {
      rtb_Thr = 1.0F;
    } else {
      rtb_Thr = rtb_Aileron;
    }

    // DataTypeConversion: '<S97>/DataTypeConv2' incorporates:
    //   Signum: '<S97>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Thr, (real_T)256.0F);

    // DataTypeConversion: '<S97>/DataTypeConv1'
    if (rtb_SignDeltaU_je < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_SignDeltaU_je;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S97>/DataTypeConv1'

    // Switch: '<S95>/Switch' incorporates:
    //   Constant: '<S95>/Constant'
    //   DataTypeConversion: '<S97>/DataTypeConv2'
    //   Logic: '<S97>/AND'
    //   RelationalOperator: '<S97>/Equal'

    if (rtb_NotEqual_ac && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
          (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)rtb_Saturate_l) ==
         rtb_Add4_b)) {
      rtb_Aileron = Ctrl_P.Constant_Value_em;
    }

    // End of Switch: '<S95>/Switch'

    // Update for DiscreteIntegrator: '<S95>/Integrator'
    Ctrl_DW.Integrator_DSTATE_m += Ctrl_P.Integrator_gainval_pk * rtb_Aileron;

    // Update for DiscreteIntegrator: '<S95>/Filter'
    Ctrl_DW.Filter_DSTATE += Ctrl_P.Filter_gainval_a * rtb_IntegralGain_cm;

    // Signum: '<S94>/SignPreIntegrator'
    if (rtb_IntegralGain_b < 0.0F) {
      rtb_IntegralGain_cm = -1.0F;
    } else if (rtb_IntegralGain_b > 0.0F) {
      rtb_IntegralGain_cm = 1.0F;
    } else {
      rtb_IntegralGain_cm = rtb_IntegralGain_b;
    }

    // DataTypeConversion: '<S94>/DataTypeConv2' incorporates:
    //   Signum: '<S94>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_IntegralGain_cm, (real_T)256.0F);

    // DataTypeConversion: '<S94>/DataTypeConv1'
    if (rtb_FilterCoefficient_i < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_FilterCoefficient_i;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S94>/DataTypeConv1'

    // Switch: '<S92>/Switch' incorporates:
    //   Constant: '<S92>/Constant'
    //   DataTypeConversion: '<S94>/DataTypeConv2'
    //   Logic: '<S94>/AND'
    //   RelationalOperator: '<S94>/Equal'

    if (rtb_NotEqual_a && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_IntegralGain_b = Ctrl_P.Constant_Value_pd;
    }

    // End of Switch: '<S92>/Switch'

    // Update for DiscreteIntegrator: '<S92>/Integrator'
    Ctrl_DW.Integrator_DSTATE_e += Ctrl_P.Integrator_gainval_hs *
      rtb_IntegralGain_b;

    // Update for DiscreteIntegrator: '<S92>/Filter'
    Ctrl_DW.Filter_DSTATE_c += Ctrl_P.Filter_gainval_d * rtb_IntegralGain_i;

    // Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator'
    Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

    // DeadZone: '<S85>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End_p) {
      rtb_Rudder -= Ctrl_P.DeadZone_End_p;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start_b) {
      rtb_Rudder = 0.0F;
    } else {
      rtb_Rudder -= Ctrl_P.DeadZone_Start_b;
    }

    // End of DeadZone: '<S85>/Dead Zone'

    // Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' incorporates:
    //   Gain: '<S85>/Scale roll2'

    Ctrl_DW.DiscreteTimeIntegrator_DSTATE += Ctrl_P.Scaleroll2_Gain_m *
      rtb_Rudder * Ctrl_P.DiscreteTimeIntegrator_gainva_h;

    // Signum: '<S106>/SignPreIntegrator'
    if (rtb_Gain1 < 0.0F) {
      rtb_Rudder = -1.0F;
    } else if (rtb_Gain1 > 0.0F) {
      rtb_Rudder = 1.0F;
    } else {
      rtb_Rudder = rtb_Gain1;
    }

    // DataTypeConversion: '<S106>/DataTypeConv2' incorporates:
    //   Signum: '<S106>/SignPreIntegrator'

    rtb_Saturate_l = (real32_T)fmod((real_T)rtb_Rudder, (real_T)256.0F);

    // DataTypeConversion: '<S106>/DataTypeConv1'
    if (rtb_Elevator < 128.0F) {
      rtb_Add4_b = (int8_T)rtb_Elevator;
    } else {
      rtb_Add4_b = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S106>/DataTypeConv1'

    // Switch: '<S104>/Switch' incorporates:
    //   Constant: '<S104>/Constant'
    //   DataTypeConversion: '<S106>/DataTypeConv2'
    //   Logic: '<S106>/AND'
    //   RelationalOperator: '<S106>/Equal'

    if (rtb_NotEqual_d && ((rtb_Saturate_l < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_Saturate_l : (int32_T)(int8_T)(uint8_T)
                            rtb_Saturate_l) == rtb_Add4_b)) {
      rtb_Gain1 = Ctrl_P.Constant_Value_fi;
    }

    // End of Switch: '<S104>/Switch'

    // Update for DiscreteIntegrator: '<S104>/Integrator'
    Ctrl_DW.Integrator_DSTATE_f += Ctrl_P.Integrator_gainval_mt * rtb_Gain1;
  } else {
    if (Ctrl_DW.VelocityCtrl_MODE) {
      Ctrl_DW.VelocityCtrl_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S1>/VelocityCtrl'

  // Saturate: '<S11>/Saturation' incorporates:
  //   Inport: '<Root>/BatteryVoltage'

  if (Ctrl_U.BatteryVoltage > Ctrl_P.Saturation_UpperSat_o) {
    rtb_Rudder = Ctrl_P.Saturation_UpperSat_o;
  } else if (Ctrl_U.BatteryVoltage < Ctrl_P.Saturation_LowerSat_k) {
    rtb_Rudder = Ctrl_P.Saturation_LowerSat_k;
  } else {
    rtb_Rudder = Ctrl_U.BatteryVoltage;
  }

  // End of Saturate: '<S11>/Saturation'

  // Polyval: '<S11>/Polynomial'
  rtb_Aileron = (Ctrl_P.Polynomial_Coefs[0] * rtb_Rudder +
                 Ctrl_P.Polynomial_Coefs[1]) * rtb_Rudder +
    Ctrl_P.Polynomial_Coefs[2];

  // Update for Delay: '<S2>/Delay'
  for (cff = 0; cff < 99; cff++) {
    Ctrl_DW.Delay_DSTATE[cff] = Ctrl_DW.Delay_DSTATE[cff + 1];
  }

  Ctrl_DW.Delay_DSTATE[99] = rtb_DiscreteFIRFilter;

  // End of Update for Delay: '<S2>/Delay'

  // Update for DiscreteFir: '<S2>/Discrete FIR Filter'
  // Update circular buffer index
  Ctrl_DW.DiscreteFIRFilter_circBuf--;
  if (Ctrl_DW.DiscreteFIRFilter_circBuf < 0) {
    Ctrl_DW.DiscreteFIRFilter_circBuf = 98;
  }

  // Update circular buffer
  Ctrl_DW.DiscreteFIRFilter_states[Ctrl_DW.DiscreteFIRFilter_circBuf] = alt;

  // End of Update for DiscreteFir: '<S2>/Discrete FIR Filter'
  // End of Outputs for SubSystem: '<Root>/Ctrl'

  // Outport: '<Root>/PWM1'
  Ctrl_Y.PWM1 = Ctrl_B.PWM1;

  // Outport: '<Root>/PWM2'
  Ctrl_Y.PWM2 = Ctrl_B.PWM2;

  // Outport: '<Root>/PWM3'
  Ctrl_Y.PWM3 = Ctrl_B.PWM3;

  // Outport: '<Root>/PWM4'
  Ctrl_Y.PWM4 = Ctrl_B.PWM4;

  // Outport: '<Root>/Altitude'
  Ctrl_Y.Altitude = rtb_DiscreteFIRFilter;

  // Outport: '<Root>/VertSpeed'
  Ctrl_Y.VertSpeed = rtb_Gain;

  // Outputs for Atomic SubSystem: '<Root>/Ctrl'
  // Saturate: '<S11>/Saturation1'
  if (rtb_Aileron > Ctrl_P.Saturation1_UpperSat_o) {
    // Outport: '<Root>/FuelPercent'
    Ctrl_Y.FuelPercent = Ctrl_P.Saturation1_UpperSat_o;
  } else if (rtb_Aileron < Ctrl_P.Saturation1_LowerSat_o) {
    // Outport: '<Root>/FuelPercent'
    Ctrl_Y.FuelPercent = Ctrl_P.Saturation1_LowerSat_o;
  } else {
    // Outport: '<Root>/FuelPercent'
    Ctrl_Y.FuelPercent = rtb_Aileron;
  }

  // End of Saturate: '<S11>/Saturation1'
  // End of Outputs for SubSystem: '<Root>/Ctrl'
}

// Model initialize function
void CtrlModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Ctrl_M), (NULL));

  // block I/O
  (void) memset(((void *) &Ctrl_B), 0,
                sizeof(B_Ctrl_T));

  // states (dwork)
  (void) memset((void *)&Ctrl_DW, 0,
                sizeof(DW_Ctrl_T));

  // external inputs
  (void) memset((void *)&Ctrl_U, 0,
                sizeof(ExtU_Ctrl_T));

  // external outputs
  (void) memset((void *)&Ctrl_Y, 0,
                sizeof(ExtY_Ctrl_T));

  {
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Ctrl'
    // InitializeConditions for Enabled SubSystem: '<S1>/AutoCtrl'
    // InitializeConditions for DiscreteIntegrator: '<S20>/Integrator'
    Ctrl_DW.Integrator_DSTATE_dl = Ctrl_P.Integrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S37>/Integrator'
    Ctrl_DW.Integrator_DSTATE_id = Ctrl_P.Integrator_IC_k;

    // InitializeConditions for DiscreteIntegrator: '<S36>/Integrator'
    Ctrl_DW.Integrator_DSTATE_ba = Ctrl_P.Integrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S32>/Integrator'
    Ctrl_DW.Integrator_DSTATE_l = Ctrl_P.Integrator_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S32>/Filter'
    Ctrl_DW.Filter_DSTATE_pa = Ctrl_P.Filter_IC;

    // InitializeConditions for DiscreteIntegrator: '<S27>/Integrator'
    Ctrl_DW.Integrator_DSTATE_j = Ctrl_P.Integrator_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S27>/Filter'
    Ctrl_DW.Filter_DSTATE_n = Ctrl_P.Filter_IC_d;

    // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' 
    Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S41>/Integrator'
    Ctrl_DW.Integrator_DSTATE_di = Ctrl_P.Integrator_IC_o;

    // End of InitializeConditions for SubSystem: '<S1>/AutoCtrl'

    // Start for Enabled SubSystem: '<S1>/Off'
    // VirtualOutportStart for Outport: '<S7>/PWMs'
    Ctrl_B.PWM1 = Ctrl_P.PWMs_Y0[0];
    Ctrl_B.PWM2 = Ctrl_P.PWMs_Y0[1];
    Ctrl_B.PWM3 = Ctrl_P.PWMs_Y0[2];
    Ctrl_B.PWM4 = Ctrl_P.PWMs_Y0[3];

    // End of Start for SubSystem: '<S1>/Off'

    // InitializeConditions for Enabled SubSystem: '<S1>/RateCtrl'
    // InitializeConditions for DiscreteIntegrator: '<S60>/Integrator'
    Ctrl_DW.Integrator_DSTATE_fa = Ctrl_P.Integrator_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S60>/Filter'
    Ctrl_DW.Filter_DSTATE_p = Ctrl_P.Filter_IC_f;

    // InitializeConditions for DiscreteIntegrator: '<S58>/Integrator'
    Ctrl_DW.Integrator_DSTATE_g = Ctrl_P.Integrator_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S58>/Filter'
    Ctrl_DW.Filter_DSTATE_h = Ctrl_P.Filter_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<S62>/Integrator'
    Ctrl_DW.Integrator_DSTATE_p = Ctrl_P.Integrator_IC_a;

    // End of InitializeConditions for SubSystem: '<S1>/RateCtrl'

    // InitializeConditions for Enabled SubSystem: '<S1>/RollPitchCtrl'
    // InitializeConditions for DiscreteIntegrator: '<S75>/Integrator'
    Ctrl_DW.Integrator_DSTATE_i = Ctrl_P.Integrator_IC_g;

    // InitializeConditions for DiscreteIntegrator: '<S75>/Filter'
    Ctrl_DW.Filter_DSTATE_o = Ctrl_P.Filter_IC_b;

    // InitializeConditions for DiscreteIntegrator: '<S72>/Integrator'
    Ctrl_DW.Integrator_DSTATE_o1 = Ctrl_P.Integrator_IC_p;

    // InitializeConditions for DiscreteIntegrator: '<S72>/Filter'
    Ctrl_DW.Filter_DSTATE_d = Ctrl_P.Filter_IC_i;

    // InitializeConditions for DiscreteIntegrator: '<S78>/Integrator'
    Ctrl_DW.Integrator_DSTATE_b = Ctrl_P.Integrator_IC_lt;

    // End of InitializeConditions for SubSystem: '<S1>/RollPitchCtrl'

    // InitializeConditions for Enabled SubSystem: '<S1>/VelocityCtrl'
    // InitializeConditions for DiscreteIntegrator: '<S86>/Integrator'
    Ctrl_DW.Integrator_DSTATE = Ctrl_P.Integrator_IC_p4;

    // InitializeConditions for DiscreteIntegrator: '<S100>/Integrator'
    Ctrl_DW.Integrator_DSTATE_d = Ctrl_P.Integrator_IC_g2;

    // InitializeConditions for DiscreteIntegrator: '<S99>/Integrator'
    Ctrl_DW.Integrator_DSTATE_o = Ctrl_P.Integrator_IC_et;

    // InitializeConditions for DiscreteIntegrator: '<S95>/Integrator'
    Ctrl_DW.Integrator_DSTATE_m = Ctrl_P.Integrator_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<S95>/Filter'
    Ctrl_DW.Filter_DSTATE = Ctrl_P.Filter_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S92>/Integrator'
    Ctrl_DW.Integrator_DSTATE_e = Ctrl_P.Integrator_IC_b;

    // InitializeConditions for DiscreteIntegrator: '<S92>/Filter'
    Ctrl_DW.Filter_DSTATE_c = Ctrl_P.Filter_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' 
    Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S104>/Integrator'
    Ctrl_DW.Integrator_DSTATE_f = Ctrl_P.Integrator_IC_g4;

    // End of InitializeConditions for SubSystem: '<S1>/VelocityCtrl'
    // End of Start for SubSystem: '<Root>/Ctrl'

    // InitializeConditions for Atomic SubSystem: '<Root>/Ctrl'
    // InitializeConditions for Delay: '<S2>/Delay'
    for (i = 0; i < 100; i++) {
      Ctrl_DW.Delay_DSTATE[i] = Ctrl_P.Delay_InitialCondition;
    }

    // End of InitializeConditions for Delay: '<S2>/Delay'

    // InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter'
    Ctrl_DW.DiscreteFIRFilter_circBuf = 0;
    for (i = 0; i < 99; i++) {
      Ctrl_DW.DiscreteFIRFilter_states[i] =
        Ctrl_P.DiscreteFIRFilter_InitialStates;
    }

    // End of InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter'

    // InitializeConditions for Chart: '<S1>/Chart'
    Ctrl_DW.is_LEDs = Ctrl_IN_NO_ACTIVE_CHILD;
    Ctrl_DW.is_Off = Ctrl_IN_NO_ACTIVE_CHILD;
    Ctrl_DW.is_On_b = Ctrl_IN_NO_ACTIVE_CHILD;
    Ctrl_DW.temporalCounter_i2 = 0U;
    Ctrl_DW.is_SystemLogic = Ctrl_IN_NO_ACTIVE_CHILD;
    Ctrl_DW.is_On = Ctrl_IN_NO_ACTIVE_CHILD;
    Ctrl_DW.is_AutoMode = Ctrl_IN_NO_ACTIVE_CHILD;
    Ctrl_DW.temporalCounter_i1 = 0U;
    Ctrl_DW.is_active_c1_Ctrl = 0U;
    Ctrl_B.Off = false;
    Ctrl_B.ManualMode = false;
    Ctrl_B.RateMode = false;
    Ctrl_B.RollPitchMode = false;
    Ctrl_B.VelocityMode = false;
    Ctrl_B.AutoMode = false;

    // End of InitializeConditions for SubSystem: '<Root>/Ctrl'
  }
}

// Model terminate function
void CtrlModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
CtrlModelClass::CtrlModelClass()
{
  static const P_Ctrl_T Ctrl_P_temp = {
    -0.5F,                             // Mask Parameter: DiscretePIDController2_LowerSat
                                       //  Referenced by: '<S21>/Saturate'

    -0.4F,                             // Mask Parameter: DiscretePIDController1_LowerSat
                                       //  Referenced by:
                                       //    '<S20>/Saturate'
                                       //    '<S22>/DeadZone'

    -1.0F,                             // Mask Parameter: DiscretePIDController2_LowerS_e
                                       //  Referenced by: '<S31>/Saturate'

    -1.0F,                             // Mask Parameter: DiscretePIDController2_LowerS_h
                                       //  Referenced by:
                                       //    '<S37>/Saturate'
                                       //    '<S39>/DeadZone'

    -1.0F,                             // Mask Parameter: DiscretePIDController1_LowerS_m
                                       //  Referenced by: '<S30>/Saturate'

    -1.0F,                             // Mask Parameter: DiscretePIDController1_LowerS_p
                                       //  Referenced by:
                                       //    '<S36>/Saturate'
                                       //    '<S38>/DeadZone'

    -200.0F,                           // Mask Parameter: DiscretePIDController1_LowerS_g
                                       //  Referenced by: '<S33>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSatu
                                       //  Referenced by:
                                       //    '<S32>/Saturate'
                                       //    '<S34>/DeadZone'

    -200.0F,                           // Mask Parameter: DiscretePIDController1_LowerS_n
                                       //  Referenced by: '<S28>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_o
                                       //  Referenced by:
                                       //    '<S27>/Saturate'
                                       //    '<S29>/DeadZone'

    -180.0F,                           // Mask Parameter: DiscretePIDController3_LowerSat
                                       //  Referenced by: '<S42>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_i
                                       //  Referenced by:
                                       //    '<S41>/Saturate'
                                       //    '<S44>/DeadZone'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_k
                                       //  Referenced by:
                                       //    '<S60>/Saturate'
                                       //    '<S61>/DeadZone'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerS_io
                                       //  Referenced by:
                                       //    '<S58>/Saturate'
                                       //    '<S59>/DeadZone'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_a
                                       //  Referenced by:
                                       //    '<S62>/Saturate'
                                       //    '<S63>/DeadZone'

    -200.0F,                           // Mask Parameter: DiscretePIDController1_LowerS_d
                                       //  Referenced by: '<S76>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_b
                                       //  Referenced by:
                                       //    '<S75>/Saturate'
                                       //    '<S77>/DeadZone'

    -200.0F,                           // Mask Parameter: DiscretePIDController1_Lower_de
                                       //  Referenced by: '<S73>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_p
                                       //  Referenced by:
                                       //    '<S72>/Saturate'
                                       //    '<S74>/DeadZone'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_f
                                       //  Referenced by:
                                       //    '<S78>/Saturate'
                                       //    '<S79>/DeadZone'

    -0.4F,                             // Mask Parameter: DiscretePIDController1_LowerS_b
                                       //  Referenced by:
                                       //    '<S86>/Saturate'
                                       //    '<S87>/DeadZone'

    -1.0F,                             // Mask Parameter: DiscretePIDController2_LowerS_a
                                       //  Referenced by:
                                       //    '<S100>/Saturate'
                                       //    '<S102>/DeadZone'

    -1.0F,                             // Mask Parameter: DiscretePIDController1_LowerS_e
                                       //  Referenced by:
                                       //    '<S99>/Saturate'
                                       //    '<S101>/DeadZone'

    -200.0F,                           // Mask Parameter: DiscretePIDController1_Lower_pq
                                       //  Referenced by: '<S96>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerS_ok
                                       //  Referenced by:
                                       //    '<S95>/Saturate'
                                       //    '<S97>/DeadZone'

    -200.0F,                           // Mask Parameter: DiscretePIDController1_LowerS_f
                                       //  Referenced by: '<S93>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerS_a3
                                       //  Referenced by:
                                       //    '<S92>/Saturate'
                                       //    '<S94>/DeadZone'

    -180.0F,                           // Mask Parameter: DiscretePIDController3_LowerS_f
                                       //  Referenced by: '<S105>/Saturate'

    -0.2F,                             // Mask Parameter: DiscretePIDController_LowerSa_m
                                       //  Referenced by:
                                       //    '<S104>/Saturate'
                                       //    '<S106>/DeadZone'

    50.0F,                             // Mask Parameter: DiscretePIDController_N
                                       //  Referenced by: '<S32>/Filter Coefficient'

    50.0F,                             // Mask Parameter: DiscretePIDController_N_h
                                       //  Referenced by: '<S27>/Filter Coefficient'

    50.0F,                             // Mask Parameter: DiscretePIDController_N_hm
                                       //  Referenced by: '<S60>/Filter Coefficient'

    50.0F,                             // Mask Parameter: DiscretePIDController_N_p
                                       //  Referenced by: '<S58>/Filter Coefficient'

    50.0F,                             // Mask Parameter: DiscretePIDController_N_i
                                       //  Referenced by: '<S75>/Filter Coefficient'

    50.0F,                             // Mask Parameter: DiscretePIDController_N_hn
                                       //  Referenced by: '<S72>/Filter Coefficient'

    50.0F,                             // Mask Parameter: DiscretePIDController_N_n
                                       //  Referenced by: '<S95>/Filter Coefficient'

    50.0F,                             // Mask Parameter: DiscretePIDController_N_g
                                       //  Referenced by: '<S92>/Filter Coefficient'

    0.5F,                              // Mask Parameter: DiscretePIDController2_UpperSat
                                       //  Referenced by: '<S21>/Saturate'

    0.4F,                              // Mask Parameter: DiscretePIDController1_UpperSat
                                       //  Referenced by:
                                       //    '<S20>/Saturate'
                                       //    '<S22>/DeadZone'

    1.0F,                              // Mask Parameter: DiscretePIDController2_UpperS_o
                                       //  Referenced by: '<S31>/Saturate'

    1.0F,                              // Mask Parameter: DiscretePIDController2_UpperS_d
                                       //  Referenced by:
                                       //    '<S37>/Saturate'
                                       //    '<S39>/DeadZone'

    1.0F,                              // Mask Parameter: DiscretePIDController1_UpperS_b
                                       //  Referenced by: '<S30>/Saturate'

    1.0F,                              // Mask Parameter: DiscretePIDController1_UpperS_g
                                       //  Referenced by:
                                       //    '<S36>/Saturate'
                                       //    '<S38>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSatu
                                       //  Referenced by:
                                       //    '<S32>/Saturate'
                                       //    '<S34>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_g
                                       //  Referenced by:
                                       //    '<S27>/Saturate'
                                       //    '<S29>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperS_gi
                                       //  Referenced by:
                                       //    '<S41>/Saturate'
                                       //    '<S44>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_h
                                       //  Referenced by:
                                       //    '<S60>/Saturate'
                                       //    '<S61>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_n
                                       //  Referenced by:
                                       //    '<S58>/Saturate'
                                       //    '<S59>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_b
                                       //  Referenced by:
                                       //    '<S62>/Saturate'
                                       //    '<S63>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_p
                                       //  Referenced by:
                                       //    '<S75>/Saturate'
                                       //    '<S77>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_i
                                       //  Referenced by:
                                       //    '<S72>/Saturate'
                                       //    '<S74>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_k
                                       //  Referenced by:
                                       //    '<S78>/Saturate'
                                       //    '<S79>/DeadZone'

    0.4F,                              // Mask Parameter: DiscretePIDController1_UpperS_l
                                       //  Referenced by:
                                       //    '<S86>/Saturate'
                                       //    '<S87>/DeadZone'

    1.0F,                              // Mask Parameter: DiscretePIDController2_UpperS_i
                                       //  Referenced by:
                                       //    '<S100>/Saturate'
                                       //    '<S102>/DeadZone'

    1.0F,                              // Mask Parameter: DiscretePIDController1_UpperS_n
                                       //  Referenced by:
                                       //    '<S99>/Saturate'
                                       //    '<S101>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperS_ii
                                       //  Referenced by:
                                       //    '<S95>/Saturate'
                                       //    '<S97>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperSa_m
                                       //  Referenced by:
                                       //    '<S92>/Saturate'
                                       //    '<S94>/DeadZone'

    0.2F,                              // Mask Parameter: DiscretePIDController_UpperS_nb
                                       //  Referenced by:
                                       //    '<S104>/Saturate'
                                       //    '<S106>/DeadZone'

    57.2957802F,                       // Computed Parameter: Gain_Gain
                                       //  Referenced by: '<S43>/Gain'

    12.0F,                             // Computed Parameter: ScaleVel_Gain
                                       //  Referenced by: '<S13>/Scale Vel'

    20.0F,                             // Computed Parameter: FixFaultyBaro_UpperSat
                                       //  Referenced by: '<S13>/Fix Faulty Baro'

    -20.0F,                            // Computed Parameter: FixFaultyBaro_LowerSat
                                       //  Referenced by: '<S13>/Fix Faulty Baro'

    0.0025F,                           // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S20>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC
                                       //  Referenced by: '<S20>/Integrator'

    0.0F,                              // Computed Parameter: ZeroGain_Gain
                                       //  Referenced by: '<S22>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S20>/Constant'

    0.9F,                              // Computed Parameter: LimitOutput_UpperSat
                                       //  Referenced by: '<S13>/Limit Output'

    0.2F,                              // Computed Parameter: LimitOutput_LowerSat
                                       //  Referenced by: '<S13>/Limit Output'

    0.0025F,                           // Computed Parameter: Integrator_gainval_g
                                       //  Referenced by: '<S37>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_k
                                       //  Referenced by: '<S37>/Integrator'

    0.0174532924F,                     // Computed Parameter: Gain1_Gain
                                       //  Referenced by: '<S35>/Gain1'

    0.0025F,                           // Computed Parameter: Integrator_gainval_i
                                       //  Referenced by: '<S36>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_h
                                       //  Referenced by: '<S36>/Integrator'

    0.0025F,                           // Computed Parameter: Integrator_gainval_p
                                       //  Referenced by: '<S32>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_m
                                       //  Referenced by: '<S32>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S32>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC
                                       //  Referenced by: '<S32>/Filter'

    0.0025F,                           // Computed Parameter: Integrator_gainval_d
                                       //  Referenced by: '<S27>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_l
                                       //  Referenced by: '<S27>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval_l
                                       //  Referenced by: '<S27>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC_d
                                       //  Referenced by: '<S27>/Filter'

    0.0025F,                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                                       //  Referenced by: '<S19>/Discrete-Time Integrator'

    -1000.0F,                          // Computed Parameter: Switch_Threshold
                                       //  Referenced by: '<S19>/Switch'

    0.0025F,                           // Computed Parameter: Integrator_gainval_dg
                                       //  Referenced by: '<S41>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_o
                                       //  Referenced by: '<S41>/Integrator'

    1100.0F,                           // Computed Parameter: Constant_Value_p
                                       //  Referenced by: '<S23>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat
                                       //  Referenced by: '<S23>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat
                                       //  Referenced by: '<S23>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_f
                                       //  Referenced by: '<S23>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_a
                                       //  Referenced by: '<S24>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_k
                                       //  Referenced by: '<S24>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_i
                                       //  Referenced by: '<S24>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_a
                                       //  Referenced by: '<S24>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_j
                                       //  Referenced by: '<S25>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_m
                                       //  Referenced by: '<S25>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_ih
                                       //  Referenced by: '<S25>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_j
                                       //  Referenced by: '<S25>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_p4
                                       //  Referenced by: '<S26>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_a
                                       //  Referenced by: '<S26>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_n
                                       //  Referenced by: '<S26>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_b
                                       //  Referenced by: '<S26>/Gain'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_p
                                       //  Referenced by: '<S29>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_b
                                       //  Referenced by: '<S27>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_px
                                       //  Referenced by: '<S34>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_e
                                       //  Referenced by: '<S32>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_e
                                       //  Referenced by: '<S38>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_h
                                       //  Referenced by: '<S36>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_g
                                       //  Referenced by: '<S39>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_hp
                                       //  Referenced by: '<S37>/Constant'

    -0.1F,                             // Computed Parameter: DeadZone_Start
                                       //  Referenced by: '<S19>/Dead Zone'

    0.1F,                              // Computed Parameter: DeadZone_End
                                       //  Referenced by: '<S19>/Dead Zone'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_n
                                       //  Referenced by: '<S44>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_d
                                       //  Referenced by: '<S41>/Constant'

    90.0F,                             // Computed Parameter: Scaleroll2_Gain
                                       //  Referenced by: '<S19>/Scale roll2'

    1.0F,                              // Computed Parameter: Gain_Gain_ae
                                       //  Referenced by: '<S6>/Gain'

    0.2F,                              // Computed Parameter: Gain1_Gain_e
                                       //  Referenced by: '<S6>/Gain1'

    0.2F,                              // Computed Parameter: Gain2_Gain
                                       //  Referenced by: '<S6>/Gain2'

    0.2F,                              // Computed Parameter: Gain3_Gain
                                       //  Referenced by: '<S6>/Gain3'

    1100.0F,                           // Computed Parameter: Constant_Value_c
                                       //  Referenced by: '<S46>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_l
                                       //  Referenced by: '<S46>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_g
                                       //  Referenced by: '<S46>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_m
                                       //  Referenced by: '<S46>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_i
                                       //  Referenced by: '<S47>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_b
                                       //  Referenced by: '<S47>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_k
                                       //  Referenced by: '<S47>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_c
                                       //  Referenced by: '<S47>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_o
                                       //  Referenced by: '<S48>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_o
                                       //  Referenced by: '<S48>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_d
                                       //  Referenced by: '<S48>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_e
                                       //  Referenced by: '<S48>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_ew
                                       //  Referenced by: '<S49>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_c
                                       //  Referenced by: '<S49>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_f
                                       //  Referenced by: '<S49>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_bq
                                       //  Referenced by: '<S49>/Gain'


    //  Computed Parameter: PWMs_Y0
    //  Referenced by: '<S7>/PWMs'

    { 1000.0F, 1000.0F, 1000.0F, 1000.0F },
    1000.0F,                           // Computed Parameter: Constant1_Value
                                       //  Referenced by: '<S7>/Constant1'

    1000.0F,                           // Computed Parameter: Constant2_Value
                                       //  Referenced by: '<S7>/Constant2'

    1000.0F,                           // Computed Parameter: Constant3_Value
                                       //  Referenced by: '<S7>/Constant3'

    1000.0F,                           // Computed Parameter: Constant4_Value
                                       //  Referenced by: '<S7>/Constant4'

    1.0F,                              // Computed Parameter: Gain_Gain_cu
                                       //  Referenced by: '<S8>/Gain'

    0.0025F,                           // Computed Parameter: Integrator_gainval_a
                                       //  Referenced by: '<S60>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_e
                                       //  Referenced by: '<S60>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval_f
                                       //  Referenced by: '<S60>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC_f
                                       //  Referenced by: '<S60>/Filter'

    0.0025F,                           // Computed Parameter: Integrator_gainval_h
                                       //  Referenced by: '<S58>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_j
                                       //  Referenced by: '<S58>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S58>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC_c
                                       //  Referenced by: '<S58>/Filter'

    -0.1F,                             // Computed Parameter: DeadZone_Start_c
                                       //  Referenced by: '<S53>/Dead Zone'

    0.1F,                              // Computed Parameter: DeadZone_End_o
                                       //  Referenced by: '<S53>/Dead Zone'

    0.0025F,                           // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S62>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_a
                                       //  Referenced by: '<S62>/Integrator'

    1100.0F,                           // Computed Parameter: Constant_Value_g
                                       //  Referenced by: '<S54>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_d
                                       //  Referenced by: '<S54>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_ku
                                       //  Referenced by: '<S54>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_h
                                       //  Referenced by: '<S54>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_ev
                                       //  Referenced by: '<S55>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_a1
                                       //  Referenced by: '<S55>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_e
                                       //  Referenced by: '<S55>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_ce
                                       //  Referenced by: '<S55>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_k
                                       //  Referenced by: '<S56>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_g
                                       //  Referenced by: '<S56>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_j
                                       //  Referenced by: '<S56>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_cc
                                       //  Referenced by: '<S56>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_n
                                       //  Referenced by: '<S57>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_j
                                       //  Referenced by: '<S57>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_o
                                       //  Referenced by: '<S57>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_hp
                                       //  Referenced by: '<S57>/Gain'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_e0
                                       //  Referenced by: '<S59>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_aw
                                       //  Referenced by: '<S58>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_c
                                       //  Referenced by: '<S61>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_jl
                                       //  Referenced by: '<S60>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_ez
                                       //  Referenced by: '<S63>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_nm
                                       //  Referenced by: '<S62>/Constant'

    1.0F,                              // Computed Parameter: Gain_Gain_mu
                                       //  Referenced by: '<S9>/Gain'

    0.0025F,                           // Computed Parameter: Integrator_gainval_l
                                       //  Referenced by: '<S75>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_g
                                       //  Referenced by: '<S75>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S75>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC_b
                                       //  Referenced by: '<S75>/Filter'

    0.0025F,                           // Computed Parameter: Integrator_gainval_dk
                                       //  Referenced by: '<S72>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_p
                                       //  Referenced by: '<S72>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval_o
                                       //  Referenced by: '<S72>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC_i
                                       //  Referenced by: '<S72>/Filter'

    -0.1F,                             // Computed Parameter: DeadZone_Start_l
                                       //  Referenced by: '<S67>/Dead Zone'

    0.1F,                              // Computed Parameter: DeadZone_End_h
                                       //  Referenced by: '<S67>/Dead Zone'

    0.0025F,                           // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S78>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_lt
                                       //  Referenced by: '<S78>/Integrator'

    1100.0F,                           // Computed Parameter: Constant_Value_p42
                                       //  Referenced by: '<S68>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_b5
                                       //  Referenced by: '<S68>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_jv
                                       //  Referenced by: '<S68>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_o
                                       //  Referenced by: '<S68>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_co
                                       //  Referenced by: '<S69>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_gu
                                       //  Referenced by: '<S69>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_dd
                                       //  Referenced by: '<S69>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_d
                                       //  Referenced by: '<S69>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_oi
                                       //  Referenced by: '<S70>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_kf
                                       //  Referenced by: '<S70>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_du
                                       //  Referenced by: '<S70>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_i
                                       //  Referenced by: '<S70>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_awg
                                       //  Referenced by: '<S71>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_n
                                       //  Referenced by: '<S71>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_b
                                       //  Referenced by: '<S71>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_m5
                                       //  Referenced by: '<S71>/Gain'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_b
                                       //  Referenced by: '<S74>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_cx
                                       //  Referenced by: '<S72>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_o
                                       //  Referenced by: '<S77>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_is
                                       //  Referenced by: '<S75>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_d
                                       //  Referenced by: '<S79>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_kd
                                       //  Referenced by: '<S78>/Constant'

    -0.5F,                             // Computed Parameter: Bias_Bias
                                       //  Referenced by: '<S80>/Bias'

    -0.1F,                             // Computed Parameter: DeadZone_Start_p
                                       //  Referenced by: '<S80>/Dead Zone'

    0.1F,                              // Computed Parameter: DeadZone_End_b
                                       //  Referenced by: '<S80>/Dead Zone'

    12.0F,                             // Computed Parameter: ScaleVel_Gain_a
                                       //  Referenced by: '<S80>/Scale Vel'

    20.0F,                             // Computed Parameter: FixFaultyBaro_UpperSat_d
                                       //  Referenced by: '<S80>/Fix Faulty Baro'

    -20.0F,                            // Computed Parameter: FixFaultyBaro_LowerSat_o
                                       //  Referenced by: '<S80>/Fix Faulty Baro'

    0.0025F,                           // Computed Parameter: Integrator_gainval_o
                                       //  Referenced by: '<S86>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_p4
                                       //  Referenced by: '<S86>/Integrator'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_f
                                       //  Referenced by: '<S87>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_n4
                                       //  Referenced by: '<S86>/Constant'

    0.9F,                              // Computed Parameter: LimitOutput_UpperSat_h
                                       //  Referenced by: '<S80>/Limit Output'

    0.2F,                              // Computed Parameter: LimitOutput_LowerSat_f
                                       //  Referenced by: '<S80>/Limit Output'

    -1.0F,                             // Computed Parameter: Gain2_Gain_j
                                       //  Referenced by: '<S10>/Gain2'

    0.0174532924F,                     // Computed Parameter: Gain1_Gain_k
                                       //  Referenced by: '<S98>/Gain1'

    0.0025F,                           // Computed Parameter: Integrator_gainval_dj
                                       //  Referenced by: '<S100>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_g2
                                       //  Referenced by: '<S100>/Integrator'

    0.0025F,                           // Computed Parameter: Integrator_gainval_iz
                                       //  Referenced by: '<S99>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_et
                                       //  Referenced by: '<S99>/Integrator'

    0.0025F,                           // Computed Parameter: Integrator_gainval_pk
                                       //  Referenced by: '<S95>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_c
                                       //  Referenced by: '<S95>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval_a
                                       //  Referenced by: '<S95>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC_e
                                       //  Referenced by: '<S95>/Filter'

    0.0025F,                           // Computed Parameter: Integrator_gainval_hs
                                       //  Referenced by: '<S92>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_b
                                       //  Referenced by: '<S92>/Integrator'

    0.0025F,                           // Computed Parameter: Filter_gainval_d
                                       //  Referenced by: '<S92>/Filter'

    0.0F,                              // Computed Parameter: Filter_IC_l
                                       //  Referenced by: '<S92>/Filter'

    0.0025F,                           // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                       //  Referenced by: '<S85>/Discrete-Time Integrator'

    0.0025F,                           // Computed Parameter: Integrator_gainval_mt
                                       //  Referenced by: '<S104>/Integrator'

    0.0F,                              // Computed Parameter: Integrator_IC_g4
                                       //  Referenced by: '<S104>/Integrator'

    1100.0F,                           // Computed Parameter: Constant_Value_l
                                       //  Referenced by: '<S88>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_p
                                       //  Referenced by: '<S88>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_it
                                       //  Referenced by: '<S88>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_oa
                                       //  Referenced by: '<S88>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_bv
                                       //  Referenced by: '<S89>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_e
                                       //  Referenced by: '<S89>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_l
                                       //  Referenced by: '<S89>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_hh
                                       //  Referenced by: '<S89>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_f
                                       //  Referenced by: '<S90>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_lo
                                       //  Referenced by: '<S90>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_gb
                                       //  Referenced by: '<S90>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_do
                                       //  Referenced by: '<S90>/Gain'

    1100.0F,                           // Computed Parameter: Constant_Value_d3
                                       //  Referenced by: '<S91>/Constant'

    1.0F,                              // Computed Parameter: Limit3_UpperSat_i
                                       //  Referenced by: '<S91>/Limit3'

    0.0F,                              // Computed Parameter: Limit3_LowerSat_d4
                                       //  Referenced by: '<S91>/Limit3'

    800.0F,                            // Computed Parameter: Gain_Gain_bo
                                       //  Referenced by: '<S91>/Gain'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_fc
                                       //  Referenced by: '<S94>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_pd
                                       //  Referenced by: '<S92>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_bv
                                       //  Referenced by: '<S97>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_em
                                       //  Referenced by: '<S95>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_ph
                                       //  Referenced by: '<S101>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_gz
                                       //  Referenced by: '<S99>/Constant'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_em
                                       //  Referenced by: '<S102>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_fy
                                       //  Referenced by: '<S100>/Constant'

    -0.1F,                             // Computed Parameter: DeadZone_Start_b
                                       //  Referenced by: '<S85>/Dead Zone'

    0.1F,                              // Computed Parameter: DeadZone_End_p
                                       //  Referenced by: '<S85>/Dead Zone'

    0.0F,                              // Computed Parameter: ZeroGain_Gain_ei
                                       //  Referenced by: '<S106>/ZeroGain'

    0.0F,                              // Computed Parameter: Constant_Value_fi
                                       //  Referenced by: '<S104>/Constant'

    90.0F,                             // Computed Parameter: Scaleroll2_Gain_m
                                       //  Referenced by: '<S85>/Scale roll2'

    0.0F,                              // Computed Parameter: Delay_InitialCondition
                                       //  Referenced by: '<S2>/Delay'

    0.0F,                              // Computed Parameter: DiscreteFIRFilter_InitialStates
                                       //  Referenced by: '<S2>/Discrete FIR Filter'

    4.0F,                              // Computed Parameter: Gain_Gain_f1
                                       //  Referenced by: '<S2>/Gain'

    1024.0F,                           // Computed Parameter: Constant3_Value_b
                                       //  Referenced by: '<S5>/Constant3'

    -0.00147929F,                      // Computed Parameter: Gain3_Gain_f
                                       //  Referenced by: '<S5>/Gain3'

    1.0F,                              // Computed Parameter: Saturation3_UpperSat
                                       //  Referenced by: '<S5>/Saturation3'

    -1.0F,                             // Computed Parameter: Saturation3_LowerSat
                                       //  Referenced by: '<S5>/Saturation3'

    350.0F,                            // Computed Parameter: Constant_Value_pb
                                       //  Referenced by: '<S5>/Constant'

    1024.0F,                           // Computed Parameter: Constant1_Value_g
                                       //  Referenced by: '<S5>/Constant1'

    1024.0F,                           // Computed Parameter: Constant2_Value_c
                                       //  Referenced by: '<S5>/Constant2'

    0.000740740739F,                   // Computed Parameter: Gain_Gain_g
                                       //  Referenced by: '<S5>/Gain'

    -0.00147929F,                      // Computed Parameter: Gain1_Gain_b
                                       //  Referenced by: '<S5>/Gain1'

    -0.00147929F,                      // Computed Parameter: Gain2_Gain_k
                                       //  Referenced by: '<S5>/Gain2'

    1.0F,                              // Computed Parameter: Saturation_UpperSat
                                       //  Referenced by: '<S5>/Saturation'

    0.0F,                              // Computed Parameter: Saturation_LowerSat
                                       //  Referenced by: '<S5>/Saturation'

    1.0F,                              // Computed Parameter: Saturation1_UpperSat
                                       //  Referenced by: '<S5>/Saturation1'

    -1.0F,                             // Computed Parameter: Saturation1_LowerSat
                                       //  Referenced by: '<S5>/Saturation1'

    1.0F,                              // Computed Parameter: Saturation2_UpperSat
                                       //  Referenced by: '<S5>/Saturation2'

    -1.0F,                             // Computed Parameter: Saturation2_LowerSat
                                       //  Referenced by: '<S5>/Saturation2'

    16.5F,                             // Computed Parameter: Saturation_UpperSat_o
                                       //  Referenced by: '<S11>/Saturation'

    14.0F,                             // Computed Parameter: Saturation_LowerSat_k
                                       //  Referenced by: '<S11>/Saturation'


    //  Computed Parameter: Polynomial_Coefs
    //  Referenced by: '<S11>/Polynomial'

    { -20.2357502F, 666.277588F, -5384.2915F },
    100.0F,                            // Computed Parameter: Saturation1_UpperSat_o
                                       //  Referenced by: '<S11>/Saturation1'

    0.0F,                              // Computed Parameter: Saturation1_LowerSat_o
                                       //  Referenced by: '<S11>/Saturation1'

    100U                               // Computed Parameter: Delay_DelayLength
                                       //  Referenced by: '<S2>/Delay'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  Ctrl_P = Ctrl_P_temp;
}

// Destructor
CtrlModelClass::~CtrlModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Ctrl_T * CtrlModelClass::getRTM()
{
  return (&Ctrl_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
