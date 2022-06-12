#include<iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
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

char pop(){
    char x=-1;
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

int isBalanced(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            if(top==NULL){
                return 0;
            }
            pop();
        }
    }
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    char *exp="((a+b)*(c-d)))";

    cout<<isBalanced(exp);

    return 0;
}