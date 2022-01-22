#include<bits/stdc++.h>
#ifndef _WORLD_H
#define _WORLD_H
#include "AnsiPrint.h"
#include"Creature.h"
#include"RandomNum.h"
#include "Grass.h"
#include "Goat.h"
using namespace std;
class World{
    public:
        World(int Pass, int Seed);
        void mainLoop(int Interval);
        void printmap();
        void evolve();
        void start();
    private:
        Creature ***map;
        RandomNum New;
        bool check[25][40];
        int pass;
        int aimpass;
        int seed;
};
#endif