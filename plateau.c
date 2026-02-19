/*
 * plateau.c
 *
 */
#include "plateau.h"
#include <stdio.h>
#include <stdlib.h>

#define TAILLE 8

void init_plateau(Plateau *p) {
  for (int i = 0; i < TAILLE; i++) {
    for (int j = 0; j < TAILLE; j++) {
      p->cases[i][j] = caseVide;
    }
  }
  p->cases[3][4] = pionBlanc;
  p->cases[4][3] = pionBlanc;
  p->cases[3][3] = pionNoir;
  p->cases[4][4] = pionNoir;
}

void afficher_plateau(Plateau p) {
  printf("  A   B   C   D   E   F   G   H\n");
  for (int i = 0; i < TAILLE; i++) {
    for (int j = 0; j < TAILLE; j++) {
      printf("+---");
    }
    printf("+\n");
    for (int j = 0; j < TAILLE; j++) {
      printf("| %c ", p.cases[i][j]);
    }
    printf("| %d\n", i + 1);
  }
  for (int j = 0; j < TAILLE; j++) {
    printf("+---");
  }
  printf("+\n");
}

