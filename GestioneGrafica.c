

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "GestioneGrafica.h"
#include "StruttureAccessorie.h"

//Code By Antonio Lanuto Matricola :N86003762
//Funzioni Grafiche 


//----------------------------------------------------------------------------------------------------//
//Funzioni Interfaccia Grafica : 

void colorTesto(int x)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,3<<4|x);
	/*
	0 = Nero
	1 = Blu scuro
	2 = Verde
	3 = Verde acqua
	4 = Bordeaux
	5 = Viola
	6 = Verde oliva
	7 = Grigio chiaro
	8 = Grigio
	9 = Blu
	10 = Verde limone (A)
	11 = Azzurro (B)
	12 = Rosso (C)
	13 = Fucsia (D)
	14 = Giallo (E)
	15 = Bianco (F)
	*/
}

void colorSfondo(int x)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,(x<<4)|15);
	/*
	0 = Nero
	1 = Blu scuro
	2 = Verde
	3 = Verde acqua
	4 = Bordeaux
	5 = Viola
	6 = Verde oliva
	7 = Grigio chiaro
	8 = Grigio
	9 = Blu
	10 = Verde limone (A)
	11 = Azzurro (B)
	12 = Rosso (C)
	13 = Fucsia (D)
	14 = Giallo (E)
	15 = Bianco (F)
	*/
}
void spazio(int n)//Funzione che crea spazio nel Prompt
{
	for(int i=0;i<n;i++)
	{
		printf("\n");
	}
}
void intro()//Funzione che genera la scritta principale
{
	spazio(9);

	
	
	printf("                    _____                                 _          _   _  _                       _ \n");
	printf("                   |  ___|                               (_)        | | | |(_)                     (_)\n");
	printf("                   | |__   _ __   __ _  _ __ ___   _ __   _  ______ | | | | _   __ _   __ _   __ _  _ \n");
	printf("                   |  __| | '__| / _` || '_ ` _ \\ | '_ \\ | ||______|| | | || | / _` | / _` | / _` || |\n");
	printf("                   | |___ | |   | (_| || | | | | || |_) || |        \\ \\_/ /| || (_| || (_| || (_| || |\n");
	printf("                   \\____/ |_|    \\__,_||_| |_| |_|| .__/ |_|         \\___/ |_| \\__,_| \\__, | \\__, ||_|\n");
	printf("                                                  | |                                  __/ |  __/ |   \n");
	printf("                                                  |_|                                 |___/  |___/    \n");
	printf("\n");
	printf("\n");
	
	spazio(2);
	printf("                                   ษอออออออออออออออป               ษอออออออออออออออป                   \n");
	printf("                                   บ");  
	colorTesto(0);
	printf("  A - ACCEDI   ");
	colorTesto(15);
	printf("บ               บ");
	colorTesto(0);
	printf(" R -REGISTRATI ");
	colorTesto(15);
	printf("บ                   \n");
	printf("                                   ศอออออออออออออออผ               ศอออออออออออออออผ                   \n\n");
	printf("                                                   ษอออออออออออออออป                                    \n");
	printf("                                                   บ");
	colorTesto(0);
	printf("   C - CHIUDI  ");
	colorTesto(15);		
	printf("บ                                    \n");
	printf("                                                   ศอออออออออออออออผ                                    \n");
}
void intestazione1()//Funzione video 
{
	colorTesto(15);
    system("cls");//Funzione per Pulire lo schermo 
    printf("                                            ษออออออออออออออออออออออออออป                                             \n");
	printf("                                            บ          MENU :          บ                                             \n");
	printf("                                            บ   Inserisci Un Comando   บ                                             \n");
	printf("                                            ศออออออออออออออออออออออออออผ                                             \n");
}

void intestazioneEmail()//Funzione video 
{
	colorTesto(15);
    system("cls");//Funzione per Pulire lo schermo 
    printf("                                            ษออออออออออออออออออออออออออป                                             \n");
	printf("                                            บ         Accesso :        บ                                             \n");
	printf("                                            บ  Inserire Email-Password บ                                             \n");
	printf("                                            ศออออออออออออออออออออออออออผ                                             \n");
}
void menuAdmin()//Funzione che genera il menu del admin 
{
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("M -MODIFY GRAPH");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("E -ESCI ACCOUNT");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("   C -CHIUDI   ");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	
	
}
void menuUtente()//Funzione che genera il menu  del utente
{
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf(" A - ACQUISTA  ");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf(" R - RICARICA  ");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("S -SVUOTA CONTO");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("E -ESCI ACCOUNT");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("   C -CHIUDI   ");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n");
	
}

void stampaTreno()
{
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ");  
	colorTesto(0);
	printf("  T - TRENO    ");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ \n");
}

void stampaAereo()
{
	printf("                                                  ษอออออออออออออออป\n");
	printf("                                                  บ");  
	colorTesto(0);
	printf("  A - AEREO    ");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ \n");
}
void stampaEntrambiTrenoAereo()
{
	spazio(2);
	printf("                                   ษอออออออออออออออป               ษอออออออออออออออป                   \n");
	printf("                                   บ");  
	colorTesto(0);
	printf("  T - TRENO    ");
	colorTesto(15);
	printf("บ               บ");
	colorTesto(0);
	printf(" A  - AEREO    ");
	colorTesto(15);
	printf("บ                   \n");
	printf("                                   ศอออออออออออออออผ               ศอออออออออออออออผ                   \n\n");
}
void stampaScelteRisolutive()
{
	spazio(2);
	printf("                                   ษอออออออออออออออป               ษอออออออออออออออป                   \n");
	printf("                                   บ");  
	colorTesto(0);
	printf(" E-ELM VERTICE ");
	colorTesto(15);
	printf("บ               บ");
	colorTesto(0);
	printf(" A- AGG ARCO   ");
	colorTesto(15);
	printf("บ                   \n");
	printf("                                   ศอออออออออออออออผ               ศอออออออออออออออผ                   \n\n");
}
void setupVideo()//Semplice funzione Per la definizione di Alcune proprieta grafiche del prompt
{
    system("color 3f");//Colore dello schermo
    system("mode con lines=130");//Larghezza dello schermo 
    system("mode con lines=30");//Lunghezza dello schermo
}
void introVideo()//Funzione Grafica per il carimento della intro video
{
    system("cls");
    intro();
}
void stampaUtente(struct Utente *utenteMain)//Funzione che stampa il corrente di un Utente
{
	colorTesto(0);
    printf("Utente: ");
	colorTesto(15);
	printf("%s %s\n",utenteMain->nome,utenteMain->cognome);
	colorTesto(0);
    printf("Saldo : ");
	colorTesto(15);
	printf("%5.2f\n",utenteMain->saldoCorrente);
}
 
void greaficaAcquistaCitta()//Funzione che genera il menu del admin 
{
	colorTesto(15);
	printf("\n                                                  ษอออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("     CITTA'    ");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศอออออออออออออออผ                                                  \n\n");
}

 void greaficaAcquistaMete()//Funzione che genera il menu del admin 
{
	colorTesto(15);
	printf("\n                                                  ษออออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("METE DISPONIBILI");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศออออออออออออออออผ                                                  \n\n");
}

 void greaficaAcquistaViaggiDispo()//Funzione che genera il menu del admin 
{
	colorTesto(13);
	printf("\n                                     ษอออออออออออออออออออออออออออออออออออออออออป\n");
	printf("                                     บ"); 
	colorTesto(0);
	printf("     MODALITA' DI VIAGGIO DISPONIBILI    ");
	colorTesto(13);
	printf("บ\n");
	printf("                                     ศอออออออออออออออออออออออออออออออออออออออออผ                                                  \n\n");
	colorTesto(15);
}

 void greaficaAcquistaHotel()//Funzione che genera il menu del admin 
{
	colorTesto(15);
	printf("\n                                                  ษออออออออออออออออออป\n");
	printf("                                                  บ"); 
	colorTesto(0);
	printf("HOTEL DISPONIBILI");
	colorTesto(15);
	printf("บ\n");
	printf("                                                  ศออออออออออออออออออผ                                                  \n\n");
}