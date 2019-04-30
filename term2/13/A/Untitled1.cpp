#include <stdio.h>

class node{
public:
	char key;
	node *left,*right,*p;
	node(void):key('\0'),left(NULL),right(NULL),p(NULL){}
	node(char c,node* ptr):key(c),left(NULL),right(NULL),p(ptr){}
	void inorder(void){
		if(left!=NULL){
			left->inorder();
		}
		if(key!='#'){
			putchar(key);
		}
		if(right!=NULL){
			right->inorder();
		}
	}
};
int main(){
	node *root=NULL,*p=NULL,*q=NULL;
	int i,j,k,depth,tempdepth=0;
	char c;
	scanf("%d",&depth);
	while((c=getchar())=='\n');
	root=new node();
	p=root;
	p->key=c;
	++tempdepth;
	for(i=1;i<(1<<depth)-1;++i){
		c=getchar();
		q=new node(c,p);
		++tempdepth;
		if(p->left==NULL){
			p->left=q;
		}else{
			p->right=q;
		}
		if(tempdepth==depth){
			while(p->right!=NULL&&p->p!=NULL){
				p=p->p;
				--tempdepth;
			}
			--tempdepth;
		}else{
			p=q;
		}
	}
	root->inorder();
	return 0;
}

