//��������ʮ��һ�У� 
#include <stdio.h>
int main()
{
	int nu, num;
	scanf("%d %d", &nu, &num);
	while(nu>num){
		printf("ERROR! type again\n");
		scanf("%d %d", &nu, &num);//������� 
	}
	
	int prime = 2, a = 2;
	int listPrime[10001];
	int i = 0;
	int shang = 0;
	while(1){//�ж����� 
	
	while(prime>a){
		shang = prime%a;
		if(shang == 0){
			a = 1;
			prime ++;//���������ֱ����һ������һ���� 
		}
		a ++;
	}//һֱû������������������ͨ���°��ѭ�������������б�����ʼ����һ���� 
	a = 2;
	listPrime[i]=prime;//�����Ž��б� 
	if(i==num-1){
		break;//����������ޣ�����׷������ ����������ѭ�� 
	}
	i ++;
	prime ++;	
	}
	int count = 0;
	for(i=nu-1;i<=num-1;i++){
		printf("%d",listPrime[i]);
		count ++;
		if(count<10){//ʮ��һ�� 
			printf(" ");
		}else{
			printf("\n");
			count = 0;
		}
	}
	return 0;
}
