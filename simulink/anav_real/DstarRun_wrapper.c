
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
// Set up
Dstar *dstar;
bool b_autoreplan = false;

list<state> path;
double l; 
int steps = 10;
int s;

dspath[0] = costs[0];
dspath[10] = 0;
dspath[1] = costs[3];
dspath[11] = costs[4];
dspath[2] = costs[6];
dspath[12] = costs[7];
// Use Dstar
/*
dstar = new Dstar();
dstar->init(start[0],start[1],goal[0],goal[1]);
for (int i = 0; i < l; i++)
{
  dstar->updateCell(obst[i], obst[i+l], -1);
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


