#include<stdio.h>

struct RB{
	struct RB *p,*left,*right;
	int key;
};

void Transplant(struct RB *T,struct RB *u,struct RB *v){
	if(u->p = NULL)
		T = v;
	else if(u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	if(u->p != NULL)
		v->p = u->p;
}

void left_rotate(struct RB *T,struct RB *x){
	if((x != NULL)*(x->right != NULL)){
		Transplant(T,x,x->right);
		struct RB *y = x->right;
		x->p = y;
		x->right = y->left;
		y->left->p = x;
		y->left = x;				
	}
}

void right_rotate(struct RB *T,struct RB *x){
	if((x != NULL)*(x->left != NULL)){
		Transplant(T,x,x->left);
		struct RB *y = x->left;
		x->p = y;
		x->left = y->right;
		y->right->p = x;
		y->right = x;				
	}
}

