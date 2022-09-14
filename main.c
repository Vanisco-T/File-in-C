#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct candidat candidat;
struct candidat
    {
        char nom[100];
        char prenoms[100];
        int age;
        int notes[10];//10.00000 POUR AFFICHER LES NOTES 0 DEUX CHIFFRES APRES LA VIRGULE ON FAIT "%.2f"
        int ncni;
        char DECISION[10];
        float moy;
    };

typedef struct CONCOURS CONCOURS;
struct CONCOURS
{
    candidat CANDIDAT[1000];
};//1000 candidats maximum dans le concours

//Declaration des prototypes des fonctions
void saisir(const char* filename);//FONCTIONNE BIEN
char* statut(const char* som);//FONCTIONNE BIEN
void ajouter(const char* filename);//FONCTIONNE BIEN
void modifier();//
void supprimer();//
char* admis(const char* filename);
void attente(const char* filename);
void statistiques();
void supprimer_plus();
void affiche_merite();
int nbr_candidats();//On va compter le nombre de lignes du fichier et retourner le nombre de ligne -1 comme etan,yt le nombre de candidats
int nbr_candidats_admis();
void recherche();
void menu();
void supprimer1();
void supprimer2();
void modifier1();
void modifier2();
int nbr_candidats()
{
    int nbre_lignes = 0, nbre_candidats = 0;
    char c1=' ';
    FILE*fic=fopen("concour.txt", "r");
    if(fic == NULL)
        exit(1);
    if(fic != NULL)
    {
        while((c1=fgetc(fic))!=EOF)
        {
            if(c1 == '\n')
            {
               nbre_lignes++;
            }
        }
        if((c1=fgetc(fic))==EOF)
        {
           nbre_candidats=nbre_lignes;
                return nbre_candidats;
        }
            /*if(nbre_lignes == 0)
            {
                nbre_lignes++;
                nbre_candidats=nbre_lignes;
                return nbre_candidats;
            }*/
            if(nbre_lignes >= 1)
            {
                nbre_candidats=nbre_lignes;
                return nbre_candidats;
            }
        fclose(fic);
    }
}//correct
int nbr_candidats_admis()
{
    int nbre_lignes = 0, nbre_candidats = 0;
    char c1=' ';
    FILE*fic2=fopen("admis.txt", "r");
    if(fic2== NULL)
        exit(1);
    if(fic2 != NULL)
    {
        while((c1=fgetc(fic2))!=EOF)
        {
            if(c1 == '\n')
            {
               nbre_lignes++;
            }
        }
        if((c1=fgetc(fic2))==EOF)
        {
           nbre_candidats=nbre_lignes;
                return nbre_candidats;
        }
            /*if(nbre_lignes == 0)
            {
                nbre_lignes++;
                nbre_candidats=nbre_lignes;
                return nbre_candidats;
            }*/
            if(nbre_lignes >= 1)
            {
                nbre_candidats=nbre_lignes;
                return nbre_candidats;
            }
        fclose(fic2);
    }
}//correct
//defijnition de la fonction saisir
void saisir(const char* filename)
{
    candidat CANDIDAT[1000];
    int choix_saisir = 0, matiere_num = 1, cpt_sous = 0, cpt_note = 0, nbr_candidat1 = 0, nbre_candidats, carte=0, temp_carte=0;
    float som_notes = 0, moy_generale = 0;
    char c=' ';
    // on initialise les données necessaires au calcul de decision ici pour qu'il soit reinitialisé à la boucle
FILE*fic3=fopen("concour.txt", "a");
FILE*fic=fopen("concours.txt", "a");
if(fic == NULL)
    exit(1);
if(fic != NULL)
{
    nbre_candidats=nbr_candidats();
    do{
    	if(nbre_candidats == 1)
    	{
    		printf("                                   Saisie des information du candidat dans le fichier                                    \n");
    	}
    	else
    	{
    		printf("le nombre de candidats actuellement dans le concours est: %d\n", nbre_candidats);
            nbre_candidats++;
            printf("Information du candidat %d\n",nbre_candidats);
    	}
        printf("Entrez le nom du candidat:");
        scanf("%s", &CANDIDAT[nbre_candidats].nom);//IL YA UNE FAILLE DANS LE NOMS ET LE PRENOMS C7 QUE ON NE PEUT PAS ENTRER DEUX A LA  FOIS
        printf("%s\n", &CANDIDAT[nbre_candidats].nom);
        printf("Entrez le prenoms du candidat: ");
        scanf("%s", &CANDIDAT[nbre_candidats].prenoms);
        carte=0;
        printf("Entrez le ncin du candidat (MAX 10 CHIFFRES):");
        scanf("%d", &carte);

        printf("Entrez l'age du candidat n: ");
        scanf("%d", &CANDIDAT[nbre_candidats].age);
        fputs("\n", fic3);
        fputs("\n", fic);
        for(matiere_num=1; matiere_num<=10; matiere_num++)
        {
            printf("Entrez la note obtenue par le candidat a la matiere numero %d: ", matiere_num);
            scanf("%d", &CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic, "%d", CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic, "%c", ';');
            fprintf(fic3, "%d", CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic3, "%c", c);
            if(CANDIDAT[nbre_candidats].notes[matiere_num]<10)
            {
                cpt_sous+=1;
            }
            som_notes+=CANDIDAT[nbre_candidats].notes[matiere_num];
        }
        for(matiere_num=1; matiere_num<=10; matiere_num++)
        {
            printf("%d ", CANDIDAT[nbre_candidats].notes[matiere_num]);
        }
        char* statut(float som_notes)
{
    moy_generale = som_notes/10;
        if(moy_generale>=10 && cpt_sous == 0)
        {
            return"Admis";
        }
        else if(moy_generale>=10 && cpt_sous >= 1)
        {
            return"Ajourné";
            //fprintf(fic3, "%.2f", moy_generale);
            //fprintf(fic3, "%c", c);
        }
        else if(moy_generale<10 && cpt_sous >= 1)
        {
            return"Refusé";
        }
        else
            {
              return"Desole Exception non gere dans le concours";
}
            }

        printf("%s %s %d %d %s\n", CANDIDAT[nbre_candidats].nom, CANDIDAT[nbre_candidats].prenoms, carte, CANDIDAT[nbre_candidats].age, statut(som_notes));
        fputs(CANDIDAT[nbre_candidats].nom, fic);
        fputs(";", fic);
        fputs(CANDIDAT[nbre_candidats].prenoms, fic);
        fputs(";", fic);
        //atoi(CANDIDAT[nbre_candidats].ncni);
        fprintf(fic, "%d", carte);//IL FAUDRA FAIRE UNASCII TO INT PLUTARD SI NECESSAIRE
        fputs(";", fic);
        fprintf(fic, "%d", CANDIDAT[nbre_candidats].age);
        fputs(";", fic);
        fputs(statut(som_notes), fic);
        fputs(";", fic);
        fprintf(fic3, "%.2f", moy_generale);
        fprintf(fic3, "%c", c);
        fputs(CANDIDAT[nbre_candidats].nom, fic3);
        fprintf(fic3, "%c", c);
        fputs(CANDIDAT[nbre_candidats].prenoms, fic3);
        fprintf(fic3, "%c", c);
        fprintf(fic3, "%d", carte);
        fprintf(fic3, "%c", c);
        fprintf(fic3, "%d", CANDIDAT[nbre_candidats].age);
        fprintf(fic3, "%c", c);
        fputs(statut(som_notes), fic3);
        strcpy(CANDIDAT[nbre_candidats].DECISION, statut(som_notes));
        printf("%s\n", CANDIDAT[nbre_candidats].DECISION);
        printf("\nvoulez vous saisir les informations du nouveau candidat dans le fichier concour.txt ? 1/0 1(oui) et 0(non): ");
        scanf("%d", &choix_saisir);
        matiere_num=1;
        cpt_sous=0;
        som_notes=0;
        moy_generale=0;
        carte=0;
}while(choix_saisir == 1);//i inferieur à 1000 nombre de candidat max
fclose(fic);
}
fclose(fic3);
}

//definition de la fonction ajouter elle est presque similaire à la fonction saisir sauf que il n'ya pas de boucle sauf que ici on demande a l'utilsateur le numero du cnadidat qu'il veut ajouter
void ajouter(const char* filename)
{
    candidat CANDIDAT[1000];
    int choix_ajouter = 0, matiere_num = 1, cpt_sous = 0, cpt_note = 0, nbr_candidat1 = 0, nbre_candidats, carte=0, temp_carte=0;
    float som_notes = 0, moy_generale = 0;
    char c=' ';
    // on initialise les données necessaires au calcul de decision ici pour qu'il soit reinitialisé à la boucle
FILE*fic3=fopen("concour.txt", "a");
FILE*fic=fopen("concours.txt", "a");
if(fic == NULL)
    exit(1);
if(fic != NULL)
{
        nbre_candidats=nbr_candidats();
    do{
    	if(nbre_candidats == 1)
    	{
    		printf("                                   Saisie des information du candidat dans le fichier                                    \n");
    	}
    	else
    	{
    		printf("le nombre de candidats actuellement dans le concours est: %d\n", nbre_candidats);
            nbre_candidats++;
            printf("Information du candidat %d\n",nbre_candidats);
    	}
        printf("Entrez le nom du candidat:");
        scanf("%s", &CANDIDAT[nbre_candidats].nom);//IL YA UNE FAILLE DANS LE NOMS ET LE PRENOMS C7 QUE ON NE PEUT PAS ENTRER DEUX A LA  FOIS
        printf("%s\n", &CANDIDAT[nbre_candidats].nom);
        printf("Entrez le prenoms du candidat: ");
        scanf("%s", &CANDIDAT[nbre_candidats].prenoms);
        printf("Entrez le ncin du candidat (MAX 10 CHIFFRES):");
        scanf("%d", &carte);

        printf("Entrez l'age du candidat n: ");
        scanf("%d", &CANDIDAT[nbre_candidats].age);
        fputs("\n", fic3);
        fputs("\n", fic);
        for(matiere_num=1; matiere_num<=10; matiere_num++)
        {
            printf("Entrez la note obtenue par le candidat a la matiere numero %d: ", matiere_num);
            scanf("%d", &CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic, "%d", CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic, "%c", ';');
            fprintf(fic3, "%d", CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic3, "%c", c);
            if(CANDIDAT[nbre_candidats].notes[matiere_num]<10)
            {
                cpt_sous+=1;
            }
            som_notes+=CANDIDAT[nbre_candidats].notes[matiere_num];
        }
        for(matiere_num=1; matiere_num<=10; matiere_num++)
        {
            printf("%d ", CANDIDAT[nbre_candidats].notes[matiere_num]);
        }
        char* statut(float som_notes)
{
    moy_generale = som_notes/10;
        if(moy_generale>=10 && cpt_sous == 0)
        {
            return"Admis";
        }
        else if(moy_generale>=10 && cpt_sous >= 1)
        {
            return"Ajourné";
            //fprintf(fic3, "%.2f", moy_generale);
            //fprintf(fic3, "%c", c);
        }
        else if(moy_generale<10 && cpt_sous >= 1)
        {
            return"Refusé";
        }
        else
            {
              return"Desole Exception non gere dans le concours";
}
            }

        printf("%s %s %d %d %s\n", CANDIDAT[nbre_candidats].nom, CANDIDAT[nbre_candidats].prenoms, carte, CANDIDAT[nbre_candidats].age, statut(som_notes));
        fputs(CANDIDAT[nbre_candidats].nom, fic);
        fputs(";", fic);
        fputs(CANDIDAT[nbre_candidats].prenoms, fic);
        fputs(";", fic);
        //atoi(CANDIDAT[nbre_candidats].ncni);
        fprintf(fic, "%d", carte);//IL FAUDRA FAIRE UNASCII TO INT PLUTARD SI NECESSAIRE
        fputs(";", fic);
        fprintf(fic, "%d", CANDIDAT[nbre_candidats].age);
        fputs(";", fic);
        fputs(statut(som_notes), fic);
        fputs(";", fic);
        fprintf(fic3, "%.2f", moy_generale);
        fprintf(fic3, "%c", c);
        fputs(CANDIDAT[nbre_candidats].nom, fic3);
        fprintf(fic3, "%c", c);
        fputs(CANDIDAT[nbre_candidats].prenoms, fic3);
        fprintf(fic3, "%c", c);
        fprintf(fic3, "%d", carte);
        fprintf(fic3, "%c", c);
        fprintf(fic3, "%d", CANDIDAT[nbre_candidats].age);
        fprintf(fic3, "%c", c);
        fputs(statut(som_notes), fic3);
        strcpy(CANDIDAT[nbre_candidats].DECISION, statut(som_notes));
        printf("%s\n", CANDIDAT[nbre_candidats].DECISION);
        printf("\nvoulez vous ajouter un nouveau candidat dans le fichier concours.txt ? 1/0 1(oui) et 0(non): ");
        scanf("%d", &choix_ajouter);
        matiere_num=1;
        cpt_sous=0;
        som_notes=0;
        moy_generale=0;
        carte=0;
        //nbr_candidat2+=1;
        //nbr_candidat1+=nbr_candidat2;
    }while(choix_ajouter == 1);
fclose(fic);
}
fclose(fic3);
}

char* admis(const char* filename)//On va parcourir tout les candidat et verifier si la chaine decision est égale à "Admis" ou "Ajourné" ou "Refusé"
{
    //char str1[1000]="", str2[1000]="";
    candidat CANDIDAT[1000];
    int i = 1, age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2= 0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    FILE*fic3=fopen("concour.txt", "r");
    if(fic3 == NULL)
    exit(1);
    if(fic3 != NULL)
    {
        FILE*fic2=fopen("admis.txt", "w");
        if(fic2 != NULL)
        {
            while(fgets(texte_total_fichier, 1000, fic3) != NULL)
            {
                fscanf(fic3,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                //printf("\n%d %d %d %d %d %d %d %d %d %d %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, nom, prenom, ncni, age, decision);
                if((strcmp(decision, "Admis")) == 0)
                {
                    fprintf(fic2, "\n%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, moy_sur_20, nom, prenom, ncni2, age, decision);
                }
                printf("%s\n", decision);
            }

        fclose(fic2);
        }

    fclose(fic3);
    }
    }

void attente(const char* filename)
{
    int i = 0, age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2= 0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    FILE*fic2=fopen("admis.txt", "r");
    if(fic2 == NULL)
    exit(1);
    if(fic2 != NULL)
    {
        FILE*fic1=fopen("attente.txt", "w");
        if(fic1 != NULL)
        {
            while(fgets(texte_total_fichier, 1000, fic2) != NULL)
            {
                i++;
                fscanf(fic2,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                //printf("\n%d %d %d %d %d %d %d %d %d %d %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, nom, prenom, ncni, age, decision);
                if((strcmp(decision, "Admis")) == 0 && age>20)
                {
                    fprintf(fic1, "\n%d;%s;%s", ncni2, nom, prenom);
                }
                printf("l'age du candidat %d est : %d\n", i, age);
            }

        fclose(fic1);
        }

    fclose(fic2);
    }

}

void statistiques()//la fonction ci dessous fonctionne mais seulement il faut ecrire une fonctionc apable de compter le nombre de candidat à partir du fichier concours.txt et de afire par exemple que si on est à la ligne 3 on fait ressortir la decision du candidat 3 et utiliser le nombre totale de ligne du fichier comme etant le nombre de candidat total
{
    int age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2= 0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    float prctage_admis, prctage_ajourne, prctage_refuse;
    float cpt_admis=0, cpt_ajourne=0, cpt_refuse=0, nbre_candidats, i, total=0;
    FILE*fic3=fopen("concour.txt", "r");
    if(fic3 == NULL)
    exit(1);
    if(fic3 != NULL)
    {
        while(fgets(texte_total_fichier, 1000, fic3) != NULL)
            {
                fscanf(fic3,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                //printf("\n%d %d %d %d %d %d %d %d %d %d %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, nom, prenom, ncni, age, decision);
                if((strcmp(decision, "Admis")) == 0)
                {
                  cpt_admis++;
                }
                if((strcmp(decision, "Refusé")) == 0)
                {
                    cpt_refuse++;
                }
                if((strcmp(decision, "Ajourné")) == 0)
                {
                    cpt_ajourne++;
                }
            }
    fclose(fic3);
    }
    total=nbr_candidats("concour.txt");
    printf("compteur admis: %.1f\n", cpt_admis);
    printf("Le nombre total de candidat est: %.1f\n", total);
   prctage_admis=cpt_admis*100/total;
   prctage_ajourne=cpt_ajourne*100/total;
   prctage_refuse=cpt_refuse*100/total;
FILE*fic4=fopen("stats.txt", "w");
if(fic4 == NULL)
    exit(1);
if(fic4 != NULL)
{
    fputs("\nPourcentage des admis ", fic4);
    fprintf(fic4, "%.2f\n", prctage_admis);
    fputs("\nPourcentage des ajourné ", fic4);
    fprintf(fic4, "%.2f\n", prctage_ajourne);
    fputs("\nPourcentage des refuse ", fic4);
    fprintf(fic4, "%.2f", prctage_refuse);
    fclose(fic4);
}
printf("Les pourcentages sont: -Admis: %.2f\n                       -Ajourné: %.2f\n                       -Refusé: %.2f\n", prctage_admis, prctage_ajourne, prctage_refuse);
}
void supprimer_plus()
{
    int age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2=0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    float prctage_admis, prctage_ajourne, prctage_refuse;
    float cpt_admis=0, cpt_ajourne=0, cpt_refuse=0, nbre_candidats, i, total=0;
    FILE*fic2=fopen("admis.txt", "r");
    if(fic2 == NULL)
    exit(1);
    if(fic2 != NULL)
    {
        FILE*fic5=fopen("admis_temp", "w");
        if(fic5 != NULL)
        {
             while(fgets(texte_total_fichier, 1000, fic2) != NULL)
            {
                fscanf(fic2,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                if(age<20)
                {
                    fprintf(fic5, "\n%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, moy_sur_20, nom, prenom, ncni2, age, decision);
                }

        }
       fclose(fic5);
    }
    fclose(fic2);
    }
    remove("admis.txt");
    rename("admis_temp", "admis.txt");
}

void supprimer1()
{
    int age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2=0, ncni4=0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    float prctage_admis, prctage_ajourne, prctage_refuse;
    float cpt_admis=0, cpt_ajourne=0, cpt_refuse=0, nbre_candidats, i, total=0;
    FILE*fic3=fopen("concour.txt", "r");
    if(fic3 == NULL)
    exit(1);
    if(fic3 != NULL)
    {
        printf("\nEntrez le numero de CNI du candidat à supprimer:  ");
        scanf("%d", &ncni4);
        FILE*fic8=fopen("concour_tmp", "w");
        if(fic8 != NULL)
        {
             while(fgets(texte_total_fichier, 1000, fic3) != NULL)
            {
                fscanf(fic3,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                if(ncni4 != ncni2)
                {
                    fprintf(fic8, "\n%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, moy_sur_20, nom, prenom, ncni2, age, decision);
                }

        }
       fclose(fic8);
    }
    fclose(fic3);
    }
    remove("concour.txt");
    rename("concour_tmp", "concour.txt");
}

void supprimer2()
{
    int age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2=0, ncni4=0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    float prctage_admis, prctage_ajourne, prctage_refuse;
    float cpt_admis=0, cpt_ajourne=0, cpt_refuse=0, nbre_candidats, i, total=0;
    FILE*fic3=fopen("concour.txt", "r");
    if(fic3 == NULL)
    exit(1);
    if(fic3 != NULL)
    {
        FILE*fic=fopen("concours.txt", "w");
        if(fic != NULL)
        {
             while(fgets(texte_total_fichier, 1000, fic3) != NULL)
            {
                fscanf(fic3,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                fprintf(fic, "\n%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%s;%s;%d;%d;%s;", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, nom, prenom, ncni2, age, decision);
                }
       fclose(fic);
    }
    fclose(fic3);
    }
}

void supprimer()
{
    supprimer1();
    supprimer2();
}

void modifier1()
{
    candidat CANDIDAT[1000];
    int choix_saisir = 0, matiere_num = 1, cpt_sous = 0, cpt_note = 0, nbr_candidat1 = 0, nbre_candidats, carte=0, temp_carte=0;
    float som_notes = 0, moy_generale = 0;
    int age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2=0, ncni4=0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000], c=' ';
    float prctage_admis, prctage_ajourne, prctage_refuse;
    float cpt_admis=0, cpt_ajourne=0, cpt_refuse=0, total=0;
    FILE*fic3=fopen("concour.txt", "r");
    if(fic3 == NULL)
    exit(1);
    if(fic3 != NULL)
    {
        printf("\nEntrez le numero de CNI du candidat dont vous voulez modifier le contenu :  ");
        scanf("%d", &ncni4);
        FILE*fic8=fopen("concour_tmp", "w");
        if(fic8 != NULL)
        {
             while(fgets(texte_total_fichier, 1000, fic3) != NULL)
            {
                fscanf(fic3,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                if(ncni4 != ncni2)
                {
                    fprintf(fic8, "\n%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, moy_sur_20, nom, prenom, ncni2, age, decision);
                }

        }

        //Ici on fait une fonction saisir modifiée
        printf("Entrez le nom du candidat:");
        scanf("%s", &CANDIDAT[nbre_candidats].nom);//IL YA UNE FAILLE DANS LE NOMS ET LE PRENOMS C7 QUE ON NE PEUT PAS ENTRER DEUX A LA  FOIS
        printf("%s\n", &CANDIDAT[nbre_candidats].nom);
        printf("Entrez le prenoms du candidat: ");
        scanf("%s", &CANDIDAT[nbre_candidats].prenoms);
        printf("Entrez le ncin du candidat (MAX 10 CHIFFRES):");
        scanf("%d", &carte);

        printf("Entrez l'age du candidat n: ");
        scanf("%d", &CANDIDAT[nbre_candidats].age);
        fputs("\n", fic8);
        for(matiere_num=1; matiere_num<=10; matiere_num++)
        {
            printf("Entrez la note obtenue par le candidat a la matiere numero %d: ", matiere_num);
            scanf("%d", &CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic8, "%d", CANDIDAT[nbre_candidats].notes[matiere_num]);
            fprintf(fic8, "%c", c);
            if(CANDIDAT[nbre_candidats].notes[matiere_num]<10)
            {
                cpt_sous+=1;
            }
            som_notes+=CANDIDAT[nbre_candidats].notes[matiere_num];
        }
        for(matiere_num=1; matiere_num<=10; matiere_num++)
        {
            printf("%d ", CANDIDAT[nbre_candidats].notes[matiere_num]);
        }
        char* statut(float som_notes)
{
    moy_generale = som_notes/10;
        if(moy_generale>=10 && cpt_sous == 0)
        {
            return"Admis";
        }
        else if(moy_generale>=10 && cpt_sous >= 1)
        {
            return"Ajourné";
        }
        else if(moy_generale<10 && cpt_sous >= 1)
        {
            return"Refusé";
        }
        else
            {
              return"Desole Exception non gere dans le concours";
}
            }

        printf("%s %s %d %d %s\n", CANDIDAT[nbre_candidats].nom, CANDIDAT[nbre_candidats].prenoms, carte, CANDIDAT[nbre_candidats].age, statut(som_notes));
        fprintf(fic8, "%.2f", moy_generale);
        fprintf(fic8, "%c", c);
        fputs(CANDIDAT[nbre_candidats].nom, fic8);
        fprintf(fic8, "%c", c);
        fputs(CANDIDAT[nbre_candidats].prenoms, fic8);
        fprintf(fic8, "%c", c);
        fprintf(fic8, "%d", carte);
        fprintf(fic8, "%c", c);
        fprintf(fic8, "%d", CANDIDAT[nbre_candidats].age);
        fprintf(fic8, "%c", c);
        fputs(statut(som_notes), fic8);
        strcpy(CANDIDAT[nbre_candidats].DECISION, statut(som_notes));
        printf("%s\n", CANDIDAT[nbre_candidats].DECISION);

       fclose(fic8);
    }
    fclose(fic3);
    }
}

void modifier2()
{
    int age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2=0, ncni4=0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    float prctage_admis, prctage_ajourne, prctage_refuse;
    float cpt_admis=0, cpt_ajourne=0, cpt_refuse=0, nbre_candidats, i, total=0;
    FILE*fic8=fopen("concour_tmp", "r");
    if(fic8 == NULL)
    exit(1);
    if(fic8 != NULL)
    {
        FILE*fic=fopen("concours.txt", "w");
        FILE*fic3=fopen("concour.txt", "w");
        if(fic != NULL && fic3 != NULL)
        {
             while(fgets(texte_total_fichier, 1000, fic8) != NULL)
            {
                fscanf(fic8,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                fprintf(fic, "\n%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%s;%s;%d;%d;%s;", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, nom, prenom, ncni2, age, decision);
                fprintf(fic3, "\n%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, moy_sur_20, nom, prenom, ncni2, age, decision);
            }
       fclose(fic3);
       fclose(fic);
    }
    fclose(fic8);
    }
    remove("concour_tmp");
}

void modifier()
{
    modifier1();
    modifier2();
}

void recherche()
{
    int age = 0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2= 0, ncni, trouve=0;
    float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000];
    FILE*fic3=fopen("concour.txt", "r");
    if(fic3 == NULL)
    exit(1);
    if(fic3 != NULL)
    {            printf("Quel est le numero de cni du candidat dont vous voulez afficher les informations ?: ");
                 scanf("%d", &ncni);
        while(fgets(texte_total_fichier, 1000, fic3) != NULL)
            {
                fscanf(fic3,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &moy_sur_20, nom, prenom, &ncni2, &age, decision);
                if(ncni == ncni2)
                {
                    trouve=1;
                    printf("\nLes informations relatives au candidats dont vous avez entré le ncni sont: -Moyenne sur 20: %.2f\n                                                                           -Nom: %s\n                                                                           -Prenoms: %s\n                                                                           -Numero de la CNI: %d\n                                                                           -Age: %d\n                                                                           -Décision: %s\n", moy_sur_20, nom, prenom, ncni2, age, decision);
                    break;
                }
                else if(trouve=0)
		printf("le candidat de numero de CNI %d n'exite pas .\n", ncni);
		break;
        }

}
fclose(fic3);
}


void affiche_merite()
{
    candidat CANDIDAT[1000];
    int age = 0, age2=0;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, ncni2= 0, ncni4=0;
    //float moy_sur_20;
    char texte_total_fichier[1001], decision[10], prenom[1000], nom[1000], notes[1000], decision2[10], prenom2[1000], nom2[1000];
    int nbre_candidats, i=0;
    nbre_candidats=nbr_candidats_admis("admis.txt");
    printf("%d\n", nbre_candidats);
    float T[nbre_candidats];
    FILE*fic2=fopen("admis.txt", "r");
    if(fic2 == NULL)
    exit(1);
    if(fic2 != NULL)
    {
        FILE*fic6=fopen("affiche_merite.txt", "w");
    if(fic6 != NULL)
    {
       while(fgets(texte_total_fichier, 1000, fic2) != NULL)
        {
            i++;
            fscanf(fic2,"%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &CANDIDAT[i].moy, CANDIDAT[i].nom, CANDIDAT[i].prenoms, &CANDIDAT[i].ncni, &CANDIDAT[i].age, CANDIDAT[i].DECISION);
            /*T[i]=moy_sur_20;
            strcpy(nom2, nom);
            strcpy(prenom2, prenom);
            age2=age;
            ncni4=ncni2;*/
            printf("%d %d %d %d %d %d %d %d %d %d %f %s %s %d %d %s\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, CANDIDAT[i].moy, CANDIDAT[i].nom, CANDIDAT[i].prenoms, CANDIDAT[i].ncni, CANDIDAT[i].age, CANDIDAT[i].DECISION);
            //printf("%.2f\n", CANDIDAT[i].moy);
        }
        for(i=1; i<=nbre_candidats; i++)
        { int booleen=0;
            for(int j=1; j<=nbre_candidats; j++)
            {
                if(CANDIDAT[i].moy>CANDIDAT[i+1].moy)
                {
                    booleen=1;
                }
            }
            if(booleen != 1)
                printf("La table n'est pas triée\n");
        }
        {
            i++;
            //On teste pour voir si les valeurs sont corrcetement stockées
            //printf("%f %s %s %d %d %s\n", CANDIDAT[i].moy, CANDIDAT[i].nom, CANDIDAT[i].prenoms, CANDIDAT[i].ncni, CANDIDAT[i].age, CANDIDAT[i].DECISION);
            /*if(CANDIDAT[i].moy>=CANDIDAT[i+1].moy)
            {
                int position_curseur = -1;
                position_curseur=ftell(fic6);
                fseek(fic6, 0, position_curseur);
                fprintf(fic2,"%f %s %s %d %d %s", CANDIDAT[i].moy, CANDIDAT[i].nom, CANDIDAT[i].prenoms, CANDIDAT[i].ncni, CANDIDAT[i].age, CANDIDAT[i].DECISION);

            }
            else if(CANDIDAT[i].moy<CANDIDAT[i+1].moy)
            {
                fprintf(fic2,"%f %s %s %d %d %s", CANDIDAT[i].moy, CANDIDAT[i].nom, CANDIDAT[i].prenoms, CANDIDAT[i].ncni, CANDIDAT[i].age, CANDIDAT[i].DECISION);
            }*/
        }
        fprintf(fic6,"%f %s %s %d %d %s", CANDIDAT[i].moy, CANDIDAT[i].nom, CANDIDAT[i].prenoms, CANDIDAT[i].ncni, CANDIDAT[i].age, CANDIDAT[i].DECISION);
        fclose(fic6);
    }
     fclose(fic2);
    }
}
//J'ecris la fonction menu ici pour l'appeler dans le main lorsque besoin sera
void menu()
{
    int acceder = 0, choix = 0, continuer = 0;
    do
    {
        printf("========================================================================================================================");
        printf("\n\n                            ***************Bienvenue dans le menu du logiciel***************                            \n\n________________________________________________________________________________________________________________________\n|                                           Selectionnez une option au choix                                           |________________________________________________________________________________________________________________________\n\n");
        printf("1- Saisir les informations relatives aux                                        6- Produire le fichier (attente.txt)\ncandidat dans le fichier (concours.txt)\n\n2- Ajouter les informations relatives au                                        7- Afficher le pourcentages du concours candidat dans le fichier (concours.txt)                                                      (admis, ajournés, refusés)\n \n3- Modifier les informations d'un candi-                                        8- Supprimer du fichier admis.txt les \ndat                                                                                    candidats agés de plus de 20ans\n\n4-Supprimer un candidat dans le fichier*                                        9- Afficher les candidats par ordre de \nconcours.txt                                                                                              merite\n\n5-Creer le fichier *admis.txt*                                                  10- Rechercher et afficher les infor                                                                                                       mations d'un canditat");
        printf("\n\n                                                     Votre choix ?: ");
        scanf("%d", &choix);
        switch(choix)
        {
            case 1: saisir("concours.txt");
            break;
            case 2: ajouter("concours.txt");
            break;
            case 3: modifier();
                //printf("\n\n\n                                      Desole la fonction mofifier n'est pas encore disponible pour le moment.  Merci                                       \n");
            break;
            case 4: supprimer();
            case 5: admis("concour.txt");
            break;
            case 6: attente("admis.txt");
            break;
            case 7: statistiques();
            break;
            case 8: supprimer_plus();
            break;
            case 9: affiche_merite ("admis.txt");
            //printf("\n\n\n                Desole la fonction affiche_merite n'est pas encore disponible pour le moment.  Merci                                          \n");
            break;
            case 10: recherche();
            break;
            default: printf("\n\n                                     Desole aucune option ne correspond à votre choix                                    \n");
        }
        printf("\n\nVoulez vous continuer si oui taper 1 ou autre chose sinon: ?\n");
        scanf("%d", &continuer);
        }while(continuer == 1);
        if(continuer != 1)
        {
        	printf("\n\n\n\n========================================================================================================================");
        printf("***********************************!!!!Merci d'avoir utilise le programme au revoir !!!!*******************************");
        printf("========================================================================================================================\n");
		}
    }

int main()
{
    int acceder = 0, choix = 0;
    //int ncni=917874836;
    //supprimer();
    //recherche();
    //printf("le nombre de candidats actuellement dans le concours est: %d\n", nbr_candidats("concour.txt"));
    //saisir("concours.txt");
    //admis("concour.txt");
    //statistiques();
    //attente("admis.txt");
    //supprimer_plus();
    //affiche_merite();
    //printf("%s\n", CANDIDAT[nbre_candidats].DECISION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("<<<<<<<<<<<<******************** BIENVENUE DANS LE LOGICIEL DE GESTION DES CONCOURS !!! ********************>>>>>>>>>>>>\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n");
    printf("Appuyez sur la touche 1 pour acceder au menu ou autre chose pour quitter: ");//Le menu doit etre supprimé à partir d'ici
    scanf("%d", &acceder);
    if(acceder == 1)
    {
        menu();
    }
    else
    {
        printf("\n\n\n\n========================================================================================================================");
        printf("***********************************!!!!Merci d'avoir utiliser le programme au revoir !!!!*******************************");
        printf("========================================================================================================================\n");
    }


return 0;
}// il y'a erreur d'affichage lors de la fonctions saisir et ajouter ça ne permet pas d'entrer les valeur à partie du nulero de ncni ça malange tout en meme temp et ça me retourne une fauuse decision mais je vais d'abord sauter
