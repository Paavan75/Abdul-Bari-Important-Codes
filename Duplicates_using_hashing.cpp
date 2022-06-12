#include<iostream>
using namespace std;

int main(){

    int i;
    int A[10]={3,5,8,8,8,8,13,13,13,20};
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
        H[A[i]]++;
    }
    
    for(i=min;i<max;i++){
        if(H[i]>1){
            cout<<"Duplicates: "<<H[i]<<endl;
        }
    }


    return 0;
}