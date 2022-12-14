%% CUBCOEF  
%  Encontra os coefientes para o polinomio que descreve o movimento do
%  ligamento
%
%% Calling Syntax
%  function [near,far,sol]=solve_robot(goal,current,trelw,srelb,L,thetalim)
%
%% I/O Variables
%  |IN Double Matrix| *goal*: goal objective of the robot  Homogeneous 
% Transformation Matrix 4x4
%  |IN Double Matrix| *wrelb*: W rel to B  Homogeneous Transformation 
% Matrix 4x4
%  |IN Double Array| *current*: joint angle degrees  [theta1 theta2 theta3]
% [degrees degrees degrees]
%  |IN Double Matrix| *srelb*: S rel to B  Homogeneous Transformation 
% Matrix 4x4
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
%  srelb = utoi([-0.1, 0.3, 30]);
%  goal = utoi([0, 0, -90]);
%  trelw = utoi([0.1 0.2 30]);
%  [near,far,sol] = solve_robot(goal,current,trelw,srelb,L,thetalim);
%
%% Hypothesis
%  RRR planar robot.
%
% NÃO DOCUMENTADO


function [cc]=cubcoef(th0,thdot0,thf,thdotf,T)
    a0 = th0;
    a1 = thdot0;
    a2 = ((thdotf/2*T) - (3*thf/T^2) + 3*a0 + a1*((-1/2*T)+(3/T)));
    a3 = (thf - a0 - a1*T - a2*T^2)/T^3;
    cc = [a0 a1 a2 a3];
end