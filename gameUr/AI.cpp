//---------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Executes the moves for an AI player, which is based on the users 
//          selection of several Personality options. Is derived from Player.
//----------------------------------------------------------------------------
#include "AI.h"

AI::AI(Personality newDiff, Board* &currBoard) : Player(2)
{
   diff = newDiff;
   boardState = currBoard;
   IsPlayer1 = false;
}

AI::AI() : Player(2)
{
   diff = ADAM;
   IsPlayer1 = false;
}

AI::AI(Board *& currBoard) : Player(2)
{
   diff = ADAM;
   boardState = currBoard;
   IsPlayer1 = false;
}

void AI::AddPiece(Piece * pc)
{
   if (currMaxPieceCount > 0)
   {
      if (pieces.size() < currMaxPieceCount && pc->PeakPath(0) == NULL)
         pieces.push(pc);
      if (currPieces.size() < currMaxPieceCount && pc->PeakPath(1) != NULL)
         currPieces.push_back(pc);
   }
   else
   {
	  if(pc->PeakPath(0) == NULL)
		   pieces.push(pc);
     currPieces.push_back(pc);
   }
}

// Generates the coordinate of a piece AI wants to move. 
Coordinate * AI::GenerateMove(int roll)
{
   currPieces.sort();

   if (diff == ADAM)
      return GenerateAdamMove(roll);
   if (diff == ALEX)
      return GenerateAlexMove(roll);
   if (diff == ANIMAL)
      return GenerateAnimalMove(roll);
   if (diff == BAILEY)
      return GenerateBaileyMove(roll);
   if (diff == DAN)
      return GenerateDanMove(roll);
   if (diff == EDWARD)
      return GenerateEdwardMove(roll);
   if (diff == EVE)
      return GenerateEveMove(roll);
   if (diff == JUN)
      return GenerateJunMove(roll);
   if (diff == STORM)
      return GenerateStormMove(roll);
   else
      return NULL;
}

Coordinate * AI::GenerateAdamMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = PlacePiece();
   if (c != NULL)
      return c;
   c = MoveBackPiece(roll);
   return c;
}

Coordinate * AI::GenerateEveMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = PlacePiece();
   if (c != NULL)
      return c;
   c = MoveFrontPiece(roll);
   return c;
}

Coordinate * AI::GenerateStormMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = MoveBackPiece(roll);
   if (c != NULL)
      return c;
   c = PlacePiece();
   return c;
}

Coordinate * AI::GenerateAlexMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = MoveFrontPiece(roll);
   if (c != NULL)
      return c;
   c = PlacePiece();
   return c;
}

Coordinate * AI::GenerateJunMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = AttackFromBack(roll);
   if (c != NULL)
      return c;
   c = PlacePiece();
   if (c != NULL)
      return c;
   c = MoveBackPiece(roll);
   return c;
}

Coordinate * AI::GenerateEdwardMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = Score(roll);
   if (c != NULL)
      return c;
   c = AttackFromBack(roll);
   if (c != NULL)
      return c;
   c = PlacePiece();
   if (c != NULL)
      return c;
   c = MoveBackPiece(roll);
   return c;
}

Coordinate * AI::GenerateBaileyMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = Score(roll);
   if (c != NULL)
      return c;
   c = AttackFromFront(roll);
   if (c != NULL)
      return c;
   c = PlacePiece();
   if (c != NULL)
      return c;
   c = MoveFrontPiece(roll);
   if (c != NULL)
      return c;
   return c;
}

Coordinate * AI::GenerateDanMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = Score(roll);
   if (c != NULL)
      return c;
   c = AttackFromFront(roll);
   if (c != NULL)
      return c;
   if (roll < 2)
   {
      c = PlacePiece();
      if (c != NULL)
         return c;
   }
   c = MoveFrontPiece(roll);
   if (c != NULL)
      return c;
   c = PlacePiece();
   return c;
}

Coordinate * AI::GenerateAnimalMove(int roll)
{
   Coordinate * c;
   if (roll < 1)
      return NULL;
   c = MoveRandom(roll);
   if (c == NULL)
      c = PlacePiece();
   return c;
}


/*Place piece will attempt to place a piece in an empty starting location. If the player’s bowl is empty it
will return NULL. This is required for each AI to move to the next strategy call. The start location might
not be empty. If the place is not empty it will only place a piece there if it is occupied by an opponent.
If it is occupied by that player’s piece it will return NULL.*/
Coordinate * AI::PlacePiece()
{
   Coordinate * c;
   if (!pieces.empty()) // check to see if there are pieces in the AI's Bowl
   {
      c = (pieces.top()->PeakPath(1)); // gets the coordinates of the next spot (start position)
      if (boardState->PieceIsOwnedByPlayer(c->GetRow(), c->GetCol(), IsPlayer1)) // if an AI piece is in that spot. . .
         return NULL;
      else
         return new Coordinate(-1, -1);
   }
   return NULL;
}

Coordinate * AI::MoveBackPiece(int roll)
{
   Piece * p = GetBackPiece(roll);
   if (p != NULL)
      return p->PeakPath(0);
   return NULL;
}

Coordinate * AI::MoveFrontPiece(int roll)
{
   Piece * p = GetFrontPiece(roll);
   if (p != NULL)
      return p->PeakPath(0);
   return NULL;
}

Piece * AI::GetBackPiece(int roll)
{
   Piece * backP;
   for (list<Piece*>::iterator iter = currPieces.begin(); iter != currPieces.end(); iter++) // Flip iterators
   {
      backP = *iter;
      if (backP->PeakPath(0) != NULL)
         if (CanMove(backP, roll))
            return backP;

   }
   return NULL;
}

Piece * AI::GetFrontPiece(int roll)
{
   Piece * frontP;
   for (list<Piece*>::iterator iter = currPieces.begin(); iter != currPieces.end(); iter++)
   {
      frontP = *iter;
      if (frontP->PeakPath(0) != NULL)
         if (CanMove(frontP, roll))
            return frontP;
   }
   frontP = *currPieces.begin();
   if (frontP->PeakPath(0) != NULL)
      if (CanMove(frontP, roll))
         return frontP;
   return NULL;
}

Coordinate * AI::AttackFromBack(int roll)
{
   Piece * backAtkP;
   Coordinate * peak;
   Coordinate * c;
   for (list<Piece*>::iterator iter = currPieces.begin(); iter != currPieces.end(); iter++) // Flip iterators
   {
      backAtkP = *iter;
      peak = backAtkP->PeakPath(roll);
      c = backAtkP->PeakPath(0);
      if (c != NULL && c->GetRow() >= 0)
         if (CanMove(backAtkP, roll) && boardState->IsOccupied(peak->GetRow(), peak->GetCol()))
            return backAtkP->PeakPath(0);
   }
   return NULL;
}

Coordinate * AI::AttackFromFront(int roll)
{
   Piece * frontAtkP, target;
   Coordinate * peak;
   Coordinate * c;
   for (list<Piece*>::iterator iter = currPieces.begin(); iter != currPieces.end(); iter++)
   {
      frontAtkP = *iter;
      peak = frontAtkP->PeakPath(roll);
      c = frontAtkP->PeakPath(0);
      if (c != NULL && c->GetRow() >= 0)
         if (CanMove(frontAtkP, roll) && boardState->IsOccupied(peak->GetRow(), peak->GetCol()))
            return frontAtkP->PeakPath(0);
   }
   return NULL;
}

bool AI::CanMove(Piece * p, int roll)
{
   if (p->IsFaceDown())
      return false;
   Coordinate * futureC = p->PeakPath(roll);
   if (futureC == NULL || boardState->PieceIsOwnedByPlayer(futureC->GetRow(), futureC->GetCol(), IsPlayer1))
      return false;
   return true;
}

Coordinate * AI::MoveRandom(int roll)
{
   Piece * p = FindMoveRandom(roll);
   if (p != NULL)
      return p->PeakPath(0);
   return NULL;
}


Piece * AI::FindMoveRandom(int roll)
{
   int pos = rand() % currPieces.size();
   list<Piece*>::iterator iter = currPieces.begin();
   for (int i = 0; i < pos; i++)
      ++iter;

   Piece * p;

   while (iter != currPieces.end())
   {
      p = *iter;
      if (p->PeakPath(0) == NULL)
      {
         if (CanMove(p, 1))
            return p;
      }
      else
      {
         if (CanMove(p, roll))
            return p;
      }

      ++iter;
   }

   iter = currPieces.begin();
   for (int i = 0; i < pos - 1; i++)
   {
      p = *iter;
      if (p->PeakPath(0) == NULL)
      {
         if (CanMove(p, 1))
            return p;
      }
      else
      {
         if (CanMove(p, roll))
            return p;
      }

      ++iter;
   }
   return NULL;
}

Coordinate * AI::Score(int roll)
{
   list<Piece *>::iterator iter = currPieces.begin();
   Piece * p;
   Coordinate * end = NULL;
   while (iter != currPieces.end())
   {
      p = *iter;
      if (end == NULL)
         end = p->GetFinalPosition();
      if (p->PeakPath(roll) == end && CanMove(p, roll))
         return p->PeakPath(0);

      ++iter;
   }

   return NULL;
}

AI & AI::operator=(const AI & ai)
{
   if (this != &ai)
   {
      // For the player members of AI    
      playerNum = ai.playerNum;
      score = ai.score;
      currMaxPieceCount = ai.currMaxPieceCount;
      finalMaxPieceCount = ai.finalMaxPieceCount;

      // For the AI only members
      diff = ai.diff;
      IsPlayer1 = ai.IsPlayer1;
      boardState = new Board(*ai.boardState);

      Piece * p;

      while (!currPieces.empty())
      {
         if (!pieces.empty())
            pieces.pop();
         currPieces.pop_front();
      }

      for (int i = 0; i < ROWS; i++)
      {
         for (int j = 0; j < COLM; j++)
         {
            if (boardState->PieceIsOwnedByPlayer(i, j, false))
            {
               boardState->Remove(i, j);
               p = boardState->GetRemovedPiece();
               if (p != NULL)
               {
                  currPieces.push_back(p);
                  boardState->Place(i, j, p);
               }
            }
         }
      }

      while (currPieces.size() < currMaxPieceCount)
      {
         AddPiece(new Piece(*ai.pieces.top()));
      }
   }
   return *this;
}

AI::AI(AI & ai)
{
   *this = ai;
}
