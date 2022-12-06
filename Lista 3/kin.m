%% KIN 
% Calcula a cinem�tica direta, ou seja, a matriz de transforma��o homog�nea do punho em rela��o � base, de
% um rob� RRR planar a partir do comprimento dos ligamentos e �ngulos das
% juntas.
% 
%% Calling Syntax
% wrelb=kin(theta,L);
%
%% I/O Variables
% |IN 1 Double Array| *theta*: _joint angles_  [theta1 theta2 theta3]
%
% |IN 2 Double Array| *L*: _link lengths_  [L1 L2]
%
% |OUT Double Matrix| *wrelb*: _W relative to B_ Homogeneous Transformation Matrix 4x4
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
function [wrelb]=kin(theta,L)
    rel1_0 = utoi([0,0,theta(1)]);
    rel2_1 = utoi([L(1),0,theta(2)]);
    rel3_2 = utoi([L(2),0,theta(3)]);
    wrelb = rel1_0*rel2_1*rel3_2;
end