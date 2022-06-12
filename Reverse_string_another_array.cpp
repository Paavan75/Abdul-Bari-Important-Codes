#include<iostream>
using namespace std;

int main(){

    char A[]="Paavan";
    char B[6],temp;
    int i,j;

    for(j=0;A[j]!='\0';j++){
    }

    for(i=0,j=j-1;j>=0;j--,i++){
        B[i]=A[j];
    }
    B[i]='\0';

    cout<<B;

    return 0;
}