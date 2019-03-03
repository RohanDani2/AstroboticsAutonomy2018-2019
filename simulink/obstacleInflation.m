function [newOccupancyMap] = obstacleInflation(occupancyMap,botRadius)
    botRadius = round(botRadius); %%get max rounded radius of bot for turning 
    [rows,columns] = size(occupancyMap); 
    newOccupancyMap = occupancyMap; %%new grid with inflated obstacles 
    for i = 1:rows %%loop through the occupancy grid of obstcles 
        for j = 1:columns
             if (occupancyMap(i,j) == 1) %%first check if already obstacle in that location
               if (newOccupancyMap(i+botRadius,j) ~= 1) %%down 
                    newOccupancyMap(i+botRadius,j) = 1; %%consider an obstacle if within bot turning radius
               end 
               if(newOccupancyMap(i-botRadius,j) ~= 1) %%up 
                    newOccupancyMap(i-botRadius,j) = 1;
               end
               if(newOccupancyMap(i,j+botRadius) ~= 1) %%right 
                    newOccupancyMap(i,j+botRadius) = 1;
               end
               if (newOccupancyMap(i,j-botRadius) ~= 1) %%left 
                    newOccupancyMap(i,j-botRadius) = 1;
               end 
               if (newOccupancyMap(i-botRadius,j-botRadius) ~= 1) %% top left diagonal
                    newOccupancyMap(i-botRadius,j-botRadius) = 1;
               end
               if (newOccupancyMap(i+botRadius,j-botRadius) ~= 1) %%bottom right diagonal
                    newOccupancyMap(i+botRadius,j-botRadius) = 1;
               end 
               if (newOccupancyMap(i+botRadius,j+botRadius) ~= 1) %%top right diagonal 
                    newOccupancyMap(i+botRadius,j+botRadius) = 1;
               end
               if (newOccupancyMap(i-botRadius,j+botRadius) ~= 1) %%bottom left diagonal
                    newOccupancyMap(i-botRadius,j+botRadius) = 1;
               end
            end  
        end    
    end
end 