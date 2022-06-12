#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        cout<<"Queue is full";
    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    struct Node *t;
    if(front==NULL){
        cout<<"Queue is empty";
    }
    else{
        x=front->data;
        t=front;
        front=front->next;
        free(front);
    }
    return x;
}

void Display(){
    struct Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    Display();
    
    return 0;
}