#include<stdio.h>
int isJ(int n){
	if(n%2){
		n=n*3+1;
	}
	return n;
}
int min(int a[],int len){
	int mini=0;
	for(int i=0;i<len;i++){
		if(a[i]<a[mini]){
			mini=i;
		}
	}
	return mini;
}
int m[10000];
int* iscNt(int n[],int a){
	int cnt=0;
	int i=0;
	for(i=0;i<a;i++){
		int b=n[i];
		while(b!=1){
		b=isJ(b);
		b=b/2;
		m[cnt]=b;
//		printf("%d/",b) ;
		cnt++;
		}
	}
	m[cnt]=0;
	return m;
}
int main()
{
	int a=0;
	scanf("%d",&a);
	int n[100];
	for(int i=0;i<a;i++){
		scanf("%d",&n[i]);
	}
	for(int i=a-1;i>0;i--){
		int mini=min(n,i+1);
		int t=n[mini];
		n[mini]=n[i];
		n[i]=t;
	}
	int *q=iscNt(n,a);
	int v[100];
	int y=0;
	for(int i=0;i<a;i++){
		int ret=1;
		int *p=q;
		do{
			if(n[i]==*p){
				ret=0;	
			}
		}while(*(++p));
		if(ret){
			v[y]=n[i];
			y++;
		}
	}
	for(int i=0;i<y;i++){
		if(i!=y-1){
		printf("%d ",v[i]);	
		}else printf("%d",v[i]);	
	}
	return 0;
}
