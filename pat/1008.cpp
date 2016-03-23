#include<stdio.h>
void rigm(int a[],int c,int rcnt){
	int j=c;
	for(int i=0;i<c;i++){
		a[j]=a[i];
		j++;
	}
}
int main()
{
	int a=0;
	int b=0;
	
	scanf("%d",&a);
	scanf("%d",&b);
	if(a<b){
		b=b%a;
	}
	int c[200];
	for(int i=0;i<a;i++){
		scanf("%d",&c[i]);
	}
	rigm(c,a,b);
	for(int i=a-b;i<2*a-b;i++){
		printf("%d",c[i]);
		if(i!=2*a-b-1){
			printf(" ");	
		}
	}
	return 0;
}
