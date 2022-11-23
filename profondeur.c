#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node {
	int val;
	struct node *fg;
	struct  node *fd;
	
};



int pfd(node*root){
if(root == NULL)
return 0;
else
{
int g = pfd( root->fg );
int d = pfd( root->fd );
if( g > d){

      return(g+1);
}else{
     return(d+1);
}
}
}
main()
{
  int b;



  printf(" le profendeur de un arbre ");
  b = pfd(node *root);
   printf(" le profendeur de un arbre est :%d",b);
}
