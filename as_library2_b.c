/*******************************************************************************************************************
 * Parte 3 A
 * 2.   Creare una funzione chiamata generaStudente che generi casualmente tutte le
        informazioni relative al record dello studente seguendo le specifiche riportate al punto
        precedente e restituisca un elemento completo.

        parte 3 A in "as_library2_a.c"
        parte 3 C in "as_library2_c.c"
 **********************************************************************************************************************/
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"
//* Macros
#define DIM_LIST_NAME 50
#define DIM_LIST_SURNAME 50

// funzione per generare randomicamente tutti i campi dati di struct Recordstudente
RecordStudente generaStudente(){
    RecordStudente studente;
    studente=random_nome_cognome();
    generaCodiceFiscale(studente.codiceFiscale);
    studente.titoloStudio= random_titolo();
    // controllo data esistente/possibile per data random generata
    do {
        studente.dataNascita = random_data();
    }while(!controllo_dataNascita(studente.dataNascita));
    studente.edizione= random_edizione();
    studente.inCorso= random_inCorso();
    studente.sommaPagata= random_sommaPagata();
    return studente;
}

// dati una lista array nomi e una lista cognomi genera una stringa nome e un cognome random per i campi Recordstudente
RecordStudente random_nome_cognome() {
    RecordStudente studente;
    char nomi_lista[DIM_LIST_NAME][DIM_NOME_COGNOME] = {"Michael", "Samantha", "Noah", "Ethan", "Tracy", "Charlie", "Megan", "Sophia", "Liam",
                         "Mia", "Linda", "Joseph", "William", "Isabella", "Daniel", "Margaret", "Alexander", "Jayden",
                         "Joanne","Emma", "James", "Olivia", "Reece", "Jennifer", "Oscar", "Richard", "David",
                         "Robert", "Barbara", "Harry","Mason", "Madison", "Lauren", "Thomas", "Bethany", "Kyle", "Ava",
                         "Jacob", "Oliver", "Amelia", "John", "Elizabeth", "Victoria", "Callum", "Connor", "Jake",
                         "Jack", "Joe", "Patricia", "Susan"};

    int i = rand() % DIM_LIST_NAME;
    strcpy(studente.nome,nomi_lista[i]);

    char cognomi_lista[DIM_LIST_SURNAME][DIM_NOME_COGNOME] = {"Jones", "Williams", "Davies", "Evans", "Adams", "Wilson", "Johnson", "Roberts", "Thompson",
                                                              "Robertson", "Wright", "White", "Lewis", "Harris", "Cooper", "Turner", "Moore", "Morris",
                                                              "Clark", "Lee", "Harrison", "Scott", "Allan", "Morgan", "Phillips", "Davis", "Watson",
                                                              "Parker", "Bennet", "Carter", "Collins", "Cox", "Marshall", "Simpson", "Foster", "Chapman",
                                                              "Wilkinson", "Rogers", "Gray", "Mason", "Hunt", "Campbell", "Holmes", "Palmer", "Mills",
                                                              "Lloyd", "Knight", "Fisher", "Stevens", "Jenkins"};

    int j = rand() % DIM_LIST_SURNAME;
    strcpy(studente.cognome,cognomi_lista[j]);
    return studente;
}

// genera random lettere per il CF
char lettera_random() {
    char caratteri_CF[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lunghezza = strlen(caratteri_CF);
    int i = rand() % lunghezza;
    return caratteri_CF[i];
}

// genera random numeri per il CF
char random_numeri(){
    char numeri_CF[] = "0123456789";
    int lunghezza = strlen(numeri_CF);
    int i = rand() % lunghezza;
    return numeri_CF[i];
}

// genera un CF con lettere e numeri nelle corrette posizioni in formato CF
void generaCodiceFiscale(char codiceFiscale[]) {
    // SNN LSS 90H  0 3  B    3  5  4  X     \n
    // 012 345 678  9 10 11   12 13 14 15    16
    int i;
    for (i = 0; i < DIM_CF-1; i++) {
        if (i == 6 || i == 7 || i == 9 || i == 10 || i == 12 || i == 13 || i == 14)
            codiceFiscale[i] = random_numeri();
        else if(i == 0 || i == 1 ||i == 2||i == 3||i == 4||i == 5|| i == 8 || i == 11 || i == 15)
            codiceFiscale[i] = lettera_random();
    }
    codiceFiscale[DIM_CF-1] = '\0';

}

// genera un titolo di studio basandosi sulla rispettiva enum Titolo
Titolo random_titolo(){
    Titolo titolo;
    titolo= MIN_TITOLO + rand()%(MAX_TITOLO-MIN_TITOLO+1);
    return titolo;
}

// genera una data in formato gg/mm/aa per il corrispettivo campo struct dataNascita
Data random_data(){
    Data data;
    data.giorno = MIN_GIORNI + rand()%(MAX_GIORNI-MIN_GIORNI+1);
    data.mese = MIN_MESI + rand()%(MAX_MESI-MIN_MESI+1);
    data.anno = MIN_ANNI + rand()%(MAX_ANNI-MIN_ANNI+1);
    return data;
}

// genera un edizione random > 1
int random_edizione() {
    int edizione;
    edizione = MIN_EDIZIONE + rand()%(MAX_EDIZIONE-MIN_EDIZIONE+1);
    return edizione;
}

// genera random un bool In corso / Non in corso
bool random_inCorso() {
    return rand() % 2 == 0;
}

// genera random float somma pagata > 0
float random_sommaPagata(){
    float sommaPagata;
    sommaPagata = MIN_SOMMA_PAGATA + rand()%(MAX_SOMMA_PAGATA-MIN_SOMMA_PAGATA+1);
    return sommaPagata;
}

