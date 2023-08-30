//OK funzioniAdmin 10
// Alunno: Biagio Scotto di Covella
// Matricola : N86003605

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include <windows.h> 
#include <conio.h>
#include <ctype.h>
#include "Prototipi.h"

//OK Funzione creazione admin
admin *creaAdmin(Stringa nome, Stringa cognome, Stringa username, Stringa password){
	
	admin *e;
	e = (admin *) malloc(sizeof(admin));
	strcpy(e->nome,nome);	
	strcpy(e->cognome,cognome);
	strcpy(e->username,username);
	strcpy(e->password,password);

	return e;
} 

//OK Funzione che controlla che i dati (username) non siano già presenti nel sistema
int controllaDatiAdmin(Stringa username){
	
	FILE *fp;
	fp = fopen("databaseAdmin.txt","r");
	
	Stringa n,c,u,p;
	int k=0;
	
	while (fscanf(fp,"%s%s%s%s\n", &n, &c, &u, &p)==4) {
		k= strcmp(u,username);
		if (k==0){ 
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

//OK Funzione che prende le info di un admin
admin *chiediInfoAdmin(){
	
	admin *account;
	Stringa nome, cognome, username, password;
	int control; 
	
	fflush(stdin);
	do{
		color(12); 
		printf("\nInserire nome(usare '_' come spazio): ");
		color(15); 
		gets(nome);
	}while(nome[0]=='\0' || isdigit(nome[0]));
	
	fflush(stdin);
	do{
		color(12); 
		printf("\nInserire cognome(usare '_' come spazio): ");
		color(15); 
		gets(cognome);
	}while(cognome[0]=='\0' || isdigit(nome[0]));
	
	fflush(stdin);
	color(12);
	printf("\nInserire username(almeno 9 caratteri): ");
	color(15); 
	gets(username);
	control=controllaDatiAdmin(username);
	while(strlen(username)<9 || control==1){
		color(12); 
		printf("Username troppo corta (almeno 9 caratteri) o gia' usata!\n");
		color(15); 
		gets(username);
		control=controllaDatiAdmin(username);
	}

	fflush(stdin);
	color(12);
	printf("\nInserire password(almeno 9 caratteri): ");
	color(15); 
	gets(password);
	while(strlen(password)<9){
		color(12); 
		printf("Password troppo corta (almeno 9 caratteri)!\n");
		color(15); 
		gets(password);
	}
	
	
	account=creaAdmin(nome,cognome,username,password);
		return account;
}

//OK Funzione che scrive le info di un admin su un file
admin *scriviFileAdmin(FILE *fp){
	
	admin *account;
	account=chiediInfoAdmin();
	
	if(account==NULL) return NULL;
	
	int registrato;
	while(!feof) registrato=0;
	if((fprintf(fp,"%s %s %s %s  \n",account->nome,account->cognome,account->username,account->password))!=0)registrato=1;
	
	if(registrato==1 && account!=NULL)return account;
}

//OK Funzione ausiliare alla registrazione di un admin
admin *registraAdmin(){
		
		FILE *fp;
		admin *registrato=NULL;
		fp = fopen("databaseAdmin.txt","a");
		registrato=scriviFileAdmin(fp);
		fclose(fp);
		return registrato;
}

//OK Funzione ausiliare alla ricerca di un admin nel file per vedere se è registrato già
admin *trovaAdmin(FILE *fp, Stringa username, Stringa password){
	
	Stringa n,c,u,p;
	int k=0,j=0;
	admin *ad=NULL;
	
	while (fscanf(fp,"%s%s%s%s\n", &n, &c, &u, &p)==4) {
		k= strcmp(u,username);
		j= strcmp(p,password);
		if (k==0 && j==0){ 
			ad=creaAdmin(n,c,u,p);
			return ad;
		}
	}
	
	return NULL;
}

//OK Funzione ausiliare per l'accesso di un adim
admin *accediAdmin(Stringa username, Stringa password){
		
		FILE *fp;
		admin *trovato=NULL;
		fp = fopen("databaseAdmin.txt","r");

		trovato=trovaAdmin(fp, username, password);
		fclose(fp);
		return trovato;
}

//OK Funzione che permette l'accesso
void paginaAccessoAdmin(){
	
	Stringa username, password;
	admin *entrato=NULL;
	
	do{
		color(12); 
		printf("\n					Inserisci username:\n					"); 
		color(15);
		scanf("%s",&username);
		color(12); 
		printf("\n					Inserisci password:\n					"); 
		color(15);
		scanf("%s",&password);

		entrato=accediAdmin(username,password);
		
		if(entrato!=NULL){
			color(15);
			printf("\n\n		Benvenuto nella pagina di controllo admin\n\n");		
		}
		else {
			color(12);
			printf("\n\n				Username o password errata!");
		}
		
		color(15);
		
	}while(entrato==0);
	
	unitControlAdmin(entrato);
}

//OK Funzione che permette la registrazione
void paginaRegistraAdmin(){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	Stringa username, password;
	admin *entrato=NULL;
	
	do{
		
		entrato=registraAdmin();
		if(entrato!=NULL){
			color(2); 
			printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%cRegistrazione avvenuta con successo!%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
			color(15); 
		}
		else {
			color(12); 
			printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%cRegistrazione non andata a buon fine%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
			printf("																		 Username gia' usata		\n");
		}
		color(15);
	}while(entrato==NULL);
	
	unitControlAdmin(entrato);
}

//OK Funzione controllo admin
void unitControlAdmin(admin *utenteA){
	
	char cc=218,cc2=196,cc3=191,cc4=179,cc5=217,cc6=192;
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	int scelta, continua;
	prodotti *prodottiDb=NULL;
	
	Sleep(2000);
	system("cls");

	do{
		color(2); 
		printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   1-View Products   %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   2-Modify Product  %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   3-Insert product  %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c        0-Exit       %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		
		color(15);
		printf("\n\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   Inserisci scelta  %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		color(15); 
		scelta=eventiAdmin();

		switch(scelta){
		
			case 1:
				system("cls");
				prodottiDb=leggiFileProd(prodottiDb);
				if(prodottiDb==NULL){
					color(12); 
					printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%cNon ci sono prodotti da visualizzare%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
					color(15); 
					break;
					}
				stampaListaProdotti(prodottiDb);
				prodottiDb=freeListaPR(prodottiDb);
				tornaMenu();
				break;
				
			case 2:
				system("cls");
				prodottiDb=leggiFileProd(prodottiDb);
				if(prodottiDb==NULL){
					color(12); 
					printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c Non ci sono prodotti modificabili  %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
					color(15); 
					break;
					}
				prodottiDb=modificaProdotti(prodottiDb);
				stampaListaProdotti(prodottiDb);
				prodottiDb=freeListaPR(prodottiDb);
				tornaMenu();
				break;
				
			case 3:
				system("cls");
				do{
					prodottiDb=nuovoProdotto();
					color(2); 
					printf("Vuoi inserire altri prodotti(1-si, 0-no)? ");
					color(15);
					scanf("%d",&continua);
				}while(continua!=0);
				prodottiDb=freeListaPR(prodottiDb);
				tornaMenu();
				break;
				
			case 0:
				system("cls");	
		}	
	}while(scelta!=0);
	
	color(2);
	printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   ",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4);
	color(15);
	printf("GOODBYE TO MOUNT ST. ANGEL SHOP  ");
	color(2);
	printf("%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	color(15);
	exit(-1);

}

