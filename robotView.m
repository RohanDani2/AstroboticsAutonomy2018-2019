function robotView(cone, robot, light, detected)
    % Visualize data 
    p1 = plot(cone(:,1), cone(:,2), 'r.-');
    p2 = plot(xrobot, yrobot, 'k.-');
    p3 = plot(xlight_v, ylight_v, lightColor);
    set([p1 p2 p3],'LineWidth',5)
    drawnow
end