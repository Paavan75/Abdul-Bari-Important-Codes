#include<iostream>
using namespace std;

int main(){

    int i,sum=10;
    int A[10]={3,5,1,2,7,8,10,15,0,9};
    int max=A[0];
    int min=A[0];
    for(i=1;i<10;i++){

        if(max<A[i]){
            max=A[i];
        }

    }

    for(i=1;i<10;i++){

        if(min>A[i]){
            min=A[i];
        }

    }

    int H[20]={0};


    for(i=0;i<10;i++){
        if(H[sum-A[i]]!=0 && (sum-A[i])>=0){
            cout<<A[i]<<" "<<sum-A[i]<<" "<<sum<<endl;
        }
        H[A[i]]++;
    }

    return 0;
}