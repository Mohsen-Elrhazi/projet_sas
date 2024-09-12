#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "etudiant.h"



#define MAX_DEPARTEMENTS 100
#define TAILLE_DEPARTEMENT 50
#define MAX_NOM_DEPARTEMENT 50



int main()
{

  while (1) {
        printf("\n-------------MENU PRINCIPAL------------\n");
        printf("Que souhaitez-vous faire:\n");
        printf("1: Ajouter un etudiant\n");
        printf("2: Modifier ou supprimer un etudiant\n");
        printf("3: Afficher les details d'un etudiant\n");
        printf("4: Calculer la moyenne generale\n");
        printf("5: Statistiques\n");
        printf("6: Rechercher un etudiant\n");
        printf("7: Trier des etudiants\n");
        printf("0: Quitter\n");  // Option pour quitter le programme
        printf("-------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                n++;
                e = realloc(e, n * sizeof(Etudiant));
                if (e == NULL) {
                    printf("Erreur de réallocation de mémoire.\n");
                    exit(1);
                }
                Ajouter(e, &n);
                break;

            case 2:
                while (1) {
                    printf("\n--- MENU MODIFICATION/SUPPRESSION ---\n");
                    printf("Que souhaitez-vous faire:\n");
                    printf("1: Modifier les informations d'un etudiant\n");
                    printf("2: Supprimer les informations d'un etudiant\n");
                    printf("0: Quitter\n");
                    printf("Entrer votre choix: ");
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            printf("Entrer le numero d'etudiant a modifier: ");
                            scanf("%d", &num);
                            Modifier(e, &n, &num);
                            break;
                        case 2:
                            printf("Entrer le numero d'etudiant a supprimer: ");
                            scanf("%d", &num);
                            Supprimer(e, &n, &num);
                            break;
                        case 0:
                            break; // Quitter le sous-menu
                        default:
                            printf("Choix invalide. Veuillez essayer a nouveau.\n");
                            break;
                    }
                    if (choix == 0) break; // Quitter le sous-menu
                }
                break;

            case 3:
                Afficher(e, &n);
                break;

            case 4:
                calcMoyenne(e, &n);
                break;

            case 5:
                while (1) {
                    printf("\n--- MENU STATISTIQUES ---\n");
                    printf("1: Afficher le nombre total d'etudiants inscrits\n");
                    printf("2: Afficher le nombre d'etudiants dans chaque departement\n");
                    printf("3: Afficher les etudiants ayant une note superieure a un certain seuil\n");
                    printf("4: Afficher les 3 etudiants ayant les meilleures notes\n");
                    printf("5: Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
                    printf("0: Quitter statistiques\n");
                    printf("Entrer votre choix: ");
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            printf("Nombre total d'etudiants inscrits: %d\n",obtenirTotalEtudiants(&n));
                            break;
                        case 2:
                            compteEtudiantsDepartements(e, n);
                            break;
                        case 3:
                            printf("Entrer le seuil: ");
                            scanf("%f", &seuil);
                            afficherEtudiantsAuDessusSeuil(e, &n, seuil);
                            break;
                        case 4:
                            afficherTop3Etudiants(e, &n);
                            break;
                        case 5:
                            afficherNombreReussiteParDepartement(e, &n);
                            break;
                        case 0:
                            break; // Quitter le sous-menu
                        default:
                            printf("Choix invalide. Veuillez essayer a nouveau.\n");
                            break;
                    }
                    if (choix == 0) break; // Quitter le sous-menu
                }
                break;

            case 6:
                while (1) {
                    printf("\n--- MENU RECHERCHE ---\n");
                    printf("1: Rechercher un etudiant par son nom\n");
                    printf("2: Afficher la liste des etudiants inscrits dans un departement specifique\n");
                    printf("0: Quitter\n");
                    printf("Entrer votre choix: ");
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            printf("Entrer le nom d'etudiant a rechercher: ");
                            scanf("%s", nom);
                            RechercherEtudiantParNom(e, &n, nom);
                            break;
                        case 2:
                            printf("Entrer le nom du département que vous souhaitez consulter: ");
                            scanf("%s", departement);
                            AfficherEtudiantsParDepartement(e, n, &departement);
                            break;
                        case 0:
                            break; // Quitter le sous-menu
                        default:
                            printf("Choix invalide. Veuillez essayer a nouveau.\n");
                            break;
                    }
                    if (choix == 0) break; // Quitter le sous-menu
                }
                break;

            case 7:
                while (1) {
                    printf("\n--- MENU TRI ---\n");
                    printf("1: Tri alphabetique des etudiants en fonction de leur nom (de A à Z)\n");
                    printf("2: Tri des etudiants par moyenne generale, du plus eleve au plus faible\n");
                    printf("3: Tri des etudiants selon leur statut de reussite (note >= 10/20)\n");
                    printf("0: Quitter\n");
                    printf("Entrer votre choix: ");
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            trieParNom(e, n);
                            break;
                        case 2:
                            trieParNote(e, n);
                            break;
                        case 3:
                            trieParStatutReussite(e, n);
                            break;
                        case 0:
                            break; // Quitter le sous-menu
                        default:
                            printf("Choix invalide. Veuillez essayer a nouveau.\n");
                            break;
                    }
                    if (choix == 0) break; // Quitter le sous-menu
                }
                break;

            case 8:
                printf("---------------Fin de programme !---------------\n");
                return 0;

            default:
                printf("Choix invalide. Veuillez essayer a nouveau.\n");
                break;
        }
    }
    free(e);
    return 0;
}
