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
    robot_line1 = [0,150,0; 100, 50,0;];
    robot_line2 = [100, 50, 0; 100, -150, 0;];
    robot_line3 = [100, -150, 0; -100, -150, 0;];
    robot_line4 = [-100,-150,0; -100, 50, 0;];
    robot_line5 = [-100, 50, 0; 0, 150, 0;];
    base_robot = vertcat(robot_line1, robot_line2, robot_line3, robot_line4, robot_line5);
    
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
    % for rotation: come up with a set roation dependent on var and
    %  then make other rotation negative
    % for facing opposite direction: turn 180
    % could do eight cases 
    [base_cone2, base_robot2] = rowtayshun(base_cone,base_robot,command);
    cone = base_cone2;
    cone(:,1) = base_cone2(:,1) + xpos;
    cone(:,2) = base_cone2(:,2) + ypos;
    cone(:,3) = base_cone2(:,3);
   
   
    robot = base_robot2;
    
    robot(:,1) = base_robot2(:,1) + xpos;
    robot(:,2) = base_robot2(:,2) + ypos;
    robot(:,3) = base_robot2(:,3);
    
    % should concat robot beforehand, like with cone
   % robot = fliplr(rot90(robot,3));
    
    %put rotation here--make function in different file

    % Check if obstacle is in vision cone 
    detected = detectObject(allObstacles, cone); 
    
    
end
