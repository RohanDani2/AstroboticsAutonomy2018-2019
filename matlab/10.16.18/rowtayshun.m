function [cone, robot] = rowtayshun (cone, robot, command, position)

tempBot = robot;
tempCone = cone;
if command == 3 % cw
    if position == 1 % "up"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY;
        robot(:,2) = tempX;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY;
        cone(:,2) = tempX;
    elseif position == 2 % "right"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY;
        robot(:,2) = tempX*-1;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY;
        cone(:,2) = tempX*-1;
    elseif position == 3 % "down"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY;
        robot(:,2) = tempX;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY;
        cone(:,2) = tempX;
    elseif position == 4 % "left"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY;
        robot(:,2) = tempX*-1;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY;
        cone(:,2) = tempX*-1;
    end
elseif command == 4 % ccw
    
    if position == 1 % "up"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY*-1;
        robot(:,2) = tempX;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY*-1;
        cone(:,2) = tempX;
    elseif position == 2 % "right"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY;
        robot(:,2) = tempX;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY;
        cone(:,2) = tempX;
    elseif position == 3 % "down"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY*-1;
        robot(:,2) = tempX;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY*-1;
        cone(:,2) = tempX;
    elseif position == 4 % "left"
        tempY = tempBot(:,2);
        tempX = tempBot(:,1);
        robot(:,1) = tempY;
        robot(:,2) = tempX;
        
        tempY = tempCone(:,2);
        tempX = tempCone(:,1);
        cone(:,1) = tempY;
        cone(:,2) = tempX;
    end
end
end 
