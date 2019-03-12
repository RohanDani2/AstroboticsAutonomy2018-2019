#include "__cf_anav_real.h"
#ifndef RTW_HEADER_anav_real_h_
#define RTW_HEADER_anav_real_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "rtw_modelmap.h"
#ifndef anav_real_COMMON_INCLUDES_
#define anav_real_COMMON_INCLUDES_
#include <stdlib.h>
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
#include "anav_real_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME anav_real
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (9) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
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
typedef struct { real_T dxvsehi3eh [ 6156 ] ; real_T kmt24znwlx [ 2534 ] ;
real_T jzuawnezs0 [ 2322 ] ; real_T amu1d5bdwh [ 2162 ] ; real_T esfappxofl [
2052 ] ; real_T cdr5byzwej [ 1000 ] ; real_T pjlwnmofjs [ 1000 ] ; real_T
a4yf2mjntq [ 40 ] ; real_T bihr3dlknt ; real_T caboiln2oj ; real_T nt4wgp4qph
; real_T pfhqhr1gju ; real_T gmumll0z2v ; real_T hcyznxmk0r [ 6165 ] ; real_T
nmf2aoyssm ; real_T h1obb2nc31 [ 2 ] ; } B ; typedef struct { real_T
irqtpqf4mz [ 2 ] ; real_T pgjmsvvkae ; real_T mn4hlzccjn [ 2052 ] ; real_T
gkteqaogoh [ 2 ] ; real_T jrjyklivwq [ 2 ] ; real_T mnkxa541wi [ 2 ] ; real_T
pfra4oyvtl [ 2 ] ; real_T dhr4mxnvua ; real_T likqxler4y ; real_T nxxhtxi2pq
; real_T gplbfb5auy ; int32_T kakhnbjo3s ; uint8_T ouzu4kamsj ; uint8_T
gesvnspaab ; uint8_T j1l4gcbtpq ; uint8_T khdufyvkjm ; boolean_T fgjqzsh1cz ;
} DW ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T limit [ 558 ] ; real_T mapDim [ 2 ] ; real_T mode ; real_T sObs [
240 ] ; real_T verticies [ 4292 ] ; real_T visualObj [ 1164 ] ; real_T
hokuyoPort_Value ; real_T pozyxPort_Value ; real_T vehicleRad_Value ; real_T
Gain_Gain ; real_T velConst_Value ; real_T turnConst_Value ; real_T
isTeleOp_Value ; real_T doVis_Value ; real_T DataStoreMemory_InitialValue [ 2
] ; real_T DataStoreMemory1_InitialValue ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * anav_real_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
