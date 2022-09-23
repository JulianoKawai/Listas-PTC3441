%% ITOU  
% Converte o formato interno (matriz de transforma��o homog�nea)
% para o formato de entrada de dados do usu�rio
% $(x,y,\theta)$
% para um manipulador RRR planar.
% 
%% Calling Syntax
% uform = itou(iform)
%
%% I/O Variables
% |IN Double Matrix| *iform*: _Internal form_  Homogeneous Transformation Matrix 4x4
%
% |OU Double Array| *uform*: _User form_  [x y theta] [meters meters degrees]
% 
%% Example
%  iform = [0 -1  0  1;
%           1  0  0  0;
%           0  0  1  0;
%           0  0  0  1];
%  uform = itou(iform);
%
%% Hypothesis
% Rob� RRR planar.
%
%% Limitations
% O "Formato interno" � espec�fico para o exerc�cio de simula��o e n�o tem
% validade para qualquer configura��o de rob�.
%
%% Function
function [uform] = itou(iform)
    sincos = iform(1:2,1);
    theta_rad = atan2(sincos(2), sincos(1));
    uform = [iform(1:2,4).' theta_rad*180/pi()];
end