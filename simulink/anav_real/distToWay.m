function dist = distToWay(point, pos)
    x = point(1) - pos(1);
    y = point(2) - pos(2);
    dist = sqrt(x^2 + y^2);
end
