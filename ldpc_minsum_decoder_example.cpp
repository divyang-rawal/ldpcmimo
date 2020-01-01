///////////////////////////////////   FINAL LDPC DECODING TOY EXAMPLE  /////////////////////////////////////
////////////////////////////////////// 1/1/2020 //////////////////////////////////////////
//////////////////////////////////////LNMIIT////////////////////////////////////////

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define N 5
int main()
{
	int i,j,k;
   	float LLR[7] = {0.4281, 1.5147 ,-0.4577, 0.3089, -0.6264, 1.9481, -0.0228};  ////////defining LLR
    float Base_Mat[4][7] =  {{1, 1, 1 ,0 ,1 ,0 ,0},
                             {0, 1, 1, 1 ,0, 1 ,0},
                             {1, 1, 0, 1, 0, 0, 1},
                             {1, 0, 1, 0 ,1, 1, 1}};
	

    
 	int m = sizeof(Base_Mat) / sizeof(Base_Mat[0]);
    int n = sizeof(Base_Mat[0])/sizeof(Base_Mat[0][0]);
	printf("\nNumber of rows: %d\n", m);
    printf("Number of columns: %d\n", n); 
	
	int itermax = 1;      // FOR NUMBER OF ITERATIONS 
	int NLayer = 2;
	int count = 0;	 
	
	float r_new[n];
		for(j=0;j<n;j++)
    	{
    		r_new[j]=LLR[j];
		}
	
	printf("r_new ::\n");

    	for(j=0;j<n;j++)
    	{
    	  printf("%f\n",r_new[j]);
		}
	
	float L[m][n];        /// defining L 
   for(i=0;i<m;i++)
   {
   	for(j=0;j<n;j++)
   	{
   		L[i][j]=r_new[j]*Base_Mat[i][j];
	}
   } printf("\n L=r_new* Base_Mat\n");
   	 for(i=0;i<m;i++)
   {
   	for(j=0;j<n;j++)
   	{
   		printf("%.1f  ",L[i][j]);
	   }printf("\n\n");
   }
	float Sgn[m][n];
	for(i=0;i<m;i++)                      // Sign matrix
	{
		for(j=0;j<n;j++)
		{
		Sgn[i][j]=0;
		} 
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(L[i][j]>0)
			Sgn[i][j]=1;
			if(L[i][j]<0)
			Sgn[i][j]=-1;
			
		}
	}
	printf("\nThe Sgn ::\n");
		for(i=0;i<m;i++)                     
	{
		for(j=0;j<n;j++)
		{
	      printf("%.0f",Sgn[i][j]);
		} printf("\n");
	}
	//Replacing all 0's in L by 100
	 for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
       {
	     if(L[i][j]==0)
	     L[i][j]=100;
       }
	}
	printf("\nL_100 ::\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%.1f ",L[i][j]);
		}printf("\n\n");
	}
	
		////////////// ROW OPERTAIONS  ////////////////
int S1,S2,S3,S4;
for(i=0;i<1;i++)
{     int S1=1;               //sign of  row1
	  for(j=0;j<n;j++)
      { 
	    if(Sgn[i][j]!=0)
		S1=S1*Sgn[i][j];
	  }
    	printf("\nThe sign of row %d  is :: %d  ",i,S1);

for(i=1;i<2;i++)
{     int S2=1;               //sign of row2
	  for(j=0;j<n;j++)
      { 
	    if(Sgn[i][j]!=0)
		S2=S2*Sgn[i][j];
	  }
   	printf("\nThe sign of row %d  is :: %d  ",i,S2);
for(i=2;i<3;i++)
{     int S3=1;               //sign of  row3
	  for(j=0;j<n;j++)
      { 
	    if(Sgn[i][j]!=0)
		S3=S3*Sgn[i][j];
	  }
    	printf("\nThe sign of row %d  is :: %d  ",i,S3);    
for(i=3;i<4;i++)
{     int S4=1;               //sign of  row4
	  for(j=0;j<n;j++)
      { 
	    if(Sgn[i][j]!=0)
		S4=S4*Sgn[i][j];
	  }
   	printf("\nThe sign of row %d  is :: %d  ",i,S4);
	
	///////////////// ABSOLUTE VALUE OF L  /////////////////
      float L_ABS[4][7];
      for(i=0;i<m;i++)
      {
      	 for(j=0;j<n;j++)  	
      	 { L_ABS[i][j]=L[i][j];
      	   if(L[i][j]<0)
		   L_ABS[i][j]=(-1)*L[i][j];	 	
		 }
	  }
	  printf("\nThe absolute value of L in L_ABS  is::\n");
	   for(i=0;i<m;i++)
      {
      	 for(j=0;j<n;j++) 
      	 {
      	 	printf("%.1f    ",L_ABS[i][j]);
		 }printf("\n\n");
	  }
	  
	  
	   printf("\nThe absolute value of L is::\n");
	   for(i=0;i<m;i++)
      {
      	 for(j=0;j<n;j++) 
      	 {
      	   L[i][j]=L_ABS[i][j];
		 }
	  }
	  
	    for(i=0;i<m;i++)
      {
      	 for(j=0;j<n;j++) 
      	 {
      	 	printf("%.1f    ",L[i][j]);
		 }printf("\n\n");
	  }
	  
	  
	  
	////////////////  Finding the minimum values /////////////////////	 
      float L1min1,L1min2, L2min1,L2min2, L3min1,L3min2, L4min1,L4min2;
      int p1=0,p2=0,p3=0,p4=0;
     for(i=0;i<1;i++)
     {
     	L1min1=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L1min1>L_ABS[i][j])	
     	 { L1min1=L_ABS[i][j];//	printf(" UDDATION IS %.1f    ",L1min1);
            p1=j;         printf("p1 is==  %d  ",p1);}
		}
	 }
	  for(i=0;i<1;i++)
	   {
	   	for(j=0;j<n;j++)
	   	{
	   		if( L1min1==L_ABS[i][j])
	   		L_ABS[i][j]=100; // printf(" UDDATION  L_ABS IS %.1f  \n  ",	L_ABS[i][j]);
		   }
		} 
	  for(i=0;i<1;i++)
     {
     	L1min2=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L1min2>L_ABS[i][j])	
     	  L1min2=L_ABS[i][j];
            
		}
	 }
	   printf("\n 1st and 2nd Minimum element of Row 1:: %f %f\n  %d ", L1min1,L1min2,p1);
	    for(i=1;i<2;i++)
     {
     	L2min1=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L2min1>L_ABS[i][j])	
     	 { L2min1=L_ABS[i][j];//	printf(" UDDATION IS %.1f    ",L1min1);
            p2=j;}
		}
	 }
	  for(i=1;i<2;i++)
	   {
	   	for(j=0;j<n;j++)
	   	{
	   		if( L2min1==L_ABS[i][j])
	   		L_ABS[i][j]=100;  //printf(" UDDATION  L_ABS IS %.1f  \n  ",	L_ABS[i][j]);
		   }
		} 
	  for(i=1;i<2;i++)
     {
     	L2min2=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L2min2>L_ABS[i][j])	
     	  L2min2=L_ABS[i][j];
            
		}
	 }
	   printf("\n 1st and 2nd Minimum element of Row 2:: %f %f\n  %d ", L2min1,L2min2,p2);
	   
	   for(i=2;i<3;i++)
     {
     	L3min1=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L3min1>L_ABS[i][j])	
     	 { L3min1=L_ABS[i][j];//	printf(" UDDATION IS %.1f    ",L1min1);
            p3=j;}
		}
	 }
	  for(i=2;i<3;i++)
	   {
	   	for(j=0;j<n;j++)
	   	{
	   		if( L3min1==L_ABS[i][j])
	   		L_ABS[i][j]=100;  //printf(" UDDATION  L_ABS IS %.1f  \n  ",	L_ABS[i][j]);
		   }
		} 
	  for(i=2;i<3;i++)
     {
     	L3min2=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L3min2>L_ABS[i][j])	
     	  L3min2=L_ABS[i][j];
            
		}
	 }
	   printf("\n 1st and 2nd Minimum element of Row 3:: %f %f\n  %d ", L3min1,L3min2,p3); 
	   
	   for(i=3;i<4;i++)
     {
     	L4min1=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L4min1>L_ABS[i][j])	
     	 { L4min1=L_ABS[i][j];//	printf(" UDDATION IS %.1f    ",L1min1);
           p4=j; }
		}
	 }
	  for(i=3;i<4;i++)
	   {
	   	for(j=0;j<n;j++)
	   	{
	   		if( L4min1==L_ABS[i][j])
	   		L_ABS[i][j]=100;  //printf(" UDDATION  L_ABS IS %.1f  \n  ",	L_ABS[i][j]);
		   }
		} 
	  for(i=3;i<4;i++)
     {
     	L4min2=L_ABS[i][0];
     	for(j=1;j<n;j++)
     	{
     	  if(L4min2>L_ABS[i][j])	
     	  L4min2=L_ABS[i][j];
            
		}
	 }
	   printf("\n 1st and 2nd Minimum element of Row 4:: %f %f\n  %d ", L4min1,L4min2,p4);  
	     
	 
	    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(i=0;i<1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==p1)
			L[i][j]=L1min2;
			else if(L[i][j]!=100)
			L[i][j]=L1min1;
		} 
	}
	for(i=1;i<2;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(j==p2)
			L[i][j]=L2min2;
			else if(L[i][j]!=100)
			L[i][j]=L2min1;
		} 
	}
	for(i=2;i<3;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==p3)
			L[i][j]=L3min2;
			else if(L[i][j]!=100)
			L[i][j]=L3min1;
		} 
	}
		for(i=3;i<4;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==p4)
			L[i][j]=L4min2;
			else if(L[i][j]!=100)
			L[i][j]=L4min1;
		} 
	}
	
	
	/*   printf("\nThe absolute value of L AFTER MINIMUM PUTTING is::\n");
	   for(i=0;i<m;i++)
      {
      	 for(j=0;j<n;j++) 
      	 {
      	 	printf("%.1f    ",L[i][j]);
		 }printf("\n\n");
	  }*/
	  
	  
	  
	                     
	
//////////////////////////  Assinging sign to all elements in L   ////////////////////////////////	
		for(i=0;i<1;i++)
	{
		for(j=0;j<n;j++)
		{   if(S1==-1)
			L[i][j]=(S1*Sgn[i][j])*L[i][j];
			else if(S1==1)
			L[i][j]=(S1*Sgn[i][j])*L[i][j];
			
		}
	} 
		for(i=1;i<2;i++)
	{
		for(j=0;j<n;j++)
		{   if(S2==-1)
			L[i][j]=(S2*Sgn[i][j])*L[i][j];
			else if(S2==1)
			L[i][j]=(S2*Sgn[i][j])*L[i][j];
			
		}
	}
		for(i=2;i<3;i++)
	{
		for(j=0;j<n;j++)
		{   if(S3==-1)
			L[i][j]=(S3*Sgn[i][j])*L[i][j];
			else if(S3==1)
			L[i][j]=(S3*Sgn[i][j])*L[i][j];
			
		}
	}
		for(i=3;i<4;i++)
	{
		for(j=0;j<n;j++)
		{   if(S4==-1)
			L[i][j]=(S4*Sgn[i][j])*L[i][j];
			else if(S4==1)
			L[i][j]=(S4*Sgn[i][j])*L[i][j];
			
		}
	}
}
}
}}
	////////////////////////////// EXTRINSIC FROM REPETITION CODE ////////////////////////////////
	
	float MUL[m][n],L_MATRIX[m][n];
 for(i=0;i<m;i++)
 {
 	for(j=0;j<n;j++)
 	{
 	   MUL[i][j]=L[i][j]*Base_Mat[i][j];	
	}
 }  printf("\n MULTIPLIED RESULT IS ::\n");
 for(i=0;i<m;i++)
 {
 	for(j=0;j<n;j++)
 	{
 	   printf("%.1f  ",MUL[i][j]);	
	} printf("\n\n");
 }
	for(i=0;i<m;i++)
 {
 	for(j=0;j<n;j++)
 	{
 	   L[i][j]=MUL[i][j];	
 	   L_MATRIX[i][j]=L[i][j];
	}
 } 	 printf("\n L_MATRIX  IS ::\n");
 for(i=0;i<m;i++)
 {
 	for(j=0;j<n;j++)
 	{
 	   printf("%.1f  ",L_MATRIX[i][j]);	
	} printf("\n\n");
 }  
 /////////////  PUTTING L_MATRIX into L_M  ////////////////  
 float L_M[m][n];
	   for(i=0;i<m;i++)
 {
 	for(j=0;j<n;j++)
 	{
 	   	
 	   L_M[i][j]=L_MATRIX[i][j];
	}
 }   printf("\n L_M  IS ::\n");
	  for(i=0;i<m;i++)
 {
 	for(j=0;j<n;j++)
 	{
 	   printf("%.1f  ",L_M[i][j]);	
	} printf("\n\n");
 }    
	    
	 /////////////////////  COLUMN OPERATIONS  ////////////////////////////
	
float sumvar[n];
for(i=0;i<n;i++)
{
	sumvar[i]=0;
}

   for(i=0;i<n;i++)
  {  sumvar[i]=0;
    for(j=0;j<m;j++) 
	{
	  sumvar[i]=sumvar[i]+L_M[j][i];	
	}	
  }	
 	printf("\nThe sumvar is\n");
	
		for(j=0;j<n;j++)
		{ 
	      printf("%.2f ",sumvar[j]);
	    }
	    float ADD[n];
	    for(j=0;j<n;j++)
	    {
	    	ADD[j]=0;
		}
    for(i=0;i<n;i++)
    {   ADD[i]=0;
    
	   ADD[i]=ADD[i]+r_new[i]+sumvar[i];
	
	}
	/////////////  FINAL OUTPUT  ////////////////////////////
	
	printf("\n\nThe updated LLR after sum is  is\n");
		for(j=0;j<n;j++)
		{ 
	      LLR[j]=ADD[j];
	    }	printf("\n");
	    	for(j=0;j<n;j++)
		{ 
	      printf("%.2f ",LLR[j]);
	    }	
	   
	   
	   int TH[n];
	   for(j=0;j<n;j++)
		{ 
		  TH[j] = LLR[j];
     	}
	    printf("\n\n Thresholded LLR:=");
	
	for(j=0;j<n;j++)
		{ 
	          if(LLR[j]>0)
	          {
	            TH[j] = 1;
	          }
	          else if(LLR[j]<0)
	          {
			  
	           TH[j] = 0;
	           }
         }
    for(j=0;j<n;j++)
		{ 
		printf(" %d  ",TH[j]);
    	}
    }
