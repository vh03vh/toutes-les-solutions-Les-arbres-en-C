#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node {
	int val;
	struct node *fg;
	struct  node *fd;
	
};
 
 int s ;

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
int nomber_de_noud(node*root){
	if(root == NULL)
	return 0;
	return ( 1+nomber_de_noud(root->fg)+nomber_de_noud(root->fd));
	
}
int nomber_fils(node *root){
	int n;
		if(root == NULL)
	return 0;
	if (root != NULL){
	
		if(root->fg == NULL && root->fd == NULL )
		n++;
		return n ;
	}
	 nomber_fils(root->fg );
	  nomber_fils(root->fd);

	
}
 int somme (node *root){
	
	if(root != NULL){
	s = s +root->val;
	somme(root->fg);
	somme(root->fd);
	 return s;
	}
}

main()
{
int s;
int j ;
 int o ;
node * root = NULL;
root = add(root ,5);
root = add(root ,10);
root = add(root ,14);
root = add(root ,11);
root = add(root ,12);
root = add(root ,20);
prefixe (root);
printf(" \n");
postfixe (root);
printf(" \n");
infixe (root);
printf(" \n");
s = nomber_de_noud(root);
printf("le nombers des node est :%d",s);
  j =nomber_fils(root);
  printf("\n le nomber des fils est :%d",j);
  o = somme(root);
  printf("\n  la somme des elts d un arbre est :%d",o);
}
