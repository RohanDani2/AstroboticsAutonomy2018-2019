function inflated = inflate2(grid, r)
%     coder.extrinsic('fspecial')
%     coder.extrinsic('imfilter')

    persistent h
    if isempty(h)
        h = fspecial('disk', r);
        h = real(h);
        h(h>0) = 1;
    end
        
    inflated = imfilter(grid, h);
    inflated = real(inflated);
    inflated(inflated > 1) = 1;

end
