#include<iostream>
#include<string.h>
using namespace std;

int main(){

    char A[]="medical";
    char B[]="decimal";
    int i,j,count=0;
    int len1=strlen(A);
    int len2=strlen(B);
    
    if(len1==len2){
        for(i=0;i<len1;i++){
            count=0;
            for(j=0;j<len2;j++){
                if(A[i]==B[j]){
                    count=1;
                    break;
                }
            }
            if(count==0){
                cout<<"Not an anagram";
                break;
            }
        }
    }
    if(count==1){
        cout<<"Strings are anagram";
    }
    

    return 0;
}