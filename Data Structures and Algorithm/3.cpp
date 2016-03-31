#include<stdio.h>
#include<stdlib.h>
typedef struct Itm *List;
struct Itm{
  int coef;
  int expon;
};
void pro(List a,int cnt1,List b,int cnt2){
	List proList=(List)malloc(sizeof(struct Itm)*cnt1*cnt2);
	int k=0;
	for(int i=0;i<cnt2;i++){
		for(int j=0;j<cnt1;j++){
			proList[k].coef=b[i].coef*a[j].coef;
			proList[k].expon=b[i].expon+a[j].expon;
			k++;
		}
	}
	for(int i=0;i<k;i++){
		if(i!=k-1){
			printf("%d %d ",proList[i].coef,proList[i].expon);
		}else printf("%d %d\n",proList[i].coef,proList[i].expon);	
	}
}
int compare(int a,int b){
	if(a>b) return 1;
	else if(a==b) return 0;
	else if(a<b) return -1;
}
void add(List a,int cnt1,List b,int cnt2){
	List addList=(List)malloc(sizeof(struct Itm)*(cnt1+cnt2));
	int i=0;
	int j=0;
	int k;
	for(k=0;k<cnt1+cnt2&&j<cnt2;k++){
		switch (compare(a[i].expon,b[j].expon)){
			case 1:
				addList[k].coef=a[i].coef;
				addList[k].expon=a[i].expon;
				i++;
				break;
			case -1:
				addList[k].coef=b[j].coef;
				addList[k].expon=b[j].expon;
				j++;
				break;
			case 0:
				int sum=a[i].coef+b[j].coef;
				if(sum) addList[k].coef=sum;
				addList[k].expon=a[i].expon;
				i++;
				j++;
				break;	
		}	
	}
	for(;i<cnt1;i++){
		addList[k].coef=a[i].coef;
		addList[k].expon=a[i].expon;
		k++;
	}
	for(;j<cnt2;i++){
		addList[k].coef=b[j].coef;
		addList[k].expon=b[j].expon;
		k++;
	}		
	for(int i=0;i<k;i++){
		if(i!=0){
			printf(" %d %d",addList[i].coef,addList[i].expon);
		}else printf("%d %d",addList[i].coef,addList[i].expon);	
	}
}
int main(int argc, char const *argv[]) {
  int cnt1=0;
  int cnt2=0;
  scanf("%d",&cnt1);
  List itmList=(List)malloc(sizeof(struct Itm)*cnt1);
  for(int i=0;i<cnt1;i++){
    struct Itm L;
    scanf("%d %d",&L.coef,&L.expon);
    itmList[i]=L;
  }
  scanf("%d",&cnt2);
  List itmList2=(List)malloc(sizeof(struct Itm)*cnt2);
  for(int i=0;i<cnt2;i++){
    struct Itm L;
    scanf("%d %d",&L.coef,&L.expon);
    itmList2[i]=L;
  }
  pro(itmList,cnt1,itmList2,cnt2);
  add(itmList,cnt1,itmList2,cnt2);		
  return 0;
} 
