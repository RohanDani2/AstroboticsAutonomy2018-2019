function angle = degFromPath(endPt, xpos, ypos, theta)
    x = endPt(1) - xpos;
    y = endPt(2) - ypos;
    angle = atan(y/x) - theta;
    if angle >= pi
        angle = angle - 2*pi;
    elseif angle <= -pi
        angle = angle + 2*pi;
    end
end