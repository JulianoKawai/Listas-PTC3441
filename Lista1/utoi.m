function [iform] = utoi(uform)
    x = uform(1);
    y = uform(2);
    theta = uform(3);
    theta_rad = theta*pi()/180; 
    iform = eye(4);
    iform(1:2,1:2) = [cos(theta_rad) -sin(theta_rad); sin(theta_rad) cos(theta_rad)];
    iform(1:2,4) = [x; y];
end