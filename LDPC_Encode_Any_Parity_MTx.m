%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% LDPC_Encode_Example %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% Prepared By : D.Rawal (Team LNMIIT)%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% Date : 03/12/2019 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc;
clear all;
close all;
I = eye(5);
I1 = circshift(I,[0 1]);
I1_LF = circshift(I,[0 -1]);

I2 = circshift(I,[0 2]);
I3 = circshift(I,[0 3]);
I4 = circshift(I,[0 4]);
Z_Mat = zeros(5,5);

msg1 = mod(randi(2,1,5),2);%[1 0 1 0 1];
msg2 = mod(randi(2,1,5),2);%[1 0 1 0 1];
msg3 = mod(randi(2,1,5),2);%[0 1 0 0 1];
msg4 = mod(randi(2,1,5),2);%[0 1 1 1 1];

message = [msg1,msg2,msg3,msg4];


H_Parity_Mat = [I1 Z_Mat I3 I1 I2 I Z_Mat Z_Mat;...
                I2 I Z_Mat I3 Z_Mat I I Z_Mat;... 
                Z_Mat I4 I2 I I1 Z_Mat I I;...
                I4 I1 I Z_Mat I2 Z_Mat Z_Mat I];
            
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% OR %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%% Base_Graph _Matrix = [1 -1 3 1 2 0 -1 -1;...
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2 0 -1 3 -1 0 0 -1;... 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% -1 4 2 0 1 -1 0 0;...
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 4 1 0 -1 2 -1 -1 0];
%%%%%%% or One can take any graph depending on expansion factor z 
%%%%%%%%%  according to Draft  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            
Parity_1_shift = mod((I1*msg1' + I3*msg3' + I1*msg4' + I2*msg1'  + I*msg2' + I3*msg4'  + I4*msg2' + I2*msg3' + I*msg4' + I4*msg1' + I1*msg2' + I*msg3'),2);           
Parity_1 = (I1_LF*Parity_1_shift);%circshift(Parity_1_shift,[0 -1]);
Parity_2 = mod((I1*msg1' + I3*msg3' + I1*msg4' + I2*Parity_1),2);
Parity_3 = mod((I2*msg1' + I*msg2' + I3*msg4' + I*Parity_2),2); 
Parity_4 = mod((I4*msg2' + I2*msg3' + I*msg4' + Parity_1_shift + Parity_3),2); 

%Parity_4 = mod((I4*msg1' + I1*msg2' + I*msg3' + I2*Parity_1 ),2); 

Parity = [Parity_1',Parity_2',Parity_3',Parity_4'];
Code = [message, Parity];
Syndrome = mod((H_Parity_Mat*Code'),2);
sum(Syndrome)
