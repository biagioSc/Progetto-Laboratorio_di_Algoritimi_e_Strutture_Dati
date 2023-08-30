//FunzioniListaDiAtttesa 9
// Alunno: Biagio Scotto di Covella
// Matricola : N86003605

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include <windows.h> 
#include <conio.h>
#include "prototipi.h"


//OK Funzione crea file di attesa
void listaAttesa(cliente *account, carrello*cart){
	
	FILE *fp;
	fp = fopen("databaseAttesa.txt","a");
	
	fprintf(fp,"%s %s %s %s %s %d\n",account->nome,account->cognome, account->username, cart->nome, cart->taglia, cart->quantita);
	fclose(fp);
}	

//OK Funzione crea un nodo di attesa
attesa *creaAttesa(Stringa nome,Stringa cognome,Stringa username, Stringa nomeprod,char taglia[4],	int quantita){
	  
	attesa *e;
	e = (attesa *) malloc(sizeof(attesa));
	strcpy(e->nome,nome);
	strcpy(e->cognome,cognome);
	strcpy(e->username,username);
	strcpy(e->nomeprod,nomeprod);
	strcpy(e->taglia,taglia);
	e->quantita=quantita;
	e->next=NULL;	
	e->prev=NULL;	
	return e;
}

//OK Funzione crea una lista di notifiche per un cliente
attesa *inserisciListaNotifiche(Stringa nome,Stringa cognome,Stringa username, Stringa nomeprod,char taglia[4],int quantita, attesa *head){
	
	attesa *tmp=NULL, *nodo=NULL;
	nodo=creaAttesa(nome,cognome,username,nomeprod,taglia,quantita);
	
	if (head==NULL){
		tmp=creaAttesa(nome,cognome,username,nomeprod,taglia,quantita);
		head=tmp;
	} 
	else{
		tmp=inserisciListaNotifiche(nome,cognome,username,nomeprod,taglia,quantita,head->next);
		head->next=tmp;
		tmp->prev=head;
	}
	return head;

}

//OK Funzione leggi file di attesa
attesa *leggiFileAttesa(attesa *head){
	
	FILE *fp;
	fp = fopen("databaseAttesa.txt","r");
	Stringa name,cognome,username,cartnome;
	char tg1[4];
	int qta;
	
	while(fscanf(fp,"%s %s %s %s %s %d\n",name,cognome, username, cartnome, tg1, &qta)==6){
		
		head=inserisciListaNotifiche(name,cognome,username,cartnome,tg1,qta,head);
	}
	fclose(fp);
	return head;
}	

//Funzione che elimina un nodo da lista di attesa
attesa *eliminaNodo(attesa *head1,attesa *nodo){
		
	attesa*head=head1;
	
	if(head==NULL)return NULL;
	
		
		if(strcmp(head->username,nodo->username)==0){
			//centrale
		if(head->prev!=NULL && head->next!=NULL){
			head->prev->next=head->next;
			head->next->prev=head->prev;
			attesa *tmp=head;
			head=head->next;
			return head;
			}
			//coda
		else if (head->prev!=NULL && head->next==NULL){
			head->prev->next=NULL;
			attesa *tmp=head;
			head=head->next;
			return head;
		}
			//testa
		else if(head->next!=NULL && head->prev==NULL){
			head->next->prev=NULL;
			attesa *tmp=head;
			head=head->next;
			return head;
		}
		
		}
		
		else{
		head->next=eliminaNodo(head->next,nodo);
	}
	return head1;
	
}

//Funzione che mostra notifica
void mostraNotifica(attesa *mess){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	attesa *tmp=mess;
	char euro=36;
	int i=1;
	color(2);
	printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   ",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4);
	color(15);
	printf("I seguenti prodotti sono di nuovo disponibili  ");
	color(2);
	printf("%c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
	color(15);
	

	while(tmp!=NULL){
		printf("\n\n\n%d) Nome prodotto: %s	Taglia: %s	Quantita': %d\n\n\n",i, tmp->nomeprod, tmp->taglia, tmp->quantita);
		i++;
		tmp=tmp->next;
		}
}

//Funzione modifica file di attesa
void modificaFileAttesa(attesa *head,attesa *corrente){
	
	FILE *fp;
	fp = fopen("databaseAttesa.txt","w");
	attesa *tmp=head;
	
	while(tmp!=NULL){
		if(strcmp(tmp->username,corrente->username)==0)tmp=tmp->next;
		else{
			fprintf(fp,"%s %s %s %s %s %d\n",tmp->nome,tmp->cognome, tmp->username, tmp->nomeprod, tmp->taglia, tmp->quantita);
			tmp=tmp->next;
		}
	}
	fclose(fp);

}	

//Funzione controllo notifiche
attesa *notifiche(cliente *utente){
	
	prodotti *listaProd=NULL;
	attesa *listaAttesa=NULL,*nodocorrente=NULL,*listaRitorno=NULL;
	
	listaProd=leggiFileProd(listaProd);
	listaAttesa=leggiFileAttesa(listaAttesa);
	nodocorrente=listaAttesa;
	
	while(listaProd!=NULL){
		nodocorrente=listaAttesa;
		while(nodocorrente!=NULL){
			if(strcmp(utente->username,nodocorrente->username)==0){
				if(strcmp(listaProd->nome,nodocorrente->nomeprod)==0){
					taglie *taglia=listaProd->listaTaglie;
					while(taglia!=NULL){
						if(strcmp(taglia->tg,nodocorrente->taglia)==0){
							if(taglia->qta>=nodocorrente->quantita){
								listaRitorno=inserisciListaNotifiche(nodocorrente->nome,nodocorrente->cognome,nodocorrente->username,nodocorrente->nomeprod,nodocorrente->taglia,nodocorrente->quantita,listaRitorno);
								listaAttesa=eliminaNodo(listaAttesa,nodocorrente);
								modificaFileAttesa(listaAttesa,nodocorrente);
							}
						}
						taglia=taglia->next;
					}
					
				}
			}
			nodocorrente=nodocorrente->next;
		}
		listaProd=listaProd->next;
	}
		return listaRitorno;
}

//Funzione per grafica notifica
void grafica(cliente *cl, attesa *head){

	int dato,scelta;
	
	if(head==NULL) dato=0;
	else dato=1;
	
	char cc=218,cc2=196,cc3=191,cc4=179,cc5=217,cc6=192;
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	char diritta=179, diagonalesx=47, diagonaledx=92, linea=196;
	char angolo1=192, angolo2=217, angolo3=218, angolo4=191,giu=31,su=30;
	printf("%c%c%c%c%c%c%c\n",angolo3,linea,linea,linea,linea,linea,angolo4);
	printf("%c%c %d %c%c\n",diritta,diagonaledx,dato,diagonalesx,diritta);
	printf("%c %c %c %c\n",diritta,diagonaledx,diagonalesx,diritta);
	printf("%c  %c  %c\n",diritta,giu,diritta);
	printf("%c%c%c%c%c%c%c\n",angolo1,linea,linea,linea,linea,linea,angolo2);

	if(dato==0) printf("\n\nNON HAI NUOVE NOTIFICHE!\n\n");
	else{
		char scelta;
		printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   Inserisci 1 per aprire la posta  %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
		
	do{	
		if (kbhit()){
				
			scelta=getch();
			if(scelta=='1'){
				system("cls");
				printf("   %c    \n",su);
				printf("  %c %c   \n",diagonalesx,diagonaledx);	
				printf(" %c   %c  \n",diagonalesx,diagonaledx);
				printf("%c%c%c%c%c%c%c\n",angolo3,linea,linea,linea,linea,linea,angolo4);
				printf("%c  %d  %c\n",diritta,dato,diritta);
				printf("%c%c%c%c%c%c%c\n",angolo1,linea,linea,linea,linea,linea,angolo2);
				mostraNotifica(head);
				return;
				}
			}
	}while(scelta!='1');
			
  }
}


