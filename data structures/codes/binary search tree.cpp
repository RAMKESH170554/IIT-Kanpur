#include<stdio.h>
#include<stdlib.h>

struct BT{
	struct BT *left, *right, *p;
	int key;
};

struct BT *search(struct BT *T, int key){
	struct BT *x = T;
	if(x == NULL)
		return NULL;
	else if(x->key == key)
		return x;
	else if(x->key <= key)
		return search(x->right,key);
	else
		return search(x->left,key);
}

struct BT *minimum(struct BT *T){
	struct BT *x = T;
	struct BT *y = T->p;

	while(x->left != NULL){
		y = x;
		x = x->left;
	}
	return x;
}
struct BT *maximum(struct BT *T){
	struct BT *x = T;
	struct BT *y = T->p;
	
	while(x->right != NULL){
		y = x;
		x = x->right;
	}
	return x;
}

void inorderTrav(struct BT *T){
	if(T == NULL)
		return;
	inorderTrav(T->left);
	printf("%d ",T->key);
	inorderTrav(T->right);
}

struct BT *successor(struct BT *x){
	struct BT *y = NULL;
	if(x->right != NULL)
		return minimum(x->right);
	else{
		y = x->p;
		while((x == y->right) && (y != NULL)){
			x = y;
			y = y->p;
		}
		return y;
	}
}

struct BT *predecessor(struct BT *x){
	struct BT *y = NULL;
	if(x->left != NULL)
		return maximum(x->left);
	else{
		y = x->p;
		while(x == y->left && y != NULL){
			x = y;
			y = y->p;
		}
		return y;
	}
}

void iterativeTrav(struct BT *T){
	//struct BT *x = T;
	struct BT *x = minimum(T);
	while(x != NULL){
		printf("%d ",x->key);
		x = successor(x);
	}
}

void insert(struct BT *T){
	struct BT *x = (struct BT *)malloc(sizeof(struct BT));
	x->left = NULL, x->right = NULL, x->p = NULL;
	scanf("%d",&x->key);
	struct BT *z = T, *y = NULL;
	
	while(z != NULL){
		y = z;
		if(z->key <= x->key)
			z = z->right;
		else
			z = z->left;
	}
	if(y != NULL){
		if(y->key <= x->key)
			y->right = x;
		else
			y->left = x;
		x->p = y;
	}
	delete x;
}

void transplant(struct BT *T,struct BT *u,struct BT *v){
	if(u->p = NULL)
		T = v;
	else if(u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	if(u->p != NULL)
		v->p = u->p;
}

void Del(struct BT *T,struct BT *z){
	if(z->right == NULL)
		transplant(T,z,z->left);
	else if(z->left == NULL)
		transplant(T,z,z->right);
	else{
		struct BT *y = minimum(z->right);
		if(y == z->right){
			transplant(T,z,z->right);
			y->left = z->left;
			z->left->p = y;
		}
		else{
			transplant(T,y,y->right);
			y->left = z->left;
			y->right = z->right;
			z->left->p = y;
			z->right->p = y;
			transplant(T,z,y);
		}
	}
}

int main(){
	struct BT *T = (struct BT *)malloc(sizeof(struct BT));
	T->p = NULL,T->left = NULL,T->right = NULL;
	int n;
	scanf("%d ",&n);
	scanf("%d ",&T->key);
	for(int h=1; h < n; h++)
		insert(T);
	inorderTrav(T);	
//	struct BT *u = predecessor(T);
//	printf("\n%d",u->key);
//	struct BT *f = minimum(T);
	printf("\n");
	iterativeTrav(T);
	delete(T);
	return 0;
}

/*
8
5 564 45 84 21 64 984 31
12
25 15 40 12 20 30 60 1 13 17 57 65
*/






