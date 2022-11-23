#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node {
	int val;
	struct node *fg;
	struct  node *fd;
	
};
	int j = 0;

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
	 int s=0;
	if(root != NULL){
		
	printf("%d__ ",root->val);
	 s= s + root->val;
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
int nbr_fils(node*root){
	if (root != NULL){
		if (root->fg  ==  NULL  &&  root->fd == NULL){
	j++;
	}
		nbr_fils(root->fg);
		nbr_fils(root->fd);
	}
	return j ;
}
/*Retourne un pointeur vers le pointeur vers le nœud qu'on cherche*/
node* FindPtrToNode(node *ppRoot, int key)
{
	btree *ppCurrent = ppRoot;
	if(ppCurrent==NULL)
		return NULL;
	while(*ppCurrent != NULL)
	{
		if((*ppCurrent)->key == key)
			break;
		else if((*ppCurrent)->key < key)
			ppCurrent = &( (*ppCurrent)->left );
		else
			ppCurrent = &( (*ppCurrent)->right );
	}
	return ppCurrent;
}
 
/*Retourne un pointeur sur le pointeur du fils le plus à gauche*/
btree* FindPtrLeftmost(btree* ppNode)
{
	btree* ppPrevious = ppNode;
	if(ppNode==NULL)
		return NULL;
	while(*ppNode != NULL)
	{
		ppPrevious = ppNode;
		ppNode = &( (*ppNode)->left );
	}
	return ppPrevious;
}
 
void Remove(btree *ppNode)
{
	/*Algorithme de suppression qui aura besoin de FindPtrLeftmost().*/
}
 
void FindAndRemove(btree *ppRoot, int key)
{
	btree* ppDelete = FindPtrToNode(ppRoot, key);
	Remove(ppDelete);
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
prefixe (root);
printf(" \n");
postfixe (root);
printf(" \n");
infixe (root);
printf(" \n");
printf("l arbre apres supprision est :\n");
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
supprimerElement(root , 12);

}
