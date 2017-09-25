//----------------------------------------------------------------------------
// Name:    Team C--: David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: The entire purpose of this method is simply to return a row and a 
//				column ie. the coordinates of an array. 
//----------------------------------------------------------------------------

#include "Coordinate.h"

Coordinate::Coordinate(const Coordinate & cd)
{
   *this = cd;
}

Coordinate & Coordinate::operator=(const Coordinate & cd)
{
   if (this != &cd)
   {
      r = cd.r;
      c = cd.c;
   }
   return *this;
}

bool Coordinate::operator==(const Coordinate & cd)
{
   return r == cd.r && c == cd.c;
}
