#include<stdio.h>
typedef struct stu{
	char *name[2];
	char *num[2];
	/*
char* name[10]��  ���Եõ���ȷ�𰸣����Ҳ����������λ������������� 
                ��������Ƕ�����10��ָ����������������ʽ��ţ�Ϊʲô��  
					�˴��Ƕ�����10��ָ��������������ʽ��ţ�����ÿ��ָ��ָ�����һ��char���� 
					
			ԭ��	[number]���м������ָ��ָ���ַ�Ĵ�С�ǣ�number*8���ֽڣ�����������һ��ָ�����ռ���ֽ�Ҳ��8���ֽ� 
					��������name[x]��д��abcdef��ʱ��ʵ����������ָ�������д�롰abcdef������ָ�������С����8���ֽ� 
					��ô*name[x]������ȡ��ַ��abcdef������ֵ
					�˴�ֵ�����;���char 
					���������û��ȡ��ַ����ô��ʼʱchar��������ʲô����Ҳ������ν 
					
					                
char* name ��    ���־�һֱ������ֻ�ܶ���������ָ���ַ�ĵط�д��������Ȼ������� 
char  name[11]�� ���Դ��10���ַ���ɵ��ַ���
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
