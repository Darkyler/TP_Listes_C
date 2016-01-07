#include <stdio.h>

#include "Flotte.h"
#include "Position.h"
#include "Bateau.h"
Position choixPosition()
{           /* demande de rentrer 2 entiers et en fait une position */
    int X,Y;
    printf("Entrez une valeur de X: ");
    scanf("%d",&X);
    printf("\nEntrez une valeur de Y: ");
    scanf("%d",&Y);
    Position pos;
    pos.X = X;
    pos.Y = Y;
    return pos;
}

int estTouchee(Position p, FlotteN f)
{
  int i = 0;
  int j = 0;
  while (i <= sizeof(f->nbreBateaux))
  {
    BateauN b = tableauBateaux(f)[i];
    while (j < taille(b) || (tableauMorceaux(b)[i].X == p.X && tableauMorceaux(b)[i].Y == p.Y))
    {
        j++;
    }
    if (j < taille(b))
    {
      return 1;
      break;
    }
    i++;

  }
  return 0;
}   /* retourne 1 si la position paramètre correspond à la position d'un bateau dans la flotte en paramètre, 0 sinon */

int estCoulee(Position p, FlotteN f)
{
  if (estTouchee(p,f))
  {
    int i = 0;
    int j = 0;
    while (i <= nbreBateaux(f))
    {
      BateauN b = tableauBateaux(f)[i];
      while (j < taille(b) || (tableauMorceaux(b)[i].X == p.X && tableauMorceaux(b)[i].Y == p.Y))
      {
          j++;
      }
      /* Soit aucun morceau touché : j == taille(b) soit morceau touché j = numero du morceau du bateau */
      if (j < taille(b))
      {
        return (taille(b)==1);
        break;
      }

    }
    return 0;
  }   /* retourne 1 si la position paramètre correspond à la position d'un bateau dans la flotte en paramètre, 0 sinon */
  else{
    return 1;
  }
}
/* retourne 1 si la position paramètre correspond au dernier morceau du bateau au préalablement touché,0 sinon, NECESSITE estTouchee(Position, Flotte)==1 */
int estVue(Position p, FlotteN f)
{
  int i= 0;
  int j=0;
  while (i <= f->nbreBateaux)
  {
    BateauN b = tableauBateaux(f)[i];
    while (j < taille(b) || (tableauMorceaux(b)[i].X == p.X || tableauMorceaux(b)[i].Y == p.Y))
    {
        j++;
    }
    if (j < taille(b))
    {
      return 1;
      break;
    }
    i++;

  }
  return 0;
}   /* retourne 1 si la position paramètre correspond à la position d'un bateau dans la flotte en paramètre, 0 sinon */

     /* retourne 1 si une des coordonnées de la position paramètre correspond à un bateau de la flotte, 0 sinon*/
int estRatee(Position p, FlotteN f)
{
 return (estTouchee(p,f) || estVue(p,f));
}     /* retourne 1 si la position paramètre ne touche pas et ne voit pas un bateau compris dans la flotte, 0 sinon */
int estValide(Position p)
{
  return (p.X >= 0 && p.X <= 20 && p.Y >= 0 && p.Y <= 20);
}            /* retourne 1 si les coordonnées de la position sont comprises entre 1 et 20, et si estDans(Position, Flotte) == 0,  0 sinon */

int estDans(Position p, FlotteN f)
{
    return estTouchee(p,f);
}      /* retourne 1 si la position paramètre est déjà correspondant à une position de bateau dans la flotte */