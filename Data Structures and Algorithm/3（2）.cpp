#include<stdio.h>
#include<stdlib.h>
typedef struct Itm *List;
struct Itm{
  int coef;
  int expon;
};
List Readf(int cnt){
  	List itmList=(List)malloc(sizeof(struct Itm)*cnt);
  	for(int i=0;i<cnt;i++){
	    struct Itm L;
	    scanf("%d %d",&L.coef,&L.expon);
	    itmList[i]=L;
  	}
  	return itmList;
}
void Writef(List a,int k){
  	for(int i=0;i<k;i++){
		if(i!=0){
			printf(" %d %d",a[i].coef,a[i].expon);
		}else printf("%d %d",a[i].coef,a[i].expon);	
	}
}
void pro(List a,int cnt1,List b,int cnt2){
	List proList=(List)malloc(sizeof(struct Itm)*cnt1*cnt2);
	int k=0;
	int c,e;
	for(int i=0;i<cnt2;i++){
		if(i==0){
			for(int j=0;j<cnt1;j++){
				proList[k].coef=b[i].coef*a[j].coef;
				proList[k].expon=b[i].expon+a[j].expon;
				k++;
			}
		}else{
			for(int j=0;j<cnt1;j++){
				int flag=0;
				c=b[i].coef*a[j].coef;
				e=b[i].expon+a[j].expon;
				for(int m=0;m<k;m++){
					if(proList[m].expon==e){
						proList[m].coef+=c;
						flag++;
					}
				}
				if(flag==0){
					proList[k].coef=c;
					proList[k].expon=e;
					k++;
				}
			}
		}
	}
	Writef(proList,k);
	printf("\n");
}
int compare(int a,int b){
	if(a>b) return 1;
	else if(a==b) return 0;
	else return -1;
}
void add(List a,int cnt1,List b,int cnt2){
	List addList=(List)malloc(sizeof(struct Itm)*(cnt1+cnt2));
	int i=0;
	int j=0;
	int cnt=0;
	int k=0;
	int sum;
	if(cnt1>cnt2) {
		cnt=cnt1; 
	}else cnt=cnt2;
	for(k=0;k<cnt1+cnt2&&j<cnt;k++){
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
				sum=a[i].coef+b[j].coef;
				if(sum) addList[k].coef=sum;
				addList[k].expon=a[i].expon;
				i++;
				j++;
				break;	
		}	
	}
	for(;i<cnt1;i++){
		addList[k-1].coef=a[i].coef;
		addList[k-1].expon=a[i].expon;
		k++;
	}
	for(;j<cnt2;j++){
		addList[k-1].coef=b[j].coef;
		addList[k-1].expon=b[j].expon;
		k++;
	}
	Writef(addList,k-1);		
}
int main(int argc, char const *argv[]) {
  int cnt1=0;
  int cnt2=0;
  scanf("%d",&cnt1);
  List itmList1=Readf(cnt1);
  scanf("%d",&cnt2);
  List itmList2=Readf(cnt2);
  pro(itmList1,cnt1,itmList2,cnt2);
  add(itmList1,cnt1,itmList2,cnt2);		
  return 0;
} 

