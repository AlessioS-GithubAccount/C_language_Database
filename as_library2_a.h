/*******************************************************************************************************************
 * // Created by Alessio Sanna on 10/08/2023.
 * Parte 3
 * 1.   Creare una funzione chiamata inserisciStudente che permetta l’inserimento dei dati di uno studente.
        La procedura deve effettuare i seguenti controlli (direttamente nella procedura o
        utilizzando subroutine esterne – scelta consigliata):

        Il nome e il cognome possono contenere solo spazi e lettere (maiuscole o minuscole);
        Il codice fiscale deve contenere esattamente 16 caratteri alfanumerici maiuscoli;
        il titolo di studio può essere scelta solo tra i valori dell’enumerazione;
        la data di nascita deve rispettare i vincoli canonici
        (non si può inserire il 30 febbraio il 31 aprile… ma non fare caso agli anni bisestili!);
        l’edizione deve essere maggiore di zero;
        la sommaPagata non può essere negativa;

        parte 3 .2 in "as_library2_b.c"
        parte 3 .3 in "as_library2_c.c"
 **********************************************************************************************************************/

#ifndef AS_TNV_PROJECT_AS_LIBRARY2_A_H
#define AS_TNV_PROJECT_AS_LIBRARY2_A_H
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
//* Librerie interne
#include <ctype.h>

/*

#define CF_i_0
#define CF_i_1
#define CF_i_2
#define CF_i_3
#define CF_i_4
#define CF_i_5
#define CF_i_6
#define CF_i_7
#define CF_i_8
#define CF_i_9
#define CF_i_10
#define CF_i_11
#define CF_i_12
#define CF_i_13
#define CF_i_14
#define CF_i_15
#define CF_i_16  *///* Macros

// prototipi
// funzione per avviare l'inserimento dati da terminale di struct Recordstudente
RecordStudente inserisciStudente();

// funzioni di inserimento dati Recordstudente studente

void acquisisciNome(char nome[]);
void acquisisciCognome(char cognome[]);
void acquisisci_CF(char codiceFiscale[]);
Titolo acquisisce_titoloStudio();
Data data_Nascita();
int acquisisci_edizione();
bool acquisisci_inCorso();
float acquisisci_sommaPagata();

// funzioni di controllo correttezza/validita' dati inseriti
int controllo_nome_cognome(char stringa[]);
int controllo_codice_fiscale_Beta(char stringa[DIM_CF]);  // beta version, piu precisa, posizioni numero/lettera specifiche in formato CF
int controllo_codice_fiscale(char stringa[]); // controllo originale codice fiscale: controlla se CF ha solo numeri e lettere maiuscole
int controllo_titolo(Titolo titolo);
int controllo_dataNascita(Data data);
int controllo_edizione(int edizione);
int controllo_inCorso(int inCorso);
int controllo_sommaPagata(float sommaPagata);

/* procedure di inserimento da terminale
void inserimento_cognome_da_terminale();
void inserimento_nome_da_terminale(char *nome);
void inserimento_codiceFiscale_da_terminale(char codiceFiscale[]);
int inserimento_titoloStudio_da_terminale();
*/


#endif //AS_TNV_PROJECT_AS_LIBRARY2_A_H
