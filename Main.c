//gcc -o main GestioneAccesso.c GestioneFile.c GestioneGrafica.c Grafi_Partenze_Destinazioni.c GrafiHotel.c Main.c GestioneUtente.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestioneGrafica.h"
#include "GestioneUtente.h"
#include "GestioneAccesso.h"
#include "StruttureAccessorie.h"
#include "GestioneFile.h"

Stringa Citta[7]={"Barcellona","New York","Berlino","Tokyo","Reykjavik","Montecarlo","Londra"};

//Code By Antonio Lanuto     Matricola : N86003762
//Code By Erasmo  Prosciutto Matricola : N86003546
//Code By Biagio  Scotto     Matricola : N86003605
//EVO 1.1 Erambi Viaggi : 


//----------------------------------------------------------------------------------------------------//

//Main principale : 

int main()
{
    
    //Funzioni Video Preliminari
    setupVideo();
    graphHotel *grafoAlbergo=creaGrafoHotel(7);
    creaMappaHotel(grafoAlbergo);
    graph *grafoMappa=creaGrafo(7);
    creaMappa(grafoMappa);
    //Inizializzazione Strutture Dati
    struct Utente UtenteGestito;
    
    int Ingresso,reset=0,Accesso_Autorizzato;
    do
    {
        system("cls");
        introVideo();
        Ingresso=accessoMain();//Torna un valore su quale schermata tornare
        if (Ingresso==1)
        {
            //Entra nella fase di Accesso regolare che gestisce Accesso nel caso tu sia Utente o Admin 
             Accesso_Autorizzato=recuperaUser(&UtenteGestito);
             if (Accesso_Autorizzato==1)
             {
                //User mode 
                //Se Accesso è andato a buon fine entro nell account di gestione dell user 
                reset=gestioneUtente(&UtenteGestito,grafoMappa,grafoAlbergo);       
             }
             else if (Accesso_Autorizzato==2)
             {
                 //Modalita Admin Mode
                 reset=gestioneAdmin(&UtenteGestito,grafoMappa,Citta);
             }
             else
             {
                 //Procedura in caso di accesso sbagliato
                 //Quindi Nessun Utente trovato 
                colorTesto(13);
                spazio(2);
                printf("                                            Utente Inserito Non Corretto\n");
                colorTesto(15);
                Sleep(500);
             }
             Accesso_Autorizzato=0;//Resetto la Variabile
        }
        else if (Ingresso==2)
        {
            //Permette la registrazione del Utente (per semplicita si suppone che si possano registrare solo Utenti Normali)
            //per poi tornare alla schermata Principale
            registrazione();
            reset=0;
        }
        else
        {
            //Ho digitato dal menu pricipale uscita quindi viene chiuso il programma 
            reset=1;
        }
    } while(reset==0);
    
    return 0;
}



