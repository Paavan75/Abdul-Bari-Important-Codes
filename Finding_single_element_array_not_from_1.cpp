#include<iostream>
using namespace std;

int main(){
    
    int A[10],i,diff=0,s=0,n,store=0;
    cout<<"number of Elements"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    diff=A[0];
    for(i=0;i<n;i++){
        if(A[i]-i!=diff){
            cout<<"Missing "<<i+diff;
            break;
        }
    }

    return 0;
}
