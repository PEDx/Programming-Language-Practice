//link-list
#include<stdio.h>
#include<stdlib.h>
typedef struct _num{
	int count;
	struct _num * next;
}Num;
int main()
{
	Num* head=NULL;
	int numble;
	do{
		scanf("%d",&numble);
		if(numble!=-1){
			//add to link-list
			Num * p=(Num*)malloc(sizeof(Num));
			p->count=numble;
			p->next=NULL;
			//find the last
			Num*last=head;
			if(last){
					while(last->next){
					last=last->next;
					}
					//attach
					last->next=p;
			}else {
				head=p;//此处的head是形参，改变head指针值后并不能对main函数的head起作用
				/*
				函数中只是改变函数的形参，而不是改变形参（指针）所指向的那个变量
				那么最后如果不返回形参值，而main函数又没有一个变量来接收这个值，那么这个函数调用就不会对main函数有作用  
				
				
				第一种解决方案是：声明一个全局变量Num* head
								那么在函数调用完后就会对main函数中的head起作用
								不过如果以后有更多的链表会不妥 
				第二种解决方法是：将head指针return回去 
								在add函数前必须有head来装这个返回值
				第三种解决方法是；将head指针的指针传入add函数
								最后再将p赋给*head（为指向head的指针）
								下一轮函数调用的是指向head的指针
								所指向的head已经被更改为了p
				第四种解决方法是； 创建一个结构体	typedef struct _list{ 
												 		Num *head；
												 	}List
									结构体中是一个Num的结构指针*head			 	
									在main函数中创建一个List list；
									将list.head初始化为NULL 
									再将指向list的地址（指针）传入到add函数里面去add（&list，number）； 
									那么我们在函数原型中add（List *list，number）传入的是一个指向List结构的结构指针变量*list
									而在add函数中改变的是list->head
									（将第三种方案的指向head指针的指针封装成了结构） 
									最后我们改变的是形参（指针）指向的那个*head，完成函数调用的效果 
				*/ 
			}
		}
	}while(numble!=-1);
	return 0;
}
