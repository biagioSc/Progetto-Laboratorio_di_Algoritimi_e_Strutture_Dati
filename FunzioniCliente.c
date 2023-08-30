//OK funzioniCliente 19
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


//Funzione che EliminaLista di clienti
cliente *freeListaCL(cliente *head){
	
	cliente *tmp=NULL;
	while(head != NULL) {
		tmp = head;
		head->prev=NULL;
		head = head->next;
		free(tmp);
	}	
	return head;
}

//Ok Funzione che crea nuovo cliente
cliente *creaCliente(Stringa nome, Stringa cognome, Stringa username, Stringa password, float saldo){
	
	cliente *e;
	e = (cliente *) malloc(sizeof(cliente));
	strcpy(e->nome,nome);	
	strcpy(e->cognome,cognome);
	strcpy(e->username,username);
	strcpy(e->password,password);
	e->conto=saldo;
	e->next=NULL;
	e->prev=NULL;
	return e;
} 

//OK Funzione che inserisce in coda nella lista di clienti
cliente *inserisciListaCliente(cliente *nodo, cliente *head){

	cliente *tmp=NULL;
	if (head==NULL){
		tmp=nodo;
		head=tmp;
	}
	else{
		tmp=inserisciListaCliente(nodo,head->next);
		head->next=tmp;
		tmp->prev=head;
	}

	return head;
}

//OK Funzione che controlla che i dati (username e password) non siano già presenti nel sistema
int controllaDatiCliente(Stringa username){
	
	FILE *fp;
	fp = fopen("databaseCliente.txt","r");
	
	Stringa n,c,u,p;
	int k=0;
	float con;
	
	while (fscanf(fp,"%s%s%s%s%f\n", &n, &c, &u, &p, &con)==5) {
		k= strcmp(u,username);
		if (k==0){ 
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

//OK Funzione che prende le info di un cliente
cliente *chiediInfoCliente(){
	
	cliente *account;
	Stringa nome, cognome, username, password;
	float saldo;
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
	control=controllaDatiCliente(username);
	while(strlen(username)<9 || control==1){
		color(12); 
		printf("Username troppo corta (almeno 9 caratteri) o gia' usata!\n");
		color(15); 
		gets(username);
		control=controllaDatiCliente(username);
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
	
	color(12);
	printf("\nInserire l'importo che si vuole caricare (inserire 0 per non ricaricare): ");
	color(15);
	scanf("%f",&saldo);
	while(saldo<0){
		color(12);
		printf("Inserire un importo positivo!\n");
		color(15);
		scanf("%f",&saldo);
	}
	
	
	account=creaCliente(nome,cognome,username,password,saldo);
	return account;
	
}

//OK Funzione che registra cliente sul file database
cliente *scriviFileCliente(FILE *fp){
	
	cliente *account;
	account=chiediInfoCliente();
	int registrato;
	while(!feof) registrato=0;
	if((fprintf(fp,"%s %s %s %s %.2f \n",account->nome,account->cognome,account->username,account->password,account->conto))!=0)registrato=1;
	
	if(registrato==1 && account!=NULL)return account;
}

//OK Funzione che registra cliente
cliente *registraCliente(){
		
		FILE *fp;
		cliente *registrato=NULL;
		fp = fopen("databaseCliente.txt","a");
		registrato=scriviFileCliente(fp);
		fclose(fp);
		return registrato;
}

//OK Funzione che legge cliente dal file database
cliente *leggiFileCliente(cliente *head){
	
	FILE *fp = fopen("databaseCliente.txt","r");
	Stringa nome, cognome, username, password;
	float saldo;
	cliente *tmp=head;
	cliente *nodo=NULL;
	
	while (fscanf(fp,"%s %s %s %s %f", nome,cognome,username,password, &saldo)==5){

		nodo=creaCliente(nome,cognome,username,password,saldo);
		if (nodo == NULL) exit(-1);
		head = inserisciListaCliente(nodo, head);
	}
	
	fclose(fp);
	return head;
}	

//OK Funzione ausiliare alla ricerca di un cliente nel file per vedere se è registrato già
cliente *trovaCliente(FILE *fp, Stringa username, Stringa password){
	
	Stringa n,c,u,p;
	int k=0,j=0;
	float price;
	cliente *ad=NULL;
	
	while (fscanf(fp,"%s%s%s%s%f\n", n, c, u, p,&price)==5) {
		k= strcmp(u,username);
		j= strcmp(p,password);
		if (k==0 && j==0){ 
			ad=creaCliente(n,c,u,p,price);
			return ad;
		}
	}
	
	return NULL;
}

//OK Funzione ausiliare per l'accesso di un cliente
cliente *accediCliente(Stringa username, Stringa password){
		
		FILE *fp;
		cliente *trovato=NULL;
		fp = fopen("databaseCliente.txt","r");

		trovato=trovaCliente(fp, username, password);
		fclose(fp);
		return trovato;
}

//OK Funzione che permette l'accesso
void paginaAccessoCliente(){
	
	Stringa username, password;
	cliente *entrato=NULL;
	do{
		color(12); 
		printf("\n					Inserisci username:\n					"); 
		color(15);
		scanf("%s",&username);
		color(12); 
		printf("\n					Inserisci password:\n					"); 
		color(15);
		scanf("%s",&password);

		entrato=accediCliente(username,password);
		
		if(entrato!=NULL){
			color(15);
			printf("\n\n			Benvenuto nella pagina di controllo cliente\n\n");		
		}
		else {
			color(12);
			printf("\n\n		Username o password errata!");
		}
		
		color(15);

	}while(entrato==0);
	
	unitControlCliente(entrato);
}

//OK Funzione che permette la registrazione
void paginaRegistraCliente(){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	Stringa username, password;
	cliente *entrato=NULL;
	do{
		
		entrato=registraCliente();
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
	
	unitControlCliente(entrato);
}

//OK Funzione che modifica le info cliente registrate
void modificaFileCliente(cliente *account, cliente *lista){
	
	
	FILE *fp;
	fp = fopen("databaseCliente.txt","w");
	int registrato;
	cliente *scorrLista=lista;
	
	while(scorrLista!=NULL){
		if(strcmp(scorrLista->username,account->username)==0 && strcmp(scorrLista->password,account->password)==0){
			scorrLista->conto=account->conto;
		}
		scorrLista=scorrLista->next;
	}

	while(lista!=NULL){
		fprintf(fp,"%s %s %s %s %.2f \n",lista->nome,lista->cognome,lista->username,lista->password,lista->conto);
		lista=lista->next;
	}
	fclose(fp);
}

//OK Funzione che svuota il saldo corrente
cliente *svuotaConto(cliente *head){
	
	char euro=36;
	int scelta;

	printf("\n\nSEI SICURO DI VOLER AZZERARE IL TUO SALDO CORRENTE?(1-SI, 0-NO)	");
	scanf("%d",&scelta);
	if(scelta==1){
		if(head->conto!=0) head->conto=0;
		printf("\nIl tuo saldo corrente e': %.2f%c\n",head->conto,euro);
	}
	else{
		printf("\nIl tuo saldo corrente e': %.2f%c\n",head->conto,euro);
	}
	return head;	
}

//OK Funzione che ricarica il saldo corrente
cliente *ricaricaConto(cliente *head){
	
	char euro=36;
	float ric;
	
	printf("\nIl tuo saldo corrente e': %.2f%c\n",head->conto,euro);
	color(2);
	printf("\nQuanti soldi vuoi ricaricare? ");
	color(15);
	scanf("%f",&ric);
	head->conto=head->conto+ric;
	printf("\nIl tuo saldo corrente ora e': %.2f%c\n",head->conto,euro);

	return head;	
}

//OK Funzione che preleva da saldo corrente
cliente *preleva(cliente *head){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	char euro=36;
	float ric;
	
	printf("\nIl tuo saldo corrente e': %.2f%c\n",head->conto,euro);
	do{
		color(2);
		printf("\nQuanti soldi vuoi prelevare? (Inserire importo positivo)");
		color(15);
		scanf("%f",&ric);
	}while(ric<0);
	if(head->conto-ric<0){
		color(12);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c SALDO INSUFFICIENTE %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		color(15);
	}
	else{
		head->conto=head->conto-ric;
		printf("\nIl tuo saldo corrente ora e': %.2f%c\n",head->conto,euro);
	}
	return head;	
}

//OK Funzione che modifica saldo corrente
cliente *modificaConto(cliente *head, float buy){
	
		head->conto=head->conto-buy;
		return head;
}

//OK Funzione che acquista prodotti 
carrello *acquistaProdotti(cliente *head,prodotti *listaProd){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;	
	carrello *acquisti=NULL, *cart=NULL;
	cliente *listaClienti=NULL;
	float totale;
	char euro=36;
	
	acquisti=creaCarrello(listaProd,head);
	totale=daPagare(acquisti);
	
	system("cls");
	cart=acquisti;
	color(11);
	printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%cProdotti nel Carrello%c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	color(15);
	stampaListaCarrello(cart);
	printf("\nTotale da pagare %.2f%c\n",totale,euro);
	
	while(head->conto<totale){
		color(12);
		printf("\n\nSaldo insufficiente, eseguire una ricarica\n\n");
		color(15);
		head=ricaricaConto(head);
	}
	
	head=modificaConto(head,totale);

	color(2);
	printf("\n\nPagamento effettuato\n\n");
	color(15);

	listaClienti=leggiFileCliente(listaClienti);
	modificaFileCliente(head,listaClienti);
	
	return acquisti;
}

//OK Funzione unità di controllo cliente
void unitControlCliente(cliente *UtenteC){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	char cc=218,cc2=196,cc3=191,cc4=179,cc5=217,cc6=192;
	int scelta, continua, buy;
	prodotti *prodottiDb=NULL;
	carrello *cart=NULL;
	cliente *listaClient=NULL;
	char euro=36;
	attesa *notizia=NULL;
	
	Sleep(2000);
	system("cls");
	
	do{
		color(2);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c1-Apri lista prodotti%c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c 2-Acquista prodotti %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c   3-Apri notifiche  %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c   4-Ricarica conto  %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c    5-Svuota conto   %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c     6-Apri conto    %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c      7-Preleva      %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c        0-Esci       %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		
		
		notizia=notifiche(UtenteC);
		if(notizia!=NULL){
			color(15);
			printf("\n\nHAI DELLE NUOVE NOTIFICHE, INSERISCI '3' PER VISUALIZZARLE\n\n");
		}
		
		color(11);
		printf("		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n		%c   Inserisci scelta  %c\n		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		color(15);
		scelta=eventiCliente();		

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
					printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c Non ci sono prodotti da acquistare %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
					color(15);
					break;
				}
				cart=acquistaProdotti(UtenteC, prodottiDb);
				if(cart==NULL){
					color(12);
					printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c    Non hai acquistato prodotti    %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
					color(15);
					break;
					}
				stampaListaCarrello(cart);
				cart=freeListaCR(cart);
				prodottiDb=freeListaPR(prodottiDb);
				tornaMenu();
				break;
			case 3:
				system("cls");
				if(notizia!=NULL)grafica(UtenteC,notizia);
				else grafica(UtenteC,notizia);
				tornaMenu();
				break;
				
			case 4:
				system("cls");
				listaClient=freeListaCL(listaClient);
				UtenteC=ricaricaConto(UtenteC);
				listaClient=leggiFileCliente(listaClient);
				modificaFileCliente(UtenteC,listaClient);
				listaClient=freeListaCL(listaClient);
				tornaMenu();
				break;
			
			case 5:
				system("cls");
				listaClient=freeListaCL(listaClient);
				UtenteC=svuotaConto(UtenteC);
				listaClient=leggiFileCliente(listaClient);
				modificaFileCliente(UtenteC,listaClient);
				listaClient=freeListaCL(listaClient);
				tornaMenu();
				break;
				
			case 6:
				system("cls");
				color(2);
				printf("\n\nIl tuo saldo attuale e' di: ");
				color(15);
				printf("%.2f%c\n\n",UtenteC->conto,euro);
				color(15);
				tornaMenu();
				break;
				
			case 7:
				system("cls");
				listaClient=freeListaCL(listaClient);
				UtenteC=preleva(UtenteC);
				listaClient=leggiFileCliente(listaClient);
				modificaFileCliente(UtenteC,listaClient);
				listaClient=freeListaCL(listaClient);
				tornaMenu();
				break;
			
			case 0:
				UtenteC=freeListaCL(UtenteC);
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

