#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 10000

typedef struct
    {
        char nom[TAILLE];
        char date[TAILLE];
        int temper;
        int eff;
    }ville;

char chaine[TAILLE],car,car1,car2,wil[TAILLE],jour[TAILLE],reponse[TAILLE],*inter;
int i=0,j=0,cpt=0,nb_lig=0,nb_occur=0,arret=0,differ=0,nb,temp,exist=0,i,min,max,moy=0;
ville wilaya,test;

void fecrit1(FILE *fichier) //AVEC FGETC
{
    rewind(fichier);
    while((car=fgetc(fichier))!=EOF)
        {
            printf("%c",car);
        }
}
void fecrit2(FILE *fichier) //AVEC FGETS
{
    rewind(fichier);
    while(fgets(chaine,10,fichier)!=NULL)
        {
            printf("%s",chaine);
        }
}
void concat_fich(FILE *fichier1,FILE *fichier2,FILE *fichier3)
{
        rewind(fichier1);
        rewind(fichier2);
        car=fgetc(fichier1);
        while (car!=EOF)
        {
            fputc(car,fichier3);
            car=fgetc(fichier1);
        }
        car=fgetc(fichier2);
        while (car!=EOF)
        {
            fputc(car,fichier3);
            car=fgetc(fichier2);
        }
}
int nb_occurences(FILE *fichier1,char mot[TAILLE])
{
        nb_occur=0;
        i=0;
        rewind(fichier1);
        car=fgetc(fichier1);
        while (car!=EOF)
        {
            chaine[i]=car;
            i++;
            car=fgetc(fichier1);
        }
        inter=strtok(chaine," .,;:()\n");
        while (inter!=NULL)
        {
           if (strcmp(mot,inter)==0)
           {
             nb_occur++;
           }
           inter=strtok(NULL," .,;:()\n");
        }
        return nb_occur;
}
int nb_lignes(FILE* fichier1)
{
        nb_lig=0;
        rewind(fichier1);
        while (fgets(chaine,255,fichier1)!=NULL)
        {
            nb_lig++;
        }
        return nb_lig;
}
void crypte(FILE *fichier1,char cle[TAILLE],FILE* code)
{
        rewind(fichier1);
        rewind(code);
        arret=0;
        car=fgetc(fichier1);
        while (car!=EOF)
        {
            for (i=0;i<=strlen(cle)-1;i++)
            {
                if (arret!=1)
                {
                    fputc(cle[i]+car,code);
                    car=fgetc(fichier1);
                    if (car==EOF) arret=1;
                }

            }
        }
}
void decrypte(FILE *code,char cle[TAILLE],FILE* decode)
{
        rewind(code);
        rewind(decode);
        arret=0;
        car=fgetc(code);
        while (car!=EOF)
        {
           for (i=0;i<=strlen(cle)-1;i++)
            {
                if (arret!=1)
                {
                    fputc(car-cle[i],decode);
                    car=fgetc(code);
                    if (car==EOF) arret=1;

                }
            }
        }
}
void compare_fichier(FILE *fichier1,FILE *fichier2)
{
        rewind(fichier1);
        rewind(fichier2);
        arret=0;
        car1=fgetc(fichier1);
        car2=fgetc(fichier2);
        while ((arret==0)&&(car1!=EOF)&&(car2!=EOF))
        {
           if (car1!=car2) arret=1;
           else
           {
               car1=fgetc(fichier1);
               car2=fgetc(fichier2);
           }
        }
        if (arret==1 ) printf("LES FICHIERS SONT DIFFERENTS ! \n");
        else
        {
            if (car1==car2) printf("LES FICHIERS 1 ET 2 SONT IDENTIQUES  ! \n");
            else printf("LES FICHIERS SONT DIFFERENTS ! \n");
        }
}
void affiche_bin(FILE *fichierbin)
{
        rewind(fichierbin);
        printf("NOM      DATE      TEMPERATURE\n\n");
        while(fread(&test,sizeof(test),1,fichierbin)!=0)
        {
                if (test.eff!=1)
                {
                    printf("%s     ",test.nom);
                    printf("%s     ",test.date);
                    printf("%d     \n",test.temper);
                }
            }
}
void creationbin(FILE *fichierbin)
{
        rewind(fichierbin);
        printf("NOMBRE D'ENREGISTREMENTS : \n");
        scanf("%d",&nb);
        for (i=1;i<=nb;i++)
        {
            printf("\nVILLE NUMERO %d : \n\n",i);
            printf("LE NOM : ");
            scanf("%s",&test.nom);
            printf("\n");
            printf("LA DATE (FORMAT JJ/MM/AAAA): ");
            scanf("%s",&test.date);
            printf("\n");
            printf("LA TEMPERATURE : ");
            scanf("%d",&test.temper);
            printf("\n");
            test.eff=0;
            fwrite(&test,sizeof(test),1,fichierbin);
        }
}
void statistique(FILE *fichierbin)
{
        cpt=0;
        printf("LA VILLE SUR LAQUELLE FAIRE DES STATISTIQUES : ");
        scanf("%s",&wil);
        rewind(fichierbin);
        exist=0;
        while ((exist==0)&&(fread(&test,sizeof(test),1,fichierbin)!=0))
        {
            if ((test.eff!=1)&&(strcmp(test.nom,wil)==0))
            {
                exist=1;
            }
        }

        if (exist==1)
        {
        min=test.temper;
        max=test.temper;
        moy=0;
        rewind(fichierbin);
        while(fread(&test,sizeof(test),1,fichierbin)!=0)
        {
            if ((strcmp(test.nom,wil)==0)&&(test.eff!=1))
            {
               if (test.temper>=max) max=test.temper;
               if (test.temper<=min) min=test.temper;
               moy=test.temper+moy;
               cpt++;
            }
        }
        printf("\n==================================\n");
        rewind(fichierbin);
        moy=moy/cpt;
        printf(" LE MIN : %d , LE MAX : %d , LA MOYENNE : %d ",min,max,moy);
        } else printf("\nLa ville est inexistante dans le fichier ! \n");
}
void ajoutville(FILE *fichierbin)
{
        printf("LE NOM DE LA VILLE A AJOUTER : ");
        scanf("%s",&wilaya.nom);
        printf("LA DATE (FORMAT JJ/MM/AAAA): ");
        scanf("%s",&wilaya.date);
        printf("LA TEMPERATURE : ");
        scanf("%d",&wilaya.temper);
        wilaya.eff=0;
        rewind(fichierbin);
        exist=0;
        while((exist!=1)&&(fread(&test,sizeof(test),1,fichierbin)!=0))
        {
           if ((strcmp(test.nom,wilaya.nom)==0)&&(strcmp(test.date,wilaya.date)==0)&&(test.eff!=1))
            {
            printf("\nCETTE VILLE EXISTE DEJA DANS LE FICHIER ! \n");
            exist=1;
            }
        }
        if (exist!=1) fwrite(&wilaya,sizeof(wilaya),1,fichierbin);
}
void modifiville(FILE *fichierbin)
{
        printf("LE NOM DE LA VILLE A CHANGER : ");
        scanf("%s",&wil);
        printf("LA DATE (FORMAT JJ/MM/AAAA): ");
        scanf("%s",&jour);
        printf("LA NOUVELLE TEMPERATURE : ");
        scanf("%d",&temp);
        rewind(fichierbin);
        exist=0;
        while(fread(&test,sizeof(test),1,fichierbin)!=0)
        {
            if ((strcmp(test.nom,wil)==0)&&(strcmp(test.date,jour)==0)&&(test.eff!=1))
            {
                exist=1;
                test.temper=temp;
                fseek(fichierbin,-sizeof(test),SEEK_CUR);
                fwrite(&test,sizeof(test),1,fichierbin);
                fseek(fichierbin,sizeof(test),SEEK_CUR);
            }
        }
        if (exist==0) printf("\nLA VILLE EST INEXISTANTE DANS LE FICHIER ! \n");

}
void supprville(FILE *fichierbin)
{
        rewind(fichierbin);
        printf("LE NOM DE LA VILLE A SUPPRIMER : ");
        scanf("%s",&wil);
        exist=0;
        while(fread(&test,sizeof(test),1,fichierbin)!=0)
        {
            if ((strcmp(test.nom,wil)==0)&&(test.eff==0))
            {
                exist=1;
                test.eff=1;
                fseek(fichierbin,-sizeof(test),SEEK_CUR);
                fwrite(&test,sizeof(test),1,fichierbin);
                fseek(fichierbin,sizeof(test),SEEK_CUR);
            }
        }
        if (exist==0) printf("\nLA VILLE EST INEXISTANTE DANS LE FICHIER ! \n");
}
void reorganis(fichierbin,nouveaubin1)
{
        while(fread(&test,sizeof(test),1,fichierbin)!=0)
            {
                if (test.eff!=1)
                {
                    fwrite(&test,sizeof(test),1,nouveaubin1);
                }
            }
}
