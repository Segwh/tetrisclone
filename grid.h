#pragma once
#include <vector>
#include <raylib.h>


class Grid
{
public:
   Grid();
	void Initilaize();
	int grid[20][10];
	void Print();
    void Draw();
    bool iscelloutofbounds(int row,int collom);
    bool iscellempty(int row,int collom);
    int clearfullrows();

private:
    
    void moverowdown(int row,int numrows);
    void clearrow(int row);
    bool isrowfull(int row);
    int numrows;
	int numcolloms;
	int cellsize;
    std::vector<Color>colors;
};