#include<iostream>
using namespace std;
int main(){

    char s[]="Hello World";
    int ccount=0,vcount=0,word=0;

    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            vcount++;
        }
        else if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)){
            ccount++;
        }
    }

    cout<<"Vowels:"<<vcount<<" Consonants:"<<ccount<<endl;

    for(int i=0;s[i]!='\0';i++){

        if(s[i]==' ' && s[i-1]!=' '){
            word++;
        }
    }
    cout<<"Words:"<<word+1;

    return 0;
}