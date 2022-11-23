# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
struct arbre{
	int info;
	struct arbre *fg,*fd;
};

struct  arbre *crea_arbre(struct arbre *r,int val){
	char n;
	struct arbre *r1=malloc(sizeof(struct arbre));
   	  
	  r1->info = val;
	  r1->fg = NULL;
	  r1->fd = NULL;
	  
    if(r==NULL){
	  return r1;		
	}else{
	  printf(" donner fils (g/d) : "); scanf("%s",&n);
	  if(n=='g' || n=='G')
	    r->fg = crea_arbre(r->fg,val);
	  else  
		r->fd = crea_arbre(r->fd,val);	
	}
return r;	

}
