#ifndef __c12_anav_real_h__
#define __c12_anav_real_h__

/* Type Definitions */
#ifndef struct_tag_spGKsvEVm7uA89hv31XX4LH
#define struct_tag_spGKsvEVm7uA89hv31XX4LH

struct tag_spGKsvEVm7uA89hv31XX4LH
{
  uint32_T MissingPlacement;
  uint32_T ComparisonMethod;
};

#endif                                 /*struct_tag_spGKsvEVm7uA89hv31XX4LH*/

#ifndef typedef_c12_spGKsvEVm7uA89hv31XX4LH
#define typedef_c12_spGKsvEVm7uA89hv31XX4LH

typedef struct tag_spGKsvEVm7uA89hv31XX4LH c12_spGKsvEVm7uA89hv31XX4LH;

#endif                                 /*typedef_c12_spGKsvEVm7uA89hv31XX4LH*/

#ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
#define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
  uint32_T SafeEq;
  uint32_T Absolute;
  uint32_T NaNBias;
  uint32_T NaNWithFinite;
  uint32_T FiniteWithNaN;
  uint32_T NaNWithNaN;
};

#endif                                 /*struct_tag_skA4KFEZ4HPkJJBOYCrevdH*/

#ifndef typedef_c12_skA4KFEZ4HPkJJBOYCrevdH
#define typedef_c12_skA4KFEZ4HPkJJBOYCrevdH

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH c12_skA4KFEZ4HPkJJBOYCrevdH;

#endif                                 /*typedef_c12_skA4KFEZ4HPkJJBOYCrevdH*/

#include <stdlib.h>
#include "lapacke.h"
#ifndef struct_emxArray_real_T_1081
#define struct_emxArray_real_T_1081

struct emxArray_real_T_1081
{
  real_T data[1081];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_1081*/

#ifndef typedef_c12_emxArray_real_T_1081
#define typedef_c12_emxArray_real_T_1081

typedef struct emxArray_real_T_1081 c12_emxArray_real_T_1081;

#endif                                 /*typedef_c12_emxArray_real_T_1081*/

#ifndef struct_sR3snNy4tpJ3f126gtk9zIE_tag
#define struct_sR3snNy4tpJ3f126gtk9zIE_tag

struct sR3snNy4tpJ3f126gtk9zIE_tag
{
  c12_emxArray_real_T_1081 f1;
};

#endif                                 /*struct_sR3snNy4tpJ3f126gtk9zIE_tag*/

#ifndef typedef_c12_cell_wrap_0
#define typedef_c12_cell_wrap_0

typedef struct sR3snNy4tpJ3f126gtk9zIE_tag c12_cell_wrap_0;

#endif                                 /*typedef_c12_cell_wrap_0*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_c12_emxArray_int32_T
#define typedef_c12_emxArray_int32_T

typedef struct emxArray_int32_T c12_emxArray_int32_T;

#endif                                 /*typedef_c12_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_c12_emxArray_real_T
#define typedef_c12_emxArray_real_T

typedef struct emxArray_real_T c12_emxArray_real_T;

#endif                                 /*typedef_c12_emxArray_real_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_c12_emxArray_boolean_T
#define typedef_c12_emxArray_boolean_T

typedef struct emxArray_boolean_T c12_emxArray_boolean_T;

#endif                                 /*typedef_c12_emxArray_boolean_T*/

#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 /*struct_tag_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_c12_sJCxfmxS8gBOONUZjbjUd9E
#define typedef_c12_sJCxfmxS8gBOONUZjbjUd9E

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E c12_sJCxfmxS8gBOONUZjbjUd9E;

#endif                                 /*typedef_c12_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_c12_emxArray_creal_T
#define typedef_c12_emxArray_creal_T

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} c12_emxArray_creal_T;

#endif                                 /*typedef_c12_emxArray_creal_T*/

#ifndef typedef_SFc12_anav_realInstanceStruct
#define typedef_SFc12_anav_realInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_anav_real;
  real_T c12_mapGridP[3081];
  boolean_T c12_mapGridP_not_empty;
  c12_emxArray_creal_T *c12_h;
  boolean_T c12_h_not_empty;
  real_T c12_costsTemp[9252];
  real_T c12_costs[9252];
  real_T c12_x[9252];
  real_T c12_b_costs[9252];
  real_T c12_mapList[9243];
  real_T c12_dv3[9243];
  creal_T c12_inflated_data[3081];
  creal_T c12_b1_data[3081];
  creal_T c12_b2_data[3081];
  real_T c12_limitGrid[3081];
  real_T c12_b_inflated_data[3081];
  real_T c12_mapGrid[3081];
  real_T c12_grid[3081];
  real_T c12_b_grid[3081];
  real_T c12_b_data[3081];
  real_T c12_hoistedGlobal[3081];
  real_T c12_b_mapGrid[3081];
  real_T c12_c_mapGrid[3081];
  real_T c12_varargin_1[3081];
  real_T c12_b_varargin_1[3081];
  real_T c12_b_b1_data[3081];
  real_T c12_b_b2_data[3081];
  real_T c12_tmp_data[3081];
  real_T c12_b_tmp_data[3081];
  real_T c12_roundedLimitUnique_data[2634];
  real_T c12_c_tmp_data[2634];
  c12_cell_wrap_0 c12_reshapes[2];
  real_T c12_detectedList[2162];
  real_T c12_compressed_data[2162];
  real_T c12_orientCart_data[2162];
  real_T c12_transCart_data[2162];
  real_T c12_roundedUnique_data[2162];
  real_T c12_roundTransCart_data[2162];
  real_T c12_b_detectedList[2162];
  real_T c12_a_data[2162];
  real_T c12_b_b_data[2162];
  real_T c12_b_roundedUnique_data[2162];
  real_T c12_c_roundedUnique_data[2162];
  real_T c12_result_data[2162];
  real_T c12_y_data[2162];
  real_T c12_x_data[2162];
  void *c12_fEmlrtCtx;
  real_T (*c12_pos)[2];
  real_T (*c12_c_costs)[9252];
  real_T *c12_theta;
  real_T (*c12_c_detectedList)[2162];
  real_T *c12_scale;
  real_T (*c12_goal)[2];
  real_T *c12_vehicleRad;
  real_T (*c12_limit)[708];
  real_T *c12_mode;
  real_T (*c12_d_mapGrid)[3081];
} SFc12_anav_realInstanceStruct;

#endif                                 /*typedef_SFc12_anav_realInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_anav_real_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_anav_real_get_check_sum(mxArray *plhs[]);
extern void c12_anav_real_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
