#include "__cf_anav_real.h"
#include "rt_logging_mmi.h"
#include "anav_real_capi.h"
#include <math.h>
#include "anav_real.h"
#include "anav_real_private.h"
#include "anav_real_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.1 (R2018a) 06-Feb-2018" ; void
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
"slprj//raccel//anav_real//anav_real_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
#define be0hrt2btn ((uint8_T)3U)
#define c5miqm4t0o ((uint8_T)0U)
#define dlfdnyv1oi ((uint8_T)1U)
#define dvlswjras4 ((uint8_T)4U)
#define ezhxovdz0k ((uint8_T)4U)
#define fsgq5eu5gr ((uint8_T)3U)
#define glax4n3wtn ((uint8_T)2U)
#define htqygblbkw ((uint8_T)1U)
#define ie5c514xpt ((uint8_T)6U)
#define ky5isj23hv ((uint8_T)2U)
#define m5g52nnwqj ((uint8_T)1U)
#define mmtcsa0dos ((uint8_T)5U)
#define ms3whpqgva ((uint8_T)3U)
#define ow55tvtdru ((uint8_T)2U)
#define pn0a5mj0hw (-1)
#define pw32odyy51 ((uint8_T)4U)
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; static void pmqwaydwaa ( real_T b [ 2162 ] ) ; static void
pjnm0y2tj2 ( const real_T th [ 4 ] , const real_T r [ 4 ] , real_T x [ 4 ] ,
real_T y [ 4 ] ) ; static void h3qssivgk2 ( const real_T A [ 12 ] , real_T
B_p [ 12 ] ) ; static void avt4c5oukr ( const real_T a [ 240 ] , real_T b [
240 ] ) ; static void ompu40hmw2 ( const real_T points [ 240 ] , const real_T
cone [ 12 ] , real_T detected [ 80 ] ) ; static boolean_T dxa5iip3uk ( const
real_T x [ 80 ] ) ; static void pmqwaydwaac ( real_T varargin_1 , real_T
b_data [ ] , int32_T b_size [ 2 ] ) ; static void pkweif0o5v ( j10j441lav * *
pEmxArray , int32_T numDimensions ) ; static void bg4f1bvure ( j10j441lav *
emxArray , int32_T oldNumel ) ; static void likoamzwrl ( real_T y_data [ ] ,
int32_T y_size [ 2 ] ) ; static void f2qi2kns4m ( real_T x_data [ ] ) ;
static void i34aejfn50 ( real_T x_data [ ] ) ; static void jep4enklrj ( const
real_T A_data [ ] , real_T B_data [ ] , int32_T * B_size ) ; static void
mihyddqrv3 ( real_T x_data [ ] ) ; static void e3bbpejt4t ( const boolean_T x
[ 2534 ] , boolean_T y [ 1267 ] ) ; static void ezwc21kfgg ( mcksbdyopm * *
pEmxArray , int32_T numDimensions ) ; static void p1dkmzgym3 ( mcksbdyopm *
emxArray , int32_T oldNumel ) ; static void evlvzvt14y ( mcksbdyopm * *
pEmxArray ) ; static boolean_T gejattcw5r ( const j10j441lav * v , int32_T
idx1 , int32_T idx2 ) ; static void o50srltrxs ( mcksbdyopm * idx , const
j10j441lav * x , int32_T n ) ; static void npgz1yugad ( const j10j441lav * x
, mcksbdyopm * idx ) ; static void imrakosaxk ( j10j441lav * * pEmxArray ) ;
static void mwryfaeomi ( j10j441lav * y , const mcksbdyopm * idx ) ; static
void eor2uyq41x ( j10j441lav * y , j10j441lav * ndx ) ; static boolean_T
dspdmkiria ( const j10j441lav * b , int32_T k0 , int32_T k ) ; static void
ft4lwvewep ( const real_T points [ 2534 ] , real_T r , j10j441lav * inflated
) ; static void laq0qhn0ac ( gqxdbrx2bu * * pEmxArray , int32_T numDimensions
) ; static void ccljhojhzi ( gqxdbrx2bu * emxArray , int32_T oldNumel ) ;
static void n2k0x4li2y ( j10j441lav * x , const gqxdbrx2bu * idx ) ; static
void biqz5t5nns ( gqxdbrx2bu * * pEmxArray ) ; static void fs0o2m5z0x ( const
j10j441lav * x , const j10j441lav * y , real_T map [ 2052 ] ) ; static void
mimxo5upq1 ( const real_T grid [ 2052 ] , real_T list [ 6156 ] ) ; static
void pmqwaydwaa ( real_T b [ 2162 ] ) { int32_T ibmat ; int32_T jcol ;
int32_T itilerow ; for ( jcol = 0 ; jcol < 2 ; jcol ++ ) { ibmat = jcol *
1081 ; for ( itilerow = 0 ; itilerow < 1081 ; itilerow ++ ) { b [ ibmat +
itilerow ] = ( rtNaN ) ; } } } static void pjnm0y2tj2 ( const real_T th [ 4 ]
, const real_T r [ 4 ] , real_T x [ 4 ] , real_T y [ 4 ] ) { x [ 0 ] = r [ 0
] * muDoubleScalarCos ( th [ 0 ] ) ; y [ 0 ] = r [ 0 ] * muDoubleScalarSin (
th [ 0 ] ) ; x [ 1 ] = r [ 1 ] * muDoubleScalarCos ( th [ 1 ] ) ; y [ 1 ] = r
[ 1 ] * muDoubleScalarSin ( th [ 1 ] ) ; x [ 2 ] = r [ 2 ] *
muDoubleScalarCos ( th [ 2 ] ) ; y [ 2 ] = r [ 2 ] * muDoubleScalarSin ( th [
2 ] ) ; x [ 3 ] = r [ 3 ] * muDoubleScalarCos ( th [ 3 ] ) ; y [ 3 ] = r [ 3
] * muDoubleScalarSin ( th [ 3 ] ) ; } static void h3qssivgk2 ( const real_T
A [ 12 ] , real_T B_p [ 12 ] ) { int32_T i ; for ( i = 0 ; i < 4 ; i ++ ) {
B_p [ i ] = A [ 3 * i + 2 ] ; B_p [ i + 4 ] = A [ 3 * i + 1 ] ; B_p [ i + 8 ]
= A [ 3 * i ] ; } } static void avt4c5oukr ( const real_T a [ 240 ] , real_T
b [ 240 ] ) { int32_T k ; int32_T b_k ; int32_T c_k ; int8_T subsa_idx_0 ;
int8_T subsa_idx_1 ; int8_T subsa_idx_2 ; for ( k = 0 ; k < 5 ; k ++ ) {
subsa_idx_2 = ( int8_T ) ( k + 1 ) ; for ( b_k = 0 ; b_k < 3 ; b_k ++ ) {
subsa_idx_1 = ( int8_T ) ( b_k + 1 ) ; for ( c_k = 0 ; c_k < 16 ; c_k ++ ) {
subsa_idx_0 = ( int8_T ) ( c_k + 1 ) ; b [ ( ( subsa_idx_1 + 3 * (
subsa_idx_0 - 1 ) ) + 48 * ( subsa_idx_2 - 1 ) ) - 1 ] = a [ ( ( ( (
subsa_idx_1 - 1 ) << 4 ) + subsa_idx_0 ) + ( subsa_idx_2 - 1 ) * 48 ) - 1 ] ;
} } } } static void ompu40hmw2 ( const real_T points [ 240 ] , const real_T
cone [ 12 ] , real_T detected [ 80 ] ) { real_T d [ 240 ] ; int32_T j ;
boolean_T b_b [ 3 ] ; boolean_T y ; int32_T k ; boolean_T exitg1 ; memset ( &
d [ 0 ] , 0 , 240U * sizeof ( real_T ) ) ; for ( j = 0 ; j < 80 ; j ++ ) {
b_b [ 0 ] = muDoubleScalarIsNaN ( points [ j ] ) ; b_b [ 1 ] =
muDoubleScalarIsNaN ( points [ j + 80 ] ) ; b_b [ 2 ] = muDoubleScalarIsNaN (
points [ j + 160 ] ) ; y = false ; k = 0 ; exitg1 = false ; while ( ( !
exitg1 ) && ( k < 3 ) ) { if ( b_b [ k ] ) { y = true ; exitg1 = true ; }
else { k ++ ; } } if ( y ) { detected [ j ] = 0.0 ; } else { for ( k = 0 ; k
< 3 ; k ++ ) { d [ j + 80 * k ] = ( - ( cone [ k + 4 ] - cone [ k + 5 ] ) * (
points [ j ] - cone [ k + 1 ] ) + ( cone [ k ] - cone [ k + 1 ] ) * ( points
[ j + 80 ] - cone [ k + 5 ] ) ) + ( cone [ k + 8 ] - cone [ k + 9 ] ) * (
points [ j + 160 ] - cone [ k + 9 ] ) ; } if ( ( d [ j ] >= 0.0 ) && ( d [ 80
+ j ] >= 0.0 ) && ( d [ 160 + j ] >= 0.0 ) ) { detected [ j ] = 1.0 ; } else
{ detected [ j ] = 0.0 ; } } } } static boolean_T dxa5iip3uk ( const real_T x
[ 80 ] ) { boolean_T y ; int32_T k ; boolean_T exitg1 ; y = false ; k = 0 ;
exitg1 = false ; while ( ( ! exitg1 ) && ( k < 80 ) ) { if ( ! ( x [ k ] ==
0.0 ) ) { y = true ; exitg1 = true ; } else { k ++ ; } } return y ; } static
void pmqwaydwaac ( real_T varargin_1 , real_T b_data [ ] , int32_T b_size [ 2
] ) { int32_T ntilerows ; int32_T itilerow ; b_size [ 0 ] = ( int16_T ) (
int32_T ) varargin_1 ; b_size [ 1 ] = 2 ; ntilerows = ( int32_T ) varargin_1
; for ( itilerow = 1 ; itilerow <= ntilerows ; itilerow ++ ) { b_data [
itilerow - 1 ] = ( rtNaN ) ; } for ( itilerow = 1 ; itilerow <= ntilerows ;
itilerow ++ ) { b_data [ ( ntilerows + itilerow ) - 1 ] = ( rtNaN ) ; } }
static void pkweif0o5v ( j10j441lav * * pEmxArray , int32_T numDimensions ) {
j10j441lav * emxArray ; int32_T i ; * pEmxArray = ( j10j441lav * ) malloc (
sizeof ( j10j441lav ) ) ; emxArray = * pEmxArray ; emxArray -> data = (
real_T * ) NULL ; emxArray -> numDimensions = numDimensions ; emxArray ->
size = ( int32_T * ) malloc ( sizeof ( int32_T ) * numDimensions ) ; emxArray
-> allocatedSize = 0 ; emxArray -> canFreeData = true ; for ( i = 0 ; i <
numDimensions ; i ++ ) { emxArray -> size [ i ] = 0 ; } } static void
bg4f1bvure ( j10j441lav * emxArray , int32_T oldNumel ) { int32_T newNumel ;
int32_T i ; void * newData ; if ( oldNumel < 0 ) { oldNumel = 0 ; } newNumel
= 1 ; for ( i = 0 ; i < emxArray -> numDimensions ; i ++ ) { newNumel *=
emxArray -> size [ i ] ; } if ( newNumel > emxArray -> allocatedSize ) { i =
emxArray -> allocatedSize ; if ( i < 16 ) { i = 16 ; } while ( i < newNumel )
{ if ( i > 1073741823 ) { i = MAX_int32_T ; } else { i <<= 1 ; } } newData =
calloc ( ( uint32_T ) i , sizeof ( real_T ) ) ; if ( emxArray -> data != NULL
) { memcpy ( newData , ( void * ) emxArray -> data , sizeof ( real_T ) *
oldNumel ) ; if ( emxArray -> canFreeData ) { free ( ( void * ) emxArray ->
data ) ; } } emxArray -> data = ( real_T * ) newData ; emxArray ->
allocatedSize = i ; emxArray -> canFreeData = true ; } } static void
likoamzwrl ( real_T y_data [ ] , int32_T y_size [ 2 ] ) { int32_T k ; y_size
[ 0 ] = 1 ; y_size [ 1 ] = 500 ; y_data [ 499 ] = 6.2831853071795862 ; y_data
[ 0 ] = 0.0 ; for ( k = 0 ; k < 498 ; k ++ ) { y_data [ k + 1 ] = ( 1.0 + (
real_T ) k ) * 0.012591553721802777 ; } } static void f2qi2kns4m ( real_T
x_data [ ] ) { int32_T k ; for ( k = 0 ; k < 500 ; k ++ ) { x_data [ k ] =
muDoubleScalarCos ( x_data [ k ] ) ; } } static void i34aejfn50 ( real_T
x_data [ ] ) { int32_T k ; for ( k = 0 ; k < 500 ; k ++ ) { x_data [ k ] =
muDoubleScalarSin ( x_data [ k ] ) ; } } static void jep4enklrj ( const
real_T A_data [ ] , real_T B_data [ ] , int32_T * B_size ) { * B_size = 500 ;
memcpy ( & B_data [ 0 ] , & A_data [ 0 ] , 500U * sizeof ( real_T ) ) ; }
static void mihyddqrv3 ( real_T x_data [ ] ) { int32_T k ; for ( k = 0 ; k <
1000 ; k ++ ) { x_data [ k ] = muDoubleScalarRound ( x_data [ k ] ) ; } }
static void e3bbpejt4t ( const boolean_T x [ 2534 ] , boolean_T y [ 1267 ] )
{ int32_T i2 ; int32_T iy ; int32_T i1 ; int32_T j ; int32_T ix ; boolean_T
exitg1 ; memset ( & y [ 0 ] , 0 , 1267U * sizeof ( boolean_T ) ) ; iy = - 1 ;
i1 = 0 ; i2 = 1267 ; for ( j = 0 ; j < 1267 ; j ++ ) { i1 ++ ; i2 ++ ; iy ++
; ix = i1 ; exitg1 = false ; while ( ( ! exitg1 ) && ( ix <= i2 ) ) { if ( x
[ ix - 1 ] ) { y [ iy ] = true ; exitg1 = true ; } else { ix += 1267 ; } } }
} static void ezwc21kfgg ( mcksbdyopm * * pEmxArray , int32_T numDimensions )
{ mcksbdyopm * emxArray ; int32_T i ; * pEmxArray = ( mcksbdyopm * ) malloc (
sizeof ( mcksbdyopm ) ) ; emxArray = * pEmxArray ; emxArray -> data = (
int32_T * ) NULL ; emxArray -> numDimensions = numDimensions ; emxArray ->
size = ( int32_T * ) malloc ( sizeof ( int32_T ) * numDimensions ) ; emxArray
-> allocatedSize = 0 ; emxArray -> canFreeData = true ; for ( i = 0 ; i <
numDimensions ; i ++ ) { emxArray -> size [ i ] = 0 ; } } static void
p1dkmzgym3 ( mcksbdyopm * emxArray , int32_T oldNumel ) { int32_T newNumel ;
int32_T i ; void * newData ; if ( oldNumel < 0 ) { oldNumel = 0 ; } newNumel
= 1 ; for ( i = 0 ; i < emxArray -> numDimensions ; i ++ ) { newNumel *=
emxArray -> size [ i ] ; } if ( newNumel > emxArray -> allocatedSize ) { i =
emxArray -> allocatedSize ; if ( i < 16 ) { i = 16 ; } while ( i < newNumel )
{ if ( i > 1073741823 ) { i = MAX_int32_T ; } else { i <<= 1 ; } } newData =
calloc ( ( uint32_T ) i , sizeof ( int32_T ) ) ; if ( emxArray -> data !=
NULL ) { memcpy ( newData , ( void * ) emxArray -> data , sizeof ( int32_T )
* oldNumel ) ; if ( emxArray -> canFreeData ) { free ( ( void * ) emxArray ->
data ) ; } } emxArray -> data = ( int32_T * ) newData ; emxArray ->
allocatedSize = i ; emxArray -> canFreeData = true ; } } static void
evlvzvt14y ( mcksbdyopm * * pEmxArray ) { if ( * pEmxArray != ( mcksbdyopm *
) NULL ) { if ( ( ( * pEmxArray ) -> data != ( int32_T * ) NULL ) && ( *
pEmxArray ) -> canFreeData ) { free ( ( void * ) ( * pEmxArray ) -> data ) ;
} free ( ( void * ) ( * pEmxArray ) -> size ) ; free ( ( void * ) * pEmxArray
) ; * pEmxArray = ( mcksbdyopm * ) NULL ; } } static boolean_T gejattcw5r (
const j10j441lav * v , int32_T idx1 , int32_T idx2 ) { boolean_T p ; int32_T
k ; boolean_T exitg1 ; p = true ; k = 0 ; exitg1 = false ; while ( ( ! exitg1
) && ( k + 1 < 3 ) ) { if ( ( v -> data [ ( v -> size [ 0 ] * k + idx1 ) - 1
] == v -> data [ ( v -> size [ 0 ] * k + idx2 ) - 1 ] ) || (
muDoubleScalarIsNaN ( v -> data [ ( v -> size [ 0 ] * k + idx1 ) - 1 ] ) &&
muDoubleScalarIsNaN ( v -> data [ ( v -> size [ 0 ] * k + idx2 ) - 1 ] ) ) )
{ k ++ ; } else { if ( ( v -> data [ ( v -> size [ 0 ] * k + idx1 ) - 1 ] <=
v -> data [ ( v -> size [ 0 ] * k + idx2 ) - 1 ] ) || muDoubleScalarIsNaN ( v
-> data [ ( v -> size [ 0 ] * k + idx2 ) - 1 ] ) ) { } else { p = false ; }
exitg1 = true ; } } return p ; } static void o50srltrxs ( mcksbdyopm * idx ,
const j10j441lav * x , int32_T n ) { mcksbdyopm * iwork ; int32_T k ; int32_T
i ; int32_T i2 ; int32_T j ; int32_T pEnd ; int32_T p ; int32_T q ; int32_T
qEnd ; int32_T kEnd ; ezwc21kfgg ( & iwork , 1 ) ; i = iwork -> size [ 0 ] ;
iwork -> size [ 0 ] = idx -> size [ 0 ] ; p1dkmzgym3 ( iwork , i ) ; for ( i
= 1 ; i <= n - 1 ; i += 2 ) { if ( gejattcw5r ( x , i , i + 1 ) ) { idx ->
data [ i - 1 ] = i ; idx -> data [ i ] = i + 1 ; } else { idx -> data [ i - 1
] = i + 1 ; idx -> data [ i ] = i ; } } if ( ( n & 1U ) != 0U ) { idx -> data
[ n - 1 ] = n ; } i = 2 ; while ( i < n ) { i2 = i << 1 ; j = 1 ; pEnd = 1 +
i ; while ( pEnd < n + 1 ) { p = j ; q = pEnd ; qEnd = j + i2 ; if ( qEnd > n
+ 1 ) { qEnd = n + 1 ; } k = 0 ; kEnd = qEnd - j ; while ( k + 1 <= kEnd ) {
if ( gejattcw5r ( x , idx -> data [ p - 1 ] , idx -> data [ q - 1 ] ) ) {
iwork -> data [ k ] = idx -> data [ p - 1 ] ; p ++ ; if ( p == pEnd ) { while
( q < qEnd ) { k ++ ; iwork -> data [ k ] = idx -> data [ q - 1 ] ; q ++ ; }
} } else { iwork -> data [ k ] = idx -> data [ q - 1 ] ; q ++ ; if ( q ==
qEnd ) { while ( p < pEnd ) { k ++ ; iwork -> data [ k ] = idx -> data [ p -
1 ] ; p ++ ; } } } k ++ ; } for ( pEnd = 0 ; pEnd < kEnd ; pEnd ++ ) { idx ->
data [ ( j + pEnd ) - 1 ] = iwork -> data [ pEnd ] ; } j = qEnd ; pEnd = qEnd
+ i ; } i = i2 ; } evlvzvt14y ( & iwork ) ; } static void npgz1yugad ( const
j10j441lav * x , mcksbdyopm * idx ) { int32_T loop_ub ; int32_T i ; i = idx
-> size [ 0 ] ; idx -> size [ 0 ] = x -> size [ 0 ] ; p1dkmzgym3 ( idx , i )
; loop_ub = x -> size [ 0 ] ; for ( i = 0 ; i < loop_ub ; i ++ ) { idx ->
data [ i ] = 0 ; } o50srltrxs ( idx , x , x -> size [ 0 ] ) ; } static void
imrakosaxk ( j10j441lav * * pEmxArray ) { if ( * pEmxArray != ( j10j441lav *
) NULL ) { if ( ( ( * pEmxArray ) -> data != ( real_T * ) NULL ) && ( *
pEmxArray ) -> canFreeData ) { free ( ( void * ) ( * pEmxArray ) -> data ) ;
} free ( ( void * ) ( * pEmxArray ) -> size ) ; free ( ( void * ) * pEmxArray
) ; * pEmxArray = ( j10j441lav * ) NULL ; } } static void mwryfaeomi (
j10j441lav * y , const mcksbdyopm * idx ) { int32_T m ; j10j441lav * ycol ;
int32_T tmp ; int32_T y_idx_0 ; pkweif0o5v ( & ycol , 1 ) ; m = y -> size [ 0
] ; y_idx_0 = y -> size [ 0 ] ; tmp = ycol -> size [ 0 ] ; ycol -> size [ 0 ]
= y_idx_0 ; bg4f1bvure ( ycol , tmp ) ; for ( y_idx_0 = 0 ; y_idx_0 < m ;
y_idx_0 ++ ) { ycol -> data [ y_idx_0 ] = y -> data [ idx -> data [ y_idx_0 ]
- 1 ] ; } for ( y_idx_0 = 0 ; y_idx_0 < m ; y_idx_0 ++ ) { y -> data [
y_idx_0 ] = ycol -> data [ y_idx_0 ] ; } for ( y_idx_0 = 0 ; y_idx_0 < m ;
y_idx_0 ++ ) { ycol -> data [ y_idx_0 ] = y -> data [ ( idx -> data [ y_idx_0
] + y -> size [ 0 ] ) - 1 ] ; } for ( y_idx_0 = 0 ; y_idx_0 < m ; y_idx_0 ++
) { y -> data [ y_idx_0 + y -> size [ 0 ] ] = ycol -> data [ y_idx_0 ] ; }
imrakosaxk ( & ycol ) ; } static void eor2uyq41x ( j10j441lav * y ,
j10j441lav * ndx ) { mcksbdyopm * idx ; int32_T loop_ub ; int32_T i ;
ezwc21kfgg ( & idx , 1 ) ; npgz1yugad ( y , idx ) ; mwryfaeomi ( y , idx ) ;
i = ndx -> size [ 0 ] ; ndx -> size [ 0 ] = idx -> size [ 0 ] ; bg4f1bvure (
ndx , i ) ; loop_ub = idx -> size [ 0 ] ; for ( i = 0 ; i < loop_ub ; i ++ )
{ ndx -> data [ i ] = idx -> data [ i ] ; } evlvzvt14y ( & idx ) ; } static
boolean_T dspdmkiria ( const j10j441lav * b , int32_T k0 , int32_T k ) {
boolean_T p ; int32_T j ; real_T absxk ; int32_T exponent ; boolean_T exitg1
; p = false ; j = 0 ; exitg1 = false ; while ( ( ! exitg1 ) && ( j < 2 ) ) {
absxk = muDoubleScalarAbs ( b -> data [ ( b -> size [ 0 ] * j + k ) - 1 ] /
2.0 ) ; if ( ( ! muDoubleScalarIsInf ( absxk ) ) && ( ! muDoubleScalarIsNaN (
absxk ) ) ) { if ( absxk <= 2.2250738585072014E-308 ) { absxk =
4.94065645841247E-324 ; } else { frexp ( absxk , & exponent ) ; absxk = ldexp
( 1.0 , exponent - 53 ) ; } } else { absxk = ( rtNaN ) ; } if ( (
muDoubleScalarAbs ( b -> data [ ( b -> size [ 0 ] * j + k ) - 1 ] - b -> data
[ ( b -> size [ 0 ] * j + k0 ) - 1 ] ) < absxk ) || ( muDoubleScalarIsInf ( b
-> data [ ( b -> size [ 0 ] * j + k0 ) - 1 ] ) && muDoubleScalarIsInf ( b ->
data [ ( b -> size [ 0 ] * j + k ) - 1 ] ) && ( ( b -> data [ ( b -> size [ 0
] * j + k0 ) - 1 ] > 0.0 ) == ( b -> data [ ( b -> size [ 0 ] * j + k ) - 1 ]
> 0.0 ) ) ) ) { j ++ ; } else { p = true ; exitg1 = true ; } } return p ; }
static void ft4lwvewep ( const real_T points [ 2534 ] , real_T r , j10j441lav
* inflated ) { real_T theta_data [ 500 ] ; int32_T len ; boolean_T b [ 1267 ]
; j10j441lav * a ; int32_T khi ; int32_T k ; int32_T k0 ; real_T e_data [ 500
] ; boolean_T tmp [ 2534 ] ; real_T r_data [ 500 ] ; j10j441lav * inflated_p
; int32_T i ; int32_T theta_size [ 2 ] ; int32_T circle_size [ 2 ] ; int32_T
tmp_size ; j10j441lav * inflated_e ; likoamzwrl ( theta_data , theta_size ) ;
memcpy ( & e_data [ 0 ] , & theta_data [ 0 ] , 500U * sizeof ( real_T ) ) ;
f2qi2kns4m ( e_data ) ; i34aejfn50 ( theta_data ) ; for ( k = 0 ; k < 500 ; k
++ ) { r_data [ k ] = r * e_data [ k ] ; } jep4enklrj ( r_data , e_data , &
tmp_size ) ; for ( k = 0 ; k < 500 ; k ++ ) { r_data [ k ] = r * theta_data [
k ] ; rtB . cdr5byzwej [ k ] = e_data [ k ] ; } jep4enklrj ( r_data , e_data
, & tmp_size ) ; circle_size [ 0 ] = 500 ; memcpy ( & rtB . cdr5byzwej [ 500
] , & e_data [ 0 ] , 500U * sizeof ( real_T ) ) ; mihyddqrv3 ( rtB .
cdr5byzwej ) ; for ( k = 0 ; k < 2534 ; k ++ ) { tmp [ k ] = !
muDoubleScalarIsNaN ( points [ k ] ) ; } e3bbpejt4t ( tmp , b ) ; len = 0 ;
for ( khi = 0 ; khi < 1267 ; khi ++ ) { if ( b [ khi ] ) { len ++ ; } } k =
inflated -> size [ 0 ] * inflated -> size [ 1 ] ; inflated -> size [ 0 ] =
500 * len + len ; inflated -> size [ 1 ] = 2 ; bg4f1bvure ( inflated , k ) ;
khi = ( ( 500 * len + len ) << 1 ) - 1 ; for ( k = 0 ; k <= khi ; k ++ ) {
inflated -> data [ k ] = 0.0 ; } memset ( & rtB . pjlwnmofjs [ 0 ] , 0 ,
1000U * sizeof ( real_T ) ) ; for ( khi = 0 ; khi < len ; khi ++ ) { for ( k
= 0 ; k < 500 ; k ++ ) { rtB . pjlwnmofjs [ k ] = rtB . cdr5byzwej [ k ] +
points [ khi ] ; rtB . pjlwnmofjs [ k + 500 ] = rtB . cdr5byzwej [ k +
circle_size [ 0 ] ] + points [ 1267 + khi ] ; } k0 = 500 * khi + khi ;
inflated -> data [ k0 ] = points [ khi ] ; inflated -> data [ k0 + inflated
-> size [ 0 ] ] = points [ khi + 1267 ] ; k0 = ( 500 * khi + khi ) + 1 ; for
( k = 0 ; k < 2 ; k ++ ) { for ( i = 0 ; i < 500 ; i ++ ) { inflated -> data
[ ( i + k0 ) + inflated -> size [ 0 ] * k ] = rtB . pjlwnmofjs [ 500 * k + i
] ; } } } pkweif0o5v ( & a , 2 ) ; k = a -> size [ 0 ] * a -> size [ 1 ] ; a
-> size [ 0 ] = inflated -> size [ 0 ] ; a -> size [ 1 ] = 2 ; bg4f1bvure ( a
, k ) ; khi = inflated -> size [ 0 ] * inflated -> size [ 1 ] - 1 ; for ( k =
0 ; k <= khi ; k ++ ) { a -> data [ k ] = inflated -> data [ k ] ; } if (
inflated -> size [ 0 ] != 0 ) { pkweif0o5v ( & inflated_e , 1 ) ; eor2uyq41x
( inflated , inflated_e ) ; len = 0 ; khi = a -> size [ 0 ] ; k = 1 ;
imrakosaxk ( & inflated_e ) ; while ( k <= khi ) { k0 = k ; do { k ++ ; }
while ( ! ( ( k > khi ) || dspdmkiria ( inflated , k0 , k ) ) ) ; len ++ ;
inflated -> data [ len - 1 ] = inflated -> data [ k0 - 1 ] ; inflated -> data
[ ( len + inflated -> size [ 0 ] ) - 1 ] = inflated -> data [ ( k0 + inflated
-> size [ 0 ] ) - 1 ] ; } pkweif0o5v ( & inflated_p , 2 ) ; if ( 1 > len ) {
len = 0 ; } k = inflated_p -> size [ 0 ] * inflated_p -> size [ 1 ] ;
inflated_p -> size [ 0 ] = len ; inflated_p -> size [ 1 ] = 2 ; bg4f1bvure (
inflated_p , k ) ; for ( k = 0 ; k < len ; k ++ ) { inflated_p -> data [ k ]
= inflated -> data [ k ] ; } for ( k = 0 ; k < len ; k ++ ) { inflated_p ->
data [ k + inflated_p -> size [ 0 ] ] = inflated -> data [ k + inflated ->
size [ 0 ] ] ; } k = inflated -> size [ 0 ] * inflated -> size [ 1 ] ;
inflated -> size [ 0 ] = inflated_p -> size [ 0 ] ; inflated -> size [ 1 ] =
2 ; bg4f1bvure ( inflated , k ) ; khi = inflated_p -> size [ 0 ] ; for ( k =
0 ; k < khi ; k ++ ) { inflated -> data [ k ] = inflated_p -> data [ k ] ; }
khi = inflated_p -> size [ 0 ] ; for ( k = 0 ; k < khi ; k ++ ) { inflated ->
data [ k + inflated -> size [ 0 ] ] = inflated_p -> data [ k + inflated_p ->
size [ 0 ] ] ; } imrakosaxk ( & inflated_p ) ; } imrakosaxk ( & a ) ; }
static void laq0qhn0ac ( gqxdbrx2bu * * pEmxArray , int32_T numDimensions ) {
gqxdbrx2bu * emxArray ; int32_T i ; * pEmxArray = ( gqxdbrx2bu * ) malloc (
sizeof ( gqxdbrx2bu ) ) ; emxArray = * pEmxArray ; emxArray -> data = (
boolean_T * ) NULL ; emxArray -> numDimensions = numDimensions ; emxArray ->
size = ( int32_T * ) malloc ( sizeof ( int32_T ) * numDimensions ) ; emxArray
-> allocatedSize = 0 ; emxArray -> canFreeData = true ; for ( i = 0 ; i <
numDimensions ; i ++ ) { emxArray -> size [ i ] = 0 ; } } static void
ccljhojhzi ( gqxdbrx2bu * emxArray , int32_T oldNumel ) { int32_T newNumel ;
int32_T i ; void * newData ; if ( oldNumel < 0 ) { oldNumel = 0 ; } newNumel
= 1 ; for ( i = 0 ; i < emxArray -> numDimensions ; i ++ ) { newNumel *=
emxArray -> size [ i ] ; } if ( newNumel > emxArray -> allocatedSize ) { i =
emxArray -> allocatedSize ; if ( i < 16 ) { i = 16 ; } while ( i < newNumel )
{ if ( i > 1073741823 ) { i = MAX_int32_T ; } else { i <<= 1 ; } } newData =
calloc ( ( uint32_T ) i , sizeof ( boolean_T ) ) ; if ( emxArray -> data !=
NULL ) { memcpy ( newData , ( void * ) emxArray -> data , sizeof ( boolean_T
) * oldNumel ) ; if ( emxArray -> canFreeData ) { free ( ( void * ) emxArray
-> data ) ; } } emxArray -> data = ( boolean_T * ) newData ; emxArray ->
allocatedSize = i ; emxArray -> canFreeData = true ; } } static void
n2k0x4li2y ( j10j441lav * x , const gqxdbrx2bu * idx ) { int32_T nrowx ;
int32_T ncolx ; int32_T nrows ; int32_T i ; int32_T k ; int32_T j ;
j10j441lav * x_p ; nrowx = x -> size [ 0 ] ; ncolx = x -> size [ 1 ] ; nrows
= 0 ; for ( i = 1 ; i <= idx -> size [ 0 ] ; i ++ ) { nrows += idx -> data [
i - 1 ] ; } nrows = x -> size [ 0 ] - nrows ; i = 0 ; for ( k = 1 ; k <=
nrowx ; k ++ ) { if ( ( k > idx -> size [ 0 ] ) || ( ! idx -> data [ k - 1 ]
) ) { for ( j = 0 ; j < ncolx ; j ++ ) { x -> data [ i + x -> size [ 0 ] * j
] = x -> data [ ( x -> size [ 0 ] * j + k ) - 1 ] ; } i ++ ; } } pkweif0o5v (
& x_p , 2 ) ; if ( 1 > nrows ) { nrows = 0 ; } i = x -> size [ 1 ] ; nrowx =
x_p -> size [ 0 ] * x_p -> size [ 1 ] ; x_p -> size [ 0 ] = nrows ; x_p ->
size [ 1 ] = i ; bg4f1bvure ( x_p , nrowx ) ; for ( nrowx = 0 ; nrowx < i ;
nrowx ++ ) { for ( ncolx = 0 ; ncolx < nrows ; ncolx ++ ) { x_p -> data [
ncolx + x_p -> size [ 0 ] * nrowx ] = x -> data [ x -> size [ 0 ] * nrowx +
ncolx ] ; } } nrowx = x -> size [ 0 ] * x -> size [ 1 ] ; x -> size [ 0 ] =
x_p -> size [ 0 ] ; x -> size [ 1 ] = x_p -> size [ 1 ] ; bg4f1bvure ( x ,
nrowx ) ; nrows = x_p -> size [ 1 ] ; for ( nrowx = 0 ; nrowx < nrows ; nrowx
++ ) { i = x_p -> size [ 0 ] ; for ( ncolx = 0 ; ncolx < i ; ncolx ++ ) { x
-> data [ ncolx + x -> size [ 0 ] * nrowx ] = x_p -> data [ x_p -> size [ 0 ]
* nrowx + ncolx ] ; } } imrakosaxk ( & x_p ) ; } static void biqz5t5nns (
gqxdbrx2bu * * pEmxArray ) { if ( * pEmxArray != ( gqxdbrx2bu * ) NULL ) { if
( ( ( * pEmxArray ) -> data != ( boolean_T * ) NULL ) && ( * pEmxArray ) ->
canFreeData ) { free ( ( void * ) ( * pEmxArray ) -> data ) ; } free ( ( void
* ) ( * pEmxArray ) -> size ) ; free ( ( void * ) * pEmxArray ) ; * pEmxArray
= ( gqxdbrx2bu * ) NULL ; } } static void fs0o2m5z0x ( const j10j441lav * x ,
const j10j441lav * y , real_T map [ 2052 ] ) { int32_T l ; memset ( & map [ 0
] , 0 , 2052U * sizeof ( real_T ) ) ; for ( l = 0 ; l < x -> size [ 0 ] ; l
++ ) { map [ ( ( int32_T ) y -> data [ l ] + 36 * ( ( int32_T ) x -> data [ l
] - 1 ) ) - 1 ] = 1.0 ; } } static void mimxo5upq1 ( const real_T grid [ 2052
] , real_T list [ 6156 ] ) { real_T i ; int32_T r ; int32_T c ; int32_T i_p ;
memset ( & list [ 0 ] , 0 , 6156U * sizeof ( real_T ) ) ; i = 1.0 ; for ( r =
0 ; r < 36 ; r ++ ) { for ( c = 0 ; c < 57 ; c ++ ) { i_p = ( int32_T ) i - 1
; list [ i_p ] = 1.0 + ( real_T ) c ; list [ 2052 + i_p ] = 1.0 + ( real_T )
r ; list [ 4104 + i_p ] = grid [ 36 * c + r ] ; i ++ ; } } } void
MdlInitialize ( void ) { rtDW . kakhnbjo3s = pn0a5mj0hw ; rtDW . j1l4gcbtpq =
c5miqm4t0o ; rtDW . khdufyvkjm = c5miqm4t0o ; rtDW . ouzu4kamsj = 1U ; rtDW .
gesvnspaab = mmtcsa0dos ; memset ( & rtDW . mn4hlzccjn [ 0 ] , 0 , 2052U *
sizeof ( real_T ) ) ; } void MdlStart ( void ) { { void * * slioCatalogueAddr
= rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
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
externalInputIsInDatasetFormat ) { } } { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } rtDW . irqtpqf4mz [ 0 ] = rtP . DataStoreMemory_InitialValue [ 0 ]
; rtDW . irqtpqf4mz [ 1 ] = rtP . DataStoreMemory_InitialValue [ 1 ] ; rtDW .
pgjmsvvkae = rtP . DataStoreMemory1_InitialValue ; MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T theta ; real_T sObsList [ 240 ] ; real_T
detected [ 80 ] ; real_T detectedListTemp1_data [ 160 ] ; real_T x [ 4 ] ;
real_T y [ 4 ] ; int8_T b_data [ 80 ] ; int32_T trueCount ; int32_T i ;
static const real_T c [ 4 ] = { 0.0 , 6.0 , 6.0 , 0.0 } ; j10j441lav *
inflated ; j10j441lav * c_p ; real_T x_p ; real_T y_p ; boolean_T rEQ0 ;
real_T q ; real_T c_x ; real_T e0pbc0ztiw [ 12 ] ; j10j441lav * inflated_p ;
j10j441lav * inflated_e ; gqxdbrx2bu * inflated_i ; gqxdbrx2bu * inflated_m ;
gqxdbrx2bu * inflated_g ; gqxdbrx2bu * inflated_j ; real_T tmp [ 240 ] ;
real_T tmp_p [ 12 ] ; real_T d [ 4 ] ; int32_T loop_ub ; int32_T tmp_size [ 2
] ; real_T mvvlmdavbc_idx_0 ; real_T mvvlmdavbc_idx_1 ; int32_T b_size_idx_1
; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { mvvlmdavbc_idx_0 = 0.0 ;
mvvlmdavbc_idx_1 = 0.0 ; theta = 0.0 ; if ( ( rtP . mode == 1.0 ) || ( rtP .
mode == 2.0 ) ) { mvvlmdavbc_idx_0 = rtDW . irqtpqf4mz [ 0 ] ;
mvvlmdavbc_idx_1 = rtDW . irqtpqf4mz [ 1 ] ; theta = rtDW . pgjmsvvkae ; }
pmqwaydwaa ( rtB . amu1d5bdwh ) ; if ( rtP . mode == 1.0 ) { d [ 0 ] = theta
; d [ 1 ] = 0.78539816339744828 + theta ; d [ 2 ] = - 0.78539816339744828 +
theta ; d [ 3 ] = theta ; pjnm0y2tj2 ( d , c , x , y ) ; tmp_p [ 0 ] = 0.0 ;
tmp_p [ 1 ] = y [ 0 ] ; tmp_p [ 2 ] = x [ 0 ] ; tmp_p [ 3 ] = 0.0 ; tmp_p [ 4
] = y [ 1 ] ; tmp_p [ 5 ] = x [ 1 ] ; tmp_p [ 6 ] = 0.0 ; tmp_p [ 7 ] = y [ 2
] ; tmp_p [ 8 ] = x [ 2 ] ; tmp_p [ 9 ] = 0.0 ; tmp_p [ 10 ] = y [ 3 ] ;
tmp_p [ 11 ] = x [ 3 ] ; h3qssivgk2 ( tmp_p , e0pbc0ztiw ) ; e0pbc0ztiw [ 0 ]
+= mvvlmdavbc_idx_0 ; e0pbc0ztiw [ 4 ] += mvvlmdavbc_idx_1 ; e0pbc0ztiw [ 1 ]
+= mvvlmdavbc_idx_0 ; e0pbc0ztiw [ 5 ] += mvvlmdavbc_idx_1 ; e0pbc0ztiw [ 2 ]
+= mvvlmdavbc_idx_0 ; e0pbc0ztiw [ 6 ] += mvvlmdavbc_idx_1 ; e0pbc0ztiw [ 3 ]
+= mvvlmdavbc_idx_0 ; e0pbc0ztiw [ 7 ] += mvvlmdavbc_idx_1 ; avt4c5oukr ( rtP
. sObs , tmp ) ; for ( trueCount = 0 ; trueCount < 3 ; trueCount ++ ) { for (
b_size_idx_1 = 0 ; b_size_idx_1 < 80 ; b_size_idx_1 ++ ) { sObsList [
b_size_idx_1 + 80 * trueCount ] = tmp [ 3 * b_size_idx_1 + trueCount ] ; } }
ompu40hmw2 ( sObsList , e0pbc0ztiw , detected ) ; if ( dxa5iip3uk ( detected
) ) { trueCount = 0 ; for ( i = 0 ; i < 80 ; i ++ ) { if ( detected [ i ] ==
1.0 ) { trueCount ++ ; } } b_size_idx_1 = trueCount ; trueCount = 0 ; for ( i
= 0 ; i < 80 ; i ++ ) { if ( detected [ i ] == 1.0 ) { b_data [ trueCount ] =
( int8_T ) ( i + 1 ) ; trueCount ++ ; } } for ( trueCount = 0 ; trueCount <
b_size_idx_1 ; trueCount ++ ) { detectedListTemp1_data [ trueCount ] =
sObsList [ b_data [ trueCount ] - 1 ] ; } for ( trueCount = 0 ; trueCount <
b_size_idx_1 ; trueCount ++ ) { detectedListTemp1_data [ trueCount +
b_size_idx_1 ] = sObsList [ b_data [ trueCount ] + 79 ] ; } pmqwaydwaac (
1081.0 - ( real_T ) b_size_idx_1 , rtB . amu1d5bdwh , tmp_size ) ; i =
b_size_idx_1 + tmp_size [ 0 ] ; if ( 0 <= b_size_idx_1 - 1 ) { memcpy ( & rtB
. jzuawnezs0 [ 0 ] , & detectedListTemp1_data [ 0 ] , b_size_idx_1 * sizeof (
real_T ) ) ; } for ( trueCount = 0 ; trueCount < b_size_idx_1 ; trueCount ++
) { rtB . jzuawnezs0 [ trueCount + i ] = detectedListTemp1_data [ trueCount +
b_size_idx_1 ] ; } loop_ub = tmp_size [ 0 ] ; for ( trueCount = 0 ; trueCount
< loop_ub ; trueCount ++ ) { rtB . jzuawnezs0 [ trueCount + b_size_idx_1 ] =
rtB . amu1d5bdwh [ trueCount ] ; } loop_ub = tmp_size [ 0 ] ; for ( trueCount
= 0 ; trueCount < loop_ub ; trueCount ++ ) { rtB . jzuawnezs0 [ ( trueCount +
b_size_idx_1 ) + i ] = rtB . amu1d5bdwh [ trueCount + tmp_size [ 0 ] ] ; }
memcpy ( & rtB . amu1d5bdwh [ 0 ] , & rtB . jzuawnezs0 [ 0 ] , 2162U * sizeof
( real_T ) ) ; } } else { memset ( & e0pbc0ztiw [ 0 ] , 0 , 12U * sizeof (
real_T ) ) ; } switch ( rtDW . gesvnspaab ) { case m5g52nnwqj : switch ( rtDW
. j1l4gcbtpq ) { case htqygblbkw : rtB . h1obb2nc31 [ 0 ] = rtDW . mnkxa541wi
[ 0 ] ; rtB . h1obb2nc31 [ 1 ] = rtDW . mnkxa541wi [ 1 ] ; break ; case
glax4n3wtn : rtB . h1obb2nc31 [ 0 ] = rtDW . jrjyklivwq [ 0 ] ; rtB .
h1obb2nc31 [ 1 ] = rtDW . jrjyklivwq [ 1 ] ; break ; case fsgq5eu5gr : rtB .
h1obb2nc31 [ 0 ] = rtDW . pfra4oyvtl [ 0 ] ; rtB . h1obb2nc31 [ 1 ] = rtDW .
pfra4oyvtl [ 1 ] ; break ; default : rtB . h1obb2nc31 [ 0 ] = rtDW .
gkteqaogoh [ 0 ] ; rtB . h1obb2nc31 [ 1 ] = rtDW . gkteqaogoh [ 1 ] ; break ;
} break ; case ow55tvtdru : rtB . nmf2aoyssm = 0.0 ; break ; case be0hrt2btn
: rtB . nmf2aoyssm = 0.0 ; break ; case pw32odyy51 : switch ( rtDW .
khdufyvkjm ) { case dlfdnyv1oi : rtB . nmf2aoyssm = 2.0 ; break ; case
ky5isj23hv : rtB . nmf2aoyssm = 3.0 ; break ; case ms3whpqgva : rtB .
nmf2aoyssm = 4.0 ; break ; default : rtB . nmf2aoyssm = 1.0 ; break ; } break
; case mmtcsa0dos : rtDW . gkteqaogoh [ 0 ] = 50.0 ; rtB . h1obb2nc31 [ 0 ] =
rtDW . gkteqaogoh [ 0 ] ; rtDW . gkteqaogoh [ 1 ] = 30.0 ; rtB . h1obb2nc31 [
1 ] = rtDW . gkteqaogoh [ 1 ] ; break ; } pkweif0o5v ( & inflated , 2 ) ; if
( rtP . mode == 1.0 ) { for ( trueCount = 0 ; trueCount < 2 ; trueCount ++ )
{ memcpy ( & rtB . kmt24znwlx [ trueCount * 1267 ] , & rtP . limit [
trueCount * 186 ] , 186U * sizeof ( real_T ) ) ; memcpy ( & rtB . kmt24znwlx
[ trueCount * 1267 + 186 ] , & rtB . amu1d5bdwh [ trueCount * 1081 ] , 1081U
* sizeof ( real_T ) ) ; } pkweif0o5v ( & c_p , 2 ) ; ft4lwvewep ( rtB .
kmt24znwlx , rtP . vehicleRad_Value , c_p ) ; trueCount = inflated -> size [
0 ] * inflated -> size [ 1 ] ; inflated -> size [ 0 ] = c_p -> size [ 0 ] ;
inflated -> size [ 1 ] = 2 ; bg4f1bvure ( inflated , trueCount ) ; loop_ub =
c_p -> size [ 0 ] * c_p -> size [ 1 ] - 1 ; for ( trueCount = 0 ; trueCount
<= loop_ub ; trueCount ++ ) { inflated -> data [ trueCount ] = c_p -> data [
trueCount ] ; } imrakosaxk ( & c_p ) ; } else { trueCount = inflated -> size
[ 0 ] * inflated -> size [ 1 ] ; inflated -> size [ 0 ] = 1 ; inflated ->
size [ 1 ] = 1 ; bg4f1bvure ( inflated , trueCount ) ; inflated -> data [ 0 ]
= 0.0 ; } laq0qhn0ac ( & inflated_j , 1 ) ; loop_ub = inflated -> size [ 0 ]
; trueCount = inflated_j -> size [ 0 ] ; inflated_j -> size [ 0 ] = loop_ub ;
ccljhojhzi ( inflated_j , trueCount ) ; for ( trueCount = 0 ; trueCount <
loop_ub ; trueCount ++ ) { inflated_j -> data [ trueCount ] = ( inflated ->
data [ trueCount ] <= 0.0 ) ; } laq0qhn0ac ( & inflated_g , 1 ) ; n2k0x4li2y
( inflated , inflated_j ) ; loop_ub = inflated -> size [ 0 ] ; trueCount =
inflated_g -> size [ 0 ] ; inflated_g -> size [ 0 ] = loop_ub ; ccljhojhzi (
inflated_g , trueCount ) ; biqz5t5nns ( & inflated_j ) ; for ( trueCount = 0
; trueCount < loop_ub ; trueCount ++ ) { inflated_g -> data [ trueCount ] = (
inflated -> data [ trueCount ] >= 58.0 ) ; } laq0qhn0ac ( & inflated_m , 1 )
; n2k0x4li2y ( inflated , inflated_g ) ; loop_ub = inflated -> size [ 0 ] ;
trueCount = inflated_m -> size [ 0 ] ; inflated_m -> size [ 0 ] = loop_ub ;
ccljhojhzi ( inflated_m , trueCount ) ; biqz5t5nns ( & inflated_g ) ; for (
trueCount = 0 ; trueCount < loop_ub ; trueCount ++ ) { inflated_m -> data [
trueCount ] = ( inflated -> data [ trueCount + inflated -> size [ 0 ] ] <=
0.0 ) ; } laq0qhn0ac ( & inflated_i , 1 ) ; n2k0x4li2y ( inflated ,
inflated_m ) ; loop_ub = inflated -> size [ 0 ] ; trueCount = inflated_i ->
size [ 0 ] ; inflated_i -> size [ 0 ] = loop_ub ; ccljhojhzi ( inflated_i ,
trueCount ) ; biqz5t5nns ( & inflated_m ) ; for ( trueCount = 0 ; trueCount <
loop_ub ; trueCount ++ ) { inflated_i -> data [ trueCount ] = ( inflated ->
data [ trueCount + inflated -> size [ 0 ] ] >= 37.0 ) ; } pkweif0o5v ( &
inflated_p , 1 ) ; n2k0x4li2y ( inflated , inflated_i ) ; loop_ub = inflated
-> size [ 0 ] ; trueCount = inflated_p -> size [ 0 ] ; inflated_p -> size [ 0
] = loop_ub ; bg4f1bvure ( inflated_p , trueCount ) ; biqz5t5nns ( &
inflated_i ) ; for ( trueCount = 0 ; trueCount < loop_ub ; trueCount ++ ) {
inflated_p -> data [ trueCount ] = inflated -> data [ trueCount ] ; }
pkweif0o5v ( & inflated_e , 1 ) ; loop_ub = inflated -> size [ 0 ] ;
trueCount = inflated_e -> size [ 0 ] ; inflated_e -> size [ 0 ] = loop_ub ;
bg4f1bvure ( inflated_e , trueCount ) ; for ( trueCount = 0 ; trueCount <
loop_ub ; trueCount ++ ) { inflated_e -> data [ trueCount ] = inflated ->
data [ trueCount + inflated -> size [ 0 ] ] ; } imrakosaxk ( & inflated ) ;
fs0o2m5z0x ( inflated_p , inflated_e , rtB . esfappxofl ) ; imrakosaxk ( &
inflated_e ) ; imrakosaxk ( & inflated_p ) ; for ( trueCount = 0 ; trueCount
< 2052 ; trueCount ++ ) { rtDW . mn4hlzccjn [ trueCount ] = 0.5 * rtDW .
mn4hlzccjn [ trueCount ] + 0.5 * rtB . esfappxofl [ trueCount ] ; }
mimxo5upq1 ( rtDW . mn4hlzccjn , rtB . dxvsehi3eh ) ; rtB . hcyznxmk0r [ 0 ]
= 2052.0 ; rtB . hcyznxmk0r [ 1 ] = 0.0 ; rtB . hcyznxmk0r [ 2 ] = 0.0 ; rtB
. hcyznxmk0r [ 5 ] = 0.0 ; rtB . hcyznxmk0r [ 3 ] = mvvlmdavbc_idx_0 ; rtB .
hcyznxmk0r [ 6 ] = rtB . h1obb2nc31 [ 0 ] ; rtB . hcyznxmk0r [ 4 ] =
mvvlmdavbc_idx_1 ; rtB . hcyznxmk0r [ 7 ] = rtB . h1obb2nc31 [ 1 ] ; rtB .
hcyznxmk0r [ 8 ] = 0.0 ; for ( trueCount = 0 ; trueCount < 2052 ; trueCount
++ ) { rtB . hcyznxmk0r [ 3 * ( trueCount + 3 ) ] = rtB . dxvsehi3eh [
trueCount ] ; rtB . hcyznxmk0r [ 1 + 3 * ( trueCount + 3 ) ] = rtB .
dxvsehi3eh [ trueCount + 2052 ] ; rtB . hcyznxmk0r [ 2 + 3 * ( trueCount + 3
) ] = rtB . dxvsehi3eh [ trueCount + 4104 ] ; } { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; } x_p = rtB .
a4yf2mjntq [ 4 ] - mvvlmdavbc_idx_0 ; y_p = rtB . a4yf2mjntq [ 24 ] -
mvvlmdavbc_idx_1 ; theta = - ( muDoubleScalarAtan ( ( rtB . a4yf2mjntq [ 24 ]
- mvvlmdavbc_idx_1 ) / ( rtB . a4yf2mjntq [ 4 ] - mvvlmdavbc_idx_0 ) ) -
theta ) ; c_x = theta ; if ( ( ! muDoubleScalarIsInf ( theta ) ) && ( !
muDoubleScalarIsNaN ( theta ) ) ) { if ( theta == 0.0 ) { theta = 0.0 ; }
else { theta = muDoubleScalarRem ( theta , 6.2831853071795862 ) ; rEQ0 = (
theta == 0.0 ) ; if ( ! rEQ0 ) { q = muDoubleScalarAbs ( c_x /
6.2831853071795862 ) ; rEQ0 = ( muDoubleScalarAbs ( q - muDoubleScalarFloor (
q + 0.5 ) ) <= 2.2204460492503131E-16 * q ) ; } if ( rEQ0 ) { theta = 0.0 ; }
else { if ( c_x < 0.0 ) { theta += 6.2831853071795862 ; } } } } else { theta
= ( rtNaN ) ; } if ( theta >= 3.1415926535897931 ) { theta -=
6.2831853071795862 ; } c_x = rtB . h1obb2nc31 [ 0 ] - mvvlmdavbc_idx_0 ; q =
rtB . h1obb2nc31 [ 1 ] - mvvlmdavbc_idx_1 ; rtB . gmumll0z2v = 0.0 ; if ( (
rtB . a4yf2mjntq [ 4 ] >= mvvlmdavbc_idx_0 ) && ( rtB . a4yf2mjntq [ 24 ] >=
mvvlmdavbc_idx_1 ) ) { rtB . gmumll0z2v = 1.0 ; } else if ( ( rtB .
a4yf2mjntq [ 4 ] < mvvlmdavbc_idx_0 ) && ( rtB . a4yf2mjntq [ 24 ] >=
mvvlmdavbc_idx_1 ) ) { rtB . gmumll0z2v = 2.0 ; } else if ( ( rtB .
a4yf2mjntq [ 4 ] < mvvlmdavbc_idx_0 ) && ( rtB . a4yf2mjntq [ 24 ] <
mvvlmdavbc_idx_1 ) ) { rtB . gmumll0z2v = 3.0 ; } else { if ( ( rtB .
a4yf2mjntq [ 4 ] >= mvvlmdavbc_idx_0 ) && ( rtB . a4yf2mjntq [ 24 ] <
mvvlmdavbc_idx_1 ) ) { rtB . gmumll0z2v = 4.0 ; } } rtB . caboiln2oj =
muDoubleScalarSqrt ( c_x * c_x + q * q ) ; rtB . nt4wgp4qph =
muDoubleScalarSqrt ( x_p * x_p + y_p * y_p ) ; rtB . pfhqhr1gju = theta ; rtB
. bihr3dlknt = rtP . Gain_Gain * rtB . pfhqhr1gju ; if ( ( rtP . mode == 1.0
) && ( ! ( rtB . nmf2aoyssm == 0.0 ) ) ) { if ( rtB . nmf2aoyssm == 1.0 ) {
rtDW . irqtpqf4mz [ 0 ] += rtP . velConst_Value * muDoubleScalarCos ( rtDW .
pgjmsvvkae ) ; rtDW . irqtpqf4mz [ 1 ] += rtP . velConst_Value *
muDoubleScalarSin ( rtDW . pgjmsvvkae ) ; } else if ( rtB . nmf2aoyssm == 2.0
) { rtDW . irqtpqf4mz [ 0 ] -= rtP . velConst_Value * muDoubleScalarCos (
rtDW . pgjmsvvkae ) ; rtDW . irqtpqf4mz [ 1 ] -= rtP . velConst_Value *
muDoubleScalarSin ( rtDW . pgjmsvvkae ) ; } else if ( rtB . nmf2aoyssm == 3.0
) { rtDW . pgjmsvvkae += rtP . turnConst_Value ; } else { if ( rtB .
nmf2aoyssm == 4.0 ) { rtDW . pgjmsvvkae -= rtP . turnConst_Value ; } } } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { boolean_T guard1
= false ; boolean_T guard2 = false ; boolean_T guard3 = false ; boolean_T
guard4 = false ; boolean_T guard5 = false ; boolean_T guard6 = false ;
boolean_T guard7 = false ; boolean_T guard8 = false ; boolean_T guard9 =
false ; boolean_T guard10 = false ; boolean_T guard11 = false ; boolean_T
guard12 = false ; boolean_T guard13 = false ; boolean_T guard14 = false ;
boolean_T guard15 = false ; boolean_T guard16 = false ; boolean_T guard17 =
false ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { rtDW . kakhnbjo3s = pn0a5mj0hw
; switch ( rtDW . gesvnspaab ) { case m5g52nnwqj : switch ( rtDW . j1l4gcbtpq
) { case htqygblbkw : rtB . h1obb2nc31 [ 0 ] = rtDW . mnkxa541wi [ 0 ] ; rtB
. h1obb2nc31 [ 1 ] = rtDW . mnkxa541wi [ 1 ] ; rtDW . dhr4mxnvua = rtDW .
nxxhtxi2pq ; break ; case glax4n3wtn : rtB . h1obb2nc31 [ 0 ] = rtDW .
jrjyklivwq [ 0 ] ; rtB . h1obb2nc31 [ 1 ] = rtDW . jrjyklivwq [ 1 ] ; rtDW .
dhr4mxnvua = rtDW . likqxler4y ; break ; case fsgq5eu5gr : rtB . h1obb2nc31 [
0 ] = rtDW . pfra4oyvtl [ 0 ] ; rtB . h1obb2nc31 [ 1 ] = rtDW . pfra4oyvtl [
1 ] ; rtDW . dhr4mxnvua = rtDW . likqxler4y ; break ; default : rtB .
h1obb2nc31 [ 0 ] = rtDW . gkteqaogoh [ 0 ] ; rtB . h1obb2nc31 [ 1 ] = rtDW .
gkteqaogoh [ 1 ] ; rtDW . dhr4mxnvua = rtDW . likqxler4y ; break ; } break ;
case ow55tvtdru : case pw32odyy51 : break ; case be0hrt2btn : rtDW .
gplbfb5auy ++ ; break ; case mmtcsa0dos : rtDW . likqxler4y = 0.0 ; rtDW .
nxxhtxi2pq = 3.1415926535897931 ; rtDW . gplbfb5auy = 1.0 ; rtDW . dhr4mxnvua
= rtDW . likqxler4y ; rtDW . gkteqaogoh [ 0 ] = 50.0 ; rtDW . jrjyklivwq [ 0
] = 7.0 ; rtDW . pfra4oyvtl [ 0 ] = 7.0 ; rtDW . mnkxa541wi [ 0 ] = 7.0 ; rtB
. h1obb2nc31 [ 0 ] = rtDW . gkteqaogoh [ 0 ] ; rtDW . gkteqaogoh [ 1 ] = 30.0
; rtDW . jrjyklivwq [ 1 ] = 15.0 ; rtDW . pfra4oyvtl [ 1 ] = 14.0 ; rtDW .
mnkxa541wi [ 1 ] = 7.0 ; rtB . h1obb2nc31 [ 1 ] = rtDW . gkteqaogoh [ 1 ] ;
break ; } guard1 = false ; guard2 = false ; guard3 = false ; guard4 = false ;
guard5 = false ; guard6 = false ; guard7 = false ; guard8 = false ; guard9 =
false ; guard10 = false ; guard11 = false ; guard12 = false ; guard13 = false
; guard14 = false ; guard15 = false ; guard16 = false ; guard17 = false ;
switch ( rtDW . gesvnspaab ) { case m5g52nnwqj : switch ( rtDW . j1l4gcbtpq )
{ case htqygblbkw : if ( ( ( rtDW . dhr4mxnvua == rtDW . likqxler4y ) && ( (
rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) || ( ( rtDW .
dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB .
gmumll0z2v == 3.0 ) ) ) ) { if ( rtB . pfhqhr1gju >= 0.0 ) { guard3 = true ;
} else if ( rtB . pfhqhr1gju < 0.0 ) { guard4 = true ; } else { guard12 =
true ; } } else { guard12 = true ; } break ; case glax4n3wtn : if ( ( ( rtDW
. dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB
. gmumll0z2v == 4.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) &&
( ( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) ) { if ( rtB
. pfhqhr1gju >= 0.0 ) { guard5 = true ; } else if ( rtB . pfhqhr1gju < 0.0 )
{ guard6 = true ; } else { guard13 = true ; } } else { guard13 = true ; }
break ; case fsgq5eu5gr : if ( ( ( rtDW . dhr4mxnvua == rtDW . likqxler4y )
&& ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) || ( (
rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB . gmumll0z2v == 2.0 ) ||
( rtB . gmumll0z2v == 3.0 ) ) ) ) { if ( rtB . pfhqhr1gju >= 0.0 ) { guard7 =
true ; } else if ( rtB . pfhqhr1gju < 0.0 ) { guard8 = true ; } else {
guard14 = true ; } } else { guard14 = true ; } break ; default : if ( ( (
rtDW . dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 ) ||
( rtB . gmumll0z2v == 4.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq
) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) ) { if
( rtB . pfhqhr1gju >= 0.0 ) { guard1 = true ; } else if ( rtB . pfhqhr1gju <
0.0 ) { guard2 = true ; } else { guard11 = true ; } } else { guard11 = true ;
} break ; } break ; case ow55tvtdru : break ; case be0hrt2btn : if ( rtDW .
gplbfb5auy > 12.0 ) { rtDW . gesvnspaab = ow55tvtdru ; } else if ( rtB .
h1obb2nc31 [ 1 ] == rtDW . gkteqaogoh [ 1 ] ) { rtDW . gesvnspaab =
m5g52nnwqj ; rtDW . j1l4gcbtpq = glax4n3wtn ; } else if ( rtB . h1obb2nc31 [
1 ] == rtDW . jrjyklivwq [ 1 ] ) { rtDW . gesvnspaab = m5g52nnwqj ; rtDW .
j1l4gcbtpq = htqygblbkw ; } else if ( rtB . h1obb2nc31 [ 1 ] == rtDW .
pfra4oyvtl [ 1 ] ) { rtDW . gesvnspaab = m5g52nnwqj ; rtDW . j1l4gcbtpq =
dvlswjras4 ; } else { if ( rtB . h1obb2nc31 [ 1 ] == rtDW . mnkxa541wi [ 1 ]
) { rtDW . gesvnspaab = m5g52nnwqj ; rtDW . j1l4gcbtpq = fsgq5eu5gr ; } }
break ; case pw32odyy51 : switch ( rtDW . khdufyvkjm ) { case dlfdnyv1oi : if
( rtB . nt4wgp4qph <= 1.0 ) { rtDW . khdufyvkjm = c5miqm4t0o ; rtDW .
gesvnspaab = be0hrt2btn ; } else if ( ( ( ( ( rtDW . dhr4mxnvua == rtDW .
likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 )
) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB . gmumll0z2v
== 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) && ( ( ( rtB . pfhqhr1gju <
3.1415926535897931 ) && ( rtB . pfhqhr1gju > 3.1170489609836229 ) ) || ( (
rtB . pfhqhr1gju > - 3.1415926535897931 ) && ( rtB . pfhqhr1gju < -
3.1170489609836229 ) ) ) ) || ( ( ( ( rtDW . dhr4mxnvua == rtDW . likqxler4y
) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) || ( (
rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB . gmumll0z2v == 2.0 ) ||
( rtB . gmumll0z2v == 3.0 ) ) ) ) && ( ( rtB . pfhqhr1gju > -
0.024543692606170259 ) && ( rtB . pfhqhr1gju < 0.024543692606170259 ) ) ) ) {
rtDW . khdufyvkjm = c5miqm4t0o ; rtDW . gesvnspaab = ie5c514xpt ; } else if (
( ( rtDW . dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 )
|| ( rtB . gmumll0z2v == 4.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW .
nxxhtxi2pq ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 )
) ) ) { if ( rtB . pfhqhr1gju >= 0.0 ) { rtDW . khdufyvkjm = ms3whpqgva ; }
else if ( rtB . pfhqhr1gju < 0.0 ) { rtDW . khdufyvkjm = ky5isj23hv ; } else
{ guard16 = true ; } } else { guard16 = true ; } break ; case ky5isj23hv : if
( ( ( ( ( rtDW . dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v ==
2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW .
nxxhtxi2pq ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 )
) ) ) && ( ( ( rtB . pfhqhr1gju < 3.1415926535897931 ) && ( rtB . pfhqhr1gju
> 3.1170489609836229 ) ) || ( ( rtB . pfhqhr1gju > - 3.1415926535897931 ) &&
( rtB . pfhqhr1gju < - 3.1170489609836229 ) ) ) ) || ( ( ( ( rtDW .
dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB .
gmumll0z2v == 4.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && (
( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) ) && ( ( rtB .
pfhqhr1gju > - 0.024543692606170259 ) && ( rtB . pfhqhr1gju <
0.024543692606170259 ) ) ) ) { rtDW . khdufyvkjm = c5miqm4t0o ; rtDW .
gesvnspaab = ie5c514xpt ; } break ; case ms3whpqgva : if ( ( ( ( ( rtDW .
dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB .
gmumll0z2v == 3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && (
( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) && ( ( ( rtB
. pfhqhr1gju < 3.1415926535897931 ) && ( rtB . pfhqhr1gju >
3.1170489609836229 ) ) || ( ( rtB . pfhqhr1gju > - 3.1415926535897931 ) && (
rtB . pfhqhr1gju < - 3.1170489609836229 ) ) ) ) || ( ( ( ( rtDW . dhr4mxnvua
== rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v
== 4.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB .
gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) ) && ( ( rtB .
pfhqhr1gju > - 0.024543692606170259 ) && ( rtB . pfhqhr1gju <
0.024543692606170259 ) ) ) ) { rtDW . khdufyvkjm = c5miqm4t0o ; rtDW .
gesvnspaab = ie5c514xpt ; } break ; default : if ( rtB . nt4wgp4qph <= 1.0 )
{ rtDW . khdufyvkjm = c5miqm4t0o ; rtDW . gesvnspaab = be0hrt2btn ; } else if
( ( ( ( ( rtDW . dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v ==
2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW .
nxxhtxi2pq ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 )
) ) ) && ( ( ( rtB . pfhqhr1gju < 3.1415926535897931 ) && ( rtB . pfhqhr1gju
> 3.1170489609836229 ) ) || ( ( rtB . pfhqhr1gju > - 3.1415926535897931 ) &&
( rtB . pfhqhr1gju < - 3.1170489609836229 ) ) ) ) || ( ( ( ( rtDW .
dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB .
gmumll0z2v == 4.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && (
( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) ) && ( ( rtB .
pfhqhr1gju > - 0.024543692606170259 ) && ( rtB . pfhqhr1gju <
0.024543692606170259 ) ) ) ) { rtDW . khdufyvkjm = c5miqm4t0o ; rtDW .
gesvnspaab = ie5c514xpt ; } else if ( ( ( rtDW . dhr4mxnvua == rtDW .
likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 )
) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB . gmumll0z2v
== 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) ) { if ( rtB . pfhqhr1gju >= 0.0
) { rtDW . khdufyvkjm = ms3whpqgva ; } else if ( rtB . pfhqhr1gju < 0.0 ) {
rtDW . khdufyvkjm = ky5isj23hv ; } else { guard15 = true ; } } else { guard15
= true ; } break ; } break ; case mmtcsa0dos : if ( ( ( rtDW . dhr4mxnvua ==
rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v ==
4.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB .
gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) ) { if ( rtB .
pfhqhr1gju >= 0.0 ) { guard9 = true ; } else if ( rtB . pfhqhr1gju < 0.0 ) {
guard10 = true ; } else { guard17 = true ; } } else { guard17 = true ; }
break ; default : if ( rtDW . dhr4mxnvua == rtDW . likqxler4y ) { rtDW .
gesvnspaab = pw32odyy51 ; rtDW . khdufyvkjm = ezhxovdz0k ; } else { if ( rtDW
. dhr4mxnvua == rtDW . nxxhtxi2pq ) { rtDW . gesvnspaab = pw32odyy51 ; rtDW .
khdufyvkjm = dlfdnyv1oi ; } } break ; } if ( guard17 ) { if ( ( ( rtDW .
dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB .
gmumll0z2v == 3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && (
( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) { if ( rtB .
pfhqhr1gju >= 0.0 ) { guard10 = true ; } else { if ( rtB . pfhqhr1gju < 0.0 )
{ guard9 = true ; } } } } if ( guard16 ) { if ( ( ( rtDW . dhr4mxnvua == rtDW
. likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0
) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB . gmumll0z2v
== 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) { if ( rtB . pfhqhr1gju >= 0.0
) { rtDW . khdufyvkjm = ky5isj23hv ; } else { if ( rtB . pfhqhr1gju < 0.0 ) {
rtDW . khdufyvkjm = ms3whpqgva ; } } } } if ( guard15 ) { if ( ( ( rtDW .
dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB .
gmumll0z2v == 3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && (
( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) { if ( rtB .
pfhqhr1gju >= 0.0 ) { rtDW . khdufyvkjm = ky5isj23hv ; } else { if ( rtB .
pfhqhr1gju < 0.0 ) { rtDW . khdufyvkjm = ms3whpqgva ; } } } } if ( guard14 )
{ if ( ( ( rtDW . dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v
== 2.0 ) || ( rtB . gmumll0z2v == 3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW
. nxxhtxi2pq ) && ( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0
) ) ) ) { if ( rtB . pfhqhr1gju >= 0.0 ) { guard8 = true ; } else { if ( rtB
. pfhqhr1gju < 0.0 ) { guard7 = true ; } } } } if ( guard13 ) { if ( ( ( rtDW
. dhr4mxnvua == rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB
. gmumll0z2v == 3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) &&
( ( rtB . gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) { if ( rtB
. pfhqhr1gju >= 0.0 ) { guard6 = true ; } else { if ( rtB . pfhqhr1gju < 0.0
) { guard5 = true ; } } } } if ( guard12 ) { if ( ( ( rtDW . dhr4mxnvua ==
rtDW . likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v ==
3.0 ) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB .
gmumll0z2v == 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) { if ( rtB .
pfhqhr1gju >= 0.0 ) { guard4 = true ; } else { if ( rtB . pfhqhr1gju < 0.0 )
{ guard3 = true ; } } } } if ( guard11 ) { if ( ( ( rtDW . dhr4mxnvua == rtDW
. likqxler4y ) && ( ( rtB . gmumll0z2v == 2.0 ) || ( rtB . gmumll0z2v == 3.0
) ) ) || ( ( rtDW . dhr4mxnvua == rtDW . nxxhtxi2pq ) && ( ( rtB . gmumll0z2v
== 1.0 ) || ( rtB . gmumll0z2v == 4.0 ) ) ) ) { if ( rtB . pfhqhr1gju >= 0.0
) { guard2 = true ; } else { if ( rtB . pfhqhr1gju < 0.0 ) { guard1 = true ;
} } } } if ( guard10 ) { rtDW . gesvnspaab = pw32odyy51 ; rtDW . khdufyvkjm =
ky5isj23hv ; } if ( guard9 ) { rtDW . gesvnspaab = pw32odyy51 ; rtDW .
khdufyvkjm = ms3whpqgva ; } if ( guard8 ) { rtDW . j1l4gcbtpq = c5miqm4t0o ;
rtDW . gesvnspaab = pw32odyy51 ; rtDW . khdufyvkjm = ky5isj23hv ; } if (
guard7 ) { rtDW . j1l4gcbtpq = c5miqm4t0o ; rtDW . gesvnspaab = pw32odyy51 ;
rtDW . khdufyvkjm = ms3whpqgva ; } if ( guard6 ) { rtDW . j1l4gcbtpq =
c5miqm4t0o ; rtDW . gesvnspaab = pw32odyy51 ; rtDW . khdufyvkjm = ky5isj23hv
; } if ( guard5 ) { rtDW . j1l4gcbtpq = c5miqm4t0o ; rtDW . gesvnspaab =
pw32odyy51 ; rtDW . khdufyvkjm = ms3whpqgva ; } if ( guard4 ) { rtDW .
j1l4gcbtpq = c5miqm4t0o ; rtDW . gesvnspaab = pw32odyy51 ; rtDW . khdufyvkjm
= ky5isj23hv ; } if ( guard3 ) { rtDW . j1l4gcbtpq = c5miqm4t0o ; rtDW .
gesvnspaab = pw32odyy51 ; rtDW . khdufyvkjm = ms3whpqgva ; } if ( guard2 ) {
rtDW . j1l4gcbtpq = c5miqm4t0o ; rtDW . gesvnspaab = pw32odyy51 ; rtDW .
khdufyvkjm = ky5isj23hv ; } if ( guard1 ) { rtDW . j1l4gcbtpq = c5miqm4t0o ;
rtDW . gesvnspaab = pw32odyy51 ; rtDW . khdufyvkjm = ms3whpqgva ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } if ( rt_slioCatalogue
( ) != ( NULL ) ) { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( )
) , rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 37 ) ;
ssSetNumBlockIO ( rtS , 9 ) ; ssSetNumBlockParams ( rtS , 6268 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 1.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 271903700U ) ; ssSetChecksumVal ( rtS , 1 ,
3622760240U ) ; ssSetChecksumVal ( rtS , 2 , 3832336147U ) ; ssSetChecksumVal
( rtS , 3 , 1235955264U ) ; }
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
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { void * dwork =
( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork
, 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset
( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo (
rtS , & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; } anav_real_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"anav_real" ) ; ssSetPath ( rtS , "anav_real" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 25.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 0.5 ) ; ssSetMinStepSize ( rtS
, 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS
, 0 ) ; ssSetMaxStepSize ( rtS , 0.5 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 , 271903700U
) ; ssSetChecksumVal ( rtS , 1 , 3622760240U ) ; ssSetChecksumVal ( rtS , 2 ,
3832336147U ) ; ssSetChecksumVal ( rtS , 3 , 1235955264U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 7 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } rtP . sObs [ 8 ] = rtNaN ; rtP . sObs [ 9 ] = rtNaN
; rtP . sObs [ 10 ] = rtNaN ; rtP . sObs [ 11 ] = rtNaN ; rtP . sObs [ 12 ] =
rtNaN ; rtP . sObs [ 13 ] = rtNaN ; rtP . sObs [ 14 ] = rtNaN ; rtP . sObs [
15 ] = rtNaN ; rtP . sObs [ 24 ] = rtNaN ; rtP . sObs [ 25 ] = rtNaN ; rtP .
sObs [ 26 ] = rtNaN ; rtP . sObs [ 27 ] = rtNaN ; rtP . sObs [ 28 ] = rtNaN ;
rtP . sObs [ 29 ] = rtNaN ; rtP . sObs [ 30 ] = rtNaN ; rtP . sObs [ 31 ] =
rtNaN ; rtP . sObs [ 40 ] = rtNaN ; rtP . sObs [ 41 ] = rtNaN ; rtP . sObs [
42 ] = rtNaN ; rtP . sObs [ 43 ] = rtNaN ; rtP . sObs [ 44 ] = rtNaN ; rtP .
sObs [ 45 ] = rtNaN ; rtP . sObs [ 46 ] = rtNaN ; rtP . sObs [ 47 ] = rtNaN ;
rtP . sObs [ 60 ] = rtNaN ; rtP . sObs [ 61 ] = rtNaN ; rtP . sObs [ 62 ] =
rtNaN ; rtP . sObs [ 63 ] = rtNaN ; rtP . sObs [ 76 ] = rtNaN ; rtP . sObs [
77 ] = rtNaN ; rtP . sObs [ 78 ] = rtNaN ; rtP . sObs [ 79 ] = rtNaN ; rtP .
sObs [ 92 ] = rtNaN ; rtP . sObs [ 93 ] = rtNaN ; rtP . sObs [ 94 ] = rtNaN ;
rtP . sObs [ 95 ] = rtNaN ; rtP . sObs [ 155 ] = rtNaN ; rtP . sObs [ 156 ] =
rtNaN ; rtP . sObs [ 157 ] = rtNaN ; rtP . sObs [ 158 ] = rtNaN ; rtP . sObs
[ 159 ] = rtNaN ; rtP . sObs [ 171 ] = rtNaN ; rtP . sObs [ 172 ] = rtNaN ;
rtP . sObs [ 173 ] = rtNaN ; rtP . sObs [ 174 ] = rtNaN ; rtP . sObs [ 175 ]
= rtNaN ; rtP . sObs [ 187 ] = rtNaN ; rtP . sObs [ 188 ] = rtNaN ; rtP .
sObs [ 189 ] = rtNaN ; rtP . sObs [ 190 ] = rtNaN ; rtP . sObs [ 191 ] =
rtNaN ; rtP . sObs [ 203 ] = rtNaN ; rtP . sObs [ 204 ] = rtNaN ; rtP . sObs
[ 205 ] = rtNaN ; rtP . sObs [ 206 ] = rtNaN ; rtP . sObs [ 207 ] = rtNaN ;
rtP . sObs [ 219 ] = rtNaN ; rtP . sObs [ 220 ] = rtNaN ; rtP . sObs [ 221 ]
= rtNaN ; rtP . sObs [ 222 ] = rtNaN ; rtP . sObs [ 223 ] = rtNaN ; rtP .
sObs [ 235 ] = rtNaN ; rtP . sObs [ 236 ] = rtNaN ; rtP . sObs [ 237 ] =
rtNaN ; rtP . sObs [ 238 ] = rtNaN ; rtP . sObs [ 239 ] = rtNaN ; rtP .
visualObj [ 626 ] = rtNaN ; rtP . visualObj [ 627 ] = rtNaN ; rtP . visualObj
[ 628 ] = rtNaN ; rtP . visualObj [ 629 ] = rtNaN ; rtP . visualObj [ 630 ] =
rtNaN ; rtP . visualObj [ 631 ] = rtNaN ; rtP . visualObj [ 632 ] = rtNaN ;
rtP . visualObj [ 633 ] = rtNaN ; rtP . visualObj [ 634 ] = rtNaN ; rtP .
visualObj [ 635 ] = rtNaN ; rtP . visualObj [ 636 ] = rtNaN ; rtP . visualObj
[ 637 ] = rtNaN ; rtP . visualObj [ 638 ] = rtNaN ; rtP . visualObj [ 639 ] =
rtNaN ; rtP . visualObj [ 640 ] = rtNaN ; rtP . visualObj [ 641 ] = rtNaN ;
rtP . visualObj [ 642 ] = rtNaN ; rtP . visualObj [ 643 ] = rtNaN ; rtP .
visualObj [ 644 ] = rtNaN ; rtP . visualObj [ 645 ] = rtNaN ; rtP . visualObj
[ 646 ] = rtNaN ; rtP . visualObj [ 647 ] = rtNaN ; rtP . visualObj [ 648 ] =
rtNaN ; rtP . visualObj [ 649 ] = rtNaN ; rtP . visualObj [ 650 ] = rtNaN ;
rtP . visualObj [ 651 ] = rtNaN ; rtP . visualObj [ 652 ] = rtNaN ; rtP .
visualObj [ 653 ] = rtNaN ; rtP . visualObj [ 654 ] = rtNaN ; rtP . visualObj
[ 655 ] = rtNaN ; rtP . visualObj [ 656 ] = rtNaN ; rtP . visualObj [ 657 ] =
rtNaN ; rtP . visualObj [ 658 ] = rtNaN ; rtP . visualObj [ 659 ] = rtNaN ;
rtP . visualObj [ 660 ] = rtNaN ; rtP . visualObj [ 661 ] = rtNaN ; rtP .
visualObj [ 662 ] = rtNaN ; rtP . visualObj [ 663 ] = rtNaN ; rtP . visualObj
[ 664 ] = rtNaN ; rtP . visualObj [ 665 ] = rtNaN ; rtP . visualObj [ 666 ] =
rtNaN ; rtP . visualObj [ 667 ] = rtNaN ; rtP . visualObj [ 668 ] = rtNaN ;
rtP . visualObj [ 669 ] = rtNaN ; rtP . visualObj [ 670 ] = rtNaN ; rtP .
visualObj [ 671 ] = rtNaN ; rtP . visualObj [ 672 ] = rtNaN ; rtP . visualObj
[ 673 ] = rtNaN ; rtP . visualObj [ 674 ] = rtNaN ; rtP . visualObj [ 675 ] =
rtNaN ; rtP . visualObj [ 676 ] = rtNaN ; rtP . visualObj [ 677 ] = rtNaN ;
rtP . visualObj [ 678 ] = rtNaN ; rtP . visualObj [ 679 ] = rtNaN ; rtP .
visualObj [ 680 ] = rtNaN ; rtP . visualObj [ 681 ] = rtNaN ; rtP . visualObj
[ 682 ] = rtNaN ; rtP . visualObj [ 683 ] = rtNaN ; rtP . visualObj [ 684 ] =
rtNaN ; rtP . visualObj [ 685 ] = rtNaN ; rtP . visualObj [ 686 ] = rtNaN ;
rtP . visualObj [ 687 ] = rtNaN ; rtP . visualObj [ 688 ] = rtNaN ; rtP .
visualObj [ 689 ] = rtNaN ; rtP . visualObj [ 690 ] = rtNaN ; rtP . visualObj
[ 691 ] = rtNaN ; rtP . visualObj [ 692 ] = rtNaN ; rtP . visualObj [ 693 ] =
rtNaN ; rtP . visualObj [ 694 ] = rtNaN ; rtP . visualObj [ 695 ] = rtNaN ;
rtP . visualObj [ 696 ] = rtNaN ; rtP . visualObj [ 697 ] = rtNaN ; rtP .
visualObj [ 698 ] = rtNaN ; rtP . visualObj [ 699 ] = rtNaN ; rtP . visualObj
[ 700 ] = rtNaN ; rtP . visualObj [ 701 ] = rtNaN ; rtP . visualObj [ 702 ] =
rtNaN ; rtP . visualObj [ 703 ] = rtNaN ; rtP . visualObj [ 704 ] = rtNaN ;
rtP . visualObj [ 705 ] = rtNaN ; rtP . visualObj [ 706 ] = rtNaN ; rtP .
visualObj [ 707 ] = rtNaN ; rtP . visualObj [ 708 ] = rtNaN ; rtP . visualObj
[ 709 ] = rtNaN ; rtP . visualObj [ 710 ] = rtNaN ; rtP . visualObj [ 711 ] =
rtNaN ; rtP . visualObj [ 712 ] = rtNaN ; rtP . visualObj [ 713 ] = rtNaN ;
rtP . visualObj [ 714 ] = rtNaN ; rtP . visualObj [ 715 ] = rtNaN ; rtP .
visualObj [ 716 ] = rtNaN ; rtP . visualObj [ 717 ] = rtNaN ; rtP . visualObj
[ 718 ] = rtNaN ; rtP . visualObj [ 719 ] = rtNaN ; rtP . visualObj [ 720 ] =
rtNaN ; rtP . visualObj [ 721 ] = rtNaN ; rtP . visualObj [ 722 ] = rtNaN ;
rtP . visualObj [ 723 ] = rtNaN ; rtP . visualObj [ 724 ] = rtNaN ; rtP .
visualObj [ 725 ] = rtNaN ; rtP . visualObj [ 726 ] = rtNaN ; rtP . visualObj
[ 727 ] = rtNaN ; rtP . visualObj [ 728 ] = rtNaN ; rtP . visualObj [ 729 ] =
rtNaN ; rtP . visualObj [ 730 ] = rtNaN ; rtP . visualObj [ 731 ] = rtNaN ;
rtP . visualObj [ 732 ] = rtNaN ; rtP . visualObj [ 733 ] = rtNaN ; rtP .
visualObj [ 734 ] = rtNaN ; rtP . visualObj [ 735 ] = rtNaN ; rtP . visualObj
[ 736 ] = rtNaN ; rtP . visualObj [ 737 ] = rtNaN ; rtP . visualObj [ 738 ] =
rtNaN ; rtP . visualObj [ 739 ] = rtNaN ; rtP . visualObj [ 740 ] = rtNaN ;
rtP . visualObj [ 741 ] = rtNaN ; rtP . visualObj [ 742 ] = rtNaN ; rtP .
visualObj [ 743 ] = rtNaN ; rtP . visualObj [ 744 ] = rtNaN ; rtP . visualObj
[ 745 ] = rtNaN ; rtP . visualObj [ 746 ] = rtNaN ; rtP . visualObj [ 747 ] =
rtNaN ; rtP . visualObj [ 748 ] = rtNaN ; rtP . visualObj [ 749 ] = rtNaN ;
rtP . visualObj [ 750 ] = rtNaN ; rtP . visualObj [ 751 ] = rtNaN ; rtP .
visualObj [ 752 ] = rtNaN ; rtP . visualObj [ 753 ] = rtNaN ; rtP . visualObj
[ 754 ] = rtNaN ; rtP . visualObj [ 755 ] = rtNaN ; rtP . visualObj [ 756 ] =
rtNaN ; rtP . visualObj [ 757 ] = rtNaN ; rtP . visualObj [ 758 ] = rtNaN ;
rtP . visualObj [ 759 ] = rtNaN ; rtP . visualObj [ 760 ] = rtNaN ; rtP .
visualObj [ 761 ] = rtNaN ; rtP . visualObj [ 762 ] = rtNaN ; rtP . visualObj
[ 763 ] = rtNaN ; rtP . visualObj [ 764 ] = rtNaN ; rtP . visualObj [ 765 ] =
rtNaN ; rtP . visualObj [ 766 ] = rtNaN ; rtP . visualObj [ 767 ] = rtNaN ;
rtP . visualObj [ 768 ] = rtNaN ; rtP . visualObj [ 769 ] = rtNaN ; rtP .
visualObj [ 770 ] = rtNaN ; rtP . visualObj [ 771 ] = rtNaN ; rtP . visualObj
[ 772 ] = rtNaN ; rtP . visualObj [ 773 ] = rtNaN ; rtP . visualObj [ 774 ] =
rtNaN ; rtP . visualObj [ 775 ] = rtNaN ; rtP . visualObj [ 820 ] = rtNaN ;
rtP . visualObj [ 821 ] = rtNaN ; rtP . visualObj [ 822 ] = rtNaN ; rtP .
visualObj [ 823 ] = rtNaN ; rtP . visualObj [ 824 ] = rtNaN ; rtP . visualObj
[ 825 ] = rtNaN ; rtP . visualObj [ 826 ] = rtNaN ; rtP . visualObj [ 827 ] =
rtNaN ; rtP . visualObj [ 828 ] = rtNaN ; rtP . visualObj [ 829 ] = rtNaN ;
rtP . visualObj [ 830 ] = rtNaN ; rtP . visualObj [ 831 ] = rtNaN ; rtP .
visualObj [ 832 ] = rtNaN ; rtP . visualObj [ 833 ] = rtNaN ; rtP . visualObj
[ 834 ] = rtNaN ; rtP . visualObj [ 835 ] = rtNaN ; rtP . visualObj [ 836 ] =
rtNaN ; rtP . visualObj [ 837 ] = rtNaN ; rtP . visualObj [ 838 ] = rtNaN ;
rtP . visualObj [ 839 ] = rtNaN ; rtP . visualObj [ 840 ] = rtNaN ; rtP .
visualObj [ 841 ] = rtNaN ; rtP . visualObj [ 842 ] = rtNaN ; rtP . visualObj
[ 843 ] = rtNaN ; rtP . visualObj [ 844 ] = rtNaN ; rtP . visualObj [ 845 ] =
rtNaN ; rtP . visualObj [ 846 ] = rtNaN ; rtP . visualObj [ 847 ] = rtNaN ;
rtP . visualObj [ 848 ] = rtNaN ; rtP . visualObj [ 849 ] = rtNaN ; rtP .
visualObj [ 850 ] = rtNaN ; rtP . visualObj [ 851 ] = rtNaN ; rtP . visualObj
[ 852 ] = rtNaN ; rtP . visualObj [ 853 ] = rtNaN ; rtP . visualObj [ 854 ] =
rtNaN ; rtP . visualObj [ 855 ] = rtNaN ; rtP . visualObj [ 856 ] = rtNaN ;
rtP . visualObj [ 857 ] = rtNaN ; rtP . visualObj [ 858 ] = rtNaN ; rtP .
visualObj [ 859 ] = rtNaN ; rtP . visualObj [ 860 ] = rtNaN ; rtP . visualObj
[ 861 ] = rtNaN ; rtP . visualObj [ 862 ] = rtNaN ; rtP . visualObj [ 863 ] =
rtNaN ; rtP . visualObj [ 864 ] = rtNaN ; rtP . visualObj [ 865 ] = rtNaN ;
rtP . visualObj [ 866 ] = rtNaN ; rtP . visualObj [ 867 ] = rtNaN ; rtP .
visualObj [ 868 ] = rtNaN ; rtP . visualObj [ 869 ] = rtNaN ; rtP . visualObj
[ 870 ] = rtNaN ; rtP . visualObj [ 871 ] = rtNaN ; rtP . visualObj [ 872 ] =
rtNaN ; rtP . visualObj [ 873 ] = rtNaN ; rtP . visualObj [ 874 ] = rtNaN ;
rtP . visualObj [ 875 ] = rtNaN ; rtP . visualObj [ 876 ] = rtNaN ; rtP .
visualObj [ 877 ] = rtNaN ; rtP . visualObj [ 878 ] = rtNaN ; rtP . visualObj
[ 879 ] = rtNaN ; rtP . visualObj [ 880 ] = rtNaN ; rtP . visualObj [ 881 ] =
rtNaN ; rtP . visualObj [ 882 ] = rtNaN ; rtP . visualObj [ 883 ] = rtNaN ;
rtP . visualObj [ 884 ] = rtNaN ; rtP . visualObj [ 885 ] = rtNaN ; rtP .
visualObj [ 886 ] = rtNaN ; rtP . visualObj [ 887 ] = rtNaN ; rtP . visualObj
[ 888 ] = rtNaN ; rtP . visualObj [ 889 ] = rtNaN ; rtP . visualObj [ 890 ] =
rtNaN ; rtP . visualObj [ 891 ] = rtNaN ; rtP . visualObj [ 892 ] = rtNaN ;
rtP . visualObj [ 893 ] = rtNaN ; rtP . visualObj [ 894 ] = rtNaN ; rtP .
visualObj [ 895 ] = rtNaN ; rtP . visualObj [ 896 ] = rtNaN ; rtP . visualObj
[ 897 ] = rtNaN ; rtP . visualObj [ 898 ] = rtNaN ; rtP . visualObj [ 899 ] =
rtNaN ; rtP . visualObj [ 900 ] = rtNaN ; rtP . visualObj [ 901 ] = rtNaN ;
rtP . visualObj [ 902 ] = rtNaN ; rtP . visualObj [ 903 ] = rtNaN ; rtP .
visualObj [ 904 ] = rtNaN ; rtP . visualObj [ 905 ] = rtNaN ; rtP . visualObj
[ 906 ] = rtNaN ; rtP . visualObj [ 907 ] = rtNaN ; rtP . visualObj [ 908 ] =
rtNaN ; rtP . visualObj [ 909 ] = rtNaN ; rtP . visualObj [ 910 ] = rtNaN ;
rtP . visualObj [ 911 ] = rtNaN ; rtP . visualObj [ 912 ] = rtNaN ; rtP .
visualObj [ 913 ] = rtNaN ; rtP . visualObj [ 914 ] = rtNaN ; rtP . visualObj
[ 915 ] = rtNaN ; rtP . visualObj [ 916 ] = rtNaN ; rtP . visualObj [ 917 ] =
rtNaN ; rtP . visualObj [ 918 ] = rtNaN ; rtP . visualObj [ 919 ] = rtNaN ;
rtP . visualObj [ 920 ] = rtNaN ; rtP . visualObj [ 921 ] = rtNaN ; rtP .
visualObj [ 922 ] = rtNaN ; rtP . visualObj [ 923 ] = rtNaN ; rtP . visualObj
[ 924 ] = rtNaN ; rtP . visualObj [ 925 ] = rtNaN ; rtP . visualObj [ 926 ] =
rtNaN ; rtP . visualObj [ 927 ] = rtNaN ; rtP . visualObj [ 928 ] = rtNaN ;
rtP . visualObj [ 929 ] = rtNaN ; rtP . visualObj [ 930 ] = rtNaN ; rtP .
visualObj [ 931 ] = rtNaN ; rtP . visualObj [ 932 ] = rtNaN ; rtP . visualObj
[ 933 ] = rtNaN ; rtP . visualObj [ 934 ] = rtNaN ; rtP . visualObj [ 935 ] =
rtNaN ; rtP . visualObj [ 936 ] = rtNaN ; rtP . visualObj [ 937 ] = rtNaN ;
rtP . visualObj [ 938 ] = rtNaN ; rtP . visualObj [ 939 ] = rtNaN ; rtP .
visualObj [ 940 ] = rtNaN ; rtP . visualObj [ 941 ] = rtNaN ; rtP . visualObj
[ 942 ] = rtNaN ; rtP . visualObj [ 943 ] = rtNaN ; rtP . visualObj [ 944 ] =
rtNaN ; rtP . visualObj [ 945 ] = rtNaN ; rtP . visualObj [ 946 ] = rtNaN ;
rtP . visualObj [ 947 ] = rtNaN ; rtP . visualObj [ 948 ] = rtNaN ; rtP .
visualObj [ 949 ] = rtNaN ; rtP . visualObj [ 950 ] = rtNaN ; rtP . visualObj
[ 951 ] = rtNaN ; rtP . visualObj [ 952 ] = rtNaN ; rtP . visualObj [ 953 ] =
rtNaN ; rtP . visualObj [ 954 ] = rtNaN ; rtP . visualObj [ 955 ] = rtNaN ;
rtP . visualObj [ 956 ] = rtNaN ; rtP . visualObj [ 957 ] = rtNaN ; rtP .
visualObj [ 958 ] = rtNaN ; rtP . visualObj [ 959 ] = rtNaN ; rtP . visualObj
[ 960 ] = rtNaN ; rtP . visualObj [ 961 ] = rtNaN ; rtP . visualObj [ 962 ] =
rtNaN ; rtP . visualObj [ 963 ] = rtNaN ; rtP . visualObj [ 964 ] = rtNaN ;
rtP . visualObj [ 965 ] = rtNaN ; rtP . visualObj [ 966 ] = rtNaN ; rtP .
visualObj [ 967 ] = rtNaN ; rtP . visualObj [ 968 ] = rtNaN ; rtP . visualObj
[ 969 ] = rtNaN ; rtP . visualObj [ 1014 ] = rtNaN ; rtP . visualObj [ 1015 ]
= rtNaN ; rtP . visualObj [ 1016 ] = rtNaN ; rtP . visualObj [ 1017 ] = rtNaN
; rtP . visualObj [ 1018 ] = rtNaN ; rtP . visualObj [ 1019 ] = rtNaN ; rtP .
visualObj [ 1020 ] = rtNaN ; rtP . visualObj [ 1021 ] = rtNaN ; rtP .
visualObj [ 1022 ] = rtNaN ; rtP . visualObj [ 1023 ] = rtNaN ; rtP .
visualObj [ 1024 ] = rtNaN ; rtP . visualObj [ 1025 ] = rtNaN ; rtP .
visualObj [ 1026 ] = rtNaN ; rtP . visualObj [ 1027 ] = rtNaN ; rtP .
visualObj [ 1028 ] = rtNaN ; rtP . visualObj [ 1029 ] = rtNaN ; rtP .
visualObj [ 1030 ] = rtNaN ; rtP . visualObj [ 1031 ] = rtNaN ; rtP .
visualObj [ 1032 ] = rtNaN ; rtP . visualObj [ 1033 ] = rtNaN ; rtP .
visualObj [ 1034 ] = rtNaN ; rtP . visualObj [ 1035 ] = rtNaN ; rtP .
visualObj [ 1036 ] = rtNaN ; rtP . visualObj [ 1037 ] = rtNaN ; rtP .
visualObj [ 1038 ] = rtNaN ; rtP . visualObj [ 1039 ] = rtNaN ; rtP .
visualObj [ 1040 ] = rtNaN ; rtP . visualObj [ 1041 ] = rtNaN ; rtP .
visualObj [ 1042 ] = rtNaN ; rtP . visualObj [ 1043 ] = rtNaN ; rtP .
visualObj [ 1044 ] = rtNaN ; rtP . visualObj [ 1045 ] = rtNaN ; rtP .
visualObj [ 1046 ] = rtNaN ; rtP . visualObj [ 1047 ] = rtNaN ; rtP .
visualObj [ 1048 ] = rtNaN ; rtP . visualObj [ 1049 ] = rtNaN ; rtP .
visualObj [ 1050 ] = rtNaN ; rtP . visualObj [ 1051 ] = rtNaN ; rtP .
visualObj [ 1052 ] = rtNaN ; rtP . visualObj [ 1053 ] = rtNaN ; rtP .
visualObj [ 1054 ] = rtNaN ; rtP . visualObj [ 1055 ] = rtNaN ; rtP .
visualObj [ 1056 ] = rtNaN ; rtP . visualObj [ 1057 ] = rtNaN ; rtP .
visualObj [ 1058 ] = rtNaN ; rtP . visualObj [ 1059 ] = rtNaN ; rtP .
visualObj [ 1060 ] = rtNaN ; rtP . visualObj [ 1061 ] = rtNaN ; rtP .
visualObj [ 1062 ] = rtNaN ; rtP . visualObj [ 1063 ] = rtNaN ; rtP .
visualObj [ 1064 ] = rtNaN ; rtP . visualObj [ 1065 ] = rtNaN ; rtP .
visualObj [ 1066 ] = rtNaN ; rtP . visualObj [ 1067 ] = rtNaN ; rtP .
visualObj [ 1068 ] = rtNaN ; rtP . visualObj [ 1069 ] = rtNaN ; rtP .
visualObj [ 1070 ] = rtNaN ; rtP . visualObj [ 1071 ] = rtNaN ; rtP .
visualObj [ 1072 ] = rtNaN ; rtP . visualObj [ 1073 ] = rtNaN ; rtP .
visualObj [ 1074 ] = rtNaN ; rtP . visualObj [ 1075 ] = rtNaN ; rtP .
visualObj [ 1076 ] = rtNaN ; rtP . visualObj [ 1077 ] = rtNaN ; rtP .
visualObj [ 1078 ] = rtNaN ; rtP . visualObj [ 1079 ] = rtNaN ; rtP .
visualObj [ 1080 ] = rtNaN ; rtP . visualObj [ 1081 ] = rtNaN ; rtP .
visualObj [ 1082 ] = rtNaN ; rtP . visualObj [ 1083 ] = rtNaN ; rtP .
visualObj [ 1084 ] = rtNaN ; rtP . visualObj [ 1085 ] = rtNaN ; rtP .
visualObj [ 1086 ] = rtNaN ; rtP . visualObj [ 1087 ] = rtNaN ; rtP .
visualObj [ 1088 ] = rtNaN ; rtP . visualObj [ 1089 ] = rtNaN ; rtP .
visualObj [ 1090 ] = rtNaN ; rtP . visualObj [ 1091 ] = rtNaN ; rtP .
visualObj [ 1092 ] = rtNaN ; rtP . visualObj [ 1093 ] = rtNaN ; rtP .
visualObj [ 1094 ] = rtNaN ; rtP . visualObj [ 1095 ] = rtNaN ; rtP .
visualObj [ 1096 ] = rtNaN ; rtP . visualObj [ 1097 ] = rtNaN ; rtP .
visualObj [ 1098 ] = rtNaN ; rtP . visualObj [ 1099 ] = rtNaN ; rtP .
visualObj [ 1100 ] = rtNaN ; rtP . visualObj [ 1101 ] = rtNaN ; rtP .
visualObj [ 1102 ] = rtNaN ; rtP . visualObj [ 1103 ] = rtNaN ; rtP .
visualObj [ 1104 ] = rtNaN ; rtP . visualObj [ 1105 ] = rtNaN ; rtP .
visualObj [ 1106 ] = rtNaN ; rtP . visualObj [ 1107 ] = rtNaN ; rtP .
visualObj [ 1108 ] = rtNaN ; rtP . visualObj [ 1109 ] = rtNaN ; rtP .
visualObj [ 1110 ] = rtNaN ; rtP . visualObj [ 1111 ] = rtNaN ; rtP .
visualObj [ 1112 ] = rtNaN ; rtP . visualObj [ 1113 ] = rtNaN ; rtP .
visualObj [ 1114 ] = rtNaN ; rtP . visualObj [ 1115 ] = rtNaN ; rtP .
visualObj [ 1116 ] = rtNaN ; rtP . visualObj [ 1117 ] = rtNaN ; rtP .
visualObj [ 1118 ] = rtNaN ; rtP . visualObj [ 1119 ] = rtNaN ; rtP .
visualObj [ 1120 ] = rtNaN ; rtP . visualObj [ 1121 ] = rtNaN ; rtP .
visualObj [ 1122 ] = rtNaN ; rtP . visualObj [ 1123 ] = rtNaN ; rtP .
visualObj [ 1124 ] = rtNaN ; rtP . visualObj [ 1125 ] = rtNaN ; rtP .
visualObj [ 1126 ] = rtNaN ; rtP . visualObj [ 1127 ] = rtNaN ; rtP .
visualObj [ 1128 ] = rtNaN ; rtP . visualObj [ 1129 ] = rtNaN ; rtP .
visualObj [ 1130 ] = rtNaN ; rtP . visualObj [ 1131 ] = rtNaN ; rtP .
visualObj [ 1132 ] = rtNaN ; rtP . visualObj [ 1133 ] = rtNaN ; rtP .
visualObj [ 1134 ] = rtNaN ; rtP . visualObj [ 1135 ] = rtNaN ; rtP .
visualObj [ 1136 ] = rtNaN ; rtP . visualObj [ 1137 ] = rtNaN ; rtP .
visualObj [ 1138 ] = rtNaN ; rtP . visualObj [ 1139 ] = rtNaN ; rtP .
visualObj [ 1140 ] = rtNaN ; rtP . visualObj [ 1141 ] = rtNaN ; rtP .
visualObj [ 1142 ] = rtNaN ; rtP . visualObj [ 1143 ] = rtNaN ; rtP .
visualObj [ 1144 ] = rtNaN ; rtP . visualObj [ 1145 ] = rtNaN ; rtP .
visualObj [ 1146 ] = rtNaN ; rtP . visualObj [ 1147 ] = rtNaN ; rtP .
visualObj [ 1148 ] = rtNaN ; rtP . visualObj [ 1149 ] = rtNaN ; rtP .
visualObj [ 1150 ] = rtNaN ; rtP . visualObj [ 1151 ] = rtNaN ; rtP .
visualObj [ 1152 ] = rtNaN ; rtP . visualObj [ 1153 ] = rtNaN ; rtP .
visualObj [ 1154 ] = rtNaN ; rtP . visualObj [ 1155 ] = rtNaN ; rtP .
visualObj [ 1156 ] = rtNaN ; rtP . visualObj [ 1157 ] = rtNaN ; rtP .
visualObj [ 1158 ] = rtNaN ; rtP . visualObj [ 1159 ] = rtNaN ; rtP .
visualObj [ 1160 ] = rtNaN ; rtP . visualObj [ 1161 ] = rtNaN ; rtP .
visualObj [ 1162 ] = rtNaN ; rtP . visualObj [ 1163 ] = rtNaN ;
ssSetNumSFunctions ( rtS , 1 ) ; { static SimStruct childSFunctions [ 1 ] ;
static SimStruct * childSFunctionPtrs [ 1 ] ; ( void ) memset ( ( void * ) &
childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions ) ) ; ssSetSFunctions (
rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction ( rtS , 0 , &
childSFunctions [ 0 ] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static
int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof
( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 1 ] ;
_ssSetNumInputPorts ( rts , 1 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static struct _ssInPortUnit inputPortUnits [ 1 ] ;
_ssSetPortInfo2ForInputUnits ( rts , & inputPortUnits [ 0 ] ) ; }
ssSetInputPortUnit ( rts , 0 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 1 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; { ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ;
ssSetInputPortSignal ( rts , 0 , rtB . hcyznxmk0r ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 6165 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; { static int_T
dimensions [ 2 ] ; dimensions [ 0 ] = 20 ; dimensions [ 1 ] = 2 ;
_ssSetOutputPortDimensionsPtr ( rts , 0 , dimensions ) ;
_ssSetOutputPortNumDimensions ( rts , 0 , 2 ) ; ssSetOutputPortWidth ( rts ,
0 , 40 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . a4yf2mjntq
) ) ; } } ssSetModelName ( rts , "DstarRun C++" ) ; ssSetPath ( rts ,
"anav_real/DstarRun C++" ) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) {
ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; }
else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , (
NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion ( rts ,
SIMSTRUCT_VERSION_LEVEL2 ) ; DstarRun ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 1.0 ) ; sfcnTsMap [ 0 ] = 0 ; ssSetInputPortWidth
( rts , 0 , 6165 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumNonsampledZCs (
rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged ( rts
, 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } } return rtS ;
}
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
