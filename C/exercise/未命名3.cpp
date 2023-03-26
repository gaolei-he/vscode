#include <bits/stdc++.h>
#define N 500009
using namespace std;
char str1[N];
char str2[N];
int main()
{
	cin.getline(str1, N);
	
	strcpy(str2, str1);
	int length2 = strlen(str1);
	int length3 = strlen(str2)-1;
	while(length2--){
		
		//length2 --;
		str1[length2] = '\0';
		int length = length3;
		for(int i=length2-1;i>=0;i--){
			str2[length] = str1[i] + str2[length] - 48;
			if(str2[length]>'9'){
				str2[length] -= 10;
				str2[length-1] ++;
			}
			length --;
		}
	}
	for(int i=strlen(str2)-1;i>0;i--){
		if(str2[i]>'9'){
			str2[i] -= 10;
			str2[i-1] ++;
		}
	}
	if(str2[0]>'9'){
		str2[0] -= 10;
		cout << 1;
	}
	int length1 = strlen(str2);
	for(int i=0;i<length1;i++) printf("%c", str2[i]);
	return 0;
}
