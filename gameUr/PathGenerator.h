//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Use factory design pattern to generate a requested path.
//---------------------------------------------------------------------

#ifndef __PATHGENERATOR_H_
#define __PATHGENERATOR_H_

#include "Path.h"
#include "GameType.h"

const int CHARIOT_STEPS = 15;
const int RACE_STEPS = 28;


// -------------------------------------------------------------------
// Maintain ordered list of Coordinates and use it to create a path
// for a given game mode and player.
// -------------------------------------------------------------------
class PathGenerator
{
public:
   // -------------------------------------------------------------------
   // Constructor: Instantiate a path generator.
   // -------------------------------------------------------------------
   PathGenerator() { currPath = NULL; }

   // -------------------------------------------------------------------
   // Create a path that follows given gametype and player and returns
   // it. Calls on helper methods.
   // -------------------------------------------------------------------
	Path* GeneratePath(GameType type, int player);

   // -------------------------------------------------------------------
   // Destructor: Delete all Coordinates arrays.
   // -------------------------------------------------------------------
	~PathGenerator();

private:
   // -------------------------------------------------------------------
   // Helper method: Creates a Chariot game type path.
   // -------------------------------------------------------------------
	Path* GenerateChariotPath(int player);

   // -------------------------------------------------------------------
   // Helper method: Creates a Race game type path.
   // -------------------------------------------------------------------
	Path* GenerateRacePath(int player);

   Path* currPath;

	Coordinate* Chariot_2[CHARIOT_STEPS] = { new Coordinate(-1,-1), new Coordinate(2, 3),
		new Coordinate(2, 2), new Coordinate(2, 1), new Coordinate(2, 0),
		new Coordinate(1, 0), new Coordinate(1, 1), new Coordinate(1, 2),
		new Coordinate(1, 3), new Coordinate(1, 4), new Coordinate(1, 5),
		new Coordinate(1, 6), new Coordinate(1, 7), new Coordinate(2, 7),
		new Coordinate(2, 6) }; // Add new Coordinate(-1, -1) at the start

	Coordinate* Chariot_1[CHARIOT_STEPS] = { new Coordinate(-1,-1), new Coordinate(0, 3),
		new Coordinate(0, 2), new Coordinate(0, 1), new Coordinate(0, 0),
      new Coordinate(1, 0), new Coordinate(1, 1), new Coordinate(1, 2),
      new Coordinate(1, 3), new Coordinate(1, 4), new Coordinate(1, 5),
      new Coordinate(1, 6), new Coordinate(1, 7), new Coordinate(0, 7),
		new Coordinate(0, 6) }; // Add new Coordinate(-1, -1) at the start

   Coordinate* Race_2[RACE_STEPS] = { new Coordinate(-1,-1), new Coordinate(1, 0), 
      new Coordinate(0, 0), new Coordinate(0, 1), new Coordinate(1, 1),
      new Coordinate(2, 1), new Coordinate(2, 2), new Coordinate(1, 2), 
      new Coordinate(0, 2), new Coordinate(0, 3), new Coordinate(1, 3),
      new Coordinate(1, 4), new Coordinate(1, 5), new Coordinate(1, 6), 
      new Coordinate(1, 7), new Coordinate(0, 7), new Coordinate(0, 6),
      new Coordinate(1, 6), new Coordinate(2, 6), new Coordinate(2, 7), 
      new Coordinate(1, 7), new Coordinate(1, 6), new Coordinate(1, 5),
      new Coordinate(1, 4), new Coordinate(1, 3),new Coordinate(1, 2), 
      new Coordinate(1, 1), new Coordinate(0, 1) }; // Add new Coordinate(-1, -1) at the start

   Coordinate* Race_1[RACE_STEPS] = { new Coordinate(-1,-1), new Coordinate(1, 0), 
      new Coordinate(2, 0), new Coordinate(2, 1), new Coordinate(1, 1),
      new Coordinate(0, 1), new Coordinate(0, 2), new Coordinate(1, 2), 
      new Coordinate(2, 2), new Coordinate(2, 3), new Coordinate(1, 3),
      new Coordinate(1, 4), new Coordinate(1, 5), new Coordinate(1, 6), 
      new Coordinate(1, 7), new Coordinate(2, 7), new Coordinate(2, 6),
      new Coordinate(1, 6), new Coordinate(0, 6), new Coordinate(0, 7), 
      new Coordinate(1, 7), new Coordinate(1, 6), new Coordinate(1, 5),
      new Coordinate(1, 4), new Coordinate(1, 3),new Coordinate(1, 2),
      new Coordinate(1, 1), new Coordinate(2, 1) }; // Add new Coordinate(-1, -1) at the start
};



#endif