function angle = degFromPath(endPt, xpos, ypos, theta)
    x = endPt(1) - xpos;
    y = endPt(2) - ypos;
    angle = -(atan(y/x) - theta);
    angle = mod(angle, 2*pi);
    if angle >= pi
        angle = angle - 2*pi;
    end
end