//
// File: Ctrl_data.cpp
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
#include "Ctrl.h"
#include "Ctrl_private.h"

// Block parameters (default storage)
P_Ctrl_T CtrlModelClass::Ctrl_P = {
  // Mask Parameter: DiscretePIDController_InitialCo
  //  Referenced by: '<S352>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_n
  //  Referenced by: '<S154>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_c
  //  Referenced by: '<S720>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_l
  //  Referenced by: '<S669>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_p
  //  Referenced by: '<S931>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_d
  //  Referenced by: '<S831>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_j
  //  Referenced by: '<S1243>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_nr
  //  Referenced by: '<S1143>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController1_InitialC
  //  Referenced by: '<S55>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController2_InitialC
  //  Referenced by: '<S508>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController1_Initia_k
  //  Referenced by: '<S458>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_cd
  //  Referenced by: '<S357>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_m
  //  Referenced by: '<S159>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_c5
  //  Referenced by: '<S562>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_mn
  //  Referenced by: '<S725>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_f
  //  Referenced by: '<S674>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_a
  //  Referenced by: '<S776>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_pb
  //  Referenced by: '<S936>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initial_b
  //  Referenced by: '<S836>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_np
  //  Referenced by: '<S1035>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController1_Initia_c
  //  Referenced by: '<S1092>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController2_Initia_k
  //  Referenced by: '<S1399>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController1_Initia_j
  //  Referenced by: '<S1349>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_jc
  //  Referenced by: '<S1248>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initia_lr
  //  Referenced by: '<S1148>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController_Initi_c5w
  //  Referenced by: '<S1452>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController2_LowerSat
  //  Referenced by: '<S110>/Saturation'

  -0.5F,

  // Mask Parameter: DiscretePIDController1_LowerSat
  //  Referenced by:
  //    '<S62>/Saturation'
  //    '<S48>/DeadZone'

  -0.4F,

  // Mask Parameter: DiscretePIDController2_LowerS_e
  //  Referenced by: '<S312>/Saturation'

  -1.0F,

  // Mask Parameter: DiscretePIDController2_LowerS_h
  //  Referenced by:
  //    '<S515>/Saturation'
  //    '<S501>/DeadZone'

  -1.0F,

  // Mask Parameter: DiscretePIDController1_LowerS_m
  //  Referenced by: '<S264>/Saturation'

  -1.0F,

  // Mask Parameter: DiscretePIDController1_LowerS_p
  //  Referenced by:
  //    '<S465>/Saturation'
  //    '<S451>/DeadZone'

  -1.0F,

  // Mask Parameter: DiscretePIDController1_LowerS_g
  //  Referenced by: '<S412>/Saturation'

  -200.0F,

  // Mask Parameter: DiscretePIDController_LowerSatu
  //  Referenced by:
  //    '<S364>/Saturation'
  //    '<S350>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController1_LowerS_n
  //  Referenced by: '<S214>/Saturation'

  -200.0F,

  // Mask Parameter: DiscretePIDController_LowerSa_o
  //  Referenced by:
  //    '<S166>/Saturation'
  //    '<S152>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController3_LowerSat
  //  Referenced by: '<S617>/Saturation'

  -180.0F,

  // Mask Parameter: DiscretePIDController_LowerSa_i
  //  Referenced by:
  //    '<S569>/Saturation'
  //    '<S555>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController_LowerSa_k
  //  Referenced by:
  //    '<S732>/Saturation'
  //    '<S718>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController_LowerS_io
  //  Referenced by:
  //    '<S681>/Saturation'
  //    '<S667>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController_LowerSa_a
  //  Referenced by:
  //    '<S783>/Saturation'
  //    '<S769>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController1_LowerS_d
  //  Referenced by: '<S991>/Saturation'

  -200.0F,

  // Mask Parameter: DiscretePIDController_LowerSa_b
  //  Referenced by:
  //    '<S943>/Saturation'
  //    '<S929>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController1_Lower_de
  //  Referenced by: '<S891>/Saturation'

  -200.0F,

  // Mask Parameter: DiscretePIDController_LowerSa_p
  //  Referenced by:
  //    '<S843>/Saturation'
  //    '<S829>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController_LowerSa_f
  //  Referenced by:
  //    '<S1042>/Saturation'
  //    '<S1028>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController1_LowerS_b
  //  Referenced by:
  //    '<S1099>/Saturation'
  //    '<S1085>/DeadZone'

  -0.4F,

  // Mask Parameter: DiscretePIDController2_LowerS_a
  //  Referenced by:
  //    '<S1406>/Saturation'
  //    '<S1392>/DeadZone'

  -1.0F,

  // Mask Parameter: DiscretePIDController1_LowerS_e
  //  Referenced by:
  //    '<S1356>/Saturation'
  //    '<S1342>/DeadZone'

  -1.0F,

  // Mask Parameter: DiscretePIDController1_Lower_pq
  //  Referenced by: '<S1303>/Saturation'

  -200.0F,

  // Mask Parameter: DiscretePIDController_LowerS_ok
  //  Referenced by:
  //    '<S1255>/Saturation'
  //    '<S1241>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController1_LowerS_f
  //  Referenced by: '<S1203>/Saturation'

  -200.0F,

  // Mask Parameter: DiscretePIDController_LowerS_a3
  //  Referenced by:
  //    '<S1155>/Saturation'
  //    '<S1141>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController3_LowerS_f
  //  Referenced by: '<S1507>/Saturation'

  -180.0F,

  // Mask Parameter: DiscretePIDController_LowerSa_m
  //  Referenced by:
  //    '<S1459>/Saturation'
  //    '<S1445>/DeadZone'

  -0.2F,

  // Mask Parameter: DiscretePIDController_N
  //  Referenced by: '<S360>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController_N_h
  //  Referenced by: '<S162>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController_N_hm
  //  Referenced by: '<S728>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController_N_p
  //  Referenced by: '<S677>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController_N_i
  //  Referenced by: '<S939>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController_N_hn
  //  Referenced by: '<S839>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController_N_n
  //  Referenced by: '<S1251>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController_N_g
  //  Referenced by: '<S1151>/Filter Coefficient'

  50.0F,

  // Mask Parameter: DiscretePIDController2_UpperSat
  //  Referenced by: '<S110>/Saturation'

  0.5F,

  // Mask Parameter: DiscretePIDController1_UpperSat
  //  Referenced by:
  //    '<S62>/Saturation'
  //    '<S48>/DeadZone'

  0.4F,

  // Mask Parameter: DiscretePIDController2_UpperS_o
  //  Referenced by: '<S312>/Saturation'

  1.0F,

  // Mask Parameter: DiscretePIDController2_UpperS_d
  //  Referenced by:
  //    '<S515>/Saturation'
  //    '<S501>/DeadZone'

  1.0F,

  // Mask Parameter: DiscretePIDController1_UpperS_b
  //  Referenced by: '<S264>/Saturation'

  1.0F,

  // Mask Parameter: DiscretePIDController1_UpperS_g
  //  Referenced by:
  //    '<S465>/Saturation'
  //    '<S451>/DeadZone'

  1.0F,

  // Mask Parameter: DiscretePIDController_UpperSatu
  //  Referenced by:
  //    '<S364>/Saturation'
  //    '<S350>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_g
  //  Referenced by:
  //    '<S166>/Saturation'
  //    '<S152>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperS_gi
  //  Referenced by:
  //    '<S569>/Saturation'
  //    '<S555>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_h
  //  Referenced by:
  //    '<S732>/Saturation'
  //    '<S718>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_n
  //  Referenced by:
  //    '<S681>/Saturation'
  //    '<S667>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_b
  //  Referenced by:
  //    '<S783>/Saturation'
  //    '<S769>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_p
  //  Referenced by:
  //    '<S943>/Saturation'
  //    '<S929>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_i
  //  Referenced by:
  //    '<S843>/Saturation'
  //    '<S829>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_k
  //  Referenced by:
  //    '<S1042>/Saturation'
  //    '<S1028>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController1_UpperS_l
  //  Referenced by:
  //    '<S1099>/Saturation'
  //    '<S1085>/DeadZone'

  0.4F,

  // Mask Parameter: DiscretePIDController2_UpperS_i
  //  Referenced by:
  //    '<S1406>/Saturation'
  //    '<S1392>/DeadZone'

  1.0F,

  // Mask Parameter: DiscretePIDController1_UpperS_n
  //  Referenced by:
  //    '<S1356>/Saturation'
  //    '<S1342>/DeadZone'

  1.0F,

  // Mask Parameter: DiscretePIDController_UpperS_ii
  //  Referenced by:
  //    '<S1255>/Saturation'
  //    '<S1241>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperSa_m
  //  Referenced by:
  //    '<S1155>/Saturation'
  //    '<S1141>/DeadZone'

  0.2F,

  // Mask Parameter: DiscretePIDController_UpperS_nb
  //  Referenced by:
  //    '<S1459>/Saturation'
  //    '<S1445>/DeadZone'

  0.2F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S528>/Gain'

  57.2957802F,

  // Computed Parameter: Constant1_Value
  //  Referenced by: '<S46>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_c
  //  Referenced by: '<S150>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_p
  //  Referenced by: '<S348>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_b
  //  Referenced by: '<S449>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_g
  //  Referenced by: '<S499>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_j
  //  Referenced by: '<S553>/Constant1'

  0.0F,

  // Computed Parameter: ScaleVel_Gain
  //  Referenced by: '<S13>/Scale Vel'

  12.0F,

  // Computed Parameter: FixFaultyBaro_UpperSat
  //  Referenced by: '<S13>/Fix Faulty Baro'

  20.0F,

  // Computed Parameter: FixFaultyBaro_LowerSat
  //  Referenced by: '<S13>/Fix Faulty Baro'

  -20.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S55>/Integrator'

  0.0025F,

  // Computed Parameter: ZeroGain_Gain
  //  Referenced by: '<S46>/ZeroGain'

  0.0F,

  // Computed Parameter: LimitOutput_UpperSat
  //  Referenced by: '<S13>/Limit Output'

  0.9F,

  // Computed Parameter: LimitOutput_LowerSat
  //  Referenced by: '<S13>/Limit Output'

  0.2F,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: '<S508>/Integrator'

  0.0025F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S422>/Gain1'

  0.0174532924F,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S458>/Integrator'

  0.0025F,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S357>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S352>/Filter'

  0.0025F,

  // Computed Parameter: Integrator_gainval_ao
  //  Referenced by: '<S159>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval_e
  //  Referenced by: '<S154>/Filter'

  0.0025F,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S19>/Discrete-Time Integrator'

  0.0025F,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S19>/Switch'

  -1000.0F,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S562>/Integrator'

  0.0025F,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S120>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat
  //  Referenced by: '<S120>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat
  //  Referenced by: '<S120>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_f
  //  Referenced by: '<S120>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S121>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_k
  //  Referenced by: '<S121>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_i
  //  Referenced by: '<S121>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S121>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S122>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_m
  //  Referenced by: '<S122>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_ih
  //  Referenced by: '<S122>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_j
  //  Referenced by: '<S122>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S123>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_a
  //  Referenced by: '<S123>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_n
  //  Referenced by: '<S123>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_b
  //  Referenced by: '<S123>/Gain'

  800.0F,

  // Computed Parameter: ZeroGain_Gain_j
  //  Referenced by: '<S150>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_p
  //  Referenced by: '<S348>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_l
  //  Referenced by: '<S449>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_k
  //  Referenced by: '<S499>/ZeroGain'

  0.0F,

  // Computed Parameter: DeadZone_Start
  //  Referenced by: '<S19>/Dead Zone'

  -0.1F,

  // Computed Parameter: DeadZone_End
  //  Referenced by: '<S19>/Dead Zone'

  0.1F,

  // Computed Parameter: ZeroGain_Gain_g
  //  Referenced by: '<S553>/ZeroGain'

  0.0F,

  // Computed Parameter: Scaleroll2_Gain
  //  Referenced by: '<S19>/Scale roll2'

  90.0F,

  // Computed Parameter: Gain_Gain_ae
  //  Referenced by: '<S6>/Gain'

  1.0F,

  // Computed Parameter: Gain1_Gain_e
  //  Referenced by: '<S6>/Gain1'

  0.2F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S6>/Gain2'

  0.2F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S6>/Gain3'

  0.2F,

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S628>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_l
  //  Referenced by: '<S628>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_g
  //  Referenced by: '<S628>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_m
  //  Referenced by: '<S628>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S629>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_b
  //  Referenced by: '<S629>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_k
  //  Referenced by: '<S629>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_c
  //  Referenced by: '<S629>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S630>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_o
  //  Referenced by: '<S630>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_d
  //  Referenced by: '<S630>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_e
  //  Referenced by: '<S630>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S631>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_c
  //  Referenced by: '<S631>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_f
  //  Referenced by: '<S631>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_bq
  //  Referenced by: '<S631>/Gain'

  800.0F,

  // Computed Parameter: PWMs_Y0
  //  Referenced by: '<S7>/PWMs'

  { 1000.0F, 1000.0F, 1000.0F, 1000.0F },

  // Computed Parameter: Constant1_Value_l
  //  Referenced by: '<S7>/Constant1'

  1000.0F,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<S7>/Constant2'

  1000.0F,

  // Computed Parameter: Constant3_Value
  //  Referenced by: '<S7>/Constant3'

  1000.0F,

  // Computed Parameter: Constant4_Value
  //  Referenced by: '<S7>/Constant4'

  1000.0F,

  // Computed Parameter: Constant1_Value_a
  //  Referenced by: '<S665>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_e
  //  Referenced by: '<S716>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S767>/Constant1'

  0.0F,

  // Computed Parameter: Gain_Gain_cu
  //  Referenced by: '<S8>/Gain'

  1.0F,

  // Computed Parameter: Integrator_gainval_d
  //  Referenced by: '<S725>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval_el
  //  Referenced by: '<S720>/Filter'

  0.0025F,

  // Computed Parameter: Integrator_gainval_dd
  //  Referenced by: '<S674>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval_n
  //  Referenced by: '<S669>/Filter'

  0.0025F,

  // Computed Parameter: DeadZone_Start_c
  //  Referenced by: '<S635>/Dead Zone'

  -0.1F,

  // Computed Parameter: DeadZone_End_o
  //  Referenced by: '<S635>/Dead Zone'

  0.1F,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S776>/Integrator'

  0.0025F,

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S636>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_d
  //  Referenced by: '<S636>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_ku
  //  Referenced by: '<S636>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S636>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_ev
  //  Referenced by: '<S637>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_a1
  //  Referenced by: '<S637>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_e
  //  Referenced by: '<S637>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_ce
  //  Referenced by: '<S637>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S638>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_g
  //  Referenced by: '<S638>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_j
  //  Referenced by: '<S638>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_cc
  //  Referenced by: '<S638>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S639>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_j
  //  Referenced by: '<S639>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_o
  //  Referenced by: '<S639>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_hp
  //  Referenced by: '<S639>/Gain'

  800.0F,

  // Computed Parameter: ZeroGain_Gain_n
  //  Referenced by: '<S665>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_nc
  //  Referenced by: '<S716>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_e
  //  Referenced by: '<S767>/ZeroGain'

  0.0F,

  // Computed Parameter: Constant1_Value_i
  //  Referenced by: '<S827>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_o
  //  Referenced by: '<S927>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_m
  //  Referenced by: '<S1026>/Constant1'

  0.0F,

  // Computed Parameter: Gain_Gain_mu
  //  Referenced by: '<S9>/Gain'

  1.0F,

  // Computed Parameter: Integrator_gainval_j
  //  Referenced by: '<S936>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval_j
  //  Referenced by: '<S931>/Filter'

  0.0025F,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S836>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S831>/Filter'

  0.0025F,

  // Computed Parameter: DeadZone_Start_l
  //  Referenced by: '<S796>/Dead Zone'

  -0.1F,

  // Computed Parameter: DeadZone_End_h
  //  Referenced by: '<S796>/Dead Zone'

  0.1F,

  // Computed Parameter: Integrator_gainval_im
  //  Referenced by: '<S1035>/Integrator'

  0.0025F,

  // Computed Parameter: Constant_Value_p4
  //  Referenced by: '<S797>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_b5
  //  Referenced by: '<S797>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_jv
  //  Referenced by: '<S797>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S797>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_co
  //  Referenced by: '<S798>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_gu
  //  Referenced by: '<S798>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_dd
  //  Referenced by: '<S798>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_d
  //  Referenced by: '<S798>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_oi
  //  Referenced by: '<S799>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_kf
  //  Referenced by: '<S799>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_du
  //  Referenced by: '<S799>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S799>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_aw
  //  Referenced by: '<S800>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_n
  //  Referenced by: '<S800>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_b
  //  Referenced by: '<S800>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_m5
  //  Referenced by: '<S800>/Gain'

  800.0F,

  // Computed Parameter: ZeroGain_Gain_gv
  //  Referenced by: '<S827>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_nb
  //  Referenced by: '<S927>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_gq
  //  Referenced by: '<S1026>/ZeroGain'

  0.0F,

  // Computed Parameter: Constant1_Value_ok
  //  Referenced by: '<S1083>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_k
  //  Referenced by: '<S1139>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_l0
  //  Referenced by: '<S1239>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_kj
  //  Referenced by: '<S1340>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_pl
  //  Referenced by: '<S1390>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_do
  //  Referenced by: '<S1443>/Constant1'

  0.0F,

  // Computed Parameter: Bias_Bias
  //  Referenced by: '<S1052>/Bias'

  -0.5F,

  // Computed Parameter: DeadZone_Start_p
  //  Referenced by: '<S1052>/Dead Zone'

  -0.1F,

  // Computed Parameter: DeadZone_End_b
  //  Referenced by: '<S1052>/Dead Zone'

  0.1F,

  // Computed Parameter: ScaleVel_Gain_a
  //  Referenced by: '<S1052>/Scale Vel'

  12.0F,

  // Computed Parameter: FixFaultyBaro_UpperSat_d
  //  Referenced by: '<S1052>/Fix Faulty Baro'

  20.0F,

  // Computed Parameter: FixFaultyBaro_LowerSat_o
  //  Referenced by: '<S1052>/Fix Faulty Baro'

  -20.0F,

  // Computed Parameter: Integrator_gainval_be
  //  Referenced by: '<S1092>/Integrator'

  0.0025F,

  // Computed Parameter: ZeroGain_Gain_ez
  //  Referenced by: '<S1083>/ZeroGain'

  0.0F,

  // Computed Parameter: LimitOutput_UpperSat_h
  //  Referenced by: '<S1052>/Limit Output'

  0.9F,

  // Computed Parameter: LimitOutput_LowerSat_f
  //  Referenced by: '<S1052>/Limit Output'

  0.2F,

  // Computed Parameter: Gain2_Gain_j
  //  Referenced by: '<S10>/Gain2'

  -1.0F,

  // Computed Parameter: Gain1_Gain_k
  //  Referenced by: '<S1313>/Gain1'

  0.0174532924F,

  // Computed Parameter: Integrator_gainval_l
  //  Referenced by: '<S1399>/Integrator'

  0.0025F,

  // Computed Parameter: Integrator_gainval_by
  //  Referenced by: '<S1349>/Integrator'

  0.0025F,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S1248>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S1243>/Filter'

  0.0025F,

  // Computed Parameter: Integrator_gainval_h3
  //  Referenced by: '<S1148>/Integrator'

  0.0025F,

  // Computed Parameter: Filter_gainval_p4
  //  Referenced by: '<S1143>/Filter'

  0.0025F,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_h
  //  Referenced by: '<S1057>/Discrete-Time Integrator'

  0.0025F,

  // Computed Parameter: Integrator_gainval_lc
  //  Referenced by: '<S1452>/Integrator'

  0.0025F,

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S1109>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_p
  //  Referenced by: '<S1109>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_it
  //  Referenced by: '<S1109>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_oa
  //  Referenced by: '<S1109>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S1110>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_e
  //  Referenced by: '<S1110>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_l
  //  Referenced by: '<S1110>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_hh
  //  Referenced by: '<S1110>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S1111>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_lo
  //  Referenced by: '<S1111>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_gb
  //  Referenced by: '<S1111>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_do
  //  Referenced by: '<S1111>/Gain'

  800.0F,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S1112>/Constant'

  1100.0F,

  // Computed Parameter: Limit3_UpperSat_i
  //  Referenced by: '<S1112>/Limit3'

  1.0F,

  // Computed Parameter: Limit3_LowerSat_d4
  //  Referenced by: '<S1112>/Limit3'

  0.0F,

  // Computed Parameter: Gain_Gain_bo
  //  Referenced by: '<S1112>/Gain'

  800.0F,

  // Computed Parameter: ZeroGain_Gain_o
  //  Referenced by: '<S1139>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_e2
  //  Referenced by: '<S1239>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_b
  //  Referenced by: '<S1340>/ZeroGain'

  0.0F,

  // Computed Parameter: ZeroGain_Gain_ezr
  //  Referenced by: '<S1390>/ZeroGain'

  0.0F,

  // Computed Parameter: DeadZone_Start_b
  //  Referenced by: '<S1057>/Dead Zone'

  -0.1F,

  // Computed Parameter: DeadZone_End_p
  //  Referenced by: '<S1057>/Dead Zone'

  0.1F,

  // Computed Parameter: ZeroGain_Gain_ny
  //  Referenced by: '<S1443>/ZeroGain'

  0.0F,

  // Computed Parameter: Scaleroll2_Gain_m
  //  Referenced by: '<S1057>/Scale roll2'

  90.0F,

  // Computed Parameter: Gain_Gain_n
  //  Referenced by: '<S12>/Gain'

  -1.0F,

  // Computed Parameter: Constant3_Value_b
  //  Referenced by: '<S5>/Constant3'

  1024.0F,

  // Computed Parameter: Gain3_Gain_f
  //  Referenced by: '<S5>/Gain3'

  -0.00147929F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S5>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S5>/Saturation3'

  -1.0F,

  // Computed Parameter: Constant_Value_pb
  //  Referenced by: '<S5>/Constant'

  350.0F,

  // Computed Parameter: Constant1_Value_g3
  //  Referenced by: '<S5>/Constant1'

  1024.0F,

  // Computed Parameter: Constant2_Value_c
  //  Referenced by: '<S5>/Constant2'

  1024.0F,

  // Computed Parameter: Gain_Gain_g
  //  Referenced by: '<S5>/Gain'

  0.000740740739F,

  // Computed Parameter: Gain1_Gain_b
  //  Referenced by: '<S5>/Gain1'

  -0.00147929F,

  // Computed Parameter: Gain2_Gain_k
  //  Referenced by: '<S5>/Gain2'

  -0.00147929F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S5>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S5>/Saturation'

  0.0F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S5>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S5>/Saturation1'

  -1.0F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S5>/Saturation2'

  1.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S5>/Saturation2'

  -1.0F,

  // Computed Parameter: Saturation_UpperSat_o
  //  Referenced by: '<S11>/Saturation'

  16.5F,

  // Computed Parameter: Saturation_LowerSat_k
  //  Referenced by: '<S11>/Saturation'

  14.0F,

  // Computed Parameter: Polynomial_Coefs
  //  Referenced by: '<S11>/Polynomial'

  { -20.2357502F, 666.277588F, -5384.2915F },

  // Computed Parameter: Saturation1_UpperSat_o
  //  Referenced by: '<S11>/Saturation1'

  100.0F,

  // Computed Parameter: Saturation1_LowerSat_o
  //  Referenced by: '<S11>/Saturation1'

  0.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
