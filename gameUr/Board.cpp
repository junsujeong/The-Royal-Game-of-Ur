//----------------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Hold and move the pieces and cells contained within. 
//----------------------------------------------------------------------------------
#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLM; j++)
         BoardSpace[i][j] = new Cell();

   resetPiece = false;
   pieceDone = false;
   // each game optile corresponds to a rule and a tile. 
   int gameOptile2, gameOptile3, gameOptile4, gameOptile5, gameOptile6;
   gameOptile2 = gameOptile3 = gameOptile4 = gameOptile5 = gameOptile6 = 0;
}

void Board::ApplyRule(int row, int col, int ruleNo)
{
   BoardSpace[row][col]->SetTile(ruleNo);
}

int Board::DetermineRule(int row, int col)
{
   return BoardSpace[row][col]->GetRule();
}


void Board::Place(int row, int col, Piece *piece)
{
   BoardSpace[row][col]->PlacePiece(piece);
}

// This does not return the player number. Use IsOwnedByPlayer to find if tile piece is owned by a player
int Board::IsOccupied(int row, int col) 
{
   if (BoardSpace[row][col]->IsOccupied())
   {
      return 1; 
   }
   return 0;
}

Coordinate* Board::Move(int row, int col, int num)
{
   if (BoardSpace[row][col]->IsOccupied())
   {
      Piece * temp;  // a piece pointer.
      Coordinate * c; // a coordinate pointer.

      temp = BoardSpace[row][col]->Remove(); // hold the removed piece

      c = temp->MoveFront(num); // tells the piece to increment its movement, returns coordinates

      if (BoardSpace[c->GetRow()][c->GetCol()]->IsOccupied())
      {
         removedPiece = BoardSpace[c->GetRow()][c->GetCol()]->Remove();
         resetPiece = true;
         removedPiece->Restart();
      }
      BoardSpace[c->GetRow()][c->GetCol()]->PlacePiece(temp);
	  if (BoardSpace[c->GetRow()][c->GetCol()]->GetPiece()->Finished())
	  {
		  pieceDone = true;
		  delete BoardSpace[c->GetRow()][c->GetCol()]->Remove();
	  }
	  else
		  temp->Flip();
     
     return c;
   }
   return NULL;
}


bool Board::Remove(int row, int col)
{
   if (BoardSpace[row][col]->IsOccupied())  // Is there a piece to be removed?
   {
     removedPiece = BoardSpace[row][col]->Remove(); // There is, now we can remove it.
     if (removedPiece->Finished())
     {
        removedPiece = NULL;
        pieceDone = true;
     }
     else
        resetPiece = true;
	  return true;
   }
   return false;
}


// This is the destructor for board. 
Board::~Board()
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLM; j++)
         delete BoardSpace[i][j];
}

bool Board::PieceIsOwnedByPlayer(int row, int col, bool IsPlayer1) // Returns owner of piece in the board spot. If no piece, returns 0
{
   if (BoardSpace[row][col]->IsOccupied())
   {
      int playerNum = BoardSpace[row][col]->GetPiece()->GetPlayerNum();
      if(IsPlayer1)
         return playerNum == 1; // Check if the spot is occupied by the player given in the paramenter
      else
         return playerNum == 2;
   }
      
   return false;
}

bool Board::ValidPieceToMove(int row, int col, int num)
{
   Piece * p = BoardSpace[row][col]->GetPiece();
   if (p != NULL)
   {
      if (p->IsFaceDown())
         return false;
      Coordinate * futureC = p->PeakPath(num);
      if (futureC == NULL)
         return false;
      if (BoardSpace[futureC->GetRow()][futureC->GetCol()]->IsOccupied())
      {
         Piece * temp = BoardSpace[futureC->GetRow()][futureC->GetCol()]->GetPiece();
         if (temp->GetPlayerNum() == p->GetPlayerNum())
            return false;
      }
   }
   return true;
}

Piece * Board::GetRemovedPiece()
{
   if(resetPiece)
   {
      Piece * temp = removedPiece;
      removedPiece = NULL;
      resetPiece = false;
      return temp;
   }
   else
      return NULL;
}

bool Board::ValidTurn(int roll, bool IsPlayer1)
{
   for (int r = 0; r < ROWS; r++)
   {      for (int c = 0; c < COLM; c++)
      {
         if (PieceIsOwnedByPlayer(r, c, IsPlayer1))
         {
            if (ValidPieceToMove(r, c, roll))
               return true;
         }
      }
   }
   return false;
}

bool Board::IsDotsUp(int row, int col)
{
   return !BoardSpace[row][col]->GetPiece()->IsFaceDown();
}

void Board::FlipPiece(int row, int col)
{
   BoardSpace[row][col]->GetPiece()->Flip();
}

Board & Board::operator=(const Board & b)
{
   if (this != &b)
   {
      for (int i = 0; i < ROWS; i++)
		  for (int j = 0; j < COLM; j++)
			  BoardSpace[i][j] = new Cell(*b.BoardSpace[i][j]);

      resetPiece = b.resetPiece;
      pieceDone = b.pieceDone;
      removedPiece = b.removedPiece;
   }
   return *this;
}
