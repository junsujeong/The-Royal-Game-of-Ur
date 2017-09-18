#include "../gameUr/Path.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main()
{
   //PathTestBed tests if it 
   Path * p = new Path();
   Coordinate * step = new Coordinate();
   

   //Test Reset when step size is 0 
   assert(p->Reset() == NULL);
   
   //add coordinates to end of path
   
   
   p->AddStep(step);
   step = p->Move(0);
   
   assert(step->GetCol() == -1);
   assert(step->GetRow() == -1);

   for (int i = 0; i < 10; i++)
   {
      step = new Coordinate(0, i);
      p->AddStep(step);
   }

   //move the piece along with the path
   for (int i = 0; i < 5; i++)
   {
      step = p->Move(1);
      cout << step->GetRow() << " , " << step->GetCol() << endl;
   }

   Coordinate * c = new Coordinate();
   Coordinate * cb = new Coordinate();
   
   assert(p->Peak(-10) == NULL);

   //move front
   c = p->Move(3);

   //check to see if the piece moved front
   assert(c->GetRow() >= 0);
   assert(c->GetCol() >= 0);
   
   //move back
   cb = p->Move(-1);
   
   //Check to see if the piece moved back
   assert(c->GetRow() == cb->GetRow());
   assert(c->GetCol() > cb->GetCol());

   //Test operator overload < and >
   Path * p2 = new Path();
   p2->AddStep(step);
   assert(p->operator>(*p2));
   assert(p2->operator<(*p));

   
   //reset the piece to initial state
   c = p->Reset();
   //Try  operator overloading = 
   Path * copy = new Path(*p);
   //Get coordinate of p2
   cb = copy->Move(0);

   //Test to see if the coordinate resets
   assert(c->GetRow() < 0);
   assert(c->GetCol() < 0);

   //Test operator overloading
   assert(cb->GetRow() < 0);
   assert(cb->GetCol() < 0);

   
   //Test if the p is not finished
   assert(!p->Finished());


  
   delete p, c, cb;
   return 0;
}