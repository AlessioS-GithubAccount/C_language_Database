/*******************************************************************************************************************
 * // Created by Alessio Sanna on 10/08/2023.
 *
 * Parte 5
 * /** Test eseguiti: ok **/
/*********************************************************************************************************************/
#ifndef AS_TNV_PROJECT_AS_LIBRARY3_H
#define AS_TNV_PROJECT_AS_LIBRARY3_H
// Librerie interne
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"
//* Macros
#define DIM_ELENCO 50
/******************************************* Parte 5. a, b, c ********************************************************
- a. Creare nel main un vettore di 50 elementi chiamato “elenco” di tipo RecordStudente;
     Creare una funzione chiamata inserisciStudenti che permetta l’inserimento dei dati di
     tutti gli studenti utilizzando la funzione “inserisciStudente”; la procedura deve ricevere in
     ingresso il vettore degli studenti e la sua dimensione.
- b. Creare una funzione chiamata generaStudenti che generi casualmente tutte le
     informazioni relative a tutti gli studenti utilizzando la funzione “generaStudente”;
     la procedura deve ricevere in ingresso il vettore degli studenti e la sua dimensione.
- c. Creare una procedura chiamata stampaStudenti che stampi tutte le informazioni di ogni
     singolo studente utilizzando la funzione “stampaStudente”;
     la procedura deve ricevere in ingresso il vettore degli studenti e la sua dimensione.
***********************************************************************************************************************/
// Prototipi a, b, c
void inserisciStudenti(RecordStudente elenco[], int dim);  // permette creazione lista di tipo Recordstudentee inserimento dati
void generaStudenti(RecordStudente elenco[], int dim);  // genera lista studenti con dati randomici
void stampaStudenti(RecordStudente elenco[], int dim);  // stampa una lista Recordstudente

/********************************************* Parte 5 d ****************************************************************
- d. Creare una procedura chiamata cercaStudente che stampi tutte le informazioni dello
     studente il cui codice fiscale corrisponde a quello inserito dall’utente.
***********************************************************************************************************************/
void cercaStudente(RecordStudente elenco[], char cf_ricerca[], int dim);  // ricerca studenti per CF inserito da terminale
void acquisisce_cerca_codiceFiscale();  // acquisizione CF
void inserisci_cf(char str[], int dim);  // inserimento da terminale di CF per ricerca studente per CF

/********************************************* Parte 5 e ****************************************************************
- e. Creare una procedura chiamata calcolaEntrate che calcoli e stampi l’introito totale
     sommando le somme pagate da tutti gli studenti.
***********************************************************************************************************************/
void calcolaEntrate(RecordStudente elenco[], int dim);  // calcola la somma delle quote pagate dagli studenti in elenco

/********************************************* Parte 5 f ****************************************************************
- f. Creare una procedura chiamata titoloStudio che stampi il numero di studenti per ogni
    tipologia di titolo di studio.
***********************************************************************************************************************/
Titolo acquisisce_cerca_titoli_studio(); // inserimento da terminale del titolo ai fini di ricerca studenti membri
void switch_stampa_titoli_studio(int diplomi, int triennali, int magistrali, int altro, Titolo titolo);  // switch stampa n' titoli
void titoloStudio(RecordStudente elenco[], int dim);  // stampa n titoli in elenco Recordstudente

/********************************************* Parte 5 g ****************************************************************
- g. Creare una procedura chiamata stampaEdizione che stampi tutte le informazioni di ogni singolo studente
     per l’edizione specifica utilizzando la funzione “stampaStudente”; la procedura deve ricevere
     in ingresso il vettore degli studenti e la sua dimensione nonché l’edizione di riferimento.
***********************************************************************************************************************/

int acquisisce_edizione_per_ricerca();  // inserimento da terminale dell'edizione ai fini di ricerca studenti membri
void stampaEdizione(RecordStudente elenco[], int dim, int edizione);  // ricerca studenti per filtro edizione

/********************************************* Parte 6 ****************************************************************
Avviare il programma, generare i dati e stamparli.
***********************************************************************************************************************/


#endif //AS_TNV_PROJECT_AS_LIBRARY3_H
