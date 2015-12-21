#include<stdio.h> 
int main()
 {
	int num=101;
	int a[100]={0};
	int b[100]={0};
	int m,n;
	int max1=0;
	int max2=0;
	scanf("%d",&max1);
	scanf("%d",&a[max1]);
	m=max1;
	while(m!=0){
		scanf("%d",&m);
		scanf("%d",&a[m]);
	}
//	if(m==0){
//		a[m+1]=a[0];
//	}
	scanf("%d",&max2);
	scanf("%d",&b[max2]);
	n=max2;
	while(n!=0){
		scanf("%d",&n);
		scanf("%d",&b[n]);
	}
	int k=0;
	if(max1>max2){
		int k=max1;
	}else k=max2;
	int ret;
	int kmax=k;
	for(k;k>=0;k--){
		if(k==kmax){ //如果为幂次最大的就表现为式子后有加号 
			ret=a[kmax]+b[kmax];
			printf("%dx%d",ret,kmax);
		}else {
		if(k==0){
			ret=a[0]+b[0];
			if(ret<0){
			printf("-%d");
			}else printf("+%d",ret);
		}
		if(a[k]+b[k]>0&&k>0){
				printf("+");
			if(k==1){//如果幂次为1则表达为x后没有数字
			if(a[k]!=0&&b!=0) {
				ret=a[k]+b[k];
				printf("%dx",ret);
			}
			if(a[k]!=0&&b[k]==0){
				ret=a[k];
				printf("%dx",ret);
			}else if(b[k]!=0&&a[k]==0){
				ret=b[k];
				printf("%dx",ret);
				}
			}else{
				if(a[k]!=0&&b[k]!=0) {
					ret=a[k]+b[k];
				printf("%dx%d",ret,k);
				}
				if(a[k]!=0&&b[k]==0){
					ret=a[k];
					printf("%dx%d",ret,k);
				}else if(b[k]!=0&&a[k]==0){
					ret=b[k];
					printf("%dx%d",ret,k);
				}	
			}	
		}
	}
		if(a[k]+b[k]==0){
			printf("");
		}
		if(a[k]+b[k]<0&&k>0)
		{
			if(k==1){
				if(a[k]!=0&&b!=0) {
					ret=a[k]+b[k];
					printf("%dx",ret);
				}
			if(a[k]!=0&&b[k]==0){
				ret=a[k];
				printf("%dx",ret);
			}else if(b[k]!=0&&a[k]==0){
				ret=b[k];
				printf("%dx",ret);
				}
			}else{
				if(a[k]!=0&&b!=0) {
					ret=a[k]+b[k];
					printf("%dx%d",ret,k);
				}
				if(a[k]!=0&&b[k]==0){
						ret=a[k];
						printf("%dx%d",ret,k);
					}else if(b[k]!=0&&a[k]==0){
						ret=b[k];
						printf("%dx%d",ret,k);
					}
				}
			}
		}
	return 0;		
} 
