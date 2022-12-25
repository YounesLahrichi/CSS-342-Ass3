//
// Created by Younes Lahrichi 10/22/21
//


#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
//This is intialization of the operator overload of the operator "<<"
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
//these are the row and column variables that store the creatures location
  int Row;
  int Col;

public:
//intialization of the constructor
  Creature(int Row, int Col);
//Intialization the solve method that runs all of these direction methods
  string solve(Maze &Maze);
//intialization of method that checks if the creature is at the exit
  bool atExit(const Maze &Maze) const;
//intialization of the method that tries to move North
  string goNorth(Maze &Maze);
//intialization of the method that tries to move South
  string goSouth(Maze &Maze);
//intialization of the method that tries to move East
  string goEast(Maze &Maze);
//intialization of the method that tries to move West
  string goWest(Maze &Maze);
};

#endif //ASS3_CREATURE_H