#ifndef GestioneAccesso_H   /* Include guard */
#define GestioneAccesso_H

#include "StruttureAccessorie.h"
#include "Grafi_Partenze_Destinazioni.h"
#include "GrafiHotel.h"


//Lista CittaBase

int accessoMain();
int gestioneUtente(struct Utente *utenteMain,graph *mappa,graphHotel *G_Hotel);
int gestioneAdmin(struct Utente *utente,graph *G,Stringa arrayCitta[]);

#endif