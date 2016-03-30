#include<stdio.h>
#include<stdlib.h>
int* Maxsub(int* a,int b){
	int indexNum,maxNum;
	int i,c;
	int numList[b];
	indexNum=maxNum=0;
	for(i=0,c=0;i<b;i++){
		indexNum+=a[i];
		if(indexNum>maxNum){
			maxNum=indexNum;
			numList[c]=a[i];
			c++;
		}
		else if(indexNum<0){
			indexNum=0;
		}
	}
	numList[c]=maxNum;
	if(numList[c]==0){
		printf("%d %d %d",numList[c],a[0],a[b-1]);
	}else printf("%d %d %d",numList[c],numList[0],numList[c-1]);
}
int main(){
	int cnt=0;
	scanf("%d",&cnt);
	int* num=(int*)malloc(sizeof(int)*cnt);
	for (int  i = 0; i < cnt; i++) {
		scanf("%d",&num[i]);
	}
	Maxsub(num,cnt);
	return 0;
}
