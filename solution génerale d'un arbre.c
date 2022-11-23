

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Arbre
{
	int Noeud;
	struct Arbre * SAG;
	struct Arbre * SAD;
} Arbre;

AfficherArbreCroissant(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		AfficherArbreCroissant(Racine->SAG);
		printf("%d ",Racine->Noeud);
		AfficherArbreCroissant(Racine->SAD);
	}
}

Arbre * CreerNoeud(Arbre * Racine,int valeur)
{
	if (Racine!=NULL)
	{
		if (Racine->Noeud>valeur)
		{
			Racine->SAG=CreerNoeud(Racine->SAG,valeur);
		}
		else
		{
			Racine->SAD=CreerNoeud(Racine->SAD,valeur);
		}
	}
	else
	{
		Racine=(Arbre *)malloc(sizeof(Arbre));
		Racine->Noeud=valeur;
		Racine->SAD=NULL;
		Racine->SAG=NULL;
	}
return Racine;
}

AfficherArbre(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		printf("%d ",Racine->Noeud);
		if (Racine->SAD!=NULL || Racine->SAG!=NULL)
		{
			AfficherArbre(Racine->SAG);
			AfficherArbre(Racine->SAD);
		}
	}
}

EnregArbre(Arbre * Racine,char * NomFic)
{
	int nb;
	FILE * fic;
	fic=fopen(NomFic,"at");
	if (Racine!=NULL)
	{
		nb=Racine->Noeud;
		fwrite(&nb,sizeof(int),1,fic);
		fclose(fic);
		if (Racine->SAD!=NULL || Racine->SAG!=NULL)
		{
			EnregArbre(Racine->SAG,NomFic);
			EnregArbre(Racine->SAD,NomFic);
		}
	}
}

Arbre * ChargerArbre(Arbre * Racine,char * NomFic)
{
	int nb;
	FILE * fic;
	fic=fopen(NomFic,"rt");
	fread(&nb,sizeof(int),1,fic);
	while (!feof(fic))
	{
		Racine = CreerNoeud(Racine,nb);
		fread(&nb,sizeof(int),1,fic);
	}
	fclose(fic);
	return Racine;
}

AfficherArbreDecroissant(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		AfficherArbreDecroissant(Racine->SAD);
		printf("%d ",Racine->Noeud);
		AfficherArbreDecroissant(Racine->SAG);
	}
}

int Somme(Arbre * Racine)
{
	int total=0;
	if (Racine!=NULL)
	{
		total=Somme(Racine->SAG);
		total+=Racine->Noeud;
		total+=Somme(Racine->SAD);
	}
	return total;
}

int CompteNoeud(Arbre * Racine)
{
	int total=0;
	if (Racine!=NULL)
	{
		total=CompteNoeud(Racine->SAG);
		total++;
		total+=CompteNoeud(Racine->SAD);
	}
	return total;
}

Arbre * RechercheNoeud(Arbre * Racine,  int valeur)
{
	if (Racine!=NULL)
	{
		if (Racine->Noeud>valeur)
		{
			Racine=RechercheNoeud(Racine->SAG,valeur);
		}
		else
		{
			if (Racine->Noeud<valeur)
			{
				Racine=RechercheNoeud(Racine->SAD,valeur);
			}
		}
		return Racine;
	}
}

Arbre * OterNoeud(Arbre * Racine, int valeur)
{
	Arbre * NoeudASupprimer;
	if (Racine->Noeud==valeur) // on a trouv้ l'้l้ment เ supprimer
	{
		NoeudASupprimer=Racine;
		if (NoeudASupprimer->SAG==NULL) //si ya pa de SAG, on retourne SAD
			return NoeudASupprimer->SAD;
		else
		{
			Racine=NoeudASupprimer->SAG; //sinon on recherche dans SAG l'endroit pour ins้rer le SAD
				while (Racine->SAD!=NULL)
				{
					Racine=Racine->SAD;
				}
				Racine->SAD=NoeudASupprimer->SAD;
			return NoeudASupprimer->SAG;
		}
		free(NoeudASupprimer);
	}
	else
	{
		if (Racine->Noeud>valeur)
		{
			Racine->SAG=OterNoeud(Racine->SAG,valeur);
		}
		else
		{
			Racine->SAD=OterNoeud(Racine->SAD,valeur);
		}
	}
	return Racine;
}

int Menu()		
{
	int Choix;
	do
	{
		system("cls"); //efface l'้cran
		printf("             ษออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("             บ                                                      บ\n");
		printf("             บ                    Menu Principal                    บ\n");
		printf("             บ                                                      บ\n");
		printf("             ศออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
		printf("\n                 1- Ajouter un noeud");
		printf("\n                 2- Afficher l'arbre");
		printf("\n                 3- Afficher l'arbre dans l'ordre croissant");
		printf("\n                 4- Afficher l'arbre dans l'ordre decroissant");
		printf("\n                 5- Somme des noeuds");
		printf("\n                 6- Nombre de noeuds");
		printf("\n                 7- Rechercher un noeud");
		printf("\n                 8- Enlever un noeud");
		printf("\n                 9- Enregister l'arbre dans un fichier");
		printf("\n                10- Charger l'arbre \205 partir d'un fichier");
		printf("\n                11- Quitter\n");
		printf("\n\n\n\n\n\n\nChoix :");
		scanf("%d",&Choix);
	} while (Choix <1 || Choix >11);
	system("cls"); 
	return Choix;
}

main()
{
	int valeur;
	int Choix;
	char * NomFic="Fic.txt";
	Arbre * Racine;
	Arbre * RepRecherche;
	Racine=NULL;
	Choix = Menu();
	while (Choix!=11)
	{
		if (Racine==NULL && Choix>1 && Choix <10)
		{
			printf("Vous devez d'abord saisir un arbre");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
			getch();
		}
		else
		{
			switch (Choix)
			{
				case 1 :	printf("Saisir un entier (0 pour finir la saisie) : ");
							scanf("%d",&valeur);
							while (valeur != 0)
							{
								Racine=CreerNoeud(Racine,valeur);
								printf("Saisir un entier (0 pour finir la saisie) : ");
								scanf("%d",&valeur);
							}
							break;
				case 2 :	AfficherArbre(Racine);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 3 :	AfficherArbreCroissant(Racine);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 4 :	AfficherArbreDecroissant(Racine);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 5 :	AfficherArbreCroissant(Racine);
							printf("\nTotal : %d",Somme(Racine));
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 6 :	AfficherArbreCroissant(Racine);
							printf("\nTotal : %d",CompteNoeud(Racine));
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 7 :	printf("Saisir la valeur \205 rechercher : ");
							scanf("%d", &valeur);
							RepRecherche=RechercheNoeud(Racine,valeur);
							if (RepRecherche->Noeud==valeur)
							{
								printf("%d", RepRecherche->Noeud);
							}
							else
							{
								printf("Impossible de trouver la valeur recherch\202e");
							}
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 8 :	printf("Saisir la valeur du noeud \205 supprimer : \n");
							scanf("%d",&valeur);
							Racine=OterNoeud(Racine,valeur);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 9 :	system("del Fic.txt");
							system("cls");
							EnregArbre(Racine,NomFic);
							printf("Arbre enregistr\202\n");
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 10 :	Racine=ChargerArbre(Racine,NomFic);
							printf("Arbre charg\202\n");
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
			}
		}
		Choix=Menu();
	}
}
