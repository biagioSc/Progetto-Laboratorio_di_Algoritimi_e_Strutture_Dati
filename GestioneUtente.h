#ifndef GestioneUtente_H   /* Include guard */
#define GestioneUtente_H

#include "StruttureAccessorie.h"
#include "GrafiHotel.h"
#include "Grafi_Partenze_Destinazioni.h"


void acquista(struct Utente *utenteMain,graph *G,graphHotel *G_Hotel,Stringa listacitta[]);
int recuperaUser(struct Utente *utenteMain);
void registrazione();
void aggiornaFileUtenteSaldo(struct Utente *utenteMain);
void ricaricaSaldo(struct Utente *utenteMain);
void svuotaSaldo(struct Utente *utenteMain);
void modifica(graph *G,Stringa arrayCitta[]);

#endif
