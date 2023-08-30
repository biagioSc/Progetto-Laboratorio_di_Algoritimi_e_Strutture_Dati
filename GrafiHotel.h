// Libreria prototipiGrafi.h

#ifndef GrafiHotel_H   /* Include guard */
#define GrafiHotel_H
#include <stdio.h>
#include <string.h>
#include "StruttureAccessorie.h"
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct edgeHotel
{
    int key;                   
    int distanzaTreno;     
    int distanzaAereo;      
    struct edgeHotel *next;         
} edgeHotel;
/**
 * @brief Grafo Vero è proprio
 * 
 */
typedef struct graphHotel
{
    int numeroVertici;     /* numero di vertici del grafo */
    edgeHotel **array; /* vettore con le liste delle adiacenze */
} graphHotel;
//In posizione pari inseriamo le strade
//In posizione dispari inseriamo l'Hotel
//Non considerando la posizione 0 (Presa come Partenza)
/*

*/
graphHotel *creaGrafoHotel(int n);
int isEmptyHotel(graphHotel *G);
void aggiungiArcoPSHotel(graphHotel *G, int u, int v,int distanzaTreno, int distanzaAereo);
void creaMappaHotel(graphHotel *G);
void stampaGrafoHotel(graphHotel *G, Stringa *Citta);
int** convertListaToMatriceHotel(graphHotel *G,int **matrice,int modalita);
void scegliHotel(int partenza, int sceltaModalita);
int dijsktraHotel(graphHotel *G,int source,int target,Stringa Citta[],Stringa path[],int mod);

#endif
