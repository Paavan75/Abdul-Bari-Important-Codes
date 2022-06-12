#include<iostream>
using namespace std;

int main(){

    char A[]="ma44am";
    int i=0,j;
    int count=0;

    char B[6];

    for(j=0;A[j]!='\0';j++){
    }

    for(i=0,j=j-1;j>=0;j--,i++){
        B[i]=A[j];
    }
    B[i++]='\0';

    for(i=0;A[i]!='\0';i++){
        if(A[i]!=B[i]){
            cout<<"Not a palindrome";
            break;
        }
        else{
            count=1;
        }
    }
    if(count==1){
        cout<<"Palindrome";
    }

    return 0;
}