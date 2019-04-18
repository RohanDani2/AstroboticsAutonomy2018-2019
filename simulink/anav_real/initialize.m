%% Reset workspace, command window, and figures 
clear
clc
clf
tic
%% Config
mode = 0; % 1 for sim or 0 for real with all sensors 
mapDim = [80 40]; % X and Y measurements of arena in whole decimeters

%% Set colormap to inverted blue scale and generate surface point vectors also set scale  
load('notbone.mat')
colormap(notbone)

verticiesX = repmat((0:mapDim(1)-1) + 0.5, mapDim(2), 1);
verticiesY = repmat(rot90((0:mapDim(2)-1) + 0.5, 3), 1, mapDim(1));
verticies = cat(3, verticiesX, verticiesY);

if mode
    scale = 1;
else
    scale = 100;
end

%% Generate virtual wall limit obstacle 
limit = generateRectangle(mapDim(1)-2,mapDim(2)-2);
limit(:,1) = limit(:,1) + 1;
limit(:,2) = limit(:,2) + 1;
    
%% Generate static pure visual objects 
wall = generateRectangle(mapDim(1),mapDim(2));
trough = generateRectangle(15, 5);
visualObj(:,:,1) = wall;
visualObj(:,:,2) = vertcat(trough, zeros(size(wall,1)-size(trough,1),3));

%% Generate simulated obstacles and combine with limit   

if mode == 1
    % Obstacle min and max loacations in decimeters 
    obstxmin = 15;
    obstxmax = mapDim(1) - obstxmin;
    obstymin = 5;
    obstymax = mapDim(2) - obstymin; 
    % Obstacle sizes, competition has 30 cm ostacles and 30 cm craters
    size1 = 1; 
    size2 = 2;
    size3 = 3; 
    size4 = 5; 
    size5 = 5; 

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

    % Concatenate all obstacles into one matrix of x, y, z coordinates
    % Each obstacle is stored on its own "page" indentified with the third
    % dimension of the matrix. Pages with fewer coordinates are filled up to
    % the size of the largest with NaNs
    % TODO: Error if obstacle3 has fewer points than another sObs
    maxDim = size(obstacle3, 1); 
    sObs(:,:,1) = vertcat(obstacle1, nan(maxDim-size(obstacle1,1),3));
    sObs(:,:,2) = vertcat(obstacle2, nan(maxDim-size(obstacle2,1),3));
    sObs(:,:,3) = vertcat(obstacle3, nan(maxDim-size(obstacle3,1),3));
    sObs(:,:,4) = vertcat(obstacle4, nan(maxDim-size(obstacle4,1),3));
    sObs(:,:,5) = vertcat(obstacle5, nan(maxDim-size(obstacle5,1),3));
else
    sObs = zeros(2, 3);
end
