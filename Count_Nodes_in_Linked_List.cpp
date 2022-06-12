#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

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

int main(){

    int A[]={3,5,7,9};
    create(A,4);
    cout<<Rcount(first);
    
    return 0;
}