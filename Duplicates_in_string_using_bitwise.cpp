#include<iostream>
using namespace std;

int main(){

    char A[]="finding";
    int i,j,count=0;
    int H=0,x=0;
    
    for(i=0;A[i]!='\0';i++){

        x=1;
        x=x<<(A[i]-97);
        if((x&H)>0){
            cout<<A[i]<<" Duplicate"<<endl;
        }
        else{
            H=(x|H);
        }

    }

    return 0;
}