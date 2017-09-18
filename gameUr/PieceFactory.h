//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: Use factory design pattern to create a uniqie piece 
//---------------------------------------------------------------------

#ifndef __PIECEFACTORY_H_
#define __PIECEFACTORY_H_

#include "Piece.h"
#include "PathGenerator.h"

//---------------------------------------------------------------------
// Create a piece.
//---------------------------------------------------------------------
class PieceFactory
{
public:
   //---------------------------------------------------------------------
   // Constructor: Instantiate a PieceFactory by creating a new path 
   // generator
   //---------------------------------------------------------------------
	PieceFactory() { pg = new PathGenerator(); }

   //---------------------------------------------------------------------
   // Create a piece by linking path and a piece and returns the 
   // generated piece
   //---------------------------------------------------------------------
   Piece* CreatePiece(GameType type, int player);

   //---------------------------------------------------------------------
   // Destrcutor: Delete the path generator
   //---------------------------------------------------------------------
   ~PieceFactory() { delete pg; }

private:
	PathGenerator* pg;
};


#endif
