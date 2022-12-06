
uform_vec = [0.758 0.173 0.0; 
             0.6  -0.3  45.0;
             -0.4 0.3  120.0;
             0.758 0.173 0.0];

trelw = [0.1 0.2 30.0];
srelb = [0.0 0.0 0.0];

T = 1;
Ts = 0.01;
         
thpath = trajectorygenerationrrr(uform_vec, trelw, srelb, T, Ts);
