#include<iostream>
using namespace std;
#ifndef _CREATURE_H
#define _CREATURE_H
class Creature{
    public:
        int age;
        int status;
        int point;
        char type;//0 is none, 1 is goat, -1 is grass
        Creature():age(0), status(0), point(20), type('N'){}
        virtual void opt(Creature **a, Creature **b)=0;
        virtual ~Creature(){}
};
#endif