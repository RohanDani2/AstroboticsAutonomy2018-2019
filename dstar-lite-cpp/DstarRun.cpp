#include "Dstar.h"
/*
#include <stdlib.h>
#include <unistd.h>
*/

Dstar *dstar;
bool b_autoreplan = false;

int main()
{
  list<state> path;
  bool e;
  int s;
  int steps = 10;
  int x[steps];
  int y[steps];

  double obst[10];
  int obstLen = sizeof(obst)/sizeof(double);
  for (int i = 0; i < obstLen/2; i++)
  {
    obst[i] = 5;
    obst[i+obstLen/2] = i+3;
  }

  dstar = new Dstar();
  dstar->init(1,5,10,5);
  for (int i = 0; i < obstLen/2; i++)
  {
    dstar->updateCell(obst[i], obst[i+obstLen/2], -1);
  }
  dstar->replan();
  path = dstar->getPath();

  e = path.empty();
  s = path.size();

  if (s < steps)
    path.resize(steps, path.back());
  else
    path.resize(steps);

  for (int i = 0; i < steps; i++)
  {
    x[i] = path.front().x;
    y[i] = path.front().y;
    path.pop_front();
  }

  printf("--------------------\n");
  printf("Obst Len: %d\nPath Length: %d\n",obstLen,s);
  printf("--------------------\n");
  printf("#  X   Y\n");
  for (int i = 0; i < steps; i++)
    printf("%d. %d  %d\n",i+1,x[i],y[i]);

  return 1;
}
