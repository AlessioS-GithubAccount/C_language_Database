/*******************************************************************************************************************
 * // Created by Alessio Sanna on 10/08/2023.
 * Parte 3
 * 2.	Creare una funzione chiamata generaStudente che generi casualmente tutte le informazioni relative al record
 *      dello studente seguendo le specifiche riportate al punto precedente e restituisca un elemento completo.
 *
        parte 3 .1 in "as_library2_a.c"
        parte 3 .3 in "as_library2_c.c"
 **********************************************************************************************************************/
#ifndef AS_TNV_PROJECT_AS_LIBRARY2_B_H
#define AS_TNV_PROJECT_AS_LIBRARY2_B_H
//* Librerie interne
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"

//* Macro
#define MIN_TITOLO 0
#define MAX_TITOLO 3
#define MIN_GIORNI 1
#define MAX_GIORNI 31
#define MIN_MESI 1
#define MAX_MESI 12
#define MIN_ANNI 1960
#define MAX_ANNI 2005 // limite di maggiore età
#define MIN_EDIZIONE 1
#define MAX_EDIZIONE 11
#define MIN_SOMMA_PAGATA 0
#define MAX_SOMMA_PAGATA 3000

// funzione per generare randomicamente tutti i campi dati di struct Recordstudente
RecordStudente generaStudente();

// ogni funzione genera randomicamente un campo specifico di struct Recordstudente
RecordStudente random_nome_cognome();
void generaCodiceFiscale(char codiceFiscale[]);
char random_numeri();
char lettera_random();
Titolo random_titolo();
Data random_data();
int random_edizione();
bool random_inCorso();
float random_sommaPagata();

#endif //AS_TNV_PROJECT_AS_LIBRARY2_B_H
