//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: Hold a set of Coordinates that determines the movement
// of a piece. Let piece move along path.
//---------------------------------------------------------------------
#include "Path.h"

Path::Path()
{
   pos = 0;
}

Coordinate* Path::Move(int num)
{
   if (num == 0 && steps.size() > 0)
      return steps[pos];
   Coordinate * c = Peak(num);
   if (c != NULL)
         pos += num;
   return c;
}

void Path::AddStep(Coordinate* c)
{
   steps.push_back(c);
}

Coordinate* Path::Reset()
{
   if (steps.size() == 0)
      return NULL;
   pos = 0;
   return steps[pos];
}

Path::~Path()
{
}

Path & Path::operator=(const Path & path)
{
   if (this != &path)
   {
      steps = path.steps;
      pos = path.pos;
   }
      
   return *this;
}

bool Path::Finished()
{
   return pos == (steps.size() - 1);
}

Coordinate * Path::Peak(int num)
{
   if (pos + num > steps.size() - 1 || pos + num < 1)
      return NULL;
   return steps[pos + num];
}

bool Path::operator<(const Path & p)
{
   return pos < p.pos;
}

bool Path::operator>(const Path & p)
{
   return pos > p.pos;
}
