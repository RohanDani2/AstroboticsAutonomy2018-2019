load('lidar_scan.mat')
load('notgray.mat')

lidarGrid = 0;
fade = 2;
for i = 1:5
    lidar_scan(:,1) = lidar_scan(:,1) + 100;
    tic
        newGrid = lidarList2Grid(lidar_scan);
    toc
    lidarGrid = lidarGrid/fade + newGrid;
    lidarGrid(lidarGrid > 1) = 1;
    
    figure(1)
    title ('Full Lidar Scan')
    plot(lidar_scan(:,1), lidar_scan(:,2),'b.')
    
    figure(2)
    j = 0;
    lidarList = zeros(size(lidarGrid,1)*size(lidarGrid,2),2);
    for r = 1:size(lidarGrid,1)
        for c = 1:size(lidarGrid,2)
            j = j+1;
            cur = lidarGrid(r,c);
            if cur == 1
                lidarList(j,:) = [c r];
            elseif cur == 0
                lidarList(j,:) = [nan nan];
            end
        end
    end
    plot(lidarList(:,1), lidarList(:,2), 'b.')
    
    figure(3)
    colormap(notgray)
    pcolor(lidarGrid)
    pause
end