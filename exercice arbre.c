#include<stdio.h>
#include<stdlib.h>

	struct arbre{
		float salaire;
		char nom;
		char prenom ;
		int  annee;
		struct arbre *fd;
		struct arbre *fg;
	};
	typedef struct arbre arbre;


arbre *intialisation (float x,char y,char z,int t){
	arbre *d= malloc(sizeof(arbre));
	d->salaire = x;
	d->nom = y;
	d->prenom = z; 
	d->annee = t;
	d->fd = NULL;
	d->fg = NULL;
	 return (d);
}
void affichage(arbre *d){
	
	if( d != NULL){
		affichage(d->fd);
		printf("%f\t%c\t%c\t%d\t",d->salaire,d->nom,d->prenom,d->annee);
			affichage(d->fg);
	}
}
arbre *ajout(arbre*A,float x,char y,char z,int t){
	arbre*P= (struct arbre *)malloc (sizeof(struct arbre));
	
	P->salaire = x;
	P->nom = y;
	P->prenom = z; 
	P->annee = t;
	P->fd = NULL;
	P->fg = NULL;
	if(A ->salaire >= x  )
	{
		
		if ((A->fg)== NULL)
		A->fg = P;
		else
		 ajout(A->fg,x,y,z,t);
	}else {
			if ((A->fd)== NULL)
		A->fd = P;
		else
		 ajout(A->fd,x,y,z,t);
	}
	
	return (A);
}
main()
{

		float x;
		char y;
		char z ;
		int  t ;
		struct arbre *fd;
		struct arbre *fg;
		 struct arbre *A;
	
	printf ("saisier la salaire ,intail de nom, intaile de prenom et annee\n ");
	scanf ("%f%c%c%d",&x,&y,&z,&t);
	A = intialisation(x,y,z,t);
	printf("\n\n________________________\n\n");
	affichage(A);
}
