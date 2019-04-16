
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
#include "Dstar.h"

#define AMP 100
#define STEPS 20
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 2

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
void DstarRun_Start_wrapper(void **pW)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */

pW[0] = new Dstar();
pW[1] = malloc(sizeof(list<state>));
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void DstarRun_Outputs_wrapper(const real_T *costs,
			real_T *dspath,
			void **pW,
			const int_T u_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Set up
Dstar *dstar = static_cast<Dstar*>(pW[0]); 
list<state> *path = (list<state> *)pW[1];

// Update
dstar->updateStart(costs[3],costs[4]);
dstar->updateGoal(costs[6],costs[7]);
for (int i = 0; i < costs[0]; i++)
{
    if (costs[i*3+11] > 0)
        dstar->updateCell(costs[i*3+9], costs[i*3+10], AMP*costs[i*3+11]);

} 
dstar->replan();
path = dstar->getPath();

if (path.size() < STEPS)
  path.resize(STEPS, path.back());
else
  path.resize(STEPS);

for (int i = 0; i < STEPS; i++)
{
  dspath[i] = path.front().x;
  dspath[i+STEPS] = path.front().y;
  path.pop_front();
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void DstarRun_Terminate_wrapper(void **pW)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 * free(pW[0]);
 */

Dstar *dstar = static_cast<Dstar*>(pW[0]); 

delete dstar;
free(pW[1]);
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

