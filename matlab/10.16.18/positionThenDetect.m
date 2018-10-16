function [cone, robot, detected] = positionThenDetect(allObstacles, command)
    persistent xpos ypos
    if isempty(xpos)
        xpos = 2000;
        ypos = 2000;
    end
    
    % Base vision cone 
    line1 = [0,150,0; 300,450,0;];
    line2 = [0,150,0; -300,450,0;];
    line3 = [-300,450,0; 300,450,0;];
    base_cone = vertcat(line1, line2, line3);
    
    % Base robot 
    xbase_robot = [0, -100, -100, +100, 100, 0];
    ybase_robot = [150, 50, -150, -150, 50, 150];
    
    % Translate base cone and base robot based on x and y position
    if command == 1
        ypos = ypos + 500;
    elseif command == 2
        ypos = ypos - 500;
    elseif command == 3
        xpos = xpos - 500;
    elseif command == 4
        xpos = xpos + 500;
    end

    cone = base_cone;
    cone(:,1) = base_cone(:,1) + xpos;
    cone(:,2) = base_cone(:,2) + ypos;
    cone(:,3) = base_cone(:,3);

    xrobot = xbase_robot + xpos;
    yrobot = ybase_robot + ypos;
    robot = fliplr(rot90(vertcat(xrobot,yrobot),3));

    % Check if obstacle is in vision cone 
    detected = detectObject(allObstacles, cone); 
end
