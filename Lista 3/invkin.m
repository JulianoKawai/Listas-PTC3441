%% INVKIN   
%  Escreve uma função para calcular a cinemática inversa para o manipulador
%  RRR planar
%
%% Calling Syntax
%  [near,far,sol] = invkin(wrelb,current,L,thetalim)
%
%% I/O Variables
%  |IN Double Matrix| *wrelb*: W rel to B  Homogeneous Transformation
% Matrix 4x4
%  |IN Double Array| *current*: joint angle degrees  [theta1 theta2 theta3]
% [degrees degrees degrees]
%  |IN Double Array| *L*: link lenghts  [L1 L2 L3] [meters meters meters]
%  |IN Double Array| *thetalim*: Matrix of joint limits in degrees 
%
%  |OU Double Array| *near*: Homogeneous Transformation Matrix 4x4
%  |OU Double Array| *far*: Homogeneous Transformation Matrix 4x4
%  |OU Bool| *sol*: boolean represent solution existence
%
%% Example
%  L = [0.5 0.3];
%  current = [45 30 -10];
%  thetalim = [-170 170;-170 170;-170 170];
%  wrelb = kin([20,30,40],L);
%  [near,far,sol] = invkin(wrelb,current,L,thetalim);
%
%% Hypothesis
%  RRR planar robot.
%
%% Limitations
% 
%% Function
function [near,far,sol] = invkin(wrelb,current,L,thetalim)
%% Validity
%
%% Main Calculations
    sol = 0;
    coord = itou(wrelb);
    c2 = (coord(1)^2 + coord(2)^2 - L(1)^2 - L(2)^2)/(2*L(1)*L(2));
    coord(3) =  coord(3)*pi()/180;
    s2 = [sqrt(abs(1-c2^2)) -sqrt(abs(1-c2^2))];
    k1 = L(1) + L(2)*c2;
    k2 = L(2)*s2;
    gamma = atan2(k2,k1);
    theta2 = atan2(s2,c2);
    theta1 = atan2(coord(2),coord(1)) - gamma;
    theta3 = coord(3) - theta1 - theta2;
    theta1 = theta1*180/pi();
    theta2 = theta2*180/pi();
    theta3 = theta3*180/pi();
    if thetalim(1,1) < theta1(1) && theta1(1) < thetalim(1,2)
        if thetalim(2,1) < theta2(1) && theta2(1) < thetalim(2,2)
            if thetalim(3,1) < theta3(1) && theta3(1) < thetalim(3,2)
                sol = 1;
            end
        end  
    end
    if thetalim(1,1) < theta1(2) && theta1(2) < thetalim(1,2)
        if thetalim(2,1) < theta2(2) && theta2(2) < thetalim(2,2)
            if thetalim(3,1) < theta3(2) && theta3(2) < thetalim(3,2)
                sol = 1;
            end
        end  
    end
    if abs(current(1) - theta1(1)) > abs(current(1) - theta1(2))
        near = [theta1(2) theta2(2) theta3(2)];
        far = [theta1(1) theta2(1) theta3(1)];
    else
        near = [theta1(1) theta2(1) theta3(1)];
        far = [theta1(2) theta2(2) theta3(2)];    
    end
end