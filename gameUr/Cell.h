//----------------------------------------------------------------------------
// Name:    Team C--: David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: Create cell objects to hold a piece.
//----------------------------------------------------------------------------
#ifndef  __CELL_H
#define __CELL_H

#include "Piece.h"
//---------------------------------------------------------------------
// This class creates cell objects that hold a piece.
//---------------------------------------------------------------------
class Cell
{
public:
   //---------------------------------------------------------------------
   // Constructs a defualt cell.
   //---------------------------------------------------------------------
   Cell();

   //---------------------------------------------------------------------
   // Tags a tile with a particular rule number. 
   //---------------------------------------------------------------------
   void SetTile(int x);

   //---------------------------------------------------------------------
   // Returns the tile rule number from the tile. 
   //---------------------------------------------------------------------
   int GetRule();


   //---------------------------------------------------------------------
   // Places a given piece in a cell.
   //---------------------------------------------------------------------
   void PlacePiece(Piece *p);

   //---------------------------------------------------------------------
   // Checks to see if the given space is occupied.
   //---------------------------------------------------------------------
   bool IsOccupied();

   //---------------------------------------------------------------------
   // Removes a piece from the cell and returns the piece removed.
   //---------------------------------------------------------------------
   Piece* Remove();

   //---------------------------------------------------------------------
   // Gets the piece in the cell.
   //---------------------------------------------------------------------
   Piece* GetPiece();

   //---------------------------------------------------------------------
   // Destructs the cell.
   //---------------------------------------------------------------------
   ~Cell();

   //---------------------------------------------------------------------
   // Operator Overloading
   //---------------------------------------------------------------------
   Cell& operator=(const Cell& c);

   //---------------------------------------------------------------------
   // Copy Constructor
   //---------------------------------------------------------------------
   Cell(const Cell& c) { *this = c; }

private:
   bool taken;
   Piece *pc;
   int tile;
   const int FLIP_ALL_PIECES = 2; //triggers a call to flip all pieces
   const int TAKE_EXTRA_TURN = 3; //instead of switching players it gives extra roll
   const int SAFE = 4; //it is not legal to move into this slot if occupied
   const int FLIP_THIS_PIECE = 5; //piece flips back to dots up
   const int SUICIDE = 6; // this piece dies (so sad). 
   const int PLACE_PIECE = 7; // places a piece if possible. 
   const int MOVE_BACKWARDS = 8; //Roll again and move backwards
   const int SAFE_AND_ROLL = 9; // safe rule + roll again rule
   const int BLANK = 1; // All default rules.
};


#endif
