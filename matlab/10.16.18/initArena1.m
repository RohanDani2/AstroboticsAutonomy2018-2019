function [wall, allObstacles] = initArena()
    % Clear plot
    clf('reset')
    
    % Parameters 
    xwall = 5756;
    ywall = 3691;
    distance_from_wall = 300;
    
    % Generate field wall 
    wall = generateRectangle(xwall,ywall);

    % Generate virtual limit 
    limit = generateRectangle(xwall-2*distance_from_wall,ywall-2*distance_from_wall);
    limit(:,1) = limit(:,1) + distance_from_wall;
    limit(:,2) = limit(:,2) + distance_from_wall;
    
    % Generate 3 obstacles at semi-random locations 
    size1 = 300;
    size2 = 400;
    size3 = 500; 
    xobst_init = [0,0,0]; yobst_init = [0,0,0];
    for i = 1:3
        xobst_init(i) = randi([size3,xwall-size3]);
        yobst_init(i) = randi([size3,ywall-size3]);
    end
    obstacle1 = generateRectangle(size1, size1);
    obstacle1(:,1) = obstacle1(:,1) + xobst_init(1);
    obstacle1(:,2) = obstacle1(:,2) + yobst_init(1);

    obstacle2 = generateRectangle(size2, size2);
    obstacle2(:,1) = obstacle2(:,1) + xobst_init(2);
    obstacle2(:,2) = obstacle2(:,2) + yobst_init(2);
    
    obstacle3 = generateRectangle(size3, size3);
    obstacle3(:,1) = obstacle3(:,1) + xobst_init(3);
    obstacle3(:,2) = obstacle3(:,2) + yobst_init(3);
    
    % Concatinate all objects into one matrix of x, y, z coordinates
    allObstacles = vertcat(limit, obstacle1, obstacle2, obstacle3);
end