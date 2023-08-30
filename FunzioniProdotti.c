//FunzioniProdotti 23
// Alunno: Biagio Scotto di Covella
// Matricola : N86003605

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include <windows.h> 
#include <conio.h>
#include <ctype.h>
#include "prototipi.h"

//OK Funzione per tornare alla home principale
void tornaMenu(){
	
	char c=201, c2=205, c3=187, c4=186, c5=188, c6=200;
	char scelta;
		printf("			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n			%c   Inserisci 1 per tornare al menu  %c\n			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c3,c4,c4,c6,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c5);
    
	do{
		if (kbhit()){
			scelta=getch();
            if (scelta=='1'){
				system("cls");
				return;
			}
		}
    }while (scelta!=1);

	return;
}

//Funzione per intercettare eventi da tastiera HomeMain
int eventiMain(){
	
    char scelta;
    do
    {
        if (kbhit())
        {
            scelta=getch();
            if (scelta=='1') return 1;
			else if (scelta=='2') return 2;
        }
    }while (scelta!='0');

    return 0;
}

//Funzione per intercettare eventi da tastiera HomeMainScelta
int eventiMainScelta(){
	
    char scelta;
    do
    {
        if (kbhit())
        {
            scelta=getch();
            if (scelta=='1') return 1;
			else if (scelta=='0') return 0;
        }
    }while (scelta!='3');

    return 3;
}

//Funzione per intercettare eventi da tastiera Admin
int eventiAdmin(){
	
    char scelta;
    do
    {
        if (kbhit())
        {
            scelta=getch();
            if (scelta=='1') return 1;
			else if (scelta=='2') return 2;
            else if (scelta=='3') return 3;

        }
    }while (scelta!='0');

    return 0;
}

//Funzione per intercettare eventi da tastiera Cliente
int eventiCliente(){
	
    char scelta;
    do
    {
        if (kbhit())
        {
			scelta=getch();  
			if (scelta=='1') return 1;
			else if (scelta=='2') return 2;
            else if (scelta=='3') return 3;
			else if (scelta=='4') return 4;
			else if (scelta=='5') return 5;
			else if (scelta=='6') return 6;
			else if (scelta=='7') return 7;

        }
    }while (scelta!='0');

    return 0;
}

//Funzione per impostare  il colore delle scritte stampate sul prompt
void color(int x){
	
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,x);
/*
0   = Nero
1   = Blu scuro
2   = Verde
3   = Verde acqua
4   = Bordeaux
5   = Viola
6   = Verde oliva
7   = Grigio chiaro
8   = Grigio
9   = Blu
10 = Verde limone  (A)
11 = Azzurro            (B)
12 = Rosso               (C)
13 = Fucsia              (D)
14 = Giallo                (E)
15 = Bianco              (F)	
*/
}



/*----------------------------------------------------*/




//Funzione che EliminaLista di taglie
taglie *freeListaTG(taglie *head){
	
	taglie *tmp=NULL;
	while(head != NULL) {
		tmp = head;
		head->prev=NULL;
		head = head->next;
		free(tmp);
	}	
	return head;
}

//OK Funzione stampa la lista di taglie di un prodotto
void stampaListaTaglie(taglie *head){
	
	while (head != NULL) {
		if(head->qta<=0) color(12);
		else color(10);	
		printf("%s:", head->tg);
		printf("%d; ", head->qta);
		head = head->next;
	}
	color(15);
	printf("\n");	
}

//OK Funzione crea taglia di un prodotto
taglie *creaTaglie(char size[3], int quant){

	taglie *e;
	e = (taglie *) malloc(sizeof(taglie));
	strcpy(e->tg,size);	
	e->qta = quant;
	e->next = NULL;
	e->prev = NULL;

	return e;
} 

//OK Funzione che inserisce in coda nella lista delle taglie
taglie *insertCodaTg(taglie *nodo, taglie *head){

	taglie *tmp;
	if (head==NULL) return nodo;

	tmp = head;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}

	tmp->next=nodo;
	nodo->prev=tmp;

	return head;
}



/*-------------------------------------------------------*/



//Funzione che EliminaLista di prodotti
prodotti *freeListaPR(prodotti *head){
	
	prodotti *tmp=NULL;
	while(head != NULL) {
		tmp = head;
		head->prev=NULL;
		head = head->next;
		free(tmp);
	}	
	return head;
}

//OK Funzione stampa la lista di prodotti
void stampaListaProdotti(prodotti *head){
	
	char euro=36;
	while (head != NULL) {
		color(11);
		printf("%d)	", head->identificativo);
		color(15);
		printf("%s ",head->nome);
		printf("%.2f%c: ", head->prezzo,euro);
		stampaListaTaglie(head->listaTaglie);
		printf("\n");
		head = head->next;
	}
}

//OK Funzione crea prodotto
prodotti *creaProd(Stringa name, float price, taglie *Taglie, int i){
	
	prodotti *e;
	e = (prodotti *) malloc(sizeof(prodotti));
	strcpy(e->nome,name);
	e->identificativo=i;
	e->prezzo=price;	
	e->listaTaglie=Taglie;	
	e->next=NULL;	
	e->prev=NULL;	
	return e;
} 

//OK Funzione che inserisce in coda nella lista di prodotti
prodotti *inserisciLista(prodotti *nodo, prodotti *head){

	prodotti *tmp;
	if (head==NULL) return nodo;
	tmp = head;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = nodo;
	nodo->prev=tmp;

	return head;
}

//OK Funzione che controlla che i dati (nome) non siano già presenti nel sistema
int controllaDatiProdotto(Stringa nome){
	
	FILE *fp;
	fp = fopen("databaseProdotti.txt","r");
	
	Stringa name;
	char tg1[]="XXS", tg2[]="XS", tg3[]="S", tg4[]="M", tg5[]="L", tg6[]="XL", tg7[]="XXL";	
	int qta1, qta2, qta3, qta4, qta5, qta6, qta7;
	float price;
	int k=0;
	
	while (fscanf(fp,"%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%f", tg1,&qta1, tg2,&qta2, tg3,&qta3, tg4,&qta4, tg5,&qta5, tg6,&qta6, tg7,&qta7, name,&price)==16){
		k= strcmp(name,nome);
		if (k==0){ 
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

//OK Funzione che chiede le informazioni relative ad un prodotto all'admin
prodotti *chiediInfoProdotto(prodotti *head){
	
	static int i=1;
	Stringa nome;
	char tg1[]="XXS", tg2[]="XS", tg3[]="S", tg4[]="M", tg5[]="L", tg6[]="XL", tg7[]="XXL";	
	int qta1=0, qta2=0, qta3=0, qta4=0, qta5=0, qta6=0, qta7=0, dato=0;
	float price;
	taglie *listaTg=NULL;
	taglie *node=NULL;
	
	fflush(stdin);
	printf("\nInserire nome(usare '_' come spazio): ");
	gets(nome);
	dato=controllaDatiProdotto(nome);

	do{
		printf("Nome gia' nel sistema oppure non inserito correttamente\n");
		printf("\nInserire nome(usare '_' come spazio): ");
		gets(nome);
		dato=controllaDatiProdotto(nome);
	}while (nome[0]=='\0' || isdigit(nome[0]) ||dato==1);

	puts("\n");
	printf("Inserire Quantita' Taglia XXS: ");
	scanf("%d",&qta1);
	printf("Inserire Quantita' Taglia XS: ");
	scanf("%d",&qta2);
	printf("Inserire Quantita' Taglia S: ");
	scanf("%d",&qta3);
	printf("Inserire Quantita' Taglia M: ");
	scanf("%d",&qta4);
	printf("Inserire Quantita' Taglia L: ");
	scanf("%d",&qta5);
	printf("Inserire Quantita' Taglia XL: ");
	scanf("%d",&qta6);
	printf("Inserire Quantita' Taglia XXL: ");
	scanf("%d",&qta7);
	
	printf("\nInserire prezzo(Mettere il '.' per i numeri decimali): ");
	scanf("%f",&price);

		node=creaTaglie(tg1,qta1);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg2,qta2);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg3,qta3);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg4,qta4);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg5,qta5);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg6,qta6);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg7,qta7);
		listaTg=insertCodaTg(node,listaTg);

	head=creaProd(nome,price,listaTg,i);
	listaTg=NULL;//freeListaTG(listaTg);(listaTg);
	i++;
	return head;
}

//OK Funzione che legge i prodotti dal file databaseProdotti
prodotti *leggiFileProd(prodotti *head){
	
	FILE *fp = fopen("databaseProdotti.txt","r");
	static int i=1;
	Stringa name;
	char tg1[]="XXS", tg2[]="XS", tg3[]="S", tg4[]="M", tg5[]="L", tg6[]="XL", tg7[]="XXL";	
	int qta1, qta2, qta3, qta4, qta5, qta6, qta7;
	float price;
	int id;
	prodotti *nodo;
	taglie *listaTg=NULL;
	taglie *node=NULL;
	while (fscanf(fp,"%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%f", tg1,&qta1, tg2,&qta2, tg3,&qta3, tg4,&qta4, tg5,&qta5, tg6,&qta6, tg7,&qta7, name,&price)==16){

		node=creaTaglie(tg1,qta1);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg2,qta2);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg3,qta3);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg4,qta4);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg5,qta5);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg6,qta6);
		listaTg=insertCodaTg(node,listaTg);
		node=creaTaglie(tg7,qta7);
		listaTg=insertCodaTg(node,listaTg);
		nodo = creaProd(name,price,listaTg,i);
		listaTg=NULL;//freeListaTG(listaTg);
		if (nodo == NULL) exit(-1);
		head = inserisciLista(nodo, head);
		i++;
	}
	i=1;
	fclose(fp);
	return head;
}	
	
//OK Funzione inserimento nuovi prodotti
prodotti *nuovoProdotto(){
	
	prodotti *nuovoProd=NULL;
	nuovoProd=chiediInfoProdotto(nuovoProd);
	
	prodotti *listaProd=NULL;
	listaProd=leggiFileProd(listaProd);
		
	listaProd=inserisciLista(nuovoProd,listaProd);
	scriviFileProdotto(listaProd);

	return listaProd;
	
}

//OK Funzione che scrive sul file databaseProdotti
int scriviFileProdotto(prodotti *listaProd){

	taglie *TG=NULL;
	
	FILE *fp = fopen("databaseProdotti.txt","w");
		
	if(fp==NULL ) {
		printf("Si e' verificato un errore in apertura del file\n");
		return 0;
	}

	while(listaProd!=NULL){
		TG=listaProd->listaTaglie;

		while(TG!=NULL){
			fprintf(fp,"%s %d  ", TG->tg, TG->qta);
			TG=TG->next;
		}
	
		fprintf(fp,"%s	",listaProd->nome);
		fprintf(fp,"%.2f  \n",listaProd->prezzo);
		listaProd=listaProd->next;
	}
	
	fclose(fp);
	return 1;
}

//OK Funzione che modifica info di un prodotto	
prodotti *modificaProdotti(prodotti *listaProd){
	
	prodotti *prodSelect=NULL;
	prodotti *TMP=listaProd;

	int modifica;
	printf("\n\n	Quale prodotto vuoi modificare(Selezionare un numero solo)? \n\n\n");
	stampaListaProdotti(listaProd);
	scanf("%d",&modifica);
	
	while(listaProd!=NULL){
		if(listaProd->identificativo==modifica){
			prodSelect=chiediInfoProdotto(prodSelect);
			strcpy(listaProd->nome,prodSelect->nome);
			listaProd->prezzo=prodSelect->prezzo;	
			listaProd->listaTaglie=prodSelect->listaTaglie;
		}
		listaProd=listaProd->next;
	}
	
	scriviFileProdotto(TMP);
	return TMP;
}



/*-------------------------------------------------*/



//Funzione che EliminaLista del carrello
carrello *freeListaCR(carrello *head){
	
	carrello *tmp=NULL;
	while(head != NULL) {
		tmp = head;
		head->prev=NULL;
		head = head->next;
		free(tmp);
	}	
	return head;
}

//OK Funzione stampa la lista di prodotti acquistato
void stampaListaCarrello(carrello *head){
	
	float totale=0;
	char euro=36;
	static int i=0;
	while (head != NULL) {
		i++;
		printf("%d) %s ", i,head->nome);
		printf("Taglia:%s Qta: %d ",head->taglia,head->quantita);
		printf("%.2f%c ", head->prezzo,euro);
		printf("\n");
		totale=totale+(head->prezzo*head->quantita);
		head = head->next;
	}
	printf("-----------------------------------------------");
	printf("\n						 %.2f%c",totale,euro);
	printf("\n\n");
	i=0;
}

//OK Funzione crea prodotto acquistato
carrello *creaProdCarrello( char tg[4],Stringa name, float price, int qta){
	
	carrello *e;
	e = (carrello *) malloc(sizeof(carrello));
	strcpy(e->nome,name);
	e->prezzo=price;	
	strcpy(e->taglia,tg);	
	e->quantita=qta;
	e->next=NULL;	
	e->prev=NULL;	
	return e;
} 

//OK Funzione che inserisce in coda nella lista di prodotti acquistato
carrello *inserisciListaCarrello(carrello *nodo, carrello *head){

	carrello *tmp=NULL;
	if (head==NULL) return nodo;
	tmp = head;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = nodo;
	nodo->prev=tmp;

	return head;
}

//OK Funzione che crea carrello	
carrello *creaCarrello(prodotti *listaProd, cliente *account){
	
	prodotti *prodSelect=listaProd;
	prodotti *tmp=listaProd;
	carrello *nodoNew=NULL, *acquisti=NULL;
	int esc=0,var,acquistato;
	
	char tagliaSelect[4] ;
	int modifica, qtaS;
	taglie *listaTag=NULL;
	color(11);
	printf("\nQuale prodotto vuoi comprare(Selezionare un numero solo; 0 per andare al carrello)? \n\n");
	color(15);
	stampaListaProdotti(listaProd);
	scanf("%d",&modifica);
	
	do{
		color(11);
		printf("\nSelezionare una taglia: XXS, XS, S, M, L, XL, XXL --> ");
		color(15);
		scanf("%s",&tagliaSelect);
		
		color(11);
		printf("\nInserire quantita' --> ");
		color(15);
		scanf("%d",&qtaS);
		
		while(listaProd!=NULL){
			if(listaProd->identificativo==modifica){

				listaTag=listaProd->listaTaglie;
					while(listaTag!=NULL){
						if(strcmp(listaTag->tg,tagliaSelect)==0){
								if((listaTag->qta-qtaS)<0){
									while((listaTag->qta-qtaS)<0&&esc==0){
										color(12);
										printf("\nProdotto non disponibile in questa quantita'\n");
										color(11);
										printf("\nInserire una quantita' adeguata oppure mettersi in lista di attesa (1-nuova quantita' 0-lista di attesa)\n--> ");
										color(15);
										scanf("%d",&var);
										
										if(var==1){
											color(11);
											printf("\nInserire quantita' --> ");
											color(15);
											scanf("%d",&qtaS);
											if(listaTag->qta<qtaS) esc=0;
											else {
												acquistato=1;
												esc=1;
											}
										}
										else if(var==0){ 
											carrello *nodoTmp=creaProdCarrello(listaTag->tg,listaProd->nome,listaProd->prezzo,qtaS);
											listaAttesa(account,nodoTmp);
											acquistato=0;
											esc=1;
										}
									}
								}
								else{
									acquistato=1;
								}								
								if(acquistato==1&&qtaS!=0){
									listaTag->qta=listaTag->qta-qtaS;
									nodoNew=creaProdCarrello(listaTag->tg,listaProd->nome,listaProd->prezzo,qtaS);
									acquisti=inserisciListaCarrello(nodoNew,acquisti);
									
								}
								listaTag=NULL;//freeListaTG(listaTg);(listaTag);
							}
						else{							
							esc=0;
							listaTag=listaTag->next;
						}
					}
					listaProd=NULL;
			}
			else{
			listaProd=listaProd->next;
			}
		}
		listaProd=tmp;
		scriviFileProdotto(prodSelect);
		color(11);
		printf("\nQuale prodotto vuoi comprare(Selezionare un numero solo; 0 per andare al carrello)? \n\n");
		color(15);
		stampaListaProdotti(prodSelect);
		scanf("%d",&modifica);
		prodSelect=tmp;
		
	}while(modifica!=0);
	
	return acquisti;
}

//OK funzione che dice il totale da pagare
float daPagare(carrello *cart){
	
	carrello *tmp=cart;
	int totale=0;
	
	while(tmp!=NULL){
		totale=totale+tmp->prezzo*tmp->quantita;
		tmp=tmp->next;
	}
	return totale;
}

