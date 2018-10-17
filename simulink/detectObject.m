function detected = detectObject(points, triangle)
        % Distances to from points to lines, negitave if below line
        % Can add index of j 'detected(j)' to store detected for each object 
        r = size(points,1);
        dist = zeros(r,3);
        detected = 0;
        for j = 1:r
            for i = 1:2:5
                a = triangle(i,:) - triangle(i+1,:);
                b = points(j,:) - triangle(i+1,:);
                slope = (triangle(i+1,2) - triangle(i,2))/(triangle(i+1,1) - triangle(i,1));
                y_int = triangle(i,2) - slope*triangle(i,1);
                x = points(j,1);
                y = points(j,2);
                if slope*x + y_int > y
                    dist(j,(i+1)/2) = -(norm(cross(a,b)) / norm(a));
                else
                    dist(j,(i+1)/2) = norm(cross(a,b)) / norm(a);
                end
            end
            if dist(j,1)>=0 && dist(j,2)>=0 && dist(j,3)<=0
                detected = 1;
                return
            else
                detected = 0;
            end
        end
end

