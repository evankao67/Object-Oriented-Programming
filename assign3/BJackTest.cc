/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardGame.cc
   PURPOSE
     Homework assignment for simulating card game
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "ConsoleMenu.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"
#include "BJackGame.h"

/**
 * Print my id 
 */

void PrintMyID(const char *studId)
{

  char *str = new char[sizeof(studId) + 5];
  sprintf(str, "ID: %s", studId);
  AnsiPrint(str, yellow, red, true, true);
  cout << endl
       << endl;
  delete[] str;
}

/**
 * PrintUsage
 */

void PrintUsage(const char *progName)
{

  assert(progName);
  cout << "Usage: " << progName << " [Seed] [nDecks]" << endl;
}

/**
 * Main Function Call
 */

int main(int argc, char **argv)
{

  int ndecks = 2; // number of cards to draw

  if (argc == 3)
  {
    long seed = atoi(argv[1]); // the first argument is the seed
    srand(seed);
    ndecks = atoi(argv[2]); // the second argument is the number of decks
  }
  else if (argc == 2)
  {
    if (argv[1][1] == 'h')
    {
      PrintUsage(argv[0]);
      exit(-1);
    }
    else
    {
      long seed = atoi(argv[1]); // the first argument is the seed
      srand(seed);
    }
  }
  else if (argc > 3)
  {
    PrintUsage(argv[0]);
    exit(-1);
  }
  // create an instance of player and dealer
  BJackPlayer bjplayer("Player");   //create a player
  BJackPlayer fakedealer("Dealer"); //create a dealer but with player type
  BJackDealer bjdealer(ndecks);     //create a dealer that copes with the rule of dealer
  BJackDealer fakeplayer(ndecks);   //create a dealer that copes with the rule of player
  // create an instance of the bj game with the given player an dealer
  BJackGame bjgame(bjplayer, fakedealer, fakeplayer, bjdealer); //so my game has 4 index to be initialized

  // play the game until the user quit
  while (bjgame.oneRun()) //run the game tile user presses 4
  {
    bjgame.menu.print();
    int k = bjgame.menu.getAnswer();
    bjgame.setopt(k);
    if (bjgame.getopt() == 1) //press 1 add card, but have to consider whether the game is running or not
    {
      if (!bjgame.getstatus()) //get the game's status. if not in the game, output the warning sign
      {
        cout << "game over! you have to start a new game, got it?" << endl;
        puts("");
      }
      else //if the game well functioned, run the "moreCard" function
      {
        bjgame.moreCard();
        bjplayer.showCards();
        fakedealer.showCards();
        if (bjplayer.totalPoints() > 21) //if the user decide to add card, but the points are over 21, the game instantly ended, and the user lose.
        {
          puts("");
          cout << "busto!! you greedy loser, press 3 if you wanna restart" << endl;
          fakeplayer.minus(); //minus player's point
          bjdealer.add();     //increse dealer's point
          cout << "you have " << fakeplayer.getpoint() << " points, and dealer has " << bjdealer.getpoint() << " points" << endl;
          puts("");
          bjgame.setstatus(false); //because the game ends, we need to set the game's status into false.
        }
        if(bjgame.getstatus()&&bjplayer.getncard()==5)
        {
          puts("");
          cout << "congrat! you pass the 5 cards challenge! ypo win!" << endl;
          fakeplayer.add(); //minus player's point
          bjdealer.minus();     //increse dealer's point
          cout << "you have " << fakeplayer.getpoint() << " points, and dealer has " << bjdealer.getpoint() << " points" << endl;
          puts("");
           bjgame.setstatus(false); //because the game ends, we need to set the game's status into false.
        }
      }
    }
    else if (bjgame.getopt() == 2) //when user decide to stop adding cards, that means dealer's job has started.
    {
      if (!bjgame.getstatus()) //again, check the game status first.
      {
        cout << "game over! you have to start a new game, got it?" << endl;
        puts("");
      }
      else
      {
        bjgame.enough();
        bjplayer.showCards();
        fakedealer.showCards();
      }
    }
    else if (bjgame.getopt() == 3) //start a new game
    {
      if (fakeplayer.getpoint() == 0) //when player lose all the point, end game
      {
        cout << "you are bankrupted! now you are a loser with no moeny! get away gambling!" << endl;
        break;
      }
      //cout<<bjdealer.getpoint();
      else if (bjdealer.getpoint() == 0) //when dealer lose all the point, end game.
      {
        cout << "you win! congrat!" << endl;
        break;
      }
      bjgame.restart();
      int index = 2; //give both player and dealer 2 cards first
      while(index--)
      {
        Card newcard(rand()%52);
        bjplayer.addCard(newcard);
        Card dealercard(rand()%52);
        fakedealer.addCard(dealercard);
      }
      fakedealer.openFirstCard();
      bjplayer.showCards();
      fakedealer.showCards();
    }
    else if (bjgame.getopt() == 4)//end game
    {
      break;
    }
    //cout << "kkk";
  }

  PrintMyID("109703030");
  return 0;
}