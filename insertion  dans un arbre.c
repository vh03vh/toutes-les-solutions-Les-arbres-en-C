#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node {
	int val ;
	node * fg ;
	node *fd;
}; 
node * add (node*root , int val ){
	if (root == NULL){
		node *n = (node *)malloc(sizeof(node));
		n->fg= NULL;
		n->fd= NULL;
		n->val= val;
		return n;
	}
	if (val <root->val){
	
	root ->fg = add (root->fg ,val);
	return root ;
}
	if (val >root->val){
	
	root->fd = add (root->fd ,val);
	return root ;
	
}
return root ;//val == root ->val
}
  node *insere (node * root ,int val ){
 	if (root == NULL){
 	return  add (root , val );
 }else{
 	if ( val < root->val ){
 		root->fg = insere (root->fg,val);}
 		 return root;
 		if ( val > root->val ){
 		root->fd = insere (root->fd,val);}
	 return root ;
 }	
 }

void prefixe (node *root ){
	if (root != NULL){
		printf ("%d__",root->val);
		prefixe(root->fg);
		prefixe(root->fd);
	}
}
void infixe(node *root ){
	if(root != NULL){
		infixe(root->fg);
		printf("%d__",root->val);
		infixe (root ->fd);
		
	}
}
 void postfixe(node *root ){
 	if (root != NULL){
 		postfixe (root->fg);
 		postfixe(root->fd);
 		printf("%d__",root->val);
 		
	 }
 }
 main()
 {

 	node * root = NULL;
 	
 	
 	root = add(root,3);
 	root = add(root,10);
 	root = add(root,5);
 	root = add(root,45);
 	root = add(root,1);
 	root = add(root,55);
 	root = add(root,2);
printf("l arbrecontient les elments suivant avec trois type de parcours\n");
 	prefixe(root );
 	printf("\n");
 	infixe(root );
 	printf("\n");
 	postfixe(root );
 	printf("\n");
 	
 	
 	printf("arbre apres insertion\n");
 	root = add(root,3);
 	root = add(root,10);
 	root = add(root,5);
 	root = add(root,45);
 	root = add(root,1);
 	root = add(root,55);
 	root = add(root,2);
	root =insere(root , 90);
 	prefixe(root );
 	printf("\n");
 	infixe(root );
 	printf("\n");
 	postfixe(root );
 	printf("\n");
 }

