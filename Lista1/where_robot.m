%% WHERE_ROBOT
% Calcula a posi��o da ferramenta em rela��o ao sistema da esta��o a partir
% das posi��es das juntas, comprimento dos ligamentos e posi��es relativas
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
% Rob� RRR planar. A dist�ncia entre o sistema da base e a primeira
% junta � 0. 
%
%% Limitations
% A entrada � espec�fica para o exerc�cio de simula��o e n�o tem
% validade para qualquer configura��o de rob�.
%
%% Function
function [trels]=where_robot(theta,trelw,srelb,L)
    wrelb = kin(theta,L);
    brels = tinvert(srelb);
    trels = brels*wrelb*trelw;
end