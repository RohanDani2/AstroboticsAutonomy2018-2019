function angle = degFromLine(endPt, xpos, ypos, theta)
x = endPt(1) - xpos;
y = endPt(2) - ypos;
angle = atan(y/x) - theta;
end