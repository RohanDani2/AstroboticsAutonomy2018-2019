function rectangle = generateRectangle(x,y)
% Returns n-by-3 matrix of x and y coordinate pairs to plot a rectanlgle of
% specified dimensions. 3rd columns is 0 fillled z-coordinates. Bottom left
% corner of rectangle will be at (0,0,0).

    xpoints = [1:x, x*ones([1,y]), x:-1:1, ones([1,y])]-1;
    ypoints = [ones([1,x]), 1:y, y*ones([1,x]), y:-1:1]-1;
    rectangle = horzcat(flipud(rot90(vertcat(xpoints, ypoints))), zeros([2*x+2*y,1])); 
end

