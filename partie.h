/*
 * partie.h
 *
 */
#ifndef PARTIE_H
#define PARTIE_H

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"

typedef enum {
  J1 = 1, J2 = 2
} Joueur;

int fin_partie(Plateau p);
Case proposer_coup(Plateau p, Joueur j);
int est_valide(Plateau p, Joueur j, Case c);
int existe_coup(Plateau p, Joueur j);
void jouer_coup(Plateau *p, Joueur j, Case c);

#endif
