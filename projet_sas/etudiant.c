#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "etudiant.h"


#define MAX_DEPARTEMENTS 100
#define TAILLE_DEPARTEMENT 50
#define MAX_NOM_DEPARTEMENT 50


Etudiant *e=NULL;
int n = 0;
Etudiant *p,*p1,*p2;
int num;
int choix;

char nom[20];
char departement[20];
float seuil;
Etudiant help;

/*-----------Ajouter un etudiant-----------*/

void Ajouter(Etudiant *e,int *n){
     p = e + (*n - 1);   // Pointeur sur le dernier étudiant ajouté
     printf("Entrer les infos d'etu %d:\n",*n);
    printf("Entrer le numero: ");
    scanf("%d",&p->numero);
    printf("Entrer le nom: ");
    scanf("%s",p->nom);
    printf("Entrer le prenom: ");
    scanf("%s",p->prenom);
    printf("entrer la date de naissance (jour mois annee): ");
    do {
        scanf("%d %d %d", &p->naissance.jour, &p->naissance.mois, &p->naissance.annee);
        if (p->naissance.jour < 1 || p->naissance.jour > 31 ||
            p->naissance.mois < 1 || p->naissance.mois > 12 ||
            p->naissance.annee < 1900 || p->naissance.annee > 2024) {
            printf("Date invalide. Veuillez entrer une date valide (jour mois annee): ");
        }
    } while (p->naissance.jour < 1 || p->naissance.jour > 31 ||
             p->naissance.mois < 1 || p->naissance.mois > 12 ||
             p->naissance.annee < 1900 || p->naissance.annee > 2024);
    printf("Entrer la departement: ");
    scanf("%s",p->departement);
    do{
        printf("Entrer la note generale (entre 0 et 20): ");
        scanf("%f",&p->noteGenerale);
        if (p->noteGenerale < 0 || p->noteGenerale > 20) {
            printf("Erreur: La note doit etre comprise entre 0 et 20.\n");
        }
    }while(p->noteGenerale>20  || p->noteGenerale<0);
}


/*-----------Afficher les étudiants-----------*/

void Afficher(Etudiant *e, int *n) {
    if (*n == 0) {
        printf("Aucun etudiant disponible.\n");
        return;
    }

    printf("Liste des étudiants inscrits:\n");
    printf("-------------------------------------------------\n");

    for (p = e; p < e + *n; p++) {
        printf("Etudiant %d:\n", (p - e) + 1);
        printf("Numero: %d\n", p->numero);
        printf("Nom: %s\n", p->nom);
        printf("Prenom: %s\n", p->prenom);
        printf("Date de naissance: %02d/%02d/%d\n", p->naissance.jour, p->naissance.mois, p->naissance.annee);
        printf("Departement: %s\n", p->departement);
        printf("Note generale: %.2f\n", p->noteGenerale);
        printf("-------------------------------------------------\n");
    }
}


/*-----------Modifier un etudiant-----------*/

void Modifier(Etudiant *e, int *n, int *num) {
    int trouve = 0;

    for (p = e; p < e + *n; p++) {
        if (p->numero == *num) {
            trouve = 1;
            break;  // On sort de la boucle une fois l'étudiant trouvé
        }
    }

    if (trouve == 0) {
        printf("L'etudiant avec le numero %d n'a pas ete trouve.\n", *num);
        return;
    }
    printf("Entrer le nouveau numero: ");
    scanf("%d", &p->numero);
    printf("Entrer le nouveau nom: ");
    scanf("%s", p->nom);
    printf("Entrer le nouveau prenom: ");
    scanf("%s", p->prenom);
    // Saisie et validation de la nouvelle date de naissance
    int jour, mois, annee;
    do {
        printf("Entrer la nouvelle date de naissance (jour mois annee): ");
        scanf("%d %d %d", &jour, &mois, &annee);

        if (jour < 1 || jour > 31 || mois < 1 || mois > 12 || annee < 1900 || annee>2024) {
            printf("Date invalide. Veuillez reessayer.\n");
        }
    } while (jour < 1 || jour > 31 || mois < 1 || mois > 12 || annee < 1900 || annee>2024);

    // Affecter la date valide
    p->naissance.jour = jour;
    p->naissance.mois = mois;
    p->naissance.annee = annee;

    printf("Entrer le nouveau departement: ");
    scanf("%s", p->departement);

    // Validation et saisie de la note générale
    do {
        printf("Entrer la nouvelle note generale (0 à 20): ");
        scanf("%f", &p->noteGenerale);

        if (p->noteGenerale < 0 || p->noteGenerale > 20) {
            printf("Note invalide. Veuillez reessayer.\n");
        }
    } while (p->noteGenerale < 0 || p->noteGenerale > 20);

    printf("Les informations de l'etudiant ont ete modifiees.\n");
}


/*-----------Supprimer un etudiant-----------*/

void Supprimer(Etudiant *e, int *n, int *num) {
    int trv = 0;
    for (p = e; p < e + *n; p++) {
        if (p->numero == *num) {
            trv = 1;
            p1 = p;  // Pointeur sur l'étudiant à supprimer
            break;
        }
    }

    if (trv == 0) {
        printf("L'etudiant avec le numero %d n'a pas ete trouve.\n", *num);
        return;
    }
    for (p = p1; p < e + *n - 1; p++) {
        *p = *(p + 1);  // Déplace l'élément suivant dans la position actuelle
    }
    (*n)--;
    printf("L'etudiant avec le numero %d a ete supprime.\n", *num);
}


/*-----------Calculer et afficher la moyenne-----------*/

void calcMoyenne(Etudiant *e, int *n) {
    float sommeDepartement;
    float sommeGenerale = 0;
    float moyenne;
    int nbretu;
    int traite;

    // Calcul de la somme des notes pour la moyenne générale
    for (p = e; p < e + *n; p++) {
        sommeGenerale += p->noteGenerale;
    }

    // Calcul et affichage des moyennes par département
    for (p = e; p < e + *n; p++) {
        traite = 0;

        // Vérifier si le département a déjà été traité
        for (p1 = e; p1 < p; p1++) {
            if (strcmp(p->departement, p1->departement) == 0) {
                traite = 1;
                break;
            }
        }

        if (traite) continue;

        sommeDepartement = 0;
        nbretu = 0;

        // Calcul de la somme des notes et du nombre d'étudiants pour ce département
        for (p1 = e; p1 < e + *n; p1++) {
            if (strcmp(p->departement, p1->departement) == 0) {
                sommeDepartement += p1->noteGenerale;
                nbretu++;
            }
        }

        // Calcul et affichage de la moyenne pour le département
        if (nbretu > 0) {
            moyenne = sommeDepartement / nbretu;
            printf("La moyenne du departement %s est: %.2f\n", p->departement, moyenne);
        }
    }

    // Calcul et affichage de la moyenne générale
    if (*n > 0) {
        moyenne = sommeGenerale / (*n);
        printf("La moyenne generale de l'universite est: %.2f\n", moyenne);
    } else {
        printf("Aucun etudiant n'est inscrit.\n");
    }
}


/* ------------Statistiques------------ */

int obtenirTotalEtudiants(int n) {
    return n;
}

void compteEtudiantsDepartements(Etudiant *e, int n) {
    if (n == 0) {
        printf("Aucun etudiant disponible.\n");
        return;
    }

    int count[MAX_DEPARTEMENTS] = {0}; // Tableau pour compter les étudiants par département
    char departements[MAX_DEPARTEMENTS][MAX_NOM_DEPARTEMENT]; // Tableau pour stocker les noms des départements
    int num_departements = 0;

    // Compter le nombre d'étudiants dans chaque département
    for (int i = 0; i < n; i++) {
        int j;
        int trv = 0;
        for (j = 0; j < num_departements; j++) {
            if (strcmp(e[i].departement, departements[j]) == 0) {
                count[j]++;
                trv = 1;
                break;
            }
        }
        if (!trv) {
            strcpy(departements[num_departements], e[i].departement);
            count[num_departements] = 1;
            num_departements++;
        }
    }

    // Afficher les résultats
    printf("Nombre d'etudiants dans chaque departement :\n");
    for (int i = 0; i < num_departements; i++) {
        printf("Departement: %s, Nombre d'etudiants: %d\n", departements[i], count[i]);
    }
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


/*-------Afficher les 3 étudiants ayant les meilleures notes------*/

 void afficherTop3Etudiants(Etudiant *e, int *n) {
    if (*n == 0) {
        printf("Aucun étudiant disponible.\n");
        return;
    }
    Etudiant temp ;
    int i;

     // Tableau pour stocker les indices originaux avant le tri
     int indicesOriginaux[*n];
     for (i = 0; i < *n; i++) {
        indicesOriginaux[i] = i + 1;  // On stocke les indices originaux (1-based)
    }

    // Trier les étudiants par note générale en ordre décroissant
    for (p=e;p<e+ (*n-1);p++) {
        for (p1=p+1; p1 <e+ *n; p1++) {
            if (p->noteGenerale<p1->noteGenerale) {
                 temp = *p;
                *p = *p1;
                *p1 = temp;

                 // Échanger aussi leurs indices originaux
                int tempIndice = indicesOriginaux[p - e];
                indicesOriginaux[p - e] = indicesOriginaux[p1 - e];
                indicesOriginaux[p1 - e] = tempIndice;
            }
        }
    }

    // Afficher les 3 meilleurs étudiants
    int limite = *n;
    if (*n > 3) {
        limite = 3; // Afficher seulement les 3 meilleurs
    }

   printf("Les 3 étudiants ayant les meilleures notes :\n");
    for (i = 0; i < limite; i++) {
        p = e + i; // Pointer sur le premier etudiant
        printf("Les infos d'etudiant %d:\n", indicesOriginaux[i]);
        printf("Numero: %d\n", p->numero);
        printf("Nom: %s\n", p->nom);
        printf("Prenom: %s\n", p->prenom);
        printf("Date de naissance: %d/%d/%d\n", p->naissance.jour, p->naissance.mois, p->naissance.annee);
        printf("Departement: %s\n", p->departement);
        printf("Note generale : %.2f\n", p->noteGenerale);
        printf("\n------------------------------\n");
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
void AfficherEtudiantsParDepartement(Etudiant *e, int n, char *depart) {
    int nbretu = 0;
    int trouve = 0;  // Indique si des étudiants ont été trouvés

    printf("Les etudiants inscrits dans le departement %s sont:\n", depart);

    for (p = e; p < e + n; p++) {
        if (strcasecmp(p->departement, depart) == 0) {
            if (!trouve) {
                trouve = 1;  // Indique que des étudiants ont été trouvés
            }
            printf("Etudiant %d:\n", (p - e) + 1);
            printf("Numero: %d\n", p->numero);
            printf("Nom: %s\n", p->nom);
            printf("Prenom: %s\n", p->prenom);
            printf("Date de naissance: %d/%d/%d\n", p->naissance.jour, p->naissance.mois, p->naissance.annee);
            printf("Departement: %s\n", p->departement);
            printf("Note generale: %.2f\n", p->noteGenerale);
            nbretu++;
        }
    }

    if (!trouve) {
        printf("Aucun etudiant inscrit dans ce departement: %s\n", depart);
    } else {
        printf("Nombre d'etudiants dans le departement %s: %d\n", depart, nbretu);
    }
}


/*-------- Trie par nom--------*/

void trieParNom(Etudiant *e, int n){
     for (p1 = e; p1 < e + (n - 1); p1++) {   // le tri par sélection
        for (p2 = p1 + 1; p2 < e + n; p2++) {
        if(strcmp(p1->nom,p2->nom)>0){
           help = *p1;   // Echange des deux étudiants
           *p1 = *p2;
           *p2 = help;
         }
        }
    }
    printf("Les etudiants ont ete tries par nom (de A a Z).\n");
}

/*-------- Trie par note generale--------*/

void trieParNote(Etudiant *e, int n){
     for (p1 = e; p1 < e + (n - 1); p1++) {   // le tri par sélection
        for (p2 = p1 + 1; p2 < e + n; p2++) {
        if(p1->noteGenerale < p2->noteGenerale){
           help = *p1;   // Echange des deux étudiants
           *p1 = *p2;
           *p2 = help;
         }
        }
    }
    printf("Les etudiants ont ete tries par note generale,du plus eleve au plus faible.\n");
}



/*-------- Trie par stutue de reaussite--------*/

void trieParStatutReussite(Etudiant *e, int n) {
    Etudiant *p1, *p2;
    Etudiant help;

    for (p1 = e; p1 < e + (n - 1); p1++) {
        for (p2 = p1 + 1; p2 < e + n; p2++) {
            // Placer en premier ceux qui ont une moyenne >= 10
            if (p1->noteGenerale < 10 && p2->noteGenerale >= 10) {
                // Échanger les étudiants pour placer ceux qui réussissent en premier
                help = *p1;
                *p1 = *p2;
                *p2 = help;
            }
        }
    }
    printf("Les etudiants ont ete tries selon leur statut de reussite.\n");
}
