#include<iostream>
using namespace std;

int main(){

    char A[]="Paint";
    char B[]="Painter";
    int i,j;
    int count=1;

    for(i=0,j=0;A[i]!='\0' || B[j]!='\0';i++,j++){
        if(A[i]!=B[j]){
            if(A[i]>B[j]){
            count=2;
            break;
            }
            else{
            count=0;
            break;
            }
        }
        else{
            count=1;
        }
    }
    if(count==1){
        cout<<"Equal";
    }
    else if(count==0){
        cout<<"Smaller";
    }
    else{
        cout<<"Greater";
    }

    return 0;
}