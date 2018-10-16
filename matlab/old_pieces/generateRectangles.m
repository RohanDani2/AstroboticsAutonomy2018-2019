function rectangle = generateRectangles(x,y)
% Returns n-by-3 matrix of x and y coordinate pairs to plot a rectanlgle of
% specified dimensions. 3rd columns is 0 fillled z-coordinates. 

    xpoints = [1:x, x*ones([1,x]), x:-1:1, ones([1,x])];
    ypoints = [ones([1,y]), 1:y, y*ones([1,y]), y:-1:1];
    rectangle = horzcat(flipud(rot90(vertcat(xpoints, ypoints))), zeros([2*x+2*y,1])); 
end

