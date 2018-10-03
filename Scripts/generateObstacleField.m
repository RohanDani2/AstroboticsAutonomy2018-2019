% Goal for next week is to move robot around obstacle field forever without
% collision and vison cone shown 

% Clear workspace and reinitialize random number generator 
clear;
clf('reset')
rng('shuffle') 

% User defined variables
% Optional manual control 
% Add obstacle size 
xmax = 180;
ymax = 120;
obstacle_count = 100;

% Generate field wall
xwall = 0:xmax;
ywall = 0:ymax;
xmax_vector = xmax*ones(1, ymax+1);
ymax_vector = ymax*ones(1, xmax+1);

% Generate x, y coordiantes of each obstacle 
xcoord = 1:obstacle_count;
ycoord = 1:obstacle_count;
for i = 1:obstacle_count
    xcoord(i) = randi([0,xmax]);
    ycoord(i) = randi([0,ymax]);
end

% Visualize data 
% Increase wall thickness 
hold on
grid on
grid minor
S = 'c+-';
plot(xwall, zeros(1, xmax+1), S);
plot(xwall, ymax_vector, S);
plot(zeros(1, ymax+1), ywall, S);
plot(xmax_vector, ywall, S);
plot(xcoord, ycoord, 'ks')
hold off

% Add virtual boarder for operation area, reject all data outside (can't detect
% wall) based on known positions 

% Generate random start and finish location  

% Find ideal path withought obstacles 

% Place robot on start location with orientation ^, v, <, > 

% Manual control 

% Auto-pilot without prior knowledge of obstacles or learning

% Collect data from test 

% Alert when finished or stuck 


