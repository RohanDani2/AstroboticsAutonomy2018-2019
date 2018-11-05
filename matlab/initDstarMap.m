function allObstacles = initDstarMap()
    % Parameters 
    xwall = 58;
    ywall = 37;
    distance_from_wall = 1;
    obstymin = 10;
    obstymax = 30;
    size1 = 2;
    size2 = 4;
    size3 = 6; 
    % size4 = 125; % circle sizes
    % size5 = 150; 

    % Generate field wall 
    wall = generateRectangle(xwall,ywall);

    % Generate virtual limit 
    limit = generateRectangle(xwall-distance_from_wall,ywall-distance_from_wall);
    limit(:,1) = limit(:,1) + distance_from_wall;
    limit(:,2) = limit(:,2) + distance_from_wall;

    % Generate random end location 
    endPtx = randi([size3, xwall-size3]);
    endPty = ywall - distance_from_wall - 2*size3;
    endPt = horzcat(endPtx, endPty); 

    % Generate 3 obstacles at semi-random locations and 2 circles (craters) 
    xobst_init = [0,0,0]; yobst_init = [0,0,0];
    for i = 1:3
        xobst_init(i) = randi([size3,xwall-size3]);
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

    % t = linspace(-pi,pi);
    % circle1x = size4*cos(t) + xobst_init(4);
    % circle1y = -size4*sin(t) + yobst_init(4)-100;
    % circle1z = zeros(1,length(t));
    % circle1 = fliplr(rot90(vertcat(circle1x, circle1y, circle1z), 3));
    %  
    % circle2x = size5*cos(t) + xobst_init(5);
    % circle2y = -size5*sin(t) + yobst_init(5)-100;
    % circle2z = zeros(1,length(t));
    % circle2 = fliplr(rot90(vertcat(circle2x, circle2y, circle2z), 3));


    % Concatenate all objects into one matrix of x, y, z coordinates
    allObstacles = vertcat(limit, obstacle1, obstacle2, obstacle3);
end
