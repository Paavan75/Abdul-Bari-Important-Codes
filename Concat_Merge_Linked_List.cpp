#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){

    int i;
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[],int n){

    int i;
    struct Node *t,*last;

    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}

void Rdisplay(struct Node *p){
    if(p!=NULL){
        printf("%d",p->data);
        Rdisplay(p->next);
    }
}

int count(struct Node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int Rcount(struct Node *p){
    if(p!=NULL){
        return 1+(Rcount(p->next));
    }
    else{
        return 0;
    }
}

int sum(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int Rsum(struct Node *p){
    if(p){
        return (Rsum(p->next)+p->data);
    }
    else{
        return 0;
    }
}

int max(struct Node *p){
    int m=INT_MIN;
    while(p){
        if(p->data>m){
            m=p->data;
        }
        p=p->next;
    }
    return m;
}

int Rmax(struct Node *p){
    int x=0;
    if(p==0){
        return INT_MIN;
    }
    x=Rmax(p->next);
    if(p->data>x){
        return p->data;
    }
    else{
        return x;
    }
}

struct Node * LSearch(Node *p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

struct Node * RSearch(Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
    }
    return RSearch(p->next,key);
}

struct Node * LSearchFront(Node *p,int key){
    struct Node * q;

    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;

            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void Insert(struct Node *p,int index,int x){
    struct Node *t;

    if(index<0 || index>count(p)){
        return;
    }

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void sortedInsert(struct Node *p,int x){
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(first==p){
            t->next=first;
            first=t;
        }
        else{
            q->next=t->next;
            q->next=t;
        }
    }
}

int Delete(struct Node *p,int index){
    struct Node *q;
    int x=-1;
    if(index<0 || index>count(p)){
        return -1;
    }
    else if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            free(p);
        }
    }
    return x;
}

int CheckSorted(struct Node *p){
    int x=INT_MIN;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

void CheckDuplicates(struct Node *p){
    struct Node *q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void RevArr(struct Node *p){
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i--];
        q=q->next;
    }
}

void RevLinks(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void RevRecursion(struct Node *q,struct Node *p){
    if(p){
        RevRecursion(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}

void Concat(struct Node *p,struct Node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

void Merge(struct Node *p,struct Node *q){
    struct Node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL){
        last->next=p;
    }
    else{
        last->next=q;
    }
}

int main(){

    int A[]={3,5,7,9};
    create(A,4);

    int B[]={2,4,6,8};
    create2(B,4);
    
    Merge(first,second);
    display(third);

    return 0;
}