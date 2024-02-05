/*******************************************************************************************************************
 * Parte 3 A
 * 2.   Creare una procedura chiamata stampaStudente che stampi tutte le informazioni, in
        modo ordinato e leggibile relative all’elemento passato come parametro.

        parte 3 A in "as_library2_a.c"
        parte 3 B in "as_library2_c.c"
 **********************************************************************************************************************/

#ifndef AS_TNV_PROJECT_AS_LIBRARY2_C_H
#define AS_TNV_PROJECT_AS_LIBRARY2_C_H
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_b.h"
#include "as_library2_c.h"

// funzioni di stampa
void stampaStudente(RecordStudente studente);  // stampa tutti i dati di struct Recordstudente
void stampa_titolo_studio(RecordStudente studente);  // switch case
void stampa_inCorso(RecordStudente studente);  // switch case

#endif //AS_TNV_PROJECT_AS_LIBRARY2_C_H
