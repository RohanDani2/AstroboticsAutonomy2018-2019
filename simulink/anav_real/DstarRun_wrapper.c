
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
#define u_width 1
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
void DstarRun_Outputs_wrapper(const real_T *goal,
			const real_T *start,
			const real_T *obst,
			real_T *short_path)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Set up
Dstar *dstar;
bool b_autoreplan = false;

list<state> path;
int l = 2052;
int steps = 10;
int s;

// Use Dstar
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
  short_path[i] = path.front().x;
  short_path[i+steps] = path.front().y;
  path.pop_front();
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


