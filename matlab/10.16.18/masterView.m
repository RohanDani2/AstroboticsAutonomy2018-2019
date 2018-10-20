function masterView(wall, allObstacles)
    % Visualize data 
    % hold on
    grid on
    grid minor
    xlim([-800 6600])
    ylim([-700 4400])
    plot(wall(:,1), wall(:,2), 'ks-');
    hold on 
    plot(allObstacles(:,1), allObstacles(:,2), 'bs');
    drawnow
end