/** *******************************************************************************************************************
 *  Created by Alessio Sanna on 10/08/2023.
 *  parte 3 A in "as_library2_a.c"
 *  parte 3 C in "as_library2_c.c"
/** *******************************************************************************************************************/
/** TESTED IN MAIN OK **/
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"

/** Inserimento da terminale dei campi RecordStudente studente **/
/** TESTED IN MAIN OK **/
RecordStudente inserisciStudente() {
    RecordStudente studente;

/* inserimento nome (con controllo correttezza condizioni inserimento):
   Il nome e il cognome possono contenere solo spazi e lettere (maiuscole o minuscole).*/
    do {
        acquisisciNome(studente.nome);
        svuotaBuffer();
        // error message
        if(!controllo_nome_cognome(studente.nome))
            printf("\nSpiacente. Il nome deve contenere solo lettere maiuscole o minuscole e spazi vuoti."
                   " Accenti o lettere accentate non sono ammesse. \nReinserire: ");
    } while (!controllo_nome_cognome(studente.nome));

// inserimento cognome (con controllo correttezza condizioni inserimento):
    do {
        acquisisciCognome(studente.cognome);
        svuotaBuffer();
        // error message
        if(!controllo_nome_cognome(studente.cognome))
            printf("\nSpiacente. Il cognome deve contenere solo lettere maiuscole o minuscole e spazi vuoti. "
                   "\nReinserire: ");
    } while (!controllo_nome_cognome(studente.cognome));

/* Inserimento campo codice fiscale con verifica true oppure ripete acquisizione;
** Il codice fiscale deve contenere esattamente 16 caratteri alfanumerici maiuscoli
** nelle corrette posizioni formato CF. */
    do {
        acquisisci_CF(studente.codiceFiscale);
        svuotaBuffer();
        // error message
        if(!controllo_codice_fiscale_Beta(studente.codiceFiscale))
            printf("\nSpiacente. Il codice fiscale deve contenere solo lettere maiuscole e numeri"
                   " nella corretta posizione. Reinserire: ");
    } while (!controllo_codice_fiscale_Beta(studente.codiceFiscale));

/* Inserimento campo titoloStudio: può essere scelto solo tra i valori dell’enumerazione enum {} . */
    do {
        studente.titoloStudio = acquisisce_titoloStudio();
        // error message
            if(!controllo_titolo(studente.titoloStudio))
            printf("\nOpzione non valida / non presente in menu\'. Reinserire:\n");
    } while (!controllo_titolo(studente.titoloStudio));


/* Inserimento campo dataNascita: deve rispettare i vincoli canonici, non è possibile scegliere
** date inesistenti/impossibili. */

    do {
        studente.dataNascita = data_Nascita();
        if(!controllo_dataNascita(studente.dataNascita))
            printf("\nOpzione non valida / non presente in menu\'. Reinserire:\n");
    }while(!controllo_dataNascita(studente.dataNascita));

/* Inserimento campo edizione: non può essere minore o uguale a zero. */
    do {
        studente.edizione = acquisisci_edizione();
        // error message
        if(!controllo_edizione(studente.edizione))
            printf("\nL\'edizione deve essere maggiore di zero. Reinserire:\n");
    } while (!controllo_edizione(studente.edizione));

/* Inserimento campo inCorso: può essere solo o zero o uno */

    do {
       studente.inCorso = acquisisci_inCorso();

        if (studente.inCorso > 1 || studente.inCorso < 0) {
            printf("\nOpzione non valida. Reinserire.\n");
            svuotaBuffer();  // se l'utente inserisce un valore minore di 0 o maggiore di 1, il programma visualizzerà il messaggio di errore e pulirà il buffer (svuotaBuffer()) per evitare che input non valido influisca sulla prossima iterazione del ciclo. In questo modo, l'utente sarà obbligato a reinserire il valore corretto per inCorso.
        }
        } while (!controllo_inCorso(studente.inCorso));

/* Inserimento campo sommaPagata : non può essere negativa. */

    do {
        studente.sommaPagata = acquisisci_sommaPagata();
        // error message
        if(!controllo_sommaPagata(studente.sommaPagata))
            printf("\nOpzione non valida. Reinserire.\n");
    } while (!controllo_sommaPagata(studente.sommaPagata));

    return studente;

}


/**************************************** Funzioni di controllo *****************************************************/
/// funzione di controllo. Il nome e il cognome possono contenere solo spazi e lettere (maiuscole o minuscole).
int controllo_nome_cognome(char stringa[]){
    int i;
    int dim = strlen(stringa);
    for (i = 0; i < dim; i++) {
        if(!isalpha(stringa[i]) && !isspace(stringa[i]))
            return false;
    }
    return true;
}

/// funzione di controllo. Il codice fiscale deve contenere esattamente 16 caratteri alfanumerici maiuscoli.
// VERSIONE BETA: controlla se il CF ha nelle corrette posizioni un numero o una lettera solo maiuscola
int controllo_codice_fiscale_Beta(char stringa[DIM_CF]){
    // CF SAMPLE con posizioni lettere e numeri
    // SNN LSS 90H  0 3  B    3  5  4  X     \n
    // 012 345 678  9 10 11   12 13 14 15    16
    int i;
    int dim = strlen(stringa);
    for (i = 0; i < dim; ++i) {

        // restituisce false se in data posizione c'è un numero al posto di una lettera maiuscola e viceversa
        if(!isupper(stringa[0]) || !isupper(stringa[1]) || !isupper(stringa[2])
           || !isupper(stringa[3]) || !isupper(stringa[4]) || !isupper(stringa[5])
           || !isdigit(stringa[6]) || !isdigit(stringa[7]) || !isupper(stringa[8])
           || !isdigit(stringa[9]) || !isdigit(stringa[10]) || !isupper(stringa[11])
           || !isdigit(stringa[12]) || !isdigit(stringa[13]) || !isdigit(stringa[14]) || !isupper(stringa[15])){
            return 0;
        }
        // Restituisci false se la dimensione non è corretta
        if (dim != 16)
            return 0;
    }
    return 1; // restituisce true se tutti i valori sono in posizione corretta con tipo corretto per il formato CF
}

// controllo originale codice fiscale: controlla se CF ha solo numeri e lettere maiuscole
int controllo_codice_fiscale(char stringa[]){
    int i;
    int dim = strlen(stringa);
    for (i = 0; i < dim; i++) {
        if(!isalpha(stringa[i]) && !isdigit(stringa[i]))
            return false;
    }
    return true;
}

/// funzione di controllo titolo. Il titolo di studio può essere scelto solo tra i valori dell’enumerazione.
int controllo_titolo(Titolo titolo) {
    if (titolo < 0 || titolo > 3) {
        return 0;
    }
    return 1;
}

/// funzione di controllo dataNascita. La data deve essere una data calendariale esistente/possibile.
int controllo_dataNascita(Data data) {
    if (data.giorno < 1 || data.giorno > 31 || data.mese < 1 || data.mese > 12) {
        return 0;
    } else if ((data.mese == 4 || data.mese == 6 || data.mese == 9 || data.mese == 11) && data.giorno > 30) {
        return 0;
    } else if (data.mese == 2 && data.giorno > 28) {
        return 0;
    }
    return 1;
}

/// funzione di controllo: edizione. Non può essere negativa.
int controllo_edizione(int edizione){
    if (edizione <= 0) {
        return 0;
        // printf("\nL\'edizione deve essere maggiore di zero. Reinserire:\n");
    }
    return 1;
}

/// funzione di controllo: inCorso. Non può essere negativo o maggiore 1
int controllo_inCorso(int inCorso){
    if (inCorso < 0 || inCorso > 1) {
        return 0;
    }
    return 1;
}

/// funzione di controllo: non può essere negativa
int controllo_sommaPagata(float sommaPagata){
    if (sommaPagata < 0) {
        return false;
        // printf("\nLa somma non può essere negativa. Reinserire.\n");
    }
    return true;
}

/************************************* Funzioni di inserimento campi **************************************************/
/// Inserisce il campo char nome
void acquisisciNome(char nome[]) {
    printf("Inserisci il nome: ");
    scanf("%[^\n]s", nome);
}

/// Inserisce il campo char cognome
void acquisisciCognome(char cognome[]) {
    printf("Inserisci il cognome: ");
    scanf("%[^\n]s", cognome);
}

/// Inserisce il campo char codice fiscale
void acquisisci_CF(char codiceFiscale[]) {
    printf("\nCodice fiscale: ");
    scanf("%s", codiceFiscale);
}

/// Inserire campo Titolo TitoloStudio: le scelte vanno solo da 0 a 4.
Titolo acquisisce_titoloStudio(){
    Titolo titolo;
    printf("\nTitolo di studio:\n"
           "0=diploma, 1=laurea_triennale, 2=laurea_magistrale, 3=altro: ");
    scanf("%d", &titolo);
    return titolo;
}

/// Inserisce il campo dataNascita: La data deve essere una data calendariale esistente/possibile.
Data data_Nascita(){
    Data data;
    printf("\nData di nascita: gg/mm/aaaa  ");
    printf("\nGiorno: ");
    scanf("%d", &data.giorno);
    printf("\nMese: ");
    scanf("%d", &data.mese);
    printf("\nAnno: ");
    scanf("%d", &data.anno);
    return data;
}

/// Inserisce il campo edizione deve essere maggiore di zero.
int acquisisci_edizione() {
    int edizione;
    printf("\nEdizione: ");
    scanf("%d", &edizione);
    return edizione;
}

/// Inserisce il campo Incorso: deve essere solo o zero o uno
bool acquisisci_inCorso() {
    int inCorsoInt;
    printf("\nIn corso (0 = no, 1 = si): ");
    scanf("%d", &inCorsoInt);

    if (inCorsoInt == 0) {
        return false;
    } else
        return true;
}

/// Inserisce il campo sommaPagata: non può essere negativa
float acquisisci_sommaPagata() {
    float sommaPagata;
    printf("\nSomma pagata: ");
    scanf("%f", &sommaPagata);
    return sommaPagata;
}

/** svuota buffer */
void svuotaBuffer(){
    char c;
    do {
        c = getchar();
    } while (c != '\n');
}







