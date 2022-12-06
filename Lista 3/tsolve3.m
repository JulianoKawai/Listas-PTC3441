%% TSOLVE3
%  Converte o formato das entrada de dados do usu�rio
%  $(x,y,\theta)$
%  para o formato interno (matriz de transforma��o homog�nea)
%  para um manipulador RRR planar. Ent�o realiza a invers�o das matrizes de  
%  transforma��o que estiverem invertidas e, por fim, multiplica elas de
%  forma a obter a matriz de transforma��o equivalente, que � impresso na 
%  janela de comando, e em seguida retorn�-la em formato de usu�rio. 
% 
%% Calling Syntax
%  crelb=tsolve3(crelu,urela,arelb,is_inv);
%
%% I/O Variables
%  |IN 1 Double Array| *crelu*: _C relative to U_  _User form_  [x y theta]
%  |IN 2 Double Array| *urela*: _U relative to A_  _User form_  [x y theta]
%  |IN 3 Double Array| *arelb*: _A relative to B_  _User form_  [x y theta]
%  |IN 4 Int Array| *is_inv*: _is [crelu,urela,arelb] inverted?_ 1 if true,
% 0 if false
%
%  |OUT 2 Double Array| *crelb*: _C relative to B_ _User form_  [x y theta]
%
%% Example
%  crelb = tsolve3([-3 -3 -30],[11 -1 30],[0 7 45],[1 1 0]);
%
%% Hypothesis
%  Rob� RRR planar. As 3 matrizes de transforma��o homog�nea devem
%  representar o o sistema intermedi�rio em rela��o aos 2 sistemas da
%  transforma��o equivalente.
%
%% Limitations
%  A "Forma do usu�rio" � espec�fica para o exerc�cio de simula��o e n�o tem
%  validade para qualquer configura��o de rob�. As matrizes de transforma��o
%  devem estar ordenadas e a necessidade de invers�o de cada uma delas deve
%  ser conhecida.
%
%% Function
function [crelb]=tsolve3(crelu,urela,arelb,is_inv)
    crelu = utoi(crelu);
    urela = utoi(urela);
    arelb = utoi(arelb);
    if is_inv(1) == 1
        crelu = tinvert(crelu);
    end
    if is_inv(2) == 1
        urela = tinvert(urela);
    end
    if is_inv(3) == 1
        arelb = tinvert(arelb);
    end
    crela = tmult(urela,crelu);
    crelb = tmult(arelb,crela);
    disp(crelb);
    crelb = itou(crelb);
end