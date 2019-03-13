
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <stdlib.h>
#include <string.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void sfbuilder_movingAvg_Start_wrapper(real_T *xD,
			void **pW,
			const real_T *windowSize, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Allocate the temporal window, the window will be accessed like a circular
 * queue FIFO structure. discrete state xD[0] is used to store the current
 * index.
 */
    pW[0] = malloc( windowSize[0] * sizeof(real_T) );
    memset( pW[0], '0', windowSize[0] * sizeof(real_T) );
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void sfbuilder_movingAvg_Outputs_wrapper(const real_T *in,
			real_T *avg,
			real_T *std,
			const real_T *xD,
			void **pW,
			const real_T *windowSize, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Output performs:
 *     avg = mean(in(t-windowsize+1), in(t-windowsize+2),, ... in(t));
 *     std = std(in(t-windowsize+1), in(t-windowsize+2), ... in(t));
 *
 * where "avg" represents the (temporal) moving average of the input scalar
 * signal, while "std" represents its standard deviation within the time
 * window.
 */

    int i;
    int idx = (int)xD[0];
    real_T sum = 0.0, sumSquare = 0.0;
    real_T *window = (real_T *)pW[0];
    
    window[idx] = in[0];
    
    /* The following is used solely for simplicity of demonstration, variables
     * "sum" and "sumSquare" can be cached and updated only once per step to
     * reduce the runtime complexity.
     */
    for(i = 0; i < windowSize[0]; i ++) {
        sum += window[i];
        sumSquare += window[i] * window[i];
    }
    
    avg[0] = sum / (real_T)windowSize[0];
    std[0] = sqrt( sumSquare / (real_T)windowSize[0] );
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void sfbuilder_movingAvg_Update_wrapper(const real_T *in,
			real_T *avg,
			real_T *std,
			real_T *xD,
			void **pW,
			const real_T *windowSize, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * The discrete state xD[0] is used to store the index in the circular queue
 * FIFO structure, and is updated every step by circular increment.
 */

    uint64_T idx = (uint64_T)xD[0];
    
    idx = (idx+1) % (uint64_T)windowSize[0];
    xD[0] = (real_T)idx;
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Terminate function
 *
 */
void sfbuilder_movingAvg_Terminate_wrapper(real_T *xD,
			void **pW,
			const real_T *windowSize, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Free the memory allocated in Start.
 */
    free(pW[0]);
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

