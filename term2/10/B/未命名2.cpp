#include <stdio.h>
#include <stdlib.h>
#define MAXN 33808
struct people{
	int no;
	people *next;
};
people ans[MAXN];
int main(){
	int i,j,k,l,n;
	people *head,*p,*q,*tail,*temp;
	
	head=(people*)malloc(sizeof(people));
	head->no=2;
	p=head;
	for(i=1;i<MAXN;++i){
		p->next=(people*)malloc(sizeof(people));
		p=p->next;
		p->no=i+2;
	}
	p->next=p;
	tail=p;
	p=head;
	for(i=1;i<=3000;++i){
		q=p;
		k=0;
		while(true){
			for(j=0;j<p->no-1;++j){
				q=q->next;
			}
			temp=q->next;
			if(q==temp){
				goto tag;
			}
			q->next=temp->next;
			free(temp);
		}
		tag:;
		p=p->next;
	}
	re:;
	scanf("%d",&n);
	if(n==0){
		return 0;
	}
	p=head;
	for(i=1;i<n;++i){
		p=p->next;
	}
	printf("%d\n",p->no);
	goto re;
}
