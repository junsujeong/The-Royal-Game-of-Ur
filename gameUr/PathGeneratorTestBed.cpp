#include "../gameUr/PathGenerator.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main()
{
   ///Creates a new path generator and two paths to test
   PathGenerator * pg = new PathGenerator();
   Path * p = NULL;
   Path * p2 = NULL;

   ///Creates the two possible paths that can be created
   p2 = pg->GeneratePath(Chariot, 2);
   p = pg->GeneratePath(Chariot, 1);

   ///Test to make sure the paths are no longer null
   assert(p != NULL);
   assert(p2 != NULL);

   delete p, p2;

   p = pg->GeneratePath(Race, 1);
   p2 = pg->GeneratePath(Race, 2);

   assert(p != NULL);
   assert(p2 != NULL);

   delete p, p2;
   delete pg;
   return 0;
}