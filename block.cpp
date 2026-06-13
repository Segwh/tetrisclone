#include "block.h"

Block::Block()
{
    cellsize=30;
    rotationstate=0;
    Color = GetCellColors();
    rowOfset=0;
    collumofset=0;
}

void Block::Draw(int offsetx,int offsety)
{
    std::vector<Pozition> tiles = GetCellPozition();
    for(Pozition item:tiles)
    {
        DrawRectangle(item.collom*cellsize+offsetx,item.row*cellsize+offsety,cellsize-1,cellsize-1,Color[id]);
    }
}

void Block::Move(int rows,int collums)
{
        rowOfset+=rows;
        collumofset+=collums;
}



std::vector<Pozition>Block::GetCellPozition()
{
    std::vector<Pozition> tiles = cells[rotationstate];
    std::vector<Pozition> movedTiles ;

    for(Pozition item: tiles)
    {
        Pozition newpoz = Pozition(item.row+rowOfset,item.collom+collumofset);
        movedTiles.push_back(newpoz);
    }
return movedTiles;
}

void Block::don()
{
    rotationstate++;
    if (rotationstate==(int)cells.size())
    {
        rotationstate = 0;
    }
    
}

void Block::donmeengelle()
{
    rotationstate--;
    if (rotationstate==-1)
    {
        rotationstate=cells.size()-1;
    }
    
}
