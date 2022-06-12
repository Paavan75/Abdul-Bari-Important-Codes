#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){

    int i;
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p){
        cout<<p->data;
        p=p->next;
    }
}

void RDisplay(struct Node *p){
    static int flag=0;
    if(p!=first || flag==0){
        flag=1;
        cout<<p->data;
        RDisplay(p->next);
    }
    flag=0;
}

int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;

    if(index<0 || index>Length(p)){
        return;
    }
    if(index==0){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}

int Delete(struct Node *p,int index){
    int i,x;
    if(index<0 || index>Length(p)){
        return -1;
    }
    if(index==1){
        first=first->next;
        if(first){
            first->prev=NULL;
        }
        x=p->data;
        free(p);
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}

int main(){

    int A[]={3,5,7,9};
    create(A,4);
    Reverse(first);
    Display(first);

    return 0;
}