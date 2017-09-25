#include "MoveCommand.h"

MoveCommand::MoveCommand()
{
   oldState = NULL;
   newState = NULL;
}

Coordinate * MoveCommand::execute(State * & s, int roll, Coordinate * c)
{
   if (newState != NULL)
   {
      s = newState;
      return NULL;
   }
   oldState = s;
   Board * tempBoard = new Board(*oldState->GetCurrBoard());
   Player * tempP1 = new Player(*oldState->GetPlayer(true));
   Player * tempP2 = NULL;
   AI * ai = NULL;
   GameType game = s->GetGameType();
   bool currPlayer1Turn = s->GetPlayer1Turn();

   int row = c->GetRow();
   int col = c->GetCol();
   Coordinate* cr = NULL;

   if (oldState->GetGameMode()) // True if single player
   {
      ai = new AI(*oldState->GetAI());
      tempP2 = ai;
   }  
   else
      tempP2 = new Player(*oldState->GetPlayer(false));

   if (row < 0 || col < 0)
   {
      if (currPlayer1Turn)
         cr = PlacePiece(tempP1, tempBoard);
      else
         cr = PlacePiece(tempP2, tempBoard);
      currPlayer1Turn = !currPlayer1Turn;
   }
   else
   {

      if (tempBoard->IsOccupied(row, col))
      {
         if (tempBoard->PieceIsOwnedByPlayer(row, col, currPlayer1Turn))
         {
            if (tempBoard->ValidPieceToMove(row, col, roll))
            {
               {
                  cr = tempBoard->Move(row, col, roll);
                  if (tempBoard->PieceWasRemoved())
                  {
                     Piece * temp = tempBoard->GetRemovedPiece();
                     if (temp->IsFaceDown())
                        temp->Flip();
                     if (temp->GetPlayerNum() == 1)
                        tempP1->AddPiece(temp);
                     else
                        tempP2->AddPiece(temp);
                  }
                  if (cr != NULL)
                  {
                     if (tempBoard->IsPieceDone())
                     {
                        if (currPlayer1Turn)
                           tempP1->IncreaseScore();
                           
                        else
                           tempP2->IncreaseScore();
                     }
                     currPlayer1Turn = !currPlayer1Turn;
                  }
               }
            }
         }
      }
   }
   if (cr != NULL)
   {
      if(ai == NULL)
         newState = new State(tempBoard, tempP1, tempP2, game, currPlayer1Turn);
      else
         newState = new State(tempBoard, tempP1, ai, game, ai->GetPersonality(), currPlayer1Turn);
      s = newState;
   }
   else
      oldState = NULL;
      
   return cr;
}

State * MoveCommand::unexecute()
{
   return oldState;
}

Coordinate * MoveCommand::PlacePiece(Player * & pl, Board * & b)
{
   Piece * p;
   Coordinate * c;
   p = pl->RequestPiece();
   if (p != NULL && !b->IsOccupied(p->PeakPath(1)->GetRow(), p->PeakPath(1)->GetCol()))
   {
      c = p->MoveFront(1);
      b->Place(c->GetRow(), c->GetCol(), p);
   }
   else
   {
      c = NULL;
      if (p != NULL)
      {
         pl->AddPiece(p);
      }
   }
   return c;
}
