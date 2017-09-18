//----------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			   Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: This class maintains the dice values and rolls them.
//----------------------------------------------------------------------------
#include "RollDice.h"

RollDice::RollDice()
{
   dice1 = 0;
   dice2 = 0;
   dice3 = 0;
   dice4 = 0;
   totalDiceValue = 0;
   srand(time(NULL));
}

void RollDice::rollAllDice()
{
   dice1 = rand() % 2;
   dice2 = rand() % 2;
   dice3 = rand() % 2;
   dice4 = rand() % 2;
   //dice1 = dice2 = dice3 = 0;
   totalDiceValue = dice1 + dice2 + dice3 + dice4;

}

string RollDice::GetString()
{
   stringstream ss;
   ss << dice1;
   ss << dice2;
   ss << dice3;
   ss << dice4;
   string s = ss.str();
   return s;
}
