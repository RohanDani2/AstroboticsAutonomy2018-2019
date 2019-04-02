function inflated = inflate(points, r, mode)
    % perform object inflation on list of XY coordinates by creating high
    % point-count circles around each point and then rounding the values of
    % said circles. Can use lower point count for real lidar scan to reduce
    % matrix size since it will be compressed anyways 
  
%     points = [30 25; 31 25; 32 25; 33 25];
%     r = 10;
%     mode = 1;
        
    if mode == 1
        n = 500;
    else
        n = 25;
    end
    
    % round points to grid 
    points = round(points);
    
    % generate x, y list representing origin centered circle with radius r
    theta = linspace(0, 2*pi, n);
    x = rot90(r*cos(theta), 3); 
    y = rot90(r*sin(theta), 3);
    circle = horzcat(x, y);
    circle = round(circle);

    % add circle around each point in points
    len = size(points(any(~isnan(points), 2), :), 1);
    inflated = zeros(n*len+len, 2);
    circleTrans = zeros(n, 2);
    for i = 1:len
        circleTrans(:, 1) = circle(:, 1) + points(i, 1);
        circleTrans(:, 2) = circle(:, 2) + points(i, 2);
        inflated(i+n*(i-1), :) = points(i, :);
        inflated(i+n*(i-1)+1:i+n*(i-1)+n, :) = circleTrans;
    end
    inflated = unique(inflated, 'rows');
    
%     plot(inflated(:,1), inflated(:,2), 'bs')
%     xlim([0 60])
%     ylim([0 40])
end