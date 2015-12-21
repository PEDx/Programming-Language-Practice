
#include<stdio.h>
#include<string.h>
int main()
{	
	int mag=15;
	char string[mag]; 
	int c=0;
	int d=0;
	int count[mag];	
	while(c==0){
		scanf("%s",string);
		for(int i=0;i<mag;i++){ //此循环用于判断输入单词结尾
							    //是否是'.' 
		int t=string[i];
		if(t==46){ 
			int n=strlen(string)-1;
			c++;
			}
		}
		int n=strlen(string);//此处用于测量每个输入单词的长度
							 //并将长度传入一个数组 
		count[d]=n;
		d++;	
		if(c!=0){         //如果上面判断为末尾单词则将长度减一 
			n=strlen(string)-1;
			count[d]=n;
		}
	}
	int p=d;	
		for(int i=0;i<p-1;i++){ //遍历数组将前p-1项打印出且后面
								//有空格 
			int n=count[i];
			printf("%d ",n);
		}	
		int m=count[p];			//打印最后一项没有kongge 
		printf("%d",m);
return 0;
}
