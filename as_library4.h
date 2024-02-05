/*******************************************************************************************************************
 * // Created by Alessio Sanna on 10/08/2023.
 * Parte 7
 * Implementare una funzione criptaStudente che cripti nome, cognome e codice fiscale di
 * una variabile RecordStudente data in ingresso restituisca la suo versione criptata.
 *
 * - Implementare una funzione decriptaStudente che decripti nome, cognome e codice
 * fiscale di una variabile RecordStudente data in ingresso restituisca la suo versione criptata.
 *
 * - Implentare una procedura criptaDati che cripti tutti gli studenti utilizzando la funzione
 * “criptaStudente”; la procedura deve ricevere in ingresso il vettore degli studenti e la sua dimensione.
 * - Implentare una procedura decriptaDati che cripti tutti gli studenti utilizzando la funzione
 * “decriptaStudente”; la procedura deve ricevere in ingresso il vettore degli studenti e la sua dimensione.


        parte 7 in "as_library4.c"
 **********************************************************************************************************************/
#ifndef AS_TNV_PROJECT_AS_LIBRARY4_H
#define AS_TNV_PROJECT_AS_LIBRARY4_H
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"
#include "as_library3.h"
#include "as_library4.h"

//* Macro
#define DAYS_IN_ONEYEAR 360
#define DAYS_IN_ONEMONTH 30

// prototipi
void cripta_stringa(char str[], int dim);  // cripta una stringa generica
RecordStudente criptaStudente(RecordStudente studente);  // cripta nome, cognome, codice fiscale di uno studente Recordstudente
void decriptaStudente(RecordStudente studente);  // decripta nome, cognome, codice fiscale di uno studente Recordstudente
void criptaDati(RecordStudente elenco[], int dim);   // cripta un elenco di struct Recordstudente studente
void decriptaDati(RecordStudente elenco[], int dim);  // decripta un elenco di struct Recordstudente studente

int calcola_data_inGiorni(RecordStudente studente);    // converte una data gg/mm/aaaa in giorni
void ordinaAlfabetico( RecordStudente elenco[], int dimensione);  // ordina studenti in elenco per ordine alfabetico
void ordinaDataNascita(RecordStudente elenco[], int dimensione);  // ordina studenti in elenco per data crescente (conv. in giorni)

// procedure di stampa
void stampaOrdineAlfabetico( RecordStudente elenco[], int dimensione);
void stampaOrdineAnnoNascita( RecordStudente elenco[], int dimensione);

#endif //AS_TNV_PROJECT_AS_LIBRARY4_H
