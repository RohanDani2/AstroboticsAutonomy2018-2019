global occupancyMap
xmax = 5; % Physical wall just outside these distances 
ymax = 5; 
obstList = zeros(ymax*xmax,2);

fov = zeros([10 2]);
fov_record = zeros([xmax*ymax 2]);
n = 20;
if isempty(occupancyMap)
    occupancyMap = logical(zeros(ymax, xmax));
end
detected = randi([0 1], 1, n);
allObstX = randi([1 xmax], n, 1);
allObstY = randi([1 ymax], n, 1);

if any(detected)
    a = allObstX(detected==1);
    b = allObstY(detected==1);
    detObst = horzcat(a, b);
    unique(detObst, 'rows')

    occupancyMapNew = createOccupancyMap(a,b,xmax,ymax);
    occupancyMap = occupancyMap | occupancyMapNew
end

i = 0;
for r = 1:ymax
    for c = 1:xmax
        i = i+1;
        cur = occupancyMap(r,c);
        if cur == 1
            obstList(i,:) = [c r];
        elseif cur == 0
            obstList(i,:) = [0 0];
        end
    end
end

unique(obstList, 'rows');
