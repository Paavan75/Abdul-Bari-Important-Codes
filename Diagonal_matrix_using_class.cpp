#include<iostream>
#include<string.h>
using namespace std;

class Matrix{
    private:
    int *A;
    int n;

    public:
    Matrix(int n){
        this->n=n;
        A=new int[n];
    }
    void set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Matrix(){
        delete []A;
    }
};

void Matrix :: set(int i,int j,int x){
    if(i==j){
        A[i-1]=x;
    }
}

int Matrix :: Get(int i,int j){
    if(i==j){
        return A[i-1];
    }
    else{
        return 0;
    }
}

void Matrix :: Display(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                cout<<A[i];
            }
            else 
                cout<<0;
        }
        cout<<"\n";
    }
}
    
int main(){

    Matrix m(4);
    m.set(1,1,4);
    m.set(2,2,7);
    m.set(3,3,9);
    m.set(4,4,1);
    m.Get(2,2);
    m.Display();
    return 0;
}