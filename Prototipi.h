// Libreria 
// Alunno: Biagio Scotto di Covella
// Matricola : N86003605

#define numero 100

typedef char Stringa[numero];//creazione di un tipo stringa

//Funzione per impostare  il colore delle scritte stampate sul prompt
void color(int x);

//Funzione per tornare alla home principale di admin o cliente
void tornaMenu();

//Funzione per intercettare eventi da tastiera HomeMain
int eventiMain();
int eventiMainScelta();

//Funzione per intercettare eventi da tastiera Admin
int eventiAdmin(); 

//Funzione per intercettare eventi da tastiera Cliente
int eventiCliente();

/*----------------------------------------------------*/

//Definizione delle strutture dati utilizzate:

//Struttura per gli admin
struct listaAdmin {
	Stringa nome;
	Stringa cognome;
	Stringa username;
	Stringa password;
};
typedef struct listaAdmin admin;

//Struttura per i clienti
struct listaClienti {
	Stringa nome;
	Stringa cognome;
	Stringa username;
	Stringa password;
	float conto;
	struct listaClienti *next;
	struct listaClienti *prev;
};
typedef struct listaClienti cliente;

//Struttura per le taglie
struct listaTaglie {
	char tg[4];//xxs,xs,s,m,l,xl,xxl
	int qta;
	//collegamenti in lista
    struct listaTaglie *next;
	struct listaTaglie *prev;
};
typedef struct listaTaglie taglie;

//Struttura per i prodotti acquistati
//La struttura contiene campi con informazioni relative al prodotto
//acquistato, ma non ha una lista di taglie,ma solo una (quella scelta)
struct listaProdottiAcquistati {
	//Prodotto
	Stringa nome;
	float prezzo;
	char taglia[4];
	int quantita;
	//collegamenti in lista
    struct listaProdottiAcquistati *next;
	struct listaProdottiAcquistati *prev;
};
typedef struct listaProdottiAcquistati carrello;

//Struttura per i prodotti 
//La struttura contiene campi con informazioni relative al prodotto
struct listaProdotti {
	//prodotto
	int identificativo;
	Stringa nome;
	float prezzo;
	//lista di taglie per quel prodotto
	taglie *listaTaglie;
	//collegamenti in lista
    struct listaProdotti *next;
	struct listaProdotti *prev;
};
typedef struct listaProdotti prodotti;

//Struttura per la lista di attesa
//La struttura contiene campi con informazioni relative al cliente,
//e campi con informazioni relative al prodotto
struct listaDiAttesa {
	//cliente
	Stringa nome;
	Stringa cognome;
	Stringa username;
	//prodotto
	Stringa nomeprod;
	char taglia[4];
	int quantita;  
	//collegamenti in lista
	struct listaDiAttesa *next;
	struct listaDiAttesa *prev;
};
typedef struct listaDiAttesa attesa;

		
		
/*-------------------------------------------------*/



//funzioniAdmin.h	

//La funzione creaAdmin crea un nodo di tipo admin
admin *creaAdmin(Stringa nome, Stringa cognome, Stringa username, Stringa password);
//La funzione controllaDatiAdmin controlla che l'username inserito non sia già presente nel sistema
int controllaDatiAdmin(Stringa username);
//La funzione chiediInfoAdmin si interfaccia con l'utente chiedendogli di inserire i dati richiesti
admin *chiediInfoAdmin();
//La funzione scriviFileAdmin registra le informazioni sul databaseAdmin.txt
admin *scriviFileAdmin(FILE *fp);
//Funzione ausiliaria alla registrazione dell'admin (richiama le funzioni sopra discusse)
admin *registraAdmin();
//La funzione trovaAdmin cerca sul databaseAdmin.txt i dati inseriti in fase di accesso,
//in caso positivo permette l'accesso altrimenti no
admin *trovaAdmin(FILE *fp, Stringa username, Stringa password);
//Funzione ausiliaria all'accesso dell'admin al sistema(richiama la funzioni sopra discussa)
admin *accediAdmin(Stringa username, Stringa password);
//Funzione di controllo dell'accesso (richiama le funzioni sopra discusse)
void paginaAccessoAdmin();
//Funzione di controllo della registrazione (richiama le funzioni sopra discusse)
void paginaRegistraAdmin();
//Unità di controllo dell'utente admin; in particolare è la funzione che gestisce le azioni
//che un admin può compiere
void unitControlAdmin(admin *utenteA);



/*-------------------------------------------------*/



//funzioniCliente.h

//La funzione freeListaCL elimina la lista di clienti creata
cliente *freeListaCL(cliente *head);
//La funzione creaCliente crea un utente di tipo Cliente
cliente *creaCliente(Stringa nome, Stringa cognome, Stringa username, Stringa password, float saldo);
//La funzione inserisciListaCliente crea una lista di clienti 
cliente *inserisciListaCliente(cliente *nodo, cliente *head);
//La funzione controllaDatiCliente controlla che l'username inserito non sia già presente nel sistema
int controllaDatiCliente(Stringa username);
//La funzione chiediInfoCliente si interfaccia con l'utente chiedendogli di inserire i dati richiesti
cliente *chiediInfoCliente();
//La funzione scriviFileCliente registra le informazioni sul databaseCliente.txt
cliente *scriviFileCliente(FILE *fp);
//Funzione ausiliaria alla registrazione del cliente (richiama le funzioni sopra discusse)
cliente *registraCliente();
//Funzione di lettura file databaseCliente.txt
cliente *leggiFileCliente(cliente *head);
//La funzione trovaCliente cerca sul databaseCliente.txt i dati inseriti in fase di accesso,
//in caso positivo permette l'accesso altrimenti no
cliente *trovaCliente(FILE *fp, Stringa username, Stringa password);
//Funzione ausiliaria all'accesso del cliente al sistema(richiama la funzioni sopra discussa)
cliente *accediCliente(Stringa username, Stringa password);
//Funzione di controllo dell'accesso (richiama le funzioni sopra discusse)
void paginaAccessoCliente();
//Funzione di controllo della registrazione (richiama le funzioni sopra discusse)
void paginaRegistraCliente();
//Funzione di modifica file databaseCliente.txt
void modificaFileCliente(cliente *account, cliente *lista);
//Le seguenti funzioni svuotano, ricaricano, prelevano, e modifica il conto del cliente
cliente *svuotaConto(cliente *head);
cliente *ricaricaConto(cliente *head);
cliente *preleva(cliente *head);
cliente *modificaConto(cliente *head, float buy);
//La funzione acquistaProdotti permette l'acqusito di prodotti 
carrello *acquistaProdotti(cliente *head,prodotti *listaProd);
//Unità di controllo dell'utente cliente; in particolare è la funzione che gestisce le azioni
//che un cliente può compiere
void unitControlCliente(cliente *UtenteC);



/*-------------------------------------------------*/



//FunzioniListaDiAtttesa.h

//OK Funzione crea file di attesa
void listaAttesa(cliente *account, carrello*cart);
//OK Funzione crea un nodo di attesa
attesa *creaAttesa(Stringa nome,Stringa cognome,Stringa username, Stringa nomeprod,char taglia[4],	int quantita);
//OK Funzione crea una lista di notifiche per un cliente
attesa *inserisciListaNotifiche(Stringa nome,Stringa cognome,Stringa username, Stringa nomeprod,char taglia[4],int quantita, attesa *head);
//OK Funzione leggi file di attesa
attesa *leggiFileAttesa(attesa *head);
//Funzione che elimina un nodo da lista di attesa
attesa *eliminaNodo(attesa *head1,attesa *nodo);
//Funzione che mostra notifica
void mostraNotifica(attesa *mess);
//Funzione modifica file di attesa
void modificaFileAttesa(attesa *head,attesa *corrente);
//Funzione controllo notifiche
attesa *notifiche(cliente *utente);
//Funzione per grafica notifica
void grafica(cliente *cl, attesa *head);



/*-------------------------------------------------*/




//funzioniProdotti.h

//funzioni sulle taglie
taglie *freeListaTG(taglie *head);
void stampaListaTaglie(taglie *head);
taglie *creaTaglie(char size[3], int quant);
taglie *insertCodaTg(taglie *nodo, taglie *head);

//funzioni sui prodotti
prodotti *freeListaPR(prodotti *head);
void stampaListaProdotti(prodotti *head);
prodotti *creaProd(Stringa name, float price, taglie *Taglie, int i);
prodotti *inserisciLista(prodotti *nodo, prodotti *head);
int controllaDatiProdotto(Stringa nome);
prodotti *chiediInfoProdotto(prodotti *head);
prodotti *leggiFileProd(prodotti *head);
prodotti *nuovoProdotto();
int scriviFileProdotto(prodotti *listaProd);
prodotti *modificaProdotti(prodotti *listaProd);

//funzioni sul carrello
carrello *freeListaCR(carrello *head);
void stampaListaCarrello(carrello *head);
carrello *creaProdCarrello( char tg[4],Stringa name, float price, int qta);
carrello *inserisciListaCarrello(carrello *nodo, carrello *head);
carrello *creaCarrello(prodotti *listaProd, cliente *account);
float daPagare(carrello *cart);

/*-------------------------*/