
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
 * Output function
 *
 */
void DstarRun_Outputs_wrapper(const real_T *costs,
			real_T *dspath,
			const int_T u_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/*
dspath[0] = costs[0];
dspath[10] = 0;
dspath[1] = costs[3];
dspath[11] = costs[4];
dspath[2] = costs[6];
dspath[12] = costs[7];
*/

// Set up
Dstar *dstar;
bool b_autoreplan = false;

list<state> path;
int steps = 20;
int s;

// Use Dstar
dstar = new Dstar();
dstar->init(costs[3],costs[4],costs[6],costs[7]);
for (int i = 0; i < costs[0]; i++)
{
  if (costs[i*3+11] > 0)
    dstar->updateCell(costs[i*3+9], costs[i*3+10], -1);
} 
dstar->replan();
path = dstar->getPath();

s = path.size();

if (s < steps)
  path.resize(steps, path.back());
else
  path.resize(steps);

for (int i = 0; i < steps; i++)
{
  dspath[i] = path.front().x;
  dspath[i+steps] = path.front().y;
  path.pop_front();
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


