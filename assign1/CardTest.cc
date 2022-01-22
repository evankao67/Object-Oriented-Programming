/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardTest.cc
   PURPOSE
     Testing card displaying
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
}

#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

/**
 * Print my id 
 */
void PrintMyID(const char *studId)
{

  char *str = new char[sizeof(studId) + 5];
  // we put string in a buffer first
  sprintf(str, "ID: %s", studId);
  // print the buffer out with color
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
  cout << "Usage: " << progName << " NCards [Seed]" << endl;
}

/**
 * Main Function Call
 */
int main(int argc, char **argv)
{

  int ncards = 0; // number of cards to draw
  if (argc == 3)
  {
    long seed = atoi(argv[2]); // the third argument is the seed
    srand(seed);
    ncards = atoi(argv[1]); // the second argument is the number of cards
  }
  else if (argc == 2)
  {
    ncards = atoi(argv[1]);
  }
  else
  {
    PrintUsage(argv[0]);
    exit(-1);
  }
  if (ncards > 52)
  {
    char *str = new char[100];
    // we put string in a buffer first
    sprintf(str, "Sorry, number of cards can not exceed 52.");
    // print the buffer out with color
    AnsiPrint(str, yellow, red, true, true);
    cout << endl
         << endl;
    delete[] str;
    return 0;
  }
  // You are asked to fill in a few missing statements here
  int arr[52];                         //array for cards
  char suit[4] = {'S', 'H', 'D', 'C'}; //array for suits
  for (int i = 0; i < 52; i++)         //set an array 0 to 51
  {
    arr[i] = i;
  }
  for (int i = 0; i < 52; i++) //randomly swap value 0 to 51
  {
    int tmp;
    int replace = rand() % (52 - i);
    tmp = arr[i];
    arr[i] = arr[replace + i];
    arr[replace + i] = tmp;
  }
  int record = 0;
  int pr = record;
  while (ncards - record > 5) //print cards in the unit of 5
  {
    for (int j = 0; j < 11; j++)
    {
      for (int i = 0; i < 5; i++)
      {
        pr++;
        for (int k = 0; k < 11; k++)
        {
          if (card[arr[pr - 1] / 4][j][k] != 'x') //color the rest without the 'x'
          {
            char *ptr = new char; //print colored cards
            sprintf(ptr, "%c", card[arr[pr - 1] / 4][j][k]);
            if (arr[pr - 1] % 4 == 0 || arr[pr - 1] % 4 == 3) //balck goes to spade and club
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
            sprintf(ptr, "%c", suit[arr[pr - 1] % 4]);
            if (arr[pr - 1] % 4 == 0 || arr[pr - 1] % 4 == 3)
            {
              AnsiPrint(ptr, black, white, false, false);
            }
            else
            {
              AnsiPrint(ptr, red, white, false, false);
            }
          }
        }
        cout << ' ';
      }
      pr -= 5;
      puts("");
    }
    record += 5;
    pr += 5;
  }
  for (int j = 0; j < 11; j++) //print the rest of the cards
  {
    for (int i = 0; i < ncards - record; i++)
    {
      for (int k = 0; k < 11; k++)
      {
        if (card[arr[pr] / 4][j][k] != 'x')
        {
          char *ptr = new char;
          sprintf(ptr, "%c", card[arr[pr] / 4][j][k]);
          if (arr[pr] % 4 == 0 || arr[pr] % 4 == 3)
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
          sprintf(ptr, "%c", suit[arr[pr] % 4]);
          if (arr[pr] % 4 == 0 || arr[pr] % 4 == 3)
          {
            AnsiPrint(ptr, black, white, false, false);
          }
          else
          {
            AnsiPrint(ptr, red, white, false, false);
          }
        }
      }
      cout << ' ';
      pr++;
    }
    pr -= (ncards - record);
    puts("");
  }
  // Print my id at the end of the program
  PrintMyID("109703030");
  return 0;
}
