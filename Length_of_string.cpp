#include<iostream>
using namespace std;
int main(){

    int i;
    char s[]="Hello World";

    for(i=0;s[i]!='\0';i++){}

    cout<<"Length of string is: "<<i;

    return 0;
}