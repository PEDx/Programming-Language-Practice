#include<stdio.h>
typedef struct stu{
	char *name[2];
	char *num[2];
	/*
char* name[10]；  可以得到正确答案，而且不管输入多少位都可以正常输出 
                （这好像是定义了10个指针变量，以数组的形式存放）为什么呢  
					此处是定义了10个指针变量以数组的形式存放，并且每个指针指向的是一个char类型 
					
			原因；	[number]号中间表明了指针指向地址的大小是（number*8）字节，而本电脑中一个指针变量占用字节也是8个字节 
					我们在往name[x]中写“abcdef”时，实际上是在往指针变量中写入“abcdef”，而指针变量大小就是8个字节 
					那么*name[x]就是在取地址“abcdef”处的值
					此处值的类型就是char 
					如果程序中没有取地址，那么开始时char还是其他什么类型也就无所谓 
					
					                
char* name ；    这种就一直崩溃（只能读，不能往指向地址的地方写东西，不然会崩溃） 
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
