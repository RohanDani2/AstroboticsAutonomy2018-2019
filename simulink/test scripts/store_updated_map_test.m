global occupancyMap
xmax = 10; % Physical wall just outside these distances 
ymax = 10; 
obstList = zeros(ymax*xmax,2);

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

 for r = 1:ymax
    for c = 1:xmax
        if occupancyMap(r,c) == 1
            obstList(r*c,:) = [r c];
        elseif occupancyMap(r,c) == 0
            obstList(r*c,:) = [0 0];
        end
    end
 end
obstList;