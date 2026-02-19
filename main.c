/*
 * main.c
 *
 */
#include "plateau.h"
#include "partie.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  Plateau p;
  init_plateau(&p);
  afficher_plateau(p);
  Joueur j = J1;
  while (!fin_partie(p)) {
    Case c = proposer_coup(p, j);
    jouer_coup(&p, j, c);
    afficher_plateau(p);
    if (existe_coup(p, ((j + 1) % 2))) {
      j = ((j + 1) % 2);
    } else {
      printf("\nLe joueur %d passe son tour\n", ((j + 1) % 2));
    }
  }
  return 0;
}

