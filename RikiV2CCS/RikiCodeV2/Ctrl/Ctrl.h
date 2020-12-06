//
// File: Ctrl.h
//
// Code generated for Simulink model 'Ctrl'.
//
// Model version                  : 2.29
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Dec  6 15:33:43 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Texas Instruments->TMS470
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Ctrl_h_
#define RTW_HEADER_Ctrl_h_
#include <math.h>
#include "rtwtypes.h"
#include "Ctrl_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S19>/Correct Yaw1'
typedef struct {
  real32_T y;                          // '<S19>/Correct Yaw1'
} B_CorrectYaw1_Ctrl_T;

// Block signals (default storage)
typedef struct {
  real32_T PWM1;                       // '<S1>/Merge'
  real32_T PWM2;                       // '<S1>/Merge'
  real32_T PWM3;                       // '<S1>/Merge'
  real32_T PWM4;                       // '<S1>/Merge'
  real32_T VertVelRef;                 // '<S1052>/Scale Vel'
  real32_T VertVelOut;                 // '<S1052>/Bias1'
  real32_T RollRef;                    // '<S1055>/Scale roll2'
  real32_T dRollRef;                   // '<S1303>/Saturation'
  real32_T RollOut;                    // '<S1255>/Saturation'
  real32_T PitchRef;                   // '<S1054>/Scale roll1'
  real32_T dPitchRef;                  // '<S1203>/Saturation'
  real32_T PitchOut;                   // '<S1155>/Saturation'
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
  B_CorrectYaw1_Ctrl_T sf_CorrectYaw1_l;// '<S1057>/Correct Yaw1'
  B_CorrectYaw1_Ctrl_T sf_CorrectYaw1; // '<S19>/Correct Yaw1'
} B_Ctrl_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real32_T Integrator_DSTATE;          // '<S1092>/Integrator'
  real32_T Integrator_DSTATE_d;        // '<S1399>/Integrator'
  real32_T Integrator_DSTATE_b;        // '<S1349>/Integrator'
  real32_T Integrator_DSTATE_e;        // '<S1248>/Integrator'
  real32_T Filter_DSTATE;              // '<S1243>/Filter'
  real32_T Integrator_DSTATE_n;        // '<S1148>/Integrator'
  real32_T Filter_DSTATE_o;            // '<S1143>/Filter'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S1057>/Discrete-Time Integrator'
  real32_T Integrator_DSTATE_m;        // '<S1452>/Integrator'
  real32_T Integrator_DSTATE_h;        // '<S936>/Integrator'
  real32_T Filter_DSTATE_c;            // '<S931>/Filter'
  real32_T Integrator_DSTATE_h0;       // '<S836>/Integrator'
  real32_T Filter_DSTATE_oq;           // '<S831>/Filter'
  real32_T Integrator_DSTATE_o;        // '<S1035>/Integrator'
  real32_T Integrator_DSTATE_i;        // '<S725>/Integrator'
  real32_T Filter_DSTATE_f;            // '<S720>/Filter'
  real32_T Integrator_DSTATE_g;        // '<S674>/Integrator'
  real32_T Filter_DSTATE_b;            // '<S669>/Filter'
  real32_T Integrator_DSTATE_f;        // '<S776>/Integrator'
  real32_T Integrator_DSTATE_k;        // '<S55>/Integrator'
  real32_T Integrator_DSTATE_l;        // '<S508>/Integrator'
  real32_T Integrator_DSTATE_lw;       // '<S458>/Integrator'
  real32_T Integrator_DSTATE_gj;       // '<S357>/Integrator'
  real32_T Filter_DSTATE_a;            // '<S352>/Filter'
  real32_T Integrator_DSTATE_c;        // '<S159>/Integrator'
  real32_T Filter_DSTATE_e;            // '<S154>/Filter'
  real32_T DiscreteTimeIntegrator_DSTATE_f;// '<S19>/Discrete-Time Integrator'
  real32_T Integrator_DSTATE_mo;       // '<S562>/Integrator'
  real32_T OrbPhi;                     // '<S1>/Chart'
  real32_T OrbRadius;                  // '<S1>/Chart'
  real32_T OrbdPhidT;                  // '<S1>/Chart'
  real32_T dPdT[3];                    // '<S1>/Chart'
  real32_T P1[3];                      // '<S1>/Chart'
  real32_T Ttotal;                     // '<S1>/Chart'
  real32_T Time;                       // '<S1>/Chart'
  uint16_T temporalCounter_i1;         // '<S1>/Chart'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S1057>/Discrete-Time Integrator'
  uint8_T is_active_c1_Ctrl;           // '<S1>/Chart'
  uint8_T is_SystemLogic;              // '<S1>/Chart'
  uint8_T is_On;                       // '<S1>/Chart'
  uint8_T is_AutoMode;                 // '<S1>/Chart'
  uint8_T is_LEDs;                     // '<S1>/Chart'
  uint8_T is_Off;                      // '<S1>/Chart'
  uint8_T is_On_e;                     // '<S1>/Chart'
  uint8_T Mode;                        // '<S1>/Chart'
  uint8_T wayIndex;                    // '<S1>/Chart'
  uint8_T ModeOld;                     // '<S1>/Chart'
  uint8_T temporalCounter_i2;          // '<S1>/Chart'
  uint8_T DiscreteTimeIntegrator_IC_LOA_j;// '<S19>/Discrete-Time Integrator'
  boolean_T VelocityCtrl_MODE;         // '<S1>/VelocityCtrl'
  boolean_T RollPitchCtrl_MODE;        // '<S1>/RollPitchCtrl'
  boolean_T RateCtrl_MODE;             // '<S1>/RateCtrl'
  boolean_T AutoCtrl_MODE;             // '<S1>/AutoCtrl'
} DW_Ctrl_T;

// External inputs (root inport signals with default storage)
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
  real32_T GPSHeight;                  // '<Root>/GPSHeight'
} ExtU_Ctrl_T;

// External outputs (root outports fed by signals with default storage)
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

// Parameters (default storage)
struct P_Ctrl_T_ {
  real32_T DiscretePIDController_InitialCo;
                              // Mask Parameter: DiscretePIDController_InitialCo
                                 //  Referenced by: '<S352>/Filter'

  real32_T DiscretePIDController_Initial_n;
                              // Mask Parameter: DiscretePIDController_Initial_n
                                 //  Referenced by: '<S154>/Filter'

  real32_T DiscretePIDController_Initial_c;
                              // Mask Parameter: DiscretePIDController_Initial_c
                                 //  Referenced by: '<S720>/Filter'

  real32_T DiscretePIDController_Initial_l;
                              // Mask Parameter: DiscretePIDController_Initial_l
                                 //  Referenced by: '<S669>/Filter'

  real32_T DiscretePIDController_Initial_p;
                              // Mask Parameter: DiscretePIDController_Initial_p
                                 //  Referenced by: '<S931>/Filter'

  real32_T DiscretePIDController_Initial_d;
                              // Mask Parameter: DiscretePIDController_Initial_d
                                 //  Referenced by: '<S831>/Filter'

  real32_T DiscretePIDController_Initial_j;
                              // Mask Parameter: DiscretePIDController_Initial_j
                                 //  Referenced by: '<S1243>/Filter'

  real32_T DiscretePIDController_Initia_nr;
                              // Mask Parameter: DiscretePIDController_Initia_nr
                                 //  Referenced by: '<S1143>/Filter'

  real32_T DiscretePIDController1_InitialC;
                              // Mask Parameter: DiscretePIDController1_InitialC
                                 //  Referenced by: '<S55>/Integrator'

  real32_T DiscretePIDController2_InitialC;
                              // Mask Parameter: DiscretePIDController2_InitialC
                                 //  Referenced by: '<S508>/Integrator'

  real32_T DiscretePIDController1_Initia_k;
                              // Mask Parameter: DiscretePIDController1_Initia_k
                                 //  Referenced by: '<S458>/Integrator'

  real32_T DiscretePIDController_Initia_cd;
                              // Mask Parameter: DiscretePIDController_Initia_cd
                                 //  Referenced by: '<S357>/Integrator'

  real32_T DiscretePIDController_Initial_m;
                              // Mask Parameter: DiscretePIDController_Initial_m
                                 //  Referenced by: '<S159>/Integrator'

  real32_T DiscretePIDController_Initia_c5;
                              // Mask Parameter: DiscretePIDController_Initia_c5
                                 //  Referenced by: '<S562>/Integrator'

  real32_T DiscretePIDController_Initia_mn;
                              // Mask Parameter: DiscretePIDController_Initia_mn
                                 //  Referenced by: '<S725>/Integrator'

  real32_T DiscretePIDController_Initial_f;
                              // Mask Parameter: DiscretePIDController_Initial_f
                                 //  Referenced by: '<S674>/Integrator'

  real32_T DiscretePIDController_Initial_a;
                              // Mask Parameter: DiscretePIDController_Initial_a
                                 //  Referenced by: '<S776>/Integrator'

  real32_T DiscretePIDController_Initia_pb;
                              // Mask Parameter: DiscretePIDController_Initia_pb
                                 //  Referenced by: '<S936>/Integrator'

  real32_T DiscretePIDController_Initial_b;
                              // Mask Parameter: DiscretePIDController_Initial_b
                                 //  Referenced by: '<S836>/Integrator'

  real32_T DiscretePIDController_Initia_np;
                              // Mask Parameter: DiscretePIDController_Initia_np
                                 //  Referenced by: '<S1035>/Integrator'

  real32_T DiscretePIDController1_Initia_c;
                              // Mask Parameter: DiscretePIDController1_Initia_c
                                 //  Referenced by: '<S1092>/Integrator'

  real32_T DiscretePIDController2_Initia_k;
                              // Mask Parameter: DiscretePIDController2_Initia_k
                                 //  Referenced by: '<S1399>/Integrator'

  real32_T DiscretePIDController1_Initia_j;
                              // Mask Parameter: DiscretePIDController1_Initia_j
                                 //  Referenced by: '<S1349>/Integrator'

  real32_T DiscretePIDController_Initia_jc;
                              // Mask Parameter: DiscretePIDController_Initia_jc
                                 //  Referenced by: '<S1248>/Integrator'

  real32_T DiscretePIDController_Initia_lr;
                              // Mask Parameter: DiscretePIDController_Initia_lr
                                 //  Referenced by: '<S1148>/Integrator'

  real32_T DiscretePIDController_Initi_c5w;
                              // Mask Parameter: DiscretePIDController_Initi_c5w
                                 //  Referenced by: '<S1452>/Integrator'

  real32_T DiscretePIDController2_LowerSat;
                              // Mask Parameter: DiscretePIDController2_LowerSat
                                 //  Referenced by: '<S110>/Saturation'

  real32_T DiscretePIDController1_LowerSat;
                              // Mask Parameter: DiscretePIDController1_LowerSat
                                 //  Referenced by:
                                 //    '<S62>/Saturation'
                                 //    '<S48>/DeadZone'

  real32_T DiscretePIDController2_LowerS_e;
                              // Mask Parameter: DiscretePIDController2_LowerS_e
                                 //  Referenced by: '<S312>/Saturation'

  real32_T DiscretePIDController2_LowerS_h;
                              // Mask Parameter: DiscretePIDController2_LowerS_h
                                 //  Referenced by:
                                 //    '<S515>/Saturation'
                                 //    '<S501>/DeadZone'

  real32_T DiscretePIDController1_LowerS_m;
                              // Mask Parameter: DiscretePIDController1_LowerS_m
                                 //  Referenced by: '<S264>/Saturation'

  real32_T DiscretePIDController1_LowerS_p;
                              // Mask Parameter: DiscretePIDController1_LowerS_p
                                 //  Referenced by:
                                 //    '<S465>/Saturation'
                                 //    '<S451>/DeadZone'

  real32_T DiscretePIDController1_LowerS_g;
                              // Mask Parameter: DiscretePIDController1_LowerS_g
                                 //  Referenced by: '<S412>/Saturation'

  real32_T DiscretePIDController_LowerSatu;
                              // Mask Parameter: DiscretePIDController_LowerSatu
                                 //  Referenced by:
                                 //    '<S364>/Saturation'
                                 //    '<S350>/DeadZone'

  real32_T DiscretePIDController1_LowerS_n;
                              // Mask Parameter: DiscretePIDController1_LowerS_n
                                 //  Referenced by: '<S214>/Saturation'

  real32_T DiscretePIDController_LowerSa_o;
                              // Mask Parameter: DiscretePIDController_LowerSa_o
                                 //  Referenced by:
                                 //    '<S166>/Saturation'
                                 //    '<S152>/DeadZone'

  real32_T DiscretePIDController3_LowerSat;
                              // Mask Parameter: DiscretePIDController3_LowerSat
                                 //  Referenced by: '<S617>/Saturation'

  real32_T DiscretePIDController_LowerSa_i;
                              // Mask Parameter: DiscretePIDController_LowerSa_i
                                 //  Referenced by:
                                 //    '<S569>/Saturation'
                                 //    '<S555>/DeadZone'

  real32_T DiscretePIDController_LowerSa_k;
                              // Mask Parameter: DiscretePIDController_LowerSa_k
                                 //  Referenced by:
                                 //    '<S732>/Saturation'
                                 //    '<S718>/DeadZone'

  real32_T DiscretePIDController_LowerS_io;
                              // Mask Parameter: DiscretePIDController_LowerS_io
                                 //  Referenced by:
                                 //    '<S681>/Saturation'
                                 //    '<S667>/DeadZone'

  real32_T DiscretePIDController_LowerSa_a;
                              // Mask Parameter: DiscretePIDController_LowerSa_a
                                 //  Referenced by:
                                 //    '<S783>/Saturation'
                                 //    '<S769>/DeadZone'

  real32_T DiscretePIDController1_LowerS_d;
                              // Mask Parameter: DiscretePIDController1_LowerS_d
                                 //  Referenced by: '<S991>/Saturation'

  real32_T DiscretePIDController_LowerSa_b;
                              // Mask Parameter: DiscretePIDController_LowerSa_b
                                 //  Referenced by:
                                 //    '<S943>/Saturation'
                                 //    '<S929>/DeadZone'

  real32_T DiscretePIDController1_Lower_de;
                              // Mask Parameter: DiscretePIDController1_Lower_de
                                 //  Referenced by: '<S891>/Saturation'

  real32_T DiscretePIDController_LowerSa_p;
                              // Mask Parameter: DiscretePIDController_LowerSa_p
                                 //  Referenced by:
                                 //    '<S843>/Saturation'
                                 //    '<S829>/DeadZone'

  real32_T DiscretePIDController_LowerSa_f;
                              // Mask Parameter: DiscretePIDController_LowerSa_f
                                 //  Referenced by:
                                 //    '<S1042>/Saturation'
                                 //    '<S1028>/DeadZone'

  real32_T DiscretePIDController1_LowerS_b;
                              // Mask Parameter: DiscretePIDController1_LowerS_b
                                 //  Referenced by:
                                 //    '<S1099>/Saturation'
                                 //    '<S1085>/DeadZone'

  real32_T DiscretePIDController2_LowerS_a;
                              // Mask Parameter: DiscretePIDController2_LowerS_a
                                 //  Referenced by:
                                 //    '<S1406>/Saturation'
                                 //    '<S1392>/DeadZone'

  real32_T DiscretePIDController1_LowerS_e;
                              // Mask Parameter: DiscretePIDController1_LowerS_e
                                 //  Referenced by:
                                 //    '<S1356>/Saturation'
                                 //    '<S1342>/DeadZone'

  real32_T DiscretePIDController1_Lower_pq;
                              // Mask Parameter: DiscretePIDController1_Lower_pq
                                 //  Referenced by: '<S1303>/Saturation'

  real32_T DiscretePIDController_LowerS_ok;
                              // Mask Parameter: DiscretePIDController_LowerS_ok
                                 //  Referenced by:
                                 //    '<S1255>/Saturation'
                                 //    '<S1241>/DeadZone'

  real32_T DiscretePIDController1_LowerS_f;
                              // Mask Parameter: DiscretePIDController1_LowerS_f
                                 //  Referenced by: '<S1203>/Saturation'

  real32_T DiscretePIDController_LowerS_a3;
                              // Mask Parameter: DiscretePIDController_LowerS_a3
                                 //  Referenced by:
                                 //    '<S1155>/Saturation'
                                 //    '<S1141>/DeadZone'

  real32_T DiscretePIDController3_LowerS_f;
                              // Mask Parameter: DiscretePIDController3_LowerS_f
                                 //  Referenced by: '<S1507>/Saturation'

  real32_T DiscretePIDController_LowerSa_m;
                              // Mask Parameter: DiscretePIDController_LowerSa_m
                                 //  Referenced by:
                                 //    '<S1459>/Saturation'
                                 //    '<S1445>/DeadZone'

  real32_T DiscretePIDController_N;   // Mask Parameter: DiscretePIDController_N
                                         //  Referenced by: '<S360>/Filter Coefficient'

  real32_T DiscretePIDController_N_h;
                                    // Mask Parameter: DiscretePIDController_N_h
                                       //  Referenced by: '<S162>/Filter Coefficient'

  real32_T DiscretePIDController_N_hm;
                                   // Mask Parameter: DiscretePIDController_N_hm
                                      //  Referenced by: '<S728>/Filter Coefficient'

  real32_T DiscretePIDController_N_p;
                                    // Mask Parameter: DiscretePIDController_N_p
                                       //  Referenced by: '<S677>/Filter Coefficient'

  real32_T DiscretePIDController_N_i;
                                    // Mask Parameter: DiscretePIDController_N_i
                                       //  Referenced by: '<S939>/Filter Coefficient'

  real32_T DiscretePIDController_N_hn;
                                   // Mask Parameter: DiscretePIDController_N_hn
                                      //  Referenced by: '<S839>/Filter Coefficient'

  real32_T DiscretePIDController_N_n;
                                    // Mask Parameter: DiscretePIDController_N_n
                                       //  Referenced by: '<S1251>/Filter Coefficient'

  real32_T DiscretePIDController_N_g;
                                    // Mask Parameter: DiscretePIDController_N_g
                                       //  Referenced by: '<S1151>/Filter Coefficient'

  real32_T DiscretePIDController2_UpperSat;
                              // Mask Parameter: DiscretePIDController2_UpperSat
                                 //  Referenced by: '<S110>/Saturation'

  real32_T DiscretePIDController1_UpperSat;
                              // Mask Parameter: DiscretePIDController1_UpperSat
                                 //  Referenced by:
                                 //    '<S62>/Saturation'
                                 //    '<S48>/DeadZone'

  real32_T DiscretePIDController2_UpperS_o;
                              // Mask Parameter: DiscretePIDController2_UpperS_o
                                 //  Referenced by: '<S312>/Saturation'

  real32_T DiscretePIDController2_UpperS_d;
                              // Mask Parameter: DiscretePIDController2_UpperS_d
                                 //  Referenced by:
                                 //    '<S515>/Saturation'
                                 //    '<S501>/DeadZone'

  real32_T DiscretePIDController1_UpperS_b;
                              // Mask Parameter: DiscretePIDController1_UpperS_b
                                 //  Referenced by: '<S264>/Saturation'

  real32_T DiscretePIDController1_UpperS_g;
                              // Mask Parameter: DiscretePIDController1_UpperS_g
                                 //  Referenced by:
                                 //    '<S465>/Saturation'
                                 //    '<S451>/DeadZone'

  real32_T DiscretePIDController_UpperSatu;
                              // Mask Parameter: DiscretePIDController_UpperSatu
                                 //  Referenced by:
                                 //    '<S364>/Saturation'
                                 //    '<S350>/DeadZone'

  real32_T DiscretePIDController_UpperSa_g;
                              // Mask Parameter: DiscretePIDController_UpperSa_g
                                 //  Referenced by:
                                 //    '<S166>/Saturation'
                                 //    '<S152>/DeadZone'

  real32_T DiscretePIDController_UpperS_gi;
                              // Mask Parameter: DiscretePIDController_UpperS_gi
                                 //  Referenced by:
                                 //    '<S569>/Saturation'
                                 //    '<S555>/DeadZone'

  real32_T DiscretePIDController_UpperSa_h;
                              // Mask Parameter: DiscretePIDController_UpperSa_h
                                 //  Referenced by:
                                 //    '<S732>/Saturation'
                                 //    '<S718>/DeadZone'

  real32_T DiscretePIDController_UpperSa_n;
                              // Mask Parameter: DiscretePIDController_UpperSa_n
                                 //  Referenced by:
                                 //    '<S681>/Saturation'
                                 //    '<S667>/DeadZone'

  real32_T DiscretePIDController_UpperSa_b;
                              // Mask Parameter: DiscretePIDController_UpperSa_b
                                 //  Referenced by:
                                 //    '<S783>/Saturation'
                                 //    '<S769>/DeadZone'

  real32_T DiscretePIDController_UpperSa_p;
                              // Mask Parameter: DiscretePIDController_UpperSa_p
                                 //  Referenced by:
                                 //    '<S943>/Saturation'
                                 //    '<S929>/DeadZone'

  real32_T DiscretePIDController_UpperSa_i;
                              // Mask Parameter: DiscretePIDController_UpperSa_i
                                 //  Referenced by:
                                 //    '<S843>/Saturation'
                                 //    '<S829>/DeadZone'

  real32_T DiscretePIDController_UpperSa_k;
                              // Mask Parameter: DiscretePIDController_UpperSa_k
                                 //  Referenced by:
                                 //    '<S1042>/Saturation'
                                 //    '<S1028>/DeadZone'

  real32_T DiscretePIDController1_UpperS_l;
                              // Mask Parameter: DiscretePIDController1_UpperS_l
                                 //  Referenced by:
                                 //    '<S1099>/Saturation'
                                 //    '<S1085>/DeadZone'

  real32_T DiscretePIDController2_UpperS_i;
                              // Mask Parameter: DiscretePIDController2_UpperS_i
                                 //  Referenced by:
                                 //    '<S1406>/Saturation'
                                 //    '<S1392>/DeadZone'

  real32_T DiscretePIDController1_UpperS_n;
                              // Mask Parameter: DiscretePIDController1_UpperS_n
                                 //  Referenced by:
                                 //    '<S1356>/Saturation'
                                 //    '<S1342>/DeadZone'

  real32_T DiscretePIDController_UpperS_ii;
                              // Mask Parameter: DiscretePIDController_UpperS_ii
                                 //  Referenced by:
                                 //    '<S1255>/Saturation'
                                 //    '<S1241>/DeadZone'

  real32_T DiscretePIDController_UpperSa_m;
                              // Mask Parameter: DiscretePIDController_UpperSa_m
                                 //  Referenced by:
                                 //    '<S1155>/Saturation'
                                 //    '<S1141>/DeadZone'

  real32_T DiscretePIDController_UpperS_nb;
                              // Mask Parameter: DiscretePIDController_UpperS_nb
                                 //  Referenced by:
                                 //    '<S1459>/Saturation'
                                 //    '<S1445>/DeadZone'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S528>/Gain'

  real32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S46>/Constant1'

  real32_T Constant1_Value_c;          // Computed Parameter: Constant1_Value_c
                                          //  Referenced by: '<S150>/Constant1'

  real32_T Constant1_Value_p;          // Computed Parameter: Constant1_Value_p
                                          //  Referenced by: '<S348>/Constant1'

  real32_T Constant1_Value_b;          // Computed Parameter: Constant1_Value_b
                                          //  Referenced by: '<S449>/Constant1'

  real32_T Constant1_Value_g;          // Computed Parameter: Constant1_Value_g
                                          //  Referenced by: '<S499>/Constant1'

  real32_T Constant1_Value_j;          // Computed Parameter: Constant1_Value_j
                                          //  Referenced by: '<S553>/Constant1'

  real32_T ScaleVel_Gain;              // Computed Parameter: ScaleVel_Gain
                                          //  Referenced by: '<S13>/Scale Vel'

  real32_T FixFaultyBaro_UpperSat; // Computed Parameter: FixFaultyBaro_UpperSat
                                      //  Referenced by: '<S13>/Fix Faulty Baro'

  real32_T FixFaultyBaro_LowerSat; // Computed Parameter: FixFaultyBaro_LowerSat
                                      //  Referenced by: '<S13>/Fix Faulty Baro'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S55>/Integrator'

  real32_T ZeroGain_Gain;              // Computed Parameter: ZeroGain_Gain
                                          //  Referenced by: '<S46>/ZeroGain'

  real32_T LimitOutput_UpperSat;     // Computed Parameter: LimitOutput_UpperSat
                                        //  Referenced by: '<S13>/Limit Output'

  real32_T LimitOutput_LowerSat;     // Computed Parameter: LimitOutput_LowerSat
                                        //  Referenced by: '<S13>/Limit Output'

  real32_T Integrator_gainval_c;     // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S508>/Integrator'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S422>/Gain1'

  real32_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S458>/Integrator'

  real32_T Integrator_gainval_a;     // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S357>/Integrator'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S352>/Filter'

  real32_T Integrator_gainval_ao;   // Computed Parameter: Integrator_gainval_ao
                                       //  Referenced by: '<S159>/Integrator'

  real32_T Filter_gainval_e;           // Computed Parameter: Filter_gainval_e
                                          //  Referenced by: '<S154>/Filter'

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S19>/Discrete-Time Integrator'

  real32_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S19>/Switch'

  real32_T Integrator_gainval_p;     // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S562>/Integrator'

  real32_T Constant_Value;             // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S120>/Constant'

  real32_T Limit3_UpperSat;            // Computed Parameter: Limit3_UpperSat
                                          //  Referenced by: '<S120>/Limit3'

  real32_T Limit3_LowerSat;            // Computed Parameter: Limit3_LowerSat
                                          //  Referenced by: '<S120>/Limit3'

  real32_T Gain_Gain_f;                // Computed Parameter: Gain_Gain_f
                                          //  Referenced by: '<S120>/Gain'

  real32_T Constant_Value_a;           // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S121>/Constant'

  real32_T Limit3_UpperSat_k;          // Computed Parameter: Limit3_UpperSat_k
                                          //  Referenced by: '<S121>/Limit3'

  real32_T Limit3_LowerSat_i;          // Computed Parameter: Limit3_LowerSat_i
                                          //  Referenced by: '<S121>/Limit3'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S121>/Gain'

  real32_T Constant_Value_j;           // Computed Parameter: Constant_Value_j
                                          //  Referenced by: '<S122>/Constant'

  real32_T Limit3_UpperSat_m;          // Computed Parameter: Limit3_UpperSat_m
                                          //  Referenced by: '<S122>/Limit3'

  real32_T Limit3_LowerSat_ih;         // Computed Parameter: Limit3_LowerSat_ih
                                          //  Referenced by: '<S122>/Limit3'

  real32_T Gain_Gain_j;                // Computed Parameter: Gain_Gain_j
                                          //  Referenced by: '<S122>/Gain'

  real32_T Constant_Value_p;           // Computed Parameter: Constant_Value_p
                                          //  Referenced by: '<S123>/Constant'

  real32_T Limit3_UpperSat_a;          // Computed Parameter: Limit3_UpperSat_a
                                          //  Referenced by: '<S123>/Limit3'

  real32_T Limit3_LowerSat_n;          // Computed Parameter: Limit3_LowerSat_n
                                          //  Referenced by: '<S123>/Limit3'

  real32_T Gain_Gain_b;                // Computed Parameter: Gain_Gain_b
                                          //  Referenced by: '<S123>/Gain'

  real32_T ZeroGain_Gain_j;            // Computed Parameter: ZeroGain_Gain_j
                                          //  Referenced by: '<S150>/ZeroGain'

  real32_T ZeroGain_Gain_p;            // Computed Parameter: ZeroGain_Gain_p
                                          //  Referenced by: '<S348>/ZeroGain'

  real32_T ZeroGain_Gain_l;            // Computed Parameter: ZeroGain_Gain_l
                                          //  Referenced by: '<S449>/ZeroGain'

  real32_T ZeroGain_Gain_k;            // Computed Parameter: ZeroGain_Gain_k
                                          //  Referenced by: '<S499>/ZeroGain'

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: '<S19>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S19>/Dead Zone'

  real32_T ZeroGain_Gain_g;            // Computed Parameter: ZeroGain_Gain_g
                                          //  Referenced by: '<S553>/ZeroGain'

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
                                          //  Referenced by: '<S628>/Constant'

  real32_T Limit3_UpperSat_l;          // Computed Parameter: Limit3_UpperSat_l
                                          //  Referenced by: '<S628>/Limit3'

  real32_T Limit3_LowerSat_g;          // Computed Parameter: Limit3_LowerSat_g
                                          //  Referenced by: '<S628>/Limit3'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                          //  Referenced by: '<S628>/Gain'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S629>/Constant'

  real32_T Limit3_UpperSat_b;          // Computed Parameter: Limit3_UpperSat_b
                                          //  Referenced by: '<S629>/Limit3'

  real32_T Limit3_LowerSat_k;          // Computed Parameter: Limit3_LowerSat_k
                                          //  Referenced by: '<S629>/Limit3'

  real32_T Gain_Gain_c;                // Computed Parameter: Gain_Gain_c
                                          //  Referenced by: '<S629>/Gain'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S630>/Constant'

  real32_T Limit3_UpperSat_o;          // Computed Parameter: Limit3_UpperSat_o
                                          //  Referenced by: '<S630>/Limit3'

  real32_T Limit3_LowerSat_d;          // Computed Parameter: Limit3_LowerSat_d
                                          //  Referenced by: '<S630>/Limit3'

  real32_T Gain_Gain_e;                // Computed Parameter: Gain_Gain_e
                                          //  Referenced by: '<S630>/Gain'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S631>/Constant'

  real32_T Limit3_UpperSat_c;          // Computed Parameter: Limit3_UpperSat_c
                                          //  Referenced by: '<S631>/Limit3'

  real32_T Limit3_LowerSat_f;          // Computed Parameter: Limit3_LowerSat_f
                                          //  Referenced by: '<S631>/Limit3'

  real32_T Gain_Gain_bq;               // Computed Parameter: Gain_Gain_bq
                                          //  Referenced by: '<S631>/Gain'

  real32_T PWMs_Y0[4];                 // Computed Parameter: PWMs_Y0
                                          //  Referenced by: '<S7>/PWMs'

  real32_T Constant1_Value_l;          // Computed Parameter: Constant1_Value_l
                                          //  Referenced by: '<S7>/Constant1'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<S7>/Constant2'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<S7>/Constant3'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<S7>/Constant4'

  real32_T Constant1_Value_a;          // Computed Parameter: Constant1_Value_a
                                          //  Referenced by: '<S665>/Constant1'

  real32_T Constant1_Value_e;          // Computed Parameter: Constant1_Value_e
                                          //  Referenced by: '<S716>/Constant1'

  real32_T Constant1_Value_d;          // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S767>/Constant1'

  real32_T Gain_Gain_cu;               // Computed Parameter: Gain_Gain_cu
                                          //  Referenced by: '<S8>/Gain'

  real32_T Integrator_gainval_d;     // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S725>/Integrator'

  real32_T Filter_gainval_el;          // Computed Parameter: Filter_gainval_el
                                          //  Referenced by: '<S720>/Filter'

  real32_T Integrator_gainval_dd;   // Computed Parameter: Integrator_gainval_dd
                                       //  Referenced by: '<S674>/Integrator'

  real32_T Filter_gainval_n;           // Computed Parameter: Filter_gainval_n
                                          //  Referenced by: '<S669>/Filter'

  real32_T DeadZone_Start_c;           // Computed Parameter: DeadZone_Start_c
                                          //  Referenced by: '<S635>/Dead Zone'

  real32_T DeadZone_End_o;             // Computed Parameter: DeadZone_End_o
                                          //  Referenced by: '<S635>/Dead Zone'

  real32_T Integrator_gainval_g;     // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S776>/Integrator'

  real32_T Constant_Value_g;           // Computed Parameter: Constant_Value_g
                                          //  Referenced by: '<S636>/Constant'

  real32_T Limit3_UpperSat_d;          // Computed Parameter: Limit3_UpperSat_d
                                          //  Referenced by: '<S636>/Limit3'

  real32_T Limit3_LowerSat_ku;         // Computed Parameter: Limit3_LowerSat_ku
                                          //  Referenced by: '<S636>/Limit3'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S636>/Gain'

  real32_T Constant_Value_ev;          // Computed Parameter: Constant_Value_ev
                                          //  Referenced by: '<S637>/Constant'

  real32_T Limit3_UpperSat_a1;         // Computed Parameter: Limit3_UpperSat_a1
                                          //  Referenced by: '<S637>/Limit3'

  real32_T Limit3_LowerSat_e;          // Computed Parameter: Limit3_LowerSat_e
                                          //  Referenced by: '<S637>/Limit3'

  real32_T Gain_Gain_ce;               // Computed Parameter: Gain_Gain_ce
                                          //  Referenced by: '<S637>/Gain'

  real32_T Constant_Value_k;           // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S638>/Constant'

  real32_T Limit3_UpperSat_g;          // Computed Parameter: Limit3_UpperSat_g
                                          //  Referenced by: '<S638>/Limit3'

  real32_T Limit3_LowerSat_j;          // Computed Parameter: Limit3_LowerSat_j
                                          //  Referenced by: '<S638>/Limit3'

  real32_T Gain_Gain_cc;               // Computed Parameter: Gain_Gain_cc
                                          //  Referenced by: '<S638>/Gain'

  real32_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                          //  Referenced by: '<S639>/Constant'

  real32_T Limit3_UpperSat_j;          // Computed Parameter: Limit3_UpperSat_j
                                          //  Referenced by: '<S639>/Limit3'

  real32_T Limit3_LowerSat_o;          // Computed Parameter: Limit3_LowerSat_o
                                          //  Referenced by: '<S639>/Limit3'

  real32_T Gain_Gain_hp;               // Computed Parameter: Gain_Gain_hp
                                          //  Referenced by: '<S639>/Gain'

  real32_T ZeroGain_Gain_n;            // Computed Parameter: ZeroGain_Gain_n
                                          //  Referenced by: '<S665>/ZeroGain'

  real32_T ZeroGain_Gain_nc;           // Computed Parameter: ZeroGain_Gain_nc
                                          //  Referenced by: '<S716>/ZeroGain'

  real32_T ZeroGain_Gain_e;            // Computed Parameter: ZeroGain_Gain_e
                                          //  Referenced by: '<S767>/ZeroGain'

  real32_T Constant1_Value_i;          // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S827>/Constant1'

  real32_T Constant1_Value_o;          // Computed Parameter: Constant1_Value_o
                                          //  Referenced by: '<S927>/Constant1'

  real32_T Constant1_Value_m;          // Computed Parameter: Constant1_Value_m
                                          //  Referenced by: '<S1026>/Constant1'

  real32_T Gain_Gain_mu;               // Computed Parameter: Gain_Gain_mu
                                          //  Referenced by: '<S9>/Gain'

  real32_T Integrator_gainval_j;     // Computed Parameter: Integrator_gainval_j
                                        //  Referenced by: '<S936>/Integrator'

  real32_T Filter_gainval_j;           // Computed Parameter: Filter_gainval_j
                                          //  Referenced by: '<S931>/Filter'

  real32_T Integrator_gainval_i;     // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S836>/Integrator'

  real32_T Filter_gainval_p;           // Computed Parameter: Filter_gainval_p
                                          //  Referenced by: '<S831>/Filter'

  real32_T DeadZone_Start_l;           // Computed Parameter: DeadZone_Start_l
                                          //  Referenced by: '<S796>/Dead Zone'

  real32_T DeadZone_End_h;             // Computed Parameter: DeadZone_End_h
                                          //  Referenced by: '<S796>/Dead Zone'

  real32_T Integrator_gainval_im;   // Computed Parameter: Integrator_gainval_im
                                       //  Referenced by: '<S1035>/Integrator'

  real32_T Constant_Value_p4;          // Computed Parameter: Constant_Value_p4
                                          //  Referenced by: '<S797>/Constant'

  real32_T Limit3_UpperSat_b5;         // Computed Parameter: Limit3_UpperSat_b5
                                          //  Referenced by: '<S797>/Limit3'

  real32_T Limit3_LowerSat_jv;         // Computed Parameter: Limit3_LowerSat_jv
                                          //  Referenced by: '<S797>/Limit3'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S797>/Gain'

  real32_T Constant_Value_co;          // Computed Parameter: Constant_Value_co
                                          //  Referenced by: '<S798>/Constant'

  real32_T Limit3_UpperSat_gu;         // Computed Parameter: Limit3_UpperSat_gu
                                          //  Referenced by: '<S798>/Limit3'

  real32_T Limit3_LowerSat_dd;         // Computed Parameter: Limit3_LowerSat_dd
                                          //  Referenced by: '<S798>/Limit3'

  real32_T Gain_Gain_d;                // Computed Parameter: Gain_Gain_d
                                          //  Referenced by: '<S798>/Gain'

  real32_T Constant_Value_oi;          // Computed Parameter: Constant_Value_oi
                                          //  Referenced by: '<S799>/Constant'

  real32_T Limit3_UpperSat_kf;         // Computed Parameter: Limit3_UpperSat_kf
                                          //  Referenced by: '<S799>/Limit3'

  real32_T Limit3_LowerSat_du;         // Computed Parameter: Limit3_LowerSat_du
                                          //  Referenced by: '<S799>/Limit3'

  real32_T Gain_Gain_i;                // Computed Parameter: Gain_Gain_i
                                          //  Referenced by: '<S799>/Gain'

  real32_T Constant_Value_aw;          // Computed Parameter: Constant_Value_aw
                                          //  Referenced by: '<S800>/Constant'

  real32_T Limit3_UpperSat_n;          // Computed Parameter: Limit3_UpperSat_n
                                          //  Referenced by: '<S800>/Limit3'

  real32_T Limit3_LowerSat_b;          // Computed Parameter: Limit3_LowerSat_b
                                          //  Referenced by: '<S800>/Limit3'

  real32_T Gain_Gain_m5;               // Computed Parameter: Gain_Gain_m5
                                          //  Referenced by: '<S800>/Gain'

  real32_T ZeroGain_Gain_gv;           // Computed Parameter: ZeroGain_Gain_gv
                                          //  Referenced by: '<S827>/ZeroGain'

  real32_T ZeroGain_Gain_nb;           // Computed Parameter: ZeroGain_Gain_nb
                                          //  Referenced by: '<S927>/ZeroGain'

  real32_T ZeroGain_Gain_gq;           // Computed Parameter: ZeroGain_Gain_gq
                                          //  Referenced by: '<S1026>/ZeroGain'

  real32_T Constant1_Value_ok;         // Computed Parameter: Constant1_Value_ok
                                          //  Referenced by: '<S1083>/Constant1'

  real32_T Constant1_Value_k;          // Computed Parameter: Constant1_Value_k
                                          //  Referenced by: '<S1139>/Constant1'

  real32_T Constant1_Value_l0;         // Computed Parameter: Constant1_Value_l0
                                          //  Referenced by: '<S1239>/Constant1'

  real32_T Constant1_Value_kj;         // Computed Parameter: Constant1_Value_kj
                                          //  Referenced by: '<S1340>/Constant1'

  real32_T Constant1_Value_pl;         // Computed Parameter: Constant1_Value_pl
                                          //  Referenced by: '<S1390>/Constant1'

  real32_T Constant1_Value_do;         // Computed Parameter: Constant1_Value_do
                                          //  Referenced by: '<S1443>/Constant1'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S1052>/Bias'

  real32_T DeadZone_Start_p;           // Computed Parameter: DeadZone_Start_p
                                          //  Referenced by: '<S1052>/Dead Zone'

  real32_T DeadZone_End_b;             // Computed Parameter: DeadZone_End_b
                                          //  Referenced by: '<S1052>/Dead Zone'

  real32_T ScaleVel_Gain_a;            // Computed Parameter: ScaleVel_Gain_a
                                          //  Referenced by: '<S1052>/Scale Vel'

  real32_T FixFaultyBaro_UpperSat_d;
                                 // Computed Parameter: FixFaultyBaro_UpperSat_d
                                    //  Referenced by: '<S1052>/Fix Faulty Baro'

  real32_T FixFaultyBaro_LowerSat_o;
                                 // Computed Parameter: FixFaultyBaro_LowerSat_o
                                    //  Referenced by: '<S1052>/Fix Faulty Baro'

  real32_T Integrator_gainval_be;   // Computed Parameter: Integrator_gainval_be
                                       //  Referenced by: '<S1092>/Integrator'

  real32_T ZeroGain_Gain_ez;           // Computed Parameter: ZeroGain_Gain_ez
                                          //  Referenced by: '<S1083>/ZeroGain'

  real32_T LimitOutput_UpperSat_h; // Computed Parameter: LimitOutput_UpperSat_h
                                      //  Referenced by: '<S1052>/Limit Output'

  real32_T LimitOutput_LowerSat_f; // Computed Parameter: LimitOutput_LowerSat_f
                                      //  Referenced by: '<S1052>/Limit Output'

  real32_T Gain2_Gain_j;               // Computed Parameter: Gain2_Gain_j
                                          //  Referenced by: '<S10>/Gain2'

  real32_T Gain1_Gain_k;               // Computed Parameter: Gain1_Gain_k
                                          //  Referenced by: '<S1313>/Gain1'

  real32_T Integrator_gainval_l;     // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S1399>/Integrator'

  real32_T Integrator_gainval_by;   // Computed Parameter: Integrator_gainval_by
                                       //  Referenced by: '<S1349>/Integrator'

  real32_T Integrator_gainval_h;     // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S1248>/Integrator'

  real32_T Filter_gainval_f;           // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S1243>/Filter'

  real32_T Integrator_gainval_h3;   // Computed Parameter: Integrator_gainval_h3
                                       //  Referenced by: '<S1148>/Integrator'

  real32_T Filter_gainval_p4;          // Computed Parameter: Filter_gainval_p4
                                          //  Referenced by: '<S1143>/Filter'

  real32_T DiscreteTimeIntegrator_gainva_h;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                             //  Referenced by: '<S1057>/Discrete-Time Integrator'

  real32_T Integrator_gainval_lc;   // Computed Parameter: Integrator_gainval_lc
                                       //  Referenced by: '<S1452>/Integrator'

  real32_T Constant_Value_l;           // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S1109>/Constant'

  real32_T Limit3_UpperSat_p;          // Computed Parameter: Limit3_UpperSat_p
                                          //  Referenced by: '<S1109>/Limit3'

  real32_T Limit3_LowerSat_it;         // Computed Parameter: Limit3_LowerSat_it
                                          //  Referenced by: '<S1109>/Limit3'

  real32_T Gain_Gain_oa;               // Computed Parameter: Gain_Gain_oa
                                          //  Referenced by: '<S1109>/Gain'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S1110>/Constant'

  real32_T Limit3_UpperSat_e;          // Computed Parameter: Limit3_UpperSat_e
                                          //  Referenced by: '<S1110>/Limit3'

  real32_T Limit3_LowerSat_l;          // Computed Parameter: Limit3_LowerSat_l
                                          //  Referenced by: '<S1110>/Limit3'

  real32_T Gain_Gain_hh;               // Computed Parameter: Gain_Gain_hh
                                          //  Referenced by: '<S1110>/Gain'

  real32_T Constant_Value_f;           // Computed Parameter: Constant_Value_f
                                          //  Referenced by: '<S1111>/Constant'

  real32_T Limit3_UpperSat_lo;         // Computed Parameter: Limit3_UpperSat_lo
                                          //  Referenced by: '<S1111>/Limit3'

  real32_T Limit3_LowerSat_gb;         // Computed Parameter: Limit3_LowerSat_gb
                                          //  Referenced by: '<S1111>/Limit3'

  real32_T Gain_Gain_do;               // Computed Parameter: Gain_Gain_do
                                          //  Referenced by: '<S1111>/Gain'

  real32_T Constant_Value_d;           // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S1112>/Constant'

  real32_T Limit3_UpperSat_i;          // Computed Parameter: Limit3_UpperSat_i
                                          //  Referenced by: '<S1112>/Limit3'

  real32_T Limit3_LowerSat_d4;         // Computed Parameter: Limit3_LowerSat_d4
                                          //  Referenced by: '<S1112>/Limit3'

  real32_T Gain_Gain_bo;               // Computed Parameter: Gain_Gain_bo
                                          //  Referenced by: '<S1112>/Gain'

  real32_T ZeroGain_Gain_o;            // Computed Parameter: ZeroGain_Gain_o
                                          //  Referenced by: '<S1139>/ZeroGain'

  real32_T ZeroGain_Gain_e2;           // Computed Parameter: ZeroGain_Gain_e2
                                          //  Referenced by: '<S1239>/ZeroGain'

  real32_T ZeroGain_Gain_b;            // Computed Parameter: ZeroGain_Gain_b
                                          //  Referenced by: '<S1340>/ZeroGain'

  real32_T ZeroGain_Gain_ezr;          // Computed Parameter: ZeroGain_Gain_ezr
                                          //  Referenced by: '<S1390>/ZeroGain'

  real32_T DeadZone_Start_b;           // Computed Parameter: DeadZone_Start_b
                                          //  Referenced by: '<S1057>/Dead Zone'

  real32_T DeadZone_End_p;             // Computed Parameter: DeadZone_End_p
                                          //  Referenced by: '<S1057>/Dead Zone'

  real32_T ZeroGain_Gain_ny;           // Computed Parameter: ZeroGain_Gain_ny
                                          //  Referenced by: '<S1443>/ZeroGain'

  real32_T Scaleroll2_Gain_m;          // Computed Parameter: Scaleroll2_Gain_m
                                          //  Referenced by: '<S1057>/Scale roll2'

  real32_T Gain_Gain_n;                // Computed Parameter: Gain_Gain_n
                                          //  Referenced by: '<S12>/Gain'

  real32_T Constant3_Value_b;          // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S5>/Constant3'

  real32_T Gain3_Gain_f;               // Computed Parameter: Gain3_Gain_f
                                          //  Referenced by: '<S5>/Gain3'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S5>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S5>/Saturation3'

  real32_T Constant_Value_pb;          // Computed Parameter: Constant_Value_pb
                                          //  Referenced by: '<S5>/Constant'

  real32_T Constant1_Value_g3;         // Computed Parameter: Constant1_Value_g3
                                          //  Referenced by: '<S5>/Constant1'

  real32_T Constant2_Value_c;          // Computed Parameter: Constant2_Value_c
                                          //  Referenced by: '<S5>/Constant2'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                          //  Referenced by: '<S5>/Gain'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: '<S5>/Gain1'

  real32_T Gain2_Gain_k;               // Computed Parameter: Gain2_Gain_k
                                          //  Referenced by: '<S5>/Gain2'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S5>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S5>/Saturation'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S5>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S5>/Saturation1'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S5>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S5>/Saturation2'

  real32_T Saturation_UpperSat_o;   // Computed Parameter: Saturation_UpperSat_o
                                       //  Referenced by: '<S11>/Saturation'

  real32_T Saturation_LowerSat_k;   // Computed Parameter: Saturation_LowerSat_k
                                       //  Referenced by: '<S11>/Saturation'

  real32_T Polynomial_Coefs[3];        // Computed Parameter: Polynomial_Coefs
                                          //  Referenced by: '<S11>/Polynomial'

  real32_T Saturation1_UpperSat_o; // Computed Parameter: Saturation1_UpperSat_o
                                      //  Referenced by: '<S11>/Saturation1'

  real32_T Saturation1_LowerSat_o; // Computed Parameter: Saturation1_LowerSat_o
                                      //  Referenced by: '<S11>/Saturation1'

};

// Real-time Model Data Structure
struct tag_RTM_Ctrl_T {
  const char_T * volatile errorStatus;
};

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern real32_T AltKp;                 // Variable: AltKp
                                          //  Referenced by: '<S108>/Proportional Gain'

extern real32_T AltRateBias;           // Variable: AltRateBias
                                          //  Referenced by:
                                          //    '<S13>/Bias1'
                                          //    '<S1052>/Bias1'

extern real32_T AltRateKi;             // Variable: AltRateKi
                                          //  Referenced by:
                                          //    '<S52>/Integral Gain'
                                          //    '<S1089>/Integral Gain'

extern real32_T AltRateKp;             // Variable: AltRateKp
                                          //  Referenced by:
                                          //    '<S60>/Proportional Gain'
                                          //    '<S1097>/Proportional Gain'

extern real32_T PosKp;                 // Variable: PosKp
                                          //  Referenced by:
                                          //    '<S262>/Proportional Gain'
                                          //    '<S310>/Proportional Gain'

extern real32_T RollPitchKp;           // Variable: RollPitchKp
                                          //  Referenced by:
                                          //    '<S212>/Proportional Gain'
                                          //    '<S410>/Proportional Gain'
                                          //    '<S889>/Proportional Gain'
                                          //    '<S989>/Proportional Gain'
                                          //    '<S1201>/Proportional Gain'
                                          //    '<S1301>/Proportional Gain'

extern real32_T RollPitchMax;          // Variable: RollPitchMax
                                          //  Referenced by:
                                          //    '<S15>/Scale roll1'
                                          //    '<S17>/Scale roll2'
                                          //    '<S794>/Scale roll1'
                                          //    '<S795>/Scale roll2'
                                          //    '<S1054>/Scale roll1'
                                          //    '<S1055>/Scale roll2'

extern real32_T RollPitchRateKd;       // Variable: RollPitchRateKd
                                          //  Referenced by:
                                          //    '<S153>/Derivative Gain'
                                          //    '<S351>/Derivative Gain'
                                          //    '<S668>/Derivative Gain'
                                          //    '<S719>/Derivative Gain'
                                          //    '<S830>/Derivative Gain'
                                          //    '<S930>/Derivative Gain'
                                          //    '<S1142>/Derivative Gain'
                                          //    '<S1242>/Derivative Gain'

extern real32_T RollPitchRateKi;       // Variable: RollPitchRateKi
                                          //  Referenced by:
                                          //    '<S156>/Integral Gain'
                                          //    '<S354>/Integral Gain'
                                          //    '<S671>/Integral Gain'
                                          //    '<S722>/Integral Gain'
                                          //    '<S833>/Integral Gain'
                                          //    '<S933>/Integral Gain'
                                          //    '<S1145>/Integral Gain'
                                          //    '<S1245>/Integral Gain'

extern real32_T RollPitchRateKp;       // Variable: RollPitchRateKp
                                          //  Referenced by:
                                          //    '<S164>/Proportional Gain'
                                          //    '<S362>/Proportional Gain'
                                          //    '<S679>/Proportional Gain'
                                          //    '<S730>/Proportional Gain'
                                          //    '<S841>/Proportional Gain'
                                          //    '<S941>/Proportional Gain'
                                          //    '<S1153>/Proportional Gain'
                                          //    '<S1253>/Proportional Gain'

extern real32_T RollPitchRateMax;      // Variable: RollPitchRateMax
                                          //  Referenced by:
                                          //    '<S633>/Scale roll2'
                                          //    '<S634>/Scale roll2'
                                          //    '<S214>/Saturation'
                                          //    '<S412>/Saturation'
                                          //    '<S891>/Saturation'
                                          //    '<S991>/Saturation'
                                          //    '<S1203>/Saturation'
                                          //    '<S1303>/Saturation'

extern real32_T VelKi;                 // Variable: VelKi
                                          //  Referenced by:
                                          //    '<S455>/Integral Gain'
                                          //    '<S505>/Integral Gain'
                                          //    '<S1346>/Integral Gain'
                                          //    '<S1396>/Integral Gain'

extern real32_T VelKp;                 // Variable: VelKp
                                          //  Referenced by:
                                          //    '<S463>/Proportional Gain'
                                          //    '<S513>/Proportional Gain'
                                          //    '<S1354>/Proportional Gain'
                                          //    '<S1404>/Proportional Gain'

extern real32_T VelMax;                // Variable: VelMax
                                          //  Referenced by:
                                          //    '<S18>/Gain'
                                          //    '<S18>/Gain1'
                                          //    '<S1056>/Gain'
                                          //    '<S1056>/Gain1'

extern real32_T YawKp;                 // Variable: YawKp
                                          //  Referenced by:
                                          //    '<S615>/Proportional Gain'
                                          //    '<S1505>/Proportional Gain'

extern real32_T YawRateKi;             // Variable: YawRateKi
                                          //  Referenced by:
                                          //    '<S559>/Integral Gain'
                                          //    '<S773>/Integral Gain'
                                          //    '<S1032>/Integral Gain'
                                          //    '<S1449>/Integral Gain'

extern real32_T YawRateKp;             // Variable: YawRateKp
                                          //  Referenced by:
                                          //    '<S567>/Proportional Gain'
                                          //    '<S781>/Proportional Gain'
                                          //    '<S1040>/Proportional Gain'
                                          //    '<S1457>/Proportional Gain'

extern real32_T YawRateMax;            // Variable: YawRateMax
                                          //  Referenced by:
                                          //    '<S635>/Scale roll2'
                                          //    '<S796>/Scale roll2'
                                          //    '<S617>/Saturation'
                                          //    '<S1507>/Saturation'


// Class declaration for model Ctrl
class CtrlModelClass {
  // public data and function members
 public:
  // Tunable parameters
  static P_Ctrl_T Ctrl_P;

  // Block signals
  B_Ctrl_T Ctrl_B;

  // Block states
  DW_Ctrl_T Ctrl_DW;

  // External inputs
  ExtU_Ctrl_T Ctrl_U;

  // External outputs
  ExtY_Ctrl_T Ctrl_Y;

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

  // private member function(s) for subsystem '<S19>/Correct Yaw1'
  static void Ctrl_CorrectYaw1(real32_T rtu_u, B_CorrectYaw1_Ctrl_T *localB);

  // private member function(s) for subsystem '<Root>'
  void Ctrl_SelectMode(void);
  void Ctrl_CalculateTrajSegment(uint8_T index1, uint8_T index2, real32_T
    velocity);
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
//  '<S12>'  : 'ModelRiki/Ctrl/AltCalculator/GPSAltitude'
//  '<S13>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller'
//  '<S14>'  : 'ModelRiki/Ctrl/AutoCtrl/Mapper'
//  '<S15>'  : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller'
//  '<S16>'  : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl'
//  '<S17>'  : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller'
//  '<S18>'  : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl'
//  '<S19>'  : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller'
//  '<S20>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1'
//  '<S21>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2'
//  '<S22>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Anti-windup'
//  '<S23>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/D Gain'
//  '<S24>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Filter'
//  '<S25>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Filter ICs'
//  '<S26>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/I Gain'
//  '<S27>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S28>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S29>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Integrator'
//  '<S30>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Integrator ICs'
//  '<S31>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/N Copy'
//  '<S32>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/N Gain'
//  '<S33>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/P Copy'
//  '<S34>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S35>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Reset Signal'
//  '<S36>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Saturation'
//  '<S37>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S38>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Sum'
//  '<S39>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S40>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode'
//  '<S41>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S42>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S43>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S44>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/postSat Signal'
//  '<S45>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/preSat Signal'
//  '<S46>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S47>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S48>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S49>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S50>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S51>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S52>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S53>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S54>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S55>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Integrator/Discrete'
//  '<S56>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S57>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S58>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S59>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S60>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S61>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S62>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S63>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S64>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Sum/Sum_PI'
//  '<S65>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S66>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S67>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S68>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Integral/Passthrough'
//  '<S69>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S70>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S71>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S72>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Anti-windup'
//  '<S73>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/D Gain'
//  '<S74>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Filter'
//  '<S75>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Filter ICs'
//  '<S76>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/I Gain'
//  '<S77>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Ideal P Gain'
//  '<S78>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Ideal P Gain Fdbk'
//  '<S79>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Integrator'
//  '<S80>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Integrator ICs'
//  '<S81>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/N Copy'
//  '<S82>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/N Gain'
//  '<S83>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/P Copy'
//  '<S84>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Parallel P Gain'
//  '<S85>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Reset Signal'
//  '<S86>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Saturation'
//  '<S87>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Saturation Fdbk'
//  '<S88>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Sum'
//  '<S89>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Sum Fdbk'
//  '<S90>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tracking Mode'
//  '<S91>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tracking Mode Sum'
//  '<S92>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tsamp - Integral'
//  '<S93>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tsamp - Ngain'
//  '<S94>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/postSat Signal'
//  '<S95>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/preSat Signal'
//  '<S96>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Anti-windup/Disabled'
//  '<S97>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/D Gain/Disabled'
//  '<S98>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Filter/Disabled'
//  '<S99>'  : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Filter ICs/Disabled'
//  '<S100>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/I Gain/Disabled'
//  '<S101>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Ideal P Gain/Passthrough'
//  '<S102>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S103>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Integrator/Disabled'
//  '<S104>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Integrator ICs/Disabled'
//  '<S105>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S106>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/N Gain/Disabled'
//  '<S107>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/P Copy/Disabled'
//  '<S108>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S109>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Reset Signal/Disabled'
//  '<S110>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Saturation/Enabled'
//  '<S111>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Saturation Fdbk/Disabled'
//  '<S112>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Sum/Passthrough_P'
//  '<S113>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Sum Fdbk/Disabled'
//  '<S114>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tracking Mode/Disabled'
//  '<S115>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S116>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tsamp - Integral/Disabled wSignal Specification'
//  '<S117>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S118>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/postSat Signal/Forward_Path'
//  '<S119>' : 'ModelRiki/Ctrl/AutoCtrl/Alt Controller/Discrete PID Controller2/preSat Signal/Forward_Path'
//  '<S120>' : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale'
//  '<S121>' : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale1'
//  '<S122>' : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale2'
//  '<S123>' : 'ModelRiki/Ctrl/AutoCtrl/Mapper/LimitAndRescale3'
//  '<S124>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller'
//  '<S125>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1'
//  '<S126>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Anti-windup'
//  '<S127>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/D Gain'
//  '<S128>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Filter'
//  '<S129>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Filter ICs'
//  '<S130>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/I Gain'
//  '<S131>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain'
//  '<S132>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S133>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Integrator'
//  '<S134>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs'
//  '<S135>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/N Copy'
//  '<S136>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/N Gain'
//  '<S137>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/P Copy'
//  '<S138>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain'
//  '<S139>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Reset Signal'
//  '<S140>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Saturation'
//  '<S141>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S142>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Sum'
//  '<S143>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk'
//  '<S144>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode'
//  '<S145>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S146>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S147>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S148>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/postSat Signal'
//  '<S149>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/preSat Signal'
//  '<S150>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S151>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S152>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S153>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S154>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S155>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S156>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S157>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S158>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S159>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S160>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S161>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S162>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S163>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S164>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S165>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S166>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S167>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S168>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S169>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S170>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S171>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S172>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S173>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S174>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S175>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S176>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Anti-windup'
//  '<S177>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/D Gain'
//  '<S178>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Filter'
//  '<S179>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Filter ICs'
//  '<S180>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/I Gain'
//  '<S181>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S182>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S183>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Integrator'
//  '<S184>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Integrator ICs'
//  '<S185>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/N Copy'
//  '<S186>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/N Gain'
//  '<S187>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/P Copy'
//  '<S188>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S189>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Reset Signal'
//  '<S190>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Saturation'
//  '<S191>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S192>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Sum'
//  '<S193>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S194>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode'
//  '<S195>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S196>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S197>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S198>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/postSat Signal'
//  '<S199>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/preSat Signal'
//  '<S200>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S201>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S202>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S203>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S204>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/I Gain/Disabled'
//  '<S205>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S206>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S207>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Integrator/Disabled'
//  '<S208>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S209>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S210>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S211>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S212>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S213>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S214>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S215>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S216>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Sum/Passthrough_P'
//  '<S217>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S218>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S219>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S220>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
//  '<S221>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S222>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S223>' : 'ModelRiki/Ctrl/AutoCtrl/Pitch Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S224>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1'
//  '<S225>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2'
//  '<S226>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Anti-windup'
//  '<S227>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/D Gain'
//  '<S228>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Filter'
//  '<S229>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Filter ICs'
//  '<S230>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/I Gain'
//  '<S231>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Ideal P Gain'
//  '<S232>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S233>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Integrator'
//  '<S234>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Integrator ICs'
//  '<S235>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/N Copy'
//  '<S236>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/N Gain'
//  '<S237>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/P Copy'
//  '<S238>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Parallel P Gain'
//  '<S239>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Reset Signal'
//  '<S240>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Saturation'
//  '<S241>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Saturation Fdbk'
//  '<S242>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Sum'
//  '<S243>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Sum Fdbk'
//  '<S244>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tracking Mode'
//  '<S245>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tracking Mode Sum'
//  '<S246>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tsamp - Integral'
//  '<S247>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tsamp - Ngain'
//  '<S248>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/postSat Signal'
//  '<S249>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/preSat Signal'
//  '<S250>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S251>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/D Gain/Disabled'
//  '<S252>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Filter/Disabled'
//  '<S253>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S254>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/I Gain/Disabled'
//  '<S255>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S256>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S257>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Integrator/Disabled'
//  '<S258>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S259>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S260>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/N Gain/Disabled'
//  '<S261>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/P Copy/Disabled'
//  '<S262>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S263>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S264>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Saturation/Enabled'
//  '<S265>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S266>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Sum/Passthrough_P'
//  '<S267>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S268>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S269>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S270>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
//  '<S271>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S272>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S273>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S274>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Anti-windup'
//  '<S275>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/D Gain'
//  '<S276>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Filter'
//  '<S277>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Filter ICs'
//  '<S278>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/I Gain'
//  '<S279>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Ideal P Gain'
//  '<S280>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Ideal P Gain Fdbk'
//  '<S281>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Integrator'
//  '<S282>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Integrator ICs'
//  '<S283>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/N Copy'
//  '<S284>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/N Gain'
//  '<S285>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/P Copy'
//  '<S286>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Parallel P Gain'
//  '<S287>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Reset Signal'
//  '<S288>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Saturation'
//  '<S289>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Saturation Fdbk'
//  '<S290>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Sum'
//  '<S291>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Sum Fdbk'
//  '<S292>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tracking Mode'
//  '<S293>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tracking Mode Sum'
//  '<S294>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tsamp - Integral'
//  '<S295>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tsamp - Ngain'
//  '<S296>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/postSat Signal'
//  '<S297>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/preSat Signal'
//  '<S298>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Anti-windup/Disabled'
//  '<S299>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/D Gain/Disabled'
//  '<S300>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Filter/Disabled'
//  '<S301>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Filter ICs/Disabled'
//  '<S302>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/I Gain/Disabled'
//  '<S303>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Ideal P Gain/Passthrough'
//  '<S304>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S305>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Integrator/Disabled'
//  '<S306>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Integrator ICs/Disabled'
//  '<S307>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S308>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/N Gain/Disabled'
//  '<S309>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/P Copy/Disabled'
//  '<S310>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S311>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Reset Signal/Disabled'
//  '<S312>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Saturation/Enabled'
//  '<S313>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Saturation Fdbk/Disabled'
//  '<S314>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Sum/Passthrough_P'
//  '<S315>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Sum Fdbk/Disabled'
//  '<S316>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tracking Mode/Disabled'
//  '<S317>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S318>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tsamp - Integral/Disabled wSignal Specification'
//  '<S319>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S320>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/postSat Signal/Forward_Path'
//  '<S321>' : 'ModelRiki/Ctrl/AutoCtrl/Position Ctrl/Discrete PID Controller2/preSat Signal/Forward_Path'
//  '<S322>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller'
//  '<S323>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1'
//  '<S324>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Anti-windup'
//  '<S325>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/D Gain'
//  '<S326>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Filter'
//  '<S327>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Filter ICs'
//  '<S328>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/I Gain'
//  '<S329>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain'
//  '<S330>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S331>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Integrator'
//  '<S332>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Integrator ICs'
//  '<S333>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/N Copy'
//  '<S334>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/N Gain'
//  '<S335>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/P Copy'
//  '<S336>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain'
//  '<S337>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Reset Signal'
//  '<S338>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Saturation'
//  '<S339>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S340>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Sum'
//  '<S341>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk'
//  '<S342>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tracking Mode'
//  '<S343>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S344>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S345>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S346>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/postSat Signal'
//  '<S347>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/preSat Signal'
//  '<S348>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S349>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S350>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S351>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S352>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S353>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S354>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S355>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S356>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S357>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S358>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S359>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S360>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S361>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S362>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S363>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S364>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S365>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S366>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S367>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S368>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S369>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S370>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S371>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S372>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S373>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S374>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Anti-windup'
//  '<S375>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/D Gain'
//  '<S376>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Filter'
//  '<S377>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Filter ICs'
//  '<S378>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/I Gain'
//  '<S379>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S380>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S381>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Integrator'
//  '<S382>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Integrator ICs'
//  '<S383>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/N Copy'
//  '<S384>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/N Gain'
//  '<S385>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/P Copy'
//  '<S386>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S387>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Reset Signal'
//  '<S388>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Saturation'
//  '<S389>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S390>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Sum'
//  '<S391>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S392>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode'
//  '<S393>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S394>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S395>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S396>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/postSat Signal'
//  '<S397>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/preSat Signal'
//  '<S398>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S399>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S400>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S401>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S402>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/I Gain/Disabled'
//  '<S403>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S404>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S405>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Integrator/Disabled'
//  '<S406>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S407>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S408>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S409>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S410>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S411>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S412>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S413>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S414>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Sum/Passthrough_P'
//  '<S415>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S416>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S417>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S418>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
//  '<S419>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S420>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S421>' : 'ModelRiki/Ctrl/AutoCtrl/Roll Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S422>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Degrees to Radians'
//  '<S423>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1'
//  '<S424>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2'
//  '<S425>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Anti-windup'
//  '<S426>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/D Gain'
//  '<S427>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Filter'
//  '<S428>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Filter ICs'
//  '<S429>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/I Gain'
//  '<S430>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Ideal P Gain'
//  '<S431>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S432>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Integrator'
//  '<S433>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Integrator ICs'
//  '<S434>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/N Copy'
//  '<S435>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/N Gain'
//  '<S436>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/P Copy'
//  '<S437>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Parallel P Gain'
//  '<S438>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Reset Signal'
//  '<S439>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Saturation'
//  '<S440>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Saturation Fdbk'
//  '<S441>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Sum'
//  '<S442>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Sum Fdbk'
//  '<S443>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tracking Mode'
//  '<S444>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tracking Mode Sum'
//  '<S445>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tsamp - Integral'
//  '<S446>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tsamp - Ngain'
//  '<S447>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/postSat Signal'
//  '<S448>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/preSat Signal'
//  '<S449>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S450>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S451>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S452>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/D Gain/Disabled'
//  '<S453>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Filter/Disabled'
//  '<S454>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S455>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S456>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S457>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S458>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Integrator/Discrete'
//  '<S459>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S460>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S461>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/N Gain/Disabled'
//  '<S462>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/P Copy/Disabled'
//  '<S463>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S464>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S465>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Saturation/Enabled'
//  '<S466>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S467>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Sum/Sum_PI'
//  '<S468>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S469>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S470>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S471>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tsamp - Integral/Passthrough'
//  '<S472>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S473>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S474>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S475>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Anti-windup'
//  '<S476>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/D Gain'
//  '<S477>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Filter'
//  '<S478>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Filter ICs'
//  '<S479>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/I Gain'
//  '<S480>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Ideal P Gain'
//  '<S481>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Ideal P Gain Fdbk'
//  '<S482>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Integrator'
//  '<S483>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Integrator ICs'
//  '<S484>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/N Copy'
//  '<S485>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/N Gain'
//  '<S486>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/P Copy'
//  '<S487>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Parallel P Gain'
//  '<S488>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Reset Signal'
//  '<S489>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Saturation'
//  '<S490>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Saturation Fdbk'
//  '<S491>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Sum'
//  '<S492>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Sum Fdbk'
//  '<S493>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tracking Mode'
//  '<S494>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tracking Mode Sum'
//  '<S495>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tsamp - Integral'
//  '<S496>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tsamp - Ngain'
//  '<S497>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/postSat Signal'
//  '<S498>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/preSat Signal'
//  '<S499>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S500>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S501>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S502>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/D Gain/Disabled'
//  '<S503>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Filter/Disabled'
//  '<S504>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Filter ICs/Disabled'
//  '<S505>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/I Gain/Internal Parameters'
//  '<S506>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Ideal P Gain/Passthrough'
//  '<S507>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S508>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Integrator/Discrete'
//  '<S509>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Integrator ICs/Internal IC'
//  '<S510>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S511>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/N Gain/Disabled'
//  '<S512>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/P Copy/Disabled'
//  '<S513>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S514>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Reset Signal/Disabled'
//  '<S515>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Saturation/Enabled'
//  '<S516>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Saturation Fdbk/Disabled'
//  '<S517>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Sum/Sum_PI'
//  '<S518>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Sum Fdbk/Disabled'
//  '<S519>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tracking Mode/Disabled'
//  '<S520>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S521>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tsamp - Integral/Passthrough'
//  '<S522>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S523>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/postSat Signal/Forward_Path'
//  '<S524>' : 'ModelRiki/Ctrl/AutoCtrl/Velocity Ctrl/Discrete PID Controller2/preSat Signal/Forward_Path'
//  '<S525>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Correct Yaw1'
//  '<S526>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller'
//  '<S527>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3'
//  '<S528>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Radians to Degrees'
//  '<S529>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Anti-windup'
//  '<S530>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/D Gain'
//  '<S531>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Filter'
//  '<S532>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Filter ICs'
//  '<S533>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/I Gain'
//  '<S534>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain'
//  '<S535>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S536>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Integrator'
//  '<S537>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs'
//  '<S538>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/N Copy'
//  '<S539>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/N Gain'
//  '<S540>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/P Copy'
//  '<S541>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain'
//  '<S542>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Reset Signal'
//  '<S543>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Saturation'
//  '<S544>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S545>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Sum'
//  '<S546>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk'
//  '<S547>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode'
//  '<S548>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S549>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S550>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S551>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/postSat Signal'
//  '<S552>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/preSat Signal'
//  '<S553>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S554>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S555>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S556>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/D Gain/Disabled'
//  '<S557>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Filter/Disabled'
//  '<S558>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Filter ICs/Disabled'
//  '<S559>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S560>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S561>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S562>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S563>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S564>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S565>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/N Gain/Disabled'
//  '<S566>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S567>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S568>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S569>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S570>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S571>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Sum/Sum_PI'
//  '<S572>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S573>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S574>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S575>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S576>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S577>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S578>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S579>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Anti-windup'
//  '<S580>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/D Gain'
//  '<S581>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Filter'
//  '<S582>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Filter ICs'
//  '<S583>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/I Gain'
//  '<S584>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain'
//  '<S585>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain Fdbk'
//  '<S586>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Integrator'
//  '<S587>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Integrator ICs'
//  '<S588>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/N Copy'
//  '<S589>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/N Gain'
//  '<S590>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/P Copy'
//  '<S591>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Parallel P Gain'
//  '<S592>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Reset Signal'
//  '<S593>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Saturation'
//  '<S594>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Saturation Fdbk'
//  '<S595>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Sum'
//  '<S596>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Sum Fdbk'
//  '<S597>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode'
//  '<S598>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode Sum'
//  '<S599>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Integral'
//  '<S600>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Ngain'
//  '<S601>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/postSat Signal'
//  '<S602>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/preSat Signal'
//  '<S603>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Anti-windup/Disabled'
//  '<S604>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/D Gain/Disabled'
//  '<S605>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Filter/Disabled'
//  '<S606>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Filter ICs/Disabled'
//  '<S607>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/I Gain/Disabled'
//  '<S608>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain/Passthrough'
//  '<S609>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S610>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Integrator/Disabled'
//  '<S611>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Integrator ICs/Disabled'
//  '<S612>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S613>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/N Gain/Disabled'
//  '<S614>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/P Copy/Disabled'
//  '<S615>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S616>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Reset Signal/Disabled'
//  '<S617>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Saturation/Enabled'
//  '<S618>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Saturation Fdbk/Disabled'
//  '<S619>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Sum/Passthrough_P'
//  '<S620>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Sum Fdbk/Disabled'
//  '<S621>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode/Disabled'
//  '<S622>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S623>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Integral/Disabled wSignal Specification'
//  '<S624>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S625>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/postSat Signal/Forward_Path'
//  '<S626>' : 'ModelRiki/Ctrl/AutoCtrl/Yaw Controller/Discrete PID Controller3/preSat Signal/Forward_Path'
//  '<S627>' : 'ModelRiki/Ctrl/ManualCtrl/Mapper'
//  '<S628>' : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale'
//  '<S629>' : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale1'
//  '<S630>' : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale2'
//  '<S631>' : 'ModelRiki/Ctrl/ManualCtrl/Mapper/LimitAndRescale3'
//  '<S632>' : 'ModelRiki/Ctrl/RateCtrl/Mapper'
//  '<S633>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller'
//  '<S634>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller'
//  '<S635>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller'
//  '<S636>' : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale'
//  '<S637>' : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale1'
//  '<S638>' : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale2'
//  '<S639>' : 'ModelRiki/Ctrl/RateCtrl/Mapper/LimitAndRescale3'
//  '<S640>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller'
//  '<S641>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Anti-windup'
//  '<S642>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/D Gain'
//  '<S643>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Filter'
//  '<S644>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Filter ICs'
//  '<S645>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/I Gain'
//  '<S646>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain'
//  '<S647>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S648>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Integrator'
//  '<S649>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs'
//  '<S650>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/N Copy'
//  '<S651>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/N Gain'
//  '<S652>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/P Copy'
//  '<S653>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain'
//  '<S654>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Reset Signal'
//  '<S655>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Saturation'
//  '<S656>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S657>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Sum'
//  '<S658>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk'
//  '<S659>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode'
//  '<S660>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S661>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S662>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S663>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/postSat Signal'
//  '<S664>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/preSat Signal'
//  '<S665>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S666>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S667>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S668>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S669>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S670>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S671>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S672>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S673>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S674>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S675>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S676>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S677>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S678>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S679>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S680>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S681>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S682>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S683>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S684>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S685>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S686>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S687>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S688>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S689>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S690>' : 'ModelRiki/Ctrl/RateCtrl/Pitch Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S691>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller'
//  '<S692>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Anti-windup'
//  '<S693>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/D Gain'
//  '<S694>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Filter'
//  '<S695>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Filter ICs'
//  '<S696>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/I Gain'
//  '<S697>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain'
//  '<S698>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S699>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Integrator'
//  '<S700>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Integrator ICs'
//  '<S701>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/N Copy'
//  '<S702>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/N Gain'
//  '<S703>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/P Copy'
//  '<S704>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain'
//  '<S705>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Reset Signal'
//  '<S706>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Saturation'
//  '<S707>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S708>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Sum'
//  '<S709>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk'
//  '<S710>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tracking Mode'
//  '<S711>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S712>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S713>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S714>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/postSat Signal'
//  '<S715>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/preSat Signal'
//  '<S716>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S717>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S718>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S719>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S720>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S721>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S722>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S723>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S724>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S725>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S726>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S727>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S728>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S729>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S730>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S731>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S732>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S733>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S734>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S735>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S736>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S737>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S738>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S739>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S740>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S741>' : 'ModelRiki/Ctrl/RateCtrl/Roll Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S742>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller'
//  '<S743>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Anti-windup'
//  '<S744>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/D Gain'
//  '<S745>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Filter'
//  '<S746>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Filter ICs'
//  '<S747>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/I Gain'
//  '<S748>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain'
//  '<S749>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S750>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Integrator'
//  '<S751>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs'
//  '<S752>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/N Copy'
//  '<S753>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/N Gain'
//  '<S754>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/P Copy'
//  '<S755>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain'
//  '<S756>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Reset Signal'
//  '<S757>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Saturation'
//  '<S758>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S759>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Sum'
//  '<S760>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk'
//  '<S761>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode'
//  '<S762>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S763>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S764>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S765>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/postSat Signal'
//  '<S766>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/preSat Signal'
//  '<S767>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S768>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S769>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S770>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/D Gain/Disabled'
//  '<S771>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Filter/Disabled'
//  '<S772>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Filter ICs/Disabled'
//  '<S773>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S774>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S775>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S776>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S777>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S778>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S779>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/N Gain/Disabled'
//  '<S780>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S781>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S782>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S783>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S784>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S785>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Sum/Sum_PI'
//  '<S786>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S787>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S788>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S789>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S790>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S791>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S792>' : 'ModelRiki/Ctrl/RateCtrl/Yaw Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S793>' : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper'
//  '<S794>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller'
//  '<S795>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller'
//  '<S796>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller'
//  '<S797>' : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale'
//  '<S798>' : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale1'
//  '<S799>' : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale2'
//  '<S800>' : 'ModelRiki/Ctrl/RollPitchCtrl/Mapper/LimitAndRescale3'
//  '<S801>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller'
//  '<S802>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1'
//  '<S803>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Anti-windup'
//  '<S804>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/D Gain'
//  '<S805>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Filter'
//  '<S806>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Filter ICs'
//  '<S807>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/I Gain'
//  '<S808>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain'
//  '<S809>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S810>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Integrator'
//  '<S811>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs'
//  '<S812>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/N Copy'
//  '<S813>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/N Gain'
//  '<S814>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/P Copy'
//  '<S815>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain'
//  '<S816>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Reset Signal'
//  '<S817>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Saturation'
//  '<S818>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S819>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Sum'
//  '<S820>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk'
//  '<S821>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode'
//  '<S822>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S823>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S824>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S825>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/postSat Signal'
//  '<S826>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/preSat Signal'
//  '<S827>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S828>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S829>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S830>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S831>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S832>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S833>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S834>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S835>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S836>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S837>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S838>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S839>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S840>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S841>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S842>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S843>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S844>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S845>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S846>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S847>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S848>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S849>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S850>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S851>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S852>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S853>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Anti-windup'
//  '<S854>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/D Gain'
//  '<S855>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Filter'
//  '<S856>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Filter ICs'
//  '<S857>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/I Gain'
//  '<S858>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S859>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S860>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Integrator'
//  '<S861>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Integrator ICs'
//  '<S862>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/N Copy'
//  '<S863>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/N Gain'
//  '<S864>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/P Copy'
//  '<S865>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S866>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Reset Signal'
//  '<S867>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Saturation'
//  '<S868>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S869>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Sum'
//  '<S870>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S871>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode'
//  '<S872>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S873>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S874>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S875>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/postSat Signal'
//  '<S876>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/preSat Signal'
//  '<S877>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S878>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S879>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S880>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S881>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/I Gain/Disabled'
//  '<S882>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S883>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S884>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Integrator/Disabled'
//  '<S885>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S886>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S887>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S888>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S889>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S890>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S891>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S892>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S893>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Sum/Passthrough_P'
//  '<S894>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S895>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S896>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S897>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
//  '<S898>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S899>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S900>' : 'ModelRiki/Ctrl/RollPitchCtrl/Pitch Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S901>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller'
//  '<S902>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1'
//  '<S903>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Anti-windup'
//  '<S904>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/D Gain'
//  '<S905>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Filter'
//  '<S906>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Filter ICs'
//  '<S907>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/I Gain'
//  '<S908>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain'
//  '<S909>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S910>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Integrator'
//  '<S911>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Integrator ICs'
//  '<S912>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/N Copy'
//  '<S913>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/N Gain'
//  '<S914>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/P Copy'
//  '<S915>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain'
//  '<S916>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Reset Signal'
//  '<S917>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Saturation'
//  '<S918>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S919>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Sum'
//  '<S920>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk'
//  '<S921>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tracking Mode'
//  '<S922>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S923>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S924>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S925>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/postSat Signal'
//  '<S926>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/preSat Signal'
//  '<S927>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S928>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S929>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S930>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S931>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S932>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S933>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S934>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S935>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S936>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S937>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S938>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S939>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S940>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S941>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S942>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S943>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S944>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S945>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S946>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S947>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S948>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S949>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S950>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S951>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S952>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S953>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Anti-windup'
//  '<S954>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/D Gain'
//  '<S955>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Filter'
//  '<S956>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Filter ICs'
//  '<S957>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/I Gain'
//  '<S958>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S959>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S960>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Integrator'
//  '<S961>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Integrator ICs'
//  '<S962>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/N Copy'
//  '<S963>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/N Gain'
//  '<S964>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/P Copy'
//  '<S965>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S966>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Reset Signal'
//  '<S967>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Saturation'
//  '<S968>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S969>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Sum'
//  '<S970>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S971>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode'
//  '<S972>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S973>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S974>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S975>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/postSat Signal'
//  '<S976>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/preSat Signal'
//  '<S977>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S978>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S979>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S980>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S981>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/I Gain/Disabled'
//  '<S982>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S983>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S984>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Integrator/Disabled'
//  '<S985>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S986>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S987>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S988>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S989>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S990>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S991>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S992>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S993>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Sum/Passthrough_P'
//  '<S994>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S995>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S996>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S997>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
//  '<S998>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S999>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S1000>' : 'ModelRiki/Ctrl/RollPitchCtrl/Roll Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S1001>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller'
//  '<S1002>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Anti-windup'
//  '<S1003>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/D Gain'
//  '<S1004>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Filter'
//  '<S1005>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Filter ICs'
//  '<S1006>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/I Gain'
//  '<S1007>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain'
//  '<S1008>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S1009>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Integrator'
//  '<S1010>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs'
//  '<S1011>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/N Copy'
//  '<S1012>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/N Gain'
//  '<S1013>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/P Copy'
//  '<S1014>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain'
//  '<S1015>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Reset Signal'
//  '<S1016>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Saturation'
//  '<S1017>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S1018>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Sum'
//  '<S1019>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk'
//  '<S1020>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode'
//  '<S1021>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S1022>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S1023>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S1024>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/postSat Signal'
//  '<S1025>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/preSat Signal'
//  '<S1026>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S1027>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S1028>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S1029>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/D Gain/Disabled'
//  '<S1030>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Filter/Disabled'
//  '<S1031>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Filter ICs/Disabled'
//  '<S1032>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S1033>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S1034>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S1035>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S1036>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S1037>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S1038>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/N Gain/Disabled'
//  '<S1039>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S1040>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S1041>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S1042>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S1043>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S1044>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Sum/Sum_PI'
//  '<S1045>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S1046>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S1047>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S1048>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S1049>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S1050>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S1051>' : 'ModelRiki/Ctrl/RollPitchCtrl/Yaw Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S1052>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller'
//  '<S1053>' : 'ModelRiki/Ctrl/VelocityCtrl/Mapper'
//  '<S1054>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller'
//  '<S1055>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller'
//  '<S1056>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1'
//  '<S1057>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller'
//  '<S1058>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1'
//  '<S1059>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Anti-windup'
//  '<S1060>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/D Gain'
//  '<S1061>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Filter'
//  '<S1062>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Filter ICs'
//  '<S1063>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/I Gain'
//  '<S1064>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S1065>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S1066>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Integrator'
//  '<S1067>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Integrator ICs'
//  '<S1068>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/N Copy'
//  '<S1069>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/N Gain'
//  '<S1070>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/P Copy'
//  '<S1071>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S1072>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Reset Signal'
//  '<S1073>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Saturation'
//  '<S1074>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S1075>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Sum'
//  '<S1076>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S1077>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode'
//  '<S1078>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S1079>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S1080>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S1081>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/postSat Signal'
//  '<S1082>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/preSat Signal'
//  '<S1083>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S1084>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S1085>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S1086>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S1087>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S1088>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S1089>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S1090>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S1091>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S1092>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Integrator/Discrete'
//  '<S1093>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S1094>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S1095>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S1096>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S1097>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S1098>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S1099>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S1100>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S1101>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Sum/Sum_PI'
//  '<S1102>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S1103>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S1104>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S1105>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Integral/Passthrough'
//  '<S1106>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S1107>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S1108>' : 'ModelRiki/Ctrl/VelocityCtrl/Alt Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S1109>' : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale'
//  '<S1110>' : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale1'
//  '<S1111>' : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale2'
//  '<S1112>' : 'ModelRiki/Ctrl/VelocityCtrl/Mapper/LimitAndRescale3'
//  '<S1113>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller'
//  '<S1114>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1'
//  '<S1115>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Anti-windup'
//  '<S1116>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/D Gain'
//  '<S1117>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Filter'
//  '<S1118>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Filter ICs'
//  '<S1119>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/I Gain'
//  '<S1120>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain'
//  '<S1121>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S1122>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Integrator'
//  '<S1123>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs'
//  '<S1124>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/N Copy'
//  '<S1125>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/N Gain'
//  '<S1126>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/P Copy'
//  '<S1127>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain'
//  '<S1128>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Reset Signal'
//  '<S1129>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Saturation'
//  '<S1130>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S1131>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Sum'
//  '<S1132>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk'
//  '<S1133>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode'
//  '<S1134>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S1135>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S1136>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S1137>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/postSat Signal'
//  '<S1138>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/preSat Signal'
//  '<S1139>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S1140>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S1141>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S1142>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S1143>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S1144>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S1145>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S1146>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S1147>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S1148>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S1149>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S1150>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S1151>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S1152>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S1153>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S1154>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S1155>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S1156>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S1157>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S1158>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S1159>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S1160>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S1161>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S1162>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S1163>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S1164>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S1165>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Anti-windup'
//  '<S1166>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/D Gain'
//  '<S1167>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Filter'
//  '<S1168>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Filter ICs'
//  '<S1169>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/I Gain'
//  '<S1170>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S1171>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S1172>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Integrator'
//  '<S1173>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Integrator ICs'
//  '<S1174>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/N Copy'
//  '<S1175>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/N Gain'
//  '<S1176>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/P Copy'
//  '<S1177>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S1178>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Reset Signal'
//  '<S1179>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Saturation'
//  '<S1180>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S1181>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Sum'
//  '<S1182>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S1183>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode'
//  '<S1184>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S1185>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S1186>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S1187>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/postSat Signal'
//  '<S1188>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/preSat Signal'
//  '<S1189>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S1190>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S1191>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S1192>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S1193>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/I Gain/Disabled'
//  '<S1194>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S1195>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S1196>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Integrator/Disabled'
//  '<S1197>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S1198>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S1199>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S1200>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S1201>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S1202>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S1203>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S1204>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S1205>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Sum/Passthrough_P'
//  '<S1206>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S1207>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S1208>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S1209>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
//  '<S1210>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S1211>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S1212>' : 'ModelRiki/Ctrl/VelocityCtrl/Pitch Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S1213>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller'
//  '<S1214>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1'
//  '<S1215>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Anti-windup'
//  '<S1216>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/D Gain'
//  '<S1217>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Filter'
//  '<S1218>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Filter ICs'
//  '<S1219>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/I Gain'
//  '<S1220>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain'
//  '<S1221>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S1222>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Integrator'
//  '<S1223>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Integrator ICs'
//  '<S1224>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/N Copy'
//  '<S1225>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/N Gain'
//  '<S1226>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/P Copy'
//  '<S1227>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain'
//  '<S1228>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Reset Signal'
//  '<S1229>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Saturation'
//  '<S1230>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S1231>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Sum'
//  '<S1232>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk'
//  '<S1233>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tracking Mode'
//  '<S1234>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S1235>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S1236>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S1237>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/postSat Signal'
//  '<S1238>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/preSat Signal'
//  '<S1239>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S1240>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S1241>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S1242>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S1243>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S1244>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S1245>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S1246>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S1247>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S1248>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S1249>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S1250>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/N Copy/Disabled'
//  '<S1251>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S1252>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S1253>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S1254>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S1255>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S1256>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S1257>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S1258>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S1259>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S1260>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S1261>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S1262>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S1263>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S1264>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S1265>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Anti-windup'
//  '<S1266>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/D Gain'
//  '<S1267>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Filter'
//  '<S1268>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Filter ICs'
//  '<S1269>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/I Gain'
//  '<S1270>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S1271>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S1272>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Integrator'
//  '<S1273>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Integrator ICs'
//  '<S1274>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/N Copy'
//  '<S1275>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/N Gain'
//  '<S1276>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/P Copy'
//  '<S1277>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S1278>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Reset Signal'
//  '<S1279>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Saturation'
//  '<S1280>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S1281>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Sum'
//  '<S1282>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S1283>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode'
//  '<S1284>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S1285>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S1286>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S1287>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/postSat Signal'
//  '<S1288>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/preSat Signal'
//  '<S1289>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S1290>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/D Gain/Disabled'
//  '<S1291>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Filter/Disabled'
//  '<S1292>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S1293>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/I Gain/Disabled'
//  '<S1294>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S1295>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S1296>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Integrator/Disabled'
//  '<S1297>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S1298>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S1299>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/N Gain/Disabled'
//  '<S1300>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S1301>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S1302>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S1303>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Saturation/Enabled'
//  '<S1304>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S1305>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Sum/Passthrough_P'
//  '<S1306>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S1307>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S1308>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S1309>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
//  '<S1310>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S1311>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S1312>' : 'ModelRiki/Ctrl/VelocityCtrl/Roll Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S1313>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Degrees to Radians'
//  '<S1314>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1'
//  '<S1315>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2'
//  '<S1316>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Anti-windup'
//  '<S1317>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/D Gain'
//  '<S1318>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Filter'
//  '<S1319>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Filter ICs'
//  '<S1320>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/I Gain'
//  '<S1321>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Ideal P Gain'
//  '<S1322>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S1323>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Integrator'
//  '<S1324>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Integrator ICs'
//  '<S1325>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/N Copy'
//  '<S1326>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/N Gain'
//  '<S1327>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/P Copy'
//  '<S1328>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Parallel P Gain'
//  '<S1329>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Reset Signal'
//  '<S1330>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Saturation'
//  '<S1331>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Saturation Fdbk'
//  '<S1332>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Sum'
//  '<S1333>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Sum Fdbk'
//  '<S1334>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tracking Mode'
//  '<S1335>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tracking Mode Sum'
//  '<S1336>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tsamp - Integral'
//  '<S1337>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tsamp - Ngain'
//  '<S1338>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/postSat Signal'
//  '<S1339>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/preSat Signal'
//  '<S1340>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S1341>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S1342>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S1343>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/D Gain/Disabled'
//  '<S1344>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Filter/Disabled'
//  '<S1345>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Filter ICs/Disabled'
//  '<S1346>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S1347>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S1348>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S1349>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Integrator/Discrete'
//  '<S1350>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S1351>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S1352>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/N Gain/Disabled'
//  '<S1353>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/P Copy/Disabled'
//  '<S1354>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S1355>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S1356>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Saturation/Enabled'
//  '<S1357>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S1358>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Sum/Sum_PI'
//  '<S1359>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S1360>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S1361>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S1362>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tsamp - Integral/Passthrough'
//  '<S1363>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S1364>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S1365>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S1366>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Anti-windup'
//  '<S1367>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/D Gain'
//  '<S1368>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Filter'
//  '<S1369>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Filter ICs'
//  '<S1370>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/I Gain'
//  '<S1371>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Ideal P Gain'
//  '<S1372>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Ideal P Gain Fdbk'
//  '<S1373>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Integrator'
//  '<S1374>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Integrator ICs'
//  '<S1375>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/N Copy'
//  '<S1376>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/N Gain'
//  '<S1377>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/P Copy'
//  '<S1378>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Parallel P Gain'
//  '<S1379>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Reset Signal'
//  '<S1380>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Saturation'
//  '<S1381>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Saturation Fdbk'
//  '<S1382>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Sum'
//  '<S1383>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Sum Fdbk'
//  '<S1384>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tracking Mode'
//  '<S1385>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tracking Mode Sum'
//  '<S1386>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tsamp - Integral'
//  '<S1387>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tsamp - Ngain'
//  '<S1388>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/postSat Signal'
//  '<S1389>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/preSat Signal'
//  '<S1390>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S1391>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S1392>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S1393>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/D Gain/Disabled'
//  '<S1394>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Filter/Disabled'
//  '<S1395>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Filter ICs/Disabled'
//  '<S1396>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/I Gain/Internal Parameters'
//  '<S1397>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Ideal P Gain/Passthrough'
//  '<S1398>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S1399>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Integrator/Discrete'
//  '<S1400>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Integrator ICs/Internal IC'
//  '<S1401>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S1402>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/N Gain/Disabled'
//  '<S1403>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/P Copy/Disabled'
//  '<S1404>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S1405>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Reset Signal/Disabled'
//  '<S1406>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Saturation/Enabled'
//  '<S1407>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Saturation Fdbk/Disabled'
//  '<S1408>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Sum/Sum_PI'
//  '<S1409>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Sum Fdbk/Disabled'
//  '<S1410>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tracking Mode/Disabled'
//  '<S1411>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S1412>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tsamp - Integral/Passthrough'
//  '<S1413>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S1414>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/postSat Signal/Forward_Path'
//  '<S1415>' : 'ModelRiki/Ctrl/VelocityCtrl/Velocity Ctrl1/Discrete PID Controller2/preSat Signal/Forward_Path'
//  '<S1416>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Correct Yaw1'
//  '<S1417>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller'
//  '<S1418>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3'
//  '<S1419>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Anti-windup'
//  '<S1420>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/D Gain'
//  '<S1421>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Filter'
//  '<S1422>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Filter ICs'
//  '<S1423>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/I Gain'
//  '<S1424>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain'
//  '<S1425>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S1426>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Integrator'
//  '<S1427>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs'
//  '<S1428>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/N Copy'
//  '<S1429>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/N Gain'
//  '<S1430>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/P Copy'
//  '<S1431>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain'
//  '<S1432>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Reset Signal'
//  '<S1433>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Saturation'
//  '<S1434>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk'
//  '<S1435>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Sum'
//  '<S1436>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk'
//  '<S1437>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode'
//  '<S1438>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S1439>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral'
//  '<S1440>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S1441>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/postSat Signal'
//  '<S1442>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/preSat Signal'
//  '<S1443>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S1444>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S1445>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S1446>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/D Gain/Disabled'
//  '<S1447>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Filter/Disabled'
//  '<S1448>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Filter ICs/Disabled'
//  '<S1449>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S1450>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S1451>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S1452>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Integrator/Discrete'
//  '<S1453>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S1454>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S1455>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/N Gain/Disabled'
//  '<S1456>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/P Copy/Disabled'
//  '<S1457>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S1458>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S1459>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Saturation/Enabled'
//  '<S1460>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S1461>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Sum/Sum_PI'
//  '<S1462>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S1463>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S1464>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S1465>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S1466>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S1467>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S1468>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S1469>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Anti-windup'
//  '<S1470>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/D Gain'
//  '<S1471>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Filter'
//  '<S1472>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Filter ICs'
//  '<S1473>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/I Gain'
//  '<S1474>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain'
//  '<S1475>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain Fdbk'
//  '<S1476>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Integrator'
//  '<S1477>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Integrator ICs'
//  '<S1478>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/N Copy'
//  '<S1479>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/N Gain'
//  '<S1480>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/P Copy'
//  '<S1481>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Parallel P Gain'
//  '<S1482>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Reset Signal'
//  '<S1483>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Saturation'
//  '<S1484>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Saturation Fdbk'
//  '<S1485>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Sum'
//  '<S1486>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Sum Fdbk'
//  '<S1487>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode'
//  '<S1488>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode Sum'
//  '<S1489>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Integral'
//  '<S1490>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Ngain'
//  '<S1491>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/postSat Signal'
//  '<S1492>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/preSat Signal'
//  '<S1493>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Anti-windup/Disabled'
//  '<S1494>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/D Gain/Disabled'
//  '<S1495>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Filter/Disabled'
//  '<S1496>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Filter ICs/Disabled'
//  '<S1497>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/I Gain/Disabled'
//  '<S1498>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain/Passthrough'
//  '<S1499>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S1500>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Integrator/Disabled'
//  '<S1501>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Integrator ICs/Disabled'
//  '<S1502>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S1503>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/N Gain/Disabled'
//  '<S1504>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/P Copy/Disabled'
//  '<S1505>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S1506>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Reset Signal/Disabled'
//  '<S1507>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Saturation/Enabled'
//  '<S1508>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Saturation Fdbk/Disabled'
//  '<S1509>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Sum/Passthrough_P'
//  '<S1510>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Sum Fdbk/Disabled'
//  '<S1511>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode/Disabled'
//  '<S1512>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S1513>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Integral/Disabled wSignal Specification'
//  '<S1514>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S1515>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/postSat Signal/Forward_Path'
//  '<S1516>' : 'ModelRiki/Ctrl/VelocityCtrl/Yaw Controller/Discrete PID Controller3/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_Ctrl_h_

//
// File trailer for generated code.
//
// [EOF]
//
