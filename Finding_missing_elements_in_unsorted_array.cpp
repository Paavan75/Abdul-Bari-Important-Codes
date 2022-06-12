#include<iostream>
using namespace std;

int main(){

    int i;
    int A[10]={3,7,4,9,12,6,1,11,2,10};
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

    int H[12]={0};

    for(i=0;i<10;i++){
        H[A[i]]++;
    }
    for(i=min;i<=max;i++){
        if(H[i]==0){
            cout<<"Missing "<<i<<endl;
        }
    }


    return 0;
}