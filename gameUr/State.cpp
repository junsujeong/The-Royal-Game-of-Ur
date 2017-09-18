#include "State.h"

State::State(Board * b, Player * p1, Player * p2, GameType gt, bool turn)
{
   currBoard = b;
   currP1 = p1;
   currP2 = p2;
   game = gt;
   ai = NULL;
   player1Turn = turn;
   singlePlayer = false;
}

State::State(Board * b, Player * p1, AI * a, GameType gt, Personality p, bool turn)
{
   currBoard = b;
   currP1 = p1;
   currP2 = NULL;
   game = gt;
   ai = a;
   player1Turn = turn;
   per = p;
   singlePlayer = true;
}

Player * State::GetPlayer(bool player1)
{
   if (player1)
      return currP1;
   return currP2;
}

State & State::operator=(const State & s)
{
   if (this != &s)
   {
      delete currBoard, currP1, currP2;
      *currBoard = *s.currBoard;
      *currP1 = *s.currP1;
      *currP2 = *s.currP2;
      game = s.game;
      per = s.per;
      ai->UpdateBoard(currBoard);
      *ai = *s.ai;
   }
   return *this;
}