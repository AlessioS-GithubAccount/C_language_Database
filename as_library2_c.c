/*******************************************************************************************************************
 * Parte 3 A
 * 2.   Creare una procedura chiamata stampaStudente che stampi tutte le informazioni, in
        modo ordinato e leggibile relative all’elemento passato come parametro.

        parte 3 A in "as_library2_a.c"
        parte 3 B in "as_library2_c.c"
 **********************************************************************************************************************/
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"
/******************************************* Funzioni di stampa **************************************************/
// stampa i dati di un intera struct Recordstudente
void stampaStudente(RecordStudente studente){
    printf("\nNome: %s", studente.nome);
    printf("\nCognome: %s", studente.cognome);
    printf("\nCodice Fiscale: %s", studente.codiceFiscale);
    stampa_titolo_studio(studente);
    printf("\nData di nascita: %02d/%02d/%02d", studente.dataNascita.giorno,studente.dataNascita.mese,studente.dataNascita.anno);
    printf("\nEdizione: %d", studente.edizione);
    stampa_inCorso(studente);
    printf("\nSomma pagata: %.2f EUR", studente.sommaPagata);
}

// switch case stampa per enum studente.titoloStudio
void stampa_titolo_studio(RecordStudente studente){
    switch (studente.titoloStudio) {
        case 0:
            printf("\nTitolo di studio: Diploma", studente.titoloStudio);
            break;
        case 1:
            printf("\nTitolo di studio: Laurea triennale", studente.titoloStudio);
            break;
        case 2:
            printf("\nTitolo di studio: Laurea magistrale", studente.titoloStudio);
            break;
        case 3:
            printf("\nTitolo di studio: Altro", studente.titoloStudio);
            break;
    }
};

// stampa In corso: si / In corso: no
void stampa_inCorso(RecordStudente studente){
    if(studente.inCorso==1)
        printf("\nIn Corso: Si", studente.inCorso);
    else
        printf("\nIn Corso: No", studente.inCorso);
}


