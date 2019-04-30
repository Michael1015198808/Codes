#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::ostream;
//OOPÕæ°ô£¡£¨¼Ù»°£©
class node{
public:
	enum Color{black,red};
	Color color;
	int key;
	node *left,*right,*p;
	node(void);
	node(int i,enum Color c);
	void add(int);
	void fixup(void);
	void trans(node*);
	node* search(int,int&);
	node* mini(void);
	void del(void);
	void inorder(void);
	void preorder(void);
	void postorder(void);
	void left_rotate(void);
	void right_rotate(void);
	friend ostream& operator<<(ostream&,node&);
};
node* nil=new node();
node* root=nil;
int main(){
	int i,j,v;
	nil->color=node::black;
	scanf("%d%d",&i,&j);
	while(i--){
		scanf("%d",&v);
		if(root!=nil){
			root->add(v);
		}else{
			root=new node(v,node::black);
		}
//		printf("%d\n",v);
	}
	root->preorder();
	while(j--){
		scanf("%d",&v);
		int temp=0;
		root->search(v,temp);
		printf("%d\n",temp);
	}
	return 0;
}
node::node(void):color(black){left=right=p=this;}
node::node(int i,enum Color c=red):key(i),left(nil),right(nil),p(nil),color(c){}
void node::add(int j){
	if(j>key){
		if(right==nil){
			right=new node(j);
			right->p=this;
			right->fixup();
		}else{
			right->add(j);
		}
	}else{
		if(left==nil){
			left=new node(j);
			left->p=this;
			left->fixup();
		}else{
			left->add(j);
		}
	}
}
void node::trans(node* q){
	if(p==nil){
		root=q;
	}else if(this==p->left){
		p->left=q;
	}else p->right=q;
	if(q!=nil){
		q->p=p;
	}
}
node* node::search(int k,int& depth){
	if(this==nil){
		return nil;
	}
	if(key>k){
		++depth;
		return left->search(k,depth);
	}else if(key<k){
		++depth;
		return right->search(k,depth);
	}else{
		return this;
	}
}
void node::del(void){
	if(left==nil){
		this->trans(right);
	}else if(right==nil){
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
	if(left!=nil){
		return left->mini();
	}else{
		return this;
	}
}
void node::inorder(void){
	if(this!=nil){
		left->inorder();
		printf("%d ",key);
		right->inorder();
	}
}
void node::preorder(void){
	if(this!=nil){
		std::cout<<(*this);
		left->preorder();
		right->preorder();
	}
}
void node::postorder(void){
	if(this!=nil){
		left->postorder();
		right->postorder();
		printf("%d ",key);
	}
}
void node::fixup(void){
	node *y,*z=this;
	while(z->p->color==red){
		if(z->p==z->p->p->left){
			y=z->p->p->right;
			if(y->color==red){
				z->p->color=black;
				y->color=black;
				z->p->p->color=red;
				z=z->p->p;
			}else{
				 if(z==z->p->right){
					z=z->p;
					z->left_rotate();
				}
				z->p->color=black;
				z->p->p->color=red;
				z->p->p->right_rotate();
			}
		}else{
			y=z->p->p->left;
			if(y->color==red){
				z->p->color=black;
				y->color=black;
				z->p->p->color=red;
				z=z->p->p;
			}else{
				 if(z==z->p->left){
					z=z->p;
					z->right_rotate();
				}
				z->p->color=black;
				z->p->p->color=red;
				z->p->p->left_rotate();
			}
		}
	}
	root->color=black;
}
void node::left_rotate(void){
	node* y=right;
	right=y->left;
	if(y->left!=nil){
		y->left->p=this;
	}
	y->p=p;
	if(p==nil){
		root=y;
	}else if(this==p->left){
		p->left=y;
	}else{
		p->right=y;
	}
	y->left=this;
	p=y;
}
void node::right_rotate(void){
	node* y=left;
	left=y->right;
	if(y->right!=nil){
		y->right->p=this;
	}
	y->p=p;
	if(p==nil){
		root=y;
	}else if(this==p->right){
		p->right=y;
	}else{
		p->left=y;
	}
	y->right=this;
	p=y;
}
ostream& operator<<(ostream& os,node& p){
	os<<p.key;
	if(p.color==node::red){
		os<<":red"<<std::endl;
	}else{
		os<<":black"<<std::endl;
	}
	return os;
}
