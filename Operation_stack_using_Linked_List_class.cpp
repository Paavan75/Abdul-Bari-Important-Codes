#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Stack{
    private:
    Node *top;

    public:
    Stack(){
        top=NULL;
    }
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x){
    Node *t=new Node;
    if(t==NULL){
        cout<<"Stack Overflow";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop(){
    int x=-1;
    struct Node *p=top;
    if(top==NULL){
        cout<<"Stack Underflow";
    }
    else{
        top=top->next;
        x=p->data;
        delete p;
    }
    return x;
}

void Stack::Display(){
    struct Node *p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();

    cout<<st.pop();

    return 0;
}