function detected = detectRotated(points, cone)
    r = size(points,1);
    d = zeros(r,3);
    detected = zeros(1,r);

    for j = 1:r
        for i = 1:3
            a = cone(i,:) - cone(i+1,:);
            a(:,[1 2]) = a(:,[2 1]);
            a(:,1) = -a(:,1);
            b = points(j,:) - cone(i+1,:);
            
            d(j,i) = dot(a,b);
        end
        if d(j,1)>=0 && d(j,2)>=0 && d(j,3)>=0
            detected(j)= 1;
        else
            detected(j) = 0;
        end
    end
end