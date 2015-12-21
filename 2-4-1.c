//link function
#include<stdio.h>
#include<stdlib.h>
typedef struct _num{
	int count;
	struct _num * next;
}Num;
typedef struct _list{
	Num *head;
}List;
void add(List* pList,int number);
int main()
{
	List list;
	list.head=NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number!=-1){
			//add to link-list
			add(&list,number);
		}
	}while(number!=-1);
	return 0;
}
void add(List* pList,int number){
	Num * p=(Num*)malloc(sizeof(Num));
	p->count=number;
	p->next=NULL;
	//find the last
	Num*last=pList->head;
	if(last){
			while(last->next){
			last=last->next;
			}
			//attach
			last->next=p;
	}else {
	pList->head=p;
	}
}
