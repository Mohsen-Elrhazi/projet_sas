#ifndef ETUDIANT_H
#define ETUDIANT_H


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


extern Etudiant *e;
extern int n;
extern Etudiant *p,*p1,*p2;
extern int num;
extern int choix;
extern char nom[20];
extern char departement[20];
extern float seuil;
extern Etudiant help;

void Ajouter(Etudiant *e, int *n);
void Modifier(Etudiant *e, int *n, int *num);
void Supprimer(Etudiant *e, int *n, int *num);
void Afficher(Etudiant *e, int *n);
void calcMoyenne(Etudiant *e, int *n);
int afficherTotalEtudiants(int *n);
void compteEtudiantsDepartements(Etudiant *e, int n);
void afficherEtudiantsAuDessusSeuil(Etudiant *e, int *n, float seuil);
void afficherTop3Etudiants(Etudiant *e, int *n);
void afficherNombreReussiteParDepartement(Etudiant *e, int *n);
void RechercherEtudiantParNom(Etudiant *e, int *n, char *nom);
void AfficherEtudiantsParDepartement(Etudiant *e, int n, char *depart);
void trieParNom(Etudiant *e, int n);
void trieParNote(Etudiant *e, int n);
void trieParStatutReussite(Etudiant *e, int n);


#endif /


