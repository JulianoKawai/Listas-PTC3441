#include "__cf_dinamicaRRR.h"
#include "rt_logging_mmi.h"
#include "dinamicaRRR_capi.h"
#include <math.h>
#include "dinamicaRRR.h"
#include "dinamicaRRR_private.h"
#include "dinamicaRRR_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.2 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\dinamicaRRR\\dinamicaRRR_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; ExtY rtY ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; void MdlInitialize ( void ) { rtX . apy3xqi2fg [ 0 ]
= rtP . Integrator1_IC [ 0 ] ; rtX . ck1sa2eqzz [ 0 ] = rtP . Integrator_IC [
0 ] ; rtX . apy3xqi2fg [ 1 ] = rtP . Integrator1_IC [ 1 ] ; rtX . ck1sa2eqzz
[ 1 ] = rtP . Integrator_IC [ 1 ] ; rtX . apy3xqi2fg [ 2 ] = rtP .
Integrator1_IC [ 2 ] ; rtX . ck1sa2eqzz [ 2 ] = rtP . Integrator_IC [ 2 ] ; }
void MdlStart ( void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr
( ) ; void * r2 = ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ;
const int maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [
16384 ] ; bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { void * slioCatalogue =
rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "dinamicaRRR/Out2" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 2 ] = { 3 , 1 } ; sigDims . nDims = 2 ; sigDims . dimensions = sigDimsArray
; srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = (
sdiFullBlkPathU ) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ;
srcInfo . subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . hob2ynzifl .
AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo
. mmi . InstanceMap . fullPath , "2e5039a3-2ac9-44c9-9deb-af4fd0dc59db" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. hob2ynzifl . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . hob2ynzifl
. AQHandles , "0.05" , 0.05 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime (
rtDW . hob2ynzifl . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . hob2ynzifl . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . hob2ynzifl . AQHandles ,
loggedName , origSigName , propName ) ; sdiAsyncRepoSetSignalDomainType (
rtDW . hob2ynzifl . AQHandles , "outport" ) ;
sdiAsyncRepoSetSignalExportOrder ( rtDW . hob2ynzifl . AQHandles , 2 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
hob2ynzifl . SlioLTF = ( NULL ) ; } { void * slioCatalogue = rt_slioCatalogue
( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "dinamicaRRR/Out1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 2 ] = { 3 , 1 } ; sigDims . nDims = 2 ; sigDims . dimensions = sigDimsArray
; srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = (
sdiFullBlkPathU ) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ;
srcInfo . subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . aak15wri3n .
AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo
. mmi . InstanceMap . fullPath , "ddbaeca5-f959-4417-aa4b-ab198d9e5e96" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. aak15wri3n . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . aak15wri3n
. AQHandles , "0.05" , 0.05 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime (
rtDW . aak15wri3n . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . aak15wri3n . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . aak15wri3n . AQHandles ,
loggedName , origSigName , propName ) ; sdiAsyncRepoSetSignalDomainType (
rtDW . aak15wri3n . AQHandles , "outport" ) ;
sdiAsyncRepoSetSignalExportOrder ( rtDW . aak15wri3n . AQHandles , 1 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
aak15wri3n . SlioLTF = ( NULL ) ; } MdlInitialize ( ) ; } void MdlOutputs (
int_T tid ) { real_T x [ 9 ] ; int32_T p1 ; int32_T p2 ; int32_T p3 ; real_T
absx11 ; real_T absx21 ; int32_T itmp ; real_T iggpl5reso [ 9 ] ; absx11 =
ssGetTaskTime ( rtS , 0 ) ; rtB . mo2rcpgszm [ 0 ] = rtX . ck1sa2eqzz [ 0 ] ;
rtB . mo2rcpgszm [ 1 ] = rtX . ck1sa2eqzz [ 1 ] ; rtB . mo2rcpgszm [ 2 ] =
rtX . ck1sa2eqzz [ 2 ] ; if ( absx11 < rtP . Step_Time ) { absx21 = rtP .
Step_Y0 [ 0 ] ; } else { absx21 = rtP . Step_YFinal [ 0 ] ; } rtB .
o12gyljr2e [ 0 ] = absx21 - ( ( ( - ( rtP . m2 + rtP . m3 ) * rtP . l1 * rtP
. l2 * muDoubleScalarSin ( rtX . apy3xqi2fg [ 1 ] ) * ( rtB . mo2rcpgszm [ 1
] * rtB . mo2rcpgszm [ 1 ] ) - ( rtP . m2 + rtP . m3 ) * 2.0 * rtP . l1 * rtP
. l2 * muDoubleScalarSin ( rtX . apy3xqi2fg [ 1 ] ) * rtB . mo2rcpgszm [ 0 ]
* rtB . mo2rcpgszm [ 1 ] ) + ( ( ( rtP . m1 + rtP . m2 ) + rtP . m3 ) * rtP .
l1 * rtP . g * muDoubleScalarCos ( rtX . apy3xqi2fg [ 0 ] ) + ( rtP . m2 +
rtP . m3 ) * rtP . l2 * rtP . g * muDoubleScalarCos ( rtX . apy3xqi2fg [ 0 ]
+ rtX . apy3xqi2fg [ 1 ] ) ) ) + rtP . v * rtB . mo2rcpgszm [ 0 ] ) ; rtY .
mjooh2zg0b [ 0 ] = rtB . o12gyljr2e [ 0 ] ; rtB . iyo3zdchld [ 0 ] = rtP .
Gain_Gain * rtX . apy3xqi2fg [ 0 ] ; rtY . ms50kk21e4 [ 0 ] = rtB .
iyo3zdchld [ 0 ] ; if ( absx11 < rtP . Step_Time ) { absx21 = rtP . Step_Y0 [
1 ] ; absx11 = rtP . Step_Y0 [ 2 ] ; } else { absx21 = rtP . Step_YFinal [ 1
] ; absx11 = rtP . Step_YFinal [ 2 ] ; } rtB . o12gyljr2e [ 1 ] = absx21 - (
( ( rtP . m2 + rtP . m3 ) * rtP . l1 * rtP . l2 * muDoubleScalarSin ( rtX .
apy3xqi2fg [ 1 ] ) * ( rtB . mo2rcpgszm [ 0 ] * rtB . mo2rcpgszm [ 0 ] ) + (
rtP . m2 + rtP . m3 ) * rtP . l2 * rtP . g * muDoubleScalarCos ( rtX .
apy3xqi2fg [ 0 ] + rtX . apy3xqi2fg [ 1 ] ) ) + rtP . v * rtB . mo2rcpgszm [
1 ] ) ; rtY . mjooh2zg0b [ 1 ] = rtB . o12gyljr2e [ 1 ] ; rtB . iyo3zdchld [
1 ] = rtP . Gain_Gain * rtX . apy3xqi2fg [ 1 ] ; rtY . ms50kk21e4 [ 1 ] = rtB
. iyo3zdchld [ 1 ] ; rtB . o12gyljr2e [ 2 ] = absx11 - rtP . v * rtB .
mo2rcpgszm [ 2 ] ; rtY . mjooh2zg0b [ 2 ] = rtB . o12gyljr2e [ 2 ] ; rtB .
iyo3zdchld [ 2 ] = rtP . Gain_Gain * rtX . apy3xqi2fg [ 2 ] ; rtY .
ms50kk21e4 [ 2 ] = rtB . iyo3zdchld [ 2 ] ; iggpl5reso [ 0 ] = ( ( rtP . m2 +
rtP . m3 ) * 2.0 * rtP . l1 * rtP . l2 * muDoubleScalarCos ( rtX . apy3xqi2fg
[ 1 ] ) + ( ( rtP . m2 + rtP . m3 ) * ( rtP . l2 * rtP . l2 ) + 0.1 ) ) + ( (
rtP . m1 + rtP . m2 ) + rtP . m3 ) * ( rtP . l1 * rtP . l1 ) ; iggpl5reso [ 3
] = ( rtP . m2 + rtP . m3 ) * rtP . l1 * rtP . l2 * muDoubleScalarCos ( rtX .
apy3xqi2fg [ 1 ] ) + ( ( rtP . m2 + rtP . m3 ) * ( rtP . l2 * rtP . l2 ) +
0.1 ) ; iggpl5reso [ 6 ] = 0.1 ; iggpl5reso [ 1 ] = ( rtP . m2 + rtP . m3 ) *
rtP . l1 * rtP . l2 * muDoubleScalarCos ( rtX . apy3xqi2fg [ 1 ] ) + ( ( rtP
. m2 + rtP . m3 ) * ( rtP . l2 * rtP . l2 ) + 0.1 ) ; iggpl5reso [ 4 ] = (
rtP . m2 + rtP . m3 ) * ( rtP . l2 * rtP . l2 ) + 0.1 ; iggpl5reso [ 7 ] =
0.1 ; iggpl5reso [ 2 ] = 0.1 ; iggpl5reso [ 5 ] = 0.1 ; iggpl5reso [ 8 ] =
0.1 ; memcpy ( & x [ 0 ] , & iggpl5reso [ 0 ] , 9U * sizeof ( real_T ) ) ; p1
= 0 ; p2 = 3 ; p3 = 6 ; absx11 = muDoubleScalarAbs ( iggpl5reso [ 0 ] ) ;
absx21 = muDoubleScalarAbs ( iggpl5reso [ 1 ] ) ; if ( ( absx21 > absx11 ) &&
( absx21 > 0.1 ) ) { p1 = 3 ; p2 = 0 ; x [ 0 ] = iggpl5reso [ 1 ] ; x [ 1 ] =
iggpl5reso [ 0 ] ; x [ 3 ] = iggpl5reso [ 4 ] ; x [ 4 ] = iggpl5reso [ 3 ] ;
} else { if ( 0.1 > absx11 ) { p1 = 6 ; p3 = 0 ; x [ 0 ] = 0.1 ; x [ 2 ] =
iggpl5reso [ 0 ] ; x [ 3 ] = 0.1 ; x [ 5 ] = iggpl5reso [ 3 ] ; } } absx11 =
x [ 1 ] / x [ 0 ] ; x [ 1 ] /= x [ 0 ] ; absx21 = x [ 2 ] / x [ 0 ] ; x [ 2 ]
/= x [ 0 ] ; x [ 4 ] -= absx11 * x [ 3 ] ; x [ 5 ] -= absx21 * x [ 3 ] ; x [
7 ] = 0.1 - absx11 * 0.1 ; x [ 8 ] = 0.1 - absx21 * 0.1 ; if (
muDoubleScalarAbs ( x [ 5 ] ) > muDoubleScalarAbs ( x [ 4 ] ) ) { itmp = p2 ;
p2 = p3 ; p3 = itmp ; x [ 1 ] = absx21 ; x [ 2 ] = absx11 ; absx11 = x [ 4 ]
; x [ 4 ] = x [ 5 ] ; x [ 5 ] = absx11 ; absx11 = x [ 7 ] ; x [ 7 ] = x [ 8 ]
; x [ 8 ] = absx11 ; } absx11 = x [ 5 ] / x [ 4 ] ; x [ 5 ] /= x [ 4 ] ; x [
8 ] -= absx11 * x [ 7 ] ; absx11 = ( x [ 5 ] * x [ 1 ] - x [ 2 ] ) / x [ 8 ]
; absx21 = - ( x [ 7 ] * absx11 + x [ 1 ] ) / x [ 4 ] ; iggpl5reso [ p1 ] = (
( 1.0 - x [ 3 ] * absx21 ) - 0.1 * absx11 ) / x [ 0 ] ; iggpl5reso [ p1 + 1 ]
= absx21 ; iggpl5reso [ p1 + 2 ] = absx11 ; absx11 = - x [ 5 ] / x [ 8 ] ;
absx21 = ( 1.0 - x [ 7 ] * absx11 ) / x [ 4 ] ; iggpl5reso [ p2 ] = - ( x [ 3
] * absx21 + 0.1 * absx11 ) / x [ 0 ] ; iggpl5reso [ p2 + 1 ] = absx21 ;
iggpl5reso [ p2 + 2 ] = absx11 ; absx11 = 1.0 / x [ 8 ] ; absx21 = - x [ 7 ]
* absx11 / x [ 4 ] ; iggpl5reso [ p3 ] = - ( x [ 3 ] * absx21 + 0.1 * absx11
) / x [ 0 ] ; iggpl5reso [ p3 + 1 ] = absx21 ; iggpl5reso [ p3 + 2 ] = absx11
; for ( p1 = 0 ; p1 < 3 ; p1 ++ ) { rtB . pgzyesdab5 [ p1 ] = 0.0 ; rtB .
pgzyesdab5 [ p1 ] += iggpl5reso [ p1 ] * rtB . o12gyljr2e [ 0 ] ; rtB .
pgzyesdab5 [ p1 ] += iggpl5reso [ p1 + 3 ] * rtB . o12gyljr2e [ 1 ] ; rtB .
pgzyesdab5 [ p1 ] += iggpl5reso [ p1 + 6 ] * rtB . o12gyljr2e [ 2 ] ; rtB .
om3zdku30z [ p1 ] = rtP . Gain2_Gain * rtB . pgzyesdab5 [ p1 ] ; rtB .
kyek2i5x1s [ p1 ] = rtP . Gain1_Gain * rtB . mo2rcpgszm [ p1 ] ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( ( rtDW . hob2ynzifl . AQHandles ||
rtDW . hob2ynzifl . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . hob2ynzifl . AQHandles , rtDW . hob2ynzifl .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . iyo3zdchld [ 0 ]
+ 0 ) ; } } { if ( ( rtDW . aak15wri3n . AQHandles || rtDW . aak15wri3n .
SlioLTF ) && ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW .
aak15wri3n . AQHandles , rtDW . aak15wri3n . SlioLTF , 0 , ssGetTaskTime (
rtS , 1 ) , ( char * ) & rtB . o12gyljr2e [ 0 ] + 0 ) ; } } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER
( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( (
XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> apy3xqi2fg [ 0 ] = rtB . mo2rcpgszm [
0 ] ; _rtXdot -> ck1sa2eqzz [ 0 ] = rtB . pgzyesdab5 [ 0 ] ; _rtXdot ->
apy3xqi2fg [ 1 ] = rtB . mo2rcpgszm [ 1 ] ; _rtXdot -> ck1sa2eqzz [ 1 ] = rtB
. pgzyesdab5 [ 1 ] ; _rtXdot -> apy3xqi2fg [ 2 ] = rtB . mo2rcpgszm [ 2 ] ;
_rtXdot -> ck1sa2eqzz [ 2 ] = rtB . pgzyesdab5 [ 2 ] ; } void MdlProjection (
void ) { } void MdlTerminate ( void ) { { if ( rtDW . hob2ynzifl . AQHandles
) { sdiTerminateStreaming ( & rtDW . hob2ynzifl . AQHandles ) ; } if ( rtDW .
hob2ynzifl . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . hob2ynzifl .
SlioLTF ) ; } } { if ( rtDW . aak15wri3n . AQHandles ) {
sdiTerminateStreaming ( & rtDW . aak15wri3n . AQHandles ) ; } if ( rtDW .
aak15wri3n . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . aak15wri3n .
SlioLTF ) ; } } if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 6 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 6 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 23 ) ; ssSetNumBlockIO ( rtS , 6 ) ;
ssSetNumBlockParams ( rtS , 23 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.05 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 899073710U ) ;
ssSetChecksumVal ( rtS , 1 , 1450954633U ) ; ssSetChecksumVal ( rtS , 2 ,
1723097066U ) ; ssSetChecksumVal ( rtS , 3 , 816124328U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( ( void * ) & rtY , 0
, sizeof ( ExtY ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates (
rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 14 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } dinamicaRRR_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"dinamicaRRR" ) ; ssSetPath ( rtS , "dinamicaRRR" ) ; ssSetTStart ( rtS , 0.0
) ; ssSetTFinal ( rtS , 5.0 ) ; ssSetStepSize ( rtS , 0.05 ) ;
ssSetFixedStepSize ( rtS , 0.05 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; { static void * rt_LoggedOutputSignalPtrs [ ] = { & rtY .
mjooh2zg0b [ 0 ] , & rtY . ms50kk21e4 [ 0 ] } ; rtliSetLogYSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( ( LogSignalPtrsType ) rt_LoggedOutputSignalPtrs )
) ; } { static int_T rt_LoggedOutputWidths [ ] = { 3 , 3 } ; static int_T
rt_LoggedOutputNumDimensions [ ] = { 2 , 2 } ; static int_T
rt_LoggedOutputDimensions [ ] = { 3 , 1 , 3 , 1 } ; static boolean_T
rt_LoggedOutputIsVarDims [ ] = { 0 , 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) } ; static int_T rt_LoggedCurrentSignalDimensionsSize [ ] = { 4 , 4 ,
4 , 4 } ; static BuiltInDTypeId rt_LoggedOutputDataTypeIds [ ] = { SS_DOUBLE
, SS_DOUBLE } ; static int_T rt_LoggedOutputComplexSignals [ ] = { 0 , 0 } ;
static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs [ ] = { ( NULL )
, ( NULL ) } ; static const char_T * rt_LoggedOutputLabels [ ] = { "" , "" }
; static const char_T * rt_LoggedOutputBlockNames [ ] = { "dinamicaRRR/Out1"
, "dinamicaRRR/Out2" } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static RTWLogSignalInfo rt_LoggedOutputSignalInfo [ ] = { { 2 ,
rt_LoggedOutputWidths , rt_LoggedOutputNumDimensions ,
rt_LoggedOutputDimensions , rt_LoggedOutputIsVarDims ,
rt_LoggedCurrentSignalDimensions , rt_LoggedCurrentSignalDimensionsSize ,
rt_LoggedOutputDataTypeIds , rt_LoggedOutputComplexSignals , ( NULL ) ,
rt_LoggingPreprocessingFcnPtrs , { rt_LoggedOutputLabels } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedOutputBlockNames } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert } } ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS
) , rt_LoggedOutputSignalInfo ) ; rt_LoggedCurrentSignalDimensions [ 0 ] = &
rt_LoggedOutputWidths [ 0 ] ; rt_LoggedCurrentSignalDimensions [ 1 ] = &
rt_LoggedOutputWidths [ 0 ] ; rt_LoggedCurrentSignalDimensions [ 2 ] = &
rt_LoggedOutputWidths [ 1 ] ; rt_LoggedCurrentSignalDimensions [ 3 ] = &
rt_LoggedOutputWidths [ 1 ] ; } rtliSetLogY ( ssGetRTWLogInfo ( rtS ) ,
"yout" ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 (
rtS , & statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode3" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 899073710U ) ; ssSetChecksumVal ( rtS , 1 ,
1450954633U ) ; ssSetChecksumVal ( rtS , 2 , 1723097066U ) ; ssSetChecksumVal
( rtS , 3 , 816124328U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 5 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
