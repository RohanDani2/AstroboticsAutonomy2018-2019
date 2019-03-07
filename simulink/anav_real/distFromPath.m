function [dist, xdif, ydif] = distFromPath(endPt, xpos, ypos)
    xdif = endPt(1) - xpos;
    ydif = endPt(2) - ypos;
    dist = sqrt(xdif^2 + ydif^2);
end
