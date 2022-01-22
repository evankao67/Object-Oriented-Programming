/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackGame.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

#include <iostream>
#include <cstdlib>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackGame.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
BJackGame::BJackGame(BJackPlayer &bjp, BJackPlayer &fkd, BJackDealer &fkp, BJackDealer &bjd) : bjplayer(bjp), fakedealer(fkd), fakeplayer(fkp), bjdealer(bjd), menu(sizeof(menuItems) / sizeof(char *), menuItems)
{
  status=false;
}

// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool BJackGame::oneRun()
{
    return true;
}

// give the player one more card
// check if we can do that first
void BJackGame::moreCard()
{
  Card poker(rand()%52);
  bjplayer.addCard(poker);
}

// give the dealer enough cards to try to win the player
// determine who win the game at the end
void BJackGame::enough()
{
  fakedealer.openFirstCard();
  while(true)
  {
    if(fakedealer.totalPoints()==bjplayer.totalPoints())
    {
      cout<<"it's a tie!"<<endl;
      cout<<"you have "<<fakeplayer.getpoint()<<" points, and dealer has "<<bjdealer.getpoint()<<" points"<<endl;
      status=false;
      break;
    }
    else if(fakedealer.totalPoints()>bjplayer.totalPoints()&&fakedealer.totalPoints()<=21)
    {
      cout<<"you lose, lmao! try harder next time"<<endl;
      fakeplayer.minus();
      bjdealer.add();
      cout<<"you have "<<fakeplayer.getpoint()<<" points, and dealer has "<<bjdealer.getpoint()<<" points"<<endl;
      status=false;
      break;
    }
    else if(fakedealer.totalPoints()>21)
    {
      cout<<"congrat! you win! what an effort!"<<endl;
      bjdealer.minus();
      fakeplayer.add();
      cout<<"you have "<<fakeplayer.getpoint()<<" points, and dealer has "<<bjdealer.getpoint()<<" points"<<endl;
      status=false;
      break;
    }
    Card poker(rand()%52);
    fakedealer.addCard(poker);
  }
}

// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void BJackGame::restart()
{
  bjplayer.start();
  fakedealer.start();
  status=true;
}
