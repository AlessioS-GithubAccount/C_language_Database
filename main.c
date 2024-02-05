/// Project Library
#include "as_library0.h"
#include "as_library1.h"
#include "as_library2_a.h"
#include "as_library2_b.h"
#include "as_library2_c.h"
#include "as_library3.h"
#include "as_library4.h"


int main() {
    // seed to rand()
    srand(time(NULL));


    // dichiarazoione variabili;
    RecordStudente elenco[DIM_ELENCO];

    generaStudenti(elenco, DIM_ELENCO);

    stampaStudenti(elenco, DIM_ELENCO);

    //*spacebar/
    printf("\n");

    criptaDati(elenco, DIM_ELENCO);

    decriptaDati(elenco, DIM_ELENCO);


    stampaOrdineAnnoNascita(elenco, DIM_ELENCO);


    return 0;
}

