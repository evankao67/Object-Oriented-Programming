#include "Grass.h"
void Grass::opt(Creature **a, Creature **b)
{
    if (age < 6 && age >= 3)
    {
        //puts("evan");
        Grass *tmp = new Grass;
        *b = tmp;
        (*b)->status=1;
    }
}
