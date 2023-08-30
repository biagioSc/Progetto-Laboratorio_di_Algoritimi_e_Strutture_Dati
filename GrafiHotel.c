// Libreria prototipiGrafi.h

#include "GrafiHotel.h"
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "GestioneGrafica.h"
#include "GestioneUtente.h"

Stringa MatriceHotel[7][7]=
{
    {"Barcellona","Rambla","Hotel Sagrada Familia","Stadio","Hotel Peninsular","Barceloneta","Hotel Hilton"},
    {"New York","Street Avenue","The Empire Hotel","ESB Street","York Hotel","Underground","New Era Hotel"},
    {"Berlino","Muro","Hotel Nandes","Mercatini","Hotel Diprijok","Piazza Maggiore","Hotel LichAmber"},
    {"Tokyo","China Town","Hotel Miris","MicroChip","Hotel Selenius","Fukushima","Hotel Miriabil"},
    {"Reykjavik","Via Roma","Hotel Imperatore Suites and Spa","Stadio","Hotel Hiffington","Colosseo","Hotel Colosseo"},
    {"Montecarlo","Street Diprist","The Colon Hotel","Money Street","Carlo Hotel","TerraCarlo Street","Main Hotel"},
    {"Londra","Piazza Regina","High BiaHotel","Piazza Pin","High AntuanneHotel","Drive on the Left Street","The Bridge Hotel"},
};

graphHotel *creaGrafoHotel(int n)
{
    graphHotel *G;
    int i;
    G = (graphHotel *)malloc(sizeof(graphHotel)); // Alloco Il grafo principale
    if (G == NULL)
    {
        printf("ERRORE: impossibile allocare memoria per il grafo\n");
    }
    else
    {
        G->array = (edgeHotel **)malloc(n * sizeof(edgeHotel *)); // Alloco il numero di vertici
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
int isEmptyHotel(graphHotel *G)
{
    return (G == NULL);
}
void aggiungiArcoPSHotel(graphHotel *G, int u, int v,int distanzaTreno, int distanzaAereo)
{
    edgeHotel *tempNuovo, *e;  
    tempNuovo = (edgeHotel*)malloc(sizeof(edgeHotel));
    if (u>=G->numeroVertici)
    {
        printf("ERRORE: Numero Di vertice inserito Errato \n");
    }
    else if (tempNuovo==NULL)
    {
        printf("ERRORE: impossibile allocare memoria \n");
    } 
    else
    {
        tempNuovo->key=v; 
        tempNuovo->distanzaTreno=distanzaTreno;
        tempNuovo->distanzaAereo=distanzaAereo;
        tempNuovo->next=NULL;
        if (G->array[u] == NULL) //il nodo u non ha archi //
        {
            G->array[u] = tempNuovo;
        }
        else
        {
            e=G->array[u];
            while (e->next!=NULL)
            {
                 e=e->next;
            }
            e->next=tempNuovo;     
        }
    }
}
void creaMappaHotel(graphHotel *G)
{
    //Nodi 0    
    aggiungiArcoPSHotel(G,0,1,10,10); //PASSAGGIO: 0-1
    aggiungiArcoPSHotel(G,0,6,7,5); //PASSAGGIO: 0-6
    aggiungiArcoPSHotel(G,0,5,5,9); //PASSAGGIO: 0-5
    aggiungiArcoPSHotel(G,0,2,4,9); //PASSAGGIO: 0-2
    //Nodo 1
    aggiungiArcoPSHotel(G,1,0,10,10); //PASSAGGIO 1-0
    aggiungiArcoPSHotel(G,1,6,15,2); //PASSAGGIO 1-6
    //Nodi 2
    aggiungiArcoPSHotel(G,2,0,4,9); //PASSAGGIO 2-0
    //Nodo 5
    aggiungiArcoPSHotel(G,5,0,5,9); //PASSAGGIO 5-0
    aggiungiArcoPSHotel(G,5,3,10,7); //PASSAGGIO 5-3
    //Nodo 3
    aggiungiArcoPSHotel(G,3,5,10,7); //PASSAGGIO 3-5
    aggiungiArcoPSHotel(G,3,6,2,10); //PASSAGGIO 3-6
    //Nodo 6
    aggiungiArcoPSHotel(G,6,3,2,10); //PASSAGGIO 6-3
    aggiungiArcoPSHotel(G,6,1,15,2); //PASSAGGIO 6-1
    aggiungiArcoPSHotel(G,6,0,7,5); //PASSAGGIO 6-0
    aggiungiArcoPSHotel(G,6,4,5,1); //PASSAGGIO 6-4
    //Nodo 4
    aggiungiArcoPSHotel(G,4,6,5,1); //PASSAGGIO 4-6
}
void stampaGrafoHotel(graphHotel *G, Stringa *Citta)
{
     int i, ne = 0;
    edgeHotel *e;
    if (!isEmptyHotel(G))
    {
		colorTesto(15);
        printf("\nLa citta'");
		colorTesto(0);
		printf(" %s", Citta[0]);
		colorTesto(15);
		printf(" ha  ");
		colorTesto(0);
		printf("%d",(G->numeroVertici-1)/2);
		colorTesto(15);
		printf(" Hotel : \n");

        for (i = 1; i < G->numeroVertici; i++)
        {
            //prendiamo i pari
            if(i%2==0)
            {
				colorTesto(0);
				printf(" %d: ", i);
				colorTesto(15);
				printf(" %s",Citta[i]);

            }
            printf("\n");
        }
    }
    else
        printf("Errore: grafo vuoto!");
}
int** convertListaToMatriceHotel(graphHotel *G,int **matrice,int modalita)
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
        edgeHotel *tmp=G->array[i];
        while (tmp != NULL)
        {
            if (modalita==1)
            {
                matrice[i][tmp->key]=tmp->distanzaTreno;
            }
            else if (modalita==2)
            {
                matrice[i][tmp->key]=tmp->distanzaAereo;
            }
            tmp = tmp->next;
        }
    }
    return matrice;
}
int dijsktraHotel(graphHotel *G,int source,int target,Stringa Citta[],Stringa path[],int mod)
{
    //Starting Vari Array e Matrici
    int i,m,min,start,d,j;
    int **matriceDijsktra;
    matriceDijsktra=convertListaToMatriceHotel(G,matriceDijsktra,mod);
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

void scegliHotel(int partenza, int sceltaModalita)
{
    system("cls");

    Stringa StringaCitta[7];
    graphHotel *GrafoCitta=NULL;
    Stringa path[7]={""};
    int numeroHotel;
    int result;
    for(int i=0; i<7; i++)
    {
       strcpy(StringaCitta[i],MatriceHotel[partenza][i]);
    }
    GrafoCitta=creaGrafoHotel(7);
    creaMappaHotel(GrafoCitta);
	void greaficaAcquistaHotel();//Funzione che genera il menu del admin 
    stampaGrafoHotel(GrafoCitta,StringaCitta);
	colorTesto(15);
    printf("\nInserisci numero Hotel: ");
	colorTesto(0);
    scanf("%d",&numeroHotel);
	while(numeroHotel%2!=0){
		colorTesto(12);
		printf("\n\nNUMERO HOTEL NON VALIDO\n\n");
		colorTesto(15);
		printf("\nInserisci numero Hotel: ");
		colorTesto(0);
		scanf("%d",&numeroHotel);
	}
    result=dijsktraHotel(GrafoCitta,0,numeroHotel,StringaCitta,path,sceltaModalita);
    //treno
    if(sceltaModalita==1)
    {
		colorTesto(15);
        printf("\n\n\nPercorso Veloce da stazione Treni di %s a %s\n", StringaCitta[0], StringaCitta[numeroHotel]);
    }
    //aereo
    else
    {
		colorTesto(15);
        printf("\n\n\nPercorso Veloce da Aeroposto di %s a %s\n ", StringaCitta[0], StringaCitta[numeroHotel]);    
	}
	
	printf("Passando per: ");
	for (size_t i = 0; i < GrafoCitta->numeroVertici; i++)
	{
		if(strcmp(path[i],"") && i<(GrafoCitta->numeroVertici-1))
		{
			printf("%s-->",path[i]);
		}
		else if(strcmp(path[i],"") && i==(GrafoCitta->numeroVertici-1) ){
							printf("%s\n",path[i]);

		}
		strcpy(path[i],"");
	}
	
	colorTesto(15);
	printf("Km da percorrere: ");
	colorTesto(0);
	printf("%d  \n",result);
    Sleep(2000);
}
