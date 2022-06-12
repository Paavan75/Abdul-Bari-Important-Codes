#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        cout<<"Stack Overflow";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x=-1;
    struct Node *p=top;
    if(top==NULL){
        cout<<"Stack Underflow";
    }
    else{
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

void Display(){
    struct Node *p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){

    push(10);
    push(20);
    push(30);
    Display();

    cout<<pop();

    return 0;
}