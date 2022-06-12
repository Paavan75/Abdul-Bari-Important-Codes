#include<iostream>
#include<math.h>
using namespace std;

struct Node{
	int coeff;
	int exp;
	struct Node *next; 
}*poly=NULL;

void create(){
	struct Node *t,*last;
	int num,i;
	cout<<"Number of terms";
	cin>>num;
	cout<<"Enter coeff and exp";
	for(i=0;i<num;i++){
		t=(struct Node *)malloc(sizeof(struct Node));
		cin>>t->coeff>>t->exp;
		t->next=NULL;
		if(poly==NULL){
			poly=last=t;
		}
		else{
			last->next=t;
			last=t;
		}
	}
}

void Display(struct Node *p){
	while(p){
		cout<<p->coeff<<"*"<<p->exp<<" + ";
		p=p->next;
	}
}

long Eval(struct Node *p,int x){
	long sum=0;
	while(p){
		sum+=p->coeff*(pow(x,p->exp));
		p=p->next;
	}
	return sum;
}

int main(){

	create();
	Display(poly);
	cout<<Eval(poly,1);

	return 0;
}