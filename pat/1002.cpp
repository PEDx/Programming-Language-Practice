#include<stdio.h>

int zcount(int n){
	int c=n-48;
	return c;
	}
void pys(int n){
	switch(n){
		case 1:printf("yi");break;
		case 2:printf("er");break;
		case 3:printf("san");break;
		case 4:printf("si");break;
		case 5:printf("wu");break;
		case 6:printf("liu");break;
		case 7:printf("qi");break;
		case 8:printf("ba");break;
		case 9:printf("jiu");break;
		case 0:printf("ling");break;
	}
}
int sumfj(int n){
	int a=0;
	int cnt=1;
	int n2=n;
	//de dao shu liang ji
	while(n>9){
		n=n/10;
		cnt=cnt*10;
	}
	while(cnt>9){
		a=n2/cnt;//sou wei
		pys(a);
		printf(" ");
		n2%=cnt;//chu qu sou wei
		cnt/=10;//
	}
	a=n2/cnt;
	pys(a);
}
int main()
{
//怎样连续输入数字，并且每一轮都要将数字加到n项和里面 
	int x=0;
	int sum=0;
	x=getchar();
	while(x!='\n'){
		int x1=0;
		x1=zcount(x);
		sum+=x1;
		x=getchar();
	}
	sumfj(sum);
	return 0;
}






















