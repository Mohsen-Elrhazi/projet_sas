#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "etudiant.h"



#define MAX_DEPARTEMENTS 100
#define TAILLE_DEPARTEMENT 50


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

char nom[20];
char departement[20];
float seuil;

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
        return ;
    }
    else{
     for(p=e;p<e+ *n;p++){
    /* printf("les infos d'etu %d:\n",(p-e)+1);
    printf("Numero: %d\n",p->numero);
    printf("Nom: %s\n",p->nom);
    printf("Prenom: %s\n",p->prenom);
    printf("Date naissance: %d/%d/%d\n",p->naissance.jour,p->naissance.mois,p->naissance.annee);
    printf("Departement: %s\n",p->departement);
    printf("Note generale : %.2f\n",p->noteGenerale);   */
     printf("Etudiant %d => Numero: %d, Nom: %s, Prenom: %s, Date de naissance: %d/%d/%d, Departement: %s, Note generale: %.2f\n",
               (p-e)+1, p->numero, p->nom, p->prenom, p->naissance.jour, p->naissance.mois, p->naissance.annee, p->departement, p->noteGenerale);
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
       int processed[100] = {0}; // Tableau pour suivre les départements déjà traités
    float sommeDepartement;
    float sommeGenerale;
      float moyenne;
        int nbretu;
        sommeGenerale=0;
    for(p=e;p<e+ *n;p++){
            sommeGenerale+=p->noteGenerale;
            if (processed[p - e] == 1) {
            continue; // Passer si le département est déjà traité
        }
         sommeDepartement = 0;
         nbretu = 0;
        for(p1=e;p1<e+ *n;p1++){
            if(strcasecmp(p->departement,p1->departement)==0){
              sommeDepartement= sommeDepartement+ p1->noteGenerale ;
              nbretu++;
              processed[p1- e] = 1 ;
            }
    }
    if (nbretu>0){
       moyenne=sommeDepartement/nbretu;
       printf("la moyenne du departement %s est: %.2f\n",p->departement,moyenne);
    }
   }
   moyenne=sommeGenerale/ (*n);
   printf("la moyenne generale de l'universite est: %.2f",moyenne);
}

/*-----------Rechercher etudiant par son nom-----------*/
void RechercherEtudiantParNom(Etudiant *e,int *n,char *nom){
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
            // return ;
        }
    }
    printf("l'etudiant n'a pas ete trouve.\n");
}

/*-----------Afficher la liste des étudiants inscrits dans un département spécifique-----------*/
void AfficherEtudiantsParDepartement(Etudiant *e,int n,char *depart){
    int nbretu=0;
    printf("Les étudiants inscrits dans le département %s sont:\n", depart);
    for(p=e;p<e+n;p++){
        if(strcasecmp(p->departement,depart)==0){
                if(nbretu=0){
                    printf("Les etudiants inscrits dans le departement %s sont:\n", departement);
                }
            printf("les infos d'etu %d:\n",(p-e)+1);
            printf("Numero: %d\n",p->numero);
            printf("Nom: %s\n",p->nom);
            printf("Prenom: %s\n",p->prenom);
            printf("Date naissance: %d/%d/%d\n",p->naissance.jour,p->naissance.mois,p->naissance.annee);
            printf("Departement: %s\n",p->departement);
            printf("Note generale : %.2f\n",p->noteGenerale);
            nbretu++;
        }
    }
    if(nbretu==0){
    printf("aucun etudiant inscris dans cette departement: %s\n",departement);
    }
}
/*-----------Trie par choix-----------*/
/*
void trie(Etudiant *c, int n) {
    Etudiant Temp;
    if(n==0){
        printf("Aucun etudiant inscris.\n");
        return ;
    }
     printf("1:Trie des etudiants par nom\n");
    printf("2:Trie des etudiants par moyenne generale\n");
    printf("3:Tri des étudiants selon leur statut de réussite (ceux ayant une moyenne supérieure ou égale à 10/20)\n");
    printf("Entrer votre choix de trie: ");
    scanf("%d",&choix);

     if (choix < 1 || choix > 3) {
        printf("Le type de choix est incorrect.\n");
        return;
    }

    for ( p1 = c; p1 < c + (n - 1); p1++) {
        for ( p2 = p1 + 1; p2 < c + n; p2++) {
            int comparer = 0;

            if (choix == 1) {
                comparer = strcasecmp(p1->nom, p2->nom);
            } else if (choix == 2) {
                if (p1->noteGenerale < p2->noteGenerale) {
                    comparer = 1;
                } else if (p1->noteGenerale > p2->noteGenerale) {
                    comparer = -1;
                }
            } else if (choix == 3) {
                comparer = ;
            }

            if (comparer > 0) {
                help = *p1;
                *p1 = *p2;
                *p2 = help;
            }
        }
    }
    printf("Les etudiant ont ete tries.\n");
}
*/


/* ------------stastiques------------*/

void afficherTotalEtudiants(int *n){
    printf("Nombre total d'etudiants inscrits: %d\n",*n);
}

void afficherEtudiantsAuDessusSeuil(Etudiant *e, int *n, float seuil){
  int trv=0;
  if(*n==0){
    printf("Aucun etudiant disponible.\n");
    return ;
  }
  else{
    for(p=e;p<e+ *n;p++){
        if(p->noteGenerale > seuil){
            if (!trv) {
                printf("Les etudiants ayant une note superieure a %.2f:\n", seuil);
            }
            printf("les infos d'etu %d:\n",(p-e)+1);
            printf("Numero: %d\n",p->numero);
            printf("Nom: %s\n",p->nom);
            printf("Prenom: %s\n",p->prenom);
            printf("Date naissance: %d/%d/%d\n",p->naissance.jour,p->naissance.mois,p->naissance.annee);
            printf("Departement: %s\n",p->departement);
            printf("Note generale : %.2f\n",p->noteGenerale);
            trv=1;
        }
    }
    if(!trv){
    printf("Aucun etudiant n'a une note superieure a %.2f\n", seuil);
  }
  }

}


/*-------------Afficher le nombre d'étudiants ayant réussi dans chaque département-------------*/

void afficherNombreReussiteParDepartement(Etudiant *e, int *n) {
    if (*n == 0) {
        printf("Aucun étudiant disponible.\n");
        return;
    }

    // Tableaux pour stocker les départements et le nombre d'étudiants ayant réussi
    char departements[MAX_DEPARTEMENTS][TAILLE_DEPARTEMENT];
    int reussiteCount[MAX_DEPARTEMENTS] = {0};
    int departementCount = 0;

    // Itération sur chaque étudiant
    for (p = e; p < e + *n; p++) {
        if (p->noteGenerale >= 10) {
            // Chercher si le département est déjà dans le tableau
            int j;
            for (j = 0; j < departementCount; j++) {
                if (strcasecmp(p->departement, departements[j]) == 0) {
                    reussiteCount[j]++;
                    break;
                }
            }
            // Si le département n'est pas encore dans le tableau, l'ajouter
            if (j == departementCount) {
                strcpy(departements[departementCount], p->departement);
                reussiteCount[departementCount] = 1;
                departementCount++;
            }
        }
    }

    // Affichage des résultats
    printf("Nombre d'étudiants ayant réussi dans chaque département :\n");
    for (int i = 0; i < departementCount; i++) {
        printf("Departement: %s, Nombre d'etudiants ayant reussi: %d\n", departements[i], reussiteCount[i]);
    }
}

/*-------Afficher les 3 étudiants ayant les meilleures notes------*/

void afficherTop3Etudiants(Etudiant *e, int *n) {
    if (*n == 0) {
        printf("Aucun étudiant disponible.\n");
        return;
    }
    Etudiant temp ;

    // Trier les étudiants par note générale en ordre décroissant
    for (p=e;p<e+ *n;p++) {
        for (p1=p+1; p1 < *n; p1++) {
            if (p->noteGenerale<p1->noteGenerale) {
                 temp = *p;
                *p = *p1;
                *p1 = temp;
            }
        }
    }

    // Afficher les 3 meilleurs étudiants
    int limite = *n;
    if (*n > 3) {
        limite = 3; // Afficher seulement les 3 meilleurs
    }

    printf("Les 3 etudiants ayant les meilleures notes :\n");
    for (p=e; p<e+limite;p++) {
        printf("Les infos d'etudiant %d:\n", (p-e)+1);
        printf("Numero: %d\n", p->numero);
        printf("Nom: %s\n", p->nom);
        printf("Prenom: %s\n", p->prenom);
        printf("Date de naissance: %d/%d/%d\n", p->naissance.jour, p->naissance.mois, p->naissance.annee);
        printf("Departement: %s\n", p->departement);
        printf("Note genrale : %.2f\n", p->noteGenerale);
        printf("\n------------------------------\n");
    }
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
    printf("5:Rechercher un étudiant par son nom\n");
    printf("6:Afficher la liste des étudiants inscrits dans un département spécifique\n");
    printf("7:Claculer la moyenne de generale de chaque departement\n");
    printf("\n--------Menu Statistiques--------\n");
        printf("8. Afficher le nombre total d'étudiants inscrits\n");
        printf("9. Afficher le nombre d'étudiants dans chaque département\n");
        printf("10. Afficher les étudiants ayant une note supérieure à un certain seuil\n");
        printf("11. Afficher les 3 étudiants ayant les meilleures notes\n");
        printf("12. Afficher le nombre d'étudiants ayant réussi dans chaque département\n");
    printf("13:Quitter le programme\n");
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
        RechercherEtudiantParNom(e,&n,&nom);
       break;
    case 6: printf("Entrer  le nom du département que souhaite consulter les etudiants: ");
            scanf("%s",departement);
            AfficherEtudiantsParDepartement(e,n,&departement);
       break;
    case 7:  calcMoyenne(e,&n);
          break;
          case 8: afficherTotalEtudiants(&n);
          break;
          case 9:
          break;
          case 10: if(n==0){
                    printf("Aucun etudiant disponible.\n");
                    break ;
                    }
                  printf("Entrer le seuil: ");
                  scanf("%f",&seuil);
                  afficherEtudiantsAuDessusSeuil(e,&n,seuil);
          break;
          case 11:  afficherTop3Etudiants(e,&n);
          break;
          case 12:afficherNombreReussiteParDepartement(e,&n);
          break;
          case 13: printf("---------------Fin de programme1 !--------------- ");
          return 0;
          break;
    default : printf("le type de choix est incorrect\n");
       break;
    }
    }
    free(e);
    return 0;
}
