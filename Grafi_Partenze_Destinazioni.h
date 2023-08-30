// Libreria Grafi.h
#ifndef Grafi_Partenze_Destinazioni_H   /* Include guard */
#define Grafi_Partenze_Destinazioni_H

#include <stdio.h>
#include <string.h>
#include "StruttureAccessorie.h"
#include <conio.h>
#include <ctype.h>


// Strutture Dati:
/**
 * @brief Arco Del Grafo
 * 
 */
typedef struct edge
{
    int key;                    // Campo Informativo con il dato
    int pesoTrenoEconomico;     // Campo Informativo con il peso Del Treno In Termini Economici
    int pesoAreoEconomico;      // Campo Informativo con il peso Del Aereo In Termini Economici
    int pesoTrenoVelocita;     // Campo Informativo con il peso Del Treno In Termini Velocita
    int pesoAreoVelocita;      // Campo Informativo con il peso Del Aereo In Termini Velocita
    struct edge *next;          // Campo Informativo con il Next Della lista di Archi
} edge;

/**
 * @brief Grafo Vero è proprio
 * 
 */
typedef struct graph
{
    int numeroVertici;     /* numero di vertici del grafo */
    edge **array; /* vettore con le liste delle adiacenze */
} graph;


graph *creaGrafo(int n);
int isEmpty(graph *G);
void aggiungiArcoPS(graph *G, int u, int v,int pesoTreEco,int pesoAerEco,int pesoTreVel,int pesoAerVel);
void stampaGrafoDebugPS(graph *G,Stringa Citta[]);
int gradoUscente(graph *G,int vertice);
int gradoEntrante(graph *G,int verticeDaControllare);
void DFSClassic(graph* graph, int vertice,int cittaVisitate[]);
void DFSTreno(graph* graph, int vertice,int cittaVisitate[]);
void DFSAereo(graph* graph, int vertice,int cittaVisitate[]);
int** convertListaToMatrice(graph *G,int **matrice,int modalita);
int dijsktra(graph *G,int source,int target,Stringa Citta[],Stringa path[],int mod);
void creaMappa(graph *G);
graph *eliminaElemento(graph *G,int indexToRemove);






#endif
