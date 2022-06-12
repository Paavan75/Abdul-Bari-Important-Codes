#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Matrix{
    int *A;
    int n;
};

void set(struct Matrix *m,int i,int j,int x){

    if(i>=j)
    m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
    
}

int Get(struct Matrix m,int i,int j){
    if(i>=j){
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    }
    else {
        return 0;
    }
}

void Display(struct Matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i>=j){
                cout<<m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
            }
            else 
                cout<<0;
        }
        cout<<"\n";
    }
}
    
int main(){

    struct Matrix m;
    m.n=3;
    m.A=(int *)malloc((m.n*(m.n+1)/2)*sizeof(int));
    set(&m,1,1,4);
    set(&m,2,1,5);
    set(&m,2,2,6);
    set(&m,3,1,7);
    set(&m,3,2,8);
    set(&m,3,3,4);
    Display(m);
    cout<<Get(m,2,1);
    return 0;
}