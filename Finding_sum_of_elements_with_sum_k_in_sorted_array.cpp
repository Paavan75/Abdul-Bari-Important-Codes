#include<iostream>
using namespace std;

int main(){

    int A[10]={1,3,4,5,6,7,9,11,13,15};
    int sum=11,i=0,j=9,count=0;
    
    while(i<j){
        if(A[i]+A[j]>sum){
            j--;
        }
        else if(A[i]+A[j]<sum){
            i++;
        }
        else{
            cout<<A[i]<<" "<<A[j]<<" "<<sum<<endl;
            i++;
            j--;
        }
    }

    return 0;
}