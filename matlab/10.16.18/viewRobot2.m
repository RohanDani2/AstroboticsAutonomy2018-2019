function viewRobot2(cone, robot, detected) 
    if detected
        coneColor = 'r.-';
    else
        coneColor = 'k.-';
    end
    coneFig = plot(cone(:,1), cone(:,2), coneColor); 
    botFig = plot(robot(:,1), robot(:,2), 'k.-');
    set([coneFig botFig],'LineWidth', 5)
    hold off
end