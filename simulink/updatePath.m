function path = updatePath(occupancyMap, goal, xpos, ypos, botRadius)
    % Current location, start of new path 
    start = [xpos, ypos];
    about occupancyMap
    
    % Create instance of map
    dstar = Dstar(occupancyMap,'inflate', botRadius);

    % Create costmap and print elapsed time 
    tic; dstar.plan(goal); toc

    % Diplay obstacles and cost to goal, store path from start
    path = dstar.query(start);
end
