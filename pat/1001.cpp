#include<stdio.h>
int isJ(int n){
	if(n%2){
		n=n*3+1;
	}else n=n;
	return n;
}

int iscNt(int n){
//	n=isJ(n);
	int cnt=0;
	while(n!=1){
		n=isJ(n);
		n=n/2;
//		printf("%d\n",n) ;
		cnt++;
	}
	return cnt;
}
int main()
{
	int cnt=0;
	int n;
	scanf("%d",&n);
	cnt=iscNt(n);
	printf("%d",cnt);
	return 0;
}
