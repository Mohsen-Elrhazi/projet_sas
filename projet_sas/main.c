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
char departement[20];

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
    printf("\n------------------------------");
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
        RechercherEtudiantParNom(e,&n,&nom);
       break;
    case 6: printf("Entrer  le nom du département que souhaite consulter les etudiants: ");
            scanf("%s",departement);
            AfficherEtudiantsParDepartement(e,n,&departement);
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
