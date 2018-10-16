#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
struct TREE{
	int n,n_member;
	int ldep,rdep;
	int dup;
	struct TREE *left,*right,*parent;
};
void recal(struct TREE *t){
	struct TREE *l=t->left,*r=t->right;
	t->n_member=t->dup;
	t->ldep=t->rdep=0;
	if(l!=NULL){
		t->n_member+=l->n_member;
		t->ldep=MAX(l->ldep,l->rdep)+1;
	}
	if(r!=NULL){
		t->n_member+=r->n_member;
		t->rdep=MAX(r->ldep,r->rdep)+1;
	}
}
void insert(struct TREE **root,int n){
	struct TREE *y,*x;
	struct TREE *z=(struct TREE *)malloc(sizeof(struct TREE));
	z->n=n,z->n_member=1,z->left=z->right=NULL;
	z->ldep=z->rdep=0;
	z->dup=1;
	for(y=NULL,x=*root;x!=NULL;y->n_member++){
		y=x;
		if(z->n<x->n) x=x->left;
		else if(z->n>x->n) x=x->right;
		else{
			free(z),x->dup++,x->n_member++;
			return;
		}
	}
	z->parent=y;
	if(y==NULL) (*root)=z;
	else if(z->n<y->n) y->left=z;
	else y->right=z;
	for(y=z->parent,x=z;y!=NULL;x=y,y=y->parent){
		recal(y);
		if(x->n<y->n){
			if(y->ldep==y->rdep+2){
				if(z->n<y->left->n){
					struct TREE *A=y,*B=y->left,*C=y->left->right;
					if(A->parent==NULL) (*root)=B,B->parent=NULL;
					else if(A->n<A->parent->n) A->parent->left=B,B->parent=A->parent;
					else A->parent->right=B,B->parent=A->parent;
					A->left=C;
					if(C!=NULL) C->parent=A;
					B->right=A,A->parent=B;
					recal(A),recal(B);
					y=B;
				}else{
					struct TREE *A=y,*B=A->left,*C=B->right,*D=C->left,*E=C->right;
					if(A->parent==NULL) (*root)=C,C->parent=NULL;
					else if(A->n<A->parent->n) A->parent->left=C,C->parent=A->parent;
					else A->parent->right=C,C->parent=A->parent;
					C->right=A,A->parent=C;
					C->left=B,B->parent=C;
					B->right=D;
					if(D!=NULL) D->parent=B;
					A->left=E;
					if(E!=NULL) E->parent=A;
					recal(A),recal(B),recal(C);
					y=C;
				}
			}
		}else{
			if(y->rdep==y->ldep+2){
				if(z->n<y->right->n){
					struct TREE *A=y,*B=A->right,*C=B->left,*D=C->left,*E=C->right;
					if(A->parent==NULL) (*root)=C,C->parent=NULL;
					else if(A->n<A->parent->n) A->parent->left=C,C->parent=A->parent;
					else A->parent->right=C,C->parent=A->parent;
					C->left=A,A->parent=C;
					C->right=B,B->parent=C;
					B->left=E;
					if(E!=NULL) E->parent=B;
					A->right=D;
					if(D!=NULL) D->parent=A;
					recal(A),recal(B),recal(C);
					y=C;
				}else{
					struct TREE *A=y,*B=A->right,*C=B->left;
					if(A->parent==NULL) (*root)=B,B->parent=NULL;
					else if(A->n<A->parent->n) A->parent->left=B,B->parent=A->parent;
					else A->parent->right=B,B->parent=A->parent;
					A->right=C;
					if(C!=NULL) C->parent=A;
					B->left=A,A->parent=B;
					recal(A),recal(B);
					y=B;
				}
			}
		}
	}
}
int find_i_min(struct TREE *now,int i_min){
	if(now->left==NULL){
		if(i_min<=now->dup) return now->n;
		return find_i_min(now->right,i_min-now->dup);
	}else{
		int r=now->left->n_member;
		if(i_min<=r) return find_i_min(now->left,i_min);
		if(i_min<=r+now->dup) return now->n;
		return find_i_min(now->right,i_min-r-now->dup);
	}
}
int main(){
	int cases;
	int M,N,i_min,len,n_insert;
	int array[30005];
	int i;
	struct TREE *root;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&M,&N);
		for(i=0;i<M;i++) scanf("%d",&array[i]);
		root=NULL;
		n_insert=0;
		for(i_min=1;i_min<=N;i_min++){
			scanf("%d",&len);
			for(;n_insert<len;n_insert++)
				insert(&root,array[n_insert]);
			printf("%d\n",find_i_min(root,i_min));
		}
		if(cases) puts("");
	}
	return 0;
}
