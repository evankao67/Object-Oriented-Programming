#include<bits/stdc++.h>
#ifndef _GRASS_H
#define _GRASS_H
#include"Creature.h"
using namespace std;
class Creature;
class Grass:public Creature{
    public:
        Grass():Creature(){type = 'I';}
        virtual ~Grass(){}
        virtual void opt(Creature **a, Creature **b);
};
#endif