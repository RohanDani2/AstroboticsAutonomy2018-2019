#ifndef __c2_multitime_h__
#define __c2_multitime_h__

/* Type Definitions */
#include <stdlib.h>
#ifndef typedef_SFc2_multitimeInstanceStruct
#define typedef_SFc2_multitimeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_multitime;
  uint32_T c2_method;
  boolean_T c2_method_not_empty;
  uint32_T c2_state;
  boolean_T c2_state_not_empty;
  uint32_T c2_b_state[2];
  boolean_T c2_b_state_not_empty;
  uint32_T c2_c_state[625];
  boolean_T c2_c_state_not_empty;
  real_T c2_a[4500];
  real_T c2_b[4000];
  void *c2_fEmlrtCtx;
  real_T (*c2_inflated1)[3200];
} SFc2_multitimeInstanceStruct;

#endif                                 /*typedef_SFc2_multitimeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_multitime_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_multitime_get_check_sum(mxArray *plhs[]);
extern void c2_multitime_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
