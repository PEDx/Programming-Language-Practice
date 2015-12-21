#include<stdio.h>
#include<string.h>
int main()
{
	int maxlong=10000;
	char a[maxlong];
	char b[maxlong];
	gets(a);
	gets(b);
	char *d2=strstr(b,a);
	if(d2!=NULL){
		for(int i=0;i<strlen(b)+1;i++){
			if((b+i)==d2){
				printf("%d ",i);
			}	
		}
		for(int i=0;i<strlen(b);i++){
			char *e=strstr(d2+1,a);
			if(e!=NULL){
				d2=e;
				for(int i=0;i<strlen(b)+1;i++){
					if((b+i)==d2){
						printf("%d ",i);
					}
				}
			}	
		}
	}else printf("-1");
	return 0;	
}
