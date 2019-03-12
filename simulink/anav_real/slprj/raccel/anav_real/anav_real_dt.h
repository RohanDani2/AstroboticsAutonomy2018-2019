#include "__cf_anav_real.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . a4yf2mjntq
[ 0 ] ) , 0 , 0 , 6213 } , { ( char_T * ) ( & rtDW . irqtpqf4mz [ 0 ] ) , 0 ,
0 , 2067 } , { ( char_T * ) ( & rtDW . kakhnbjo3s ) , 6 , 0 , 1 } , { (
char_T * ) ( & rtDW . ouzu4kamsj ) , 3 , 0 , 4 } , { ( char_T * ) ( & rtDW .
fgjqzsh1cz ) , 8 , 0 , 1 } } ; static DataTypeTransitionTable rtBTransTable =
{ 5U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { {
( char_T * ) ( & rtP . limit [ 0 ] ) , 0 , 0 , 6268 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
