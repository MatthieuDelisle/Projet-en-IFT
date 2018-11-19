#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>




int main(int argc, char *argv[])
{


int jours=0;
int equipements=100;
int niveauDuJoueur=1;
int force=equipements+niveauDuJoueur;
int pointsDeVie=100;
int argent=0;
int armure=3;
int nbArmes=0;
int buyEpee=0, buyHache=0, buyBaton=0;

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
	
	printf(" %s,", armesTab[indiceArmes]);
}


	printf("\n \n \n \n Vous avez %d points de vie. \n \n Vous avez %d pieces d'or. \n \n", pointsDeVie, argent);
	

	Sleep(3000);

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


	Sleep(3000);




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

   	char ArmesTabShop[50][50];
   	strcpy(ArmesTabShop[0], EpeeBasique), strcpy(ArmesTabShop[1],HacheDeGuerre), strcpy(ArmesTabShop[2],BatonDeSorcier), strcpy(ArmesTabShop[3], Hallebarde), strcpy(ArmesTabShop[4], ArcElfique), strcpy(ArmesTabShop[5], DagueDeVoleur), strcpy(ArmesTabShop[6],KatanaSurpuissant);
   	strcpy(ArmesTabShop[7],MarteauDeThor), strcpy(ArmesTabShop[8],Excalibur);

   	int PrixArmesTabShop[10]={92,138,253,368,437,529,972,1392,2550};


   	printf("\n \n \n Que desirez-vous acheter ? \n \n \n \n 1 : Armes\n \n 2 : Armures\n \n 3 : Potions \n \n 4 : Coequipiers\n \n \n \n \n");


   	scanf("%d", &choixArmes);


   		while(choixArmes!=10){

   		printf("\n \n \n \n Voici le magasin ! \n \n \n 1 : %s\n \n \n 2 : %s\n \n \n 3 : %s\n \n \n 4 : %s\n \n \n 5 : %s\n \n \n"
   			" 6 : %s\n \n \n 7 : %s\n \n \n 8 : %s\n \n \n 9 : %s\n \n \n \n \n 10 : Retour \n \n \n \n", EpeeBasique, HacheDeGuerre, BatonDeSorcier, Hallebarde, ArcElfique, DagueDeVoleur, KatanaSurpuissant, MarteauDeThor, Excalibur);
   		scanf("%d", &choixArmes);

   		if (choixArmes>0 && choixArmes<10){


   			printf("\n \n Etes-vous sur de vouloir acheter %s ? \n \n \n", ArmesTabShop[choixArmes-1]);
   				scanf("%s", &reponse);

   				if(strcasecmp(Oui, reponse)==0){
   					

   					argent-=PrixArmesTabShop[choixArmes-1];

   					if (argent<=0){
  						argent+=PrixArmesTabShop[choixArmes-1];
   						printf("\n \n \n Vous n'avez pas les moyens pour acheter cela. \n \n \n");
   						Sleep(2000);
   					}

   					else if(buyEpee==0){
   					equipements+=8;
   					buyEpee=1;
   					
   					strcpy(armesTab[indiceArmes], EpeeBasique);
   					indiceArmes++;
   					nbArmes++;

   					printf("\n \n Bon choix ! \n \n +1 Epee Basique\n \n +8 forces \n \n -200 pieces d'or \n \n");
   					Sleep(2000);

   					}
   				  					
   					else{
   						printf("\n \n \n Vous avez deja cette arme !");
   						Sleep(1000);
   					}

   					}
   				
   				
   				if(strcasecmp(Non, reponse)==0){
   					printf("\n \n \n Souhaitez-vous autre chose ?");
   				}
   			}

   			
   			



   			}

   			if(choixArmes==10){
   			jours-=1;
   		}

   		}


   		

   	

   	}


   }




