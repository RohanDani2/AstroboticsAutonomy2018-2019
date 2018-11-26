function dist = distFromPath(endPt, xpos, ypos)
    x = endPt(1) - xpos;
    y = endPt(2) - ypos;
    dist = sqrt(x^2 + y^2);
end
