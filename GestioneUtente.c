//GestioneUtente.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestioneGrafica.h"
#include "Grafi_Partenze_Destinazioni.h"
#include "GestioneUtente.h"
#include "GestioneFile.h"
#include "StruttureAccessorie.h"


void aggiornaFileUtenteSaldo(struct Utente *utenteMain)
{
    FILE *fpIn=fopen("UTENTI.txt","r");//Il file originale viene aperto in modalita lettura
    FILE *fpOut=fopen("utente2.txt","w");//E ne viene creato un temporaneo in modalità scrittura
    Stringa nome,cognome,email,password;
    float appogio;
    int privilegio;
    while (fscanf(fpIn,"%s %s %s %s %f %d",nome,cognome,email,password,&appogio,&privilegio)==6)
    {
        if(strcmp(utenteMain->email,email)==0 && strcmp(utenteMain->passoword,password)==0)
        {
            fprintf(fpOut,"\n%s %s %s %s %f %d",nome,cognome,email,password,utenteMain->saldoCorrente,privilegio);
        }
        else
        {
            fprintf(fpOut,"\n%s %s %s %s %f %d",nome,cognome,email,password,appogio,privilegio);
        }
    }
    fclose(fpIn);
    fclose(fpOut);
    remove("UTENTI.txt");//Dopo aver modificato il file temporaneo distruggiamo il file orginale e lo 
    rename("utente2.txt","UTENTI.txt");//Sostituiamo con il nuovo file temporaneo
    
}
void modifica(graph *G,Stringa arrayCitta[])
{
    intestazione1();
    spazio(2);
    printf("Sei in Admin Mode : \n");
    spazio(2);
    if(isFileEmpty())
    {
      printf("Nessuna Richiesta di Cambiamento Grafo : \n");
      printf("Verrai Riportato alla Pagina Principale \n");
      Sleep(2500);  
      return;
    }
    printf("Puoi effettuare le seguenti modifiche : \n");
    stampaScelteRisolutive();
    printf("Scegliere una modalita di risoluzione >:  \n");
    char controllo_Viaggio='O';//Valore per il controllo di quale sottofunzione eseguire 
    int modalita_uscita=0;
    do
    {
        if (kbhit())
            {
            controllo_Viaggio=getch();
            //Modalità Vertice
            if (controllo_Viaggio=='E'||controllo_Viaggio=='e')
            {
                    modalita_uscita=1;                
                    system("cls");
                    intestazione1();
                    FILE *fpOUT = fopen("NOTIFICHE.txt","r");
                    int cittaTarget;
                    fscanf(fpOUT,"%d",&cittaTarget);
                    fclose(fpOUT);
                    printf("Verra eliminato il nodo  %s \n",arrayCitta[cittaTarget]);
                    G=eliminaElemento(G,cittaTarget);
                    printf("                                 0");
                    for(int i=0;i<55;i++)
                    {
                        Sleep(30);
                        printf("@");
                    }
                    printf("100  \n");
                    printf("Eliminazione Avvenuta con successo !");
                    pulisciFile();
                    
            }
            //Modalità Arco
            else if (controllo_Viaggio=='A'||controllo_Viaggio=='a')
            {
                    int arco,scelta,pesoEconomicoAereo,pesoVeloceAereo,pesoEconomicoTreno,pesoVeloceTreno;
                    modalita_uscita=1;
                    system("cls");
                    intestazione1();
                    FILE *fpOUT = fopen("NOTIFICHE.txt","r");
                    int cittaTarget;
                    fscanf(fpOUT,"%d",&cittaTarget);
                    printf("Puoi aggiungere un arco dal punto : %s \n",arrayCitta[cittaTarget]);
                    printf("Queste sono le citta disponibili : \n\n");
                     for (size_t i = 0; i < G->numeroVertici; i++)
                    {
                        if (cittaTarget!=i)
                        {
                            colorTesto(13);
                            printf("[");
                            colorTesto(15);
                            printf("%d:%s",i,arrayCitta[i]);
                            colorTesto(13);
                            printf("]            ");
                            if (i%4==0&&i!=0)
                            {
                                printf("\n\n  ");
                            }
                            colorTesto(15);
                        }
                    }
                    printf("\n                                          ");
                    colorTesto(13);
                    printf(">: ");
                    colorTesto(15);
                    scanf("%d",&arco);
                    printf("Ok Ora vuoi che 1=Collegamento Treno 2=Collegamento Aereo 3 = Entrambi \n");
                    printf("                                          ");
                    colorTesto(13);
                    printf(">: ");
                    colorTesto(15);
                    scanf("%d",&scelta);
                    
                    //Modalita Treno
                    if (scelta==1)
                    {
                        printf("Scelta modalita Treno !\n");
                        printf("Inserire Peso Economico - : ");
                        scanf("%d",&pesoEconomicoTreno);
                        printf("Inserire Peso Veloce - : ");
                        scanf("%d",&pesoVeloceTreno);
                        aggiungiArcoPS(G,cittaTarget,arco,pesoEconomicoTreno,99,pesoVeloceTreno,99);
                    }
                    //Modalita Aereo
                    else if (scelta==2)
                    {
                        printf("Scelta modalita Aereo !\n");
                        printf("Inserire Peso Economico - : ");
                        scanf("%d",&pesoEconomicoAereo);
                        printf("Inserire Peso Veloce - : ");
                        scanf("%d",&pesoVeloceAereo);
                        aggiungiArcoPS(G,cittaTarget,arco,99,pesoEconomicoAereo,99,pesoVeloceAereo);
                    }
                    //Modalita Entrambi
                    else
                    {
                        printf("Scelta modalita Entrambi !\n");
                        printf("Inserire Peso Economico Treno - : ");
                        scanf("%d",&pesoEconomicoTreno);
                        printf("Inserire Peso Veloce Treno- : ");
                        scanf("%d",&pesoVeloceTreno);
                        printf("Inserire Peso Economico  Aereo- : ");
                        scanf("%d",&pesoEconomicoAereo);
                        printf("Inserire Peso Veloce Aereo- : ");
                        scanf("%d",&pesoVeloceAereo);
                        aggiungiArcoPS(G,cittaTarget,arco,pesoEconomicoTreno,pesoVeloceAereo,pesoVeloceTreno,pesoEconomicoAereo);
                    }
                    fclose(fpOUT);
                    pulisciFile();
                    printf("\nAggiornamento Avvenuto con Successo!!\n\n");
                }
                
            }
        }while (modalita_uscita==0);
    Sleep(3000);
    return;

}

//Funzioni per la gestione dell User :
void acquista(struct Utente *utenteMain,graph *G,graphHotel *G_Hotel,Stringa listacitta[])
{
    Stringa path[7]={""};
    int cittaStart=0;
    int cittaTarget=0;
    int arrayCittaRangiugibili[7]={0};
    int checkSum=0;
    int resultTemp=0;
    int sceltaHotel=0;
    int sceltaModalita=0;

    printf("Scegliere tra una delle citta disponibili per la partenza     \n");
	greaficaAcquistaCitta();
   // printf("                                                      Citta : \n\n  ");
    
    for (size_t i = 0; i < G->numeroVertici; i++)
    {
        colorTesto(13);
        printf("[");
        colorTesto(15);
        printf("%d:%s",i,listacitta[i]);
        colorTesto(13);
        printf("]            ");
        if (i%4==0&&i!=0)
        {
            printf("\n\n  ");
        }
        colorTesto(15);
    }
    printf("\n                                          ");
    colorTesto(13);
    printf(">: ");
    scanf("%d",&cittaStart);
    DFSClassic(G,cittaStart,arrayCittaRangiugibili);
	greaficaAcquistaMete();
    printf("   ");
    int nessunaCitta=1;
    for (size_t i = 0; i < G->numeroVertici; i++)
    {
        if (arrayCittaRangiugibili[i]==1 && i!=cittaStart)
        {
            nessunaCitta=0;
            break;
        }
    }
    if (nessunaCitta)
    {
        colorTesto(15);
        printf("                                             Nessuna Citta Disponibile!!      \n\n\n");
        printf("Sara inviata una richiesta ai nostri admin per rangiungere anche : %s",listacitta[cittaStart]);
        inviaRichiestaIsola(cittaStart);
        Sleep(3000);
        return ;
    }
    
	int k=0;
	int numeri[6];
    for (size_t i = 0 ,j=0; i < G->numeroVertici; i++)
    {

        if (arrayCittaRangiugibili[i]==1&&i!=cittaStart)
        {
            j++;
            colorTesto(13);
            printf("[");
            colorTesto(15);
			numeri[k]=i;
			k++;
            printf("%d:%s",i,listacitta[i]);
            colorTesto(13);
            printf("]            ");
            if (j%4==0&&j!=0)
            {
                printf("\n\n   ");
            }
            colorTesto(15);    
        }
        
        
    }
	
	int flag=0;
	
	while(flag==0){
		
		printf("\n                                          ");
		colorTesto(13);
		printf(">: ");
		colorTesto(15);
		scanf("%d",&cittaTarget);
		for(int i=0;i<k;i++){
				if(cittaTarget==numeri[i]){
					flag=1;
				}
		}
	}
	
	colorTesto(15);
	printf("\n\n Hai scelto di andare a ");
	colorTesto(0);
	printf("%s ",listacitta[cittaTarget]);
	colorTesto(15);
	printf("partendo da ");
	colorTesto(0);
	printf("%s \n\n",listacitta[cittaStart]);
	colorTesto(15);
	Sleep(3500);
	
    for(int i =0; i<G->numeroVertici; i++) 
    {
        arrayCittaRangiugibili[i] = 0;
    }
    DFSAereo(G,cittaStart,arrayCittaRangiugibili);
    checkSum=(arrayCittaRangiugibili[cittaTarget]!= 0) ? 1 : 0;
    for(int i =0; i<G->numeroVertici; i++) 
    {
        arrayCittaRangiugibili[i] = 0;
    }
    DFSTreno(G,cittaStart,arrayCittaRangiugibili);
    checkSum=(arrayCittaRangiugibili[cittaTarget]!= 0) ? checkSum+3 : checkSum+0;
    //Risultati Show Off
    int scelta=0;

    if (checkSum==1)
    {
        //modalità aereo
        sceltaModalita=2;

        system("cls");
        intestazione1();
        spazio(5);
        printf("Unica Modalita' di Viaggio disponibile e' in : \n");
        stampaAereo();
        resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,2);
        printf("\n\n\nPercorso Veloce - Aereo %s->%s : %d-99$ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
        printf("Passando per le citta : ");
        for (size_t i = 0; i < G->numeroVertici; i++)
        {
            if(strcmp(path[i],"") && i<(G->numeroVertici-1))
            {
                printf("%s->",path[i]);
            }
			else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
				printf("%s",path[i]);

			}

            strcpy(path[i],"");
        }
        resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,1);
        printf("\nPercorso Economico - Aereo %s->%s : %d$ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
        printf("Passando per le citta : ");
        for (size_t i = 0; i < G->numeroVertici; i++)
        {
            if(strcmp(path[i],"") && i<(G->numeroVertici-1))
            {
                printf("%s->",path[i]);
            }
			else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
				printf("%s",path[i]);

			}

            strcpy(path[i],"");
        }
        printf("\n\nInserire 1 Per il Viaggio Veloce - 2 Per il Viaggio Economico - : ");
        scanf("%d",&scelta);
        if (scelta==2)
        {
            if (utenteMain->saldoCorrente-resultTemp<0)
            {
                printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                printf("Prova a ricaricare per poter acquistare!!!!\n");
            }
            else
            {
                utenteMain->saldoCorrente-=resultTemp;
                aggiornaFileUtenteSaldo(utenteMain);
                printf("Acquisto Avvenuto Con Successo!!!!\n");
                printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                scanf("%d",&sceltaHotel);

                sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : sceltaHotel;
            }
        }
        else
        {
            if (utenteMain->saldoCorrente-99<0)
            {
                printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                printf("Prova a ricaricare per poter acquistare!!!!\n");
            }
            else
            {
               utenteMain->saldoCorrente-=99;
                aggiornaFileUtenteSaldo(utenteMain);
                printf("Acquisto Avvenuto Con Successo!!!!\n");
                printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                scanf("%d",&sceltaHotel);

                sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : sceltaHotel;
            }
        }

    }
    else if (checkSum==3)
    {
        //modalità treno
        sceltaModalita=1;

        system("cls");
        intestazione1();
        spazio(5);
        printf("Unica Modalita' di Viaggio disponibile e' in : \n");
        stampaTreno();
        resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,4);
        printf("\n\n\nPercorso Veloce - Treno %s->%s : %d-99$ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
        printf("Passando per le citta : ");
        for (size_t i = 0; i < G->numeroVertici; i++)
        {
            if(strcmp(path[i],"") && i<(G->numeroVertici-1))
            {
                printf("%s->",path[i]);
            }
			else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
				printf("%s",path[i]);

			}
			                        strcpy(path[i],"");

        }
        resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,3);
        printf("\nPercorso Economico - Treno %s->%s : %d $ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
        printf("Passando per le citta : ");
        for (size_t i = 0; i < G->numeroVertici; i++)
        {
            if(strcmp(path[i],"") && i<(G->numeroVertici-1))
            {
                printf("%s->",path[i]);
            }
			else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
				printf("%s",path[i]);

			}
			                        strcpy(path[i],"");

        }
        printf("\n\nInserire 1 Per il Viaggio Veloce - 2 Per il Viaggio Economico - : ");
        scanf("%d",&scelta);
        if (scelta==2)
        {
            if (utenteMain->saldoCorrente-resultTemp<0)
            {
                printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                printf("Prova a ricaricare per poter acquistare!!!!\n");
            }
            else
            {
                utenteMain->saldoCorrente-=resultTemp;
				aggiornaFileUtenteSaldo(utenteMain);
                printf("Acquisto Avvenuto Con Successo!!!!\n");

                printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                scanf("%d",&sceltaHotel);

                sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : sceltaHotel;
            }
        }
        else
        {
            if (utenteMain->saldoCorrente-99<0)
            {
                printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                printf("Prova a ricaricare per poter acquistare!!!!\n");
            }
            else
            {
                utenteMain->saldoCorrente-=99;
				aggiornaFileUtenteSaldo(utenteMain);
                printf("Acquisto Avvenuto Con Successo!!!!\n");
                printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                scanf("%d",&sceltaHotel);

                sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : scegliHotel;
            }
        }
    }
    else
    {


        system("cls");
        intestazione1();
        spazio(5);
		greaficaAcquistaViaggiDispo();
        printf("Premere un tasto corretto per Continuare  : \n");
        stampaEntrambiTrenoAereo();
        char controllo_Viaggio='O';//Valore per il controllo di quale sottofunzione eseguire 
        int modalita_uscita=0;
        do
        {
            if (kbhit())
            {
                controllo_Viaggio=getch();
                //Modalità Aereo
                if (controllo_Viaggio=='A'||controllo_Viaggio=='a')
                {
                    sceltaModalita=2;
                    modalita_uscita=1;                
                    system("cls");
                    intestazione1();
                    printf("Hai Scelto La modalita Aereo : \n");
                    stampaAereo();
                    resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,2);
                    printf("\nPercorso Veloce - Aereo %s->%s : %d-99$ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
                    printf("Passando per le citta : ");
                    for (size_t i = 0; i < G->numeroVertici; i++)
                    {
                        if(strcmp(path[i],"") && i<(G->numeroVertici-1))
						{
							printf("%s->",path[i]);
						}
						else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
							printf("%s",path[i]);

						}
						                        strcpy(path[i],"");

                    }
                     resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,1);
                    printf("\n\n\nPercorso Economico - Aereo %s->%s : %d$ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
                    printf("Passando per le citta : ");
                    for (size_t i = 0; i < G->numeroVertici; i++)
                    {
                        if(strcmp(path[i],"") && i<(G->numeroVertici-1))
						{
							printf("%s->",path[i]);
						}
						else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
							printf("%s",path[i]);

						}
						                        strcpy(path[i],"");

                    }
                    printf("\n\nInserire 1 Per il Viaggio Veloce - 2 Per il Viaggio Economico - : ");
                    scanf("%d",&scelta);
                    if (scelta==2)
                    {
                        if (utenteMain->saldoCorrente-resultTemp<0)
                        {
                            printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                            printf("Prova a ricaricare per poter acquistare!!!!\n");
                        }
                        else
                        {
                            utenteMain->saldoCorrente-=resultTemp;
							aggiornaFileUtenteSaldo(utenteMain);
                            printf("Acquisto Avvenuto Con Successo!!!!\n");
                            printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                            scanf("%d",&sceltaHotel);

                            sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : sceltaHotel;
                        }
                    }
                    else
                    {
                        if (utenteMain->saldoCorrente-99<0)
                        {
                            printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                            printf("Prova a ricaricare per poter acquistare!!!!\n");
                        }
                        else
                        {
                            utenteMain->saldoCorrente-=99;
							aggiornaFileUtenteSaldo(utenteMain);
                            printf("Acquisto Avvenuto Con Successo!!!!\n");
                            printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                            scanf("%d",&sceltaHotel);

                            sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : sceltaHotel;
                        }
                    }
                }
                //Modalità Treno
                else if (controllo_Viaggio=='T'||controllo_Viaggio=='t')
                {
                    sceltaModalita=1;
                    modalita_uscita=1;
                    system("cls");
                    intestazione1();
                    printf("Hai Scelto La modalita Treno : \n");
                    stampaTreno();
                    resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,4);
                    printf("\nPercorso Veloce - Treno %s->%s : %d-99$ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
                    printf("Passando per le citta : ");
                    for (size_t i = 0; i < G->numeroVertici; i++)
                    {
                        if(strcmp(path[i],"") && i<(G->numeroVertici-1))
						{
							printf("%s->",path[i]);
						}
						else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
							printf("%s",path[i]);

						}
						                        strcpy(path[i],"");
                    }
                    resultTemp=dijsktra(G,cittaStart,cittaTarget,listacitta,path,3);
                    printf("\n\n\nPercorso Economico - Treno %s->%s : %d $ \n", listacitta[cittaStart], listacitta[cittaTarget],resultTemp);
                    printf("Passando per le citta : ");
                    for (size_t i = 0; i < G->numeroVertici; i++)
                    {
                        if(strcmp(path[i],"") && i<(G->numeroVertici-1))
						{
							printf("%s->",path[i]);
						}
						else if(strcmp(path[i],"") && i==(G->numeroVertici-1)){
							printf("%s",path[i]);

						}
						strcpy(path[i],"");
                    }
                    printf("\n\nInserire 1 Per il Viaggio Veloce - 2 Per il Viaggio Economico - : ");
                    scanf("%d",&scelta);
                    if (scelta==2)
                    {
                        if (utenteMain->saldoCorrente-resultTemp<0)
                        {
                            printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                            printf("Prova a ricaricare per poter acquistare!!!!\n");
                        }
                        else
                        {
                            utenteMain->saldoCorrente-=resultTemp;
							aggiornaFileUtenteSaldo(utenteMain);
                            printf("Acquisto Avvenuto Con Successo!!!!\n");
                            printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                            scanf("%d",&sceltaHotel);

                            sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : sceltaHotel;
                        }
                    }
                    else
                    {
                        if (utenteMain->saldoCorrente-99<0)
                        {
                            printf("Mi dispiace ma il tuo Saldo Corrente non permette di Acquistare il viaggio\n");
                            printf("Prova a ricaricare per poter acquistare!!!!\n");
                        }
                        else
                        {
                            utenteMain->saldoCorrente-=99;
							aggiornaFileUtenteSaldo(utenteMain);
                            printf("Acquisto Avvenuto Con Successo!!!!\n");
                            printf("\nE' possibile scegliere anche l'Hotel, procedere? (0:no, 1:si):  ");
                            scanf("%d",&sceltaHotel);

                            sceltaHotel ? scegliHotel(cittaTarget,sceltaModalita) : sceltaHotel;
                        }
                    }
                }
            }
        }while (modalita_uscita==0);
    } 
    Sleep(5000);
}
/**
 * @brief Funzione per il carimento in memoria del utente corrispondente 
 * 
 * @param utenteMain Utente Da Inserire 
 * @return int Ritorno Positivo o Negativo
 */
int recuperaUser(struct Utente *utenteMain)
{
    FILE *fp = fopen("UTENTI.txt","r"); 

    Stringa email,passowrd;//Stringhe di Appoggio per controllare email e passoword
    int accesso_ok=0;//Valore imposta a false per controllare se utente è presente negli utenti gia registrati
    system("cls");
    intestazioneEmail();
    spazio(5);
    printf("                                                      Email : \n\n");
    printf("                                          ");
    colorTesto(13);
    printf(">: ");
    colorTesto(15);
    scanf("%s",email);
    spazio(2);
    printf("                                                    Passoword : \n\n");
    printf("                                          ");
    colorTesto(13);
    printf(">: ");
    colorTesto(15);
    scanf("%s",passowrd);
    
    fflush(stdin);
    while (fscanf(fp,"%s %s %s %s %f %d",utenteMain->nome,utenteMain->cognome,utenteMain->email,utenteMain->passoword,&utenteMain->saldoCorrente,&utenteMain->privelegio)==6)
    {
        if(strcmp(utenteMain->email,email)==0 && strcmp(utenteMain->passoword,passowrd)==0)
        {
            if (utenteMain->privelegio==0)
            {
                //Utente Standard
                accesso_ok=1;
            }
            else
            {
                //Utente Admin
                accesso_ok=2;
            }
            break;
        }
    }
    fclose(fp);
    return accesso_ok;//Ritorno un valore positivo se l'utente è stato trovato

}


/**
 * @brief Funzione che permette la registrazione di un nuovo Utente 
 * 
 */
void registrazione()
{
    FILE *fp = fopen("UTENTI.txt","a");
    Stringa email,passoword,nome,cognome;//Stringhe di Appoggio per controllare email e passoword
    float appoggio;
    system("cls");
    intestazione1();
    spazio(2);
    printf("                                                       Nome : \n");
    printf("                                           ");
    colorTesto(13);
    printf(">: ");
    colorTesto(15);
    scanf("%s",nome);
    printf("                                                    Cognome : \n");
    printf("                                           ");
    colorTesto(13);
    printf(">: ");
    colorTesto(15);
    scanf("%s",cognome);
    printf("                                                      Email : \n");
     printf("                                           ");
    colorTesto(13);
    printf(">: ");
    colorTesto(15);
    scanf("%s",email);
    printf("                                                   Passowrd : \n");
    printf("                                           ");
    colorTesto(13);
    printf(">: ");
    colorTesto(15);
    scanf("%s",passoword);
    fflush(stdin);
    printf("                                               Saldo Iniziale : \n");
    printf("                                           ");
    colorTesto(13);
    printf(">: ");
    colorTesto(15);
    scanf("%f",&appoggio);
    fflush(stdin);
    fprintf(fp,"\n%s %s %s %s %f %d",nome,cognome,email,passoword,appoggio,0);
    fclose(fp);
    
}



/**
 * @brief Funzione principale per la ricarica del saldo del Utente
 * 
 * @param utenteMain Utente In Ingresso
 */
void ricaricaSaldo(struct Utente *utenteMain)
{
    system("cls");
    float appoggio;
    intestazione1();
    spazio(5);
    printf("                                                    Saldo Attuale :\n");
    printf("                                                        %5.2f\n\n\n",utenteMain->saldoCorrente);
    printf("                                                 Quanto vuoi ricaricare ?\n");
    printf("                                                       :");
    scanf("%f",&appoggio);
    utenteMain->saldoCorrente+=appoggio;//Aggiorna il saldo attuale del utente
    aggiornaFileUtenteSaldo(utenteMain);
}
/**
 * @brief Funzione per azzeramento del saldo
 * 
 * @param utenteMain Utente In Ingresso
 */
void svuotaSaldo(struct Utente *utenteMain)
{
    system("cls");
    intestazione1();
    spazio(5);
    //Righe di codice puramente grafiche giusto per rendere il tutto un po piu user friendly
    printf("                                                    Azzeramento in corso...\n");
    printf("                                 0");
	for(int i=0;i<55;i++)
	{
		Sleep(30);
	    printf("@");
	}
	printf("100  \n");
    Sleep(100);
    utenteMain->saldoCorrente=0;
    aggiornaFileUtenteSaldo(utenteMain);
}
