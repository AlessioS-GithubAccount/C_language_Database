//
// Created by notic_v0rm88d on 17/08/2023.
//
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"
#include "as_library3.h"
#include "as_library4.h"

// cripta una singola stringa alfanumerica
void cripta_stringa(char str[], int dim){
    /* //inserimento manuale
    printf("\nInserisci una parola da criptare:");
    scanf("%s", str);
    */
    int i, k, j;
    char lettera;

    int lunghezzaStringa = strlen(str);

    for (i = 0; i < lunghezzaStringa; i++) {
        lettera = str[i];
        if (lettera >= 'A' && lettera <= 'Z')
            str[i] = 'Z' - (lettera - 'A');
        else if(lettera >= 'a' && lettera <= 'z')
            str[i] = 'z' - (lettera - 'a');
        else if(lettera > '0' && lettera <= '9')
            str[i] = '9' + 1 - (lettera - '0');
        else if(lettera=='0')
            str[i] = '9';

    }
}

// cripta una struct Recordstudente studente
RecordStudente criptaStudente(RecordStudente studente) {
    cripta_stringa(studente.nome, DIM_NOME_COGNOME);
    cripta_stringa(studente.cognome, DIM_NOME_COGNOME);
    cripta_stringa(studente.codiceFiscale, DIM_CF);
}

// decripta una struct Recordstudente studente
void decriptaStudente(RecordStudente studente) {
    cripta_stringa(studente.nome, DIM_NOME_COGNOME);
    cripta_stringa(studente.cognome, DIM_NOME_COGNOME);
    cripta_stringa(studente.codiceFiscale, DIM_CF);
}


 // cripta un elenco di struct Recordstudente studente
 void criptaDati(RecordStudente elenco[], int dim){
     int i;
     RecordStudente studente;
     for (i = 0; i < DIM_ELENCO ; i++) {
         cripta_stringa(elenco[i].nome, DIM_NOME_COGNOME);
         cripta_stringa(elenco[i].cognome, DIM_NOME_COGNOME);
         cripta_stringa(elenco[i].codiceFiscale, DIM_NOME_COGNOME);
         // decommenta se si necessita di vedere in runtime i dati criptati o decriptati
         //printf("\nCriptato studente %d: \t\n%s\n%s\n%s", i+1, elenco[i].nome,elenco[i].cognome,elenco[i].codiceFiscale);

     }
}

void decriptaDati(RecordStudente elenco[], int dim){
    int i;
    RecordStudente studente;
    for (i = 0; i < DIM_ELENCO ; i++) {
        cripta_stringa(elenco[i].nome, DIM_NOME_COGNOME);
        cripta_stringa(elenco[i].cognome, DIM_NOME_COGNOME);
        cripta_stringa(elenco[i].codiceFiscale, DIM_NOME_COGNOME);
        // decommenta se si necessita di vedere in runtime i dati criptati o decriptati
        // printf("\nDecriptato studente %d: \t\n%s\n%s\n%s", i+1, elenco[i].nome,elenco[i].cognome,elenco[i].codiceFiscale);
    }
}

int calcola_data_inGiorni(RecordStudente studente) {    // converte una data gg/mm/aaaa in giorni
    int i, giorni, mesi, anni;

    giorni = studente.dataNascita.giorno;
    mesi = studente.dataNascita.mese;
    anni = studente.dataNascita.anno;

    // Converte anni in giorni senza uso di anni bisestili
    giorni += (anni - 1) * DAYS_IN_ONEYEAR; // 12 months * 30 days

    // Converte mesi commerciali(30 giorni) in giorni
    for (i = 1; i < mesi; i++) {
        giorni += DAYS_IN_ONEMONTH;
    }
    giorni += giorni;

    return giorni;
}

void ordinaAlfabetico( RecordStudente elenco[], int dimensione) {
    int i, j;
    for (i = 0; i < dimensione - 1; i++) {
        for (j = 0; j < dimensione - i - 1; j++) {
            if (strcmp(elenco[j].cognome, elenco[j + 1].cognome) > 0) {
                RecordStudente temp = elenco[j];
                elenco[j] = elenco[j + 1];
                elenco[j + 1] = temp;
            }
        }
    }
}

// Procedura per ordinare gli studenti in base all'anno di nascita dal più piccolo al più grande
void ordinaDataNascita(RecordStudente elenco[], int dimensione) {
    int i, j;
    for (i = 0; i < dimensione - 1; i++) {
        for (j = 0; j < dimensione - i - 1; j++) {
            int giorniA = calcola_data_inGiorni(elenco[j]);
            int giorniB = calcola_data_inGiorni(elenco[j + 1]);
            if (giorniA > giorniB) {
                RecordStudente n = elenco[j];
                elenco[j] = elenco[j + 1];
                elenco[j + 1] = n;
            }
        }
    }
}

// Procedura per stampare gli studenti in ordine alfabetico
void stampaOrdineAlfabetico(RecordStudente elenco[], int dimensione) {
    ordinaAlfabetico(elenco, dimensione);
    printf("\nStampa degli studenti in ordine alfabetico:\n");
    stampaStudenti(elenco, dimensione);
}

// Procedura per stampare gli studenti in ordine di data di nascita
void stampaOrdineAnnoNascita( RecordStudente elenco[], int dimensione) {
    ordinaDataNascita(elenco, dimensione);
    printf("\nStampa degli studenti in ordine di data di nascita:\n");
    stampaStudenti(elenco, dimensione);
}

