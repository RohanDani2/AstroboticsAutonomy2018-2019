clear all;

% Run once
allObstacles = initMapSim();

% Continuously check for new command from autonomous system
while 1
    command = randi([0,4]);
    updateMapSim(allObstacles, command);
end


