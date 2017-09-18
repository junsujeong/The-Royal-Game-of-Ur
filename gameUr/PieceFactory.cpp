//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: Use factory design pattern to create a uniqie piece 
//---------------------------------------------------------------------
#include "PieceFactory.h"

Piece* PieceFactory::CreatePiece(GameType type, int player)
{
   Piece * pc = new Piece();
   Path * p;
   p = pg->GeneratePath(type, player);
   pc->SetPath(p);
   pc->SetPlayer(player);
   p = NULL;
   return pc;
}
