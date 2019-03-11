% Load most recent version of obstacle map 
% Convert x,y table to occupancy map of predetermined dimensions
xmax = 57; ymax = 36;
botRadius = 0; % x10 cm

map = initDstarMap();
map = accumarray([map(:,2),map(:,1)],1,[ymax xmax]);
clc; about map

% Define the goal and start coordinates
goal = [randi([botRadius+2,xmax-botRadius-1]),ymax-botRadius-1];
start = [randi([botRadius+2,xmax-botRadius-1]),botRadius+2];

% Create instance of map
dstar = Dstar(map,'inflate', botRadius);

% Create costmap and print elapsed time 
tic; dstar.plan(goal); toc

% Diplay obstacles and cost to goal, find path from start
path = dstar.query(start, 'animate');
about path
