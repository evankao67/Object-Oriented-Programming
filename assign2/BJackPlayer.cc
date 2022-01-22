/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackPlayer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct. 5, 1998: Created.
***************************************************************************/

/* $Log: BJackPlayer.cc,v $
 * */

extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
#include "CardPat.h"
#include "BJackPlayer.h"

// default constructor: simply initialize the number of cards to 0

BJackPlayer::BJackPlayer(const char *player_name)
{
  points = 0;
  index = 0;
}

// start the black jack game with a new card
void BJackPlayer::start(int order)
{
  record[index] = order;
  index++;
  int realpoint = order / 4 + 1;
  if (realpoint >= 10)
    realpoint = 10;
  points += realpoint;
}

// add a new card to the current hand.
// need to protect the array from overflowing
void BJackPlayer::addCard(int order)
{
  record[index] = order;
  index++;
  int realpoint = order / 4 + 1;
  if (realpoint >= 10)
    realpoint = 10;
  points += realpoint;
}

// get the total points of the current hand in a black jack game
// cards with face vaules above 10 are treated as 10
// Ace's can be treated as 1 or 11 points

int BJackPlayer::totalPoints(void) const
{
  return points;
}

// set the status of the first card

void BJackPlayer::openFirstCard(bool show)
{
  showornot = show;
}

// print the current hand to the screen graphically

void BJackPlayer::showCards() const
{
  int rec = 0;
  int pr = rec;
  int flag = 0;
  if (index > 5)
    flag = 1;
  while (index - rec > 5) //print cards in the unit of 5
  {
    for (int j = 0; j < 11; j++)
    {
      if (flag == 1)
      {
        if (j == 0)
          cout << "P ";
        else if (j == 1)
          cout << "L ";
        else if (j == 2)
          cout << "A ";
        else if (j == 3)
          cout << "Y ";
        else if (j == 4)
          cout << "E ";
        else if (j == 5)
          cout << "R ";
        else
          cout << "  ";
      }
      else
      {
        cout << "  ";
      }
      for (int i = 0; i < 5; i++)
      {
        pr++;
        for (int k = 0; k < 11; k++)
        {
          if (!showornot && pr == 1)
          {
            char *ptr = new char;
            sprintf(ptr, "%c", card[13][j][k]);
            AnsiPrint(ptr, black, white, false, false);
          }
          else
          {
            if (card[record[pr - 1] / 4][j][k] != 'x') //color the rest without the 'x'
            {
              char *ptr = new char; //print colored cards
              sprintf(ptr, "%c", card[record[pr - 1] / 4][j][k]);
              if (record[pr - 1] % 4 == 0 || record[pr - 1] % 4 == 3) //balck goes to spade and club
              {
                AnsiPrint(ptr, black, white, false, false);
              }
              else //red goes to heart and diamond
              {
                AnsiPrint(ptr, red, white, false, false);
              }
              delete ptr;
            }
            else //replace the x with the right suit and color
            {
              char *ptr = new char;
              sprintf(ptr, "%c", suit[record[pr - 1] % 4]);
              if (record[pr - 1] % 4 == 0 || record[pr - 1] % 4 == 3)
              {
                AnsiPrint(ptr, black, white, false, false);
              }
              else
              {
                AnsiPrint(ptr, red, white, false, false);
              }
            }
          }
        }
        cout << ' ';
      }
      pr -= 5;
      puts("");
    }
    rec += 5;
    pr += 5;
    puts("");
  }

  for (int j = 0; j < 11; j++) //print the rest of the cards
  {
    if (flag == 0)
    {
      if (j == 0)
        cout << "P ";
      else if (j == 1)
        cout << "L ";
      else if (j == 2)
        cout << "A ";
      else if (j == 3)
        cout << "Y ";
      else if (j == 4)
        cout << "E ";
      else if (j == 5)
        cout << "R ";
      else
        cout << "  ";
    }
    else
    {
      cout << "  ";
    }
    for (int i = 0; i < index - rec; i++)
    {
      for (int k = 0; k < 11; k++)
      {
        if (!showornot && pr == 0 && !flag)
        {
          char *ptr = new char;
          sprintf(ptr, "%c", card[13][j][k]);
          AnsiPrint(ptr, black, white, false, false);
        }
        else
        {
          if (card[record[pr] / 4][j][k] != 'x')
          {
            char *ptr = new char;
            sprintf(ptr, "%c", card[record[pr] / 4][j][k]);
            if (record[pr] % 4 == 0 || record[pr] % 4 == 3)
            {
              AnsiPrint(ptr, black, white, false, false);
            }
            else
            {
              AnsiPrint(ptr, red, white, false, false);
            }
          }
          else //replace the x with the right suit
          {
            char *ptr = new char;
            sprintf(ptr, "%c", suit[record[pr] % 4]);
            if (record[pr] % 4 == 0 || record[pr] % 4 == 3)
            {
              AnsiPrint(ptr, black, white, false, false);
            }
            else
            {
              AnsiPrint(ptr, red, white, false, false);
            }
          }
        }
      }
      cout << ' ';
      pr++;
    }
    pr -= (index - rec);
    puts("");
  }
}
