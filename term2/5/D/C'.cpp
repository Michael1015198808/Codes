#include <stdio.h>
#include <stdlib.h>

#define test printf("Hi\n");

struct node{
	char name[16];
	node* pre;
	node* next;
};
int main(){
	int n,w,s,i;
	scanf("%d",&n);
	node* first=NULL;
	node* last=NULL;
	node* temp=NULL,*p=NULL;
	for(i=0;i<n;++i){
		if(first==NULL){
			first=(node*)malloc(sizeof(node));
			last=first;
			first->pre=first;
			first->next=first;
		}else{
			last->next=(node*)malloc(sizeof(node));
			last->next->pre=last;
			last=last->next;
			last->next=first;
			first->pre=last;
		}
		scanf("%s",last->name);
	}
	scanf("%d,%d",&w,&s);
	temp=first;
	while(--w){
		temp=temp->next;
	}
	while(temp->next!=temp){
		for(i=1;i<s;++i){
			temp=temp->next;
		}
		printf("%s\n",temp->name);
		temp->pre->next=temp->next;
		temp->next->pre=temp->pre;
		p=temp;
		temp=temp->next;
		free(p);
	}
	printf("%s",temp->name);
}

