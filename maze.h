//
// 
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;
//this is the enumerator
enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
//this is the intialization of the operator overload for the operator << 
  friend ostream &operator<<(ostream &Out, const Maze &Maze);
private:
  const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;
public:
//this is the constructor
  explicit Maze(const string &FileName);
//this is the initialization of the method that returns if the block clear or not
  bool isClear(int Row, int Col) const;
// is the intialization of the method that marks the block as part of the path
  void markAsPath(int Row, int Col);
//this is the intialization of the method that marks the block as visited
  void markAsVisited(int Row, int Col);
//this is the intialization of the method that returns the exit row
  int getExitRow() const;
//this is the intialization of the method that returns the exit column
  int getExitColumn() const;

};

#endif //ASS3_MAZE_H