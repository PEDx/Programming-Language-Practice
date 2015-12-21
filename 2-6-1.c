#include <stdio.h>
int max(char a[],int len);
int main(int argc, char const *argv[])
{
	int n=0;
	char a[100000];
	scanf("%d",&n);
	int len=n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=len-1;i>0;i--){
		int maxi=max(a,i+1);
		int t=a[i];
		a[i]=a[maxi];
		a[maxi]=t;
	}
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
int max(char a[],int len){
	int max=a[i];
	int rem=0;
	for(int i=0;i<len;i++){
		if(a[i]>max){
			max=a[i];
			rem=i;
		}
	}
return rem;
}
