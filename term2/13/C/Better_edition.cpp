#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::ostream;
//This edition is considered better because it deals class Node and Tree differently and thus faster
class Node{
public:
	enum Color{black,red};
	Color color;
	int key;
	Node *left,*right,*p;
	Node(void);
	Node(int i,enum Color c);
	void inorder(void);
	void preorder(void);
	void postorder(void);
	friend ostream& operator<<(ostream&,Node&);	
};
class Tree{
public:
	Node *root;
	Tree(void);
	void add(int);
	int search(int);
	void left_rotate(Node*);
	void right_rotate(Node*);
	void fixup(Node*);
};

Node* nil=new Node();
int main(){
	int i,j,v;
	Tree a;
	scanf("%d%d",&i,&j);
	while(i--){
		scanf("%d",&v);
		a.add(v);
	}
	a.root->preorder();
	while(j--){
		scanf("%d",&v);
		printf("%d\n",a.search(v));
	}
	return 0;
}
Node::Node(void):color(black){left=right=p=this;}
Node::Node(int i,enum Color c=red):key(i),left(nil),right(nil),p(nil),color(c){}
Tree::Tree(void):root(nil){}
void Tree::add(int j){
	Node *p=root,*q=root;
	if(p==nil){
		root=new Node(j);
		root->color=Node::black;
	}else{
		while(p!=nil){
			q=p;
			if(j>p->key){
				p=p->right;
			}else{
				p=p->left;
			}
		}
		p=new Node(j);
		p->p=q;
		if(p->key>q->key){
			q->right=p;
		}else{
			q->left=p;
		}
		fixup(p);
	}
}
int Tree::search(int k){
	Node *p=root;
	int count=-1;
	while(root!=nil){
		++count;
		if(k>p->key){
			p=p->right;
		}else if(k<p->key){
			p=p->left;
		}else{
			return count;
		}
	}
	return -1;//For warning
}
void Node::inorder(void){
	if(this!=nil){
		left->inorder();
		printf("%d ",key);
		right->inorder();
	}
}
void Node::preorder(void){
	if(this!=nil){
		std::cout<<(*this);
		left->preorder();
		right->preorder();
	}
}
void Node::postorder(void){
	if(this!=nil){
		left->postorder();
		right->postorder();
		printf("%d ",key);
	}
}
void Tree::fixup(Node *z){
	Node *y=nil;
	while(z->p->color==Node::red){
		if(z->p==z->p->p->left){
			y=z->p->p->right;
			if(y->color==Node::red){
				z->p->color=Node::black;
				y->color=Node::black;
				z->p->p->color=Node::red;
				z=z->p->p;
			}else{
				 if(z==z->p->right){
					z=z->p;
					left_rotate(z);
				}
				z->p->color=Node::black;
				z->p->p->color=Node::red;
				right_rotate(z->p->p);
			}
		}else{
			y=z->p->p->left;
			if(y->color==Node::red){
				z->p->color=Node::black;
				y->color=Node::black;
				z->p->p->color=Node::red;
				z=z->p->p;
			}else{
				 if(z==z->p->left){
					z=z->p;
					right_rotate(z);
				}
				z->p->color=Node::black;
				z->p->p->color=Node::red;
				left_rotate(z->p->p);
			}
		}
	}
	root->color=Node::black;
}
void Tree::left_rotate(Node *z){
	Node* y=z->right;
	z->right=y->left;
	if(y->left!=nil){
		y->left->p=z;
	}
	y->p=z->p;
	if(z->p==nil){
		root=y;
	}else if(z==z->p->left){
		z->p->left=y;
	}else{
		z->p->right=y;
	}
	y->left=z;
	z->p=y;
}
void Tree::right_rotate(Node *z){
	Node* y=z->left;
	z->left=y->right;
	if(y->right!=nil){
		y->right->p=z;
	}
	y->p=z->p;
	if(z->p==nil){
		root=y;
	}else if(z==z->p->right){
		z->p->right=y;
	}else{
		z->p->left=y;
	}
	y->right=z;
	z->p=y;
}
ostream& operator<<(ostream& os,Node& p){
	os<<p.key;
	if(p.color==Node::red){
		os<<":red"<<std::endl;
	}else{
		os<<":black"<<std::endl;
	}
	return os;
}
