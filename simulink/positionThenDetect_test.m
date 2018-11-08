xmax = 57; % Physical wall just outside these distances 
ymax = 36; 

%%%% duplicate replace with persistents and function def from non-test block
initArena
xmax = 57; % Physical wall just outside these distances 
ymax = 36; 
global occupancyMap
if isempty(occupancyMap)
    occupancyMap = zeros(ymax, xmax);
end
command = 0;
xpos = 25;
ypos = 2;
theta = pi/2;
xmax = 57; % Physical wall just outside these distances 
ymax = 36;
goal = [10 10];
%%%%

if isempty(xpos)
    xpos = 25;
    ypos = 2;
    theta = pi/2;
end

% Robot specifications 
botRadius = 1.5; % Used for graphic circle and Dstar inflation 
coneDepth = 3;
speed = 1;
turnSpeed = pi/128;

% Radius of robot vision and representing circles 
r = sqrt(botRadius^2+(2*coneDepth^2)-2*botRadius*sqrt(2*coneDepth^2)*cos(135*pi/180));
t = linspace(-pi,pi);
xc = [r*cos(t); botRadius*cos(t)];
yc = [-r*sin(t); -botRadius*sin(t)];

% Update position and rotation based on command 
if command == 1 % forward
    xpos = xpos + speed*cos(theta);
    ypos = ypos + speed*sin(theta);
elseif command == 2 % back
    xpos = xpos - speed*cos(theta);
    ypos = ypos - speed*sin(theta);
elseif command == 3 % counter clockwise
    theta = theta + turnSpeed;
elseif command == 4 % clockwise 
    theta = theta - turnSpeed;
end

% Calculate rotated cone around origin 
thigh = theta + asin(coneDepth/r);
tlow = thigh-2*asin(coneDepth/r);
x = [botRadius*cos(theta) r*cos(thigh) r*cos(tlow) botRadius*cos(theta)];
y = [botRadius*sin(theta) r*sin(thigh) r*sin(tlow) botRadius*sin(theta)];
z = zeros(1,4);
rotated_cone = fliplr(rot90(vertcat(x,y,z),3));

% Translate cone to new position 
cone = rotated_cone;
cone(:,1) = rotated_cone(:,1) + xpos;
cone(:,2) = rotated_cone(:,2) + ypos;
cone(:,3) = rotated_cone(:,3);

% Translate circle to new position 
circInner = zeros(2, length(t));
circInner(1,:) = xc(2,:) + xpos;
circInner(2,:) = yc(2,:) + ypos;

% Check if obstacle is in vision cone 
detected = detectRotated(allObstacles, cone);

% Update stored values of discovered objects  
allObstX = allObstacles(:,1);
allObstY = allObstacles(:,2);

% Create a list of obstacles that are detected 
if (detected ~= 0)
    x = allObstX(detected==1);
    y = allObstY(detected==1);
    
    % Convert list of x,y coordinates to occupany map 
    occupancyMapNew = accumarray([y,x],1,[ymax xmax])
    occupancyMap = occupancyMap | occupancyMapNew
end

% Get new path based on last map update 
path = updatePath(occupancyMap, goal, xpos, ypos, 0);
plot(path(:,1),path(:,2))

% Indicate if any obstacles are detected 
any_detected = double(any(detected(:)));

% Calculate intantaneous angle/dist between current and ideal orientation 
angle = degFromPath(endPt, xpos, ypos, theta); 
[dist, xdif, ydif] = distFromPath(endPt, xpos, ypos);
