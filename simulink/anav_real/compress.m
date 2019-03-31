function compressed = compress(grid, mapDim, scale)
% reduce size of grid by 'scale' times 
% loop through mini scale x scale size matricies and set a 1 in compressed
% where any 1 is found in original 

    compressed = zeros(mapDim(2)-1,mapDim(1)-1); 
    q = 1;
    flag = 0;
    for i = 1:scale:mapDim(1)-2 
        r = 1; 
        for j = 1:scale:mapDim(2)-2 
            if flag == 1
                break
            end
            for k = i:(i+scale) 
                if flag == 1
                    break
                end
                for l = j:(j+scale) 
                    if (grid(k,l) == 1)
                        compressed(q,r) = 1;
                        flag = 1;
                        break
                    end
                end
            end
            r = r+1;
            flag = 0;
        end
        q = q+1;
    end

end