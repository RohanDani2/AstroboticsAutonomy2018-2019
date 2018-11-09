function p = updatePath(occupancyMap, goal, xpos, ypos, botRadius)
    steps = 5;
    p = 10*ones(5,2);

    % Current location, start of new path 
    start = [xpos, ypos];
    
%     % Create instance of map
%     dstar = Dstar(occupancyMap,'inflate', botRadius);
% 
%     % Create costmap and print elapsed time 
%     dstar.plan(goal);
% 
%     % Diplay obstacles and cost to goal, store path from start
%     p = dstar.query(start);
%     l = size(p,1);
%     if l < steps
%         for i = 1:steps-length(p)
%             p(l+1:steps,1) = p(l,1);
%             p(l+1:steps,2) = p(l,2);
%         end
%     else
%        p = p(1:steps,:);
%     end 
end
