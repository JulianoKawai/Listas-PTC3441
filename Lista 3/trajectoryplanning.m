%% CUBECOEF  
% Calcula os coeficientes do polinômio de terceiro grau descrito pelas
% posições e velocidades iniciais e finais de um determinado segmento,
% assim como a duração do segmento.
% 
%% Calling Syntax
% cc=cubcoef(th0,thdot0,thf,thdotf,T);
%
%% I/O Variables
% |IN 1 Double| *th0*: 
%
% |IN 2 Double| *thdot0*: 
%
% |IN 3 Double| *thf*: 
% 
% |IN 4 Double| *thdotf*: 
%
% |IN 5 Double| *T*: 
%
% |OUT 1 Double Array| *cc*: coeficientes da equação cúbica [a0 a1 a2 a3]
%
%% Example
%  
%
%% Hypothesis
% 
%
%% Limitations
% 
%
%% Function

function [cctot]=trajectoryplanning(traj_points,T)

traj_vel = zeros([length(traj_points),1]);
cctot = zeros([length(traj_points)-1,4]);

for a = 2:length(traj_points)-1
    dif1 = traj_points(a)-traj_points(a-1);
    dif2 = traj_points(a+1)-traj_points(a);
    if dif1*(-dif2) >= 0
        traj_vel(a) = 0;
    else
        traj_vel(a) = (dif1+dif2)/(2*T);
    end
    cctot(a-1,:) = cubcoef(traj_points(a-1),traj_vel(a-1),traj_points(a),traj_vel(a),T);
end
cctot(end,:) = cubcoef(traj_points(end-1),traj_vel(end-1),traj_points(end),traj_vel(end),T);
end