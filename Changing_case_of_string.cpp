#include<iostream>
using namespace std;
int main(){

    char s[]="Hello World";

    for(int i=0;s[i]!='\0';i++){

        if(s[i]>=65 && s[i]<=90){
            s[i]+=32;
        }
        else if(s[i]>='a' && s[i]<='z'){
            s[i]-=32;
        }

    }
    
    cout<<s;

    return 0;
}