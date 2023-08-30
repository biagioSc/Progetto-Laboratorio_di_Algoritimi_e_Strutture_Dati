//Main
// Alunno: Biagio Scotto di Covella
// Matricola : N86003605

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include <windows.h> 
#include "prototipi.h"

int main(){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;

	system("cls");
	color(2);
	printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   ",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4);
	color(15);
	printf("WELCOME TO MOUNT ST. ANGEL SHOP  ");
	color(2);
	printf("%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	color(15);

	printf("				   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n				   %c   1-LOG IN   %c\n				   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	printf("				   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n				   %c   2-SIGN UP  %c\n				   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	printf("				   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n				   %c    0-EXIT    %c\n				   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);

	int scelta,ruolo;

	color(11);
	printf("\n\n				%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n				%c   Inserisci scelta  %c\n				%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	color(15);
	scelta=eventiMain();	
	
	switch(scelta){
		
		case 1: 
			system("cls");
			color(2);
			printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   ",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4);
			color(15);
			printf("	Sei un admin o un utente?    ");
			color(2);
			printf("%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
			color(15);
			printf("		  (Inserisci 0 per admin, 1 per utente, 3 per uscire)");
			
			ruolo=eventiMainScelta();

			switch(ruolo){
				
				case 0:
					system("cls");
					paginaAccessoAdmin();
					scelta=0;
					break;
				case 1:
					system("cls");
					paginaAccessoCliente();
					scelta=0;
					break;
				case 3:
					system("cls");
					exit(-1);
					break;
			}
			
		case 2: 
			system("cls");
			color(2);
			printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   ",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4);
			color(15);
			printf("Vuoi registrarti come admin o come utente? ");
			color(2);
			printf("%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
			color(15);
			printf("		       (Inserisci 0 per admin, 1 per utente, 3 per uscire)");
			
			ruolo=eventiMainScelta();
			
			switch(ruolo){
				
				case 0:
					system("cls");
					paginaRegistraAdmin();
					break;
				case 1:
					system("cls");
					paginaRegistraCliente();
					break;
				case 3:
					system("cls");
					scelta=0;
					break;
			}
		
		case 0:
			system("cls");
	}
		
	color(2);
	printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   ",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4);
	color(15);
	printf("GOODBYE TO MOUNT ST. ANGEL SHOP  ");
	color(2);
	printf("%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	color(15);
	
}

