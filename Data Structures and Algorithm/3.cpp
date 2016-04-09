#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode{
  int coef;
  int expon;
  Polynomial link;
};
void Attach(int c,int e,Polynomial *pRear){//因为参数传递为值传递，因此此处要传入指向Polynomial（本来也是指向结构体PolyNode的指针）类型的指针
  Polynomial P;
  P=(Polynomial)malloc(sizeof(struct PolyNode));
  P->coef=c;
  P->expon=e;
  P->link=NULL;
  (*pRear)->link=P;
  *pRear=P;//我们必须修改指针指向的值，而不是直接修改指针或者参数，这样才能改变预期要改变的值；
}
Polynomial ReadPoly(){
  Polynomial P,Rear,t;
  int c,e,N;
  scanf("%d",&N);
  P=(Polynomial)malloc(sizeof(struct PolyNode));
  P->link=NULL;
  Rear=P;
  while(N--){
    scanf("%d %d",&c,&e);
    Attach(c,e,&Rear);
  }
  t=P;
  P=P->link;
  free(t);
  return P;
}
Polynomial Add(Polynomial P1,Polynomial P2){
  Polynomial P,Rear,t,t1,t2;
  int sum;
  t1=P1;
  t2=P2;
  P=(Polynomial)malloc(sizeof(struct PolyNode));
  P->link=NULL;
  Rear=P;
  while(t1&&t2){
    if(t1->expon==t2->expon){
      // Polynomial P;
      // P=(Polynomial)malloc(sizeof(struct PolyNode));
      // P->coef=t1->coef+t2->coef;
      // P->expon=t1->expon;
      // P->link=NULL;
      // Rear->link=P;
      // Rear=P;
      sum=t1->coef+t2->coef;
      if(sum) Attach(sum,t1->expon,&Rear);
      t1=t1->link;
      t2=t2->link;
    }
    else if(t1->expon>t2->expon){
      Attach(t1->coef,t1->expon,&Rear);
      t1=t1->link;
    }
    else{
      Attach(t2->coef,t2->expon,&Rear);
      t2=t2->link;
    }
  }
  while(t1){
    Attach(t1->coef,t1->expon,&Rear);
    t1=t1->link;
  }
  while(t2){
    Attach(t2->coef,t2->expon,&Rear);
    t2=t2->link;
  }
  t=P;
  P=P->link;
  free(t);
  return P;
}
Polynomial Mult(Polynomial P1,Polynomial P2){
  Polynomial P,Rear,t,t1,t2,f;
  int c,e;
  if(!(P1&&P2)) return NULL;
  t1=P1;
  t2=P2;
  P=(Polynomial)malloc(sizeof(struct PolyNode));
  P->link=NULL;
  Rear=P;
  while(t2){
    Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
    t2=t2->link;
  }
  t1=t1->link;
  while(t1){
    t2=P2;
    Rear=P;
    while(t2){
      c=t1->coef*t2->coef;
      e=t1->expon+t2->expon;
      while(Rear->link&&Rear->link->expon>e){
        Rear=Rear->link;
      }
      if(Rear->link&&Rear->link->expon==e){
        if(Rear->link->coef+c){
          Rear->link->coef+=c;
        }
        else{
          t=Rear->link;
          Rear->link=Rear->link->link;
          free(t);
        }
      }
      else{
          t=(Polynomial)malloc(sizeof(struct PolyNode));
          t->link=Rear->link;
          t->coef=c;
          t->expon=e;
          Rear->link=t;
          Rear=Rear->link;
      }
      t2=t2->link;
    }
    t1=t1->link;
  }
  t=P;
  P=P->link;
  free(t);
  return P;
}
void PrintPoly(Polynomial P){
  int flag=0;
  if(!P){
    printf("0 0");
    return ;
  } 
  while(P){
    if(!flag){
      flag=1;
    }else printf(" ");
    printf("%d %d",P->coef,P->expon);
    P=P->link;
  }
}
int main(){
  Polynomial P1,P2,PP,PS;
  P1=ReadPoly();
  P2=ReadPoly();
  PP=Mult(P1,P2);
  PrintPoly(PP);
  PS=Add(P1,P2);
  printf("\n");
  PrintPoly(PS);
  return 0;
}
