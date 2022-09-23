function [wrelb]=kin(theta,L)
    theta_rad = theta*pi()/180; 
    iform = eye(4);
    iform(1:2,1:2) = [cos(theta_rad(1)) -sin(theta_rad(1)); sin(theta_rad(1)) cos(theta_rad(1))];
    iform(1:2,4) = [0; 0];
    wrelb = iform(:,:);
    for i=1:length(L)
        disp(wrelb);
        iform = eye(4);
        iform(1:2,1:2) = [cos(theta_rad(i)) -sin(theta_rad(i)); sin(theta_rad(i)) cos(theta_rad(i))];
        iform(1:2,4) = [L(i); 0];
        disp(iform);
        wrelb = wrelb*iform(:,:);
    end
end