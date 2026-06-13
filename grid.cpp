#include "grid.h"
#include <iostream>
#include "colors.h"


Grid::Grid()
{
	    numrows = 20;
		numcolloms = 10;
		cellsize = 30;
		Initilaize();
        colors = GetCellColors();
}

void Grid::Initilaize()
{
	for (int row = 0; row < numrows; row++)
	{
		for (int collum = 0; collum < numcolloms; collum++)
		{
			grid[row][collum] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numrows; row++)
	{
		for (int collum = 0; collum < numcolloms; collum++)
		{
			std::cout << grid[row][collum] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::Draw()
{
    for (int row = 0;row<numrows;row++)
    {
       for (int collum = 0; collum < numcolloms; collum++)
       {
        int cellValue = grid[row][collum];
        DrawRectangle(collum * cellsize+1, row * cellsize+1, cellsize-1, cellsize-1, colors[cellValue]);
       }
    }
}

bool Grid::iscelloutofbounds(int row, int collom)
{
    if (row >=0 && row<numrows && collom >=0 && collom <numcolloms)
    {
        return false;
    }
    return true;
}

bool Grid::iscellempty(int row, int collom)
{
    if (grid[row][collom]== 0)
    {
        return true;
    }
    return false;
}

int Grid::clearfullrows()
{
    int compleated = 0;
    for (int row = numrows-1; row>=0;row--)
    {
       if (isrowfull(row))
       {
       clearrow(row);
       compleated++;
       }
       else if (compleated>0)
       {
        moverowdown(row,compleated);
       }
       
       
    }
    return compleated;
    
}

void Grid::moverowdown(int row, int numrows)
{
     
    for (int collum = 0;collum < numcolloms ;collum++)
    {
grid[row+numrows][collum] = grid[row][collum];
grid[row][collum]=0;
    }
}

void Grid::clearrow(int row)
{
     for (int collum = 0; collum < numcolloms; collum++)
    {
        grid[row][collum] = 0;
    }
}

bool Grid::isrowfull(int row)
{
   
{
    for (int collum = 0; collum < numcolloms; collum++)
    {
        if (grid[row][collum] == 0)
        {
            return false;
        }
    }
    return true;
}
}
