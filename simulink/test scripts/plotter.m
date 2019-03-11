function plotter(in)
    size1 = size(in,2);
    theta = linspace((-pi/4),(5*pi/4), size1);
    polarscatter(theta,in,'b.');
    rlim([0 2000]);
    
%     figure (2)
%     [x,y] = pol2cart(theta,in);
%     plot(x, y, 'b.');
%     xlim([-8000, 8000]);
%     ylim([-8000, 8000]);
    drawnow
end
