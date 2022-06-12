#include<iostream>
using namespace std;

int main(){

    char A[]="Paavan";
    char B[6],temp;
    int i,j;

    for(j=0;A[j]!='\0';j++){
    }

    for(j=j-1,i=0;i<j;i++,j--){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }

    cout<<A;

    return 0;
}