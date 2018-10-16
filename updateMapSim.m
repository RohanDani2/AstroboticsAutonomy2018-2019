function updateMapSim(allObstacles, command)
    global xpos ypos
    
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
    
    % Check if obstacle is in vision cone 
    detected = detectObject(allObstacles, cone); 
    if detected 
        lightColor = 'r.-';
    else
        lightColor = 'g.-';
    end

    % Create light to indicate if object is detected 
    xlight = 6000;
    ylight = 4000;
    xlight_v = [xlight, xlight+200, xlight+200, xlight, xlight];
    ylight_v = [ylight, ylight, ylight+200, ylight+200, ylight];
    
    % Visualize data 
    p1 = plot(cone(:,1), cone(:,2), 'r.-');
    p2 = plot(xrobot, yrobot, 'k.-');
    p3 = plot(xlight_v, ylight_v, lightColor);
    set([p1 p2 p3],'LineWidth',5)
    drawnow
end
