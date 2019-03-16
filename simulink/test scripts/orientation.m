function theta = orientation(front, back)
    x = front(1) - back(1);
    y = front(2) - back(2);
    theta = atan(y/x);
    if (y >= 0) && (x < 0)
       theta = theta + pi;
    elseif (y < 0) && (x < 0)
       theta = theta - pi;
    end
    theta = rad2deg(theta);
end