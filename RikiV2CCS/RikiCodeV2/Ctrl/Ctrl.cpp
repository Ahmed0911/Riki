//
// File: Ctrl.cpp
//
// Code generated for Simulink model 'Ctrl'.
//
// Model version                  : 2.28
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Nov 29 15:57:45 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Texas Instruments->TMS470
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Ctrl.h"
#include "Ctrl_private.h"

// Named constants for Chart: '<S1>/Chart'
const uint8_T Ctrl_IN_AutoMode = 1U;
const uint8_T Ctrl_IN_End = 1U;
const uint8_T Ctrl_IN_GotoWaypoint = 2U;
const uint8_T Ctrl_IN_GreenOff = 1U;
const uint8_T Ctrl_IN_GreenOn = 2U;
const uint8_T Ctrl_IN_Idle = 3U;
const uint8_T Ctrl_IN_InitOrbitBezSecera = 4U;
const uint8_T Ctrl_IN_InitSegment = 5U;
const uint8_T Ctrl_IN_ManualMode = 2U;
const uint8_T Ctrl_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T Ctrl_IN_NextWaypoint = 6U;
const uint8_T Ctrl_IN_Off = 1U;
const uint8_T Ctrl_IN_On = 2U;
const uint8_T Ctrl_IN_Orbit = 7U;
const uint8_T Ctrl_IN_RateMode = 3U;
const uint8_T Ctrl_IN_RedOff = 1U;
const uint8_T Ctrl_IN_RedOn = 2U;
const uint8_T Ctrl_IN_RollPitchMode = 4U;
const uint8_T Ctrl_IN_VelocityMode = 5U;
const real32_T Ctrl_Ts = 0.0025F;

// Exported block parameters
real32_T AltKp = 0.03F;                // Variable: AltKp
                                          //  Referenced by: '<S108>/Proportional Gain'

real32_T AltRateBias = 0.65F;          // Variable: AltRateBias
                                          //  Referenced by:
                                          //    '<S13>/Bias1'
                                          //    '<S1052>/Bias1'

real32_T AltRateKi = 0.01F;            // Variable: AltRateKi
                                          //  Referenced by:
                                          //    '<S52>/Integral Gain'
                                          //    '<S1089>/Integral Gain'

real32_T AltRateKp = 0.1F;             // Variable: AltRateKp
                                          //  Referenced by:
                                          //    '<S60>/Proportional Gain'
                                          //    '<S1097>/Proportional Gain'

real32_T PosKp = 0.1F;                 // Variable: PosKp
                                          //  Referenced by:
                                          //    '<S262>/Proportional Gain'
                                          //    '<S310>/Proportional Gain'

real32_T RollPitchKp = 10.0F;          // Variable: RollPitchKp
                                          //  Referenced by:
                                          //    '<S212>/Proportional Gain'
                                          //    '<S410>/Proportional Gain'
                                          //    '<S889>/Proportional Gain'
                                          //    '<S989>/Proportional Gain'
                                          //    '<S1201>/Proportional Gain'
                                          //    '<S1301>/Proportional Gain'

real32_T RollPitchMax = 30.0F;         // Variable: RollPitchMax
                                          //  Referenced by:
                                          //    '<S15>/Scale roll1'
                                          //    '<S17>/Scale roll2'
                                          //    '<S794>/Scale roll1'
                                          //    '<S795>/Scale roll2'
                                          //    '<S1054>/Scale roll1'
                                          //    '<S1055>/Scale roll2'

real32_T RollPitchRateKd = 5.0E-5F;    // Variable: RollPitchRateKd
                                          //  Referenced by:
                                          //    '<S153>/Derivative Gain'
                                          //    '<S351>/Derivative Gain'
                                          //    '<S668>/Derivative Gain'
                                          //    '<S719>/Derivative Gain'
                                          //    '<S830>/Derivative Gain'
                                          //    '<S930>/Derivative Gain'
                                          //    '<S1142>/Derivative Gain'
                                          //    '<S1242>/Derivative Gain'

real32_T RollPitchRateKi = 0.002F;     // Variable: RollPitchRateKi
                                          //  Referenced by:
                                          //    '<S156>/Integral Gain'
                                          //    '<S354>/Integral Gain'
                                          //    '<S671>/Integral Gain'
                                          //    '<S722>/Integral Gain'
                                          //    '<S833>/Integral Gain'
                                          //    '<S933>/Integral Gain'
                                          //    '<S1145>/Integral Gain'
                                          //    '<S1245>/Integral Gain'

real32_T RollPitchRateKp = 0.0007F;    // Variable: RollPitchRateKp
                                          //  Referenced by:
                                          //    '<S164>/Proportional Gain'
                                          //    '<S362>/Proportional Gain'
                                          //    '<S679>/Proportional Gain'
                                          //    '<S730>/Proportional Gain'
                                          //    '<S841>/Proportional Gain'
                                          //    '<S941>/Proportional Gain'
                                          //    '<S1153>/Proportional Gain'
                                          //    '<S1253>/Proportional Gain'

real32_T RollPitchRateMax = 200.0F;    // Variable: RollPitchRateMax
                                          //  Referenced by:
                                          //    '<S633>/Scale roll2'
                                          //    '<S634>/Scale roll2'
                                          //    '<S214>/Saturation'
                                          //    '<S412>/Saturation'
                                          //    '<S891>/Saturation'
                                          //    '<S991>/Saturation'
                                          //    '<S1203>/Saturation'
                                          //    '<S1303>/Saturation'

real32_T VelKi = 0.02F;                // Variable: VelKi
                                          //  Referenced by:
                                          //    '<S455>/Integral Gain'
                                          //    '<S505>/Integral Gain'
                                          //    '<S1346>/Integral Gain'
                                          //    '<S1396>/Integral Gain'

real32_T VelKp = 0.15F;                // Variable: VelKp
                                          //  Referenced by:
                                          //    '<S463>/Proportional Gain'
                                          //    '<S513>/Proportional Gain'
                                          //    '<S1354>/Proportional Gain'
                                          //    '<S1404>/Proportional Gain'

real32_T VelMax = 6.0F;                // Variable: VelMax
                                          //  Referenced by:
                                          //    '<S18>/Gain'
                                          //    '<S18>/Gain1'
                                          //    '<S1056>/Gain'
                                          //    '<S1056>/Gain1'

real32_T YawKp = 3.0F;                 // Variable: YawKp
                                          //  Referenced by:
                                          //    '<S615>/Proportional Gain'
                                          //    '<S1505>/Proportional Gain'

real32_T YawRateKi = 0.000213867097F;  // Variable: YawRateKi
                                          //  Referenced by:
                                          //    '<S559>/Integral Gain'
                                          //    '<S773>/Integral Gain'
                                          //    '<S1032>/Integral Gain'
                                          //    '<S1449>/Integral Gain'

real32_T YawRateKp = 0.00321759842F;   // Variable: YawRateKp
                                          //  Referenced by:
                                          //    '<S567>/Proportional Gain'
                                          //    '<S781>/Proportional Gain'
                                          //    '<S1040>/Proportional Gain'
                                          //    '<S1457>/Proportional Gain'

real32_T YawRateMax = 180.0F;          // Variable: YawRateMax
                                          //  Referenced by:
                                          //    '<S635>/Scale roll2'
                                          //    '<S796>/Scale roll2'
                                          //    '<S617>/Saturation'
                                          //    '<S1507>/Saturation'


//
// Output and update for atomic system:
//    '<S19>/Correct Yaw1'
//    '<S1057>/Correct Yaw1'
//
void CtrlModelClass::Ctrl_CorrectYaw1(real32_T rtu_u, B_CorrectYaw1_Ctrl_T
  *localB)
{
  // MATLAB Function 'Ctrl/AutoCtrl/Yaw Controller/Correct Yaw1': '<S525>:1'
  // '<S525>:1:3'
  if (rtu_u == 0.0F) {
    localB->y = 0.0F;
  } else {
    localB->y = static_cast<real32_T>(fmod(static_cast<real_T>(rtu_u), 360.0));
    if (localB->y == 0.0F) {
      localB->y = 0.0F;
    } else {
      if (rtu_u < 0.0F) {
        localB->y += 360.0F;
      }
    }
  }

  if (localB->y > 180.0F) {
    // '<S525>:1:4'
    // '<S525>:1:5'
    localB->y -= 360.0F;
  }
}

// Function for Chart: '<S1>/Chart'
void CtrlModelClass::Ctrl_SelectMode(void)
{
  // Outport: '<Root>/ActualMode' incorporates:
  //   Inport: '<Root>/ModeCode'

  // MATLAB Function 'SelectMode': '<S4>:176'
  // Graphical Function 'SelectMode': '<S4>:176'
  // Transition: '<S4>:320'
  // '<S4>:315:1'
  if (Ctrl_Y.ActualMode > 10) {
    // Transition: '<S4>:315'
    // Transition: '<S4>:317'
    // Transition: '<S4>:231'
    // Transition: '<S4>:232'
    // Transition: '<S4>:234'
    // Transition: '<S4>:235'
  } else {
    // Transition: '<S4>:321'
    if ((Ctrl_U.Thr < 400.0F) && (Ctrl_DW.Mode != 5)) {
      // '<S4>:186:1'
      // Transition: '<S4>:186'
      // Transition: '<S4>:185'
      // '<S4>:185:1'
      Ctrl_DW.Mode = 0U;

      // Transition: '<S4>:231'
      // Transition: '<S4>:232'
      // Transition: '<S4>:234'
      // Transition: '<S4>:235'
    } else {
      // Transition: '<S4>:224'
      // '<S4>:184:1'
      if (Ctrl_U.Mode < 600U) {
        // Transition: '<S4>:184'
        // Transition: '<S4>:227'
        // '<S4>:227:1'
        Ctrl_DW.Mode = Ctrl_U.ModeCode;

        // Transition: '<S4>:232'
        // Transition: '<S4>:234'
        // Transition: '<S4>:235'
      } else {
        // Transition: '<S4>:223'
        // '<S4>:219:1'
        if (Ctrl_U.Mode < 1300U) {
          // Transition: '<S4>:219'
          // Transition: '<S4>:229'
          // '<S4>:229:1'
          Ctrl_DW.Mode = 4U;

          // Transition: '<S4>:234'
          // Transition: '<S4>:235'
        } else {
          // Transition: '<S4>:230'
          // '<S4>:230:1'
          Ctrl_DW.Mode = 5U;
        }
      }
    }
  }

  // End of Outport: '<Root>/ActualMode'
  // Transition: '<S4>:183'
}

// Function for Chart: '<S1>/Chart'
void CtrlModelClass::Ctrl_CalculateTrajSegment(uint8_T index1, uint8_T index2,
  real32_T velocity)
{
  real32_T absxk;
  real32_T dPLen;
  real32_T scale;
  real32_T t;

  // MATLAB Function 'CalculateTrajSegment': '<S4>:300'
  // '<S4>:300:3'
  // '<S4>:300:2'
  // '<S4>:300:4'
  // '<S4>:300:5'
  scale = 1.29246971E-26F;

  // Inport: '<Root>/Waypoints'
  Ctrl_DW.P1[0] = Ctrl_U.Waypoints[index1 - 1];
  Ctrl_DW.dPdT[0] = Ctrl_U.Waypoints[index2 - 1] - Ctrl_DW.P1[0];
  absxk = static_cast<real32_T>(fabs(static_cast<real_T>(Ctrl_DW.dPdT[0])));
  if (absxk > 1.29246971E-26F) {
    dPLen = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    dPLen = t * t;
  }

  // Inport: '<Root>/Waypoints'
  Ctrl_DW.P1[1] = Ctrl_U.Waypoints[index1 + 8];
  Ctrl_DW.dPdT[1] = Ctrl_U.Waypoints[index2 + 8] - Ctrl_DW.P1[1];
  absxk = static_cast<real32_T>(fabs(static_cast<real_T>(Ctrl_DW.dPdT[1])));
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
  absxk = static_cast<real32_T>(fabs(static_cast<real_T>(Ctrl_DW.dPdT[2])));
  if (absxk > scale) {
    t = scale / absxk;
    dPLen = dPLen * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    dPLen += t * t;
  }

  dPLen = scale * static_cast<real32_T>(sqrt(static_cast<real_T>(dPLen)));

  // '<S4>:300:6'
  Ctrl_DW.Ttotal = dPLen / velocity;

  // '<S4>:300:7'
  Ctrl_DW.dPdT[0] /= Ctrl_DW.Ttotal;
  Ctrl_DW.dPdT[1] /= Ctrl_DW.Ttotal;
  Ctrl_DW.dPdT[2] /= Ctrl_DW.Ttotal;
}

// Model step function
void CtrlModelClass::step()
{
  int32_T tmp_0;
  int32_T tmp_1;
  real32_T rtb_DeadZone_f;
  real32_T rtb_FilterCoefficient_od;
  real32_T rtb_Gain;
  real32_T rtb_IntegralGain_a;
  real32_T rtb_IntegralGain_c;
  real32_T rtb_IntegralGain_p;
  real32_T rtb_Integrator;
  real32_T rtb_Integrator_b;
  real32_T rtb_Integrator_i;
  real32_T rtb_Integrator_j;
  real32_T rtb_Integrator_m;
  real32_T rtb_Limit3_c;
  real32_T rtb_Polynomial;
  real32_T rtb_Rudder;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_SignPreSat;
  real32_T rtb_SignPreSat_f;
  real32_T rtb_SignPreSat_iz;
  real32_T rtb_SignPreSat_n;
  real32_T rtb_Switch_o;
  real32_T rtb_ZeroGain_m4;
  real32_T tmp;
  boolean_T rtb_NotEqual_e1;
  boolean_T rtb_NotEqual_el;
  boolean_T rtb_NotEqual_j;
  boolean_T rtb_NotEqual_kp;
  boolean_T rtb_NotEqual_pr;

  // Outputs for Atomic SubSystem: '<Root>/Ctrl'
  // Gain: '<S12>/Gain' incorporates:
  //   Inport: '<Root>/FlatVe'

  rtb_Gain = Ctrl_P.Gain_Gain_n * Ctrl_U.FlatVe[2];

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

  // Chart: '<S1>/Chart' incorporates:
  //   Inport: '<Root>/ExecuteWaypoints'
  //   Inport: '<Root>/FlatXe'
  //   Inport: '<Root>/TrajZNEVParams'
  //   Inport: '<Root>/WayCnt'
  //   Inport: '<Root>/Waypoints'
  //   Outport: '<Root>/LEDs'
  //   SignalConversion generated from: '<S4>/ SFunction '

  // Gateway: Ctrl/Chart
  if (Ctrl_DW.temporalCounter_i1 < 1023U) {
    Ctrl_DW.temporalCounter_i1 = static_cast<uint16_T>
      (Ctrl_DW.temporalCounter_i1 + 1U);
  }

  if (Ctrl_DW.temporalCounter_i2 < 127U) {
    Ctrl_DW.temporalCounter_i2 = static_cast<uint8_T>(Ctrl_DW.temporalCounter_i2
      + 1U);
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
    Ctrl_Y.LEDs[1] = false;
    Ctrl_Y.LEDs[2] = false;

    // Entry Internal 'Off': '<S4>:192'
    // Transition: '<S4>:199'
    Ctrl_DW.is_Off = Ctrl_IN_RedOn;
    Ctrl_DW.temporalCounter_i2 = 0U;

    // Entry 'RedOn': '<S4>:197'
    Ctrl_Y.LEDs[0] = true;
  } else {
    // During 'SystemLogic': '<S4>:12'
    Ctrl_SelectMode();
    if (Ctrl_DW.is_SystemLogic == 1) {
      // During 'Off': '<S4>:14'
      if (Ctrl_DW.Mode == 1) {
        // Transition: '<S4>:17'
        Ctrl_B.Off = false;
        Ctrl_DW.is_SystemLogic = Ctrl_IN_On;

        // Entry 'On': '<S4>:143'
        Ctrl_DW.ModeOld = Ctrl_DW.Mode;
        Ctrl_DW.is_On = Ctrl_IN_ManualMode;
        Ctrl_B.ManualMode = true;

        // Outport: '<Root>/ActualMode'
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

        // Outport: '<Root>/ActualMode'
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

        // Outport: '<Root>/ActualMode'
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

        // Outport: '<Root>/ActualMode'
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

          // Entry 'AutoMode': '<S4>:283'
          // Entry Internal 'AutoMode': '<S4>:283'
          // Transition: '<S4>:286'
          Ctrl_DW.is_AutoMode = Ctrl_IN_Idle;

          // Entry 'Idle': '<S4>:301'
          Ctrl_DW.wayIndex = 1U;

          // Outport: '<Root>/ActualMode'
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
        Ctrl_B.ManualMode = false;
        Ctrl_B.RateMode = false;
        Ctrl_B.RollPitchMode = false;
        Ctrl_B.VelocityMode = false;
        Ctrl_DW.is_On = Ctrl_IN_NO_ACTIVE_CHILD;
        Ctrl_DW.is_SystemLogic = Ctrl_IN_Off;
        Ctrl_B.Off = true;

        // Outport: '<Root>/ActualMode'
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

            // Outport: '<Root>/ActualMode'
            Ctrl_Y.ActualMode = 5U;
            break;

           case Ctrl_IN_GotoWaypoint:
            // During 'GotoWaypoint': '<S4>:302'
            if (Ctrl_DW.Time > Ctrl_DW.Ttotal) {
              // Transition: '<S4>:290'
              Ctrl_DW.is_AutoMode = Ctrl_IN_NextWaypoint;
              Ctrl_DW.temporalCounter_i1 = 0U;

              // Entry 'NextWaypoint': '<S4>:304'
              tmp_0 = static_cast<int32_T>(Ctrl_DW.wayIndex + 1U);
              if (Ctrl_DW.wayIndex + 1U > 255U) {
                tmp_0 = 255;
              }

              Ctrl_DW.wayIndex = static_cast<uint8_T>(tmp_0);
            } else if (Ctrl_U.ExecuteWaypoints == 10U) {
              // Transition: '<S4>:322'
              Ctrl_DW.is_AutoMode = Ctrl_IN_Idle;

              // Entry 'Idle': '<S4>:301'
              Ctrl_DW.wayIndex = 1U;

              // Outport: '<Root>/ActualMode'
              Ctrl_Y.ActualMode = 5U;
            } else {
              Ctrl_B.AutoRef[0] = Ctrl_DW.dPdT[0] * Ctrl_DW.Time + Ctrl_DW.P1[0];
              Ctrl_B.AutoRef[1] = Ctrl_DW.dPdT[1] * Ctrl_DW.Time + Ctrl_DW.P1[1];
              Ctrl_B.AutoRef[2] = Ctrl_DW.dPdT[2] * Ctrl_DW.Time + Ctrl_DW.P1[2];
              Ctrl_DW.Time += Ctrl_Ts;
            }
            break;

           case Ctrl_IN_Idle:
            // During 'Idle': '<S4>:301'
            if ((Ctrl_U.ExecuteWaypoints == 1U) && (Ctrl_U.WayCnt > 0)) {
              // Transition: '<S4>:287'
              Ctrl_DW.is_AutoMode = Ctrl_IN_InitSegment;

              // Entry 'InitSegment': '<S4>:296'
              tmp_0 = static_cast<int32_T>(Ctrl_DW.wayIndex + 10U);
              if (Ctrl_DW.wayIndex + 10U > 255U) {
                tmp_0 = 255;
              }

              // Outport: '<Root>/ActualMode'
              Ctrl_Y.ActualMode = static_cast<uint8_T>(tmp_0);
              tmp_0 = static_cast<int32_T>(Ctrl_DW.wayIndex + 1U);
              if (Ctrl_DW.wayIndex + 1U > 255U) {
                tmp_0 = 255;
              }

              Ctrl_CalculateTrajSegment(Ctrl_DW.wayIndex, static_cast<uint8_T>
                (tmp_0), Ctrl_U.TrajZNEVParams[3]);
              Ctrl_DW.Time = 0.0F;
              tmp_0 = static_cast<int32_T>(Ctrl_DW.wayIndex + 1U);
              if (Ctrl_DW.wayIndex + 1U > 255U) {
                tmp_0 = 255;
              }

              tmp_1 = static_cast<int32_T>(Ctrl_DW.wayIndex + 1U);
              if (Ctrl_DW.wayIndex + 1U > 255U) {
                tmp_1 = 255;
              }

              Ctrl_B.AutoRefAng = static_cast<real32_T>(atan2(static_cast<real_T>
                (Ctrl_U.Waypoints[tmp_0 + 17] -
                 Ctrl_U.Waypoints[Ctrl_DW.wayIndex + 17]), static_cast<real_T>
                (Ctrl_U.Waypoints[tmp_1 + 8] - Ctrl_U.Waypoints[Ctrl_DW.wayIndex
                 + 8])));
            } else if (Ctrl_U.ExecuteWaypoints == 2U) {
              // Transition: '<S4>:289'
              Ctrl_DW.is_AutoMode = Ctrl_IN_InitOrbitBezSecera;

              // Entry 'InitOrbitBezSecera': '<S4>:306'
              rtb_IntegralGain_a = Ctrl_U.FlatXe[0] - Ctrl_U.TrajZNEVParams[1];
              rtb_IntegralGain_p = Ctrl_U.FlatXe[1] - Ctrl_U.TrajZNEVParams[2];
              Ctrl_DW.OrbRadius = rtb_IntegralGain_a * rtb_IntegralGain_a +
                rtb_IntegralGain_p * rtb_IntegralGain_p;
              Ctrl_DW.OrbRadius = static_cast<real32_T>(sqrt(static_cast<real_T>
                (Ctrl_DW.OrbRadius)));
              Ctrl_DW.OrbPhi = static_cast<real32_T>(atan2(static_cast<real_T>
                (rtb_IntegralGain_p), static_cast<real_T>(rtb_IntegralGain_a)));
              Ctrl_DW.OrbdPhidT = Ctrl_U.TrajZNEVParams[3] / Ctrl_DW.OrbRadius;
            } else {
              Ctrl_B.AutoRef[0] = Ctrl_U.Waypoints[0];
              Ctrl_B.AutoRef[1] = Ctrl_U.Waypoints[9];
              Ctrl_B.AutoRef[2] = Ctrl_U.Waypoints[18];
              Ctrl_B.AutoRefAng = -2000.0F;
            }
            break;

           case Ctrl_IN_InitOrbitBezSecera:
            // During 'InitOrbitBezSecera': '<S4>:306'
            // Transition: '<S4>:295'
            Ctrl_DW.is_AutoMode = Ctrl_IN_Orbit;

            // Entry 'Orbit': '<S4>:305'
            break;

           case Ctrl_IN_InitSegment:
            // During 'InitSegment': '<S4>:296'
            // Transition: '<S4>:288'
            Ctrl_DW.is_AutoMode = Ctrl_IN_GotoWaypoint;

            // Entry 'GotoWaypoint': '<S4>:302'
            break;

           case Ctrl_IN_NextWaypoint:
            // During 'NextWaypoint': '<S4>:304'
            if (Ctrl_DW.temporalCounter_i1 >= 1000) {
              // Transition: '<S4>:294'
              if (Ctrl_DW.wayIndex > Ctrl_U.WayCnt) {
                // Transition: '<S4>:293'
                Ctrl_DW.is_AutoMode = Ctrl_IN_End;
              } else {
                // Transition: '<S4>:313'
                Ctrl_DW.is_AutoMode = Ctrl_IN_InitSegment;

                // Entry 'InitSegment': '<S4>:296'
                tmp_0 = static_cast<int32_T>(Ctrl_DW.wayIndex + 10U);
                if (Ctrl_DW.wayIndex + 10U > 255U) {
                  tmp_0 = 255;
                }

                // Outport: '<Root>/ActualMode'
                Ctrl_Y.ActualMode = static_cast<uint8_T>(tmp_0);
                tmp_0 = static_cast<int32_T>(Ctrl_DW.wayIndex + 1U);
                if (Ctrl_DW.wayIndex + 1U > 255U) {
                  tmp_0 = 255;
                }

                Ctrl_CalculateTrajSegment(Ctrl_DW.wayIndex, static_cast<uint8_T>
                  (tmp_0), Ctrl_U.TrajZNEVParams[3]);
                Ctrl_DW.Time = 0.0F;
                tmp_0 = static_cast<int32_T>(Ctrl_DW.wayIndex + 1U);
                if (Ctrl_DW.wayIndex + 1U > 255U) {
                  tmp_0 = 255;
                }

                tmp_1 = static_cast<int32_T>(Ctrl_DW.wayIndex + 1U);
                if (Ctrl_DW.wayIndex + 1U > 255U) {
                  tmp_1 = 255;
                }

                Ctrl_B.AutoRefAng = static_cast<real32_T>(atan2
                  (static_cast<real_T>(Ctrl_U.Waypoints[tmp_0 + 17] -
                  Ctrl_U.Waypoints[Ctrl_DW.wayIndex + 17]), static_cast<real_T>
                   (Ctrl_U.Waypoints[tmp_1 + 8] -
                    Ctrl_U.Waypoints[Ctrl_DW.wayIndex + 8])));
              }
            }
            break;

           default:
            // During 'Orbit': '<S4>:305'
            Ctrl_B.AutoRef[0] = Ctrl_U.TrajZNEVParams[0];
            Ctrl_B.AutoRef[1] = static_cast<real32_T>(cos(static_cast<real_T>
              (Ctrl_DW.OrbPhi))) * Ctrl_DW.OrbRadius + Ctrl_U.TrajZNEVParams[1];
            Ctrl_B.AutoRef[2] = static_cast<real32_T>(sin(static_cast<real_T>
              (Ctrl_DW.OrbPhi))) * Ctrl_DW.OrbRadius + Ctrl_U.TrajZNEVParams[2];
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

    // During 'LEDs': '<S4>:191'
    if (Ctrl_DW.is_LEDs == 1) {
      // During 'Off': '<S4>:192'
      if (Ctrl_DW.is_SystemLogic == 2) {
        // Transition: '<S4>:195'
        // Exit Internal 'Off': '<S4>:192'
        Ctrl_DW.is_Off = Ctrl_IN_NO_ACTIVE_CHILD;
        Ctrl_DW.is_LEDs = Ctrl_IN_On;

        // Entry 'On': '<S4>:193'
        Ctrl_Y.LEDs[0] = false;
        Ctrl_Y.LEDs[2] = false;

        // Entry Internal 'On': '<S4>:193'
        // Transition: '<S4>:203'
        Ctrl_DW.is_On_e = Ctrl_IN_GreenOn;
        Ctrl_DW.temporalCounter_i2 = 0U;

        // Entry 'GreenOn': '<S4>:206'
        Ctrl_Y.LEDs[1] = true;
      } else if (Ctrl_DW.is_Off == 1) {
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
      if (Ctrl_DW.is_SystemLogic == 1) {
        // Transition: '<S4>:196'
        // Exit Internal 'On': '<S4>:193'
        Ctrl_DW.is_On_e = Ctrl_IN_NO_ACTIVE_CHILD;
        Ctrl_DW.is_LEDs = Ctrl_IN_Off;

        // Entry 'Off': '<S4>:192'
        Ctrl_Y.LEDs[1] = false;
        Ctrl_Y.LEDs[2] = false;

        // Entry Internal 'Off': '<S4>:192'
        // Transition: '<S4>:199'
        Ctrl_DW.is_Off = Ctrl_IN_RedOn;
        Ctrl_DW.temporalCounter_i2 = 0U;

        // Entry 'RedOn': '<S4>:197'
        Ctrl_Y.LEDs[0] = true;
      } else if (Ctrl_DW.is_On_e == 1) {
        // During 'GreenOff': '<S4>:205'
        if (Ctrl_DW.temporalCounter_i2 >= 100) {
          // Transition: '<S4>:204'
          Ctrl_DW.is_On_e = Ctrl_IN_GreenOn;
          Ctrl_DW.temporalCounter_i2 = 0U;

          // Entry 'GreenOn': '<S4>:206'
          Ctrl_Y.LEDs[1] = true;
        }
      } else {
        // During 'GreenOn': '<S4>:206'
        if (Ctrl_DW.temporalCounter_i2 >= 100) {
          // Transition: '<S4>:202'
          Ctrl_DW.is_On_e = Ctrl_IN_GreenOff;
          Ctrl_DW.temporalCounter_i2 = 0U;

          // Entry 'GreenOff': '<S4>:205'
          Ctrl_Y.LEDs[1] = false;
        }
      }
    }
  }

  // End of Chart: '<S1>/Chart'

  // Outputs for Enabled SubSystem: '<S1>/AutoCtrl' incorporates:
  //   EnablePort: '<S3>/Enable'

  if (Ctrl_B.AutoMode) {
    if (!Ctrl_DW.AutoCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S55>/Integrator'
      Ctrl_DW.Integrator_DSTATE_k = Ctrl_P.DiscretePIDController1_InitialC;

      // InitializeConditions for DiscreteIntegrator: '<S508>/Integrator'
      Ctrl_DW.Integrator_DSTATE_l = Ctrl_P.DiscretePIDController2_InitialC;

      // InitializeConditions for DiscreteIntegrator: '<S458>/Integrator'
      Ctrl_DW.Integrator_DSTATE_lw = Ctrl_P.DiscretePIDController1_Initia_k;

      // InitializeConditions for DiscreteIntegrator: '<S357>/Integrator'
      Ctrl_DW.Integrator_DSTATE_gj = Ctrl_P.DiscretePIDController_Initia_cd;

      // InitializeConditions for DiscreteIntegrator: '<S352>/Filter'
      Ctrl_DW.Filter_DSTATE_a = Ctrl_P.DiscretePIDController_InitialCo;

      // InitializeConditions for DiscreteIntegrator: '<S159>/Integrator'
      Ctrl_DW.Integrator_DSTATE_c = Ctrl_P.DiscretePIDController_Initial_m;

      // InitializeConditions for DiscreteIntegrator: '<S154>/Filter'
      Ctrl_DW.Filter_DSTATE_e = Ctrl_P.DiscretePIDController_Initial_n;

      // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' 
      Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j = 1U;

      // InitializeConditions for DiscreteIntegrator: '<S562>/Integrator'
      Ctrl_DW.Integrator_DSTATE_mo = Ctrl_P.DiscretePIDController_Initia_c5;
      Ctrl_DW.AutoCtrl_MODE = true;
    }

    // Gain: '<S108>/Proportional Gain' incorporates:
    //   Inport: '<Root>/GPSHeight'
    //   Sum: '<S13>/Sum1'

    rtb_SignPreIntegrator = (Ctrl_B.AutoRef[0] - Ctrl_U.GPSHeight) * AltKp;

    // Saturate: '<S110>/Saturation'
    if (rtb_SignPreIntegrator > Ctrl_P.DiscretePIDController2_UpperSat) {
      rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController2_UpperSat;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController2_LowerSat) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController2_LowerSat;
      }
    }

    // End of Saturate: '<S110>/Saturation'

    // Gain: '<S13>/Scale Vel'
    Ctrl_B.VertVelRef5 = Ctrl_P.ScaleVel_Gain * rtb_SignPreIntegrator;

    // Saturate: '<S13>/Fix Faulty Baro'
    if (rtb_Gain > Ctrl_P.FixFaultyBaro_UpperSat) {
      rtb_Polynomial = Ctrl_P.FixFaultyBaro_UpperSat;
    } else if (rtb_Gain < Ctrl_P.FixFaultyBaro_LowerSat) {
      rtb_Polynomial = Ctrl_P.FixFaultyBaro_LowerSat;
    } else {
      rtb_Polynomial = rtb_Gain;
    }

    // End of Saturate: '<S13>/Fix Faulty Baro'

    // Sum: '<S13>/Sum3'
    rtb_DeadZone_f = Ctrl_B.VertVelRef5 - rtb_Polynomial;

    // Sum: '<S64>/Sum' incorporates:
    //   DiscreteIntegrator: '<S55>/Integrator'
    //   Gain: '<S60>/Proportional Gain'

    rtb_Limit3_c = AltRateKp * rtb_DeadZone_f + Ctrl_DW.Integrator_DSTATE_k;

    // Saturate: '<S62>/Saturation'
    if (rtb_Limit3_c > Ctrl_P.DiscretePIDController1_UpperSat) {
      rtb_SignPreSat_f = Ctrl_P.DiscretePIDController1_UpperSat;
    } else if (rtb_Limit3_c < Ctrl_P.DiscretePIDController1_LowerSat) {
      rtb_SignPreSat_f = Ctrl_P.DiscretePIDController1_LowerSat;
    } else {
      rtb_SignPreSat_f = rtb_Limit3_c;
    }

    // End of Saturate: '<S62>/Saturation'

    // Bias: '<S13>/Bias1'
    Ctrl_B.VertVelOut5 = rtb_SignPreSat_f + AltRateBias;

    // Gain: '<S46>/ZeroGain'
    rtb_ZeroGain_m4 = Ctrl_P.ZeroGain_Gain * rtb_Limit3_c;

    // DeadZone: '<S48>/DeadZone'
    if (rtb_Limit3_c > Ctrl_P.DiscretePIDController1_UpperSat) {
      rtb_Limit3_c -= Ctrl_P.DiscretePIDController1_UpperSat;
    } else if (rtb_Limit3_c >= Ctrl_P.DiscretePIDController1_LowerSat) {
      rtb_Limit3_c = 0.0F;
    } else {
      rtb_Limit3_c -= Ctrl_P.DiscretePIDController1_LowerSat;
    }

    // End of DeadZone: '<S48>/DeadZone'

    // RelationalOperator: '<S46>/NotEqual'
    rtb_NotEqual_e1 = (rtb_ZeroGain_m4 != rtb_Limit3_c);

    // Signum: '<S46>/SignPreSat'
    if (rtb_Limit3_c < 0.0F) {
      rtb_Limit3_c = -1.0F;
    } else {
      if (rtb_Limit3_c > 0.0F) {
        rtb_Limit3_c = 1.0F;
      }
    }

    // End of Signum: '<S46>/SignPreSat'

    // Gain: '<S52>/Integral Gain'
    rtb_DeadZone_f *= AltRateKi;

    // DataTypeConversion: '<S46>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_Limit3_c), 256.0));

    // Signum: '<S46>/SignPreIntegrator'
    if (rtb_DeadZone_f < 0.0F) {
      rtb_IntegralGain_a = -1.0F;
    } else if (rtb_DeadZone_f > 0.0F) {
      rtb_IntegralGain_a = 1.0F;
    } else {
      rtb_IntegralGain_a = rtb_DeadZone_f;
    }

    // End of Signum: '<S46>/SignPreIntegrator'

    // DataTypeConversion: '<S46>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_IntegralGain_a),
      256.0));

    // Switch: '<S46>/Switch' incorporates:
    //   Constant: '<S46>/Constant1'
    //   DataTypeConversion: '<S46>/DataTypeConv1'
    //   DataTypeConversion: '<S46>/DataTypeConv2'
    //   Logic: '<S46>/AND3'
    //   RelationalOperator: '<S46>/Equal1'

    if (rtb_NotEqual_e1 && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Switch_o = Ctrl_P.Constant1_Value;
    } else {
      rtb_Switch_o = rtb_DeadZone_f;
    }

    // End of Switch: '<S46>/Switch'

    // Saturate: '<S13>/Limit Output'
    if (Ctrl_B.VertVelOut5 > Ctrl_P.LimitOutput_UpperSat) {
      rtb_DeadZone_f = Ctrl_P.LimitOutput_UpperSat;
    } else if (Ctrl_B.VertVelOut5 < Ctrl_P.LimitOutput_LowerSat) {
      rtb_DeadZone_f = Ctrl_P.LimitOutput_LowerSat;
    } else {
      rtb_DeadZone_f = Ctrl_B.VertVelOut5;
    }

    // End of Saturate: '<S13>/Limit Output'

    // Gain: '<S310>/Proportional Gain' incorporates:
    //   Inport: '<Root>/FlatXe'
    //   Sum: '<S16>/Sum2'

    rtb_SignPreIntegrator = (Ctrl_B.AutoRef[1] - Ctrl_U.FlatXe[0]) * PosKp;

    // Saturate: '<S312>/Saturation'
    if (rtb_SignPreIntegrator > Ctrl_P.DiscretePIDController2_UpperS_o) {
      rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController2_UpperS_o;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController2_LowerS_e) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController2_LowerS_e;
      }
    }

    // End of Saturate: '<S312>/Saturation'

    // Sum: '<S18>/Sum2' incorporates:
    //   Gain: '<S18>/Gain'
    //   Inport: '<Root>/FlatVe'

    rtb_Limit3_c = VelMax * rtb_SignPreIntegrator - Ctrl_U.FlatVe[0];

    // Sum: '<S517>/Sum' incorporates:
    //   DiscreteIntegrator: '<S508>/Integrator'
    //   Gain: '<S513>/Proportional Gain'

    rtb_SignPreSat_f = VelKp * rtb_Limit3_c + Ctrl_DW.Integrator_DSTATE_l;

    // Saturate: '<S515>/Saturation'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController2_UpperS_d) {
      rtb_Integrator_b = Ctrl_P.DiscretePIDController2_UpperS_d;
    } else if (rtb_SignPreSat_f < Ctrl_P.DiscretePIDController2_LowerS_h) {
      rtb_Integrator_b = Ctrl_P.DiscretePIDController2_LowerS_h;
    } else {
      rtb_Integrator_b = rtb_SignPreSat_f;
    }

    // End of Saturate: '<S515>/Saturation'

    // Gain: '<S422>/Gain1' incorporates:
    //   Inport: '<Root>/RPY'

    rtb_IntegralGain_p = Ctrl_P.Gain1_Gain * Ctrl_U.RPY[2];

    // Trigonometry: '<S18>/Trigonometric Function'
    rtb_IntegralGain_c = static_cast<real32_T>(cos(static_cast<real_T>
      (rtb_IntegralGain_p)));
    rtb_IntegralGain_p = static_cast<real32_T>(sin(static_cast<real_T>
      (rtb_IntegralGain_p)));

    // Gain: '<S262>/Proportional Gain' incorporates:
    //   Inport: '<Root>/FlatXe'
    //   Sum: '<S16>/Sum1'

    rtb_SignPreIntegrator = (Ctrl_B.AutoRef[2] - Ctrl_U.FlatXe[1]) * PosKp;

    // Saturate: '<S264>/Saturation'
    if (rtb_SignPreIntegrator > Ctrl_P.DiscretePIDController1_UpperS_b) {
      rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController1_UpperS_b;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController1_LowerS_m) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController1_LowerS_m;
      }
    }

    // End of Saturate: '<S264>/Saturation'

    // Sum: '<S18>/Sum1' incorporates:
    //   Gain: '<S18>/Gain1'
    //   Inport: '<Root>/FlatVe'

    rtb_SignPreSat_n = VelMax * rtb_SignPreIntegrator - Ctrl_U.FlatVe[1];

    // Sum: '<S467>/Sum' incorporates:
    //   DiscreteIntegrator: '<S458>/Integrator'
    //   Gain: '<S463>/Proportional Gain'

    rtb_Integrator_i = VelKp * rtb_SignPreSat_n + Ctrl_DW.Integrator_DSTATE_lw;

    // Saturate: '<S465>/Saturation'
    if (rtb_Integrator_i > Ctrl_P.DiscretePIDController1_UpperS_g) {
      rtb_ZeroGain_m4 = Ctrl_P.DiscretePIDController1_UpperS_g;
    } else if (rtb_Integrator_i < Ctrl_P.DiscretePIDController1_LowerS_p) {
      rtb_ZeroGain_m4 = Ctrl_P.DiscretePIDController1_LowerS_p;
    } else {
      rtb_ZeroGain_m4 = rtb_Integrator_i;
    }

    // End of Saturate: '<S465>/Saturation'

    // Gain: '<S410>/Proportional Gain' incorporates:
    //   Gain: '<S17>/Scale roll2'
    //   Inport: '<Root>/RPY'
    //   Product: '<S18>/Product2'
    //   Product: '<S18>/Product3'
    //   Sum: '<S17>/Sum3'
    //   Sum: '<S18>/Add1'
    //   Trigonometry: '<S18>/Trigonometric Function'

    rtb_SignPreIntegrator = ((rtb_IntegralGain_c * rtb_ZeroGain_m4 -
      rtb_Integrator_b * rtb_IntegralGain_p) * RollPitchMax - Ctrl_U.RPY[0]) *
      RollPitchKp;

    // Saturate: '<S412>/Saturation'
    if (rtb_SignPreIntegrator > RollPitchRateMax) {
      rtb_SignPreIntegrator = RollPitchRateMax;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController1_LowerS_g) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController1_LowerS_g;
      }
    }

    // End of Saturate: '<S412>/Saturation'

    // Sum: '<S17>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_a = rtb_SignPreIntegrator - Ctrl_U.dRPY[0];

    // Gain: '<S360>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S352>/Filter'
    //   Gain: '<S351>/Derivative Gain'
    //   Sum: '<S352>/SumD'

    rtb_FilterCoefficient_od = (RollPitchRateKd * rtb_IntegralGain_a -
      Ctrl_DW.Filter_DSTATE_a) * Ctrl_P.DiscretePIDController_N;

    // Sum: '<S366>/Sum' incorporates:
    //   DiscreteIntegrator: '<S357>/Integrator'
    //   Gain: '<S362>/Proportional Gain'

    rtb_SignPreSat = (RollPitchRateKp * rtb_IntegralGain_a +
                      Ctrl_DW.Integrator_DSTATE_gj) + rtb_FilterCoefficient_od;

    // Saturate: '<S364>/Saturation'
    if (rtb_SignPreSat > Ctrl_P.DiscretePIDController_UpperSatu) {
      rtb_Integrator_m = Ctrl_P.DiscretePIDController_UpperSatu;
    } else if (rtb_SignPreSat < Ctrl_P.DiscretePIDController_LowerSatu) {
      rtb_Integrator_m = Ctrl_P.DiscretePIDController_LowerSatu;
    } else {
      rtb_Integrator_m = rtb_SignPreSat;
    }

    // End of Saturate: '<S364>/Saturation'

    // Gain: '<S212>/Proportional Gain' incorporates:
    //   Gain: '<S15>/Scale roll1'
    //   Inport: '<Root>/RPY'
    //   Product: '<S18>/Product'
    //   Product: '<S18>/Product1'
    //   Sum: '<S15>/Sum3'
    //   Sum: '<S18>/Add'
    //   Trigonometry: '<S18>/Trigonometric Function'

    rtb_SignPreIntegrator = (((0.0F - rtb_Integrator_b * rtb_IntegralGain_c) -
      rtb_IntegralGain_p * rtb_ZeroGain_m4) * RollPitchMax - Ctrl_U.RPY[1]) *
      RollPitchKp;

    // Saturate: '<S214>/Saturation'
    if (rtb_SignPreIntegrator > RollPitchRateMax) {
      rtb_SignPreIntegrator = RollPitchRateMax;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController1_LowerS_n) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController1_LowerS_n;
      }
    }

    // End of Saturate: '<S214>/Saturation'

    // Sum: '<S15>/Sum1' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_Integrator_b = rtb_SignPreIntegrator - Ctrl_U.dRPY[1];

    // Gain: '<S162>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S154>/Filter'
    //   Gain: '<S153>/Derivative Gain'
    //   Sum: '<S154>/SumD'

    rtb_IntegralGain_p = (RollPitchRateKd * rtb_Integrator_b -
                          Ctrl_DW.Filter_DSTATE_e) *
      Ctrl_P.DiscretePIDController_N_h;

    // Sum: '<S168>/Sum' incorporates:
    //   DiscreteIntegrator: '<S159>/Integrator'
    //   Gain: '<S164>/Proportional Gain'

    rtb_ZeroGain_m4 = (RollPitchRateKp * rtb_Integrator_b +
                       Ctrl_DW.Integrator_DSTATE_c) + rtb_IntegralGain_p;

    // Saturate: '<S166>/Saturation'
    if (rtb_ZeroGain_m4 > Ctrl_P.DiscretePIDController_UpperSa_g) {
      rtb_IntegralGain_c = Ctrl_P.DiscretePIDController_UpperSa_g;
    } else if (rtb_ZeroGain_m4 < Ctrl_P.DiscretePIDController_LowerSa_o) {
      rtb_IntegralGain_c = Ctrl_P.DiscretePIDController_LowerSa_o;
    } else {
      rtb_IntegralGain_c = rtb_ZeroGain_m4;
    }

    // End of Saturate: '<S166>/Saturation'

    // DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
    //   Inport: '<Root>/RPY'

    if (Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j != 0) {
      Ctrl_DW.DiscreteTimeIntegrator_DSTATE_f = Ctrl_U.RPY[2];
    }

    // Switch: '<S19>/Switch' incorporates:
    //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
    //   Gain: '<S528>/Gain'

    if (Ctrl_B.AutoRefAng > Ctrl_P.Switch_Threshold) {
      rtb_SignPreIntegrator = Ctrl_P.Gain_Gain * Ctrl_B.AutoRefAng;
    } else {
      rtb_SignPreIntegrator = Ctrl_DW.DiscreteTimeIntegrator_DSTATE_f;
    }

    // End of Switch: '<S19>/Switch'

    // MATLAB Function: '<S19>/Correct Yaw1' incorporates:
    //   Inport: '<Root>/RPY'
    //   Sum: '<S19>/Sum3'

    Ctrl_CorrectYaw1(rtb_SignPreIntegrator - Ctrl_U.RPY[2],
                     &Ctrl_B.sf_CorrectYaw1);

    // Gain: '<S615>/Proportional Gain'
    rtb_SignPreIntegrator = YawKp * Ctrl_B.sf_CorrectYaw1.y;

    // Saturate: '<S617>/Saturation'
    if (rtb_SignPreIntegrator > YawRateMax) {
      rtb_SignPreIntegrator = YawRateMax;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController3_LowerSat) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController3_LowerSat;
      }
    }

    // End of Saturate: '<S617>/Saturation'

    // Sum: '<S19>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_Integrator_j = rtb_SignPreIntegrator - Ctrl_U.dRPY[2];

    // Sum: '<S571>/Sum' incorporates:
    //   DiscreteIntegrator: '<S562>/Integrator'
    //   Gain: '<S567>/Proportional Gain'

    rtb_Polynomial = YawRateKp * rtb_Integrator_j + Ctrl_DW.Integrator_DSTATE_mo;

    // Saturate: '<S569>/Saturation'
    if (rtb_Polynomial > Ctrl_P.DiscretePIDController_UpperS_gi) {
      rtb_Integrator = Ctrl_P.DiscretePIDController_UpperS_gi;
    } else if (rtb_Polynomial < Ctrl_P.DiscretePIDController_LowerSa_i) {
      rtb_Integrator = Ctrl_P.DiscretePIDController_LowerSa_i;
    } else {
      rtb_Integrator = rtb_Polynomial;
    }

    // End of Saturate: '<S569>/Saturation'

    // Sum: '<S14>/Add1' incorporates:
    //   Sum: '<S14>/Add2'

    rtb_SignPreIntegrator = rtb_DeadZone_f - rtb_Integrator_m;
    rtb_SignPreSat_iz = (rtb_SignPreIntegrator + rtb_IntegralGain_c) +
      rtb_Integrator;

    // Sum: '<S14>/Add2'
    rtb_SignPreIntegrator = (rtb_SignPreIntegrator - rtb_IntegralGain_c) -
      rtb_Integrator;

    // Sum: '<S14>/Add3' incorporates:
    //   Sum: '<S14>/Add4'

    rtb_DeadZone_f += rtb_Integrator_m;
    rtb_Integrator_m = (rtb_DeadZone_f + rtb_IntegralGain_c) - rtb_Integrator;

    // Sum: '<S14>/Add4'
    rtb_DeadZone_f = (rtb_DeadZone_f - rtb_IntegralGain_c) + rtb_Integrator;

    // Saturate: '<S120>/Limit3'
    if (rtb_Integrator_m > Ctrl_P.Limit3_UpperSat) {
      rtb_Integrator_m = Ctrl_P.Limit3_UpperSat;
    } else {
      if (rtb_Integrator_m < Ctrl_P.Limit3_LowerSat) {
        rtb_Integrator_m = Ctrl_P.Limit3_LowerSat;
      }
    }

    // End of Saturate: '<S120>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S120>/Constant'
    //   Gain: '<S120>/Gain'
    //   Sum: '<S120>/Subtract'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_f * rtb_Integrator_m + Ctrl_P.Constant_Value;

    // Saturate: '<S121>/Limit3'
    if (rtb_SignPreSat_iz > Ctrl_P.Limit3_UpperSat_k) {
      rtb_SignPreSat_iz = Ctrl_P.Limit3_UpperSat_k;
    } else {
      if (rtb_SignPreSat_iz < Ctrl_P.Limit3_LowerSat_i) {
        rtb_SignPreSat_iz = Ctrl_P.Limit3_LowerSat_i;
      }
    }

    // End of Saturate: '<S121>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S121>/Constant'
    //   Gain: '<S121>/Gain'
    //   Sum: '<S121>/Subtract'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_a * rtb_SignPreSat_iz +
      Ctrl_P.Constant_Value_a;

    // Saturate: '<S122>/Limit3'
    if (rtb_SignPreIntegrator > Ctrl_P.Limit3_UpperSat_m) {
      rtb_SignPreIntegrator = Ctrl_P.Limit3_UpperSat_m;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.Limit3_LowerSat_ih) {
        rtb_SignPreIntegrator = Ctrl_P.Limit3_LowerSat_ih;
      }
    }

    // End of Saturate: '<S122>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S122>/Constant'
    //   Gain: '<S122>/Gain'
    //   Sum: '<S122>/Subtract'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_j * rtb_SignPreIntegrator +
      Ctrl_P.Constant_Value_j;

    // Saturate: '<S123>/Limit3'
    if (rtb_DeadZone_f > Ctrl_P.Limit3_UpperSat_a) {
      rtb_DeadZone_f = Ctrl_P.Limit3_UpperSat_a;
    } else {
      if (rtb_DeadZone_f < Ctrl_P.Limit3_LowerSat_n) {
        rtb_DeadZone_f = Ctrl_P.Limit3_LowerSat_n;
      }
    }

    // End of Saturate: '<S123>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S123>/Constant'
    //   Gain: '<S123>/Gain'
    //   Sum: '<S123>/Subtract'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_b * rtb_DeadZone_f + Ctrl_P.Constant_Value_p;

    // Gain: '<S150>/ZeroGain'
    rtb_IntegralGain_c = Ctrl_P.ZeroGain_Gain_j * rtb_ZeroGain_m4;

    // DeadZone: '<S152>/DeadZone'
    if (rtb_ZeroGain_m4 > Ctrl_P.DiscretePIDController_UpperSa_g) {
      rtb_ZeroGain_m4 -= Ctrl_P.DiscretePIDController_UpperSa_g;
    } else if (rtb_ZeroGain_m4 >= Ctrl_P.DiscretePIDController_LowerSa_o) {
      rtb_ZeroGain_m4 = 0.0F;
    } else {
      rtb_ZeroGain_m4 -= Ctrl_P.DiscretePIDController_LowerSa_o;
    }

    // End of DeadZone: '<S152>/DeadZone'

    // RelationalOperator: '<S150>/NotEqual'
    rtb_NotEqual_e1 = (rtb_IntegralGain_c != rtb_ZeroGain_m4);

    // Signum: '<S150>/SignPreSat'
    if (rtb_ZeroGain_m4 < 0.0F) {
      rtb_ZeroGain_m4 = -1.0F;
    } else {
      if (rtb_ZeroGain_m4 > 0.0F) {
        rtb_ZeroGain_m4 = 1.0F;
      }
    }

    // End of Signum: '<S150>/SignPreSat'

    // Gain: '<S156>/Integral Gain'
    rtb_Integrator_b *= RollPitchRateKi;

    // Gain: '<S348>/ZeroGain'
    rtb_IntegralGain_c = Ctrl_P.ZeroGain_Gain_p * rtb_SignPreSat;

    // DeadZone: '<S350>/DeadZone'
    if (rtb_SignPreSat > Ctrl_P.DiscretePIDController_UpperSatu) {
      rtb_SignPreSat -= Ctrl_P.DiscretePIDController_UpperSatu;
    } else if (rtb_SignPreSat >= Ctrl_P.DiscretePIDController_LowerSatu) {
      rtb_SignPreSat = 0.0F;
    } else {
      rtb_SignPreSat -= Ctrl_P.DiscretePIDController_LowerSatu;
    }

    // End of DeadZone: '<S350>/DeadZone'

    // RelationalOperator: '<S348>/NotEqual'
    rtb_NotEqual_kp = (rtb_IntegralGain_c != rtb_SignPreSat);

    // Signum: '<S348>/SignPreSat'
    if (rtb_SignPreSat < 0.0F) {
      rtb_SignPreSat = -1.0F;
    } else {
      if (rtb_SignPreSat > 0.0F) {
        rtb_SignPreSat = 1.0F;
      }
    }

    // End of Signum: '<S348>/SignPreSat'

    // Gain: '<S354>/Integral Gain'
    rtb_IntegralGain_a *= RollPitchRateKi;

    // Gain: '<S449>/ZeroGain'
    rtb_IntegralGain_c = Ctrl_P.ZeroGain_Gain_l * rtb_Integrator_i;

    // DeadZone: '<S451>/DeadZone'
    if (rtb_Integrator_i > Ctrl_P.DiscretePIDController1_UpperS_g) {
      rtb_Integrator_i -= Ctrl_P.DiscretePIDController1_UpperS_g;
    } else if (rtb_Integrator_i >= Ctrl_P.DiscretePIDController1_LowerS_p) {
      rtb_Integrator_i = 0.0F;
    } else {
      rtb_Integrator_i -= Ctrl_P.DiscretePIDController1_LowerS_p;
    }

    // End of DeadZone: '<S451>/DeadZone'

    // RelationalOperator: '<S449>/NotEqual'
    rtb_NotEqual_el = (rtb_IntegralGain_c != rtb_Integrator_i);

    // Signum: '<S449>/SignPreSat'
    if (rtb_Integrator_i < 0.0F) {
      rtb_Integrator_i = -1.0F;
    } else {
      if (rtb_Integrator_i > 0.0F) {
        rtb_Integrator_i = 1.0F;
      }
    }

    // End of Signum: '<S449>/SignPreSat'

    // Gain: '<S455>/Integral Gain'
    rtb_SignPreSat_n *= VelKi;

    // Gain: '<S499>/ZeroGain'
    rtb_IntegralGain_c = Ctrl_P.ZeroGain_Gain_k * rtb_SignPreSat_f;

    // DeadZone: '<S501>/DeadZone'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController2_UpperS_d) {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController2_UpperS_d;
    } else if (rtb_SignPreSat_f >= Ctrl_P.DiscretePIDController2_LowerS_h) {
      rtb_SignPreSat_f = 0.0F;
    } else {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController2_LowerS_h;
    }

    // End of DeadZone: '<S501>/DeadZone'

    // RelationalOperator: '<S499>/NotEqual'
    rtb_NotEqual_pr = (rtb_IntegralGain_c != rtb_SignPreSat_f);

    // Signum: '<S499>/SignPreSat'
    if (rtb_SignPreSat_f < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else {
      if (rtb_SignPreSat_f > 0.0F) {
        rtb_SignPreSat_f = 1.0F;
      }
    }

    // End of Signum: '<S499>/SignPreSat'

    // Gain: '<S505>/Integral Gain'
    rtb_Limit3_c *= VelKi;

    // Gain: '<S553>/ZeroGain'
    rtb_IntegralGain_c = Ctrl_P.ZeroGain_Gain_g * rtb_Polynomial;

    // DeadZone: '<S555>/DeadZone'
    if (rtb_Polynomial > Ctrl_P.DiscretePIDController_UpperS_gi) {
      rtb_Polynomial -= Ctrl_P.DiscretePIDController_UpperS_gi;
    } else if (rtb_Polynomial >= Ctrl_P.DiscretePIDController_LowerSa_i) {
      rtb_Polynomial = 0.0F;
    } else {
      rtb_Polynomial -= Ctrl_P.DiscretePIDController_LowerSa_i;
    }

    // End of DeadZone: '<S555>/DeadZone'

    // RelationalOperator: '<S553>/NotEqual'
    rtb_NotEqual_j = (rtb_IntegralGain_c != rtb_Polynomial);

    // Signum: '<S553>/SignPreSat'
    if (rtb_Polynomial < 0.0F) {
      rtb_Polynomial = -1.0F;
    } else {
      if (rtb_Polynomial > 0.0F) {
        rtb_Polynomial = 1.0F;
      }
    }

    // End of Signum: '<S553>/SignPreSat'

    // Gain: '<S559>/Integral Gain'
    rtb_Integrator_j *= YawRateKi;

    // Update for DiscreteIntegrator: '<S55>/Integrator'
    Ctrl_DW.Integrator_DSTATE_k += Ctrl_P.Integrator_gainval * rtb_Switch_o;

    // DataTypeConversion: '<S499>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_f), 256.0));

    // Signum: '<S499>/SignPreIntegrator'
    if (rtb_Limit3_c < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else if (rtb_Limit3_c > 0.0F) {
      rtb_SignPreSat_f = 1.0F;
    } else {
      rtb_SignPreSat_f = rtb_Limit3_c;
    }

    // End of Signum: '<S499>/SignPreIntegrator'

    // DataTypeConversion: '<S499>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_SignPreSat_f),
      256.0));

    // Switch: '<S499>/Switch' incorporates:
    //   Constant: '<S499>/Constant1'
    //   DataTypeConversion: '<S499>/DataTypeConv1'
    //   DataTypeConversion: '<S499>/DataTypeConv2'
    //   Logic: '<S499>/AND3'
    //   RelationalOperator: '<S499>/Equal1'

    if (rtb_NotEqual_pr && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Limit3_c = Ctrl_P.Constant1_Value_g;
    }

    // End of Switch: '<S499>/Switch'

    // Update for DiscreteIntegrator: '<S508>/Integrator'
    Ctrl_DW.Integrator_DSTATE_l += Ctrl_P.Integrator_gainval_c * rtb_Limit3_c;

    // DataTypeConversion: '<S449>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_Integrator_i), 256.0));

    // Signum: '<S449>/SignPreIntegrator'
    if (rtb_SignPreSat_n < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else if (rtb_SignPreSat_n > 0.0F) {
      rtb_SignPreSat_f = 1.0F;
    } else {
      rtb_SignPreSat_f = rtb_SignPreSat_n;
    }

    // End of Signum: '<S449>/SignPreIntegrator'

    // DataTypeConversion: '<S449>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_SignPreSat_f),
      256.0));

    // Switch: '<S449>/Switch' incorporates:
    //   Constant: '<S449>/Constant1'
    //   DataTypeConversion: '<S449>/DataTypeConv1'
    //   DataTypeConversion: '<S449>/DataTypeConv2'
    //   Logic: '<S449>/AND3'
    //   RelationalOperator: '<S449>/Equal1'

    if (rtb_NotEqual_el && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_SignPreSat_n = Ctrl_P.Constant1_Value_b;
    }

    // End of Switch: '<S449>/Switch'

    // Update for DiscreteIntegrator: '<S458>/Integrator'
    Ctrl_DW.Integrator_DSTATE_lw += Ctrl_P.Integrator_gainval_b *
      rtb_SignPreSat_n;

    // DataTypeConversion: '<S348>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat), 256.0));

    // Signum: '<S348>/SignPreIntegrator'
    if (rtb_IntegralGain_a < 0.0F) {
      rtb_SignPreSat_n = -1.0F;
    } else if (rtb_IntegralGain_a > 0.0F) {
      rtb_SignPreSat_n = 1.0F;
    } else {
      rtb_SignPreSat_n = rtb_IntegralGain_a;
    }

    // End of Signum: '<S348>/SignPreIntegrator'

    // DataTypeConversion: '<S348>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_SignPreSat_n),
      256.0));

    // Switch: '<S348>/Switch' incorporates:
    //   Constant: '<S348>/Constant1'
    //   DataTypeConversion: '<S348>/DataTypeConv1'
    //   DataTypeConversion: '<S348>/DataTypeConv2'
    //   Logic: '<S348>/AND3'
    //   RelationalOperator: '<S348>/Equal1'

    if (rtb_NotEqual_kp && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_IntegralGain_a = Ctrl_P.Constant1_Value_p;
    }

    // End of Switch: '<S348>/Switch'

    // Update for DiscreteIntegrator: '<S357>/Integrator'
    Ctrl_DW.Integrator_DSTATE_gj += Ctrl_P.Integrator_gainval_a *
      rtb_IntegralGain_a;

    // Update for DiscreteIntegrator: '<S352>/Filter'
    Ctrl_DW.Filter_DSTATE_a += Ctrl_P.Filter_gainval * rtb_FilterCoefficient_od;

    // DataTypeConversion: '<S150>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_ZeroGain_m4), 256.0));

    // Signum: '<S150>/SignPreIntegrator'
    if (rtb_Integrator_b < 0.0F) {
      rtb_IntegralGain_a = -1.0F;
    } else if (rtb_Integrator_b > 0.0F) {
      rtb_IntegralGain_a = 1.0F;
    } else {
      rtb_IntegralGain_a = rtb_Integrator_b;
    }

    // End of Signum: '<S150>/SignPreIntegrator'

    // DataTypeConversion: '<S150>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_IntegralGain_a),
      256.0));

    // Switch: '<S150>/Switch' incorporates:
    //   Constant: '<S150>/Constant1'
    //   DataTypeConversion: '<S150>/DataTypeConv1'
    //   DataTypeConversion: '<S150>/DataTypeConv2'
    //   Logic: '<S150>/AND3'
    //   RelationalOperator: '<S150>/Equal1'

    if (rtb_NotEqual_e1 && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Integrator_b = Ctrl_P.Constant1_Value_c;
    }

    // End of Switch: '<S150>/Switch'

    // Update for DiscreteIntegrator: '<S159>/Integrator'
    Ctrl_DW.Integrator_DSTATE_c += Ctrl_P.Integrator_gainval_ao *
      rtb_Integrator_b;

    // Update for DiscreteIntegrator: '<S154>/Filter'
    Ctrl_DW.Filter_DSTATE_e += Ctrl_P.Filter_gainval_e * rtb_IntegralGain_p;

    // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
    Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j = 0U;

    // DeadZone: '<S19>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End) {
      rtb_ZeroGain_m4 = rtb_Rudder - Ctrl_P.DeadZone_End;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start) {
      rtb_ZeroGain_m4 = 0.0F;
    } else {
      rtb_ZeroGain_m4 = rtb_Rudder - Ctrl_P.DeadZone_Start;
    }

    // End of DeadZone: '<S19>/Dead Zone'

    // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
    //   Gain: '<S19>/Scale roll2'

    Ctrl_DW.DiscreteTimeIntegrator_DSTATE_f += Ctrl_P.Scaleroll2_Gain *
      rtb_ZeroGain_m4 * Ctrl_P.DiscreteTimeIntegrator_gainval;

    // DataTypeConversion: '<S553>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_Polynomial), 256.0));

    // Signum: '<S553>/SignPreIntegrator'
    if (rtb_Integrator_j < 0.0F) {
      rtb_IntegralGain_a = -1.0F;
    } else if (rtb_Integrator_j > 0.0F) {
      rtb_IntegralGain_a = 1.0F;
    } else {
      rtb_IntegralGain_a = rtb_Integrator_j;
    }

    // End of Signum: '<S553>/SignPreIntegrator'

    // DataTypeConversion: '<S553>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_IntegralGain_a),
      256.0));

    // Switch: '<S553>/Switch' incorporates:
    //   Constant: '<S553>/Constant1'
    //   DataTypeConversion: '<S553>/DataTypeConv1'
    //   DataTypeConversion: '<S553>/DataTypeConv2'
    //   Logic: '<S553>/AND3'
    //   RelationalOperator: '<S553>/Equal1'

    if (rtb_NotEqual_j && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>(
           static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
                            (static_cast<int8_T>(static_cast<uint8_T>
            (rtb_SignPreIntegrator)))) == (tmp < 0.0F ? static_cast<int32_T>(
           static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-tmp))))
          : static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Integrator_j = Ctrl_P.Constant1_Value_j;
    }

    // End of Switch: '<S553>/Switch'

    // Update for DiscreteIntegrator: '<S562>/Integrator'
    Ctrl_DW.Integrator_DSTATE_mo += Ctrl_P.Integrator_gainval_p *
      rtb_Integrator_j;
  } else {
    Ctrl_DW.AutoCtrl_MODE = false;
  }

  // End of Outputs for SubSystem: '<S1>/AutoCtrl'

  // Gain: '<S5>/Gain' incorporates:
  //   Constant: '<S5>/Constant'
  //   Inport: '<Root>/Thr'
  //   Sum: '<S5>/Subtract'

  rtb_Polynomial = (Ctrl_U.Thr - Ctrl_P.Constant_Value_pb) * Ctrl_P.Gain_Gain_g;

  // Saturate: '<S5>/Saturation'
  if (rtb_Polynomial > Ctrl_P.Saturation_UpperSat) {
    rtb_Polynomial = Ctrl_P.Saturation_UpperSat;
  } else {
    if (rtb_Polynomial < Ctrl_P.Saturation_LowerSat) {
      rtb_Polynomial = Ctrl_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S5>/Saturation'

  // Gain: '<S5>/Gain1' incorporates:
  //   Constant: '<S5>/Constant1'
  //   Inport: '<Root>/Aileron'
  //   Sum: '<S5>/Subtract1'

  rtb_SignPreSat_n = (Ctrl_U.Aileron - Ctrl_P.Constant1_Value_g3) *
    Ctrl_P.Gain1_Gain_b;

  // Saturate: '<S5>/Saturation1'
  if (rtb_SignPreSat_n > Ctrl_P.Saturation1_UpperSat) {
    rtb_SignPreSat_n = Ctrl_P.Saturation1_UpperSat;
  } else {
    if (rtb_SignPreSat_n < Ctrl_P.Saturation1_LowerSat) {
      rtb_SignPreSat_n = Ctrl_P.Saturation1_LowerSat;
    }
  }

  // End of Saturate: '<S5>/Saturation1'

  // Gain: '<S5>/Gain2' incorporates:
  //   Constant: '<S5>/Constant2'
  //   Inport: '<Root>/Elevator'
  //   Sum: '<S5>/Subtract2'

  rtb_IntegralGain_a = (Ctrl_U.Elevator - Ctrl_P.Constant2_Value_c) *
    Ctrl_P.Gain2_Gain_k;

  // Saturate: '<S5>/Saturation2'
  if (rtb_IntegralGain_a > Ctrl_P.Saturation2_UpperSat) {
    rtb_IntegralGain_a = Ctrl_P.Saturation2_UpperSat;
  } else {
    if (rtb_IntegralGain_a < Ctrl_P.Saturation2_LowerSat) {
      rtb_IntegralGain_a = Ctrl_P.Saturation2_LowerSat;
    }
  }

  // End of Saturate: '<S5>/Saturation2'

  // Outputs for Enabled SubSystem: '<S1>/ManualCtrl' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (Ctrl_B.ManualMode) {
    // Gain: '<S6>/Gain'
    rtb_DeadZone_f = Ctrl_P.Gain_Gain_ae * rtb_Polynomial;

    // Gain: '<S6>/Gain1'
    rtb_Switch_o = Ctrl_P.Gain1_Gain_e * rtb_SignPreSat_n;

    // Gain: '<S6>/Gain2'
    rtb_Limit3_c = Ctrl_P.Gain2_Gain * rtb_IntegralGain_a;

    // Gain: '<S6>/Gain3'
    rtb_Integrator = Ctrl_P.Gain3_Gain * rtb_Rudder;

    // Sum: '<S627>/Add1' incorporates:
    //   Sum: '<S627>/Add2'

    rtb_IntegralGain_p = rtb_DeadZone_f - rtb_Switch_o;
    rtb_SignPreSat_f = (rtb_IntegralGain_p + rtb_Limit3_c) + rtb_Integrator;

    // Sum: '<S627>/Add2'
    rtb_Integrator_b = (rtb_IntegralGain_p - rtb_Limit3_c) - rtb_Integrator;

    // Sum: '<S627>/Add3'
    rtb_IntegralGain_p = ((rtb_DeadZone_f + rtb_Switch_o) + rtb_Limit3_c) -
      rtb_Integrator;

    // Sum: '<S627>/Add4'
    rtb_DeadZone_f = ((rtb_DeadZone_f + rtb_Switch_o) - rtb_Limit3_c) +
      rtb_Integrator;

    // Saturate: '<S628>/Limit3'
    if (rtb_IntegralGain_p > Ctrl_P.Limit3_UpperSat_l) {
      rtb_IntegralGain_p = Ctrl_P.Limit3_UpperSat_l;
    } else {
      if (rtb_IntegralGain_p < Ctrl_P.Limit3_LowerSat_g) {
        rtb_IntegralGain_p = Ctrl_P.Limit3_LowerSat_g;
      }
    }

    // End of Saturate: '<S628>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S628>/Constant'
    //   Gain: '<S628>/Gain'
    //   Sum: '<S628>/Subtract'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_m * rtb_IntegralGain_p +
      Ctrl_P.Constant_Value_c;

    // Saturate: '<S629>/Limit3'
    if (rtb_SignPreSat_f > Ctrl_P.Limit3_UpperSat_b) {
      rtb_SignPreSat_f = Ctrl_P.Limit3_UpperSat_b;
    } else {
      if (rtb_SignPreSat_f < Ctrl_P.Limit3_LowerSat_k) {
        rtb_SignPreSat_f = Ctrl_P.Limit3_LowerSat_k;
      }
    }

    // End of Saturate: '<S629>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S629>/Constant'
    //   Gain: '<S629>/Gain'
    //   Sum: '<S629>/Subtract'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_c * rtb_SignPreSat_f +
      Ctrl_P.Constant_Value_i;

    // Saturate: '<S630>/Limit3'
    if (rtb_Integrator_b > Ctrl_P.Limit3_UpperSat_o) {
      rtb_Integrator_b = Ctrl_P.Limit3_UpperSat_o;
    } else {
      if (rtb_Integrator_b < Ctrl_P.Limit3_LowerSat_d) {
        rtb_Integrator_b = Ctrl_P.Limit3_LowerSat_d;
      }
    }

    // End of Saturate: '<S630>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S630>/Constant'
    //   Gain: '<S630>/Gain'
    //   Sum: '<S630>/Subtract'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_e * rtb_Integrator_b +
      Ctrl_P.Constant_Value_o;

    // Saturate: '<S631>/Limit3'
    if (rtb_DeadZone_f > Ctrl_P.Limit3_UpperSat_c) {
      rtb_DeadZone_f = Ctrl_P.Limit3_UpperSat_c;
    } else {
      if (rtb_DeadZone_f < Ctrl_P.Limit3_LowerSat_f) {
        rtb_DeadZone_f = Ctrl_P.Limit3_LowerSat_f;
      }
    }

    // End of Saturate: '<S631>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S631>/Constant'
    //   Gain: '<S631>/Gain'
    //   Sum: '<S631>/Subtract'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_bq * rtb_DeadZone_f + Ctrl_P.Constant_Value_e;
  }

  // End of Outputs for SubSystem: '<S1>/ManualCtrl'

  // Outputs for Enabled SubSystem: '<S1>/Off' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (Ctrl_B.Off) {
    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S7>/Constant1'

    Ctrl_B.PWM2 = Ctrl_P.Constant1_Value_l;

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S7>/Constant2'

    Ctrl_B.PWM1 = Ctrl_P.Constant2_Value;

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S7>/Constant3'

    Ctrl_B.PWM3 = Ctrl_P.Constant3_Value;

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S7>/Constant4'

    Ctrl_B.PWM4 = Ctrl_P.Constant4_Value;
  }

  // End of Outputs for SubSystem: '<S1>/Off'

  // Outputs for Enabled SubSystem: '<S1>/RateCtrl' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (Ctrl_B.RateMode) {
    if (!Ctrl_DW.RateCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S725>/Integrator'
      Ctrl_DW.Integrator_DSTATE_i = Ctrl_P.DiscretePIDController_Initia_mn;

      // InitializeConditions for DiscreteIntegrator: '<S720>/Filter'
      Ctrl_DW.Filter_DSTATE_f = Ctrl_P.DiscretePIDController_Initial_c;

      // InitializeConditions for DiscreteIntegrator: '<S674>/Integrator'
      Ctrl_DW.Integrator_DSTATE_g = Ctrl_P.DiscretePIDController_Initial_f;

      // InitializeConditions for DiscreteIntegrator: '<S669>/Filter'
      Ctrl_DW.Filter_DSTATE_b = Ctrl_P.DiscretePIDController_Initial_l;

      // InitializeConditions for DiscreteIntegrator: '<S776>/Integrator'
      Ctrl_DW.Integrator_DSTATE_f = Ctrl_P.DiscretePIDController_Initial_a;
      Ctrl_DW.RateCtrl_MODE = true;
    }

    // Gain: '<S8>/Gain'
    rtb_DeadZone_f = Ctrl_P.Gain_Gain_cu * rtb_Polynomial;

    // Sum: '<S634>/Sum' incorporates:
    //   Gain: '<S634>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_Switch_o = RollPitchRateMax * rtb_SignPreSat_n - Ctrl_U.dRPY[0];

    // Gain: '<S728>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S720>/Filter'
    //   Gain: '<S719>/Derivative Gain'
    //   Sum: '<S720>/SumD'

    rtb_Integrator_j = (RollPitchRateKd * rtb_Switch_o - Ctrl_DW.Filter_DSTATE_f)
      * Ctrl_P.DiscretePIDController_N_hm;

    // Sum: '<S734>/Sum' incorporates:
    //   DiscreteIntegrator: '<S725>/Integrator'
    //   Gain: '<S730>/Proportional Gain'

    rtb_SignPreSat_f = (RollPitchRateKp * rtb_Switch_o +
                        Ctrl_DW.Integrator_DSTATE_i) + rtb_Integrator_j;

    // Saturate: '<S732>/Saturation'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController_UpperSa_h) {
      rtb_Integrator_b = Ctrl_P.DiscretePIDController_UpperSa_h;
    } else if (rtb_SignPreSat_f < Ctrl_P.DiscretePIDController_LowerSa_k) {
      rtb_Integrator_b = Ctrl_P.DiscretePIDController_LowerSa_k;
    } else {
      rtb_Integrator_b = rtb_SignPreSat_f;
    }

    // End of Saturate: '<S732>/Saturation'

    // Sum: '<S633>/Sum' incorporates:
    //   Gain: '<S633>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_p = RollPitchRateMax * rtb_IntegralGain_a - Ctrl_U.dRPY[1];

    // Gain: '<S677>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S669>/Filter'
    //   Gain: '<S668>/Derivative Gain'
    //   Sum: '<S669>/SumD'

    rtb_Integrator = (RollPitchRateKd * rtb_IntegralGain_p -
                      Ctrl_DW.Filter_DSTATE_b) *
      Ctrl_P.DiscretePIDController_N_p;

    // Sum: '<S683>/Sum' incorporates:
    //   DiscreteIntegrator: '<S674>/Integrator'
    //   Gain: '<S679>/Proportional Gain'

    rtb_SignPreSat_iz = (RollPitchRateKp * rtb_IntegralGain_p +
                         Ctrl_DW.Integrator_DSTATE_g) + rtb_Integrator;

    // Saturate: '<S681>/Saturation'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController_UpperSa_n) {
      rtb_Integrator_i = Ctrl_P.DiscretePIDController_UpperSa_n;
    } else if (rtb_SignPreSat_iz < Ctrl_P.DiscretePIDController_LowerS_io) {
      rtb_Integrator_i = Ctrl_P.DiscretePIDController_LowerS_io;
    } else {
      rtb_Integrator_i = rtb_SignPreSat_iz;
    }

    // End of Saturate: '<S681>/Saturation'

    // DeadZone: '<S635>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End_o) {
      rtb_ZeroGain_m4 = rtb_Rudder - Ctrl_P.DeadZone_End_o;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start_c) {
      rtb_ZeroGain_m4 = 0.0F;
    } else {
      rtb_ZeroGain_m4 = rtb_Rudder - Ctrl_P.DeadZone_Start_c;
    }

    // End of DeadZone: '<S635>/Dead Zone'

    // Sum: '<S635>/Sum' incorporates:
    //   Gain: '<S635>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_ZeroGain_m4 = YawRateMax * rtb_ZeroGain_m4 - Ctrl_U.dRPY[2];

    // Sum: '<S785>/Sum' incorporates:
    //   DiscreteIntegrator: '<S776>/Integrator'
    //   Gain: '<S781>/Proportional Gain'

    rtb_FilterCoefficient_od = YawRateKp * rtb_ZeroGain_m4 +
      Ctrl_DW.Integrator_DSTATE_f;

    // Saturate: '<S783>/Saturation'
    if (rtb_FilterCoefficient_od > Ctrl_P.DiscretePIDController_UpperSa_b) {
      rtb_Limit3_c = Ctrl_P.DiscretePIDController_UpperSa_b;
    } else if (rtb_FilterCoefficient_od < Ctrl_P.DiscretePIDController_LowerSa_a)
    {
      rtb_Limit3_c = Ctrl_P.DiscretePIDController_LowerSa_a;
    } else {
      rtb_Limit3_c = rtb_FilterCoefficient_od;
    }

    // End of Saturate: '<S783>/Saturation'

    // Sum: '<S632>/Add1' incorporates:
    //   Sum: '<S632>/Add2'

    rtb_SignPreIntegrator = rtb_DeadZone_f - rtb_Integrator_b;
    rtb_SignPreSat = (rtb_SignPreIntegrator + rtb_Integrator_i) + rtb_Limit3_c;

    // Sum: '<S632>/Add2'
    rtb_Integrator_m = (rtb_SignPreIntegrator - rtb_Integrator_i) - rtb_Limit3_c;

    // Sum: '<S632>/Add3' incorporates:
    //   Sum: '<S632>/Add4'

    rtb_Integrator_b += rtb_DeadZone_f;
    rtb_IntegralGain_c = (rtb_Integrator_b + rtb_Integrator_i) - rtb_Limit3_c;

    // Sum: '<S632>/Add4'
    rtb_DeadZone_f = (rtb_Integrator_b - rtb_Integrator_i) + rtb_Limit3_c;

    // Saturate: '<S636>/Limit3'
    if (rtb_IntegralGain_c > Ctrl_P.Limit3_UpperSat_d) {
      rtb_IntegralGain_c = Ctrl_P.Limit3_UpperSat_d;
    } else {
      if (rtb_IntegralGain_c < Ctrl_P.Limit3_LowerSat_ku) {
        rtb_IntegralGain_c = Ctrl_P.Limit3_LowerSat_ku;
      }
    }

    // End of Saturate: '<S636>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S636>/Constant'
    //   Gain: '<S636>/Gain'
    //   Sum: '<S636>/Subtract'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_h * rtb_IntegralGain_c +
      Ctrl_P.Constant_Value_g;

    // Saturate: '<S637>/Limit3'
    if (rtb_SignPreSat > Ctrl_P.Limit3_UpperSat_a1) {
      rtb_SignPreSat = Ctrl_P.Limit3_UpperSat_a1;
    } else {
      if (rtb_SignPreSat < Ctrl_P.Limit3_LowerSat_e) {
        rtb_SignPreSat = Ctrl_P.Limit3_LowerSat_e;
      }
    }

    // End of Saturate: '<S637>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S637>/Constant'
    //   Gain: '<S637>/Gain'
    //   Sum: '<S637>/Subtract'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_ce * rtb_SignPreSat +
      Ctrl_P.Constant_Value_ev;

    // Saturate: '<S638>/Limit3'
    if (rtb_Integrator_m > Ctrl_P.Limit3_UpperSat_g) {
      rtb_Integrator_m = Ctrl_P.Limit3_UpperSat_g;
    } else {
      if (rtb_Integrator_m < Ctrl_P.Limit3_LowerSat_j) {
        rtb_Integrator_m = Ctrl_P.Limit3_LowerSat_j;
      }
    }

    // End of Saturate: '<S638>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S638>/Constant'
    //   Gain: '<S638>/Gain'
    //   Sum: '<S638>/Subtract'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_cc * rtb_Integrator_m +
      Ctrl_P.Constant_Value_k;

    // Saturate: '<S639>/Limit3'
    if (rtb_DeadZone_f > Ctrl_P.Limit3_UpperSat_j) {
      rtb_DeadZone_f = Ctrl_P.Limit3_UpperSat_j;
    } else {
      if (rtb_DeadZone_f < Ctrl_P.Limit3_LowerSat_o) {
        rtb_DeadZone_f = Ctrl_P.Limit3_LowerSat_o;
      }
    }

    // End of Saturate: '<S639>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S639>/Constant'
    //   Gain: '<S639>/Gain'
    //   Sum: '<S639>/Subtract'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_hp * rtb_DeadZone_f + Ctrl_P.Constant_Value_n;

    // Gain: '<S665>/ZeroGain'
    rtb_SignPreSat = Ctrl_P.ZeroGain_Gain_n * rtb_SignPreSat_iz;

    // DeadZone: '<S667>/DeadZone'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController_UpperSa_n) {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController_UpperSa_n;
    } else if (rtb_SignPreSat_iz >= Ctrl_P.DiscretePIDController_LowerS_io) {
      rtb_SignPreSat_iz = 0.0F;
    } else {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController_LowerS_io;
    }

    // End of DeadZone: '<S667>/DeadZone'

    // RelationalOperator: '<S665>/NotEqual'
    rtb_NotEqual_e1 = (rtb_SignPreSat != rtb_SignPreSat_iz);

    // Signum: '<S665>/SignPreSat'
    if (rtb_SignPreSat_iz < 0.0F) {
      rtb_SignPreSat_iz = -1.0F;
    } else {
      if (rtb_SignPreSat_iz > 0.0F) {
        rtb_SignPreSat_iz = 1.0F;
      }
    }

    // End of Signum: '<S665>/SignPreSat'

    // Gain: '<S671>/Integral Gain'
    rtb_IntegralGain_p *= RollPitchRateKi;

    // Gain: '<S716>/ZeroGain'
    rtb_SignPreSat = Ctrl_P.ZeroGain_Gain_nc * rtb_SignPreSat_f;

    // DeadZone: '<S718>/DeadZone'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController_UpperSa_h) {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController_UpperSa_h;
    } else if (rtb_SignPreSat_f >= Ctrl_P.DiscretePIDController_LowerSa_k) {
      rtb_SignPreSat_f = 0.0F;
    } else {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController_LowerSa_k;
    }

    // End of DeadZone: '<S718>/DeadZone'

    // RelationalOperator: '<S716>/NotEqual'
    rtb_NotEqual_kp = (rtb_SignPreSat != rtb_SignPreSat_f);

    // Signum: '<S716>/SignPreSat'
    if (rtb_SignPreSat_f < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else {
      if (rtb_SignPreSat_f > 0.0F) {
        rtb_SignPreSat_f = 1.0F;
      }
    }

    // End of Signum: '<S716>/SignPreSat'

    // Gain: '<S722>/Integral Gain'
    rtb_Switch_o *= RollPitchRateKi;

    // Gain: '<S767>/ZeroGain'
    rtb_SignPreSat = Ctrl_P.ZeroGain_Gain_e * rtb_FilterCoefficient_od;

    // DeadZone: '<S769>/DeadZone'
    if (rtb_FilterCoefficient_od > Ctrl_P.DiscretePIDController_UpperSa_b) {
      rtb_FilterCoefficient_od -= Ctrl_P.DiscretePIDController_UpperSa_b;
    } else if (rtb_FilterCoefficient_od >=
               Ctrl_P.DiscretePIDController_LowerSa_a) {
      rtb_FilterCoefficient_od = 0.0F;
    } else {
      rtb_FilterCoefficient_od -= Ctrl_P.DiscretePIDController_LowerSa_a;
    }

    // End of DeadZone: '<S769>/DeadZone'

    // RelationalOperator: '<S767>/NotEqual'
    rtb_NotEqual_el = (rtb_SignPreSat != rtb_FilterCoefficient_od);

    // Signum: '<S767>/SignPreSat'
    if (rtb_FilterCoefficient_od < 0.0F) {
      rtb_FilterCoefficient_od = -1.0F;
    } else {
      if (rtb_FilterCoefficient_od > 0.0F) {
        rtb_FilterCoefficient_od = 1.0F;
      }
    }

    // End of Signum: '<S767>/SignPreSat'

    // Gain: '<S773>/Integral Gain'
    rtb_ZeroGain_m4 *= YawRateKi;

    // DataTypeConversion: '<S716>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_f), 256.0));

    // Signum: '<S716>/SignPreIntegrator'
    if (rtb_Switch_o < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else if (rtb_Switch_o > 0.0F) {
      rtb_SignPreSat_f = 1.0F;
    } else {
      rtb_SignPreSat_f = rtb_Switch_o;
    }

    // End of Signum: '<S716>/SignPreIntegrator'

    // DataTypeConversion: '<S716>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_SignPreSat_f),
      256.0));

    // Switch: '<S716>/Switch' incorporates:
    //   Constant: '<S716>/Constant1'
    //   DataTypeConversion: '<S716>/DataTypeConv1'
    //   DataTypeConversion: '<S716>/DataTypeConv2'
    //   Logic: '<S716>/AND3'
    //   RelationalOperator: '<S716>/Equal1'

    if (rtb_NotEqual_kp && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Switch_o = Ctrl_P.Constant1_Value_e;
    }

    // End of Switch: '<S716>/Switch'

    // Update for DiscreteIntegrator: '<S725>/Integrator'
    Ctrl_DW.Integrator_DSTATE_i += Ctrl_P.Integrator_gainval_d * rtb_Switch_o;

    // Update for DiscreteIntegrator: '<S720>/Filter'
    Ctrl_DW.Filter_DSTATE_f += Ctrl_P.Filter_gainval_el * rtb_Integrator_j;

    // DataTypeConversion: '<S665>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_iz), 256.0));

    // Signum: '<S665>/SignPreIntegrator'
    if (rtb_IntegralGain_p < 0.0F) {
      rtb_Integrator_j = -1.0F;
    } else if (rtb_IntegralGain_p > 0.0F) {
      rtb_Integrator_j = 1.0F;
    } else {
      rtb_Integrator_j = rtb_IntegralGain_p;
    }

    // End of Signum: '<S665>/SignPreIntegrator'

    // DataTypeConversion: '<S665>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Integrator_j),
      256.0));

    // Switch: '<S665>/Switch' incorporates:
    //   Constant: '<S665>/Constant1'
    //   DataTypeConversion: '<S665>/DataTypeConv1'
    //   DataTypeConversion: '<S665>/DataTypeConv2'
    //   Logic: '<S665>/AND3'
    //   RelationalOperator: '<S665>/Equal1'

    if (rtb_NotEqual_e1 && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_IntegralGain_p = Ctrl_P.Constant1_Value_a;
    }

    // End of Switch: '<S665>/Switch'

    // Update for DiscreteIntegrator: '<S674>/Integrator'
    Ctrl_DW.Integrator_DSTATE_g += Ctrl_P.Integrator_gainval_dd *
      rtb_IntegralGain_p;

    // Update for DiscreteIntegrator: '<S669>/Filter'
    Ctrl_DW.Filter_DSTATE_b += Ctrl_P.Filter_gainval_n * rtb_Integrator;

    // DataTypeConversion: '<S767>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_FilterCoefficient_od), 256.0));

    // Signum: '<S767>/SignPreIntegrator'
    if (rtb_ZeroGain_m4 < 0.0F) {
      rtb_Integrator_b = -1.0F;
    } else if (rtb_ZeroGain_m4 > 0.0F) {
      rtb_Integrator_b = 1.0F;
    } else {
      rtb_Integrator_b = rtb_ZeroGain_m4;
    }

    // End of Signum: '<S767>/SignPreIntegrator'

    // DataTypeConversion: '<S767>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Integrator_b),
      256.0));

    // Switch: '<S767>/Switch' incorporates:
    //   Constant: '<S767>/Constant1'
    //   DataTypeConversion: '<S767>/DataTypeConv1'
    //   DataTypeConversion: '<S767>/DataTypeConv2'
    //   Logic: '<S767>/AND3'
    //   RelationalOperator: '<S767>/Equal1'

    if (rtb_NotEqual_el && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_ZeroGain_m4 = Ctrl_P.Constant1_Value_d;
    }

    // End of Switch: '<S767>/Switch'

    // Update for DiscreteIntegrator: '<S776>/Integrator'
    Ctrl_DW.Integrator_DSTATE_f += Ctrl_P.Integrator_gainval_g * rtb_ZeroGain_m4;
  } else {
    Ctrl_DW.RateCtrl_MODE = false;
  }

  // End of Outputs for SubSystem: '<S1>/RateCtrl'

  // Outputs for Enabled SubSystem: '<S1>/RollPitchCtrl' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (Ctrl_B.RollPitchMode) {
    if (!Ctrl_DW.RollPitchCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S936>/Integrator'
      Ctrl_DW.Integrator_DSTATE_h = Ctrl_P.DiscretePIDController_Initia_pb;

      // InitializeConditions for DiscreteIntegrator: '<S931>/Filter'
      Ctrl_DW.Filter_DSTATE_c = Ctrl_P.DiscretePIDController_Initial_p;

      // InitializeConditions for DiscreteIntegrator: '<S836>/Integrator'
      Ctrl_DW.Integrator_DSTATE_h0 = Ctrl_P.DiscretePIDController_Initial_b;

      // InitializeConditions for DiscreteIntegrator: '<S831>/Filter'
      Ctrl_DW.Filter_DSTATE_oq = Ctrl_P.DiscretePIDController_Initial_d;

      // InitializeConditions for DiscreteIntegrator: '<S1035>/Integrator'
      Ctrl_DW.Integrator_DSTATE_o = Ctrl_P.DiscretePIDController_Initia_np;
      Ctrl_DW.RollPitchCtrl_MODE = true;
    }

    // Gain: '<S9>/Gain'
    rtb_DeadZone_f = Ctrl_P.Gain_Gain_mu * rtb_Polynomial;

    // Gain: '<S989>/Proportional Gain' incorporates:
    //   Gain: '<S795>/Scale roll2'
    //   Inport: '<Root>/RPY'
    //   Sum: '<S795>/Sum3'

    rtb_SignPreIntegrator = (RollPitchMax * rtb_SignPreSat_n - Ctrl_U.RPY[0]) *
      RollPitchKp;

    // Saturate: '<S991>/Saturation'
    if (rtb_SignPreIntegrator > RollPitchRateMax) {
      rtb_SignPreIntegrator = RollPitchRateMax;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController1_LowerS_d) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController1_LowerS_d;
      }
    }

    // End of Saturate: '<S991>/Saturation'

    // Sum: '<S795>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_Switch_o = rtb_SignPreIntegrator - Ctrl_U.dRPY[0];

    // Gain: '<S939>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S931>/Filter'
    //   Gain: '<S930>/Derivative Gain'
    //   Sum: '<S931>/SumD'

    rtb_Integrator_j = (RollPitchRateKd * rtb_Switch_o - Ctrl_DW.Filter_DSTATE_c)
      * Ctrl_P.DiscretePIDController_N_i;

    // Sum: '<S945>/Sum' incorporates:
    //   DiscreteIntegrator: '<S936>/Integrator'
    //   Gain: '<S941>/Proportional Gain'

    rtb_SignPreSat_f = (RollPitchRateKp * rtb_Switch_o +
                        Ctrl_DW.Integrator_DSTATE_h) + rtb_Integrator_j;

    // Saturate: '<S943>/Saturation'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController_UpperSa_p) {
      rtb_Integrator_b = Ctrl_P.DiscretePIDController_UpperSa_p;
    } else if (rtb_SignPreSat_f < Ctrl_P.DiscretePIDController_LowerSa_b) {
      rtb_Integrator_b = Ctrl_P.DiscretePIDController_LowerSa_b;
    } else {
      rtb_Integrator_b = rtb_SignPreSat_f;
    }

    // End of Saturate: '<S943>/Saturation'

    // Gain: '<S889>/Proportional Gain' incorporates:
    //   Gain: '<S794>/Scale roll1'
    //   Inport: '<Root>/RPY'
    //   Sum: '<S794>/Sum3'

    rtb_SignPreIntegrator = (RollPitchMax * rtb_IntegralGain_a - Ctrl_U.RPY[1]) *
      RollPitchKp;

    // Saturate: '<S891>/Saturation'
    if (rtb_SignPreIntegrator > RollPitchRateMax) {
      rtb_SignPreIntegrator = RollPitchRateMax;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController1_Lower_de) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController1_Lower_de;
      }
    }

    // End of Saturate: '<S891>/Saturation'

    // Sum: '<S794>/Sum1' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_p = rtb_SignPreIntegrator - Ctrl_U.dRPY[1];

    // Gain: '<S839>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S831>/Filter'
    //   Gain: '<S830>/Derivative Gain'
    //   Sum: '<S831>/SumD'

    rtb_Integrator = (RollPitchRateKd * rtb_IntegralGain_p -
                      Ctrl_DW.Filter_DSTATE_oq) *
      Ctrl_P.DiscretePIDController_N_hn;

    // Sum: '<S845>/Sum' incorporates:
    //   DiscreteIntegrator: '<S836>/Integrator'
    //   Gain: '<S841>/Proportional Gain'

    rtb_SignPreSat_iz = (RollPitchRateKp * rtb_IntegralGain_p +
                         Ctrl_DW.Integrator_DSTATE_h0) + rtb_Integrator;

    // Saturate: '<S843>/Saturation'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController_UpperSa_i) {
      rtb_Integrator_i = Ctrl_P.DiscretePIDController_UpperSa_i;
    } else if (rtb_SignPreSat_iz < Ctrl_P.DiscretePIDController_LowerSa_p) {
      rtb_Integrator_i = Ctrl_P.DiscretePIDController_LowerSa_p;
    } else {
      rtb_Integrator_i = rtb_SignPreSat_iz;
    }

    // End of Saturate: '<S843>/Saturation'

    // DeadZone: '<S796>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End_h) {
      rtb_ZeroGain_m4 = rtb_Rudder - Ctrl_P.DeadZone_End_h;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start_l) {
      rtb_ZeroGain_m4 = 0.0F;
    } else {
      rtb_ZeroGain_m4 = rtb_Rudder - Ctrl_P.DeadZone_Start_l;
    }

    // End of DeadZone: '<S796>/Dead Zone'

    // Sum: '<S796>/Sum' incorporates:
    //   Gain: '<S796>/Scale roll2'
    //   Inport: '<Root>/dRPY'

    rtb_ZeroGain_m4 = YawRateMax * rtb_ZeroGain_m4 - Ctrl_U.dRPY[2];

    // Sum: '<S1044>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1035>/Integrator'
    //   Gain: '<S1040>/Proportional Gain'

    rtb_FilterCoefficient_od = YawRateKp * rtb_ZeroGain_m4 +
      Ctrl_DW.Integrator_DSTATE_o;

    // Saturate: '<S1042>/Saturation'
    if (rtb_FilterCoefficient_od > Ctrl_P.DiscretePIDController_UpperSa_k) {
      rtb_Limit3_c = Ctrl_P.DiscretePIDController_UpperSa_k;
    } else if (rtb_FilterCoefficient_od < Ctrl_P.DiscretePIDController_LowerSa_f)
    {
      rtb_Limit3_c = Ctrl_P.DiscretePIDController_LowerSa_f;
    } else {
      rtb_Limit3_c = rtb_FilterCoefficient_od;
    }

    // End of Saturate: '<S1042>/Saturation'

    // Sum: '<S793>/Add1' incorporates:
    //   Sum: '<S793>/Add2'

    rtb_SignPreIntegrator = rtb_DeadZone_f - rtb_Integrator_b;
    rtb_SignPreSat = (rtb_SignPreIntegrator + rtb_Integrator_i) + rtb_Limit3_c;

    // Sum: '<S793>/Add2'
    rtb_Integrator_m = (rtb_SignPreIntegrator - rtb_Integrator_i) - rtb_Limit3_c;

    // Sum: '<S793>/Add3' incorporates:
    //   Sum: '<S793>/Add4'

    rtb_Integrator_b += rtb_DeadZone_f;
    rtb_IntegralGain_c = (rtb_Integrator_b + rtb_Integrator_i) - rtb_Limit3_c;

    // Sum: '<S793>/Add4'
    rtb_DeadZone_f = (rtb_Integrator_b - rtb_Integrator_i) + rtb_Limit3_c;

    // Saturate: '<S797>/Limit3'
    if (rtb_IntegralGain_c > Ctrl_P.Limit3_UpperSat_b5) {
      rtb_IntegralGain_c = Ctrl_P.Limit3_UpperSat_b5;
    } else {
      if (rtb_IntegralGain_c < Ctrl_P.Limit3_LowerSat_jv) {
        rtb_IntegralGain_c = Ctrl_P.Limit3_LowerSat_jv;
      }
    }

    // End of Saturate: '<S797>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S797>/Constant'
    //   Gain: '<S797>/Gain'
    //   Sum: '<S797>/Subtract'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_o * rtb_IntegralGain_c +
      Ctrl_P.Constant_Value_p4;

    // Saturate: '<S798>/Limit3'
    if (rtb_SignPreSat > Ctrl_P.Limit3_UpperSat_gu) {
      rtb_SignPreSat = Ctrl_P.Limit3_UpperSat_gu;
    } else {
      if (rtb_SignPreSat < Ctrl_P.Limit3_LowerSat_dd) {
        rtb_SignPreSat = Ctrl_P.Limit3_LowerSat_dd;
      }
    }

    // End of Saturate: '<S798>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S798>/Constant'
    //   Gain: '<S798>/Gain'
    //   Sum: '<S798>/Subtract'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_d * rtb_SignPreSat + Ctrl_P.Constant_Value_co;

    // Saturate: '<S799>/Limit3'
    if (rtb_Integrator_m > Ctrl_P.Limit3_UpperSat_kf) {
      rtb_Integrator_m = Ctrl_P.Limit3_UpperSat_kf;
    } else {
      if (rtb_Integrator_m < Ctrl_P.Limit3_LowerSat_du) {
        rtb_Integrator_m = Ctrl_P.Limit3_LowerSat_du;
      }
    }

    // End of Saturate: '<S799>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S799>/Constant'
    //   Gain: '<S799>/Gain'
    //   Sum: '<S799>/Subtract'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_i * rtb_Integrator_m +
      Ctrl_P.Constant_Value_oi;

    // Saturate: '<S800>/Limit3'
    if (rtb_DeadZone_f > Ctrl_P.Limit3_UpperSat_n) {
      rtb_DeadZone_f = Ctrl_P.Limit3_UpperSat_n;
    } else {
      if (rtb_DeadZone_f < Ctrl_P.Limit3_LowerSat_b) {
        rtb_DeadZone_f = Ctrl_P.Limit3_LowerSat_b;
      }
    }

    // End of Saturate: '<S800>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S800>/Constant'
    //   Gain: '<S800>/Gain'
    //   Sum: '<S800>/Subtract'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_m5 * rtb_DeadZone_f +
      Ctrl_P.Constant_Value_aw;

    // Gain: '<S827>/ZeroGain'
    rtb_SignPreSat = Ctrl_P.ZeroGain_Gain_gv * rtb_SignPreSat_iz;

    // DeadZone: '<S829>/DeadZone'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController_UpperSa_i) {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController_UpperSa_i;
    } else if (rtb_SignPreSat_iz >= Ctrl_P.DiscretePIDController_LowerSa_p) {
      rtb_SignPreSat_iz = 0.0F;
    } else {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController_LowerSa_p;
    }

    // End of DeadZone: '<S829>/DeadZone'

    // RelationalOperator: '<S827>/NotEqual'
    rtb_NotEqual_e1 = (rtb_SignPreSat != rtb_SignPreSat_iz);

    // Signum: '<S827>/SignPreSat'
    if (rtb_SignPreSat_iz < 0.0F) {
      rtb_SignPreSat_iz = -1.0F;
    } else {
      if (rtb_SignPreSat_iz > 0.0F) {
        rtb_SignPreSat_iz = 1.0F;
      }
    }

    // End of Signum: '<S827>/SignPreSat'

    // Gain: '<S833>/Integral Gain'
    rtb_IntegralGain_p *= RollPitchRateKi;

    // Gain: '<S927>/ZeroGain'
    rtb_SignPreSat = Ctrl_P.ZeroGain_Gain_nb * rtb_SignPreSat_f;

    // DeadZone: '<S929>/DeadZone'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController_UpperSa_p) {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController_UpperSa_p;
    } else if (rtb_SignPreSat_f >= Ctrl_P.DiscretePIDController_LowerSa_b) {
      rtb_SignPreSat_f = 0.0F;
    } else {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController_LowerSa_b;
    }

    // End of DeadZone: '<S929>/DeadZone'

    // RelationalOperator: '<S927>/NotEqual'
    rtb_NotEqual_kp = (rtb_SignPreSat != rtb_SignPreSat_f);

    // Signum: '<S927>/SignPreSat'
    if (rtb_SignPreSat_f < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else {
      if (rtb_SignPreSat_f > 0.0F) {
        rtb_SignPreSat_f = 1.0F;
      }
    }

    // End of Signum: '<S927>/SignPreSat'

    // Gain: '<S933>/Integral Gain'
    rtb_Switch_o *= RollPitchRateKi;

    // Gain: '<S1026>/ZeroGain'
    rtb_SignPreSat = Ctrl_P.ZeroGain_Gain_gq * rtb_FilterCoefficient_od;

    // DeadZone: '<S1028>/DeadZone'
    if (rtb_FilterCoefficient_od > Ctrl_P.DiscretePIDController_UpperSa_k) {
      rtb_FilterCoefficient_od -= Ctrl_P.DiscretePIDController_UpperSa_k;
    } else if (rtb_FilterCoefficient_od >=
               Ctrl_P.DiscretePIDController_LowerSa_f) {
      rtb_FilterCoefficient_od = 0.0F;
    } else {
      rtb_FilterCoefficient_od -= Ctrl_P.DiscretePIDController_LowerSa_f;
    }

    // End of DeadZone: '<S1028>/DeadZone'

    // RelationalOperator: '<S1026>/NotEqual'
    rtb_NotEqual_el = (rtb_SignPreSat != rtb_FilterCoefficient_od);

    // Signum: '<S1026>/SignPreSat'
    if (rtb_FilterCoefficient_od < 0.0F) {
      rtb_FilterCoefficient_od = -1.0F;
    } else {
      if (rtb_FilterCoefficient_od > 0.0F) {
        rtb_FilterCoefficient_od = 1.0F;
      }
    }

    // End of Signum: '<S1026>/SignPreSat'

    // Gain: '<S1032>/Integral Gain'
    rtb_ZeroGain_m4 *= YawRateKi;

    // DataTypeConversion: '<S927>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_f), 256.0));

    // Signum: '<S927>/SignPreIntegrator'
    if (rtb_Switch_o < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else if (rtb_Switch_o > 0.0F) {
      rtb_SignPreSat_f = 1.0F;
    } else {
      rtb_SignPreSat_f = rtb_Switch_o;
    }

    // End of Signum: '<S927>/SignPreIntegrator'

    // DataTypeConversion: '<S927>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_SignPreSat_f),
      256.0));

    // Switch: '<S927>/Switch' incorporates:
    //   Constant: '<S927>/Constant1'
    //   DataTypeConversion: '<S927>/DataTypeConv1'
    //   DataTypeConversion: '<S927>/DataTypeConv2'
    //   Logic: '<S927>/AND3'
    //   RelationalOperator: '<S927>/Equal1'

    if (rtb_NotEqual_kp && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Switch_o = Ctrl_P.Constant1_Value_o;
    }

    // End of Switch: '<S927>/Switch'

    // Update for DiscreteIntegrator: '<S936>/Integrator'
    Ctrl_DW.Integrator_DSTATE_h += Ctrl_P.Integrator_gainval_j * rtb_Switch_o;

    // Update for DiscreteIntegrator: '<S931>/Filter'
    Ctrl_DW.Filter_DSTATE_c += Ctrl_P.Filter_gainval_j * rtb_Integrator_j;

    // DataTypeConversion: '<S827>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_iz), 256.0));

    // Signum: '<S827>/SignPreIntegrator'
    if (rtb_IntegralGain_p < 0.0F) {
      rtb_Integrator_j = -1.0F;
    } else if (rtb_IntegralGain_p > 0.0F) {
      rtb_Integrator_j = 1.0F;
    } else {
      rtb_Integrator_j = rtb_IntegralGain_p;
    }

    // End of Signum: '<S827>/SignPreIntegrator'

    // DataTypeConversion: '<S827>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Integrator_j),
      256.0));

    // Switch: '<S827>/Switch' incorporates:
    //   Constant: '<S827>/Constant1'
    //   DataTypeConversion: '<S827>/DataTypeConv1'
    //   DataTypeConversion: '<S827>/DataTypeConv2'
    //   Logic: '<S827>/AND3'
    //   RelationalOperator: '<S827>/Equal1'

    if (rtb_NotEqual_e1 && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_IntegralGain_p = Ctrl_P.Constant1_Value_i;
    }

    // End of Switch: '<S827>/Switch'

    // Update for DiscreteIntegrator: '<S836>/Integrator'
    Ctrl_DW.Integrator_DSTATE_h0 += Ctrl_P.Integrator_gainval_i *
      rtb_IntegralGain_p;

    // Update for DiscreteIntegrator: '<S831>/Filter'
    Ctrl_DW.Filter_DSTATE_oq += Ctrl_P.Filter_gainval_p * rtb_Integrator;

    // DataTypeConversion: '<S1026>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_FilterCoefficient_od), 256.0));

    // Signum: '<S1026>/SignPreIntegrator'
    if (rtb_ZeroGain_m4 < 0.0F) {
      rtb_Integrator_b = -1.0F;
    } else if (rtb_ZeroGain_m4 > 0.0F) {
      rtb_Integrator_b = 1.0F;
    } else {
      rtb_Integrator_b = rtb_ZeroGain_m4;
    }

    // End of Signum: '<S1026>/SignPreIntegrator'

    // DataTypeConversion: '<S1026>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Integrator_b),
      256.0));

    // Switch: '<S1026>/Switch' incorporates:
    //   Constant: '<S1026>/Constant1'
    //   DataTypeConversion: '<S1026>/DataTypeConv1'
    //   DataTypeConversion: '<S1026>/DataTypeConv2'
    //   Logic: '<S1026>/AND3'
    //   RelationalOperator: '<S1026>/Equal1'

    if (rtb_NotEqual_el && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_ZeroGain_m4 = Ctrl_P.Constant1_Value_m;
    }

    // End of Switch: '<S1026>/Switch'

    // Update for DiscreteIntegrator: '<S1035>/Integrator'
    Ctrl_DW.Integrator_DSTATE_o += Ctrl_P.Integrator_gainval_im *
      rtb_ZeroGain_m4;
  } else {
    Ctrl_DW.RollPitchCtrl_MODE = false;
  }

  // End of Outputs for SubSystem: '<S1>/RollPitchCtrl'

  // Outputs for Enabled SubSystem: '<S1>/VelocityCtrl' incorporates:
  //   EnablePort: '<S10>/Enable'

  if (Ctrl_B.VelocityMode) {
    if (!Ctrl_DW.VelocityCtrl_MODE) {
      // InitializeConditions for DiscreteIntegrator: '<S1092>/Integrator'
      Ctrl_DW.Integrator_DSTATE = Ctrl_P.DiscretePIDController1_Initia_c;

      // InitializeConditions for DiscreteIntegrator: '<S1399>/Integrator'
      Ctrl_DW.Integrator_DSTATE_d = Ctrl_P.DiscretePIDController2_Initia_k;

      // InitializeConditions for DiscreteIntegrator: '<S1349>/Integrator'
      Ctrl_DW.Integrator_DSTATE_b = Ctrl_P.DiscretePIDController1_Initia_j;

      // InitializeConditions for DiscreteIntegrator: '<S1248>/Integrator'
      Ctrl_DW.Integrator_DSTATE_e = Ctrl_P.DiscretePIDController_Initia_jc;

      // InitializeConditions for DiscreteIntegrator: '<S1243>/Filter'
      Ctrl_DW.Filter_DSTATE = Ctrl_P.DiscretePIDController_Initial_j;

      // InitializeConditions for DiscreteIntegrator: '<S1148>/Integrator'
      Ctrl_DW.Integrator_DSTATE_n = Ctrl_P.DiscretePIDController_Initia_lr;

      // InitializeConditions for DiscreteIntegrator: '<S1143>/Filter'
      Ctrl_DW.Filter_DSTATE_o = Ctrl_P.DiscretePIDController_Initia_nr;

      // InitializeConditions for DiscreteIntegrator: '<S1057>/Discrete-Time Integrator' 
      Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

      // InitializeConditions for DiscreteIntegrator: '<S1452>/Integrator'
      Ctrl_DW.Integrator_DSTATE_m = Ctrl_P.DiscretePIDController_Initi_c5w;
      Ctrl_DW.VelocityCtrl_MODE = true;
    }

    // Bias: '<S1052>/Bias'
    rtb_Polynomial += Ctrl_P.Bias_Bias;

    // DeadZone: '<S1052>/Dead Zone'
    if (rtb_Polynomial > Ctrl_P.DeadZone_End_b) {
      rtb_Polynomial -= Ctrl_P.DeadZone_End_b;
    } else if (rtb_Polynomial >= Ctrl_P.DeadZone_Start_p) {
      rtb_Polynomial = 0.0F;
    } else {
      rtb_Polynomial -= Ctrl_P.DeadZone_Start_p;
    }

    // End of DeadZone: '<S1052>/Dead Zone'

    // Gain: '<S1052>/Scale Vel'
    Ctrl_B.VertVelRef = Ctrl_P.ScaleVel_Gain_a * rtb_Polynomial;

    // Saturate: '<S1052>/Fix Faulty Baro'
    if (rtb_Gain > Ctrl_P.FixFaultyBaro_UpperSat_d) {
      rtb_Polynomial = Ctrl_P.FixFaultyBaro_UpperSat_d;
    } else if (rtb_Gain < Ctrl_P.FixFaultyBaro_LowerSat_o) {
      rtb_Polynomial = Ctrl_P.FixFaultyBaro_LowerSat_o;
    } else {
      rtb_Polynomial = rtb_Gain;
    }

    // End of Saturate: '<S1052>/Fix Faulty Baro'

    // Sum: '<S1052>/Sum3'
    rtb_Polynomial = Ctrl_B.VertVelRef - rtb_Polynomial;

    // Sum: '<S1101>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1092>/Integrator'
    //   Gain: '<S1097>/Proportional Gain'

    rtb_SignPreSat_iz = AltRateKp * rtb_Polynomial + Ctrl_DW.Integrator_DSTATE;

    // Saturate: '<S1099>/Saturation'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController1_UpperS_l) {
      rtb_IntegralGain_p = Ctrl_P.DiscretePIDController1_UpperS_l;
    } else if (rtb_SignPreSat_iz < Ctrl_P.DiscretePIDController1_LowerS_b) {
      rtb_IntegralGain_p = Ctrl_P.DiscretePIDController1_LowerS_b;
    } else {
      rtb_IntegralGain_p = rtb_SignPreSat_iz;
    }

    // End of Saturate: '<S1099>/Saturation'

    // Bias: '<S1052>/Bias1'
    Ctrl_B.VertVelOut = rtb_IntegralGain_p + AltRateBias;

    // Gain: '<S1083>/ZeroGain'
    rtb_ZeroGain_m4 = Ctrl_P.ZeroGain_Gain_ez * rtb_SignPreSat_iz;

    // DeadZone: '<S1085>/DeadZone'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController1_UpperS_l) {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController1_UpperS_l;
    } else if (rtb_SignPreSat_iz >= Ctrl_P.DiscretePIDController1_LowerS_b) {
      rtb_SignPreSat_iz = 0.0F;
    } else {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController1_LowerS_b;
    }

    // End of DeadZone: '<S1085>/DeadZone'

    // RelationalOperator: '<S1083>/NotEqual'
    rtb_NotEqual_e1 = (rtb_ZeroGain_m4 != rtb_SignPreSat_iz);

    // Signum: '<S1083>/SignPreSat'
    if (rtb_SignPreSat_iz < 0.0F) {
      rtb_SignPreSat_iz = -1.0F;
    } else {
      if (rtb_SignPreSat_iz > 0.0F) {
        rtb_SignPreSat_iz = 1.0F;
      }
    }

    // End of Signum: '<S1083>/SignPreSat'

    // Gain: '<S1089>/Integral Gain'
    rtb_Polynomial *= AltRateKi;

    // DataTypeConversion: '<S1083>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_iz), 256.0));

    // Signum: '<S1083>/SignPreIntegrator'
    if (rtb_Polynomial < 0.0F) {
      rtb_IntegralGain_p = -1.0F;
    } else if (rtb_Polynomial > 0.0F) {
      rtb_IntegralGain_p = 1.0F;
    } else {
      rtb_IntegralGain_p = rtb_Polynomial;
    }

    // End of Signum: '<S1083>/SignPreIntegrator'

    // DataTypeConversion: '<S1083>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_IntegralGain_p),
      256.0));

    // Switch: '<S1083>/Switch' incorporates:
    //   Constant: '<S1083>/Constant1'
    //   DataTypeConversion: '<S1083>/DataTypeConv1'
    //   DataTypeConversion: '<S1083>/DataTypeConv2'
    //   Logic: '<S1083>/AND3'
    //   RelationalOperator: '<S1083>/Equal1'

    if (rtb_NotEqual_e1 && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Integrator_b = Ctrl_P.Constant1_Value_ok;
    } else {
      rtb_Integrator_b = rtb_Polynomial;
    }

    // End of Switch: '<S1083>/Switch'

    // Saturate: '<S1052>/Limit Output'
    if (Ctrl_B.VertVelOut > Ctrl_P.LimitOutput_UpperSat_h) {
      rtb_FilterCoefficient_od = Ctrl_P.LimitOutput_UpperSat_h;
    } else if (Ctrl_B.VertVelOut < Ctrl_P.LimitOutput_LowerSat_f) {
      rtb_FilterCoefficient_od = Ctrl_P.LimitOutput_LowerSat_f;
    } else {
      rtb_FilterCoefficient_od = Ctrl_B.VertVelOut;
    }

    // End of Saturate: '<S1052>/Limit Output'

    // Gain: '<S10>/Gain2'
    rtb_Polynomial = Ctrl_P.Gain2_Gain_j * rtb_IntegralGain_a;

    // Gain: '<S1313>/Gain1' incorporates:
    //   Inport: '<Root>/RPY'

    rtb_SignPreSat_iz = Ctrl_P.Gain1_Gain_k * Ctrl_U.RPY[2];

    // Trigonometry: '<S1056>/Trigonometric Function1' incorporates:
    //   Trigonometry: '<S1056>/Trigonometric Function'

    rtb_SignPreSat_f = static_cast<real32_T>(sin(static_cast<real_T>
      (rtb_SignPreSat_iz)));
    rtb_IntegralGain_p = static_cast<real32_T>(cos(static_cast<real_T>
      (rtb_SignPreSat_iz)));

    // Sum: '<S1056>/Sum2' incorporates:
    //   Gain: '<S1056>/Gain'
    //   Inport: '<Root>/FlatVe'
    //   Product: '<S1056>/Product6'
    //   Product: '<S1056>/Product7'
    //   Sum: '<S1056>/Add3'
    //   Trigonometry: '<S1056>/Trigonometric Function1'

    rtb_IntegralGain_c = (rtb_Polynomial * rtb_IntegralGain_p - rtb_SignPreSat_f
                          * rtb_SignPreSat_n) * VelMax - Ctrl_U.FlatVe[0];

    // Sum: '<S1408>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1399>/Integrator'
    //   Gain: '<S1404>/Proportional Gain'

    rtb_SignPreSat = VelKp * rtb_IntegralGain_c + Ctrl_DW.Integrator_DSTATE_d;

    // Saturate: '<S1406>/Saturation'
    if (rtb_SignPreSat > Ctrl_P.DiscretePIDController2_UpperS_i) {
      rtb_Limit3_c = Ctrl_P.DiscretePIDController2_UpperS_i;
    } else if (rtb_SignPreSat < Ctrl_P.DiscretePIDController2_LowerS_a) {
      rtb_Limit3_c = Ctrl_P.DiscretePIDController2_LowerS_a;
    } else {
      rtb_Limit3_c = rtb_SignPreSat;
    }

    // End of Saturate: '<S1406>/Saturation'

    // Sum: '<S1056>/Sum1' incorporates:
    //   Gain: '<S1056>/Gain1'
    //   Inport: '<Root>/FlatVe'
    //   Product: '<S1056>/Product4'
    //   Product: '<S1056>/Product5'
    //   Sum: '<S1056>/Add2'
    //   Trigonometry: '<S1056>/Trigonometric Function1'

    rtb_Integrator_i = (rtb_Polynomial * rtb_SignPreSat_f + rtb_IntegralGain_p *
                        rtb_SignPreSat_n) * VelMax - Ctrl_U.FlatVe[1];

    // Sum: '<S1358>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1349>/Integrator'
    //   Gain: '<S1354>/Proportional Gain'

    rtb_Polynomial = VelKp * rtb_Integrator_i + Ctrl_DW.Integrator_DSTATE_b;

    // Saturate: '<S1356>/Saturation'
    if (rtb_Polynomial > Ctrl_P.DiscretePIDController1_UpperS_n) {
      rtb_IntegralGain_a = Ctrl_P.DiscretePIDController1_UpperS_n;
    } else if (rtb_Polynomial < Ctrl_P.DiscretePIDController1_LowerS_e) {
      rtb_IntegralGain_a = Ctrl_P.DiscretePIDController1_LowerS_e;
    } else {
      rtb_IntegralGain_a = rtb_Polynomial;
    }

    // End of Saturate: '<S1356>/Saturation'

    // Gain: '<S1055>/Scale roll2' incorporates:
    //   Product: '<S1056>/Product2'
    //   Product: '<S1056>/Product3'
    //   Sum: '<S1056>/Add1'

    Ctrl_B.RollRef = (rtb_IntegralGain_p * rtb_IntegralGain_a - rtb_Limit3_c *
                      rtb_SignPreSat_f) * RollPitchMax;

    // Gain: '<S1301>/Proportional Gain' incorporates:
    //   Inport: '<Root>/RPY'
    //   Sum: '<S1055>/Sum3'

    rtb_SignPreIntegrator = (Ctrl_B.RollRef - Ctrl_U.RPY[0]) * RollPitchKp;

    // Saturate: '<S1303>/Saturation'
    if (rtb_SignPreIntegrator > RollPitchRateMax) {
      // Saturate: '<S1303>/Saturation'
      Ctrl_B.dRollRef = RollPitchRateMax;
    } else if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController1_Lower_pq) {
      // Saturate: '<S1303>/Saturation'
      Ctrl_B.dRollRef = Ctrl_P.DiscretePIDController1_Lower_pq;
    } else {
      // Saturate: '<S1303>/Saturation'
      Ctrl_B.dRollRef = rtb_SignPreIntegrator;
    }

    // End of Saturate: '<S1303>/Saturation'

    // Sum: '<S1055>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_ZeroGain_m4 = Ctrl_B.dRollRef - Ctrl_U.dRPY[0];

    // Gain: '<S1251>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S1243>/Filter'
    //   Gain: '<S1242>/Derivative Gain'
    //   Sum: '<S1243>/SumD'

    rtb_Integrator_m = (RollPitchRateKd * rtb_ZeroGain_m4 -
                        Ctrl_DW.Filter_DSTATE) *
      Ctrl_P.DiscretePIDController_N_n;

    // Sum: '<S1257>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1248>/Integrator'
    //   Gain: '<S1253>/Proportional Gain'

    rtb_SignPreSat_n = (RollPitchRateKp * rtb_ZeroGain_m4 +
                        Ctrl_DW.Integrator_DSTATE_e) + rtb_Integrator_m;

    // Saturate: '<S1255>/Saturation'
    if (rtb_SignPreSat_n > Ctrl_P.DiscretePIDController_UpperS_ii) {
      // Saturate: '<S1255>/Saturation'
      Ctrl_B.RollOut = Ctrl_P.DiscretePIDController_UpperS_ii;
    } else if (rtb_SignPreSat_n < Ctrl_P.DiscretePIDController_LowerS_ok) {
      // Saturate: '<S1255>/Saturation'
      Ctrl_B.RollOut = Ctrl_P.DiscretePIDController_LowerS_ok;
    } else {
      // Saturate: '<S1255>/Saturation'
      Ctrl_B.RollOut = rtb_SignPreSat_n;
    }

    // End of Saturate: '<S1255>/Saturation'

    // Gain: '<S1054>/Scale roll1' incorporates:
    //   Product: '<S1056>/Product'
    //   Product: '<S1056>/Product1'
    //   Sum: '<S1056>/Add'

    Ctrl_B.PitchRef = ((0.0F - rtb_Limit3_c * rtb_IntegralGain_p) -
                       rtb_SignPreSat_f * rtb_IntegralGain_a) * RollPitchMax;

    // Gain: '<S1201>/Proportional Gain' incorporates:
    //   Inport: '<Root>/RPY'
    //   Sum: '<S1054>/Sum3'

    rtb_SignPreIntegrator = (Ctrl_B.PitchRef - Ctrl_U.RPY[1]) * RollPitchKp;

    // Saturate: '<S1203>/Saturation'
    if (rtb_SignPreIntegrator > RollPitchRateMax) {
      // Saturate: '<S1203>/Saturation'
      Ctrl_B.dPitchRef = RollPitchRateMax;
    } else if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController1_LowerS_f) {
      // Saturate: '<S1203>/Saturation'
      Ctrl_B.dPitchRef = Ctrl_P.DiscretePIDController1_LowerS_f;
    } else {
      // Saturate: '<S1203>/Saturation'
      Ctrl_B.dPitchRef = rtb_SignPreIntegrator;
    }

    // End of Saturate: '<S1203>/Saturation'

    // Sum: '<S1054>/Sum1' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_a = Ctrl_B.dPitchRef - Ctrl_U.dRPY[1];

    // Gain: '<S1151>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S1143>/Filter'
    //   Gain: '<S1142>/Derivative Gain'
    //   Sum: '<S1143>/SumD'

    rtb_Integrator_j = (RollPitchRateKd * rtb_IntegralGain_a -
                        Ctrl_DW.Filter_DSTATE_o) *
      Ctrl_P.DiscretePIDController_N_g;

    // Sum: '<S1157>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1148>/Integrator'
    //   Gain: '<S1153>/Proportional Gain'

    rtb_SignPreSat_iz = (RollPitchRateKp * rtb_IntegralGain_a +
                         Ctrl_DW.Integrator_DSTATE_n) + rtb_Integrator_j;

    // Saturate: '<S1155>/Saturation'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController_UpperSa_m) {
      // Saturate: '<S1155>/Saturation'
      Ctrl_B.PitchOut = Ctrl_P.DiscretePIDController_UpperSa_m;
    } else if (rtb_SignPreSat_iz < Ctrl_P.DiscretePIDController_LowerS_a3) {
      // Saturate: '<S1155>/Saturation'
      Ctrl_B.PitchOut = Ctrl_P.DiscretePIDController_LowerS_a3;
    } else {
      // Saturate: '<S1155>/Saturation'
      Ctrl_B.PitchOut = rtb_SignPreSat_iz;
    }

    // End of Saturate: '<S1155>/Saturation'

    // DiscreteIntegrator: '<S1057>/Discrete-Time Integrator' incorporates:
    //   Inport: '<Root>/RPY'

    if (Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
      Ctrl_DW.DiscreteTimeIntegrator_DSTATE = Ctrl_U.RPY[2];
    }

    // MATLAB Function: '<S1057>/Correct Yaw1' incorporates:
    //   DiscreteIntegrator: '<S1057>/Discrete-Time Integrator'
    //   Inport: '<Root>/RPY'
    //   Sum: '<S1057>/Sum3'

    Ctrl_CorrectYaw1(Ctrl_DW.DiscreteTimeIntegrator_DSTATE - Ctrl_U.RPY[2],
                     &Ctrl_B.sf_CorrectYaw1_l);

    // Gain: '<S1505>/Proportional Gain'
    rtb_SignPreIntegrator = YawKp * Ctrl_B.sf_CorrectYaw1_l.y;

    // Saturate: '<S1507>/Saturation'
    if (rtb_SignPreIntegrator > YawRateMax) {
      rtb_SignPreIntegrator = YawRateMax;
    } else {
      if (rtb_SignPreIntegrator < Ctrl_P.DiscretePIDController3_LowerS_f) {
        rtb_SignPreIntegrator = Ctrl_P.DiscretePIDController3_LowerS_f;
      }
    }

    // End of Saturate: '<S1507>/Saturation'

    // Sum: '<S1057>/Sum' incorporates:
    //   Inport: '<Root>/dRPY'

    rtb_IntegralGain_p = rtb_SignPreIntegrator - Ctrl_U.dRPY[2];

    // Sum: '<S1461>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1452>/Integrator'
    //   Gain: '<S1457>/Proportional Gain'

    rtb_SignPreSat_f = YawRateKp * rtb_IntegralGain_p +
      Ctrl_DW.Integrator_DSTATE_m;

    // Saturate: '<S1459>/Saturation'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController_UpperS_nb) {
      rtb_Integrator = Ctrl_P.DiscretePIDController_UpperS_nb;
    } else if (rtb_SignPreSat_f < Ctrl_P.DiscretePIDController_LowerSa_m) {
      rtb_Integrator = Ctrl_P.DiscretePIDController_LowerSa_m;
    } else {
      rtb_Integrator = rtb_SignPreSat_f;
    }

    // End of Saturate: '<S1459>/Saturation'

    // Sum: '<S1053>/Add1' incorporates:
    //   Sum: '<S1053>/Add2'

    rtb_SignPreIntegrator = rtb_FilterCoefficient_od - Ctrl_B.RollOut;
    rtb_Limit3_c = (rtb_SignPreIntegrator + Ctrl_B.PitchOut) + rtb_Integrator;

    // Sum: '<S1053>/Add2'
    rtb_Switch_o = (rtb_SignPreIntegrator - Ctrl_B.PitchOut) - rtb_Integrator;

    // Sum: '<S1053>/Add3' incorporates:
    //   Sum: '<S1053>/Add4'

    rtb_FilterCoefficient_od += Ctrl_B.RollOut;
    rtb_DeadZone_f = (rtb_FilterCoefficient_od + Ctrl_B.PitchOut) -
      rtb_Integrator;

    // Sum: '<S1053>/Add4'
    rtb_FilterCoefficient_od = (rtb_FilterCoefficient_od - Ctrl_B.PitchOut) +
      rtb_Integrator;

    // Saturate: '<S1109>/Limit3'
    if (rtb_DeadZone_f > Ctrl_P.Limit3_UpperSat_p) {
      rtb_DeadZone_f = Ctrl_P.Limit3_UpperSat_p;
    } else {
      if (rtb_DeadZone_f < Ctrl_P.Limit3_LowerSat_it) {
        rtb_DeadZone_f = Ctrl_P.Limit3_LowerSat_it;
      }
    }

    // End of Saturate: '<S1109>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S1109>/Constant'
    //   Gain: '<S1109>/Gain'
    //   Sum: '<S1109>/Subtract'

    Ctrl_B.PWM1 = Ctrl_P.Gain_Gain_oa * rtb_DeadZone_f + Ctrl_P.Constant_Value_l;

    // Saturate: '<S1110>/Limit3'
    if (rtb_Limit3_c > Ctrl_P.Limit3_UpperSat_e) {
      rtb_Limit3_c = Ctrl_P.Limit3_UpperSat_e;
    } else {
      if (rtb_Limit3_c < Ctrl_P.Limit3_LowerSat_l) {
        rtb_Limit3_c = Ctrl_P.Limit3_LowerSat_l;
      }
    }

    // End of Saturate: '<S1110>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S1110>/Constant'
    //   Gain: '<S1110>/Gain'
    //   Sum: '<S1110>/Subtract'

    Ctrl_B.PWM2 = Ctrl_P.Gain_Gain_hh * rtb_Limit3_c + Ctrl_P.Constant_Value_b;

    // Saturate: '<S1111>/Limit3'
    if (rtb_Switch_o > Ctrl_P.Limit3_UpperSat_lo) {
      rtb_Switch_o = Ctrl_P.Limit3_UpperSat_lo;
    } else {
      if (rtb_Switch_o < Ctrl_P.Limit3_LowerSat_gb) {
        rtb_Switch_o = Ctrl_P.Limit3_LowerSat_gb;
      }
    }

    // End of Saturate: '<S1111>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S1111>/Constant'
    //   Gain: '<S1111>/Gain'
    //   Sum: '<S1111>/Subtract'

    Ctrl_B.PWM3 = Ctrl_P.Gain_Gain_do * rtb_Switch_o + Ctrl_P.Constant_Value_f;

    // Saturate: '<S1112>/Limit3'
    if (rtb_FilterCoefficient_od > Ctrl_P.Limit3_UpperSat_i) {
      rtb_FilterCoefficient_od = Ctrl_P.Limit3_UpperSat_i;
    } else {
      if (rtb_FilterCoefficient_od < Ctrl_P.Limit3_LowerSat_d4) {
        rtb_FilterCoefficient_od = Ctrl_P.Limit3_LowerSat_d4;
      }
    }

    // End of Saturate: '<S1112>/Limit3'

    // Merge generated from: '<S1>/Merge' incorporates:
    //   Constant: '<S1112>/Constant'
    //   Gain: '<S1112>/Gain'
    //   Sum: '<S1112>/Subtract'

    Ctrl_B.PWM4 = Ctrl_P.Gain_Gain_bo * rtb_FilterCoefficient_od +
      Ctrl_P.Constant_Value_d;

    // Gain: '<S1139>/ZeroGain'
    rtb_DeadZone_f = Ctrl_P.ZeroGain_Gain_o * rtb_SignPreSat_iz;

    // DeadZone: '<S1141>/DeadZone'
    if (rtb_SignPreSat_iz > Ctrl_P.DiscretePIDController_UpperSa_m) {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController_UpperSa_m;
    } else if (rtb_SignPreSat_iz >= Ctrl_P.DiscretePIDController_LowerS_a3) {
      rtb_SignPreSat_iz = 0.0F;
    } else {
      rtb_SignPreSat_iz -= Ctrl_P.DiscretePIDController_LowerS_a3;
    }

    // End of DeadZone: '<S1141>/DeadZone'

    // RelationalOperator: '<S1139>/NotEqual'
    rtb_NotEqual_e1 = (rtb_DeadZone_f != rtb_SignPreSat_iz);

    // Signum: '<S1139>/SignPreSat'
    if (rtb_SignPreSat_iz < 0.0F) {
      rtb_SignPreSat_iz = -1.0F;
    } else {
      if (rtb_SignPreSat_iz > 0.0F) {
        rtb_SignPreSat_iz = 1.0F;
      }
    }

    // End of Signum: '<S1139>/SignPreSat'

    // Gain: '<S1145>/Integral Gain'
    rtb_IntegralGain_a *= RollPitchRateKi;

    // Gain: '<S1239>/ZeroGain'
    rtb_DeadZone_f = Ctrl_P.ZeroGain_Gain_e2 * rtb_SignPreSat_n;

    // DeadZone: '<S1241>/DeadZone'
    if (rtb_SignPreSat_n > Ctrl_P.DiscretePIDController_UpperS_ii) {
      rtb_SignPreSat_n -= Ctrl_P.DiscretePIDController_UpperS_ii;
    } else if (rtb_SignPreSat_n >= Ctrl_P.DiscretePIDController_LowerS_ok) {
      rtb_SignPreSat_n = 0.0F;
    } else {
      rtb_SignPreSat_n -= Ctrl_P.DiscretePIDController_LowerS_ok;
    }

    // End of DeadZone: '<S1241>/DeadZone'

    // RelationalOperator: '<S1239>/NotEqual'
    rtb_NotEqual_kp = (rtb_DeadZone_f != rtb_SignPreSat_n);

    // Signum: '<S1239>/SignPreSat'
    if (rtb_SignPreSat_n < 0.0F) {
      rtb_SignPreSat_n = -1.0F;
    } else {
      if (rtb_SignPreSat_n > 0.0F) {
        rtb_SignPreSat_n = 1.0F;
      }
    }

    // End of Signum: '<S1239>/SignPreSat'

    // Gain: '<S1245>/Integral Gain'
    rtb_ZeroGain_m4 *= RollPitchRateKi;

    // Gain: '<S1340>/ZeroGain'
    rtb_DeadZone_f = Ctrl_P.ZeroGain_Gain_b * rtb_Polynomial;

    // DeadZone: '<S1342>/DeadZone'
    if (rtb_Polynomial > Ctrl_P.DiscretePIDController1_UpperS_n) {
      rtb_Polynomial -= Ctrl_P.DiscretePIDController1_UpperS_n;
    } else if (rtb_Polynomial >= Ctrl_P.DiscretePIDController1_LowerS_e) {
      rtb_Polynomial = 0.0F;
    } else {
      rtb_Polynomial -= Ctrl_P.DiscretePIDController1_LowerS_e;
    }

    // End of DeadZone: '<S1342>/DeadZone'

    // RelationalOperator: '<S1340>/NotEqual'
    rtb_NotEqual_el = (rtb_DeadZone_f != rtb_Polynomial);

    // Signum: '<S1340>/SignPreSat'
    if (rtb_Polynomial < 0.0F) {
      rtb_Polynomial = -1.0F;
    } else {
      if (rtb_Polynomial > 0.0F) {
        rtb_Polynomial = 1.0F;
      }
    }

    // End of Signum: '<S1340>/SignPreSat'

    // Gain: '<S1346>/Integral Gain'
    rtb_Integrator_i *= VelKi;

    // Gain: '<S1390>/ZeroGain'
    rtb_DeadZone_f = Ctrl_P.ZeroGain_Gain_ezr * rtb_SignPreSat;

    // DeadZone: '<S1392>/DeadZone'
    if (rtb_SignPreSat > Ctrl_P.DiscretePIDController2_UpperS_i) {
      rtb_SignPreSat -= Ctrl_P.DiscretePIDController2_UpperS_i;
    } else if (rtb_SignPreSat >= Ctrl_P.DiscretePIDController2_LowerS_a) {
      rtb_SignPreSat = 0.0F;
    } else {
      rtb_SignPreSat -= Ctrl_P.DiscretePIDController2_LowerS_a;
    }

    // End of DeadZone: '<S1392>/DeadZone'

    // RelationalOperator: '<S1390>/NotEqual'
    rtb_NotEqual_pr = (rtb_DeadZone_f != rtb_SignPreSat);

    // Signum: '<S1390>/SignPreSat'
    if (rtb_SignPreSat < 0.0F) {
      rtb_SignPreSat = -1.0F;
    } else {
      if (rtb_SignPreSat > 0.0F) {
        rtb_SignPreSat = 1.0F;
      }
    }

    // End of Signum: '<S1390>/SignPreSat'

    // Gain: '<S1396>/Integral Gain'
    rtb_IntegralGain_c *= VelKi;

    // Gain: '<S1443>/ZeroGain'
    rtb_DeadZone_f = Ctrl_P.ZeroGain_Gain_ny * rtb_SignPreSat_f;

    // DeadZone: '<S1445>/DeadZone'
    if (rtb_SignPreSat_f > Ctrl_P.DiscretePIDController_UpperS_nb) {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController_UpperS_nb;
    } else if (rtb_SignPreSat_f >= Ctrl_P.DiscretePIDController_LowerSa_m) {
      rtb_SignPreSat_f = 0.0F;
    } else {
      rtb_SignPreSat_f -= Ctrl_P.DiscretePIDController_LowerSa_m;
    }

    // End of DeadZone: '<S1445>/DeadZone'

    // RelationalOperator: '<S1443>/NotEqual'
    rtb_NotEqual_j = (rtb_DeadZone_f != rtb_SignPreSat_f);

    // Signum: '<S1443>/SignPreSat'
    if (rtb_SignPreSat_f < 0.0F) {
      rtb_SignPreSat_f = -1.0F;
    } else {
      if (rtb_SignPreSat_f > 0.0F) {
        rtb_SignPreSat_f = 1.0F;
      }
    }

    // End of Signum: '<S1443>/SignPreSat'

    // Gain: '<S1449>/Integral Gain'
    rtb_IntegralGain_p *= YawRateKi;

    // Update for DiscreteIntegrator: '<S1092>/Integrator'
    Ctrl_DW.Integrator_DSTATE += Ctrl_P.Integrator_gainval_be * rtb_Integrator_b;

    // DataTypeConversion: '<S1390>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat), 256.0));

    // Signum: '<S1390>/SignPreIntegrator'
    if (rtb_IntegralGain_c < 0.0F) {
      rtb_Integrator_b = -1.0F;
    } else if (rtb_IntegralGain_c > 0.0F) {
      rtb_Integrator_b = 1.0F;
    } else {
      rtb_Integrator_b = rtb_IntegralGain_c;
    }

    // End of Signum: '<S1390>/SignPreIntegrator'

    // DataTypeConversion: '<S1390>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Integrator_b),
      256.0));

    // Switch: '<S1390>/Switch' incorporates:
    //   Constant: '<S1390>/Constant1'
    //   DataTypeConversion: '<S1390>/DataTypeConv1'
    //   DataTypeConversion: '<S1390>/DataTypeConv2'
    //   Logic: '<S1390>/AND3'
    //   RelationalOperator: '<S1390>/Equal1'

    if (rtb_NotEqual_pr && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_IntegralGain_c = Ctrl_P.Constant1_Value_pl;
    }

    // End of Switch: '<S1390>/Switch'

    // Update for DiscreteIntegrator: '<S1399>/Integrator'
    Ctrl_DW.Integrator_DSTATE_d += Ctrl_P.Integrator_gainval_l *
      rtb_IntegralGain_c;

    // DataTypeConversion: '<S1340>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_Polynomial), 256.0));

    // Signum: '<S1340>/SignPreIntegrator'
    if (rtb_Integrator_i < 0.0F) {
      rtb_Polynomial = -1.0F;
    } else if (rtb_Integrator_i > 0.0F) {
      rtb_Polynomial = 1.0F;
    } else {
      rtb_Polynomial = rtb_Integrator_i;
    }

    // End of Signum: '<S1340>/SignPreIntegrator'

    // DataTypeConversion: '<S1340>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Polynomial), 256.0));

    // Switch: '<S1340>/Switch' incorporates:
    //   Constant: '<S1340>/Constant1'
    //   DataTypeConversion: '<S1340>/DataTypeConv1'
    //   DataTypeConversion: '<S1340>/DataTypeConv2'
    //   Logic: '<S1340>/AND3'
    //   RelationalOperator: '<S1340>/Equal1'

    if (rtb_NotEqual_el && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_Integrator_i = Ctrl_P.Constant1_Value_kj;
    }

    // End of Switch: '<S1340>/Switch'

    // Update for DiscreteIntegrator: '<S1349>/Integrator'
    Ctrl_DW.Integrator_DSTATE_b += Ctrl_P.Integrator_gainval_by *
      rtb_Integrator_i;

    // DataTypeConversion: '<S1239>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_n), 256.0));

    // Signum: '<S1239>/SignPreIntegrator'
    if (rtb_ZeroGain_m4 < 0.0F) {
      rtb_Integrator_b = -1.0F;
    } else if (rtb_ZeroGain_m4 > 0.0F) {
      rtb_Integrator_b = 1.0F;
    } else {
      rtb_Integrator_b = rtb_ZeroGain_m4;
    }

    // End of Signum: '<S1239>/SignPreIntegrator'

    // DataTypeConversion: '<S1239>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Integrator_b),
      256.0));

    // Switch: '<S1239>/Switch' incorporates:
    //   Constant: '<S1239>/Constant1'
    //   DataTypeConversion: '<S1239>/DataTypeConv1'
    //   DataTypeConversion: '<S1239>/DataTypeConv2'
    //   Logic: '<S1239>/AND3'
    //   RelationalOperator: '<S1239>/Equal1'

    if (rtb_NotEqual_kp && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_ZeroGain_m4 = Ctrl_P.Constant1_Value_l0;
    }

    // End of Switch: '<S1239>/Switch'

    // Update for DiscreteIntegrator: '<S1248>/Integrator'
    Ctrl_DW.Integrator_DSTATE_e += Ctrl_P.Integrator_gainval_h * rtb_ZeroGain_m4;

    // Update for DiscreteIntegrator: '<S1243>/Filter'
    Ctrl_DW.Filter_DSTATE += Ctrl_P.Filter_gainval_f * rtb_Integrator_m;

    // DataTypeConversion: '<S1139>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_iz), 256.0));

    // Signum: '<S1139>/SignPreIntegrator'
    if (rtb_IntegralGain_a < 0.0F) {
      rtb_SignPreSat_n = -1.0F;
    } else if (rtb_IntegralGain_a > 0.0F) {
      rtb_SignPreSat_n = 1.0F;
    } else {
      rtb_SignPreSat_n = rtb_IntegralGain_a;
    }

    // End of Signum: '<S1139>/SignPreIntegrator'

    // DataTypeConversion: '<S1139>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_SignPreSat_n),
      256.0));

    // Switch: '<S1139>/Switch' incorporates:
    //   Constant: '<S1139>/Constant1'
    //   DataTypeConversion: '<S1139>/DataTypeConv1'
    //   DataTypeConversion: '<S1139>/DataTypeConv2'
    //   Logic: '<S1139>/AND3'
    //   RelationalOperator: '<S1139>/Equal1'

    if (rtb_NotEqual_e1 && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>
          (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
          (static_cast<int8_T>(static_cast<uint8_T>(rtb_SignPreIntegrator)))) ==
         (tmp < 0.0F ? static_cast<int32_T>(static_cast<int8_T>
           (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
          static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_IntegralGain_a = Ctrl_P.Constant1_Value_k;
    }

    // End of Switch: '<S1139>/Switch'

    // Update for DiscreteIntegrator: '<S1148>/Integrator'
    Ctrl_DW.Integrator_DSTATE_n += Ctrl_P.Integrator_gainval_h3 *
      rtb_IntegralGain_a;

    // Update for DiscreteIntegrator: '<S1143>/Filter'
    Ctrl_DW.Filter_DSTATE_o += Ctrl_P.Filter_gainval_p4 * rtb_Integrator_j;

    // Update for DiscreteIntegrator: '<S1057>/Discrete-Time Integrator'
    Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

    // DeadZone: '<S1057>/Dead Zone'
    if (rtb_Rudder > Ctrl_P.DeadZone_End_p) {
      rtb_Rudder -= Ctrl_P.DeadZone_End_p;
    } else if (rtb_Rudder >= Ctrl_P.DeadZone_Start_b) {
      rtb_Rudder = 0.0F;
    } else {
      rtb_Rudder -= Ctrl_P.DeadZone_Start_b;
    }

    // End of DeadZone: '<S1057>/Dead Zone'

    // Update for DiscreteIntegrator: '<S1057>/Discrete-Time Integrator' incorporates:
    //   Gain: '<S1057>/Scale roll2'

    Ctrl_DW.DiscreteTimeIntegrator_DSTATE += Ctrl_P.Scaleroll2_Gain_m *
      rtb_Rudder * Ctrl_P.DiscreteTimeIntegrator_gainva_h;

    // DataTypeConversion: '<S1443>/DataTypeConv1'
    rtb_SignPreIntegrator = static_cast<real32_T>(fmod(static_cast<real_T>
      (rtb_SignPreSat_f), 256.0));

    // Signum: '<S1443>/SignPreIntegrator'
    if (rtb_IntegralGain_p < 0.0F) {
      rtb_Integrator_j = -1.0F;
    } else if (rtb_IntegralGain_p > 0.0F) {
      rtb_Integrator_j = 1.0F;
    } else {
      rtb_Integrator_j = rtb_IntegralGain_p;
    }

    // End of Signum: '<S1443>/SignPreIntegrator'

    // DataTypeConversion: '<S1443>/DataTypeConv2'
    tmp = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Integrator_j),
      256.0));

    // Switch: '<S1443>/Switch' incorporates:
    //   Constant: '<S1443>/Constant1'
    //   DataTypeConversion: '<S1443>/DataTypeConv1'
    //   DataTypeConversion: '<S1443>/DataTypeConv2'
    //   Logic: '<S1443>/AND3'
    //   RelationalOperator: '<S1443>/Equal1'

    if (rtb_NotEqual_j && ((rtb_SignPreIntegrator < 0.0F ? static_cast<int32_T>(
           static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_SignPreIntegrator)))) : static_cast<int32_T>
                            (static_cast<int8_T>(static_cast<uint8_T>
            (rtb_SignPreIntegrator)))) == (tmp < 0.0F ? static_cast<int32_T>(
           static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-tmp))))
          : static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))))))
    {
      rtb_IntegralGain_p = Ctrl_P.Constant1_Value_do;
    }

    // End of Switch: '<S1443>/Switch'

    // Update for DiscreteIntegrator: '<S1452>/Integrator'
    Ctrl_DW.Integrator_DSTATE_m += Ctrl_P.Integrator_gainval_lc *
      rtb_IntegralGain_p;
  } else {
    Ctrl_DW.VelocityCtrl_MODE = false;
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
  rtb_Polynomial = (Ctrl_P.Polynomial_Coefs[0] * rtb_Rudder +
                    Ctrl_P.Polynomial_Coefs[1]) * rtb_Rudder +
    Ctrl_P.Polynomial_Coefs[2];

  // End of Outputs for SubSystem: '<Root>/Ctrl'

  // Outport: '<Root>/PWM1'
  Ctrl_Y.PWM1 = Ctrl_B.PWM1;

  // Outport: '<Root>/PWM2'
  Ctrl_Y.PWM2 = Ctrl_B.PWM2;

  // Outport: '<Root>/PWM3'
  Ctrl_Y.PWM3 = Ctrl_B.PWM3;

  // Outport: '<Root>/PWM4'
  Ctrl_Y.PWM4 = Ctrl_B.PWM4;

  // Outport: '<Root>/Altitude' incorporates:
  //   Inport: '<Root>/GPSHeight'

  Ctrl_Y.Altitude = Ctrl_U.GPSHeight;

  // Outport: '<Root>/VertSpeed'
  Ctrl_Y.VertSpeed = rtb_Gain;

  // Outputs for Atomic SubSystem: '<Root>/Ctrl'
  // Saturate: '<S11>/Saturation1'
  if (rtb_Polynomial > Ctrl_P.Saturation1_UpperSat_o) {
    // Outport: '<Root>/FuelPercent'
    Ctrl_Y.FuelPercent = Ctrl_P.Saturation1_UpperSat_o;
  } else if (rtb_Polynomial < Ctrl_P.Saturation1_LowerSat_o) {
    // Outport: '<Root>/FuelPercent'
    Ctrl_Y.FuelPercent = Ctrl_P.Saturation1_LowerSat_o;
  } else {
    // Outport: '<Root>/FuelPercent'
    Ctrl_Y.FuelPercent = rtb_Polynomial;
  }

  // End of Saturate: '<S11>/Saturation1'
  // End of Outputs for SubSystem: '<Root>/Ctrl'
}

// Model initialize function
void CtrlModelClass::initialize()
{
  // SystemInitialize for Atomic SubSystem: '<Root>/Ctrl'
  // SystemInitialize for Enabled SubSystem: '<S1>/AutoCtrl'
  // InitializeConditions for DiscreteIntegrator: '<S55>/Integrator'
  Ctrl_DW.Integrator_DSTATE_k = Ctrl_P.DiscretePIDController1_InitialC;

  // InitializeConditions for DiscreteIntegrator: '<S508>/Integrator'
  Ctrl_DW.Integrator_DSTATE_l = Ctrl_P.DiscretePIDController2_InitialC;

  // InitializeConditions for DiscreteIntegrator: '<S458>/Integrator'
  Ctrl_DW.Integrator_DSTATE_lw = Ctrl_P.DiscretePIDController1_Initia_k;

  // InitializeConditions for DiscreteIntegrator: '<S357>/Integrator'
  Ctrl_DW.Integrator_DSTATE_gj = Ctrl_P.DiscretePIDController_Initia_cd;

  // InitializeConditions for DiscreteIntegrator: '<S352>/Filter'
  Ctrl_DW.Filter_DSTATE_a = Ctrl_P.DiscretePIDController_InitialCo;

  // InitializeConditions for DiscreteIntegrator: '<S159>/Integrator'
  Ctrl_DW.Integrator_DSTATE_c = Ctrl_P.DiscretePIDController_Initial_m;

  // InitializeConditions for DiscreteIntegrator: '<S154>/Filter'
  Ctrl_DW.Filter_DSTATE_e = Ctrl_P.DiscretePIDController_Initial_n;

  // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' 
  Ctrl_DW.DiscreteTimeIntegrator_IC_LOA_j = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S562>/Integrator'
  Ctrl_DW.Integrator_DSTATE_mo = Ctrl_P.DiscretePIDController_Initia_c5;

  // End of SystemInitialize for SubSystem: '<S1>/AutoCtrl'

  // SystemInitialize for Enabled SubSystem: '<S1>/Off'
  // SystemInitialize for Merge generated from: '<S1>/Merge' incorporates:
  //   Outport: '<S7>/PWMs'

  Ctrl_B.PWM1 = Ctrl_P.PWMs_Y0[0];

  // SystemInitialize for Merge generated from: '<S1>/Merge' incorporates:
  //   Outport: '<S7>/PWMs'

  Ctrl_B.PWM2 = Ctrl_P.PWMs_Y0[1];

  // SystemInitialize for Merge generated from: '<S1>/Merge' incorporates:
  //   Outport: '<S7>/PWMs'

  Ctrl_B.PWM3 = Ctrl_P.PWMs_Y0[2];

  // SystemInitialize for Merge generated from: '<S1>/Merge' incorporates:
  //   Outport: '<S7>/PWMs'

  Ctrl_B.PWM4 = Ctrl_P.PWMs_Y0[3];

  // End of SystemInitialize for SubSystem: '<S1>/Off'

  // SystemInitialize for Enabled SubSystem: '<S1>/RateCtrl'
  // InitializeConditions for DiscreteIntegrator: '<S725>/Integrator'
  Ctrl_DW.Integrator_DSTATE_i = Ctrl_P.DiscretePIDController_Initia_mn;

  // InitializeConditions for DiscreteIntegrator: '<S720>/Filter'
  Ctrl_DW.Filter_DSTATE_f = Ctrl_P.DiscretePIDController_Initial_c;

  // InitializeConditions for DiscreteIntegrator: '<S674>/Integrator'
  Ctrl_DW.Integrator_DSTATE_g = Ctrl_P.DiscretePIDController_Initial_f;

  // InitializeConditions for DiscreteIntegrator: '<S669>/Filter'
  Ctrl_DW.Filter_DSTATE_b = Ctrl_P.DiscretePIDController_Initial_l;

  // InitializeConditions for DiscreteIntegrator: '<S776>/Integrator'
  Ctrl_DW.Integrator_DSTATE_f = Ctrl_P.DiscretePIDController_Initial_a;

  // End of SystemInitialize for SubSystem: '<S1>/RateCtrl'

  // SystemInitialize for Enabled SubSystem: '<S1>/RollPitchCtrl'
  // InitializeConditions for DiscreteIntegrator: '<S936>/Integrator'
  Ctrl_DW.Integrator_DSTATE_h = Ctrl_P.DiscretePIDController_Initia_pb;

  // InitializeConditions for DiscreteIntegrator: '<S931>/Filter'
  Ctrl_DW.Filter_DSTATE_c = Ctrl_P.DiscretePIDController_Initial_p;

  // InitializeConditions for DiscreteIntegrator: '<S836>/Integrator'
  Ctrl_DW.Integrator_DSTATE_h0 = Ctrl_P.DiscretePIDController_Initial_b;

  // InitializeConditions for DiscreteIntegrator: '<S831>/Filter'
  Ctrl_DW.Filter_DSTATE_oq = Ctrl_P.DiscretePIDController_Initial_d;

  // InitializeConditions for DiscreteIntegrator: '<S1035>/Integrator'
  Ctrl_DW.Integrator_DSTATE_o = Ctrl_P.DiscretePIDController_Initia_np;

  // End of SystemInitialize for SubSystem: '<S1>/RollPitchCtrl'

  // SystemInitialize for Enabled SubSystem: '<S1>/VelocityCtrl'
  // InitializeConditions for DiscreteIntegrator: '<S1092>/Integrator'
  Ctrl_DW.Integrator_DSTATE = Ctrl_P.DiscretePIDController1_Initia_c;

  // InitializeConditions for DiscreteIntegrator: '<S1399>/Integrator'
  Ctrl_DW.Integrator_DSTATE_d = Ctrl_P.DiscretePIDController2_Initia_k;

  // InitializeConditions for DiscreteIntegrator: '<S1349>/Integrator'
  Ctrl_DW.Integrator_DSTATE_b = Ctrl_P.DiscretePIDController1_Initia_j;

  // InitializeConditions for DiscreteIntegrator: '<S1248>/Integrator'
  Ctrl_DW.Integrator_DSTATE_e = Ctrl_P.DiscretePIDController_Initia_jc;

  // InitializeConditions for DiscreteIntegrator: '<S1243>/Filter'
  Ctrl_DW.Filter_DSTATE = Ctrl_P.DiscretePIDController_Initial_j;

  // InitializeConditions for DiscreteIntegrator: '<S1148>/Integrator'
  Ctrl_DW.Integrator_DSTATE_n = Ctrl_P.DiscretePIDController_Initia_lr;

  // InitializeConditions for DiscreteIntegrator: '<S1143>/Filter'
  Ctrl_DW.Filter_DSTATE_o = Ctrl_P.DiscretePIDController_Initia_nr;

  // InitializeConditions for DiscreteIntegrator: '<S1057>/Discrete-Time Integrator' 
  Ctrl_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S1452>/Integrator'
  Ctrl_DW.Integrator_DSTATE_m = Ctrl_P.DiscretePIDController_Initi_c5w;

  // End of SystemInitialize for SubSystem: '<S1>/VelocityCtrl'
  // End of SystemInitialize for SubSystem: '<Root>/Ctrl'
}

// Model terminate function
void CtrlModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
CtrlModelClass::CtrlModelClass() :
  Ctrl_B(),
  Ctrl_DW(),
  Ctrl_U(),
  Ctrl_Y(),
  Ctrl_M()
{
  // Currently there is no constructor body generated.
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
