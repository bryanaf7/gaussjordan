#include<stdio.h>
#include<math.h>
#define n 3

void printmb(double m[][n+1]){
     int i,j;
     
     printf("\n\n");
     
     
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n+1;j++)
                     printf("%lf\t",m[i][j]);
     printf("\n");
     }
 return;    
}

void printm(double m[][n+1]){
     int i,j;
     
     printf("\n\n");
     for(i=0;i<n;i++)
     {               
                     for(j=0;j<n;j++)
                     printf("%lf\t",m[i][j]);                
     printf("\n");
     }
return;}

void printv(double x[]){
     int i;
     
     
     for(i=0;i<n;i++)
     printf("%lf\t",x[i]);
     return;
}

void trocarl(double m[][n+1],int i,int j)
{int k;
double aux;

    for(k=0;k<n+1;k++)
    {aux=m[i][k];
    m[i][k]=m[j][k];
    m[j][k]=aux;}

return;}

void subsrevu(double m[][n+1],double x[])
{int i,j;



    for(i=n-1;i>=0;i--)
    	{
    	x[i]=m[i][n];
    	j=i+1;
    		while(j<n)
    		{x[i]-=m[i][j]*x[j];
    		j++;}
    		
    	x[i]=x[i]/m[i][i];
    	}
	
return;
}

void pivotear (double m[][n+1],int p)
{int i,maior=p;
 
     for(i=p+1;i<n;i++)
    {                  if(fabs(m[i][p])>fabs(m[p][p]))
                       maior=i;
    }

    if(maior!=p)
    trocarl(m,maior,p);
}

void somarl(double m[][n+1],int p,int i,double lambda)
{int j;
	for(j=p;j<n+1;j++)
	m[i][j]-=lambda*m[p][j];

return;
}


void gaussjordan(double m[][n+1],double x[])
{double lambda;
int i,p,j=0;

	//MATRIZ TRIANGULAR
	for(p=0;p<n-1;p++){	
		for(i=p+1;i<n;i++){
        pivotear(m,p);
                           
		lambda=m[i][p]/m[p][p];
		
		//pivotear(m,p);
		somarl(m,p,i,lambda);
		}
	}

	//substituíçã
	subsrevu(m,x);

	//print solução
}

main(){

    double m[n][n+1],x[n];
    int i,j;
    FILE *fp=fopen("matriz.dat","w");
    
    
for(i=0;i<n;i++)
{ for(j=0;j<n+1;j++)
  {fscanf(fp,"%lf",&m[i][j]);}
}

gaussjordan(m,x);
}  
    
    
    
    
    
    
    
    


