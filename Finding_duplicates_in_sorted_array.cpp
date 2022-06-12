#include<iostream>
using namespace std;

int main(){

    int A[10]={3,5,5,7,9,9,11,11,11,11};
    int lastDuplicate=0,i,CurrentDuplicate=0;

    for(i=0;i<10;i++){
        if(A[i]==A[i+1]){
            CurrentDuplicate=A[i];
            if(CurrentDuplicate!=lastDuplicate){
                cout<<A[i]<<endl;
                lastDuplicate=CurrentDuplicate;
            }
        }
    }


    return 0;
}