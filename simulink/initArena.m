% Clear plot
clear
clf('reset')
 
% Parameters 
xwall = 58;
ywall = 37;
distance_from_wall = 2;
obstxmin = 15;
obstxmax = 58-15;
obstymin = 2;
obstymax = 35; 
size1 = 1; % obstacles 10 - 30 cm diameter 
size2 = 2;
size3 = 3; 
size4 = 5; % craters up to 30 cm diameter and depth
size5 = 5; % circles replaced with interior corners  

% Generate random end location 
endPtx = xwall - distance_from_wall - size3; 
endPty = randi([6, ywall-6]);
endPt = horzcat(endPtx, endPty); 

% Create wall and trough visual objects
wall = generateRectangle(xwall,ywall);
trough = generateRectangle(15, 5);
visualObjects(:,:,1) = wall;
visualObjects(:,:,2) = vertcat(trough, nan(size(wall,1)-size(trough,1),3));

% Generate virtual wall limit obstacle  
limit = generateRectangle(xwall-distance_from_wall,ywall-distance_from_wall);
limit(:,1) = limit(:,1) + distance_from_wall/2;
limit(:,2) = limit(:,2) + distance_from_wall/2;

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

% Concatenate all obstacle into one matrix of x, y, z coordinates
% Each obstacle is stored on its own "page" indentified with the third
% dimension of the matrix. Pages with fewer coordinates are filled up to
% the size of the largest with NaNs

maxDim = size(limit, 1); 
allObstacles(:,:,1) = limit;
allObstacles(:,:,2) = vertcat(obstacle1, nan(maxDim-size(obstacle1,1),3));
allObstacles(:,:,3) = vertcat(obstacle2, nan(maxDim-size(obstacle2,1),3));
allObstacles(:,:,4) = vertcat(obstacle3, nan(maxDim-size(obstacle3,1),3));
allObstacles(:,:,5) = vertcat(obstacle4, nan(maxDim-size(obstacle4,1),3));
allObstacles(:,:,6) = vertcat(obstacle5, nan(maxDim-size(obstacle5,1),3));

% Define strategy as list of coordinate goals 
strategy(1,:) = [50 30];
strategy(2,:) = [6 15];
strategy(3,:) = [6 7];
strategy(4,:) = [6 15];
strategy(5,:) = [50 25];
strategy(6,:) = [6 15];
strategy(7,:) = [6 7];
strategy(8,:) = [6 15];
strategy(9,:) = [50 20];
strategy(10,:) = [6 15];
strategy(11,:) = [6 7];
strategy(12,:) = [6 15];



