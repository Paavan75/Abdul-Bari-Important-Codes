#include<iostream>
#include<string.h>
using namespace std;

class LowerTri{
    private:
    int *A;
    int n;

    public:
    LowerTri(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~LowerTri(){
        delete []A;
    }
};

void LowerTri :: set(int i,int j,int x){
    if(i>=j){
        A[i*(i-1)/2+j-1]=x;
    }
}

int LowerTri :: Get(int i,int j){
    if(i>=j){
        return A[i*(i-1)/2+j-1];
    }
    else{
        return 0;
    }
}

void LowerTri :: Display(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i>=j){
                cout<<A[i*(i-1)/2+j-1];
            }
            else 
                cout<<0;
        }
        cout<<"\n";
    }
}
    
int main(){

    LowerTri m(4);
    m.set(1,1,4);
    m.set(2,1,4);
    m.set(2,2,7);
    m.set(3,1,4);
    m.set(3,2,5);
    m.set(3,3,9);
    m.set(4,1,6);
    m.set(4,2,4);
    m.set(4,3,7);
    m.set(4,4,4);
    m.Get(2,2);
    m.Display();
    return 0;
}