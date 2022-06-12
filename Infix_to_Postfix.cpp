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

int pre(char exp){
    if(exp=='+' || exp=='-'){
        return 1;
    }
    else if(exp=='*' || exp=='/'){
        return 2;
    }
    return 0;
}

int isOperand(char exp){
    if(exp=='+' || exp=='-' || exp=='*' || exp=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

char *InfixtoPostfix(char *infix){
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+1)*sizeof(char));
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i])>pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){

    char *infix="((a+b)*(c-d)))";
    push('#');

    char *postfix=InfixtoPostfix(infix);
    cout<<postfix;

    return 0;
}