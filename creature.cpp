//
// Created by Younes Lahrichi 10/22/21
//

#include "creature.h"
//This is the operator overload of the operator "<<"
//this prints out the current location of the creature
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "The Creatures' current location is: " << "(" << Creature.Row << "," << Creature.Col << ")" << endl;
  return Out;
}
//This is the constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}
//This method returns whether the creature is currently at the exit point of the maze.
bool Creature::atExit(const Maze &Maze) const {
  //this if checks if the current row and column is matching with the exit row and column
  if (Row == Maze.getExitRow() && Col == Maze.getExitColumn()){
    return true;
  }
  return false;
}
//this is the method that you call to solve the maze
//this method utilized the move methods to effectively solve the maze
//this method is needed to boot up the recursive methods to start working with each other.
string Creature::solve(Maze &Maze) {
  string path;
  string noPath;
//this marks the starting spot as part of the path.
  Maze.markAsPath(Row, Col);
//this makes the creature attempt to go North
  path = goNorth(Maze);
//this checks if the northern block is a wall
  if (path == "X"){
//this makes the creature attempt to go East
    path = goEast(Maze);
//this checks if the eastern block is a wall
    if (path == "X"){
//this makes the creature attempt to go West
      path = goWest(Maze);
//this checks if the western block is a wall
      if(path == "X"){
//this makes the creature attempt to go South
        path = goSouth(Maze);
//this checks if the southern block is a wall
        if (path == "X"){
//if the code gets here then it means that the creature is surrounded by walls or has explored every option and there is no possible path to the exit
          noPath = "There is no path to move.";
          return noPath;
        }
      }
    }
  }
  return path;
}
//this is the function that attempts to move the creature north
string Creature::goNorth(Maze &Maze) {
//intializing the path to be blocked at the start
  string newPath = "X";
//this checks if the block north of the creature is clear
  if (Maze.isClear(Row - 1 , Col)){
//if it is clear it moves the creature north and marks it as part of the path
    Row--;
    Maze.markAsPath(Row, Col);
//this checks if the creature is at the exit and returns the path
    if (atExit(Maze) == true){
      return "N";
    }
//attempts to move the creature north again 
    newPath = goNorth(Maze);
//checks if the northern block is a wall
    if(newPath == "X"){
//attempts to go east (gets here if northern block is a wall)
      newPath = goEast(Maze);
//checks if the eastern block is a wall
      if (newPath == "X"){
//attempts to go west (gets here if the eastern block is a wall)
        newPath = goWest(Maze);
//checks if the western block is a wall
        if (newPath == "X"){
//if the western wall is a wall then it marks the current spot as visited and backtracks to previous block
          Maze.markAsVisited(Row, Col);
          Row++;
          return newPath;
        }
      }
    }
  }
  else {
    return newPath;
  }
//recursively returns the path
  return "N" + newPath;
}
//this is the function that attempts to move the creature west
string Creature::goWest(Maze &Maze) {
//intializing the path to be blocked at the start
  string newPath = "X";
//this checks if the block west of the creature is clear
  if (Maze.isClear(Row, Col - 1) == true){
//if it is clear it moves the creature west and marks it as part of the path
    Col--;
    Maze.markAsPath(Row, Col);
//this checks if the creature is at the exit and returns the path
    if (atExit(Maze) == true){
      return "W";
    }
//attempts to move the creature west again 
    newPath = goWest(Maze);
//checks if the western block is a wall
    if(newPath == "X"){
//attempts to go north (gets here if western block is a wall)
      newPath = goNorth(Maze);
//checks if the northern block is a wall
      if (newPath == "X"){
//attempts to go south (gets here if northern block is a wall)
        newPath = goSouth(Maze);
//checks if the southern block is a wall
        if (newPath == "X"){
//if the southern wall is a wall then it marks the current spot as visited and backtracks to previous block
          Maze.markAsVisited(Row, Col);
          Col++;
          return newPath;
        }
      }
    }
  }
  else {
    return newPath;
  }
//recursively returns the path
  return "W" + newPath;
}
//this is the function that attempts to move the creature east
string Creature::goEast(Maze &Maze) {
//intializing the path to be blocked at the start
  string newPath = "X";
//this checks if the block east of the creature is clear
  if (Maze.isClear(Row, Col + 1) == true){
//if it is clear it moves the creature east and marks it as part of the path
    Col++;
    Maze.markAsPath(Row, Col);
//this checks if the creature is at the exit and returns the path
    if (atExit(Maze) == true){
      return "E";
    }
//attempts to move the creature east again 
    newPath = goEast(Maze);
//checks if the eastern block is a wall
    if(newPath == "X"){
//attempts to go north (gets here if eastern block is a wall)
      newPath = goNorth(Maze);
//checks if the northern block is a wall
      if (newPath == "X"){
//attempts to go south (gets here if northern block is a wall)
        newPath = goSouth(Maze);
//checks if the southern block is a wall
        if (newPath == "X"){
//if the southern wall is a wall then it marks the current spot as visited and backtracks to previous block
          Maze.markAsVisited(Row, Col);
          Col--;
          return newPath;
        }
      }
    }
  }
  else {
    return newPath;
  }
//recursively returns the path
  return "E" + newPath;
}
//this is the function that attempts to move the creature south
string Creature::goSouth(Maze &Maze) {
//intializing the path to be blocked at the start
  string newPath = "X";
//this checks if the block south of the creature is clear
  if (Maze.isClear(Row + 1 , Col)){
//if it is clear it moves the creature south and marks it as part of the path
    Row++;
    Maze.markAsPath(Row, Col);
//this checks if the creature is at the exit and returns the path
    if (atExit(Maze) == true){
      return "S";
    }
//attempts to move the creature south again 
    newPath = goSouth(Maze);
//checks if the southern block is a wall
    if(newPath == "X"){
//attempts to go east (gets here if southern block is a wall)
      newPath = goEast(Maze);
//checks if the eastern block is a wall
      if (newPath == "X"){
//attempts to go west (gets here if the eastern block is a wall)
        newPath = goWest(Maze);
//checks if the western block is a wall
        if (newPath == "X"){
//if the western wall is a wall then it marks the current spot as visited and backtracks to previous block
          Maze.markAsVisited(Row, Col);
          Row--;
          return newPath;
        }
      }
    }
  } else {
    return newPath;
  }
//recursively returns the path
  return "S" + newPath;
}