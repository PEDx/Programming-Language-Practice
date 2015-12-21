#include<stdio.h>
typedef struct stu{
	char name[11];
	char num[11];
	/*
嗯，只要把两处判断语句删掉就可以

新问题是关于定义的结构成员char name[11]三种形式 三种情况的问题

char* name[10]；  可以得到正确答案，而且不管输入多少位都可以正常输出 
                （这好像是定义了10个指针变量，以数组的形式存放）为什么呢                     
char* name ；    这种就一直崩溃
char  name[11]； 可以存放10个字符组成的字符串
	*/
	int gra;
}Stu;
void maxormin(Stu n[],int x);
int main()
{
	int x=0;
	scanf("%d",&x);
	Stu xs[100];
	for(int i=0;i<x;i++){
		scanf("%s %s %d",&xs[i].name,&xs[i].num,&xs[i].gra);
	}
	maxormin(xs,x);
return 0;		
}
void maxormin(Stu n[],int x){
	int max=0;
	int min=100;
	int cnt1=0;
	int cnt2=0;
	for(int i=0;i<x;i++){
		int p=n[i].gra;
		if(p>max){
			max=p;
			cnt1=i;
		}	
		if(p<min){
			min=p;
			cnt2=i;
		}
	}	
		printf("%s %s\n",n[cnt1].name,n[cnt1].num);
		printf("%s %s",n[cnt2].name,n[cnt2].num);
}
/*
5
aa 123456 0
bb 234567 100
cc 456789 28
dd 567890 92
ee 789456 1
3
aa 123456 90
bb 234567 10
cc 456789 29
2
aa 123456 9
bb 234567 10
*/
