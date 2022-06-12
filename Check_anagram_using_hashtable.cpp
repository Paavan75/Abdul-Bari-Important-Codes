#include<iostream>
using namespace std;

int main(){

    char A[]="medicll";
    char B[]="decimll";
    int H[26]={0},i,j,count=0;

    for(i=0;A[i]!='\0';i++){
        H[A[i]-97]++;
    }
    for(i=0;B[i]!='\0';i++){
        H[B[i]-97]--;
        if(H[B[i]-97]<0){
            cout<<"Not an anagram";
            break;
        }
    }

    for(i=0;i<26;i++){
        if(H[i]>0){
            count=0;
            break;
        }
        else{
            count=1;
        }
    }
    
    if(count==0){
        cout<<"Not an anagram";
    }
    else{
        cout<<"Strings are anagram";
    }

    return 0;
}