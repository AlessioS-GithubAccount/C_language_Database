//
// Created by notic_v0rm88d on 14/08/2023.
//
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"
#include "as_library3.h"

/******************************************** Parte 5. a, b, c *******************************************************/
// utente inserisce manualmente dati delle varie struct Recordstudente nell'elenco
void inserisciStudenti(RecordStudente elenco[], int dim){
    /*int i;
    for (i = 0; i < DIM_ELENCO; i++) {
        printf("\n\nStudente %d: \n", i+1);
        elenco[i] = inserisciStudente();
    }*/

    int i;
    int continua = 1; // Inizializziamo continua a 1 per iniziare il ciclo

    for (i = 0; i < dim && continua; i++) {
        printf("\n\nStudente %d: \n", i + 1);
        elenco[i] = inserisciStudente();

        // Chiedi all'utente se desidera continuare
        printf("Vuoi inserire un altro studente? (1 = si, 0 = no): ");
        scanf("%d", &continua);

        if (continua != 1) {
            // L'utente ha inserito un valore diverso da 1, quindi usciamo dal ciclo, chiudi il runtime, esce dalla procedura;
            break;
        }
    }
}

// genera random Recordstudente 'studente' nell'elenco
void generaStudenti(RecordStudente elenco[], int dim){
    RecordStudente studente;
    int i;
    for (i = 0; i < DIM_ELENCO; i++) {
        elenco[i]=generaStudente();
    }
}

// stampa elenco RecordStudente
void stampaStudenti(RecordStudente elenco[], int dim){
    RecordStudente studente;
    int i;
    for (i = 0; i < DIM_ELENCO; ++i) {
        printf("\n\nStudente %d.", i+1);
        stampaStudente(elenco[i]);
        printf("\n");
    }
}

///************************************************ Parte 5. d ********************************************************/
// Utente inserisce un CF in barra di ricerca (con controlli)
void acquisisce_cerca_codiceFiscale(char str[DIM_CF], int dim){
    do {
        acquisisci_CF(str);
        svuotaBuffer();
        // error message
        if(!controllo_codice_fiscale_Beta(str))
            printf("\nSpiacente. Il codice fiscale deve contenere solo lettere maiuscole e numeri"
                 " nella corretta posizione. Reinserire: ");
    } while (!controllo_codice_fiscale_Beta(str));
}

// effettua un strcmp tra cf inserito da utente e i cf in elenco Recordstudente delle varie struct generate da generaStudenti();
void cercaStudente(RecordStudente elenco[], char cf_ricerca[], int dim){
    int i;
    printf("\nInserire il codice fiscale nel motore di ricerca: "); // barra di ricerca
    acquisisce_cerca_codiceFiscale(cf_ricerca, DIM_CF);  // inserimento cf da cercare

    for (i = 0; i < dim; ++i) {
        if (strcmp(elenco[i].codiceFiscale, cf_ricerca) == 0) {
            printf("\nStudente trovato. Dati studente:\n");
            stampaStudente(elenco[i]); // Devi passare l'indirizzo dello studente
        }
    }
}
///************************************************ Parte 5. e ********************************************************/
// procedura che somma tutte le quote iscrizione registrate in RecordStudente elenco[] di ogni studente
void calcolaEntrate(RecordStudente elenco[], int dim){
    int i;
    float somma;
    for (i = 0; i < DIM_ELENCO; ++i) {
        somma += elenco[i].sommaPagata;
    }
    printf("\nTotale introito quote di iscrizione al corso TNV Fullstack Developer: %.2f EUR \n", somma); // titolo
}
///************************************************ Parte 5. f ********************************************************/
// procedura che stampa quanti studenti per ogni titolo di studio ci sono in RecordStudente elenco[]
Titolo acquisisce_cerca_titoli_studio(){
    Titolo titolo;
    do {
        printf("\nInserisci un titolo di studio : \nDigita 0=diploma, 1=laurea triennale, 2=laurea magistrale, 3=altro.\n");
        scanf("%d", &titolo);
        if(titolo<0 || titolo>3)
            printf("\nOpzione non valida / non presente in menu\'. Reinserire:\n");
    } while (titolo<0 || titolo>3);
    return titolo;
}

void switch_stampa_titoli_studio(int diplomi, int triennali, int magistrali, int altro, Titolo titolo){

    switch (titolo) {
        case 0:
            printf("\nNumero di studenti con diploma: %d", diplomi);
            break;
        case 1:
            printf("\nNumero di studenti con laurea triennale: %d", triennali);
            break;
        case 2:
            printf("\nNumero di studenti con laurea magistrale: %d", magistrali);
            break;
        case 3:
            printf("\nNumero di studenti con altri titoli: %d", altro);
            break;
        default:
            printf("\nSpiacente, hai digitato un numero fuori elenco. Reinserire: ");
    }
}

void titoloStudio(RecordStudente elenco[], int dim){
    int i; int diplomi=0; int triennali=0; int magistrali=0; int altro=0;
    Titolo titolo;

     titolo = acquisisce_cerca_titoli_studio();

    for (i = 0; i < DIM_ELENCO; ++i) {
        if(elenco[i].titoloStudio==0)
            diplomi++;
        else if(elenco[i].titoloStudio==1)
            triennali++;
        else if(elenco[i].titoloStudio==2)
            magistrali++;
        else
            altro++;
    }
    switch_stampa_titoli_studio(diplomi, triennali, magistrali, altro, titolo);
}
///************************************************ Parte 5. g ********************************************************/
/********************************************* Parte 5 g ****************************************************************
- g. Creare una procedura chiamata stampaEdizione che stampi tutte le informazioni di ogni singolo studente
     per l’edizione specifica utilizzando la funzione “stampaStudente”; la procedura deve ricevere
     in ingresso il vettore degli studenti e la sua dimensione nonché l’edizione di riferimento.
***********************************************************************************************************************/
int acquisisce_edizione_per_ricerca(){
    int edizione;
    printf("\nInserisci numero dell'edizione per la ricerca degli studenti partecipanti: ");
    scanf("%d", &edizione);
    return edizione;
}

void stampaEdizione(RecordStudente elenco[], int dim, int edizione){
    int i;
    edizione = acquisisce_edizione_per_ricerca();

    for (i = 0; i < DIM_ELENCO; ++i) {
        if(edizione== elenco[i].edizione)
            stampaStudente(elenco[i]);
    }
}

