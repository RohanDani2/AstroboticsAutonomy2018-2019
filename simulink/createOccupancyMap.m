function map = createOccupancyMap(x, y, xmax, ymax)
    map = zeros(ymax, xmax);
    len = length(x);

    for l = 1:len
        map(y(l),x(l)) = 1;
    end

    map = logical(map);
end