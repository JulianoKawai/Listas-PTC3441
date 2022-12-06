%% UTOI   
% Converte o formato de entrada de dados do usu�rio
% $(x,y,\theta)$
% para o formato interno (matriz de transforma��o homog�nea)
% para um manipulador RRR planar.
% 
%% Calling Syntax
% iform = utoi(uform)
%
%% I/O Variables
% |IN Double Array| *uform*: _User form_  [x y theta] [meters meters degrees]
% 
% |OUT Double Matrix| *iform*: _Internal form_  Homogeneous Transformation Matrix 4x4
%
%% Example
%  uform = [1 0 90];
%  iform = utoi(uform);
%
%% Hypothesis
% Rob� RRR planar.
%
%% Limitations
% A "Forma do usu�rio" � espec�fica para o exerc�cio de simula��o e n�o tem
% validade para qualquer configura��o de rob�.
%
%% Function
function [iform] = utoi(uform)
    x = uform(1);
    y = uform(2);
    theta = uform(3);
    theta_rad = theta*pi()/180; 
    iform = eye(4);
    iform(1:2,1:2) = [cos(theta_rad) -sin(theta_rad); sin(theta_rad) cos(theta_rad)];
    iform(1:2,4) = [x; y];
end