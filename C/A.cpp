#include <iostream>
#include <cstring>
#include <cmath> 
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    char str[110];
    scanf("%s", str);
    int len = strlen(str);
    cout << str[0];
    for(int i=1;i<len-1;i++){
    	
        if(str[i]=='-'){
        	if(str[i-1]=='-'||str[i+1]=='-'){
        		printf("-");
        		continue;
			}
        	if(str[i+1]=='-'){
        		cout << "--";
        		i ++;
        		continue;
			}
            if(str[i+1]-str[i-1]==1)
                continue;
            else if(str[i+1]-str[i-1]<=0||abs(str[i+1]-str[i-1])>30)
                printf("-");
            else{

                if(a==3){
                    for(int i=0;i<(str[i+1]-str[i-1]-1)*b;i++) printf("*");
                    continue;
            }
            int k;
            int cnt;
            a==2?cnt=32:cnt=0;
            c==1?k=str[i-1]+1:k=str[i+1]-1;
            for(;c==1?k<str[i+1]:k>str[i-1];c==1?k++:k--){
                for(int j=0;j<b;j++){
                	if(str[i-1]>'a') printf("%c", k-cnt);
                	else printf("%c", k);
				}
                    
            }
            }
        }
        else printf("%c", str[i]);
    }
	cout << str[len-1];
    return 0;
}

