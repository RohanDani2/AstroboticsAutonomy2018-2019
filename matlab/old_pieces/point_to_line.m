function detected = point_to_line(points, triangle)
        % Distances to from points to lines, negitave if below line
        % Can add index of j 'detected(j)' to store detected for each object 
        r = size(points,1);
        d(r,3)  = 0;
        detected = 0;
        for j = 1:r
            for i = 1:2:5
                a = triangle(i,:) - triangle(i+1,:);
                b = points(j,:) - triangle(i+1,:);
                slope = (triangle(i+1,2) - triangle(i,2))/(triangle(i+1,1) - triangle(i,1));
                y_int = triangle(i,2) + slope*triangle(i,1);
                x = points(j,1);
                y = points(j,2);
                if slope*x + y_int > y
                    d(j,(i+1)/2) = -(norm(cross(a,b)) / norm(a));
                else
                    d(j,(i+1)/2) = norm(cross(a,b)) / norm(a);
                end
            end
            if d(j,1)>=0 && d(j,2)>=0 && d(j,3)<=0
                detected = 1;
                return
            else
                detected = 0;
            end
        end
end

