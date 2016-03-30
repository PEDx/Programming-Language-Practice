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
	}//if(isprime==1){
	//	printf("%d ",a);
	return isprime;
	}
int main()
{	
	int count=0;
	int a,b,c,d,e,i;
	scanf("%d",&count);
	int ret=count;
	a=zs(count);
	if(a==1){
		printf("%d",count);
	}
	for(int i=2;i<count;){
				a=ret%i;
				if(a==0){
					b=zs(i);
					if(b==1){
						printf("%dx",i);
					}
					ret/=i;//将ret逐级除掉一个质数，如果ret最后变成了一个质数那么就标志着
					//循环的结束，然后输出这个ret，且没有空格。 
					c=zs(ret);
					if(c==1){
						printf("%d",ret);
						break;
					}
				}else i++;
 		}
 return 0;
 }				
