#include <stdio.h>
int main ()
{
	int m,i,j,A,B,sum1,sum2;
	while(scanf("%d",&m)!=EOF)
	{
		for(i=0;i<m;i++){
			sum1=0;sum2=0;
			scanf("%d %d",&A,&B);
			for(j=1;j<A;j++){          
				if(A%j==0){            
					sum1+=j;          
				}
			}	
			for(j=1;j<B;j++){
				if(B%j==0){
					sum2+=j;
				}
			}	
			if((sum1==B)&&(sum2==A)){ 
			    printf("YES\n");
		    }else{
			    printf("NO\n"); 
		    } 
		}
		
	}
	return 0;
}
 
