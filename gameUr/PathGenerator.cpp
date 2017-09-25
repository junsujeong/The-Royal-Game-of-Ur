//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Use factory design pattern to generate a requested path.
//---------------------------------------------------------------------
#include "PathGenerator.h"

Path* PathGenerator::GeneratePath(GameType type, int player)
{
	if (type == Chariot)
		return GenerateChariotPath(player);
	else
		return GenerateRacePath(player);
}

PathGenerator::~PathGenerator()
{
   for (int i = 0; i < CHARIOT_STEPS; i++)
   {
      delete Chariot_1[i];
      delete Chariot_2[i];
	  delete Race_1[i];
	  delete Race_2[i];
   }
}

Path* PathGenerator::GenerateChariotPath(int player)
{
   //delete currPath;
   currPath = new Path();
	if (player == 1)
		for (int i = 0; i < CHARIOT_STEPS; i++)
         currPath->AddStep(Chariot_1[i]);
	else
		for (int i = 0; i < CHARIOT_STEPS; i++)
         currPath->AddStep(Chariot_2[i]);
	return currPath;
}

Path* PathGenerator::GenerateRacePath(int player)
{
	currPath = new Path();
	if (player == 1)
		for (int i = 0; i < RACE_STEPS; i++)
			currPath->AddStep(Race_1[i]);
	else
		for (int i = 0; i < RACE_STEPS; i++)
			currPath->AddStep(Race_2[i]);
	return currPath;
}
