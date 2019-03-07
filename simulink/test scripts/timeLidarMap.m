load('lidar_scan.mat')
load('notgray.mat')

lidarGrid = 0;
alpha = 0.5;
beta = 0.5;
botRadius = 100;
for i = 1:5
    lidar_scan(:,1) = lidar_scan(:, 1) + 100;
    inflated = lidarInflate(lidar_scan, botRadius);
    tic
        newGrid = lidarList2Grid(inflated);
    toc
    lidarGrid = alpha*lidarGrid + beta*newGrid; 
    %lidarGrid(lidarGrid > 1) = 1;
    
    figure(1)
    title ('Lidar Scan')
    plot(lidar_scan(:,1), lidar_scan(:,2),'b.')
    
    figure(2)
    title('Inflated Lidar Scan')
    plot(inflated(:,1), inflated(:,2),'b.')
    
    figure(3)
    title('Lidar Scan - Eliminated OOB Points - Reduced Resolution by 100x')
    j = 0;
    lidarList = zeros(size(lidarGrid,1)*size(lidarGrid,2),2);
    for r = 1:size(lidarGrid,1)
        for c = 1:size(lidarGrid,2)
            j = j+1;
            cur = lidarGrid(r,c);
            if cur > 0
                lidarList(j,:) = [c r];
            elseif cur == 0
                lidarList(j,:) = [nan nan];
            end
        end
    end
    plot(lidarList(:,1), lidarList(:,2), 'b.')
    
    figure(4)
    title('Gray-Scale Robot Probability Map')
    colormap(notgray)
    pcolor(lidarGrid)
    pause
end