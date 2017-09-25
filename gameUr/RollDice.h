//----------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: This class maintains the dice values and rolls them.
//----------------------------------------------------------------------------
#ifndef  __ROLLDICE_H
#define __ROLLDICE_H

#include "RollDice.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>

using namespace std;
//---------------------------------------------------------------------
// This class maintains the dice values and rolls them.
//---------------------------------------------------------------------
class RollDice
{


public:
   //---------------------------------------------------------------------
   // This method constructs a dice.
   //---------------------------------------------------------------------
   RollDice();

   //---------------------------------------------------------------------
   // This method rolls each dice sequentally using a random number
   // 1 or 0, and sums their values.
   //---------------------------------------------------------------------
   void rollAllDice();

   //---------------------------------------------------------------------
   // Gets the sum of all the dice.
   //---------------------------------------------------------------------
   int getTotalValue() { return totalDiceValue; }

   //---------------------------------------------------------------------
   // Gets the "binary" string value of the four dice combination.
   //---------------------------------------------------------------------
   string GetString();

private:
   int totalDiceValue;
   int dice1, dice2, dice3, dice4;
};



#endif
