function rad = radToWay(point, pos, theta)
    x = point(1) - pos(1);
    y = point(2) - pos(2);
    rad = -(atan(y/x) - theta);
    rad = mod(rad, 2*pi);
    if rad >= pi
        rad = rad - 2*pi;
    end
    if isnan(rad)
       disp('RAD IS NAN')
    end
end