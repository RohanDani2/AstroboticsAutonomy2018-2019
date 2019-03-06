function lidarGrid = lidarList2Grid(lidarRaw)
    fullLidarGrid = zeros(3600,5700);
    lidarRaw = round(lidarRaw, 0);
    x = lidarRaw(:,1);
    y = lidarRaw(:,2);
    len = length(x);
    
    % Map list to grid and delete points outside of map limits 
    count = 0;
    for i = 1:len
        if (x(i)>=1) && (x(i)<=5700) && (y(i)>=1) && (y(i)<=3600)
            fullLidarGrid(y(i), x(i)) = 1; 
            count = count + 1;
        end
    end
   
    % Reduce grid by 100x by stepping through 100x100 mini grids 
    lidarGrid = zeros(36,57); 
    q = 1;
    flag = 0;
    for i = 1:100:3500 
        r = 1; 
        for j = 1:100:5600 
            if flag == 1
                break
            end
            for k = i:(i+100) 
                if flag == 1
                    break
                end
                for l = j:(j+100) 
                    if (fullLidarGrid(k,l) == 1)
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
 