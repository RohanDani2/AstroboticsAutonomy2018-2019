function lidarGrid = lidarList2Grid(data)%create occupancy map out of lidar scan. PASS ADJUSTED DATA HERE 
    fullLidarMap = zeros(3600,5700); %y,x
    x = data(:,1);
    y = data(:,2);
    x1 = round(x,0);
    y1 = round(y,0);
    len = length(x1); 
    count = 0;
    for i = 1:len
        if (x1(i) >= 1) && (x1(i) <= 5700) && (y1(i)>=1) && (y1(i)<=3600)
            fullLidarMap(y1(i),x1(i)) = 1; 
            count = count+1;
        end
    end
   
    lidarGrid = zeros(36,57); %%change size to 36 x 57 for full compression 
    q = 1;
    flag = 0;
    for i = 1:100:3500 % y change to 1:100:3500 for full compression
        r = 1; 
        for j = 1:100:5600 % x change to 1:100:5600 for full compression
            if flag == 1
                break
            end
            for k = i:(i+100) % change to i + 100
                if flag == 1
                    break
                end
                for l = j:(j+100) % change to i + 100 
                    if (fullLidarMap(k,l) == 1)
                        lidarGrid(q,r) = 1;
                        flag = 1;
                        break
                    end
                end
            end
            r = r+1;
            flag = 0;
        end
        q = q+1;
    end
end
