% Clear plot
clear
clf('reset')
 
% Parameters 
xwall = 58;
ywall = 37;
distance_from_wall = 2;
obstxmin = 10;
obstxmax = 45;
obstymin = 10;
obstymax = 25; 
size1 = 1; % obstacles 10 - 30 cm diameter 
size2 = 2;
size3 = 3; 
size4 = 5; % craters up to 30 cm diameter and depth
size5 = 5; % circles replaced with interior corners  

% Generate field wall 
wall = generateRectangle(xwall,ywall);

% Generate virtual limit 
limit = generateRectangle(xwall-distance_from_wall,ywall-distance_from_wall);
limit(:,1) = limit(:,1) + distance_from_wall/2;
limit(:,2) = limit(:,2) + distance_from_wall/2;

% Generate random end location 
endPtx = randi([size3, xwall-size3]);
endPty = ywall - distance_from_wall - 2*size3;
endPt = horzcat(endPtx, endPty); 

% Generate 3 obstacles at semi-random locations and 2 crosses (craters)
% init points are bottom left corner for rectangles, center for crosses
xobst_init = [0,0,0]; yobst_init = [0,0,0];
for i = 1:5
    xobst_init(i) = randi([obstxmin,obstxmax]);
    yobst_init(i) = randi([obstymin,obstymax]);
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

obstacle4 = generateCross(size4);
obstacle4(:,1) = obstacle4(:,1) + xobst_init(4);
obstacle4(:,2) = obstacle4(:,2) + yobst_init(4);

obstacle5 = generateCross(size5);
obstacle5(:,1) = obstacle5(:,1) + xobst_init(5);
obstacle5(:,2) = obstacle5(:,2) + yobst_init(5);

% Concatenate all objects into one matrix of x, y, z coordinates
allObstacles = vertcat(limit, obstacle1, obstacle2, obstacle3, obstacle4, obstacle5);
