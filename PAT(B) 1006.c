#include<stdio.h>
int main()
{
	int a=0;
	scanf("%d",&a);
	int x=a;
	int cnt=1;
	for(;a>9;a=a/10){
		cnt=cnt*10;
	}
	if(cnt==100){
		int a=x/cnt;
		x=x%cnt;
		for(int i=0;i<a;i++){
			printf("B");
		}
		cnt/=10;
	}
	if(cnt==10){
		int a=x/cnt;
		x=x%cnt;
		for(int i=0;i<a;i++){
			printf("S");
		}cnt/=10;
	}
	if(cnt==1){
		for(int i=1;i<x+1;i++){
			 printf("%d",i);
		}
	}
	return 0;
}
