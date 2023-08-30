#ifndef StruttureAccessorie_H   /* Include guard */
#define StruttureAccessorie_H


#define MAXLENG 200


typedef char Stringa[MAXLENG];//Ridefinizione di un Array di Caratteri

/**
 * @brief Struttura Dati Utente
 * 
 */
struct Utente 
{
    Stringa nome;//Campo informativo per il Nome
    Stringa cognome;//Campo informativo per il Cognome
    Stringa email;//Campo informativo per l'Email
    Stringa passoword;//Campo informativo per la Password
    float saldoCorrente;//Campo informativo per il Saldo Corrente
    int privelegio;//Campo informativo per indicare se utente ha privileggi da amministratore (1=Aministratore 0=Utente Standard)
};

#endif