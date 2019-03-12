#include "__cf_anav_real.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "anav_real_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "anav_real.h"
#include "anav_real_capi.h"
#include "anav_real_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"anav_real/Stateflow1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 ,
1 , TARGET_STRING ( "anav_real/Stateflow1" ) , TARGET_STRING ( "" ) , 1 , 0 ,
1 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"anav_real/Stateflow1/is_active_c10_anav_real" ) , TARGET_STRING (
"is_active_c10_anav_real" ) , 0 , 1 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"anav_real/Stateflow1/is_c10_anav_real" ) , TARGET_STRING (
"is_c10_anav_real" ) , 0 , 1 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"anav_real/Stateflow1/change_goal.is_change_goal" ) , TARGET_STRING (
"is_change_goal" ) , 0 , 1 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"anav_real/Stateflow1/ideal_path.is_ideal_path" ) , TARGET_STRING (
"is_ideal_path" ) , 0 , 1 , 0 , 0 , 0 } , { 6 , 2 , TARGET_STRING (
"anav_real/buildMap" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 7 , 5
, TARGET_STRING ( "anav_real/relativePos" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 8 , 5 , TARGET_STRING ( "anav_real/relativePos" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 9 , 5 , TARGET_STRING (
"anav_real/relativePos" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 10
, 5 , TARGET_STRING ( "anav_real/relativePos" ) , TARGET_STRING ( "" ) , 3 ,
0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING ( "anav_real/DstarRun C++" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"anav_real/Radians to Degrees/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 13 , TARGET_STRING (
"anav_real/Data Store Memory" ) , TARGET_STRING ( "InitialValue" ) , 0 , 4 ,
0 } , { 14 , TARGET_STRING ( "anav_real/Data Store Memory1" ) , TARGET_STRING
( "InitialValue" ) , 0 , 0 , 0 } , { 15 , TARGET_STRING ( "anav_real/doVis" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"anav_real/hokuyoPort" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 17 ,
TARGET_STRING ( "anav_real/isTeleOp" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 18 , TARGET_STRING ( "anav_real/pozyxPort" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING ( "anav_real/turnConst" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 20 , TARGET_STRING (
"anav_real/vehicleRad" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 21 ,
TARGET_STRING ( "anav_real/velConst" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 22 , TARGET_STRING ( "anav_real/Radians to Degrees/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 23 ,
TARGET_STRING ( "limit" ) , 0 , 5 , 0 } , { 24 , TARGET_STRING ( "mapDim" ) ,
0 , 4 , 0 } , { 25 , TARGET_STRING ( "mode" ) , 0 , 0 , 0 } , { 26 ,
TARGET_STRING ( "sObs" ) , 0 , 6 , 0 } , { 27 , TARGET_STRING ( "verticies" )
, 0 , 7 , 0 } , { 28 , TARGET_STRING ( "visualObj" ) , 0 , 8 , 0 } , { 0 , (
NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . nmf2aoyssm , & rtB . h1obb2nc31 [
0 ] , & rtDW . ouzu4kamsj , & rtDW . gesvnspaab , & rtDW . j1l4gcbtpq , &
rtDW . khdufyvkjm , & rtB . hcyznxmk0r [ 0 ] , & rtB . caboiln2oj , & rtB .
nt4wgp4qph , & rtB . pfhqhr1gju , & rtB . gmumll0z2v , & rtB . a4yf2mjntq [ 0
] , & rtB . bihr3dlknt , & rtP . DataStoreMemory_InitialValue [ 0 ] , & rtP .
DataStoreMemory1_InitialValue , & rtP . doVis_Value , & rtP .
hokuyoPort_Value , & rtP . isTeleOp_Value , & rtP . pozyxPort_Value , & rtP .
turnConst_Value , & rtP . vehicleRad_Value , & rtP . velConst_Value , & rtP .
Gain_Gain , & rtP . limit [ 0 ] , & rtP . mapDim [ 0 ] , & rtP . mode , & rtP
. sObs [ 0 ] , & rtP . verticies [ 0 ] , & rtP . visualObj [ 0 ] , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , SS_UINT8 , 0 , 0 }
} ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 ,
0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0
} , { rtwCAPI_MATRIX_COL_MAJOR_ND , 10 , 3 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR_ND , 13 , 3 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND ,
16 , 3 , 0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 , 1 , 2 ,
1 , 6165 , 20 , 2 , 186 , 3 , 16 , 3 , 5 , 37 , 58 , 2 , 194 , 3 , 2 } ;
static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 13 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 10 , rtModelParameters , 6 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 271903700U , 3622760240U
, 3832336147U , 1235955264U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * anav_real_GetCAPIStaticMap ( void ) { return
& mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void anav_real_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void anav_real_host_InitializeDataMapInfo ( anav_real_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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
