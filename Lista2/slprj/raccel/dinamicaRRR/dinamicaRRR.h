#include "__cf_dinamicaRRR.h"
#ifndef RTW_HEADER_dinamicaRRR_h_
#define RTW_HEADER_dinamicaRRR_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef dinamicaRRR_COMMON_INCLUDES_
#define dinamicaRRR_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "dinamicaRRR_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME dinamicaRRR
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (6)     
#define NBLOCKIO (6) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T mo2rcpgszm [ 3 ] ; real_T o12gyljr2e [ 3 ] ; real_T
iyo3zdchld [ 3 ] ; real_T pgzyesdab5 [ 3 ] ; real_T om3zdku30z [ 3 ] ; real_T
kyek2i5x1s [ 3 ] ; } B ; typedef struct { struct { void * LoggedData [ 3 ] ;
} bhsacjpwps ; struct { void * LoggedData [ 3 ] ; } nstnpkeqqh ; struct {
void * AQHandles ; void * SlioLTF ; } hob2ynzifl ; struct { void * AQHandles
; void * SlioLTF ; } aak15wri3n ; } DW ; typedef struct { real_T apy3xqi2fg [
3 ] ; real_T ck1sa2eqzz [ 3 ] ; } X ; typedef struct { real_T apy3xqi2fg [ 3
] ; real_T ck1sa2eqzz [ 3 ] ; } XDot ; typedef struct { boolean_T apy3xqi2fg
[ 3 ] ; boolean_T ck1sa2eqzz [ 3 ] ; } XDis ; typedef struct { real_T
mjooh2zg0b [ 3 ] ; real_T ms50kk21e4 [ 3 ] ; } ExtY ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T g ; real_T
l1 ; real_T l2 ; real_T m1 ; real_T m2 ; real_T m3 ; real_T v ; real_T
Step_Time ; real_T Step_Y0 [ 3 ] ; real_T Step_YFinal [ 3 ] ; real_T
Integrator1_IC [ 3 ] ; real_T Integrator_IC [ 3 ] ; real_T Gain_Gain ; real_T
Gain2_Gain ; real_T Gain1_Gain ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtY rtY ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo
* dinamicaRRR_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
