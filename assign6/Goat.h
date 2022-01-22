#include<bits/stdc++.h>
#ifndef _GOAT_H
#define _GOAT_H
#include"Creature.h"
using namespace std;
class Creature;
class Goat:public Creature{
    public:
    Goat():Creature(){type='X';}
    virtual ~Goat(){}
    virtual void opt(Creature **a, Creature **b);
};
#endif