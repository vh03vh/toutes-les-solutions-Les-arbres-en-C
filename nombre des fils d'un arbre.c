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
node *supprimerElement(node *root , int val)
{
    node* tmp;
    if (root->val== val ){
       if( root->fg != NULL)
       {
          // on accroche a->fd au fils le plus à droite du fils gauche 
          tmp = root->fg;
          while(tmp->fd != NULL)
          {
             tmp = tmp->fd;
          }
          tmp->fd = root->fd;
          root = root->fg;
       }else{
           root = root->fd;
       }
    }
    else
    {
        if( val < root->val)
        {
            root->fg = supprimerElement( root->fg, val);
        }
        else
        {
            root->fd = supprimerElement( root->fd, val);
        }
    }
    return root;
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
supprimerElement(root ,10);

}
