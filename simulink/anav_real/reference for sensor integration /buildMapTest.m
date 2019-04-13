pos = [20 20];
theta = 0;
scale = 100;
goal = [40 20];
vehicleRad = 2;
limit = [1 1 0];
mode = 0;
                                    
mapDim = [80 40]; %[40 20]; % must be equalivant in initialize.m
detectedList = scan_decoded;



    mapGridP = zeros(mapDim(2)-1, mapDim(1)-1);


%% Orient polar list and convert to certesian 
if mode == 0
    detectedList(:,1) = detectedList(:,1) + theta - pi/2;
    [detX, detY] = pol2cart(detectedList(:,1), detectedList(:,2));
    detectedList = [detX detY];
end

%% Translate cartesian list 
offset = 1.2; % measure lidar to midpoint in decimeter 
if mode == 0
    detectedList(:,1) = detectedList(:,1) + scale*pos(1) + scale*offset*cos(theta); 
    detectedList(:,2) = detectedList(:,2) + scale*pos(2) + scale*offset*sin(theta); 
end
any(~isfinite(detectedList))
%% Round lidar data, add limit, eliminate duplicates 
rounded = round(detectedList);
rounded = vertcat(limit(:,1:2), rounded);
rounded = unique(rounded, 'rows');
any(~isfinite(rounded))
%% Eliminate points outside limit 
rounded(rounded(:, 1) <= 0, :) = [];
rounded(rounded(:, 1) > mapDim(1)*scale-scale, :) = [];
rounded(rounded(:, 2) <= 0, :) = [];
rounded(rounded(:, 2) > mapDim(2)*scale-scale, :) = [];
any(~isfinite(rounded))
%% Convert list to grid 
limitGrid = list2grid(rounded(:,1), rounded(:,2), mapDim(1)*scale-scale, mapDim(2)*scale-scale);
any(~isfinite(limitGrid))
%% Inflate points 
tic
inflated = inflate2(limitGrid, vehicleRad*scale);
time = toc;
fprintf('inflation completed in %f seconds\n', time)

%% Convert list to grid 
%     mapGridNew = 0;
%     mapGridNewTemp = 0;
%     if mode == 1
%         mapGridNew = list2grid(inflated(:,1), inflated(:,2), mapDim(1)*scale-scale, mapDim(2)*scale-scale);
%     else
%         mapGridNewTemp = list2grid(inflated(:,1), inflated(:,2), mapDim(1)*scale-scale, mapDim(2)*scale-scale);
%     end

%% (NOT NEEDED) Compress 1e-3 m grid to 1e-1 m grid
% divide lidar points by 100
% don't apply scale in buildMap
% round and eliminate duplicates, use high inflation n
% could be slower due to high inflation n 

if mode == 0
    tic
    mapGridNew = compress2(inflated, mapDim-1, scale);
    time = toc;
    fprintf('compression completed in %f seconds\n', time)
else 
    mapGridNew = inflated;
end


%% Persist grid and average with new 
if mode == 0
    alpha = 0.8; beta = 0.2;
else
    alpha = 0.99; beta = 0.01;
end
mapGridP = alpha*mapGridP + beta*real(mapGridNew);
mapGrid = mapGridP;

%% Convert probability grid to list for d*
mapList = grid2list(mapGrid);

% convert into 1-by vector: size pos goal mapList1:end
costsTemp = vertcat([numel(mapList)/3 0 0], [pos 0], [goal 0], mapList);
costs = reshape(costsTemp.',1,numel(costsTemp));

tic