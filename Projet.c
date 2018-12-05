#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>



int main(int argc, char *argv[])
{


printf("Quel est votre nom?\n \n");

char nomDuJoueur[100];

scanf("%s", &nomDuJoueur);

printf("\n \n \n Bienvenue %s dans Monsteur Attaque \n \n \n Une mission vous a ete confiee !\n \n \n Celle de proteger votre village d'une terrible menace qui s'abattra dans 10 jours.\n \n \n Afin de reussir cette perieuse mission, vous devrez acquerir de la force et de l'experience en liberant votre village des monstres qui l'occupe.\n \n \n Bonne chance, j'espere que vous serez a la hauteur de cette quete.\n \n \n ", nomDuJoueur);

Sleep(3000);

system("cls");

int choixRaces=0;
char Humain[]="Humain ", Orc[]="Orc  ", Elfe[]="Elfe ", Nain[]="Nain  ", Gnome[]="Gnome ";

char Races[10][50];
       strcpy(Races[0], Humain), strcpy(Races[1],Orc), strcpy(Races [2],Elfe), strcpy(Races[3], Nain), strcpy(Races[4], Gnome);


printf("\n \n \n Quelle race choisissez vous ? ! \n \n \n 1 : %s\n \n \n 2 : %s\n \n \n 3 : %s\n \n \n 4 : %s\n \n \n 5 : %s\n \n \n", Humain, Orc,Elfe, Nain, Gnome);
    scanf("%d", &choixRaces);

printf("\n \n \n Vous etes maintenant un %s !\n \n \n \n", Races[choixRaces-1]);



Sleep(3000);

int choixClasse=0;

char Epeiste[]="Epeiste", Magicien[]="Magicien", Voleur[]="Voleur", Archer[]="Archer", Ranger[]="Ranger";



char Classe [5][100];
strcpy(Classe[0], Epeiste ), strcpy(Classe[1], Magicien ), strcpy(Classe[2], Voleur ), strcpy(Classe[3], Archer ), strcpy(Classe[4], Ranger);



printf("\n \n \n Quelle classe choisissez-vous?\n \n \n 1 : %s\n \n \n 2 : %s\n \n \n 3 : %s\n \n \n 4 : %s\n \n \n 5 : %s\n \n \n",Epeiste, Magicien, Voleur, Archer, Ranger);

scanf("%d", &choixClasse);


printf("\n \n Vous etes maintenant un %s%s! \n \n \n",Races[choixRaces-1], Classe[choixClasse-1]);


Sleep(3000);



int jours=0;
int equipements=100;
int niveauDuJoueur=20;
int force=equipements+niveauDuJoueur;
int pointsDeVie=100;
int argent=0;
int armure=3;
int nbArmes=0;
int tabDecisionArmes[10]={0};

int combattre=1;
int repos=2;
int commerce=3;
int quitter=4;

int choixActions=0;
int choixArmes=0;

char Oui[]= "oui";
char Non[]= "non";
char reponse[10];
char armesTab[100][100];

int niveauDuMonstre;
int maxNiveauDuMonstre = 3, minNiveauDuMonstre = -4;
srand(time(NULL));

int de;
int maxDe = 6, minDe = 1;
srand(time(NULL));

int viePerdue;
int maxViePerdue=35, minViePerdue=5;
srand(time(NULL));

int argentGagne;
int maxArgentGagne=100, minArgentGagne=1;
srand(time(NULL));
argentGagne = (rand() % (maxArgentGagne - minArgentGagne + 1)) + minArgentGagne;
argent=argentGagne+500;


while(jours<20){

	force=equipements+niveauDuJoueur;
	maxNiveauDuMonstre+=5, minNiveauDuMonstre+=5;
	jours+=1;

	niveauDuMonstre = (rand() % (maxNiveauDuMonstre - minNiveauDuMonstre + 1)) + minNiveauDuMonstre;
	de = (rand() % (maxDe - minDe + 1)) + minDe;
	viePerdue = (rand() % (maxViePerdue - minViePerdue + 1)) + minViePerdue;
	argentGagne = (rand() % (maxArgentGagne - minArgentGagne + 1)) + minArgentGagne;

	
	printf("\n \n \n C'est le jour %d. \n \n \n Vous etes niveau %d. \n \n Equipements : bonus +%d.\n \n Force totale : %d. \n \n Armure : %d \n \n \n Vous possedez %d armes : ", jours, niveauDuJoueur, equipements, force, armure, nbArmes);
	

	int indiceArmes=0;
	for (indiceArmes; indiceArmes<nbArmes; indiceArmes++){
	
	printf("\n \n %s", armesTab[indiceArmes]);
}


	printf("\n \n \n \n Vous avez %d points de vie. \n \n Vous avez %d pieces d'or. \n \n", pointsDeVie, argent);
	

	Sleep(1000);

  while(choixActions!=combattre || choixActions!=repos || choixActions!=commerce || choixActions!=quitter){
	printf("\n \n Que souhaitez-vous faire ? \n \n \n 1 : Combattre \n \n 2 : Me reposer \n \n 3 : Faire du commerce \n \n \n 4 : Quitter la partie \n \n \n");

   scanf("%d", &choixActions);


if(choixActions==combattre || choixActions==repos || choixActions==commerce || choixActions==quitter){
   	break;
   }

   if (choixActions!=combattre || choixActions!=repos || choixActions!=commerce || choixActions!=quitter){
   	printf("\n \nJe n'ai pas tres bien compris, pouvez-vous repeter ?\n");
   	Sleep(2000);
   }
   
}


   if (choixActions==combattre){
   
	printf("\n \nUn monstre de niveau %d apparait !\n \n \n \n", niveauDuMonstre);


	Sleep(1000);




	if (force>=niveauDuMonstre){

		pointsDeVie -= viePerdue;
		
		if(pointsDeVie<=0){

			printf("En combattant vigoureusement le monstre, vos points de vies sont tombes a 0. Vous etes mort.\n \n \n");
			Sleep(4000);
			exit(1);
		}

		

		if(niveauDuMonstre<10){
		niveauDuJoueur += 1;
		argent += argentGagne;
		
		printf("Votre force est superieure au niveau du monstre ! \n \n \n \nVous le tuez : \n \n+1 niveau\n \n+%d pieces d'or\n \n-%d points de vie\n \n \n \n \n \n", argentGagne, viePerdue);
		}	
		
		
		if(niveauDuMonstre>=10 && niveauDuMonstre<20){
		niveauDuJoueur += 2;
		argent += argentGagne+100;

		printf("Votre force est superieure au niveau du monstre ! \n \n \n \nVous le tuez : \n \n+2 niveau\n \n+%d pieces d'or\n \n-%d points de vie\n \n \n \n \n \n", argentGagne+150, viePerdue);
		}

		if(niveauDuMonstre>=20 && niveauDuMonstre<40){
		niveauDuJoueur += 3;
		argent += argentGagne+200;

		printf("Votre force est superieure au niveau du monstre ! \n \n \n \nVous le tuez : \n \n+3 niveau\n \n+%d pieces d'or\n \n-%d points de vie\n \n \n \n \n \n", argentGagne+500, viePerdue);
		}

		if(niveauDuMonstre>=40 && niveauDuMonstre<60){
		niveauDuJoueur += 4;
		argent += argentGagne+300;

		printf("Votre force est superieure au niveau du monstre ! \n \n \n \nVous le tuez : \n \n+4 niveau\n \n+%d pieces d'or\n \n-%d points de vie\n \n \n \n \n \n", argentGagne+1000, viePerdue);
		}

		if(niveauDuMonstre>=60 && niveauDuMonstre<80){
		niveauDuJoueur += 5;
		argent += argentGagne+400;

		printf("Votre force est superieure au niveau du monstre ! \n \n \n \nVous le tuez : \n \n+5 niveau\n \n+%d pieces d'or\n \n-%d points de vie\n \n \n \n \n \n", argentGagne+1700, viePerdue);
		}

		if(niveauDuMonstre>=80 && niveauDuMonstre<99){
		niveauDuJoueur += 6;
		argent += argentGagne+500; 

		printf("Votre force est superieure au niveau du monstre ! \n \n \n \nVous le tuez : \n \n+6 niveau\n \n+%d pieces d'or\n \n-%d points de vie\n \n \n \n \n \n", argentGagne+2600, viePerdue);
		}
		
		}

   


   if(force<niveauDuMonstre){
   	printf("Votre force est inferieure au niveau du monstre... \n \nSouhaitez-vous tenter de deguerpir ? \n \n");

   	scanf("%s", &reponse);


   	if (strcasecmp(Oui, reponse)==0){

   		printf("\n \nVous essayez de vous enfuir... \n \n \n");

   		Sleep(2000);

         if(de>=3){
         	printf("Et vous reussissez honorablement ! \n \n \n");
         	Sleep(2000);
         	jours=jours+1;
         }

         if(de<3){
         	printf("Et vous echouez lamentablement... \n \n \nLe monstre vous devore dans d'atroces souffrances \n \n \n");
         	Sleep(5000);
         	exit(1);
         }
	 }
		if (strcasecmp(Non, reponse) == 0){

	  printf("\n \n \nLe monstre vous devore dans d'atroces souffrances \n \n \n");
	  Sleep(5000);
	  exit(1);
   }
   
   	}



   }


   if(choixActions==quitter){
   	exit(1);
   }


   if(choixActions==repos){

   	pointsDeVie+=viePerdue;
	printf("\n \n \n \n Vous vous reposez paisiblement dans une taverne.\n \n \n +%d points de vie\n \n \n \n \n", viePerdue);
	Sleep(3000);

   }

   if(choixActions==commerce){

   	char EpeeBasique[]="Epee basique [+4 forces] [92 pieces d'or] [niveau 3]", HacheDeGuerre[]="Hache de guerre [+6 forces] [138 pieces d'or] [niveau 5]", BatonDeSorcier[]="Baton de sorcier [+11 forces] [253 pieces d'or] [niveau 10]", Hallebarde[]="Hallebarde [+16 forces] [368 pieces d'or] [niveau 15]", ArcElfique[]="Arc elfique [+19 forces] [437 pieces d'or] [niveau 18]";
   	char DagueDeVoleur[]="Dague de Voleur [+23 forces] [529 pieces d'or] [niveau 22]", KatanaSurpuissant[]="Katana surpuissant [+36 forces] [972 pieces d'or] [niveau 38]", MarteauDeThor[]="Marteau de Thor [+48 forces] [1392 pieces d'or] [niveau 59]", Excalibur[]="Excalibur [+75 forces] [2550 pieces d'or] [niveau 100]";

   	char ArmesTabShop[10][100];
   	strcpy(ArmesTabShop[0], EpeeBasique), strcpy(ArmesTabShop[1],HacheDeGuerre), strcpy(ArmesTabShop[2],BatonDeSorcier), strcpy(ArmesTabShop[3], Hallebarde), strcpy(ArmesTabShop[4], ArcElfique), strcpy(ArmesTabShop[5], DagueDeVoleur), strcpy(ArmesTabShop[6],KatanaSurpuissant);
   	strcpy(ArmesTabShop[7],MarteauDeThor), strcpy(ArmesTabShop[8],Excalibur);

   	int PrixArmesTabShop[10]={92,138,253,368,437,529,972,1392,2550};
   	int EquiArmesTab[10]={4,6,11,16,19,23,36,48,75};
   	int ArmesNivRequis[10]={3,5,10,15,18,22,38,59,100};


   	printf("\n \n \n Que desirez-vous acheter ? \n \n \n \n 1 : Armes\n \n 2 : Armures\n \n 3 : Potions \n \n \n \n \n");


   	scanf("%d", &choixArmes); 


   		while(choixArmes!=10){

   		printf("\n \n \n \n Voici le magasin ! \n \n \n \n Vous etes niveau %d et avez %d pieces d'or. \n \n \n \n \n 1 : %s\n \n \n 2 : %s\n \n \n 3 : %s\n \n \n 4 : %s\n \n \n 5 : %s\n \n \n"
   			" 6 : %s\n \n \n 7 : %s\n \n \n 8 : %s\n \n \n 9 : %s\n \n \n \n \n 10 : Retour \n \n \n \n",niveauDuJoueur, argent, EpeeBasique, HacheDeGuerre, BatonDeSorcier, Hallebarde, ArcElfique, DagueDeVoleur, KatanaSurpuissant, MarteauDeThor, Excalibur);
   		scanf("%d", &choixArmes);


   		if (choixArmes>0 && choixArmes<10){


   			printf("\n \n Etes-vous sur de vouloir acheter %s ? \n \n \n", ArmesTabShop[choixArmes-1]);
   				scanf("%s", &reponse);

   				if(strcasecmp(Oui, reponse)==0){
   					
   					if (tabDecisionArmes[choixArmes-1]!=666){
   						tabDecisionArmes[choixArmes-1]=choixArmes;
   					}
   					
   					argent-=PrixArmesTabShop[choixArmes-1];

   					if (argent<=0){
  						argent+=PrixArmesTabShop[choixArmes-1];
   						printf("\n \n \n Vous n'avez pas les moyens pour acheter cela. \n \n \n");
   						Sleep(2000);
   					}

   					else if(choixArmes==tabDecisionArmes[choixArmes-1] && niveauDuJoueur>=ArmesNivRequis[choixArmes-1]){
   						tabDecisionArmes[choixArmes-1]=666;
   						equipements+=EquiArmesTab[choixArmes-1];
   						
   					strcpy(armesTab[indiceArmes], ArmesTabShop[choixArmes-1]);
   					indiceArmes++;
   					nbArmes++;

   					printf("\n \n Tres bon choix ! Vous venez d'acquerir cette arme !\n \n ");
   					Sleep(2000);

   					}
   				  					
   					else if(niveauDuJoueur<=ArmesNivRequis[choixArmes-1]){
   						argent+=PrixArmesTabShop[choixArmes-1];
   						printf("\n \n \n Vous n'avez pas le niveau requis !\n \n \n");
   						Sleep(1000);
   					}

   					else if(choixArmes!=tabDecisionArmes[choixArmes-1]){
   						argent+=PrixArmesTabShop[choixArmes-1];
   						printf("\n \n \n Vous avez deja cette arme !\n \n \n");
   						Sleep(2000);
   					}

   					
   				}

   			


   				
   				if(strcasecmp(Non, reponse)==0){
   					printf("\n \n \n Souhaitez-vous autre chose ?\n \n \n");
   					Sleep(1500);
   				}
   			

   			
   			



   			}

   			if(choixArmes==10){
   			jours-=1;
   		}

   		}


   		

   	

   	}


   }

}


