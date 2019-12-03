%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% LDPC_LLR Soft Decode_Example %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% Prepared By : D.Rawal (Team LNMIIT) %%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% Date : 03/12/2019 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear all;
close all;

%Code1 = zeros(1,40);
snr_dB = 0;
snr_linear = 10^(snr_dB/10);
k_databits = 20;
n_codebits = 40;
r_rate = k_databits/n_codebits;
n_var = 1/sqrt(2*r_rate*snr_linear);
Itermax = 8;

Tx_data = 1 - zeros(1,40);                %%%%%%%%%%%% All zero codeword
Code = Tx_data + n_var*randn(1,40); 
%Code = [1.26760845423876,0.555051963385502,1.99749374499034,0.356614537079136,0.984873745774076,1.34619674412894,1.09851275537076,1.39307991304684,1.11491352257410,0.652053279515413,1.11736596471570,1.28884589371053,1.04775123859141,0.933432038263744,0.226649186116525,-0.114154190829898,0.246798602214083,1.13318120668987,1.48480036823413,0.290591440780821,0.734073188986942,1.37304504799276,1.35448652462476,1.51517894954432,1.39211961729698,0.729747608059110,1.30353194125672,0.240142383513637,1.55567499570432,1.49311933462377,1.30195356303786,0.745363600483588,-0.202647404512546,1.55682661571005,1.94740816835012,1.76110056584264,0.203426016084147,0.994512247310367,1.55845746357356,0.671841388316112];
%Code = [0.888517750652336,0.0261842518105864,0.831450329770298,1.54439926644243,0.723409971773288,0.936128435492400,2.43875642638731,1.06343566652467,0.503069749096237,0.307749974686596,0.492824136036691,0.630737420543691,1.08931805899675,0.466097199686703,1.31625934232682,0.574069223185079,1.62430018586852,0.251070185651991,1.52623074786458,-0.239295018421092,1.70785240890287,0.976861021691744,1.24226756557335,1.25869180032837,0.691745348832848,-0.421306210606352,0.913266958196573,0.0690093913992322,0.940819063705450,1.20778154489135,1.79797297595987,0.914331975371884,0.993101199789955,1.44246318535448,0.895430448778166,1.45791840551724,1.52004144440905,1.04488130466349,1.09686620638030,1.10786870182479];
LLR = Code; %+ (0.01*randn(1,length(Code)));%[0.2 -0.3 1.2 -0.8 00.5 .6 -1.1];
Threshold = LLR > 0;
%%%%%%%%%%%%%%%%%%%% Base Matrices %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

I = eye(5);
I1 = circshift(I,[0 1]);
I2 = circshift(I,[0 2]);
I3 = circshift(I,[0 3]);
I4 = circshift(I,[0 4]);
Z_Mat = zeros(5,5);

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

Base_Matrix(:,:,1) = H_Parity_Mat(1:5,:);
Base_Matrix(:,:,2) = H_Parity_Mat(6:10,:);
Base_Matrix(:,:,3) = H_Parity_Mat(11:15,:);
Base_Matrix(:,:,4) = H_Parity_Mat(16:20,:);

%%%%%%%%%%%%%%%%%%%%%%% Uncomment it: Toy Example works, NLayer = 2 %%%%%%%
% % % LLR = [0.2 -0.3 1.2 -0.5 0.8 0.6 -1.1];
% % % Base_Matrix(:,:,1) = [1 1 1 0 1 0 0;...
% % %                       0 0 0 1 0 1 1];
% % % Base_Matrix(:,:,2) = [1 1 0 1 0 0 1;...
% % %                       0 0 1 0 1 1 0];

[m,n] = size(Base_Matrix(:,:,1));
itermax = 2;
NLayer = 4;
count = 0;

for iter = 1:itermax
for L1 = 1:NLayer
r_new = LLR;

% if(L1 == 1)
%     Base_Mat = Base_Mat1;
% else
%     Base_Mat = Base_Mat2;
% end;
Base_Mat = Base_Matrix(:,:,L1);

for i = 1:m
    L(i,:) = r_new.*Base_Mat(i,:);
    Sgn(i,:) = sign(L(i,:));
end;

for i=1:m
    for j = 1:n
    if(L(i,j) == 0)
        L(i,j) = 100;
    end;
    end;
end;

for i = 1:m
    S = prod(sign(L(i,:)));
    [Lmin1(i),Pos1(i)] = min(abs(L(i,:)));
    Lmin1(i) = L(i,Pos1(i)); 
    Temp = L(i,Pos1(i));
    L(i,Pos1(i)) = 100;
    [Lmin2(i),Pos2(i)] = min(abs(L(i,:)));
    Lmin2(i) = L(i,Pos2(i));
    L(i,Pos1(i)) = Temp;    

    
    for j =1:n
        if(j == Pos1(i))
          L(i,j) = Lmin2(i);
        else
            if(L(i,j)~=100)
               L(i,j) = Lmin1(i);
            end;
        end;        
    end;
    
    L(i,:) = abs(L(i,:));
    if(S == -1)
       L(i,:) = ((S.*Sgn(i,:)).*(L(i,:))); 
    else
       L(i,:) = (Sgn(i,:)).*(L(i,:));
    end;
    
end;

%%%%%%%%%%%%Extrinsic from Repetition code %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

for i =1:n
    sumvar(i) = sum(L(:,i));
    LLR(i) = r_new(i) + sum(L(:,i));
%    L(:,i) = r_new(i) + sum(L(:,i)) - L(:,i);    
end;
LLRx = LLR;
%Detect = bitxor((LLRx > 0),ones(1,n)) ;
Detect = (LLRx > 0);

L = L.*Base_Mat;
% if(L1 == 1)
%     L_Matrix_1 = L; 
% else
%     L_Matrix_2 = L;   
% end;
L_Matrix(:,:,L1) = L;

%if(iter == 1)%(L1 ==2)

if(count > 5000000)  %%%%%%%%% Can be opened to remove offset values
    if(L1>1)
        for i = 1:n
            LLR(i) = LLR(i) - sum(L_Matrix(:,i,L1-1));
           %    L(:,i) = r_new(i) + sum(L(:,i)) - L(:,i);    
        end;
    else
        for i = 1:n
            LLR(i) = LLR(i) - sum(L_Matrix(:,i,NLayer));
           %    L(:,i) = r_new(i) + sum(L(:,i)) - L(:,i);    
        end;
    end;
end;
%end;

count = count + 1;
end; 

end;

Hard_decode = sum(abs(Tx_data - Threshold))/length(Tx_data)
Soft_decode = sum(abs(Tx_data - Detect))/length(Tx_data)

