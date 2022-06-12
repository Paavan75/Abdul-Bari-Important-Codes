#include<iostream>
using namespace std;

int main(){

    char A[]="ma44am";
    int i=0,j;
    int count=0;

    for(j=0;A[j]!='\0';j++){}

    j--;

    while(i<j){
        if(A[i]!=A[j]){
            cout<<"Not a palindrome";
            break;
        }
        else{
            count=1;
        }
        i++;
        j--;
    }

    if(count==1){
        cout<<"Palindrome";
    }

    return 0;
}