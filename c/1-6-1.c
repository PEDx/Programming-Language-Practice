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
					ret/=i;//��ret�𼶳���һ�����������ret�������һ��������ô�ͱ�־��
					//ѭ���Ľ�����Ȼ��������ret����û�пո� 
					c=zs(ret);
					if(c==1){
						printf("%d",ret);
						break;
					}
				}else i++;
 		}
 return 0;
 }				
