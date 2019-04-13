/* Include files */

#include "multitime_sfun.h"
#include "c2_multitime.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "multitime_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[6] = { "grid", "r", "h", "nargin",
  "nargout", "inflated1" };

static emlrtRTEInfo c2_emlrtRTEI = { 110,/* lineNo */
  17,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 823,/* lineNo */
  21,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 84,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_d_emlrtRTEI = { 820,/* lineNo */
  21,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_e_emlrtRTEI = { 88,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static const char_T c2_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
  'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

/* Function Declarations */
static void initialize_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance);
static void initialize_params_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance);
static void enable_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance);
static void disable_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance);
static void set_sim_state_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance);
static void sf_gateway_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance);
static void mdl_start_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance);
static void c2_chartstep_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance);
static void initSimStructsc2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_grid, const char_T *c2_identifier, real_T c2_y[3200]);
static void c2_b_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3200]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_randi(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_r
                     [3200]);
static void c2_rand(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_r
                    [3200]);
static void c2_eml_rand_mt19937ar(SFc2_multitimeInstanceStruct *chartInstance,
  uint32_T c2_d_state[625], uint32_T c2_e_state[625], real_T *c2_r);
static void c2_error(SFc2_multitimeInstanceStruct *chartInstance);
static void c2_imfilter(SFc2_multitimeInstanceStruct *chartInstance, real_T
  c2_varargin_1[3200], real_T c2_varargin_2[121], real_T c2_b_b[3200]);
static void c2_svd(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_A[121],
                   real_T c2_U[121], real_T c2_S[121], real_T c2_V[121]);
static boolean_T c2_anyNonFinite(SFc2_multitimeInstanceStruct *chartInstance,
  real_T c2_x[121]);
static void c2_b_svd(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_A
                     [121], real_T c2_U[121], real_T c2_s[11], real_T c2_V[121]);
static void c2_b_error(SFc2_multitimeInstanceStruct *chartInstance);
static void c2_c_error(SFc2_multitimeInstanceStruct *chartInstance, int32_T
  c2_varargin_2);
static void c2_ceval_xgesvd(SFc2_multitimeInstanceStruct *chartInstance, real_T
  c2_A[121], real_T c2_U[121], real_T c2_S[11], real_T c2_V[121], int32_T
  *c2_info);
static void c2_d_error(SFc2_multitimeInstanceStruct *chartInstance, int32_T
  c2_varargin_2);
static real_T c2_sqrt(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_x);
static void c2_e_error(SFc2_multitimeInstanceStruct *chartInstance);
static void c2_f_error(SFc2_multitimeInstanceStruct *chartInstance);
static void c2_diag(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_v[121],
                    real_T c2_d[11]);
static void c2_padImage(SFc2_multitimeInstanceStruct *chartInstance, real_T
  c2_a_tmp[3200], real_T c2_boundary_pos, int8_T c2_boundaryEnum, real_T
  c2_boundaryStr_pos, real_T c2_b_a[4500]);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint32_T c2_e_emlrt_marshallIn(SFc2_multitimeInstanceStruct
  *chartInstance, const mxArray *c2_b_method, const char_T *c2_identifier,
  boolean_T *c2_svPtr);
static uint32_T c2_f_emlrt_marshallIn(SFc2_multitimeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T *c2_svPtr);
static void c2_g_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, boolean_T *c2_svPtr,
  uint32_T c2_y[625]);
static void c2_h_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T
  *c2_svPtr, uint32_T c2_y[625]);
static void c2_i_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, boolean_T *c2_svPtr,
  uint32_T c2_y[2]);
static void c2_j_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T
  *c2_svPtr, uint32_T c2_y[2]);
static uint8_T c2_k_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_multitime, const char_T *c2_identifier);
static uint8_T c2_l_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static real_T c2_b_eml_rand_mt19937ar(SFc2_multitimeInstanceStruct
  *chartInstance, uint32_T c2_d_state[625]);
static void c2_b_sqrt(SFc2_multitimeInstanceStruct *chartInstance, real_T *c2_x);
static void init_dsm_address_info(SFc2_multitimeInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_multitimeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c2_fEmlrtCtx, "Image_Toolbox", 2);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_multitime(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_method_not_empty = false;
  chartInstance->c2_state_not_empty = false;
  chartInstance->c2_b_state_not_empty = false;
  chartInstance->c2_c_state_not_empty = false;
  chartInstance->c2_is_active_c2_multitime = 0U;
}

static void initialize_params_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  uint32_T c2_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  uint32_T c2_b_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  const mxArray *c2_g_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(6, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_inflated1, 0, 0U,
    1U, 0U, 2, 40, 80), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_method;
  c2_c_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_hoistedGlobal, 7, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = chartInstance->c2_state;
  c2_d_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_hoistedGlobal, 7, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_e_y = NULL;
  if (!chartInstance->c2_c_state_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", chartInstance->c2_c_state, 7, 0U,
      1U, 0U, 1, 625), false);
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_f_y = NULL;
  if (!chartInstance->c2_b_state_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", chartInstance->c2_b_state, 7, 0U,
      1U, 0U, 1, 2), false);
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_multitime;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_c_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3200];
  int32_T c2_i0;
  uint32_T c2_uv0[625];
  int32_T c2_i1;
  uint32_T c2_uv1[2];
  int32_T c2_i2;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "inflated1", c2_dv0);
  for (c2_i0 = 0; c2_i0 < 3200; c2_i0++) {
    (*chartInstance->c2_inflated1)[c2_i0] = c2_dv0[c2_i0];
  }

  chartInstance->c2_method = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "method", &chartInstance->c2_method_not_empty);
  chartInstance->c2_state = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "state", &chartInstance->c2_state_not_empty);
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                        "state", &chartInstance->c2_c_state_not_empty, c2_uv0);
  for (c2_i1 = 0; c2_i1 < 625; c2_i1++) {
    chartInstance->c2_c_state[c2_i1] = c2_uv0[c2_i1];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
                        "state", &chartInstance->c2_b_state_not_empty, c2_uv1);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    chartInstance->c2_b_state[c2_i2] = c2_uv1[c2_i2];
  }

  chartInstance->c2_is_active_c2_multitime = c2_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 5)), "is_active_c2_multitime");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_multitime(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_multitime(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i3 = 0; c2_i3 < 3200; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_inflated1)[c2_i3], 0U);
  }
}

static void mdl_start_c2_multitime(SFc2_multitimeInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c2_chartstep_c2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[6];
  real_T c2_grid[3200];
  real_T c2_r;
  real_T c2_h[121];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  real_T c2_b_inflated1[3200];
  real_T c2_dv1[3200];
  int32_T c2_i4;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_i5;
  static real_T c2_dv2[121] = { 0.0, 0.0, 0.0, 0.0012496038320163742,
    0.0049669471840339948, 0.0062599347021485806, 0.0049669471840339948,
    0.0012496038320163742, 0.0, 0.0, 0.0, 0.0, 3.2046417151121444E-5,
    0.00615706957966511, 0.012395873558578515, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012395873558578515,
    0.00615706957966511, 3.2046417151121444E-5, 0.0, 0.0, 0.00615706957966511,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.00615706957966511, 0.0, 0.0012496038320163742,
    0.012395873558578515, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012395873558578515,
    0.0012496038320163742, 0.0049669471840339948, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.0049669471840339948,
    0.0062599347021485806, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.0062599347021485806, 0.0049669471840339948,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.0049669471840339948, 0.0012496038320163742, 0.012395873558578515,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012395873558578515, 0.0012496038320163742, 0.0,
    0.00615706957966511, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012732395447351627, 0.012732395447351627, 0.00615706957966511, 0.0, 0.0,
    3.2046417151121444E-5, 0.00615706957966511, 0.012395873558578515,
    0.012732395447351627, 0.012732395447351627, 0.012732395447351627,
    0.012395873558578515, 0.00615706957966511, 3.2046417151121444E-5, 0.0, 0.0,
    0.0, 0.0, 0.0012496038320163742, 0.0049669471840339948,
    0.0062599347021485806, 0.0049669471840339948, 0.0012496038320163742, 0.0,
    0.0, 0.0 };

  int32_T c2_i6;
  static int32_T c2_iv0[101] = { 3, 4, 5, 6, 7, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 34, 35, 36, 37, 38, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 89, 90, 91, 92, 93, 94, 95, 96, 97, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 113, 114, 115, 116, 117 };

  int32_T c2_i7;
  int32_T c2_i8;
  real_T c2_b_grid[3200];
  real_T c2_b_h[121];
  real_T c2_dv3[3200];
  int32_T c2_i9;
  int32_T c2_i10;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_grid, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_r, 1U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_h, 2U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_inflated1, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_randi(chartInstance, c2_dv1);
  for (c2_i4 = 0; c2_i4 < 3200; c2_i4++) {
    c2_grid[c2_i4] = c2_dv1[c2_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_i = 0;
  while (c2_i <= 3199) {
    c2_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c2_b_i = 0;
  while (c2_b_i <= 3199) {
    if (c2_grid[c2_b_i] > 1.0) {
      c2_grid[c2_b_i] = 0.0;
    }

    c2_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_r = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i5 = 0; c2_i5 < 121; c2_i5++) {
    c2_h[c2_i5] = c2_dv2[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i6 = 0; c2_i6 < 101; c2_i6++) {
    c2_h[c2_iv0[c2_i6]] = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  for (c2_i7 = 0; c2_i7 < 3200; c2_i7++) {
    c2_b_grid[c2_i7] = c2_grid[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 121; c2_i8++) {
    c2_b_h[c2_i8] = c2_h[c2_i8];
  }

  c2_imfilter(chartInstance, c2_b_grid, c2_b_h, c2_dv3);
  for (c2_i9 = 0; c2_i9 < 3200; c2_i9++) {
    c2_b_inflated1[c2_i9] = c2_dv3[c2_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i10 = 0; c2_i10 < 3200; c2_i10++) {
    (*chartInstance->c2_inflated1)[c2_i10] = c2_b_inflated1[c2_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_multitime(SFc2_multitimeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i11;
  int32_T c2_i12;
  const mxArray *c2_y = NULL;
  int32_T c2_i13;
  real_T c2_u[3200];
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i11 = 0;
  for (c2_i12 = 0; c2_i12 < 80; c2_i12++) {
    for (c2_i13 = 0; c2_i13 < 40; c2_i13++) {
      c2_u[c2_i13 + c2_i11] = (*(real_T (*)[3200])c2_inData)[c2_i13 + c2_i11];
    }

    c2_i11 += 40;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 40, 80), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_grid, const char_T *c2_identifier, real_T c2_y[3200])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_grid), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_grid);
}

static void c2_b_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3200])
{
  real_T c2_dv4[3200];
  int32_T c2_i14;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 40,
                80);
  for (c2_i14 = 0; c2_i14 < 3200; c2_i14++) {
    c2_y[c2_i14] = c2_dv4[c2_i14];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_grid;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3200];
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)chartInstanceVoid;
  c2_grid = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_grid), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_grid);
  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 80; c2_i16++) {
    for (c2_i17 = 0; c2_i17 < 40; c2_i17++) {
      (*(real_T (*)[3200])c2_outData)[c2_i17 + c2_i15] = c2_y[c2_i17 + c2_i15];
    }

    c2_i15 += 40;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i18;
  int32_T c2_i19;
  const mxArray *c2_y = NULL;
  int32_T c2_i20;
  real_T c2_u[121];
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i18 = 0;
  for (c2_i19 = 0; c2_i19 < 11; c2_i19++) {
    for (c2_i20 = 0; c2_i20 < 11; c2_i20++) {
      c2_u[c2_i20 + c2_i18] = (*(real_T (*)[121])c2_inData)[c2_i20 + c2_i18];
    }

    c2_i18 += 11;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 11, 11), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargin;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)chartInstanceVoid;
  c2_nargin = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargin), &c2_thisId);
  sf_mex_destroy(&c2_nargin);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_multitime_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_randi(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_r
                     [3200])
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x;
  real_T c2_b_x;
  c2_rand(chartInstance, c2_r);
  for (c2_k = 0; c2_k < 3200; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x = c2_r[(int32_T)c2_b_k - 1] * 100.0;
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarFloor(c2_b_x);
    c2_r[(int32_T)c2_b_k - 1] = 1.0 + c2_b_x;
  }
}

static void c2_rand(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_r
                    [3200])
{
  int32_T c2_i21;
  int32_T c2_k;
  uint32_T c2_b_r;
  real_T c2_b_k;
  real_T c2_d1;
  int32_T c2_mti;
  real_T c2_b_mti;
  real_T c2_d2;
  uint32_T c2_u0;
  if (!chartInstance->c2_method_not_empty) {
    chartInstance->c2_method = 7U;
    chartInstance->c2_method_not_empty = true;
  }

  if (!chartInstance->c2_c_state_not_empty) {
    for (c2_i21 = 0; c2_i21 < 625; c2_i21++) {
      chartInstance->c2_c_state[c2_i21] = 0U;
    }

    c2_b_r = 5489U;
    chartInstance->c2_c_state[0] = 5489U;
    for (c2_mti = 0; c2_mti < 623; c2_mti++) {
      c2_b_mti = 2.0 + (real_T)c2_mti;
      c2_d2 = muDoubleScalarRound(c2_b_mti - 1.0);
      if (c2_d2 < 4.294967296E+9) {
        if (c2_d2 >= 0.0) {
          c2_u0 = (uint32_T)c2_d2;
        } else {
          c2_u0 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c2_d2 >= 4.294967296E+9) {
        c2_u0 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_u0 = 0U;
      }

      c2_b_r = (c2_b_r ^ c2_b_r >> 30U) * 1812433253U + c2_u0;
      chartInstance->c2_c_state[(int32_T)c2_b_mti - 1] = c2_b_r;
    }

    chartInstance->c2_c_state[624] = 624U;
    chartInstance->c2_c_state_not_empty = true;
  }

  for (c2_k = 0; c2_k < 3200; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d1 = c2_b_eml_rand_mt19937ar(chartInstance, chartInstance->c2_c_state);
    c2_r[(int32_T)c2_b_k - 1] = c2_d1;
  }
}

static void c2_eml_rand_mt19937ar(SFc2_multitimeInstanceStruct *chartInstance,
  uint32_T c2_d_state[625], uint32_T c2_e_state[625], real_T *c2_r)
{
  int32_T c2_i22;
  for (c2_i22 = 0; c2_i22 < 625; c2_i22++) {
    c2_e_state[c2_i22] = c2_d_state[c2_i22];
  }

  *c2_r = c2_b_eml_rand_mt19937ar(chartInstance, c2_e_state);
}

static void c2_error(SFc2_multitimeInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv1[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 37),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 37),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 1U,
    14, c2_b_y)));
}

static void c2_imfilter(SFc2_multitimeInstanceStruct *chartInstance, real_T
  c2_varargin_1[3200], real_T c2_varargin_2[121], real_T c2_b_b[3200])
{
  int32_T c2_i23;
  real_T c2_b_varargin_2[121];
  real_T c2_unusedU0[121];
  real_T c2_s[121];
  real_T c2_unusedU1[121];
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_x;
  real_T c2_b_s[11];
  real_T c2_b_x;
  boolean_T c2_c_b;
  boolean_T c2_p;
  int32_T c2_idx;
  int32_T c2_c_k;
  int32_T c2_first;
  real_T c2_maxval;
  real_T c2_c_x;
  real_T c2_ex;
  real_T c2_d_x;
  int32_T c2_i24;
  real_T c2_tol;
  boolean_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_i25;
  boolean_T c2_b_p;
  real_T c2_rank;
  boolean_T c2_e_x[11];
  int32_T c2_e_k;
  int32_T c2_xoffset;
  boolean_T c2_separable;
  int32_T c2_ix;
  int32_T c2_i26;
  int32_T c2_i27;
  real_T c2_b_varargin_1[3200];
  real_T c2_c_varargin_1[3200];
  int32_T c2_trueCount;
  int32_T c2_i28;
  int32_T c2_i;
  real_T c2_c_varargin_2[121];
  int32_T c2_tmp_size[1];
  int32_T c2_partialTrueCount;
  int32_T c2_i29;
  int32_T c2_b_i;
  real_T c2_e_b;
  real_T c2_hcol[11];
  int32_T c2_nonzero_h_size[1];
  int32_T c2_loop_ub;
  int32_T c2_tmp_data[121];
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  real_T c2_nonzero_h_data[121];
  real_T c2_f_b;
  real_T c2_hrow[11];
  boolean_T c2_densityFlag;
  boolean_T c2_connb[121];
  real_T c2_A;
  int32_T c2_i34;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_y;
  int32_T c2_b_trueCount;
  int32_T c2_c_i;
  boolean_T c2_tooBig;
  int32_T c2_d_i;
  int32_T c2_b_tmp_size[1];
  int32_T c2_b_partialTrueCount;
  int32_T c2_e_i;
  boolean_T c2_modeFlag;
  int32_T c2_b_nonzero_h_size[1];
  int32_T c2_b_loop_ub;
  int32_T c2_b_tmp_data[11];
  int32_T c2_i35;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  int32_T c2_i36;
  real_T c2_b_nonzero_h_data[11];
  real_T c2_numKernElem;
  int32_T c2_i37;
  int32_T c2_i38;
  boolean_T c2_b_densityFlag;
  real_T c2_b_A;
  int32_T c2_i39;
  real_T c2_padSizeT[2];
  real_T c2_h_x;
  int32_T c2_i40;
  real_T c2_i_x;
  real_T c2_b_y;
  int32_T c2_i41;
  real_T c2_outSizeT[2];
  int32_T c2_i42;
  boolean_T c2_b_tooBig;
  real_T c2_connDimsT[2];
  int32_T c2_f_i;
  int32_T c2_i43;
  real_T c2_startT[2];
  boolean_T c2_d_modeFlag;
  boolean_T c2_e_modeFlag;
  int32_T c2_i44;
  boolean_T c2_f_modeFlag;
  real_T c2_b_numKernElem;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_c_trueCount;
  int32_T c2_g_i;
  int32_T c2_i52;
  int32_T c2_c_tmp_size[1];
  int32_T c2_c_partialTrueCount;
  int32_T c2_h_i;
  int32_T c2_c_loop_ub;
  int32_T c2_c_tmp_data[11];
  int32_T c2_i53;
  int32_T c2_i54;
  boolean_T c2_c_densityFlag;
  real_T c2_c_A;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_c_y;
  boolean_T c2_c_tooBig;
  int32_T c2_i_i;
  boolean_T c2_g_modeFlag;
  boolean_T c2_h_modeFlag;
  boolean_T c2_i_modeFlag;
  real_T c2_c_numKernElem;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  boolean_T exitg1;
  for (c2_i23 = 0; c2_i23 < 121; c2_i23++) {
    c2_b_varargin_2[c2_i23] = c2_varargin_2[c2_i23];
  }

  c2_svd(chartInstance, c2_b_varargin_2, c2_unusedU0, c2_s, c2_unusedU1);
  c2_k = 0;
  for (c2_b_k = 0; c2_b_k < 11; c2_b_k++) {
    c2_b_s[c2_b_k] = c2_s[c2_k];
    c2_k += 12;
  }

  c2_x = c2_b_s[0];
  c2_b_x = c2_x;
  c2_c_b = muDoubleScalarIsNaN(c2_b_x);
  c2_p = !c2_c_b;
  if (c2_p) {
    c2_idx = 1;
  } else {
    c2_idx = 0;
    c2_c_k = 2;
    exitg1 = false;
    while ((!exitg1) && (c2_c_k < 12)) {
      c2_c_x = c2_b_s[c2_c_k - 1];
      c2_d_x = c2_c_x;
      c2_d_b = muDoubleScalarIsNaN(c2_d_x);
      c2_b_p = !c2_d_b;
      if (c2_b_p) {
        c2_idx = c2_c_k;
        exitg1 = true;
      } else {
        c2_c_k++;
      }
    }
  }

  if (c2_idx == 0) {
    c2_maxval = c2_b_s[0];
  } else {
    c2_first = c2_idx;
    c2_ex = c2_b_s[c2_first - 1];
    c2_i24 = c2_first;
    for (c2_d_k = c2_i24; c2_d_k + 1 < 12; c2_d_k++) {
      if (c2_ex < c2_b_s[c2_d_k]) {
        c2_ex = c2_b_s[c2_d_k];
      }
    }

    c2_maxval = c2_ex;
  }

  c2_tol = 11.0 * c2_maxval * 2.2204460492503131E-16;
  for (c2_i25 = 0; c2_i25 < 11; c2_i25++) {
    c2_e_x[c2_i25] = (c2_b_s[c2_i25] > c2_tol);
  }

  c2_rank = (real_T)c2_e_x[0];
  for (c2_e_k = 0; c2_e_k < 10; c2_e_k++) {
    c2_xoffset = c2_e_k;
    c2_ix = c2_xoffset + 1;
    c2_rank += (real_T)c2_e_x[c2_ix];
  }

  if (c2_rank == 1.0) {
    c2_separable = true;
  } else {
    c2_separable = false;
  }

  if (c2_separable) {
    for (c2_i27 = 0; c2_i27 < 3200; c2_i27++) {
      c2_c_varargin_1[c2_i27] = c2_varargin_1[c2_i27];
    }

    c2_padImage(chartInstance, c2_c_varargin_1, 0.0, 0, 0.0, chartInstance->c2_a);
    for (c2_i28 = 0; c2_i28 < 121; c2_i28++) {
      c2_c_varargin_2[c2_i28] = c2_varargin_2[c2_i28];
    }

    c2_svd(chartInstance, c2_c_varargin_2, c2_unusedU0, c2_s, c2_unusedU1);
    c2_diag(chartInstance, c2_s, c2_b_s);
    for (c2_i29 = 0; c2_i29 < 11; c2_i29++) {
      c2_hcol[c2_i29] = c2_unusedU0[c2_i29];
    }

    c2_e_b = c2_b_s[0];
    c2_b_sqrt(chartInstance, &c2_e_b);
    for (c2_i30 = 0; c2_i30 < 11; c2_i30++) {
      c2_hcol[c2_i30] *= c2_e_b;
    }

    for (c2_i32 = 0; c2_i32 < 11; c2_i32++) {
      c2_hrow[c2_i32] = c2_unusedU1[c2_i32];
    }

    c2_f_b = c2_b_s[0];
    c2_b_sqrt(chartInstance, &c2_f_b);
    for (c2_i34 = 0; c2_i34 < 11; c2_i34++) {
      c2_hrow[c2_i34] *= c2_f_b;
    }

    c2_b_trueCount = 0;
    for (c2_c_i = 0; c2_c_i < 11; c2_c_i++) {
      if (c2_hrow[c2_c_i] != 0.0) {
        c2_b_trueCount++;
      }
    }

    c2_b_tmp_size[0] = c2_b_trueCount;
    c2_b_partialTrueCount = 0;
    for (c2_e_i = 0; c2_e_i < 11; c2_e_i++) {
      if (c2_hrow[c2_e_i] != 0.0) {
        c2_b_tmp_data[c2_b_partialTrueCount] = c2_e_i + 1;
        c2_b_partialTrueCount++;
      }
    }

    c2_b_nonzero_h_size[0] = c2_b_tmp_size[0];
    c2_b_loop_ub = c2_b_tmp_size[0] - 1;
    for (c2_i35 = 0; c2_i35 <= c2_b_loop_ub; c2_i35++) {
      c2_b_nonzero_h_data[c2_i35] = c2_hrow[c2_b_tmp_data[c2_i35] - 1];
    }

    for (c2_i36 = 0; c2_i36 < 11; c2_i36++) {
      c2_e_x[c2_i36] = (c2_hrow[c2_i36] != 0.0);
    }

    c2_b_densityFlag = false;
    c2_b_A = (real_T)c2_b_nonzero_h_size[0];
    c2_h_x = c2_b_A;
    c2_i_x = c2_h_x;
    c2_b_y = c2_i_x / 11.0;
    if (c2_b_y > 0.05) {
      c2_b_densityFlag = true;
    }

    c2_b_tooBig = true;
    for (c2_f_i = 0; c2_f_i < 2; c2_f_i++) {
      c2_b_tooBig = false;
    }

    if (c2_b_densityFlag && (!c2_b_tooBig)) {
      c2_d_modeFlag = true;
    } else {
      c2_d_modeFlag = false;
    }

    if (c2_d_modeFlag) {
      c2_e_modeFlag = true;
    } else {
      c2_e_modeFlag = false;
    }

    for (c2_i44 = 0; c2_i44 < 11; c2_i44++) {
      c2_e_x[c2_i44];
    }

    c2_f_modeFlag = c2_e_modeFlag;
    if (c2_f_modeFlag) {
      for (c2_i45 = 0; c2_i45 < 2; c2_i45++) {
        c2_padSizeT[c2_i45] = 50.0 + 40.0 * (real_T)c2_i45;
      }

      for (c2_i47 = 0; c2_i47 < 2; c2_i47++) {
        c2_outSizeT[c2_i47] = 50.0 + 30.0 * (real_T)c2_i47;
      }

      for (c2_i49 = 0; c2_i49 < 2; c2_i49++) {
        c2_connDimsT[c2_i49] = 1.0 + 10.0 * (real_T)c2_i49;
      }

      ippfilter_real64(chartInstance->c2_a, chartInstance->c2_b, c2_outSizeT,
                       2.0, c2_padSizeT, c2_hrow, c2_connDimsT, false);
    } else {
      c2_b_numKernElem = (real_T)c2_b_nonzero_h_size[0];
      for (c2_i46 = 0; c2_i46 < 11; c2_i46++) {
        c2_e_x[c2_i46];
      }

      for (c2_i48 = 0; c2_i48 < 2; c2_i48++) {
        c2_padSizeT[c2_i48] = 50.0 + 40.0 * (real_T)c2_i48;
      }

      for (c2_i50 = 0; c2_i50 < 2; c2_i50++) {
        c2_outSizeT[c2_i50] = 50.0 + 30.0 * (real_T)c2_i50;
      }

      for (c2_i51 = 0; c2_i51 < 2; c2_i51++) {
        c2_connDimsT[c2_i51] = 1.0 + 10.0 * (real_T)c2_i51;
      }

      for (c2_i52 = 0; c2_i52 < 2; c2_i52++) {
        c2_startT[c2_i52] = 5.0 * (real_T)c2_i52;
      }

      imfilter_real64(chartInstance->c2_a, chartInstance->c2_b, 2.0, c2_outSizeT,
                      2.0, c2_padSizeT, &c2_b_nonzero_h_data[0],
                      c2_b_numKernElem, c2_e_x, 2.0, c2_connDimsT, c2_startT,
                      2.0, true, false);
    }

    c2_c_trueCount = 0;
    for (c2_g_i = 0; c2_g_i < 11; c2_g_i++) {
      if (c2_hcol[c2_g_i] != 0.0) {
        c2_c_trueCount++;
      }
    }

    c2_c_tmp_size[0] = c2_c_trueCount;
    c2_c_partialTrueCount = 0;
    for (c2_h_i = 0; c2_h_i < 11; c2_h_i++) {
      if (c2_hcol[c2_h_i] != 0.0) {
        c2_c_tmp_data[c2_c_partialTrueCount] = c2_h_i + 1;
        c2_c_partialTrueCount++;
      }
    }

    c2_b_nonzero_h_size[0] = c2_c_tmp_size[0];
    c2_c_loop_ub = c2_c_tmp_size[0] - 1;
    for (c2_i53 = 0; c2_i53 <= c2_c_loop_ub; c2_i53++) {
      c2_b_nonzero_h_data[c2_i53] = c2_hcol[c2_c_tmp_data[c2_i53] - 1];
    }

    for (c2_i54 = 0; c2_i54 < 11; c2_i54++) {
      c2_e_x[c2_i54] = (c2_hcol[c2_i54] != 0.0);
    }

    c2_c_densityFlag = false;
    c2_c_A = (real_T)c2_b_nonzero_h_size[0];
    c2_j_x = c2_c_A;
    c2_k_x = c2_j_x;
    c2_c_y = c2_k_x / 11.0;
    if (c2_c_y > 0.05) {
      c2_c_densityFlag = true;
    }

    c2_c_tooBig = true;
    for (c2_i_i = 0; c2_i_i < 2; c2_i_i++) {
      c2_c_tooBig = false;
    }

    if (c2_c_densityFlag && (!c2_c_tooBig)) {
      c2_g_modeFlag = true;
    } else {
      c2_g_modeFlag = false;
    }

    if (c2_g_modeFlag) {
      c2_h_modeFlag = true;
    } else {
      c2_h_modeFlag = false;
    }

    c2_i_modeFlag = c2_h_modeFlag;
    if (c2_i_modeFlag) {
      for (c2_i55 = 0; c2_i55 < 2; c2_i55++) {
        c2_padSizeT[c2_i55] = 50.0 + 30.0 * (real_T)c2_i55;
      }

      for (c2_i57 = 0; c2_i57 < 2; c2_i57++) {
        c2_outSizeT[c2_i57] = 40.0 + 40.0 * (real_T)c2_i57;
      }

      for (c2_i59 = 0; c2_i59 < 2; c2_i59++) {
        c2_connDimsT[c2_i59] = 11.0 + -10.0 * (real_T)c2_i59;
      }

      ippfilter_real64(chartInstance->c2_b, c2_b_b, c2_outSizeT, 2.0,
                       c2_padSizeT, c2_hcol, c2_connDimsT, false);
    } else {
      c2_c_numKernElem = (real_T)c2_b_nonzero_h_size[0];
      for (c2_i56 = 0; c2_i56 < 2; c2_i56++) {
        c2_padSizeT[c2_i56] = 50.0 + 30.0 * (real_T)c2_i56;
      }

      for (c2_i58 = 0; c2_i58 < 2; c2_i58++) {
        c2_outSizeT[c2_i58] = 40.0 + 40.0 * (real_T)c2_i58;
      }

      for (c2_i60 = 0; c2_i60 < 2; c2_i60++) {
        c2_connDimsT[c2_i60] = 11.0 + -10.0 * (real_T)c2_i60;
      }

      for (c2_i61 = 0; c2_i61 < 2; c2_i61++) {
        c2_startT[c2_i61] = 5.0 + -5.0 * (real_T)c2_i61;
      }

      imfilter_real64(chartInstance->c2_b, c2_b_b, 2.0, c2_outSizeT, 2.0,
                      c2_padSizeT, &c2_b_nonzero_h_data[0], c2_c_numKernElem,
                      c2_e_x, 2.0, c2_connDimsT, c2_startT, 2.0, true, false);
    }
  } else {
    for (c2_i26 = 0; c2_i26 < 3200; c2_i26++) {
      c2_b_varargin_1[c2_i26] = c2_varargin_1[c2_i26];
    }

    c2_padImage(chartInstance, c2_b_varargin_1, 0.0, 0, 0.0, chartInstance->c2_a);
    c2_trueCount = 0;
    for (c2_i = 0; c2_i < 121; c2_i++) {
      if (c2_varargin_2[c2_i] != 0.0) {
        c2_trueCount++;
      }
    }

    c2_tmp_size[0] = c2_trueCount;
    c2_partialTrueCount = 0;
    for (c2_b_i = 0; c2_b_i < 121; c2_b_i++) {
      if (c2_varargin_2[c2_b_i] != 0.0) {
        c2_tmp_data[c2_partialTrueCount] = c2_b_i + 1;
        c2_partialTrueCount++;
      }
    }

    c2_nonzero_h_size[0] = c2_tmp_size[0];
    c2_loop_ub = c2_tmp_size[0] - 1;
    for (c2_i31 = 0; c2_i31 <= c2_loop_ub; c2_i31++) {
      c2_nonzero_h_data[c2_i31] = c2_varargin_2[c2_tmp_data[c2_i31] - 1];
    }

    for (c2_i33 = 0; c2_i33 < 121; c2_i33++) {
      c2_connb[c2_i33] = (c2_varargin_2[c2_i33] != 0.0);
    }

    c2_densityFlag = false;
    c2_A = (real_T)c2_nonzero_h_size[0];
    c2_f_x = c2_A;
    c2_g_x = c2_f_x;
    c2_y = c2_g_x / 121.0;
    if (c2_y > 0.05) {
      c2_densityFlag = true;
    }

    c2_tooBig = true;
    for (c2_d_i = 0; c2_d_i < 2; c2_d_i++) {
      c2_tooBig = false;
    }

    if (c2_densityFlag && (!c2_tooBig)) {
      c2_modeFlag = true;
    } else {
      c2_modeFlag = false;
    }

    if (c2_modeFlag) {
      c2_b_modeFlag = true;
    } else {
      c2_b_modeFlag = false;
    }

    c2_c_modeFlag = c2_b_modeFlag;
    if (c2_c_modeFlag) {
      for (c2_i37 = 0; c2_i37 < 2; c2_i37++) {
        c2_padSizeT[c2_i37] = 50.0 + 40.0 * (real_T)c2_i37;
      }

      for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
        c2_outSizeT[c2_i39] = 40.0 + 40.0 * (real_T)c2_i39;
      }

      for (c2_i41 = 0; c2_i41 < 2; c2_i41++) {
        c2_connDimsT[c2_i41] = 11.0;
      }

      ippfilter_real64(chartInstance->c2_a, c2_b_b, c2_outSizeT, 2.0,
                       c2_padSizeT, c2_varargin_2, c2_connDimsT, false);
    } else {
      c2_numKernElem = (real_T)c2_nonzero_h_size[0];
      for (c2_i38 = 0; c2_i38 < 2; c2_i38++) {
        c2_padSizeT[c2_i38] = 50.0 + 40.0 * (real_T)c2_i38;
      }

      for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
        c2_outSizeT[c2_i40] = 40.0 + 40.0 * (real_T)c2_i40;
      }

      for (c2_i42 = 0; c2_i42 < 2; c2_i42++) {
        c2_connDimsT[c2_i42] = 11.0;
      }

      for (c2_i43 = 0; c2_i43 < 2; c2_i43++) {
        c2_startT[c2_i43] = 5.0;
      }

      imfilter_real64(chartInstance->c2_a, c2_b_b, 2.0, c2_outSizeT, 2.0,
                      c2_padSizeT, &c2_nonzero_h_data[0], c2_numKernElem,
                      c2_connb, 2.0, c2_connDimsT, c2_startT, 2.0, true, false);
    }
  }
}

static void c2_svd(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_A[121],
                   real_T c2_U[121], real_T c2_S[121], real_T c2_V[121])
{
  int32_T c2_i62;
  boolean_T c2_allFiniteA;
  real_T c2_b_A[121];
  int32_T c2_i63;
  int32_T c2_i64;
  real_T c2_dv5[121];
  real_T c2_U1[121];
  real_T c2_s[11];
  real_T c2_V1[121];
  real_T c2_c_A[121];
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i68;
  for (c2_i62 = 0; c2_i62 < 121; c2_i62++) {
    c2_b_A[c2_i62] = c2_A[c2_i62];
  }

  c2_allFiniteA = !c2_anyNonFinite(chartInstance, c2_b_A);
  if (c2_allFiniteA) {
    for (c2_i64 = 0; c2_i64 < 121; c2_i64++) {
      c2_c_A[c2_i64] = c2_A[c2_i64];
    }

    c2_b_svd(chartInstance, c2_c_A, c2_U, c2_s, c2_V);
  } else {
    for (c2_i63 = 0; c2_i63 < 121; c2_i63++) {
      c2_dv5[c2_i63] = 0.0;
    }

    c2_b_svd(chartInstance, c2_dv5, c2_U1, c2_s, c2_V1);
    for (c2_i65 = 0; c2_i65 < 121; c2_i65++) {
      c2_U[c2_i65] = rtNaN;
    }

    for (c2_i67 = 0; c2_i67 < 11; c2_i67++) {
      c2_s[c2_i67] = rtNaN;
    }

    for (c2_i68 = 0; c2_i68 < 121; c2_i68++) {
      c2_V[c2_i68] = rtNaN;
    }
  }

  for (c2_i66 = 0; c2_i66 < 121; c2_i66++) {
    c2_S[c2_i66] = 0.0;
  }

  c2_k = 0;
  for (c2_b_k = 0; c2_b_k < 11; c2_b_k++) {
    c2_S[c2_k] = c2_s[c2_b_k];
    c2_k += 12;
  }
}

static boolean_T c2_anyNonFinite(SFc2_multitimeInstanceStruct *chartInstance,
  real_T c2_x[121])
{
  boolean_T c2_b_p;
  int32_T c2_k;
  boolean_T c2_c_p;
  (void)chartInstance;
  (void)c2_x;
  c2_b_p = true;
  for (c2_k = 0; c2_k < 121; c2_k++) {
    if (c2_b_p) {
      c2_c_p = true;
    } else {
      c2_c_p = false;
    }

    c2_b_p = c2_c_p;
  }

  return !c2_b_p;
}

static void c2_b_svd(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_A
                     [121], real_T c2_U[121], real_T c2_s[11], real_T c2_V[121])
{
  int32_T c2_i69;
  ptrdiff_t c2_m_t;
  real_T c2_b_A[121];
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldu_t;
  ptrdiff_t c2_ldv_t;
  ptrdiff_t c2_info_t;
  real_T c2_Vt[121];
  int32_T c2_info;
  int32_T c2_b_info;
  int32_T c2_c_info;
  boolean_T c2_p;
  int32_T c2_d_info;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_e_info;
  int32_T c2_i73;
  int32_T c2_f_info;
  int32_T c2_i74;
  for (c2_i69 = 0; c2_i69 < 121; c2_i69++) {
    c2_b_A[c2_i69] = c2_A[c2_i69];
  }

  c2_m_t = (ptrdiff_t)11;
  c2_n_t = (ptrdiff_t)11;
  c2_lda_t = (ptrdiff_t)11;
  c2_ldu_t = (ptrdiff_t)11;
  c2_ldv_t = (ptrdiff_t)11;
  c2_info_t = LAPACKE_dgesdd(102, 'A', c2_m_t, c2_n_t, &c2_b_A[0], c2_lda_t,
    &c2_s[0], &c2_U[0], c2_ldu_t, &c2_Vt[0], c2_ldv_t);
  c2_info = (int32_T)c2_info_t;
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_p = (c2_c_info < 0);
  if (c2_p) {
    if (c2_b_info == -1010) {
      c2_b_error(chartInstance);
    } else {
      c2_c_error(chartInstance, c2_b_info);
    }
  }

  c2_d_info = c2_info;
  if (c2_info > 0) {
    for (c2_i71 = 0; c2_i71 < 121; c2_i71++) {
      c2_b_A[c2_i71] = c2_A[c2_i71];
    }

    c2_ceval_xgesvd(chartInstance, c2_b_A, c2_U, c2_s, c2_V, &c2_e_info);
    c2_f_info = c2_e_info;
    c2_d_info = c2_f_info;
  } else {
    c2_i70 = 0;
    for (c2_i72 = 0; c2_i72 < 11; c2_i72++) {
      c2_i73 = 0;
      for (c2_i74 = 0; c2_i74 < 11; c2_i74++) {
        c2_V[c2_i74 + c2_i70] = c2_Vt[c2_i73 + c2_i72];
        c2_i73 += 11;
      }

      c2_i70 += 11;
    }
  }

  if (c2_d_info > 0) {
    c2_f_error(chartInstance);
  }
}

static void c2_b_error(SFc2_multitimeInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv2[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 1U,
    14, c2_b_y)));
}

static void c2_c_error(SFc2_multitimeInstanceStruct *chartInstance, int32_T
  c2_varargin_2)
{
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv3[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 's', 'd', 'd' };

  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 3U,
    14, c2_b_y, 14, c2_c_y, 14, c2_d_y)));
}

static void c2_ceval_xgesvd(SFc2_multitimeInstanceStruct *chartInstance, real_T
  c2_A[121], real_T c2_U[121], real_T c2_S[11], real_T c2_V[121], int32_T
  *c2_info)
{
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldu_t;
  ptrdiff_t c2_ldv_t;
  ptrdiff_t c2_info_t;
  real_T c2_Vt[121];
  real_T c2_superb[10];
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_b_info;
  int32_T c2_i77;
  int32_T c2_c_info;
  int32_T c2_i78;
  boolean_T c2_p;
  c2_m_t = (ptrdiff_t)11;
  c2_n_t = (ptrdiff_t)11;
  c2_lda_t = (ptrdiff_t)11;
  c2_ldu_t = (ptrdiff_t)11;
  c2_ldv_t = (ptrdiff_t)11;
  c2_info_t = LAPACKE_dgesvd(102, 'A', 'A', c2_m_t, c2_n_t, &c2_A[0], c2_lda_t,
    &c2_S[0], &c2_U[0], c2_ldu_t, &c2_Vt[0], c2_ldv_t, &c2_superb[0]);
  *c2_info = (int32_T)c2_info_t;
  c2_i75 = 0;
  for (c2_i76 = 0; c2_i76 < 11; c2_i76++) {
    c2_i77 = 0;
    for (c2_i78 = 0; c2_i78 < 11; c2_i78++) {
      c2_V[c2_i78 + c2_i75] = c2_Vt[c2_i77 + c2_i76];
      c2_i77 += 11;
    }

    c2_i75 += 11;
  }

  c2_b_info = *c2_info;
  c2_c_info = c2_b_info;
  c2_p = (c2_c_info < 0);
  if (c2_p) {
    if (c2_b_info == -1010) {
      c2_b_error(chartInstance);
    } else {
      c2_d_error(chartInstance, c2_b_info);
    }
  }
}

static void c2_d_error(SFc2_multitimeInstanceStruct *chartInstance, int32_T
  c2_varargin_2)
{
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv4[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 's', 'v', 'd' };

  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 3U,
    14, c2_b_y, 14, c2_c_y, 14, c2_d_y)));
}

static real_T c2_sqrt(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_e_error(SFc2_multitimeInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv5[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv6[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 2U,
    14, c2_b_y, 14, c2_c_y)));
}

static void c2_f_error(SFc2_multitimeInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv7[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 1U,
    14, c2_b_y)));
}

static void c2_diag(SFc2_multitimeInstanceStruct *chartInstance, real_T c2_v[121],
                    real_T c2_d[11])
{
  int32_T c2_k;
  int32_T c2_b_k;
  (void)chartInstance;
  c2_k = 0;
  for (c2_b_k = 0; c2_b_k < 11; c2_b_k++) {
    c2_d[c2_b_k] = c2_v[c2_k];
    c2_k += 12;
  }
}

static void c2_padImage(SFc2_multitimeInstanceStruct *chartInstance, real_T
  c2_a_tmp[3200], real_T c2_boundary_pos, int8_T c2_boundaryEnum, real_T
  c2_boundaryStr_pos, real_T c2_b_a[4500])
{
  int32_T c2_j;
  int32_T c2_b_j;
  real_T c2_c_j;
  int32_T c2_i;
  int32_T c2_d_j;
  int32_T c2_b_i;
  real_T c2_c_i;
  int32_T c2_e_j;
  int32_T c2_d_i;
  int32_T c2_f_j;
  int32_T c2_e_i;
  real_T c2_c_a;
  int32_T c2_c;
  int32_T c2_f_i;
  real_T c2_d_a;
  int32_T c2_b_c;
  real_T c2_e_a;
  int32_T c2_c_c;
  real_T c2_f_a;
  int32_T c2_d_c;
  (void)chartInstance;
  (void)c2_boundary_pos;
  (void)c2_boundaryEnum;
  (void)c2_boundaryStr_pos;
  for (c2_j = 0; c2_j < 5; c2_j++) {
    c2_c_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 50; c2_i++) {
      c2_c_i = 1.0 + (real_T)c2_i;
      c2_b_a[((int32_T)c2_c_i + 50 * ((int32_T)c2_c_j - 1)) - 1] = 0.0;
    }
  }

  for (c2_b_j = 0; c2_b_j < 5; c2_b_j++) {
    for (c2_b_i = 0; c2_b_i < 50; c2_b_i++) {
      c2_c_i = 1.0 + (real_T)c2_b_i;
      c2_b_a[((int32_T)c2_c_i + 50 * (c2_b_j + 85)) - 1] = 0.0;
    }
  }

  for (c2_d_j = 0; c2_d_j < 80; c2_d_j++) {
    c2_c_j = 1.0 + (real_T)c2_d_j;
    for (c2_d_i = 0; c2_d_i < 5; c2_d_i++) {
      c2_c_i = 1.0 + (real_T)c2_d_i;
      c2_c_a = c2_c_j;
      c2_c = (int32_T)c2_c_a;
      c2_b_a[((int32_T)c2_c_i + 50 * (c2_c + 4)) - 1] = 0.0;
    }
  }

  for (c2_e_j = 0; c2_e_j < 80; c2_e_j++) {
    c2_c_j = 1.0 + (real_T)c2_e_j;
    for (c2_e_i = 0; c2_e_i < 5; c2_e_i++) {
      c2_d_a = c2_c_j;
      c2_b_c = (int32_T)c2_d_a;
      c2_b_a[(c2_e_i + 50 * (c2_b_c + 4)) + 45] = 0.0;
    }
  }

  for (c2_f_j = 0; c2_f_j < 80; c2_f_j++) {
    c2_c_j = 1.0 + (real_T)c2_f_j;
    for (c2_f_i = 0; c2_f_i < 40; c2_f_i++) {
      c2_c_i = 1.0 + (real_T)c2_f_i;
      c2_e_a = c2_c_i;
      c2_c_c = (int32_T)c2_e_a;
      c2_f_a = c2_c_j;
      c2_d_c = (int32_T)c2_f_a;
      c2_b_a[(c2_c_c + 50 * (c2_d_c + 4)) + 4] = c2_a_tmp[((int32_T)c2_c_i + 40 *
        ((int32_T)c2_c_j - 1)) - 1];
    }
  }
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i79;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i79, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i79;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint32_T c2_e_emlrt_marshallIn(SFc2_multitimeInstanceStruct
  *chartInstance, const mxArray *c2_b_method, const char_T *c2_identifier,
  boolean_T *c2_svPtr)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_method),
    &c2_thisId, c2_svPtr);
  sf_mex_destroy(&c2_b_method);
  return c2_y;
}

static uint32_T c2_f_emlrt_marshallIn(SFc2_multitimeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T *c2_svPtr)
{
  uint32_T c2_y;
  uint32_T c2_u1;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u1, 1, 7, 0U, 0, 0U, 0);
    c2_y = c2_u1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, boolean_T *c2_svPtr,
  uint32_T c2_y[625])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId,
                        c2_svPtr, c2_y);
  sf_mex_destroy(&c2_d_state);
}

static void c2_h_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T
  *c2_svPtr, uint32_T c2_y[625])
{
  uint32_T c2_uv2[625];
  int32_T c2_i80;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv2, 1, 7, 0U, 1, 0U, 1, 625);
    for (c2_i80 = 0; c2_i80 < 625; c2_i80++) {
      c2_y[c2_i80] = c2_uv2[c2_i80];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_i_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, boolean_T *c2_svPtr,
  uint32_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId,
                        c2_svPtr, c2_y);
  sf_mex_destroy(&c2_d_state);
}

static void c2_j_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T
  *c2_svPtr, uint32_T c2_y[2])
{
  uint32_T c2_uv3[2];
  int32_T c2_i81;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv3, 1, 7, 0U, 1, 0U, 1, 2);
    for (c2_i81 = 0; c2_i81 < 2; c2_i81++) {
      c2_y[c2_i81] = c2_uv3[c2_i81];
    }
  }

  sf_mex_destroy(&c2_u);
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_multitime, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_multitime), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_multitime);
  return c2_y;
}

static uint8_T c2_l_emlrt_marshallIn(SFc2_multitimeInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u2;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u2, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static real_T c2_b_eml_rand_mt19937ar(SFc2_multitimeInstanceStruct
  *chartInstance, uint32_T c2_d_state[625])
{
  int32_T c2_j;
  uint32_T c2_u[2];
  real_T c2_b_j;
  uint32_T c2_mti;
  real_T c2_b_r;
  int32_T c2_kk;
  uint32_T c2_y;
  boolean_T c2_isvalid;
  int32_T c2_b_kk;
  real_T c2_c_kk;
  boolean_T c2_b_isvalid;
  uint32_T c2_b_y;
  uint32_T c2_c_y;
  uint32_T c2_d_y;
  int32_T c2_k;
  uint32_T c2_e_y;
  uint32_T c2_f_y;
  uint32_T c2_g_y;
  int32_T c2_b_a;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    for (c2_j = 0; c2_j < 2; c2_j++) {
      c2_b_j = 1.0 + (real_T)c2_j;
      c2_mti = c2_d_state[624] + 1U;
      if ((real_T)c2_mti >= 625.0) {
        for (c2_kk = 0; c2_kk < 227; c2_kk++) {
          c2_c_kk = 1.0 + (real_T)c2_kk;
          c2_y = (c2_d_state[(int32_T)c2_c_kk - 1] & 2147483648U) | (c2_d_state
            [(int32_T)(c2_c_kk + 1.0) - 1] & 2147483647U);
          c2_b_y = c2_y;
          c2_c_y = c2_b_y;
          if ((real_T)(c2_c_y & 1U) == 0.0) {
            c2_c_y >>= 1U;
          } else {
            c2_c_y = c2_c_y >> 1U ^ 2567483615U;
          }

          c2_d_state[(int32_T)c2_c_kk - 1] = c2_d_state[(int32_T)(c2_c_kk +
            397.0) - 1] ^ c2_c_y;
        }

        for (c2_b_kk = 0; c2_b_kk < 396; c2_b_kk++) {
          c2_c_kk = 228.0 + (real_T)c2_b_kk;
          c2_y = (c2_d_state[(int32_T)c2_c_kk - 1] & 2147483648U) | (c2_d_state
            [(int32_T)(c2_c_kk + 1.0) - 1] & 2147483647U);
          c2_f_y = c2_y;
          c2_g_y = c2_f_y;
          if ((real_T)(c2_g_y & 1U) == 0.0) {
            c2_g_y >>= 1U;
          } else {
            c2_g_y = c2_g_y >> 1U ^ 2567483615U;
          }

          c2_d_state[(int32_T)c2_c_kk - 1] = c2_d_state[(int32_T)((c2_c_kk + 1.0)
            - 228.0) - 1] ^ c2_g_y;
        }

        c2_y = (c2_d_state[623] & 2147483648U) | (c2_d_state[0] & 2147483647U);
        c2_d_y = c2_y;
        c2_e_y = c2_d_y;
        if ((real_T)(c2_e_y & 1U) == 0.0) {
          c2_e_y >>= 1U;
        } else {
          c2_e_y = c2_e_y >> 1U ^ 2567483615U;
        }

        c2_d_state[623] = c2_d_state[396] ^ c2_e_y;
        c2_mti = 1U;
      }

      c2_y = c2_d_state[(int32_T)c2_mti - 1];
      c2_d_state[624] = c2_mti;
      c2_y ^= c2_y >> 11U;
      c2_y ^= c2_y << 7U & 2636928640U;
      c2_y ^= c2_y << 15U & 4022730752U;
      c2_y ^= c2_y >> 18U;
      c2_u[(int32_T)c2_b_j - 1] = c2_y;
    }

    c2_u[0] >>= 5U;
    c2_u[1] >>= 6U;
    c2_b_r = 1.1102230246251565E-16 * ((real_T)c2_u[0] * 6.7108864E+7 + (real_T)
      c2_u[1]);
    if (c2_b_r == 0.0) {
      if (((real_T)c2_d_state[624] >= 1.0) && ((real_T)c2_d_state[624] < 625.0))
      {
        c2_isvalid = true;
      } else {
        c2_isvalid = false;
      }

      c2_b_isvalid = c2_isvalid;
      if (c2_isvalid) {
        c2_b_isvalid = false;
        c2_k = 0;
        exitg2 = false;
        while ((!exitg2) && (c2_k + 1 < 625)) {
          if ((real_T)c2_d_state[c2_k] == 0.0) {
            c2_b_a = c2_k + 1;
            c2_k = c2_b_a;
          } else {
            c2_b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c2_b_isvalid) {
        c2_error(chartInstance);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_b_r;
}

static void c2_b_sqrt(SFc2_multitimeInstanceStruct *chartInstance, real_T *c2_x)
{
  real_T c2_b_x;
  boolean_T c2_p;
  boolean_T c2_b_p;
  c2_b_x = *c2_x;
  if (c2_b_x < 0.0) {
    c2_p = true;
  } else {
    c2_p = false;
  }

  c2_b_p = c2_p;
  if (c2_b_p) {
    c2_e_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void init_dsm_address_info(SFc2_multitimeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_multitimeInstanceStruct *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_inflated1 = (real_T (*)[3200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_multitime_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3234820705U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3567972886U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(847455053U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2343990064U);
}

mxArray* sf_c2_multitime_get_post_codegen_info(void);
mxArray *sf_c2_multitime_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NTPqMUJWqaxdxfknoq7PaE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(40);
      pr[1] = (double)(80);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_multitime_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_multitime_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,4);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  return(mxcell3p);
}

mxArray *sf_c2_multitime_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ippfilter_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_multitime_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_multitime_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_multitime(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[7],T\"inflated1\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[523 529],M[1],T\"/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/randfun/private/eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/randfun/private/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/randfun/private/eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/randfun/private/eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c2_multitime\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_multitime_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_multitimeInstanceStruct *chartInstance = (SFc2_multitimeInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _multitimeMachineNumber_,
           2,
           1,
           1,
           0,
           1,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_multitimeMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_multitimeMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _multitimeMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"inflated1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,165);

        {
          unsigned int dimVector[2];
          dimVector[0]= 40U;
          dimVector[1]= 80U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _multitimeMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_multitimeInstanceStruct *chartInstance = (SFc2_multitimeInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_inflated1);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sdKW4lYgmvCGNmXZP6E2TNE";
}

static void sf_opaque_initialize_c2_multitime(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_multitimeInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_multitime((SFc2_multitimeInstanceStruct*)
    chartInstanceVar);
  initialize_c2_multitime((SFc2_multitimeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_multitime(void *chartInstanceVar)
{
  enable_c2_multitime((SFc2_multitimeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_multitime(void *chartInstanceVar)
{
  disable_c2_multitime((SFc2_multitimeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_multitime(void *chartInstanceVar)
{
  sf_gateway_c2_multitime((SFc2_multitimeInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_multitime(SimStruct* S)
{
  return get_sim_state_c2_multitime((SFc2_multitimeInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_multitime(SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_multitime((SFc2_multitimeInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_multitime(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_multitimeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_multitime_optimization_info();
    }

    finalize_c2_multitime((SFc2_multitimeInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_multitime((SFc2_multitimeInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_multitime(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_multitime((SFc2_multitimeInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_multitime(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_multitime_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1406474653U));
  ssSetChecksum1(S,(3741329046U));
  ssSetChecksum2(S,(535062068U));
  ssSetChecksum3(S,(861002018U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_multitime(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_multitime(SimStruct *S)
{
  SFc2_multitimeInstanceStruct *chartInstance;
  chartInstance = (SFc2_multitimeInstanceStruct *)utMalloc(sizeof
    (SFc2_multitimeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_multitimeInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_multitime;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_multitime;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_multitime;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_multitime;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_multitime;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_multitime;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_multitime;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_multitime;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_multitime;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_multitime;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_multitime;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_multitime(chartInstance);
}

void c2_multitime_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_multitime(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_multitime(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_multitime(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_multitime_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
