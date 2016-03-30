#include<stdio.h>
int sum(int a)
{
	int isprime=0;
	int g=0;					//printf("a%d\n",a);
	for(int i=2;i<a/2;i++){
		if(a%i==0){
			int b,f=0;
			b=a/i;
			if(b>i){
				f=b+i;	
			}
				g+=f;		//printf("o%d\t",f);
		}
	}
			if(a==1){
				a+=1;
				isprime=0;
			}
			if(a==g+1)
			{  				
				isprime=1;
			}		
return isprime;	
}
int main()
{
	int c=0,d=0;
	int e,k=0;
	scanf("%d %d",&c,&d);
	for(int i=c;i<=d;i++){
		e=sum(i);
		if(e==1){
			printf("%d",i);
			k++;
		}
	}
			if(k==0){
			printf("NIL\n");
			}
return 0;		
}
