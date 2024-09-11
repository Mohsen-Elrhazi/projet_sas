#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "etudiant.h"

typedef struct Date {
    int jour;
    int mois;
    int annee;
}Date;

typedef struct Etudiant {
    int numero;
    char nom[50];
    char prenom[50];
     Date naissance;
    char departement[100];
    float noteGenerale;
}Etudiant;

Etudiant *e;
Etudiant *p,*p1,*p2;
int num;
int choix,n;
float somme[100];
float *s=&somme;
char nom[20];

/*-----------Ajouter un etudiant-----------*/
void Ajouter(Etudiant *e,int n){
     p = e + (n - 1);
     printf("Entrer les infos d'etu %d:\n",(p-e)+1);
    printf("Entrer le numero: ");
    scanf("%d",&p->numero);
    printf("Entrer le nom: ");
    scanf("%s",&p->nom);
    printf("Entrer le prenom: ");
    scanf("%s",&p->prenom);
    printf("entrer la date naissance: ");
    scanf("%d%d%d",&p->naissance.jour,&p->naissance.mois,&p->naissance.annee);
    printf("Entrer la departement: ");
    scanf("%s",&p->departement);
    printf("Entrer la note generale : ");
    scanf("%f",&p->noteGenerale);
}

/*-----------Afficher les etudiant-----------*/
void Afficher(Etudiant *e,int *n){
    if(*n==0){
        printf("Aucun etudiant disponible.\n");
    }
    else{
     for(p=e;p<e+ *n;p++){
     printf("les infos d'etu %d:\n",(p-e)+1);
    printf("Numero: %d\n",p->numero);
    printf("Nom: %s\n",p->nom);
    printf("Prenom: %s\n",p->prenom);
    printf("Date naissance: %d/%d/%d\n",p->naissance.jour,p->naissance.mois,p->naissance.annee);
    printf("Departement: %s\n",p->departement);
    printf("Note generale : %.2f\n",p->noteGenerale);
    printf("------------------------------");
     }
    }
}

/*-----------Modifier un etudiant-----------*/
void Modifier(Etudiant *e,int *n,int *num){
    int trv=0;
     for(p=e;p<e+ *n;p++){
       if(p->numero==*num){
         trv=1;
         p1=p;
         break;
       }
     }
     if(trv==0){
        printf("L'etudiant n'a pas ete trouve.\n");
     }
     else {
        printf("Entrer la nouveau numero: ");
        scanf("%d",&p1->numero);
        printf("Entrer la nouveau nom: ");
        scanf("%s",&p1->nom);
        printf("Entrer le nouveau prenom: ");
        scanf("%s",&p1->prenom);
        printf("Entrer la nouvelle date de naissance: ");
        scanf("%d%d%d",&p1->naissance.jour,&p1->naissance.mois,&p1->naissance.annee);
        printf("Entrer le nouveau departement: ");
        scanf("%s",&p1->departement);
        printf("Entrer la nouvelle note generale: ");
        scanf("%f",&p1->noteGenerale);
        printf("les informations de l'etu ont ete modifiees.\n");
     }
    }

/*-----------Supprimer un etudiant-----------*/
void Supprimer(Etudiant *e,int *n,int *num){
    int trv=0;
     for(p=e;p<e+ *n;p++){
       if(p->numero==*num){
         trv=1;
         p1=p;
         break;
       }
     }
     if(trv==0){
        printf("L'etudiant n'a pas ete trouve.\n");
     }
     else {
            for(p=p1;p<e+ *n;p++){
                *p = *(p+1);
            }
            printf("L'etudiant a ete supprime.\n");
             *n-=1;
     }
    }

/*-----------Calculer la moyenne-----------*/
void calcMoyenne(Etudiant *e,int *n){

}

/*-----------Rechercher etudiant par son nom-----------*/
void rechercherEtud(Etudiant *e,int *n,char *nom){
    for(p=e;p<e+ *n;p++){
        if(strcasecmp(p->nom,nom)==0){
           // Afficher(e,1);
            printf("les infos d'etu %d:\n",(p-e)+1);
            printf("Numero: %d\n",p->numero);
            printf("Nom: %s\n",p->nom);
            printf("Prenom: %s\n",p->prenom);
            printf("Date naissance: %d/%d/%d\n",p->naissance.jour,p->naissance.mois,p->naissance.annee);
            printf("Departement: %s\n",p->departement);
            printf("Note generale : %.2f\n",p->noteGenerale);
            return ;
        }
    }
    printf("l'etudiant n'a pas ete trouve.\n");
}

int main()
{

while(1){
    printf("\n-------------MENU------------\n");
     printf("Que souhaitez vous faire:\n");
    printf("1:Ajouter un etudiant\n");
    printf("2:afficher les etudiants \n");
    printf("3:modifier un etudiant\n");
    printf("4:Supprimer un etudiant\n");
    printf("5:Rechercher etudiant\n");
    printf("6:Trier les Contacts\n");
    printf("7:Quitter le programme\n");
    printf("entrer votre choix: ");
    scanf("%d",&choix);
    printf("-------------------------------\n");
    switch(choix){
    case 1:
        if (n==0){
        e=calloc(n=1,sizeof(Etudiant));
        Ajouter(e,n);
        }
        else {
        n+=1;
            e=realloc(e,n*sizeof(Etudiant));
            Ajouter(e,n);
        }
       break;
    case 2:Afficher(e,&n);
       break;
    case 3: printf("Entrer le numero d'etudiant a modifier: ");
            scanf("%d",&num);
            Modifier(e,&n,&num);
       break;
    case 4:printf("Entrer le numero d'etudiant a supprimer: ");
            scanf("%d",&num);
            Supprimer(e,&n,&num);
       break;
    case 5: printf("entrer le nom d'etudiant a rechercher: ");
    scanf("%s",&nom);
        rechercherEtud(e,&n,&nom);
       break;
    case 6:calcMoyenne(e,&n);
       break;
    case 7: printf("---------------Fin de programme1 !--------------- ");
          return 0;
          break;
    default : printf("le type de choix est incorrect\n");
       break;
    }
    }
    free(e);
    return 0;
}
