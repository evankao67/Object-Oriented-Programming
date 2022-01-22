#include "World.h"
int x[4]{0, 0, 1, -1};
int y[4]{1, -1, 0, 0};
World::World(int Pass, int Seed)
{
    aimpass = Pass;
    seed = Seed;
    RandomNum New(seed);
    pass = 0;
    map = new Creature **[25];
    for (int i = 0; i < 25; i++)
        map[i] = new Creature *[40];
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            map[i][j] = NULL;
        }
    }
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            check[i][j] = false;
        }
    }
}
void World::mainLoop(int interval)
{
    for (int i = 0; i < aimpass; i++)
    {
        pass = i;
        if (i == 0)
            start();
        else
            evolve();
        if (i % interval == 0)
        {
            printmap();
            cout<<"the number of passes "<<pass<<endl;
        }
    }
}
void World::printmap()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (i == 0 && j == 0)
                cout << ' ';
            if (i == 0 && (j != 35))
                cout << ' ' << j % 10;
            else if (j == 0)
                cout << (i - 1) % 10;
            else
            {
                if (j != 35 || i != 0)
                {
                    if (map[i][j] != NULL)
                    {
                        if(map[i][j]->type=='I')
                        {
                            AnsiPrint(" ",black,black,false,false);
                            AnsiPrint("I",green,black,false,false);
                        }
                        else
                        {
                            AnsiPrint("I",black,black,false,false);
                            AnsiPrint("X",white,black,false,false);
                        }
                    }
                    else
                        AnsiPrint("  ",black,black,false,false);
                }
            }
        }
        puts("");
    }
    for (int i = 0; i < 71; i++)
    {
        cout << '-';
    }
    puts("");
}
void World::evolve()
{
    for (int i = 1; i < 21; i++) //intitial creature status, so the newborn creature will not get action
    {
        for (int j = 1; j < 36; j++)
        {
            if (map[i][j] != NULL)
                map[i][j]->status = 0;
        }
    }
    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j < 36; j++)
        {
            if (map[i][j] != NULL) //not null
            {

                if (map[i][j]->type == 'I' && map[i][j]->status == 0)
                {
                    //cout<<map[i][j]->type<<' '<<map[i][j]->point<<' '<<i<<' '<<j<<endl;
                    map[i][j]->age += 1;
                    Creature **ptr;
                    int random = New.getRandomNum(0, 3);
                    ptr = &(map[i + x[random]][j + y[random]]);
                    if (map[i][j]->age > 6)
                    {
                        delete map[i][j];
                        map[i][j] = NULL;
                    }
                    else if (*ptr == NULL)
                    {
                        map[i][j]->opt(&map[i][j], ptr);
                        map[i][j]->status = 1;
                    }
                }
                else if (map[i][j]->type == 'X' && map[i][j]->status == 0)
                {
                    //cout << map[i][j]->type << ' ' << map[i][j]->point << ' ' << i << ' ' << j << endl;
                    map[i][j]->age += 1;
                    map[i][j]->point -= 1;
                    Creature **ptr;
                    int random = New.getRandomNum(0, 3);
                    int xway = i + x[random];
                    int yway = j + y[random];
                    ptr = &(map[xway][yway]);
                    if (map[i][j]->point <= 0 || map[i][j]->age > 70)
                    {
                        delete map[i][j];
                        map[i][j] = NULL;
                    }
                    else if (*ptr != NULL)
                    {
                        if (map[xway][yway]->type == 'I') //goat's next step is grass
                        {
                            if (map[i][j]->age > 50 && map[i][j]->age < 56) //goat's pregenent, eat grass and not move
                            {
                                delete map[xway][yway];
                                map[xway][yway] = NULL;
                            }
                            else//normal situation
                            {
                                delete map[xway][yway];
                                map[xway][yway] = map[i][j];
                                map[i][j] = NULL;
                                map[xway][yway]->point += 5;
                                map[xway][yway]->status = 1;
                            }
                        }
                    }
                    else if (*ptr == NULL && xway > 0 && xway < 21 && yway > 0 && yway < 36)
                    {
                        map[i][j]->opt(&map[i][j], ptr);
                    }
                }
            }
        }
    }
}
void World::start()
{
    //cout<<New.getRandomNum(1,21);
    int sum = 0;
    while (sum < 5)
    {

        int a = New.getRandomNum(1, 20);
        int b = New.getRandomNum(1, 35);
        if (check[a][b] == true)
            continue;
        Goat *tmp = new Goat;
        map[a][b] = tmp;
        check[a][b] = true;
        sum++;
    }
    sum = 0;
    while (sum < 10)
    {

        int a = New.getRandomNum(1, 20);
        int b = New.getRandomNum(1, 35);
        if (check[a][b] == true)
            continue;
        Grass *tmp = new Grass;
        map[a][b] = tmp;
        check[a][b] = true;
        sum++;
    }
}