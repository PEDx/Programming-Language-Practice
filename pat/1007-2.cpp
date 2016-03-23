#include<stdio.h>
int zs(int a)
{
	int isprime=1;
	for(int i=2;i<a;i++)
	{
		int ret=a%i;
		if(ret==0){
			isprime=0;
		}	
	}
	return isprime;
}
int main()
{
	int n=0;
	int c[1000];
	int cnt=0;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++){
		if(zs(i)){
			c[cnt]=i;
			cnt++;
		}
	}
	int y=0;
	for(int i=0;i<cnt;i++){
		if(c[i+1]-c[i]==2){
			y++;
		}
	}	
	printf("%d",y);
	return 0;
}
