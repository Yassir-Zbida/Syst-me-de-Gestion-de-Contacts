#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  count_Contacts = 0 ;
int  i ,j ;
char recherche [20];
int  trouve ;

struct contact {
   char Nom[30] ;
   char Prenom [30];
   char Numero_Tele[30] ;
   char Email[30] ;
};

struct contact contacts [150];

void ajouterContact(){
    if(count_Contacts < 150){
       printf("Veuillez entrer Votre Nom :");
       scanf("%s[^\n]",contacts[count_Contacts].Nom);
       printf("Veuillez entrer Votre Prenom :");
       scanf("%s[^\n]",contacts[count_Contacts].Prenom);
       printf("Veuillez entrer Votre Numero de Telephone :");
       scanf("%s[^\n]",contacts[count_Contacts].Numero_Tele);
       printf("Veuillez entrer Votre Email Personel :");
       scanf("%s[^\n]",contacts[count_Contacts].Email);
       printf("Contact  %s  ajoute avec succes.\n",contacts[count_Contacts].Nom);
       count_Contacts++ ;
    }
}
void modifierContact(){
   trouve = 0 ;
   if (count_Contacts == 0) {
     printf("Aucun contact n'est disponible pour modification.\n");
     return ;
   }
   printf("Entrez le nom du contact a modifier : ");
   scanf("%s[^\n]", recherche);
   for(i=0 ; i<count_Contacts; i++){
    if(strcmp (contacts[i].Nom,recherche)== 0){
       printf("Contact %s trouve. Veuillez entrer les nouvelles informations.\n",recherche);

       printf("Nouveau Nom : ");
       scanf("%s[^\n]", contacts[i].Nom);

       printf("Nouveau prenom : ");
       scanf("%s[^\n]", contacts[i].Prenom);

       printf("Nouveau numero de telephone : ");
       scanf("%s[^\n]", contacts[i].Numero_Tele);

       printf("Nouvel email : ");
       scanf("%s[^\n]", contacts[i].Email);
       printf("Le contact %s a ete modifie avec succes.\n",contacts[i].Nom);
       trouve = 1 ;
       break ;
    }
    }
    if (trouve!=1) {
        printf("Contact %s non trouve.\n", recherche );
   }
}

void supprimerContact(){
   if (count_Contacts == 0) {
     printf("Aucun contact n'est disponible pour supprimer.\n");
     return ;
   }
   trouve = 0 ;
   printf("Entrez le nom du contact a supprimer: ");
   scanf("%s[^\n]", recherche);
   for(i=0; i<count_Contacts;i++){
      if(strcmp(contacts[i].Nom,recherche )== 0){
        for(j=i ; j<count_Contacts;j++){
           strcpy(contacts[j].Nom , contacts[j+1].Nom );
           strcpy(contacts[j].Prenom , contacts[j+1].Prenom );
           strcpy(contacts[j].Numero_Tele, contacts[j+1].Numero_Tele);
           strcpy(contacts[j].Email,contacts[j+1].Email);
        }
        count_Contacts--;
        printf("Livre supprime avec succes.\n");
        trouve = 1 ;
        break;
      }
   }
   if(trouve!=1){
    printf("Contact %s non trouve.\n",recherche);
   }
}

void afficheContacts (){
    if (count_Contacts == 0){
        printf("Aucun contact n'est disponible pour affichage.\n");
        return;
    }
    for(i=0 ; i<count_Contacts ; i++){
        printf("Nom : %s\t Prenom : %s\t Numero de Telephone : %s\t Email : %s\n",contacts[i].Nom, contacts[i].Prenom, contacts[i].Numero_Tele, contacts[i].Email);
    }
}

void rechercheContact (){
    trouve = 0 ;
    if (count_Contacts == 0) {
        printf("Aucun contact a rechercher.\n");
        return;
    }
    printf("Entrez le nom du contact a rechercher : ");
    scanf("%s[^\n]", recherche);

    for(i=0 ; i<count_Contacts ; i++){
        if(strcmp(contacts[i].Nom,recherche)== 0){
        printf("Nom : %s\t Prenom : %s\t Numero de Telephone : %s\t Email : %s\t\n",contacts[i].Nom,contacts[i].Prenom,contacts[i].Numero_Tele,contacts[i].Email);
        trouve = 1 ;
        break ;
        }
    }
    if(trouve!=1){
       printf("Contact %s non trouve.\n",recherche);
    }
}

void Menu(){
  int choix ;
    do{
        printf("******************************************\n");
        printf("Systeme de gestion des contacts Youcode :\n");
        printf("1. Ajouter un contact\n");
        printf("2. Modifier un Contact\n");
        printf("3. Supprimer un contact\n");
        printf("4. Afficher tous les contacts\n");
        printf("5. Recherche Contact\n");
        printf("6. Quitter\n");
        printf("******************************************\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterContact();
                    break;
            case 2: modifierContact();
                    break;
            case 3: supprimerContact();
                    break;
            case 4: afficheContacts();
                    break;
            case 5: rechercheContact();
                    break;
            case 6: printf("Systeme est Terminer.\n");
                    break;
            default: printf("Choix invalide, reessayez (choix entre 1-6).\n");
        }
    }while(choix!=6);

};

int main()
{
    Menu();
    return 0;
}
