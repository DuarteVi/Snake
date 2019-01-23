#include <stdlib.h>
#include <graph.h>
#include "jeu.h"
#include "option.h"
#include "launcher.h"

 



int launcher(){
    ChoisirEcran(6);

    /* Initialisation des variables */
    int play_button = ChargerSprite("img/play_button.png");
    int option_button = ChargerSprite("img/option_button.png");
    int exit_button = ChargerSprite("img/exit_button.png");
    int snake_icon = ChargerSprite("img/snake2.png");
    int snake_icon_reverse = ChargerSprite("img/snake2_r.png");
    int c1, c2;

    int Param[14];
    Param[0]=60;
    Param[1]=40;
    Param[2]=5;
    Param[3]=0;
    Param[4]=10;
    Param[5]=10;
    Param[6] = 1;                      
    Param[7] = CouleurParComposante(000,105,000);         
    Param[8] = CouleurParComposante(000,100,000);
    Param[9] = CouleurParComposante(000,100,000);
    Param[10] = CouleurParComposante(000,000,000);         
    Param[11] = CouleurParComposante(000,000,000);
    Param[12] = CouleurParComposante(050,050,050);        
    Param[13] = CouleurParComposante(255,000,000); 
    

    /* Fond écran */
    c1=CouleurParComposante(20,120,20);
    EffacerEcran(c1);
    int T=0;

/* ------------- Affichage des boutons et images ------------- */

    while (True) {
        ChoisirEcran(6);

        /* Titre en haut de page */
        c2=CouleurParNom("black");
        ChoisirCouleurDessin(c2);
        EcrireTexte(600,60,"Snaky !",2);

        /* Bouton jouer */
        EcrireTexte(470,290,"Jouer",2);
        AfficherSprite(play_button, 405, 255);

        /* Bouton options */
        EcrireTexte(740,290,"Options",2);
        AfficherSprite(option_button, 675, 255);

        /* Bouton quitter */
        EcrireTexte(602,540,"Quitter",2);
        AfficherSprite(exit_button, 537, 505);

        /* Image du serpent */
        AfficherSprite(snake_icon_reverse, -20, 5);
        AfficherSprite(snake_icon, 675, 5);

        /* Contours des boutons */
        DessinerRectangle(400, 250, 190, 60);
        DessinerRectangle(670, 250, 190, 60);
        DessinerRectangle(532, 500, 190, 60);
        SourisPosition();
        if ( _X > 400 && _X < 590 && _Y > 250 && _Y < 310 )
        {
            ChoisirCouleurDessin(CouleurParNom("red"));
            DessinerRectangle(400, 250, 190, 60);
        }
        if ( _X > 670 && _X < 860 && _Y > 250 && _Y < 310 )
        {
            ChoisirCouleurDessin(CouleurParNom("red"));
            DessinerRectangle(670, 250, 190, 60);
        }
        if ( _X > 532 && _X < 722 && _Y > 500 && _Y < 560)
        {
            ChoisirCouleurDessin(CouleurParNom("red"));
            DessinerRectangle(532, 500, 190, 60);
        }

        CopierZone(6,0,0,0,1250,600,0,0);
    
/* ----------------- Changement de programme ----------------- */
        if (ToucheEnAttente())
        {
            T=Touche();
            if (T==XK_Escape)
                return 0;
        }
        if(SourisCliquee()) {
            
        
            if ( _X > 400 && _X < 590 && _Y > 250 && _Y < 310 ) {
                /* Lancer le programme jeu */
                jeu(Param);

            } else if ( _X > 670 && _X < 860 && _Y > 250 && _Y < 310 ) {
                /* Lancer les options */
                option(Param);

            } else if ( _X > 532 && _X < 722 && _Y > 500 && _Y < 560) {
                

                return 0;
            }
            CopierZone(6,0,0,0,1250,600,0,0);
        }
/* ----------------------------------------------------------- */

    }


}

