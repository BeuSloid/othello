/*
 * plateau.h
 *
 */
#ifndef PLATEAU_H
#define PLATEAU_H
/* directives #include */
#include <stdio.h>

/* directives #define */
#define pionNoir 'X'
#define pionBlanc 'O'
#define caseVide ' '
/* Déclarations des structures */
typedef struct {
  char cases[8][8];
} Plateau;

typedef struct {
  int col;
  int lig;
} Case;
/* Déclarations des variables globales */

/* Déclarations des fonctions
 * Exemple :*/
void init_plateau(Plateau *p);
void afficher_plateau(Plateau p);
#endif // PLATEAU_H

