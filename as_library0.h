/*******************************************************************************************************************
 * // Created by Alessio Sanna on 10/08/2023.
 *
 * PROGETTO TNV ED XI
 * Obiettivo del progetto
 * Il programma in oggetto dovrà permettere alla TNV la gestione e ricerca di studenti sulla base
 * di determinati parametri. Devono essere quindi permesse operazioni di inserimento, modifica,
 * eliminazione, ricerca, ordinamento ed esportazione dei dati inerenti agli studenti memorizzati nel sistema.
 *
 * *****************************************************************************************************************/
/*********************************************************************************************************************
    Parte 1 - Definizione strutture ed enumerazioni

    Nome struttura: RecordStudente

    Ogni record registrato dovrà contenere (esclusivamente) le seguenti informazioni:
    a) nome (vettore char 64 caratteri, compreso terminatore)
    b) cognome (vettore char 64 caratteri, compreso terminatore)
    c) codiceFiscale (vettore char 17 caratteri, compreso terminatore)
    d) titoloStudio (enumerazione, vedi sotto)
    e) dataNascita (struttura, vedi sotto)
    f) edizione (int)
    g) inCorso (booleano)
    h) sommaPagata (float)
    Nome struttura: Data
    Ogni posizione dovrà contenere (esclusivamente) le seguenti informazioni:
    a) anno (int)
    b) mese (int)
    c) giorno (int)
    Nome enumerazione: Titolo
    L’enumerazione dovrà contenere i seguenti valori: diploma, laurea triennale, laurea
    magistrale, altro.

    /** Test eseguiti: ok **/
/*********************************************************************************************************************/

#ifndef AS_TNV_PROJECT_AS_LIBRARY0_H
#define AS_TNV_PROJECT_AS_LIBRARY0_H

#include "as_library1.h"

//* Librerie interne
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//* Macros
#define DIM_NOME_COGNOME 64
#define DIM_CF 17


/// dichiarazione enum, strutture
// enum titolo di studio
typedef enum {diploma, laurea_triennale, laurea_magistrale, altro} Titolo;

// struct data di nascita
typedef struct {
    int anno;
    int mese;
    int giorno;
} Data;

// struct RecordStudente
typedef struct {
    char nome[DIM_NOME_COGNOME];
    char cognome[DIM_NOME_COGNOME];
    char codiceFiscale[DIM_CF];
    Titolo titoloStudio;
    Data dataNascita;
    int edizione;
    bool inCorso;
    float sommaPagata;
} RecordStudente;

// prototipi funzioni
void svuotaBuffer();

#endif //AS_TNV_PROJECT_AS_LIBRARY0_H
