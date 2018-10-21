function [cone, robot, detected] = positionThenDetect(allObstacles, command)
    persistent xpos ypos position base_cone base_robot
    
    
    if isempty(xpos)
        xpos = 2000;
        ypos = 2000;
        position = 1;
        % Base vision cone 
        line1 = [0,150,0; 300,450,0;];
        line2 = [0,150,0; -300,450,0;];
        line3 = [-300,450,0; 300,450,0;];
        base_cone = vertcat(line1, line2, line3);

        % Base robot     
        robot_line1 = [0,150,0; 100, 50,0;];
        robot_line2 = [100, 50, 0; 100, -150, 0;];
        robot_line3 = [100, -150, 0; -100, -150, 0;];
        robot_line4 = [-100,-150,0; -100, 50, 0;];
        robot_line5 = [-100, 50, 0; 0, 150, 0;];
        base_robot = vertcat(robot_line1, robot_line2, robot_line3, robot_line4, robot_line5);

    end
    if command ~= 0 
        % Translate base cone and base robot based on x and y positionif command == 1
        % rotate it
        if command == 1 % forwards
            if position == 1 % "up"
                ypos = ypos + 50;
            elseif position == 2 % "right"
                xpos = xpos + 50;
            elseif position == 3 % "down"
                ypos = ypos -50;
            elseif position == 4 % "left"
                xpos = xpos - 50;
            end
        elseif command == 2 % backwards
            if position == 1 % "up"
                ypos = ypos - 50;
            elseif position == 2 % "right"
                xpos = xpos - 50;
            elseif position == 3 % "down"
                ypos = ypos + 50; 
            elseif position == 4 % "left"
                xpos = xpos + 50;
            end
        elseif command == 3 % cw
            [base_cone2, base_robot2] = rowtayshun (base_cone, base_robot, 3, position);
            position = position+1;
            if position == 0
                position = 4;
            end
            if position == 5
                position = 1;
            end
            base_cone = base_cone2;
            base_robot = base_robot2;
        elseif command == 4 % cc
            [base_cone2, base_robot2] = rowtayshun (base_cone, base_robot, 4, position);
            position = position-1; 
            if position == 0
                position = 4;
            end
            if position == 5
                position = 1;
            end
            base_cone = base_cone2;
            base_robot = base_robot2;
        end
    end

    cone = base_cone;
    cone(:,1) = base_cone(:,1) + xpos;
    cone(:,2) = base_cone(:,2) + ypos;
    cone(:,3) = base_cone(:,3);

    robot = base_robot;
    robot(:,1) = base_robot(:,1) + xpos;
    robot(:,2) = base_robot(:,2) + ypos;
    robot(:,3) = base_robot(:,3);

    % Check if obstacle is in vision cone 
    detected = detectObject(allObstacles, cone); 
    
end
