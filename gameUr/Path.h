//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: Hold a set of Coordinates that determines the movement
// of a piece. Let piece move along path.
//---------------------------------------------------------------------

#ifndef  __PATH_H
#define __PATH_H

#include "Coordinate.h"
#include <cstddef>
#include <vector>

using namespace std;

// -------------------------------------------------------------------
// Maintain ordered list of Coordinates.
// -------------------------------------------------------------------
class Path
{
public:
   // -------------------------------------------------------------------
   // Constructor: Create a path instance.
   // -------------------------------------------------------------------
   Path();

   // -------------------------------------------------------------------
   // Move number of steps backwards or forwards in the path and 
   // return the resulting Coordinate. Returns NULL if no path exists
   // or out of bounds.
   // -------------------------------------------------------------------
   Coordinate* Move(int num);

   // -------------------------------------------------------------------
   // Add a Coordinate to the end of the path.
   // -------------------------------------------------------------------
   void AddStep(Coordinate* c);

   // -------------------------------------------------------------------
   // Reset the path to the intial state and returns the resulting 
   // Coordinate.
   // -------------------------------------------------------------------
   Coordinate* Reset();

   // -------------------------------------------------------------------
   // Destructor: Not needed.
   // -------------------------------------------------------------------
   ~Path();

   // -------------------------------------------------------------------
   // Assignment Overload: Sets path equal to given path by copying its 
   // contents.
   // -------------------------------------------------------------------
   Path& operator=(const Path& path);

   // -------------------------------------------------------------------
   // Checks if the current position is the final position.
   // -------------------------------------------------------------------
   bool Finished();

   //----------------------------------------------------------------------------
   // Return the position of the piece as if it were moved by the given 
   // number of spaces.
   //----------------------------------------------------------------------------
   Coordinate * Peak(int num); 
   
   //----------------------------------------------------------------------------
   // Overloads the less than operator by comparing the position
   //----------------------------------------------------------------------------
   bool operator<(const Path & p);

   //----------------------------------------------------------------------------
   // Overloads the greater than operator by comparing the position
   //----------------------------------------------------------------------------
   bool operator>(const Path & p);

   //----------------------------------------------------------------------------
   // Returns the final position
   //----------------------------------------------------------------------------
   Coordinate * GetFinalPosition() { return steps[steps.size() - 1]; }

   // -------------------------------------------------------------------
   // Copy Constructor: Instantiates a path as a copy of the given path
   // (Calls on assignment overload).
   // -------------------------------------------------------------------
   Path(const Path& p) { *this = p; }


private:
   vector<Coordinate*> steps; // Coordinates are not owned by path
   int pos;
};


#endif