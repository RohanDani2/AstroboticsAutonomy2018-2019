/* Copyright 2003-2014 The MathWorks, Inc. */

// *******************************************************************
// **** To build this mex function use: mex sfun_cppcount_cpp.cpp ****
// *******************************************************************

#include "sfun_DstarRun_cpp.h"

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME  sfun_DstarRun_cpp

// Need to include simstruc.h for the definition of the SimStruct and
// its associated macro definitions.
#include "simstruc.h"

#define IS_PARAM_DOUBLE(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsDouble(pVal))

// Function: mdlInitializeSizes ===============================================
// Abstract:
//    The sizes information is used by Simulink to determine the S-function
//    block's characteristics (number of inputs, outputs, states, etc.).
static void mdlInitializeSizes(SimStruct *S)
{
    // No expected parameters
    ssSetNumSFcnParams(S, 0);

    // Parameter mismatch will be reported by Simulink
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }

    ssSetNumContStates(    S, 0);
    ssSetNumDiscStates(    S, 0);

    // Specify I/O
    if (!ssSetNumInputPorts(S, 4)) return;
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortWidth(S, 1, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortWidth(S, 2, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortWidth(S, 3, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, 3, 1);
    if (!ssSetNumOutputPorts(S,2)) return;
    ssSetOutputPortWidth(S, 0, 10);
    ssSetOutputPortWidth(S, 1, 10);

    ssSetNumSampleTimes(S, 1);

    // Reserve place for C++ object
    ssSetNumPWork(S, 0);

    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetNumRWork(S, 0);   /* real vector    */
    ssSetNumIWork(S, 0);   /* integer vector */
    ssSetNumPWork(S, 0);   /* pointer vector */
    ssSetNumModes(S, 0);   /* mode vector    */
    ssSetNumNonsampledZCs(S, 0);   /* zero crossings */

    ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE |
                  SS_OPTION_PLACE_ASAP |
                  SS_OPTION_ALLOW_INPUT_SCALAR_EXPANSION |
                  SS_OPTION_REQ_INPUT_SAMPLE_TIME_MATCH |
                  SS_OPTION_WORKS_WITH_CODE_REUSE |
                  SS_OPTION_ALLOW_CONSTANT_PORT_SAMPLE_TIME);
}

// Function: mdlInitializeSampleTimes =========================================
// Abstract:
//   This function is used to specify the sample time(s) for your
//   S-function. You must register the same number of sample times as
//   specified in ssSetNumSampleTimes.
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
}

// Function: mdlStart =======================================================
// Abstract:
//   This function is called once at start of model execution. If you
//   have states that should be initialized once, this is the place
//   to do it.
#define MDL_START
static void mdlStart(SimStruct *S)
{
    // Store new C++ object in the pointers vector
}

// Function: mdlOutputs =======================================================
// Abstract:
//   In this function, you compute the outputs of your S-function
//   block.
static void mdlOutputs(SimStruct *S, int_T tid)
{
    // Set up
    Dstar *dstar;
    bool b_autoreplan = false;

    list<state> path;
    int_T steps = 10;
    int_T s;
    int_T i;
    double px[steps];
    double py[steps];

    // Get data addresses of I/O
    InputRealPtrsType  u0 = ssGetInputPortRealSignalPtrs(S,0);
    InputRealPtrsType  u1 = ssGetInputPortRealSignalPtrs(S,1);
    InputRealPtrsType  u2 = ssGetInputPortRealSignalPtrs(S,2);
    InputRealPtrsType  u3 = ssGetInputPortRealSignalPtrs(S,3);

    real_T *y0 = ssGetOutputPortRealSignal(S, 0);
    real_T *y1 = ssGetOutputPortRealSignal(S, 1);

    // Use Dstar
    dstar = new Dstar();
    dstar->init(*u0[0],*u1[0],*u2[0],*u3[0]);
    dstar->replan();
    path = dstar->getPath();

    s = path.size();

    if (s < steps)
      path.resize(steps, path.back());
    else
      path.resize(steps);

    for (int i = 0; i < steps; i++)
    {
      px[i] = path.front().x;
      py[i] = path.front().y;
      path.pop_front();

      // Set outputs to S-Block
      y0[i] = px[i];
      y1[i] = py[i];
    }
}

#ifdef MATLAB_MEX_FILE
/* Define to indicate that this S-Function has the mdlG[S]etSimState methods */
#define MDL_SIM_STATE

/* Function: mdlGetSimState =====================================================
 * Abstract:
 *
 */
static mxArray* mdlGetSimState(SimStruct* S)
{
    // Retrieve C++ object from the pointers vector
}
/* Function: mdlGetSimState =====================================================
 * Abstract:
 *
 */
static void mdlSetSimState(SimStruct* S, const mxArray* ma)
{
    // Retrieve C++ object from the pointers vector
}
#endif // MATLAB_MEX_FILE

// Function: mdlTerminate =====================================================
// Abstract:
//   In this function, you should perform any actions that are necessary
//   at the termination of a simulation.  For example, if memory was
//   allocated in mdlStart, this is the place to free it.
static void mdlTerminate(SimStruct *S)
{
    // Retrieve and destroy C++ object
}


// Required S-function trailer
#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
