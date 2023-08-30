#ifndef GestioneGrafica_H   /* Include guard */
#define GestioneGrafica_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "StruttureAccessorie.h"

//Code By Antonio Lanuto Matricola :N86003762
//Funzioni Grafiche 

//----------------------------------------------------------------------------------------------------//
//Funzioni Interfaccia Grafica : 

void colorTesto(int x);
void colorSfondo(int x);
void spazio(int n);//Funzione che crea spazio nel Prompt
void intro();//Funzione che genera la scritta principale
void intestazione1();//Funzione video 
void intestazioneEmail();//Funzione video 
void menuAdmin();//Funzione che genera il menu del admin 
void menuUtente();//Funzione che genera il menu  del utente
void stampaTreno();
void stampaAereo();
void stampaEntrambiTrenoAereo();
void stampaScelteRisolutive();
void setupVideo();//Semplice funzione Per la definizione di Alcune proprieta grafiche del prompt
void introVideo();//Funzione Grafica per il carimento della intro video
void stampaUtente(struct Utente *utenteMain);//Funzione che stampa il corrente di un Utente
void greaficaAcquistaCitta();//Funzione che genera il menu del admin 
 void greaficaAcquistaMete();//Funzione che genera il menu del admin 
 void greaficaAcquistaViaggiDispo();//Funzione che genera il menu del admin 
 void greaficaAcquistaHotel();//Funzione che genera il menu del admin 
#endif