/* Include files */

#include "anav_real_sfun.h"
#include "c12_anav_real.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "anav_real_sfun_debug_macros.h"
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
static const char * c12_debug_family_names[31] = { "t1", "mapDim", "compressed",
  "orientCart", "detX", "detY", "offset", "transCart", "roundedUnique",
  "roundTransCart", "roundedLimitUnique", "limitGrid", "inflated", "alpha",
  "beta", "mapList", "costsTemp", "time", "nargin", "nargout", "pos", "theta",
  "detectedList", "scale", "goal", "vehicleRad", "limit", "mode", "costs",
  "mapGrid", "mapGridP" };

static const char * c12_b_debug_family_names[9] = { "len", "l", "xmax", "ymax",
  "nargin", "nargout", "x", "y", "map" };

static const char * c12_c_debug_family_names[6] = { "inflated", "nargin",
  "nargout", "grid", "r", "h" };

static const char * c12_d_debug_family_names[9] = { "rows", "columns", "i", "r",
  "c", "nargin", "nargout", "grid", "list" };

static emlrtRTEInfo c12_emlrtRTEI = { 3,/* lineNo */
  16,                                  /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_b_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_c_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_d_emlrtRTEI = { 25,/* lineNo */
  20,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_e_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_f_emlrtRTEI = { 25,/* lineNo */
  27,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_g_emlrtRTEI = { 19,/* lineNo */
  9,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_h_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_i_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_j_emlrtRTEI = { 36,/* lineNo */
  19,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_k_emlrtRTEI = { 26,/* lineNo */
  33,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_l_emlrtRTEI = { 49,/* lineNo */
  9,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_m_emlrtRTEI = { 36,/* lineNo */
  26,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_n_emlrtRTEI = { 26,/* lineNo */
  50,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_o_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_p_emlrtRTEI = { 43,/* lineNo */
  9,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_q_emlrtRTEI = { 26,/* lineNo */
  10,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_r_emlrtRTEI = { 26,/* lineNo */
  16,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_s_emlrtRTEI = { 56,/* lineNo */
  30,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_t_emlrtRTEI = { 44,/* lineNo */
  32,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_u_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "isnan",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c12_v_emlrtRTEI = { 37,/* lineNo */
  19,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_w_emlrtRTEI = { 27,/* lineNo */
  23,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_x_emlrtRTEI = { 277,/* lineNo */
  1,                                   /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c12_y_emlrtRTEI = { 27,/* lineNo */
  28,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_ab_emlrtRTEI = { 37,/* lineNo */
  26,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_bb_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_cb_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_db_emlrtRTEI = { 108,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c12_eb_emlrtRTEI = { 57,/* lineNo */
  24,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_fb_emlrtRTEI = { 286,/* lineNo */
  35,                                  /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c12_gb_emlrtRTEI = { 115,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c12_hb_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_ib_emlrtRTEI = { 306,/* lineNo */
  5,                                   /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c12_jb_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c12_kb_emlrtRTEI = { 58,/* lineNo */
  24,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_lb_emlrtRTEI = { 27,/* lineNo */
  9,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_mb_emlrtRTEI = { 58,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_nb_emlrtRTEI = { 59,/* lineNo */
  24,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_ob_emlrtRTEI = { 59,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_pb_emlrtRTEI = { 60,/* lineNo */
  24,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_qb_emlrtRTEI = { 60,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_rb_emlrtRTEI = { 63,/* lineNo */
  27,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_sb_emlrtRTEI = { 63,/* lineNo */
  52,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_tb_emlrtRTEI = { 5,/* lineNo */
  9,                                   /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_ub_emlrtRTEI = { 10,/* lineNo */
  31,                                  /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_vb_emlrtRTEI = { 10,/* lineNo */
  5,                                   /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_wb_emlrtRTEI = { 6,/* lineNo */
  9,                                   /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_xb_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_yb_emlrtRTEI = { 69,/* lineNo */
  16,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_ac_emlrtRTEI = { 77,/* lineNo */
  38,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_bc_emlrtRTEI = { 77,/* lineNo */
  33,                                  /* colNo */
  "buildMap",                          /* fName */
  "#anav_real:215"                     /* pName */
};

static emlrtRTEInfo c12_cc_emlrtRTEI = { 7,/* lineNo */
  11,                                  /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_dc_emlrtRTEI = { 10,/* lineNo */
  16,                                  /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_ec_emlrtRTEI = { 5,/* lineNo */
  13,                                  /* colNo */
  "inflate2",                          /* fName */
  "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"/* pName */
};

static emlrtRTEInfo c12_fc_emlrtRTEI = { 10,/* lineNo */
  8,                                   /* colNo */
  "pol2cart",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/specfun/pol2cart.m"/* pName */
};

static emlrtRTEInfo c12_gc_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "pol2cart",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/specfun/pol2cart.m"/* pName */
};

static emlrtRTEInfo c12_hc_emlrtRTEI = { 11,/* lineNo */
  8,                                   /* colNo */
  "pol2cart",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/specfun/pol2cart.m"/* pName */
};

static emlrtRTEInfo c12_ic_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "pol2cart",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/specfun/pol2cart.m"/* pName */
};

static emlrtRTEInfo c12_jc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "cos",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/cos.m"/* pName */
};

static emlrtRTEInfo c12_kc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sin",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/sin.m"/* pName */
};

static emlrtRTEInfo c12_lc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "round",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/round.m"/* pName */
};

static emlrtRTEInfo c12_mc_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c12_nc_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c12_oc_emlrtRTEI = { 1,/* lineNo */
  28,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c12_pc_emlrtRTEI = { 87,/* lineNo */
  19,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c12_qc_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c12_rc_emlrtRTEI = { 33,/* lineNo */
  14,                                  /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c12_sc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c12_tc_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c12_uc_emlrtRTEI = { 52,/* lineNo */
  14,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_vc_emlrtRTEI = { 52,/* lineNo */
  16,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_wc_emlrtRTEI = { 98,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c12_xc_emlrtRTEI = { 19,/* lineNo */
  24,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c12_yc_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "scalexpAlloc",                      /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo c12_ad_emlrtRTEI = { 45,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo c12_bd_emlrtRTEI = { 17,/* lineNo */
  28,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo c12_cd_emlrtRTEI = { 17,/* lineNo */
  30,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo c12_dd_emlrtRTEI = { 53,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ed_emlrtRTEI = { 54,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_fd_emlrtRTEI = { 55,/* lineNo */
  30,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_gd_emlrtRTEI = { 55,/* lineNo */
  47,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_hd_emlrtRTEI = { 55,/* lineNo */
  20,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_id_emlrtRTEI = { 56,/* lineNo */
  39,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_jd_emlrtRTEI = { 56,/* lineNo */
  17,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_kd_emlrtRTEI = { 55,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ld_emlrtRTEI = { 57,/* lineNo */
  29,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_md_emlrtRTEI = { 57,/* lineNo */
  46,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_nd_emlrtRTEI = { 57,/* lineNo */
  19,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_od_emlrtRTEI = { 57,/* lineNo */
  18,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_pd_emlrtRTEI = { 57,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_qd_emlrtRTEI = { 58,/* lineNo */
  30,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_rd_emlrtRTEI = { 58,/* lineNo */
  47,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_sd_emlrtRTEI = { 58,/* lineNo */
  20,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_td_emlrtRTEI = { 59,/* lineNo */
  39,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ud_emlrtRTEI = { 59,/* lineNo */
  17,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_vd_emlrtRTEI = { 58,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_wd_emlrtRTEI = { 60,/* lineNo */
  29,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_xd_emlrtRTEI = { 60,/* lineNo */
  46,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_yd_emlrtRTEI = { 60,/* lineNo */
  19,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ae_emlrtRTEI = { 60,/* lineNo */
  18,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_be_emlrtRTEI = { 60,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ce_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "mrdivide",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mrdivide.p"/* pName */
};

static emlrtRTEInfo c12_de_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c12_ee_emlrtRTEI = { 61,/* lineNo */
  34,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_fe_emlrtRTEI = { 61,/* lineNo */
  29,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ge_emlrtRTEI = { 62,/* lineNo */
  23,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_he_emlrtRTEI = { 62,/* lineNo */
  17,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ie_emlrtRTEI = { 61,/* lineNo */
  22,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_je_emlrtRTEI = { 63,/* lineNo */
  17,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ke_emlrtRTEI = { 64,/* lineNo */
  32,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_le_emlrtRTEI = { 64,/* lineNo */
  49,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_me_emlrtRTEI = { 65,/* lineNo */
  27,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ne_emlrtRTEI = { 65,/* lineNo */
  44,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_oe_emlrtRTEI = { 64,/* lineNo */
  23,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_pe_emlrtRTEI = { 65,/* lineNo */
  18,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_qe_emlrtRTEI = { 66,/* lineNo */
  19,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_re_emlrtRTEI = { 66,/* lineNo */
  30,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_se_emlrtRTEI = { 66,/* lineNo */
  18,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_te_emlrtRTEI = { 66,/* lineNo */
  48,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ue_emlrtRTEI = { 64,/* lineNo */
  22,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ve_emlrtRTEI = { 64,/* lineNo */
  21,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_we_emlrtRTEI = { 61,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_xe_emlrtRTEI = { 67,/* lineNo */
  31,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ye_emlrtRTEI = { 67,/* lineNo */
  48,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_af_emlrtRTEI = { 67,/* lineNo */
  30,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_bf_emlrtRTEI = { 67,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_cf_emlrtRTEI = { 83,/* lineNo */
  27,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_df_emlrtRTEI = { 83,/* lineNo */
  13,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ef_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_ff_emlrtRTEI = { 52,/* lineNo */
  30,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_gf_emlrtRTEI = { 52,/* lineNo */
  41,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_hf_emlrtRTEI = { 53,/* lineNo */
  25,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_if_emlrtRTEI = { 53,/* lineNo */
  32,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_jf_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c12_kf_emlrtRTEI = { 61,/* lineNo */
  54,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_lf_emlrtRTEI = { 62,/* lineNo */
  34,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_mf_emlrtRTEI = { 62,/* lineNo */
  56,                                  /* colNo */
  "fspecial",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/fspecial.m"/* pName */
};

static emlrtRTEInfo c12_nf_emlrtRTEI = { 1,/* lineNo */
  23,                                  /* colNo */
  "meshgrid",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/meshgrid.m"/* pName */
};

static emlrtRTEInfo c12_of_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/abs.m"/* pName */
};

static emlrtRTEInfo c12_pf_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c12_qf_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c12_rf_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "asin",                              /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/asin.m"/* pName */
};

static emlrtRTEInfo c12_sf_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_tf_emlrtRTEI = { 600,/* lineNo */
  22,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_uf_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_vf_emlrtRTEI = { 814,/* lineNo */
  8,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_wf_emlrtRTEI = { 16,/* lineNo */
  13,                                  /* colNo */
  "isinf",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c12_xf_emlrtRTEI = { 16,/* lineNo */
  34,                                  /* colNo */
  "isinf",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c12_yf_emlrtRTEI = { 66,/* lineNo */
  18,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_ag_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isinf",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c12_bg_emlrtRTEI = { 12,/* lineNo */
  5,                                   /* colNo */
  "isfinite",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isfinite.m"/* pName */
};

static emlrtRTEInfo c12_cg_emlrtRTEI = { 67,/* lineNo */
  16,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_dg_emlrtRTEI = { 819,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_eg_emlrtRTEI = { 16,/* lineNo */
  13,                                  /* colNo */
  "isnan",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c12_fg_emlrtRTEI = { 16,/* lineNo */
  34,                                  /* colNo */
  "isnan",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c12_gg_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_hg_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isnan",                             /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c12_ig_emlrtRTEI = { 12,/* lineNo */
  17,                                  /* colNo */
  "isfinite",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isfinite.m"/* pName */
};

static emlrtRTEInfo c12_jg_emlrtRTEI = { 68,/* lineNo */
  16,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_kg_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "isfinite",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isfinite.m"/* pName */
};

static emlrtRTEInfo c12_lg_emlrtRTEI = { 110,/* lineNo */
  17,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_mg_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_ng_emlrtRTEI = { 823,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_og_emlrtRTEI = { 820,/* lineNo */
  27,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_pg_emlrtRTEI = { 848,/* lineNo */
  35,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_qg_emlrtRTEI = { 848,/* lineNo */
  44,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_rg_emlrtRTEI = { 603,/* lineNo */
  19,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_sg_emlrtRTEI = { 84,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_tg_emlrtRTEI = { 606,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_ug_emlrtRTEI = { 848,/* lineNo */
  5,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_vg_emlrtRTEI = { 851,/* lineNo */
  35,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_wg_emlrtRTEI = { 608,/* lineNo */
  16,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_xg_emlrtRTEI = { 851,/* lineNo */
  44,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_yg_emlrtRTEI = { 917,/* lineNo */
  11,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_ah_emlrtRTEI = { 851,/* lineNo */
  5,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_bh_emlrtRTEI = { 857,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_ch_emlrtRTEI = { 110,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_dh_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_eh_emlrtRTEI = { 88,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_fh_emlrtRTEI = { 921,/* lineNo */
  29,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_gh_emlrtRTEI = { 921,/* lineNo */
  5,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_hh_emlrtRTEI = { 924,/* lineNo */
  29,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_ih_emlrtRTEI = { 924,/* lineNo */
  5,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_jh_emlrtRTEI = { 927,/* lineNo */
  18,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_kh_emlrtRTEI = { 863,/* lineNo */
  26,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_lh_emlrtRTEI = { 863,/* lineNo */
  37,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_mh_emlrtRTEI = { 864,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_nh_emlrtRTEI = { 864,/* lineNo */
  24,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_oh_emlrtRTEI = { 863,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_ph_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_qh_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_rh_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_sh_emlrtRTEI = { 603,/* lineNo */
  8,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_th_emlrtRTEI = { 12,/* lineNo */
  6,                                   /* colNo */
  "isfinite",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isfinite.m"/* pName */
};

static emlrtRTEInfo c12_uh_emlrtRTEI = { 12,/* lineNo */
  18,                                  /* colNo */
  "isfinite",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/isfinite.m"/* pName */
};

static emlrtRTEInfo c12_vh_emlrtRTEI = { 820,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_wh_emlrtRTEI = { 823,/* lineNo */
  23,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c12_xh_emlrtRTEI = { 25,/* lineNo */
  38,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_yh_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_ai_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_bi_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_ci_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_di_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_ei_emlrtRTEI = { 19,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_fi_emlrtRTEI = { 25,/* lineNo */
  12,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_gi_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c12_hi_emlrtRTEI = { 75,/* lineNo */
  63,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c12_ii_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c12_ji_emlrtRTEI = { 214,/* lineNo */
  5,                                   /* colNo */
  "xgesvd",                            /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo c12_ki_emlrtRTEI = { 28,/* lineNo */
  33,                                  /* colNo */
  "xgesvd",                            /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo c12_li_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "xgesvd",                            /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo c12_mi_emlrtRTEI = { 75,/* lineNo */
  14,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c12_ni_emlrtRTEI = { 117,/* lineNo */
  9,                                   /* colNo */
  "xgesvd",                            /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo c12_oi_emlrtRTEI = { 100,/* lineNo */
  5,                                   /* colNo */
  "diag",                              /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/diag.m"/* pName */
};

static emlrtRTEInfo c12_pi_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "diag",                              /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/diag.m"/* pName */
};

static emlrtRTEInfo c12_qi_emlrtRTEI = { 72,/* lineNo */
  13,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo c12_ri_emlrtRTEI = { 24,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c12_si_emlrtRTEI = { 27,/* lineNo */
  30,                                  /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c12_ti_emlrtRTEI = { 28,/* lineNo */
  29,                                  /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c12_ui_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c12_vi_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c12_wi_emlrtRTEI = { 1,/* lineNo */
  34,                                  /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c12_xi_emlrtRTEI = { 58,/* lineNo */
  32,                                  /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c12_yi_emlrtRTEI = { 85,/* lineNo */
  40,                                  /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c12_aj_emlrtRTEI = { 297,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c12_bj_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static const char_T c12_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const creal_T c12_dc0 = { 0.0,  /* re */
  0.0                                  /* im */
};

static const creal_T c12_dc1 = { 1.0,  /* re */
  0.0                                  /* im */
};

static const char_T c12_cv1[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i',
  'm', 'a', 'g', 'r', 'e', 'e' };

static const char_T c12_cv2[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
  'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static const char_T c12_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
  'E', 'r', 'r', 'o', 'r' };

static const char_T c12_cv4[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
  'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

/* Function Declarations */
static void initialize_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance);
static void initialize_params_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance);
static void enable_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance);
static void disable_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_anav_real
  (SFc12_anav_realInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_anav_real(SFc12_anav_realInstanceStruct *
  chartInstance);
static void set_sim_state_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void finalize_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance);
static void sf_gateway_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance);
static void mdl_start_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance);
static void c12_chartstep_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance);
static void initSimStructsc12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance);
static void c12_grid2list(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_c_grid[3081], real_T c12_list[9243]);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[2]);
static void c12_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[2]);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[2]);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[1]);
static void c12_b_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[1]);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[1]);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_c_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[2]);
static void c12_d_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[2]);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[2]);
static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_e_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_b_limitGrid, const char_T *c12_identifier, real_T c12_y
  [3081]);
static void c12_f_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [3081]);
static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[2]);
static void c12_g_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[2]);
static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[2]);
static const mxArray *c12_i_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_h_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [9243]);
static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_j_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_i_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [9252]);
static void c12_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_k_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_l_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_m_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_j_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_c_costs, const char_T *c12_identifier, real_T c12_y[9252]);
static void c12_k_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [9252]);
static void c12_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_n_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_l_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_b_mapGridP, const char_T *c12_identifier, boolean_T
  *c12_svPtr, real_T c12_y[3081]);
static void c12_m_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, boolean_T
  *c12_svPtr, real_T c12_y[3081]);
static void c12_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_o_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[1]);
static void c12_n_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[1]);
static void c12_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[1]);
static const mxArray *c12_p_sf_marshallOut(void *chartInstanceVoid, creal_T
  c12_inData_data[], int32_T c12_inData_size[2]);
static void c12_o_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, creal_T
  c12_b_y_data[], int32_T c12_y_size[2]);
static void c12_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, creal_T c12_outData_data[],
  int32_T c12_outData_size[2]);
static const mxArray *c12_q_sf_marshallOut(void *chartInstanceVoid,
  c12_emxArray_creal_T *c12_inData);
static void c12_p_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_b_h, const char_T *c12_identifier, boolean_T *c12_svPtr,
  c12_emxArray_creal_T *c12_y);
static void c12_q_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, boolean_T
  *c12_svPtr, c12_emxArray_creal_T *c12_y);
static void c12_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, c12_emxArray_creal_T
  *c12_outData);
static void c12_pol2cart(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_th_data[], int32_T c12_th_size[1], real_T c12_r_data[], int32_T
  c12_r_size[1], real_T c12_x_data[], int32_T c12_x_size[1], real_T
  c12_b_y_data[], int32_T c12_y_size[1]);
static void c12_cos(SFc12_anav_realInstanceStruct *chartInstance, real_T
                    c12_x_data[], int32_T c12_x_size[1], real_T c12_b_x_data[],
                    int32_T c12_b_x_size[1]);
static void c12_check_forloop_overflow_error(SFc12_anav_realInstanceStruct
  *chartInstance, boolean_T c12_overflow);
static void c12_sin(SFc12_anav_realInstanceStruct *chartInstance, real_T
                    c12_x_data[], int32_T c12_x_size[1], real_T c12_b_x_data[],
                    int32_T c12_b_x_size[1]);
static void c12_round(SFc12_anav_realInstanceStruct *chartInstance, real_T
                      c12_x_data[], int32_T c12_x_size[2], real_T c12_b_x_data[],
                      int32_T c12_b_x_size[2]);
static void c12_sortrows(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_b_y_data[], int32_T c12_y_size[2], real_T c12_c_y_data[], int32_T
  c12_b_y_size[2], real_T c12_ndx_data[], int32_T c12_ndx_size[1]);
static void c12_sortIdx(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_x_data[], int32_T c12_x_size[2], int32_T c12_col_data[], int32_T
  c12_col_size[2], int32_T c12_idx_data[], int32_T c12_idx_size[1]);
static void c12_mergesort(SFc12_anav_realInstanceStruct *chartInstance, int32_T
  c12_idx_data[], int32_T c12_idx_size[1], real_T c12_x_data[], int32_T
  c12_x_size[2], int32_T c12_dir_data[], int32_T c12_dir_size[2], int32_T c12_n,
  int32_T c12_b_idx_data[], int32_T c12_b_idx_size[1]);
static boolean_T c12_sortLE(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_v_data[], int32_T c12_v_size[2], int32_T c12_dir_data[], int32_T
  c12_dir_size[2], int32_T c12_idx1, int32_T c12_idx2);
static void c12_apply_row_permutation(SFc12_anav_realInstanceStruct
  *chartInstance, real_T c12_b_y_data[], int32_T c12_y_size[2], int32_T
  c12_idx_data[], int32_T c12_idx_size[1], real_T c12_c_y_data[], int32_T
  c12_b_y_size[2]);
static boolean_T c12_rows_differ(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_c_b_data[], int32_T c12_b_size[2], int32_T c12_k0, int32_T c12_k);
static void c12_nullAssignment(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_x_data[], int32_T c12_x_size[2], boolean_T c12_idx_data[], int32_T
  c12_idx_size[1], real_T c12_b_x_data[], int32_T c12_b_x_size[2]);
static void c12_fspecial(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_varargin_2, c12_emxArray_creal_T *c12_b_h);
static void c12_validateattributes(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_a);
static void c12_meshgrid(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T *c12_b_x, c12_emxArray_real_T *c12_y, c12_emxArray_real_T *
  c12_xx, c12_emxArray_real_T *c12_yy);
static void c12_abs(SFc12_anav_realInstanceStruct *chartInstance,
                    c12_emxArray_real_T *c12_b_x, c12_emxArray_real_T *c12_y);
static boolean_T c12_dimagree(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T *c12_z, c12_emxArray_real_T *c12_c_varargin_1,
  c12_emxArray_real_T *c12_varargin_2);
static void c12_error(SFc12_anav_realInstanceStruct *chartInstance);
static void c12_power(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_real_T *c12_a, c12_emxArray_real_T *c12_y);
static boolean_T c12_b_dimagree(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T *c12_z, c12_emxArray_real_T *c12_c_varargin_1);
static void c12_sqrt(SFc12_anav_realInstanceStruct *chartInstance,
                     c12_emxArray_creal_T *c12_b_x, c12_emxArray_creal_T
                     *c12_c_x);
static creal_T c12_b_sqrt(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  c12_b_x);
static void c12_asin(SFc12_anav_realInstanceStruct *chartInstance,
                     c12_emxArray_creal_T *c12_b_x, c12_emxArray_creal_T
                     *c12_c_x);
static creal_T c12_b_asin(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  c12_b_x);
static void c12_rescale(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_re, real_T c12_im, real_T *c12_b_re, real_T *c12_b_im, real_T *c12_b_scale);
static void c12_b_sin(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_creal_T *c12_b_x, c12_emxArray_creal_T
                      *c12_c_x);
static real_T c12_c_sqrt(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_b_x);
static void c12_b_error(SFc12_anav_realInstanceStruct *chartInstance);
static void c12_c_error(SFc12_anav_realInstanceStruct *chartInstance);
static void c12_imfilter(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_c_varargin_1[3081], c12_emxArray_creal_T *c12_varargin_2,
  c12_emxArray_creal_T *c12_b);
static void c12_svd(SFc12_anav_realInstanceStruct *chartInstance,
                    c12_emxArray_creal_T *c12_A, c12_emxArray_creal_T *c12_U,
                    c12_emxArray_real_T *c12_S, c12_emxArray_creal_T *c12_V);
static void c12_b_svd(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_creal_T *c12_A, c12_emxArray_creal_T *c12_U,
                      c12_emxArray_real_T *c12_s, c12_emxArray_creal_T *c12_V);
static void c12_d_error(SFc12_anav_realInstanceStruct *chartInstance);
static void c12_e_error(SFc12_anav_realInstanceStruct *chartInstance, int32_T
  c12_varargin_2);
static void c12_f_error(SFc12_anav_realInstanceStruct *chartInstance, int32_T
  c12_varargin_2);
static void c12_g_error(SFc12_anav_realInstanceStruct *chartInstance);
static void c12_diag(SFc12_anav_realInstanceStruct *chartInstance,
                     c12_emxArray_real_T *c12_v, c12_emxArray_real_T *c12_d);
static void c12_padImage(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_a_tmp[3081], real_T c12_pad[2], c12_emxArray_real_T *c12_a);
static const mxArray *c12_emlrt_marshallOut(SFc12_anav_realInstanceStruct
  *chartInstance, const char_T c12_u[34]);
static const mxArray *c12_b_emlrt_marshallOut(SFc12_anav_realInstanceStruct
  *chartInstance, const char_T c12_u[30]);
static const mxArray *c12_r_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_r_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_s_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_anav_real, const char_T
  *c12_identifier);
static uint8_T c12_t_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_cos(SFc12_anav_realInstanceStruct *chartInstance, real_T
                      c12_x_data[], int32_T c12_x_size[1]);
static void c12_c_sin(SFc12_anav_realInstanceStruct *chartInstance, real_T
                      c12_x_data[], int32_T c12_x_size[1]);
static void c12_b_round(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_x_data[], int32_T c12_x_size[2]);
static void c12_b_sortrows(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_b_y_data[], int32_T c12_y_size[2], real_T c12_ndx_data[], int32_T
  c12_ndx_size[1]);
static void c12_b_mergesort(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_idx_data[], int32_T c12_idx_size[1], real_T c12_x_data[], int32_T
  c12_x_size[2], int32_T c12_dir_data[], int32_T c12_dir_size[2], int32_T c12_n);
static void c12_b_apply_row_permutation(SFc12_anav_realInstanceStruct
  *chartInstance, real_T c12_b_y_data[], int32_T c12_y_size[2], int32_T
  c12_idx_data[], int32_T c12_idx_size[1]);
static void c12_b_nullAssignment(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_x_data[], int32_T c12_x_size[2], boolean_T c12_idx_data[], int32_T
  c12_idx_size[1]);
static void c12_d_sqrt(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T *c12_b_x);
static void c12_e_sqrt(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  *c12_b_x);
static void c12_c_asin(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T *c12_b_x);
static void c12_d_asin(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  *c12_b_x);
static real_T c12_b_rescale(SFc12_anav_realInstanceStruct *chartInstance, real_T
  *c12_re, real_T *c12_im);
static void c12_d_sin(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_creal_T *c12_b_x);
static void c12_f_sqrt(SFc12_anav_realInstanceStruct *chartInstance, real_T
  *c12_b_x);
static void c12_emxInit_creal_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxFree_creal_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T **c12_pEmxArray);
static void c12_emxEnsureCapacity_creal_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_creal_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation);
static void c12_emxEnsureCapacity_int32_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_int32_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation);
static void c12_emxInit_int32_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_int32_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxFree_int32_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_int32_T **c12_pEmxArray);
static void c12_emxEnsureCapacity_real_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_real_T *c12_emxArray, int32_T c12_oldNumel, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxEnsureCapacity_boolean_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_boolean_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation);
static void c12_emxEnsureCapacity_creal_T1(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_creal_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation);
static void c12_emxInit_real_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxInit_boolean_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_boolean_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxInit_creal_T1(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxFree_real_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T **c12_pEmxArray);
static void c12_emxFree_boolean_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_boolean_T **c12_pEmxArray);
static void c12_emxEnsureCapacity_boolean_T1(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_boolean_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation);
static void c12_emxEnsureCapacity_real_T1(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_real_T *c12_emxArray, int32_T c12_oldNumel, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxInit_real_T1(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation);
static void c12_emxInit_boolean_T1(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_boolean_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation);
static int32_T c12_div_nzp_s32(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_numerator, int32_T c12_denominator, uint32_T c12_ssid_src_loc,
  int32_T c12_offset_src_loc, int32_T c12_length_src_loc);
static int32_T c12__s32_add__(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_b, int32_T c12_c, uint32_T c12_ssid_src_loc, int32_T
  c12_offset_src_loc, int32_T c12_length_src_loc);
static int32_T c12__s32_minus__(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_b, int32_T c12_c, uint32_T c12_ssid_src_loc, int32_T
  c12_offset_src_loc, int32_T c12_length_src_loc);
static int32_T c12__s32_s64_(SFc12_anav_realInstanceStruct *chartInstance,
  int64_T c12_b, uint32_T c12_ssid_src_loc, int32_T c12_offset_src_loc, int32_T
  c12_length_src_loc);
static void init_dsm_address_info(SFc12_anav_realInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc12_anav_realInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c12_fEmlrtCtx, "Image_Toolbox", 2);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc12_anav_real(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_mapGridP_not_empty = false;
  chartInstance->c12_h_not_empty = false;
  chartInstance->c12_is_active_c12_anav_real = 0U;
  c12_emxInit_creal_T(chartInstance, &chartInstance->c12_h, 2, &c12_emlrtRTEI);
}

static void initialize_params_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_anav_real
  (SFc12_anav_realInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c12_anav_real(SFc12_anav_realInstanceStruct *
  chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  const mxArray *c12_b_y = NULL;
  const mxArray *c12_c_y = NULL;
  const mxArray *c12_d_y = NULL;
  const mxArray *c12_e_y = NULL;
  uint8_T c12_b_hoistedGlobal;
  const mxArray *c12_f_y = NULL;
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellmatrix(5, 1), false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", *chartInstance->c12_b_costs, 0, 0U,
    1U, 0U, 2, 1, 9252), false);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", *chartInstance->c12_c_mapGrid, 0,
    0U, 1U, 0U, 2, 39, 79), false);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_d_y = NULL;
  if (!chartInstance->c12_h_not_empty) {
    sf_mex_assign(&c12_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c12_d_y, sf_mex_create("y", chartInstance->c12_h->data, 0, 1U,
      1U, 0U, 2, chartInstance->c12_h->size[0], chartInstance->c12_h->size[1]),
                  false);
  }

  sf_mex_setcell(c12_y, 2, c12_d_y);
  c12_e_y = NULL;
  if (!chartInstance->c12_mapGridP_not_empty) {
    sf_mex_assign(&c12_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c12_e_y, sf_mex_create("y", chartInstance->c12_mapGridP, 0,
      0U, 1U, 0U, 2, 39, 79), false);
  }

  sf_mex_setcell(c12_y, 3, c12_e_y);
  c12_b_hoistedGlobal = chartInstance->c12_is_active_c12_anav_real;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c12_y, 4, c12_f_y);
  sf_mex_assign(&c12_st, c12_y, false);
  return c12_st;
}

static void set_sim_state_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T c12_dv0[9252];
  int32_T c12_i0;
  real_T c12_dv1[3081];
  int32_T c12_i1;
  c12_emxArray_creal_T *c12_r0;
  int32_T c12_i2;
  int32_T c12_i3;
  int32_T c12_i4;
  int32_T c12_loop_ub;
  int32_T c12_i5;
  real_T c12_dv2[3081];
  int32_T c12_i6;
  chartInstance->c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 0)),
    "costs", c12_dv0);
  for (c12_i0 = 0; c12_i0 < 9252; c12_i0++) {
    (*chartInstance->c12_b_costs)[c12_i0] = c12_dv0[c12_i0];
  }

  c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
    "mapGrid", c12_dv1);
  for (c12_i1 = 0; c12_i1 < 3081; c12_i1++) {
    (*chartInstance->c12_c_mapGrid)[c12_i1] = c12_dv1[c12_i1];
  }

  c12_emxInit_creal_T(chartInstance, &c12_r0, 2, (emlrtRTEInfo *)NULL);
  c12_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 2)),
    "h", &chartInstance->c12_h_not_empty, c12_r0);
  c12_i2 = chartInstance->c12_h->size[0] * chartInstance->c12_h->size[1];
  chartInstance->c12_h->size[0] = c12_r0->size[0];
  chartInstance->c12_h->size[1] = c12_r0->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, chartInstance->c12_h, c12_i2,
    (emlrtRTEInfo *)NULL);
  c12_i3 = chartInstance->c12_h->size[0];
  c12_i4 = chartInstance->c12_h->size[1];
  c12_loop_ub = c12_r0->size[0] * c12_r0->size[1] - 1;
  for (c12_i5 = 0; c12_i5 <= c12_loop_ub; c12_i5++) {
    chartInstance->c12_h->data[c12_i5] = c12_r0->data[c12_i5];
  }

  c12_emxFree_creal_T(chartInstance, &c12_r0);
  c12_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 3)),
    "mapGridP", &chartInstance->c12_mapGridP_not_empty, c12_dv2);
  for (c12_i6 = 0; c12_i6 < 3081; c12_i6++) {
    chartInstance->c12_mapGridP[c12_i6] = c12_dv2[c12_i6];
  }

  chartInstance->c12_is_active_c12_anav_real = c12_s_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 4)),
     "is_active_c12_anav_real");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_anav_real(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance)
{
  c12_emxFree_creal_T(chartInstance, &chartInstance->c12_h);
}

static void sf_gateway_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance)
{
  int32_T c12_i7;
  int32_T c12_i8;
  int32_T c12_i9;
  int32_T c12_i10;
  int32_T c12_i11;
  int32_T c12_i12;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_mode, 7U);
  for (c12_i7 = 0; c12_i7 < 708; c12_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_limit)[c12_i7], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_vehicleRad, 5U);
  for (c12_i8 = 0; c12_i8 < 2; c12_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_goal)[c12_i8], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_scale, 3U);
  for (c12_i9 = 0; c12_i9 < 2162; c12_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_c_detectedList)[c12_i9], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_theta, 1U);
  for (c12_i10 = 0; c12_i10 < 2; c12_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_pos)[c12_i10], 0U);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  c12_chartstep_c12_anav_real(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  for (c12_i11 = 0; c12_i11 < 9252; c12_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_b_costs)[c12_i11], 8U);
  }

  for (c12_i12 = 0; c12_i12 < 3081; c12_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_c_mapGrid)[c12_i12], 9U);
  }
}

static void mdl_start_c12_anav_real(SFc12_anav_realInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c12_chartstep_c12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance)
{
  real_T c12_b_hoistedGlobal;
  real_T c12_c_hoistedGlobal;
  real_T c12_d_hoistedGlobal;
  real_T c12_e_hoistedGlobal;
  int32_T c12_i13;
  real_T c12_b_theta;
  real_T c12_b_pos[2];
  int32_T c12_i14;
  real_T c12_b_scale;
  int32_T c12_i15;
  real_T c12_b_vehicleRad;
  real_T c12_b_goal[2];
  int32_T c12_i16;
  real_T c12_b_mode;
  real_T c12_b_limit[708];
  uint32_T c12_debug_family_var_map[31];
  const mxArray *c12_t1 = NULL;
  real_T c12_mapDim[2];
  int32_T c12_compressed_size[2];
  int32_T c12_orientCart_size[2];
  real_T c12_detX_data[1081];
  int32_T c12_detX_size[1];
  real_T c12_detY_data[1081];
  int32_T c12_detY_size[1];
  real_T c12_offset;
  int32_T c12_transCart_size[2];
  int32_T c12_roundedUnique_size[2];
  int32_T c12_roundTransCart_size[2];
  int32_T c12_roundedLimitUnique_size[2];
  int32_T c12_inflated_size[2];
  real_T c12_alpha;
  real_T c12_beta;
  const mxArray *c12_time = NULL;
  real_T c12_nargin = 8.0;
  real_T c12_nargout = 2.0;
  int32_T c12_i17;
  int32_T c12_i18;
  int32_T c12_compressed;
  int32_T c12_b_compressed;
  int32_T c12_i19;
  int32_T c12_orientCart;
  real_T c12_B;
  real_T c12_A[1081];
  int32_T c12_b_orientCart;
  real_T c12_y;
  real_T c12_b_y;
  int32_T c12_i20;
  int32_T c12_i21;
  int32_T c12_i22;
  int32_T c12_tmp_size[1];
  int32_T c12_loop_ub;
  int32_T c12_i23;
  int32_T c12_i24;
  int32_T c12_transCart;
  int32_T c12_b_transCart;
  int32_T c12_i25;
  int32_T c12_d_tmp_data[1081];
  int32_T c12_b_detX_size[1];
  int32_T c12_b_loop_ub;
  int32_T c12_c_compressed;
  int32_T c12_i26;
  int32_T c12_d_compressed;
  int32_T c12_i27;
  int32_T c12_iv0[1];
  real_T c12_b_detX_data[1081];
  int32_T c12_c_transCart;
  int32_T c12_roundedUnique;
  int32_T c12_d_transCart;
  int32_T c12_c_loop_ub;
  int32_T c12_b_roundedUnique;
  int32_T c12_d_loop_ub;
  int32_T c12_i28;
  int32_T c12_i29;
  int32_T c12_a_size[2];
  int32_T c12_i30;
  int32_T c12_i31;
  int32_T c12_b_compressed_size[1];
  int32_T c12_a;
  int32_T c12_e_loop_ub;
  int32_T c12_f_loop_ub;
  int32_T c12_b_a;
  int32_T c12_i32;
  int32_T c12_i33;
  int32_T c12_i34;
  int32_T c12_g_loop_ub;
  int32_T c12_c_roundedUnique;
  int32_T c12_d_roundedUnique;
  int32_T c12_i35;
  int32_T c12_e_roundedUnique;
  int32_T c12_i36;
  int32_T c12_i37;
  real_T c12_b_compressed_data[1081];
  int32_T c12_i38;
  int32_T c12_c_compressed_size[1];
  int32_T c12_i39;
  int32_T c12_h_loop_ub;
  int32_T c12_i_loop_ub;
  int32_T c12_i40;
  int32_T c12_i41;
  int32_T c12_i42;
  int32_T c12_i43;
  int32_T c12_roundTransCart;
  int32_T c12_b_roundTransCart;
  int32_T c12_iv1[1];
  real_T c12_c_compressed_data[1081];
  real_T c12_b_detY_data[1081];
  int32_T c12_b_detY_size[1];
  int32_T c12_j_loop_ub;
  int32_T c12_k_loop_ub;
  int32_T c12_i44;
  real_T c12_b_x;
  int32_T c12_l_loop_ub;
  int32_T c12_i45;
  int32_T c12_i46;
  real_T c12_c_x;
  int32_T c12_i47;
  int32_T c12_x_size[1];
  int32_T c12_m_loop_ub;
  real_T c12_c_pos;
  int32_T c12_i48;
  real_T c12_d0;
  int32_T c12_n_loop_ub;
  int32_T c12_o_loop_ub;
  int32_T c12_c_a;
  int32_T c12_i49;
  int32_T c12_i50;
  int32_T c12_b_size[1];
  real_T c12_x_data[1317];
  int32_T c12_d_a;
  int32_T c12_p_loop_ub;
  int32_T c12_q_loop_ub;
  int32_T c12_i51;
  int32_T c12_i52;
  int32_T c12_i53;
  int32_T c12_r_loop_ub;
  int32_T c12_b_tmp_size[2];
  boolean_T c12_c_b_data[1317];
  int32_T c12_b_b_size[2];
  int32_T c12_s_loop_ub;
  int32_T c12_i54;
  int32_T c12_i55;
  int32_T c12_i56;
  int32_T c12_b;
  int32_T c12_i57;
  int32_T c12_b_b;
  int32_T c12_t_loop_ub;
  int32_T c12_u_loop_ub;
  int32_T c12_v_loop_ub;
  int32_T c12_i58;
  int32_T c12_i59;
  int32_T c12_i60;
  int32_T c12_i61;
  c12_emxArray_real_T_1081 c12_d_b_data;
  int32_T c12_w_loop_ub;
  int32_T c12_result;
  int32_T c12_i62;
  int32_T c12_sizes[2];
  int32_T c12_expected;
  int32_T c12_roundedLimitUnique;
  int32_T c12_f_roundedUnique;
  int32_T c12_b_roundedLimitUnique;
  int32_T c12_g_roundedUnique;
  int32_T c12_iv2[1];
  boolean_T c12_b0;
  int32_T c12_x_loop_ub;
  int32_T c12_y_loop_ub;
  int32_T c12_i63;
  int32_T c12_i64;
  real_T c12_d_x;
  real_T c12_e_x;
  const mxArray *c12_c_y = NULL;
  static char_T c12_cv5[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T c12_nb;
  real_T c12_d_pos;
  const mxArray *c12_d_y = NULL;
  int32_T c12_khi;
  real_T c12_d1;
  int32_T c12_k;
  int32_T c12_ab_loop_ub;
  int32_T c12_i65;
  int32_T c12_i66;
  const mxArray *c12_e_y = NULL;
  int32_T c12_i67;
  int32_T c12_bb_loop_ub;
  int32_T c12_k0;
  const mxArray *c12_f_y = NULL;
  int32_T c12_cb_loop_ub;
  int32_T c12_i68;
  int32_T c12_i69;
  boolean_T c12_b1;
  int32_T c12_e_a;
  boolean_T c12_b2;
  int32_T c12_i70;
  boolean_T c12_b3;
  int32_T c12_b_roundedLimitUnique_size[1];
  int32_T c12_b_roundedUnique_size[2];
  int32_T c12_db_loop_ub;
  int32_T c12_eb_loop_ub;
  int32_T c12_i71;
  int32_T c12_f_a;
  int32_T c12_i72;
  int32_T c12_i73;
  int32_T c12_h_roundedUnique;
  int32_T c12_i_roundedUnique;
  int32_T c12_j_roundedUnique;
  int32_T c12_i74;
  int32_T c12_c_roundedUnique_size[2];
  int32_T c12_fb_loop_ub;
  int32_T c12_c_b;
  boolean_T c12_b_roundedLimitUnique_data[1317];
  int32_T c12_i75;
  int32_T c12_d_b;
  int32_T c12_gb_loop_ub;
  int32_T c12_hb_loop_ub;
  int32_T c12_i76;
  int32_T c12_i77;
  boolean_T c12_overflow;
  int32_T c12_c_roundedLimitUnique;
  int32_T c12_d_roundedLimitUnique;
  int32_T c12_ib_loop_ub;
  int32_T c12_jb_loop_ub;
  int32_T c12_kb_loop_ub;
  int32_T c12_i78;
  int32_T c12_i79;
  int32_T c12_j;
  int32_T c12_i80;
  int32_T c12_lb_loop_ub;
  int32_T c12_i81;
  int32_T c12_g_a;
  int32_T c12_result_size[2];
  int32_T c12_i82;
  int32_T c12_e_b;
  int32_T c12_mb_loop_ub;
  int32_T c12_h_a;
  int32_T c12_nb_loop_ub;
  int32_T c12_i83;
  int32_T c12_f_b;
  int32_T c12_i84;
  int32_T c12_g_b;
  int32_T c12_i85;
  int32_T c12_i86;
  int32_T c12_i_a;
  int32_T c12_ob_loop_ub;
  boolean_T c12_b_overflow;
  int32_T c12_h_b;
  int32_T c12_i87;
  int32_T c12_pb_loop_ub;
  boolean_T c12_c_overflow;
  int32_T c12_i88;
  int32_T c12_i89;
  int32_T c12_c_roundedLimitUnique_size[1];
  int32_T c12_qb_loop_ub;
  int32_T c12_i90;
  int32_T c12_c_orientCart;
  int32_T c12_d_orientCart;
  int32_T c12_rb_loop_ub;
  boolean_T c12_c_roundedLimitUnique_data[1317];
  int32_T c12_i91;
  int32_T c12_e_roundedLimitUnique;
  int32_T c12_f_roundedLimitUnique;
  int32_T c12_sb_loop_ub;
  int32_T c12_i92;
  int32_T c12_i93;
  int32_T c12_i94;
  int32_T c12_tb_loop_ub;
  int32_T c12_i95;
  int32_T c12_i96;
  int32_T c12_d_roundedLimitUnique_size[1];
  int32_T c12_ub_loop_ub;
  int32_T c12_i97;
  boolean_T c12_d_roundedLimitUnique_data[1317];
  int32_T c12_g_roundedLimitUnique;
  int32_T c12_h_roundedLimitUnique;
  int32_T c12_vb_loop_ub;
  int32_T c12_i98;
  int32_T c12_i99;
  int32_T c12_i100;
  int32_T c12_wb_loop_ub;
  int32_T c12_i101;
  int32_T c12_i102;
  int32_T c12_e_roundedLimitUnique_size[1];
  int32_T c12_xb_loop_ub;
  int32_T c12_i103;
  boolean_T c12_e_roundedLimitUnique_data[1317];
  int32_T c12_i_roundedLimitUnique;
  int32_T c12_j_roundedLimitUnique;
  int32_T c12_yb_loop_ub;
  int32_T c12_i104;
  int32_T c12_i105;
  int32_T c12_b_x_size[1];
  int32_T c12_ac_loop_ub;
  int32_T c12_i106;
  int32_T c12_i107;
  real_T c12_b_x_data[1317];
  int32_T c12_y_size[1];
  int32_T c12_bc_loop_ub;
  int32_T c12_i108;
  uint32_T c12_b_debug_family_var_map[9];
  real_T c12_b_y_data[1317];
  real_T c12_len;
  real_T c12_l;
  real_T c12_xmax;
  real_T c12_ymax;
  real_T c12_b_nargin = 4.0;
  real_T c12_b_nargout = 1.0;
  int32_T c12_i109;
  int32_T c12_c_varargin_1;
  int32_T c12_d_varargin_1;
  int32_T c12_n;
  real_T c12_b_len;
  int32_T c12_i110;
  int32_T c12_b_l;
  int32_T c12_i111;
  real_T c12_r;
  uint32_T c12_c_debug_family_var_map[6];
  int32_T c12_b_inflated_size[2];
  real_T c12_c_nargin = 2.0;
  real_T c12_c_nargout = 1.0;
  c12_emxArray_creal_T *c12_r1;
  int32_T c12_i112;
  int32_T c12_i113;
  c12_emxArray_creal_T *c12_r2;
  int32_T c12_i114;
  int32_T c12_i115;
  int32_T c12_i116;
  int32_T c12_cc_loop_ub;
  int32_T c12_i117;
  int32_T c12_i118;
  int32_T c12_i119;
  int32_T c12_dc_loop_ub;
  int32_T c12_i120;
  boolean_T c12_b4;
  c12_emxArray_creal_T *c12_r3;
  boolean_T c12_b5;
  int32_T c12_i121;
  int32_T c12_inflated;
  int32_T c12_i122;
  int32_T c12_b_inflated;
  int32_T c12_ec_loop_ub;
  int32_T c12_i123;
  int32_T c12_i124;
  int32_T c12_i125;
  int32_T c12_fc_loop_ub;
  int32_T c12_i126;
  boolean_T c12_b6;
  creal_T c12_dc2;
  boolean_T c12_b7;
  int32_T c12_c_inflated;
  int32_T c12_d_inflated;
  int32_T c12_i127;
  int32_T c12_end;
  int32_T c12_trueCount;
  int32_T c12_i;
  int32_T c12_b_i;
  c12_emxArray_int32_T *c12_r4;
  int32_T c12_i128;
  int32_T c12_c_i;
  int32_T c12_partialTrueCount;
  int32_T c12_d_i;
  int32_T c12_i129;
  int32_T c12_i130;
  int32_T c12_i131;
  int32_T c12_i132;
  int32_T c12_i133;
  int32_T c12_i134;
  int32_T c12_gc_loop_ub;
  real_T c12_j_a;
  int32_T c12_i135;
  int32_T c12_c_b_size[2];
  int32_T c12_i_b;
  int32_T c12_j_b;
  int32_T c12_i136;
  int32_T c12_i137;
  int32_T c12_k_b;
  int32_T c12_l_b;
  int32_T c12_i138;
  int32_T c12_i139;
  real_T c12_k_a;
  int32_T c12_i140;
  int32_T c12_i141;
  int32_T c12_i142;
  int32_T c12_i143;
  int32_T c12_i144;
  int32_T c12_i145;
  int32_T c12_i146;
  int32_T c12_i147;
  static real_T c12_dv4[3] = { 3081.0, 0.0, 0.0 };

  int32_T c12_i148;
  int32_T c12_i149;
  int32_T c12_i150;
  int32_T c12_i151;
  int32_T c12_i152;
  int32_T c12_i153;
  int32_T c12_i154;
  int32_T c12_i155;
  int32_T c12_i156;
  int32_T c12_i157;
  int32_T c12_i158;
  int32_T c12_i159;
  static char_T c12_cv6[34] = { 'b', 'u', 'i', 'l', 'd', 'M', 'a', 'p', ' ', 'c',
    'o', 'm', 'p', 'l', 'e', 't', 'e', 'd', ' ', 'i', 'n', ' ', '%', 'f', ' ',
    's', 'e', 'c', 'o', 'n', 'd', 's', '\\', 'n' };

  int32_T c12_i160;
  int32_T c12_i161;
  int32_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
  c12_b_hoistedGlobal = *chartInstance->c12_theta;
  c12_c_hoistedGlobal = *chartInstance->c12_scale;
  c12_d_hoistedGlobal = *chartInstance->c12_vehicleRad;
  c12_e_hoistedGlobal = *chartInstance->c12_mode;
  for (c12_i13 = 0; c12_i13 < 2; c12_i13++) {
    c12_b_pos[c12_i13] = (*chartInstance->c12_pos)[c12_i13];
  }

  c12_b_theta = c12_b_hoistedGlobal;
  for (c12_i14 = 0; c12_i14 < 2162; c12_i14++) {
    chartInstance->c12_detectedList[c12_i14] =
      (*chartInstance->c12_c_detectedList)[c12_i14];
  }

  c12_b_scale = c12_c_hoistedGlobal;
  for (c12_i15 = 0; c12_i15 < 2; c12_i15++) {
    c12_b_goal[c12_i15] = (*chartInstance->c12_goal)[c12_i15];
  }

  c12_b_vehicleRad = c12_d_hoistedGlobal;
  for (c12_i16 = 0; c12_i16 < 708; c12_i16++) {
    c12_b_limit[c12_i16] = (*chartInstance->c12_limit)[c12_i16];
  }

  c12_b_mode = c12_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 31U, 31U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_t1, 0U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_mapDim, 1U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_compressed_data, (const int32_T *)&c12_compressed_size,
    NULL, 0, 2, (void *)c12_c_sf_marshallOut, (void *)c12_sf_marshallIn, (void *)
    &chartInstance->c12_compressed_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_orientCart_data, (const int32_T *)&c12_orientCart_size,
    NULL, 0, 3, (void *)c12_c_sf_marshallOut, (void *)c12_sf_marshallIn, (void *)
    &chartInstance->c12_orientCart_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c12_detX_data, (const
    int32_T *)&c12_detX_size, NULL, 0, 4, (void *)c12_d_sf_marshallOut, (void *)
    c12_b_sf_marshallIn, (void *)&c12_detX_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c12_detY_data, (const
    int32_T *)&c12_detY_size, NULL, 0, 5, (void *)c12_d_sf_marshallOut, (void *)
    c12_b_sf_marshallIn, (void *)&c12_detY_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_offset, 6U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_transCart_data, (const int32_T *)&c12_transCart_size,
    NULL, 0, 7, (void *)c12_c_sf_marshallOut, (void *)c12_sf_marshallIn, (void *)
    &chartInstance->c12_transCart_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_roundedUnique_data, (const int32_T *)
    &c12_roundedUnique_size, NULL, 0, 8, (void *)c12_c_sf_marshallOut, (void *)
    c12_sf_marshallIn, (void *)&chartInstance->c12_roundedUnique_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_roundTransCart_data, (const int32_T *)
    &c12_roundTransCart_size, NULL, 0, 9, (void *)c12_c_sf_marshallOut, (void *)
    c12_sf_marshallIn, (void *)&chartInstance->c12_roundTransCart_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_roundedLimitUnique_data, (const int32_T *)
    &c12_roundedLimitUnique_size, NULL, 0, 10, (void *)c12_f_sf_marshallOut,
    (void *)c12_d_sf_marshallIn, (void *)
    &chartInstance->c12_roundedLimitUnique_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_limitGrid, 11U,
    c12_g_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_b_inflated_data, (const int32_T *)&c12_inflated_size,
    NULL, 0, 12, (void *)c12_h_sf_marshallOut, (void *)c12_f_sf_marshallIn,
    (void *)&chartInstance->c12_b_inflated_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_alpha, 13U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_beta, 14U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_mapList, 15U,
    c12_i_sf_marshallOut, c12_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_costsTemp, 16U,
    c12_j_sf_marshallOut, c12_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_time, 17U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 18U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 19U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b_pos, 20U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_theta, 21U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c12_detectedList, 22U,
    c12_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_scale, 23U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b_goal, 24U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_vehicleRad, 25U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b_limit, 26U, c12_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_mode, 27U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_costs, 28U,
    c12_m_sf_marshallOut, c12_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_mapGrid, 29U,
    c12_g_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_mapGridP, 30U,
    c12_n_sf_marshallOut, c12_j_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 7);
  sf_mex_assign(&c12_t1, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "tic",
    1U, 0U), false);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 9);
  for (c12_i17 = 0; c12_i17 < 2; c12_i17++) {
    c12_mapDim[c12_i17] = 80.0 + -40.0 * (real_T)c12_i17;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 12);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c12_mapGridP_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 13);
    for (c12_i18 = 0; c12_i18 < 3081; c12_i18++) {
      chartInstance->c12_mapGridP[c12_i18] = 0.0;
    }

    chartInstance->c12_mapGridP_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 17);
  c12_compressed_size[0] = 1;
  c12_compressed_size[1] = 1;
  c12_compressed = c12_compressed_size[0];
  c12_b_compressed = c12_compressed_size[1];
  chartInstance->c12_compressed_data[0] = rtNaN;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 18);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c12_b_mode, 0.0, -1, 0U,
        c12_b_mode == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 19);
    for (c12_i19 = 0; c12_i19 < 1081; c12_i19++) {
      c12_A[c12_i19] = chartInstance->c12_detectedList[c12_i19 + 1081];
    }

    c12_B = c12_b_scale;
    c12_y = c12_B;
    c12_b_y = c12_y;
    for (c12_i20 = 0; c12_i20 < 1081; c12_i20++) {
      c12_A[c12_i20] /= c12_b_y;
    }

    for (c12_i22 = 0; c12_i22 < 1081; c12_i22++) {
      chartInstance->c12_b_detectedList[c12_i22] =
        chartInstance->c12_detectedList[c12_i22];
    }

    for (c12_i24 = 0; c12_i24 < 1081; c12_i24++) {
      chartInstance->c12_b_detectedList[c12_i24 + 1081] = c12_A[c12_i24];
    }

    c12_compressed_size[0] = 1081;
    c12_compressed_size[1] = 2;
    c12_c_compressed = c12_compressed_size[0];
    c12_d_compressed = c12_compressed_size[1];
    for (c12_i27 = 0; c12_i27 < 2162; c12_i27++) {
      chartInstance->c12_compressed_data[c12_i27] =
        chartInstance->c12_b_detectedList[c12_i27];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 23);
  c12_orientCart_size[0] = 1;
  c12_orientCart_size[1] = 1;
  c12_orientCart = c12_orientCart_size[0];
  c12_b_orientCart = c12_orientCart_size[1];
  chartInstance->c12_orientCart_data[0] = rtNaN;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 24);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1, c12_b_mode, 0.0, -1, 0U,
        c12_b_mode == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 25);
    c12_i21 = c12_compressed_size[0];
    c12_tmp_size[0] = c12_i21;
    c12_loop_ub = c12_i21 - 1;
    for (c12_i23 = 0; c12_i23 <= c12_loop_ub; c12_i23++) {
      c12_d_tmp_data[c12_i23] = c12_i23;
    }

    c12_i25 = c12_compressed_size[0];
    c12_b_detX_size[0] = c12_i25;
    c12_b_loop_ub = c12_i25 - 1;
    for (c12_i26 = 0; c12_i26 <= c12_b_loop_ub; c12_i26++) {
      c12_b_detX_data[c12_i26] = chartInstance->c12_compressed_data[c12_i26];
    }

    c12_iv0[0] = c12_tmp_size[0];
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c12_iv0, 1, c12_b_detX_size, 1);
    c12_c_loop_ub = c12_b_detX_size[0] - 1;
    for (c12_i28 = 0; c12_i28 <= c12_c_loop_ub; c12_i28++) {
      chartInstance->c12_compressed_data[c12_d_tmp_data[c12_i28]] =
        (c12_b_detX_data[c12_i28] + c12_b_theta) - 1.5707963267948966;
    }

    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 26);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 832, 1, MAX_uint32_T, 2, 1, c12_compressed_size[1]);
    c12_i31 = c12_compressed_size[0];
    c12_b_compressed_size[0] = c12_i31;
    c12_f_loop_ub = c12_i31 - 1;
    for (c12_i33 = 0; c12_i33 <= c12_f_loop_ub; c12_i33++) {
      c12_b_compressed_data[c12_i33] = chartInstance->
        c12_compressed_data[c12_i33];
    }

    c12_i37 = c12_compressed_size[0];
    c12_c_compressed_size[0] = c12_i37;
    c12_i_loop_ub = c12_i37 - 1;
    for (c12_i41 = 0; c12_i41 <= c12_i_loop_ub; c12_i41++) {
      c12_c_compressed_data[c12_i41] = chartInstance->
        c12_compressed_data[c12_i41 + c12_compressed_size[0]];
    }

    c12_pol2cart(chartInstance, c12_b_compressed_data, c12_b_compressed_size,
                 c12_c_compressed_data, c12_c_compressed_size, c12_b_detX_data,
                 c12_b_detX_size, c12_b_detY_data, c12_b_detY_size);
    c12_detX_size[0] = c12_b_detX_size[0];
    c12_l_loop_ub = c12_b_detX_size[0] - 1;
    for (c12_i47 = 0; c12_i47 <= c12_l_loop_ub; c12_i47++) {
      c12_detX_data[c12_i47] = c12_b_detX_data[c12_i47];
    }

    c12_detY_size[0] = c12_b_detY_size[0];
    c12_o_loop_ub = c12_b_detY_size[0] - 1;
    for (c12_i50 = 0; c12_i50 <= c12_o_loop_ub; c12_i50++) {
      c12_detY_data[c12_i50] = c12_b_detY_data[c12_i50];
    }

    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 27);
    c12_b_detX_size[0] = c12_detX_size[0];
    c12_r_loop_ub = c12_detX_size[0] - 1;
    for (c12_i54 = 0; c12_i54 <= c12_r_loop_ub; c12_i54++) {
      c12_b_detX_data[c12_i54] = c12_detX_data[c12_i54];
    }

    c12_b_detY_size[0] = c12_detY_size[0];
    c12_v_loop_ub = c12_detY_size[0] - 1;
    for (c12_i60 = 0; c12_i60 <= c12_v_loop_ub; c12_i60++) {
      c12_b_detY_data[c12_i60] = c12_detY_data[c12_i60];
    }

    c12_result = c12_b_detX_size[0];
    c12_sizes[0] = c12_result;
    c12_expected = c12_sizes[0];
    if (c12_b_detX_size[0] == c12_expected) {
      c12_b0 = true;
    } else {
      c12_b0 = false;
    }

    if (c12_b0) {
    } else {
      c12_c_y = NULL;
      sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv5, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      c12_d_y = NULL;
      sf_mex_assign(&c12_d_y, sf_mex_create("y", c12_cv5, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                        c12_c_y, 14, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                         sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c12_d_y)));
    }

    if (c12_b_detY_size[0] == c12_expected) {
      c12_b0 = true;
    } else {
      c12_b0 = false;
    }

    if (c12_b0) {
    } else {
      c12_e_y = NULL;
      sf_mex_assign(&c12_e_y, sf_mex_create("y", c12_cv5, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      c12_f_y = NULL;
      sf_mex_assign(&c12_f_y, sf_mex_create("y", c12_cv5, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                        c12_e_y, 14, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                         sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c12_f_y)));
    }

    chartInstance->c12_reshapes[0].f1.size[0] = c12_b_detX_size[0];
    c12_cb_loop_ub = c12_b_detX_size[0] - 1;
    for (c12_i69 = 0; c12_i69 <= c12_cb_loop_ub; c12_i69++) {
      chartInstance->c12_reshapes[0].f1.data[c12_i69] = c12_b_detX_data[c12_i69];
    }

    chartInstance->c12_reshapes[1].f1.size[0] = c12_b_detY_size[0];
    c12_db_loop_ub = c12_b_detY_size[0] - 1;
    for (c12_i72 = 0; c12_i72 <= c12_db_loop_ub; c12_i72++) {
      chartInstance->c12_reshapes[1].f1.data[c12_i72] = c12_b_detY_data[c12_i72];
    }

    c12_b_detX_size[0] = chartInstance->c12_reshapes[0].f1.size[0];
    c12_gb_loop_ub = chartInstance->c12_reshapes[0].f1.size[0] - 1;
    for (c12_i76 = 0; c12_i76 <= c12_gb_loop_ub; c12_i76++) {
      c12_b_detX_data[c12_i76] = chartInstance->c12_reshapes[0].f1.data[c12_i76];
    }

    c12_b_detY_size[0] = chartInstance->c12_reshapes[1].f1.size[0];
    c12_kb_loop_ub = chartInstance->c12_reshapes[1].f1.size[0] - 1;
    for (c12_i80 = 0; c12_i80 <= c12_kb_loop_ub; c12_i80++) {
      c12_b_detY_data[c12_i80] = chartInstance->c12_reshapes[1].f1.data[c12_i80];
    }

    c12_result_size[0] = c12_b_detX_size[0];
    c12_result_size[1] = 2;
    c12_nb_loop_ub = c12_b_detX_size[0] - 1;
    for (c12_i85 = 0; c12_i85 <= c12_nb_loop_ub; c12_i85++) {
      chartInstance->c12_result_data[c12_i85] = c12_b_detX_data[c12_i85];
    }

    c12_pb_loop_ub = c12_b_detY_size[0] - 1;
    for (c12_i88 = 0; c12_i88 <= c12_pb_loop_ub; c12_i88++) {
      chartInstance->c12_result_data[c12_i88 + c12_result_size[0]] =
        c12_b_detY_data[c12_i88];
    }

    c12_orientCart_size[0] = c12_result_size[0];
    c12_orientCart_size[1] = 2;
    c12_c_orientCart = c12_orientCart_size[0];
    c12_d_orientCart = c12_orientCart_size[1];
    c12_rb_loop_ub = c12_result_size[0] * c12_result_size[1] - 1;
    for (c12_i91 = 0; c12_i91 <= c12_rb_loop_ub; c12_i91++) {
      chartInstance->c12_orientCart_data[c12_i91] =
        chartInstance->c12_result_data[c12_i91];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 31);
  c12_offset = 1.2;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 33);
  c12_transCart_size[0] = 1;
  c12_transCart_size[1] = 1;
  c12_transCart = c12_transCart_size[0];
  c12_b_transCart = c12_transCart_size[1];
  chartInstance->c12_transCart_data[0] = rtNaN;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 34);
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 2, c12_b_mode, 0.0, -1, 0U,
        c12_b_mode == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 35);
    c12_transCart_size[0] = c12_orientCart_size[0];
    c12_transCart_size[1] = c12_orientCart_size[1];
    c12_c_transCart = c12_transCart_size[0];
    c12_d_transCart = c12_transCart_size[1];
    c12_d_loop_ub = c12_orientCart_size[0] * c12_orientCart_size[1] - 1;
    for (c12_i29 = 0; c12_i29 <= c12_d_loop_ub; c12_i29++) {
      chartInstance->c12_transCart_data[c12_i29] =
        chartInstance->c12_orientCart_data[c12_i29];
    }

    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 36);
    c12_i30 = c12_transCart_size[0];
    c12_tmp_size[0] = c12_i30;
    c12_e_loop_ub = c12_i30 - 1;
    for (c12_i32 = 0; c12_i32 <= c12_e_loop_ub; c12_i32++) {
      c12_d_tmp_data[c12_i32] = c12_i32;
    }

    c12_i36 = c12_transCart_size[0];
    c12_b_detX_size[0] = c12_i36;
    c12_h_loop_ub = c12_i36 - 1;
    for (c12_i40 = 0; c12_i40 <= c12_h_loop_ub; c12_i40++) {
      c12_b_detX_data[c12_i40] = chartInstance->c12_transCart_data[c12_i40];
    }

    c12_iv1[0] = c12_tmp_size[0];
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c12_iv1, 1, c12_b_detX_size, 1);
    c12_b_x = c12_b_theta;
    c12_c_x = c12_b_x;
    c12_c_x = muDoubleScalarCos(c12_c_x);
    c12_c_pos = c12_b_pos[0];
    c12_d0 = 1.2 * c12_c_x;
    c12_n_loop_ub = c12_b_detX_size[0] - 1;
    for (c12_i49 = 0; c12_i49 <= c12_n_loop_ub; c12_i49++) {
      chartInstance->c12_transCart_data[c12_d_tmp_data[c12_i49]] =
        (c12_b_detX_data[c12_i49] + c12_c_pos) + c12_d0;
    }

    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 37);
    c12_i53 = c12_transCart_size[0];
    c12_tmp_size[0] = c12_i53;
    c12_s_loop_ub = c12_i53 - 1;
    for (c12_i55 = 0; c12_i55 <= c12_s_loop_ub; c12_i55++) {
      c12_d_tmp_data[c12_i55] = c12_i55;
    }

    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 1178, 1, MAX_uint32_T, 2, 1, c12_transCart_size[1]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 1195, 1, MAX_uint32_T, 2, 1, c12_transCart_size[1]);
    c12_i61 = c12_transCart_size[0];
    c12_b_detX_size[0] = c12_i61;
    c12_w_loop_ub = c12_i61 - 1;
    for (c12_i62 = 0; c12_i62 <= c12_w_loop_ub; c12_i62++) {
      c12_b_detX_data[c12_i62] = chartInstance->c12_transCart_data[c12_i62 +
        c12_transCart_size[0]];
    }

    c12_iv2[0] = c12_tmp_size[0];
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c12_iv2, 1, c12_b_detX_size, 1);
    c12_d_x = c12_b_theta;
    c12_e_x = c12_d_x;
    c12_e_x = muDoubleScalarSin(c12_e_x);
    c12_d_pos = c12_b_pos[1];
    c12_d1 = 1.2 * c12_e_x;
    c12_ab_loop_ub = c12_b_detX_size[0] - 1;
    for (c12_i66 = 0; c12_i66 <= c12_ab_loop_ub; c12_i66++) {
      chartInstance->c12_transCart_data[c12_d_tmp_data[c12_i66] +
        c12_transCart_size[0]] = (c12_b_detX_data[c12_i66] + c12_d_pos) + c12_d1;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 41);
  c12_roundedUnique_size[0] = 1;
  c12_roundedUnique_size[1] = 1;
  c12_roundedUnique = c12_roundedUnique_size[0];
  c12_b_roundedUnique = c12_roundedUnique_size[1];
  chartInstance->c12_roundedUnique_data[0] = rtNaN;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 42);
  if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 3, c12_b_mode, 0.0, -1, 0U,
        c12_b_mode == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 43);
    c12_a_size[0] = c12_transCart_size[0];
    c12_a_size[1] = c12_transCart_size[1];
    c12_a = c12_a_size[0];
    c12_b_a = c12_a_size[1];
    c12_g_loop_ub = c12_transCart_size[0] * c12_transCart_size[1] - 1;
    for (c12_i35 = 0; c12_i35 <= c12_g_loop_ub; c12_i35++) {
      chartInstance->c12_a_data[c12_i35] = chartInstance->
        c12_transCart_data[c12_i35];
    }

    c12_b_round(chartInstance, chartInstance->c12_a_data, c12_a_size);
    c12_roundTransCart_size[0] = c12_a_size[0];
    c12_roundTransCart_size[1] = c12_a_size[1];
    c12_roundTransCart = c12_roundTransCart_size[0];
    c12_b_roundTransCart = c12_roundTransCart_size[1];
    c12_j_loop_ub = c12_a_size[0] * c12_a_size[1] - 1;
    for (c12_i44 = 0; c12_i44 <= c12_j_loop_ub; c12_i44++) {
      chartInstance->c12_roundTransCart_data[c12_i44] =
        chartInstance->c12_a_data[c12_i44];
    }

    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 44);
    c12_a_size[0] = c12_roundTransCart_size[0];
    c12_a_size[1] = c12_roundTransCart_size[1];
    c12_c_a = c12_a_size[0];
    c12_d_a = c12_a_size[1];
    c12_q_loop_ub = c12_roundTransCart_size[0] * c12_roundTransCart_size[1] - 1;
    for (c12_i52 = 0; c12_i52 <= c12_q_loop_ub; c12_i52++) {
      chartInstance->c12_a_data[c12_i52] =
        chartInstance->c12_roundTransCart_data[c12_i52];
    }

    c12_b_b_size[0] = c12_a_size[0];
    c12_b_b_size[1] = c12_a_size[1];
    c12_b = c12_b_b_size[0];
    c12_b_b = c12_b_b_size[1];
    c12_u_loop_ub = c12_a_size[0] * c12_a_size[1] - 1;
    for (c12_i59 = 0; c12_i59 <= c12_u_loop_ub; c12_i59++) {
      chartInstance->c12_b_b_data[c12_i59] = chartInstance->c12_a_data[c12_i59];
    }

    c12_b_sortrows(chartInstance, chartInstance->c12_b_b_data, c12_b_b_size,
                   c12_d_b_data.data, c12_d_b_data.size);
    c12_roundedUnique_size[0] = c12_b_b_size[0];
    c12_roundedUnique_size[1] = c12_b_b_size[1];
    c12_f_roundedUnique = c12_roundedUnique_size[0];
    c12_g_roundedUnique = c12_roundedUnique_size[1];
    c12_y_loop_ub = c12_b_b_size[0] * c12_b_b_size[1] - 1;
    for (c12_i64 = 0; c12_i64 <= c12_y_loop_ub; c12_i64++) {
      chartInstance->c12_roundedUnique_data[c12_i64] =
        chartInstance->c12_b_b_data[c12_i64];
    }

    c12_nb = 0;
    c12_khi = c12_a_size[0];
    c12_k = 1;
    while (c12_k <= c12_khi) {
      c12_k0 = c12_k;
      do {
        exitg1 = 0;
        c12_e_a = c12_k + 1;
        c12_k = c12_e_a;
        if (c12_k > c12_khi) {
          exitg1 = 1;
        } else {
          c12_b_roundedUnique_size[0] = c12_roundedUnique_size[0];
          c12_b_roundedUnique_size[1] = c12_roundedUnique_size[1];
          c12_h_roundedUnique = c12_b_roundedUnique_size[0];
          c12_j_roundedUnique = c12_b_roundedUnique_size[1];
          c12_fb_loop_ub = c12_roundedUnique_size[0] * c12_roundedUnique_size[1]
            - 1;
          for (c12_i75 = 0; c12_i75 <= c12_fb_loop_ub; c12_i75++) {
            chartInstance->c12_b_roundedUnique_data[c12_i75] =
              chartInstance->c12_roundedUnique_data[c12_i75];
          }

          if (c12_rows_differ(chartInstance,
                              chartInstance->c12_b_roundedUnique_data,
                              c12_b_roundedUnique_size, c12_k0, c12_k)) {
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      c12_f_a = c12_nb + 1;
      c12_nb = c12_f_a;
      c12_i74 = c12_roundedUnique_size[1];
      c12_c_b = c12_i74;
      c12_d_b = c12_c_b;
      if (1 > c12_d_b) {
        c12_overflow = false;
      } else {
        c12_overflow = (c12_d_b > 2147483646);
      }

      if (c12_overflow) {
        c12_check_forloop_overflow_error(chartInstance, true);
      }

      for (c12_j = 0; c12_j < c12_i74; c12_j++) {
        chartInstance->c12_roundedUnique_data[(c12_nb + c12_roundedUnique_size[0]
          * c12_j) - 1] = chartInstance->c12_roundedUnique_data[(c12_k0 +
          c12_roundedUnique_size[0] * c12_j) - 1];
      }

      c12_g_a = c12_k;
      c12_i82 = c12_g_a;
      c12_h_a = c12_k0;
      c12_g_b = c12_i82 - 1;
      c12_i_a = c12_h_a;
      c12_h_b = c12_g_b;
      if (c12_i_a > c12_h_b) {
        c12_c_overflow = false;
      } else {
        c12_c_overflow = (c12_h_b > 2147483646);
      }

      if (c12_c_overflow) {
        c12_check_forloop_overflow_error(chartInstance, true);
      }
    }

    if (c12_nb <= c12_a_size[0]) {
    } else {
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                        c12_b_emlrt_marshallOut(chartInstance, c12_cv0), 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c12_b_emlrt_marshallOut(chartInstance, c12_cv0))));
    }

    c12_b1 = (1 > c12_nb);
    c12_b2 = c12_b1;
    c12_b3 = c12_b2;
    if (c12_b3) {
      c12_i71 = 0;
    } else {
      c12_i71 = c12_nb;
    }

    c12_i_roundedUnique = c12_roundedUnique_size[1];
    c12_c_roundedUnique_size[0] = c12_i71;
    c12_c_roundedUnique_size[1] = c12_i_roundedUnique;
    c12_hb_loop_ub = c12_i_roundedUnique - 1;
    for (c12_i77 = 0; c12_i77 <= c12_hb_loop_ub; c12_i77++) {
      c12_jb_loop_ub = c12_i71 - 1;
      for (c12_i79 = 0; c12_i79 <= c12_jb_loop_ub; c12_i79++) {
        chartInstance->c12_c_roundedUnique_data[c12_i79 +
          c12_c_roundedUnique_size[0] * c12_i77] =
          chartInstance->c12_roundedUnique_data[c12_i79 +
          c12_roundedUnique_size[0] * c12_i77];
      }
    }

    c12_roundedUnique_size[0] = c12_c_roundedUnique_size[0];
    c12_roundedUnique_size[1] = c12_c_roundedUnique_size[1];
    c12_lb_loop_ub = c12_c_roundedUnique_size[1] - 1;
    for (c12_i81 = 0; c12_i81 <= c12_lb_loop_ub; c12_i81++) {
      c12_mb_loop_ub = c12_c_roundedUnique_size[0] - 1;
      for (c12_i84 = 0; c12_i84 <= c12_mb_loop_ub; c12_i84++) {
        chartInstance->c12_roundedUnique_data[c12_i84 + c12_roundedUnique_size[0]
          * c12_i81] = chartInstance->c12_c_roundedUnique_data[c12_i84 +
          c12_c_roundedUnique_size[0] * c12_i81];
      }
    }

    c12_e_b = c12_nb;
    c12_f_b = c12_e_b;
    if (1 > c12_f_b) {
      c12_b_overflow = false;
    } else {
      c12_b_overflow = (c12_f_b > 2147483646);
    }

    if (c12_b_overflow) {
      c12_check_forloop_overflow_error(chartInstance, true);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 48);
  if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 4, c12_b_mode, 1.0, -1, 0U,
        c12_b_mode == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 49);
    c12_roundedUnique_size[0] = 1081;
    c12_roundedUnique_size[1] = 2;
    c12_d_roundedUnique = c12_roundedUnique_size[0];
    c12_e_roundedUnique = c12_roundedUnique_size[1];
    for (c12_i38 = 0; c12_i38 < 2162; c12_i38++) {
      chartInstance->c12_roundedUnique_data[c12_i38] =
        chartInstance->c12_detectedList[c12_i38];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 53);
  c12_i34 = c12_roundedUnique_size[0];
  c12_c_roundedUnique = c12_roundedUnique_size[1];
  c12_roundedLimitUnique_size[0] = 236 + c12_i34;
  c12_roundedLimitUnique_size[1] = 2;
  for (c12_i39 = 0; c12_i39 < 2; c12_i39++) {
    for (c12_i43 = 0; c12_i43 < 236; c12_i43++) {
      chartInstance->c12_roundedLimitUnique_data[c12_i43 +
        c12_roundedLimitUnique_size[0] * c12_i39] = c12_b_limit[c12_i43 + 236 *
        c12_i39];
    }
  }

  for (c12_i42 = 0; c12_i42 < 2; c12_i42++) {
    c12_k_loop_ub = c12_i34 - 1;
    for (c12_i46 = 0; c12_i46 <= c12_k_loop_ub; c12_i46++) {
      chartInstance->c12_roundedLimitUnique_data[(c12_i46 +
        c12_roundedLimitUnique_size[0] * c12_i42) + 236] =
        chartInstance->c12_roundedUnique_data[c12_i46 + c12_roundedUnique_size[0]
        * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 1659, 20, MAX_uint32_T, c12_i42 + 1, 1,
            c12_c_roundedUnique) - 1)];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 56);
  c12_i45 = c12_roundedLimitUnique_size[0];
  c12_x_size[0] = c12_i45;
  c12_m_loop_ub = c12_i45 - 1;
  for (c12_i48 = 0; c12_i48 <= c12_m_loop_ub; c12_i48++) {
    c12_x_data[c12_i48] = chartInstance->c12_roundedLimitUnique_data[c12_i48];
  }

  c12_b_size[0] = c12_x_size[0];
  c12_p_loop_ub = c12_x_size[0] - 1;
  for (c12_i51 = 0; c12_i51 <= c12_p_loop_ub; c12_i51++) {
    c12_c_b_data[c12_i51] = muDoubleScalarIsNaN(c12_x_data[c12_i51]);
  }

  c12_b_tmp_size[0] = c12_roundedLimitUnique_size[0];
  c12_b_tmp_size[1] = 2;
  c12_i56 = c12_b_tmp_size[0];
  c12_i57 = c12_b_tmp_size[1];
  c12_t_loop_ub = c12_roundedLimitUnique_size[0] * c12_roundedLimitUnique_size[1]
    - 1;
  for (c12_i58 = 0; c12_i58 <= c12_t_loop_ub; c12_i58++) {
    chartInstance->c12_c_tmp_data[c12_i58] =
      chartInstance->c12_roundedLimitUnique_data[c12_i58];
  }

  c12_b_nullAssignment(chartInstance, chartInstance->c12_c_tmp_data,
                       c12_b_tmp_size, c12_c_b_data, c12_b_size);
  c12_roundedLimitUnique_size[0] = c12_b_tmp_size[0];
  c12_roundedLimitUnique_size[1] = 2;
  c12_roundedLimitUnique = c12_roundedLimitUnique_size[0];
  c12_b_roundedLimitUnique = c12_roundedLimitUnique_size[1];
  c12_x_loop_ub = c12_b_tmp_size[0] * c12_b_tmp_size[1] - 1;
  for (c12_i63 = 0; c12_i63 <= c12_x_loop_ub; c12_i63++) {
    chartInstance->c12_roundedLimitUnique_data[c12_i63] =
      chartInstance->c12_c_tmp_data[c12_i63];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 57);
  c12_b_tmp_size[0] = c12_roundedLimitUnique_size[0];
  c12_b_tmp_size[1] = 2;
  c12_i65 = c12_b_tmp_size[0];
  c12_i67 = c12_b_tmp_size[1];
  c12_bb_loop_ub = c12_roundedLimitUnique_size[0] * c12_roundedLimitUnique_size
    [1] - 1;
  for (c12_i68 = 0; c12_i68 <= c12_bb_loop_ub; c12_i68++) {
    chartInstance->c12_c_tmp_data[c12_i68] =
      chartInstance->c12_roundedLimitUnique_data[c12_i68];
  }

  c12_i70 = c12_roundedLimitUnique_size[0];
  c12_b_roundedLimitUnique_size[0] = c12_i70;
  c12_eb_loop_ub = c12_i70 - 1;
  for (c12_i73 = 0; c12_i73 <= c12_eb_loop_ub; c12_i73++) {
    c12_b_roundedLimitUnique_data[c12_i73] =
      (chartInstance->c12_roundedLimitUnique_data[c12_i73] <= 0.0);
  }

  c12_b_nullAssignment(chartInstance, chartInstance->c12_c_tmp_data,
                       c12_b_tmp_size, c12_b_roundedLimitUnique_data,
                       c12_b_roundedLimitUnique_size);
  c12_roundedLimitUnique_size[0] = c12_b_tmp_size[0];
  c12_roundedLimitUnique_size[1] = 2;
  c12_c_roundedLimitUnique = c12_roundedLimitUnique_size[0];
  c12_d_roundedLimitUnique = c12_roundedLimitUnique_size[1];
  c12_ib_loop_ub = c12_b_tmp_size[0] * c12_b_tmp_size[1] - 1;
  for (c12_i78 = 0; c12_i78 <= c12_ib_loop_ub; c12_i78++) {
    chartInstance->c12_roundedLimitUnique_data[c12_i78] =
      chartInstance->c12_c_tmp_data[c12_i78];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 58);
  c12_b_tmp_size[0] = c12_roundedLimitUnique_size[0];
  c12_b_tmp_size[1] = 2;
  c12_i83 = c12_b_tmp_size[0];
  c12_i86 = c12_b_tmp_size[1];
  c12_ob_loop_ub = c12_roundedLimitUnique_size[0] * c12_roundedLimitUnique_size
    [1] - 1;
  for (c12_i87 = 0; c12_i87 <= c12_ob_loop_ub; c12_i87++) {
    chartInstance->c12_c_tmp_data[c12_i87] =
      chartInstance->c12_roundedLimitUnique_data[c12_i87];
  }

  c12_i89 = c12_roundedLimitUnique_size[0];
  c12_c_roundedLimitUnique_size[0] = c12_i89;
  c12_qb_loop_ub = c12_i89 - 1;
  for (c12_i90 = 0; c12_i90 <= c12_qb_loop_ub; c12_i90++) {
    c12_c_roundedLimitUnique_data[c12_i90] =
      (chartInstance->c12_roundedLimitUnique_data[c12_i90] > 79.0);
  }

  c12_b_nullAssignment(chartInstance, chartInstance->c12_c_tmp_data,
                       c12_b_tmp_size, c12_c_roundedLimitUnique_data,
                       c12_c_roundedLimitUnique_size);
  c12_roundedLimitUnique_size[0] = c12_b_tmp_size[0];
  c12_roundedLimitUnique_size[1] = 2;
  c12_e_roundedLimitUnique = c12_roundedLimitUnique_size[0];
  c12_f_roundedLimitUnique = c12_roundedLimitUnique_size[1];
  c12_sb_loop_ub = c12_b_tmp_size[0] * c12_b_tmp_size[1] - 1;
  for (c12_i92 = 0; c12_i92 <= c12_sb_loop_ub; c12_i92++) {
    chartInstance->c12_roundedLimitUnique_data[c12_i92] =
      chartInstance->c12_c_tmp_data[c12_i92];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 59);
  c12_b_tmp_size[0] = c12_roundedLimitUnique_size[0];
  c12_b_tmp_size[1] = 2;
  c12_i93 = c12_b_tmp_size[0];
  c12_i94 = c12_b_tmp_size[1];
  c12_tb_loop_ub = c12_roundedLimitUnique_size[0] * c12_roundedLimitUnique_size
    [1] - 1;
  for (c12_i95 = 0; c12_i95 <= c12_tb_loop_ub; c12_i95++) {
    chartInstance->c12_c_tmp_data[c12_i95] =
      chartInstance->c12_roundedLimitUnique_data[c12_i95];
  }

  c12_i96 = c12_roundedLimitUnique_size[0];
  c12_d_roundedLimitUnique_size[0] = c12_i96;
  c12_ub_loop_ub = c12_i96 - 1;
  for (c12_i97 = 0; c12_i97 <= c12_ub_loop_ub; c12_i97++) {
    c12_d_roundedLimitUnique_data[c12_i97] =
      (chartInstance->c12_roundedLimitUnique_data[c12_i97 +
       c12_roundedLimitUnique_size[0]] <= 0.0);
  }

  c12_b_nullAssignment(chartInstance, chartInstance->c12_c_tmp_data,
                       c12_b_tmp_size, c12_d_roundedLimitUnique_data,
                       c12_d_roundedLimitUnique_size);
  c12_roundedLimitUnique_size[0] = c12_b_tmp_size[0];
  c12_roundedLimitUnique_size[1] = 2;
  c12_g_roundedLimitUnique = c12_roundedLimitUnique_size[0];
  c12_h_roundedLimitUnique = c12_roundedLimitUnique_size[1];
  c12_vb_loop_ub = c12_b_tmp_size[0] * c12_b_tmp_size[1] - 1;
  for (c12_i98 = 0; c12_i98 <= c12_vb_loop_ub; c12_i98++) {
    chartInstance->c12_roundedLimitUnique_data[c12_i98] =
      chartInstance->c12_c_tmp_data[c12_i98];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 60);
  c12_b_tmp_size[0] = c12_roundedLimitUnique_size[0];
  c12_b_tmp_size[1] = 2;
  c12_i99 = c12_b_tmp_size[0];
  c12_i100 = c12_b_tmp_size[1];
  c12_wb_loop_ub = c12_roundedLimitUnique_size[0] * c12_roundedLimitUnique_size
    [1] - 1;
  for (c12_i101 = 0; c12_i101 <= c12_wb_loop_ub; c12_i101++) {
    chartInstance->c12_c_tmp_data[c12_i101] =
      chartInstance->c12_roundedLimitUnique_data[c12_i101];
  }

  c12_i102 = c12_roundedLimitUnique_size[0];
  c12_e_roundedLimitUnique_size[0] = c12_i102;
  c12_xb_loop_ub = c12_i102 - 1;
  for (c12_i103 = 0; c12_i103 <= c12_xb_loop_ub; c12_i103++) {
    c12_e_roundedLimitUnique_data[c12_i103] =
      (chartInstance->c12_roundedLimitUnique_data[c12_i103 +
       c12_roundedLimitUnique_size[0]] > 39.0);
  }

  c12_b_nullAssignment(chartInstance, chartInstance->c12_c_tmp_data,
                       c12_b_tmp_size, c12_e_roundedLimitUnique_data,
                       c12_e_roundedLimitUnique_size);
  c12_roundedLimitUnique_size[0] = c12_b_tmp_size[0];
  c12_roundedLimitUnique_size[1] = 2;
  c12_i_roundedLimitUnique = c12_roundedLimitUnique_size[0];
  c12_j_roundedLimitUnique = c12_roundedLimitUnique_size[1];
  c12_yb_loop_ub = c12_b_tmp_size[0] * c12_b_tmp_size[1] - 1;
  for (c12_i104 = 0; c12_i104 <= c12_yb_loop_ub; c12_i104++) {
    chartInstance->c12_roundedLimitUnique_data[c12_i104] =
      chartInstance->c12_c_tmp_data[c12_i104];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 63);
  c12_i105 = c12_roundedLimitUnique_size[0];
  c12_b_x_size[0] = c12_i105;
  c12_ac_loop_ub = c12_i105 - 1;
  for (c12_i106 = 0; c12_i106 <= c12_ac_loop_ub; c12_i106++) {
    c12_b_x_data[c12_i106] = chartInstance->c12_roundedLimitUnique_data[c12_i106];
  }

  c12_i107 = c12_roundedLimitUnique_size[0];
  c12_y_size[0] = c12_i107;
  c12_bc_loop_ub = c12_i107 - 1;
  for (c12_i108 = 0; c12_i108 <= c12_bc_loop_ub; c12_i108++) {
    c12_b_y_data[c12_i108] = chartInstance->c12_roundedLimitUnique_data[c12_i108
      + c12_roundedLimitUnique_size[0]];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c12_b_debug_family_names,
    c12_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_len, 0U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_l, 1U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_xmax, 2U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_ymax, 3U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_nargin, 4U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_nargout, 5U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c12_b_x_data, (const
    int32_T *)&c12_b_x_size, NULL, 1, 6, (void *)c12_o_sf_marshallOut, (void *)
    c12_k_sf_marshallIn, (void *)&c12_b_x_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c12_b_y_data, (const
    int32_T *)&c12_y_size, NULL, 1, 7, (void *)c12_o_sf_marshallOut, (void *)
    c12_k_sf_marshallIn, (void *)&c12_b_y_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_limitGrid, 8U,
    c12_g_sf_marshallOut, c12_e_sf_marshallIn);
  c12_ymax = 39.0;
  c12_xmax = 79.0;
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 2);
  for (c12_i109 = 0; c12_i109 < 3081; c12_i109++) {
    chartInstance->c12_limitGrid[c12_i109] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 3);
  c12_c_varargin_1 = c12_b_x_size[0];
  c12_d_varargin_1 = c12_c_varargin_1;
  c12_n = c12_d_varargin_1;
  c12_len = (real_T)c12_n;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 5);
  c12_b_len = c12_len;
  c12_i110 = (int32_T)c12_b_len - 1;
  c12_l = 1.0;
  c12_b_l = 0;
  while (c12_b_l <= c12_i110) {
    c12_l = 1.0 + (real_T)c12_b_l;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 6);
    chartInstance->c12_limitGrid[(sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2127, 85, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 2127U, 85U,
      c12_b_y_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 2127, 85, MAX_uint32_T, (int32_T)c12_l, 1,
      c12_y_size[0]) - 1]), 1, 39) + 39 * (sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2127, 85, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 2127U, 85U,
      c12_b_x_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 2127, 85, MAX_uint32_T, (int32_T)c12_l, 1,
      c12_b_x_size[0]) - 1]), 1, 79) - 1)) - 1] = 1.0;
    c12_b_l++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 66);
  if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 5, c12_b_vehicleRad, 0.0, -1,
        3U, c12_b_vehicleRad <= 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 67);
    c12_b_vehicleRad = 0.1;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 69);
  for (c12_i111 = 0; c12_i111 < 3081; c12_i111++) {
    chartInstance->c12_grid[c12_i111] = chartInstance->c12_limitGrid[c12_i111];
  }

  c12_r = c12_b_vehicleRad;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 7U, c12_c_debug_family_names,
    c12_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_inflated_data, (const int32_T *)&c12_b_inflated_size,
    NULL, 0, -1, (void *)c12_p_sf_marshallOut, (void *)c12_l_sf_marshallIn,
    (void *)&chartInstance->c12_inflated_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_c_nargin, 1U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_c_nargout, 2U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c12_grid, 3U,
    c12_g_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_r, 4U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &chartInstance->c12_b_inflated_data, (const int32_T *)&c12_inflated_size,
    NULL, 0, -1, (void *)c12_h_sf_marshallOut, (void *)c12_f_sf_marshallIn,
    (void *)&chartInstance->c12_b_inflated_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(chartInstance->c12_h->data, (
    const int32_T *)chartInstance->c12_h->size, NULL, 1, 5, (void *)
    c12_q_sf_marshallOut, (void *)c12_m_sf_marshallIn, (void *)
    chartInstance->c12_h, true);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 4);
  if (CV_SCRIPT_IF(1, 0, !chartInstance->c12_h_not_empty)) {
    c12_emxInit_creal_T(chartInstance, &c12_r1, 2, &c12_ec_emlrtRTEI);
    _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 5);
    c12_fspecial(chartInstance, c12_r, c12_r1);
    c12_i113 = chartInstance->c12_h->size[0] * chartInstance->c12_h->size[1];
    chartInstance->c12_h->size[0] = c12_r1->size[0];
    chartInstance->c12_h->size[1] = c12_r1->size[1];
    c12_emxEnsureCapacity_creal_T(chartInstance, chartInstance->c12_h, c12_i113,
      &c12_tb_emlrtRTEI);
    c12_i115 = chartInstance->c12_h->size[0];
    c12_i116 = chartInstance->c12_h->size[1];
    c12_cc_loop_ub = c12_r1->size[0] * c12_r1->size[1] - 1;
    for (c12_i118 = 0; c12_i118 <= c12_cc_loop_ub; c12_i118++) {
      chartInstance->c12_h->data[c12_i118] = c12_r1->data[c12_i118];
    }

    c12_emxFree_creal_T(chartInstance, &c12_r1);
    chartInstance->c12_h_not_empty = true;
    c12_b4 = (chartInstance->c12_h->size[0] == 0);
    c12_b5 = (chartInstance->c12_h->size[1] == 0);
    chartInstance->c12_h_not_empty = !(c12_b4 || c12_b5);
    _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 6);
    c12_i121 = chartInstance->c12_h->size[0] * chartInstance->c12_h->size[1];
    c12_i122 = chartInstance->c12_h->size[0] * chartInstance->c12_h->size[1];
    chartInstance->c12_h->size[0];
    chartInstance->c12_h->size[1];
    c12_emxEnsureCapacity_creal_T(chartInstance, chartInstance->c12_h, c12_i122,
      &c12_wb_emlrtRTEI);
    c12_i124 = chartInstance->c12_h->size[0];
    c12_i125 = chartInstance->c12_h->size[1];
    c12_fc_loop_ub = c12_i121 - 1;
    for (c12_i126 = 0; c12_i126 <= c12_fc_loop_ub; c12_i126++) {
      c12_dc2 = chartInstance->c12_h->data[c12_i126];
      chartInstance->c12_h->data[c12_i126].re = c12_dc2.re;
      chartInstance->c12_h->data[c12_i126].im = 0.0;
    }

    c12_b6 = (chartInstance->c12_h->size[0] == 0);
    c12_b7 = (chartInstance->c12_h->size[1] == 0);
    chartInstance->c12_h_not_empty = !(c12_b6 || c12_b7);
    _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 7);
    c12_end = c12__s32_s64_(chartInstance, (int64_T)chartInstance->c12_h->size[0]
      * (int64_T)chartInstance->c12_h->size[1], 1U, 2346, 31);
    c12_trueCount = 0;
    c12_i = 0;
    while (c12_i <= c12__s32_minus__(chartInstance, c12_end, 1, 1U, 2346, 31)) {
      if (chartInstance->c12_h->data[c12_i].re > c12_dc0.re) {
        c12_trueCount = c12__s32_add__(chartInstance, c12_trueCount, 1, 1U, 2346,
          31);
      }

      c12_i = c12__s32_add__(chartInstance, c12_i, 1, 1U, 2346, 31);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c12_emxInit_int32_T(chartInstance, &c12_r4, 1, &c12_cc_emlrtRTEI);
    c12_i128 = c12_r4->size[0];
    c12_r4->size[0] = c12_trueCount;
    c12_emxEnsureCapacity_int32_T(chartInstance, c12_r4, c12_i128,
      &c12_yb_emlrtRTEI);
    c12_partialTrueCount = 0;
    c12_d_i = 0;
    while (c12_d_i <= c12__s32_minus__(chartInstance, c12_end, 1, 1U, 2346, 31))
    {
      if (chartInstance->c12_h->data[c12_d_i].re > c12_dc0.re) {
        c12_r4->data[c12_partialTrueCount] = c12__s32_add__(chartInstance,
          c12_d_i, 1, 1U, 2346, 31);
        c12_partialTrueCount = c12__s32_add__(chartInstance,
          c12_partialTrueCount, 1, 1U, 2346, 31);
      }

      c12_d_i = c12__s32_add__(chartInstance, c12_d_i, 1, 1U, 2346, 31);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c12_i129 = c12_r4->size[0];
    c12_i130 = chartInstance->c12_h->size[0];
    c12_i131 = chartInstance->c12_h->size[1];
    c12_i132 = chartInstance->c12_h->size[0];
    c12_i133 = chartInstance->c12_h->size[1];
    c12_i134 = c12__s32_s64_(chartInstance, (int64_T)c12_i132 * (int64_T)
      c12_i133, 1U, 2346, 31);
    c12_gc_loop_ub = c12_i129 - 1;
    for (c12_i135 = 0; c12_i135 <= c12_gc_loop_ub; c12_i135++) {
      chartInstance->c12_h->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2346, 31,
         MAX_uint32_T, c12_r4->data[c12_i135], 1, c12_i134) - 1].re = c12_dc1.re;
      chartInstance->c12_h->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2346, 31,
         MAX_uint32_T, c12_r4->data[c12_i135], 1, c12_i134) - 1].im = c12_dc1.im;
    }

    c12_emxFree_int32_T(chartInstance, &c12_r4);
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 10);
  for (c12_i112 = 0; c12_i112 < 3081; c12_i112++) {
    chartInstance->c12_b_grid[c12_i112] = chartInstance->c12_grid[c12_i112];
  }

  c12_emxInit_creal_T(chartInstance, &c12_r2, 2, &c12_ub_emlrtRTEI);
  c12_i114 = c12_r2->size[0] * c12_r2->size[1];
  c12_r2->size[0] = chartInstance->c12_h->size[0];
  c12_r2->size[1] = chartInstance->c12_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_r2, c12_i114,
    &c12_ub_emlrtRTEI);
  c12_i117 = c12_r2->size[0];
  c12_i119 = c12_r2->size[1];
  c12_dc_loop_ub = chartInstance->c12_h->size[0] * chartInstance->c12_h->size[1]
    - 1;
  for (c12_i120 = 0; c12_i120 <= c12_dc_loop_ub; c12_i120++) {
    c12_r2->data[c12_i120] = chartInstance->c12_h->data[c12_i120];
  }

  c12_emxInit_creal_T(chartInstance, &c12_r3, 2, &c12_dc_emlrtRTEI);
  c12_imfilter(chartInstance, chartInstance->c12_b_grid, c12_r2, c12_r3);
  c12_b_inflated_size[0] = c12_r3->size[0];
  c12_b_inflated_size[1] = 79;
  c12_inflated = c12_b_inflated_size[0];
  c12_b_inflated = c12_b_inflated_size[1];
  c12_ec_loop_ub = c12_r3->size[0] * c12_r3->size[1] - 1;
  c12_emxFree_creal_T(chartInstance, &c12_r2);
  for (c12_i123 = 0; c12_i123 <= c12_ec_loop_ub; c12_i123++) {
    chartInstance->c12_inflated_data[c12_i123] = c12_r3->data[c12_i123];
  }

  c12_emxFree_creal_T(chartInstance, &c12_r3);
  _SFD_SYMBOL_SWITCH(0U, 0U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 11);
  c12_inflated_size[0] = 39;
  c12_inflated_size[1] = 79;
  c12_c_inflated = c12_inflated_size[0];
  c12_d_inflated = c12_inflated_size[1];
  for (c12_i127 = 0; c12_i127 < 3081; c12_i127++) {
    chartInstance->c12_b_inflated_data[c12_i127] =
      chartInstance->c12_inflated_data[c12_i127].re;
  }

  _SFD_SYMBOL_SWITCH(0U, 5U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, 12);
  c12_b_i = 0;
  while (c12_b_i <= 3080) {
    c12_b_i = c12__s32_add__(chartInstance, c12_b_i, 1, 1U, 2346, 31);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c12_c_i = 0;
  while (c12_c_i <= 3080) {
    if (chartInstance->c12_b_inflated_data[c12_c_i] > 1.0) {
      chartInstance->c12_b_inflated_data[c12__s32_add__(chartInstance, c12_c_i,
        1, 1U, 2346, 31) - 1] = 1.0;
      _SFD_SYMBOL_SWITCH(0U, 5U);
    }

    c12_c_i = c12__s32_add__(chartInstance, c12_c_i, 1, 1U, 2346, 31);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c12_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 72);
  if (CV_EML_IF(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 6, c12_b_mode, 0.0, -1, 0U,
        c12_b_mode == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 73);
    c12_alpha = 0.8;
    c12_beta = 0.2;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 75);
    c12_alpha = 0.99;
    c12_beta = 0.01;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 77);
  c12_j_a = c12_beta;
  c12_c_b_size[0] = 39;
  c12_c_b_size[1] = 79;
  c12_i_b = c12_c_b_size[0];
  c12_j_b = c12_c_b_size[1];
  for (c12_i136 = 0; c12_i136 < 3081; c12_i136++) {
    chartInstance->c12_b_data[c12_i136] = chartInstance->
      c12_b_inflated_data[c12_i136];
  }

  c12_i137 = c12_c_b_size[0] * c12_c_b_size[1];
  c12_c_b_size[0] = 39;
  c12_c_b_size[1] = 79;
  c12_k_b = c12_c_b_size[0];
  c12_l_b = c12_c_b_size[1];
  for (c12_i138 = 0; c12_i138 < 3081; c12_i138++) {
    chartInstance->c12_b_data[c12_i138] *= c12_j_a;
  }

  for (c12_i139 = 0; c12_i139 < 3081; c12_i139++) {
    chartInstance->c12_hoistedGlobal[c12_i139] = chartInstance->
      c12_mapGridP[c12_i139];
  }

  c12_k_a = c12_alpha;
  for (c12_i140 = 0; c12_i140 < 3081; c12_i140++) {
    chartInstance->c12_hoistedGlobal[c12_i140] *= c12_k_a;
  }

  for (c12_i141 = 0; c12_i141 < 3081; c12_i141++) {
    chartInstance->c12_mapGridP[c12_i141] = chartInstance->
      c12_hoistedGlobal[c12_i141] + chartInstance->c12_b_data[c12_i141];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 78);
  for (c12_i142 = 0; c12_i142 < 3081; c12_i142++) {
    chartInstance->c12_mapGrid[c12_i142] = chartInstance->c12_mapGridP[c12_i142];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 81);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "tic", 0U, 0U);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 82);
  for (c12_i143 = 0; c12_i143 < 3081; c12_i143++) {
    chartInstance->c12_b_mapGrid[c12_i143] = chartInstance->c12_mapGrid[c12_i143];
  }

  c12_grid2list(chartInstance, chartInstance->c12_b_mapGrid,
                chartInstance->c12_dv3);
  for (c12_i144 = 0; c12_i144 < 9243; c12_i144++) {
    chartInstance->c12_mapList[c12_i144] = chartInstance->c12_dv3[c12_i144];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 85);
  c12_i145 = 0;
  for (c12_i146 = 0; c12_i146 < 3; c12_i146++) {
    chartInstance->c12_costsTemp[c12_i145] = c12_dv4[c12_i146];
    c12_i145 += 3084;
  }

  c12_i147 = 0;
  for (c12_i148 = 0; c12_i148 < 2; c12_i148++) {
    chartInstance->c12_costsTemp[c12_i147 + 1] = c12_b_pos[c12_i148];
    c12_i147 += 3084;
  }

  chartInstance->c12_costsTemp[6169] = 0.0;
  c12_i149 = 0;
  for (c12_i150 = 0; c12_i150 < 2; c12_i150++) {
    chartInstance->c12_costsTemp[c12_i149 + 2] = c12_b_goal[c12_i150];
    c12_i149 += 3084;
  }

  chartInstance->c12_costsTemp[6170] = 0.0;
  c12_i151 = 0;
  c12_i152 = 0;
  for (c12_i153 = 0; c12_i153 < 3; c12_i153++) {
    for (c12_i154 = 0; c12_i154 < 3081; c12_i154++) {
      chartInstance->c12_costsTemp[(c12_i154 + c12_i151) + 3] =
        chartInstance->c12_mapList[c12_i154 + c12_i152];
    }

    c12_i151 += 3084;
    c12_i152 += 3081;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 86);
  c12_i155 = 0;
  for (c12_i156 = 0; c12_i156 < 3084; c12_i156++) {
    c12_i158 = 0;
    for (c12_i159 = 0; c12_i159 < 3; c12_i159++) {
      chartInstance->c12_x[c12_i159 + c12_i155] = chartInstance->
        c12_costsTemp[c12_i158 + c12_i156];
      c12_i158 += 3084;
    }

    c12_i155 += 3;
  }

  for (c12_i157 = 0; c12_i157 < 9252; c12_i157++) {
    chartInstance->c12_costs[c12_i157] = chartInstance->c12_x[c12_i157];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 88);
  sf_mex_assign(&c12_time, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "toc",
    1U, 1U, 14, sf_mex_dup(c12_t1)), false);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 89);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "fprintf", 0U, 2U, 14,
                    c12_emlrt_marshallOut(chartInstance, c12_cv6), 14,
                    sf_mex_dup(c12_time));
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 90);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "tic", 0U, 0U);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -90);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c12_t1);
  sf_mex_destroy(&c12_time);
  for (c12_i160 = 0; c12_i160 < 9252; c12_i160++) {
    (*chartInstance->c12_b_costs)[c12_i160] = chartInstance->c12_costs[c12_i160];
  }

  for (c12_i161 = 0; c12_i161 < 3081; c12_i161++) {
    (*chartInstance->c12_c_mapGrid)[c12_i161] = chartInstance->
      c12_mapGrid[c12_i161];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
}

static void initSimStructsc12_anav_real(SFc12_anav_realInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c12_grid2list(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_c_grid[3081], real_T c12_list[9243])
{
  uint32_T c12_debug_family_var_map[9];
  real_T c12_rows;
  real_T c12_columns;
  real_T c12_i;
  real_T c12_r;
  real_T c12_c;
  real_T c12_nargin = 1.0;
  real_T c12_nargout = 1.0;
  int32_T c12_i162;
  int32_T c12_b_r;
  int32_T c12_b_c;
  int32_T c12_b_i;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c12_d_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_rows, 0U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_columns, 1U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_i, 2U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_r, 3U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_c, 4U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 5U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 6U, c12_e_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_c_grid, 7U, c12_g_sf_marshallOut,
    c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_list, 8U, c12_i_sf_marshallOut,
    c12_g_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 2);
  c12_rows = 39.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 3);
  c12_columns = 79.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 4);
  for (c12_i162 = 0; c12_i162 < 9243; c12_i162++) {
    c12_list[c12_i162] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 5);
  c12_i = 1.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 7);
  c12_r = 1.0;
  for (c12_b_r = 0; c12_b_r < 39; c12_b_r++) {
    c12_r = 1.0 + (real_T)c12_b_r;
    CV_SCRIPT_FOR(2, 0, 1);
    _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 8);
    c12_c = 1.0;
    for (c12_b_c = 0; c12_b_c < 79; c12_b_c++) {
      c12_c = 1.0 + (real_T)c12_b_c;
      CV_SCRIPT_FOR(2, 1, 1);
      _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 9);
      c12_b_i = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 0U, 0, 0, MAX_uint32_T, (int32_T)c12_i, 1, 3081) - 1;
      c12_list[c12_b_i] = c12_c;
      c12_list[3081 + c12_b_i] = c12_r;
      c12_list[6162 + c12_b_i] = c12_c_grid[((int32_T)c12_r + 39 * ((int32_T)
        c12_c - 1)) - 1];
      _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, 10);
      c12_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_SCRIPT_FOR(2, 1, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(2, 0, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c12_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)(c12_machineNumber);
  (void)(c12_chartNumber);
  (void)(c12_instanceNumber);
  _SFD_SCRIPT_TRANSLATION(c12_chartNumber, c12_instanceNumber, 0U,
    sf_debug_get_script_id(
    "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/list2grid.m"));
  _SFD_SCRIPT_TRANSLATION(c12_chartNumber, c12_instanceNumber, 1U,
    sf_debug_get_script_id(
    "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m"));
  _SFD_SCRIPT_TRANSLATION(c12_chartNumber, c12_instanceNumber, 2U,
    sf_debug_get_script_id(
    "/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/grid2list.m"));
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  const mxArray *c12_u;
  const mxArray *c12_y = NULL;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = sf_mex_dup(*(const mxArray **)c12_inData);
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_duplicatearraysafe(&c12_u), false);
  sf_mex_destroy(&c12_u);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i163;
  const mxArray *c12_y = NULL;
  real_T c12_u[2];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  for (c12_i163 = 0; c12_i163 < 2; c12_i163++) {
    c12_u[c12_i163] = (*(real_T (*)[2])c12_inData)[c12_i163];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[2])
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_u_size[2];
  int32_T c12_u;
  int32_T c12_b_u;
  int32_T c12_loop_ub;
  int32_T c12_i164;
  const mxArray *c12_y = NULL;
  real_T c12_u_data[2162];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u_size[0] = c12_inData_size[0];
  c12_u_size[1] = c12_inData_size[1];
  c12_u = c12_u_size[0];
  c12_b_u = c12_u_size[1];
  c12_loop_ub = c12_inData_size[0] * c12_inData_size[1] - 1;
  for (c12_i164 = 0; c12_i164 <= c12_loop_ub; c12_i164++) {
    c12_u_data[c12_i164] = c12_inData_data[c12_i164];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", (void *)&c12_u_data, 0, 0U, 1U, 0U, 2,
    c12_u_size[0], c12_u_size[1]), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[2])
{
  int32_T c12_i165;
  int32_T c12_tmp_size[2];
  uint32_T c12_uv0[2];
  int32_T c12_i166;
  real_T c12_d_tmp_data[2162];
  boolean_T c12_bv0[2];
  int32_T c12_y;
  int32_T c12_b_y;
  int32_T c12_loop_ub;
  int32_T c12_i167;
  (void)chartInstance;
  for (c12_i165 = 0; c12_i165 < 2; c12_i165++) {
    c12_uv0[c12_i165] = 1081U + (uint32_T)(-1079 * c12_i165);
  }

  c12_tmp_size[0] = sf_mex_get_dimension(c12_u, 0);
  c12_tmp_size[1] = sf_mex_get_dimension(c12_u, 1);
  for (c12_i166 = 0; c12_i166 < 2; c12_i166++) {
    c12_bv0[c12_i166] = true;
  }

  sf_mex_import_vs(c12_parentId, sf_mex_dup(c12_u), (void *)&c12_d_tmp_data, 1,
                   0, 0U, 1, 0U, 2, c12_bv0, c12_uv0, c12_tmp_size);
  c12_y_size[0] = c12_tmp_size[0];
  c12_y_size[1] = c12_tmp_size[1];
  c12_y = c12_y_size[0];
  c12_b_y = c12_y_size[1];
  c12_loop_ub = c12_tmp_size[0] * c12_tmp_size[1] - 1;
  for (c12_i167 = 0; c12_i167 <= c12_loop_ub; c12_i167++) {
    c12_b_y_data[c12_i167] = c12_d_tmp_data[c12_i167];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[2])
{
  const mxArray *c12_compressed;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y_data[2162];
  int32_T c12_y_size[2];
  int32_T c12_loop_ub;
  int32_T c12_i168;
  int32_T c12_b_loop_ub;
  int32_T c12_i169;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_compressed = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_compressed), &c12_thisId,
                       c12_b_y_data, c12_y_size);
  sf_mex_destroy(&c12_compressed);
  c12_outData_size[0] = c12_y_size[0];
  c12_outData_size[1] = c12_y_size[1];
  c12_loop_ub = c12_y_size[1] - 1;
  for (c12_i168 = 0; c12_i168 <= c12_loop_ub; c12_i168++) {
    c12_b_loop_ub = c12_y_size[0] - 1;
    for (c12_i169 = 0; c12_i169 <= c12_b_loop_ub; c12_i169++) {
      c12_outData_data[c12_i169 + c12_outData_size[0] * c12_i168] =
        c12_b_y_data[c12_i169 + c12_y_size[0] * c12_i168];
    }
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[1])
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_u_size[1];
  int32_T c12_loop_ub;
  int32_T c12_i170;
  const mxArray *c12_y = NULL;
  real_T c12_u_data[1081];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u_size[0] = c12_inData_size[0];
  c12_loop_ub = c12_inData_size[0] - 1;
  for (c12_i170 = 0; c12_i170 <= c12_loop_ub; c12_i170++) {
    c12_u_data[c12_i170] = c12_inData_data[c12_i170];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", (void *)&c12_u_data, 0, 0U, 1U, 0U, 1,
    c12_u_size[0]), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_b_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[1])
{
  uint32_T c12_uv1[1];
  int32_T c12_tmp_size[1];
  boolean_T c12_bv1[1];
  real_T c12_d_tmp_data[1081];
  int32_T c12_loop_ub;
  int32_T c12_i171;
  (void)chartInstance;
  c12_uv1[0] = 1081U;
  c12_tmp_size[0] = sf_mex_get_dimension(c12_u, 0);
  c12_bv1[0] = true;
  sf_mex_import_vs(c12_parentId, sf_mex_dup(c12_u), (void *)&c12_d_tmp_data, 1,
                   0, 0U, 1, 0U, 1, c12_bv1, c12_uv1, c12_tmp_size);
  c12_y_size[0] = c12_tmp_size[0];
  c12_loop_ub = c12_tmp_size[0] - 1;
  for (c12_i171 = 0; c12_i171 <= c12_loop_ub; c12_i171++) {
    c12_b_y_data[c12_i171] = c12_d_tmp_data[c12_i171];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[1])
{
  const mxArray *c12_detX;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y_data[1081];
  int32_T c12_y_size[1];
  int32_T c12_loop_ub;
  int32_T c12_i172;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_detX = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_detX), &c12_thisId,
    c12_b_y_data, c12_y_size);
  sf_mex_destroy(&c12_detX);
  c12_outData_size[0] = c12_y_size[0];
  c12_loop_ub = c12_y_size[0] - 1;
  for (c12_i172 = 0; c12_i172 <= c12_loop_ub; c12_i172++) {
    c12_outData_data[c12_i172] = c12_b_y_data[c12_i172];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static real_T c12_c_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d2;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d2, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d2;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_offset;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_offset = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_offset),
    &c12_thisId);
  sf_mex_destroy(&c12_offset);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[2])
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_u_size[2];
  int32_T c12_u;
  int32_T c12_b_u;
  int32_T c12_loop_ub;
  int32_T c12_i173;
  const mxArray *c12_y = NULL;
  real_T c12_u_data[2634];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u_size[0] = c12_inData_size[0];
  c12_u_size[1] = 2;
  c12_u = c12_u_size[0];
  c12_b_u = c12_u_size[1];
  c12_loop_ub = c12_inData_size[0] * c12_inData_size[1] - 1;
  for (c12_i173 = 0; c12_i173 <= c12_loop_ub; c12_i173++) {
    c12_u_data[c12_i173] = c12_inData_data[c12_i173];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", (void *)&c12_u_data, 0, 0U, 1U, 0U, 2,
    c12_u_size[0], c12_u_size[1]), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_d_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[2])
{
  int32_T c12_i174;
  int32_T c12_tmp_size[2];
  uint32_T c12_uv2[2];
  int32_T c12_i175;
  real_T c12_d_tmp_data[2634];
  boolean_T c12_bv2[2];
  static boolean_T c12_bv3[2] = { true, false };

  int32_T c12_y;
  int32_T c12_b_y;
  int32_T c12_loop_ub;
  int32_T c12_i176;
  (void)chartInstance;
  for (c12_i174 = 0; c12_i174 < 2; c12_i174++) {
    c12_uv2[c12_i174] = 1317U + (uint32_T)(-1315 * c12_i174);
  }

  c12_tmp_size[0] = sf_mex_get_dimension(c12_u, 0);
  c12_tmp_size[1] = sf_mex_get_dimension(c12_u, 1);
  for (c12_i175 = 0; c12_i175 < 2; c12_i175++) {
    c12_bv2[c12_i175] = c12_bv3[c12_i175];
  }

  sf_mex_import_vs(c12_parentId, sf_mex_dup(c12_u), (void *)&c12_d_tmp_data, 1,
                   0, 0U, 1, 0U, 2, c12_bv2, c12_uv2, c12_tmp_size);
  c12_y_size[0] = c12_tmp_size[0];
  c12_y_size[1] = 2;
  c12_y = c12_y_size[0];
  c12_b_y = c12_y_size[1];
  c12_loop_ub = c12_tmp_size[0] * c12_tmp_size[1] - 1;
  for (c12_i176 = 0; c12_i176 <= c12_loop_ub; c12_i176++) {
    c12_b_y_data[c12_i176] = c12_d_tmp_data[c12_i176];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[2])
{
  const mxArray *c12_roundedLimitUnique;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y_data[2634];
  int32_T c12_y_size[2];
  int32_T c12_i177;
  int32_T c12_loop_ub;
  int32_T c12_i178;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_roundedLimitUnique = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_roundedLimitUnique),
    &c12_thisId, c12_b_y_data, c12_y_size);
  sf_mex_destroy(&c12_roundedLimitUnique);
  c12_outData_size[0] = c12_y_size[0];
  c12_outData_size[1] = 2;
  for (c12_i177 = 0; c12_i177 < 2; c12_i177++) {
    c12_loop_ub = c12_y_size[0] - 1;
    for (c12_i178 = 0; c12_i178 <= c12_loop_ub; c12_i178++) {
      c12_outData_data[c12_i178 + c12_outData_size[0] * c12_i177] =
        c12_b_y_data[c12_i178 + c12_y_size[0] * c12_i177];
    }
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i179;
  int32_T c12_i180;
  const mxArray *c12_y = NULL;
  int32_T c12_i181;
  real_T c12_u[3081];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_i179 = 0;
  for (c12_i180 = 0; c12_i180 < 79; c12_i180++) {
    for (c12_i181 = 0; c12_i181 < 39; c12_i181++) {
      c12_u[c12_i181 + c12_i179] = (*(real_T (*)[3081])c12_inData)[c12_i181 +
        c12_i179];
    }

    c12_i179 += 39;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 39, 79),
                false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_e_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_b_limitGrid, const char_T *c12_identifier, real_T c12_y
  [3081])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_limitGrid), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_b_limitGrid);
}

static void c12_f_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [3081])
{
  real_T c12_dv5[3081];
  int32_T c12_i182;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv5, 1, 0, 0U, 1, 0U, 2, 39,
                79);
  for (c12_i182 = 0; c12_i182 < 3081; c12_i182++) {
    c12_y[c12_i182] = c12_dv5[c12_i182];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_limitGrid;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[3081];
  int32_T c12_i183;
  int32_T c12_i184;
  int32_T c12_i185;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_b_limitGrid = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_limitGrid), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_b_limitGrid);
  c12_i183 = 0;
  for (c12_i184 = 0; c12_i184 < 79; c12_i184++) {
    for (c12_i185 = 0; c12_i185 < 39; c12_i185++) {
      (*(real_T (*)[3081])c12_outData)[c12_i185 + c12_i183] = c12_y[c12_i185 +
        c12_i183];
    }

    c12_i183 += 39;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[2])
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_u_size[2];
  int32_T c12_u;
  int32_T c12_b_u;
  int32_T c12_i186;
  const mxArray *c12_y = NULL;
  real_T c12_u_data[3081];
  SFc12_anav_realInstanceStruct *chartInstance;
  (void)c12_inData_size;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u_size[0] = 39;
  c12_u_size[1] = 79;
  c12_u = c12_u_size[0];
  c12_b_u = c12_u_size[1];
  for (c12_i186 = 0; c12_i186 < 3081; c12_i186++) {
    c12_u_data[c12_i186] = c12_inData_data[c12_i186];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", (void *)&c12_u_data, 0, 0U, 1U, 0U, 2,
    c12_u_size[0], c12_u_size[1]), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_g_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[2])
{
  int32_T c12_i187;
  int32_T c12_tmp_size[2];
  uint32_T c12_uv3[2];
  int32_T c12_i188;
  real_T c12_d_tmp_data[3081];
  boolean_T c12_bv4[2];
  int32_T c12_y;
  int32_T c12_b_y;
  int32_T c12_i189;
  (void)chartInstance;
  for (c12_i187 = 0; c12_i187 < 2; c12_i187++) {
    c12_uv3[c12_i187] = 39U + 40U * (uint32_T)c12_i187;
  }

  c12_tmp_size[0] = sf_mex_get_dimension(c12_u, 0);
  c12_tmp_size[1] = sf_mex_get_dimension(c12_u, 1);
  for (c12_i188 = 0; c12_i188 < 2; c12_i188++) {
    c12_bv4[c12_i188] = false;
  }

  sf_mex_import_vs(c12_parentId, sf_mex_dup(c12_u), (void *)&c12_d_tmp_data, 1,
                   0, 0U, 1, 0U, 2, c12_bv4, c12_uv3, c12_tmp_size);
  c12_y_size[0] = 39;
  c12_y_size[1] = 79;
  c12_y = c12_y_size[0];
  c12_b_y = c12_y_size[1];
  for (c12_i189 = 0; c12_i189 < 3081; c12_i189++) {
    c12_b_y_data[c12_i189] = c12_d_tmp_data[c12_i189];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[2])
{
  const mxArray *c12_inflated;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y_data[3081];
  int32_T c12_y_size[2];
  int32_T c12_i190;
  int32_T c12_i191;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_inflated = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_inflated), &c12_thisId,
    c12_b_y_data, c12_y_size);
  sf_mex_destroy(&c12_inflated);
  c12_outData_size[0] = 39;
  c12_outData_size[1] = 79;
  for (c12_i190 = 0; c12_i190 < 79; c12_i190++) {
    for (c12_i191 = 0; c12_i191 < 39; c12_i191++) {
      c12_outData_data[c12_i191 + c12_outData_size[0] * c12_i190] =
        c12_b_y_data[c12_i191 + c12_y_size[0] * c12_i190];
    }
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_i_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i192;
  int32_T c12_i193;
  const mxArray *c12_y = NULL;
  int32_T c12_i194;
  real_T c12_u[9243];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_i192 = 0;
  for (c12_i193 = 0; c12_i193 < 3; c12_i193++) {
    for (c12_i194 = 0; c12_i194 < 3081; c12_i194++) {
      c12_u[c12_i194 + c12_i192] = (*(real_T (*)[9243])c12_inData)[c12_i194 +
        c12_i192];
    }

    c12_i192 += 3081;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3081, 3),
                false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_h_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [9243])
{
  real_T c12_dv6[9243];
  int32_T c12_i195;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv6, 1, 0, 0U, 1, 0U, 2,
                3081, 3);
  for (c12_i195 = 0; c12_i195 < 9243; c12_i195++) {
    c12_y[c12_i195] = c12_dv6[c12_i195];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_mapList;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[9243];
  int32_T c12_i196;
  int32_T c12_i197;
  int32_T c12_i198;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_b_mapList = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_mapList), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_b_mapList);
  c12_i196 = 0;
  for (c12_i197 = 0; c12_i197 < 3; c12_i197++) {
    for (c12_i198 = 0; c12_i198 < 3081; c12_i198++) {
      (*(real_T (*)[9243])c12_outData)[c12_i198 + c12_i196] = c12_y[c12_i198 +
        c12_i196];
    }

    c12_i196 += 3081;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_j_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i199;
  int32_T c12_i200;
  const mxArray *c12_y = NULL;
  int32_T c12_i201;
  real_T c12_u[9252];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_i199 = 0;
  for (c12_i200 = 0; c12_i200 < 3; c12_i200++) {
    for (c12_i201 = 0; c12_i201 < 3084; c12_i201++) {
      c12_u[c12_i201 + c12_i199] = (*(real_T (*)[9252])c12_inData)[c12_i201 +
        c12_i199];
    }

    c12_i199 += 3084;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3084, 3),
                false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_i_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [9252])
{
  real_T c12_dv7[9252];
  int32_T c12_i202;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv7, 1, 0, 0U, 1, 0U, 2,
                3084, 3);
  for (c12_i202 = 0; c12_i202 < 9252; c12_i202++) {
    c12_y[c12_i202] = c12_dv7[c12_i202];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_costsTemp;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[9252];
  int32_T c12_i203;
  int32_T c12_i204;
  int32_T c12_i205;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_b_costsTemp = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_costsTemp), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_b_costsTemp);
  c12_i203 = 0;
  for (c12_i204 = 0; c12_i204 < 3; c12_i204++) {
    for (c12_i205 = 0; c12_i205 < 3084; c12_i205++) {
      (*(real_T (*)[9252])c12_outData)[c12_i205 + c12_i203] = c12_y[c12_i205 +
        c12_i203];
    }

    c12_i203 += 3084;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_k_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i206;
  int32_T c12_i207;
  const mxArray *c12_y = NULL;
  int32_T c12_i208;
  real_T c12_u[2162];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_i206 = 0;
  for (c12_i207 = 0; c12_i207 < 2; c12_i207++) {
    for (c12_i208 = 0; c12_i208 < 1081; c12_i208++) {
      c12_u[c12_i208 + c12_i206] = (*(real_T (*)[2162])c12_inData)[c12_i208 +
        c12_i206];
    }

    c12_i206 += 1081;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 1081, 2),
                false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_l_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i209;
  int32_T c12_i210;
  const mxArray *c12_y = NULL;
  int32_T c12_i211;
  real_T c12_u[708];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_i209 = 0;
  for (c12_i210 = 0; c12_i210 < 3; c12_i210++) {
    for (c12_i211 = 0; c12_i211 < 236; c12_i211++) {
      c12_u[c12_i211 + c12_i209] = (*(real_T (*)[708])c12_inData)[c12_i211 +
        c12_i209];
    }

    c12_i209 += 236;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 236, 3),
                false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_m_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i212;
  const mxArray *c12_y = NULL;
  real_T c12_u[9252];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  for (c12_i212 = 0; c12_i212 < 9252; c12_i212++) {
    c12_u[c12_i212] = (*(real_T (*)[9252])c12_inData)[c12_i212];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 1, 9252),
                false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_j_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_c_costs, const char_T *c12_identifier, real_T c12_y[9252])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_c_costs), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_c_costs);
}

static void c12_k_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y
  [9252])
{
  real_T c12_dv8[9252];
  int32_T c12_i213;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv8, 1, 0, 0U, 1, 0U, 2, 1,
                9252);
  for (c12_i213 = 0; c12_i213 < 9252; c12_i213++) {
    c12_y[c12_i213] = c12_dv8[c12_i213];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_c_costs;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[9252];
  int32_T c12_i214;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_c_costs = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_c_costs), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_c_costs);
  for (c12_i214 = 0; c12_i214 < 9252; c12_i214++) {
    (*(real_T (*)[9252])c12_outData)[c12_i214] = c12_y[c12_i214];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_n_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_i215;
  int32_T c12_i216;
  const mxArray *c12_y = NULL;
  int32_T c12_i217;
  real_T c12_u[3081];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_i215 = 0;
  for (c12_i216 = 0; c12_i216 < 79; c12_i216++) {
    for (c12_i217 = 0; c12_i217 < 39; c12_i217++) {
      c12_u[c12_i217 + c12_i215] = (*(real_T (*)[3081])c12_inData)[c12_i217 +
        c12_i215];
    }

    c12_i215 += 39;
  }

  c12_y = NULL;
  if (!chartInstance->c12_mapGridP_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 39, 79),
                  false);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_l_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_b_mapGridP, const char_T *c12_identifier, boolean_T
  *c12_svPtr, real_T c12_y[3081])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_mapGridP), &c12_thisId,
    c12_svPtr, c12_y);
  sf_mex_destroy(&c12_b_mapGridP);
}

static void c12_m_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, boolean_T
  *c12_svPtr, real_T c12_y[3081])
{
  real_T c12_dv9[3081];
  int32_T c12_i218;
  (void)chartInstance;
  if (mxIsEmpty(c12_u)) {
    *c12_svPtr = false;
  } else {
    *c12_svPtr = true;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv9, 1, 0, 0U, 1, 0U, 2,
                  39, 79);
    for (c12_i218 = 0; c12_i218 < 3081; c12_i218++) {
      c12_y[c12_i218] = c12_dv9[c12_i218];
    }
  }

  sf_mex_destroy(&c12_u);
}

static void c12_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_mapGridP;
  const char_T *c12_identifier;
  boolean_T *c12_svPtr;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[3081];
  int32_T c12_i219;
  int32_T c12_i220;
  int32_T c12_i221;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_b_mapGridP = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_svPtr = &chartInstance->c12_mapGridP_not_empty;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_mapGridP), &c12_thisId,
    c12_svPtr, c12_y);
  sf_mex_destroy(&c12_b_mapGridP);
  c12_i219 = 0;
  for (c12_i220 = 0; c12_i220 < 79; c12_i220++) {
    for (c12_i221 = 0; c12_i221 < 39; c12_i221++) {
      (*(real_T (*)[3081])c12_outData)[c12_i221 + c12_i219] = c12_y[c12_i221 +
        c12_i219];
    }

    c12_i219 += 39;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_o_sf_marshallOut(void *chartInstanceVoid, real_T
  c12_inData_data[], int32_T c12_inData_size[1])
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_u_size[1];
  int32_T c12_loop_ub;
  int32_T c12_i222;
  const mxArray *c12_y = NULL;
  real_T c12_u_data[1317];
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u_size[0] = c12_inData_size[0];
  c12_loop_ub = c12_inData_size[0] - 1;
  for (c12_i222 = 0; c12_i222 <= c12_loop_ub; c12_i222++) {
    c12_u_data[c12_i222] = c12_inData_data[c12_i222];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", (void *)&c12_u_data, 0, 0U, 1U, 0U, 1,
    c12_u_size[0]), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_n_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T
  c12_b_y_data[], int32_T c12_y_size[1])
{
  uint32_T c12_uv4[1];
  int32_T c12_tmp_size[1];
  boolean_T c12_bv5[1];
  real_T c12_d_tmp_data[1317];
  int32_T c12_loop_ub;
  int32_T c12_i223;
  (void)chartInstance;
  c12_uv4[0] = 1317U;
  c12_tmp_size[0] = sf_mex_get_dimension(c12_u, 0);
  c12_bv5[0] = true;
  sf_mex_import_vs(c12_parentId, sf_mex_dup(c12_u), (void *)&c12_d_tmp_data, 1,
                   0, 0U, 1, 0U, 1, c12_bv5, c12_uv4, c12_tmp_size);
  c12_y_size[0] = c12_tmp_size[0];
  c12_loop_ub = c12_tmp_size[0] - 1;
  for (c12_i223 = 0; c12_i223 <= c12_loop_ub; c12_i223++) {
    c12_b_y_data[c12_i223] = c12_d_tmp_data[c12_i223];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, real_T c12_outData_data[],
  int32_T c12_outData_size[1])
{
  const mxArray *c12_b_x;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y_data[1317];
  int32_T c12_y_size[1];
  int32_T c12_loop_ub;
  int32_T c12_i224;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_b_x = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_x), &c12_thisId,
    c12_b_y_data, c12_y_size);
  sf_mex_destroy(&c12_b_x);
  c12_outData_size[0] = c12_y_size[0];
  c12_loop_ub = c12_y_size[0] - 1;
  for (c12_i224 = 0; c12_i224 <= c12_loop_ub; c12_i224++) {
    c12_outData_data[c12_i224] = c12_b_y_data[c12_i224];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_p_sf_marshallOut(void *chartInstanceVoid, creal_T
  c12_inData_data[], int32_T c12_inData_size[2])
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_u_size[2];
  int32_T c12_u;
  int32_T c12_b_u;
  int32_T c12_i225;
  const mxArray *c12_y = NULL;
  creal_T c12_u_data[3081];
  SFc12_anav_realInstanceStruct *chartInstance;
  (void)c12_inData_size;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u_size[0] = 39;
  c12_u_size[1] = 79;
  c12_u = c12_u_size[0];
  c12_b_u = c12_u_size[1];
  for (c12_i225 = 0; c12_i225 < 3081; c12_i225++) {
    c12_u_data[c12_i225] = c12_inData_data[c12_i225];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", (void *)&c12_u_data, 0, 1U, 1U, 0U, 2,
    c12_u_size[0], c12_u_size[1]), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_o_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, creal_T
  c12_b_y_data[], int32_T c12_y_size[2])
{
  int32_T c12_i226;
  int32_T c12_tmp_size[2];
  uint32_T c12_uv5[2];
  int32_T c12_i227;
  creal_T c12_d_tmp_data[3081];
  boolean_T c12_bv6[2];
  int32_T c12_y;
  int32_T c12_b_y;
  int32_T c12_i228;
  (void)chartInstance;
  for (c12_i226 = 0; c12_i226 < 2; c12_i226++) {
    c12_uv5[c12_i226] = 39U + 40U * (uint32_T)c12_i226;
  }

  c12_tmp_size[0] = sf_mex_get_dimension(c12_u, 0);
  c12_tmp_size[1] = sf_mex_get_dimension(c12_u, 1);
  for (c12_i227 = 0; c12_i227 < 2; c12_i227++) {
    c12_bv6[c12_i227] = false;
  }

  sf_mex_import_vs(c12_parentId, sf_mex_dup(c12_u), (void *)&c12_d_tmp_data, 1,
                   0, 1U, 1, 0U, 2, c12_bv6, c12_uv5, c12_tmp_size);
  c12_y_size[0] = 39;
  c12_y_size[1] = 79;
  c12_y = c12_y_size[0];
  c12_b_y = c12_y_size[1];
  for (c12_i228 = 0; c12_i228 < 3081; c12_i228++) {
    c12_b_y_data[c12_i228] = c12_d_tmp_data[c12_i228];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, creal_T c12_outData_data[],
  int32_T c12_outData_size[2])
{
  const mxArray *c12_inflated;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  creal_T c12_b_y_data[3081];
  int32_T c12_y_size[2];
  int32_T c12_i229;
  int32_T c12_i230;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_inflated = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_inflated), &c12_thisId,
    c12_b_y_data, c12_y_size);
  sf_mex_destroy(&c12_inflated);
  c12_outData_size[0] = 39;
  c12_outData_size[1] = 79;
  for (c12_i229 = 0; c12_i229 < 79; c12_i229++) {
    for (c12_i230 = 0; c12_i230 < 39; c12_i230++) {
      c12_outData_data[c12_i230 + c12_outData_size[0] * c12_i229] =
        c12_b_y_data[c12_i230 + c12_y_size[0] * c12_i229];
    }
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_q_sf_marshallOut(void *chartInstanceVoid,
  c12_emxArray_creal_T *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  c12_emxArray_creal_T *c12_u;
  int32_T c12_i231;
  int32_T c12_b_u;
  int32_T c12_c_u;
  int32_T c12_loop_ub;
  int32_T c12_i232;
  const mxArray *c12_y = NULL;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_emxInit_creal_T(chartInstance, &c12_u, 2, (emlrtRTEInfo *)NULL);
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_i231 = c12_u->size[0] * c12_u->size[1];
  c12_u->size[0] = c12_inData->size[0];
  c12_u->size[1] = c12_inData->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_u, c12_i231, (emlrtRTEInfo *)
    NULL);
  c12_b_u = c12_u->size[0];
  c12_c_u = c12_u->size[1];
  c12_loop_ub = c12_inData->size[0] * c12_inData->size[1] - 1;
  for (c12_i232 = 0; c12_i232 <= c12_loop_ub; c12_i232++) {
    c12_u->data[c12_i232] = c12_inData->data[c12_i232];
  }

  c12_y = NULL;
  if (!chartInstance->c12_h_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", c12_u->data, 0, 1U, 1U, 0U, 2,
      c12_u->size[0], c12_u->size[1]), false);
  }

  c12_emxFree_creal_T(chartInstance, &c12_u);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_p_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_b_h, const char_T *c12_identifier, boolean_T *c12_svPtr,
  c12_emxArray_creal_T *c12_y)
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_h), &c12_thisId,
    c12_svPtr, c12_y);
  sf_mex_destroy(&c12_b_h);
}

static void c12_q_emlrt_marshallIn(SFc12_anav_realInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, boolean_T
  *c12_svPtr, c12_emxArray_creal_T *c12_y)
{
  c12_emxArray_creal_T *c12_r5;
  int32_T c12_i233;
  uint32_T c12_uv6[2];
  int32_T c12_i234;
  int32_T c12_i235;
  boolean_T c12_bv7[2];
  int32_T c12_i236;
  int32_T c12_b_y;
  int32_T c12_c_y;
  int32_T c12_loop_ub;
  int32_T c12_i237;
  c12_emxInit_creal_T(chartInstance, &c12_r5, 2, (emlrtRTEInfo *)NULL);
  for (c12_i233 = 0; c12_i233 < 2; c12_i233++) {
    c12_uv6[c12_i233] = MAX_uint32_T;
  }

  if (mxIsEmpty(c12_u)) {
    *c12_svPtr = false;
  } else {
    *c12_svPtr = true;
    c12_i234 = c12_r5->size[0] * c12_r5->size[1];
    c12_r5->size[0] = sf_mex_get_dimension(c12_u, 0);
    c12_r5->size[1] = sf_mex_get_dimension(c12_u, 1);
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_r5, c12_i234, (emlrtRTEInfo
      *)NULL);
    for (c12_i235 = 0; c12_i235 < 2; c12_i235++) {
      c12_bv7[c12_i235] = true;
    }

    sf_mex_import_vs(c12_parentId, sf_mex_dup(c12_u), c12_r5->data, 1, 0, 1U, 1,
                     0U, 2, c12_bv7, c12_uv6, c12_r5->size);
    c12_i236 = c12_y->size[0] * c12_y->size[1];
    c12_y->size[0] = c12_r5->size[0];
    c12_y->size[1] = c12_r5->size[1];
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_y, c12_i236, (emlrtRTEInfo *)
      NULL);
    c12_b_y = c12_y->size[0];
    c12_c_y = c12_y->size[1];
    c12_loop_ub = c12_r5->size[0] * c12_r5->size[1] - 1;
    for (c12_i237 = 0; c12_i237 <= c12_loop_ub; c12_i237++) {
      c12_y->data[c12_i237] = c12_r5->data[c12_i237];
    }
  }

  sf_mex_destroy(&c12_u);
  c12_emxFree_creal_T(chartInstance, &c12_r5);
}

static void c12_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, c12_emxArray_creal_T
  *c12_outData)
{
  c12_emxArray_creal_T *c12_y;
  const mxArray *c12_b_h;
  const char_T *c12_identifier;
  boolean_T *c12_svPtr;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_i238;
  int32_T c12_loop_ub;
  int32_T c12_i239;
  int32_T c12_b_loop_ub;
  int32_T c12_i240;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_emxInit_creal_T(chartInstance, &c12_y, 2, (emlrtRTEInfo *)NULL);
  c12_b_h = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_svPtr = &chartInstance->c12_h_not_empty;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_h), &c12_thisId,
    c12_svPtr, c12_y);
  sf_mex_destroy(&c12_b_h);
  c12_i238 = c12_outData->size[0] * c12_outData->size[1];
  c12_outData->size[0] = c12_y->size[0];
  c12_outData->size[1] = c12_y->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_outData, c12_i238,
    (emlrtRTEInfo *)NULL);
  c12_loop_ub = c12_y->size[1] - 1;
  for (c12_i239 = 0; c12_i239 <= c12_loop_ub; c12_i239++) {
    c12_b_loop_ub = c12_y->size[0] - 1;
    for (c12_i240 = 0; c12_i240 <= c12_b_loop_ub; c12_i240++) {
      c12_outData->data[c12_i240 + c12_outData->size[0] * c12_i239] =
        c12_y->data[c12_i240 + c12_y->size[0] * c12_i239];
    }
  }

  c12_emxFree_creal_T(chartInstance, &c12_y);
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_anav_real_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  const char * c12_data[6] = {
    "789ced56cb4edb40141d178a6051946efa035d8383112dec929294462def20405555ecf83a1e320fb0c7116653a4aa7fd10fe992bfe8b6ffd14d6de24732d2c8"
    "9540a6ae7225cff8e878ee99b91a1f5da475b63584d062f4b4bf20f4eb39ba8b67a309d592f9099a0c99d7927946c2693c45b313ebb444ef7b827b9c09b81223",
    "4030839d805ae045809914b23436a798994c74c30b401ef89c0cc1be631c4ca08b297ce063e01d8e007d3b466520a6e2f74d177a83c38022cff5f3ed92718092"
    "fac471a638ff6c417de490eb237f57a43757a0a729e63416d07c0e6e761ba9de85225fd1f9d2fc0b0abd9ac413ec0ba3ef613bc1f7ad6faa3727e15c7fc4d83c",
    "b008e47a3feea977a2d49be43fb63fe92ea7a0bb26d15bbc175060c2d74d5f785c6fc6a3c505eef9cd4070c66968d457d697a26143f7310da21f62a09bcc1c7e"
    "f6205a9f156f9996774f6ebffe7ef9b359eabd4425ff078fa877a5c8f7b7f7f08542af26f1979dc38e07dbe29cb0f69ac5dcf0744f18ad7c1f7b053a45fb400a",
    "5c56fe33c5fa4afb7363bff150fe382f61947d376230738829c0a8aa1f1f2bf526f907f5e3b468cbb4c47b71fb6d7d69eac755f7e3c1eeeb70bf75b06138966b"
    "77ebe41abcfee9e6d48fe5f8a7fcf8a65b7abf1c777b46dcf725b8aafefc28fd7256bc69bffcbfe895e5cf70696f9df78fea6f561deabc0aede14960bedfaabe",
    "3fff0127e1e07f", "" };

  c12_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c12_data, 4600U, &c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static void c12_pol2cart(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_th_data[], int32_T c12_th_size[1], real_T c12_r_data[], int32_T
  c12_r_size[1], real_T c12_x_data[], int32_T c12_x_size[1], real_T
  c12_b_y_data[], int32_T c12_y_size[1])
{
  int32_T c12_loop_ub;
  int32_T c12_i241;
  int32_T c12_b_loop_ub;
  int32_T c12_i242;
  int32_T c12_c_loop_ub;
  int32_T c12_i243;
  int32_T c12_d_loop_ub;
  int32_T c12_i244;
  c12_x_size[0] = c12_th_size[0];
  c12_loop_ub = c12_th_size[0] - 1;
  for (c12_i241 = 0; c12_i241 <= c12_loop_ub; c12_i241++) {
    c12_x_data[c12_i241] = c12_th_data[c12_i241];
  }

  c12_b_cos(chartInstance, c12_x_data, c12_x_size);
  c12_x_size[0] = c12_r_size[0];
  c12_b_loop_ub = c12_r_size[0] - 1;
  for (c12_i242 = 0; c12_i242 <= c12_b_loop_ub; c12_i242++) {
    c12_x_data[c12_i242] *= c12_r_data[c12_i242];
  }

  c12_y_size[0] = c12_th_size[0];
  c12_c_loop_ub = c12_th_size[0] - 1;
  for (c12_i243 = 0; c12_i243 <= c12_c_loop_ub; c12_i243++) {
    c12_b_y_data[c12_i243] = c12_th_data[c12_i243];
  }

  c12_c_sin(chartInstance, c12_b_y_data, c12_y_size);
  c12_y_size[0] = c12_r_size[0];
  c12_d_loop_ub = c12_r_size[0] - 1;
  for (c12_i244 = 0; c12_i244 <= c12_d_loop_ub; c12_i244++) {
    c12_b_y_data[c12_i244] *= c12_r_data[c12_i244];
  }
}

static void c12_cos(SFc12_anav_realInstanceStruct *chartInstance, real_T
                    c12_x_data[], int32_T c12_x_size[1], real_T c12_b_x_data[],
                    int32_T c12_b_x_size[1])
{
  int32_T c12_loop_ub;
  int32_T c12_i245;
  c12_b_x_size[0] = c12_x_size[0];
  c12_loop_ub = c12_x_size[0] - 1;
  for (c12_i245 = 0; c12_i245 <= c12_loop_ub; c12_i245++) {
    c12_b_x_data[c12_i245] = c12_x_data[c12_i245];
  }

  c12_b_cos(chartInstance, c12_b_x_data, c12_b_x_size);
}

static void c12_check_forloop_overflow_error(SFc12_anav_realInstanceStruct
  *chartInstance, boolean_T c12_overflow)
{
  const mxArray *c12_y = NULL;
  static char_T c12_cv7[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c12_b_y = NULL;
  const mxArray *c12_c_y = NULL;
  static char_T c12_cv8[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c12_overflow;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv7, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv7, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv8, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 2U,
    14, c12_b_y, 14, c12_c_y)));
}

static void c12_sin(SFc12_anav_realInstanceStruct *chartInstance, real_T
                    c12_x_data[], int32_T c12_x_size[1], real_T c12_b_x_data[],
                    int32_T c12_b_x_size[1])
{
  int32_T c12_loop_ub;
  int32_T c12_i246;
  c12_b_x_size[0] = c12_x_size[0];
  c12_loop_ub = c12_x_size[0] - 1;
  for (c12_i246 = 0; c12_i246 <= c12_loop_ub; c12_i246++) {
    c12_b_x_data[c12_i246] = c12_x_data[c12_i246];
  }

  c12_c_sin(chartInstance, c12_b_x_data, c12_b_x_size);
}

static void c12_round(SFc12_anav_realInstanceStruct *chartInstance, real_T
                      c12_x_data[], int32_T c12_x_size[2], real_T c12_b_x_data[],
                      int32_T c12_b_x_size[2])
{
  int32_T c12_b_x;
  int32_T c12_c_x;
  int32_T c12_loop_ub;
  int32_T c12_i247;
  c12_b_x_size[0] = c12_x_size[0];
  c12_b_x_size[1] = c12_x_size[1];
  c12_b_x = c12_b_x_size[0];
  c12_c_x = c12_b_x_size[1];
  c12_loop_ub = c12_x_size[0] * c12_x_size[1] - 1;
  for (c12_i247 = 0; c12_i247 <= c12_loop_ub; c12_i247++) {
    c12_b_x_data[c12_i247] = c12_x_data[c12_i247];
  }

  c12_b_round(chartInstance, c12_b_x_data, c12_b_x_size);
}

static void c12_sortrows(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_b_y_data[], int32_T c12_y_size[2], real_T c12_c_y_data[], int32_T
  c12_b_y_size[2], real_T c12_ndx_data[], int32_T c12_ndx_size[1])
{
  int32_T c12_y;
  int32_T c12_b_y;
  int32_T c12_loop_ub;
  int32_T c12_i248;
  c12_b_y_size[0] = c12_y_size[0];
  c12_b_y_size[1] = c12_y_size[1];
  c12_y = c12_b_y_size[0];
  c12_b_y = c12_b_y_size[1];
  c12_loop_ub = c12_y_size[0] * c12_y_size[1] - 1;
  for (c12_i248 = 0; c12_i248 <= c12_loop_ub; c12_i248++) {
    c12_c_y_data[c12_i248] = c12_b_y_data[c12_i248];
  }

  c12_b_sortrows(chartInstance, c12_c_y_data, c12_b_y_size, c12_ndx_data,
                 c12_ndx_size);
}

static void c12_sortIdx(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_x_data[], int32_T c12_x_size[2], int32_T c12_col_data[], int32_T
  c12_col_size[2], int32_T c12_idx_data[], int32_T c12_idx_size[1])
{
  int32_T c12_n;
  int32_T c12_loop_ub;
  int32_T c12_i249;
  int32_T c12_b_x_size[2];
  int32_T c12_b_x;
  int32_T c12_c_x;
  int32_T c12_b_loop_ub;
  int32_T c12_i250;
  int32_T c12_b_col_size[2];
  real_T c12_b_x_data[2162];
  int32_T c12_col;
  int32_T c12_b_col;
  int32_T c12_c_loop_ub;
  int32_T c12_i251;
  int32_T c12_b_col_data[2];
  c12_n = c12_x_size[0];
  c12_idx_size[0] = c12_x_size[0];
  c12_loop_ub = c12_x_size[0] - 1;
  for (c12_i249 = 0; c12_i249 <= c12_loop_ub; c12_i249++) {
    c12_idx_data[c12_i249] = 0;
  }

  c12_b_x_size[0] = c12_x_size[0];
  c12_b_x_size[1] = c12_x_size[1];
  c12_b_x = c12_b_x_size[0];
  c12_c_x = c12_b_x_size[1];
  c12_b_loop_ub = c12_x_size[0] * c12_x_size[1] - 1;
  for (c12_i250 = 0; c12_i250 <= c12_b_loop_ub; c12_i250++) {
    c12_b_x_data[c12_i250] = c12_x_data[c12_i250];
  }

  c12_b_col_size[0] = 1;
  c12_b_col_size[1] = c12_col_size[1];
  c12_col = c12_b_col_size[0];
  c12_b_col = c12_b_col_size[1];
  c12_c_loop_ub = c12_col_size[0] * c12_col_size[1] - 1;
  for (c12_i251 = 0; c12_i251 <= c12_c_loop_ub; c12_i251++) {
    c12_b_col_data[c12_i251] = c12_col_data[c12_i251];
  }

  c12_b_mergesort(chartInstance, c12_idx_data, c12_idx_size, c12_b_x_data,
                  c12_b_x_size, c12_b_col_data, c12_b_col_size, c12_n);
}

static void c12_mergesort(SFc12_anav_realInstanceStruct *chartInstance, int32_T
  c12_idx_data[], int32_T c12_idx_size[1], real_T c12_x_data[], int32_T
  c12_x_size[2], int32_T c12_dir_data[], int32_T c12_dir_size[2], int32_T c12_n,
  int32_T c12_b_idx_data[], int32_T c12_b_idx_size[1])
{
  int32_T c12_loop_ub;
  int32_T c12_i252;
  int32_T c12_b_x_size[2];
  int32_T c12_b_x;
  int32_T c12_c_x;
  int32_T c12_b_loop_ub;
  int32_T c12_i253;
  int32_T c12_b_dir_size[2];
  real_T c12_b_x_data[2162];
  int32_T c12_dir;
  int32_T c12_b_dir;
  int32_T c12_c_loop_ub;
  int32_T c12_i254;
  int32_T c12_b_dir_data[2];
  c12_b_idx_size[0] = c12_idx_size[0];
  c12_loop_ub = c12_idx_size[0] - 1;
  for (c12_i252 = 0; c12_i252 <= c12_loop_ub; c12_i252++) {
    c12_b_idx_data[c12_i252] = c12_idx_data[c12_i252];
  }

  c12_b_x_size[0] = c12_x_size[0];
  c12_b_x_size[1] = c12_x_size[1];
  c12_b_x = c12_b_x_size[0];
  c12_c_x = c12_b_x_size[1];
  c12_b_loop_ub = c12_x_size[0] * c12_x_size[1] - 1;
  for (c12_i253 = 0; c12_i253 <= c12_b_loop_ub; c12_i253++) {
    c12_b_x_data[c12_i253] = c12_x_data[c12_i253];
  }

  c12_b_dir_size[0] = 1;
  c12_b_dir_size[1] = c12_dir_size[1];
  c12_dir = c12_b_dir_size[0];
  c12_b_dir = c12_b_dir_size[1];
  c12_c_loop_ub = c12_dir_size[0] * c12_dir_size[1] - 1;
  for (c12_i254 = 0; c12_i254 <= c12_c_loop_ub; c12_i254++) {
    c12_b_dir_data[c12_i254] = c12_dir_data[c12_i254];
  }

  c12_b_mergesort(chartInstance, c12_b_idx_data, c12_b_idx_size, c12_b_x_data,
                  c12_b_x_size, c12_b_dir_data, c12_b_dir_size, c12_n);
}

static boolean_T c12_sortLE(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_v_data[], int32_T c12_v_size[2], int32_T c12_dir_data[], int32_T
  c12_dir_size[2], int32_T c12_idx1, int32_T c12_idx2)
{
  boolean_T c12_p;
  int32_T c12_irow1;
  int32_T c12_irow2;
  int32_T c12_ncols;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  int32_T c12_colk;
  int32_T c12_b_x;
  int32_T c12_c_x;
  int32_T c12_d_x;
  int32_T c12_abscolk;
  real_T c12_v1;
  real_T c12_v2;
  boolean_T c12_v1eqv2;
  real_T c12_e_x;
  boolean_T c12_c_b;
  boolean_T c12_b8;
  real_T c12_f_x;
  boolean_T c12_d_b;
  real_T c12_a;
  real_T c12_e_b;
  real_T c12_b_a;
  real_T c12_f_b;
  real_T c12_c_a;
  real_T c12_g_b;
  boolean_T c12_b_p;
  real_T c12_g_x;
  boolean_T c12_h_b;
  boolean_T c12_c_p;
  boolean_T exitg1;
  c12_irow1 = c12_idx1 - 1;
  c12_irow2 = c12_idx2 - 1;
  c12_p = true;
  c12_ncols = c12_dir_size[1];
  c12_b = c12_ncols;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  c12_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c12_k + 1 <= c12_ncols)) {
    c12_colk = c12_dir_data[c12_k];
    c12_b_x = c12_colk;
    c12_c_x = c12_b_x;
    c12_d_x = c12_c_x;
    c12_abscolk = c12_d_x - 1;
    c12_v1 = c12_v_data[c12_irow1 + c12_v_size[0] * c12_abscolk];
    c12_v2 = c12_v_data[c12_irow2 + c12_v_size[0] * c12_abscolk];
    c12_v1eqv2 = (c12_v1 == c12_v2);
    if (c12_v1eqv2) {
      c12_b8 = true;
    } else {
      c12_e_x = c12_v1;
      c12_c_b = muDoubleScalarIsNaN(c12_e_x);
      if (c12_c_b) {
        c12_f_x = c12_v2;
        c12_d_b = muDoubleScalarIsNaN(c12_f_x);
        if (c12_d_b) {
          c12_b8 = true;
        } else {
          c12_b8 = false;
        }
      } else {
        c12_b8 = false;
      }
    }

    if (!c12_b8) {
      c12_a = c12_v1;
      c12_e_b = c12_v2;
      c12_b_a = c12_a;
      c12_f_b = c12_e_b;
      c12_c_a = c12_b_a;
      c12_g_b = c12_f_b;
      c12_b_p = (c12_c_a <= c12_g_b);
      if (c12_b_p) {
        c12_c_p = true;
      } else {
        c12_g_x = c12_f_b;
        c12_h_b = muDoubleScalarIsNaN(c12_g_x);
        if (c12_h_b) {
          c12_c_p = true;
        } else {
          c12_c_p = false;
        }
      }

      c12_p = c12_c_p;
      exitg1 = true;
    } else {
      c12_k++;
    }
  }

  return c12_p;
}

static void c12_apply_row_permutation(SFc12_anav_realInstanceStruct
  *chartInstance, real_T c12_b_y_data[], int32_T c12_y_size[2], int32_T
  c12_idx_data[], int32_T c12_idx_size[1], real_T c12_c_y_data[], int32_T
  c12_b_y_size[2])
{
  int32_T c12_y;
  int32_T c12_b_y;
  int32_T c12_loop_ub;
  int32_T c12_i255;
  int32_T c12_b_idx_size[1];
  int32_T c12_b_loop_ub;
  int32_T c12_i256;
  int32_T c12_b_idx_data[1081];
  c12_b_y_size[0] = c12_y_size[0];
  c12_b_y_size[1] = c12_y_size[1];
  c12_y = c12_b_y_size[0];
  c12_b_y = c12_b_y_size[1];
  c12_loop_ub = c12_y_size[0] * c12_y_size[1] - 1;
  for (c12_i255 = 0; c12_i255 <= c12_loop_ub; c12_i255++) {
    c12_c_y_data[c12_i255] = c12_b_y_data[c12_i255];
  }

  c12_b_idx_size[0] = c12_idx_size[0];
  c12_b_loop_ub = c12_idx_size[0] - 1;
  for (c12_i256 = 0; c12_i256 <= c12_b_loop_ub; c12_i256++) {
    c12_b_idx_data[c12_i256] = c12_idx_data[c12_i256];
  }

  c12_b_apply_row_permutation(chartInstance, c12_c_y_data, c12_b_y_size,
    c12_b_idx_data, c12_b_idx_size);
}

static boolean_T c12_rows_differ(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_c_b_data[], int32_T c12_b_size[2], int32_T c12_k0, int32_T c12_k)
{
  boolean_T c12_p;
  real_T c12_d3;
  int32_T c12_i257;
  int32_T c12_j;
  real_T c12_b_j;
  real_T c12_a;
  real_T c12_b;
  real_T c12_b_x;
  real_T c12_c_x;
  real_T c12_d_x;
  real_T c12_y;
  real_T c12_A;
  real_T c12_e_x;
  real_T c12_f_x;
  real_T c12_b_y;
  real_T c12_g_x;
  real_T c12_h_x;
  real_T c12_i_x;
  real_T c12_j_x;
  real_T c12_absxk;
  real_T c12_k_x;
  real_T c12_l_x;
  boolean_T c12_b_b;
  boolean_T c12_b9;
  real_T c12_m_x;
  boolean_T c12_c_b;
  boolean_T c12_b10;
  boolean_T c12_d_b;
  real_T c12_r;
  int32_T c12_exponent;
  int32_T c12_b_exponent;
  real_T c12_n_x;
  boolean_T c12_e_b;
  boolean_T c12_b_p;
  real_T c12_o_x;
  boolean_T c12_c_p;
  boolean_T c12_f_b;
  boolean_T exitg1;
  (void)chartInstance;
  c12_p = false;
  c12_d3 = (real_T)c12_b_size[1];
  c12_i257 = (int32_T)c12_d3 - 1;
  c12_j = 0;
  exitg1 = false;
  while ((!exitg1) && (c12_j <= c12_i257)) {
    c12_b_j = 1.0 + (real_T)c12_j;
    c12_a = c12_c_b_data[(c12_k0 + c12_b_size[0] * ((int32_T)c12_b_j - 1)) - 1];
    c12_b = c12_c_b_data[(c12_k + c12_b_size[0] * ((int32_T)c12_b_j - 1)) - 1];
    c12_b_x = c12_b - c12_a;
    c12_c_x = c12_b_x;
    c12_d_x = c12_c_x;
    c12_y = muDoubleScalarAbs(c12_d_x);
    c12_A = c12_b;
    c12_e_x = c12_A;
    c12_f_x = c12_e_x;
    c12_b_y = c12_f_x / 2.0;
    c12_g_x = c12_b_y;
    c12_h_x = c12_g_x;
    c12_i_x = c12_h_x;
    c12_j_x = c12_i_x;
    c12_absxk = muDoubleScalarAbs(c12_j_x);
    c12_k_x = c12_absxk;
    c12_l_x = c12_k_x;
    c12_b_b = muDoubleScalarIsInf(c12_l_x);
    c12_b9 = !c12_b_b;
    c12_m_x = c12_k_x;
    c12_c_b = muDoubleScalarIsNaN(c12_m_x);
    c12_b10 = !c12_c_b;
    c12_d_b = (c12_b9 && c12_b10);
    if (c12_d_b) {
      if (c12_absxk <= 2.2250738585072014E-308) {
        c12_r = 4.94065645841247E-324;
      } else {
        frexp(c12_absxk, &c12_exponent);
        c12_b_exponent = c12_exponent;
        c12_r = ldexp(1.0, c12_b_exponent - 53);
      }
    } else {
      c12_r = rtNaN;
    }

    if (c12_y < c12_r) {
      c12_b_p = true;
    } else {
      c12_n_x = c12_a;
      c12_e_b = muDoubleScalarIsInf(c12_n_x);
      if (c12_e_b) {
        c12_o_x = c12_b;
        c12_f_b = muDoubleScalarIsInf(c12_o_x);
        if (c12_f_b && ((c12_a > 0.0) == (c12_b > 0.0))) {
          c12_b_p = true;
        } else {
          c12_b_p = false;
        }
      } else {
        c12_b_p = false;
      }
    }

    c12_c_p = c12_b_p;
    if (!c12_c_p) {
      c12_p = true;
      exitg1 = true;
    } else {
      c12_j++;
    }
  }

  return c12_p;
}

static void c12_nullAssignment(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_x_data[], int32_T c12_x_size[2], boolean_T c12_idx_data[], int32_T
  c12_idx_size[1], real_T c12_b_x_data[], int32_T c12_b_x_size[2])
{
  int32_T c12_b_x;
  int32_T c12_c_x;
  int32_T c12_loop_ub;
  int32_T c12_i258;
  int32_T c12_b_idx_size[1];
  int32_T c12_b_loop_ub;
  int32_T c12_i259;
  boolean_T c12_b_idx_data[1317];
  c12_b_x_size[0] = c12_x_size[0];
  c12_b_x_size[1] = 2;
  c12_b_x = c12_b_x_size[0];
  c12_c_x = c12_b_x_size[1];
  c12_loop_ub = c12_x_size[0] * c12_x_size[1] - 1;
  for (c12_i258 = 0; c12_i258 <= c12_loop_ub; c12_i258++) {
    c12_b_x_data[c12_i258] = c12_x_data[c12_i258];
  }

  c12_b_idx_size[0] = c12_idx_size[0];
  c12_b_loop_ub = c12_idx_size[0] - 1;
  for (c12_i259 = 0; c12_i259 <= c12_b_loop_ub; c12_i259++) {
    c12_b_idx_data[c12_i259] = c12_idx_data[c12_i259];
  }

  c12_b_nullAssignment(chartInstance, c12_b_x_data, c12_b_x_size, c12_b_idx_data,
                       c12_b_idx_size);
}

static void c12_fspecial(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_varargin_2, c12_emxArray_creal_T *c12_b_h)
{
  c12_emxArray_real_T *c12_y;
  real_T c12_b_x;
  real_T c12_crad;
  real_T c12_a;
  real_T c12_d;
  real_T c12_b_a;
  real_T c12_b;
  real_T c12_c_x;
  boolean_T c12_b_b;
  real_T c12_d_x;
  boolean_T c12_c_b;
  int32_T c12_i260;
  real_T c12_e_x;
  boolean_T c12_d_b;
  int32_T c12_b_y;
  real_T c12_f_x;
  int32_T c12_c_y;
  boolean_T c12_e_b;
  int32_T c12_i261;
  real_T c12_g_x;
  c12_emxArray_real_T *c12_d_y;
  real_T c12_h_x;
  real_T c12_c_a;
  real_T c12_b_d;
  int32_T c12_e_y;
  real_T c12_d_a;
  real_T c12_e_a;
  int32_T c12_i262;
  int32_T c12_f_y;
  real_T c12_f_b;
  real_T c12_g_b;
  real_T c12_i_x;
  real_T c12_f_a;
  boolean_T c12_h_b;
  real_T c12_i_b;
  real_T c12_anew;
  int32_T c12_loop_ub;
  real_T c12_j_x;
  real_T c12_k_x;
  int32_T c12_i263;
  boolean_T c12_j_b;
  int32_T c12_i264;
  real_T c12_ndbl;
  real_T c12_l_x;
  real_T c12_apnd;
  boolean_T c12_k_b;
  real_T c12_cdiff;
  int32_T c12_g_y;
  real_T c12_m_x;
  real_T c12_n_x;
  int32_T c12_h_y;
  real_T c12_o_x;
  boolean_T c12_l_b;
  real_T c12_p_x;
  int32_T c12_i265;
  real_T c12_i_y;
  real_T c12_q_x;
  c12_emxArray_real_T *c12_r_x;
  real_T c12_g_a;
  real_T c12_s_x;
  c12_emxArray_real_T *c12_j_y;
  real_T c12_m_b;
  c12_emxArray_real_T *c12_c_varargin_1;
  real_T c12_t_x;
  int32_T c12_k_y;
  c12_emxArray_real_T *c12_u_x;
  real_T c12_v_x;
  real_T c12_h_a;
  int32_T c12_i266;
  int32_T c12_l_y;
  real_T c12_w_x;
  real_T c12_n_b;
  int32_T c12_i267;
  real_T c12_absa;
  real_T c12_i_a;
  real_T c12_x_x;
  real_T c12_o_b;
  real_T c12_y_x;
  real_T c12_b_anew;
  int32_T c12_b_loop_ub;
  real_T c12_ab_x;
  real_T c12_bb_x;
  int32_T c12_i268;
  int32_T c12_cb_x;
  real_T c12_absb;
  real_T c12_b_ndbl;
  int32_T c12_db_x;
  int32_T c12_c_loop_ub;
  real_T c12_c;
  real_T c12_b_apnd;
  real_T c12_b_cdiff;
  real_T c12_eb_x;
  int32_T c12_i269;
  real_T c12_fb_x;
  real_T c12_bnew;
  real_T c12_gb_x;
  real_T c12_m_y;
  c12_emxArray_real_T *c12_b_varargin_2;
  boolean_T c12_n_too_large;
  real_T c12_j_a;
  c12_emxArray_real_T *c12_n_y;
  real_T c12_p_b;
  int32_T c12_n;
  real_T c12_hb_x;
  int32_T c12_i270;
  real_T c12_ib_x;
  boolean_T c12_p;
  real_T c12_jb_x;
  real_T c12_b_absa;
  const mxArray *c12_o_y = NULL;
  real_T c12_kb_x;
  int32_T c12_p_y;
  static char_T c12_cv9[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T c12_i271;
  real_T c12_lb_x;
  int32_T c12_q_y;
  const mxArray *c12_r_y = NULL;
  real_T c12_mb_x;
  int32_T c12_d_loop_ub;
  real_T c12_b_absb;
  int32_T c12_i272;
  real_T c12_b_c;
  c12_emxArray_real_T *c12_r6;
  int32_T c12_k_a;
  real_T c12_b_bnew;
  int32_T c12_sak;
  int32_T c12_nm1;
  int32_T c12_sbk;
  int32_T c12_l_a;
  boolean_T c12_b_n_too_large;
  int32_T c12_m_a;
  int32_T c12_nm1d2;
  int32_T c12_q_b;
  int32_T c12_n_a;
  int32_T c12_b_n;
  int32_T c12_i273;
  int32_T c12_r_b;
  boolean_T c12_b_p;
  int32_T c12_c_c;
  int32_T c12_s_b;
  const mxArray *c12_s_y = NULL;
  int32_T c12_csz[2];
  boolean_T c12_overflow;
  static char_T c12_cv10[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T c12_i274;
  const mxArray *c12_t_y = NULL;
  int32_T c12_o_a;
  int32_T c12_t_b;
  int32_T c12_k;
  int32_T c12_d_c;
  int32_T c12_u_b;
  real_T c12_kd;
  c12_emxArray_real_T *c12_ztemp;
  int32_T c12_e_c;
  int32_T c12_p_a;
  int32_T c12_q_a;
  int32_T c12_f_c;
  int32_T c12_b_nm1;
  int32_T c12_i275;
  int32_T c12_r_a;
  int32_T c12_s_a;
  int32_T c12_t_a;
  int32_T c12_g_c;
  int32_T c12_u_a;
  int32_T c12_b_nm1d2;
  int32_T c12_h_c;
  int32_T c12_v_b;
  int32_T c12_v_a;
  int32_T c12_i_c;
  int32_T c12_i276;
  int32_T c12_i277;
  int32_T c12_w_a;
  int32_T c12_w_b;
  int32_T c12_j_c;
  int32_T c12_x_b;
  boolean_T c12_b_overflow;
  int32_T c12_i278;
  int32_T c12_i279;
  int32_T c12_b_k;
  int32_T c12_y_b;
  real_T c12_b_kd;
  int32_T c12_i280;
  int32_T c12_k_c;
  int32_T c12_x_a;
  int32_T c12_l_c;
  int32_T c12_y_a;
  c12_emxArray_real_T *c12_r7;
  int32_T c12_ab_a;
  int32_T c12_m_c;
  int32_T c12_bb_a;
  int32_T c12_i281;
  int32_T c12_n_c;
  int32_T c12_ab_b;
  int32_T c12_o_c;
  int32_T c12_cb_a;
  int32_T c12_p_c;
  int32_T c12_i282;
  int32_T c12_i283;
  int32_T c12_i284;
  int32_T c12_e_loop_ub;
  int32_T c12_i285;
  c12_emxArray_real_T *c12_d_varargin_1;
  int32_T c12_i286;
  int32_T c12_e_varargin_1;
  int32_T c12_f_varargin_1;
  int32_T c12_f_loop_ub;
  int32_T c12_i287;
  c12_emxArray_real_T *c12_c_varargin_2;
  int32_T c12_i288;
  int32_T c12_d_varargin_2;
  int32_T c12_e_varargin_2;
  int32_T c12_g_loop_ub;
  int32_T c12_i289;
  const mxArray *c12_u_y = NULL;
  const mxArray *c12_v_y = NULL;
  int32_T c12_i290;
  c12_emxArray_real_T *c12_maxxy;
  int32_T c12_i291;
  int32_T c12_nx;
  int32_T c12_bb_b;
  int32_T c12_cb_b;
  boolean_T c12_c_overflow;
  int32_T c12_c_k;
  real_T c12_nb_x;
  real_T c12_w_y;
  int32_T c12_b_sak;
  real_T c12_ob_x;
  int32_T c12_b_sbk;
  real_T c12_x_y;
  int32_T c12_db_a;
  real_T c12_ex;
  int32_T c12_db_b;
  int32_T c12_q_c;
  int32_T c12_b_csz[2];
  int32_T c12_eb_a;
  int32_T c12_eb_b;
  int32_T c12_r_c;
  int32_T c12_i292;
  int32_T c12_i293;
  int32_T c12_i294;
  int32_T c12_i295;
  int32_T c12_i296;
  c12_emxArray_real_T *c12_r8;
  int32_T c12_i297;
  int32_T c12_i298;
  int32_T c12_i299;
  int32_T c12_i300;
  int32_T c12_h_loop_ub;
  int32_T c12_i301;
  c12_emxArray_real_T *c12_g_varargin_1;
  int32_T c12_i302;
  int32_T c12_h_varargin_1;
  int32_T c12_i_varargin_1;
  int32_T c12_i_loop_ub;
  int32_T c12_i303;
  c12_emxArray_real_T *c12_f_varargin_2;
  int32_T c12_i304;
  int32_T c12_g_varargin_2;
  int32_T c12_h_varargin_2;
  int32_T c12_j_loop_ub;
  int32_T c12_i305;
  const mxArray *c12_y_y = NULL;
  const mxArray *c12_ab_y = NULL;
  int32_T c12_i306;
  c12_emxArray_real_T *c12_minxy;
  int32_T c12_i307;
  int32_T c12_b_nx;
  int32_T c12_fb_b;
  int32_T c12_gb_b;
  boolean_T c12_d_overflow;
  int32_T c12_d_k;
  real_T c12_pb_x;
  real_T c12_bb_y;
  c12_emxArray_real_T *c12_b_maxxy;
  real_T c12_qb_x;
  int32_T c12_i308;
  real_T c12_cb_y;
  real_T c12_b_ex;
  int32_T c12_c_maxxy;
  int32_T c12_d_maxxy;
  int32_T c12_k_loop_ub;
  int32_T c12_i309;
  c12_emxArray_real_T *c12_b_minxy;
  int32_T c12_i310;
  int32_T c12_c_minxy;
  int32_T c12_d_minxy;
  int32_T c12_l_loop_ub;
  int32_T c12_i311;
  int32_T c12_i312;
  int32_T c12_i313;
  int32_T c12_iv3[2];
  c12_emxArray_boolean_T *c12_r9;
  int32_T c12_rb_x[2];
  real_T c12_fb_a;
  real_T c12_gb_a;
  real_T c12_hb_a;
  real_T c12_sb_x;
  real_T c12_ib_a;
  real_T c12_s_c;
  int32_T c12_i314;
  int32_T c12_i315;
  int32_T c12_i316;
  int32_T c12_m_loop_ub;
  int32_T c12_i317;
  c12_emxArray_real_T *c12_e_maxxy;
  real_T c12_jb_a;
  real_T c12_kb_a;
  real_T c12_lb_a;
  real_T c12_tb_x;
  real_T c12_mb_a;
  real_T c12_t_c;
  int32_T c12_i318;
  int32_T c12_f_maxxy;
  int32_T c12_g_maxxy;
  int32_T c12_n_loop_ub;
  int32_T c12_i319;
  c12_emxArray_creal_T *c12_m1c;
  int32_T c12_i320;
  int32_T c12_b_m1c;
  int32_T c12_c_m1c;
  int32_T c12_o_loop_ub;
  int32_T c12_i321;
  int32_T c12_i322;
  int32_T c12_i323;
  int32_T c12_iv4[2];
  int32_T c12_d_m1c[2];
  int32_T c12_i324;
  int32_T c12_i325;
  int32_T c12_i326;
  int32_T c12_e_m1c;
  int32_T c12_f_m1c;
  int32_T c12_p_loop_ub;
  int32_T c12_i327;
  c12_emxArray_real_T *c12_h_maxxy;
  int32_T c12_i328;
  int32_T c12_i_maxxy;
  int32_T c12_j_maxxy;
  int32_T c12_q_loop_ub;
  int32_T c12_i329;
  c12_emxArray_real_T *c12_e_minxy;
  int32_T c12_i330;
  int32_T c12_f_minxy;
  int32_T c12_g_minxy;
  int32_T c12_r_loop_ub;
  int32_T c12_i331;
  int32_T c12_i332;
  int32_T c12_i333;
  int32_T c12_iv5[2];
  int32_T c12_ub_x[2];
  real_T c12_nb_a;
  real_T c12_ob_a;
  real_T c12_pb_a;
  real_T c12_vb_x;
  real_T c12_qb_a;
  real_T c12_u_c;
  int32_T c12_i334;
  int32_T c12_i335;
  int32_T c12_i336;
  int32_T c12_s_loop_ub;
  int32_T c12_i337;
  int32_T c12_i338;
  int32_T c12_i339;
  int32_T c12_iv6[2];
  int32_T c12_h_minxy[2];
  int32_T c12_i340;
  int32_T c12_i341;
  int32_T c12_i342;
  int32_T c12_t_loop_ub;
  int32_T c12_i343;
  int32_T c12_i344;
  int32_T c12_i345;
  int32_T c12_iv7[2];
  int32_T c12_g_m1c[2];
  int32_T c12_i346;
  int32_T c12_i347;
  int32_T c12_i348;
  int32_T c12_h_m1c;
  int32_T c12_i_m1c;
  int32_T c12_u_loop_ub;
  int32_T c12_i349;
  c12_emxArray_real_T *c12_k_maxxy;
  int32_T c12_i350;
  int32_T c12_l_maxxy;
  int32_T c12_m_maxxy;
  int32_T c12_v_loop_ub;
  int32_T c12_i351;
  c12_emxArray_real_T *c12_i_minxy;
  int32_T c12_i352;
  int32_T c12_j_minxy;
  int32_T c12_k_minxy;
  int32_T c12_w_loop_ub;
  int32_T c12_i353;
  int32_T c12_i354;
  int32_T c12_i355;
  int32_T c12_iv8[2];
  int32_T c12_wb_x[2];
  real_T c12_rb_a;
  real_T c12_sb_a;
  real_T c12_tb_a;
  real_T c12_xb_x;
  real_T c12_ub_a;
  real_T c12_v_c;
  int32_T c12_i356;
  int32_T c12_i357;
  int32_T c12_i358;
  int32_T c12_x_loop_ub;
  int32_T c12_i359;
  c12_emxArray_real_T *c12_n_maxxy;
  real_T c12_vb_a;
  real_T c12_wb_a;
  real_T c12_xb_a;
  real_T c12_yb_x;
  real_T c12_yb_a;
  real_T c12_w_c;
  int32_T c12_i360;
  int32_T c12_o_maxxy;
  int32_T c12_p_maxxy;
  int32_T c12_y_loop_ub;
  int32_T c12_i361;
  c12_emxArray_creal_T *c12_m2c;
  int32_T c12_i362;
  int32_T c12_b_m2c;
  int32_T c12_c_m2c;
  int32_T c12_ab_loop_ub;
  int32_T c12_i363;
  int32_T c12_i364;
  int32_T c12_i365;
  int32_T c12_iv9[2];
  int32_T c12_d_m2c[2];
  int32_T c12_i366;
  int32_T c12_i367;
  int32_T c12_i368;
  int32_T c12_e_m2c;
  int32_T c12_f_m2c;
  int32_T c12_bb_loop_ub;
  int32_T c12_i369;
  c12_emxArray_real_T *c12_q_maxxy;
  int32_T c12_i370;
  int32_T c12_r_maxxy;
  int32_T c12_s_maxxy;
  int32_T c12_cb_loop_ub;
  int32_T c12_i371;
  c12_emxArray_real_T *c12_l_minxy;
  int32_T c12_i372;
  int32_T c12_m_minxy;
  int32_T c12_n_minxy;
  int32_T c12_db_loop_ub;
  int32_T c12_i373;
  int32_T c12_i374;
  int32_T c12_i375;
  int32_T c12_iv10[2];
  int32_T c12_ac_x[2];
  real_T c12_ac_a;
  real_T c12_bc_a;
  real_T c12_cc_a;
  real_T c12_bc_x;
  real_T c12_dc_a;
  real_T c12_x_c;
  int32_T c12_i376;
  int32_T c12_i377;
  int32_T c12_i378;
  int32_T c12_eb_loop_ub;
  int32_T c12_i379;
  int32_T c12_i380;
  int32_T c12_i381;
  int32_T c12_iv11[2];
  int32_T c12_o_minxy[2];
  int32_T c12_i382;
  int32_T c12_i383;
  int32_T c12_i384;
  int32_T c12_fb_loop_ub;
  int32_T c12_i385;
  int32_T c12_i386;
  int32_T c12_i387;
  int32_T c12_iv12[2];
  int32_T c12_g_m2c[2];
  int32_T c12_i388;
  int32_T c12_i389;
  int32_T c12_i390;
  int32_T c12_h_m2c;
  int32_T c12_i_m2c;
  int32_T c12_gb_loop_ub;
  int32_T c12_i391;
  real_T c12_B;
  real_T c12_db_y;
  real_T c12_eb_y;
  int32_T c12_i392;
  int32_T c12_c_h;
  int32_T c12_d_h;
  int32_T c12_hb_loop_ub;
  int32_T c12_i393;
  c12_emxArray_creal_T *c12_fb_y;
  creal_T c12_j_m2c;
  creal_T c12_gb_y;
  real_T c12_b_B;
  real_T c12_hb_y;
  real_T c12_ar;
  real_T c12_ib_y;
  real_T c12_ai;
  int32_T c12_i394;
  real_T c12_br;
  real_T c12_bi;
  int32_T c12_jb_y;
  real_T c12_brm;
  int32_T c12_kb_y;
  real_T c12_bim;
  int32_T c12_ib_loop_ub;
  int32_T c12_i395;
  real_T c12_s;
  real_T c12_c_d;
  real_T c12_sgnbr;
  real_T c12_nr;
  creal_T c12_j_m1c;
  real_T c12_ni;
  int32_T c12_i396;
  creal_T c12_lb_y;
  real_T c12_sgnbi;
  real_T c12_b_ar;
  int32_T c12_i397;
  int32_T c12_e_h[2];
  real_T c12_b_ai;
  real_T c12_b_br;
  real_T c12_b_bi;
  c12_emxArray_creal_T *c12_mb_y;
  int32_T c12_nb_y[2];
  real_T c12_c_B;
  real_T c12_b_brm;
  real_T c12_ob_y;
  real_T c12_b_bim;
  real_T c12_pb_y;
  int32_T c12_i398;
  real_T c12_b_s;
  real_T c12_d_d;
  real_T c12_b_sgnbr;
  real_T c12_b_nr;
  real_T c12_b_ni;
  int32_T c12_qb_y;
  int32_T c12_rb_y;
  real_T c12_b_sgnbi;
  int32_T c12_jb_loop_ub;
  int32_T c12_i399;
  creal_T c12_k_m2c;
  int32_T c12_i400;
  creal_T c12_sb_y;
  int32_T c12_i401;
  real_T c12_c_ar;
  real_T c12_c_ai;
  real_T c12_c_br;
  int32_T c12_tb_y;
  real_T c12_c_bi;
  int32_T c12_ub_y;
  int32_T c12_kb_loop_ub;
  int32_T c12_i402;
  real_T c12_c_brm;
  real_T c12_c_bim;
  c12_emxArray_creal_T *c12_vb_y;
  real_T c12_c_s;
  real_T c12_e_d;
  real_T c12_d_B;
  real_T c12_c_sgnbr;
  real_T c12_c_nr;
  real_T c12_wb_y;
  real_T c12_c_ni;
  real_T c12_xb_y;
  int32_T c12_i403;
  real_T c12_c_sgnbi;
  int32_T c12_yb_y;
  int32_T c12_ac_y;
  int32_T c12_lb_loop_ub;
  int32_T c12_i404;
  creal_T c12_k_m1c;
  int32_T c12_i405;
  creal_T c12_bc_y;
  int32_T c12_i406;
  real_T c12_d_ar;
  real_T c12_d_ai;
  real_T c12_d_br;
  int32_T c12_cc_y;
  real_T c12_d_bi;
  int32_T c12_dc_y;
  int32_T c12_mb_loop_ub;
  int32_T c12_i407;
  real_T c12_d_brm;
  real_T c12_d_bim;
  real_T c12_d_s;
  int32_T c12_i408;
  real_T c12_f_d;
  real_T c12_d_sgnbr;
  real_T c12_d_nr;
  real_T c12_d_ni;
  int32_T c12_i409;
  int32_T c12_ec_y[2];
  real_T c12_d_sgnbi;
  int32_T c12_fc_y[2];
  int32_T c12_i410;
  int32_T c12_i411;
  int32_T c12_i412;
  int32_T c12_f_h;
  int32_T c12_g_h;
  int32_T c12_nb_loop_ub;
  int32_T c12_i413;
  int32_T c12_i414;
  int32_T c12_i415;
  int32_T c12_h_h;
  int32_T c12_i_h;
  int32_T c12_ob_loop_ub;
  int32_T c12_i416;
  int32_T c12_i417;
  int32_T c12_i418;
  int32_T c12_i419;
  int32_T c12_gc_y;
  int32_T c12_hc_y;
  int32_T c12_pb_loop_ub;
  int32_T c12_i420;
  int32_T c12_i421;
  int32_T c12_i422;
  int32_T c12_ic_y;
  int32_T c12_jc_y;
  int32_T c12_qb_loop_ub;
  int32_T c12_i423;
  int32_T c12_i424;
  int32_T c12_i425;
  int32_T c12_j_h[2];
  int32_T c12_kc_y[2];
  int32_T c12_i426;
  int32_T c12_i427;
  int32_T c12_l_m2c[2];
  int32_T c12_l_m1c[2];
  int32_T c12_i428;
  int32_T c12_i429;
  int32_T c12_t_maxxy[2];
  int32_T c12_m_m2c[2];
  real_T c12_ec_a;
  real_T c12_fc_a;
  real_T c12_gc_a;
  real_T c12_cc_x;
  real_T c12_hc_a;
  real_T c12_y_c;
  real_T c12_ic_a;
  int32_T c12_i430;
  int32_T c12_i431;
  int32_T c12_i432;
  int32_T c12_k_h;
  int32_T c12_l_h;
  int32_T c12_rb_loop_ub;
  int32_T c12_i433;
  int32_T c12_i434;
  int32_T c12_i435;
  int32_T c12_m_h;
  int32_T c12_n_h;
  int32_T c12_sb_loop_ub;
  int32_T c12_i436;
  int32_T c12_i437;
  int32_T c12_i438;
  int32_T c12_i439;
  int32_T c12_i440;
  int32_T c12_n_m2c;
  int32_T c12_o_m2c;
  int32_T c12_tb_loop_ub;
  int32_T c12_i441;
  int32_T c12_i442;
  creal_T c12_p_m2c;
  int32_T c12_i443;
  int32_T c12_o_h[2];
  int32_T c12_q_m2c[2];
  int32_T c12_i444;
  int32_T c12_i445;
  int32_T c12_m_m1c[2];
  int32_T c12_p_minxy[2];
  int32_T c12_i446;
  int32_T c12_i447;
  int32_T c12_p_h[2];
  c12_emxArray_real_T *c12_u_maxxy;
  int32_T c12_n_m1c[2];
  int32_T c12_i448;
  int32_T c12_v_maxxy;
  int32_T c12_w_maxxy;
  int32_T c12_ub_loop_ub;
  int32_T c12_i449;
  c12_emxArray_real_T *c12_q_minxy;
  int32_T c12_i450;
  int32_T c12_r_minxy;
  int32_T c12_s_minxy;
  int32_T c12_vb_loop_ub;
  int32_T c12_i451;
  int32_T c12_i452;
  int32_T c12_i453;
  int32_T c12_iv13[2];
  c12_emxArray_real_T *c12_x_maxxy;
  int32_T c12_dc_x[2];
  int32_T c12_i454;
  int32_T c12_y_maxxy;
  int32_T c12_ab_maxxy;
  int32_T c12_wb_loop_ub;
  int32_T c12_i455;
  c12_emxArray_real_T *c12_t_minxy;
  int32_T c12_i456;
  int32_T c12_u_minxy;
  int32_T c12_v_minxy;
  int32_T c12_xb_loop_ub;
  int32_T c12_i457;
  int32_T c12_i458;
  int32_T c12_i459;
  int32_T c12_lc_y[2];
  int32_T c12_b_ztemp[2];
  real_T c12_jc_a;
  real_T c12_kc_a;
  real_T c12_lc_a;
  real_T c12_ec_x;
  real_T c12_mc_a;
  real_T c12_ab_c;
  int32_T c12_i460;
  int32_T c12_i461;
  int32_T c12_i462;
  int32_T c12_yb_loop_ub;
  int32_T c12_i463;
  c12_emxArray_boolean_T *c12_r10;
  real_T c12_nc_a;
  real_T c12_oc_a;
  real_T c12_pc_a;
  real_T c12_fc_x;
  real_T c12_qc_a;
  real_T c12_bb_c;
  int32_T c12_i464;
  int32_T c12_i465;
  int32_T c12_i466;
  int32_T c12_ac_loop_ub;
  int32_T c12_i467;
  int32_T c12_i468;
  int32_T c12_i469;
  int32_T c12_iv14[2];
  c12_emxArray_boolean_T *c12_r11;
  int32_T c12_iv15[2];
  int32_T c12_i470;
  int32_T c12_i471;
  int32_T c12_i472;
  int32_T c12_bc_loop_ub;
  int32_T c12_i473;
  c12_emxArray_boolean_T *c12_r12;
  int32_T c12_i474;
  int32_T c12_i475;
  int32_T c12_i476;
  int32_T c12_cc_loop_ub;
  int32_T c12_i477;
  int32_T c12_i478;
  int32_T c12_i479;
  int32_T c12_iv16[2];
  int32_T c12_iv17[2];
  int32_T c12_i480;
  int32_T c12_i481;
  int32_T c12_i482;
  int32_T c12_i483;
  int32_T c12_i484;
  int32_T c12_dc_loop_ub;
  int32_T c12_i485;
  int32_T c12_i486;
  int32_T c12_i487;
  int32_T c12_i488;
  int32_T c12_ec_loop_ub;
  int32_T c12_i489;
  int32_T c12_i490;
  int32_T c12_i491;
  int32_T c12_iv18[2];
  int32_T c12_iv19[2];
  int32_T c12_i492;
  int32_T c12_i493;
  int32_T c12_i494;
  int32_T c12_i495;
  int32_T c12_i496;
  int32_T c12_fc_loop_ub;
  int32_T c12_i497;
  int32_T c12_i498;
  int32_T c12_i499;
  int32_T c12_i500;
  int32_T c12_i501;
  int32_T c12_i502;
  int32_T c12_gc_loop_ub;
  int32_T c12_i503;
  int32_T c12_i504;
  int32_T c12_i505;
  int32_T c12_iv20[2];
  int32_T c12_iv21[2];
  int32_T c12_i506;
  int32_T c12_i507;
  int32_T c12_i508;
  int32_T c12_i509;
  int32_T c12_i510;
  int32_T c12_hc_loop_ub;
  int32_T c12_i511;
  int32_T c12_i512;
  int32_T c12_i513;
  int32_T c12_q_h[2];
  int32_T c12_iv22[2];
  int32_T c12_i514;
  int32_T c12_i515;
  int32_T c12_i516;
  int32_T c12_i517;
  int32_T c12_i518;
  int32_T c12_i519;
  int32_T c12_r_h;
  int32_T c12_s_h;
  int32_T c12_ic_loop_ub;
  int32_T c12_i520;
  creal_T c12_t_h;
  static creal_T c12_dc3 = { 0.5,      /* re */
    0.0                                /* im */
  };

  c12_emxArray_real_T *c12_bb_maxxy;
  int32_T c12_i521;
  int32_T c12_cb_maxxy;
  int32_T c12_db_maxxy;
  int32_T c12_jc_loop_ub;
  int32_T c12_i522;
  c12_emxArray_real_T *c12_w_minxy;
  int32_T c12_i523;
  int32_T c12_x_minxy;
  int32_T c12_y_minxy;
  int32_T c12_kc_loop_ub;
  int32_T c12_i524;
  int32_T c12_i525;
  int32_T c12_i526;
  int32_T c12_iv23[2];
  int32_T c12_gc_x[2];
  real_T c12_rc_a;
  real_T c12_sc_a;
  real_T c12_tc_a;
  real_T c12_hc_x;
  real_T c12_uc_a;
  real_T c12_cb_c;
  int32_T c12_i527;
  int32_T c12_i528;
  int32_T c12_i529;
  int32_T c12_lc_loop_ub;
  int32_T c12_i530;
  int32_T c12_i531;
  int32_T c12_i532;
  int32_T c12_u_h[2];
  int32_T c12_iv24[2];
  int32_T c12_i533;
  int32_T c12_i534;
  int32_T c12_i535;
  int32_T c12_v_h;
  int32_T c12_w_h;
  int32_T c12_mc_loop_ub;
  int32_T c12_i536;
  real_T c12_vc_a;
  real_T c12_wc_a;
  real_T c12_xc_a;
  real_T c12_ic_x;
  real_T c12_yc_a;
  real_T c12_db_c;
  real_T c12_j_varargin_1;
  real_T c12_jc_x;
  real_T c12_kc_x;
  real_T c12_lc_x;
  real_T c12_mc_x;
  real_T c12_nc_x;
  real_T c12_oc_x;
  real_T c12_minval;
  real_T c12_ad_a;
  real_T c12_bd_a;
  creal_T c12_k_varargin_1;
  real_T c12_cd_a;
  real_T c12_pc_x;
  boolean_T c12_b11;
  real_T c12_dd_a;
  boolean_T c12_b12;
  real_T c12_eb_c;
  boolean_T c12_hb_b;
  real_T c12_ed_a;
  real_T c12_fd_a;
  real_T c12_qc_x;
  boolean_T c12_c_p;
  real_T c12_gd_a;
  real_T c12_rc_x;
  real_T c12_sc_x;
  real_T c12_tc_x;
  real_T c12_hd_a;
  real_T c12_mc_y;
  real_T c12_fb_c;
  c12_emxArray_creal_T *c12_uc_x;
  real_T c12_vc_x;
  real_T c12_id_a;
  real_T c12_wc_x;
  boolean_T c12_SCALEA;
  real_T c12_jd_a;
  real_T c12_xc_x;
  int32_T c12_i537;
  real_T c12_kd_a;
  real_T c12_nc_y;
  real_T c12_yc_x;
  real_T c12_x1;
  real_T c12_A;
  real_T c12_ld_a;
  real_T c12_x2;
  real_T c12_ad_x;
  int32_T c12_nc_loop_ub;
  real_T c12_gb_c;
  real_T c12_bd_x;
  real_T c12_cd_x;
  int32_T c12_i538;
  real_T c12_md_a;
  real_T c12_oc_y;
  real_T c12_pc_y;
  real_T c12_nd_a;
  real_T c12_b_A;
  real_T c12_dd_x;
  real_T c12_ed_x;
  real_T c12_fd_x;
  real_T c12_od_a;
  real_T c12_qc_y;
  real_T c12_gd_x;
  real_T c12_rc_y;
  boolean_T c12_d_p;
  real_T c12_sc_y;
  boolean_T c12_b13;
  real_T c12_hd_x;
  real_T c12_id_x;
  real_T c12_m1;
  real_T c12_jd_x;
  real_T c12_tc_y;
  real_T c12_kd_x;
  real_T c12_ld_x;
  real_T c12_md_x;
  const mxArray *c12_uc_y = NULL;
  real_T c12_nd_x;
  real_T c12_vc_y;
  int32_T c12_vlen;
  boolean_T c12_e_p;
  real_T c12_absar;
  real_T c12_od_x;
  const mxArray *c12_wc_y = NULL;
  real_T c12_pd_x;
  real_T c12_xc_y;
  boolean_T c12_f_p;
  real_T c12_qd_x;
  real_T c12_b_x1;
  int32_T c12_b_vlen;
  real_T c12_rd_x;
  real_T c12_b_x2;
  real_T c12_absai;
  int32_T c12_ib_b;
  int32_T c12_jb_b;
  int32_T c12_i539;
  real_T c12_c_A;
  real_T c12_Ma;
  int32_T c12_i540;
  real_T c12_e_B;
  real_T c12_ma;
  boolean_T c12_e_overflow;
  real_T c12_sd_x;
  real_T c12_yc_y;
  real_T c12_td_x;
  int32_T c12_x_h;
  real_T c12_ad_y;
  real_T c12_ud_x;
  int32_T c12_e_k;
  int32_T c12_y_h;
  real_T c12_m1n;
  real_T c12_bd_y;
  real_T c12_d_A;
  int32_T c12_oc_loop_ub;
  real_T c12_pd_a;
  real_T c12_e_A;
  real_T c12_vd_x;
  int32_T c12_i541;
  real_T c12_qd_a;
  real_T c12_wd_x;
  real_T c12_xd_x;
  int32_T c12_xoffset;
  real_T c12_rd_a;
  real_T c12_yd_x;
  real_T c12_cd_y;
  int32_T c12_ix;
  real_T c12_ae_x;
  real_T c12_dd_y;
  real_T c12_Mbar;
  creal_T c12_ab_h;
  real_T c12_sd_a;
  real_T c12_be_x;
  real_T c12_f_A;
  creal_T c12_l_varargin_1;
  real_T c12_hb_c;
  real_T c12_ed_y;
  real_T c12_g_A;
  real_T c12_ce_x;
  real_T c12_e_ar;
  real_T c12_de_x;
  boolean_T c12_g_p;
  real_T c12_ee_x;
  real_T c12_fe_x;
  real_T c12_e_ai;
  real_T c12_ge_x;
  real_T c12_he_x;
  real_T c12_fd_y;
  real_T c12_e_br;
  real_T c12_ie_x;
  real_T c12_gd_y;
  real_T c12_hd_y;
  real_T c12_mbar;
  real_T c12_e_bi;
  boolean_T c12_b14;
  real_T c12_je_x;
  real_T c12_h_A;
  boolean_T c12_b15;
  real_T c12_i_A;
  real_T c12_f_B;
  real_T c12_g_B;
  real_T c12_ke_x;
  real_T c12_e_brm;
  boolean_T c12_h_p;
  real_T c12_le_x;
  real_T c12_me_x;
  real_T c12_id_y;
  real_T c12_e_bim;
  boolean_T c12_i_p;
  real_T c12_jd_y;
  real_T c12_ne_x;
  boolean_T c12_j_p;
  real_T c12_oe_x;
  real_T c12_kd_y;
  real_T c12_e_s;
  real_T c12_pe_x;
  real_T c12_ld_y;
  real_T c12_md_y;
  real_T c12_g_d;
  real_T c12_qe_x;
  real_T c12_nd_y;
  real_T c12_e_sgnbr;
  real_T c12_e_nr;
  real_T c12_f_ar;
  real_T c12_e_ni;
  real_T c12_re_x;
  real_T c12_f_ai;
  real_T c12_se_x;
  real_T c12_e_sgnbi;
  real_T c12_te_x;
  boolean_T c12_b16;
  boolean_T c12_b17;
  real_T c12_od_y;
  boolean_T c12_k_p;
  boolean_T c12_l_p;
  real_T c12_ue_x;
  real_T c12_pd_y;
  boolean_T c12_m_p;
  real_T c12_ve_x;
  real_T c12_we_x;
  real_T c12_sg0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c12_emxInit_real_T(chartInstance, &c12_y, 2, &c12_ff_emlrtRTEI);
  c12_validateattributes(chartInstance, c12_varargin_2);
  c12_b_x = c12_varargin_2 - 0.5;
  c12_crad = c12_b_x;
  c12_crad = muDoubleScalarCeil(c12_crad);
  c12_a = -c12_crad;
  c12_d = c12_crad;
  c12_b_a = c12_a;
  c12_b = c12_d;
  c12_c_x = c12_b_a;
  c12_b_b = muDoubleScalarIsNaN(c12_c_x);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (c12_b_b) {
    guard2 = true;
  } else {
    c12_d_x = c12_b;
    c12_c_b = muDoubleScalarIsNaN(c12_d_x);
    if (c12_c_b) {
      guard2 = true;
    } else {
      c12_e_x = c12_b_a;
      c12_d_b = muDoubleScalarIsInf(c12_e_x);
      if (c12_d_b) {
        guard3 = true;
      } else {
        c12_f_x = c12_b;
        c12_e_b = muDoubleScalarIsInf(c12_f_x);
        if (c12_e_b) {
          guard3 = true;
        } else {
          guard1 = true;
        }
      }
    }
  }

  if (guard3) {
    if (c12_b_a == c12_b) {
      c12_i261 = c12_y->size[0] * c12_y->size[1];
      c12_y->size[0] = 1;
      c12_y->size[1] = 1;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_y, c12_i261,
        &c12_tc_emlrtRTEI);
      c12_e_y = c12_y->size[0];
      c12_f_y = c12_y->size[1];
      c12_y->data[0] = rtNaN;
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    c12_i260 = c12_y->size[0] * c12_y->size[1];
    c12_y->size[0] = 1;
    c12_y->size[1] = 1;
    c12_emxEnsureCapacity_real_T(chartInstance, c12_y, c12_i260,
      &c12_tc_emlrtRTEI);
    c12_b_y = c12_y->size[0];
    c12_c_y = c12_y->size[1];
    c12_y->data[0] = rtNaN;
  }

  if (guard1) {
    c12_g_x = c12_b_a;
    c12_h_x = c12_g_x;
    c12_h_x = muDoubleScalarFloor(c12_h_x);
    if (c12_h_x == c12_b_a) {
      c12_i262 = c12_y->size[0] * c12_y->size[1];
      c12_y->size[0] = 1;
      c12_y->size[1] = (int32_T)muDoubleScalarFloor(c12_b - c12_b_a) + 1;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_y, c12_i262,
        &c12_tc_emlrtRTEI);
      c12_loop_ub = (int32_T)muDoubleScalarFloor(c12_b - c12_b_a);
      for (c12_i263 = 0; c12_i263 <= c12_loop_ub; c12_i263++) {
        c12_y->data[c12_y->size[0] * c12_i263] = c12_b_a + (real_T)c12_i263;
      }
    } else {
      c12_e_a = c12_b_a;
      c12_g_b = c12_b;
      c12_f_a = c12_e_a;
      c12_i_b = c12_g_b;
      c12_anew = c12_f_a;
      c12_k_x = (c12_i_b - c12_f_a) + 0.5;
      c12_ndbl = c12_k_x;
      c12_ndbl = muDoubleScalarFloor(c12_ndbl);
      c12_apnd = c12_f_a + c12_ndbl;
      c12_cdiff = c12_apnd - c12_i_b;
      c12_m_x = c12_cdiff;
      c12_o_x = c12_m_x;
      c12_p_x = c12_o_x;
      c12_i_y = muDoubleScalarAbs(c12_p_x);
      c12_g_a = c12_f_a;
      c12_m_b = c12_i_b;
      c12_t_x = c12_g_a;
      c12_v_x = c12_t_x;
      c12_w_x = c12_v_x;
      c12_absa = muDoubleScalarAbs(c12_w_x);
      c12_x_x = c12_m_b;
      c12_y_x = c12_x_x;
      c12_ab_x = c12_y_x;
      c12_absb = muDoubleScalarAbs(c12_ab_x);
      if (c12_absa > c12_absb) {
        c12_c = c12_absa;
      } else {
        c12_c = c12_absb;
      }

      if (c12_i_y < 4.4408920985006262E-16 * c12_c) {
        c12_ndbl++;
        c12_bnew = c12_i_b;
      } else if (c12_cdiff > 0.0) {
        c12_bnew = c12_f_a + (c12_ndbl - 1.0);
      } else {
        c12_ndbl++;
        c12_bnew = c12_apnd;
      }

      c12_n_too_large = (c12_ndbl > 2.147483647E+9);
      if (c12_ndbl >= 0.0) {
        c12_n = (int32_T)muDoubleScalarFloor(c12_ndbl);
      } else {
        c12_n = 0;
      }

      c12_p = !c12_n_too_large;
      if (c12_p) {
      } else {
        c12_o_y = NULL;
        sf_mex_assign(&c12_o_y, sf_mex_create("y", c12_cv9, 10, 0U, 1U, 0U, 2, 1,
          21), false);
        c12_r_y = NULL;
        sf_mex_assign(&c12_r_y, sf_mex_create("y", c12_cv9, 10, 0U, 1U, 0U, 2, 1,
          21), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c12_o_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c12_r_y)));
      }

      c12_i271 = c12_y->size[0] * c12_y->size[1];
      c12_y->size[0] = 1;
      c12_y->size[1] = c12_n;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_y, c12_i271,
        &c12_wc_emlrtRTEI);
      if (c12_n > 0) {
        c12_y->data[0] = c12_anew;
        if (c12_n > 1) {
          c12_y->data[c12_n - 1] = c12_bnew;
          c12_k_a = c12_n - 1;
          c12_nm1 = c12_k_a;
          c12_l_a = c12_nm1;
          c12_nm1d2 = c12_div_nzp_s32(chartInstance, c12_l_a, 2, 1U, 0, 0);
          c12_n_a = c12_nm1d2 - 1;
          c12_i273 = c12_n_a;
          c12_r_b = c12_i273;
          c12_s_b = c12_r_b;
          if (1 > c12_s_b) {
            c12_overflow = false;
          } else {
            c12_overflow = (c12_s_b > 2147483646);
          }

          if (c12_overflow) {
            c12_check_forloop_overflow_error(chartInstance, true);
          }

          for (c12_k = 1; c12_k <= c12_i273; c12_k++) {
            c12_kd = (real_T)c12_k;
            c12_p_a = c12_k + 1;
            c12_f_c = c12_p_a - 1;
            c12_y->data[c12_f_c] = c12_anew + c12_kd;
            c12_u_a = c12_n;
            c12_v_b = c12_k;
            c12_i_c = (c12_u_a - c12_v_b) - 1;
            c12_y->data[c12_i_c] = c12_bnew - c12_kd;
          }

          c12_u_b = c12_nm1d2;
          c12_e_c = c12_u_b << 1;
          if (c12_e_c == c12_nm1) {
            c12_r_a = c12_nm1d2 + 1;
            c12_g_c = c12_r_a - 1;
            c12_y->data[c12_g_c] = (c12_anew + c12_bnew) / 2.0;
          } else {
            c12_kd = (real_T)c12_nm1d2;
            c12_t_a = c12_nm1d2 + 1;
            c12_h_c = c12_t_a - 1;
            c12_y->data[c12_h_c] = c12_anew + c12_kd;
            c12_w_a = c12_nm1d2 + 2;
            c12_j_c = c12_w_a - 1;
            c12_y->data[c12_j_c] = c12_bnew - c12_kd;
          }
        }
      }
    }
  }

  c12_emxInit_real_T(chartInstance, &c12_d_y, 2, &c12_gf_emlrtRTEI);
  c12_c_a = -c12_crad;
  c12_b_d = c12_crad;
  c12_d_a = c12_c_a;
  c12_f_b = c12_b_d;
  c12_i_x = c12_d_a;
  c12_h_b = muDoubleScalarIsNaN(c12_i_x);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (c12_h_b) {
    guard2 = true;
  } else {
    c12_j_x = c12_f_b;
    c12_j_b = muDoubleScalarIsNaN(c12_j_x);
    if (c12_j_b) {
      guard2 = true;
    } else {
      c12_l_x = c12_d_a;
      c12_k_b = muDoubleScalarIsInf(c12_l_x);
      if (c12_k_b) {
        guard3 = true;
      } else {
        c12_n_x = c12_f_b;
        c12_l_b = muDoubleScalarIsInf(c12_n_x);
        if (c12_l_b) {
          guard3 = true;
        } else {
          guard1 = true;
        }
      }
    }
  }

  if (guard3) {
    if (c12_d_a == c12_f_b) {
      c12_i265 = c12_d_y->size[0] * c12_d_y->size[1];
      c12_d_y->size[0] = 1;
      c12_d_y->size[1] = 1;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_d_y, c12_i265,
        &c12_tc_emlrtRTEI);
      c12_k_y = c12_d_y->size[0];
      c12_l_y = c12_d_y->size[1];
      c12_d_y->data[0] = rtNaN;
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    c12_i264 = c12_d_y->size[0] * c12_d_y->size[1];
    c12_d_y->size[0] = 1;
    c12_d_y->size[1] = 1;
    c12_emxEnsureCapacity_real_T(chartInstance, c12_d_y, c12_i264,
      &c12_tc_emlrtRTEI);
    c12_g_y = c12_d_y->size[0];
    c12_h_y = c12_d_y->size[1];
    c12_d_y->data[0] = rtNaN;
  }

  if (guard1) {
    c12_q_x = c12_d_a;
    c12_s_x = c12_q_x;
    c12_s_x = muDoubleScalarFloor(c12_s_x);
    if (c12_s_x == c12_d_a) {
      c12_i266 = c12_d_y->size[0] * c12_d_y->size[1];
      c12_d_y->size[0] = 1;
      c12_d_y->size[1] = (int32_T)muDoubleScalarFloor(c12_f_b - c12_d_a) + 1;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_d_y, c12_i266,
        &c12_tc_emlrtRTEI);
      c12_b_loop_ub = (int32_T)muDoubleScalarFloor(c12_f_b - c12_d_a);
      for (c12_i268 = 0; c12_i268 <= c12_b_loop_ub; c12_i268++) {
        c12_d_y->data[c12_d_y->size[0] * c12_i268] = c12_d_a + (real_T)c12_i268;
      }
    } else {
      c12_h_a = c12_d_a;
      c12_n_b = c12_f_b;
      c12_i_a = c12_h_a;
      c12_o_b = c12_n_b;
      c12_b_anew = c12_i_a;
      c12_bb_x = (c12_o_b - c12_i_a) + 0.5;
      c12_b_ndbl = c12_bb_x;
      c12_b_ndbl = muDoubleScalarFloor(c12_b_ndbl);
      c12_b_apnd = c12_i_a + c12_b_ndbl;
      c12_b_cdiff = c12_b_apnd - c12_o_b;
      c12_eb_x = c12_b_cdiff;
      c12_fb_x = c12_eb_x;
      c12_gb_x = c12_fb_x;
      c12_m_y = muDoubleScalarAbs(c12_gb_x);
      c12_j_a = c12_i_a;
      c12_p_b = c12_o_b;
      c12_hb_x = c12_j_a;
      c12_ib_x = c12_hb_x;
      c12_jb_x = c12_ib_x;
      c12_b_absa = muDoubleScalarAbs(c12_jb_x);
      c12_kb_x = c12_p_b;
      c12_lb_x = c12_kb_x;
      c12_mb_x = c12_lb_x;
      c12_b_absb = muDoubleScalarAbs(c12_mb_x);
      if (c12_b_absa > c12_b_absb) {
        c12_b_c = c12_b_absa;
      } else {
        c12_b_c = c12_b_absb;
      }

      if (c12_m_y < 4.4408920985006262E-16 * c12_b_c) {
        c12_b_ndbl++;
        c12_b_bnew = c12_o_b;
      } else if (c12_b_cdiff > 0.0) {
        c12_b_bnew = c12_i_a + (c12_b_ndbl - 1.0);
      } else {
        c12_b_ndbl++;
        c12_b_bnew = c12_b_apnd;
      }

      c12_b_n_too_large = (c12_b_ndbl > 2.147483647E+9);
      if (c12_b_ndbl >= 0.0) {
        c12_b_n = (int32_T)muDoubleScalarFloor(c12_b_ndbl);
      } else {
        c12_b_n = 0;
      }

      c12_b_p = !c12_b_n_too_large;
      if (c12_b_p) {
      } else {
        c12_s_y = NULL;
        sf_mex_assign(&c12_s_y, sf_mex_create("y", c12_cv10, 10, 0U, 1U, 0U, 2,
          1, 21), false);
        c12_t_y = NULL;
        sf_mex_assign(&c12_t_y, sf_mex_create("y", c12_cv10, 10, 0U, 1U, 0U, 2,
          1, 21), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c12_s_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c12_t_y)));
      }

      c12_i274 = c12_d_y->size[0] * c12_d_y->size[1];
      c12_d_y->size[0] = 1;
      c12_d_y->size[1] = c12_b_n;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_d_y, c12_i274,
        &c12_wc_emlrtRTEI);
      if (c12_b_n > 0) {
        c12_d_y->data[0] = c12_b_anew;
        if (c12_b_n > 1) {
          c12_d_y->data[c12_b_n - 1] = c12_b_bnew;
          c12_q_a = c12_b_n - 1;
          c12_b_nm1 = c12_q_a;
          c12_s_a = c12_b_nm1;
          c12_b_nm1d2 = c12_div_nzp_s32(chartInstance, c12_s_a, 2, 1U, 0, 0);
          c12_v_a = c12_b_nm1d2 - 1;
          c12_i276 = c12_v_a;
          c12_w_b = c12_i276;
          c12_x_b = c12_w_b;
          if (1 > c12_x_b) {
            c12_b_overflow = false;
          } else {
            c12_b_overflow = (c12_x_b > 2147483646);
          }

          if (c12_b_overflow) {
            c12_check_forloop_overflow_error(chartInstance, true);
          }

          for (c12_b_k = 1; c12_b_k <= c12_i276; c12_b_k++) {
            c12_b_kd = (real_T)c12_b_k;
            c12_x_a = c12_b_k + 1;
            c12_l_c = c12_x_a - 1;
            c12_d_y->data[c12_l_c] = c12_b_anew + c12_b_kd;
            c12_bb_a = c12_b_n;
            c12_ab_b = c12_b_k;
            c12_o_c = (c12_bb_a - c12_ab_b) - 1;
            c12_d_y->data[c12_o_c] = c12_b_bnew - c12_b_kd;
          }

          c12_y_b = c12_b_nm1d2;
          c12_k_c = c12_y_b << 1;
          if (c12_k_c == c12_b_nm1) {
            c12_y_a = c12_b_nm1d2 + 1;
            c12_m_c = c12_y_a - 1;
            c12_d_y->data[c12_m_c] = (c12_b_anew + c12_b_bnew) / 2.0;
          } else {
            c12_b_kd = (real_T)c12_b_nm1d2;
            c12_ab_a = c12_b_nm1d2 + 1;
            c12_n_c = c12_ab_a - 1;
            c12_d_y->data[c12_n_c] = c12_b_anew + c12_b_kd;
            c12_cb_a = c12_b_nm1d2 + 2;
            c12_p_c = c12_cb_a - 1;
            c12_d_y->data[c12_p_c] = c12_b_bnew - c12_b_kd;
          }
        }
      }
    }
  }

  c12_emxInit_real_T(chartInstance, &c12_r_x, 2, &c12_ef_emlrtRTEI);
  c12_emxInit_real_T(chartInstance, &c12_j_y, 2, &c12_ef_emlrtRTEI);
  c12_emxInit_real_T(chartInstance, &c12_c_varargin_1, 2, &c12_hf_emlrtRTEI);
  c12_emxInit_real_T(chartInstance, &c12_u_x, 2, &c12_uc_emlrtRTEI);
  c12_meshgrid(chartInstance, c12_y, c12_d_y, c12_r_x, c12_j_y);
  c12_i267 = c12_u_x->size[0] * c12_u_x->size[1];
  c12_u_x->size[0] = c12_r_x->size[0];
  c12_u_x->size[1] = c12_r_x->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_u_x, c12_i267,
    &c12_uc_emlrtRTEI);
  c12_cb_x = c12_u_x->size[0];
  c12_db_x = c12_u_x->size[1];
  c12_c_loop_ub = c12_r_x->size[0] * c12_r_x->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_d_y);
  c12_emxFree_real_T(chartInstance, &c12_y);
  for (c12_i269 = 0; c12_i269 <= c12_c_loop_ub; c12_i269++) {
    c12_u_x->data[c12_i269] = c12_r_x->data[c12_i269];
  }

  c12_emxInit_real_T(chartInstance, &c12_b_varargin_2, 2, &c12_if_emlrtRTEI);
  c12_emxInit_real_T(chartInstance, &c12_n_y, 2, &c12_vc_emlrtRTEI);
  c12_abs(chartInstance, c12_u_x, c12_c_varargin_1);
  c12_i270 = c12_n_y->size[0] * c12_n_y->size[1];
  c12_n_y->size[0] = c12_j_y->size[0];
  c12_n_y->size[1] = c12_j_y->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_n_y, c12_i270,
    &c12_vc_emlrtRTEI);
  c12_p_y = c12_n_y->size[0];
  c12_q_y = c12_n_y->size[1];
  c12_d_loop_ub = c12_j_y->size[0] * c12_j_y->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_u_x);
  for (c12_i272 = 0; c12_i272 <= c12_d_loop_ub; c12_i272++) {
    c12_n_y->data[c12_i272] = c12_j_y->data[c12_i272];
  }

  c12_emxInit_real_T(chartInstance, &c12_r6, 2, &c12_ad_emlrtRTEI);
  c12_abs(chartInstance, c12_n_y, c12_b_varargin_2);
  c12_sak = c12_c_varargin_1->size[0];
  c12_sbk = c12_b_varargin_2->size[0];
  c12_m_a = c12_sak;
  c12_q_b = c12_sbk;
  c12_emxFree_real_T(chartInstance, &c12_n_y);
  if (c12_m_a <= c12_q_b) {
    c12_c_c = c12_m_a;
  } else {
    c12_c_c = c12_q_b;
  }

  c12_csz[0] = c12_c_c;
  c12_sak = c12_c_varargin_1->size[1];
  c12_sbk = c12_b_varargin_2->size[1];
  c12_o_a = c12_sak;
  c12_t_b = c12_sbk;
  if (c12_o_a <= c12_t_b) {
    c12_d_c = c12_o_a;
  } else {
    c12_d_c = c12_t_b;
  }

  c12_emxInit_real_T(chartInstance, &c12_ztemp, 2, &c12_jf_emlrtRTEI);
  c12_csz[1] = c12_d_c;
  c12_i275 = c12_ztemp->size[0] * c12_ztemp->size[1];
  c12_ztemp->size[0] = c12_csz[0];
  c12_ztemp->size[1] = c12_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_ztemp, c12_i275,
    &c12_xc_emlrtRTEI);
  c12_i277 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_ztemp->size[0];
  c12_r6->size[1] = c12_ztemp->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i277,
    &c12_xc_emlrtRTEI);
  for (c12_i278 = 0; c12_i278 < 2; c12_i278++) {
    c12_csz[c12_i278] = c12_r6->size[c12_i278];
  }

  c12_i279 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_csz[0];
  c12_r6->size[1] = c12_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i279,
    &c12_yc_emlrtRTEI);
  for (c12_i280 = 0; c12_i280 < 2; c12_i280++) {
    c12_csz[c12_i280] = c12_r6->size[c12_i280];
  }

  c12_emxInit_real_T(chartInstance, &c12_r7, 2, &c12_bd_emlrtRTEI);
  c12_i281 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_csz[0];
  c12_r6->size[1] = c12_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i281,
    &c12_ad_emlrtRTEI);
  c12_i282 = c12_r7->size[0] * c12_r7->size[1];
  c12_r7->size[0] = c12_r6->size[0];
  c12_r7->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r7, c12_i282,
    &c12_bd_emlrtRTEI);
  c12_i283 = c12_r7->size[0];
  c12_i284 = c12_r7->size[1];
  c12_e_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i285 = 0; c12_i285 <= c12_e_loop_ub; c12_i285++) {
    c12_r7->data[c12_i285] = c12_r6->data[c12_i285];
  }

  c12_emxInit_real_T(chartInstance, &c12_d_varargin_1, 2, &c12_cd_emlrtRTEI);
  c12_i286 = c12_d_varargin_1->size[0] * c12_d_varargin_1->size[1];
  c12_d_varargin_1->size[0] = c12_c_varargin_1->size[0];
  c12_d_varargin_1->size[1] = c12_c_varargin_1->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_d_varargin_1, c12_i286,
    &c12_cd_emlrtRTEI);
  c12_e_varargin_1 = c12_d_varargin_1->size[0];
  c12_f_varargin_1 = c12_d_varargin_1->size[1];
  c12_f_loop_ub = c12_c_varargin_1->size[0] * c12_c_varargin_1->size[1] - 1;
  for (c12_i287 = 0; c12_i287 <= c12_f_loop_ub; c12_i287++) {
    c12_d_varargin_1->data[c12_i287] = c12_c_varargin_1->data[c12_i287];
  }

  c12_emxInit_real_T(chartInstance, &c12_c_varargin_2, 2, &c12_cd_emlrtRTEI);
  c12_i288 = c12_c_varargin_2->size[0] * c12_c_varargin_2->size[1];
  c12_c_varargin_2->size[0] = c12_b_varargin_2->size[0];
  c12_c_varargin_2->size[1] = c12_b_varargin_2->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_c_varargin_2, c12_i288,
    &c12_cd_emlrtRTEI);
  c12_d_varargin_2 = c12_c_varargin_2->size[0];
  c12_e_varargin_2 = c12_c_varargin_2->size[1];
  c12_g_loop_ub = c12_b_varargin_2->size[0] * c12_b_varargin_2->size[1] - 1;
  for (c12_i289 = 0; c12_i289 <= c12_g_loop_ub; c12_i289++) {
    c12_c_varargin_2->data[c12_i289] = c12_b_varargin_2->data[c12_i289];
  }

  if (c12_dimagree(chartInstance, c12_r7, c12_d_varargin_1, c12_c_varargin_2)) {
  } else {
    c12_u_y = NULL;
    sf_mex_assign(&c12_u_y, sf_mex_create("y", c12_cv1, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    c12_v_y = NULL;
    sf_mex_assign(&c12_v_y, sf_mex_create("y", c12_cv1, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_u_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c12_v_y)));
  }

  c12_emxFree_real_T(chartInstance, &c12_c_varargin_2);
  c12_emxFree_real_T(chartInstance, &c12_d_varargin_1);
  c12_emxFree_real_T(chartInstance, &c12_r7);
  for (c12_i290 = 0; c12_i290 < 2; c12_i290++) {
    c12_csz[c12_i290] = c12_r6->size[c12_i290];
  }

  c12_emxInit_real_T(chartInstance, &c12_maxxy, 2, &c12_dd_emlrtRTEI);
  c12_i291 = c12_maxxy->size[0] * c12_maxxy->size[1];
  c12_maxxy->size[0] = c12_csz[0];
  c12_maxxy->size[1] = c12_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_maxxy, c12_i291,
    &c12_dd_emlrtRTEI);
  c12_nx = c12_maxxy->size[0] * c12_maxxy->size[1];
  c12_bb_b = c12_nx;
  c12_cb_b = c12_bb_b;
  if (1 > c12_cb_b) {
    c12_c_overflow = false;
  } else {
    c12_c_overflow = (c12_cb_b > 2147483646);
  }

  if (c12_c_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_c_k = 0; c12_c_k < c12_nx; c12_c_k++) {
    c12_nb_x = c12_c_varargin_1->data[c12_c_k];
    c12_w_y = c12_b_varargin_2->data[c12_c_k];
    c12_ob_x = c12_nb_x;
    c12_x_y = c12_w_y;
    c12_ex = muDoubleScalarMax(c12_ob_x, c12_x_y);
    c12_maxxy->data[c12_c_k] = c12_ex;
  }

  c12_abs(chartInstance, c12_r_x, c12_c_varargin_1);
  c12_abs(chartInstance, c12_j_y, c12_b_varargin_2);
  c12_b_sak = c12_c_varargin_1->size[0];
  c12_b_sbk = c12_b_varargin_2->size[0];
  c12_db_a = c12_b_sak;
  c12_db_b = c12_b_sbk;
  if (c12_db_a <= c12_db_b) {
    c12_q_c = c12_db_a;
  } else {
    c12_q_c = c12_db_b;
  }

  c12_b_csz[0] = c12_q_c;
  c12_b_sak = c12_c_varargin_1->size[1];
  c12_b_sbk = c12_b_varargin_2->size[1];
  c12_eb_a = c12_b_sak;
  c12_eb_b = c12_b_sbk;
  if (c12_eb_a <= c12_eb_b) {
    c12_r_c = c12_eb_a;
  } else {
    c12_r_c = c12_eb_b;
  }

  c12_b_csz[1] = c12_r_c;
  c12_i292 = c12_ztemp->size[0] * c12_ztemp->size[1];
  c12_ztemp->size[0] = c12_b_csz[0];
  c12_ztemp->size[1] = c12_b_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_ztemp, c12_i292,
    &c12_xc_emlrtRTEI);
  c12_i293 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_ztemp->size[0];
  c12_r6->size[1] = c12_ztemp->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i293,
    &c12_xc_emlrtRTEI);
  for (c12_i294 = 0; c12_i294 < 2; c12_i294++) {
    c12_csz[c12_i294] = c12_r6->size[c12_i294];
  }

  c12_i295 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_csz[0];
  c12_r6->size[1] = c12_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i295,
    &c12_yc_emlrtRTEI);
  for (c12_i296 = 0; c12_i296 < 2; c12_i296++) {
    c12_csz[c12_i296] = c12_r6->size[c12_i296];
  }

  c12_emxInit_real_T(chartInstance, &c12_r8, 2, &c12_bd_emlrtRTEI);
  c12_i297 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_csz[0];
  c12_r6->size[1] = c12_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i297,
    &c12_ad_emlrtRTEI);
  c12_i298 = c12_r8->size[0] * c12_r8->size[1];
  c12_r8->size[0] = c12_r6->size[0];
  c12_r8->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r8, c12_i298,
    &c12_bd_emlrtRTEI);
  c12_i299 = c12_r8->size[0];
  c12_i300 = c12_r8->size[1];
  c12_h_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i301 = 0; c12_i301 <= c12_h_loop_ub; c12_i301++) {
    c12_r8->data[c12_i301] = c12_r6->data[c12_i301];
  }

  c12_emxInit_real_T(chartInstance, &c12_g_varargin_1, 2, &c12_cd_emlrtRTEI);
  c12_i302 = c12_g_varargin_1->size[0] * c12_g_varargin_1->size[1];
  c12_g_varargin_1->size[0] = c12_c_varargin_1->size[0];
  c12_g_varargin_1->size[1] = c12_c_varargin_1->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_g_varargin_1, c12_i302,
    &c12_cd_emlrtRTEI);
  c12_h_varargin_1 = c12_g_varargin_1->size[0];
  c12_i_varargin_1 = c12_g_varargin_1->size[1];
  c12_i_loop_ub = c12_c_varargin_1->size[0] * c12_c_varargin_1->size[1] - 1;
  for (c12_i303 = 0; c12_i303 <= c12_i_loop_ub; c12_i303++) {
    c12_g_varargin_1->data[c12_i303] = c12_c_varargin_1->data[c12_i303];
  }

  c12_emxInit_real_T(chartInstance, &c12_f_varargin_2, 2, &c12_cd_emlrtRTEI);
  c12_i304 = c12_f_varargin_2->size[0] * c12_f_varargin_2->size[1];
  c12_f_varargin_2->size[0] = c12_b_varargin_2->size[0];
  c12_f_varargin_2->size[1] = c12_b_varargin_2->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_f_varargin_2, c12_i304,
    &c12_cd_emlrtRTEI);
  c12_g_varargin_2 = c12_f_varargin_2->size[0];
  c12_h_varargin_2 = c12_f_varargin_2->size[1];
  c12_j_loop_ub = c12_b_varargin_2->size[0] * c12_b_varargin_2->size[1] - 1;
  for (c12_i305 = 0; c12_i305 <= c12_j_loop_ub; c12_i305++) {
    c12_f_varargin_2->data[c12_i305] = c12_b_varargin_2->data[c12_i305];
  }

  if (c12_dimagree(chartInstance, c12_r8, c12_g_varargin_1, c12_f_varargin_2)) {
  } else {
    c12_y_y = NULL;
    sf_mex_assign(&c12_y_y, sf_mex_create("y", c12_cv1, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    c12_ab_y = NULL;
    sf_mex_assign(&c12_ab_y, sf_mex_create("y", c12_cv1, 10, 0U, 1U, 0U, 2, 1,
      15), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c12_ab_y)));
  }

  c12_emxFree_real_T(chartInstance, &c12_f_varargin_2);
  c12_emxFree_real_T(chartInstance, &c12_g_varargin_1);
  c12_emxFree_real_T(chartInstance, &c12_r8);
  for (c12_i306 = 0; c12_i306 < 2; c12_i306++) {
    c12_csz[c12_i306] = c12_r6->size[c12_i306];
  }

  c12_emxInit_real_T(chartInstance, &c12_minxy, 2, &c12_ed_emlrtRTEI);
  c12_i307 = c12_minxy->size[0] * c12_minxy->size[1];
  c12_minxy->size[0] = c12_csz[0];
  c12_minxy->size[1] = c12_csz[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_minxy, c12_i307,
    &c12_ed_emlrtRTEI);
  c12_b_nx = c12_minxy->size[0] * c12_minxy->size[1];
  c12_fb_b = c12_b_nx;
  c12_gb_b = c12_fb_b;
  if (1 > c12_gb_b) {
    c12_d_overflow = false;
  } else {
    c12_d_overflow = (c12_gb_b > 2147483646);
  }

  if (c12_d_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_d_k = 0; c12_d_k < c12_b_nx; c12_d_k++) {
    c12_pb_x = c12_c_varargin_1->data[c12_d_k];
    c12_bb_y = c12_b_varargin_2->data[c12_d_k];
    c12_qb_x = c12_pb_x;
    c12_cb_y = c12_bb_y;
    c12_b_ex = muDoubleScalarMin(c12_qb_x, c12_cb_y);
    c12_minxy->data[c12_d_k] = c12_b_ex;
  }

  c12_emxFree_real_T(chartInstance, &c12_b_varargin_2);
  c12_emxFree_real_T(chartInstance, &c12_c_varargin_1);
  c12_emxInit_real_T(chartInstance, &c12_b_maxxy, 2, &c12_fd_emlrtRTEI);
  c12_i308 = c12_b_maxxy->size[0] * c12_b_maxxy->size[1];
  c12_b_maxxy->size[0] = c12_maxxy->size[0];
  c12_b_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_b_maxxy, c12_i308,
    &c12_fd_emlrtRTEI);
  c12_c_maxxy = c12_b_maxxy->size[0];
  c12_d_maxxy = c12_b_maxxy->size[1];
  c12_k_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i309 = 0; c12_i309 <= c12_k_loop_ub; c12_i309++) {
    c12_b_maxxy->data[c12_i309] = c12_maxxy->data[c12_i309] + 0.5;
  }

  c12_emxInit_real_T(chartInstance, &c12_b_minxy, 2, &c12_gd_emlrtRTEI);
  c12_power(chartInstance, c12_b_maxxy, c12_r6);
  c12_i310 = c12_b_minxy->size[0] * c12_b_minxy->size[1];
  c12_b_minxy->size[0] = c12_minxy->size[0];
  c12_b_minxy->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_b_minxy, c12_i310,
    &c12_gd_emlrtRTEI);
  c12_c_minxy = c12_b_minxy->size[0];
  c12_d_minxy = c12_b_minxy->size[1];
  c12_l_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_b_maxxy);
  for (c12_i311 = 0; c12_i311 <= c12_l_loop_ub; c12_i311++) {
    c12_b_minxy->data[c12_i311] = c12_minxy->data[c12_i311] - 0.5;
  }

  c12_power(chartInstance, c12_b_minxy, c12_r_x);
  c12_emxFree_real_T(chartInstance, &c12_b_minxy);
  for (c12_i312 = 0; c12_i312 < 2; c12_i312++) {
    c12_iv3[c12_i312] = c12_r6->size[c12_i312];
  }

  for (c12_i313 = 0; c12_i313 < 2; c12_i313++) {
    c12_rb_x[c12_i313] = c12_r_x->size[c12_i313];
  }

  c12_emxInit_boolean_T(chartInstance, &c12_r9, 2, &c12_ef_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c12_iv3, c12_rb_x, 2);
  c12_fb_a = c12_varargin_2;
  c12_gb_a = c12_fb_a;
  c12_hb_a = c12_gb_a;
  c12_sb_x = c12_hb_a;
  c12_ib_a = c12_sb_x;
  c12_s_c = c12_ib_a * c12_ib_a;
  c12_i314 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0] = c12_r6->size[0];
  c12_r9->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i314,
    &c12_hd_emlrtRTEI);
  c12_i315 = c12_r9->size[0];
  c12_i316 = c12_r9->size[1];
  c12_m_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i317 = 0; c12_i317 <= c12_m_loop_ub; c12_i317++) {
    c12_r9->data[c12_i317] = (c12_s_c >= c12_r6->data[c12_i317] + c12_r_x->
      data[c12_i317]);
  }

  c12_emxInit_real_T(chartInstance, &c12_e_maxxy, 2, &c12_id_emlrtRTEI);
  c12_jb_a = c12_varargin_2;
  c12_kb_a = c12_jb_a;
  c12_lb_a = c12_kb_a;
  c12_tb_x = c12_lb_a;
  c12_mb_a = c12_tb_x;
  c12_t_c = c12_mb_a * c12_mb_a;
  c12_i318 = c12_e_maxxy->size[0] * c12_e_maxxy->size[1];
  c12_e_maxxy->size[0] = c12_maxxy->size[0];
  c12_e_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_e_maxxy, c12_i318,
    &c12_id_emlrtRTEI);
  c12_f_maxxy = c12_e_maxxy->size[0];
  c12_g_maxxy = c12_e_maxxy->size[1];
  c12_n_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i319 = 0; c12_i319 <= c12_n_loop_ub; c12_i319++) {
    c12_e_maxxy->data[c12_i319] = c12_maxxy->data[c12_i319] + 0.5;
  }

  c12_emxInit_creal_T(chartInstance, &c12_m1c, 2, &c12_kd_emlrtRTEI);
  c12_power(chartInstance, c12_e_maxxy, c12_r6);
  c12_i320 = c12_m1c->size[0] * c12_m1c->size[1];
  c12_m1c->size[0] = c12_r6->size[0];
  c12_m1c->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_m1c, c12_i320,
    &c12_jd_emlrtRTEI);
  c12_b_m1c = c12_m1c->size[0];
  c12_c_m1c = c12_m1c->size[1];
  c12_o_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_e_maxxy);
  for (c12_i321 = 0; c12_i321 <= c12_o_loop_ub; c12_i321++) {
    c12_m1c->data[c12_i321].re = c12_t_c - c12_r6->data[c12_i321];
    c12_m1c->data[c12_i321].im = 0.0;
  }

  c12_d_sqrt(chartInstance, c12_m1c);
  for (c12_i322 = 0; c12_i322 < 2; c12_i322++) {
    c12_iv4[c12_i322] = c12_r9->size[c12_i322];
  }

  for (c12_i323 = 0; c12_i323 < 2; c12_i323++) {
    c12_d_m1c[c12_i323] = c12_m1c->size[c12_i323];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv4, c12_d_m1c, 2);
  c12_i324 = c12_r9->size[0] * c12_r9->size[1];
  c12_i325 = c12_m1c->size[0] * c12_m1c->size[1];
  c12_i326 = c12_m1c->size[0] * c12_m1c->size[1];
  c12_m1c->size[0] = c12_r9->size[0];
  c12_m1c->size[1] = c12_r9->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_m1c, c12_i326,
    &c12_kd_emlrtRTEI);
  c12_e_m1c = c12_m1c->size[0];
  c12_f_m1c = c12_m1c->size[1];
  c12_p_loop_ub = c12_i324 - 1;
  for (c12_i327 = 0; c12_i327 <= c12_p_loop_ub; c12_i327++) {
    c12_m1c->data[c12_i327].re *= (real_T)c12_r9->data[c12_i327];
    c12_m1c->data[c12_i327].im *= (real_T)c12_r9->data[c12_i327];
  }

  c12_emxInit_real_T(chartInstance, &c12_h_maxxy, 2, &c12_ld_emlrtRTEI);
  c12_i328 = c12_h_maxxy->size[0] * c12_h_maxxy->size[1];
  c12_h_maxxy->size[0] = c12_maxxy->size[0];
  c12_h_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_h_maxxy, c12_i328,
    &c12_ld_emlrtRTEI);
  c12_i_maxxy = c12_h_maxxy->size[0];
  c12_j_maxxy = c12_h_maxxy->size[1];
  c12_q_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i329 = 0; c12_i329 <= c12_q_loop_ub; c12_i329++) {
    c12_h_maxxy->data[c12_i329] = c12_maxxy->data[c12_i329] + 0.5;
  }

  c12_emxInit_real_T(chartInstance, &c12_e_minxy, 2, &c12_md_emlrtRTEI);
  c12_power(chartInstance, c12_h_maxxy, c12_r6);
  c12_i330 = c12_e_minxy->size[0] * c12_e_minxy->size[1];
  c12_e_minxy->size[0] = c12_minxy->size[0];
  c12_e_minxy->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_e_minxy, c12_i330,
    &c12_md_emlrtRTEI);
  c12_f_minxy = c12_e_minxy->size[0];
  c12_g_minxy = c12_e_minxy->size[1];
  c12_r_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_h_maxxy);
  for (c12_i331 = 0; c12_i331 <= c12_r_loop_ub; c12_i331++) {
    c12_e_minxy->data[c12_i331] = c12_minxy->data[c12_i331] - 0.5;
  }

  c12_power(chartInstance, c12_e_minxy, c12_r_x);
  c12_emxFree_real_T(chartInstance, &c12_e_minxy);
  for (c12_i332 = 0; c12_i332 < 2; c12_i332++) {
    c12_iv5[c12_i332] = c12_r6->size[c12_i332];
  }

  for (c12_i333 = 0; c12_i333 < 2; c12_i333++) {
    c12_ub_x[c12_i333] = c12_r_x->size[c12_i333];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv5, c12_ub_x, 2);
  c12_nb_a = c12_varargin_2;
  c12_ob_a = c12_nb_a;
  c12_pb_a = c12_ob_a;
  c12_vb_x = c12_pb_a;
  c12_qb_a = c12_vb_x;
  c12_u_c = c12_qb_a * c12_qb_a;
  c12_i334 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0] = c12_r6->size[0];
  c12_r9->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i334,
    &c12_nd_emlrtRTEI);
  c12_i335 = c12_r9->size[0];
  c12_i336 = c12_r9->size[1];
  c12_s_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i337 = 0; c12_i337 <= c12_s_loop_ub; c12_i337++) {
    c12_r9->data[c12_i337] = (c12_u_c < c12_r6->data[c12_i337] + c12_r_x->
      data[c12_i337]);
  }

  for (c12_i338 = 0; c12_i338 < 2; c12_i338++) {
    c12_iv6[c12_i338] = c12_r9->size[c12_i338];
  }

  for (c12_i339 = 0; c12_i339 < 2; c12_i339++) {
    c12_h_minxy[c12_i339] = c12_minxy->size[c12_i339];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv6, c12_h_minxy, 2);
  c12_i340 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_r9->size[0];
  c12_r6->size[1] = c12_r9->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i340,
    &c12_od_emlrtRTEI);
  c12_i341 = c12_r6->size[0];
  c12_i342 = c12_r6->size[1];
  c12_t_loop_ub = c12_r9->size[0] * c12_r9->size[1] - 1;
  for (c12_i343 = 0; c12_i343 <= c12_t_loop_ub; c12_i343++) {
    c12_r6->data[c12_i343] = (real_T)c12_r9->data[c12_i343] * (c12_minxy->
      data[c12_i343] - 0.5);
  }

  for (c12_i344 = 0; c12_i344 < 2; c12_i344++) {
    c12_iv7[c12_i344] = c12_r6->size[c12_i344];
  }

  for (c12_i345 = 0; c12_i345 < 2; c12_i345++) {
    c12_g_m1c[c12_i345] = c12_m1c->size[c12_i345];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv7, c12_g_m1c, 2);
  c12_i346 = c12_r6->size[0] * c12_r6->size[1];
  c12_i347 = c12_m1c->size[0] * c12_m1c->size[1];
  c12_i348 = c12_m1c->size[0] * c12_m1c->size[1];
  c12_m1c->size[0] = c12_r6->size[0];
  c12_m1c->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_m1c, c12_i348,
    &c12_pd_emlrtRTEI);
  c12_h_m1c = c12_m1c->size[0];
  c12_i_m1c = c12_m1c->size[1];
  c12_u_loop_ub = c12_i346 - 1;
  for (c12_i349 = 0; c12_i349 <= c12_u_loop_ub; c12_i349++) {
    c12_m1c->data[c12_i349].re += c12_r6->data[c12_i349];
    c12_m1c->data[c12_i349].im;
  }

  c12_emxInit_real_T(chartInstance, &c12_k_maxxy, 2, &c12_qd_emlrtRTEI);
  c12_i350 = c12_k_maxxy->size[0] * c12_k_maxxy->size[1];
  c12_k_maxxy->size[0] = c12_maxxy->size[0];
  c12_k_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_k_maxxy, c12_i350,
    &c12_qd_emlrtRTEI);
  c12_l_maxxy = c12_k_maxxy->size[0];
  c12_m_maxxy = c12_k_maxxy->size[1];
  c12_v_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i351 = 0; c12_i351 <= c12_v_loop_ub; c12_i351++) {
    c12_k_maxxy->data[c12_i351] = c12_maxxy->data[c12_i351] - 0.5;
  }

  c12_emxInit_real_T(chartInstance, &c12_i_minxy, 2, &c12_rd_emlrtRTEI);
  c12_power(chartInstance, c12_k_maxxy, c12_r6);
  c12_i352 = c12_i_minxy->size[0] * c12_i_minxy->size[1];
  c12_i_minxy->size[0] = c12_minxy->size[0];
  c12_i_minxy->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_i_minxy, c12_i352,
    &c12_rd_emlrtRTEI);
  c12_j_minxy = c12_i_minxy->size[0];
  c12_k_minxy = c12_i_minxy->size[1];
  c12_w_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_k_maxxy);
  for (c12_i353 = 0; c12_i353 <= c12_w_loop_ub; c12_i353++) {
    c12_i_minxy->data[c12_i353] = c12_minxy->data[c12_i353] + 0.5;
  }

  c12_power(chartInstance, c12_i_minxy, c12_r_x);
  c12_emxFree_real_T(chartInstance, &c12_i_minxy);
  for (c12_i354 = 0; c12_i354 < 2; c12_i354++) {
    c12_iv8[c12_i354] = c12_r6->size[c12_i354];
  }

  for (c12_i355 = 0; c12_i355 < 2; c12_i355++) {
    c12_wb_x[c12_i355] = c12_r_x->size[c12_i355];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv8, c12_wb_x, 2);
  c12_rb_a = c12_varargin_2;
  c12_sb_a = c12_rb_a;
  c12_tb_a = c12_sb_a;
  c12_xb_x = c12_tb_a;
  c12_ub_a = c12_xb_x;
  c12_v_c = c12_ub_a * c12_ub_a;
  c12_i356 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0] = c12_r6->size[0];
  c12_r9->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i356,
    &c12_sd_emlrtRTEI);
  c12_i357 = c12_r9->size[0];
  c12_i358 = c12_r9->size[1];
  c12_x_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i359 = 0; c12_i359 <= c12_x_loop_ub; c12_i359++) {
    c12_r9->data[c12_i359] = (c12_v_c <= c12_r6->data[c12_i359] + c12_r_x->
      data[c12_i359]);
  }

  c12_emxInit_real_T(chartInstance, &c12_n_maxxy, 2, &c12_td_emlrtRTEI);
  c12_vb_a = c12_varargin_2;
  c12_wb_a = c12_vb_a;
  c12_xb_a = c12_wb_a;
  c12_yb_x = c12_xb_a;
  c12_yb_a = c12_yb_x;
  c12_w_c = c12_yb_a * c12_yb_a;
  c12_i360 = c12_n_maxxy->size[0] * c12_n_maxxy->size[1];
  c12_n_maxxy->size[0] = c12_maxxy->size[0];
  c12_n_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_n_maxxy, c12_i360,
    &c12_td_emlrtRTEI);
  c12_o_maxxy = c12_n_maxxy->size[0];
  c12_p_maxxy = c12_n_maxxy->size[1];
  c12_y_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i361 = 0; c12_i361 <= c12_y_loop_ub; c12_i361++) {
    c12_n_maxxy->data[c12_i361] = c12_maxxy->data[c12_i361] - 0.5;
  }

  c12_emxInit_creal_T(chartInstance, &c12_m2c, 2, &c12_vd_emlrtRTEI);
  c12_power(chartInstance, c12_n_maxxy, c12_r6);
  c12_i362 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_m2c->size[0] = c12_r6->size[0];
  c12_m2c->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_m2c, c12_i362,
    &c12_ud_emlrtRTEI);
  c12_b_m2c = c12_m2c->size[0];
  c12_c_m2c = c12_m2c->size[1];
  c12_ab_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_n_maxxy);
  for (c12_i363 = 0; c12_i363 <= c12_ab_loop_ub; c12_i363++) {
    c12_m2c->data[c12_i363].re = c12_w_c - c12_r6->data[c12_i363];
    c12_m2c->data[c12_i363].im = 0.0;
  }

  c12_d_sqrt(chartInstance, c12_m2c);
  for (c12_i364 = 0; c12_i364 < 2; c12_i364++) {
    c12_iv9[c12_i364] = c12_r9->size[c12_i364];
  }

  for (c12_i365 = 0; c12_i365 < 2; c12_i365++) {
    c12_d_m2c[c12_i365] = c12_m2c->size[c12_i365];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv9, c12_d_m2c, 2);
  c12_i366 = c12_r9->size[0] * c12_r9->size[1];
  c12_i367 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_i368 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_m2c->size[0] = c12_r9->size[0];
  c12_m2c->size[1] = c12_r9->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_m2c, c12_i368,
    &c12_vd_emlrtRTEI);
  c12_e_m2c = c12_m2c->size[0];
  c12_f_m2c = c12_m2c->size[1];
  c12_bb_loop_ub = c12_i366 - 1;
  for (c12_i369 = 0; c12_i369 <= c12_bb_loop_ub; c12_i369++) {
    c12_m2c->data[c12_i369].re *= (real_T)c12_r9->data[c12_i369];
    c12_m2c->data[c12_i369].im *= (real_T)c12_r9->data[c12_i369];
  }

  c12_emxInit_real_T(chartInstance, &c12_q_maxxy, 2, &c12_wd_emlrtRTEI);
  c12_i370 = c12_q_maxxy->size[0] * c12_q_maxxy->size[1];
  c12_q_maxxy->size[0] = c12_maxxy->size[0];
  c12_q_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_q_maxxy, c12_i370,
    &c12_wd_emlrtRTEI);
  c12_r_maxxy = c12_q_maxxy->size[0];
  c12_s_maxxy = c12_q_maxxy->size[1];
  c12_cb_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i371 = 0; c12_i371 <= c12_cb_loop_ub; c12_i371++) {
    c12_q_maxxy->data[c12_i371] = c12_maxxy->data[c12_i371] - 0.5;
  }

  c12_emxInit_real_T(chartInstance, &c12_l_minxy, 2, &c12_xd_emlrtRTEI);
  c12_power(chartInstance, c12_q_maxxy, c12_r6);
  c12_i372 = c12_l_minxy->size[0] * c12_l_minxy->size[1];
  c12_l_minxy->size[0] = c12_minxy->size[0];
  c12_l_minxy->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_l_minxy, c12_i372,
    &c12_xd_emlrtRTEI);
  c12_m_minxy = c12_l_minxy->size[0];
  c12_n_minxy = c12_l_minxy->size[1];
  c12_db_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_q_maxxy);
  for (c12_i373 = 0; c12_i373 <= c12_db_loop_ub; c12_i373++) {
    c12_l_minxy->data[c12_i373] = c12_minxy->data[c12_i373] + 0.5;
  }

  c12_power(chartInstance, c12_l_minxy, c12_r_x);
  c12_emxFree_real_T(chartInstance, &c12_l_minxy);
  for (c12_i374 = 0; c12_i374 < 2; c12_i374++) {
    c12_iv10[c12_i374] = c12_r6->size[c12_i374];
  }

  for (c12_i375 = 0; c12_i375 < 2; c12_i375++) {
    c12_ac_x[c12_i375] = c12_r_x->size[c12_i375];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv10, c12_ac_x, 2);
  c12_ac_a = c12_varargin_2;
  c12_bc_a = c12_ac_a;
  c12_cc_a = c12_bc_a;
  c12_bc_x = c12_cc_a;
  c12_dc_a = c12_bc_x;
  c12_x_c = c12_dc_a * c12_dc_a;
  c12_i376 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0] = c12_r6->size[0];
  c12_r9->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i376,
    &c12_yd_emlrtRTEI);
  c12_i377 = c12_r9->size[0];
  c12_i378 = c12_r9->size[1];
  c12_eb_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i379 = 0; c12_i379 <= c12_eb_loop_ub; c12_i379++) {
    c12_r9->data[c12_i379] = (c12_x_c > c12_r6->data[c12_i379] + c12_r_x->
      data[c12_i379]);
  }

  for (c12_i380 = 0; c12_i380 < 2; c12_i380++) {
    c12_iv11[c12_i380] = c12_r9->size[c12_i380];
  }

  for (c12_i381 = 0; c12_i381 < 2; c12_i381++) {
    c12_o_minxy[c12_i381] = c12_minxy->size[c12_i381];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv11, c12_o_minxy, 2);
  c12_i382 = c12_r6->size[0] * c12_r6->size[1];
  c12_r6->size[0] = c12_r9->size[0];
  c12_r6->size[1] = c12_r9->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r6, c12_i382,
    &c12_ae_emlrtRTEI);
  c12_i383 = c12_r6->size[0];
  c12_i384 = c12_r6->size[1];
  c12_fb_loop_ub = c12_r9->size[0] * c12_r9->size[1] - 1;
  for (c12_i385 = 0; c12_i385 <= c12_fb_loop_ub; c12_i385++) {
    c12_r6->data[c12_i385] = (real_T)c12_r9->data[c12_i385] * (c12_minxy->
      data[c12_i385] + 0.5);
  }

  for (c12_i386 = 0; c12_i386 < 2; c12_i386++) {
    c12_iv12[c12_i386] = c12_r6->size[c12_i386];
  }

  for (c12_i387 = 0; c12_i387 < 2; c12_i387++) {
    c12_g_m2c[c12_i387] = c12_m2c->size[c12_i387];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv12, c12_g_m2c, 2);
  c12_i388 = c12_r6->size[0] * c12_r6->size[1];
  c12_i389 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_i390 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_m2c->size[0] = c12_r6->size[0];
  c12_m2c->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_m2c, c12_i390,
    &c12_be_emlrtRTEI);
  c12_h_m2c = c12_m2c->size[0];
  c12_i_m2c = c12_m2c->size[1];
  c12_gb_loop_ub = c12_i388 - 1;
  for (c12_i391 = 0; c12_i391 <= c12_gb_loop_ub; c12_i391++) {
    c12_m2c->data[c12_i391].re += c12_r6->data[c12_i391];
    c12_m2c->data[c12_i391].im;
  }

  c12_B = c12_varargin_2;
  c12_db_y = c12_B;
  c12_eb_y = c12_db_y;
  c12_i392 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0] = c12_m2c->size[0];
  c12_b_h->size[1] = c12_m2c->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i392,
    &c12_ce_emlrtRTEI);
  c12_c_h = c12_b_h->size[0];
  c12_d_h = c12_b_h->size[1];
  c12_hb_loop_ub = c12_m2c->size[0] * c12_m2c->size[1] - 1;
  for (c12_i393 = 0; c12_i393 <= c12_hb_loop_ub; c12_i393++) {
    c12_j_m2c = c12_m2c->data[c12_i393];
    c12_gb_y.re = c12_eb_y;
    c12_gb_y.im = 0.0;
    c12_ar = c12_j_m2c.re;
    c12_ai = c12_j_m2c.im;
    c12_br = c12_gb_y.re;
    c12_bi = c12_gb_y.im;
    if (c12_bi == 0.0) {
      if (c12_ai == 0.0) {
        c12_b_h->data[c12_i393].re = c12_ar / c12_br;
        c12_b_h->data[c12_i393].im = 0.0;
      } else if (c12_ar == 0.0) {
        c12_b_h->data[c12_i393].re = 0.0;
        c12_b_h->data[c12_i393].im = c12_ai / c12_br;
      } else {
        c12_b_h->data[c12_i393].re = c12_ar / c12_br;
        c12_b_h->data[c12_i393].im = c12_ai / c12_br;
      }
    } else if (c12_br == 0.0) {
      if (c12_ar == 0.0) {
        c12_b_h->data[c12_i393].re = c12_ai / c12_bi;
        c12_b_h->data[c12_i393].im = 0.0;
      } else if (c12_ai == 0.0) {
        c12_b_h->data[c12_i393].re = 0.0;
        c12_b_h->data[c12_i393].im = -(c12_ar / c12_bi);
      } else {
        c12_b_h->data[c12_i393].re = c12_ai / c12_bi;
        c12_b_h->data[c12_i393].im = -(c12_ar / c12_bi);
      }
    } else {
      c12_brm = muDoubleScalarAbs(c12_br);
      c12_bim = muDoubleScalarAbs(c12_bi);
      if (c12_brm > c12_bim) {
        c12_s = c12_bi / c12_br;
        c12_c_d = c12_br + c12_s * c12_bi;
        c12_nr = c12_ar + c12_s * c12_ai;
        c12_ni = c12_ai - c12_s * c12_ar;
        c12_b_h->data[c12_i393].re = c12_nr / c12_c_d;
        c12_b_h->data[c12_i393].im = c12_ni / c12_c_d;
      } else if (c12_bim == c12_brm) {
        if (c12_br > 0.0) {
          c12_sgnbr = 0.5;
        } else {
          c12_sgnbr = -0.5;
        }

        if (c12_bi > 0.0) {
          c12_sgnbi = 0.5;
        } else {
          c12_sgnbi = -0.5;
        }

        c12_nr = c12_ar * c12_sgnbr + c12_ai * c12_sgnbi;
        c12_ni = c12_ai * c12_sgnbr - c12_ar * c12_sgnbi;
        c12_b_h->data[c12_i393].re = c12_nr / c12_brm;
        c12_b_h->data[c12_i393].im = c12_ni / c12_brm;
      } else {
        c12_s = c12_br / c12_bi;
        c12_c_d = c12_bi + c12_s * c12_br;
        c12_nr = c12_s * c12_ar + c12_ai;
        c12_ni = c12_s * c12_ai - c12_ar;
        c12_b_h->data[c12_i393].re = c12_nr / c12_c_d;
        c12_b_h->data[c12_i393].im = c12_ni / c12_c_d;
      }
    }
  }

  c12_emxInit_creal_T(chartInstance, &c12_fb_y, 2, &c12_kf_emlrtRTEI);
  c12_c_asin(chartInstance, c12_b_h);
  c12_b_B = c12_varargin_2;
  c12_hb_y = c12_b_B;
  c12_ib_y = c12_hb_y;
  c12_i394 = c12_fb_y->size[0] * c12_fb_y->size[1];
  c12_fb_y->size[0] = c12_m1c->size[0];
  c12_fb_y->size[1] = c12_m1c->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_fb_y, c12_i394,
    &c12_ce_emlrtRTEI);
  c12_jb_y = c12_fb_y->size[0];
  c12_kb_y = c12_fb_y->size[1];
  c12_ib_loop_ub = c12_m1c->size[0] * c12_m1c->size[1] - 1;
  for (c12_i395 = 0; c12_i395 <= c12_ib_loop_ub; c12_i395++) {
    c12_j_m1c = c12_m1c->data[c12_i395];
    c12_lb_y.re = c12_ib_y;
    c12_lb_y.im = 0.0;
    c12_b_ar = c12_j_m1c.re;
    c12_b_ai = c12_j_m1c.im;
    c12_b_br = c12_lb_y.re;
    c12_b_bi = c12_lb_y.im;
    if (c12_b_bi == 0.0) {
      if (c12_b_ai == 0.0) {
        c12_fb_y->data[c12_i395].re = c12_b_ar / c12_b_br;
        c12_fb_y->data[c12_i395].im = 0.0;
      } else if (c12_b_ar == 0.0) {
        c12_fb_y->data[c12_i395].re = 0.0;
        c12_fb_y->data[c12_i395].im = c12_b_ai / c12_b_br;
      } else {
        c12_fb_y->data[c12_i395].re = c12_b_ar / c12_b_br;
        c12_fb_y->data[c12_i395].im = c12_b_ai / c12_b_br;
      }
    } else if (c12_b_br == 0.0) {
      if (c12_b_ar == 0.0) {
        c12_fb_y->data[c12_i395].re = c12_b_ai / c12_b_bi;
        c12_fb_y->data[c12_i395].im = 0.0;
      } else if (c12_b_ai == 0.0) {
        c12_fb_y->data[c12_i395].re = 0.0;
        c12_fb_y->data[c12_i395].im = -(c12_b_ar / c12_b_bi);
      } else {
        c12_fb_y->data[c12_i395].re = c12_b_ai / c12_b_bi;
        c12_fb_y->data[c12_i395].im = -(c12_b_ar / c12_b_bi);
      }
    } else {
      c12_b_brm = muDoubleScalarAbs(c12_b_br);
      c12_b_bim = muDoubleScalarAbs(c12_b_bi);
      if (c12_b_brm > c12_b_bim) {
        c12_b_s = c12_b_bi / c12_b_br;
        c12_d_d = c12_b_br + c12_b_s * c12_b_bi;
        c12_b_nr = c12_b_ar + c12_b_s * c12_b_ai;
        c12_b_ni = c12_b_ai - c12_b_s * c12_b_ar;
        c12_fb_y->data[c12_i395].re = c12_b_nr / c12_d_d;
        c12_fb_y->data[c12_i395].im = c12_b_ni / c12_d_d;
      } else if (c12_b_bim == c12_b_brm) {
        if (c12_b_br > 0.0) {
          c12_b_sgnbr = 0.5;
        } else {
          c12_b_sgnbr = -0.5;
        }

        if (c12_b_bi > 0.0) {
          c12_b_sgnbi = 0.5;
        } else {
          c12_b_sgnbi = -0.5;
        }

        c12_b_nr = c12_b_ar * c12_b_sgnbr + c12_b_ai * c12_b_sgnbi;
        c12_b_ni = c12_b_ai * c12_b_sgnbr - c12_b_ar * c12_b_sgnbi;
        c12_fb_y->data[c12_i395].re = c12_b_nr / c12_b_brm;
        c12_fb_y->data[c12_i395].im = c12_b_ni / c12_b_brm;
      } else {
        c12_b_s = c12_b_br / c12_b_bi;
        c12_d_d = c12_b_bi + c12_b_s * c12_b_br;
        c12_b_nr = c12_b_s * c12_b_ar + c12_b_ai;
        c12_b_ni = c12_b_s * c12_b_ai - c12_b_ar;
        c12_fb_y->data[c12_i395].re = c12_b_nr / c12_d_d;
        c12_fb_y->data[c12_i395].im = c12_b_ni / c12_d_d;
      }
    }
  }

  c12_c_asin(chartInstance, c12_fb_y);
  for (c12_i396 = 0; c12_i396 < 2; c12_i396++) {
    c12_e_h[c12_i396] = c12_b_h->size[c12_i396];
  }

  for (c12_i397 = 0; c12_i397 < 2; c12_i397++) {
    c12_nb_y[c12_i397] = c12_fb_y->size[c12_i397];
  }

  c12_emxInit_creal_T(chartInstance, &c12_mb_y, 2, &c12_lf_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c12_e_h, c12_nb_y, 2);
  c12_c_B = c12_varargin_2;
  c12_ob_y = c12_c_B;
  c12_pb_y = c12_ob_y;
  c12_i398 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_mb_y->size[0] = c12_m2c->size[0];
  c12_mb_y->size[1] = c12_m2c->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_mb_y, c12_i398,
    &c12_ce_emlrtRTEI);
  c12_qb_y = c12_mb_y->size[0];
  c12_rb_y = c12_mb_y->size[1];
  c12_jb_loop_ub = c12_m2c->size[0] * c12_m2c->size[1] - 1;
  for (c12_i399 = 0; c12_i399 <= c12_jb_loop_ub; c12_i399++) {
    c12_k_m2c = c12_m2c->data[c12_i399];
    c12_sb_y.re = c12_pb_y;
    c12_sb_y.im = 0.0;
    c12_c_ar = c12_k_m2c.re;
    c12_c_ai = c12_k_m2c.im;
    c12_c_br = c12_sb_y.re;
    c12_c_bi = c12_sb_y.im;
    if (c12_c_bi == 0.0) {
      if (c12_c_ai == 0.0) {
        c12_mb_y->data[c12_i399].re = c12_c_ar / c12_c_br;
        c12_mb_y->data[c12_i399].im = 0.0;
      } else if (c12_c_ar == 0.0) {
        c12_mb_y->data[c12_i399].re = 0.0;
        c12_mb_y->data[c12_i399].im = c12_c_ai / c12_c_br;
      } else {
        c12_mb_y->data[c12_i399].re = c12_c_ar / c12_c_br;
        c12_mb_y->data[c12_i399].im = c12_c_ai / c12_c_br;
      }
    } else if (c12_c_br == 0.0) {
      if (c12_c_ar == 0.0) {
        c12_mb_y->data[c12_i399].re = c12_c_ai / c12_c_bi;
        c12_mb_y->data[c12_i399].im = 0.0;
      } else if (c12_c_ai == 0.0) {
        c12_mb_y->data[c12_i399].re = 0.0;
        c12_mb_y->data[c12_i399].im = -(c12_c_ar / c12_c_bi);
      } else {
        c12_mb_y->data[c12_i399].re = c12_c_ai / c12_c_bi;
        c12_mb_y->data[c12_i399].im = -(c12_c_ar / c12_c_bi);
      }
    } else {
      c12_c_brm = muDoubleScalarAbs(c12_c_br);
      c12_c_bim = muDoubleScalarAbs(c12_c_bi);
      if (c12_c_brm > c12_c_bim) {
        c12_c_s = c12_c_bi / c12_c_br;
        c12_e_d = c12_c_br + c12_c_s * c12_c_bi;
        c12_c_nr = c12_c_ar + c12_c_s * c12_c_ai;
        c12_c_ni = c12_c_ai - c12_c_s * c12_c_ar;
        c12_mb_y->data[c12_i399].re = c12_c_nr / c12_e_d;
        c12_mb_y->data[c12_i399].im = c12_c_ni / c12_e_d;
      } else if (c12_c_bim == c12_c_brm) {
        if (c12_c_br > 0.0) {
          c12_c_sgnbr = 0.5;
        } else {
          c12_c_sgnbr = -0.5;
        }

        if (c12_c_bi > 0.0) {
          c12_c_sgnbi = 0.5;
        } else {
          c12_c_sgnbi = -0.5;
        }

        c12_c_nr = c12_c_ar * c12_c_sgnbr + c12_c_ai * c12_c_sgnbi;
        c12_c_ni = c12_c_ai * c12_c_sgnbr - c12_c_ar * c12_c_sgnbi;
        c12_mb_y->data[c12_i399].re = c12_c_nr / c12_c_brm;
        c12_mb_y->data[c12_i399].im = c12_c_ni / c12_c_brm;
      } else {
        c12_c_s = c12_c_br / c12_c_bi;
        c12_e_d = c12_c_bi + c12_c_s * c12_c_br;
        c12_c_nr = c12_c_s * c12_c_ar + c12_c_ai;
        c12_c_ni = c12_c_s * c12_c_ai - c12_c_ar;
        c12_mb_y->data[c12_i399].re = c12_c_nr / c12_e_d;
        c12_mb_y->data[c12_i399].im = c12_c_ni / c12_e_d;
      }
    }
  }

  c12_c_asin(chartInstance, c12_mb_y);
  c12_i400 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_i401 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_mb_y->size[0];
  c12_mb_y->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_mb_y, c12_i401,
    &c12_de_emlrtRTEI);
  c12_tb_y = c12_mb_y->size[0];
  c12_ub_y = c12_mb_y->size[1];
  c12_kb_loop_ub = c12_i400 - 1;
  for (c12_i402 = 0; c12_i402 <= c12_kb_loop_ub; c12_i402++) {
    c12_mb_y->data[c12_i402].re *= 2.0;
    c12_mb_y->data[c12_i402].im *= 2.0;
  }

  c12_emxInit_creal_T(chartInstance, &c12_vb_y, 2, &c12_mf_emlrtRTEI);
  c12_d_sin(chartInstance, c12_mb_y);
  c12_d_B = c12_varargin_2;
  c12_wb_y = c12_d_B;
  c12_xb_y = c12_wb_y;
  c12_i403 = c12_vb_y->size[0] * c12_vb_y->size[1];
  c12_vb_y->size[0] = c12_m1c->size[0];
  c12_vb_y->size[1] = c12_m1c->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_vb_y, c12_i403,
    &c12_ce_emlrtRTEI);
  c12_yb_y = c12_vb_y->size[0];
  c12_ac_y = c12_vb_y->size[1];
  c12_lb_loop_ub = c12_m1c->size[0] * c12_m1c->size[1] - 1;
  for (c12_i404 = 0; c12_i404 <= c12_lb_loop_ub; c12_i404++) {
    c12_k_m1c = c12_m1c->data[c12_i404];
    c12_bc_y.re = c12_xb_y;
    c12_bc_y.im = 0.0;
    c12_d_ar = c12_k_m1c.re;
    c12_d_ai = c12_k_m1c.im;
    c12_d_br = c12_bc_y.re;
    c12_d_bi = c12_bc_y.im;
    if (c12_d_bi == 0.0) {
      if (c12_d_ai == 0.0) {
        c12_vb_y->data[c12_i404].re = c12_d_ar / c12_d_br;
        c12_vb_y->data[c12_i404].im = 0.0;
      } else if (c12_d_ar == 0.0) {
        c12_vb_y->data[c12_i404].re = 0.0;
        c12_vb_y->data[c12_i404].im = c12_d_ai / c12_d_br;
      } else {
        c12_vb_y->data[c12_i404].re = c12_d_ar / c12_d_br;
        c12_vb_y->data[c12_i404].im = c12_d_ai / c12_d_br;
      }
    } else if (c12_d_br == 0.0) {
      if (c12_d_ar == 0.0) {
        c12_vb_y->data[c12_i404].re = c12_d_ai / c12_d_bi;
        c12_vb_y->data[c12_i404].im = 0.0;
      } else if (c12_d_ai == 0.0) {
        c12_vb_y->data[c12_i404].re = 0.0;
        c12_vb_y->data[c12_i404].im = -(c12_d_ar / c12_d_bi);
      } else {
        c12_vb_y->data[c12_i404].re = c12_d_ai / c12_d_bi;
        c12_vb_y->data[c12_i404].im = -(c12_d_ar / c12_d_bi);
      }
    } else {
      c12_d_brm = muDoubleScalarAbs(c12_d_br);
      c12_d_bim = muDoubleScalarAbs(c12_d_bi);
      if (c12_d_brm > c12_d_bim) {
        c12_d_s = c12_d_bi / c12_d_br;
        c12_f_d = c12_d_br + c12_d_s * c12_d_bi;
        c12_d_nr = c12_d_ar + c12_d_s * c12_d_ai;
        c12_d_ni = c12_d_ai - c12_d_s * c12_d_ar;
        c12_vb_y->data[c12_i404].re = c12_d_nr / c12_f_d;
        c12_vb_y->data[c12_i404].im = c12_d_ni / c12_f_d;
      } else if (c12_d_bim == c12_d_brm) {
        if (c12_d_br > 0.0) {
          c12_d_sgnbr = 0.5;
        } else {
          c12_d_sgnbr = -0.5;
        }

        if (c12_d_bi > 0.0) {
          c12_d_sgnbi = 0.5;
        } else {
          c12_d_sgnbi = -0.5;
        }

        c12_d_nr = c12_d_ar * c12_d_sgnbr + c12_d_ai * c12_d_sgnbi;
        c12_d_ni = c12_d_ai * c12_d_sgnbr - c12_d_ar * c12_d_sgnbi;
        c12_vb_y->data[c12_i404].re = c12_d_nr / c12_d_brm;
        c12_vb_y->data[c12_i404].im = c12_d_ni / c12_d_brm;
      } else {
        c12_d_s = c12_d_br / c12_d_bi;
        c12_f_d = c12_d_bi + c12_d_s * c12_d_br;
        c12_d_nr = c12_d_s * c12_d_ar + c12_d_ai;
        c12_d_ni = c12_d_s * c12_d_ai - c12_d_ar;
        c12_vb_y->data[c12_i404].re = c12_d_nr / c12_f_d;
        c12_vb_y->data[c12_i404].im = c12_d_ni / c12_f_d;
      }
    }
  }

  c12_c_asin(chartInstance, c12_vb_y);
  c12_i405 = c12_vb_y->size[0] * c12_vb_y->size[1];
  c12_i406 = c12_vb_y->size[0] * c12_vb_y->size[1];
  c12_vb_y->size[0];
  c12_vb_y->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_vb_y, c12_i406,
    &c12_de_emlrtRTEI);
  c12_cc_y = c12_vb_y->size[0];
  c12_dc_y = c12_vb_y->size[1];
  c12_mb_loop_ub = c12_i405 - 1;
  for (c12_i407 = 0; c12_i407 <= c12_mb_loop_ub; c12_i407++) {
    c12_vb_y->data[c12_i407].re *= 2.0;
    c12_vb_y->data[c12_i407].im *= 2.0;
  }

  c12_d_sin(chartInstance, c12_vb_y);
  for (c12_i408 = 0; c12_i408 < 2; c12_i408++) {
    c12_ec_y[c12_i408] = c12_mb_y->size[c12_i408];
  }

  for (c12_i409 = 0; c12_i409 < 2; c12_i409++) {
    c12_fc_y[c12_i409] = c12_vb_y->size[c12_i409];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_ec_y, c12_fc_y, 2);
  c12_i410 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_i411 = c12_fb_y->size[0] * c12_fb_y->size[1];
  c12_i412 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0];
  c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i412,
    &c12_ee_emlrtRTEI);
  c12_f_h = c12_b_h->size[0];
  c12_g_h = c12_b_h->size[1];
  c12_nb_loop_ub = c12_i410 - 1;
  for (c12_i413 = 0; c12_i413 <= c12_nb_loop_ub; c12_i413++) {
    c12_b_h->data[c12_i413].re -= c12_fb_y->data[c12_i413].re;
    c12_b_h->data[c12_i413].im -= c12_fb_y->data[c12_i413].im;
  }

  c12_emxFree_creal_T(chartInstance, &c12_fb_y);
  c12_i414 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_i415 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0];
  c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i415,
    &c12_fe_emlrtRTEI);
  c12_h_h = c12_b_h->size[0];
  c12_i_h = c12_b_h->size[1];
  c12_ob_loop_ub = c12_i414 - 1;
  for (c12_i416 = 0; c12_i416 <= c12_ob_loop_ub; c12_i416++) {
    c12_b_h->data[c12_i416].re *= 0.5;
    c12_b_h->data[c12_i416].im *= 0.5;
  }

  c12_i417 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_i418 = c12_vb_y->size[0] * c12_vb_y->size[1];
  c12_i419 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_mb_y->size[0];
  c12_mb_y->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_mb_y, c12_i419,
    &c12_ge_emlrtRTEI);
  c12_gc_y = c12_mb_y->size[0];
  c12_hc_y = c12_mb_y->size[1];
  c12_pb_loop_ub = c12_i417 - 1;
  for (c12_i420 = 0; c12_i420 <= c12_pb_loop_ub; c12_i420++) {
    c12_mb_y->data[c12_i420].re -= c12_vb_y->data[c12_i420].re;
    c12_mb_y->data[c12_i420].im -= c12_vb_y->data[c12_i420].im;
  }

  c12_emxFree_creal_T(chartInstance, &c12_vb_y);
  c12_i421 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_i422 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_mb_y->size[0];
  c12_mb_y->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_mb_y, c12_i422,
    &c12_he_emlrtRTEI);
  c12_ic_y = c12_mb_y->size[0];
  c12_jc_y = c12_mb_y->size[1];
  c12_qb_loop_ub = c12_i421 - 1;
  for (c12_i423 = 0; c12_i423 <= c12_qb_loop_ub; c12_i423++) {
    c12_mb_y->data[c12_i423].re *= 0.25;
    c12_mb_y->data[c12_i423].im *= 0.25;
  }

  for (c12_i424 = 0; c12_i424 < 2; c12_i424++) {
    c12_j_h[c12_i424] = c12_b_h->size[c12_i424];
  }

  for (c12_i425 = 0; c12_i425 < 2; c12_i425++) {
    c12_kc_y[c12_i425] = c12_mb_y->size[c12_i425];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_j_h, c12_kc_y, 2);
  for (c12_i426 = 0; c12_i426 < 2; c12_i426++) {
    c12_l_m2c[c12_i426] = c12_m2c->size[c12_i426];
  }

  for (c12_i427 = 0; c12_i427 < 2; c12_i427++) {
    c12_l_m1c[c12_i427] = c12_m1c->size[c12_i427];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_l_m2c, c12_l_m1c, 2);
  for (c12_i428 = 0; c12_i428 < 2; c12_i428++) {
    c12_t_maxxy[c12_i428] = c12_maxxy->size[c12_i428];
  }

  for (c12_i429 = 0; c12_i429 < 2; c12_i429++) {
    c12_m_m2c[c12_i429] = c12_m2c->size[c12_i429];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_t_maxxy, c12_m_m2c, 2);
  c12_ec_a = c12_varargin_2;
  c12_fc_a = c12_ec_a;
  c12_gc_a = c12_fc_a;
  c12_cc_x = c12_gc_a;
  c12_hc_a = c12_cc_x;
  c12_y_c = c12_hc_a * c12_hc_a;
  c12_ic_a = c12_y_c;
  c12_i430 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_i431 = c12_mb_y->size[0] * c12_mb_y->size[1];
  c12_i432 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0];
  c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i432,
    &c12_fe_emlrtRTEI);
  c12_k_h = c12_b_h->size[0];
  c12_l_h = c12_b_h->size[1];
  c12_rb_loop_ub = c12_i430 - 1;
  for (c12_i433 = 0; c12_i433 <= c12_rb_loop_ub; c12_i433++) {
    c12_b_h->data[c12_i433].re += c12_mb_y->data[c12_i433].re;
    c12_b_h->data[c12_i433].im += c12_mb_y->data[c12_i433].im;
  }

  c12_emxFree_creal_T(chartInstance, &c12_mb_y);
  c12_i434 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_i435 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0];
  c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i435,
    &c12_ie_emlrtRTEI);
  c12_m_h = c12_b_h->size[0];
  c12_n_h = c12_b_h->size[1];
  c12_sb_loop_ub = c12_i434 - 1;
  for (c12_i436 = 0; c12_i436 <= c12_sb_loop_ub; c12_i436++) {
    c12_b_h->data[c12_i436].re *= c12_ic_a;
    c12_b_h->data[c12_i436].im *= c12_ic_a;
  }

  c12_i437 = c12_maxxy->size[0] * c12_maxxy->size[1];
  c12_i438 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_i439 = c12_m1c->size[0] * c12_m1c->size[1];
  c12_i440 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_m2c->size[0] = c12_maxxy->size[0];
  c12_m2c->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_m2c, c12_i440,
    &c12_je_emlrtRTEI);
  c12_n_m2c = c12_m2c->size[0];
  c12_o_m2c = c12_m2c->size[1];
  c12_tb_loop_ub = c12_i437 - 1;
  for (c12_i441 = 0; c12_i441 <= c12_tb_loop_ub; c12_i441++) {
    c12_p_m2c.re = c12_m2c->data[c12_i441].re - c12_m1c->data[c12_i441].re;
    c12_p_m2c.im = c12_m2c->data[c12_i441].im - c12_m1c->data[c12_i441].im;
    c12_m2c->data[c12_i441].re = (c12_maxxy->data[c12_i441] - 0.5) *
      c12_p_m2c.re;
    c12_m2c->data[c12_i441].im = (c12_maxxy->data[c12_i441] - 0.5) *
      c12_p_m2c.im;
  }

  for (c12_i442 = 0; c12_i442 < 2; c12_i442++) {
    c12_o_h[c12_i442] = c12_b_h->size[c12_i442];
  }

  for (c12_i443 = 0; c12_i443 < 2; c12_i443++) {
    c12_q_m2c[c12_i443] = c12_m2c->size[c12_i443];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_o_h, c12_q_m2c, 2);
  for (c12_i444 = 0; c12_i444 < 2; c12_i444++) {
    c12_m_m1c[c12_i444] = c12_m1c->size[c12_i444];
  }

  for (c12_i445 = 0; c12_i445 < 2; c12_i445++) {
    c12_p_minxy[c12_i445] = c12_minxy->size[c12_i445];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_m_m1c, c12_p_minxy, 2);
  for (c12_i446 = 0; c12_i446 < 2; c12_i446++) {
    c12_p_h[c12_i446] = c12_b_h->size[c12_i446];
  }

  for (c12_i447 = 0; c12_i447 < 2; c12_i447++) {
    c12_n_m1c[c12_i447] = c12_m1c->size[c12_i447];
  }

  c12_emxInit_real_T(chartInstance, &c12_u_maxxy, 2, &c12_ke_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c12_p_h, c12_n_m1c, 2);
  c12_i448 = c12_u_maxxy->size[0] * c12_u_maxxy->size[1];
  c12_u_maxxy->size[0] = c12_maxxy->size[0];
  c12_u_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_u_maxxy, c12_i448,
    &c12_ke_emlrtRTEI);
  c12_v_maxxy = c12_u_maxxy->size[0];
  c12_w_maxxy = c12_u_maxxy->size[1];
  c12_ub_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i449 = 0; c12_i449 <= c12_ub_loop_ub; c12_i449++) {
    c12_u_maxxy->data[c12_i449] = c12_maxxy->data[c12_i449] + 0.5;
  }

  c12_emxInit_real_T(chartInstance, &c12_q_minxy, 2, &c12_le_emlrtRTEI);
  c12_power(chartInstance, c12_u_maxxy, c12_r6);
  c12_i450 = c12_q_minxy->size[0] * c12_q_minxy->size[1];
  c12_q_minxy->size[0] = c12_minxy->size[0];
  c12_q_minxy->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_q_minxy, c12_i450,
    &c12_le_emlrtRTEI);
  c12_r_minxy = c12_q_minxy->size[0];
  c12_s_minxy = c12_q_minxy->size[1];
  c12_vb_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_u_maxxy);
  for (c12_i451 = 0; c12_i451 <= c12_vb_loop_ub; c12_i451++) {
    c12_q_minxy->data[c12_i451] = c12_minxy->data[c12_i451] + 0.5;
  }

  c12_power(chartInstance, c12_q_minxy, c12_r_x);
  c12_emxFree_real_T(chartInstance, &c12_q_minxy);
  for (c12_i452 = 0; c12_i452 < 2; c12_i452++) {
    c12_iv13[c12_i452] = c12_r6->size[c12_i452];
  }

  for (c12_i453 = 0; c12_i453 < 2; c12_i453++) {
    c12_dc_x[c12_i453] = c12_r_x->size[c12_i453];
  }

  c12_emxInit_real_T(chartInstance, &c12_x_maxxy, 2, &c12_me_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c12_iv13, c12_dc_x, 2);
  c12_i454 = c12_x_maxxy->size[0] * c12_x_maxxy->size[1];
  c12_x_maxxy->size[0] = c12_maxxy->size[0];
  c12_x_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_x_maxxy, c12_i454,
    &c12_me_emlrtRTEI);
  c12_y_maxxy = c12_x_maxxy->size[0];
  c12_ab_maxxy = c12_x_maxxy->size[1];
  c12_wb_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i455 = 0; c12_i455 <= c12_wb_loop_ub; c12_i455++) {
    c12_x_maxxy->data[c12_i455] = c12_maxxy->data[c12_i455] - 0.5;
  }

  c12_emxInit_real_T(chartInstance, &c12_t_minxy, 2, &c12_ne_emlrtRTEI);
  c12_power(chartInstance, c12_x_maxxy, c12_j_y);
  c12_i456 = c12_t_minxy->size[0] * c12_t_minxy->size[1];
  c12_t_minxy->size[0] = c12_minxy->size[0];
  c12_t_minxy->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_t_minxy, c12_i456,
    &c12_ne_emlrtRTEI);
  c12_u_minxy = c12_t_minxy->size[0];
  c12_v_minxy = c12_t_minxy->size[1];
  c12_xb_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_x_maxxy);
  for (c12_i457 = 0; c12_i457 <= c12_xb_loop_ub; c12_i457++) {
    c12_t_minxy->data[c12_i457] = c12_minxy->data[c12_i457] - 0.5;
  }

  c12_power(chartInstance, c12_t_minxy, c12_ztemp);
  c12_emxFree_real_T(chartInstance, &c12_t_minxy);
  for (c12_i458 = 0; c12_i458 < 2; c12_i458++) {
    c12_lc_y[c12_i458] = c12_j_y->size[c12_i458];
  }

  for (c12_i459 = 0; c12_i459 < 2; c12_i459++) {
    c12_b_ztemp[c12_i459] = c12_ztemp->size[c12_i459];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_lc_y, c12_b_ztemp, 2);
  c12_jc_a = c12_varargin_2;
  c12_kc_a = c12_jc_a;
  c12_lc_a = c12_kc_a;
  c12_ec_x = c12_lc_a;
  c12_mc_a = c12_ec_x;
  c12_ab_c = c12_mc_a * c12_mc_a;
  c12_i460 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0] = c12_r6->size[0];
  c12_r9->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i460,
    &c12_oe_emlrtRTEI);
  c12_i461 = c12_r9->size[0];
  c12_i462 = c12_r9->size[1];
  c12_yb_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i463 = 0; c12_i463 <= c12_yb_loop_ub; c12_i463++) {
    c12_r9->data[c12_i463] = (c12_ab_c < c12_r6->data[c12_i463] + c12_r_x->
      data[c12_i463]);
  }

  c12_emxInit_boolean_T(chartInstance, &c12_r10, 2, &c12_ef_emlrtRTEI);
  c12_nc_a = c12_varargin_2;
  c12_oc_a = c12_nc_a;
  c12_pc_a = c12_oc_a;
  c12_fc_x = c12_pc_a;
  c12_qc_a = c12_fc_x;
  c12_bb_c = c12_qc_a * c12_qc_a;
  c12_i464 = c12_r10->size[0] * c12_r10->size[1];
  c12_r10->size[0] = c12_j_y->size[0];
  c12_r10->size[1] = c12_j_y->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r10, c12_i464,
    &c12_pe_emlrtRTEI);
  c12_i465 = c12_r10->size[0];
  c12_i466 = c12_r10->size[1];
  c12_ac_loop_ub = c12_j_y->size[0] * c12_j_y->size[1] - 1;
  for (c12_i467 = 0; c12_i467 <= c12_ac_loop_ub; c12_i467++) {
    c12_r10->data[c12_i467] = (c12_bb_c > c12_j_y->data[c12_i467] +
      c12_ztemp->data[c12_i467]);
  }

  c12_emxFree_real_T(chartInstance, &c12_ztemp);
  c12_emxFree_real_T(chartInstance, &c12_j_y);
  for (c12_i468 = 0; c12_i468 < 2; c12_i468++) {
    c12_iv14[c12_i468] = c12_r9->size[c12_i468];
  }

  for (c12_i469 = 0; c12_i469 < 2; c12_i469++) {
    c12_iv15[c12_i469] = c12_r10->size[c12_i469];
  }

  c12_emxInit_boolean_T(chartInstance, &c12_r11, 2, &c12_ef_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c12_iv14, c12_iv15, 2);
  c12_i470 = c12_r11->size[0] * c12_r11->size[1];
  c12_r11->size[0] = c12_minxy->size[0];
  c12_r11->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r11, c12_i470,
    &c12_qe_emlrtRTEI);
  c12_i471 = c12_r11->size[0];
  c12_i472 = c12_r11->size[1];
  c12_bc_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  for (c12_i473 = 0; c12_i473 <= c12_bc_loop_ub; c12_i473++) {
    c12_r11->data[c12_i473] = (c12_minxy->data[c12_i473] == 0.0);
  }

  c12_emxInit_boolean_T(chartInstance, &c12_r12, 2, &c12_ef_emlrtRTEI);
  c12_i474 = c12_r12->size[0] * c12_r12->size[1];
  c12_r12->size[0] = c12_maxxy->size[0];
  c12_r12->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r12, c12_i474,
    &c12_re_emlrtRTEI);
  c12_i475 = c12_r12->size[0];
  c12_i476 = c12_r12->size[1];
  c12_cc_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i477 = 0; c12_i477 <= c12_cc_loop_ub; c12_i477++) {
    c12_r12->data[c12_i477] = (c12_maxxy->data[c12_i477] - 0.5 < c12_varargin_2);
  }

  for (c12_i478 = 0; c12_i478 < 2; c12_i478++) {
    c12_iv16[c12_i478] = c12_r11->size[c12_i478];
  }

  for (c12_i479 = 0; c12_i479 < 2; c12_i479++) {
    c12_iv17[c12_i479] = c12_r12->size[c12_i479];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv16, c12_iv17, 2);
  c12_i480 = c12_r11->size[0] * c12_r11->size[1];
  c12_i481 = c12_r12->size[0] * c12_r12->size[1];
  c12_i482 = c12_r11->size[0] * c12_r11->size[1];
  c12_r11->size[0];
  c12_r11->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r11, c12_i482,
    &c12_se_emlrtRTEI);
  c12_i483 = c12_r11->size[0];
  c12_i484 = c12_r11->size[1];
  c12_dc_loop_ub = c12_i480 - 1;
  for (c12_i485 = 0; c12_i485 <= c12_dc_loop_ub; c12_i485++) {
    c12_r11->data[c12_i485] = (c12_r11->data[c12_i485] && c12_r12->data[c12_i485]);
  }

  c12_i486 = c12_r12->size[0] * c12_r12->size[1];
  c12_r12->size[0] = c12_maxxy->size[0];
  c12_r12->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r12, c12_i486,
    &c12_te_emlrtRTEI);
  c12_i487 = c12_r12->size[0];
  c12_i488 = c12_r12->size[1];
  c12_ec_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i489 = 0; c12_i489 <= c12_ec_loop_ub; c12_i489++) {
    c12_r12->data[c12_i489] = (c12_maxxy->data[c12_i489] + 0.5 >= c12_varargin_2);
  }

  for (c12_i490 = 0; c12_i490 < 2; c12_i490++) {
    c12_iv18[c12_i490] = c12_r11->size[c12_i490];
  }

  for (c12_i491 = 0; c12_i491 < 2; c12_i491++) {
    c12_iv19[c12_i491] = c12_r12->size[c12_i491];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv18, c12_iv19, 2);
  c12_i492 = c12_r9->size[0] * c12_r9->size[1];
  c12_i493 = c12_r10->size[0] * c12_r10->size[1];
  c12_i494 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0];
  c12_r9->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i494,
    &c12_ue_emlrtRTEI);
  c12_i495 = c12_r9->size[0];
  c12_i496 = c12_r9->size[1];
  c12_fc_loop_ub = c12_i492 - 1;
  for (c12_i497 = 0; c12_i497 <= c12_fc_loop_ub; c12_i497++) {
    c12_r9->data[c12_i497] = (c12_r9->data[c12_i497] && c12_r10->data[c12_i497]);
  }

  c12_emxFree_boolean_T(chartInstance, &c12_r10);
  c12_i498 = c12_r11->size[0] * c12_r11->size[1];
  c12_i499 = c12_r12->size[0] * c12_r12->size[1];
  c12_i500 = c12_r11->size[0] * c12_r11->size[1];
  c12_r11->size[0];
  c12_r11->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r11, c12_i500,
    &c12_se_emlrtRTEI);
  c12_i501 = c12_r11->size[0];
  c12_i502 = c12_r11->size[1];
  c12_gc_loop_ub = c12_i498 - 1;
  for (c12_i503 = 0; c12_i503 <= c12_gc_loop_ub; c12_i503++) {
    c12_r11->data[c12_i503] = (c12_r11->data[c12_i503] && c12_r12->data[c12_i503]);
  }

  c12_emxFree_boolean_T(chartInstance, &c12_r12);
  for (c12_i504 = 0; c12_i504 < 2; c12_i504++) {
    c12_iv20[c12_i504] = c12_r9->size[c12_i504];
  }

  for (c12_i505 = 0; c12_i505 < 2; c12_i505++) {
    c12_iv21[c12_i505] = c12_r11->size[c12_i505];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv20, c12_iv21, 2);
  c12_i506 = c12_r9->size[0] * c12_r9->size[1];
  c12_i507 = c12_r11->size[0] * c12_r11->size[1];
  c12_i508 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0];
  c12_r9->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i508,
    &c12_ve_emlrtRTEI);
  c12_i509 = c12_r9->size[0];
  c12_i510 = c12_r9->size[1];
  c12_hc_loop_ub = c12_i506 - 1;
  for (c12_i511 = 0; c12_i511 <= c12_hc_loop_ub; c12_i511++) {
    c12_r9->data[c12_i511] = (c12_r9->data[c12_i511] || c12_r11->data[c12_i511]);
  }

  c12_emxFree_boolean_T(chartInstance, &c12_r11);
  for (c12_i512 = 0; c12_i512 < 2; c12_i512++) {
    c12_q_h[c12_i512] = c12_b_h->size[c12_i512];
  }

  for (c12_i513 = 0; c12_i513 < 2; c12_i513++) {
    c12_iv22[c12_i513] = c12_r9->size[c12_i513];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_q_h, c12_iv22, 2);
  c12_i514 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_i515 = c12_m2c->size[0] * c12_m2c->size[1];
  c12_i516 = c12_m1c->size[0] * c12_m1c->size[1];
  c12_i517 = c12_minxy->size[0] * c12_minxy->size[1];
  c12_i518 = c12_r9->size[0] * c12_r9->size[1];
  c12_i519 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0];
  c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i519,
    &c12_we_emlrtRTEI);
  c12_r_h = c12_b_h->size[0];
  c12_s_h = c12_b_h->size[1];
  c12_ic_loop_ub = c12_i514 - 1;
  for (c12_i520 = 0; c12_i520 <= c12_ic_loop_ub; c12_i520++) {
    c12_t_h.re = (c12_b_h->data[c12_i520].re - c12_m2c->data[c12_i520].re) +
      ((c12_m1c->data[c12_i520].re - c12_minxy->data[c12_i520]) + c12_dc3.re);
    c12_t_h.im = (c12_b_h->data[c12_i520].im - c12_m2c->data[c12_i520].im) +
      (c12_m1c->data[c12_i520].im + c12_dc3.im);
    c12_b_h->data[c12_i520].re = (real_T)c12_r9->data[c12_i520] * c12_t_h.re;
    c12_b_h->data[c12_i520].im = (real_T)c12_r9->data[c12_i520] * c12_t_h.im;
  }

  c12_emxFree_creal_T(chartInstance, &c12_m2c);
  c12_emxFree_creal_T(chartInstance, &c12_m1c);
  c12_emxInit_real_T(chartInstance, &c12_bb_maxxy, 2, &c12_xe_emlrtRTEI);
  c12_i521 = c12_bb_maxxy->size[0] * c12_bb_maxxy->size[1];
  c12_bb_maxxy->size[0] = c12_maxxy->size[0];
  c12_bb_maxxy->size[1] = c12_maxxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_bb_maxxy, c12_i521,
    &c12_xe_emlrtRTEI);
  c12_cb_maxxy = c12_bb_maxxy->size[0];
  c12_db_maxxy = c12_bb_maxxy->size[1];
  c12_jc_loop_ub = c12_maxxy->size[0] * c12_maxxy->size[1] - 1;
  for (c12_i522 = 0; c12_i522 <= c12_jc_loop_ub; c12_i522++) {
    c12_bb_maxxy->data[c12_i522] = c12_maxxy->data[c12_i522] + 0.5;
  }

  c12_emxFree_real_T(chartInstance, &c12_maxxy);
  c12_emxInit_real_T(chartInstance, &c12_w_minxy, 2, &c12_ye_emlrtRTEI);
  c12_power(chartInstance, c12_bb_maxxy, c12_r6);
  c12_i523 = c12_w_minxy->size[0] * c12_w_minxy->size[1];
  c12_w_minxy->size[0] = c12_minxy->size[0];
  c12_w_minxy->size[1] = c12_minxy->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_w_minxy, c12_i523,
    &c12_ye_emlrtRTEI);
  c12_x_minxy = c12_w_minxy->size[0];
  c12_y_minxy = c12_w_minxy->size[1];
  c12_kc_loop_ub = c12_minxy->size[0] * c12_minxy->size[1] - 1;
  c12_emxFree_real_T(chartInstance, &c12_bb_maxxy);
  for (c12_i524 = 0; c12_i524 <= c12_kc_loop_ub; c12_i524++) {
    c12_w_minxy->data[c12_i524] = c12_minxy->data[c12_i524] + 0.5;
  }

  c12_emxFree_real_T(chartInstance, &c12_minxy);
  c12_power(chartInstance, c12_w_minxy, c12_r_x);
  c12_emxFree_real_T(chartInstance, &c12_w_minxy);
  for (c12_i525 = 0; c12_i525 < 2; c12_i525++) {
    c12_iv23[c12_i525] = c12_r6->size[c12_i525];
  }

  for (c12_i526 = 0; c12_i526 < 2; c12_i526++) {
    c12_gc_x[c12_i526] = c12_r_x->size[c12_i526];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_iv23, c12_gc_x, 2);
  c12_rc_a = c12_varargin_2;
  c12_sc_a = c12_rc_a;
  c12_tc_a = c12_sc_a;
  c12_hc_x = c12_tc_a;
  c12_uc_a = c12_hc_x;
  c12_cb_c = c12_uc_a * c12_uc_a;
  c12_i527 = c12_r9->size[0] * c12_r9->size[1];
  c12_r9->size[0] = c12_r6->size[0];
  c12_r9->size[1] = c12_r6->size[1];
  c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r9, c12_i527,
    &c12_af_emlrtRTEI);
  c12_i528 = c12_r9->size[0];
  c12_i529 = c12_r9->size[1];
  c12_lc_loop_ub = c12_r6->size[0] * c12_r6->size[1] - 1;
  for (c12_i530 = 0; c12_i530 <= c12_lc_loop_ub; c12_i530++) {
    c12_r9->data[c12_i530] = (c12_r6->data[c12_i530] + c12_r_x->data[c12_i530] <
      c12_cb_c);
  }

  c12_emxFree_real_T(chartInstance, &c12_r6);
  c12_emxFree_real_T(chartInstance, &c12_r_x);
  for (c12_i531 = 0; c12_i531 < 2; c12_i531++) {
    c12_u_h[c12_i531] = c12_b_h->size[c12_i531];
  }

  for (c12_i532 = 0; c12_i532 < 2; c12_i532++) {
    c12_iv24[c12_i532] = c12_r9->size[c12_i532];
  }

  _SFD_SIZE_EQ_CHECK_ND(c12_u_h, c12_iv24, 2);
  c12_i533 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_i534 = c12_r9->size[0] * c12_r9->size[1];
  c12_i535 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0];
  c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i535,
    &c12_bf_emlrtRTEI);
  c12_v_h = c12_b_h->size[0];
  c12_w_h = c12_b_h->size[1];
  c12_mc_loop_ub = c12_i533 - 1;
  for (c12_i536 = 0; c12_i536 <= c12_mc_loop_ub; c12_i536++) {
    c12_b_h->data[c12_i536].re += (real_T)c12_r9->data[c12_i536];
    c12_b_h->data[c12_i536].im;
  }

  c12_emxFree_boolean_T(chartInstance, &c12_r9);
  c12_vc_a = c12_varargin_2;
  c12_wc_a = c12_vc_a;
  c12_xc_a = c12_wc_a;
  c12_ic_x = c12_xc_a;
  c12_yc_a = c12_ic_x;
  c12_db_c = c12_yc_a * c12_yc_a;
  c12_j_varargin_1 = 3.1415926535897931 * c12_db_c;
  c12_jc_x = c12_j_varargin_1;
  c12_kc_x = c12_jc_x;
  c12_lc_x = c12_kc_x;
  c12_mc_x = c12_lc_x;
  c12_nc_x = c12_mc_x;
  c12_oc_x = c12_nc_x;
  c12_minval = muDoubleScalarMin(c12_oc_x, 1.5707963267948966);
  c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1, c12_b_h->size[0]) +
                 c12_b_h->size[0] * (sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[1]) - 1)) - 1].re = c12_minval;
  c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1, c12_b_h->size[0]) +
                 c12_b_h->size[0] * (sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[1]) - 1)) - 1].im = 0.0;
  if ((c12_crad > 0.0) && (c12_varargin_2 > c12_crad - 0.5)) {
    c12_ad_a = c12_varargin_2;
    c12_bd_a = c12_ad_a;
    c12_cd_a = c12_bd_a;
    c12_pc_x = c12_cd_a;
    c12_dd_a = c12_pc_x;
    c12_eb_c = c12_dd_a * c12_dd_a;
    c12_ed_a = c12_crad - 0.5;
    c12_fd_a = c12_ed_a;
    c12_gd_a = c12_fd_a;
    c12_sc_x = c12_gd_a;
    c12_hd_a = c12_sc_x;
    c12_fb_c = c12_hd_a * c12_hd_a;
    if (c12_eb_c < c12_fb_c + 0.25) {
      c12_id_a = c12_varargin_2;
      c12_jd_a = c12_id_a;
      c12_kd_a = c12_jd_a;
      c12_yc_x = c12_kd_a;
      c12_ld_a = c12_yc_x;
      c12_gb_c = c12_ld_a * c12_ld_a;
      c12_md_a = c12_crad - 0.5;
      c12_nd_a = c12_md_a;
      c12_dd_x = c12_nd_a;
      c12_od_a = c12_dd_x;
      c12_rc_y = c12_od_a * c12_od_a;
      c12_hd_x = c12_gb_c - c12_rc_y;
      c12_m1 = c12_hd_x;
      c12_kd_x = c12_m1;
      if (c12_kd_x < 0.0) {
        c12_e_p = true;
      } else {
        c12_e_p = false;
      }

      c12_f_p = c12_e_p;
      if (c12_f_p) {
        c12_b_error(chartInstance);
      }

      c12_m1 = muDoubleScalarSqrt(c12_m1);
      c12_c_A = c12_m1;
      c12_e_B = c12_varargin_2;
      c12_sd_x = c12_c_A;
      c12_yc_y = c12_e_B;
      c12_td_x = c12_sd_x;
      c12_ad_y = c12_yc_y;
      c12_m1n = c12_td_x / c12_ad_y;
      c12_pd_a = c12_varargin_2;
      c12_qd_a = c12_pd_a;
      c12_rd_a = c12_qd_a;
      c12_ae_x = c12_rd_a;
      c12_sd_a = c12_ae_x;
      c12_hb_c = c12_sd_a * c12_sd_a;
      c12_de_x = c12_m1n;
      c12_ge_x = c12_de_x;
      c12_ie_x = c12_ge_x;
      c12_b14 = (c12_ie_x < -1.0);
      c12_b15 = (c12_ie_x > 1.0);
      if (c12_b14 || c12_b15) {
        c12_h_p = true;
      } else {
        c12_h_p = false;
      }

      c12_j_p = c12_h_p;
      if (c12_j_p) {
        c12_c_error(chartInstance);
      }

      c12_ge_x = muDoubleScalarAsin(c12_ge_x);
      c12_re_x = c12_m1n;
      c12_se_x = c12_re_x;
      c12_te_x = c12_se_x;
      c12_b16 = (c12_te_x < -1.0);
      c12_b17 = (c12_te_x > 1.0);
      if (c12_b16 || c12_b17) {
        c12_k_p = true;
      } else {
        c12_k_p = false;
      }

      c12_l_p = c12_k_p;
      if (c12_l_p) {
        c12_c_error(chartInstance);
      }

      c12_se_x = muDoubleScalarAsin(c12_se_x);
      c12_ve_x = 2.0 * c12_se_x;
      c12_we_x = c12_ve_x;
      c12_we_x = muDoubleScalarSin(c12_we_x);
      c12_sg0 = 2.0 * (c12_hb_c * (0.5 * c12_ge_x + 0.25 * c12_we_x) - c12_m1 *
                       (c12_crad - 0.5));
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(2.0 * c12_crad + 1.0),
        1, c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].re = c12_sg0;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(2.0 * c12_crad + 1.0),
        1, c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].im = 0.0;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(2.0 * c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].re =
        c12_sg0;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(2.0 * c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].im =
        0.0;
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c12_b_h->size[1]);
      c12_b_h->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) - 1].re = c12_sg0;
      c12_b_h->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) - 1].im = 0.0;
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c12_b_h->size[0]);
      c12_b_h->data[c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)].re = c12_sg0;
      c12_b_h->data[c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)].im = 0.0;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(2.0 * c12_crad), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].re =
        c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(2.0 * c12_crad), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].re - c12_sg0;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(2.0 * c12_crad), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].im =
        c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(2.0 * c12_crad), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)) - 1].im;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(2.0 * c12_crad), 1, c12_b_h->size[1]) - 1)) - 1].re =
        c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(2.0 * c12_crad), 1, c12_b_h->size[1]) - 1)) - 1].re - c12_sg0;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(2.0 * c12_crad), 1, c12_b_h->size[1]) - 1)) - 1].im =
        c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(2.0 * c12_crad), 1, c12_b_h->size[1]) - 1)) - 1].im;
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c12_b_h->size[1]);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c12_b_h->size[1]);
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0]) - 1].re = c12_b_h->data
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0),
           1, c12_b_h->size[0]) + c12_b_h->size[0]) - 1].re - c12_sg0;
      c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0), 1,
        c12_b_h->size[0]) + c12_b_h->size[0]) - 1].im = c12_b_h->data
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c12_crad + 1.0),
           1, c12_b_h->size[0]) + c12_b_h->size[0]) - 1].im;
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c12_b_h->size[0]);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c12_b_h->size[0]);
      c12_b_h->data[1 + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)].re =
        c12_b_h->data[1 + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)].re - c12_sg0;
      c12_b_h->data[1 + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)].im =
        c12_b_h->data[1 + c12_b_h->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c12_crad + 1.0), 1, c12_b_h->size[1]) - 1)].im;
    }
  }

  c12_k_varargin_1.re = c12_b_h->data[(sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[1]) - 1)) - 1].re;
  c12_k_varargin_1.im = c12_b_h->data[(sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[0]) + c12_b_h->size[0] * (sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[1]) - 1)) - 1].im;
  c12_b11 = muDoubleScalarIsNaN(c12_k_varargin_1.re);
  c12_b12 = muDoubleScalarIsNaN(c12_k_varargin_1.im);
  c12_hb_b = (c12_b11 || c12_b12);
  if (c12_hb_b) {
    c12_c_p = true;
  } else {
    c12_qc_x = c12_k_varargin_1.re;
    c12_rc_x = c12_qc_x;
    c12_tc_x = c12_rc_x;
    c12_mc_y = muDoubleScalarAbs(c12_tc_x);
    if (c12_mc_y > 8.9884656743115785E+307) {
      c12_SCALEA = true;
    } else {
      c12_vc_x = c12_k_varargin_1.im;
      c12_wc_x = c12_vc_x;
      c12_xc_x = c12_wc_x;
      c12_nc_y = muDoubleScalarAbs(c12_xc_x);
      if (c12_nc_y > 8.9884656743115785E+307) {
        c12_SCALEA = true;
      } else {
        c12_SCALEA = false;
      }
    }

    if (c12_SCALEA) {
      c12_A = c12_k_varargin_1.re;
      c12_ad_x = c12_A;
      c12_cd_x = c12_ad_x;
      c12_pc_y = c12_cd_x / 2.0;
      c12_b_A = c12_k_varargin_1.im;
      c12_fd_x = c12_b_A;
      c12_gd_x = c12_fd_x;
      c12_sc_y = c12_gd_x / 2.0;
      c12_id_x = c12_pc_y;
      c12_tc_y = c12_sc_y;
      c12_md_x = c12_id_x;
      c12_vc_y = c12_tc_y;
      c12_od_x = c12_md_x;
      c12_xc_y = c12_vc_y;
      c12_b_x1 = c12_od_x;
      c12_b_x2 = c12_xc_y;
      c12_bd_x = muDoubleScalarHypot(c12_b_x1, c12_b_x2);
      c12_oc_y = 0.5;
    } else {
      c12_x1 = c12_k_varargin_1.re;
      c12_x2 = c12_k_varargin_1.im;
      c12_bd_x = muDoubleScalarHypot(c12_x1, c12_x2);
      c12_oc_y = 1.0;
    }

    c12_ed_x = c12_bd_x;
    c12_qc_y = c12_oc_y;
    c12_d_p = (c12_ed_x == c12_qc_y);
    if (c12_d_p) {
      c12_jd_x = c12_k_varargin_1.re;
      c12_ld_x = c12_jd_x;
      c12_nd_x = c12_ld_x;
      c12_absar = muDoubleScalarAbs(c12_nd_x);
      c12_pd_x = c12_k_varargin_1.im;
      c12_qd_x = c12_pd_x;
      c12_rd_x = c12_qd_x;
      c12_absai = muDoubleScalarAbs(c12_rd_x);
      if (c12_absar > c12_absai) {
        c12_Ma = c12_absar;
        c12_ma = c12_absai;
      } else {
        c12_Ma = c12_absai;
        c12_ma = c12_absar;
      }

      if (c12_Ma > 1.0) {
        if (c12_ma < 0.0) {
          c12_ud_x = c12_Ma - 1.0;
          c12_d_A = c12_Ma;
          c12_vd_x = c12_d_A;
          c12_xd_x = c12_vd_x;
          c12_cd_y = c12_xd_x / 2.0;
          c12_Mbar = c12_cd_y + 0.5;
          c12_f_A = c12_ma;
          c12_ce_x = c12_f_A;
          c12_fe_x = c12_ce_x;
          c12_fd_y = c12_fe_x / 2.0;
          c12_mbar = c12_fd_y;
          c12_h_A = c12_mbar;
          c12_f_B = c12_Mbar;
          c12_ke_x = c12_h_A;
          c12_id_y = c12_f_B;
          c12_ne_x = c12_ke_x;
          c12_kd_y = c12_id_y;
          c12_md_y = c12_ne_x / c12_kd_y;
          c12_bd_y = c12_md_y * (0.0 - c12_ma);
        } else {
          c12_ud_x = c12_Ma;
          c12_bd_y = 1.0;
        }
      } else if (c12_Ma < 1.0) {
        if (c12_ma > 0.0) {
          c12_bd_y = 1.0 - c12_Ma;
          c12_e_A = c12_Ma;
          c12_wd_x = c12_e_A;
          c12_yd_x = c12_wd_x;
          c12_dd_y = c12_yd_x / 2.0;
          c12_Mbar = c12_dd_y + 0.5;
          c12_g_A = c12_ma;
          c12_ee_x = c12_g_A;
          c12_he_x = c12_ee_x;
          c12_hd_y = c12_he_x / 2.0;
          c12_mbar = c12_hd_y;
          c12_i_A = c12_mbar;
          c12_g_B = c12_Mbar;
          c12_me_x = c12_i_A;
          c12_jd_y = c12_g_B;
          c12_oe_x = c12_me_x;
          c12_ld_y = c12_jd_y;
          c12_nd_y = c12_oe_x / c12_ld_y;
          c12_ud_x = c12_nd_y * c12_ma;
        } else {
          c12_ud_x = c12_Ma;
          c12_bd_y = 1.0;
        }
      } else {
        c12_ud_x = c12_ma;
        c12_bd_y = 0.0;
      }

      c12_bd_x = c12_ud_x;
      c12_oc_y = c12_bd_y;
      c12_be_x = c12_ud_x;
      c12_ed_y = c12_bd_y;
      c12_g_p = (c12_be_x == c12_ed_y);
      if (c12_g_p) {
        c12_gd_y = c12_k_varargin_1.im;
        c12_je_x = c12_k_varargin_1.re;
        c12_bd_x = muDoubleScalarAtan2(c12_gd_y, c12_je_x);
        c12_oc_y = 0.0;
        c12_le_x = c12_bd_x;
        c12_i_p = (c12_le_x == 0.0);
        if (c12_i_p) {
          c12_pe_x = c12_bd_x;
          c12_qe_x = c12_pe_x;
          c12_f_ar = c12_k_varargin_1.re;
          c12_f_ai = c12_k_varargin_1.im;
          if (c12_qe_x > 0.78539816339744828) {
            if (c12_qe_x > 2.3561944901923448) {
              c12_qe_x = -c12_f_ai;
              c12_od_y = -0.0;
            } else {
              c12_qe_x = -c12_f_ar;
              c12_od_y = -1.0;
            }
          } else if (c12_qe_x > -0.78539816339744828) {
            c12_qe_x = c12_f_ai;
            c12_od_y = 0.0;
          } else if (c12_qe_x > -2.3561944901923448) {
            c12_qe_x = c12_f_ar;
            c12_od_y = 1.0;
          } else {
            c12_qe_x = -c12_f_ai;
            c12_od_y = -0.0;
          }

          c12_bd_x = c12_qe_x;
          c12_oc_y = c12_od_y;
          c12_ue_x = c12_qe_x;
          c12_pd_y = c12_od_y;
          c12_m_p = (c12_ue_x == c12_pd_y);
          if (c12_m_p) {
            c12_bd_x = 0.0;
            c12_oc_y = 0.0;
          }
        }
      }
    }

    c12_c_p = (c12_bd_x > c12_oc_y);
  }

  if (c12_c_p) {
    c12_k_varargin_1 = c12_dc1;
  }

  c12_emxInit_creal_T1(chartInstance, &c12_uc_x, 1, &c12_cf_emlrtRTEI);
  c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1, c12_b_h->size[0]) +
                 c12_b_h->size[0] * (sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[1]) - 1)) - 1].re = c12_k_varargin_1.re;
  c12_b_h->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1, c12_b_h->size[0]) +
                 c12_b_h->size[0] * (sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, c12_crad + 1.0), 1,
     c12_b_h->size[1]) - 1)) - 1].im = c12_k_varargin_1.im;
  c12_i537 = c12_uc_x->size[0];
  c12_uc_x->size[0] = c12_b_h->size[0] * c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T1(chartInstance, c12_uc_x, c12_i537,
    &c12_cf_emlrtRTEI);
  c12_nc_loop_ub = c12_b_h->size[0] * c12_b_h->size[1] - 1;
  for (c12_i538 = 0; c12_i538 <= c12_nc_loop_ub; c12_i538++) {
    c12_uc_x->data[c12_i538] = c12_b_h->data[c12_i538];
  }

  if ((c12_uc_x->size[0] == 1) || ((real_T)c12_uc_x->size[0] != 1.0)) {
    c12_b13 = true;
  } else {
    c12_b13 = false;
  }

  if (c12_b13) {
  } else {
    c12_uc_y = NULL;
    sf_mex_assign(&c12_uc_y, sf_mex_create("y", c12_cv2, 10, 0U, 1U, 0U, 2, 1,
      36), false);
    c12_wc_y = NULL;
    sf_mex_assign(&c12_wc_y, sf_mex_create("y", c12_cv2, 10, 0U, 1U, 0U, 2, 1,
      36), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_uc_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c12_wc_y)));
  }

  c12_vlen = c12_uc_x->size[0];
  if ((c12_uc_x->size[0] == 0) || (c12_vlen == 0)) {
    c12_k_varargin_1 = c12_dc0;
  } else {
    c12_b_vlen = c12_vlen;
    c12_k_varargin_1 = c12_uc_x->data[0];
    c12_ib_b = c12_b_vlen;
    c12_jb_b = c12_ib_b;
    if (2 > c12_jb_b) {
      c12_e_overflow = false;
    } else {
      c12_e_overflow = (c12_jb_b > 2147483646);
    }

    if (c12_e_overflow) {
      c12_check_forloop_overflow_error(chartInstance, true);
    }

    for (c12_e_k = 1; c12_e_k < c12_b_vlen; c12_e_k++) {
      c12_xoffset = c12_e_k;
      c12_ix = c12_xoffset;
      c12_k_varargin_1.re += c12_uc_x->data[c12_ix].re;
      c12_k_varargin_1.im += c12_uc_x->data[c12_ix].im;
    }
  }

  c12_emxFree_creal_T(chartInstance, &c12_uc_x);
  c12_i539 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_i540 = c12_b_h->size[0] * c12_b_h->size[1];
  c12_b_h->size[0];
  c12_b_h->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_h, c12_i540,
    &c12_df_emlrtRTEI);
  c12_x_h = c12_b_h->size[0];
  c12_y_h = c12_b_h->size[1];
  c12_oc_loop_ub = c12_i539 - 1;
  for (c12_i541 = 0; c12_i541 <= c12_oc_loop_ub; c12_i541++) {
    c12_ab_h = c12_b_h->data[c12_i541];
    c12_l_varargin_1 = c12_k_varargin_1;
    c12_e_ar = c12_ab_h.re;
    c12_e_ai = c12_ab_h.im;
    c12_e_br = c12_l_varargin_1.re;
    c12_e_bi = c12_l_varargin_1.im;
    if (c12_e_bi == 0.0) {
      if (c12_e_ai == 0.0) {
        c12_b_h->data[c12_i541].re = c12_e_ar / c12_e_br;
        c12_b_h->data[c12_i541].im = 0.0;
      } else if (c12_e_ar == 0.0) {
        c12_b_h->data[c12_i541].re = 0.0;
        c12_b_h->data[c12_i541].im = c12_e_ai / c12_e_br;
      } else {
        c12_b_h->data[c12_i541].re = c12_e_ar / c12_e_br;
        c12_b_h->data[c12_i541].im = c12_e_ai / c12_e_br;
      }
    } else if (c12_e_br == 0.0) {
      if (c12_e_ar == 0.0) {
        c12_b_h->data[c12_i541].re = c12_e_ai / c12_e_bi;
        c12_b_h->data[c12_i541].im = 0.0;
      } else if (c12_e_ai == 0.0) {
        c12_b_h->data[c12_i541].re = 0.0;
        c12_b_h->data[c12_i541].im = -(c12_e_ar / c12_e_bi);
      } else {
        c12_b_h->data[c12_i541].re = c12_e_ai / c12_e_bi;
        c12_b_h->data[c12_i541].im = -(c12_e_ar / c12_e_bi);
      }
    } else {
      c12_e_brm = muDoubleScalarAbs(c12_e_br);
      c12_e_bim = muDoubleScalarAbs(c12_e_bi);
      if (c12_e_brm > c12_e_bim) {
        c12_e_s = c12_e_bi / c12_e_br;
        c12_g_d = c12_e_br + c12_e_s * c12_e_bi;
        c12_e_nr = c12_e_ar + c12_e_s * c12_e_ai;
        c12_e_ni = c12_e_ai - c12_e_s * c12_e_ar;
        c12_b_h->data[c12_i541].re = c12_e_nr / c12_g_d;
        c12_b_h->data[c12_i541].im = c12_e_ni / c12_g_d;
      } else if (c12_e_bim == c12_e_brm) {
        if (c12_e_br > 0.0) {
          c12_e_sgnbr = 0.5;
        } else {
          c12_e_sgnbr = -0.5;
        }

        if (c12_e_bi > 0.0) {
          c12_e_sgnbi = 0.5;
        } else {
          c12_e_sgnbi = -0.5;
        }

        c12_e_nr = c12_e_ar * c12_e_sgnbr + c12_e_ai * c12_e_sgnbi;
        c12_e_ni = c12_e_ai * c12_e_sgnbr - c12_e_ar * c12_e_sgnbi;
        c12_b_h->data[c12_i541].re = c12_e_nr / c12_e_brm;
        c12_b_h->data[c12_i541].im = c12_e_ni / c12_e_brm;
      } else {
        c12_e_s = c12_e_br / c12_e_bi;
        c12_g_d = c12_e_bi + c12_e_s * c12_e_br;
        c12_e_nr = c12_e_s * c12_e_ar + c12_e_ai;
        c12_e_ni = c12_e_s * c12_e_ai - c12_e_ar;
        c12_b_h->data[c12_i541].re = c12_e_nr / c12_g_d;
        c12_b_h->data[c12_i541].im = c12_e_ni / c12_g_d;
      }
    }
  }
}

static void c12_validateattributes(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_a)
{
  real_T c12_b_a;
  real_T c12_c_a;
  boolean_T c12_p;
  real_T c12_b_x;
  real_T c12_c_x;
  boolean_T c12_b;
  boolean_T c12_b18;
  real_T c12_d_x;
  boolean_T c12_b_b;
  boolean_T c12_b19;
  boolean_T c12_c_b;
  boolean_T c12_b20;
  const mxArray *c12_y = NULL;
  static char_T c12_cv11[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'f', 's',
    'p', 'e', 'c', 'i', 'a', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'F', 'i', 'n', 'i', 't', 'e' };

  const mxArray *c12_b_y = NULL;
  static char_T c12_cv12[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  const mxArray *c12_c_y = NULL;
  static char_T c12_cv13[23] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '2', ',', ' ', 'R', 'A', 'D', 'I', 'U', 'S', ',' };

  (void)chartInstance;
  c12_b_a = c12_a;
  c12_c_a = c12_b_a;
  c12_p = true;
  c12_b_x = c12_c_a;
  c12_c_x = c12_b_x;
  c12_b = muDoubleScalarIsInf(c12_c_x);
  c12_b18 = !c12_b;
  c12_d_x = c12_b_x;
  c12_b_b = muDoubleScalarIsNaN(c12_d_x);
  c12_b19 = !c12_b_b;
  c12_c_b = (c12_b18 && c12_b19);
  if (c12_c_b) {
  } else {
    c12_p = false;
  }

  if (c12_p) {
    c12_b20 = true;
  } else {
    c12_b20 = false;
  }

  if (c12_b20) {
  } else {
    c12_y = NULL;
    sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv11, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c12_b_y = NULL;
    sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv12, 10, 0U, 1U, 0U, 2, 1,
      46), false);
    c12_c_y = NULL;
    sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv13, 10, 0U, 1U, 0U, 2, 1,
      23), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c12_b_y, 14, c12_c_y)));
  }
}

static void c12_meshgrid(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T *c12_b_x, c12_emxArray_real_T *c12_y, c12_emxArray_real_T *
  c12_xx, c12_emxArray_real_T *c12_yy)
{
  int32_T c12_nx;
  int32_T c12_ny;
  int32_T c12_iv25[2];
  int32_T c12_i542;
  int32_T c12_i543;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_j;
  int32_T c12_c_b;
  int32_T c12_d_b;
  boolean_T c12_b_overflow;
  int32_T c12_i;
  c12_nx = c12_b_x->size[1];
  c12_ny = c12_y->size[1];
  c12_iv25[0] = c12_ny;
  c12_iv25[1] = c12_nx;
  c12_i542 = c12_xx->size[0] * c12_xx->size[1];
  c12_xx->size[0] = c12_iv25[0];
  c12_xx->size[1] = c12_iv25[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_xx, c12_i542,
    &c12_nf_emlrtRTEI);
  c12_iv25[0] = c12_ny;
  c12_iv25[1] = c12_nx;
  c12_i543 = c12_yy->size[0] * c12_yy->size[1];
  c12_yy->size[0] = c12_iv25[0];
  c12_yy->size[1] = c12_iv25[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_yy, c12_i543,
    &c12_nf_emlrtRTEI);
  if ((c12_nx == 0) || (c12_ny == 0)) {
  } else {
    c12_b = c12_nx;
    c12_b_b = c12_b;
    if (1 > c12_b_b) {
      c12_overflow = false;
    } else {
      c12_overflow = (c12_b_b > 2147483646);
    }

    if (c12_overflow) {
      c12_check_forloop_overflow_error(chartInstance, true);
    }

    for (c12_j = 0; c12_j < c12_nx; c12_j++) {
      c12_c_b = c12_ny;
      c12_d_b = c12_c_b;
      if (1 > c12_d_b) {
        c12_b_overflow = false;
      } else {
        c12_b_overflow = (c12_d_b > 2147483646);
      }

      if (c12_b_overflow) {
        c12_check_forloop_overflow_error(chartInstance, true);
      }

      for (c12_i = 0; c12_i < c12_ny; c12_i++) {
        c12_xx->data[c12_i + c12_xx->size[0] * c12_j] = c12_b_x->data[c12_j];
        c12_yy->data[c12_i + c12_yy->size[0] * c12_j] = c12_y->data[c12_i];
      }
    }
  }
}

static void c12_abs(SFc12_anav_realInstanceStruct *chartInstance,
                    c12_emxArray_real_T *c12_b_x, c12_emxArray_real_T *c12_y)
{
  int32_T c12_nx;
  int32_T c12_i544;
  int32_T c12_i545;
  real_T c12_c_x[2];
  int32_T c12_i546;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  real_T c12_d_x;
  real_T c12_b_y;
  c12_nx = c12_b_x->size[0] * c12_b_x->size[1];
  for (c12_i544 = 0; c12_i544 < 2; c12_i544++) {
    c12_c_x[c12_i544] = (real_T)c12_b_x->size[c12_i544];
  }

  for (c12_i545 = 0; c12_i545 < 2; c12_i545++) {
    c12_c_x[c12_i545];
  }

  c12_i546 = c12_y->size[0] * c12_y->size[1];
  c12_y->size[0] = (int32_T)c12_c_x[0];
  c12_y->size[1] = (int32_T)c12_c_x[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_y, c12_i546, &c12_of_emlrtRTEI);
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_d_x = c12_b_x->data[c12_k];
    c12_b_y = muDoubleScalarAbs(c12_d_x);
    c12_y->data[c12_k] = c12_b_y;
  }
}

static boolean_T c12_dimagree(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T *c12_z, c12_emxArray_real_T *c12_c_varargin_1,
  c12_emxArray_real_T *c12_varargin_2)
{
  boolean_T c12_p;
  boolean_T c12_b_p;
  int32_T c12_k;
  real_T c12_d4;
  real_T c12_d5;
  boolean_T c12_c_p;
  int32_T c12_b_k;
  real_T c12_d6;
  real_T c12_d7;
  boolean_T exitg1;
  (void)chartInstance;
  c12_p = true;
  c12_b_p = true;
  c12_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c12_k + 1 < 3)) {
    c12_d4 = (real_T)c12_z->size[c12_k];
    c12_d5 = (real_T)c12_c_varargin_1->size[c12_k];
    if ((int32_T)c12_d4 != (int32_T)c12_d5) {
      c12_b_p = false;
      exitg1 = true;
    } else {
      c12_k++;
    }
  }

  if (c12_b_p) {
    c12_c_p = true;
    c12_b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c12_b_k + 1 < 3)) {
      c12_d6 = (real_T)c12_z->size[c12_b_k];
      c12_d7 = (real_T)c12_varargin_2->size[c12_b_k];
      if ((int32_T)c12_d6 != (int32_T)c12_d7) {
        c12_c_p = false;
        exitg1 = true;
      } else {
        c12_b_k++;
      }
    }

    if (c12_c_p) {
    } else {
      c12_p = false;
    }
  } else {
    c12_p = false;
  }

  return c12_p;
}

static void c12_error(SFc12_anav_realInstanceStruct *chartInstance)
{
  const mxArray *c12_y = NULL;
  static char_T c12_cv14[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  const mxArray *c12_b_y = NULL;
  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv14, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv14, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 1U,
    14, c12_b_y)));
}

static void c12_power(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_real_T *c12_a, c12_emxArray_real_T *c12_y)
{
  c12_emxArray_real_T *c12_r13;
  int32_T c12_i547;
  int32_T c12_i548;
  real_T c12_c_varargin_1[2];
  c12_emxArray_real_T *c12_ztemp;
  int32_T c12_i549;
  int32_T c12_i550;
  int32_T c12_i551;
  int32_T c12_i552;
  int32_T c12_iv26[2];
  int32_T c12_i553;
  c12_emxArray_real_T *c12_r14;
  int32_T c12_i554;
  int32_T c12_i555;
  int32_T c12_i556;
  int32_T c12_i557;
  int32_T c12_loop_ub;
  int32_T c12_i558;
  c12_emxArray_real_T *c12_b_a;
  int32_T c12_i559;
  int32_T c12_c_a;
  int32_T c12_d_a;
  int32_T c12_b_loop_ub;
  int32_T c12_i560;
  const mxArray *c12_b_y = NULL;
  const mxArray *c12_c_y = NULL;
  int32_T c12_i561;
  int32_T c12_i562;
  int32_T c12_nx;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  boolean_T c12_p;
  real_T c12_e_a;
  real_T c12_d_y;
  c12_emxInit_real_T(chartInstance, &c12_r13, 2, &c12_ad_emlrtRTEI);
  for (c12_i547 = 0; c12_i547 < 2; c12_i547++) {
    c12_c_varargin_1[c12_i547] = (real_T)c12_a->size[c12_i547];
  }

  for (c12_i548 = 0; c12_i548 < 2; c12_i548++) {
    c12_c_varargin_1[c12_i548];
  }

  c12_emxInit_real_T(chartInstance, &c12_ztemp, 2, &c12_jf_emlrtRTEI);
  c12_i549 = c12_ztemp->size[0] * c12_ztemp->size[1];
  c12_ztemp->size[0] = (int32_T)c12_c_varargin_1[0];
  c12_ztemp->size[1] = (int32_T)c12_c_varargin_1[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_ztemp, c12_i549,
    &c12_xc_emlrtRTEI);
  c12_i550 = c12_r13->size[0] * c12_r13->size[1];
  c12_r13->size[0] = c12_ztemp->size[0];
  c12_r13->size[1] = c12_ztemp->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r13, c12_i550,
    &c12_xc_emlrtRTEI);
  c12_emxFree_real_T(chartInstance, &c12_ztemp);
  for (c12_i551 = 0; c12_i551 < 2; c12_i551++) {
    c12_iv26[c12_i551] = c12_r13->size[c12_i551];
  }

  c12_i552 = c12_r13->size[0] * c12_r13->size[1];
  c12_r13->size[0] = c12_iv26[0];
  c12_r13->size[1] = c12_iv26[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r13, c12_i552,
    &c12_yc_emlrtRTEI);
  for (c12_i553 = 0; c12_i553 < 2; c12_i553++) {
    c12_iv26[c12_i553] = c12_r13->size[c12_i553];
  }

  c12_emxInit_real_T(chartInstance, &c12_r14, 2, &c12_bd_emlrtRTEI);
  c12_i554 = c12_r13->size[0] * c12_r13->size[1];
  c12_r13->size[0] = c12_iv26[0];
  c12_r13->size[1] = c12_iv26[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r13, c12_i554,
    &c12_ad_emlrtRTEI);
  c12_i555 = c12_r14->size[0] * c12_r14->size[1];
  c12_r14->size[0] = c12_r13->size[0];
  c12_r14->size[1] = c12_r13->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_r14, c12_i555,
    &c12_bd_emlrtRTEI);
  c12_i556 = c12_r14->size[0];
  c12_i557 = c12_r14->size[1];
  c12_loop_ub = c12_r13->size[0] * c12_r13->size[1] - 1;
  for (c12_i558 = 0; c12_i558 <= c12_loop_ub; c12_i558++) {
    c12_r14->data[c12_i558] = c12_r13->data[c12_i558];
  }

  c12_emxInit_real_T(chartInstance, &c12_b_a, 2, &c12_cd_emlrtRTEI);
  c12_i559 = c12_b_a->size[0] * c12_b_a->size[1];
  c12_b_a->size[0] = c12_a->size[0];
  c12_b_a->size[1] = c12_a->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_b_a, c12_i559,
    &c12_cd_emlrtRTEI);
  c12_c_a = c12_b_a->size[0];
  c12_d_a = c12_b_a->size[1];
  c12_b_loop_ub = c12_a->size[0] * c12_a->size[1] - 1;
  for (c12_i560 = 0; c12_i560 <= c12_b_loop_ub; c12_i560++) {
    c12_b_a->data[c12_i560] = c12_a->data[c12_i560];
  }

  if (c12_b_dimagree(chartInstance, c12_r14, c12_b_a)) {
  } else {
    c12_b_y = NULL;
    sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv1, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    c12_c_y = NULL;
    sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv1, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_b_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c12_c_y)));
  }

  c12_emxFree_real_T(chartInstance, &c12_b_a);
  c12_emxFree_real_T(chartInstance, &c12_r14);
  for (c12_i561 = 0; c12_i561 < 2; c12_i561++) {
    c12_iv26[c12_i561] = c12_r13->size[c12_i561];
  }

  c12_emxFree_real_T(chartInstance, &c12_r13);
  c12_i562 = c12_y->size[0] * c12_y->size[1];
  c12_y->size[0] = c12_iv26[0];
  c12_y->size[1] = c12_iv26[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_y, c12_i562, &c12_pf_emlrtRTEI);
  c12_nx = c12_y->size[0] * c12_y->size[1];
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_e_a = c12_a->data[c12_k];
    c12_d_y = c12_e_a * c12_e_a;
    c12_y->data[c12_k] = c12_d_y;
  }

  c12_p = false;
  if (c12_p) {
    c12_error(chartInstance);
  }
}

static boolean_T c12_b_dimagree(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T *c12_z, c12_emxArray_real_T *c12_c_varargin_1)
{
  boolean_T c12_p;
  boolean_T c12_b_p;
  int32_T c12_k;
  real_T c12_d8;
  real_T c12_d9;
  boolean_T exitg1;
  (void)chartInstance;
  c12_p = true;
  c12_b_p = true;
  c12_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c12_k + 1 < 3)) {
    c12_d8 = (real_T)c12_z->size[c12_k];
    c12_d9 = (real_T)c12_c_varargin_1->size[c12_k];
    if ((int32_T)c12_d8 != (int32_T)c12_d9) {
      c12_b_p = false;
      exitg1 = true;
    } else {
      c12_k++;
    }
  }

  if (c12_b_p) {
  } else {
    c12_p = false;
  }

  return c12_p;
}

static void c12_sqrt(SFc12_anav_realInstanceStruct *chartInstance,
                     c12_emxArray_creal_T *c12_b_x, c12_emxArray_creal_T
                     *c12_c_x)
{
  int32_T c12_i563;
  int32_T c12_d_x;
  int32_T c12_e_x;
  int32_T c12_loop_ub;
  int32_T c12_i564;
  c12_i563 = c12_c_x->size[0] * c12_c_x->size[1];
  c12_c_x->size[0] = c12_b_x->size[0];
  c12_c_x->size[1] = c12_b_x->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_c_x, c12_i563,
    &c12_qf_emlrtRTEI);
  c12_d_x = c12_c_x->size[0];
  c12_e_x = c12_c_x->size[1];
  c12_loop_ub = c12_b_x->size[0] * c12_b_x->size[1] - 1;
  for (c12_i564 = 0; c12_i564 <= c12_loop_ub; c12_i564++) {
    c12_c_x->data[c12_i564] = c12_b_x->data[c12_i564];
  }

  c12_d_sqrt(chartInstance, c12_c_x);
}

static creal_T c12_b_sqrt(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  c12_b_x)
{
  creal_T c12_c_x;
  c12_c_x = c12_b_x;
  c12_e_sqrt(chartInstance, &c12_c_x);
  return c12_c_x;
}

static void c12_asin(SFc12_anav_realInstanceStruct *chartInstance,
                     c12_emxArray_creal_T *c12_b_x, c12_emxArray_creal_T
                     *c12_c_x)
{
  int32_T c12_i565;
  int32_T c12_d_x;
  int32_T c12_e_x;
  int32_T c12_loop_ub;
  int32_T c12_i566;
  c12_i565 = c12_c_x->size[0] * c12_c_x->size[1];
  c12_c_x->size[0] = c12_b_x->size[0];
  c12_c_x->size[1] = c12_b_x->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_c_x, c12_i565,
    &c12_rf_emlrtRTEI);
  c12_d_x = c12_c_x->size[0];
  c12_e_x = c12_c_x->size[1];
  c12_loop_ub = c12_b_x->size[0] * c12_b_x->size[1] - 1;
  for (c12_i566 = 0; c12_i566 <= c12_loop_ub; c12_i566++) {
    c12_c_x->data[c12_i566] = c12_b_x->data[c12_i566];
  }

  c12_c_asin(chartInstance, c12_c_x);
}

static creal_T c12_b_asin(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  c12_b_x)
{
  creal_T c12_c_x;
  c12_c_x = c12_b_x;
  c12_d_asin(chartInstance, &c12_c_x);
  return c12_c_x;
}

static void c12_rescale(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_re, real_T c12_im, real_T *c12_b_re, real_T *c12_b_im, real_T *c12_b_scale)
{
  *c12_b_re = c12_re;
  *c12_b_im = c12_im;
  *c12_b_scale = c12_b_rescale(chartInstance, c12_b_re, c12_b_im);
}

static void c12_b_sin(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_creal_T *c12_b_x, c12_emxArray_creal_T
                      *c12_c_x)
{
  int32_T c12_i567;
  int32_T c12_d_x;
  int32_T c12_e_x;
  int32_T c12_loop_ub;
  int32_T c12_i568;
  c12_i567 = c12_c_x->size[0] * c12_c_x->size[1];
  c12_c_x->size[0] = c12_b_x->size[0];
  c12_c_x->size[1] = c12_b_x->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_c_x, c12_i567,
    &c12_kc_emlrtRTEI);
  c12_d_x = c12_c_x->size[0];
  c12_e_x = c12_c_x->size[1];
  c12_loop_ub = c12_b_x->size[0] * c12_b_x->size[1] - 1;
  for (c12_i568 = 0; c12_i568 <= c12_loop_ub; c12_i568++) {
    c12_c_x->data[c12_i568] = c12_b_x->data[c12_i568];
  }

  c12_d_sin(chartInstance, c12_c_x);
}

static real_T c12_c_sqrt(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_b_x)
{
  real_T c12_c_x;
  c12_c_x = c12_b_x;
  c12_f_sqrt(chartInstance, &c12_c_x);
  return c12_c_x;
}

static void c12_b_error(SFc12_anav_realInstanceStruct *chartInstance)
{
  const mxArray *c12_y = NULL;
  const mxArray *c12_b_y = NULL;
  const mxArray *c12_c_y = NULL;
  static char_T c12_cv15[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv15, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 2U,
    14, c12_b_y, 14, c12_c_y)));
}

static void c12_c_error(SFc12_anav_realInstanceStruct *chartInstance)
{
  const mxArray *c12_y = NULL;
  const mxArray *c12_b_y = NULL;
  const mxArray *c12_c_y = NULL;
  static char_T c12_cv16[4] = { 'a', 's', 'i', 'n' };

  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv16, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 2U,
    14, c12_b_y, 14, c12_c_y)));
}

static void c12_imfilter(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_c_varargin_1[3081], c12_emxArray_creal_T *c12_varargin_2,
  c12_emxArray_creal_T *c12_b)
{
  real_T c12_outSizeT[2];
  real_T c12_A;
  real_T c12_b_x;
  real_T c12_c_x;
  real_T c12_y;
  real_T c12_d_x;
  real_T c12_e_x;
  real_T c12_filter_center[2];
  real_T c12_startT[2];
  real_T c12_b_A;
  real_T c12_f_x;
  real_T c12_g_x;
  real_T c12_b_y;
  real_T c12_h_x;
  real_T c12_i_x;
  boolean_T c12_b21;
  boolean_T c12_b22;
  c12_emxArray_creal_T *c12_unusedU0;
  int32_T c12_i569;
  c12_emxArray_real_T *c12_s;
  c12_emxArray_creal_T *c12_unusedU1;
  c12_emxArray_real_T *c12_b_s;
  c12_emxArray_boolean_T *c12_b_b;
  int32_T c12_c_b;
  c12_emxArray_boolean_T *c12_d_b;
  int32_T c12_e_b;
  c12_emxArray_creal_T *c12_h_tmp;
  int32_T c12_i570;
  c12_emxArray_boolean_T *c12_b_h;
  c12_emxArray_real_T *c12_c_s;
  c12_emxArray_creal_T *c12_b_varargin_2;
  int32_T c12_i571;
  boolean_T c12_separable;
  int32_T c12_i572;
  boolean_T c12_c_y;
  boolean_T c12_j_x[2];
  c12_emxArray_real_T *c12_a;
  int32_T c12_k;
  c12_emxArray_creal_T *c12_nonzero_h;
  int32_T c12_i573;
  int32_T c12_i574;
  real_T c12_b_k;
  int32_T c12_i575;
  int32_T c12_i576;
  int32_T c12_i577;
  int32_T c12_loop_ub;
  real_T c12_b_startT[2];
  c12_emxArray_creal_T *c12_c_varargin_2;
  real_T c12_c_startT[2];
  int32_T c12_i578;
  boolean_T c12_b23;
  boolean_T c12_b24;
  int32_T c12_i579;
  c12_emxArray_int32_T *c12_r15;
  int32_T c12_i580;
  c12_emxArray_boolean_T *c12_c_h;
  c12_emxArray_boolean_T *c12_d_h;
  c12_emxArray_boolean_T *c12_e_h;
  int32_T c12_d_varargin_2;
  int32_T c12_b_loop_ub;
  int32_T c12_e_varargin_2;
  int32_T c12_i581;
  int32_T c12_i582;
  int32_T c12_c_loop_ub;
  int32_T c12_i583;
  int32_T c12_i584;
  int32_T c12_i585;
  int32_T c12_f_h;
  c12_emxArray_real_T *c12_d_s;
  int32_T c12_g_h;
  int32_T c12_h_h;
  int32_T c12_d_loop_ub;
  int32_T c12_i_h;
  int32_T c12_e_loop_ub;
  int32_T c12_i586;
  int32_T c12_i587;
  int32_T c12_f_loop_ub;
  int32_T c12_i588;
  int32_T c12_i589;
  int32_T c12_i590;
  int32_T c12_i591;
  int32_T c12_i592;
  boolean_T c12_b25;
  int32_T c12_i593;
  int32_T c12_i594;
  int32_T c12_g_loop_ub;
  int32_T c12_h_loop_ub;
  int32_T c12_i595;
  int32_T c12_i596;
  int32_T c12_matrixSize[2];
  int32_T c12_i597;
  int32_T c12_j_h;
  int32_T c12_k_h;
  int32_T c12_i598;
  boolean_T c12_nonSingletonDimFound;
  int32_T c12_indexSize[2];
  int32_T c12_i_loop_ub;
  int32_T c12_j_loop_ub;
  int32_T c12_i599;
  int32_T c12_i600;
  int32_T c12_k_loop_ub;
  int32_T c12_i601;
  int32_T c12_i602;
  boolean_T c12_b26;
  int32_T c12_i603;
  boolean_T c12_f_b;
  int32_T c12_i604;
  int32_T c12_i605;
  int32_T c12_l_loop_ub;
  boolean_T c12_b_nonSingletonDimFound;
  boolean_T c12_c;
  int32_T c12_m_loop_ub;
  int32_T c12_i606;
  int32_T c12_n_loop_ub;
  int32_T c12_i607;
  int32_T c12_i608;
  real_T c12_g_b;
  boolean_T c12_h_b;
  int32_T c12_i609;
  int32_T c12_i610;
  int32_T c12_i611;
  boolean_T c12_b_c;
  int32_T c12_o_loop_ub;
  boolean_T c12_c_c;
  const mxArray *c12_d_y = NULL;
  int32_T c12_l_h;
  int32_T c12_p_loop_ub;
  int32_T c12_i612;
  int32_T c12_end;
  static char_T c12_cv17[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':',
    'P', 'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'M', 'a', 't', 'r', 'i', 'x',
    'M', 'a', 't', 'r', 'i', 'x' };

  int32_T c12_m_h;
  int32_T c12_i613;
  int32_T c12_trueCount;
  const mxArray *c12_e_y = NULL;
  int32_T c12_q_loop_ub;
  int32_T c12_i;
  int32_T c12_i614;
  int32_T c12_i615;
  c12_emxArray_creal_T *c12_hrow;
  int32_T c12_i616;
  boolean_T c12_f_varargin_2;
  boolean_T c12_d_c;
  int32_T c12_i617;
  int32_T c12_r_loop_ub;
  int32_T c12_i618;
  int32_T c12_i619;
  const mxArray *c12_f_y = NULL;
  int32_T c12_i620;
  int32_T c12_partialTrueCount;
  static char_T c12_cv18[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':',
    'P', 'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'M', 'a', 't', 'r', 'i', 'x',
    'M', 'a', 't', 'r', 'i', 'x' };

  int32_T c12_b_i;
  const mxArray *c12_g_y = NULL;
  int32_T c12_n_h;
  int32_T c12_i621;
  int32_T c12_o_h;
  int32_T c12_s_loop_ub;
  int32_T c12_t_loop_ub;
  int32_T c12_g_varargin_2;
  boolean_T c12_h_varargin_2;
  int32_T c12_i622;
  int32_T c12_i623;
  int32_T c12_u_loop_ub;
  int32_T c12_i624;
  int32_T c12_i625;
  int32_T c12_i626;
  real_T c12_i_b;
  int32_T c12_v_loop_ub;
  int32_T c12_i627;
  int32_T c12_i628;
  int32_T c12_i629;
  int32_T c12_i630;
  int32_T c12_p_h;
  int32_T c12_w_loop_ub;
  int32_T c12_q_h;
  int32_T c12_i631;
  int32_T c12_x_loop_ub;
  int32_T c12_i632;
  int32_T c12_b_hrow;
  int32_T c12_c_hrow;
  int32_T c12_i633;
  int32_T c12_y_loop_ub;
  int32_T c12_i634;
  int32_T c12_i635;
  boolean_T c12_b27;
  int32_T c12_e_s;
  int32_T c12_ab_loop_ub;
  c12_emxArray_boolean_T *c12_r_h;
  const mxArray *c12_h_y = NULL;
  int32_T c12_f_s;
  int32_T c12_i636;
  real_T c12_out_size_row[2];
  static char_T c12_cv19[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T c12_i_y;
  int32_T c12_bb_loop_ub;
  const mxArray *c12_j_y = NULL;
  real_T c12_vlen;
  int32_T c12_i637;
  real_T c12_start[2];
  real_T c12_b_a;
  int32_T c12_b_end;
  int32_T c12_e_c;
  int32_T c12_b_trueCount;
  int32_T c12_i638;
  int32_T c12_c_a;
  int32_T c12_i639;
  int32_T c12_c_i;
  int32_T c12_vspread;
  int32_T c12_j_b;
  int32_T c12_i2;
  int32_T c12_cb_loop_ub;
  int32_T c12_i640;
  int32_T c12_s_h;
  int32_T c12_d_a;
  int32_T c12_i641;
  int32_T c12_t_h;
  int32_T c12_db_loop_ub;
  int32_T c12_k_b;
  int32_T c12_b_partialTrueCount;
  int32_T c12_i642;
  int32_T c12_l_b;
  int32_T c12_i643;
  int32_T c12_d_i;
  boolean_T c12_overflow;
  c12_emxArray_boolean_T *c12_u_h;
  int32_T c12_i644;
  int32_T c12_v_h;
  int32_T c12_w_h;
  int32_T c12_ix;
  int32_T c12_eb_loop_ub;
  int32_T c12_i645;
  int32_T c12_x_h;
  int32_T c12_y_h;
  int32_T c12_fb_loop_ub;
  boolean_T c12_densityFlag;
  int32_T c12_i646;
  int32_T c12_i647;
  real_T c12_c_A;
  real_T c12_B;
  real_T c12_k_x;
  int32_T c12_i648;
  real_T c12_k_y;
  int32_T c12_i_varargin_2;
  real_T c12_l_x;
  int32_T c12_j_varargin_2;
  real_T c12_l_y;
  int32_T c12_gb_loop_ub;
  int32_T c12_hb_loop_ub;
  real_T c12_m_y;
  int32_T c12_i649;
  int32_T c12_i650;
  boolean_T c12_tooBig;
  int32_T c12_e_i;
  int32_T c12_c_end;
  int32_T c12_i651;
  int32_T c12_c_trueCount;
  int32_T c12_i652;
  int32_T c12_f_i;
  int32_T c12_i653;
  boolean_T c12_modeFlag;
  int32_T c12_i654;
  int32_T c12_ib_loop_ub;
  int32_T c12_i655;
  boolean_T c12_b_modeFlag;
  int32_T c12_c_partialTrueCount;
  int32_T c12_g_i;
  boolean_T c12_c_modeFlag;
  int32_T c12_jb_loop_ub;
  int32_T c12_b1_size[2];
  int32_T c12_d_varargin_1;
  int32_T c12_i656;
  c12_emxArray_real_T *c12_ab_h;
  int32_T c12_k_varargin_2;
  int32_T c12_i657;
  int32_T c12_e_varargin_1;
  int32_T c12_i658;
  int32_T c12_i659;
  int32_T c12_l_varargin_2;
  int32_T c12_i660;
  real_T c12_padSizeT[2];
  int32_T c12_i661;
  int32_T c12_bb_h;
  int32_T c12_n;
  int32_T c12_cb_h;
  int32_T c12_kb_loop_ub;
  real_T c12_b_n;
  int32_T c12_i662;
  int32_T c12_i663;
  int32_T c12_i664;
  boolean_T c12_b28;
  real_T c12_numKernElem;
  int32_T c12_i665;
  int32_T c12_i666;
  int32_T c12_i667;
  const mxArray *c12_n_y = NULL;
  int32_T c12_lb_loop_ub;
  int32_T c12_i668;
  const mxArray *c12_o_y = NULL;
  const mxArray *c12_p_y = NULL;
  int32_T c12_i669;
  static char_T c12_cv20[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c12_c_n;
  const mxArray *c12_q_y = NULL;
  int32_T c12_i670;
  int32_T c12_d_n;
  real_T c12_m_x;
  real_T c12_maxval;
  int32_T c12_g_s;
  real_T c12_n_x;
  real_T c12_o_x;
  int32_T c12_h_s;
  boolean_T c12_m_b;
  boolean_T c12_n_b;
  int32_T c12_mb_loop_ub;
  int32_T c12_db_h;
  boolean_T c12_p;
  real_T c12_tol;
  int32_T c12_i671;
  int32_T c12_eb_h;
  real_T c12_p_x;
  int32_T c12_i672;
  int32_T c12_nb_loop_ub;
  int32_T c12_idx;
  boolean_T c12_o_b;
  int32_T c12_i673;
  int32_T c12_p_b;
  int32_T c12_i674;
  int32_T c12_q_b;
  int32_T c12_ob_loop_ub;
  int32_T c12_first;
  int32_T c12_i675;
  boolean_T c12_b_densityFlag;
  boolean_T c12_b_overflow;
  int32_T c12_last;
  int32_T c12_pb_loop_ub;
  real_T c12_d_A;
  real_T c12_ex;
  int32_T c12_i676;
  real_T c12_b_B;
  int32_T c12_i677;
  real_T c12_q_x;
  int32_T c12_e_a;
  real_T c12_r_y;
  int32_T c12_c_k;
  int32_T c12_r_b;
  boolean_T c12_b29;
  int32_T c12_i678;
  real_T c12_r_x;
  int32_T c12_f_a;
  real_T c12_s_y;
  int32_T c12_s_b;
  real_T c12_t_y;
  real_T c12_s_x;
  const mxArray *c12_u_y = NULL;
  real_T c12_t_x;
  boolean_T c12_c_overflow;
  int32_T c12_b_vlen;
  int32_T c12_fb_h;
  boolean_T c12_t_b;
  const mxArray *c12_v_y = NULL;
  int32_T c12_gb_h;
  boolean_T c12_b_tooBig;
  boolean_T c12_b_p;
  int32_T c12_qb_loop_ub;
  int32_T c12_h_i;
  int32_T c12_c_vlen;
  real_T c12_rank;
  int32_T c12_i679;
  int32_T c12_d_k;
  int32_T c12_u_b;
  real_T c12_i_i;
  int32_T c12_v_b;
  boolean_T c12_c_densityFlag;
  real_T c12_e_A;
  boolean_T c12_d_modeFlag;
  boolean_T c12_d_overflow;
  real_T c12_c_B;
  boolean_T c12_c_tooBig;
  real_T c12_u_x;
  real_T c12_w_y;
  boolean_T c12_e_modeFlag;
  real_T c12_v_x;
  int32_T c12_e_k;
  real_T c12_x_y;
  c12_emxArray_real_T *c12_b1;
  real_T c12_y_y;
  boolean_T c12_f_modeFlag;
  int32_T c12_i680;
  int32_T c12_xoffset;
  int32_T c12_b_ix;
  boolean_T c12_d_tooBig;
  int32_T c12_j_i;
  int32_T c12_i681;
  int32_T c12_i682;
  boolean_T c12_g_modeFlag;
  int32_T c12_i683;
  int32_T c12_i684;
  boolean_T c12_h_modeFlag;
  int32_T c12_i685;
  int32_T c12_i686;
  boolean_T c12_i_modeFlag;
  int32_T c12_b2_size[2];
  real_T c12_b_numKernElem;
  int32_T c12_i687;
  int32_T c12_i688;
  int32_T c12_i689;
  int32_T c12_i690;
  int32_T c12_i691;
  int32_T c12_i692;
  int32_T c12_i693;
  int32_T c12_i694;
  int32_T c12_i695;
  int32_T c12_hb_h;
  int32_T c12_ib_h;
  int32_T c12_rb_loop_ub;
  real_T c12_c_numKernElem;
  int32_T c12_i696;
  int32_T c12_i697;
  int32_T c12_i698;
  int32_T c12_i699;
  int32_T c12_b_b1_size[2];
  int32_T c12_sb_loop_ub;
  int32_T c12_i700;
  int32_T c12_b_b1;
  int32_T c12_c_b1;
  int32_T c12_i701;
  int32_T c12_i702;
  int32_T c12_i703;
  int32_T c12_jb_h;
  int32_T c12_kb_h;
  int32_T c12_tb_loop_ub;
  int32_T c12_w_b;
  int32_T c12_i704;
  int32_T c12_x_b;
  int32_T c12_i705;
  boolean_T c12_d_densityFlag;
  real_T c12_f_A;
  real_T c12_d_B;
  real_T c12_w_x;
  real_T c12_ab_y;
  real_T c12_x_x;
  real_T c12_bb_y;
  real_T c12_cb_y;
  boolean_T c12_e_tooBig;
  int32_T c12_k_i;
  real_T c12_l_i;
  boolean_T c12_j_modeFlag;
  boolean_T c12_f_tooBig;
  boolean_T c12_k_modeFlag;
  c12_emxArray_real_T *c12_b2;
  boolean_T c12_l_modeFlag;
  int32_T c12_i706;
  int32_T c12_i707;
  int32_T c12_i708;
  int32_T c12_i709;
  int32_T c12_i710;
  int32_T c12_i711;
  int32_T c12_i712;
  real_T c12_d_numKernElem;
  int32_T c12_i713;
  int32_T c12_i714;
  int32_T c12_i715;
  int32_T c12_i716;
  int32_T c12_d_b1[2];
  int32_T c12_b_b2[2];
  int32_T c12_i717;
  int32_T c12_y_b;
  int32_T c12_ab_b;
  int32_T c12_ub_loop_ub;
  int32_T c12_i718;
  int32_T c12_i719;
  int32_T c12_vb_loop_ub;
  int32_T c12_i720;
  int32_T c12_i721;
  int32_T c12_wb_loop_ub;
  int32_T c12_i722;
  int32_T c12_i723;
  int32_T c12_i724;
  int32_T c12_xb_loop_ub;
  int32_T c12_i725;
  int32_T c12_d_end;
  int32_T c12_d_trueCount;
  int32_T c12_m_i;
  c12_emxArray_creal_T *c12_b_nonzero_h;
  int32_T c12_i726;
  int32_T c12_d_partialTrueCount;
  int32_T c12_n_i;
  c12_emxArray_real_T *c12_lb_h;
  int32_T c12_i727;
  int32_T c12_yb_loop_ub;
  int32_T c12_i728;
  int32_T c12_i729;
  int32_T c12_ac_loop_ub;
  int32_T c12_i730;
  int32_T c12_i731;
  int32_T c12_bc_loop_ub;
  int32_T c12_i732;
  boolean_T c12_e_densityFlag;
  real_T c12_g_A;
  real_T c12_e_B;
  real_T c12_y_x;
  real_T c12_db_y;
  real_T c12_ab_x;
  real_T c12_eb_y;
  real_T c12_fb_y;
  boolean_T c12_g_tooBig;
  int32_T c12_o_i;
  boolean_T c12_m_modeFlag;
  boolean_T c12_n_modeFlag;
  int32_T c12_i733;
  int32_T c12_e_b1;
  int32_T c12_f_b1;
  int32_T c12_cc_loop_ub;
  int32_T c12_i734;
  boolean_T c12_o_modeFlag;
  int32_T c12_i735;
  int32_T c12_i736;
  int32_T c12_i737;
  int32_T c12_i738;
  real_T c12_e_numKernElem;
  int32_T c12_i739;
  int32_T c12_i740;
  int32_T c12_i741;
  int32_T c12_g_b1;
  int32_T c12_h_b1;
  int32_T c12_dc_loop_ub;
  int32_T c12_i742;
  boolean_T c12_p_modeFlag;
  int32_T c12_i743;
  int32_T c12_i744;
  int32_T c12_i745;
  int32_T c12_i746;
  real_T c12_f_numKernElem;
  int32_T c12_i747;
  int32_T c12_i748;
  int32_T c12_i_b1;
  int32_T c12_j_b1;
  int32_T c12_i749;
  int32_T c12_i750;
  static creal_T c12_dc4 = { 0.0,      /* re */
    1.0                                /* im */
  };

  int32_T c12_i751;
  int32_T c12_k_b1;
  int32_T c12_l_b1;
  int32_T c12_i752;
  int32_T c12_i753;
  int32_T c12_ec_loop_ub;
  int32_T c12_i754;
  int32_T c12_i755;
  int32_T c12_fc_loop_ub;
  int32_T c12_i756;
  int32_T c12_i757;
  int32_T c12_gc_loop_ub;
  int32_T c12_i758;
  boolean_T c12_f_densityFlag;
  real_T c12_h_A;
  real_T c12_f_B;
  real_T c12_bb_x;
  real_T c12_gb_y;
  real_T c12_cb_x;
  real_T c12_hb_y;
  real_T c12_ib_y;
  boolean_T c12_h_tooBig;
  int32_T c12_p_i;
  boolean_T c12_q_modeFlag;
  boolean_T c12_r_modeFlag;
  int32_T c12_i759;
  int32_T c12_m_b1;
  int32_T c12_n_b1;
  int32_T c12_hc_loop_ub;
  int32_T c12_i760;
  boolean_T c12_s_modeFlag;
  int32_T c12_i761;
  int32_T c12_i762;
  int32_T c12_i763;
  int32_T c12_i764;
  real_T c12_g_numKernElem;
  int32_T c12_i765;
  int32_T c12_i766;
  int32_T c12_i767;
  int32_T c12_o_b1;
  int32_T c12_p_b1;
  int32_T c12_ic_loop_ub;
  int32_T c12_i768;
  boolean_T c12_t_modeFlag;
  int32_T c12_i769;
  int32_T c12_i770;
  int32_T c12_i771;
  int32_T c12_i772;
  real_T c12_h_numKernElem;
  int32_T c12_i773;
  int32_T c12_i774;
  int32_T c12_b_b2_size[2];
  int32_T c12_c_b2;
  int32_T c12_d_b2;
  int32_T c12_i775;
  int32_T c12_i776;
  int32_T c12_i777;
  int32_T c12_e_b2;
  int32_T c12_f_b2;
  int32_T c12_i778;
  int32_T c12_q_b1;
  int32_T c12_r_b1;
  int32_T c12_i779;
  int32_T c12_g_b2;
  int32_T c12_h_b2;
  int32_T c12_i780;
  int32_T c12_tmp_size[2];
  int32_T c12_i781;
  int32_T c12_i782;
  int32_T c12_i783;
  int32_T c12_b_tmp_size[2];
  int32_T c12_i784;
  int32_T c12_i785;
  int32_T c12_i786;
  int32_T c12_s_b1;
  int32_T c12_t_b1;
  int32_T c12_i787;
  int32_T c12_i788;
  int32_T c12_bb_b;
  int32_T c12_cb_b;
  int32_T c12_i789;
  boolean_T guard1 = false;
  boolean_T exitg1;
  c12_outSizeT[0] = 39.0;
  c12_A = (real_T)c12_varargin_2->size[0] + 1.0;
  c12_b_x = c12_A;
  c12_c_x = c12_b_x;
  c12_y = c12_c_x / 2.0;
  c12_d_x = c12_y;
  c12_e_x = c12_d_x;
  c12_e_x = muDoubleScalarFloor(c12_e_x);
  c12_filter_center[0] = c12_e_x;
  c12_startT[0] = (real_T)c12_varargin_2->size[0] - c12_filter_center[0];
  c12_outSizeT[1] = 79.0;
  c12_b_A = (real_T)c12_varargin_2->size[1] + 1.0;
  c12_f_x = c12_b_A;
  c12_g_x = c12_f_x;
  c12_b_y = c12_g_x / 2.0;
  c12_h_x = c12_b_y;
  c12_i_x = c12_h_x;
  c12_i_x = muDoubleScalarFloor(c12_i_x);
  c12_filter_center[1] = c12_i_x;
  c12_startT[1] = (real_T)c12_varargin_2->size[1] - c12_filter_center[1];
  c12_b21 = (c12_varargin_2->size[0] == 0);
  c12_b22 = (c12_varargin_2->size[1] == 0);
  if (c12_b21 || c12_b22) {
    c12_i569 = c12_b->size[0] * c12_b->size[1];
    c12_b->size[0] = 39;
    c12_b->size[1] = 79;
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_b, c12_i569,
      &c12_sf_emlrtRTEI);
    c12_c_b = c12_b->size[0];
    c12_e_b = c12_b->size[1];
    for (c12_i570 = 0; c12_i570 < 3081; c12_i570++) {
      c12_b->data[c12_i570].re = 0.0;
      c12_b->data[c12_i570].im = 0.0;
    }
  } else {
    c12_emxInit_creal_T(chartInstance, &c12_unusedU0, 2, &c12_rh_emlrtRTEI);
    c12_emxInit_real_T(chartInstance, &c12_s, 2, &c12_pg_emlrtRTEI);
    c12_emxInit_creal_T(chartInstance, &c12_unusedU1, 2, &c12_rh_emlrtRTEI);
    c12_emxInit_real_T1(chartInstance, &c12_b_s, 1, &c12_sh_emlrtRTEI);
    c12_emxInit_boolean_T1(chartInstance, &c12_b_b, 1, &c12_th_emlrtRTEI);
    c12_emxInit_boolean_T1(chartInstance, &c12_d_b, 1, &c12_uh_emlrtRTEI);
    c12_emxInit_creal_T1(chartInstance, &c12_h_tmp, 1, &c12_dg_emlrtRTEI);
    c12_emxInit_boolean_T1(chartInstance, &c12_b_h, 1, &c12_vf_emlrtRTEI);
    c12_emxInit_real_T(chartInstance, &c12_c_s, 2, &c12_tg_emlrtRTEI);
    c12_emxInit_creal_T(chartInstance, &c12_b_varargin_2, 2, &c12_rg_emlrtRTEI);
    if ((real_T)(c12_varargin_2->size[0] * c12_varargin_2->size[1]) >= 49.0) {
      for (c12_i571 = 0; c12_i571 < 2; c12_i571++) {
        c12_filter_center[c12_i571] = (real_T)c12_varargin_2->size[c12_i571];
      }

      for (c12_i572 = 0; c12_i572 < 2; c12_i572++) {
        c12_j_x[c12_i572] = (c12_filter_center[c12_i572] != 1.0);
      }

      c12_c_y = true;
      c12_k = 0;
      exitg1 = false;
      while ((!exitg1) && (c12_k < 2)) {
        c12_b_k = 1.0 + (real_T)c12_k;
        if (!c12_j_x[(int32_T)c12_b_k - 1]) {
          c12_c_y = false;
          exitg1 = true;
        } else {
          c12_k++;
        }
      }

      if (c12_c_y) {
        c12_i575 = c12_h_tmp->size[0];
        c12_h_tmp->size[0] = c12_varargin_2->size[0] * c12_varargin_2->size[1];
        c12_emxEnsureCapacity_creal_T1(chartInstance, c12_h_tmp, c12_i575,
          &c12_tf_emlrtRTEI);
        c12_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
        for (c12_i578 = 0; c12_i578 <= c12_loop_ub; c12_i578++) {
          c12_h_tmp->data[c12_i578] = c12_varargin_2->data[c12_i578];
        }

        c12_i580 = c12_b_b->size[0];
        c12_b_b->size[0] = c12_h_tmp->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i580,
          &c12_wf_emlrtRTEI);
        c12_b_loop_ub = c12_h_tmp->size[0] - 1;
        for (c12_i581 = 0; c12_i581 <= c12_b_loop_ub; c12_i581++) {
          c12_b_b->data[c12_i581] = muDoubleScalarIsInf(c12_h_tmp->data[c12_i581]
            .re);
        }

        c12_i585 = c12_b_h->size[0];
        c12_b_h->size[0] = c12_h_tmp->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_h, c12_i585,
          &c12_xf_emlrtRTEI);
        c12_d_loop_ub = c12_h_tmp->size[0] - 1;
        for (c12_i587 = 0; c12_i587 <= c12_d_loop_ub; c12_i587++) {
          c12_b_h->data[c12_i587] = muDoubleScalarIsInf(c12_h_tmp->data[c12_i587]
            .im);
        }

        c12_i592 = c12_b_b->size[0];
        c12_b_b->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i592,
          &c12_ag_emlrtRTEI);
        c12_h_loop_ub = c12_b_b->size[0] - 1;
        for (c12_i595 = 0; c12_i595 <= c12_h_loop_ub; c12_i595++) {
          c12_b_b->data[c12_i595] = (c12_b_b->data[c12_i595] || c12_b_h->
            data[c12_i595]);
        }

        c12_i598 = c12_b_b->size[0];
        c12_b_b->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i598,
          &c12_bg_emlrtRTEI);
        c12_k_loop_ub = c12_b_b->size[0] - 1;
        for (c12_i602 = 0; c12_i602 <= c12_k_loop_ub; c12_i602++) {
          c12_b_b->data[c12_i602] = !c12_b_b->data[c12_i602];
        }

        c12_i605 = c12_d_b->size[0];
        c12_d_b->size[0] = c12_h_tmp->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_d_b, c12_i605,
          &c12_eg_emlrtRTEI);
        c12_n_loop_ub = c12_h_tmp->size[0] - 1;
        for (c12_i608 = 0; c12_i608 <= c12_n_loop_ub; c12_i608++) {
          c12_d_b->data[c12_i608] = muDoubleScalarIsNaN(c12_h_tmp->data[c12_i608]
            .re);
        }

        c12_i610 = c12_b_h->size[0];
        c12_b_h->size[0] = c12_h_tmp->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_h, c12_i610,
          &c12_fg_emlrtRTEI);
        c12_o_loop_ub = c12_h_tmp->size[0] - 1;
        for (c12_i612 = 0; c12_i612 <= c12_o_loop_ub; c12_i612++) {
          c12_b_h->data[c12_i612] = muDoubleScalarIsNaN(c12_h_tmp->data[c12_i612]
            .im);
        }

        c12_i615 = c12_d_b->size[0];
        c12_d_b->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_d_b, c12_i615,
          &c12_hg_emlrtRTEI);
        c12_r_loop_ub = c12_d_b->size[0] - 1;
        for (c12_i619 = 0; c12_i619 <= c12_r_loop_ub; c12_i619++) {
          c12_d_b->data[c12_i619] = (c12_d_b->data[c12_i619] || c12_b_h->
            data[c12_i619]);
        }

        c12_i621 = c12_d_b->size[0];
        c12_d_b->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_d_b, c12_i621,
          &c12_ig_emlrtRTEI);
        c12_u_loop_ub = c12_d_b->size[0] - 1;
        for (c12_i625 = 0; c12_i625 <= c12_u_loop_ub; c12_i625++) {
          c12_d_b->data[c12_i625] = !c12_d_b->data[c12_i625];
        }

        c12_i627 = c12_b_b->size[0];
        c12_b_b->size[0];
        c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i627,
          &c12_kg_emlrtRTEI);
        c12_w_loop_ub = c12_b_b->size[0] - 1;
        for (c12_i631 = 0; c12_i631 <= c12_w_loop_ub; c12_i631++) {
          c12_b_b->data[c12_i631] = (c12_b_b->data[c12_i631] && c12_d_b->
            data[c12_i631]);
        }

        if ((c12_b_b->size[0] == 1) || ((real_T)c12_b_b->size[0] != 1.0)) {
          c12_b27 = true;
        } else {
          c12_b27 = false;
        }

        if (c12_b27) {
        } else {
          c12_h_y = NULL;
          sf_mex_assign(&c12_h_y, sf_mex_create("y", c12_cv19, 10, 0U, 1U, 0U, 2,
            1, 51), false);
          c12_j_y = NULL;
          sf_mex_assign(&c12_j_y, sf_mex_create("y", c12_cv19, 10, 0U, 1U, 0U, 2,
            1, 51), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c12_h_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c12_j_y)));
        }

        c12_i_y = true;
        c12_vlen = (real_T)c12_b_b->size[0];
        c12_b_a = c12_vlen;
        c12_e_c = (int32_T)c12_b_a;
        c12_c_a = c12_e_c - 1;
        c12_vspread = c12_c_a;
        c12_j_b = c12_vspread;
        c12_i2 = c12_j_b;
        c12_d_a = c12_i2 + 1;
        c12_i2 = c12_d_a;
        c12_k_b = c12_i2;
        c12_l_b = c12_k_b;
        if (1 > c12_l_b) {
          c12_overflow = false;
        } else {
          c12_overflow = (c12_l_b > 2147483646);
        }

        if (c12_overflow) {
          c12_check_forloop_overflow_error(chartInstance, true);
        }

        c12_ix = 0;
        exitg1 = false;
        while ((!exitg1) && (c12_ix + 1 <= c12_i2)) {
          if (!c12_b_b->data[c12_ix]) {
            c12_i_y = false;
            exitg1 = true;
          } else {
            c12_ix++;
          }
        }

        if (c12_i_y) {
          c12_i647 = c12_b_varargin_2->size[0] * c12_b_varargin_2->size[1];
          c12_b_varargin_2->size[0] = c12_varargin_2->size[0];
          c12_b_varargin_2->size[1] = c12_varargin_2->size[1];
          c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_varargin_2,
            c12_i647, &c12_rg_emlrtRTEI);
          c12_i_varargin_2 = c12_b_varargin_2->size[0];
          c12_j_varargin_2 = c12_b_varargin_2->size[1];
          c12_hb_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
          for (c12_i649 = 0; c12_i649 <= c12_hb_loop_ub; c12_i649++) {
            c12_b_varargin_2->data[c12_i649] = c12_varargin_2->data[c12_i649];
          }

          c12_svd(chartInstance, c12_b_varargin_2, c12_unusedU0, c12_s,
                  c12_unusedU1);
          c12_i651 = c12_s->size[0];
          c12_i652 = c12_s->size[1];
          c12_i653 = c12_c_s->size[0] * c12_c_s->size[1];
          c12_c_s->size[0] = c12_i651;
          c12_c_s->size[1] = c12_i652;
          c12_emxEnsureCapacity_real_T(chartInstance, c12_c_s, c12_i653,
            &c12_tg_emlrtRTEI);
          c12_ib_loop_ub = c12_i652 - 1;
          for (c12_i655 = 0; c12_i655 <= c12_ib_loop_ub; c12_i655++) {
            c12_jb_loop_ub = c12_i651 - 1;
            for (c12_i656 = 0; c12_i656 <= c12_jb_loop_ub; c12_i656++) {
              c12_c_s->data[c12_i656 + c12_c_s->size[0] * c12_i655] =
                c12_s->data[c12_i656 + c12_s->size[0] * c12_i655];
            }
          }

          c12_diag(chartInstance, c12_c_s, c12_b_s);
          c12_d_varargin_1 = c12_varargin_2->size[0];
          c12_k_varargin_2 = c12_varargin_2->size[1];
          c12_e_varargin_1 = c12_d_varargin_1;
          c12_l_varargin_2 = c12_k_varargin_2;
          if ((c12_e_varargin_1 == 0) || (c12_l_varargin_2 == 0)) {
            c12_n = 0;
          } else if (c12_e_varargin_1 > c12_l_varargin_2) {
            c12_n = c12_e_varargin_1;
          } else {
            c12_n = c12_l_varargin_2;
          }

          c12_b_n = (real_T)c12_n;
          if ((c12_b_s->size[0] == 1) || ((real_T)c12_b_s->size[0] != 1.0)) {
            c12_b28 = true;
          } else {
            c12_b28 = false;
          }

          if (c12_b28) {
          } else {
            c12_n_y = NULL;
            sf_mex_assign(&c12_n_y, sf_mex_create("y", c12_cv2, 10, 0U, 1U, 0U,
              2, 1, 36), false);
            c12_o_y = NULL;
            sf_mex_assign(&c12_o_y, sf_mex_create("y", c12_cv2, 10, 0U, 1U, 0U,
              2, 1, 36), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                              c12_n_y, 14, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                               14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "message", 1U, 1U, 14, c12_o_y)));
          }

          if ((real_T)c12_b_s->size[0] >= 1.0) {
          } else {
            c12_p_y = NULL;
            sf_mex_assign(&c12_p_y, sf_mex_create("y", c12_cv20, 10, 0U, 1U, 0U,
              2, 1, 39), false);
            c12_q_y = NULL;
            sf_mex_assign(&c12_q_y, sf_mex_create("y", c12_cv20, 10, 0U, 1U, 0U,
              2, 1, 39), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                              c12_p_y, 14, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                               14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "message", 1U, 1U, 14, c12_q_y)));
          }

          c12_c_n = c12_b_s->size[0];
          if (c12_c_n <= 2) {
            if (c12_c_n == 1) {
              c12_maxval = c12_b_s->data[0];
            } else if (c12_b_s->data[0] < c12_b_s->data[1]) {
              c12_maxval = c12_b_s->data[1];
            } else {
              c12_o_x = c12_b_s->data[0];
              c12_n_b = muDoubleScalarIsNaN(c12_o_x);
              if (c12_n_b) {
                c12_p_x = c12_b_s->data[1];
                c12_o_b = muDoubleScalarIsNaN(c12_p_x);
                if (!c12_o_b) {
                  c12_maxval = c12_b_s->data[1];
                } else {
                  c12_maxval = c12_b_s->data[0];
                }
              } else {
                c12_maxval = c12_b_s->data[0];
              }
            }
          } else {
            c12_d_n = c12_b_s->size[0];
            c12_m_x = c12_b_s->data[0];
            c12_n_x = c12_m_x;
            c12_m_b = muDoubleScalarIsNaN(c12_n_x);
            c12_p = !c12_m_b;
            if (c12_p) {
              c12_idx = 1;
            } else {
              c12_idx = 0;
              c12_p_b = c12_d_n;
              c12_q_b = c12_p_b;
              if (2 > c12_q_b) {
                c12_b_overflow = false;
              } else {
                c12_b_overflow = (c12_q_b > 2147483646);
              }

              if (c12_b_overflow) {
                c12_check_forloop_overflow_error(chartInstance, true);
              }

              c12_c_k = 2;
              exitg1 = false;
              while ((!exitg1) && (c12_c_k <= c12_d_n)) {
                c12_s_x = c12_b_s->data[c12_c_k - 1];
                c12_t_x = c12_s_x;
                c12_t_b = muDoubleScalarIsNaN(c12_t_x);
                c12_b_p = !c12_t_b;
                if (c12_b_p) {
                  c12_idx = c12_c_k;
                  exitg1 = true;
                } else {
                  c12_c_k++;
                }
              }
            }

            if (c12_idx == 0) {
              c12_maxval = c12_b_s->data[0];
            } else {
              c12_first = c12_idx - 1;
              c12_last = c12_c_n;
              c12_ex = c12_b_s->data[c12_first];
              c12_i677 = c12_first + 2;
              c12_e_a = c12_i677;
              c12_r_b = c12_last;
              c12_f_a = c12_e_a;
              c12_s_b = c12_r_b;
              if (c12_f_a > c12_s_b) {
                c12_c_overflow = false;
              } else {
                c12_c_overflow = (c12_s_b > 2147483646);
              }

              if (c12_c_overflow) {
                c12_check_forloop_overflow_error(chartInstance, true);
              }

              for (c12_d_k = c12_i677 - 1; c12_d_k < c12_last; c12_d_k++) {
                if (c12_ex < c12_b_s->data[c12_d_k]) {
                  c12_ex = c12_b_s->data[c12_d_k];
                }
              }

              c12_maxval = c12_ex;
            }
          }

          c12_tol = c12_b_n * c12_maxval * 2.2204460492503131E-16;
          c12_i672 = c12_b_b->size[0];
          c12_b_b->size[0] = c12_b_s->size[0];
          c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i672,
            &c12_wg_emlrtRTEI);
          c12_ob_loop_ub = c12_b_s->size[0] - 1;
          for (c12_i675 = 0; c12_i675 <= c12_ob_loop_ub; c12_i675++) {
            c12_b_b->data[c12_i675] = (c12_b_s->data[c12_i675] > c12_tol);
          }

          if ((c12_b_b->size[0] == 1) || ((real_T)c12_b_b->size[0] != 1.0)) {
            c12_b29 = true;
          } else {
            c12_b29 = false;
          }

          if (c12_b29) {
          } else {
            c12_u_y = NULL;
            sf_mex_assign(&c12_u_y, sf_mex_create("y", c12_cv2, 10, 0U, 1U, 0U,
              2, 1, 36), false);
            c12_v_y = NULL;
            sf_mex_assign(&c12_v_y, sf_mex_create("y", c12_cv2, 10, 0U, 1U, 0U,
              2, 1, 36), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                              c12_u_y, 14, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                               14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "message", 1U, 1U, 14, c12_v_y)));
          }

          c12_b_vlen = c12_b_b->size[0];
          if ((c12_b_b->size[0] == 0) || (c12_b_vlen == 0)) {
            c12_rank = 0.0;
          } else {
            c12_c_vlen = c12_b_vlen;
            c12_rank = (real_T)c12_b_b->data[0];
            c12_u_b = c12_c_vlen;
            c12_v_b = c12_u_b;
            if (2 > c12_v_b) {
              c12_d_overflow = false;
            } else {
              c12_d_overflow = (c12_v_b > 2147483646);
            }

            if (c12_d_overflow) {
              c12_check_forloop_overflow_error(chartInstance, true);
            }

            for (c12_e_k = 2; c12_e_k <= c12_c_vlen; c12_e_k++) {
              c12_xoffset = c12_e_k;
              c12_b_ix = c12_xoffset - 1;
              c12_rank += (real_T)c12_b_b->data[c12_b_ix];
            }
          }

          if (c12_rank == 1.0) {
            c12_separable = true;
          } else {
            c12_separable = false;
          }
        } else {
          c12_separable = false;
        }
      } else {
        c12_separable = false;
      }
    } else {
      c12_separable = false;
    }

    c12_emxFree_creal_T(chartInstance, &c12_b_varargin_2);
    c12_emxFree_real_T(chartInstance, &c12_c_s);
    c12_emxFree_boolean_T(chartInstance, &c12_d_b);
    c12_emxInit_real_T(chartInstance, &c12_a, 2, &c12_qh_emlrtRTEI);
    c12_emxInit_creal_T1(chartInstance, &c12_nonzero_h, 1, &c12_vh_emlrtRTEI);
    if (c12_separable) {
      for (c12_i574 = 0; c12_i574 < 3081; c12_i574++) {
        chartInstance->c12_b_varargin_1[c12_i574] = c12_c_varargin_1[c12_i574];
      }

      for (c12_i577 = 0; c12_i577 < 2; c12_i577++) {
        c12_c_startT[c12_i577] = c12_startT[c12_i577];
      }

      c12_emxInit_creal_T(chartInstance, &c12_c_varargin_2, 2, &c12_uf_emlrtRTEI);
      c12_padImage(chartInstance, chartInstance->c12_b_varargin_1, c12_c_startT,
                   c12_a);
      c12_i579 = c12_c_varargin_2->size[0] * c12_c_varargin_2->size[1];
      c12_c_varargin_2->size[0] = c12_varargin_2->size[0];
      c12_c_varargin_2->size[1] = c12_varargin_2->size[1];
      c12_emxEnsureCapacity_creal_T(chartInstance, c12_c_varargin_2, c12_i579,
        &c12_uf_emlrtRTEI);
      c12_d_varargin_2 = c12_c_varargin_2->size[0];
      c12_e_varargin_2 = c12_c_varargin_2->size[1];
      c12_c_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
      for (c12_i584 = 0; c12_i584 <= c12_c_loop_ub; c12_i584++) {
        c12_c_varargin_2->data[c12_i584] = c12_varargin_2->data[c12_i584];
      }

      c12_emxInit_real_T(chartInstance, &c12_d_s, 2, &c12_yf_emlrtRTEI);
      c12_svd(chartInstance, c12_c_varargin_2, c12_unusedU0, c12_s, c12_unusedU1);
      c12_i586 = c12_s->size[0];
      c12_i589 = c12_s->size[1];
      c12_i591 = c12_d_s->size[0] * c12_d_s->size[1];
      c12_d_s->size[0] = c12_i586;
      c12_d_s->size[1] = c12_i589;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_d_s, c12_i591,
        &c12_yf_emlrtRTEI);
      c12_g_loop_ub = c12_i589 - 1;
      c12_emxFree_creal_T(chartInstance, &c12_c_varargin_2);
      for (c12_i597 = 0; c12_i597 <= c12_g_loop_ub; c12_i597++) {
        c12_j_loop_ub = c12_i586 - 1;
        for (c12_i600 = 0; c12_i600 <= c12_j_loop_ub; c12_i600++) {
          c12_d_s->data[c12_i600 + c12_d_s->size[0] * c12_i597] = c12_s->
            data[c12_i600 + c12_s->size[0] * c12_i597];
        }
      }

      c12_diag(chartInstance, c12_d_s, c12_b_s);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c12_unusedU0->size[1]);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c12_b_s->size[0]);
      c12_i601 = c12_unusedU0->size[0];
      c12_i603 = c12_h_tmp->size[0];
      c12_h_tmp->size[0] = c12_i601;
      c12_emxEnsureCapacity_creal_T1(chartInstance, c12_h_tmp, c12_i603,
        &c12_cg_emlrtRTEI);
      c12_l_loop_ub = c12_i601 - 1;
      c12_emxFree_real_T(chartInstance, &c12_d_s);
      for (c12_i606 = 0; c12_i606 <= c12_l_loop_ub; c12_i606++) {
        c12_h_tmp->data[c12_i606] = c12_unusedU0->data[c12_i606];
      }

      c12_g_b = c12_b_s->data[0];
      c12_f_sqrt(chartInstance, &c12_g_b);
      c12_i611 = c12_h_tmp->size[0];
      c12_h_tmp->size[0];
      c12_emxEnsureCapacity_creal_T1(chartInstance, c12_h_tmp, c12_i611,
        &c12_gg_emlrtRTEI);
      c12_p_loop_ub = c12_h_tmp->size[0] - 1;
      for (c12_i613 = 0; c12_i613 <= c12_p_loop_ub; c12_i613++) {
        c12_h_tmp->data[c12_i613].re *= c12_g_b;
        c12_h_tmp->data[c12_i613].im *= c12_g_b;
      }

      c12_emxInit_creal_T(chartInstance, &c12_hrow, 2, &c12_mg_emlrtRTEI);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c12_unusedU1->size[1]);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c12_b_s->size[0]);
      c12_i618 = c12_unusedU1->size[0];
      c12_i620 = c12_hrow->size[0] * c12_hrow->size[1];
      c12_hrow->size[0] = 1;
      c12_hrow->size[1] = c12_i618;
      c12_emxEnsureCapacity_creal_T(chartInstance, c12_hrow, c12_i620,
        &c12_jg_emlrtRTEI);
      c12_t_loop_ub = c12_i618 - 1;
      for (c12_i623 = 0; c12_i623 <= c12_t_loop_ub; c12_i623++) {
        c12_hrow->data[c12_hrow->size[0] * c12_i623].re = c12_unusedU1->
          data[c12_i623].re;
        c12_hrow->data[c12_hrow->size[0] * c12_i623].im = -c12_unusedU1->
          data[c12_i623].im;
      }

      c12_i_b = c12_b_s->data[0];
      c12_f_sqrt(chartInstance, &c12_i_b);
      c12_i629 = c12_hrow->size[0] * c12_hrow->size[1];
      c12_i630 = c12_hrow->size[0] * c12_hrow->size[1];
      c12_hrow->size[0] = 1;
      c12_hrow->size[1];
      c12_emxEnsureCapacity_creal_T(chartInstance, c12_hrow, c12_i630,
        &c12_mg_emlrtRTEI);
      c12_b_hrow = c12_hrow->size[0];
      c12_c_hrow = c12_hrow->size[1];
      c12_y_loop_ub = c12_i629 - 1;
      for (c12_i635 = 0; c12_i635 <= c12_y_loop_ub; c12_i635++) {
        c12_hrow->data[c12_i635].re *= c12_i_b;
        c12_hrow->data[c12_i635].im *= c12_i_b;
      }

      c12_emxInit_boolean_T(chartInstance, &c12_r_h, 2, &c12_vf_emlrtRTEI);
      c12_out_size_row[0] = (real_T)c12_a->size[0];
      c12_out_size_row[1] = 79.0;
      c12_start[0] = 0.0;
      c12_start[1] = c12_startT[1];
      c12_i638 = c12_r_h->size[0] * c12_r_h->size[1];
      c12_r_h->size[0] = 1;
      c12_r_h->size[1] = c12_hrow->size[1];
      c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r_h, c12_i638,
        &c12_vf_emlrtRTEI);
      c12_s_h = c12_r_h->size[0];
      c12_t_h = c12_r_h->size[1];
      c12_db_loop_ub = c12_hrow->size[0] * c12_hrow->size[1] - 1;
      for (c12_i642 = 0; c12_i642 <= c12_db_loop_ub; c12_i642++) {
        c12_r_h->data[c12_i642] = ((c12_hrow->data[c12_i642].re != c12_dc0.re) ||
          (c12_hrow->data[c12_i642].im != c12_dc0.im));
      }

      c12_emxInit_boolean_T(chartInstance, &c12_u_h, 2, &c12_vf_emlrtRTEI);
      c12_i644 = c12_u_h->size[0] * c12_u_h->size[1];
      c12_u_h->size[0] = 1;
      c12_u_h->size[1] = c12_hrow->size[1];
      c12_emxEnsureCapacity_boolean_T(chartInstance, c12_u_h, c12_i644,
        &c12_vf_emlrtRTEI);
      c12_x_h = c12_u_h->size[0];
      c12_y_h = c12_u_h->size[1];
      c12_fb_loop_ub = c12_hrow->size[0] * c12_hrow->size[1] - 1;
      for (c12_i646 = 0; c12_i646 <= c12_fb_loop_ub; c12_i646++) {
        c12_u_h->data[c12_i646] = ((c12_hrow->data[c12_i646].re != c12_dc0.re) ||
          (c12_hrow->data[c12_i646].im != c12_dc0.im));
      }

      c12_i648 = c12_b_h->size[0];
      c12_b_h->size[0] = c12_u_h->size[1];
      c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_h, c12_i648,
        &c12_og_emlrtRTEI);
      c12_gb_loop_ub = c12_u_h->size[1] - 1;
      c12_emxFree_boolean_T(chartInstance, &c12_u_h);
      for (c12_i650 = 0; c12_i650 <= c12_gb_loop_ub; c12_i650++) {
        c12_b_h->data[c12_i650] = c12_r_h->data[c12_i650];
      }

      c12_c_end = c12_b_h->size[0] - 1;
      c12_c_trueCount = 0;
      for (c12_f_i = 0; c12_f_i <= c12_c_end; c12_f_i++) {
        if (c12_b_h->data[c12_f_i]) {
          c12_c_trueCount++;
        }
      }

      c12_i654 = c12_nonzero_h->size[0];
      c12_nonzero_h->size[0] = c12_c_trueCount;
      c12_emxEnsureCapacity_creal_T1(chartInstance, c12_nonzero_h, c12_i654,
        &c12_sg_emlrtRTEI);
      c12_c_partialTrueCount = 0;
      for (c12_g_i = 0; c12_g_i <= c12_c_end; c12_g_i++) {
        if (c12_b_h->data[c12_g_i]) {
          c12_nonzero_h->data[c12_c_partialTrueCount].re = c12_hrow->
            data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_g_i + 1, 1,
            c12_hrow->size[1]) - 1].re;
          c12_nonzero_h->data[c12_c_partialTrueCount].im = c12_hrow->
            data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_g_i + 1, 1,
            c12_hrow->size[1]) - 1].im;
          c12_c_partialTrueCount++;
        }
      }

      c12_emxInit_real_T(chartInstance, &c12_ab_h, 2, &c12_pg_emlrtRTEI);
      c12_i657 = c12_ab_h->size[0] * c12_ab_h->size[1];
      c12_ab_h->size[0] = 1;
      c12_ab_h->size[1] = c12_hrow->size[1];
      c12_emxEnsureCapacity_real_T(chartInstance, c12_ab_h, c12_i657,
        &c12_pg_emlrtRTEI);
      c12_bb_h = c12_ab_h->size[0];
      c12_cb_h = c12_ab_h->size[1];
      c12_kb_loop_ub = c12_hrow->size[0] * c12_hrow->size[1] - 1;
      for (c12_i664 = 0; c12_i664 <= c12_kb_loop_ub; c12_i664++) {
        c12_ab_h->data[c12_i664] = c12_hrow->data[c12_i664].re;
      }

      c12_i666 = c12_b_s->size[0];
      c12_b_s->size[0] = c12_nonzero_h->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_b_s, c12_i666,
        &c12_qg_emlrtRTEI);
      c12_lb_loop_ub = c12_nonzero_h->size[0] - 1;
      for (c12_i668 = 0; c12_i668 <= c12_lb_loop_ub; c12_i668++) {
        c12_b_s->data[c12_i668] = c12_nonzero_h->data[c12_i668].re;
      }

      c12_i670 = c12_r_h->size[0] * c12_r_h->size[1];
      c12_r_h->size[0] = 1;
      c12_r_h->size[1] = c12_hrow->size[1];
      c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r_h, c12_i670,
        &c12_vf_emlrtRTEI);
      c12_db_h = c12_r_h->size[0];
      c12_eb_h = c12_r_h->size[1];
      c12_nb_loop_ub = c12_hrow->size[0] * c12_hrow->size[1] - 1;
      for (c12_i673 = 0; c12_i673 <= c12_nb_loop_ub; c12_i673++) {
        c12_r_h->data[c12_i673] = ((c12_hrow->data[c12_i673].re != c12_dc0.re) ||
          (c12_hrow->data[c12_i673].im != c12_dc0.im));
      }

      c12_b_densityFlag = false;
      c12_d_A = (real_T)c12_b_s->size[0];
      c12_b_B = (real_T)c12_ab_h->size[1];
      c12_q_x = c12_d_A;
      c12_r_y = c12_b_B;
      c12_r_x = c12_q_x;
      c12_s_y = c12_r_y;
      c12_t_y = c12_r_x / c12_s_y;
      if (c12_t_y > 0.05) {
        c12_b_densityFlag = true;
      }

      c12_b_tooBig = true;
      for (c12_h_i = 0; c12_h_i < 2; c12_h_i++) {
        c12_i_i = 1.0 + (real_T)c12_h_i;
        if (c12_b_tooBig && (c12_out_size_row[(int32_T)c12_i_i - 1] > 65500.0))
        {
          c12_c_tooBig = true;
        } else {
          c12_c_tooBig = false;
        }

        c12_b_tooBig = c12_c_tooBig;
      }

      if (c12_b_densityFlag && (!c12_b_tooBig)) {
        c12_d_modeFlag = true;
      } else {
        c12_d_modeFlag = false;
      }

      if (c12_d_modeFlag) {
        c12_e_modeFlag = true;
      } else {
        c12_e_modeFlag = false;
      }

      c12_emxInit_real_T(chartInstance, &c12_b1, 2, &c12_ug_emlrtRTEI);
      c12_f_modeFlag = c12_e_modeFlag;
      c12_i680 = c12_b1->size[0] * c12_b1->size[1];
      c12_b1->size[0] = (int32_T)c12_out_size_row[0];
      c12_b1->size[1] = 79;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_b1, c12_i680,
        &c12_yg_emlrtRTEI);
      if (c12_f_modeFlag) {
        for (c12_i682 = 0; c12_i682 < 2; c12_i682++) {
          c12_padSizeT[c12_i682] = (real_T)c12_a->size[c12_i682];
        }

        for (c12_i684 = 0; c12_i684 < 2; c12_i684++) {
          c12_filter_center[c12_i684] = (real_T)c12_ab_h->size[c12_i684];
        }

        for (c12_i686 = 0; c12_i686 < 2; c12_i686++) {
          c12_padSizeT[c12_i686];
        }

        for (c12_i687 = 0; c12_i687 < 2; c12_i687++) {
          c12_filter_center[c12_i687];
        }

        ippfilter_real64(&c12_a->data[0], &c12_b1->data[0], c12_out_size_row,
                         2.0, c12_padSizeT, &c12_ab_h->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i681 = 0; c12_i681 < 2; c12_i681++) {
          c12_padSizeT[c12_i681] = (real_T)c12_a->size[c12_i681];
        }

        for (c12_i683 = 0; c12_i683 < 2; c12_i683++) {
          c12_filter_center[c12_i683] = (real_T)c12_r_h->size[c12_i683];
        }

        for (c12_i685 = 0; c12_i685 < 2; c12_i685++) {
          c12_padSizeT[c12_i685];
        }

        c12_b_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i688 = 0; c12_i688 < 2; c12_i688++) {
          c12_filter_center[c12_i688];
        }

        imfilter_real64(&c12_a->data[0], &c12_b1->data[0], 2.0, c12_out_size_row,
                        2.0, c12_padSizeT, &c12_b_s->data[0], c12_b_numKernElem,
                        &c12_r_h->data[0], 2.0, c12_filter_center, c12_start,
                        2.0, true, false);
      }

      c12_i691 = c12_ab_h->size[0] * c12_ab_h->size[1];
      c12_ab_h->size[0] = 1;
      c12_ab_h->size[1] = c12_hrow->size[1];
      c12_emxEnsureCapacity_real_T(chartInstance, c12_ab_h, c12_i691,
        &c12_vg_emlrtRTEI);
      c12_hb_h = c12_ab_h->size[0];
      c12_ib_h = c12_ab_h->size[1];
      c12_rb_loop_ub = c12_hrow->size[0] * c12_hrow->size[1] - 1;
      for (c12_i697 = 0; c12_i697 <= c12_rb_loop_ub; c12_i697++) {
        c12_ab_h->data[c12_i697] = c12_hrow->data[c12_i697].im;
      }

      c12_i699 = c12_b_s->size[0];
      c12_b_s->size[0] = c12_nonzero_h->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_b_s, c12_i699,
        &c12_xg_emlrtRTEI);
      c12_sb_loop_ub = c12_nonzero_h->size[0] - 1;
      for (c12_i700 = 0; c12_i700 <= c12_sb_loop_ub; c12_i700++) {
        c12_b_s->data[c12_i700] = c12_nonzero_h->data[c12_i700].im;
      }

      c12_i702 = c12_r_h->size[0] * c12_r_h->size[1];
      c12_r_h->size[0] = 1;
      c12_r_h->size[1] = c12_hrow->size[1];
      c12_emxEnsureCapacity_boolean_T(chartInstance, c12_r_h, c12_i702,
        &c12_vf_emlrtRTEI);
      c12_jb_h = c12_r_h->size[0];
      c12_kb_h = c12_r_h->size[1];
      c12_tb_loop_ub = c12_hrow->size[0] * c12_hrow->size[1] - 1;
      for (c12_i704 = 0; c12_i704 <= c12_tb_loop_ub; c12_i704++) {
        c12_r_h->data[c12_i704] = ((c12_hrow->data[c12_i704].re != c12_dc0.re) ||
          (c12_hrow->data[c12_i704].im != c12_dc0.im));
      }

      c12_emxFree_creal_T(chartInstance, &c12_hrow);
      c12_d_densityFlag = false;
      c12_f_A = (real_T)c12_b_s->size[0];
      c12_d_B = (real_T)c12_ab_h->size[1];
      c12_w_x = c12_f_A;
      c12_ab_y = c12_d_B;
      c12_x_x = c12_w_x;
      c12_bb_y = c12_ab_y;
      c12_cb_y = c12_x_x / c12_bb_y;
      if (c12_cb_y > 0.05) {
        c12_d_densityFlag = true;
      }

      c12_e_tooBig = true;
      for (c12_k_i = 0; c12_k_i < 2; c12_k_i++) {
        c12_l_i = 1.0 + (real_T)c12_k_i;
        if (c12_e_tooBig && (c12_out_size_row[(int32_T)c12_l_i - 1] > 65500.0))
        {
          c12_f_tooBig = true;
        } else {
          c12_f_tooBig = false;
        }

        c12_e_tooBig = c12_f_tooBig;
      }

      if (c12_d_densityFlag && (!c12_e_tooBig)) {
        c12_j_modeFlag = true;
      } else {
        c12_j_modeFlag = false;
      }

      if (c12_j_modeFlag) {
        c12_k_modeFlag = true;
      } else {
        c12_k_modeFlag = false;
      }

      c12_emxInit_real_T(chartInstance, &c12_b2, 2, &c12_ah_emlrtRTEI);
      c12_l_modeFlag = c12_k_modeFlag;
      c12_i706 = c12_b2->size[0] * c12_b2->size[1];
      c12_b2->size[0] = (int32_T)c12_out_size_row[0];
      c12_b2->size[1] = 79;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_b2, c12_i706,
        &c12_yg_emlrtRTEI);
      if (c12_l_modeFlag) {
        for (c12_i708 = 0; c12_i708 < 2; c12_i708++) {
          c12_padSizeT[c12_i708] = (real_T)c12_a->size[c12_i708];
        }

        for (c12_i710 = 0; c12_i710 < 2; c12_i710++) {
          c12_filter_center[c12_i710] = (real_T)c12_ab_h->size[c12_i710];
        }

        for (c12_i712 = 0; c12_i712 < 2; c12_i712++) {
          c12_padSizeT[c12_i712];
        }

        for (c12_i713 = 0; c12_i713 < 2; c12_i713++) {
          c12_filter_center[c12_i713];
        }

        ippfilter_real64(&c12_a->data[0], &c12_b2->data[0], c12_out_size_row,
                         2.0, c12_padSizeT, &c12_ab_h->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i707 = 0; c12_i707 < 2; c12_i707++) {
          c12_padSizeT[c12_i707] = (real_T)c12_a->size[c12_i707];
        }

        for (c12_i709 = 0; c12_i709 < 2; c12_i709++) {
          c12_filter_center[c12_i709] = (real_T)c12_r_h->size[c12_i709];
        }

        for (c12_i711 = 0; c12_i711 < 2; c12_i711++) {
          c12_padSizeT[c12_i711];
        }

        c12_d_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i714 = 0; c12_i714 < 2; c12_i714++) {
          c12_filter_center[c12_i714];
        }

        imfilter_real64(&c12_a->data[0], &c12_b2->data[0], 2.0, c12_out_size_row,
                        2.0, c12_padSizeT, &c12_b_s->data[0], c12_d_numKernElem,
                        &c12_r_h->data[0], 2.0, c12_filter_center, c12_start,
                        2.0, true, false);
      }

      c12_emxFree_real_T(chartInstance, &c12_ab_h);
      c12_emxFree_boolean_T(chartInstance, &c12_r_h);
      for (c12_i715 = 0; c12_i715 < 2; c12_i715++) {
        c12_d_b1[c12_i715] = c12_b1->size[c12_i715];
      }

      for (c12_i716 = 0; c12_i716 < 2; c12_i716++) {
        c12_b_b2[c12_i716] = c12_b2->size[c12_i716];
      }

      _SFD_SIZE_EQ_CHECK_ND(c12_d_b1, c12_b_b2, 2);
      c12_i717 = c12_b->size[0] * c12_b->size[1];
      c12_b->size[0] = c12_b1->size[0];
      c12_b->size[1] = 79;
      c12_emxEnsureCapacity_creal_T(chartInstance, c12_b, c12_i717,
        &c12_dh_emlrtRTEI);
      c12_y_b = c12_b->size[0];
      c12_ab_b = c12_b->size[1];
      c12_ub_loop_ub = c12_b1->size[0] * c12_b1->size[1] - 1;
      for (c12_i718 = 0; c12_i718 <= c12_ub_loop_ub; c12_i718++) {
        c12_b->data[c12_i718].re = c12_b1->data[c12_i718];
        c12_b->data[c12_i718].im = c12_b2->data[c12_i718];
      }

      c12_emxFree_real_T(chartInstance, &c12_b2);
      c12_start[0] = c12_startT[0];
      c12_start[1] = 0.0;
      c12_i719 = c12_b_b->size[0];
      c12_b_b->size[0] = c12_h_tmp->size[0];
      c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i719,
        &c12_vf_emlrtRTEI);
      c12_vb_loop_ub = c12_h_tmp->size[0] - 1;
      for (c12_i720 = 0; c12_i720 <= c12_vb_loop_ub; c12_i720++) {
        c12_b_b->data[c12_i720] = ((c12_h_tmp->data[c12_i720].re != c12_dc0.re) ||
          (c12_h_tmp->data[c12_i720].im != c12_dc0.im));
      }

      c12_i721 = c12_b_h->size[0];
      c12_b_h->size[0] = c12_h_tmp->size[0];
      c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_h, c12_i721,
        &c12_vf_emlrtRTEI);
      c12_wb_loop_ub = c12_h_tmp->size[0] - 1;
      for (c12_i722 = 0; c12_i722 <= c12_wb_loop_ub; c12_i722++) {
        c12_b_h->data[c12_i722] = ((c12_h_tmp->data[c12_i722].re != c12_dc0.re) ||
          (c12_h_tmp->data[c12_i722].im != c12_dc0.im));
      }

      c12_i723 = c12_b_h->size[0];
      c12_i724 = c12_b_b->size[0];
      c12_b_b->size[0] = c12_i723;
      c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i724,
        &c12_og_emlrtRTEI);
      c12_xb_loop_ub = c12_i723 - 1;
      for (c12_i725 = 0; c12_i725 <= c12_xb_loop_ub; c12_i725++) {
        c12_b_b->data[c12_i725];
      }

      c12_d_end = c12_b_b->size[0] - 1;
      c12_d_trueCount = 0;
      for (c12_m_i = 0; c12_m_i <= c12_d_end; c12_m_i++) {
        if (c12_b_b->data[c12_m_i]) {
          c12_d_trueCount++;
        }
      }

      c12_emxInit_creal_T1(chartInstance, &c12_b_nonzero_h, 1, &c12_vh_emlrtRTEI);
      c12_i726 = c12_b_nonzero_h->size[0];
      c12_b_nonzero_h->size[0] = c12_d_trueCount;
      c12_emxEnsureCapacity_creal_T1(chartInstance, c12_b_nonzero_h, c12_i726,
        &c12_eh_emlrtRTEI);
      c12_d_partialTrueCount = 0;
      for (c12_n_i = 0; c12_n_i <= c12_d_end; c12_n_i++) {
        if (c12_b_b->data[c12_n_i]) {
          c12_b_nonzero_h->data[c12_d_partialTrueCount].re = c12_h_tmp->
            data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_n_i + 1, 1,
            c12_h_tmp->size[0]) - 1].re;
          c12_b_nonzero_h->data[c12_d_partialTrueCount].im = c12_h_tmp->
            data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_n_i + 1, 1,
            c12_h_tmp->size[0]) - 1].im;
          c12_d_partialTrueCount++;
        }
      }

      c12_emxInit_real_T1(chartInstance, &c12_lb_h, 1, &c12_pg_emlrtRTEI);
      c12_i727 = c12_lb_h->size[0];
      c12_lb_h->size[0] = c12_h_tmp->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_lb_h, c12_i727,
        &c12_pg_emlrtRTEI);
      c12_yb_loop_ub = c12_h_tmp->size[0] - 1;
      for (c12_i728 = 0; c12_i728 <= c12_yb_loop_ub; c12_i728++) {
        c12_lb_h->data[c12_i728] = c12_h_tmp->data[c12_i728].re;
      }

      c12_i729 = c12_b_s->size[0];
      c12_b_s->size[0] = c12_b_nonzero_h->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_b_s, c12_i729,
        &c12_qg_emlrtRTEI);
      c12_ac_loop_ub = c12_b_nonzero_h->size[0] - 1;
      for (c12_i730 = 0; c12_i730 <= c12_ac_loop_ub; c12_i730++) {
        c12_b_s->data[c12_i730] = c12_b_nonzero_h->data[c12_i730].re;
      }

      c12_i731 = c12_b_b->size[0];
      c12_b_b->size[0] = c12_h_tmp->size[0];
      c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i731,
        &c12_vf_emlrtRTEI);
      c12_bc_loop_ub = c12_h_tmp->size[0] - 1;
      for (c12_i732 = 0; c12_i732 <= c12_bc_loop_ub; c12_i732++) {
        c12_b_b->data[c12_i732] = ((c12_h_tmp->data[c12_i732].re != c12_dc0.re) ||
          (c12_h_tmp->data[c12_i732].im != c12_dc0.im));
      }

      c12_e_densityFlag = false;
      c12_g_A = (real_T)c12_b_s->size[0];
      c12_e_B = (real_T)c12_lb_h->size[0];
      c12_y_x = c12_g_A;
      c12_db_y = c12_e_B;
      c12_ab_x = c12_y_x;
      c12_eb_y = c12_db_y;
      c12_fb_y = c12_ab_x / c12_eb_y;
      if (c12_fb_y > 0.05) {
        c12_e_densityFlag = true;
      }

      c12_g_tooBig = true;
      for (c12_o_i = 0; c12_o_i < 2; c12_o_i++) {
        c12_g_tooBig = false;
      }

      if (c12_e_densityFlag && (!c12_g_tooBig)) {
        c12_m_modeFlag = true;
      } else {
        c12_m_modeFlag = false;
      }

      if (c12_m_modeFlag) {
        c12_n_modeFlag = true;
      } else {
        c12_n_modeFlag = false;
      }

      c12_i733 = c12_b1->size[0] * c12_b1->size[1];
      c12_b1->size[0] = c12_b->size[0];
      c12_b1->size[1] = 79;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_b1, c12_i733,
        &c12_fh_emlrtRTEI);
      c12_e_b1 = c12_b1->size[0];
      c12_f_b1 = c12_b1->size[1];
      c12_cc_loop_ub = c12_b->size[0] * c12_b->size[1] - 1;
      for (c12_i734 = 0; c12_i734 <= c12_cc_loop_ub; c12_i734++) {
        c12_b1->data[c12_i734] = c12_b->data[c12_i734].re;
      }

      c12_o_modeFlag = c12_n_modeFlag;
      c12_b1_size[0] = 39;
      c12_b1_size[1] = 79;
      if (c12_o_modeFlag) {
        for (c12_i736 = 0; c12_i736 < 2; c12_i736++) {
          c12_padSizeT[c12_i736] = (real_T)c12_b1->size[c12_i736];
        }

        c12_filter_center[0] = (real_T)c12_lb_h->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i738 = 0; c12_i738 < 2; c12_i738++) {
          c12_padSizeT[c12_i738];
        }

        for (c12_i739 = 0; c12_i739 < 2; c12_i739++) {
          c12_filter_center[c12_i739];
        }

        ippfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b1_data[0],
                         c12_outSizeT, 2.0, c12_padSizeT, &c12_lb_h->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i735 = 0; c12_i735 < 2; c12_i735++) {
          c12_padSizeT[c12_i735] = (real_T)c12_b1->size[c12_i735];
        }

        c12_filter_center[0] = (real_T)c12_b_b->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i737 = 0; c12_i737 < 2; c12_i737++) {
          c12_padSizeT[c12_i737];
        }

        c12_e_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i740 = 0; c12_i740 < 2; c12_i740++) {
          c12_filter_center[c12_i740];
        }

        imfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b1_data[0], 2.0,
                        c12_outSizeT, 2.0, c12_padSizeT, &c12_b_s->data[0],
                        c12_e_numKernElem, &c12_b_b->data[0], 2.0,
                        c12_filter_center, c12_start, 2.0, true, false);
      }

      c12_i741 = c12_b1->size[0] * c12_b1->size[1];
      c12_b1->size[0] = c12_b->size[0];
      c12_b1->size[1] = 79;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_b1, c12_i741,
        &c12_hh_emlrtRTEI);
      c12_g_b1 = c12_b1->size[0];
      c12_h_b1 = c12_b1->size[1];
      c12_dc_loop_ub = c12_b->size[0] * c12_b->size[1] - 1;
      for (c12_i742 = 0; c12_i742 <= c12_dc_loop_ub; c12_i742++) {
        c12_b1->data[c12_i742] = c12_b->data[c12_i742].im;
      }

      c12_p_modeFlag = c12_n_modeFlag;
      c12_b2_size[0] = 39;
      c12_b2_size[1] = 79;
      if (c12_p_modeFlag) {
        for (c12_i744 = 0; c12_i744 < 2; c12_i744++) {
          c12_padSizeT[c12_i744] = (real_T)c12_b1->size[c12_i744];
        }

        c12_filter_center[0] = (real_T)c12_lb_h->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i746 = 0; c12_i746 < 2; c12_i746++) {
          c12_padSizeT[c12_i746];
        }

        for (c12_i747 = 0; c12_i747 < 2; c12_i747++) {
          c12_filter_center[c12_i747];
        }

        ippfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b2_data[0],
                         c12_outSizeT, 2.0, c12_padSizeT, &c12_lb_h->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i743 = 0; c12_i743 < 2; c12_i743++) {
          c12_padSizeT[c12_i743] = (real_T)c12_b1->size[c12_i743];
        }

        c12_filter_center[0] = (real_T)c12_b_b->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i745 = 0; c12_i745 < 2; c12_i745++) {
          c12_padSizeT[c12_i745];
        }

        c12_f_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i748 = 0; c12_i748 < 2; c12_i748++) {
          c12_filter_center[c12_i748];
        }

        imfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b2_data[0], 2.0,
                        c12_outSizeT, 2.0, c12_padSizeT, &c12_b_s->data[0],
                        c12_f_numKernElem, &c12_b_b->data[0], 2.0,
                        c12_filter_center, c12_start, 2.0, true, false);
      }

      c12_b_b1_size[0] = 39;
      c12_b_b1_size[1] = 79;
      c12_i_b1 = c12_b_b1_size[0];
      c12_j_b1 = c12_b_b1_size[1];
      for (c12_i749 = 0; c12_i749 < 3081; c12_i749++) {
        chartInstance->c12_b1_data[c12_i749].re = chartInstance->
          c12_b_b2_data[c12_i749] * c12_dc4.re;
        chartInstance->c12_b1_data[c12_i749].im = chartInstance->
          c12_b_b2_data[c12_i749] * c12_dc4.im;
      }

      c12_i750 = c12_b1_size[0] * c12_b1_size[1];
      c12_i751 = c12_b_b1_size[0] * c12_b_b1_size[1];
      c12_b_b1_size[0] = 39;
      c12_b_b1_size[1] = 79;
      c12_k_b1 = c12_b_b1_size[0];
      c12_l_b1 = c12_b_b1_size[1];
      for (c12_i752 = 0; c12_i752 < 3081; c12_i752++) {
        chartInstance->c12_b1_data[c12_i752].re += chartInstance->
          c12_b_b1_data[c12_i752];
        chartInstance->c12_b1_data[c12_i752].im;
      }

      c12_i753 = c12_lb_h->size[0];
      c12_lb_h->size[0] = c12_h_tmp->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_lb_h, c12_i753,
        &c12_vg_emlrtRTEI);
      c12_ec_loop_ub = c12_h_tmp->size[0] - 1;
      for (c12_i754 = 0; c12_i754 <= c12_ec_loop_ub; c12_i754++) {
        c12_lb_h->data[c12_i754] = c12_h_tmp->data[c12_i754].im;
      }

      c12_i755 = c12_b_s->size[0];
      c12_b_s->size[0] = c12_b_nonzero_h->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_b_s, c12_i755,
        &c12_xg_emlrtRTEI);
      c12_fc_loop_ub = c12_b_nonzero_h->size[0] - 1;
      for (c12_i756 = 0; c12_i756 <= c12_fc_loop_ub; c12_i756++) {
        c12_b_s->data[c12_i756] = c12_b_nonzero_h->data[c12_i756].im;
      }

      c12_emxFree_creal_T(chartInstance, &c12_b_nonzero_h);
      c12_i757 = c12_b_b->size[0];
      c12_b_b->size[0] = c12_h_tmp->size[0];
      c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_b, c12_i757,
        &c12_vf_emlrtRTEI);
      c12_gc_loop_ub = c12_h_tmp->size[0] - 1;
      for (c12_i758 = 0; c12_i758 <= c12_gc_loop_ub; c12_i758++) {
        c12_b_b->data[c12_i758] = ((c12_h_tmp->data[c12_i758].re != c12_dc0.re) ||
          (c12_h_tmp->data[c12_i758].im != c12_dc0.im));
      }

      c12_f_densityFlag = false;
      c12_h_A = (real_T)c12_b_s->size[0];
      c12_f_B = (real_T)c12_lb_h->size[0];
      c12_bb_x = c12_h_A;
      c12_gb_y = c12_f_B;
      c12_cb_x = c12_bb_x;
      c12_hb_y = c12_gb_y;
      c12_ib_y = c12_cb_x / c12_hb_y;
      if (c12_ib_y > 0.05) {
        c12_f_densityFlag = true;
      }

      c12_h_tooBig = true;
      for (c12_p_i = 0; c12_p_i < 2; c12_p_i++) {
        c12_h_tooBig = false;
      }

      if (c12_f_densityFlag && (!c12_h_tooBig)) {
        c12_q_modeFlag = true;
      } else {
        c12_q_modeFlag = false;
      }

      if (c12_q_modeFlag) {
        c12_r_modeFlag = true;
      } else {
        c12_r_modeFlag = false;
      }

      c12_i759 = c12_b1->size[0] * c12_b1->size[1];
      c12_b1->size[0] = c12_b->size[0];
      c12_b1->size[1] = 79;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_b1, c12_i759,
        &c12_fh_emlrtRTEI);
      c12_m_b1 = c12_b1->size[0];
      c12_n_b1 = c12_b1->size[1];
      c12_hc_loop_ub = c12_b->size[0] * c12_b->size[1] - 1;
      for (c12_i760 = 0; c12_i760 <= c12_hc_loop_ub; c12_i760++) {
        c12_b1->data[c12_i760] = c12_b->data[c12_i760].re;
      }

      c12_s_modeFlag = c12_r_modeFlag;
      c12_b1_size[0] = 39;
      c12_b1_size[1] = 79;
      if (c12_s_modeFlag) {
        for (c12_i762 = 0; c12_i762 < 2; c12_i762++) {
          c12_padSizeT[c12_i762] = (real_T)c12_b1->size[c12_i762];
        }

        c12_filter_center[0] = (real_T)c12_lb_h->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i764 = 0; c12_i764 < 2; c12_i764++) {
          c12_padSizeT[c12_i764];
        }

        for (c12_i765 = 0; c12_i765 < 2; c12_i765++) {
          c12_filter_center[c12_i765];
        }

        ippfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b1_data[0],
                         c12_outSizeT, 2.0, c12_padSizeT, &c12_lb_h->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i761 = 0; c12_i761 < 2; c12_i761++) {
          c12_padSizeT[c12_i761] = (real_T)c12_b1->size[c12_i761];
        }

        c12_filter_center[0] = (real_T)c12_b_b->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i763 = 0; c12_i763 < 2; c12_i763++) {
          c12_padSizeT[c12_i763];
        }

        c12_g_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i766 = 0; c12_i766 < 2; c12_i766++) {
          c12_filter_center[c12_i766];
        }

        imfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b1_data[0], 2.0,
                        c12_outSizeT, 2.0, c12_padSizeT, &c12_b_s->data[0],
                        c12_g_numKernElem, &c12_b_b->data[0], 2.0,
                        c12_filter_center, c12_start, 2.0, true, false);
      }

      c12_i767 = c12_b1->size[0] * c12_b1->size[1];
      c12_b1->size[0] = c12_b->size[0];
      c12_b1->size[1] = 79;
      c12_emxEnsureCapacity_real_T(chartInstance, c12_b1, c12_i767,
        &c12_hh_emlrtRTEI);
      c12_o_b1 = c12_b1->size[0];
      c12_p_b1 = c12_b1->size[1];
      c12_ic_loop_ub = c12_b->size[0] * c12_b->size[1] - 1;
      for (c12_i768 = 0; c12_i768 <= c12_ic_loop_ub; c12_i768++) {
        c12_b1->data[c12_i768] = c12_b->data[c12_i768].im;
      }

      c12_t_modeFlag = c12_r_modeFlag;
      c12_b2_size[0] = 39;
      c12_b2_size[1] = 79;
      if (c12_t_modeFlag) {
        for (c12_i770 = 0; c12_i770 < 2; c12_i770++) {
          c12_padSizeT[c12_i770] = (real_T)c12_b1->size[c12_i770];
        }

        c12_filter_center[0] = (real_T)c12_lb_h->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i772 = 0; c12_i772 < 2; c12_i772++) {
          c12_padSizeT[c12_i772];
        }

        for (c12_i773 = 0; c12_i773 < 2; c12_i773++) {
          c12_filter_center[c12_i773];
        }

        ippfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b2_data[0],
                         c12_outSizeT, 2.0, c12_padSizeT, &c12_lb_h->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i769 = 0; c12_i769 < 2; c12_i769++) {
          c12_padSizeT[c12_i769] = (real_T)c12_b1->size[c12_i769];
        }

        c12_filter_center[0] = (real_T)c12_b_b->size[0];
        c12_filter_center[1] = 1.0;
        for (c12_i771 = 0; c12_i771 < 2; c12_i771++) {
          c12_padSizeT[c12_i771];
        }

        c12_h_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i774 = 0; c12_i774 < 2; c12_i774++) {
          c12_filter_center[c12_i774];
        }

        imfilter_real64(&c12_b1->data[0], &chartInstance->c12_b_b2_data[0], 2.0,
                        c12_outSizeT, 2.0, c12_padSizeT, &c12_b_s->data[0],
                        c12_h_numKernElem, &c12_b_b->data[0], 2.0,
                        c12_filter_center, c12_start, 2.0, true, false);
      }

      c12_emxFree_real_T(chartInstance, &c12_lb_h);
      c12_emxFree_real_T(chartInstance, &c12_b1);
      c12_b_b2_size[0] = 39;
      c12_b_b2_size[1] = 79;
      c12_c_b2 = c12_b_b2_size[0];
      c12_d_b2 = c12_b_b2_size[1];
      for (c12_i775 = 0; c12_i775 < 3081; c12_i775++) {
        chartInstance->c12_b2_data[c12_i775].re = chartInstance->
          c12_b_b2_data[c12_i775] * c12_dc4.re;
        chartInstance->c12_b2_data[c12_i775].im = chartInstance->
          c12_b_b2_data[c12_i775] * c12_dc4.im;
      }

      c12_i776 = c12_b1_size[0] * c12_b1_size[1];
      c12_i777 = c12_b_b2_size[0] * c12_b_b2_size[1];
      c12_b_b2_size[0] = 39;
      c12_b_b2_size[1] = 79;
      c12_e_b2 = c12_b_b2_size[0];
      c12_f_b2 = c12_b_b2_size[1];
      for (c12_i778 = 0; c12_i778 < 3081; c12_i778++) {
        chartInstance->c12_b2_data[c12_i778].re += chartInstance->
          c12_b_b1_data[c12_i778];
        chartInstance->c12_b2_data[c12_i778].im;
      }

      c12_b1_size[0] = 39;
      c12_b1_size[1] = 79;
      c12_q_b1 = c12_b1_size[0];
      c12_r_b1 = c12_b1_size[1];
      for (c12_i779 = 0; c12_i779 < 3081; c12_i779++) {
        chartInstance->c12_b_b1_data[c12_i779] = chartInstance->
          c12_b1_data[c12_i779].re;
      }

      c12_b2_size[0] = 39;
      c12_b2_size[1] = 79;
      c12_g_b2 = c12_b2_size[0];
      c12_h_b2 = c12_b2_size[1];
      for (c12_i780 = 0; c12_i780 < 3081; c12_i780++) {
        chartInstance->c12_b_b2_data[c12_i780] = chartInstance->
          c12_b2_data[c12_i780].im;
      }

      c12_tmp_size[0] = 39;
      c12_tmp_size[1] = 79;
      c12_i781 = c12_tmp_size[0];
      c12_i782 = c12_tmp_size[1];
      for (c12_i783 = 0; c12_i783 < 3081; c12_i783++) {
        chartInstance->c12_tmp_data[c12_i783] = chartInstance->
          c12_b1_data[c12_i783].im;
      }

      c12_b_tmp_size[0] = 39;
      c12_b_tmp_size[1] = 79;
      c12_i784 = c12_b_tmp_size[0];
      c12_i785 = c12_b_tmp_size[1];
      for (c12_i786 = 0; c12_i786 < 3081; c12_i786++) {
        chartInstance->c12_b_tmp_data[c12_i786] = chartInstance->
          c12_b2_data[c12_i786].re;
      }

      c12_b_b1_size[0] = 39;
      c12_b_b1_size[1] = 79;
      c12_s_b1 = c12_b_b1_size[0];
      c12_t_b1 = c12_b_b1_size[1];
      for (c12_i787 = 0; c12_i787 < 3081; c12_i787++) {
        chartInstance->c12_b1_data[c12_i787].re = chartInstance->
          c12_b_b1_data[c12_i787] - chartInstance->c12_b_b2_data[c12_i787];
        chartInstance->c12_b1_data[c12_i787].im = chartInstance->
          c12_tmp_data[c12_i787] + chartInstance->c12_b_tmp_data[c12_i787];
      }

      c12_i788 = c12_b->size[0] * c12_b->size[1];
      c12_b->size[0] = 39;
      c12_b->size[1] = 79;
      c12_emxEnsureCapacity_creal_T(chartInstance, c12_b, c12_i788,
        &c12_ph_emlrtRTEI);
      c12_bb_b = c12_b->size[0];
      c12_cb_b = c12_b->size[1];
      for (c12_i789 = 0; c12_i789 < 3081; c12_i789++) {
        c12_b->data[c12_i789] = chartInstance->c12_b1_data[c12_i789];
      }
    } else {
      for (c12_i573 = 0; c12_i573 < 3081; c12_i573++) {
        chartInstance->c12_varargin_1[c12_i573] = c12_c_varargin_1[c12_i573];
      }

      for (c12_i576 = 0; c12_i576 < 2; c12_i576++) {
        c12_b_startT[c12_i576] = c12_startT[c12_i576];
      }

      c12_padImage(chartInstance, chartInstance->c12_varargin_1, c12_b_startT,
                   c12_a);
      c12_b23 = (c12_varargin_2->size[0] == 1);
      c12_b24 = (c12_varargin_2->size[1] == 1);
      c12_emxInit_int32_T(chartInstance, &c12_r15, 1, &c12_wh_emlrtRTEI);
      c12_emxInit_boolean_T(chartInstance, &c12_c_h, 2, &c12_vf_emlrtRTEI);
      c12_emxInit_boolean_T(chartInstance, &c12_d_h, 2, &c12_vf_emlrtRTEI);
      c12_emxInit_boolean_T(chartInstance, &c12_e_h, 2, &c12_vf_emlrtRTEI);
      guard1 = false;
      if (c12_b23 || c12_b24) {
        c12_i582 = c12_c_h->size[0] * c12_c_h->size[1];
        c12_c_h->size[0] = c12_varargin_2->size[0];
        c12_c_h->size[1] = c12_varargin_2->size[1];
        c12_emxEnsureCapacity_boolean_T(chartInstance, c12_c_h, c12_i582,
          &c12_vf_emlrtRTEI);
        c12_f_h = c12_c_h->size[0];
        c12_h_h = c12_c_h->size[1];
        c12_e_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
        for (c12_i588 = 0; c12_i588 <= c12_e_loop_ub; c12_i588++) {
          c12_c_h->data[c12_i588] = ((c12_varargin_2->data[c12_i588].re !=
            c12_dc0.re) || (c12_varargin_2->data[c12_i588].im != c12_dc0.im));
        }

        c12_b25 = (c12_c_h->size[0] == 1);
        c12_i594 = c12_c_h->size[0] * c12_c_h->size[1];
        c12_c_h->size[0] = c12_varargin_2->size[0];
        c12_c_h->size[1] = c12_varargin_2->size[1];
        c12_emxEnsureCapacity_boolean_T(chartInstance, c12_c_h, c12_i594,
          &c12_vf_emlrtRTEI);
        c12_j_h = c12_c_h->size[0];
        c12_k_h = c12_c_h->size[1];
        c12_i_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
        for (c12_i599 = 0; c12_i599 <= c12_i_loop_ub; c12_i599++) {
          c12_c_h->data[c12_i599] = ((c12_varargin_2->data[c12_i599].re !=
            c12_dc0.re) || (c12_varargin_2->data[c12_i599].im != c12_dc0.im));
        }

        c12_b26 = (c12_c_h->size[1] == 1);
        if (c12_b25 || c12_b26) {
          c12_i604 = c12_h_tmp->size[0];
          c12_h_tmp->size[0] = c12_varargin_2->size[0] * c12_varargin_2->size[1];
          c12_emxEnsureCapacity_creal_T1(chartInstance, c12_h_tmp, c12_i604,
            &c12_dg_emlrtRTEI);
          c12_m_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
          for (c12_i607 = 0; c12_i607 <= c12_m_loop_ub; c12_i607++) {
            c12_h_tmp->data[c12_i607] = c12_varargin_2->data[c12_i607];
          }

          c12_i609 = c12_c_h->size[0] * c12_c_h->size[1];
          c12_c_h->size[0] = c12_varargin_2->size[0];
          c12_c_h->size[1] = c12_varargin_2->size[1];
          c12_emxEnsureCapacity_boolean_T(chartInstance, c12_c_h, c12_i609,
            &c12_vf_emlrtRTEI);
          c12_l_h = c12_c_h->size[0];
          c12_m_h = c12_c_h->size[1];
          c12_q_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
          for (c12_i614 = 0; c12_i614 <= c12_q_loop_ub; c12_i614++) {
            c12_c_h->data[c12_i614] = ((c12_varargin_2->data[c12_i614].re !=
              c12_dc0.re) || (c12_varargin_2->data[c12_i614].im != c12_dc0.im));
          }

          c12_i617 = c12_d_h->size[0] * c12_d_h->size[1];
          c12_d_h->size[0] = c12_varargin_2->size[0];
          c12_d_h->size[1] = c12_varargin_2->size[1];
          c12_emxEnsureCapacity_boolean_T(chartInstance, c12_d_h, c12_i617,
            &c12_vf_emlrtRTEI);
          c12_n_h = c12_d_h->size[0];
          c12_o_h = c12_d_h->size[1];
          c12_s_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
          for (c12_i622 = 0; c12_i622 <= c12_s_loop_ub; c12_i622++) {
            c12_d_h->data[c12_i622] = ((c12_varargin_2->data[c12_i622].re !=
              c12_dc0.re) || (c12_varargin_2->data[c12_i622].im != c12_dc0.im));
          }

          c12_i626 = c12_e_h->size[0] * c12_e_h->size[1];
          c12_e_h->size[0] = c12_varargin_2->size[0];
          c12_e_h->size[1] = c12_varargin_2->size[1];
          c12_emxEnsureCapacity_boolean_T(chartInstance, c12_e_h, c12_i626,
            &c12_vf_emlrtRTEI);
          c12_p_h = c12_e_h->size[0];
          c12_q_h = c12_e_h->size[1];
          c12_x_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
          for (c12_i632 = 0; c12_i632 <= c12_x_loop_ub; c12_i632++) {
            c12_e_h->data[c12_i632] = ((c12_varargin_2->data[c12_i632].re !=
              c12_dc0.re) || (c12_varargin_2->data[c12_i632].im != c12_dc0.im));
          }

          c12_i634 = c12_b_h->size[0];
          c12_b_h->size[0] = c12_d_h->size[0] * c12_e_h->size[1];
          c12_emxEnsureCapacity_boolean_T1(chartInstance, c12_b_h, c12_i634,
            &c12_og_emlrtRTEI);
          c12_ab_loop_ub = c12_d_h->size[0] * c12_e_h->size[1] - 1;
          for (c12_i636 = 0; c12_i636 <= c12_ab_loop_ub; c12_i636++) {
            c12_b_h->data[c12_i636] = c12_c_h->data[c12_i636];
          }

          c12_b_end = c12_b_h->size[0] - 1;
          c12_b_trueCount = 0;
          for (c12_c_i = 0; c12_c_i <= c12_b_end; c12_c_i++) {
            if (c12_b_h->data[c12_c_i]) {
              c12_b_trueCount++;
            }
          }

          c12_i640 = c12_nonzero_h->size[0];
          c12_nonzero_h->size[0] = c12_b_trueCount;
          c12_emxEnsureCapacity_creal_T1(chartInstance, c12_nonzero_h, c12_i640,
            &c12_lg_emlrtRTEI);
          c12_b_partialTrueCount = 0;
          for (c12_d_i = 0; c12_d_i <= c12_b_end; c12_d_i++) {
            if (c12_b_h->data[c12_d_i]) {
              c12_nonzero_h->data[c12_b_partialTrueCount].re = c12_h_tmp->
                data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_d_i + 1, 1,
                c12_h_tmp->size[0]) - 1].re;
              c12_nonzero_h->data[c12_b_partialTrueCount].im = c12_h_tmp->
                data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_d_i + 1, 1,
                c12_h_tmp->size[0]) - 1].im;
              c12_b_partialTrueCount++;
            }
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        c12_i583 = c12_c_h->size[0] * c12_c_h->size[1];
        c12_c_h->size[0] = c12_varargin_2->size[0];
        c12_c_h->size[1] = c12_varargin_2->size[1];
        c12_emxEnsureCapacity_boolean_T(chartInstance, c12_c_h, c12_i583,
          &c12_vf_emlrtRTEI);
        c12_g_h = c12_c_h->size[0];
        c12_i_h = c12_c_h->size[1];
        c12_f_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
        for (c12_i590 = 0; c12_i590 <= c12_f_loop_ub; c12_i590++) {
          c12_c_h->data[c12_i590] = ((c12_varargin_2->data[c12_i590].re !=
            c12_dc0.re) || (c12_varargin_2->data[c12_i590].im != c12_dc0.im));
        }

        for (c12_i593 = 0; c12_i593 < 2; c12_i593++) {
          c12_matrixSize[c12_i593] = c12_varargin_2->size[c12_i593];
        }

        for (c12_i596 = 0; c12_i596 < 2; c12_i596++) {
          c12_indexSize[c12_i596] = c12_c_h->size[c12_i596];
        }

        c12_nonSingletonDimFound = false;
        if (c12_matrixSize[0] != 1) {
          c12_nonSingletonDimFound = true;
        }

        if (c12_matrixSize[1] != 1) {
          if (c12_nonSingletonDimFound) {
            c12_f_b = false;
          } else {
            c12_nonSingletonDimFound = true;
            c12_f_b = c12_nonSingletonDimFound;
          }
        } else {
          c12_f_b = c12_nonSingletonDimFound;
        }

        if (c12_f_b) {
          if (c12_matrixSize[0] == 1) {
            c12_c = true;
          } else {
            c12_c = false;
          }

          if (c12_c || (!(c12_matrixSize[1] == 1))) {
            c12_c = true;
          } else {
            c12_c = false;
          }

          c12_b_c = c12_c;
          if (!c12_b_c) {
          } else {
            c12_d_y = NULL;
            sf_mex_assign(&c12_d_y, sf_mex_create("y", c12_cv17, 10, 0U, 1U, 0U,
              2, 1, 30), false);
            c12_e_y = NULL;
            sf_mex_assign(&c12_e_y, sf_mex_create("y", c12_cv17, 10, 0U, 1U, 0U,
              2, 1, 30), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                              c12_d_y, 14, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                               14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "message", 1U, 1U, 14, c12_e_y)));
          }
        } else {
          c12_b_nonSingletonDimFound = false;
          if (c12_indexSize[0] != 1) {
            c12_b_nonSingletonDimFound = true;
          }

          if (c12_indexSize[1] != 1) {
            if (c12_b_nonSingletonDimFound) {
              c12_h_b = false;
            } else {
              c12_b_nonSingletonDimFound = true;
              c12_h_b = c12_b_nonSingletonDimFound;
            }
          } else {
            c12_h_b = c12_b_nonSingletonDimFound;
          }

          if (c12_h_b) {
            if (c12_indexSize[0] == 1) {
              c12_c_c = true;
            } else {
              c12_c_c = false;
            }

            if (c12_c_c || (!(c12_indexSize[1] == 1))) {
              c12_c_c = true;
            } else {
              c12_c_c = false;
            }

            c12_d_c = c12_c_c;
            if (!c12_d_c) {
            } else {
              c12_f_y = NULL;
              sf_mex_assign(&c12_f_y, sf_mex_create("y", c12_cv18, 10, 0U, 1U,
                0U, 2, 1, 30), false);
              c12_g_y = NULL;
              sf_mex_assign(&c12_g_y, sf_mex_create("y", c12_cv18, 10, 0U, 1U,
                0U, 2, 1, 30), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                                c12_f_y, 14, sf_mex_call_debug
                                (sfGlobalDebugInstanceStruct, "getString", 1U,
                                 1U, 14, sf_mex_call_debug
                                 (sfGlobalDebugInstanceStruct, "message", 1U, 1U,
                                  14, c12_g_y)));
            }
          }
        }

        c12_end = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
        c12_trueCount = 0;
        for (c12_i = 0; c12_i <= c12_end; c12_i++) {
          c12_f_varargin_2 = ((c12_varargin_2->data[c12_i].re != c12_dc0.re) ||
                              (c12_varargin_2->data[c12_i].im != c12_dc0.im));
          if (c12_f_varargin_2) {
            c12_trueCount++;
          }
        }

        c12_i616 = c12_r15->size[0];
        c12_r15->size[0] = c12_trueCount;
        c12_emxEnsureCapacity_int32_T(chartInstance, c12_r15, c12_i616,
          &c12_lg_emlrtRTEI);
        c12_partialTrueCount = 0;
        for (c12_b_i = 0; c12_b_i <= c12_end; c12_b_i++) {
          c12_h_varargin_2 = ((c12_varargin_2->data[c12_b_i].re != c12_dc0.re) ||
                              (c12_varargin_2->data[c12_b_i].im != c12_dc0.im));
          if (c12_h_varargin_2) {
            c12_r15->data[c12_partialTrueCount] = c12_b_i + 1;
            c12_partialTrueCount++;
          }
        }

        c12_g_varargin_2 = c12_varargin_2->size[0] * c12_varargin_2->size[1];
        c12_i624 = c12_nonzero_h->size[0];
        c12_nonzero_h->size[0] = c12_r15->size[0];
        c12_emxEnsureCapacity_creal_T1(chartInstance, c12_nonzero_h, c12_i624,
          &c12_ng_emlrtRTEI);
        c12_v_loop_ub = c12_r15->size[0] - 1;
        for (c12_i628 = 0; c12_i628 <= c12_v_loop_ub; c12_i628++) {
          c12_nonzero_h->data[c12_i628].re = c12_varargin_2->
            data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_r15->data[c12_i628], 1,
            c12_g_varargin_2) - 1].re;
          c12_nonzero_h->data[c12_i628].im = c12_varargin_2->
            data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_r15->data[c12_i628], 1,
            c12_g_varargin_2) - 1].im;
        }
      }

      c12_emxFree_boolean_T(chartInstance, &c12_e_h);
      c12_emxFree_boolean_T(chartInstance, &c12_d_h);
      c12_emxFree_int32_T(chartInstance, &c12_r15);
      c12_i633 = c12_s->size[0] * c12_s->size[1];
      c12_s->size[0] = c12_varargin_2->size[0];
      c12_s->size[1] = c12_varargin_2->size[1];
      c12_emxEnsureCapacity_real_T(chartInstance, c12_s, c12_i633,
        &c12_pg_emlrtRTEI);
      c12_e_s = c12_s->size[0];
      c12_f_s = c12_s->size[1];
      c12_bb_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
      for (c12_i637 = 0; c12_i637 <= c12_bb_loop_ub; c12_i637++) {
        c12_s->data[c12_i637] = c12_varargin_2->data[c12_i637].re;
      }

      c12_i639 = c12_b_s->size[0];
      c12_b_s->size[0] = c12_nonzero_h->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_b_s, c12_i639,
        &c12_qg_emlrtRTEI);
      c12_cb_loop_ub = c12_nonzero_h->size[0] - 1;
      for (c12_i641 = 0; c12_i641 <= c12_cb_loop_ub; c12_i641++) {
        c12_b_s->data[c12_i641] = c12_nonzero_h->data[c12_i641].re;
      }

      c12_i643 = c12_c_h->size[0] * c12_c_h->size[1];
      c12_c_h->size[0] = c12_varargin_2->size[0];
      c12_c_h->size[1] = c12_varargin_2->size[1];
      c12_emxEnsureCapacity_boolean_T(chartInstance, c12_c_h, c12_i643,
        &c12_vf_emlrtRTEI);
      c12_v_h = c12_c_h->size[0];
      c12_w_h = c12_c_h->size[1];
      c12_eb_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
      for (c12_i645 = 0; c12_i645 <= c12_eb_loop_ub; c12_i645++) {
        c12_c_h->data[c12_i645] = ((c12_varargin_2->data[c12_i645].re !=
          c12_dc0.re) || (c12_varargin_2->data[c12_i645].im != c12_dc0.im));
      }

      c12_densityFlag = false;
      c12_c_A = (real_T)c12_b_s->size[0];
      c12_B = (real_T)(c12_s->size[0] * c12_s->size[1]);
      c12_k_x = c12_c_A;
      c12_k_y = c12_B;
      c12_l_x = c12_k_x;
      c12_l_y = c12_k_y;
      c12_m_y = c12_l_x / c12_l_y;
      if (c12_m_y > 0.05) {
        c12_densityFlag = true;
      }

      c12_tooBig = true;
      for (c12_e_i = 0; c12_e_i < 2; c12_e_i++) {
        c12_tooBig = false;
      }

      if (c12_densityFlag && (!c12_tooBig)) {
        c12_modeFlag = true;
      } else {
        c12_modeFlag = false;
      }

      if (c12_modeFlag) {
        c12_b_modeFlag = true;
      } else {
        c12_b_modeFlag = false;
      }

      c12_c_modeFlag = c12_b_modeFlag;
      c12_b1_size[0] = 39;
      c12_b1_size[1] = 79;
      if (c12_c_modeFlag) {
        for (c12_i659 = 0; c12_i659 < 2; c12_i659++) {
          c12_padSizeT[c12_i659] = (real_T)c12_a->size[c12_i659];
        }

        for (c12_i661 = 0; c12_i661 < 2; c12_i661++) {
          c12_filter_center[c12_i661] = (real_T)c12_s->size[c12_i661];
        }

        for (c12_i663 = 0; c12_i663 < 2; c12_i663++) {
          c12_padSizeT[c12_i663];
        }

        for (c12_i665 = 0; c12_i665 < 2; c12_i665++) {
          c12_filter_center[c12_i665];
        }

        ippfilter_real64(&c12_a->data[0], &chartInstance->c12_b_b1_data[0],
                         c12_outSizeT, 2.0, c12_padSizeT, &c12_s->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i658 = 0; c12_i658 < 2; c12_i658++) {
          c12_padSizeT[c12_i658] = (real_T)c12_a->size[c12_i658];
        }

        for (c12_i660 = 0; c12_i660 < 2; c12_i660++) {
          c12_filter_center[c12_i660] = (real_T)c12_c_h->size[c12_i660];
        }

        for (c12_i662 = 0; c12_i662 < 2; c12_i662++) {
          c12_padSizeT[c12_i662];
        }

        c12_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i667 = 0; c12_i667 < 2; c12_i667++) {
          c12_filter_center[c12_i667];
        }

        imfilter_real64(&c12_a->data[0], &chartInstance->c12_b_b1_data[0], 2.0,
                        c12_outSizeT, 2.0, c12_padSizeT, &c12_b_s->data[0],
                        c12_numKernElem, &c12_c_h->data[0], 2.0,
                        c12_filter_center, c12_startT, 2.0, true, false);
      }

      c12_i669 = c12_s->size[0] * c12_s->size[1];
      c12_s->size[0] = c12_varargin_2->size[0];
      c12_s->size[1] = c12_varargin_2->size[1];
      c12_emxEnsureCapacity_real_T(chartInstance, c12_s, c12_i669,
        &c12_vg_emlrtRTEI);
      c12_g_s = c12_s->size[0];
      c12_h_s = c12_s->size[1];
      c12_mb_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
      for (c12_i671 = 0; c12_i671 <= c12_mb_loop_ub; c12_i671++) {
        c12_s->data[c12_i671] = c12_varargin_2->data[c12_i671].im;
      }

      c12_i674 = c12_b_s->size[0];
      c12_b_s->size[0] = c12_nonzero_h->size[0];
      c12_emxEnsureCapacity_real_T1(chartInstance, c12_b_s, c12_i674,
        &c12_xg_emlrtRTEI);
      c12_pb_loop_ub = c12_nonzero_h->size[0] - 1;
      for (c12_i676 = 0; c12_i676 <= c12_pb_loop_ub; c12_i676++) {
        c12_b_s->data[c12_i676] = c12_nonzero_h->data[c12_i676].im;
      }

      c12_i678 = c12_c_h->size[0] * c12_c_h->size[1];
      c12_c_h->size[0] = c12_varargin_2->size[0];
      c12_c_h->size[1] = c12_varargin_2->size[1];
      c12_emxEnsureCapacity_boolean_T(chartInstance, c12_c_h, c12_i678,
        &c12_vf_emlrtRTEI);
      c12_fb_h = c12_c_h->size[0];
      c12_gb_h = c12_c_h->size[1];
      c12_qb_loop_ub = c12_varargin_2->size[0] * c12_varargin_2->size[1] - 1;
      for (c12_i679 = 0; c12_i679 <= c12_qb_loop_ub; c12_i679++) {
        c12_c_h->data[c12_i679] = ((c12_varargin_2->data[c12_i679].re !=
          c12_dc0.re) || (c12_varargin_2->data[c12_i679].im != c12_dc0.im));
      }

      c12_c_densityFlag = false;
      c12_e_A = (real_T)c12_b_s->size[0];
      c12_c_B = (real_T)(c12_s->size[0] * c12_s->size[1]);
      c12_u_x = c12_e_A;
      c12_w_y = c12_c_B;
      c12_v_x = c12_u_x;
      c12_x_y = c12_w_y;
      c12_y_y = c12_v_x / c12_x_y;
      if (c12_y_y > 0.05) {
        c12_c_densityFlag = true;
      }

      c12_d_tooBig = true;
      for (c12_j_i = 0; c12_j_i < 2; c12_j_i++) {
        c12_d_tooBig = false;
      }

      if (c12_c_densityFlag && (!c12_d_tooBig)) {
        c12_g_modeFlag = true;
      } else {
        c12_g_modeFlag = false;
      }

      if (c12_g_modeFlag) {
        c12_h_modeFlag = true;
      } else {
        c12_h_modeFlag = false;
      }

      c12_i_modeFlag = c12_h_modeFlag;
      c12_b2_size[0] = 39;
      c12_b2_size[1] = 79;
      if (c12_i_modeFlag) {
        for (c12_i690 = 0; c12_i690 < 2; c12_i690++) {
          c12_padSizeT[c12_i690] = (real_T)c12_a->size[c12_i690];
        }

        for (c12_i693 = 0; c12_i693 < 2; c12_i693++) {
          c12_filter_center[c12_i693] = (real_T)c12_s->size[c12_i693];
        }

        for (c12_i695 = 0; c12_i695 < 2; c12_i695++) {
          c12_padSizeT[c12_i695];
        }

        for (c12_i696 = 0; c12_i696 < 2; c12_i696++) {
          c12_filter_center[c12_i696];
        }

        ippfilter_real64(&c12_a->data[0], &chartInstance->c12_b_b2_data[0],
                         c12_outSizeT, 2.0, c12_padSizeT, &c12_s->data[0],
                         c12_filter_center, false);
      } else {
        for (c12_i689 = 0; c12_i689 < 2; c12_i689++) {
          c12_padSizeT[c12_i689] = (real_T)c12_a->size[c12_i689];
        }

        for (c12_i692 = 0; c12_i692 < 2; c12_i692++) {
          c12_filter_center[c12_i692] = (real_T)c12_c_h->size[c12_i692];
        }

        for (c12_i694 = 0; c12_i694 < 2; c12_i694++) {
          c12_padSizeT[c12_i694];
        }

        c12_c_numKernElem = (real_T)c12_b_s->size[0];
        for (c12_i698 = 0; c12_i698 < 2; c12_i698++) {
          c12_filter_center[c12_i698];
        }

        imfilter_real64(&c12_a->data[0], &chartInstance->c12_b_b2_data[0], 2.0,
                        c12_outSizeT, 2.0, c12_padSizeT, &c12_b_s->data[0],
                        c12_c_numKernElem, &c12_c_h->data[0], 2.0,
                        c12_filter_center, c12_startT, 2.0, true, false);
      }

      c12_emxFree_boolean_T(chartInstance, &c12_c_h);
      c12_b_b1_size[0] = 39;
      c12_b_b1_size[1] = 79;
      c12_b_b1 = c12_b_b1_size[0];
      c12_c_b1 = c12_b_b1_size[1];
      for (c12_i701 = 0; c12_i701 < 3081; c12_i701++) {
        chartInstance->c12_b1_data[c12_i701].re = chartInstance->
          c12_b_b1_data[c12_i701];
        chartInstance->c12_b1_data[c12_i701].im = chartInstance->
          c12_b_b2_data[c12_i701];
      }

      c12_i703 = c12_b->size[0] * c12_b->size[1];
      c12_b->size[0] = 39;
      c12_b->size[1] = 79;
      c12_emxEnsureCapacity_creal_T(chartInstance, c12_b, c12_i703,
        &c12_ch_emlrtRTEI);
      c12_w_b = c12_b->size[0];
      c12_x_b = c12_b->size[1];
      for (c12_i705 = 0; c12_i705 < 3081; c12_i705++) {
        c12_b->data[c12_i705] = chartInstance->c12_b1_data[c12_i705];
      }
    }

    c12_emxFree_boolean_T(chartInstance, &c12_b_h);
    c12_emxFree_creal_T(chartInstance, &c12_h_tmp);
    c12_emxFree_creal_T(chartInstance, &c12_nonzero_h);
    c12_emxFree_boolean_T(chartInstance, &c12_b_b);
    c12_emxFree_real_T(chartInstance, &c12_b_s);
    c12_emxFree_creal_T(chartInstance, &c12_unusedU1);
    c12_emxFree_real_T(chartInstance, &c12_s);
    c12_emxFree_creal_T(chartInstance, &c12_unusedU0);
    c12_emxFree_real_T(chartInstance, &c12_a);
  }
}

static void c12_svd(SFc12_anav_realInstanceStruct *chartInstance,
                    c12_emxArray_creal_T *c12_A, c12_emxArray_creal_T *c12_U,
                    c12_emxArray_real_T *c12_S, c12_emxArray_creal_T *c12_V)
{
  static creal_T c12_dc5 = { 0.0,      /* re */
    0.0                                /* im */
  };

  int32_T c12_nx;
  boolean_T c12_p;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  boolean_T c12_b_p;
  boolean_T c12_allFiniteA;
  creal_T c12_b_x;
  c12_emxArray_real_T *c12_s;
  boolean_T c12_c_p;
  boolean_T c12_b30;
  boolean_T c12_b31;
  int32_T c12_i790;
  c12_emxArray_creal_T *c12_b_A;
  boolean_T c12_c_b;
  int32_T c12_i791;
  boolean_T c12_b32;
  boolean_T c12_b33;
  int32_T c12_i792;
  real_T c12_c_A[2];
  boolean_T c12_b34;
  boolean_T c12_d_b;
  int32_T c12_d_A;
  boolean_T c12_b35;
  c12_emxArray_creal_T *c12_A1;
  int32_T c12_e_A;
  boolean_T c12_e_b;
  int32_T c12_i793;
  int32_T c12_loop_ub;
  int32_T c12_i794;
  int32_T c12_b_A1;
  int32_T c12_c_A1;
  int32_T c12_b_loop_ub;
  int32_T c12_i795;
  int32_T c12_i796;
  c12_emxArray_creal_T *c12_U1;
  c12_emxArray_creal_T *c12_V1;
  int32_T c12_b_S;
  int32_T c12_c_S;
  real_T c12_c_varargin_1;
  int32_T c12_c_loop_ub;
  real_T c12_varargin_2;
  int32_T c12_i797;
  int32_T c12_i798;
  int32_T c12_n;
  int32_T c12_i799;
  int32_T c12_b_U;
  int32_T c12_b_k;
  int32_T c12_c_U;
  int32_T c12_d_loop_ub;
  int32_T c12_i800;
  real_T c12_d_varargin_1;
  int32_T c12_i801;
  int32_T c12_e_loop_ub;
  int32_T c12_i802;
  real_T c12_e_varargin_1;
  real_T c12_b_varargin_2;
  int32_T c12_i803;
  int32_T c12_b_V;
  int32_T c12_c_V;
  int32_T c12_f_loop_ub;
  int32_T c12_i804;
  c12_dc5.re = rtNaN;
  c12_nx = c12_A->size[0] * c12_A->size[1];
  c12_p = true;
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    if (c12_p) {
      c12_b_x = c12_A->data[c12_k];
      c12_b30 = muDoubleScalarIsInf(c12_b_x.re);
      c12_b31 = muDoubleScalarIsInf(c12_b_x.im);
      c12_c_b = (c12_b30 || c12_b31);
      c12_b32 = !c12_c_b;
      c12_b33 = muDoubleScalarIsNaN(c12_b_x.re);
      c12_b34 = muDoubleScalarIsNaN(c12_b_x.im);
      c12_d_b = (c12_b33 || c12_b34);
      c12_b35 = !c12_d_b;
      c12_e_b = (c12_b32 && c12_b35);
      if (c12_e_b) {
        c12_c_p = true;
      } else {
        c12_c_p = false;
      }
    } else {
      c12_c_p = false;
    }

    c12_p = c12_c_p;
  }

  c12_b_p = !c12_p;
  c12_allFiniteA = !c12_b_p;
  c12_emxInit_real_T1(chartInstance, &c12_s, 1, &c12_fi_emlrtRTEI);
  if (c12_allFiniteA) {
    c12_emxInit_creal_T(chartInstance, &c12_b_A, 2, &c12_xh_emlrtRTEI);
    c12_i791 = c12_b_A->size[0] * c12_b_A->size[1];
    c12_b_A->size[0] = c12_A->size[0];
    c12_b_A->size[1] = c12_A->size[1];
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_A, c12_i791,
      &c12_xh_emlrtRTEI);
    c12_d_A = c12_b_A->size[0];
    c12_e_A = c12_b_A->size[1];
    c12_loop_ub = c12_A->size[0] * c12_A->size[1] - 1;
    for (c12_i794 = 0; c12_i794 <= c12_loop_ub; c12_i794++) {
      c12_b_A->data[c12_i794] = c12_A->data[c12_i794];
    }

    c12_b_svd(chartInstance, c12_b_A, c12_U, c12_s, c12_V);
    c12_emxFree_creal_T(chartInstance, &c12_b_A);
  } else {
    for (c12_i790 = 0; c12_i790 < 2; c12_i790++) {
      c12_c_A[c12_i790] = (real_T)c12_A->size[c12_i790];
    }

    for (c12_i792 = 0; c12_i792 < 2; c12_i792++) {
      c12_c_A[c12_i792];
    }

    c12_emxInit_creal_T(chartInstance, &c12_A1, 2, &c12_ei_emlrtRTEI);
    c12_i793 = c12_A1->size[0] * c12_A1->size[1];
    c12_A1->size[0] = (int32_T)c12_c_A[0];
    c12_A1->size[1] = (int32_T)c12_c_A[1];
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_A1, c12_i793,
      &c12_yh_emlrtRTEI);
    c12_b_A1 = c12_A1->size[0];
    c12_c_A1 = c12_A1->size[1];
    c12_b_loop_ub = (int32_T)c12_c_A[0] * (int32_T)c12_c_A[1] - 1;
    for (c12_i795 = 0; c12_i795 <= c12_b_loop_ub; c12_i795++) {
      c12_A1->data[c12_i795] = c12_dc0;
    }

    c12_emxInit_creal_T(chartInstance, &c12_U1, 2, &c12_gi_emlrtRTEI);
    c12_emxInit_creal_T(chartInstance, &c12_V1, 2, &c12_gi_emlrtRTEI);
    c12_b_svd(chartInstance, c12_A1, c12_U1, c12_s, c12_V1);
    c12_c_varargin_1 = (real_T)c12_U1->size[0];
    c12_varargin_2 = (real_T)c12_U1->size[1];
    c12_i798 = c12_U->size[0] * c12_U->size[1];
    c12_U->size[0] = (int32_T)c12_c_varargin_1;
    c12_U->size[1] = (int32_T)c12_varargin_2;
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_U, c12_i798,
      &c12_bi_emlrtRTEI);
    c12_b_U = c12_U->size[0];
    c12_c_U = c12_U->size[1];
    c12_d_loop_ub = (int32_T)c12_c_varargin_1 * (int32_T)c12_varargin_2 - 1;
    c12_emxFree_creal_T(chartInstance, &c12_U1);
    c12_emxFree_creal_T(chartInstance, &c12_A1);
    for (c12_i800 = 0; c12_i800 <= c12_d_loop_ub; c12_i800++) {
      c12_U->data[c12_i800] = c12_dc5;
    }

    c12_d_varargin_1 = (real_T)c12_s->size[0];
    c12_i801 = c12_s->size[0];
    c12_s->size[0] = (int32_T)c12_d_varargin_1;
    c12_emxEnsureCapacity_real_T1(chartInstance, c12_s, c12_i801,
      &c12_ci_emlrtRTEI);
    c12_e_loop_ub = (int32_T)c12_d_varargin_1 - 1;
    for (c12_i802 = 0; c12_i802 <= c12_e_loop_ub; c12_i802++) {
      c12_s->data[c12_i802] = rtNaN;
    }

    c12_e_varargin_1 = (real_T)c12_V1->size[0];
    c12_b_varargin_2 = (real_T)c12_V1->size[1];
    c12_i803 = c12_V->size[0] * c12_V->size[1];
    c12_V->size[0] = (int32_T)c12_e_varargin_1;
    c12_V->size[1] = (int32_T)c12_b_varargin_2;
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_V, c12_i803,
      &c12_di_emlrtRTEI);
    c12_b_V = c12_V->size[0];
    c12_c_V = c12_V->size[1];
    c12_f_loop_ub = (int32_T)c12_e_varargin_1 * (int32_T)c12_b_varargin_2 - 1;
    c12_emxFree_creal_T(chartInstance, &c12_V1);
    for (c12_i804 = 0; c12_i804 <= c12_f_loop_ub; c12_i804++) {
      c12_V->data[c12_i804] = c12_dc5;
    }
  }

  c12_i796 = c12_S->size[0] * c12_S->size[1];
  c12_S->size[0] = c12_U->size[1];
  c12_S->size[1] = c12_V->size[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_S, c12_i796, &c12_ai_emlrtRTEI);
  c12_b_S = c12_S->size[0];
  c12_c_S = c12_S->size[1];
  c12_c_loop_ub = c12_U->size[1] * c12_V->size[1] - 1;
  for (c12_i797 = 0; c12_i797 <= c12_c_loop_ub; c12_i797++) {
    c12_S->data[c12_i797] = 0.0;
  }

  c12_n = c12_s->size[0] - 1;
  c12_i799 = c12_n;
  for (c12_b_k = 0; c12_b_k <= c12_i799; c12_b_k++) {
    c12_S->data[c12_b_k + c12_S->size[0] * c12_b_k] = c12_s->data[c12_b_k];
  }

  c12_emxFree_real_T(chartInstance, &c12_s);
}

static void c12_b_svd(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_creal_T *c12_A, c12_emxArray_creal_T *c12_U,
                      c12_emxArray_real_T *c12_s, c12_emxArray_creal_T *c12_V)
{
  c12_emxArray_creal_T *c12_b_A;
  int32_T c12_m;
  int32_T c12_n;
  int32_T c12_b_m;
  int32_T c12_b_n;
  int32_T c12_i805;
  int32_T c12_c_A;
  int32_T c12_d_A;
  int32_T c12_loop_ub;
  int32_T c12_i806;
  c12_emxArray_creal_T *c12_Vt;
  int32_T c12_lda;
  int32_T c12_minnm;
  int32_T c12_i807;
  int32_T c12_i808;
  int32_T c12_i809;
  boolean_T c12_b36;
  boolean_T c12_b37;
  int32_T c12_info;
  ptrdiff_t c12_m_t;
  ptrdiff_t c12_n_t;
  int32_T c12_b_info;
  ptrdiff_t c12_lda_t;
  ptrdiff_t c12_ldu_t;
  int32_T c12_i810;
  int32_T c12_i811;
  ptrdiff_t c12_ldv_t;
  ptrdiff_t c12_info_t;
  int32_T c12_c_info;
  int32_T c12_b_loop_ub;
  int32_T c12_e_A;
  int32_T c12_d_info;
  int32_T c12_i812;
  int32_T c12_f_A;
  boolean_T c12_p;
  int32_T c12_c_loop_ub;
  int32_T c12_i813;
  int32_T c12_d_loop_ub;
  int32_T c12_i814;
  int32_T c12_c_m;
  int32_T c12_c_n;
  int32_T c12_b_minnm;
  int32_T c12_i815;
  int32_T c12_i816;
  int32_T c12_i817;
  boolean_T c12_b38;
  boolean_T c12_b39;
  int32_T c12_e_info;
  ptrdiff_t c12_b_m_t;
  ptrdiff_t c12_b_n_t;
  int32_T c12_i818;
  ptrdiff_t c12_b_lda_t;
  ptrdiff_t c12_b_ldu_t;
  ptrdiff_t c12_b_ldv_t;
  c12_emxArray_real_T *c12_superb;
  int32_T c12_e_loop_ub;
  int32_T c12_i819;
  int32_T c12_i820;
  int32_T c12_i821;
  int32_T c12_f_info;
  int32_T c12_f_loop_ub;
  int32_T c12_g_info;
  int32_T c12_i822;
  ptrdiff_t c12_b_info_t;
  boolean_T c12_b_p;
  int32_T c12_h_info;
  c12_emxInit_creal_T(chartInstance, &c12_b_A, 2, &c12_hi_emlrtRTEI);
  c12_m = c12_A->size[0];
  c12_n = c12_A->size[1];
  c12_b_m = c12_m;
  c12_b_n = c12_n;
  c12_i805 = c12_b_A->size[0] * c12_b_A->size[1];
  c12_b_A->size[0] = c12_A->size[0];
  c12_b_A->size[1] = c12_A->size[1];
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_A, c12_i805,
    &c12_hi_emlrtRTEI);
  c12_c_A = c12_b_A->size[0];
  c12_d_A = c12_b_A->size[1];
  c12_loop_ub = c12_A->size[0] * c12_A->size[1] - 1;
  for (c12_i806 = 0; c12_i806 <= c12_loop_ub; c12_i806++) {
    c12_b_A->data[c12_i806] = c12_A->data[c12_i806];
  }

  c12_emxInit_creal_T(chartInstance, &c12_Vt, 2, &c12_mi_emlrtRTEI);
  c12_lda = c12_m;
  c12_minnm = muIntScalarMin_sint32(c12_b_n, c12_b_m);
  c12_i807 = c12_U->size[0] * c12_U->size[1];
  c12_U->size[0] = c12_b_m;
  c12_U->size[1] = c12_b_m;
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_U, c12_i807,
    &c12_ii_emlrtRTEI);
  c12_i808 = c12_Vt->size[0] * c12_Vt->size[1];
  c12_Vt->size[0] = c12_b_n;
  c12_Vt->size[1] = c12_b_n;
  c12_emxEnsureCapacity_creal_T(chartInstance, c12_Vt, c12_i808,
    &c12_ii_emlrtRTEI);
  c12_i809 = c12_s->size[0];
  c12_s->size[0] = c12_minnm;
  c12_emxEnsureCapacity_real_T1(chartInstance, c12_s, c12_i809,
    &c12_ii_emlrtRTEI);
  c12_b36 = (c12_b_A->size[0] == 0);
  c12_b37 = (c12_b_A->size[1] == 0);
  if (!(c12_b36 || c12_b37)) {
    c12_m_t = (ptrdiff_t)c12_b_m;
    c12_n_t = (ptrdiff_t)c12_b_n;
    c12_lda_t = (ptrdiff_t)c12_lda;
    c12_ldu_t = (ptrdiff_t)c12_b_m;
    c12_ldv_t = (ptrdiff_t)c12_b_n;
    c12_info_t = LAPACKE_zgesdd(102, 'A', c12_m_t, c12_n_t,
      (lapack_complex_double *)&c12_b_A->data[0], c12_lda_t, &c12_s->data[0],
      (lapack_complex_double *)&c12_U->data[0], c12_ldu_t,
      (lapack_complex_double *)&c12_Vt->data[0], c12_ldv_t);
    c12_info = (int32_T)c12_info_t;
    c12_c_info = c12_info;
    c12_d_info = c12_c_info;
    c12_p = (c12_d_info < 0);
    if (c12_p) {
      if (c12_c_info == -1010) {
        c12_d_error(chartInstance);
      } else {
        c12_e_error(chartInstance, c12_c_info);
      }
    }
  } else {
    c12_info = 0;
  }

  c12_b_info = c12_info;
  if (c12_info > 0) {
    c12_i811 = c12_b_A->size[0] * c12_b_A->size[1];
    c12_b_A->size[0] = c12_A->size[0];
    c12_b_A->size[1] = c12_A->size[1];
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_b_A, c12_i811,
      &c12_ki_emlrtRTEI);
    c12_e_A = c12_b_A->size[0];
    c12_f_A = c12_b_A->size[1];
    c12_c_loop_ub = c12_A->size[0] * c12_A->size[1] - 1;
    for (c12_i813 = 0; c12_i813 <= c12_c_loop_ub; c12_i813++) {
      c12_b_A->data[c12_i813] = c12_A->data[c12_i813];
    }

    c12_c_m = c12_b_A->size[0];
    c12_c_n = c12_b_A->size[1];
    c12_b_minnm = muIntScalarMin_sint32(c12_c_n, c12_c_m);
    c12_i815 = c12_U->size[0] * c12_U->size[1];
    c12_U->size[0] = c12_c_m;
    c12_U->size[1] = c12_c_m;
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_U, c12_i815,
      &c12_li_emlrtRTEI);
    c12_i816 = c12_Vt->size[0] * c12_Vt->size[1];
    c12_Vt->size[0] = c12_c_n;
    c12_Vt->size[1] = c12_c_n;
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_Vt, c12_i816,
      &c12_li_emlrtRTEI);
    c12_i817 = c12_s->size[0];
    c12_s->size[0] = c12_b_minnm;
    c12_emxEnsureCapacity_real_T1(chartInstance, c12_s, c12_i817,
      &c12_li_emlrtRTEI);
    c12_b38 = (c12_b_A->size[0] == 0);
    c12_b39 = (c12_b_A->size[1] == 0);
    if (!(c12_b38 || c12_b39)) {
      c12_b_m_t = (ptrdiff_t)c12_c_m;
      c12_b_n_t = (ptrdiff_t)c12_c_n;
      c12_b_lda_t = (ptrdiff_t)c12_c_m;
      c12_b_ldu_t = (ptrdiff_t)c12_c_m;
      c12_b_ldv_t = (ptrdiff_t)c12_c_n;
      c12_emxInit_real_T1(chartInstance, &c12_superb, 1, &c12_ni_emlrtRTEI);
      if (c12_b_minnm > 1) {
        c12_i821 = c12_superb->size[0];
        c12_superb->size[0] = c12_b_minnm - 1;
        c12_emxEnsureCapacity_real_T1(chartInstance, c12_superb, c12_i821,
          &c12_li_emlrtRTEI);
      } else {
        c12_i820 = c12_superb->size[0];
        c12_superb->size[0] = 1;
        c12_emxEnsureCapacity_real_T1(chartInstance, c12_superb, c12_i820,
          &c12_li_emlrtRTEI);
      }

      c12_b_info_t = LAPACKE_zgesvd(102, 'A', 'A', c12_b_m_t, c12_b_n_t,
        (lapack_complex_double *)&c12_b_A->data[0], c12_b_lda_t, &c12_s->data[0],
        (lapack_complex_double *)&c12_U->data[0], c12_b_ldu_t,
        (lapack_complex_double *)&c12_Vt->data[0], c12_b_ldv_t,
        &c12_superb->data[0]);
      c12_e_info = (int32_T)c12_b_info_t;
      c12_emxFree_real_T(chartInstance, &c12_superb);
    } else {
      c12_e_info = 0;
    }

    c12_i818 = c12_V->size[0] * c12_V->size[1];
    c12_V->size[0] = c12_Vt->size[1];
    c12_V->size[1] = c12_Vt->size[0];
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_V, c12_i818,
      &c12_ji_emlrtRTEI);
    c12_e_loop_ub = c12_Vt->size[0] - 1;
    for (c12_i819 = 0; c12_i819 <= c12_e_loop_ub; c12_i819++) {
      c12_f_loop_ub = c12_Vt->size[1] - 1;
      for (c12_i822 = 0; c12_i822 <= c12_f_loop_ub; c12_i822++) {
        c12_V->data[c12_i822 + c12_V->size[0] * c12_i819].re = c12_Vt->
          data[c12_i819 + c12_Vt->size[0] * c12_i822].re;
        c12_V->data[c12_i822 + c12_V->size[0] * c12_i819].im = -c12_Vt->
          data[c12_i819 + c12_Vt->size[0] * c12_i822].im;
      }
    }

    c12_f_info = c12_e_info;
    c12_g_info = c12_f_info;
    c12_b_p = (c12_g_info < 0);
    if (c12_b_p) {
      if (c12_f_info == -1010) {
        c12_d_error(chartInstance);
      } else {
        c12_f_error(chartInstance, c12_f_info);
      }
    }

    c12_h_info = c12_e_info;
    c12_b_info = c12_h_info;
  } else {
    c12_i810 = c12_V->size[0] * c12_V->size[1];
    c12_V->size[0] = c12_Vt->size[1];
    c12_V->size[1] = c12_Vt->size[0];
    c12_emxEnsureCapacity_creal_T(chartInstance, c12_V, c12_i810,
      &c12_ji_emlrtRTEI);
    c12_b_loop_ub = c12_Vt->size[0] - 1;
    for (c12_i812 = 0; c12_i812 <= c12_b_loop_ub; c12_i812++) {
      c12_d_loop_ub = c12_Vt->size[1] - 1;
      for (c12_i814 = 0; c12_i814 <= c12_d_loop_ub; c12_i814++) {
        c12_V->data[c12_i814 + c12_V->size[0] * c12_i812].re = c12_Vt->
          data[c12_i812 + c12_Vt->size[0] * c12_i814].re;
        c12_V->data[c12_i814 + c12_V->size[0] * c12_i812].im = -c12_Vt->
          data[c12_i812 + c12_Vt->size[0] * c12_i814].im;
      }
    }
  }

  c12_emxFree_creal_T(chartInstance, &c12_b_A);
  c12_emxFree_creal_T(chartInstance, &c12_Vt);
  if (c12_b_info > 0) {
    c12_g_error(chartInstance);
  }
}

static void c12_d_error(SFc12_anav_realInstanceStruct *chartInstance)
{
  const mxArray *c12_y = NULL;
  static char_T c12_cv21[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'm', 'e', 'm' };

  const mxArray *c12_b_y = NULL;
  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv21, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv21, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 1U,
    14, c12_b_y)));
}

static void c12_e_error(SFc12_anav_realInstanceStruct *chartInstance, int32_T
  c12_varargin_2)
{
  const mxArray *c12_y = NULL;
  const mxArray *c12_b_y = NULL;
  const mxArray *c12_c_y = NULL;
  static char_T c12_cv22[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'g', 'e', 's', 'd', 'd' };

  const mxArray *c12_d_y = NULL;
  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv4, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv4, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv22, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 3U,
    14, c12_b_y, 14, c12_c_y, 14, c12_d_y)));
}

static void c12_f_error(SFc12_anav_realInstanceStruct *chartInstance, int32_T
  c12_varargin_2)
{
  const mxArray *c12_y = NULL;
  const mxArray *c12_b_y = NULL;
  const mxArray *c12_c_y = NULL;
  static char_T c12_cv23[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'g', 'e', 's', 'v', 'd' };

  const mxArray *c12_d_y = NULL;
  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv4, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv4, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv23, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 3U,
    14, c12_b_y, 14, c12_c_y, 14, c12_d_y)));
}

static void c12_g_error(SFc12_anav_realInstanceStruct *chartInstance)
{
  const mxArray *c12_y = NULL;
  static char_T c12_cv24[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e',
    'r', 'g', 'e', 'n', 'c', 'e' };

  const mxArray *c12_b_y = NULL;
  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv24, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv24, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 1U,
    14, c12_b_y)));
}

static void c12_diag(SFc12_anav_realInstanceStruct *chartInstance,
                     c12_emxArray_real_T *c12_v, c12_emxArray_real_T *c12_d)
{
  boolean_T c12_b40;
  boolean_T c12_b41;
  boolean_T c12_b42;
  int32_T c12_b_v[1];
  boolean_T c12_b43;
  int32_T c12_i823;
  const mxArray *c12_y = NULL;
  static char_T c12_cv25[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'd', 'i', 'a', 'g', '_', 'v', 'a', 'r', 's', 'i',
    'z', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x', 'V', 'e', 'c', 't', 'o', 'r' };

  int32_T c12_m;
  const mxArray *c12_b_y = NULL;
  int32_T c12_n;
  int32_T c12_dlen;
  int32_T c12_iv27[2];
  int32_T c12_i824;
  int32_T c12_i825;
  int32_T c12_k;
  c12_b40 = (c12_v->size[0] == 1);
  c12_b41 = (c12_v->size[1] == 1);
  if (c12_b40 && c12_b41) {
    c12_b_v[0] = c12_v->size[0] * c12_v->size[1];
    c12_i823 = c12_d->size[0];
    c12_d->size[0] = 1;
    c12_emxEnsureCapacity_real_T1(chartInstance, c12_d, c12_i823,
      &c12_oi_emlrtRTEI);
    c12_d->data[0] = c12_v->data[0];
  } else {
    c12_b42 = (c12_v->size[0] == 1);
    c12_b43 = (c12_v->size[1] == 1);
    if (!(c12_b42 || c12_b43)) {
    } else {
      c12_y = NULL;
      sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv25, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      c12_b_y = NULL;
      sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv25, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c12_b_y)));
    }

    c12_m = c12_v->size[0];
    c12_n = c12_v->size[1];
    if (0 < c12_n) {
      c12_dlen = muIntScalarMin_sint32(c12_m, c12_n);
    } else {
      c12_dlen = 0;
    }

    c12_iv27[0] = c12_dlen;
    c12_iv27[1] = 1;
    c12_i824 = c12_d->size[0];
    c12_d->size[0] = c12_iv27[0];
    c12_emxEnsureCapacity_real_T1(chartInstance, c12_d, c12_i824,
      &c12_pi_emlrtRTEI);
    c12_i825 = c12_dlen;
    for (c12_k = 0; c12_k < c12_i825; c12_k++) {
      c12_d->data[c12_k] = c12_v->data[c12_k + c12_v->size[0] * c12_k];
    }
  }
}

static void c12_padImage(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_a_tmp[3081], real_T c12_pad[2], c12_emxArray_real_T *c12_a)
{
  boolean_T c12_p;
  int32_T c12_k;
  real_T c12_b_k;
  real_T c12_b_x;
  boolean_T c12_b44;
  real_T c12_c_x;
  boolean_T c12_b;
  boolean_T c12_b_p;
  const mxArray *c12_y = NULL;
  static char_T c12_cv26[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a',
    'd', 'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'N', 'o', 'n', 'N', 'a', 'N' };

  boolean_T c12_c_p;
  const mxArray *c12_b_y = NULL;
  int32_T c12_c_k;
  static char_T c12_cv27[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  const mxArray *c12_c_y = NULL;
  static char_T c12_cv28[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  real_T c12_d_k;
  real_T c12_d_x;
  boolean_T c12_b45;
  boolean_T c12_d_p;
  const mxArray *c12_d_y = NULL;
  static char_T c12_cv29[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a',
    'd', 'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  boolean_T c12_e_p;
  const mxArray *c12_e_y = NULL;
  int32_T c12_e_k;
  static char_T c12_cv30[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  const mxArray *c12_f_y = NULL;
  static char_T c12_cv31[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  real_T c12_f_k;
  real_T c12_e_x;
  boolean_T c12_b46;
  real_T c12_f_x;
  real_T c12_g_x;
  boolean_T c12_b_b;
  const mxArray *c12_g_y = NULL;
  boolean_T c12_b47;
  static char_T c12_cv32[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a',
    'd', 'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'I', 'n', 't', 'e', 'g', 'e', 'r' };

  int32_T c12_i826;
  real_T c12_h_x;
  const mxArray *c12_h_y = NULL;
  boolean_T c12_c_b;
  static char_T c12_cv33[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  boolean_T c12_b48;
  const mxArray *c12_i_y = NULL;
  int32_T c12_i827;
  real_T c12_j_y[2];
  boolean_T c12_d_b;
  static char_T c12_cv34[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  real_T c12_i_x;
  int32_T c12_i828;
  real_T c12_dv10[2];
  boolean_T c12_f_p;
  real_T c12_j_x;
  boolean_T c12_g_p;
  real_T c12_d10;
  int32_T c12_i829;
  int32_T c12_j;
  real_T c12_e_b;
  real_T c12_b_j;
  int32_T c12_c;
  real_T c12_d11;
  int32_T c12_b_a;
  int32_T c12_i830;
  int32_T c12_i831;
  int32_T c12_i;
  int32_T c12_i832;
  int32_T c12_c_a;
  int32_T c12_f_b;
  real_T c12_b_i;
  int32_T c12_d_a;
  int32_T c12_g_b;
  boolean_T c12_overflow;
  int32_T c12_c_j;
  int32_T c12_d_j;
  real_T c12_d12;
  int32_T c12_i833;
  int32_T c12_c_i;
  int32_T c12_e_j;
  real_T c12_d13;
  int32_T c12_i834;
  int32_T c12_f_j;
  int32_T c12_d_i;
  real_T c12_e_a;
  int32_T c12_b_c;
  int32_T c12_f_a;
  int32_T c12_e_i;
  int32_T c12_i835;
  real_T c12_g_a;
  int32_T c12_i836;
  real_T c12_h_b;
  int32_T c12_h_a;
  int32_T c12_c_c;
  int32_T c12_i_b;
  real_T c12_i_a;
  int32_T c12_j_a;
  real_T c12_j_b;
  int32_T c12_k_b;
  int32_T c12_d_c;
  real_T c12_k_a;
  boolean_T c12_b_overflow;
  real_T c12_l_b;
  int32_T c12_e_c;
  int32_T c12_f_i;
  real_T c12_l_a;
  real_T c12_m_b;
  int32_T c12_f_c;
  boolean_T exitg1;
  c12_p = true;
  c12_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c12_k < 2)) {
    c12_b_k = 1.0 + (real_T)c12_k;
    c12_b_x = c12_pad[(int32_T)c12_b_k - 1];
    c12_c_x = c12_b_x;
    c12_b = muDoubleScalarIsNaN(c12_c_x);
    c12_b_p = !c12_b;
    if (c12_b_p) {
      c12_k++;
    } else {
      c12_p = false;
      exitg1 = true;
    }
  }

  if (c12_p) {
    c12_b44 = true;
  } else {
    c12_b44 = false;
  }

  if (c12_b44) {
  } else {
    c12_y = NULL;
    sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv26, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c12_b_y = NULL;
    sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv27, 10, 0U, 1U, 0U, 2, 1,
      46), false);
    c12_c_y = NULL;
    sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv28, 10, 0U, 1U, 0U, 2, 1,
      24), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c12_b_y, 14, c12_c_y)));
  }

  c12_c_p = true;
  c12_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c12_c_k < 2)) {
    c12_d_k = 1.0 + (real_T)c12_c_k;
    c12_d_x = c12_pad[(int32_T)c12_d_k - 1];
    c12_d_p = !(c12_d_x < 0.0);
    if (c12_d_p) {
      c12_c_k++;
    } else {
      c12_c_p = false;
      exitg1 = true;
    }
  }

  if (c12_c_p) {
    c12_b45 = true;
  } else {
    c12_b45 = false;
  }

  if (c12_b45) {
  } else {
    c12_d_y = NULL;
    sf_mex_assign(&c12_d_y, sf_mex_create("y", c12_cv29, 10, 0U, 1U, 0U, 2, 1,
      35), false);
    c12_e_y = NULL;
    sf_mex_assign(&c12_e_y, sf_mex_create("y", c12_cv30, 10, 0U, 1U, 0U, 2, 1,
      51), false);
    c12_f_y = NULL;
    sf_mex_assign(&c12_f_y, sf_mex_create("y", c12_cv31, 10, 0U, 1U, 0U, 2, 1,
      24), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c12_e_y, 14, c12_f_y)));
  }

  c12_e_p = true;
  c12_e_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c12_e_k < 2)) {
    c12_f_k = 1.0 + (real_T)c12_e_k;
    c12_e_x = c12_pad[(int32_T)c12_f_k - 1];
    c12_f_x = c12_e_x;
    c12_g_x = c12_f_x;
    c12_b_b = muDoubleScalarIsInf(c12_g_x);
    c12_b47 = !c12_b_b;
    c12_h_x = c12_f_x;
    c12_c_b = muDoubleScalarIsNaN(c12_h_x);
    c12_b48 = !c12_c_b;
    c12_d_b = (c12_b47 && c12_b48);
    if (c12_d_b) {
      c12_i_x = c12_e_x;
      c12_j_x = c12_i_x;
      c12_j_x = muDoubleScalarFloor(c12_j_x);
      if (c12_j_x == c12_e_x) {
        c12_f_p = true;
      } else {
        c12_f_p = false;
      }
    } else {
      c12_f_p = false;
    }

    c12_g_p = c12_f_p;
    if (c12_g_p) {
      c12_e_k++;
    } else {
      c12_e_p = false;
      exitg1 = true;
    }
  }

  if (c12_e_p) {
    c12_b46 = true;
  } else {
    c12_b46 = false;
  }

  if (c12_b46) {
  } else {
    c12_g_y = NULL;
    sf_mex_assign(&c12_g_y, sf_mex_create("y", c12_cv32, 10, 0U, 1U, 0U, 2, 1,
      31), false);
    c12_h_y = NULL;
    sf_mex_assign(&c12_h_y, sf_mex_create("y", c12_cv33, 10, 0U, 1U, 0U, 2, 1,
      47), false);
    c12_i_y = NULL;
    sf_mex_assign(&c12_i_y, sf_mex_create("y", c12_cv34, 10, 0U, 1U, 0U, 2, 1,
      24), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_g_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c12_h_y, 14, c12_i_y)));
  }

  for (c12_i826 = 0; c12_i826 < 2; c12_i826++) {
    c12_j_y[c12_i826] = 2.0 * c12_pad[c12_i826];
  }

  for (c12_i827 = 0; c12_i827 < 2; c12_i827++) {
    c12_dv10[c12_i827] = sf_integer_check(chartInstance->S, 1U, 0U, 0U,
      _SFD_NON_NEGATIVE_CHECK("", (39.0 + 40.0 * (real_T)c12_i827) +
      c12_j_y[c12_i827]));
  }

  c12_i828 = c12_a->size[0] * c12_a->size[1];
  c12_a->size[0] = (int32_T)c12_dv10[0];
  c12_a->size[1] = (int32_T)c12_dv10[1];
  c12_emxEnsureCapacity_real_T(chartInstance, c12_a, c12_i828, &c12_qi_emlrtRTEI);
  c12_d10 = c12_pad[1];
  c12_i829 = (int32_T)c12_d10 - 1;
  for (c12_j = 0; c12_j <= c12_i829; c12_j++) {
    c12_b_j = 1.0 + (real_T)c12_j;
    c12_d11 = (real_T)c12_a->size[0];
    c12_i830 = (int32_T)c12_d11 - 1;
    for (c12_i = 0; c12_i <= c12_i830; c12_i++) {
      c12_b_i = 1.0 + (real_T)c12_i;
      c12_a->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c12_b_i, 1,
        c12_a->size[0]) + c12_a->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c12_b_j, 1, c12_a->size[1]) - 1)) - 1] = 0.0;
    }
  }

  c12_e_b = c12_pad[1];
  c12_c = (int32_T)c12_e_b;
  c12_b_a = c12_c + 80;
  c12_i831 = c12_b_a;
  c12_i832 = c12_a->size[1];
  c12_c_a = c12_i831;
  c12_f_b = c12_i832;
  c12_d_a = c12_c_a;
  c12_g_b = c12_f_b;
  if (c12_d_a > c12_g_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_g_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_c_j = c12_i831; c12_c_j <= c12_i832; c12_c_j++) {
    c12_d12 = (real_T)c12_a->size[0];
    c12_i833 = (int32_T)c12_d12 - 1;
    for (c12_c_i = 0; c12_c_i <= c12_i833; c12_c_i++) {
      c12_b_i = 1.0 + (real_T)c12_c_i;
      c12_a->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c12_b_i, 1,
        c12_a->size[0]) + c12_a->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c12_c_j, 1, c12_a->size[1]) - 1)) - 1] = 0.0;
    }
  }

  for (c12_d_j = 0; c12_d_j < 79; c12_d_j++) {
    c12_b_j = 1.0 + (real_T)c12_d_j;
    c12_d13 = c12_pad[0];
    c12_i834 = (int32_T)c12_d13 - 1;
    for (c12_d_i = 0; c12_d_i <= c12_i834; c12_d_i++) {
      c12_b_i = 1.0 + (real_T)c12_d_i;
      c12_g_a = c12_b_j;
      c12_h_b = c12_pad[1];
      c12_c_c = (int32_T)c12_g_a + (int32_T)c12_h_b;
      c12_a->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c12_b_i, 1,
        c12_a->size[0]) + c12_a->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c12_c_c, 1, c12_a->size[1]) - 1)) - 1] = 0.0;
    }
  }

  for (c12_e_j = 0; c12_e_j < 79; c12_e_j++) {
    c12_b_j = 1.0 + (real_T)c12_e_j;
    c12_e_a = c12_pad[0];
    c12_b_c = (int32_T)c12_e_a;
    c12_f_a = c12_b_c + 40;
    c12_i835 = c12_f_a;
    c12_i836 = c12_a->size[0];
    c12_h_a = c12_i835;
    c12_i_b = c12_i836;
    c12_j_a = c12_h_a;
    c12_k_b = c12_i_b;
    if (c12_j_a > c12_k_b) {
      c12_b_overflow = false;
    } else {
      c12_b_overflow = (c12_k_b > 2147483646);
    }

    if (c12_b_overflow) {
      c12_check_forloop_overflow_error(chartInstance, true);
    }

    for (c12_f_i = c12_i835; c12_f_i <= c12_i836; c12_f_i++) {
      c12_l_a = c12_b_j;
      c12_m_b = c12_pad[1];
      c12_f_c = (int32_T)c12_l_a + (int32_T)c12_m_b;
      c12_a->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_f_i, 1, c12_a->size[0]) +
                   c12_a->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c12_f_c, 1, c12_a->size[1]) - 1)) - 1] = 0.0;
    }
  }

  for (c12_f_j = 0; c12_f_j < 79; c12_f_j++) {
    c12_b_j = 1.0 + (real_T)c12_f_j;
    for (c12_e_i = 0; c12_e_i < 39; c12_e_i++) {
      c12_b_i = 1.0 + (real_T)c12_e_i;
      c12_i_a = c12_b_i;
      c12_j_b = c12_pad[0];
      c12_d_c = (int32_T)c12_i_a + (int32_T)c12_j_b;
      c12_k_a = c12_b_j;
      c12_l_b = c12_pad[1];
      c12_e_c = (int32_T)c12_k_a + (int32_T)c12_l_b;
      c12_a->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c12_d_c, 1, c12_a->size[0]) +
                   c12_a->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c12_e_c, 1, c12_a->size[1]) - 1)) - 1] = c12_a_tmp[((int32_T)c12_b_i +
        39 * ((int32_T)c12_b_j - 1)) - 1];
    }
  }
}

static const mxArray *c12_emlrt_marshallOut(SFc12_anav_realInstanceStruct
  *chartInstance, const char_T c12_u[34])
{
  const mxArray *c12_y = NULL;
  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  return c12_y;
}

static const mxArray *c12_b_emlrt_marshallOut(SFc12_anav_realInstanceStruct
  *chartInstance, const char_T c12_u[30])
{
  const mxArray *c12_y = NULL;
  (void)chartInstance;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  return c12_y;
}

static const mxArray *c12_r_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_r_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i837;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i837, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i837;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_y = c12_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_s_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_anav_real, const char_T
  *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = (const char *)c12_identifier;
  c12_thisId.fParent = NULL;
  c12_thisId.bParentIsCell = false;
  c12_y = c12_t_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_anav_real), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_anav_real);
  return c12_y;
}

static uint8_T c12_t_emlrt_marshallIn(SFc12_anav_realInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_cos(SFc12_anav_realInstanceStruct *chartInstance, real_T
                      c12_x_data[], int32_T c12_x_size[1])
{
  int32_T c12_nx;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  real_T c12_b_x;
  real_T c12_c_x;
  c12_nx = c12_x_size[0];
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_b_x = c12_x_data[c12_k];
    c12_c_x = c12_b_x;
    c12_c_x = muDoubleScalarCos(c12_c_x);
    c12_x_data[c12_k] = c12_c_x;
  }
}

static void c12_c_sin(SFc12_anav_realInstanceStruct *chartInstance, real_T
                      c12_x_data[], int32_T c12_x_size[1])
{
  int32_T c12_nx;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  real_T c12_b_x;
  real_T c12_c_x;
  c12_nx = c12_x_size[0];
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_b_x = c12_x_data[c12_k];
    c12_c_x = c12_b_x;
    c12_c_x = muDoubleScalarSin(c12_c_x);
    c12_x_data[c12_k] = c12_c_x;
  }
}

static void c12_b_round(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_x_data[], int32_T c12_x_size[2])
{
  int32_T c12_nx;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  real_T c12_b_x;
  real_T c12_c_x;
  int32_T c12_d_x[1];
  c12_nx = c12_x_size[0] * c12_x_size[1];
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_b_x = c12_x_data[c12_k];
    c12_c_x = c12_b_x;
    c12_c_x = muDoubleScalarRound(c12_c_x);
    c12_d_x[0] = c12_x_size[0] * c12_x_size[1];
    c12_x_data[c12_k] = c12_c_x;
  }
}

static void c12_b_sortrows(SFc12_anav_realInstanceStruct *chartInstance, real_T
  c12_b_y_data[], int32_T c12_y_size[2], real_T c12_ndx_data[], int32_T
  c12_ndx_size[1])
{
  int32_T c12_n;
  int32_T c12_b_n;
  int32_T c12_col_size[2];
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  int32_T c12_b_y_size[2];
  int32_T c12_col_data[2];
  int32_T c12_y;
  int32_T c12_b_y;
  int32_T c12_loop_ub;
  int32_T c12_i838;
  int32_T c12_idx_data[1081];
  int32_T c12_idx_size[1];
  int32_T c12_b_idx_size[1];
  int32_T c12_b_loop_ub;
  int32_T c12_i839;
  int32_T c12_b_idx_data[1081];
  int32_T c12_c_loop_ub;
  int32_T c12_i840;
  c12_n = c12_y_size[1];
  c12_b_n = c12_n;
  c12_col_size[0] = 1;
  c12_col_size[1] = c12_b_n;
  c12_b = c12_b_n;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 1; c12_k <= c12_b_n; c12_k++) {
    c12_col_data[c12_k - 1] = c12_k;
  }

  c12_b_y_size[0] = c12_y_size[0];
  c12_b_y_size[1] = c12_y_size[1];
  c12_y = c12_b_y_size[0];
  c12_b_y = c12_b_y_size[1];
  c12_loop_ub = c12_y_size[0] * c12_y_size[1] - 1;
  for (c12_i838 = 0; c12_i838 <= c12_loop_ub; c12_i838++) {
    chartInstance->c12_y_data[c12_i838] = c12_b_y_data[c12_i838];
  }

  c12_sortIdx(chartInstance, chartInstance->c12_y_data, c12_b_y_size,
              c12_col_data, c12_col_size, c12_idx_data, c12_idx_size);
  c12_b_idx_size[0] = c12_idx_size[0];
  c12_b_loop_ub = c12_idx_size[0] - 1;
  for (c12_i839 = 0; c12_i839 <= c12_b_loop_ub; c12_i839++) {
    c12_b_idx_data[c12_i839] = c12_idx_data[c12_i839];
  }

  c12_b_apply_row_permutation(chartInstance, c12_b_y_data, c12_y_size,
    c12_b_idx_data, c12_b_idx_size);
  c12_ndx_size[0] = c12_idx_size[0];
  c12_c_loop_ub = c12_idx_size[0] - 1;
  for (c12_i840 = 0; c12_i840 <= c12_c_loop_ub; c12_i840++) {
    c12_ndx_data[c12_i840] = (real_T)c12_idx_data[c12_i840];
  }
}

static void c12_b_mergesort(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_idx_data[], int32_T c12_idx_size[1], real_T c12_x_data[], int32_T
  c12_x_size[2], int32_T c12_dir_data[], int32_T c12_dir_size[2], int32_T c12_n)
{
  int32_T c12_len;
  int32_T c12_iwork_size[1];
  int32_T c12_iv28[1];
  int32_T c12_np1;
  int32_T c12_i841;
  int32_T c12_k;
  int32_T c12_b_x_size[2];
  int32_T c12_i;
  int32_T c12_b_x;
  int32_T c12_c_x;
  int32_T c12_loop_ub;
  int32_T c12_a;
  int32_T c12_i842;
  int32_T c12_i2;
  int32_T c12_j;
  int32_T c12_pEnd;
  int32_T c12_b_dir_size[2];
  real_T c12_b_x_data[2162];
  int32_T c12_dir;
  int32_T c12_p;
  int32_T c12_b_dir;
  int32_T c12_q;
  int32_T c12_b_loop_ub;
  int32_T c12_qEnd;
  int32_T c12_i843;
  int32_T c12_b_k;
  int32_T c12_b_dir_data[2];
  int32_T c12_kEnd;
  int32_T c12_c_x_size[2];
  int32_T c12_b;
  int32_T c12_b_b;
  int32_T c12_d_x;
  int32_T c12_e_x;
  boolean_T c12_overflow;
  int32_T c12_c_loop_ub;
  int32_T c12_i844;
  int32_T c12_c_k;
  int32_T c12_c_dir_size[2];
  real_T c12_c_x_data[2162];
  int32_T c12_c_dir;
  int32_T c12_iwork_data[1081];
  int32_T c12_d_dir;
  int32_T c12_d_loop_ub;
  int32_T c12_i845;
  int32_T c12_c_dir_data[2];
  c12_len = c12_idx_size[0];
  c12_iwork_size[0] = c12_len;
  c12_iv28[0] = c12_iwork_size[0];
  c12_iwork_size[0] = c12_iv28[0];
  c12_np1 = c12_n + 1;
  c12_i841 = c12_n;
  for (c12_k = 1; c12_k <= c12_i841 - 1; c12_k += 2) {
    c12_b_x_size[0] = c12_x_size[0];
    c12_b_x_size[1] = c12_x_size[1];
    c12_b_x = c12_b_x_size[0];
    c12_c_x = c12_b_x_size[1];
    c12_loop_ub = c12_x_size[0] * c12_x_size[1] - 1;
    for (c12_i842 = 0; c12_i842 <= c12_loop_ub; c12_i842++) {
      c12_b_x_data[c12_i842] = c12_x_data[c12_i842];
    }

    c12_b_dir_size[0] = 1;
    c12_b_dir_size[1] = c12_dir_size[1];
    c12_dir = c12_b_dir_size[0];
    c12_b_dir = c12_b_dir_size[1];
    c12_b_loop_ub = c12_dir_size[0] * c12_dir_size[1] - 1;
    for (c12_i843 = 0; c12_i843 <= c12_b_loop_ub; c12_i843++) {
      c12_b_dir_data[c12_i843] = c12_dir_data[c12_i843];
    }

    if (c12_sortLE(chartInstance, c12_b_x_data, c12_b_x_size, c12_b_dir_data,
                   c12_b_dir_size, c12_k, c12_k + 1)) {
      c12_idx_data[c12_k - 1] = c12_k;
      c12_idx_data[c12_k] = c12_k + 1;
    } else {
      c12_idx_data[c12_k - 1] = c12_k + 1;
      c12_idx_data[c12_k] = c12_k;
    }
  }

  if ((c12_n & 1) != 0) {
    c12_idx_data[c12_n - 1] = c12_n;
  }

  c12_i = 2;
  while (c12_i < c12_n) {
    c12_a = c12_i;
    c12_i2 = c12_a << 1;
    c12_j = 1;
    for (c12_pEnd = 1 + c12_i; c12_pEnd < c12_np1; c12_pEnd = c12_qEnd + c12_i)
    {
      c12_p = c12_j - 1;
      c12_q = c12_pEnd - 1;
      c12_qEnd = c12_j + c12_i2;
      if (c12_qEnd > c12_np1) {
        c12_qEnd = c12_np1;
      }

      c12_b_k = 0;
      c12_kEnd = c12_qEnd - c12_j;
      while (c12_b_k + 1 <= c12_kEnd) {
        c12_c_x_size[0] = c12_x_size[0];
        c12_c_x_size[1] = c12_x_size[1];
        c12_d_x = c12_c_x_size[0];
        c12_e_x = c12_c_x_size[1];
        c12_c_loop_ub = c12_x_size[0] * c12_x_size[1] - 1;
        for (c12_i844 = 0; c12_i844 <= c12_c_loop_ub; c12_i844++) {
          c12_c_x_data[c12_i844] = c12_x_data[c12_i844];
        }

        c12_c_dir_size[0] = 1;
        c12_c_dir_size[1] = c12_dir_size[1];
        c12_c_dir = c12_c_dir_size[0];
        c12_d_dir = c12_c_dir_size[1];
        c12_d_loop_ub = c12_dir_size[0] * c12_dir_size[1] - 1;
        for (c12_i845 = 0; c12_i845 <= c12_d_loop_ub; c12_i845++) {
          c12_c_dir_data[c12_i845] = c12_dir_data[c12_i845];
        }

        if (c12_sortLE(chartInstance, c12_c_x_data, c12_c_x_size, c12_c_dir_data,
                       c12_c_dir_size, c12_idx_data[c12_p], c12_idx_data[c12_q]))
        {
          c12_iwork_data[c12_b_k] = c12_idx_data[c12_p];
          c12_p++;
          if (c12_p + 1 == c12_pEnd) {
            while (c12_q + 1 < c12_qEnd) {
              c12_b_k++;
              c12_iwork_data[c12_b_k] = c12_idx_data[c12_q];
              c12_q++;
            }
          }
        } else {
          c12_iwork_data[c12_b_k] = c12_idx_data[c12_q];
          c12_q++;
          if (c12_q + 1 == c12_qEnd) {
            while (c12_p + 1 < c12_pEnd) {
              c12_b_k++;
              c12_iwork_data[c12_b_k] = c12_idx_data[c12_p];
              c12_p++;
            }
          }
        }

        c12_b_k++;
      }

      c12_p = c12_j - 2;
      c12_b = c12_kEnd;
      c12_b_b = c12_b;
      if (1 > c12_b_b) {
        c12_overflow = false;
      } else {
        c12_overflow = (c12_b_b > 2147483646);
      }

      if (c12_overflow) {
        c12_check_forloop_overflow_error(chartInstance, true);
      }

      for (c12_c_k = 1; c12_c_k <= c12_kEnd; c12_c_k++) {
        c12_idx_data[c12_p + c12_c_k] = c12_iwork_data[c12_c_k - 1];
      }

      c12_j = c12_qEnd;
    }

    c12_i = c12_i2;
  }
}

static void c12_b_apply_row_permutation(SFc12_anav_realInstanceStruct
  *chartInstance, real_T c12_b_y_data[], int32_T c12_y_size[2], int32_T
  c12_idx_data[], int32_T c12_idx_size[1])
{
  int32_T c12_m;
  int32_T c12_n;
  int32_T c12_iv29[2];
  int32_T c12_ycol_size[1];
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_j;
  int32_T c12_c_b;
  int32_T c12_d_b;
  boolean_T c12_b_overflow;
  int32_T c12_i;
  int32_T c12_e_b;
  real_T c12_ycol_data[1081];
  int32_T c12_f_b;
  boolean_T c12_c_overflow;
  int32_T c12_b_i;
  (void)c12_idx_size;
  c12_m = c12_y_size[0];
  c12_n = c12_y_size[1];
  c12_iv29[0] = c12_m;
  c12_iv29[1] = 1;
  c12_ycol_size[0] = c12_iv29[0];
  c12_b = c12_n;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_j = 0; c12_j < c12_n; c12_j++) {
    c12_c_b = c12_m;
    c12_d_b = c12_c_b;
    if (1 > c12_d_b) {
      c12_b_overflow = false;
    } else {
      c12_b_overflow = (c12_d_b > 2147483646);
    }

    if (c12_b_overflow) {
      c12_check_forloop_overflow_error(chartInstance, true);
    }

    for (c12_i = 0; c12_i < c12_m; c12_i++) {
      c12_ycol_data[c12_i] = c12_b_y_data[(c12_idx_data[c12_i] + c12_y_size[0] *
        c12_j) - 1];
    }

    c12_e_b = c12_m;
    c12_f_b = c12_e_b;
    if (1 > c12_f_b) {
      c12_c_overflow = false;
    } else {
      c12_c_overflow = (c12_f_b > 2147483646);
    }

    if (c12_c_overflow) {
      c12_check_forloop_overflow_error(chartInstance, true);
    }

    for (c12_b_i = 0; c12_b_i < c12_m; c12_b_i++) {
      c12_b_y_data[c12_b_i + c12_y_size[0] * c12_j] = c12_ycol_data[c12_b_i];
    }
  }
}

static void c12_b_nullAssignment(SFc12_anav_realInstanceStruct *chartInstance,
  real_T c12_x_data[], int32_T c12_x_size[2], boolean_T c12_idx_data[], int32_T
  c12_idx_size[1])
{
  real_T c12_d14;
  int32_T c12_n;
  int32_T c12_k;
  boolean_T c12_p;
  const mxArray *c12_y = NULL;
  static char_T c12_cv35[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c',
    'h' };

  int32_T c12_nrowx;
  const mxArray *c12_b_y = NULL;
  int32_T c12_b_n;
  int32_T c12_i846;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_b_k;
  int32_T c12_nrows;
  int32_T c12_nb;
  int32_T c12_i;
  int32_T c12_c_b;
  int32_T c12_d_b;
  boolean_T c12_b_overflow;
  int32_T c12_c_k;
  const mxArray *c12_c_y = NULL;
  boolean_T c12_b49;
  int32_T c12_j;
  const mxArray *c12_d_y = NULL;
  boolean_T c12_b50;
  boolean_T c12_b51;
  int32_T c12_i847;
  int32_T c12_b_x_size[2];
  int32_T c12_i848;
  int32_T c12_loop_ub;
  int32_T c12_i849;
  int32_T c12_i850;
  real_T c12_b_x_data[2634];
  int32_T c12_b_loop_ub;
  int32_T c12_i851;
  c12_d14 = (real_T)c12_x_size[0];
  c12_n = (int32_T)c12_d14;
  c12_k = c12_idx_size[0];
  while ((c12_k >= 1) && (!c12_idx_data[c12_k - 1])) {
    c12_k--;
  }

  c12_p = (c12_k <= c12_n);
  if (c12_p) {
  } else {
    c12_y = NULL;
    sf_mex_assign(&c12_y, sf_mex_create("y", c12_cv35, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c12_b_y = NULL;
    sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_cv35, 10, 0U, 1U, 0U, 2, 1,
      25), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c12_b_y)));
  }

  c12_nrowx = c12_x_size[0];
  c12_b_n = 0;
  c12_i846 = c12_idx_size[0];
  c12_b = c12_i846;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_b_k = 0; c12_b_k < c12_i846; c12_b_k++) {
    c12_b_n += (int32_T)c12_idx_data[c12_b_k];
  }

  c12_nrows = c12_nrowx - c12_b_n;
  c12_nb = c12_idx_size[0];
  c12_i = 0;
  c12_c_b = c12_nrowx;
  c12_d_b = c12_c_b;
  if (1 > c12_d_b) {
    c12_b_overflow = false;
  } else {
    c12_b_overflow = (c12_d_b > 2147483646);
  }

  if (c12_b_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_c_k = 0; c12_c_k < c12_nrowx; c12_c_k++) {
    if ((c12_c_k + 1 > c12_nb) || (!c12_idx_data[c12_c_k])) {
      for (c12_j = 0; c12_j < 2; c12_j++) {
        c12_x_data[c12_i + c12_x_size[0] * c12_j] = c12_x_data[c12_c_k +
          c12_x_size[0] * c12_j];
      }

      c12_i++;
    }
  }

  if (c12_nrows <= c12_nrowx) {
  } else {
    c12_c_y = NULL;
    sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c12_d_y = NULL;
    sf_mex_assign(&c12_d_y, sf_mex_create("y", c12_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c12_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c12_d_y)));
  }

  c12_b49 = (1 > c12_nrows);
  c12_b50 = c12_b49;
  c12_b51 = c12_b50;
  if (c12_b51) {
    c12_i847 = 0;
  } else {
    c12_i847 = c12_nrows;
  }

  c12_b_x_size[0] = c12_i847;
  c12_b_x_size[1] = 2;
  for (c12_i848 = 0; c12_i848 < 2; c12_i848++) {
    c12_loop_ub = c12_i847 - 1;
    for (c12_i849 = 0; c12_i849 <= c12_loop_ub; c12_i849++) {
      c12_b_x_data[c12_i849 + c12_b_x_size[0] * c12_i848] = c12_x_data[c12_i849
        + c12_x_size[0] * c12_i848];
    }
  }

  c12_x_size[0] = c12_b_x_size[0];
  c12_x_size[1] = 2;
  for (c12_i850 = 0; c12_i850 < 2; c12_i850++) {
    c12_b_loop_ub = c12_b_x_size[0] - 1;
    for (c12_i851 = 0; c12_i851 <= c12_b_loop_ub; c12_i851++) {
      c12_x_data[c12_i851 + c12_x_size[0] * c12_i850] = c12_b_x_data[c12_i851 +
        c12_b_x_size[0] * c12_i850];
    }
  }
}

static void c12_d_sqrt(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T *c12_b_x)
{
  int32_T c12_nx;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  int32_T c12_c_x[1];
  c12_nx = c12_b_x->size[0] * c12_b_x->size[1];
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_c_x[0] = c12_b_x->size[0] * c12_b_x->size[1];
    c12_e_sqrt(chartInstance, &c12_b_x->data[c12_k]);
  }
}

static void c12_e_sqrt(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  *c12_b_x)
{
  real_T c12_xr;
  real_T c12_xi;
  real_T c12_c_x;
  real_T c12_yr;
  boolean_T c12_b;
  real_T c12_d_x;
  real_T c12_e_x;
  real_T c12_yi;
  real_T c12_f_x;
  real_T c12_g_x;
  real_T c12_h_x;
  real_T c12_z;
  real_T c12_b_z;
  boolean_T c12_b_b;
  real_T c12_i_x;
  boolean_T c12_c_b;
  real_T c12_j_x;
  boolean_T c12_d_b;
  real_T c12_absxr;
  real_T c12_absxi;
  real_T c12_k_x;
  real_T c12_y;
  real_T c12_x1;
  real_T c12_l_x;
  real_T c12_x2;
  real_T c12_b_y;
  real_T c12_c_z;
  real_T c12_b_x1;
  real_T c12_b_x2;
  real_T c12_absxd2;
  real_T c12_m_x;
  real_T c12_n_x;
  real_T c12_c_y;
  real_T c12_d_y;
  real_T c12_o_x;
  real_T c12_p_x;
  real_T c12_q_x;
  real_T c12_e_y;
  real_T c12_f_y;
  real_T c12_g_y;
  real_T c12_d_z;
  real_T c12_e_z;
  real_T c12_r_x;
  real_T c12_h_y;
  real_T c12_f_z;
  (void)chartInstance;
  c12_xr = c12_b_x->re;
  c12_xi = c12_b_x->im;
  if (c12_xi == 0.0) {
    if (c12_xr < 0.0) {
      c12_yr = 0.0;
      c12_yi = muDoubleScalarSqrt(-c12_xr);
    } else {
      c12_yr = muDoubleScalarSqrt(c12_xr);
      c12_yi = 0.0;
    }
  } else if (c12_xr == 0.0) {
    if (c12_xi < 0.0) {
      c12_e_x = -c12_xi;
      c12_g_x = c12_e_x;
      c12_b_z = c12_g_x / 2.0;
      c12_yr = muDoubleScalarSqrt(c12_b_z);
      c12_yi = -c12_yr;
    } else {
      c12_d_x = c12_xi;
      c12_f_x = c12_d_x;
      c12_z = c12_f_x / 2.0;
      c12_yr = muDoubleScalarSqrt(c12_z);
      c12_yi = c12_yr;
    }
  } else {
    c12_c_x = c12_xr;
    c12_b = muDoubleScalarIsNaN(c12_c_x);
    if (c12_b) {
      c12_yr = c12_xr;
      c12_yi = c12_xr;
    } else {
      c12_h_x = c12_xi;
      c12_b_b = muDoubleScalarIsNaN(c12_h_x);
      if (c12_b_b) {
        c12_yr = c12_xi;
        c12_yi = c12_xi;
      } else {
        c12_i_x = c12_xi;
        c12_c_b = muDoubleScalarIsInf(c12_i_x);
        if (c12_c_b) {
          c12_yr = muDoubleScalarAbs(c12_xi);
          c12_yi = c12_xi;
        } else {
          c12_j_x = c12_xr;
          c12_d_b = muDoubleScalarIsInf(c12_j_x);
          if (c12_d_b) {
            if (c12_xr < 0.0) {
              c12_yr = 0.0;
              c12_yi = c12_xi * -c12_xr;
            } else {
              c12_yr = c12_xr;
              c12_yi = 0.0;
            }
          } else {
            c12_absxr = muDoubleScalarAbs(c12_xr);
            c12_absxi = muDoubleScalarAbs(c12_xi);
            if ((c12_absxr > 4.4942328371557893E+307) || (c12_absxi >
                 4.4942328371557893E+307)) {
              c12_absxr *= 0.5;
              c12_absxi *= 0.5;
              c12_l_x = c12_absxr;
              c12_b_y = c12_absxi;
              c12_b_x1 = c12_l_x;
              c12_b_x2 = c12_b_y;
              c12_absxd2 = muDoubleScalarHypot(c12_b_x1, c12_b_x2);
              if (c12_absxd2 > c12_absxr) {
                c12_n_x = c12_absxr;
                c12_d_y = c12_absxd2;
                c12_p_x = c12_n_x;
                c12_f_y = c12_d_y;
                c12_e_z = c12_p_x / c12_f_y;
                c12_yr = muDoubleScalarSqrt(c12_absxd2) * muDoubleScalarSqrt(1.0
                  + c12_e_z);
              } else {
                c12_yr = muDoubleScalarSqrt(c12_absxd2) * 1.4142135623730951;
              }
            } else {
              c12_k_x = c12_absxr;
              c12_y = c12_absxi;
              c12_x1 = c12_k_x;
              c12_x2 = c12_y;
              c12_c_z = muDoubleScalarHypot(c12_x1, c12_x2);
              c12_yr = muDoubleScalarSqrt((c12_c_z + c12_absxr) * 0.5);
            }

            if (c12_xr > 0.0) {
              c12_m_x = c12_xi;
              c12_c_y = c12_yr;
              c12_o_x = c12_m_x;
              c12_e_y = c12_c_y;
              c12_d_z = c12_o_x / c12_e_y;
              c12_yi = 0.5 * c12_d_z;
            } else {
              if (c12_xi < 0.0) {
                c12_yi = -c12_yr;
              } else {
                c12_yi = c12_yr;
              }

              c12_q_x = c12_xi;
              c12_g_y = c12_yi;
              c12_r_x = c12_q_x;
              c12_h_y = c12_g_y;
              c12_f_z = c12_r_x / c12_h_y;
              c12_yr = 0.5 * c12_f_z;
            }
          }
        }
      }
    }
  }

  c12_b_x->re = c12_yr;
  c12_b_x->im = c12_yi;
}

static void c12_c_asin(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T *c12_b_x)
{
  int32_T c12_nx;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  int32_T c12_c_x[1];
  c12_nx = c12_b_x->size[0] * c12_b_x->size[1];
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_c_x[0] = c12_b_x->size[0] * c12_b_x->size[1];
    c12_d_asin(chartInstance, &c12_b_x->data[c12_k]);
  }
}

static void c12_d_asin(SFc12_anav_realInstanceStruct *chartInstance, creal_T
  *c12_b_x)
{
  creal_T c12_v;
  creal_T c12_c_x;
  creal_T c12_u;
  real_T c12_ar;
  real_T c12_ai;
  real_T c12_br;
  real_T c12_bi;
  real_T c12_tmp;
  real_T c12_d_x;
  real_T c12_e_x;
  real_T c12_y;
  boolean_T c12_b;
  real_T c12_f_x;
  boolean_T c12_b52;
  real_T c12_yr;
  real_T c12_g_x;
  real_T c12_b_ar;
  boolean_T c12_b_b;
  real_T c12_b_ai;
  boolean_T c12_b53;
  real_T c12_b_br;
  boolean_T c12_c_b;
  real_T c12_b_bi;
  real_T c12_cr;
  real_T c12_c_ar;
  real_T c12_ci;
  real_T c12_c_ai;
  real_T c12_h_x;
  real_T c12_c_br;
  real_T c12_i_x;
  real_T c12_c_bi;
  boolean_T c12_d_b;
  real_T c12_j_x;
  real_T c12_b_cr;
  boolean_T c12_b54;
  real_T c12_yi;
  real_T c12_k_x;
  real_T c12_l_x;
  boolean_T c12_xneg;
  boolean_T c12_e_b;
  boolean_T c12_f_b;
  boolean_T c12_b55;
  real_T c12_m_x;
  boolean_T c12_g_b;
  boolean_T c12_h_b;
  real_T c12_b_ci;
  real_T c12_t;
  real_T c12_n_x;
  real_T c12_d_ar;
  real_T c12_z;
  boolean_T c12_i_b;
  real_T c12_d_ai;
  real_T c12_d_br;
  real_T c12_o_x;
  real_T c12_p_x;
  real_T c12_d_bi;
  real_T c12_absz;
  boolean_T c12_j_b;
  real_T c12_c_ci;
  real_T c12_q_x;
  real_T c12_r_x;
  real_T c12_sar;
  boolean_T c12_k_b;
  real_T c12_s_x;
  real_T c12_t_x;
  real_T c12_sai;
  boolean_T c12_l_b;
  real_T c12_scaleA;
  real_T c12_u_x;
  boolean_T c12_b56;
  real_T c12_sbr;
  boolean_T c12_m_b;
  real_T c12_v_x;
  real_T c12_sbi;
  boolean_T c12_n_b;
  real_T c12_scaleB;
  real_T c12_w_x;
  boolean_T c12_b57;
  real_T c12_x_x;
  boolean_T c12_o_b;
  boolean_T c12_p_b;
  real_T c12_y_x;
  boolean_T c12_q_b;
  real_T c12_ab_x;
  boolean_T c12_b58;
  boolean_T c12_r_b;
  real_T c12_b_u;
  real_T c12_bb_x;
  real_T c12_cb_x;
  boolean_T c12_s_b;
  real_T c12_b_sar;
  real_T c12_db_x;
  boolean_T c12_b59;
  real_T c12_b_sai;
  boolean_T c12_t_b;
  real_T c12_b_scaleA;
  real_T c12_b_sbr;
  real_T c12_eb_x;
  real_T c12_b_sbi;
  boolean_T c12_finiteScale;
  real_T c12_fb_x;
  real_T c12_b_scaleB;
  boolean_T c12_u_b;
  real_T c12_gb_x;
  real_T c12_hb_x;
  boolean_T c12_b60;
  real_T c12_ib_x;
  boolean_T c12_v_b;
  real_T c12_jb_x;
  boolean_T c12_w_b;
  boolean_T c12_x_b;
  boolean_T c12_b61;
  real_T c12_kb_x;
  boolean_T c12_b62;
  real_T c12_lb_x;
  boolean_T c12_y_b;
  real_T c12_st1;
  boolean_T c12_ab_b;
  boolean_T c12_bb_b;
  real_T c12_st2;
  boolean_T c12_b63;
  boolean_T c12_cb_b;
  real_T c12_mb_x;
  real_T c12_nb_x;
  boolean_T c12_db_b;
  boolean_T c12_b_finiteScale;
  real_T c12_ob_x;
  boolean_T c12_eb_b;
  real_T c12_pb_x;
  boolean_T c12_b64;
  real_T c12_qb_x;
  boolean_T c12_fb_b;
  real_T c12_rb_x;
  boolean_T c12_gb_b;
  boolean_T c12_hb_b;
  real_T c12_t1;
  real_T c12_sb_x;
  boolean_T c12_b65;
  real_T c12_t2;
  boolean_T c12_ib_b;
  real_T c12_st3;
  boolean_T c12_jb_b;
  real_T c12_tb_x;
  real_T c12_st4;
  boolean_T c12_kb_b;
  real_T c12_ub_x;
  real_T c12_vb_x;
  boolean_T c12_lb_b;
  boolean_T c12_mb_b;
  real_T c12_wb_x;
  boolean_T c12_nb_b;
  real_T c12_t3;
  real_T c12_t4;
  real_T c12_xb_x;
  boolean_T c12_ob_b;
  real_T c12_yb_x;
  boolean_T c12_pb_b;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if ((c12_b_x->im == 0.0) && (!(muDoubleScalarAbs(c12_b_x->re) > 1.0))) {
    c12_c_x = *c12_b_x;
    c12_b_x->re = muDoubleScalarAsin(c12_c_x.re);
    c12_b_x->im = 0.0;
  } else {
    c12_v.re = 1.0 + c12_b_x->re;
    c12_v.im = c12_b_x->im;
    c12_e_sqrt(chartInstance, &c12_v);
    c12_u.re = 1.0 - c12_b_x->re;
    c12_u.im = 0.0 - c12_b_x->im;
    c12_e_sqrt(chartInstance, &c12_u);
    c12_ar = c12_u.re;
    c12_ai = c12_u.im;
    c12_br = c12_v.re;
    c12_bi = c12_v.im;
    if ((c12_ai == 0.0) && (c12_bi == 0.0)) {
      c12_tmp = c12_ar * c12_br;
    } else {
      c12_tmp = c12_ar * c12_br - c12_ai * c12_bi;
      c12_d_x = c12_tmp;
      c12_e_x = c12_d_x;
      c12_b = muDoubleScalarIsInf(c12_e_x);
      c12_b52 = !c12_b;
      c12_g_x = c12_d_x;
      c12_b_b = muDoubleScalarIsNaN(c12_g_x);
      c12_b53 = !c12_b_b;
      c12_c_b = (c12_b52 && c12_b53);
      if (!c12_c_b) {
        c12_cr = c12_tmp;
        c12_c_ar = c12_ar;
        c12_c_ai = c12_ai;
        c12_c_br = c12_br;
        c12_c_bi = c12_bi;
        c12_b_cr = c12_cr;
        c12_k_x = c12_c_ar;
        c12_e_b = muDoubleScalarIsNaN(c12_k_x);
        if (c12_e_b) {
        } else {
          c12_m_x = c12_c_ai;
          c12_h_b = muDoubleScalarIsNaN(c12_m_x);
          if (c12_h_b) {
          } else {
            c12_n_x = c12_c_br;
            c12_i_b = muDoubleScalarIsNaN(c12_n_x);
            if (c12_i_b) {
            } else {
              c12_p_x = c12_c_bi;
              c12_j_b = muDoubleScalarIsNaN(c12_p_x);
              if (c12_j_b) {
              } else {
                c12_sar = c12_c_ar;
                c12_sai = c12_c_ai;
                c12_scaleA = c12_b_rescale(chartInstance, &c12_sar, &c12_sai);
                c12_sbr = c12_c_br;
                c12_sbi = c12_c_bi;
                c12_scaleB = c12_b_rescale(chartInstance, &c12_sbr, &c12_sbi);
                c12_x_x = c12_scaleA;
                c12_y_x = c12_x_x;
                c12_q_b = muDoubleScalarIsInf(c12_y_x);
                c12_b58 = !c12_q_b;
                c12_bb_x = c12_x_x;
                c12_s_b = muDoubleScalarIsNaN(c12_bb_x);
                c12_b59 = !c12_s_b;
                c12_t_b = (c12_b58 && c12_b59);
                if (c12_t_b) {
                  c12_eb_x = c12_scaleB;
                  c12_fb_x = c12_eb_x;
                  c12_u_b = muDoubleScalarIsInf(c12_fb_x);
                  c12_b60 = !c12_u_b;
                  c12_jb_x = c12_eb_x;
                  c12_x_b = muDoubleScalarIsNaN(c12_jb_x);
                  c12_b62 = !c12_x_b;
                  c12_ab_b = (c12_b60 && c12_b62);
                  if (c12_ab_b) {
                    c12_finiteScale = true;
                  } else {
                    c12_finiteScale = false;
                  }
                } else {
                  c12_finiteScale = false;
                }

                c12_hb_x = c12_b_cr;
                c12_v_b = muDoubleScalarIsNaN(c12_hb_x);
                guard1 = false;
                guard2 = false;
                if (c12_v_b) {
                  guard2 = true;
                } else {
                  c12_kb_x = c12_b_cr;
                  c12_y_b = muDoubleScalarIsInf(c12_kb_x);
                  if (c12_y_b && c12_finiteScale) {
                    guard2 = true;
                  }
                }

                if (guard2) {
                  c12_st1 = c12_sar * c12_sbr;
                  c12_st2 = c12_sai * c12_sbi;
                  c12_b_cr = c12_st1 - c12_st2;
                  if (c12_b_cr != 0.0) {
                    c12_b_cr = c12_b_cr * c12_scaleA * c12_scaleB;
                  } else {
                    c12_mb_x = c12_scaleA;
                    c12_db_b = muDoubleScalarIsInf(c12_mb_x);
                    if (c12_db_b && ((c12_c_br == 0.0) || (c12_c_bi == 0.0))) {
                      guard1 = true;
                    } else {
                      c12_qb_x = c12_scaleB;
                      c12_gb_b = muDoubleScalarIsInf(c12_qb_x);
                      if (c12_gb_b && ((c12_c_ar == 0.0) || (c12_c_ai == 0.0)))
                      {
                        guard1 = true;
                      }
                    }
                  }
                }

                if (guard1) {
                  c12_t1 = c12_c_ar * c12_c_br;
                  c12_t2 = c12_c_ai * c12_c_bi;
                  c12_tb_x = c12_t1;
                  c12_kb_b = muDoubleScalarIsNaN(c12_tb_x);
                  if (c12_kb_b) {
                    c12_t1 = 0.0;
                  }

                  c12_vb_x = c12_t2;
                  c12_mb_b = muDoubleScalarIsNaN(c12_vb_x);
                  if (c12_mb_b) {
                    c12_t2 = 0.0;
                  }

                  c12_b_cr = c12_t1 - c12_t2;
                }
              }
            }
          }
        }

        c12_tmp = c12_b_cr;
      }
    }

    c12_y = c12_b_x->re;
    c12_f_x = c12_tmp;
    c12_yr = muDoubleScalarAtan2(c12_y, c12_f_x);
    c12_b_ar = c12_u.re;
    c12_b_ai = -c12_u.im;
    c12_b_br = c12_v.re;
    c12_b_bi = c12_v.im;
    if ((c12_b_ai == 0.0) && (c12_b_bi == 0.0)) {
      c12_ci = 0.0;
    } else {
      c12_ci = c12_b_ar * c12_b_bi + c12_b_ai * c12_b_br;
      c12_h_x = c12_ci;
      c12_i_x = c12_h_x;
      c12_d_b = muDoubleScalarIsInf(c12_i_x);
      c12_b54 = !c12_d_b;
      c12_l_x = c12_h_x;
      c12_f_b = muDoubleScalarIsNaN(c12_l_x);
      c12_b55 = !c12_f_b;
      c12_g_b = (c12_b54 && c12_b55);
      if (!c12_g_b) {
        c12_b_ci = c12_ci;
        c12_d_ar = c12_b_ar;
        c12_d_ai = c12_b_ai;
        c12_d_br = c12_b_br;
        c12_d_bi = c12_b_bi;
        c12_c_ci = c12_b_ci;
        c12_q_x = c12_d_ar;
        c12_k_b = muDoubleScalarIsNaN(c12_q_x);
        if (c12_k_b) {
        } else {
          c12_u_x = c12_d_ai;
          c12_m_b = muDoubleScalarIsNaN(c12_u_x);
          if (c12_m_b) {
          } else {
            c12_w_x = c12_d_br;
            c12_o_b = muDoubleScalarIsNaN(c12_w_x);
            if (c12_o_b) {
            } else {
              c12_ab_x = c12_d_bi;
              c12_r_b = muDoubleScalarIsNaN(c12_ab_x);
              if (c12_r_b) {
              } else {
                c12_b_sar = c12_d_ar;
                c12_b_sai = c12_d_ai;
                c12_b_scaleA = c12_b_rescale(chartInstance, &c12_b_sar,
                  &c12_b_sai);
                c12_b_sbr = c12_d_br;
                c12_b_sbi = c12_d_bi;
                c12_b_scaleB = c12_b_rescale(chartInstance, &c12_b_sbr,
                  &c12_b_sbi);
                c12_gb_x = c12_b_scaleA;
                c12_ib_x = c12_gb_x;
                c12_w_b = muDoubleScalarIsInf(c12_ib_x);
                c12_b61 = !c12_w_b;
                c12_lb_x = c12_gb_x;
                c12_bb_b = muDoubleScalarIsNaN(c12_lb_x);
                c12_b63 = !c12_bb_b;
                c12_cb_b = (c12_b61 && c12_b63);
                if (c12_cb_b) {
                  c12_nb_x = c12_b_scaleB;
                  c12_ob_x = c12_nb_x;
                  c12_eb_b = muDoubleScalarIsInf(c12_ob_x);
                  c12_b64 = !c12_eb_b;
                  c12_rb_x = c12_nb_x;
                  c12_hb_b = muDoubleScalarIsNaN(c12_rb_x);
                  c12_b65 = !c12_hb_b;
                  c12_jb_b = (c12_b64 && c12_b65);
                  if (c12_jb_b) {
                    c12_b_finiteScale = true;
                  } else {
                    c12_b_finiteScale = false;
                  }
                } else {
                  c12_b_finiteScale = false;
                }

                c12_pb_x = c12_c_ci;
                c12_fb_b = muDoubleScalarIsNaN(c12_pb_x);
                guard1 = false;
                guard2 = false;
                if (c12_fb_b) {
                  guard2 = true;
                } else {
                  c12_sb_x = c12_c_ci;
                  c12_ib_b = muDoubleScalarIsInf(c12_sb_x);
                  if (c12_ib_b && c12_b_finiteScale) {
                    guard2 = true;
                  }
                }

                if (guard2) {
                  c12_st3 = c12_b_sar * c12_b_sbi;
                  c12_st4 = c12_b_sai * c12_b_sbr;
                  c12_c_ci = c12_st3 + c12_st4;
                  if (c12_c_ci != 0.0) {
                    c12_c_ci = c12_c_ci * c12_b_scaleA * c12_b_scaleB;
                  } else {
                    c12_ub_x = c12_b_scaleA;
                    c12_lb_b = muDoubleScalarIsInf(c12_ub_x);
                    if (c12_lb_b && ((c12_d_br == 0.0) || (c12_d_bi == 0.0))) {
                      guard1 = true;
                    } else {
                      c12_wb_x = c12_b_scaleB;
                      c12_nb_b = muDoubleScalarIsInf(c12_wb_x);
                      if (c12_nb_b && ((c12_d_ar == 0.0) || (c12_d_ai == 0.0)))
                      {
                        guard1 = true;
                      }
                    }
                  }
                }

                if (guard1) {
                  c12_t3 = c12_d_ar * c12_d_bi;
                  c12_t4 = c12_d_ai * c12_d_br;
                  c12_xb_x = c12_t3;
                  c12_ob_b = muDoubleScalarIsNaN(c12_xb_x);
                  if (c12_ob_b) {
                    c12_t3 = 0.0;
                  }

                  c12_yb_x = c12_t4;
                  c12_pb_b = muDoubleScalarIsNaN(c12_yb_x);
                  if (c12_pb_b) {
                    c12_t4 = 0.0;
                  }

                  c12_c_ci = c12_t3 + c12_t4;
                }
              }
            }
          }
        }

        c12_ci = c12_c_ci;
      }
    }

    c12_tmp = c12_ci;
    c12_j_x = c12_tmp;
    c12_yi = c12_j_x;
    c12_xneg = (c12_yi < 0.0);
    if (c12_xneg) {
      c12_yi = -c12_yi;
    }

    if (c12_yi >= 2.68435456E+8) {
      c12_yi = muDoubleScalarLog(c12_yi) + 0.69314718055994529;
    } else if (c12_yi > 2.0) {
      c12_yi = muDoubleScalarLog(2.0 * c12_yi + 1.0 / (muDoubleScalarSqrt(c12_yi
        * c12_yi + 1.0) + c12_yi));
    } else {
      c12_t = c12_yi * c12_yi;
      c12_z = c12_yi + c12_t / (1.0 + muDoubleScalarSqrt(1.0 + c12_t));
      c12_yi = c12_z;
      c12_o_x = c12_yi;
      c12_absz = muDoubleScalarAbs(c12_o_x);
      guard1 = false;
      if (c12_absz > 4.503599627370496E+15) {
        guard1 = true;
      } else {
        c12_r_x = c12_yi;
        c12_s_x = c12_r_x;
        c12_l_b = muDoubleScalarIsInf(c12_s_x);
        c12_b56 = !c12_l_b;
        c12_v_x = c12_r_x;
        c12_n_b = muDoubleScalarIsNaN(c12_v_x);
        c12_b57 = !c12_n_b;
        c12_p_b = (c12_b56 && c12_b57);
        if (!c12_p_b) {
          guard1 = true;
        } else if (c12_absz < 2.2204460492503131E-16) {
        } else {
          c12_b_u = 1.0 + c12_yi;
          c12_cb_x = c12_b_u;
          c12_db_x = c12_cb_x;
          c12_db_x = muDoubleScalarLog(c12_db_x);
          c12_yi = c12_db_x * (c12_yi / (c12_b_u - 1.0));
        }
      }

      if (guard1) {
        c12_t_x = 1.0 + c12_yi;
        c12_yi = c12_t_x;
        c12_yi = muDoubleScalarLog(c12_yi);
      }
    }

    if (c12_xneg) {
      c12_yi = -c12_yi;
    }

    c12_b_x->re = c12_yr;
    c12_b_x->im = c12_yi;
  }
}

static real_T c12_b_rescale(SFc12_anav_realInstanceStruct *chartInstance, real_T
  *c12_re, real_T *c12_im)
{
  real_T c12_b_scale;
  real_T c12_b_x;
  real_T c12_c_x;
  real_T c12_d_x;
  real_T c12_absre;
  real_T c12_e_x;
  real_T c12_f_x;
  real_T c12_g_x;
  real_T c12_absim;
  real_T c12_A;
  real_T c12_B;
  real_T c12_h_x;
  real_T c12_b_A;
  real_T c12_y;
  real_T c12_b_B;
  real_T c12_i_x;
  real_T c12_j_x;
  real_T c12_b_y;
  real_T c12_c_y;
  real_T c12_k_x;
  real_T c12_d_y;
  (void)chartInstance;
  c12_b_x = *c12_re;
  c12_c_x = c12_b_x;
  c12_d_x = c12_c_x;
  c12_absre = muDoubleScalarAbs(c12_d_x);
  c12_e_x = *c12_im;
  c12_f_x = c12_e_x;
  c12_g_x = c12_f_x;
  c12_absim = muDoubleScalarAbs(c12_g_x);
  if (c12_absre > c12_absim) {
    if (*c12_re < 0.0) {
      *c12_re = -1.0;
    } else {
      *c12_re = 1.0;
    }

    c12_b_A = *c12_im;
    c12_b_B = c12_absre;
    c12_j_x = c12_b_A;
    c12_c_y = c12_b_B;
    c12_k_x = c12_j_x;
    c12_d_y = c12_c_y;
    *c12_im = c12_k_x / c12_d_y;
    c12_b_scale = c12_absre;
  } else if (c12_absim > c12_absre) {
    c12_A = *c12_re;
    c12_B = c12_absim;
    c12_h_x = c12_A;
    c12_y = c12_B;
    c12_i_x = c12_h_x;
    c12_b_y = c12_y;
    *c12_re = c12_i_x / c12_b_y;
    if (*c12_im < 0.0) {
      *c12_im = -1.0;
    } else {
      *c12_im = 1.0;
    }

    c12_b_scale = c12_absim;
  } else {
    if (*c12_re < 0.0) {
      *c12_re = -1.0;
    } else {
      *c12_re = 1.0;
    }

    if (*c12_im < 0.0) {
      *c12_im = -1.0;
    } else {
      *c12_im = 1.0;
    }

    c12_b_scale = c12_absre;
  }

  return c12_b_scale;
}

static void c12_d_sin(SFc12_anav_realInstanceStruct *chartInstance,
                      c12_emxArray_creal_T *c12_b_x)
{
  int32_T c12_nx;
  int32_T c12_b;
  int32_T c12_b_b;
  boolean_T c12_overflow;
  int32_T c12_k;
  creal_T c12_c_x;
  creal_T c12_d_x;
  creal_T c12_e_x;
  creal_T c12_f_x;
  creal_T c12_g_x;
  creal_T c12_h_x;
  creal_T c12_i_x;
  int32_T c12_j_x[1];
  c12_nx = c12_b_x->size[0] * c12_b_x->size[1];
  c12_b = c12_nx;
  c12_b_b = c12_b;
  if (1 > c12_b_b) {
    c12_overflow = false;
  } else {
    c12_overflow = (c12_b_b > 2147483646);
  }

  if (c12_overflow) {
    c12_check_forloop_overflow_error(chartInstance, true);
  }

  for (c12_k = 0; c12_k < c12_nx; c12_k++) {
    c12_c_x = c12_b_x->data[c12_k];
    if (c12_c_x.im == 0.0) {
      c12_d_x = c12_c_x;
      c12_c_x.re = muDoubleScalarSin(c12_d_x.re);
      c12_c_x.im = 0.0;
    } else if (c12_c_x.re == 0.0) {
      c12_f_x = c12_c_x;
      c12_c_x.re = 0.0;
      c12_c_x.im = muDoubleScalarSinh(c12_f_x.im);
    } else {
      c12_e_x = c12_c_x;
      c12_g_x = c12_c_x;
      c12_h_x = c12_c_x;
      c12_i_x = c12_c_x;
      c12_c_x.re = muDoubleScalarSin(c12_e_x.re) * muDoubleScalarCosh(c12_g_x.im);
      c12_c_x.im = muDoubleScalarCos(c12_h_x.re) * muDoubleScalarSinh(c12_i_x.im);
    }

    c12_j_x[0] = c12_b_x->size[0] * c12_b_x->size[1];
    c12_b_x->data[c12_k] = c12_c_x;
  }
}

static void c12_f_sqrt(SFc12_anav_realInstanceStruct *chartInstance, real_T
  *c12_b_x)
{
  real_T c12_c_x;
  boolean_T c12_p;
  boolean_T c12_b_p;
  c12_c_x = *c12_b_x;
  if (c12_c_x < 0.0) {
    c12_p = true;
  } else {
    c12_p = false;
  }

  c12_b_p = c12_p;
  if (c12_b_p) {
    c12_b_error(chartInstance);
  }

  *c12_b_x = muDoubleScalarSqrt(*c12_b_x);
}

static void c12_emxInit_creal_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation)
{
  c12_emxArray_creal_T *c12_emxArray;
  int32_T c12_i;
  *c12_pEmxArray = (c12_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c12_emxArray_creal_T));
  if ((void *)*c12_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray = *c12_pEmxArray;
  c12_emxArray->data = (creal_T *)NULL;
  c12_emxArray->numDimensions = c12_numDimensions;
  c12_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c12_numDimensions);
  if ((void *)c12_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray->allocatedSize = 0;
  c12_emxArray->canFreeData = true;
  for (c12_i = 0; c12_i < c12_numDimensions; c12_i++) {
    c12_emxArray->size[c12_i] = 0;
  }
}

static void c12_emxFree_creal_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T **c12_pEmxArray)
{
  if (*c12_pEmxArray != (c12_emxArray_creal_T *)NULL) {
    if (((*c12_pEmxArray)->data != (creal_T *)NULL) && (*c12_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                        ->data);
    }

    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)*c12_pEmxArray);
    *c12_pEmxArray = (c12_emxArray_creal_T *)NULL;
  }
}

static void c12_emxEnsureCapacity_creal_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_creal_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation)
{
  int32_T c12_newNumel;
  int32_T c12_i;
  int32_T c12_newCapacity;
  void *c12_newData;
  if (c12_oldNumel < 0) {
    c12_oldNumel = 0;
  }

  c12_newNumel = 1;
  for (c12_i = 0; c12_i < c12_emxArray->numDimensions; c12_i++) {
    c12_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c12_newNumel, (uint32_T)
      c12_emxArray->size[c12_i], c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  if (c12_newNumel > c12_emxArray->allocatedSize) {
    c12_newCapacity = c12_emxArray->allocatedSize;
    if (c12_newCapacity < 16) {
      c12_newCapacity = 16;
    }

    while (c12_newCapacity < c12_newNumel) {
      if (c12_newCapacity > 1073741823) {
        c12_newCapacity = MAX_int32_T;
      } else {
        c12_newCapacity <<= 1;
      }
    }

    c12_newData = emlrtCallocMex((uint32_T)c12_newCapacity, sizeof(creal_T));
    if (c12_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c12_srcLocation,
        chartInstance->c12_fEmlrtCtx);
    }

    if (c12_emxArray->data != NULL) {
      memcpy(c12_newData, (void *)c12_emxArray->data, sizeof(creal_T)
             * (uint32_T)c12_oldNumel);
      if (c12_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)
                          c12_emxArray->data);
      }
    }

    c12_emxArray->data = (creal_T *)c12_newData;
    c12_emxArray->allocatedSize = c12_newCapacity;
    c12_emxArray->canFreeData = true;
  }
}

static void c12_emxEnsureCapacity_int32_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_int32_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation)
{
  int32_T c12_newNumel;
  int32_T c12_i;
  int32_T c12_newCapacity;
  void *c12_newData;
  if (c12_oldNumel < 0) {
    c12_oldNumel = 0;
  }

  c12_newNumel = 1;
  for (c12_i = 0; c12_i < c12_emxArray->numDimensions; c12_i++) {
    c12_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c12_newNumel, (uint32_T)
      c12_emxArray->size[c12_i], c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  if (c12_newNumel > c12_emxArray->allocatedSize) {
    c12_newCapacity = c12_emxArray->allocatedSize;
    if (c12_newCapacity < 16) {
      c12_newCapacity = 16;
    }

    while (c12_newCapacity < c12_newNumel) {
      if (c12_newCapacity > 1073741823) {
        c12_newCapacity = MAX_int32_T;
      } else {
        c12_newCapacity <<= 1;
      }
    }

    c12_newData = emlrtCallocMex((uint32_T)c12_newCapacity, sizeof(int32_T));
    if (c12_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c12_srcLocation,
        chartInstance->c12_fEmlrtCtx);
    }

    if (c12_emxArray->data != NULL) {
      memcpy(c12_newData, (void *)c12_emxArray->data, sizeof(int32_T)
             * (uint32_T)c12_oldNumel);
      if (c12_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)
                          c12_emxArray->data);
      }
    }

    c12_emxArray->data = (int32_T *)c12_newData;
    c12_emxArray->allocatedSize = c12_newCapacity;
    c12_emxArray->canFreeData = true;
  }
}

static void c12_emxInit_int32_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_int32_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation)
{
  c12_emxArray_int32_T *c12_emxArray;
  int32_T c12_i;
  *c12_pEmxArray = (c12_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c12_emxArray_int32_T));
  if ((void *)*c12_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray = *c12_pEmxArray;
  c12_emxArray->data = (int32_T *)NULL;
  c12_emxArray->numDimensions = c12_numDimensions;
  c12_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c12_numDimensions);
  if ((void *)c12_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray->allocatedSize = 0;
  c12_emxArray->canFreeData = true;
  for (c12_i = 0; c12_i < c12_numDimensions; c12_i++) {
    c12_emxArray->size[c12_i] = 0;
  }
}

static void c12_emxFree_int32_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_int32_T **c12_pEmxArray)
{
  if (*c12_pEmxArray != (c12_emxArray_int32_T *)NULL) {
    if (((*c12_pEmxArray)->data != (int32_T *)NULL) && (*c12_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                        ->data);
    }

    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)*c12_pEmxArray);
    *c12_pEmxArray = (c12_emxArray_int32_T *)NULL;
  }
}

static void c12_emxEnsureCapacity_real_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_real_T *c12_emxArray, int32_T c12_oldNumel, const
  emlrtRTEInfo *c12_srcLocation)
{
  int32_T c12_newNumel;
  int32_T c12_i;
  int32_T c12_newCapacity;
  void *c12_newData;
  if (c12_oldNumel < 0) {
    c12_oldNumel = 0;
  }

  c12_newNumel = 1;
  for (c12_i = 0; c12_i < c12_emxArray->numDimensions; c12_i++) {
    c12_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c12_newNumel, (uint32_T)
      c12_emxArray->size[c12_i], c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  if (c12_newNumel > c12_emxArray->allocatedSize) {
    c12_newCapacity = c12_emxArray->allocatedSize;
    if (c12_newCapacity < 16) {
      c12_newCapacity = 16;
    }

    while (c12_newCapacity < c12_newNumel) {
      if (c12_newCapacity > 1073741823) {
        c12_newCapacity = MAX_int32_T;
      } else {
        c12_newCapacity <<= 1;
      }
    }

    c12_newData = emlrtCallocMex((uint32_T)c12_newCapacity, sizeof(real_T));
    if (c12_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c12_srcLocation,
        chartInstance->c12_fEmlrtCtx);
    }

    if (c12_emxArray->data != NULL) {
      memcpy(c12_newData, (void *)c12_emxArray->data, sizeof(real_T) * (uint32_T)
             c12_oldNumel);
      if (c12_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)
                          c12_emxArray->data);
      }
    }

    c12_emxArray->data = (real_T *)c12_newData;
    c12_emxArray->allocatedSize = c12_newCapacity;
    c12_emxArray->canFreeData = true;
  }
}

static void c12_emxEnsureCapacity_boolean_T(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_boolean_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation)
{
  int32_T c12_newNumel;
  int32_T c12_i;
  int32_T c12_newCapacity;
  void *c12_newData;
  if (c12_oldNumel < 0) {
    c12_oldNumel = 0;
  }

  c12_newNumel = 1;
  for (c12_i = 0; c12_i < c12_emxArray->numDimensions; c12_i++) {
    c12_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c12_newNumel, (uint32_T)
      c12_emxArray->size[c12_i], c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  if (c12_newNumel > c12_emxArray->allocatedSize) {
    c12_newCapacity = c12_emxArray->allocatedSize;
    if (c12_newCapacity < 16) {
      c12_newCapacity = 16;
    }

    while (c12_newCapacity < c12_newNumel) {
      if (c12_newCapacity > 1073741823) {
        c12_newCapacity = MAX_int32_T;
      } else {
        c12_newCapacity <<= 1;
      }
    }

    c12_newData = emlrtCallocMex((uint32_T)c12_newCapacity, sizeof(boolean_T));
    if (c12_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c12_srcLocation,
        chartInstance->c12_fEmlrtCtx);
    }

    if (c12_emxArray->data != NULL) {
      memcpy(c12_newData, (void *)c12_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c12_oldNumel);
      if (c12_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)
                          c12_emxArray->data);
      }
    }

    c12_emxArray->data = (boolean_T *)c12_newData;
    c12_emxArray->allocatedSize = c12_newCapacity;
    c12_emxArray->canFreeData = true;
  }
}

static void c12_emxEnsureCapacity_creal_T1(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_creal_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation)
{
  int32_T c12_newNumel;
  int32_T c12_i;
  int32_T c12_newCapacity;
  void *c12_newData;
  if (c12_oldNumel < 0) {
    c12_oldNumel = 0;
  }

  c12_newNumel = 1;
  for (c12_i = 0; c12_i < c12_emxArray->numDimensions; c12_i++) {
    c12_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c12_newNumel, (uint32_T)
      c12_emxArray->size[c12_i], c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  if (c12_newNumel > c12_emxArray->allocatedSize) {
    c12_newCapacity = c12_emxArray->allocatedSize;
    if (c12_newCapacity < 16) {
      c12_newCapacity = 16;
    }

    while (c12_newCapacity < c12_newNumel) {
      if (c12_newCapacity > 1073741823) {
        c12_newCapacity = MAX_int32_T;
      } else {
        c12_newCapacity <<= 1;
      }
    }

    c12_newData = emlrtCallocMex((uint32_T)c12_newCapacity, sizeof(creal_T));
    if (c12_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c12_srcLocation,
        chartInstance->c12_fEmlrtCtx);
    }

    if (c12_emxArray->data != NULL) {
      memcpy(c12_newData, (void *)c12_emxArray->data, sizeof(creal_T)
             * (uint32_T)c12_oldNumel);
      if (c12_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)
                          c12_emxArray->data);
      }
    }

    c12_emxArray->data = (creal_T *)c12_newData;
    c12_emxArray->allocatedSize = c12_newCapacity;
    c12_emxArray->canFreeData = true;
  }
}

static void c12_emxInit_real_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation)
{
  c12_emxArray_real_T *c12_emxArray;
  int32_T c12_i;
  *c12_pEmxArray = (c12_emxArray_real_T *)emlrtMallocMex(sizeof
    (c12_emxArray_real_T));
  if ((void *)*c12_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray = *c12_pEmxArray;
  c12_emxArray->data = (real_T *)NULL;
  c12_emxArray->numDimensions = c12_numDimensions;
  c12_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c12_numDimensions);
  if ((void *)c12_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray->allocatedSize = 0;
  c12_emxArray->canFreeData = true;
  for (c12_i = 0; c12_i < c12_numDimensions; c12_i++) {
    c12_emxArray->size[c12_i] = 0;
  }
}

static void c12_emxInit_boolean_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_boolean_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation)
{
  c12_emxArray_boolean_T *c12_emxArray;
  int32_T c12_i;
  *c12_pEmxArray = (c12_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c12_emxArray_boolean_T));
  if ((void *)*c12_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray = *c12_pEmxArray;
  c12_emxArray->data = (boolean_T *)NULL;
  c12_emxArray->numDimensions = c12_numDimensions;
  c12_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c12_numDimensions);
  if ((void *)c12_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray->allocatedSize = 0;
  c12_emxArray->canFreeData = true;
  for (c12_i = 0; c12_i < c12_numDimensions; c12_i++) {
    c12_emxArray->size[c12_i] = 0;
  }
}

static void c12_emxInit_creal_T1(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_creal_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation)
{
  c12_emxArray_creal_T *c12_emxArray;
  int32_T c12_i;
  *c12_pEmxArray = (c12_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c12_emxArray_creal_T));
  if ((void *)*c12_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray = *c12_pEmxArray;
  c12_emxArray->data = (creal_T *)NULL;
  c12_emxArray->numDimensions = c12_numDimensions;
  c12_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c12_numDimensions);
  if ((void *)c12_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray->allocatedSize = 0;
  c12_emxArray->canFreeData = true;
  for (c12_i = 0; c12_i < c12_numDimensions; c12_i++) {
    c12_emxArray->size[c12_i] = 0;
  }
}

static void c12_emxFree_real_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T **c12_pEmxArray)
{
  if (*c12_pEmxArray != (c12_emxArray_real_T *)NULL) {
    if (((*c12_pEmxArray)->data != (real_T *)NULL) && (*c12_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                        ->data);
    }

    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)*c12_pEmxArray);
    *c12_pEmxArray = (c12_emxArray_real_T *)NULL;
  }
}

static void c12_emxFree_boolean_T(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_boolean_T **c12_pEmxArray)
{
  if (*c12_pEmxArray != (c12_emxArray_boolean_T *)NULL) {
    if (((*c12_pEmxArray)->data != (boolean_T *)NULL) && (*c12_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                        ->data);
    }

    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)(*c12_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)*c12_pEmxArray);
    *c12_pEmxArray = (c12_emxArray_boolean_T *)NULL;
  }
}

static void c12_emxEnsureCapacity_boolean_T1(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_boolean_T *c12_emxArray, int32_T c12_oldNumel,
  const emlrtRTEInfo *c12_srcLocation)
{
  int32_T c12_newNumel;
  int32_T c12_i;
  int32_T c12_newCapacity;
  void *c12_newData;
  if (c12_oldNumel < 0) {
    c12_oldNumel = 0;
  }

  c12_newNumel = 1;
  for (c12_i = 0; c12_i < c12_emxArray->numDimensions; c12_i++) {
    c12_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c12_newNumel, (uint32_T)
      c12_emxArray->size[c12_i], c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  if (c12_newNumel > c12_emxArray->allocatedSize) {
    c12_newCapacity = c12_emxArray->allocatedSize;
    if (c12_newCapacity < 16) {
      c12_newCapacity = 16;
    }

    while (c12_newCapacity < c12_newNumel) {
      if (c12_newCapacity > 1073741823) {
        c12_newCapacity = MAX_int32_T;
      } else {
        c12_newCapacity <<= 1;
      }
    }

    c12_newData = emlrtCallocMex((uint32_T)c12_newCapacity, sizeof(boolean_T));
    if (c12_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c12_srcLocation,
        chartInstance->c12_fEmlrtCtx);
    }

    if (c12_emxArray->data != NULL) {
      memcpy(c12_newData, (void *)c12_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c12_oldNumel);
      if (c12_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)
                          c12_emxArray->data);
      }
    }

    c12_emxArray->data = (boolean_T *)c12_newData;
    c12_emxArray->allocatedSize = c12_newCapacity;
    c12_emxArray->canFreeData = true;
  }
}

static void c12_emxEnsureCapacity_real_T1(SFc12_anav_realInstanceStruct
  *chartInstance, c12_emxArray_real_T *c12_emxArray, int32_T c12_oldNumel, const
  emlrtRTEInfo *c12_srcLocation)
{
  int32_T c12_newNumel;
  int32_T c12_i;
  int32_T c12_newCapacity;
  void *c12_newData;
  if (c12_oldNumel < 0) {
    c12_oldNumel = 0;
  }

  c12_newNumel = 1;
  for (c12_i = 0; c12_i < c12_emxArray->numDimensions; c12_i++) {
    c12_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c12_newNumel, (uint32_T)
      c12_emxArray->size[c12_i], c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  if (c12_newNumel > c12_emxArray->allocatedSize) {
    c12_newCapacity = c12_emxArray->allocatedSize;
    if (c12_newCapacity < 16) {
      c12_newCapacity = 16;
    }

    while (c12_newCapacity < c12_newNumel) {
      if (c12_newCapacity > 1073741823) {
        c12_newCapacity = MAX_int32_T;
      } else {
        c12_newCapacity <<= 1;
      }
    }

    c12_newData = emlrtCallocMex((uint32_T)c12_newCapacity, sizeof(real_T));
    if (c12_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c12_srcLocation,
        chartInstance->c12_fEmlrtCtx);
    }

    if (c12_emxArray->data != NULL) {
      memcpy(c12_newData, (void *)c12_emxArray->data, sizeof(real_T) * (uint32_T)
             c12_oldNumel);
      if (c12_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c12_fEmlrtCtx, (void *)
                          c12_emxArray->data);
      }
    }

    c12_emxArray->data = (real_T *)c12_newData;
    c12_emxArray->allocatedSize = c12_newCapacity;
    c12_emxArray->canFreeData = true;
  }
}

static void c12_emxInit_real_T1(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_real_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation)
{
  c12_emxArray_real_T *c12_emxArray;
  int32_T c12_i;
  *c12_pEmxArray = (c12_emxArray_real_T *)emlrtMallocMex(sizeof
    (c12_emxArray_real_T));
  if ((void *)*c12_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray = *c12_pEmxArray;
  c12_emxArray->data = (real_T *)NULL;
  c12_emxArray->numDimensions = c12_numDimensions;
  c12_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c12_numDimensions);
  if ((void *)c12_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray->allocatedSize = 0;
  c12_emxArray->canFreeData = true;
  for (c12_i = 0; c12_i < c12_numDimensions; c12_i++) {
    c12_emxArray->size[c12_i] = 0;
  }
}

static void c12_emxInit_boolean_T1(SFc12_anav_realInstanceStruct *chartInstance,
  c12_emxArray_boolean_T **c12_pEmxArray, int32_T c12_numDimensions, const
  emlrtRTEInfo *c12_srcLocation)
{
  c12_emxArray_boolean_T *c12_emxArray;
  int32_T c12_i;
  *c12_pEmxArray = (c12_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c12_emxArray_boolean_T));
  if ((void *)*c12_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray = *c12_pEmxArray;
  c12_emxArray->data = (boolean_T *)NULL;
  c12_emxArray->numDimensions = c12_numDimensions;
  c12_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c12_numDimensions);
  if ((void *)c12_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c12_srcLocation, chartInstance->c12_fEmlrtCtx);
  }

  c12_emxArray->allocatedSize = 0;
  c12_emxArray->canFreeData = true;
  for (c12_i = 0; c12_i < c12_numDimensions; c12_i++) {
    c12_emxArray->size[c12_i] = 0;
  }
}

static int32_T c12_div_nzp_s32(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_numerator, int32_T c12_denominator, uint32_T c12_ssid_src_loc,
  int32_T c12_offset_src_loc, int32_T c12_length_src_loc)
{
  int32_T c12_quotient;
  uint32_T c12_absNumerator;
  uint32_T c12_absDenominator;
  boolean_T c12_quotientNeedsNegation;
  uint32_T c12_tempAbsQuotient;
  (void)chartInstance;
  (void)c12_ssid_src_loc;
  (void)c12_offset_src_loc;
  (void)c12_length_src_loc;
  if (c12_numerator < 0) {
    c12_absNumerator = ~(uint32_T)c12_numerator + 1U;
  } else {
    c12_absNumerator = (uint32_T)c12_numerator;
  }

  if (c12_denominator < 0) {
    c12_absDenominator = ~(uint32_T)c12_denominator + 1U;
  } else {
    c12_absDenominator = (uint32_T)c12_denominator;
  }

  c12_quotientNeedsNegation = ((c12_numerator < 0) != (c12_denominator < 0));
  c12_tempAbsQuotient = c12_absNumerator / c12_absDenominator;
  if (c12_quotientNeedsNegation) {
    c12_quotient = -(int32_T)c12_tempAbsQuotient;
  } else {
    c12_quotient = (int32_T)c12_tempAbsQuotient;
  }

  return c12_quotient;
}

static int32_T c12__s32_add__(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_b, int32_T c12_c, uint32_T c12_ssid_src_loc, int32_T
  c12_offset_src_loc, int32_T c12_length_src_loc)
{
  int32_T c12_a;
  (void)chartInstance;
  c12_a = c12_b + c12_c;
  if (((c12_a ^ c12_b) & (c12_a ^ c12_c)) < 0) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c12_ssid_src_loc, c12_offset_src_loc,
      c12_length_src_loc);
  }

  return c12_a;
}

static int32_T c12__s32_minus__(SFc12_anav_realInstanceStruct *chartInstance,
  int32_T c12_b, int32_T c12_c, uint32_T c12_ssid_src_loc, int32_T
  c12_offset_src_loc, int32_T c12_length_src_loc)
{
  int32_T c12_a;
  (void)chartInstance;
  c12_a = c12_b - c12_c;
  if (((c12_b ^ c12_a) & (c12_b ^ c12_c)) < 0) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c12_ssid_src_loc, c12_offset_src_loc,
      c12_length_src_loc);
  }

  return c12_a;
}

static int32_T c12__s32_s64_(SFc12_anav_realInstanceStruct *chartInstance,
  int64_T c12_b, uint32_T c12_ssid_src_loc, int32_T c12_offset_src_loc, int32_T
  c12_length_src_loc)
{
  int32_T c12_a;
  (void)chartInstance;
  c12_a = (int32_T)c12_b;
  if ((int64_T)c12_a != c12_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c12_ssid_src_loc, c12_offset_src_loc,
      c12_length_src_loc);
  }

  return c12_a;
}

static void init_dsm_address_info(SFc12_anav_realInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc12_anav_realInstanceStruct
  *chartInstance)
{
  chartInstance->c12_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c12_pos = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c12_b_costs = (real_T (*)[9252])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_theta = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_c_detectedList = (real_T (*)[2162])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c12_scale = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c12_goal = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c12_vehicleRad = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c12_limit = (real_T (*)[708])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c12_mode = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c12_c_mapGrid = (real_T (*)[3081])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c12_anav_real_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1786192292U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1089530903U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(364496749U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1910270818U);
}

mxArray* sf_c12_anav_real_get_post_codegen_info(void);
mxArray *sf_c12_anav_real_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jkHb3anJHSjAO99BdbPjUG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1081);
      pr[1] = (double)(2);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(236);
      pr[1] = (double)(3);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(9252);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(39);
      pr[1] = (double)(79);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c12_anav_real_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c12_anav_real_third_party_uses_info(void)
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

mxArray *sf_c12_anav_real_jit_fallback_info(void)
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

mxArray *sf_c12_anav_real_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c12_anav_real_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c12_anav_real(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"costs\",},{M[1],M[12],T\"mapGrid\",},{M[4],M[0],T\"h\",S'l','i','p'{{M1x2[54 55],M[1],T\"/home/hal/Documents/astro/AstroboticsAutonomy2018-2019/simulink/anav_real/inflate2.m\"}}},{M[4],M[0],T\"mapGridP\",S'l','i','p'{{M1x2[352 360],M[0],}}},{M[8],M[0],T\"is_active_c12_anav_real\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_anav_real_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_anav_realInstanceStruct *chartInstance =
      (SFc12_anav_realInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _anav_realMachineNumber_,
           12,
           1,
           1,
           0,
           10,
           0,
           0,
           0,
           0,
           3,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_anav_realMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_anav_realMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _anav_realMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"pos");
          _SFD_SET_DATA_PROPS(1,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(2,1,1,0,"detectedList");
          _SFD_SET_DATA_PROPS(3,1,1,0,"scale");
          _SFD_SET_DATA_PROPS(4,1,1,0,"goal");
          _SFD_SET_DATA_PROPS(5,1,1,0,"vehicleRad");
          _SFD_SET_DATA_PROPS(6,1,1,0,"limit");
          _SFD_SET_DATA_PROPS(7,1,1,0,"mode");
          _SFD_SET_DATA_PROPS(8,2,0,1,"costs");
          _SFD_SET_DATA_PROPS(9,2,0,1,"mapGrid");
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
        _SFD_CV_INIT_EML(0,1,1,0,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2984);
        _SFD_CV_INIT_EML_IF(0,1,0,366,386,-1,446);
        _SFD_CV_INIT_EML_IF(0,1,1,528,540,-1,616);
        _SFD_CV_INIT_EML_IF(0,1,2,699,711,-1,878);
        _SFD_CV_INIT_EML_IF(0,1,3,1042,1054,-1,1235);
        _SFD_CV_INIT_EML_IF(0,1,4,1319,1331,-1,1438);
        _SFD_CV_INIT_EML_IF(0,1,5,1510,1522,-1,1568);
        _SFD_CV_INIT_EML_IF(0,1,6,2246,2264,-1,2330);
        _SFD_CV_INIT_EML_IF(0,1,7,2430,2442,2480,2527);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,531,540,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,702,711,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,1045,1054,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1322,1331,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1513,1522,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,2249,2264,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,2433,2442,-1,0);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"list2grid",0,-1,151);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,98,112,147);
        _SFD_CV_INIT_SCRIPT(1,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"inflate2",0,-1,266);
        _SFD_CV_INIT_SCRIPT_IF(1,0,60,73,-1,155);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,2,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"grid2list",0,-1,268);
        _SFD_CV_INIT_SCRIPT_FOR(2,0,140,155,264);
        _SFD_CV_INIT_SCRIPT_FOR(2,1,163,181,256);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1081U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_k_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 236U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_l_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 9252U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_m_sf_marshallOut,(MexInFcnForType)
            c12_i_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 39U;
          dimVector[1]= 79U;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)
            c12_e_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _anav_realMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_anav_realInstanceStruct *chartInstance =
      (SFc12_anav_realInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c12_pos);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c12_b_costs);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c12_theta);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c12_c_detectedList);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c12_scale);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c12_goal);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c12_vehicleRad);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c12_limit);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c12_mode);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c12_c_mapGrid);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sRlbUepygUv9hztTXzdlTQB";
}

static void sf_opaque_initialize_c12_anav_real(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_anav_realInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c12_anav_real((SFc12_anav_realInstanceStruct*)
    chartInstanceVar);
  initialize_c12_anav_real((SFc12_anav_realInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_anav_real(void *chartInstanceVar)
{
  enable_c12_anav_real((SFc12_anav_realInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_anav_real(void *chartInstanceVar)
{
  disable_c12_anav_real((SFc12_anav_realInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_anav_real(void *chartInstanceVar)
{
  sf_gateway_c12_anav_real((SFc12_anav_realInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c12_anav_real(SimStruct* S)
{
  return get_sim_state_c12_anav_real((SFc12_anav_realInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c12_anav_real(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c12_anav_real((SFc12_anav_realInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c12_anav_real(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_anav_realInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_anav_real_optimization_info();
    }

    finalize_c12_anav_real((SFc12_anav_realInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_anav_real((SFc12_anav_realInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_anav_real(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_anav_real((SFc12_anav_realInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c12_anav_real(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetInputPortDirectFeedThrough(S, 6, 1);
  ssSetInputPortDirectFeedThrough(S, 7, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_anav_real_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,12,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 12);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(103248191U));
  ssSetChecksum1(S,(1335653281U));
  ssSetChecksum2(S,(240023654U));
  ssSetChecksum3(S,(2946065335U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_anav_real(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_anav_real(SimStruct *S)
{
  SFc12_anav_realInstanceStruct *chartInstance;
  chartInstance = (SFc12_anav_realInstanceStruct *)utMalloc(sizeof
    (SFc12_anav_realInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc12_anav_realInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_anav_real;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c12_anav_real;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_anav_real;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_anav_real;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_anav_real;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_anav_real;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_anav_real;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c12_anav_real;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_anav_real;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_anav_real;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_anav_real;
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
  mdl_start_c12_anav_real(chartInstance);
}

void c12_anav_real_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_anav_real(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_anav_real(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_anav_real(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_anav_real_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
