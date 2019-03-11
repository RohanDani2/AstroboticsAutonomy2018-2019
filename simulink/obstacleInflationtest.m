occupancyGridTest1 = [0,0,0,0,0,0,0,0; 0,0,0,1,1,0,0,0; 
    0,0,0,1,1,0,0,0; 0,0,0,1,1,0,0,0; 0,0,0,0,0,0,0,0]; %%occupancy grid testing
botRadiusTest1 = 0.5;
newOccupancyGrid = obstacleInflation(occupancyGridTest1,botRadiusTest1);
botRadiusTest2 = 1.75;
occupancyGridTest2 = [0,0,0,0,0,0,0,0; 0,0,0,1,1,0,0,0; 
    0,0,0,1,0,0,0,0; 0,0,0,1,0,0,0,0; 0,0,0,0,0,0,0,0]; 
newOccupancyGrid2 = obstacleInflation(occupancyGridTest2,botRadiusTest1);