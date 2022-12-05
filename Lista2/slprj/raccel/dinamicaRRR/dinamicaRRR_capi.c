#include "__cf_dinamicaRRR.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "dinamicaRRR_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "dinamicaRRR.h"
#include "dinamicaRRR_capi.h"
#include "dinamicaRRR_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"dinamicaRRR/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "dinamicaRRR/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 2 , 0 , TARGET_STRING ( "dinamicaRRR/Gain2" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "dinamicaRRR/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"dinamicaRRR/Matrix Multiply" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 5 , 0 , TARGET_STRING ( "dinamicaRRR/Sum2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 6 ,
TARGET_STRING ( "dinamicaRRR/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 }
, { 7 , TARGET_STRING ( "dinamicaRRR/Gain1" ) , TARGET_STRING ( "Gain" ) , 0
, 1 , 0 } , { 8 , TARGET_STRING ( "dinamicaRRR/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 9 , TARGET_STRING ( "dinamicaRRR/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 10 , TARGET_STRING (
"dinamicaRRR/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 2 ,
0 } , { 11 , TARGET_STRING ( "dinamicaRRR/Step" ) , TARGET_STRING ( "Time" )
, 0 , 1 , 0 } , { 12 , TARGET_STRING ( "dinamicaRRR/Step" ) , TARGET_STRING (
"Before" ) , 0 , 2 , 0 } , { 13 , TARGET_STRING ( "dinamicaRRR/Step" ) ,
TARGET_STRING ( "After" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 14 ,
TARGET_STRING ( "g" ) , 0 , 1 , 0 } , { 15 , TARGET_STRING ( "l1" ) , 0 , 1 ,
0 } , { 16 , TARGET_STRING ( "l2" ) , 0 , 1 , 0 } , { 17 , TARGET_STRING (
"m1" ) , 0 , 1 , 0 } , { 18 , TARGET_STRING ( "m2" ) , 0 , 1 , 0 } , { 19 ,
TARGET_STRING ( "m3" ) , 0 , 1 , 0 } , { 20 , TARGET_STRING ( "v" ) , 0 , 1 ,
0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . iyo3zdchld [ 0 ] , & rtB .
kyek2i5x1s [ 0 ] , & rtB . om3zdku30z [ 0 ] , & rtB . mo2rcpgszm [ 0 ] , &
rtB . pgzyesdab5 [ 0 ] , & rtB . o12gyljr2e [ 0 ] , & rtP . Gain_Gain , & rtP
. Gain1_Gain , & rtP . Gain2_Gain , & rtP . Integrator_IC [ 0 ] , & rtP .
Integrator1_IC [ 0 ] , & rtP . Step_Time , & rtP . Step_Y0 [ 0 ] , & rtP .
Step_YFinal [ 0 ] , & rtP . g , & rtP . l1 , & rtP . l2 , & rtP . m1 , & rtP
. m2 , & rtP . m3 , & rtP . v , } ; static int32_T * rtVarDimsAddrMap [ ] = {
( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_MATRIX_COL_MAJOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
3 , 1 , 1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 6 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 8 , rtModelParameters , 7 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 899073710U , 1450954633U
, 1723097066U , 816124328U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * dinamicaRRR_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void dinamicaRRR_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void dinamicaRRR_host_InitializeDataMapInfo ( dinamicaRRR_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
