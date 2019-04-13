clear
grid = randi([1 100], 40, 80);
grid(grid>1) = 0;
figure(1)
imshow(grid)

r = 5;

h = fspecial('disk', r);
h(h>0) = 1;

disktime = zeros(1,100);
for i = 1:100
    tic
    inflated1 = imfilter(grid, h);
    disktime(i) = toc;
end
mean(disktime)

figure(2)
imshow(inflated1)
