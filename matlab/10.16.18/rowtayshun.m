function [cone, robot] = rowtayshun(cone,robot,command,last_command)

tempBot = robot;
tempCone = cone; 
%robot
if (command == 1)  %up  
    robot(:,2) = tempBot(:,2);
end
if (command == 2)  % down
    robot(:,2) = tempBot(:,2)*-1; 
end
if (command == 3)  %left
    tempY = tempBot(:,2);
    tempX = tempBot(:,1);
    robot(:,1) = tempY*-1;
    robot(:,2) = tempX;
end
if command == 4 %right
    tempY = tempBot(:,2);
    tempX = tempBot(:,1);
    robot(:,1) = tempY;
    robot(:,2) = tempX; 
end

%cone
if (command == 1)  %up  
    cone(:,2) = tempCone(:,2);
end
if (command == 2)  % down
    cone(:,2) = tempCone(:,2)*-1; 
end
if (command == 3)  %left
    tempY = tempCone(:,2);
    tempX = tempCone(:,1);
    cone(:,1) = tempY*-1;
    cone(:,2) = tempX;
end
if command == 4 %right
    tempY = tempCone(:,2);
    tempX = tempCone(:,1);
    cone(:,1) = tempY;
    cone(:,2) = tempX; 
end
end


