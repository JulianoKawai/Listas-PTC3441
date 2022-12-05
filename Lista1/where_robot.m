%% WHERE_ROBOT
%  Retorna a posição da ferramenta do robô com relação ao sistema da
%  estação
% 
%% Calling Syntax
%  function  [trels] = where_robot(theta,trelw,srelb,L)
%
%% I/O Variables
%  |IN Double Matrix| *theta*: _joint angles_  [theta1 theta2 theta3]
%  |IN Double Matrix| *trelw*: S rel to W  Homogeneous Transformation
% Matrix 4x4
%  |IN Double Matrix| *srelb*: S rel to B  Homogeneous Transformation
% Matrix 4x4
%  |IN Double Matrix| *L*: link lenghts  [L1 L2 L3] [meters meters meters]
%
%  |OU Double Matrix| *arelb*: _Internal form_  Homogeneous Transformation
% Matrix 4x4
% 
%% Example
%  L = [0.5 0.3];
%  theta = [0 90 -90];
%  srelb = utoi([-0.1, 0.3, 30]);
%  trelw = utoi([0.1 0.2 30]);
%  [trels] = where_robot(theta,trelw,srelb,L)
%
%% Hypothesis
% Braço planar RRR
% Calcula a posição da ferramenta em relação ao sistema da estação a partir
% das posições das juntas, comprimento dos ligamentos e posições relativas
% da ferramenta e da base.
%
%% Calling Syntax
% trels=where_robot(theta,trelw,srelb,L);
%
%% I/O Variables
% |IN 1 Double Array| *theta*: _joint angles_  [theta1 theta2 theta3]
%
%
%
%
%
% |IN 4 Double Array| *L*: _link lengths_  [L1 L2]
%
% |OUT Double Matrix| *trels*: _W relative to B_ Homogeneous Transformation Matrix 4x4
%
%% Example
%  theta = [36.87,-126.87,0];
%  L = [0.5,0.3];
%  wrelb = kin(theta,L);
%
%% Hypothesis
% Robô RRR planar. A distância entre o sistema da base e a primeira
% junta é 0. 
%
%% Limitations
% A entrada é específica para o exercício de simulação e não tem
% validade para qualquer configuração de robô.
%
%% Function
function [trels]=where_robot(theta,trelw,srelb,L)
    wrelb = kin(theta,L);
    brels = tinvert(srelb);
    trels = brels*wrelb*trelw;
end