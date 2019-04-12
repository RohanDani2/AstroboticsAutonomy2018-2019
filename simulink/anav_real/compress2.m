function compressed = compress2(grid, mapDim, scale)


compressed = zeros(mapDim(2), mapDim(1));
for r = 1:scale:size(grid, 1)
    for c = 1:scale:size(grid, 2)
        mini = grid(r:r+scale-1, c:c+scale-1);
        if any(any(mini))
            compressed((r+scale-1)/scale, (c+scale-1)/scale) = 1;
        end
    end
end


end
