//---------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Hold and move the pieces and cells contained within. 
//----------------------------------------------------------------------------

#ifndef  __BOARD_H
#define __BOARD_H

#include "Cell.h"

//----------------------------------------------------------------------------
// The purpose of board is to hold and move the pieces and cells contained 
// within. 
//----------------------------------------------------------------------------
class Board
{
public:
   
	//----------------------------------------------------------------------------
	// The constructor for Board
	//----------------------------------------------------------------------------
   Board();


   //---------------------------------------------------------------------
   // takes a rule number from gui and tags a tile with this rule 
   //---------------------------------------------------------------------
   void ApplyRule(int x, int y, int ruleNo);

   //---------------------------------------------------------------------
   // finds out what rule is on this tile. 
   //---------------------------------------------------------------------
   int DetermineRule(int row, int col);

	//----------------------------------------------------------------------------
	// Places a piece in the board
	//----------------------------------------------------------------------------
   void Place(int row, int col, Piece *piece);

   //----------------------------------------------------------------------------
   // Checks if a cell has a piece in it and returns true only if there is a
   // piece in the cell
   //----------------------------------------------------------------------------
   int IsOccupied(int row, int col);

	//----------------------------------------------------------------------------
	// This method moves the piece along its path.
	//----------------------------------------------------------------------------
   Coordinate* Move(int row, int col, int num);

	//----------------------------------------------------------------------------
	// Attempts to remove a piece provided that there is a 
	// piece that can be removed. Return false if it cannot be removed.
	//----------------------------------------------------------------------------
   bool Remove(int row, int col);

	//----------------------------------------------------------------------------
	// Destructor for board
	//----------------------------------------------------------------------------
   ~Board();

   //----------------------------------------------------------------------------
   // Checks to see if the piece in the given row and column is owned by 
   // the player. Returns true only if their is a piece in the given
   // position is owned by the given player
   //----------------------------------------------------------------------------
   bool PieceIsOwnedByPlayer(int row, int col, bool IsPlayer1);

   //----------------------------------------------------------------------------
   // Makes sure the piece in the given space is flipped and the next space is
   // not taken by a piece of the same player. Checks if move is valid.
   //----------------------------------------------------------------------------
   bool ValidPieceToMove(int row, int col, int num);

   //----------------------------------------------------------------------------
   // Checks if a piece was removed this turn
   //----------------------------------------------------------------------------
   bool PieceWasRemoved() { return resetPiece; }

   //----------------------------------------------------------------------------
   // Checks if the piece is done with turn
   //----------------------------------------------------------------------------
   bool IsPieceDone() { return pieceDone; }

   //----------------------------------------------------------------------------
   // Gets the piece that was removed if one was removed
   //----------------------------------------------------------------------------
   Piece * GetRemovedPiece();

   //----------------------------------------------------------------------------
   // Resets the the value of piece is done to false
   //----------------------------------------------------------------------------
   void ResetIsPieceDone() { pieceDone = false; }

   //----------------------------------------------------------------------------
   // Check if there is valid move
   //----------------------------------------------------------------------------
   bool ValidTurn(int roll, bool IsPlayer1);

   //----------------------------------------------------------------------------
   // Checks if a piece is dots up.
   // Precondition: The cell is occupied.
   //----------------------------------------------------------------------------
   bool IsDotsUp(int row, int col);

   //----------------------------------------------------------------------------
   // Flip a piece up.
   // Precondition: The cell is occupied.
   //----------------------------------------------------------------------------
   void FlipPiece(int row, int col);

   //----------------------------------------------------------------------------
   // Operator Overloading
   //----------------------------------------------------------------------------
   Board& operator=(const Board& b);

   //----------------------------------------------------------------------------
   // Copy constructor
   //----------------------------------------------------------------------------
   Board(const Board& b) { *this = b; }

private:
   static const int ROWS = 3;
   static const int COLM = 8;
   static const int START_ROW = -1;
   static const int START_COL = -1;
   static const int TOTAL_TILES = ROWS * COLM;
   static const int RULE_FLIP_ME_UP = 2;
   static const int RULE_FLIP_ALL_UP = 3;
   static const int RULE_SAFE = 4;
   static const int RULE_MOVE_AGAIN = 5;
   static const int RULE_RETURN_TO_BOWL = 6;

   Cell * BoardSpace[3][8];

   bool resetPiece;
   bool pieceDone;
   Piece * removedPiece;
};



#endif // ! __BOARD_H
