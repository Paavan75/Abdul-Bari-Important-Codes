#include<iostream>
using namespace std;

int main(){

    int A[10]={3,6,1,2,9,6,3,6,9,5};
    int i,j,count=0;
    for(i=0;i<9;i++){
        count=1;
        if(A[i]!=-1){
            for(j=i+1;j<10;j++){
                if(A[i]==A[j]){
                    count++;
                    A[j]=-1;
                }
            }
            if(count>1){
                cout<<A[i]<<count<<endl;
            }
        }
    }


    return 0;
}