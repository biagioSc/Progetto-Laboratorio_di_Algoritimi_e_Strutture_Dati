

#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "StruttureAccessorie.h"
#include "Grafi_Partenze_Destinazioni.h"
#include "GestioneUtente.h"
#include "GestioneGrafica.h"


/*
#include "GestioneGrafica.h"
#include "GestioneFile.h"
#include "GestioneAccesso.h"
*/
Stringa citta[7]={"Barcellona","New York","Berlino","Tokyo","Reykjavik","Montecarlo","Londra"};


//----------------------------------------------------------------------------------------------------//

//Funzioni per la gestione dell flusso 

int accessoMain()//Funzione principale che gestisci il main del programma 
{
    char controllo_schermata='O';//Valore per il controllo di quale sottofunzione eseguire 
    int modalita_uscita=0;
    do
    {
        if (kbhit())
        {
            controllo_schermata=getch();
            if (controllo_schermata=='A'||controllo_schermata=='a')
            {
                //imposto modalita di Accesso;
                modalita_uscita=1;                
            }
            else if (controllo_schermata=='R'||controllo_schermata=='r')
            {
                //imposto modalita di Registro
                modalita_uscita=2;
            }
            else if(controllo_schermata=='C'||controllo_schermata=='c')
            {
                //imposto modalita in Chiusura 
                modalita_uscita=3;
            }
        }
    }while (modalita_uscita==0);

    return modalita_uscita;
}

int gestioneUtente(struct Utente *utenteMain,graph *mappa,graphHotel *G_Hotel)//Funzione Principale per la gestione del utente 
{
    int resetApplication=0;//Torna positivo se utente ha digitato la chiusura del programma
    int modalita_uscita=1;//Quando impostato a 0 permette uscita dal programma
    char controllo_main='h';//Valore per il controllo di quale sottofunzione eseguire 
    intestazione1();
    spazio(1);
    stampaUtente(utenteMain);
    spazio(1);
    menuUtente();
    do
    {
        if (kbhit())//Se viene intecettato che è stata toccata la tastiera si alza un evento 
        {
            controllo_main=getch();
            if (controllo_main=='R'||controllo_main=='r')
            {
                //Ricarica Saldo
                ricaricaSaldo(utenteMain);
                intestazione1();
                spazio(1);
                stampaUtente(utenteMain);
                spazio(1);
                menuUtente();
                
            }
            else if (controllo_main=='A'||controllo_main=='a')
            {
                //Acquisto Prodotti
                system("cls");
                intestazione1();
                spazio(1);
                acquista(utenteMain,mappa,G_Hotel,citta);
                system("cls");
                intestazione1();
                spazio(1);
                stampaUtente(utenteMain);
                spazio(1);
                menuUtente();
                
                
            }
            else if (controllo_main=='G'||controllo_main=='g')
            {
                //Carrello
                system("cls");
                
                intestazione1();
                spazio(1);
                stampaUtente(utenteMain);
                spazio(1);
                menuUtente();
                
                
            }
            else if (controllo_main=='s'||controllo_main=='S')
            {
                //Svuota Carrello
                svuotaSaldo(utenteMain);
                intestazione1();
                spazio(1);
                stampaUtente(utenteMain);
                spazio(1);
                menuUtente();
               
            }
            else if(controllo_main=='e'||controllo_main=='E')
            {
                //Uscita dal Account
                modalita_uscita=0;
            }
            else if(controllo_main=='c'||controllo_main=='C')
            {
                //Chiusura del programma 
                resetApplication=1;
                modalita_uscita=0;
            }
        }
    } while (modalita_uscita!=0);
    printf("sono uscito");
    return resetApplication;
}
//----------------------------------------------------------------------------------------------------//

//Funzioni per la gestione del Admin : 

int gestioneAdmin(struct Utente *utente,graph *G,Stringa arrayCitta[])//Funzione principale che permettere di gestire il menu del admin
{
    intestazione1();
    spazio(2);
    printf("Sei in Admin Mode : \n");
    stampaUtente(utente);
    spazio(2);
    menuAdmin();
    int resetApplication=0;//Torna positivo se utente ha digitato la chiusura del programma
    int modalita_uscita=1;//Quando impostato a 0 permette uscita dal programma
    char controllo_main='h';//Controllo 
    do
    {
        if (kbhit())//Se viene intecettato che è stata toccata la tastiera si alza un evento 
        {
            controllo_main=getch();
            if (controllo_main=='M'||controllo_main=='m')
            {
                //Entra in modalita aggiornamento Prodotto
              
                intestazione1();
                spazio(2);
                printf("Sei in Admin Mode : \n");
                stampaUtente(utente);
                spazio(2);
                menuAdmin();
                modifica(G,arrayCitta);
                intestazione1();
                spazio(2);
                printf("Sei in Admin Mode : \n");
                stampaUtente(utente);
                spazio(2);
                menuAdmin();
            }
            else if(controllo_main=='e'||controllo_main=='E')
            {
                //Esce dal programma
                modalita_uscita=0;
            }
            else if(controllo_main=='c'||controllo_main=='C')
            {
                //Chiude Applicazione
                resetApplication=1;
                modalita_uscita=0;
            }
        }
    } while (modalita_uscita!=0);
    return resetApplication;//Il valore ritorno indica se il programma va chiuso oppure no 
}
