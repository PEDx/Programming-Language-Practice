#include<stdio.h>
#include<stdlib.h>
int Maxsub(int a[],int b){
	int indexNum,maxNum;
	int i;
	indexNum=maxNum=0;
	for(i=0;i<b;i++){
		indexNum+=a[i];
		if(indexNum>maxNum){
			maxNum=indexNum;
		}
		else if(indexNum<0){
			indexNum=0;
		}
	}
	return maxNum;
}
int main(){
	int cnt=0;
	scanf("%d",&cnt);
	int* num=(int*)malloc(sizeof(int)*cnt);
	for (int  i = 0; i < cnt; i++) {
		scanf("%d",&num[i]);
	}
	int result=Maxsub(num,cnt);
	if(result<0){
		result=0;
		printf("%d",result);
	}else printf("%d",result );	
	return 0;
}
