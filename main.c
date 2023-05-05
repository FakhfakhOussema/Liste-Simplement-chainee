#include"listename.h"
#include<stdio.h>

main()
{
    struct liste* l;
    char* name;
    int choix,pos;
        printf("\n******Bienvenue******\n");
        printf("1-Intialiser la liste \n");
            do
            {
                printf("Choisir \n");
                scanf("%d",&choix);
            }while(choix!=1);

            switch(choix)
            {
            case 1:
                l=initialisation();
                printf("\nliste initialisee avec succes\n\n");
                break;
            }











    do
    {
       if(vide(*l))
       {

           printf("**************\n1-Ajouter \n");
            do
            {
                printf("Choisir \n");
                scanf("%d",&choix);
            }while(choix!=1);

            switch(choix)
            {
            case 1:
                    printf("1-Ajouter dans une liste vide \n");
                    do
                    {
                        printf("Choisir \n");
                        scanf("%d",&choix);
                    }while(choix != 1);
                    printf("Donner le nom \n");
                    scanf("%s",name);
                    switch(choix)
                        {
                            case 1:
                            add_empty_liste(l,name);
                            break;
                        }
                break;

            }

       }

      else
        {
        printf("**************\n");
        printf("1-Ajouter :\n");
        printf("2-Supprimer :\n");
        printf("3-Afficher : \n");
        printf("4-Recherche :\n");
        printf("5-Quitter : \n");
        printf("**************\n\n");
            do
            {
                printf("Choisir service : \n");
                scanf("%d",&choix);
            }while(choix<0 || choix >5);

            switch(choix)
            {
            case 1:

                        printf("1-Ajouter au debut \n");
                        printf("2-Ajouter a la fin \n");
                        printf("3-Ajouter dans une position \n");
                    do
                    {
                        printf("Choisir \n");
                        scanf("%d",&choix);
                    }while(choix<1 ||choix>3);
                    switch(choix)
                    {
                    case 1 :
                        printf("Donner le nom \n");
                        scanf("%s",name);
                        add_first_liste(l,name);
                        printf("element ajouter avec sucees \n");
                        break;
                    case 2 :
                        printf("Donner le nom \n");
                        scanf("%s",name);
                        add_last_liste(l,name);
                        printf("element ajouter avec sucees \n");
                        break;
                    case 3:
                        printf("Donner le nom\n");
                        scanf("%s",name);
                        printf("Donner la position \n");
                        scanf("%d",&pos);
                        add_in_pos(l,name,pos);
                        printf("element ajouter dans la position %d avec sucees \n",pos);
                        break;
                    }
                    break;
            case 2:
                    printf("1-Supprimer 1er element \n");
                    printf("2-Supprimer dernier element \n");
                    printf("3-Supprimer element referencée \n");
                    printf("4-Supprimer tous les elements \n");
                    do
                    {
                        printf("Choisir \n");
                        scanf("%d",&choix);
                    }while(choix<1 ||choix>4);
                    switch(choix)
                    {
                    case 1 :
                        supp_first(l);
                        printf("1er element supprimee avec succees\n");
                        break;
                    case 2 :
                        supp_last(l);
                        printf("dernier element supprimee avec success \n");
                        break;
                    case 3 :
                        printf("Donner la position \n");
                        scanf("%d",&pos);
                        supp_in_post(l,pos);
                        printf("element %d supprimee avec succes \n",pos);
                        break;
                    case 4 :
                        supp_liste(l);
                        printf("liste supprimee avec succees \n");
                        break;
                    }
                    break;
            case 3:
                printf("1-Afficher 1er element \n");
                printf("2-Afficher dernier element \n");
                printf("3-Afficher toute la liste \n");
                do
                {
                    printf("Choisir \n");
                    scanf("%d",&choix);
                }while(choix<1 ||choix>3);
                switch(choix)
                {
                case 1 :
                    affiche_first(*l);
                    break;
                case 2 :
                    affiche_last(*l);
                    break;
                case 3 :
                    affiche(*l);
                    break;
                }
                break;

                case 4:
                    printf("Donner une chaine a rechercher \n");
                    scanf("%s",name);
                    rech(*l,name);
            }
        }
    }while(choix!=5);

    printf("\n\t**********Au revoir !**********");


}
