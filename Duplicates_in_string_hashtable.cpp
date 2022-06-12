#include<iostream>
using namespace std;

int main(){

    char A[]="finding";
    char c;
    int i,j,count=0;
    int H[26]={0};

    for(i=0;A[i]!='\0';i++){
        H[A[i]-97]++;
    }

    for(i=0;i<26;i++){
        if(H[i]>1){
            c=i+97;
            cout<<c<<" "<<H[i]<<endl;
        }
    }

    return 0;
}