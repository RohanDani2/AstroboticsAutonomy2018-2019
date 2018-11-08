global occupancyMap
xmax = 10; % Physical wall just outside these distances 
ymax = 10; 

fov = zeros([10 2]);
fov_record = zeros([xmax*ymax 2]);
n = 20;
if isempty(occupancyMap)
    occupancyMap = 0;
end
detected = randi([0 1], 1, n);
allObstX = randi([1 xmax], n, 1);
allObstY = randi([1 ymax], n, 1);

% fov(:,1) = allObstX(detected==1); 
% fov(:,2) = allObstY(detected==1);
% fov_record(:,1) = fov_record(:,1) | fov(:,1);
% fov_record(:,2) = fov_record(:,2) | fov(:,2);

a = allObstX(detected==1);
b = allObstY(detected==1);

occupancyMapNew = accumarray([b,a],1,[ymax xmax]);
occupancyMap = occupancyMap | occupancyMapNew