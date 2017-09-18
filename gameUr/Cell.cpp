//----------------------------------------------------------------------------
// Name:    Team C--: David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: Create cell objects to hold a piece.
//----------------------------------------------------------------------------
#include "Cell.h"

Cell::Cell()
{
   taken = false;
   pc = NULL;
   tile = 0;
}

void Cell::SetTile(int x)
{
   tile = x;
}

int Cell::GetRule()
{
   return tile;
}

void Cell::PlacePiece(Piece *p)
{
   if (!taken)
   {
      pc = p;
      taken = true;
   }
   else
   {
      //pc->Restart();
      pc = p;
   }

}

bool Cell::IsOccupied()
{
   return taken;
}

Piece* Cell::Remove()
{
   taken = false;
   Piece * temp = pc;
   pc = NULL;
   return temp;
}

Piece * Cell::GetPiece()
{
   if (taken)
      return pc;
   return NULL;
}


Cell::~Cell()
{
   delete pc;
}

Cell & Cell::operator=(const Cell & c)
{
   if (this != &c)
   {
      taken = c.taken;
      if (c.pc != NULL)
         pc = new Piece(*c.pc);
      else
         pc = c.pc;
   }
   return *this;
}
