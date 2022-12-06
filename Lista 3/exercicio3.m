clc;
uform_vec = [0.758 0.173 0.0; 
             0.6  -0.3  45.0;
             -0.4 0.3  120.0;
             0.758 0.173 0.0];

trelw = [0.1 0.2 30.0];
srelb = [0.0 0.0 0.0];

T = 3;
Ts = 0.01;
         
thpath = trajectorygenerationrrr(uform_vec, trelw, srelb, T, Ts);

L = [0.5,0.3];
pontapath = zeros(length(thpath(:,1,1)),3);
for a=1:length(thpath(:,1,1))
    ponta = where_robot(thpath(a,1,:),utoi(trelw),utoi(srelb),L);  
    pontapath(a,:) = itou(ponta);
end

figure
hold on
grid on
comet(pontapath(:,1),pontapath(:,2))


