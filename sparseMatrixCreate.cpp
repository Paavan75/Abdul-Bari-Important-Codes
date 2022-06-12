#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s){
    printf("Enter dimensions");
    scanf("%d%d" , &s->m,&s->n);
    printf("Enter num");
    scanf("%d" , &s->num);

    s->ele = (struct Element *)malloc(s->num*sizeof(struct Element));

    printf("Enter elements");
    for(int k=0;k<s->num;k++){
        scanf("%d%d%d" , &s->ele[k].i,&s->ele[k].j,&s->ele[k].x);
    }
}

void display(struct Sparse s){

    int i,j,k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                printf("%d" , s.ele[k++].x);
            } 
            else{
                printf("0");
            }
        }
        printf("\n");
    }
}

    
int main(){

    struct Sparse s;
    create(&s);
    display(s);

    return 0;
}