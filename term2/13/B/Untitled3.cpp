#include <stdio.h>
#include <iostream>

//OOPÕæ°ô£¡£¨¼Ù»°£© 
class node{
public:
	int key;
	node *left,*right,*p;
	node(int i):key(i),left(NULL),right(NULL),p(NULL){}
	void add(int);
	void trans(node*);
	node* search(int);
	node* mini(void);
	void del(void);
	void inorder(void);
	void preorder(void);
	void postorder(void);
	friend std::ostream& operator<<(std::ostream&,node&);
};
node* root=NULL;
int main(){
	long n=5,v;
	char c;
	node *p;
	scanf("%ld",&n);
	while(n--){
		while(c=getchar()){
			if(c=='A'||c=='D'){
				break;
			}
		}
		scanf("%ld",&v);
		if(c=='A'){
			if(root!=NULL){
				root->add(v);
			}else{
				root=new node(v);
			}
		}else{
			root->search(v)->del();
		}
	}
	root->inorder();
	putchar('\n');
	root->preorder();
	putchar('\n');
	root->postorder(); 
	return 0;
}
void node::add(int j){
	if(j>key){
		if(right==NULL){
			right=new node(j);
			right->p=this;
		}else{
			right->add(j);
		}
	}else{
		if(left==NULL){
			left=new node(j);
			left->p=this;
		}else{
			left->add(j);
		}
	}
}
void node::trans(node* q){
	if(p==NULL){
		root=q;
	}else if(this==p->left){
		p->left=q;
	}else p->right=q;
	if(q!=NULL){
		q->p=p;
	}
}
node* node::search(int k){
	if(key>k){
		return left->search(k);
	}else if(key<k){
		return right->search(k);
	}else{
		return this;
	}
}
void node::del(void){
	if(left==NULL){
		this->trans(right);
	}else if(right==NULL){
		this->trans(left);
	}else{
		node *y=right->mini();
		if(y->p!=this){
			y->trans(y->right);
			y->right=right;
			y->right->p=y;
		}
		this->trans(y);
		y->left=left;
		y->left->p=y;
	}
	delete this;
}
node* node::mini(void){
	if(left!=NULL){
		return left->mini();
	}else{
		return this;
	}
}
void node::inorder(void){
	if(this!=NULL){
		left->inorder();
		std::cout<<(*this);
		right->inorder();
	}
}
void node::preorder(void){
	if(this!=NULL){
		std::cout<<(*this);
		left->preorder();
		right->preorder();
	}
}
void node::postorder(void){
	if(this!=NULL){
		left->postorder();
		right->postorder();
		std::cout<<(*this);
	}
}
std::ostream& operator<<(std::ostream& os,node& p){
	return os<<p.key<<' ';
}

