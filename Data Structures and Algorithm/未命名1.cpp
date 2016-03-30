#include<stdio.h>
#include<string.h>
void count(char a[],int n){
	int cnt=0;
	for(int i=0;i<=n;i++){
		if(a[i]!=' '){
			cnt++;
		}
	}
	printf("%d",cnt);	
}
int* zhuan(char a[],int l){
	for(int i=0;i<=l;i++){
		switch(a[i]){
			case '1':a[i]=1;break;
			case '2':a[i]=2;break;
			case '3':a[i]=3;break;
			case '4':a[i]=4;break;
			case '5':a[i]=5;break;
			case '6':a[i]=6;break;
			case '7':a[i]=7;break;
			case '8':a[i]=8;break;
			case '9':a[i]=9;break;
			case '0':a[i]=0;break;
		}
	}
	int b[2000];
	int j=0;
	for(int i=0;i<=l;i++){
		if(a[i]!=' '){
			b[j]=a[i];
			j++;
		}
	}
	for(int i=0;i<j-1;i++){
		printf("%d ",b[i]);
	}
	return b;
}
void prin(int a,int b){
	a*=b;
	b--;
	printf("%d %d",a,b);
}
int main()
{
	char c[4000];
	gets(c);
	int *p;
	int g=strlen(c);
//	printf("%d ",g);
	count(c,g);
	p=zhuan(c,g);
	return 0;
}






