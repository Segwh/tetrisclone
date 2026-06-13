#pragma once
#include <vector>
#include <map>
#include "pozit.h"
#include "colors.h"

class Block
{
public:
    Block();
    void Draw(int offsetx,int offsety);
    void Move(int rows, int collums);
    std::vector<Pozition>  GetCellPozition();
    void don();
    void donmeengelle();
    int id;
    std::map<int, std::vector<Pozition>>cells;

private:
    int cellsize;
    int rotationstate;
    std::vector<Color> Color;
    int rowOfset;
    int collumofset;

};


