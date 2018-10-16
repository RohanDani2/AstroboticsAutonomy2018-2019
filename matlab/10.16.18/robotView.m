function robotView(cone, robot, detected) 
    % persistent variables are kept local to the function each time it is
    % called 
    persistent coneFig botFig
    
    % coneFig and botFig are initialized as empty, so we can use that to
    % set up a 'run once' oart of the funciton that only happens the first
    % time it gets called 
    if isempty(coneFig)
        coneFig = plot(cone(:,1), cone(:,2), 'k.-'); % store cone object 
        botFig = plot(robot(:,1), robot(:,2), 'k.-'); % store robot object 
        set([coneFig botFig],'LineWidth', 5) % make the lines thicker 
        hold off % was previously on, now old objects will be removed 
    end
    
    % need to update the color of the cone if an object is detected 
    if detected 
        coneFig.Color = 'red'; % accessing color property of object directly
    else
        coneFig.Color = 'black';
    end
    
    coneFig.XData = cone(:,1); % accessing xdata of object directly 
    coneFig.YData = cone(:,2); % accessing ydata of object directly 
    botFig.XData = robot(:,1); 
    botFig.YData = robot(:,2);
    drawnow % updates the plot without waiting for script to finish 
end