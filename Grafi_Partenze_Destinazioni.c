
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafi_Partenze_Destinazioni.h"
#include "StruttureAccessorie.h"




/**
 * @brief Funzione che Crea il Grafo
 *
 * @param n Numero di Vertici
 * @return graph*
 */
graph *creaGrafo(int n)
{
    graph *G;
    int i;
    G = (graph *)malloc(sizeof(graph)); // Alloco Il grafo principale
    if (G == NULL)
    {
        printf("ERRORE: impossibile allocare memoria per il grafo\n");
    }
    else
    {
        G->array = (edge **)malloc(n * sizeof(edge *)); // Alloco il numero di vertici
        if (G->array == NULL)
        {
            printf("ERRORE: impossibile allocare memoria per la lista del grafo\n");
            free(G);
            G = NULL;
        }
        else
        {
            G->numeroVertici = n;
            for (i = 0; i < n; i++)
            {
                G->array[i] = NULL;
            }
        }
    }
    return (G);
}
/**
 * @brief Funzione per il Grafo Vuoto
 *
 * @param G
 * @return int
 */
int isEmpty(graph *G)
{
    return (G == NULL);
}


/**
  * @brief 
 * 
 * @param G Grafo 
 * @param u Numero Di Vertice
 * @param v Numero Di Vertice Da Collegare
 * @param pesoTreEco Peso Economico Treno
 * @param pesoAerEco Peso Economico Aereo
 * @param pesoTreVel Peso Velocita  Treno
 * @param pesoAerVel Peso Velocita Aereo
 */
void aggiungiArcoPS(graph *G, int u, int v,int pesoTreEco,int pesoAerEco,int pesoTreVel,int pesoAerVel)
{
  	edge *new, *e;  
	new = (edge*)malloc(sizeof(edge));
    if (u>=G->numeroVertici)
    {
        printf("ERRORE: Numero Di vertice inserito Errato \n");
    }
  	else if (new==NULL)
    {
        printf("ERRORE: impossibile allocare memoria \n");
    } 
  	else
    {
        new->key=v; 
        new->pesoTrenoEconomico=pesoTreEco;
        new->pesoTrenoVelocita=pesoTreVel;
        new->pesoAreoEconomico=pesoAerEco;
        new->pesoAreoVelocita=pesoAerVel;
        new->next=NULL;
        if (G->array[u] == NULL) //il nodo u non ha archi //
        {
            G->array[u] = new;
        }
        else
        {
            e=G->array[u];
            while (e->next!=NULL)
            {
                 e=e->next;
            }
            e->next=new;     
        }
	}
}

/**
 * @brief Funzione che Esegue la Stampa del Grafo Debug
 *
 * @param G Grafo Da Immettere
 */
void stampaGrafoDebugPS(graph *G,Stringa Citta[])
{
     int i, ne = 0;
    edge *e;
    if (!isEmpty(G))
    {
        printf("\nIl grafo ha %d vertici : \n", G->numeroVertici);
        for (i = 0; i < G->numeroVertici; i++)
        {
            printf("nodi adiacenti al nodo %d: %s", i,Citta[i]);
            e = G->array[i];
            while (e != NULL)
            {
                printf("->%s:%2d",Citta[e->key],e->key);
                ne = ne + 1;
                e = e->next;
            }
            printf("\n");
        }
        printf("\nIl grafo ha %d archi \n", ne);
    }
}


/**
 * @brief Funzione che Calcola Il grado uscente di un grafo
 * 
 * @param G Grafo
 * @param vertice Numero Del Vertice 
 * @return int 
 */

int gradoUscente(graph *G,int vertice)
{
    edge *tmp;
    int counter=0;
    tmp = G->array[vertice];
    while(tmp != NULL)
    {
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

/**
 * @brief Funzione che resi
 * 
 * @param G Grafo 
 * @param verticeDaControllare Vertice Del grado Entrante
 * @return int Restituisce Il grado Entrate di un Vertice
 */
int gradoEntrante(graph *G,int verticeDaControllare)
{
    int counter=0;
    edge *tmp;
    if (verticeDaControllare>G->numeroVertici)
    {
        printf("Errore: Il vertice che hai inserito non esiste");
    }
    else
    {
        if (!isEmpty(G))
        {
            for (size_t i = 0; i < G->numeroVertici; i++)
            {
                tmp = G->array[i];
                while (tmp != NULL)
                {
                    if (tmp->key==verticeDaControllare)
                    {
                        counter++;         
                    }
                    tmp = tmp->next;
                }
            }
        }
        else
        {
            printf("Errore: Impossibile Calcolare il Grado Entrante In un Arco Vuoto");
        }
    }
    return counter;
            
}
/**
 * @brief Dfs in Modalità Classica che calcola le Citta Rangiuggibili
 * 
 * @param graph Grafo
 * @param vertice Vertice Sorgente 
 * @param cittaVisitate Array Citta Visitate
 */
void DFSClassic(graph* graph, int vertice,int cittaVisitate[])
 {
    edge *e = graph->array[vertice];
    edge *temp = e;

  cittaVisitate[vertice] = 1;

  while (temp != NULL) 
  {
    int connectedVertex = temp->key;
    if (cittaVisitate[connectedVertex] == 0) 
    {
      DFSClassic(graph, connectedVertex,cittaVisitate);
    }
    temp = temp->next;
  }
}

/**
 * @brief Dfs in Modalità Treno che calcola le Citta Rangiuggibili
 * 
 * @param graph Grafo
 * @param vertice Vertice Sorgente 
 * @param cittaVisitate Array Citta Visitate
 */
void DFSTreno(graph* graph, int vertice,int cittaVisitate[])
 {
    edge *e = graph->array[vertice];
    edge *temp = e;

  cittaVisitate[vertice] = 1;

  while (temp != NULL) 
  {
    int connectedVertex = temp->key;
    if (cittaVisitate[connectedVertex] == 0 && temp->pesoTrenoEconomico!=99) 
    {
      DFSTreno(graph, connectedVertex,cittaVisitate);
    }
    temp = temp->next;
  }
}

/**
 * @brief Dfs in Modalità Aereo che calcola le Citta Rangiuggibili
 * 
 * @param graph Grafo
 * @param vertice Vertice Sorgente 
 * @param cittaVisitate Array Citta Visitate
 */
void DFSAereo(graph* graph, int vertice,int cittaVisitate[])
 {
    edge *e = graph->array[vertice];
    edge *temp = e;

  cittaVisitate[vertice] = 1;

  while (temp != NULL) 
  {
    int connectedVertex = temp->key;
    if (cittaVisitate[connectedVertex] == 0 && temp->pesoAreoEconomico!=99) 
    {
      DFSAereo(graph, connectedVertex,cittaVisitate);
    }
    temp = temp->next;
  }
}


int** convertListaToMatrice(graph *G,int **matrice,int modalita)
{
    //Allocazione Grafo ->Matrix Dinamico
    matrice =(int **) malloc((G->numeroVertici)*sizeof(int *));
    for (size_t i = 0; i < G->numeroVertici; i++)
    {
        matrice[i]=(int *)malloc((G->numeroVertici)*sizeof(int));
    }
    //Inzializzo Tutti gli elementi a 99 per Ottimazarli per algoritmo di Dijkstra
    for (size_t i = 0; i < G->numeroVertici; i++)
    {
        for (size_t j = 0; j < G->numeroVertici; j++)
        {
            matrice[i][j]=99;
        }
        
    }
    if(matrice == NULL)
    {
        printf("sono qui \n");
    }

    //Cerco Ora Nel Grafo 
    //TODO aggiungere mod switcher
    for (size_t i = 0; i < G->numeroVertici; i++)
    {
        edge *tmp=G->array[i];
        while (tmp != NULL)
        {
            if (modalita==1)
            {
                matrice[i][tmp->key]=tmp->pesoAreoEconomico;
            }
            else if (modalita==2)
            {
                matrice[i][tmp->key]=tmp->pesoAreoVelocita;
            }
            else if (modalita==3)
            {
                matrice[i][tmp->key]=tmp->pesoTrenoEconomico;
            }
            else
            {
                matrice[i][tmp->key]=tmp->pesoTrenoVelocita;
            }
                 
            tmp = tmp->next;
        }
     
    }
    return matrice;
}


int dijsktra(graph *G,int source,int target,Stringa Citta[],Stringa path[],int mod)
{
    //Starting Vari Array e Matrici
    int i,m,min,start,d,j;
    int **matriceDijsktra;
    matriceDijsktra=convertListaToMatrice(G,matriceDijsktra,mod);
    int *dist=(int *)malloc((G->numeroVertici)*sizeof(int));
    int *prev=(int *)malloc((G->numeroVertici)*sizeof(int));
    int *selected=(int *)malloc((G->numeroVertici)*sizeof(int));
    for (size_t i = 0; i < G->numeroVertici; i++)
    {
        selected[i]=0;
    }  
   
    
    for(int i=0;i< G->numeroVertici;i++)
    {
        dist[i] = 99;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = 99;
        m = 0;
        for(int i=0;i< G->numeroVertici;i++)
        {
            d = dist[start] + matriceDijsktra[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    //Stampa Del Path
    while(start != -1)
    {
        strcpy(path[j++], Citta[start]);
        start = prev[start];
    }
    //Reverse del Path nella Posizione Giusta
    for (int i = 0; i < G->numeroVertici/2; i++)
    {
        Stringa temp ;
        strcpy(temp,path[i]);
        strcpy(path[i] , path[(int)(G->numeroVertici )- 1 - i]);
        strcpy(path[(int)(G->numeroVertici )- 1 - i] ,temp);
    }
    //Libero Memoria
    free(prev);
    free(selected);
    int result=dist[target];
    free(dist);
    return result;
}

void creaMappa(graph *G)
{
    //Primo Abbozzo Di Mappa
    //Nodi 0    
    aggiungiArcoPS(G,0,1,2,2,5,6);
    aggiungiArcoPS(G,0,2,4,1,4,2);
    aggiungiArcoPS(G,0,3,99,4,99,3);
    //Nodi 1
    aggiungiArcoPS(G,1,5,2,99,3,99);
    //Nodi 2
    aggiungiArcoPS(G,2,3,99,5,99,7);
    aggiungiArcoPS(G,2,4,99,1,99,2);
    aggiungiArcoPS(G,2,5,3,99,5,99);
    //Nodi 3
    aggiungiArcoPS(G,3,4,2,1,3,2);
    //Nodi 4
    aggiungiArcoPS(G,4,5,99,1,99,2);

}

graph *eliminaElemento(graph *G,int indexToRemove)
{
    //Supponendo che il nodo che Elimino non ha collegamenti quindi non devo aggiornare
    //Anche le liste di Adiancenza in questo caso 
    edge **temp = (edge **)malloc(G->numeroVertici * sizeof(edge *));
     if (indexToRemove != 0)
     {
         memcpy(temp, G->array, indexToRemove * sizeof(edge *)); // copy everything BEFORE the index
     }
        

    if (indexToRemove != (G->numeroVertici- 1))
    {
        memcpy(temp+indexToRemove, G->array+indexToRemove+1, (G->numeroVertici - indexToRemove - 1) * sizeof(edge *)); // copy everything AFTER the index
    }
    free(G->array);
    G->array=temp;
    G->numeroVertici--;   
    return G;
}