#include <bits/stdc++.h> 
using namespace std;
int main() {
	int a; 
   scanf("%d",&a);
   int j=a-2,k=0;
   int b[a];
   int i=0; 
   for(;i<a;i++){
   scanf("%d",&b[i]);
   }
   sort(b,b+a);
   i--;
   for(;j>=0;){
   		if(b[i]>b[j]){
   			i--;j--;k++;
		   }else{
		   	j--;
		   }
   	
   }
   printf("%d\n",k);
    return 0;
}
