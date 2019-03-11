#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAILLE 10000

char mot[TAILLE],cle[TAILLE],reponse[TAILLE],chaine[TAILLE];
FILE *fichier1=NULL,*fichier2=NULL,*fichier3=NULL,*code=NULL,*decode=NULL,*fichierbin=NULL,*nouveaubin1=NULL;
int main()
{
while (1==1)
{
    system("cls");
    int ChoixMenu;
    {
        printf("SI-MOHAMMED SAMIR G4\n\n\n\n");
        printf("TP1 SFSD : FICHIERS TEXTE ET BINAIRES.\n\n");
        printf("************************MENU**************************\n\n\n\n");
        printf("LISTE DES EXERCICES DEMANDES : \n\n\n\n");
        printf("FICHIERS TEXTE : \n\n\n\n");
        printf(" 1-AFFICHAGE DU CONTENU D'UN FICHIER TEXTE\n\n");
        printf(" 2-CONCATENATION DE 2 FICHIERS TEXTE\n\n");
        printf(" 3-NOMBRE D'OCCURENCES D'UN MOT DANS UN FICHIER TEXTE\n\n");
        printf(" 4-NOMBRE DE LIGNES D'UN FICHIER TEXTE\n\n");
        printf(" 5-CRYPTAGE DE FICHIER TEXTE\n\n");
        printf(" 6-DECRYPTAGE DE FICHIER TEXTE\n\n");
        printf(" 7-VERIFICATION DE LA SIMILARITE DE 2 FICHIERS TEXTE\n\n");
        printf("\n\nFICHIERS BINAIRES : \n\n\n\n");
        printf(" 8-CREATION D'UN NOUVEAU FICHIER BINAIRE\n\n");
        printf(" 9-AFFICHAGE DU CONTENU DU FICHIER BINAIRE\n\n");
        printf(" 10-STATISTIQUES SUR UNE VILLE DANS UN FICHIER BINAIRE\n\n");
        printf(" 11-AJOUT D'UNE VILLE DANS UN FICHIER BINAIRE\n\n");
        printf(" 12-MODIFICATION D'UNE VILLE DANS UN FICHIER BINAIRE\n\n");
        printf(" 13-SUPPRESSION D'UNE VILLE DANS UN FICHIER BINAIRE\n\n");
        printf(" 14-REORGANISATION DE FICHIER BINAIRE\n\n");
        printf("\n\nQUEL EST VOTRE CHOIX ? ");
        scanf("%d",&ChoixMenu);
        switch (ChoixMenu)
        {
        case 1:
            printf("\nAFFICHAGE DE CONTENU D'UN FICHIER TEXTE :\n\n\n");
            printf("NOM DU FICHIER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            printf("\n\n\n");
            fichier1=fopen(chaine,"r+");
            if (fichier1!=NULL)
            {
                printf("VOICI LE CONTENU DU FICHIER : \n\n");
                fecrit1(fichier1);
            }
            else printf("LE FICHIER N'EXISTE PAS !");
            fclose(fichier1);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 2:
            printf("\nCONCATENATION DE DEUX FICHIERS TEXTE : \n\n");
            printf("NOM DU 1ER FICHIER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            printf("\n\n\n");
            fichier1=fopen(chaine,"r+");
            printf("NOM DU 2EME FICHIER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            printf("\n\n\n");
            fichier2=fopen(chaine,"r+");
            printf("ENTREZ LE NOM DU NOUVEAU FICHIER (A CREER) : ");
            scanf("%s",&mot);
            fichier3=fopen(mot,"w+");
            printf("\n\n\n");
            if ((fichier1!=NULL)&&(fichier2!=NULL)&&(fichier3!=NULL))
            {
                printf("VOICI LE CONTENU DU FICHIER CONCATENE : \n\n");
                concat_fich(fichier1,fichier2,fichier3);
                fecrit1(fichier3);
            }
            else printf("LES FICHIERS N'EXISTENT PAS !");
            fclose(fichier1);
            fclose(fichier2);
            fclose(fichier3);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 3:
            printf("\nNOMBRE D'OCCURENCES D'UN MOT DANS UN FICHIER TEXTE : \n\n\n\n");
            printf("ENTREZ LE MOT A RECHERCHER DANS LE FICHIER : ");
            scanf("%s",&mot);
            printf("\n\n\n");
            printf("NOM DU FICHIER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            printf("\n\n\n");
            fichier1=fopen(chaine,"r+");
            if (fichier1!=NULL) printf("LE NOMBRE D'OCCURENCES DU MOT DANS LE FICHIER EST : %d\n\n\n",nb_occurences(fichier1,mot));
            else printf("LE FICHIER N'EXISTE PAS !");
            fclose(fichier1);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 4:
            printf("\nNOMBRE DE LIGNES D'UN FICHIER TEXTE : \n\n\n");
            printf("NOM DU FICHIER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            printf("\n\n\n");
            fichier1=fopen(chaine,"r+");
            if (fichier1!=NULL)
            {
                printf("\nLE NOMBRE DE LIGNES DU FICHIER EST : ");
                printf("%d\n\n\n",nb_lignes(fichier1));
            }
            else printf("LE FICHIER N'EXISTE PAS !");
            fclose(fichier1);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 5:
            printf("\nCODAGE D'UN FICHIER TEXTE : \n\n");
            printf("NOM DU FICHIER A CODER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            fichier1=fopen(chaine,"r+");
            printf("\n\n\n");
            printf("ENTREZ LE NOM DU FICHIER CODE (A CREER) : ");
            scanf("%s",&mot);
            code=fopen(mot,"w+");
            printf("\n\n\n");
            if (fichier1!=NULL)
            {
                rewind(fichier1);
                printf("ENTREZ LA CLA SECRETE POUR CODER LE FICHIER : ");
                scanf("%s",&cle);
                crypte(fichier1,cle,code);
                printf("\n\n\n");
                printf("LE FICHIER A BIEN ETE CRYPTE.\n");
            }
            else printf("LE FICHIER N'EXISTE PAS !");
            fclose(fichier1);
            fclose(code);
            fclose(decode);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 6:
            printf("\nDECODAGE D'UN FICHIER TEXTE : \n\n");
            printf("NOM DU FICHIER A DECODER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            fichier1=fopen(chaine,"r+");
            printf("\n\n\n");
            printf("ENTREZ LE NOM DU FICHIER DECRYPTE (A CREER) : ");
            scanf("%s",&mot);
            decode=fopen(mot,"w+");
            if (fichier1!=NULL)
            {
                rewind(fichier1);
                printf("ENTREZ LA CLA SECRETE POUR DECRYPTER LE FICHIER : ");
                scanf("%s",&cle);
                printf("\n\n\n");
                decrypte(fichier1,cle,decode);
                printf("LE FICHIER A BIEN ETE DECRYPTE.\n");
            }
            else printf("LE FICHIER N'EXISTE PAS !");
            printf("\n\n\n");
            fclose(fichier1);
            fclose(decode);
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 7:
            printf("\nCOMPARAISON ENTRE DEUX FICHIERS TEXTE : \n\n\n");
            printf("NOM DU 1ER FICHIER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            fichier1=fopen(chaine,"r+");
            printf("NOM DU 2EME FICHIER (AJOUTEZ LE .TXT) : ");
            scanf("%s",&chaine);
            printf("\n\n\n");
            fichier2=fopen(chaine,"r+");
            if ((fichier1!=NULL)&&(fichier2!=NULL))compare_fichier(fichier1,fichier2);
            else printf("LES FICHIERS N'EXISTENT PAS !");
            fclose(fichier1);
            fclose(fichier2);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 8:
            printf("\n\nCREATION D'UN NOUVEAU FICHIER BINAIRE :\n\n");
            printf("ENTREZ LE NOM DU FICHIER A CREER (AJOUTEZ LE .bin) : ");
            scanf("%s",&chaine);
            fichierbin=fopen(chaine,"wb+");
            creationbin(fichierbin);
            fclose(fichierbin);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 9:
            printf("\n\nVOICI LE CONTENU DU FICHIER BINAIRE : \n\n");
            printf("ENTREZ LE NOM DU FICHIER A AFFICHER (AJOUTEZ LE .bin) : ");
            scanf("%s",&chaine);
            printf("\n\n");
            fichierbin=fopen(chaine,"rb+");
            if (fichierbin!=NULL)
            {
                printf("VOICI LE CONTENU DU FICHIER : \n\n\n");
                rewind(fichierbin);
                affiche_bin(fichierbin);
            }
            else printf("LE FICHIER N'EXISTE PAS ! ");
            fclose(fichierbin);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 10:
            printf("\n\nSTATISTIQUES SUR UNE VILLE : \n\n");
            printf("ENTREZ LE NOM DU FICHIER : ");
            scanf("%s",&chaine);
            fichierbin=fopen(chaine,"rb+");
            if (fichierbin!=NULL) statistique(fichierbin);
            else printf("LE FICHIER N'EXISTE PAS ! ");
            fclose(fichierbin);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 11:
            printf("\n\nAJOUT D'UNE VILLE : \n\n");
            printf("ENTREZ LE NOM DU FICHIER : ");
            scanf("%s",&chaine);
            fichierbin=fopen(chaine,"rb+");
            if (fichierbin!=NULL) ajoutville(fichierbin);
            else printf("LE FICHIER N'EXISTE PAS ! ");
            fclose(fichierbin);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 12:
            printf("\n\nMODIFICATION D'UNE VILLE : \n\n");
            printf("ENTREZ LE NOM DU FICHIER : ");
            scanf("%s",&chaine);
            fichierbin=fopen(chaine,"rb+");
            if (fichierbin!=NULL) modifiville(fichierbin);
            else printf("LE FICHIER N'EXISTE PAS ! ");
            fclose(fichierbin);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 13:
            printf("\n\nSUPPRESSION D'UNE VILLE : \n\n");
            printf("ENTREZ LE NOM DU FICHIER : ");
            scanf("%s",&chaine);
            fichierbin=fopen(chaine,"rb+");
            if (fichierbin!=NULL) supprville(fichierbin);
            else printf("LE FICHIER N'EXISTE PAS ! ");
            fclose(fichierbin);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
            break;
        case 14:
            printf("\n\nREORGANISATION DU FICHIER : \n");
            printf("ENTREZ LE NOM DU FICHIER A REORGANISER : ");
            scanf("%s",&chaine);
            fichierbin=fopen(chaine,"rb+");
            printf("ENTREZ LE NOM DU NOUVEAU FICHIER : ");
            scanf("%s",&mot);
            nouveaubin1=fopen(mot,"wb+");
            if ((fichierbin!=NULL)&&(nouveaubin1!=NULL)) reorganis(fichierbin,nouveaubin1);
            else printf("LE FICHIER N'EXISTE PAS ! ");
            fclose(fichierbin);
            fclose(nouveaubin1);
            printf("\n\n\n");
            printf("\nAPPUYEZ SUR UNE TOUCHE PUIS ENTRER POUR QUITTER ! ");
            scanf("%s",&reponse);
        }
    }
}
}
