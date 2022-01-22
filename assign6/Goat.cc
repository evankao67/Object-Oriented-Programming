#include "Goat.h"
void Goat::opt(Creature **a, Creature **b)
{
    if (age < 51 || age > 55)
    {
        *b=*a;
        *a=NULL;
        (*b)->status = 1;
    }
    else
    {
        Goat *tmp = new Goat;
        *b = tmp;
        (*b)->status = 1;
        (*a)->status = 1; 
    }
}