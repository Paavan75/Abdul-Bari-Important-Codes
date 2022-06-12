#include<iostream>
using namespace std;

int main(){

    int A[10]={3,5,1,2,7,8,13,15,17,9};
    int sum=10,i,j,count=0;
    
    for(i=0;i<9;i++){
        for(j=i+1;j<10;j++){
            if(A[i]+A[j]==sum){
                cout<<A[i]<<" "<<A[j]<<" "<<sum<<endl;
            }
        }
    }

    return 0;
}