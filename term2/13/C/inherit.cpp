#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::ostream;
//OOPÕæ°ô£¡£¨¼Ù»°£©
class RB_node;
class node{
protected:
	node *l,*r,*parent;
public:
	int key;
	node(int i):key(i),l(NULL),r(NULL),parent(NULL){}
	node(int i,node* ptr):key(i),l(ptr),r(ptr),parent(ptr){};
	virtual void add(int);
	void trans(node*);
	virtual node* search(int);
	virtual node* search(int,int);
	node* mini(void);
	void del(void);
	void inorder(void);
	void preorder(void);
	node* left(void){return l;}
	node* right(void){return r;}
	node* p(void){return parent;}
	void postorder(void);
	friend std::ostream& operator<<(std::ostream&,node&);
	operator RB_node(void);
};
class RB_node:public node{
public:
	enum Color{black,red};
	Color color;
	RB_node(int i,enum Color c);
	virtual void add(int);
	virtual void fixup(void);
	virtual void trans(node*);
	virtual RB_node* search(int,int&);
	virtual void del(void);
	virtual void preorder(void);
	void left_rotate(void);
	void right_rotate(void);
	friend ostream& operator<<(ostream&,RB_node&);
};
RB_node* nil=(RB_node*)malloc(sizeof(RB_node));
RB_node* root=nil;
int main(){
	int i,j,v;
	nil->color=RB_node::black;
	scanf("%d%d",&i,&j);
	while(i--){
		scanf("%d",&v);
		if(root!=nil){
			root->add(v);
		}else{
			root=new RB_node(v,RB_node::black);
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
RB_node::RB_node(int i,enum Color c=red):node(i,nil),color(c){}
void RB_node::add(int j){
	if(j>key){
		if(r==nil){
			r=new node(j);
			right->p=this;
			((RB_node*)right)->fixup();
		}else{
			right->add(j);
		}
	}else{
		if(left==nil){
			left=new node(j);
			left->p=this;
			((RB_node*)left)->fixup();
		}else{
			left->add(j);
		}
	}
}
void RB_node::trans(node* q){
	if(p==nil){
		root=((RB_node*)q);
	}else if(this==p->left){
		p->left=q;
	}else p->right=q;
	if(q!=nil){
		q->p=p;
	}
}
RB_node* RB_node::search(int k,int& depth){
	if(this==nil){
		return nil;
	}
	if(key>k){
		++depth;
		return (RB_node*)left->search(k,depth);
	}else if(key<k){
		++depth;
		return (RB_node*)right->search(k,depth);
	}else{
		return this;
	}
}
void RB_node::del(void){
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
void RB_node::preorder(void){
	if(this!=nil){
		std::cout<<(*this);
		left->preorder();
		right->preorder();
	}
}
void RB_node::fixup(void){
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
void RB_node::left_rotate(void){
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
void RB_node::right_rotate(void){
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
node* node::search(int k){
	if(key>k){
		return left->search(k);
	}else if(key<k){
		return right->search(k);
	}else{
		return this;
	}
}
vode* node::mini(void){
	if(left!=NULL){
		return left->mini();
	}else{
		return this;
	}
}
node::operator RB_node(void){
	return (RB_node*)this;
}

