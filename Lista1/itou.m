function [uform] = itou(iform)
    sincos = iform(1:2,1);
    theta_rad = atan2(sincos(2), sincos(1));
    uform = [iform(1:2,4).' theta_rad*180/pi()];
end