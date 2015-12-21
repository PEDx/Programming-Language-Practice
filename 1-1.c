# c-programming-language-practice
the c programming language practice.(The Types)
#include<stdio.h>
int uadd_ok(unsigned x,unsigned y){
	int s=x+y;
	int a=1;
	if(s<x){
		a=0;
	}
	return a;
}

int tadd_ok2(int x,int y){
	int sum =x+y;
	return (sum-x==y)&&(sum -y==x);
}
int tadd_ok(int x,int y){
	int s=x+y;
	int a=1;
	if(s<0&&x>0&&y>0){
		a=0;
	}else if(s>0&&x<0&&y<0){
		a=0;
	}
	return a;
}
int main()
{
	int a=2000000000;
	int b=1899999999;
	int t=tadd_ok(a,b);
	int c=4;
	double d=2.0;
	// int t=uadd_ok(a,b);
	double e=c/d;
	int f=sizeof(d);
	printf("%d",f);
	return 0;
}
