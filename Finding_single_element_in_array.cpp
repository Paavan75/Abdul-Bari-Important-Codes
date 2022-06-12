#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){
    
    int A[10],i,sum=0,s=0,n,store=0;
    cout<<"number of Elements"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    for(i=0;i<n;i++){
        sum+=A[i];
    }
    store=n;
    store++;
    s=(store*(store+1))/2;
    cout<<"Missing number is "<<s-sum;

    return 0;
}
