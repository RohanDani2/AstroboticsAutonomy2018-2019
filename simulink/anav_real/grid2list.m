function list = grid2list(grid)
    rows = size(grid,1);
    columns = size(grid,2);
    list = zeros(rows*columns, 3);
    i = 1;
    
    for r = 1:rows
        for c = 1:columns
            list(i,:) = [c r grid(r,c)];
            i = i + 1;
        end
    end
end