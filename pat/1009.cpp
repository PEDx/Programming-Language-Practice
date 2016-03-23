#include<stdio.h>
#include<string.h>
int main()
{
	int maxl=80;
	char a[maxl];
	char b[maxl][15];
	int wnum=0;
	int j=0;
	gets(a);
	int len=strlen(a);
	for(int i=0;i<=len;i++){
		if(a[i]==' '){
			b[wnum][j]='\0';
			j=0;
			wnum++; 
			i++;
		}
		b[wnum][j++]=a[i];
	}
	for(int i=wnum;i>=0;i--){
		printf("%s",b[i]);
		if(i!=0){
			printf(" ");
		}
	}
	return 0;
 } 

