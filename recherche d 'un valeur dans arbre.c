#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node {
	int val;
	struct node *fg;
	struct  node *fd;
	
};


node *add(node *root ,int val){
	if(root ==NULL){
		node *n = (node *)malloc(sizeof(node));
		n->val=val;
		n->fg= NULL;
		n->fd = NULL;
		return n;
	}
	
	if( val < root-> val ){
		
		root-> fg = add(root->fg,val);
		return root;
	}
	if(val > root->val){
			root-> fd = add(root->fd,val);
		return root;
		
	}
	return root ;// val == root->val
}
void prefixe (const node *root){
	
	if(root != NULL){
		
	printf("%d__ ",root->val);
	prefixe(root->fg);
	prefixe(root->fd);
	}
}
void postfixe (const node *root){
	if(root != NULL){
	
	postfixe(root->fg);
	postfixe(root->fd);
	printf("%d__ ",root->val);
	}
}
void infixe (const node *root){
	if(root != NULL){

	infixe(root->fg);
		printf("%d__ ",root->val);
	infixe(root->fd);
	}
}
void recherche (node*root , int val){
	
	if(root != NULL){
		if(root->val ==val ){
			printf(" la valeur existe");
		}else{
			if(val < root->val){
			 recherche (root->fg , val);
			}
			if(val > root->val){
			 recherche (root->fd, val);
			}
		}
	}
	
	
}

main()
{

node * root = NULL;
root = add(root ,5);
root = add(root ,10);
root = add(root ,14);
root = add(root ,11);
root = add(root ,12);
root = add(root ,20);
printf(" l arbre contient les elements suivant :\n");
prefixe (root);
printf(" \n");
postfixe (root);
printf(" \n");
infixe (root);
printf(" \n");
recherche (root , 5);

}
