#include<stdio.h>
void zs(int a[],int b)
{
	for(int i=2;i<=b/2;i++){ 
    if(a[i]!=0) 
      for(int j=i+i;j<=b;j+=i) 
        a[j]=0; 
   } 
}
int main()
{
	int n=0;
	int c[100001];
	int d[1000];
	int cnt=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		c[i]=i;
	}
	zs(c,n);
	for(int i=1;i<n+1;i++){
		if(c[i]){
			d[cnt]=i;
			cnt++;
		}
	}
	int y=0;
	for(int i=0;i<cnt;i++){
		if(d[i+1]-d[i]==2){
			y++;
		}
	}	
	printf("%d",y);
	return 0;
}
