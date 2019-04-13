function inflated = inflate2(grid, r)

    persistent h
    if isempty(h)
        h = fspecial('disk', r);
        h(h>0) = 1;
    end
    
    inflated = imfilter(grid, h);

end
