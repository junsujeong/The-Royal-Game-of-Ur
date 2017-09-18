//----------------------------------------------------------------------------
// Name:    Team C--: David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: The entire purpose of this method is simply to return a row and a 
//				column. ie. the coordinates of an array. 
//----------------------------------------------------------------------------

#ifndef __COORDINATE_H_
#define __COORDINATE_H_

//----------------------------------------------------------------------------
// The entire purpose of this method is simply to return a row and a 
//	column. ie. the coordinates of an array. 
//----------------------------------------------------------------------------
class Coordinate
{
public:
   //---------------------------------------------------------------------
   // Constructs a coordinate using the given input row and column,
   // otherwise the row and column are set to (-1, -1)
   //---------------------------------------------------------------------
   Coordinate(int row = -1, int col = -1) : r(row), c(col) {}

   //---------------------------------------------------------------------
   // Gets the row index.
   //---------------------------------------------------------------------
   int GetRow() { return r; }

   //---------------------------------------------------------------------
   // Gets the column index.
   //---------------------------------------------------------------------
   int GetCol() { return c; }

   //---------------------------------------------------------------------
   // Destructs the coordinate.
   //---------------------------------------------------------------------
   ~Coordinate() {}

   //---------------------------------------------------------------------
   // Copies constructor for the coordinate.
   //---------------------------------------------------------------------
   Coordinate(const Coordinate& cd);

   //---------------------------------------------------------------------
   // Overides the equals operator.
   //---------------------------------------------------------------------
   Coordinate & operator=(const Coordinate& cd);

   //---------------------------------------------------------------------
   // Operator overloading
   //---------------------------------------------------------------------
   bool operator==(const Coordinate& cd);

private:
   int r;
   int c;
};

#endif // !__COORDINATE_H_