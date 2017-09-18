//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Use factory design pattern to generate a requested path.
//---------------------------------------------------------------------
#include "Piece.h"
/*
Piece::Piece(const Piece& p)
{
   *this = p;
}*/

Piece & Piece::operator=(const Piece & p)
{
   if (this != &p)
   {
      //delete path;
      path = new Path(*p.path);
      playerNum = p.playerNum;
      faceDown = p.faceDown;
   }
   return *this;
}

bool Piece::operator<(const Piece & p)
{
   return *path < *(p.path);
}

bool Piece::operator>(const Piece & p)
{
   return *path > *(p.path);
}