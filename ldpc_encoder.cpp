
//////////////////////////  LDPC ENCODING   ///////////////////////////
//////////////////////////  21/12/19     //////////////////////////////
/////////////////////////LNMIIT /////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
int main()
{
int I[N][N]={{1,0,0,0,0},
            {0,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,0},
            {0,0,0,0,1}};
int I1[N][N]={{0,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,0},
            {0,0,0,0,1},
            {1,0,0,0,0}};              
int I2[N][N]={{0,0,1,0,0},
             {0,0,0,1,0},
             {0,0,0,0,1},
             {1,0,0,0,0},
             {0,1,0,0,0}};
int I3[N][N]={{0,0,0,1,0},
             {0,0,0,0,1},
             {1,0,0,0,0},
             {0,1,0,0,0},
             {0,0,1,0,0}};
int I4[N][N]={{0,0,0,0,1},
             {1,0,0,0,0},
             {0,1,0,0,0},
             {0,0,1,0,0},
             {0,0,0,1,0}};
int Z[N][N]={{0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}};              
 int H[20][40];
  for(int i=0;i<20;i++)
 {                
 for(int j=0;j<40;j++)
 { H[i][j]=0;
 }
 }
 
 for(int i=0;i<5;i++)  //DECLARING  1ST row of H matrix
 {                
 for(int j=0;j<40;j++)
{ if(j<N)
  H[i][j]=I1[i][j]; 
  if(j>=10&&j<15)
  H[i][j]=I3[i][j-10]; 
  if(j>=15&&j<20)
  H[i][j]=I1[i][j-15]; 
  if(j>=20&&j<25)
  H[i][j]=I2[i][j-20]; 
  if(j>=25&&j<30)
  H[i][j]=I[i][j-25];
 
 
}
}
for(int i=5;i<10;i++)       //DECLARING  2nd row of H matrix
{
  for(int j=0;j<40;j++)
 {  
  if(j<N)
   H[i][j]=I2[i-5][j];
 
  if(j>=N&&j<10)
   H[i][j]=I[i-5][j-N];
 
  if(j>=15&&j<20)
      H[i][j]=I3[i-5][j-15];
     if(j>=25&&j<30)
        H[i][j]=I[i-5][j-25];  
    if(j>=30&&j<35)
        H[i][j]=I[i-5][j-30];      
 }
}


for(int i=10;i<15;i++)         //DECLARING  3rd row of H matrix
{
  for(int j=0;j<40;j++)
 {  
   if(j>=N&&j<10)
   H[i][j]=I4[i-10][j-N];
   if(j>=10&&j<15)
   H[i][j]=I2[i-10][j-10];
   if(j>=15&&j<20)
   H[i][j]=I3[i-10][j-15];
   if(j>=20&&j<25)
   H[i][j]=I1[i-10][j-20];
   if(j>=30&&j<35)
        H[i][j]=I[i-10][j-30];
   if(j>=35&&j<40)
        H[i][j]=I[i-10][j-35];    
 }
}

for(int i=15;i<20;i++)        //DECLARING  4th row of H matrix
{
  for(int j=0;j<40;j++)
 {  
   if(j<N)
   H[i][j]=I4[i-15][j];
   if(j>=N&&j<10)
   H[i][j]=I1[i-15][j-N];
   if(j>=10&&j<15)
   H[i][j]=I[i-15][j-10];
   if(j>=20&&j<25)
   H[i][j]=I2[i-15][j-20];      
   if(j>=35&&j<40)
      H[i][j]=I[i-15][j-35];    
}
}
     

 for(int i=0;i<20;i++)         //printing the H maatrix
 {                
 for(int j=0;j<40;j++)
 { printf("%d ",H[i][j]);
 
 }printf("\n");
 }
//////////////////////////////Message bits generation//////////////////////////////////////////
 int MSG1[20][5],MSG2[20][5],MSG3[20][5],MSG4[20][5];
  printf("The messages of 5 bits are \n ");
   srand (time(NULL));
  
  for(int i=0;i<N;i++)                        //Message 1
  {
  for(int j = 0; j<1 ; j++)
  {
   MSG1[i][j]=rand()%2;
  }
  }   
//printing the message bits
   printf("MSG1 \n");
   for(int i=0;i<N;i++)
  { 
  for(int j = 0; j<1 ; j++)
  {
   printf("%d\n", MSG1[i][j]);
  }
    printf("\n");
  }
 
  for(int i=0;i<N;i++)                        //Message 2
  {
  for(int j = 0; j <1 ; j++)
  {
   MSG2[i][j]=rand()%2;
  }
  }   
//printing the message bits
  printf("MSG2 \n");
   for(int i=0;i<N;i++)
  { 
  for(int j = 0; j <1 ; j++)
  {
   printf("%d\n", MSG2[i][j]);
  }
    printf("\n");
  }
  
  for(int i=0;i<N;i++)                        //Message 3
  {
  for(int j = 0; j <1 ; j++)
  {
   MSG3[i][j]=rand()%2;
  }
  }   
//printing the message bits
  printf("MSG3 \n");
   for(int i=0;i<N;i++)
  { 
  for(int j = 0; j<1 ; j++)
  {
   printf("%d\n", MSG3[i][j]);
  }
    printf("\n");
  }
 
  for(int i=0;i<N;i++)                        //Message 4
  {
  for(int j = 0; j<1 ; j++)
  {
   MSG4[i][j]=rand()%2;
  }
  }   
//printing the message bits
  printf("MSG4 \n");
   for(int i=0;i<N;i++)
  { 
  for(int j = 0; j<1 ; j++)
  {
   printf("%d\n", MSG4[i][j]);
  }
    printf("\n");
  }
 
 /////////////////////         FORMING PARITY EQUATIONS  ///////////////////////
 int P1_shift[N][1],P1[N][N],P2[N][N],P3[N][N],P4[N][N],M1[N][N],M2[N][N],M3[N][N],M4[N][N],M5[N][N],M6[N][N],M7[N][N],M8[N][N],M9[N][N],M10[N][N],M11[N][N],
    M12[N][N],M13[N][N],M14[N][N];
 
  for (int i = 0; i < N;i++)        //FOR EXPRESSION 1
 { for (int j = 0; j < 1;j++) 
		{
	    	M1[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M1[i][j] += I1[i][k] * MSG1[k][j];
            }
        }
    }
 printf("the multiplied result of M1 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M1[i][j] );
        } 
    }
 
 for (int i = 0; i < N;i++)        //FOR EXPRESSION 2
 { for (int j = 0; j < 1;j++) 
		{
	    	M2[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M2
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M2[i][j] += I3[i][k] * MSG3[k][j];
            }
        }
    }
 printf("the multiplied result of M2 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M2[i][j] );
        } 
    }
 
 for (int i = 0; i < N;i++)        //FOR EXPRESSION 3
 { for (int j = 0; j < 1;j++) 
		{
	    	M3[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M3
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M3[i][j] += I1[i][k] * MSG4[k][j];
            }
        }
    }
 printf("the multiplied result of M3 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M3[i][j] );
        } 
    }
 
  for (int i = 0; i < N;i++)        //FOR EXPRESSION 4
 { for (int j = 0; j < 1;j++) 
		{
	    	M4[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M4
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M4[i][j] += I2[i][k] * MSG1[k][j];
            }
        }
    }
 printf("the multiplied result of M4 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M4[i][j] );
        } 
    }
 
 for (int i = 0; i < N;i++)        //FOR EXPRESSION 5
 { for (int j = 0; j < 1;j++) 
		{
	    	M5[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M5
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M5[i][j] += I[i][k] * MSG2[k][j];
            }
        }
    }
 printf("the multiplied result of M5 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M5[i][j] );
        } 
    }

 for (int i = 0; i < N;i++)        //FOR EXPRESSION 6
 { for (int j = 0; j < 1;j++) 
		{
	    	M6[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M6
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M6[i][j] += I3[i][k] * MSG4[k][j];
            }
        }
    }
 printf("the multiplied result of M6 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M6[i][j] );
        } 
    }

 for (int i = 0; i < N;i++)        //FOR EXPRESSION 7
 { for (int j = 0; j < 1;j++) 
		{
	    	M7[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M7
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M7[i][j] += I4[i][k] * MSG2[k][j];
            }
        }
    }
 printf("the multiplied result of M7 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M7[i][j] );
        } 
    }

 for (int i = 0; i < N;i++)        //FOR EXPRESSION 8
 { for (int j = 0; j < 1;j++) 
		{
	    	M8[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M8
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M8[i][j] += I2[i][k] * MSG3[k][j];
            }
        }
    }
 printf("the multiplied result of M8 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M8[i][j] );
        } 
    }

 for (int i = 0; i < N;i++)        //FOR EXPRESSION 9
 { for (int j = 0; j < 1;j++) 
		{
	    	M9[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M9
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M9[i][j] += I[i][k] * MSG4[k][j];
            }
        }
    }
 printf("the multiplied result of M9 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M9[i][j] );
        } 
    }

 for (int i = 0; i < N;i++)        //FOR EXPRESSION 10
 { for (int j = 0; j < 1;j++) 
		{
	    	M10[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M10
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M10[i][j] += I4[i][k] * MSG1[k][j];
            }
        }
    }
 printf("the multiplied result of M10 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M10[i][j] );
        } 
    }

 for (int i = 0; i < N;i++)        //FOR EXPRESSION 11
 { for (int j = 0; j < 1;j++) 
		{
	    	M11[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M11
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M11[i][j] += I1[i][k] * MSG2[k][j];
            }
        }
    }
 printf("the multiplied result of M11 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M11[i][j] );
        } 
    }

 for (int i = 0; i < N;i++)        //FOR EXPRESSION 12
 { for (int j = 0; j < 1;j++) 
		{
	    	M12[i][j] = 0;
        }
    }
    // Multiplying first and second matrices and storing in M12
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
                M12[i][j] += I[i][k] * MSG3[k][j];
            }
        }
    }
 printf("the multiplied result of M12 :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",M12[i][j] );
        } 
    }
  
   int I1_TR[N][N];        ////////////////   Taking transpose of I1
  for (int c = 0; c < N; c++)
    for (int d = 0; d < N; d++)
      I1_TR[d][c] = I1[c][d];
 
  printf("Transpose of the matrix:\n");
 
  for (int c = 0; c < N; c++) {
    for (int d = 0; d < N; d++)
      printf("%d\t", I1_TR[c][d]);
    printf("\n");
  }
//////////////////////   FORMING EQUATIONS TO FIND PARITIES////////////////////////////

for(int i=0;i<N;i++)
{ for(int j=0;j<1;j++)
  { P1_shift[i][j]=0;
  } 
}
  for(int i=0;i<N;i++)
{ for(int j=0;j<1;j++)
  { P1_shift[i][j]=(M1[i][j]+M2[i][j]+M3[i][j]+M4[i][j]+M5[i][j]+M6[i][j]+M7[i][j]+M8[i][j]+M9[i][j]+M10[i][j]+M11[i][j]+M12[i][j])%2;
  } 
} 
 printf("\n the P1_shift  matrix :: \n");
    for (int i = 0; i < N;i++)
    {
		   for (int j = 0; j <1 ;j++) {
            printf("%d   ", P1_shift[i][j]);
            }   printf("\n");
        }
        
   for (int i = 0; i < N;i++)        //FOR EXPRESSION OF P1
 { for (int j = 0; j < 1;j++) 
		{
	    	P1[i][j] = 0;
        }
    }     
   for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
          P1[i][j] += I1_TR[i][k] *P1_shift[k][j];  
		   }
        }
    }	
  printf("the P1 is :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",P1[i][j] );
        } 
    }
    for (int i = 0; i < N;i++)        //FOR EXPRESSION OF P2
 { for (int j = 0; j < 1;j++) 
		{   M14[N][N]=0;
		    M13[N][N]=0;
	    	P2[i][j] = 0;
	    	P3[i][j]=0;
	    	P4[i][j]=0;
        }
    }     
   for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
          M13[i][j] += I2[i][k] *P1[k][j];  
		   }
        }
    }	
      for (int i = 0; i < N;i++)      
 { for (int j = 0; j < 1;j++) 
		{ 	P2[i][j] =(M1[i][j]+M2[i][j]+M3[i][j]+M13[i][j])%2 ;
        }
    }     
    
  printf("the P2 is :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",P2[i][j] );
        } 
    }
  
   for (int i = 0; i < N; i++) {                //FOR EXPRESSION OF P3       
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N;k++) {
          M14[i][j] += I[i][k] *P2[k][j];  
		   }
        }
    }	
   for (int i = 0; i < N;i++)      
   { for (int j = 0; j < 1;j++) 
		{ 	P3[i][j] =(M4[i][j]+M5[i][j]+M6[i][j]+M14[i][j])%2 ;
        }
    }     
   printf("the P3 is :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",P3[i][j] );
        } 
    }
                                                //FOR EXPRESSION OF P4  
   for (int i = 0; i < N;i++)      
   { for (int j = 0; j < 1;j++) 
		{ 	P4[i][j] =(M7[i][j]+M8[i][j]+M9[i][j]+P1_shift[i][j]+P3[i][j])%2 ;
        }
    }     
   printf("the P4 is :: \n");
 for (int i = 0; i < N;i++) 
 { for (int j = 0; j < 1;j++) 
		{
	    	printf("%d\n",P4[i][j] );
        } 
    }
   /////////////////////////////// DECLARING COMPLETE MESSGAE AND PARITY MATRIX  ///////////////////////////////////

int MSG[1][20],PARITY[1][20];
  for(int i=0;i<1;i++)
 {                
 for(int j=0;j<20;j++)
 { MSG[i][j]=0;    PARITY[i][j]=0; 
 } }
 
 for(int i=0;i<1;i++)                           //declaring message
 { for(int j=0;j<20;j++)
  {
    if(j<N) 
    MSG[i][j]=MSG1[j][i];  
    if(j>=N&&j<2*N)
    MSG[i][j]=MSG2[j-N][i];
    if(j>=2*N&&j<3*N)
    MSG[i][j]=MSG3[j-2*N][i]; 
    if(j>=3*N&&j<4*N)
    MSG[i][j]=MSG4[j-3*N][i];  
  }    
 }
 int PARIT[20][1];
  for(int i=0;i<20;i++)                        //declaring parity
 { 
  for(int j=0;j<1;j++)
  {  
    if(i<N) 
    PARIT[i][j]=P1[i][j];
    if(i>=N&&i<2*N)
    PARIT[i][j]=P2[i-(N)][j];
    if(i>=2*N&&i<3*N)
    PARIT[i][j]=P3[i-2*N][j]; 
    if(i>=3*N&&i<4*N)
    PARIT[i][j]=P4[i-(3*N)][j];
  }    
}
for(int i=0;i<1;i++)           
 { 
  for(int j=0;j<20;j++)
  {  PARITY[i][j]=PARIT[j][i];
}}

//////////printing message and parity seperately  //////////////////
for(int i=0;i<1;i++)
 {    printf("The Message Matrix is::") ;           
    for(int j=0;j<20;j++)
   {  
     printf("%d",MSG[i][j]);
   }  
	 printf("\nThe Parity Matrix is::");
    for(int j=0;j<20;j++)
   {
	 printf("%d",PARITY[i][j]);
   }
 }
///////////////////  generating CODEWORD  ////////////////////////
int CW[1][40];
for(int i=0;i<1;i++)
{ 
  for(int j=0;j<40;j++)
  { if(j<N*4)
  	CW[i][j]=MSG[i][j];
  	if(j>=N*4&&j<N*8)
  	CW[i][j]=PARITY[i][j-N*4];
  }
}
  
  int CW_TR[N*8][1];                    //taking CODEWORD TRANSPOSE  
  for(int i=0;i<40;i++)    
{ 
  for(int j=0;j<1;j++)
  {
  	CW_TR[i][j]=CW[j][i];
  }
}

printf("\nThe generated CODEWORD is::");
for(int i=0;i<1;i++)
{ 
  for(int j=0;j<40;j++)
  {
  	printf("%d",CW_TR[i][j]);
  }
}

////////////////   GENERATING  SYNDROME   ///////////////////
int SYNDROME[N*4][1];
for(int i=0;i<N*4;i++)
{
	for(int j=0;j<1;j++)
	{
		SYNDROME[i][j]=0;
	}
}
     for (int i = 0; i < N*4; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < N*8;k++) {
              SYNDROME[i][j] = (SYNDROME[i][j]+H[i][k] * CW_TR[k][j])%2;
            }
        }
    }
 printf("\nThe multiplied result of SYNDROME VECTOR is  :: \n");
 for(int i=0;i<N*4;i++)
{
	for(int j=0;j<1;j++)
	{
		printf("%d",SYNDROME[i][j]);
	}
}
int SYND_SUM=0;                          //FINDING THE SUM OF SYNDROME
for(int i=0;i<N*4;i++)
{
	for(int j=0;j<1;j++)
	{
	  SYND_SUM=(SYND_SUM^SYNDROME[i][j]);
	} //printf("%d\n",SYND_SUM);
}
printf("\n\nThe Syndrome Sum is::\n%d \n",SYND_SUM);
}
