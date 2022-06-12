#include<iostream>
#include<string.h>
using namespace std;

struct Matrix{
    int A[10];
    int n;
};

void set(struct Matrix *m,int i,int j,int x){
    if(i==j){
        m->A[i-1]=x;
    }
}

int Get(struct Matrix m,int i,int j){
    if(i==j){
        return m.A[i-1];
    }
    else{
        return 0;
    }
}

void Display(struct Matrix m){
    int i,j;
    for(i=0;i<m.n;i++){
        for(j=0;j<m.n;j++){
            if(i==j){
                cout<<m.A[i];
            }
            else 
                cout<<0;
        }
        cout<<"\n";
    }
}
    
int main(){

    struct Matrix m;
    m.n=4;
    set(&m,1,1,4);
    set(&m,2,2,7);
    set(&m,3,3,9);
    set(&m,4,4,1);
    Display(m);
    return 0;
}