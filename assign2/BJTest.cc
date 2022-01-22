/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJTest.cc
   PURPOSE
     Homework assignment for simulating card game
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 5, 1998: Created.
***************************************************************************/

/* $Log: BJTest.cc,v $
 * */

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
#include "BJackPlayer.h"

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
  cout << "Usage: " << progName << " [Seed] [ShowFirst(0/1)]" << endl;
}

/**
 * Main Function Call
 */

int main(int argc, char **argv)
{

  bool showFirst = false;
  long seed = 0;

  if (argc > 3)
  {
    PrintUsage(argv[0]);
    exit(-1);
  }
  if (argc == 3)
  {
    showFirst = atoi(argv[2]); // the third argument shows the first card
  }
  if (argc > 1)
  {
    seed = atoi(argv[1]);
  }
  srand(seed);

  BJackPlayer bjplayer("BJPlayer");
  bjplayer.openFirstCard(showFirst);
  int order = rand() % 52;
  bjplayer.start(order);
  Card Handsome_Evan(order);
  int pointnow = bjplayer.totalPoints();
  //cout<<pointnow<<endl;
  while (pointnow <= 21)
  {
    order = rand() % 52;
    bjplayer.start(order);
    Card Handsome_Evan(order);
    pointnow = bjplayer.totalPoints();
    //cout<<pointnow<<endl;
  }
  bjplayer.showCards();
  puts("");
  cout << "Total points: " << pointnow << endl;
  PrintMyID("109703030");

  return 0;
}
