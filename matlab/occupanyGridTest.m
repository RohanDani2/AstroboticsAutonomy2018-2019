x = randi([1 10], 1,5);
y = randi([1 10], 1,5);

v = fliplr(rot90(vertcat(x, y),3))

out = accumarray([v(:,1),v(:,2)],1,[10 10]);