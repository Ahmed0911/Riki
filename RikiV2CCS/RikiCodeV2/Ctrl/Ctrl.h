//
// File: Ctrl.h
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
#ifndef RTW_HEADER_Ctrl_h_
#define RTW_HEADER_Ctrl_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Ctrl_COMMON_INCLUDES_
# define Ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Ctrl_COMMON_INCLUDES_

#include "Ctrl_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S19>/Correct Yaw1'
typedef struct {
  real32_T y;                          // '<S19>/Correct Yaw1'
} B_CorrectYaw1_Ctrl_T;

// Block signals (auto storage)
typedef struct {
  real32_T PWM1;                       // '<S1>/Merge'
  real32_T PWM2;                       // '<S1>/Merge'
  real32_T PWM3;                       // '<S1>/Merge'
  real32_T PWM4;                       // '<S1>/Merge'
  real32_T VertVelRef;                 // '<S80>/Scale Vel'
  real32_T VertVelOut;                 // '<S80>/Bias1'
  real32_T RollRef;                    // '<S83>/Scale roll2'
  real32_T dRollRef;                   // '<S96>/Saturate'
  real32_T RollOut;                    // '<S95>/Saturate'
  real32_T PitchRef;                   // '<S82>/Scale roll1'
  real32_T dPitchRef;                  // '<S93>/Saturate'
  real32_T PitchOut;                   // '<S92>/Saturate'
  real32_T AutoRef[3];                 // '<S1>/Chart'
  real32_T AutoRefAng;                 // '<S1>/Chart'
  real32_T VertVelRef5;                // '<S13>/Scale Vel'
  real32_T VertVelOut5;                // '<S13>/Bias1'
  boolean_T Off;                       // '<S1>/Chart'
  boolean_T ManualMode;                // '<S1>/Chart'
  boolean_T RateMode;                  // '<S1>/Chart'
  boolean_T RollPitchMode;             // '<S1>/Chart'
  boolean_T VelocityMode;              // '<S1>/Chart'
  boolean_T AutoMode;                  // '<S1>/Chart'
  B_CorrectYaw1_Ctrl_T sf_CorrectYaw1_l;// '<S85>/Correct Yaw1'
  B_CorrectYaw1_Ctrl_T sf_CorrectYaw1; // '<S19>/Correct Yaw1'
} B_Ctrl_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real32_T Delay_DSTATE[100];          // '<S2>/Delay'
  real32_T DiscreteFIRFilter_states[99];// '<S2>/Discrete FIR Filter'
  real32_T Integrator_DSTATE;          // '<S86>/Integrator'
  real32_T Integrator_DSTATE_d;        // '<S100>/Integrator'
  real32_T Integrator_DSTATE_o;        // '<S99>/Integrator'
  real32_T Integrator_DSTATE_m;        // '<S95>/Integrator'
  real32_T Filter_DSTATE;              // '<S95>/Filter'
  real32_T Integrator_DSTATE_e;        // '<S92>/Integrator'
  real32_T Filter_DSTATE_c;            // '<S92>/Filter'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S85>/Discrete-Time Integrator'
  real32_T Integrator_DSTATE_f;        // '<S104>/Integrator'
  real32_T Integrator_DSTATE_i;        // '<S75>/Integrator'
  real32_T Filter_DSTATE_o;            // '<S75>/Filter'
  real32_T Integrator_DSTATE_o1;       // '<S72>/Integrator'
  real32_T Filter_DSTATE_d;            // '<S72>/Filter'
  real32_T Integrator_DSTATE_b;        // '<S78>/Integrator'
  real32_T Integrator_DSTATE_fa;       // '<S60>/Integrator'
  real32_T Filter_DSTATE_p;            // '<S60>/Filter'
  real32_T Integrator_DSTATE_g;        // '<S58>/Integrator'
  real32_T Filter_DSTATE_h;            // '<S58>/Filter'
  real32_T Integrator_DSTATE_p;        // '<S62>/Integrator'
  real32_T Integrator_DSTATE_dl;       // '<S20>/Integrator'
  real32_T Integrator_DSTATE_id;       // '<S37>/Integrator'
  real32_T Integrator_DSTATE_ba;       // '<S36>/Integrator'
  real32_T Integrator_DSTATE_l;        // '<S32>/Integrator'
  real32_T Filter_DSTATE_pa;           // '<S32>/Filter'
  real32_T Integrator_DSTATE_j;        // '<S27>/Integrator'
  real32_T Filter_DSTATE_n;            // '<S27>/Filter'
  real32_T DiscreteTimeIntegrator_DSTATE_f;// '<S19>/Discrete-Time Integrator'
  real32_T Integrator_DSTATE_di;       // '<S41>/Integrator'
  int32_T DiscreteFIRFilter_circBuf;   // '<S2>/Discrete FIR Filter'
  real32_T OrbPhi;                     // '<S1>/Chart'
  real32_T OrbRadius;                  // '<S1>/Chart'
  real32_T OrbdPhidT;                  // '<S1>/Chart'
  real32_T dPdT[3];                    // '<S1>/Chart'
  real32_T P1[3];                      // '<S1>/Chart'
  real32_T Ttotal;                     // '<S1>/Chart'
  real32_T Time;                       // '<S1>/Chart'
  uint16_T temporalCounter_i1;         // '<S1>/Chart'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S85>/Discrete-Time Integrator'
  uint8_T is_active_c1_Ctrl;           // '<S1>/Chart'
  uint8_T is_SystemLogic;              // '<S1>/Chart'
  uint8_T is_On;                       // '<S1>/Chart'
  uint8_T is_AutoMode;                 // '<S1>/Chart'
  uint8_T is_LEDs;                     // '<S1>/Chart'
  uint8_T is_Off;                      // '<S1>/Chart'
  uint8_T is_On_b;                     // '<S1>/Chart'
  uint8_T Mode;                        // '<S1>/Chart'
  uint8_T wayIndex;                    // '<S1>/Chart'
  uint8_T ModeOld;                     // '<S1>/Chart'
  uint8_T temporalCounter_i2;          // '<S1>/Chart'
  uint8_T DiscreteTimeIntegrator_IC_LOA_j;// '<S19>/Discrete-Time Integrator'
  boolean_T AutoCtrl_MODE;             // '<S1>/AutoCtrl'
  boolean_T RateCtrl_MODE;             // '<S1>/RateCtrl'
  boolean_T RollPitchCtrl_MODE;        // '<S1>/RollPitchCtrl'
  boolean_T VelocityCtrl_MODE;         // '<S1>/VelocityCtrl'
} DW_Ctrl_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real32_T Waypoints[27];              // '<Root>/Waypoints'
  int32_T WayCnt;                      // '<Root>/WayCnt'
  real32_T TrajZNEVParams[4];          // '<Root>/TrajZNEVParams'
  uint32_T ExecuteWaypoints;           // '<Root>/ExecuteWaypoints'
  uint8_T ModeCode;                    // '<Root>/ModeCode'
  uint32_T Mode;                       // '<Root>/Mode'
  real32_T Thr;                        // '<Root>/Thr'
  real32_T Aileron;                    // '<Root>/Aileron'
  real32_T Elevator;                   // '<Root>/Elevator'
  real32_T Rudder;                     // '<Root>/Rudder'
  real32_T Pressure0;                  // '<Root>/Pressure0'
  real32_T RPY[3];                     // '<Root>/RPY'
  real32_T dRPY[3];                    // '<Root>/dRPY'
  real32_T PressureAbs;                // '<Root>/PressureAbs'
  real32_T FlatXe[2];                  // '<Root>/FlatXe'
  real32_T FlatVe[3];                  // '<Root>/FlatVe'
  real32_T BatteryVoltage;             // '<Root>/BatteryVoltage'
} ExtU_Ctrl_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real32_T PWM1;                       // '<Root>/PWM1'
  real32_T PWM2;                       // '<Root>/PWM2'
  real32_T PWM3;                       // '<Root>/PWM3'
  real32_T PWM4;                       // '<Root>/PWM4'
  boolean_T LEDs[3];                   // '<Root>/LEDs'
  uint8_T ActualMode;                  // '<Root>/ActualMode'
  real32_T Altitude;                   // '<Root>/Altitude'
  real32_T VertSpeed;                  // '<Root>/VertSpeed'
  real32_T FuelPercent;                // '<Root>/FuelPercent'
} ExtY_Ctrl_T;

// Parameters (auto storage)
struct P_Ctrl_T_ {
  real32_T DiscretePIDController2_LowerSat;// Mask Parameter: DiscretePIDController2_LowerSat
                                           //  Referenced by: '<S21>/Saturate'

  real32_T DiscretePIDController1_LowerSat;// Mask Parameter: DiscretePIDController1_LowerSat
                                           //  Referenced by:
                                           //    '<S20>/Saturate'
                                           //    '<S22>/DeadZone'

  real32_T DiscretePIDController2_LowerS_e;// Mask Parameter: DiscretePIDController2_LowerS_e
                                           //  Referenced by: '<S31>/Saturate'

  real32_T DiscretePIDController2_LowerS_h;// Mask Parameter: DiscretePIDController2_LowerS_h
                                           //  Referenced by:
                                           //    '<S37>/Saturate'
                                           //    '<S39>/DeadZone'

  real32_T DiscretePIDController1_LowerS_m;// Mask Parameter: DiscretePIDController1_LowerS_m
                                           //  Referenced by: '<S30>/Saturate'

  real32_T DiscretePIDController1_LowerS_p;// Mask Parameter: DiscretePIDController1_LowerS_p
                                           //  Referenced by:
                                           //    '<S36>/Saturate'
                                           //    '<S38>/DeadZone'

  real32_T DiscretePIDController1_LowerS_g;// Mask Parameter: DiscretePIDController1_LowerS_g
                                           //  Referenced by: '<S33>/Saturate'

  real32_T DiscretePIDController_LowerSatu;// Mask Parameter: DiscretePIDController_LowerSatu
                                           //  Referenced by:
                                           //    '<S32>/Saturate'
                                           //    '<S34>/DeadZone'

  real32_T DiscretePIDController1_LowerS_n;// Mask Parameter: DiscretePIDController1_LowerS_n
                                           //  Referenced by: '<S28>/Saturate'

  real32_T DiscretePIDController_LowerSa_o;// Mask Parameter: DiscretePIDController_LowerSa_o
                                           //  Referenced by:
                                           //    '<S27>/Saturate'
                                           //    '<S29>/DeadZone'

  real32_T DiscretePIDController3_LowerSat;// Mask Parameter: DiscretePIDController3_LowerSat
                                           //  Referenced by: '<S42>/Saturate'

  real32_T DiscretePIDController_LowerSa_i;// Mask Parameter: DiscretePIDController_LowerSa_i
                                           //  Referenced by:
                                           //    '<S41>/Saturate'
                                           //    '<S44>/DeadZone'

  real32_T DiscretePIDController_LowerSa_k;// Mask Parameter: DiscretePIDController_LowerSa_k
                                           //  Referenced by:
                                           //    '<S60>/Saturate'
                                           //    '<S61>/DeadZone'

  real32_T DiscretePIDController_LowerS_io;// Mask Parameter: DiscretePIDController_LowerS_io
                                           //  Referenced by:
                                           //    '<S58>/Saturate'
                                           //    '<S59>/DeadZone'

  real32_T DiscretePIDController_LowerSa_a;// Mask Parameter: DiscretePIDController_LowerSa_a
                                           //  Referenced by:
                                           //    '<S62>/Saturate'
                                           //    '<S63>/DeadZone'

  real32_T DiscretePIDController1_LowerS_d;// Mask Parameter: DiscretePIDController1_LowerS_d
                                           //  Referenced by: '<S76>/Saturate'

  real32_T DiscretePIDController_LowerSa_b;// Mask Parameter: DiscretePIDController_LowerSa_b
                                           //  Referenced by:
                                           //    '<S75>/Saturate'
                                           //    '<S77>/DeadZone'

  real32_T DiscretePIDController1_Lower_de;// Mask Parameter: DiscretePIDController1_Lower_de
                                           //  Referenced by: '<S73>/Saturate'

  real32_T DiscretePIDController_LowerSa_p;// Mask Parameter: DiscretePIDController_LowerSa_p
                                           //  Referenced by:
                                           //    '<S72>/Saturate'
                                           //    '<S74>/DeadZone'

  real32_T DiscretePIDController_LowerSa_f;// Mask Parameter: DiscretePIDController_LowerSa_f
                                           //  Referenced by:
                                           //    '<S78>/Saturate'
                                           //    '<S79>/DeadZone'

  real32_T DiscretePIDController1_LowerS_b;// Mask Parameter: DiscretePIDController1_LowerS_b
                                           //  Referenced by:
                                           //    '<S86>/Saturate'
                                           //    '<S87>/DeadZone'

  real32_T DiscretePIDController2_LowerS_a;// Mask Parameter: DiscretePIDController2_LowerS_a
                                           //  Referenced by:
                                           //    '<S100>/Saturate'
                                           //    '<S102>/DeadZone'

  real32_T DiscretePIDController1_LowerS_e;// Mask Parameter: DiscretePIDController1_LowerS_e
                                           //  Referenced by:
                                           //    '<S99>/Saturate'
                                           //    '<S101>/DeadZone'

  real32_T DiscretePIDController1_Lower_pq;// Mask Parameter: DiscretePIDController1_Lower_pq
                                           //  Referenced by: '<S96>/Saturate'

  real32_T DiscretePIDController_LowerS_ok;// Mask Parameter: DiscretePIDController_LowerS_ok
                                           //  Referenced by:
                                           //    '<S95>/Saturate'
                                           //    '<S97>/DeadZone'

  real32_T DiscretePIDController1_LowerS_f;// Mask Parameter: DiscretePIDController1_LowerS_f
                                           //  Referenced by: '<S93>/Saturate'

  real32_T DiscretePIDController_LowerS_a3;// Mask Parameter: DiscretePIDController_LowerS_a3
                                           //  Referenced by:
                                           //    '<S92>/Saturate'
                                           //    '<S94>/DeadZone'

  real32_T DiscretePIDController3_LowerS_f;// Mask Parameter: DiscretePIDController3_LowerS_f
                                           //  Referenced by: '<S105>/Saturate'

  real32_T DiscretePIDController_LowerSa_m;// Mask Parameter: DiscretePIDController_LowerSa_m
                                           //  Referenced by:
                                           //    '<S104>/Saturate'
                                           //    '<S106>/DeadZone'

  real32_T DiscretePIDController_N;    // Mask Parameter: DiscretePIDController_N
                                       //  Referenced by: '<S32>/Filter Coefficient'

  real32_T DiscretePIDController_N_h;  // Mask Parameter: DiscretePIDController_N_h
                                       //  Referenced by: '<S27>/Filter Coefficient'

  real32_T DiscretePIDController_N_hm; // Mask Parameter: DiscretePIDController_N_hm
                                       //  Referenced by: '<S60>/Filter Coefficient'

  real32_T DiscretePIDController_N_p;  // Mask Parameter: DiscretePIDController_N_p
                                       //  Referenced by: '<S58>/Filter Coefficient'

  real32_T DiscretePIDController_N_i;  // Mask Parameter: DiscretePIDController_N_i
                                       //  Referenced by: '<S75>/Filter Coefficient'

  real32_T DiscretePIDController_N_hn; // Mask Parameter: DiscretePIDController_N_hn
                                       //  Referenced by: '<S72>/Filter Coefficient'

  real32_T DiscretePIDController_N_n;  // Mask Parameter: DiscretePIDController_N_n
                                       //  Referenced by: '<S95>/Filter Coefficient'

  real32_T DiscretePIDController_N_g;  // Mask Parameter: DiscretePIDController_N_g
                                       //  Referenced by: '<S92>/Filter Coefficient'

  real32_T DiscretePIDController2_UpperSat;// Mask Parameter: DiscretePIDController2_UpperSat
                                           //  Referenced by: '<S21>/Saturate'

  real32_T DiscretePIDController1_UpperSat;// Mask Parameter: DiscretePIDController1_UpperSat
                                           //  Referenced by:
                                           //    '<S20>/Saturate'
                                           //    '<S22>/DeadZone'

  real32_T DiscretePIDController2_UpperS_o;// Mask Parameter: DiscretePIDController2_UpperS_o
                                           //  Referenced by: '<S31>/Saturate'

  real32_T DiscretePIDController2_UpperS_d;// Mask Parameter: DiscretePIDController2_UpperS_d
                                           //  Referenced by:
                                           //    '<S37>/Saturate'
                                           //    '<S39>/DeadZone'

  real32_T DiscretePIDController1_UpperS_b;// Mask Parameter: DiscretePIDController1_UpperS_b
                                           //  Referenced by: '<S30>/Saturate'

  real32_T DiscretePIDController1_UpperS_g;// Mask Parameter: DiscretePIDController1_UpperS_g
                                           //  Referenced by:
                                           //    '<S36>/Saturate'
                                           //    '<S38>/DeadZone'

  real32_T DiscretePIDController_UpperSatu;// Mask Parameter: DiscretePIDController_UpperSatu
                                           //  Referenced by:
                                           //    '<S32>/Saturate'
                                           //    '<S34>/DeadZone'

  real32_T DiscretePIDController_UpperSa_g;// Mask Parameter: DiscretePIDController_UpperSa_g
                                           //  Referenced by:
                                           //    '<S27>/Saturate'
                                           //    '<S29>/DeadZone'

  real32_T DiscretePIDController_UpperS_gi;// Mask Parameter: DiscretePIDController_UpperS_gi
                                           //  Referenced by:
                                           //    '<S41>/Saturate'
                                           //    '<S44>/DeadZone'

  real32_T DiscretePIDController_UpperSa_h;// Mask Parameter: DiscretePIDController_UpperSa_h
                                           //  Referenced by:
                                           //    '<S60>/Saturate'
                                           //    '<S61>/DeadZone'

  real32_T DiscretePIDController_UpperSa_n;// Mask Parameter: DiscretePIDController_UpperSa_n
                                           //  Referenced by:
                                           //    '<S58>/Saturate'
                                           //    '<S59>/DeadZone'

  real32_T DiscretePIDController_UpperSa_b;// Mask Parameter: DiscretePIDController_UpperSa_b
                                           //  Referenced by:
                                           //    '<S62>/Saturate'
                                           //    '<S63>/DeadZone'

  real32_T DiscretePIDController_UpperSa_p;// Mask Parameter: DiscretePIDController_UpperSa_p
                                           //  Referenced by:
                                           //    '<S75>/Saturate'
                                           //    '<S77>/DeadZone'

  real32_T DiscretePIDController_UpperSa_i;// Mask Parameter: DiscretePIDController_UpperSa_i
                                           //  Referenced by:
                                           //    '<S72>/Saturate'
                                           //    '<S74>/DeadZone'

  real32_T DiscretePIDController_UpperSa_k;// Mask Parameter: DiscretePIDController_UpperSa_k
                                           //  Referenced by:
                                           //    '<S78>/Saturate'
                                           //    '<S79>/DeadZone'

  real32_T DiscretePIDController1_UpperS_l;// Mask Parameter: DiscretePIDController1_UpperS_l
                                           //  Referenced by:
                                           //    '<S86>/Saturate'
                                           //    '<S87>/DeadZone'

  real32_T DiscretePIDController2_UpperS_i;// Mask Parameter: DiscretePIDController2_UpperS_i
                                           //  Referenced by:
                                           //    '<S100>/Saturate'
                                           //    '<S102>/DeadZone'

  real32_T DiscretePIDController1_UpperS_n;// Mask Parameter: DiscretePIDController1_UpperS_n
                                           //  Referenced by:
                                           //    '<S99>/Saturate'
                                           //    '<S101>/DeadZone'

  real32_T DiscretePIDController_UpperS_ii;// Mask Parameter: DiscretePIDController_UpperS_ii
                                           //  Referenced by:
                                           //    '<S95>/Saturate'
                                           //    '<S97>/DeadZone'

  real32_T DiscretePIDController_UpperSa_m;// Mask Parameter: DiscretePIDController_UpperSa_m
                                           //  Referenced by:
                                           //    '<S92>/Saturate'
                                           //    '<S94>/DeadZone'

  real32_T DiscretePIDController_UpperS_nb;// Mask Parameter: DiscretePIDController_UpperS_nb
                                           //  Referenced by:
                                           //    '<S104>/Saturate'
                                           //    '<S106>/DeadZone'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                       //  Referenced by: '<S43>/Gain'

  real32_T ScaleVel_Gain;              // Computed Parameter: ScaleVel_Gain
                                       //  Referenced by: '<S13>/Scale Vel'

  real32_T FixFaultyBaro_UpperSat;     // Computed Parameter: FixFaultyBaro_UpperSat
                                       //  Referenced by: '<S13>/Fix Faulty Baro'

  real32_T FixFaultyBaro_LowerSat;     // Computed Parameter: FixFaultyBaro_LowerSat
                                       //  Referenced by: '<S13>/Fix Faulty Baro'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S20>/Integrator'

  real32_T Integrator_IC;              // Computed Parameter: Integrator_IC
                                       //  Referenced by: '<S20>/Integrator'

  real32_T ZeroGain_Gain;              // Computed Parameter: ZeroGain_Gain
                                       //  Referenced by: '<S22>/ZeroGain'

  real32_T Constant_Value;             // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S20>/Constant'

  real32_T LimitOutput_UpperSat;       // Computed Parameter: LimitOutput_UpperSat
                                       //  Referenced by: '<S13>/Limit Output'

  real32_T LimitOutput_LowerSat;       // Computed Parameter: LimitOutput_LowerSat
                                       //  Referenced by: '<S13>/Limit Output'

  real32_T Integrator_gainval_g;       // Computed Parameter: Integrator_gainval_g
                                       //  Referenced by: '<S37>/Integrator'

  real32_T Integrator_IC_k;            // Computed Parameter: Integrator_IC_k
                                       //  Referenced by: '<S37>/Integrator'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                       //  Referenced by: '<S35>/Gain1'

  real32_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                       //  Referenced by: '<S36>/Integrator'

  real32_T Integrator_IC_h;            // Computed Parameter: Integrator_IC_h
                                       //  Referenced by: '<S36>/Integrator'

  real32_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                       //  Referenced by: '<S32>/Integrator'

  real32_T Integrator_IC_m;            // Computed Parameter: Integrator_IC_m
                                       //  Referenced by: '<S32>/Integrator'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S32>/Filter'

  real32_T Filter_IC;                  // Computed Parameter: Filter_IC
                                       //  Referenced by: '<S32>/Filter'

  real32_T Integrator_gainval_d;       // Computed Parameter: Integrator_gainval_d
                                       //  Referenced by: '<S27>/Integrator'

  real32_T Integrator_IC_l;            // Computed Parameter: Integrator_IC_l
                                       //  Referenced by: '<S27>/Integrator'

  real32_T Filter_gainval_l;           // Computed Parameter: Filter_gainval_l
                                       //  Referenced by: '<S27>/Filter'

  real32_T Filter_IC_d;                // Computed Parameter: Filter_IC_d
                                       //  Referenced by: '<S27>/Filter'

  real32_T DiscreteTimeIntegrator_gainval;// Computed Parameter: DiscreteTimeIntegrator_gainval
                                          //  Referenced by: '<S19>/Discrete-Time Integrator'

  real32_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                       //  Referenced by: '<S19>/Switch'

  real32_T Integrator_gainval_dg;      // Computed Parameter: Integrator_gainval_dg
                                       //  Referenced by: '<S41>/Integrator'

  real32_T Integrator_IC_o;            // Computed Parameter: Integrator_IC_o
                                       //  Referenced by: '<S41>/Integrator'

  real32_T Constant_Value_p;           // Computed Parameter: Constant_Value_p
                                       //  Referenced by: '<S23>/Constant'

  real32_T Limit3_UpperSat;            // Computed Parameter: Limit3_UpperSat
                                       //  Referenced by: '<S23>/Limit3'

  real32_T Limit3_LowerSat;            // Computed Parameter: Limit3_LowerSat
                                       //  Referenced by: '<S23>/Limit3'

  real32_T Gain_Gain_f;                // Computed Parameter: Gain_Gain_f
                                       //  Referenced by: '<S23>/Gain'

  real32_T Constant_Value_a;           // Computed Parameter: Constant_Value_a
                                       //  Referenced by: '<S24>/Constant'

  real32_T Limit3_UpperSat_k;          // Computed Parameter: Limit3_UpperSat_k
                                       //  Referenced by: '<S24>/Limit3'

  real32_T Limit3_LowerSat_i;          // Computed Parameter: Limit3_LowerSat_i
                                       //  Referenced by: '<S24>/Limit3'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                       //  Referenced by: '<S24>/Gain'

  real32_T Constant_Value_j;           // Computed Parameter: Constant_Value_j
                                       //  Referenced by: '<S25>/Constant'

  real32_T Limit3_UpperSat_m;          // Computed Parameter: Limit3_UpperSat_m
                                       //  Referenced by: '<S25>/Limit3'

  real32_T Limit3_LowerSat_ih;         // Computed Parameter: Limit3_LowerSat_ih
                                       //  Referenced by: '<S25>/Limit3'

  real32_T Gain_Gain_j;                // Computed Parameter: Gain_Gain_j
                                       //  Referenced by: '<S25>/Gain'

  real32_T Constant_Value_p4;          // Computed Parameter: Constant_Value_p4
                                       //  Referenced by: '<S26>/Constant'

  real32_T Limit3_UpperSat_a;          // Computed Parameter: Limit3_UpperSat_a
                                       //  Referenced by: '<S26>/Limit3'

  real32_T Limit3_LowerSat_n;          // Computed Parameter: Limit3_LowerSat_n
                                       //  Referenced by: '<S26>/Limit3'

  real32_T Gain_Gain_b;                // Computed Parameter: Gain_Gain_b
                                       //  Referenced by: '<S26>/Gain'

  real32_T ZeroGain_Gain_p;            // Computed Parameter: ZeroGain_Gain_p
                                       //  Referenced by: '<S29>/ZeroGain'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                       //  Referenced by: '<S27>/Constant'

  real32_T ZeroGain_Gain_px;           // Computed Parameter: ZeroGain_Gain_px
                                       //  Referenced by: '<S34>/ZeroGain'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                       //  Referenced by: '<S32>/Constant'

  real32_T ZeroGain_Gain_e;            // Computed Parameter: ZeroGain_Gain_e
                                       //  Referenced by: '<S38>/ZeroGain'

  real32_T Constant_Value_h;           // Computed Parameter: Constant_Value_h
                                       //  Referenced by: '<S36>/Constant'

  real32_T ZeroGain_Gain_g;            // Computed Parameter: ZeroGain_Gain_g
                                       //  Referenced by: '<S39>/ZeroGain'

  real32_T Constant_Value_hp;          // Computed Parameter: Constant_Value_hp
                                       //  Referenced by: '<S37>/Constant'

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                       //  Referenced by: '<S19>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                       //  Referenced by: '<S19>/Dead Zone'

  real32_T ZeroGain_Gain_n;            // Computed Parameter: ZeroGain_Gain_n
                                       //  Referenced by: '<S44>/ZeroGain'

  real32_T Constant_Value_d;           // Computed Parameter: Constant_Value_d
                                       //  Referenced by: '<S41>/Constant'

  real32_T Scaleroll2_Gain;            // Computed Parameter: Scaleroll2_Gain
                                       //  Referenced by: '<S19>/Scale roll2'

  real32_T Gain_Gain_ae;               // Computed Parameter: Gain_Gain_ae
                                       //  Referenced by: '<S6>/Gain'

  real32_T Gain1_Gain_e;               // Computed Parameter: Gain1_Gain_e
                                       //  Referenced by: '<S6>/Gain1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                       //  Referenced by: '<S6>/Gain2'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                       //  Referenced by: '<S6>/Gain3'

  real32_T Constant_Value_c;           // Computed Parameter: Constant_Value_c
                                       //  Referenced by: '<S46>/Constant'

  real32_T Limit3_UpperSat_l;          // Computed Parameter: Limit3_UpperSat_l
                                       //  Referenced by: '<S46>/Limit3'

  real32_T Limit3_LowerSat_g;          // Computed Parameter: Limit3_LowerSat_g
                                       //  Referenced by: '<S46>/Limit3'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                       //  Referenced by: '<S46>/Gain'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                       //  Referenced by: '<S47>/Constant'

  real32_T Limit3_UpperSat_b;          // Computed Parameter: Limit3_UpperSat_b
                                       //  Referenced by: '<S47>/Limit3'

  real32_T Limit3_LowerSat_k;          // Computed Parameter: Limit3_LowerSat_k
                                       //  Referenced by: '<S47>/Limit3'

  real32_T Gain_Gain_c;                // Computed Parameter: Gain_Gain_c
                                       //  Referenced by: '<S47>/Gain'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                       //  Referenced by: '<S48>/Constant'

  real32_T Limit3_UpperSat_o;          // Computed Parameter: Limit3_UpperSat_o
                                       //  Referenced by: '<S48>/Limit3'

  real32_T Limit3_LowerSat_d;          // Computed Parameter: Limit3_LowerSat_d
                                       //  Referenced by: '<S48>/Limit3'

  real32_T Gain_Gain_e;                // Computed Parameter: Gain_Gain_e
                                       //  Referenced by: '<S48>/Gain'

  real32_T Constant_Value_ew;          // Computed Parameter: Constant_Value_ew
                                       //  Referenced by: '<S49>/Constant'

  real32_T Limit3_UpperSat_c;          // Computed Parameter: Limit3_UpperSat_c
                                       //  Referenced by: '<S49>/Limit3'

  real32_T Limit3_LowerSat_f;          // Computed Parameter: Limit3_LowerSat_f
                                       //  Referenced by: '<S49>/Limit3'

  real32_T Gain_Gain_bq;               // Computed Parameter: Gain_Gain_bq
                                       //  Referenced by: '<S49>/Gain'

  real32_T PWMs_Y0[4];                 // Computed Parameter: PWMs_Y0
                                       //  Referenced by: '<S7>/PWMs'

  real32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                       //  Referenced by: '<S7>/Constant1'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                       //  Referenced by: '<S7>/Constant2'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                       //  Referenced by: '<S7>/Constant3'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                       //  Referenced by: '<S7>/Constant4'

  real32_T Gain_Gain_cu;               // Computed Parameter: Gain_Gain_cu
                                       //  Referenced by: '<S8>/Gain'

  real32_T Integrator_gainval_a;       // Computed Parameter: Integrator_gainval_a
                                       //  Referenced by: '<S60>/Integrator'

  real32_T Integrator_IC_e;            // Computed Parameter: Integrator_IC_e
                                       //  Referenced by: '<S60>/Integrator'

  real32_T Filter_gainval_f;           // Computed Parameter: Filter_gainval_f
                                       //  Referenced by: '<S60>/Filter'

  real32_T Filter_IC_f;                // Computed Parameter: Filter_IC_f
                                       //  Referenced by: '<S60>/Filter'

  real32_T Integrator_gainval_h;       // Computed Parameter: Integrator_gainval_h
                                       //  Referenced by: '<S58>/Integrator'

  real32_T Integrator_IC_j;            // Computed Parameter: Integrator_IC_j
                                       //  Referenced by: '<S58>/Integrator'

  real32_T Filter_gainval_h;           // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S58>/Filter'

  real32_T Filter_IC_c;                // Computed Parameter: Filter_IC_c
                                       //  Referenced by: '<S58>/Filter'

  real32_T DeadZone_Start_c;           // Computed Parameter: DeadZone_Start_c
                                       //  Referenced by: '<S53>/Dead Zone'

  real32_T DeadZone_End_o;             // Computed Parameter: DeadZone_End_o
                                       //  Referenced by: '<S53>/Dead Zone'

  real32_T Integrator_gainval_c;       // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S62>/Integrator'

  real32_T Integrator_IC_a;            // Computed Parameter: Integrator_IC_a
                                       //  Referenced by: '<S62>/Integrator'

  real32_T Constant_Value_g;           // Computed Parameter: Constant_Value_g
                                       //  Referenced by: '<S54>/Constant'

  real32_T Limit3_UpperSat_d;          // Computed Parameter: Limit3_UpperSat_d
                                       //  Referenced by: '<S54>/Limit3'

  real32_T Limit3_LowerSat_ku;         // Computed Parameter: Limit3_LowerSat_ku
                                       //  Referenced by: '<S54>/Limit3'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                       //  Referenced by: '<S54>/Gain'

  real32_T Constant_Value_ev;          // Computed Parameter: Constant_Value_ev
                                       //  Referenced by: '<S55>/Constant'

  real32_T Limit3_UpperSat_a1;         // Computed Parameter: Limit3_UpperSat_a1
                                       //  Referenced by: '<S55>/Limit3'

  real32_T Limit3_LowerSat_e;          // Computed Parameter: Limit3_LowerSat_e
                                       //  Referenced by: '<S55>/Limit3'

  real32_T Gain_Gain_ce;               // Computed Parameter: Gain_Gain_ce
                                       //  Referenced by: '<S55>/Gain'

  real32_T Constant_Value_k;           // Computed Parameter: Constant_Value_k
                                       //  Referenced by: '<S56>/Constant'

  real32_T Limit3_UpperSat_g;          // Computed Parameter: Limit3_UpperSat_g
                                       //  Referenced by: '<S56>/Limit3'

  real32_T Limit3_LowerSat_j;          // Computed Parameter: Limit3_LowerSat_j
                                       //  Referenced by: '<S56>/Limit3'

  real32_T Gain_Gain_cc;               // Computed Parameter: Gain_Gain_cc
                                       //  Referenced by: '<S56>/Gain'

  real32_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                       //  Referenced by: '<S57>/Constant'

  real32_T Limit3_UpperSat_j;          // Computed Parameter: Limit3_UpperSat_j
                                       //  Referenced by: '<S57>/Limit3'

  real32_T Limit3_LowerSat_o;          // Computed Parameter: Limit3_LowerSat_o
                                       //  Referenced by: '<S57>/Limit3'

  real32_T Gain_Gain_hp;               // Computed Parameter: Gain_Gain_hp
                                       //  Referenced by: '<S57>/Gain'

  real32_T ZeroGain_Gain_e0;           // Computed Parameter: ZeroGain_Gain_e0
                                       //  Referenced by: '<S59>/ZeroGain'

  real32_T Constant_Value_aw;          // Computed Parameter: Constant_Value_aw
                                       //  Referenced by: '<S58>/Constant'

  real32_T ZeroGain_Gain_c;            // Computed Parameter: ZeroGain_Gain_c
                                       //  Referenced by: '<S61>/ZeroGain'

  real32_T Constant_Value_jl;          // Computed Parameter: Constant_Value_jl
                                       //  Referenced by: '<S60>/Constant'

  real32_T ZeroGain_Gain_ez;           // Computed Parameter: ZeroGain_Gain_ez
                                       //  Referenced by: '<S63>/ZeroGain'

  real32_T Constant_Value_nm;          // Computed Parameter: Constant_Value_nm
                                       //  Referenced by: '<S62>/Constant'

  real32_T Gain_Gain_mu;               // Computed Parameter: Gain_Gain_mu
                                       //  Referenced by: '<S9>/Gain'

  real32_T Integrator_gainval_l;       // Computed Parameter: Integrator_gainval_l
                                       //  Referenced by: '<S75>/Integrator'

  real32_T Integrator_IC_g;            // Computed Parameter: Integrator_IC_g
                                       //  Referenced by: '<S75>/Integrator'

  real32_T Filter_gainval_i;           // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S75>/Filter'

  real32_T Filter_IC_b;                // Computed Parameter: Filter_IC_b
                                       //  Referenced by: '<S75>/Filter'

  real32_T Integrator_gainval_dk;      // Computed Parameter: Integrator_gainval_dk
                                       //  Referenced by: '<S72>/Integrator'

  real32_T Integrator_IC_p;            // Computed Parameter: Integrator_IC_p
                                       //  Referenced by: '<S72>/Integrator'

  real32_T Filter_gainval_o;           // Computed Parameter: Filter_gainval_o
                                       //  Referenced by: '<S72>/Filter'

  real32_T Filter_IC_i;                // Computed Parameter: Filter_IC_i
                                       //  Referenced by: '<S72>/Filter'

  real32_T DeadZone_Start_l;           // Computed Parameter: DeadZone_Start_l
                                       //  Referenced by: '<S67>/Dead Zone'

  real32_T DeadZone_End_h;             // Computed Parameter: DeadZone_End_h
                                       //  Referenced by: '<S67>/Dead Zone'

  real32_T Integrator_gainval_m;       // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S78>/Integrator'

  real32_T Integrator_IC_lt;           // Computed Parameter: Integrator_IC_lt
                                       //  Referenced by: '<S78>/Integrator'

  real32_T Constant_Value_p42;         // Computed Parameter: Constant_Value_p42
                                       //  Referenced by: '<S68>/Constant'

  real32_T Limit3_UpperSat_b5;         // Computed Parameter: Limit3_UpperSat_b5
                                       //  Referenced by: '<S68>/Limit3'

  real32_T Limit3_LowerSat_jv;         // Computed Parameter: Limit3_LowerSat_jv
                                       //  Referenced by: '<S68>/Limit3'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                       //  Referenced by: '<S68>/Gain'

  real32_T Constant_Value_co;          // Computed Parameter: Constant_Value_co
                                       //  Referenced by: '<S69>/Constant'

  real32_T Limit3_UpperSat_gu;         // Computed Parameter: Limit3_UpperSat_gu
                                       //  Referenced by: '<S69>/Limit3'

  real32_T Limit3_LowerSat_dd;         // Computed Parameter: Limit3_LowerSat_dd
                                       //  Referenced by: '<S69>/Limit3'

  real32_T Gain_Gain_d;                // Computed Parameter: Gain_Gain_d
                                       //  Referenced by: '<S69>/Gain'

  real32_T Constant_Value_oi;          // Computed Parameter: Constant_Value_oi
                                       //  Referenced by: '<S70>/Constant'

  real32_T Limit3_UpperSat_kf;         // Computed Parameter: Limit3_UpperSat_kf
                                       //  Referenced by: '<S70>/Limit3'

  real32_T Limit3_LowerSat_du;         // Computed Parameter: Limit3_LowerSat_du
                                       //  Referenced by: '<S70>/Limit3'

  real32_T Gain_Gain_i;                // Computed Parameter: Gain_Gain_i
                                       //  Referenced by: '<S70>/Gain'

  real32_T Constant_Value_awg;         // Computed Parameter: Constant_Value_awg
                                       //  Referenced by: '<S71>/Constant'

  real32_T Limit3_UpperSat_n;          // Computed Parameter: Limit3_UpperSat_n
                                       //  Referenced by: '<S71>/Limit3'

  real32_T Limit3_LowerSat_b;          // Computed Parameter: Limit3_LowerSat_b
                                       //  Referenced by: '<S71>/Limit3'

  real32_T Gain_Gain_m5;               // Computed Parameter: Gain_Gain_m5
                                       //  Referenced by: '<S71>/Gain'

  real32_T ZeroGain_Gain_b;            // Computed Parameter: ZeroGain_Gain_b
                                       //  Referenced by: '<S74>/ZeroGain'

  real32_T Constant_Value_cx;          // Computed Parameter: Constant_Value_cx
                                       //  Referenced by: '<S72>/Constant'

  real32_T ZeroGain_Gain_o;            // Computed Parameter: ZeroGain_Gain_o
                                       //  Referenced by: '<S77>/ZeroGain'

  real32_T Constant_Value_is;          // Computed Parameter: Constant_Value_is
                                       //  Referenced by: '<S75>/Constant'

  real32_T ZeroGain_Gain_d;            // Computed Parameter: ZeroGain_Gain_d
                                       //  Referenced by: '<S79>/ZeroGain'

  real32_T Constant_Value_kd;          // Computed Parameter: Constant_Value_kd
                                       //  Referenced by: '<S78>/Constant'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                       //  Referenced by: '<S80>/Bias'

  real32_T DeadZone_Start_p;           // Computed Parameter: DeadZone_Start_p
                                       //  Referenced by: '<S80>/Dead Zone'

  real32_T DeadZone_End_b;             // Computed Parameter: DeadZone_End_b
                                       //  Referenced by: '<S80>/Dead Zone'

  real32_T ScaleVel_Gain_a;            // Computed Parameter: ScaleVel_Gain_a
                                       //  Referenced by: '<S80>/Scale Vel'

  real32_T FixFaultyBaro_UpperSat_d;   // Computed Parameter: FixFaultyBaro_UpperSat_d
                                       //  Referenced by: '<S80>/Fix Faulty Baro'

  real32_T FixFaultyBaro_LowerSat_o;   // Computed Parameter: FixFaultyBaro_LowerSat_o
                                       //  Referenced by: '<S80>/Fix Faulty Baro'

  real32_T Integrator_gainval_o;       // Computed Parameter: Integrator_gainval_o
                                       //  Referenced by: '<S86>/Integrator'

  real32_T Integrator_IC_p4;           // Computed Parameter: Integrator_IC_p4
                                       //  Referenced by: '<S86>/Integrator'

  real32_T ZeroGain_Gain_f;            // Computed Parameter: ZeroGain_Gain_f
                                       //  Referenced by: '<S87>/ZeroGain'

  real32_T Constant_Value_n4;          // Computed Parameter: Constant_Value_n4
                                       //  Referenced by: '<S86>/Constant'

  real32_T LimitOutput_UpperSat_h;     // Computed Parameter: LimitOutput_UpperSat_h
                                       //  Referenced by: '<S80>/Limit Output'

  real32_T LimitOutput_LowerSat_f;     // Computed Parameter: LimitOutput_LowerSat_f
                                       //  Referenced by: '<S80>/Limit Output'

  real32_T Gain2_Gain_j;               // Computed Parameter: Gain2_Gain_j
                                       //  Referenced by: '<S10>/Gain2'

  real32_T Gain1_Gain_k;               // Computed Parameter: Gain1_Gain_k
                                       //  Referenced by: '<S98>/Gain1'

  real32_T Integrator_gainval_dj;      // Computed Parameter: Integrator_gainval_dj
                                       //  Referenced by: '<S100>/Integrator'

  real32_T Integrator_IC_g2;           // Computed Parameter: Integrator_IC_g2
                                       //  Referenced by: '<S100>/Integrator'

  real32_T Integrator_gainval_iz;      // Computed Parameter: Integrator_gainval_iz
                                       //  Referenced by: '<S99>/Integrator'

  real32_T Integrator_IC_et;           // Computed Parameter: Integrator_IC_et
                                       //  Referenced by: '<S99>/Integrator'

  real32_T Integrator_gainval_pk;      // Computed Parameter: Integrator_gainval_pk
                                       //  Referenced by: '<S95>/Integrator'

  real32_T Integrator_IC_c;            // Computed Parameter: Integrator_IC_c
                                       //  Referenced by: '<S95>/Integrator'

  real32_T Filter_gainval_a;           // Computed Parameter: Filter_gainval_a
                                       //  Referenced by: '<S95>/Filter'

  real32_T Filter_IC_e;                // Computed Parameter: Filter_IC_e
                                       //  Referenced by: '<S95>/Filter'

  real32_T Integrator_gainval_hs;      // Computed Parameter: Integrator_gainval_hs
                                       //  Referenced by: '<S92>/Integrator'

  real32_T Integrator_IC_b;            // Computed Parameter: Integrator_IC_b
                                       //  Referenced by: '<S92>/Integrator'

  real32_T Filter_gainval_d;           // Computed Parameter: Filter_gainval_d
                                       //  Referenced by: '<S92>/Filter'

  real32_T Filter_IC_l;                // Computed Parameter: Filter_IC_l
                                       //  Referenced by: '<S92>/Filter'

  real32_T DiscreteTimeIntegrator_gainva_h;// Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                           //  Referenced by: '<S85>/Discrete-Time Integrator'

  real32_T Integrator_gainval_mt;      // Computed Parameter: Integrator_gainval_mt
                                       //  Referenced by: '<S104>/Integrator'

  real32_T Integrator_IC_g4;           // Computed Parameter: Integrator_IC_g4
                                       //  Referenced by: '<S104>/Integrator'

  real32_T Constant_Value_l;           // Computed Parameter: Constant_Value_l
                                       //  Referenced by: '<S88>/Constant'

  real32_T Limit3_UpperSat_p;          // Computed Parameter: Limit3_UpperSat_p
                                       //  Referenced by: '<S88>/Limit3'

  real32_T Limit3_LowerSat_it;         // Computed Parameter: Limit3_LowerSat_it
                                       //  Referenced by: '<S88>/Limit3'

  real32_T Gain_Gain_oa;               // Computed Parameter: Gain_Gain_oa
                                       //  Referenced by: '<S88>/Gain'

  real32_T Constant_Value_bv;          // Computed Parameter: Constant_Value_bv
                                       //  Referenced by: '<S89>/Constant'

  real32_T Limit3_UpperSat_e;          // Computed Parameter: Limit3_UpperSat_e
                                       //  Referenced by: '<S89>/Limit3'

  real32_T Limit3_LowerSat_l;          // Computed Parameter: Limit3_LowerSat_l
                                       //  Referenced by: '<S89>/Limit3'

  real32_T Gain_Gain_hh;               // Computed Parameter: Gain_Gain_hh
                                       //  Referenced by: '<S89>/Gain'

  real32_T Constant_Value_f;           // Computed Parameter: Constant_Value_f
                                       //  Referenced by: '<S90>/Constant'

  real32_T Limit3_UpperSat_lo;         // Computed Parameter: Limit3_UpperSat_lo
                                       //  Referenced by: '<S90>/Limit3'

  real32_T Limit3_LowerSat_gb;         // Computed Parameter: Limit3_LowerSat_gb
                                       //  Referenced by: '<S90>/Limit3'

  real32_T Gain_Gain_do;               // Computed Parameter: Gain_Gain_do
                                       //  Referenced by: '<S90>/Gain'

  real32_T Constant_Value_d3;          // Computed Parameter: Constant_Value_d3
                                       //  Referenced by: '<S91>/Constant'

  real32_T Limit3_UpperSat_i;          // Computed Parameter: Limit3_UpperSat_i
                                       //  Referenced by: '<S91>/Limit3'

  real32_T Limit3_LowerSat_d4;         // Computed Parameter: Limit3_LowerSat_d4
                                       //  Referenced by: '<S91>/Limit3'

  real32_T Gain_Gain_bo;               // Computed Parameter: Gain_Gain_bo
                                       //  Referenced by: '<S91>/Gain'

  real32_T ZeroGain_Gain_fc;           // Computed Parameter: ZeroGain_Gain_fc
                                       //  Referenced by: '<S94>/ZeroGain'

  real32_T Constant_Value_pd;          // Computed Parameter: Constant_Value_pd
                                       //  Referenced by: '<S92>/Constant'

  real32_T ZeroGain_Gain_bv;           // Computed Parameter: ZeroGain_Gain_bv
                                       //  Referenced by: '<S97>/ZeroGain'

  real32_T Constant_Value_em;          // Computed Parameter: Constant_Value_em
                                       //  Referenced by: '<S95>/Constant'

  real32_T ZeroGain_Gain_ph;           // Computed Parameter: ZeroGain_Gain_ph
                                       //  Referenced by: '<S101>/ZeroGain'

  real32_T Constant_Value_gz;          // Computed Parameter: Constant_Value_gz
                                       //  Referenced by: '<S99>/Constant'

  real32_T ZeroGain_Gain_em;           // Computed Parameter: ZeroGain_Gain_em
                                       //  Referenced by: '<S102>/ZeroGain'

  real32_T Constant_Value_fy;          // Computed Parameter: Constant_Value_fy
                                       //  Referenced by: '<S100>/Constant'

  real32_T DeadZone_Start_b;           // Computed Parameter: DeadZone_Start_b
                                       //  Referenced by: '<S85>/Dead Zone'

  real32_T DeadZone_End_p;             // Computed Parameter: DeadZone_End_p
                                       //  Referenced by: '<S85>/Dead Zone'

  real32_T ZeroGain_Gain_ei;           // Computed Parameter: ZeroGain_Gain_ei
                                       //  Referenced by: '<S106>/ZeroGain'

  real32_T Constant_Value_fi;          // Computed Parameter: Constant_Value_fi
                                       //  Referenced by: '<S104>/Constant'

  real32_T Scaleroll2_Gain_m;          // Computed Parameter: Scaleroll2_Gain_m
                                       //  Referenced by: '<S85>/Scale roll2'

  real32_T Delay_InitialCondition;     // Computed Parameter: Delay_InitialCondition
                                       //  Referenced by: '<S2>/Delay'

  real32_T DiscreteFIRFilter_InitialStates;// Computed Parameter: DiscreteFIRFilter_InitialStates
                                           //  Referenced by: '<S2>/Discrete FIR Filter'

  real32_T Gain_Gain_f1;               // Computed Parameter: Gain_Gain_f1
                                       //  Referenced by: '<S2>/Gain'

  real32_T Constant3_Value_b;          // Computed Parameter: Constant3_Value_b
                                       //  Referenced by: '<S5>/Constant3'

  real32_T Gain3_Gain_f;               // Computed Parameter: Gain3_Gain_f
                                       //  Referenced by: '<S5>/Gain3'

  real32_T Saturation3_UpperSat;       // Computed Parameter: Saturation3_UpperSat
                                       //  Referenced by: '<S5>/Saturation3'

  real32_T Saturation3_LowerSat;       // Computed Parameter: Saturation3_LowerSat
                                       //  Referenced by: '<S5>/Saturation3'

  real32_T Constant_Value_pb;          // Computed Parameter: Constant_Value_pb
                                       //  Referenced by: '<S5>/Constant'

  real32_T Constant1_Value_g;          // Computed Parameter: Constant1_Value_g
                                       //  Referenced by: '<S5>/Constant1'

  real32_T Constant2_Value_c;          // Computed Parameter: Constant2_Value_c
                                       //  Referenced by: '<S5>/Constant2'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                       //  Referenced by: '<S5>/Gain'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                       //  Referenced by: '<S5>/Gain1'

  real32_T Gain2_Gain_k;               // Computed Parameter: Gain2_Gain_k
                                       //  Referenced by: '<S5>/Gain2'

  real32_T Saturation_UpperSat;        // Computed Parameter: Saturation_UpperSat
                                       //  Referenced by: '<S5>/Saturation'

  real32_T Saturation_LowerSat;        // Computed Parameter: Saturation_LowerSat
                                       //  Referenced by: '<S5>/Saturation'

  real32_T Saturation1_UpperSat;       // Computed Parameter: Saturation1_UpperSat
                                       //  Referenced by: '<S5>/Saturation1'

  real32_T Saturation1_LowerSat;       // Computed Parameter: Saturation1_LowerSat
                                       //  Referenced by: '<S5>/Saturation1'

  real32_T Saturation2_UpperSat;       // Computed Parameter: Saturation2_UpperSat
                                       //  Referenced by: '<S5>/Saturation2'

  real32_T Saturation2_LowerSat;       // Computed Parameter: Saturation2_LowerSat
                                       //  Referenced by: '<S5>/Saturation2'

  real32_T Saturation_UpperSat_o;      // Computed Parameter: Saturation_UpperSat_o
                                       //  Referenced by: '<S11>/Saturation'

  real32_T Saturation_LowerSat_k;      // Computed Parameter: Saturation_LowerSat_k
                                       //  Referenced by: '<S11>/Saturation'

  real32_T Polynomial_Coefs[3];        // Computed Parameter: Polynomial_Coefs
                                       //  Referenced by: '<S11>/Polynomial'

  real32_T Saturation1_UpperSat_o;     // Computed Parameter: Saturation1_UpperSat_o
                                       //  Referenced by: '<S11>/Saturation1'

  real32_T Saturation1_LowerSat_o;     // Computed Parameter: Saturation1_LowerSat_o
                                       //  Referenced by: '<S11>/Saturation1'

  uint32_T Delay_DelayLength;          // Computed Parameter: Delay_DelayLength
                                       //  Referenced by: '<S2>/Delay'

};

// Real-time Model Data Structure
struct tag_RTM_Ctrl_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern real32_T AltKp;                 // Variable: AltKp
                                       //  Referenced by: '<S21>/Proportional Gain'

extern real32_T AltRateBias;           // Variable: AltRateBias
                                       //  Referenced by:
                                       //    '<S13>/Bias1'
                                       //    '<S80>/Bias1'

extern real32_T AltRateKi;             // Variable: AltRateKi
                                       //  Referenced by:
                                       //    '<S20>/Integral Gain'
                                       //    '<S86>/Integral Gain'

extern real32_T AltRateKp;             // Variable: AltRateKp
                                       //  Referenced by:
                                       //    '<S20>/Proportional Gain'
                                       //    '<S86>/Proportional Gain'

extern real32_T FilterK[100];          // Variable: FilterK
                                       //  Referenced by: '<S2>/Discrete FIR Filter'

extern real32_T PosKp;                 // Variable: PosKp
                                       //  Referenced by:
                                       //    '<S30>/Proportional Gain'
                                       //    '<S31>/Proportional Gain'

extern real32_T RollPitchKp;           // Variable: RollPitchKp
                                       //  Referenced by:
                                       //    '<S28>/Proportional Gain'
                                       //    '<S33>/Proportional Gain'
                                       //    '<S73>/Proportional Gain'
                                       //    '<S76>/Proportional Gain'
                                       //    '<S93>/Proportional Gain'
                                       //    '<S96>/Proportional Gain'

extern real32_T RollPitchMax;          // Variable: RollPitchMax
                                       //  Referenced by:
                                       //    '<S15>/Scale roll1'
                                       //    '<S17>/Scale roll2'
                                       //    '<S65>/Scale roll1'
                                       //    '<S66>/Scale roll2'
                                       //    '<S82>/Scale roll1'
                                       //    '<S83>/Scale roll2'

extern real32_T RollPitchRateKd;       // Variable: RollPitchRateKd
                                       //  Referenced by:
                                       //    '<S27>/Derivative Gain'
                                       //    '<S32>/Derivative Gain'
                                       //    '<S58>/Derivative Gain'
                                       //    '<S60>/Derivative Gain'
                                       //    '<S72>/Derivative Gain'
                                       //    '<S75>/Derivative Gain'
                                       //    '<S92>/Derivative Gain'
                                       //    '<S95>/Derivative Gain'

extern real32_T RollPitchRateKi;       // Variable: RollPitchRateKi
                                       //  Referenced by:
                                       //    '<S27>/Integral Gain'
                                       //    '<S32>/Integral Gain'
                                       //    '<S58>/Integral Gain'
                                       //    '<S60>/Integral Gain'
                                       //    '<S72>/Integral Gain'
                                       //    '<S75>/Integral Gain'
                                       //    '<S92>/Integral Gain'
                                       //    '<S95>/Integral Gain'

extern real32_T RollPitchRateKp;       // Variable: RollPitchRateKp
                                       //  Referenced by:
                                       //    '<S27>/Proportional Gain'
                                       //    '<S32>/Proportional Gain'
                                       //    '<S58>/Proportional Gain'
                                       //    '<S60>/Proportional Gain'
                                       //    '<S72>/Proportional Gain'
                                       //    '<S75>/Proportional Gain'
                                       //    '<S92>/Proportional Gain'
                                       //    '<S95>/Proportional Gain'

extern real32_T RollPitchRateMax;      // Variable: RollPitchRateMax
                                       //  Referenced by:
                                       //    '<S51>/Scale roll2'
                                       //    '<S52>/Scale roll2'
                                       //    '<S28>/Saturate'
                                       //    '<S33>/Saturate'
                                       //    '<S73>/Saturate'
                                       //    '<S76>/Saturate'
                                       //    '<S93>/Saturate'
                                       //    '<S96>/Saturate'

extern real32_T VelKi;                 // Variable: VelKi
                                       //  Referenced by:
                                       //    '<S36>/Integral Gain'
                                       //    '<S37>/Integral Gain'
                                       //    '<S99>/Integral Gain'
                                       //    '<S100>/Integral Gain'

extern real32_T VelKp;                 // Variable: VelKp
                                       //  Referenced by:
                                       //    '<S36>/Proportional Gain'
                                       //    '<S37>/Proportional Gain'
                                       //    '<S99>/Proportional Gain'
                                       //    '<S100>/Proportional Gain'

extern real32_T VelMax;                // Variable: VelMax
                                       //  Referenced by:
                                       //    '<S18>/Gain'
                                       //    '<S18>/Gain1'
                                       //    '<S84>/Gain'
                                       //    '<S84>/Gain1'

extern real32_T YawKp;                 // Variable: YawKp
                                       //  Referenced by:
                                       //    '<S42>/Proportional Gain'
                                       //    '<S105>/Proportional Gain'

extern real32_T YawRateKi;             // Variable: YawRateKi
                                       //  Referenced by:
                                       //    '<S41>/Integral Gain'
                                       //    '<S62>/Integral Gain'
                                       //    '<S78>/Integral Gain'
                                       //    '<S104>/Integral Gain'

extern real32_T YawRateKp;             // Variable: YawRateKp
                                       //  Referenced by:
                                       //    '<S41>/Proportional Gain'
                                       //    '<S62>/Proportional Gain'
                                       //    '<S78>/Proportional Gain'
                                       //    '<S104>/Proportional Gain'

extern real32_T YawRateMax;            // Variable: YawRateMax
                                       //  Referenced by:
                                       //    '<S53>/Scale roll2'
                                       //    '<S67>/Scale roll2'
                                       //    '<S42>/Saturate'
                                       //    '<S105>/Saturate'


// Class declaration for model Ctrl
class CtrlModelClass {
  // public data and function members
 public:
  // Tunable parameters
  P_Ctrl_T Ctrl_P;

  // Block signals
  B_Ctrl_T Ctrl_B;

  // Block states
  DW_Ctrl_T Ctrl_DW;

  // External inputs
  ExtU_Ctrl_T Ctrl_U;

  // External outputs
  ExtY_Ctrl_T Ctrl_Y;

  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  CtrlModelClass();

  // Destructor
  ~CtrlModelClass();

  // Real-Time Model get method
  RT_MODEL_Ctrl_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_Ctrl_T Ctrl_M;

  // private member function(s) for subsystem '<Root>'
  void Ctrl_SelectMode(void);
  void Ctrl_CalculateTrajSegment(uint8_T index1, uint8_T index2, real32_T
    velocity);
  void Ctrl_SystemLogic(const real32_T TmpSignalConversionAtSFunctionI[3]);
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('ModelRiki/Ctrl')    - opens subsystem ModelRiki/Ctrl
//  hilite_system('ModelRiki/Ctrl/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ModelRiki'
//  '<S1>'   : 'ModelRiki/Ctrl'
//  '<S2>'   : 'ModelRiki/Ctrl/AltCalculator'
//  '<S3>'   : 'ModelRiki/Ctrl/AutoCtrl'
//  '<S4>'   : 'ModelRiki/Ctrl/Chart'
//  '<S5>'   : 'ModelRiki/Ctrl/Input Scaler'
//  '<S6>'   : 'ModelRiki/Ctrl/ManualCtrl'
//  '<S7>'   : 'ModelRiki/Ctrl/Off'
//  '<S8>'   : 'ModelRiki/Ctrl/RateCtrl'
//  '<S9>'   : 'ModelRiki/Ctrl/RollPitchCtrl'
//  '<S10>'  : 'ModelRiki/Ctrl/VelocityCtrl'
//  '<S11>'  : 'ModelRiki/Ctrl/VoltageToFuel'
//  '<S12>'  : 'ModelRiki/Ctrl/AltCalculator/MATLAB Function'
//  '<S13>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller'
//  '<S14>'  : 'ModelRiki/Ctrl/AutoCtrl/Mapper'
//  '<S15>'  : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller'
//  '<S16>'  : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl'
//  '<S17>'  : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller'
//  '<S18>'  : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl'
//  '<S19>'  : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller'
//  '<S20>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1'
//  '<S21>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2'
//  '<S22>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Clamping circuit'
//  '<S23>'  : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale'
//  '<S24>'  : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale1'
//  '<S25>'  : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale2'
//  '<S26>'  : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale3'
//  '<S27>'  : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller'
//  '<S28>'  : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1'
//  '<S29>'  : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Clamping circuit'
//  '<S30>'  : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1'
//  '<S31>'  : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2'
//  '<S32>'  : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller'
//  '<S33>'  : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1'
//  '<S34>'  : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Clamping circuit'
//  '<S35>'  : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Degrees to Radians'
//  '<S36>'  : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1'
//  '<S37>'  : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2'
//  '<S38>'  : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Clamping circuit'
//  '<S39>'  : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Clamping circuit'
//  '<S40>'  : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Correct Yaw1'
//  '<S41>'  : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller'
//  '<S42>'  : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3'
//  '<S43>'  : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Radians to Degrees'
//  '<S44>'  : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Clamping circuit'
//  '<S45>'  : 'ModelRiki/Ctrl/ManualCtrl/Mapper'
//  '<S46>'  : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale'
//  '<S47>'  : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale1'
//  '<S48>'  : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale2'
//  '<S49>'  : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale3'
//  '<S50>'  : 'ModelRiki/Ctrl/RateCtrl/Mapper'
//  '<S51>'  : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller'
//  '<S52>'  : 'ModelRiki/Ctrl/RateCtrl/Roll Controller'
//  '<S53>'  : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller'
//  '<S54>'  : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale'
//  '<S55>'  : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale1'
//  '<S56>'  : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale2'
//  '<S57>'  : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale3'
//  '<S58>'  : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller'
//  '<S59>'  : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Clamping circuit'
//  '<S60>'  : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller'
//  '<S61>'  : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Clamping circuit'
//  '<S62>'  : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller'
//  '<S63>'  : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Clamping circuit'
//  '<S64>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper'
//  '<S65>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller'
//  '<S66>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller'
//  '<S67>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller'
//  '<S68>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale'
//  '<S69>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale1'
//  '<S70>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale2'
//  '<S71>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale3'
//  '<S72>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller'
//  '<S73>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1'
//  '<S74>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Clamping circuit'
//  '<S75>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller'
//  '<S76>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1'
//  '<S77>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Clamping circuit'
//  '<S78>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller'
//  '<S79>'  : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Clamping circuit'
//  '<S80>'  : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller'
//  '<S81>'  : 'ModelRiki/Ctrl/VelocityCtrl/Mapper'
//  '<S82>'  : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller'
//  '<S83>'  : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller'
//  '<S84>'  : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1'
//  '<S85>'  : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller'
//  '<S86>'  : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1'
//  '<S87>'  : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Clamping circuit'
//  '<S88>'  : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale'
//  '<S89>'  : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale1'
//  '<S90>'  : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale2'
//  '<S91>'  : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale3'
//  '<S92>'  : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller'
//  '<S93>'  : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1'
//  '<S94>'  : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Clamping circuit'
//  '<S95>'  : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller'
//  '<S96>'  : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1'
//  '<S97>'  : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Clamping circuit'
//  '<S98>'  : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Degrees to Radians'
//  '<S99>'  : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1'
//  '<S100>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2'
//  '<S101>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Clamping circuit'
//  '<S102>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Clamping circuit'
//  '<S103>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Correct Yaw1'
//  '<S104>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller'
//  '<S105>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3'
//  '<S106>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Clamping circuit'

#endif                                 // RTW_HEADER_Ctrl_h_

//
// File trailer for generated code.
//
// [EOF]
//
