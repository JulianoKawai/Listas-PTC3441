%% TRAJECTORYGENERATION  
% Discretisa o uma tragetória a partir de pontos do caminho e o tempo de
% cada intervalo e o intervalor da discretização, retornando a tragetória
% suavizada pelo polinômio de quarto grau e discretizado conforme os
% parâmetros.
% 
%% Calling Syntax
% thpathi=trajectorygeneration(traj_points, T, Ts);
%
%% I/O Variables
% |IN 1 Double Matrix| *traj_points*: vector of angles of the initial, 
%  intermediate and final positions of the actuator 1xN
%  N = number of points
%
% |IN 2 Double| *T*: Time of each segment
%
% |IN 3 Double| *Ts*: Discretization resolution time for each segment
%
% |OUT 1 Double Array| *thpathi*: Matrix containing position velocity and 
% acceleration as columns and each instant discretized as rows
%
%% Example
%  traj_points = [0 22 16 0];
%  T = 3;
%  Ts = 0.2;
%
%  [thpathi]=trajectorygeneration(traj_points, T, Ts);
%
%% Hypothesis
%  traj_points tenha pelomenos 2 pontos para se formar um intervalo
%  Ts deve ser algumas vezes menor que T para que ocorra uma discretização
%
%% Limitations
%  T deve ser divisível por Ts
%
%% Function

function [thpathi]=trajectorygeneration(traj_points, T, Ts)

cctot = trajectoryplanning(traj_points,T);
thpathi = zeros([(T/Ts)*length(cctot(:,1)),3]);
pps = T/Ts;

for a=1:length(cctot(:,1))
    for b=1:pps
        td = (b-1)*Ts;
        thpathi((a-1)*pps+b,1) = cctot(a,1) + cctot(a,2)*td + cctot(a,3)*td^2 + cctot(a,4)*td^3; 
        thpathi((a-1)*pps+b,2) = cctot(a,2) + 2*cctot(a,3)*td + 3*cctot(a,4)*td^2;
        thpathi((a-1)*pps+b,3) = 2*cctot(a,3) + 6*cctot(a,4)*td;
    end  
end
end