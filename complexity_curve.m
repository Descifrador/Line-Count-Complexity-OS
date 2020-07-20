function complexity_curve()
    data0 = readmatrix("timedur.txt");
    data1 = readmatrix("timedur1.txt");
    data = (data0 + data1) / 2000;
    fitdata = fit(data(:,1),data(:,2),'poly1');
    f = plot(fitdata, data(:,1), data(:,2));
    xlabel("Number of Lines in 1000");
    ylabel("Time taken to count in ms");
    title("Complexity Curve");
    grid("on");
    exportgraphics(f, "timecurve.png","Resolution",600);
end