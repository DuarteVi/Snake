#include <stdlib.h>
#include <graph.h>
#include "jeu.h"
#include "option.h"
#include "launcher.h"

int main() {

    /* Initialisation de la fenêtre */
    InitialiserGraphique();
    CreerFenetre(0,0,1250,600);
   
    launcher();

    FermerGraphique();
    
    return EXIT_SUCCESS;
}