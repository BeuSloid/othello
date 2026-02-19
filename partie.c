#include "partie.h"
#include "plateau.h"
#include <stdio.h>
#include <stdlib.h>

int fin_partie(Plateau p) {
  int nb_pion_noir = 0;
  int nb_pion_blanc = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (p.cases[i][j] == pionNoir) {
        nb_pion_noir++;
      } else if (p.cases[i][j] == pionBlanc) {
        nb_pion_blanc++;
      } else if (p.cases[i][j] == caseVide) {
        return 0;
      }
    }
  }
  printf("Partie terminée !\n");
  printf("Score : Joueur 1 (Noir) = %d, Joueur 2 (Blanc) = %d\n", nb_pion_noir,
      nb_pion_blanc);
  if (nb_pion_noir > nb_pion_blanc) {
    printf("Le joueur 1 (Noir) est le vainqueur !\n");
  } else if (nb_pion_blanc > nb_pion_noir) {
    printf("Le joueur 2 (Blanc) est le vainqueur !\n");
  } else {
    printf("Match nul !\n");
  }
  return 1;
}

Case proposer_coup(Plateau p, Joueur j) {
  Case pos;
  char colonne;
  int ligne;
  char pionJoueur;
  if (j == J1) {
    pionJoueur = pionNoir;
  } else {
    pionJoueur = pionBlanc;
  }
  printf("Joueur %d (%c), choisissez une case (ex: A 1) : ", j, pionJoueur);
  while (1) {
    scanf("%c %d", &colonne, &ligne);
    pos.col = colonne - 'A';
    pos.lig = ligne - 1;
    if (pos.col >= 0 && pos.col < 8 && pos.lig >= 0 && pos.lig < 8) {
      return pos;
    }
    printf("Coordonnées invalides. Réessayez (ex: A 1) : ");
  }
}

int est_valide(Plateau p, Joueur j, Case c) {
  char couleur_joueur, couleur_adversaire;
  if (j == J1) {
    couleur_joueur = pionNoir;
    couleur_adversaire = pionBlanc;
  } else {
    couleur_joueur = pionBlanc;
    couleur_adversaire = pionNoir;
  }
  if (p.cases[c.lig][c.col] != caseVide) {
    return 0;
  }
  int directions[8][2] = {
    {-1, 0}, {1, 0},
    {0, -1}, {0, 1},
    {-1, -1}, {-1, 1},
    {1, -1}, {1, 1}
  };
  for (int d = 0; d < 8; d++) {
    int dx = directions[d][0], dy = directions[d][1];
    int x = c.lig + dx, y = c.col + dy;
    while (x >= 0 && x < 8 && y >= 0 && y < 8
        && p.cases[x][y] == couleur_adversaire) {
      x += dx;
      y += dy;
    }
    if (x >= 0 && x < 8 && y >= 0 && y < 8 && p.cases[x][y] == couleur_joueur) {
      return 1;
    }
  }
  return 0;
}

int existe_coup(Plateau p, Joueur j) {
  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 8; k++) {
      Case c = {
        i, k
      };
      if (est_valide(p, j, c)) {
        return 1;
      }
    }
  }
  return 0;
}

void jouer_coup(Plateau *p, Joueur j, Case c) {
  char couleur_joueur = (j == J1) ? pionNoir : pionBlanc;
  char couleur_adversaire = (j == J1) ? pionBlanc : pionNoir;
  p->cases[c.lig][c.col] = couleur_joueur;
  int directions[8][2] = {
    {-1, 0}, {1, 0},
    {0, -1}, {0, 1},
    {-1, -1}, {-1, 1},
    {1, -1}, {1, 1}
  };
  for (int d = 0; d < 8; d++) {
    int dx = directions[d][0], dy = directions[d][1];
    int x = c.lig + dx, y = c.col + dy;
    while (x >= 0 && x < 8 && y >= 0 && y < 8
        && p->cases[x][y] == couleur_adversaire) {
      x += dx;
      y += dy;
    }
    if (x >= 0 && x < 8 && y >= 0 && y < 8
        && p->cases[x][y] == couleur_joueur) {
      int rx = c.lig + dx, ry = c.col + dy;
      while (rx != x || ry != y) {
        p->cases[rx][ry] = couleur_joueur;
        rx += dx;
        ry += dy;
      }
    }
  }
}

