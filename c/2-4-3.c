#include<stdio.h>
#include<stdlib.h>

typedef struct _num{
	int count;
	struct _num * next;
	struct _num * prev;//previous
}Num;

typedef struct _list{
	Num *head;
	Num *tail;
}List;

void func(){
	printf("hello,world");
}
Num* add(List* pList,int number);

int main()
{
	func();
	List list;
	list.tail=NULL;
	list.head=NULL;
	int number;
	do{
		scanf("%s",&number);
		if(number!=-1){
			//add to link-list
			list.tail=add(&list,number);
		}
	}while(number!=-1);
	Num *p;
	for(p=list.tail;p;p=p->prev){
		printf("%s ",p->count);
	}
	return 0;
}
Num* add(List* pList,int number){
	Num * p=(Num*)malloc(sizeof(Num));
	(*p).count=number;
	p->next=NULL;
	p->prev=NULL;
	//find the last
	Num*last=pList->head;
	if(last){
//			while(last->next){
//			last=last->next;
//			}
			last=pList->tail;	
			//attach
			last->next=p;
			p->prev=last;
	}else {
	pList->head=p;
	}
	pList->tail=p;
	return p;	
}
