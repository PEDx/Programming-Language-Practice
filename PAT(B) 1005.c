#include<stdio.h>
int isJ(int n){//判断是否是奇数并改变n的值
	if(n%2){
		n=n*3+1;
	}
	return n;
}
int min(int a[],int len){//找出数组中最小数
	int mini=0;
	for(int i=0;i<len;i++){
		if(a[i]<a[mini]){
			mini=i;
		}
	}
	return mini;
}
int m[10000];
int* iscNt(int n[],int a){//将b／2的值存入数组m
	int cnt=0;
	int i=0;
	for(i=0;i<a;i++){
		int b=n[i];
		while(b!=1){
		b=isJ(b);
		b=b/2;
		m[cnt]=b;
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
	for(int i=a-1;i>0;i--){//将输入的数组按从大到小排序
		int mini=min(n,i+1);
		int t=n[mini];
		n[mini]=n[i];
		n[i]=t;
	}
	int *q=iscNt(n,a);
	int v[100];
	int y=0;
	for(int i=0;i<a;i++){//在数组m中找输入数组中的值
		int ret=1;
		int *p=q;
		do{
			if(n[i]==*p){//如果找到就将ret赋值为0
				ret=0;	
			}
		}while(*(++p));
		if(ret){//判断ret是否为0
			v[y]=n[i];//将没有找到的值赋给另一个数组
			y++;
		}
	}
	for(int i=0;i<y;i++){//遍历数组将前y-1位的值面加上空格，而y-1位不加空格
		if(i!=y-1){
		printf("%d ",v[i]);	
		}else printf("%d",v[i]);	
	}
	return 0;
}
