#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n){

    int i;
    struct Node *t,*last;

    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    do{
        cout<<p->data;
        p=p->next;
    }while(p!=Head);
}

void RDisplay(struct Node *p){
    static int flag=0;
    if(p!=Head || flag==0){
        flag=1;
        cout<<p->data;
        RDisplay(p->next);
    }
    flag=0;
}

int main(){

    int A[]={3,5,7,9};
    create(A,4);

    RDisplay(Head);

    return 0;
}