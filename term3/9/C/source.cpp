#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;
int win[1001][1001];
struct node{
				int no;
				node* next;
};
int main(){
	int i,j,k,n;
	scanf("%d",&n);
	printf("%d\n",n);
	rep(i,0,n){
					rep(j,0,n){
									scanf("%d",&win[i][j]);
					}
	}
	node* head=new node;
	node* tail=new node;
	if(win[0][1]){
					head->no=0;
	}else{
					head->no=1;
	}
	head->next=tail;
	tail->no=1-(head->no);
	rep(i,2,n){
					if(win[i][head->no]){
									node* temp=new node;
									temp->no=i;
									temp->next=head;
									head=temp;
					}else if(win[tail->no][i]){
									node* temp=new node;
									temp->no=i;
									tail->next=temp;
									tail=temp;
					}else{
									node *temp=head,*before;
									while(win[temp->no][i]){
													before=temp;
													temp=temp->next;
									}
									before->next=new node;
									before->next->no=i;
									before->next->next=temp;
					}
	}
	rep(i,0,n){
					printf("%d ",head->no+1);
					head=head->next;
	}
	puts("-1");
	return 0;
}

