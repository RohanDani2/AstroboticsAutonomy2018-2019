clear all;

% Run once
[wall, allObstacles] = initArena();
masterView(wall, allObstacles);

% Run forever 
while 1
    command = randi([0,4]);
    [cone, robot, detected] = positionThenDetect(allObstacles, command);
    
    robotView(cone, robot, detected);
end





