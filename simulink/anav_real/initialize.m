%% Reset workspace, command window, and figures
clear
clc
clf('reset')
 
%% Adjustable Parameters 
visualize = 1; % Indicate if data will be visualized (slows down processing)
object_sensor = 0; % Indicate use of real object data or simulate 
lidar_port = 0; % Indicate .dev/tty--- string of lidar USB port 
pos_sensor = 0; % Indicate use of real position sensor or simulate 
teleop_controller = 0; % Indicate presence of teleop controller 

arena_size = [58 37]; % X and Y measurements of arena in decimeters
d_from_wall = 2; % Distance from arena wall to virtual limit in decimeters
% TODO eliminate above parameter and handle the issue more logically 

%% Set colormap to inverted grayscale 
if visualize == 1
    load('notgray.mat')
    colormap(notgray)
end

%% Generate virtual wall limit obstacle 
limit = generateRectangle(arena_size(1)-d_from_wall,arena_size(2)-d_from_wall);
limit(:,1) = limit(:,1) + d_from_wall/2;
limit(:,2) = limit(:,2) + d_from_wall/2;

%% Generate pure visual objects 
wall = generateRectangle(arena_size(1),arena_size(2));
trough = generateRectangle(15, 5);
visualObjects(:,:,1) = wall;
visualObjects(:,:,2) = vertcat(trough, nan(size(wall,1)-size(trough,1),3));

%% Generate simulated obstacles 
if object_sensor == 0
    % Obstacle min and max loacations in decimeters 
    obstxmin = 15;
    obstxmax = arena_size(1) -obstxmin;
    obstymin = 2;
    obstymax = arena_size(2) - obstymin; 
    % Obstacle sizes, comp has 30 cm ostacles and 30 cm craters
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

    % Concatenate all obstacle into one matrix of x, y, z coordinates
    % Each obstacle is stored on its own "page" indentified with the third
    % dimension of the matrix. Pages with fewer coordinates are filled up to
    % the size of the largest with NaNs
    maxDim = size(limit, 1); 
    simObjects(:,:,1) = limit;
    simObjects(:,:,2) = vertcat(obstacle1, nan(maxDim-size(obstacle1,1),3));
    simObjects(:,:,3) = vertcat(obstacle2, nan(maxDim-size(obstacle2,1),3));
    simObjects(:,:,4) = vertcat(obstacle3, nan(maxDim-size(obstacle3,1),3));
    simObjects(:,:,5) = vertcat(obstacle4, nan(maxDim-size(obstacle4,1),3));
    simObjects(:,:,6) = vertcat(obstacle5, nan(maxDim-size(obstacle5,1),3));
else 
    simObjects = limit;
end
