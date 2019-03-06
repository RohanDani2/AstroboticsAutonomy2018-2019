function inflated = lidarInflate(lidarRaw, r)
%     lidarRaw = [0 -1; -1 0; 0 1; 1 0];
%     r_list = [0:0.5:10 9.5:-0.5:0];
%     for k = 1:10
%         for j = 1:length(r_list)
%             r = r_list(j);

            % Generate x, y list representing origin centered circle with radius r
            n = 100;
            theta = linspace(0, 2*pi, n);
            x = rot90(r*cos(theta), 3); 
            y = rot90(r*sin(theta), 3);
            circle = horzcat(x, y);

            % Add circle around each point in lidarRaw
            len = size(lidarRaw, 1);
            inflated = zeros(n*len, 2);
            for i = 1:len
                circleTrans(:, 1) = circle(:, 1) + lidarRaw(i, 1);
                circleTrans(:, 2) = circle(:, 2) + lidarRaw(i, 2);
                inflated(i+n*(i-1), :) = lidarRaw(i, :);
                inflated(i+n*(i-1)+1:i+n*(i-1)+n, :) = circleTrans;
            end

%             plot(inflated(:,1), inflated(:,2), 'b.')
%             xlim([-10 10])
%             ylim([-10 10])
%             drawnow
%         end
%     end
end