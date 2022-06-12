#include<iostream>
using namespace std;

int main(){

    char A[]="Finding";
    int i,j,count=0;

    for(i=0;i<5;i++){
        count=1;
        if(A[i]!=0){
            for(j=i+1;j<6;j++){
                if(A[i]==A[j]){
                    count++;
                    A[j]=0;
                }
            }
            if(count>1){
                cout<<A[i]<<" "<<count<<endl;
            }
        }
    }

    return 0;
}