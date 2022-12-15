%% Plot of data points extracted using GRABIT

% Link to grabit:
% https://it.mathworks.com/matlabcentral/fileexchange/7173-grabit

% Reference
% Naghizadeh-Kashani, Y. Y & Cressault, Y. & Gleizes, Alain. (2002). Net emission coefficient of air thermal plasmas.
% Journal of Physics D: Applied Physics. 35. 2925-2934. 10.1088/0022-3727/35/22/306. 
% Figure 13, R_p = 0

load nec.txt
x = nec(:,1);
y = nec(:,2);

% Convert the y-points to linear-scale
y = 10.^y;

vec = [x,y];

yy = @(T) spline(x, y, T);

xx = linspace(0,30000,300);

% Plotting the y-points on the log-scale
semilogy(xx,yy(xx),'k');
title('NEC vs T for air, R_{P} = 0')
xlabel('T (K)')
ylabel('NEC (W m^{-3} sr^{-1})')
grid()