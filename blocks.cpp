#include "block.h"
#include "pozit.h"

class LeBlock : public Block
{
public:
      LeBlock()
      {
        id =1;
        cells[0]={Pozition(0,2),Pozition(1,0), Pozition(1,1),Pozition(1,2)};
        cells[1]={Pozition(0,1),Pozition(1,1), Pozition(2,1),Pozition(2,2)};
        cells[2]={Pozition(1,0),Pozition(1,1), Pozition(1,2),Pozition(2,0)};
        cells[3]={Pozition(0,0),Pozition(0,1), Pozition(1,1),Pozition(2,1)};
        Move(0,3);
      }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        cells[0] = {Pozition(0, 0), Pozition(1, 0), Pozition(1, 1), Pozition(1, 2)};
        cells[1] = {Pozition(0, 1), Pozition(0, 2), Pozition(1, 1), Pozition(2, 1)};
        cells[2] = {Pozition(1, 0), Pozition(1, 1), Pozition(1, 2), Pozition(2, 2)};
        cells[3] = {Pozition(0, 1), Pozition(1, 1), Pozition(2, 0), Pozition(2, 1)};
        Move(0,3);
       
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        cells[0] = {Pozition(1, 0), Pozition(1, 1), Pozition(1, 2), Pozition(1, 3)};
        cells[1] = {Pozition(0, 2), Pozition(1, 2), Pozition(2, 2), Pozition(3, 2)};
        cells[2] = {Pozition(2, 0), Pozition(2, 1), Pozition(2, 2), Pozition(2, 3)};
        cells[3] = {Pozition(0, 1), Pozition(1, 1), Pozition(2, 1), Pozition(3, 1)};
        Move(-1,3);
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        cells[0] = {Pozition(0, 0), Pozition(0, 1), Pozition(1, 0), Pozition(1, 1)};
        cells[1] = {Pozition(0, 0), Pozition(0, 1), Pozition(1, 0), Pozition(1, 1)};
        cells[2] = {Pozition(0, 0), Pozition(0, 1), Pozition(1, 0), Pozition(1, 1)};
        cells[3] = {Pozition(0, 0), Pozition(0, 1), Pozition(1, 0), Pozition(1, 1)};
       Move(0,4);
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        cells[0] = {Pozition(0, 1), Pozition(0, 2), Pozition(1, 0), Pozition(1, 1)};
        cells[1] = {Pozition(0, 1), Pozition(1, 1), Pozition(1, 2), Pozition(2, 2)};
        cells[2] = {Pozition(1, 1), Pozition(1, 2), Pozition(2, 0), Pozition(2, 1)};
        cells[3] = {Pozition(0, 0), Pozition(1, 0), Pozition(1, 1), Pozition(2, 1)};
       Move(0,3);
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        cells[0] = {Pozition(0, 1), Pozition(1, 0), Pozition(1, 1), Pozition(1, 2)};
        cells[1] = {Pozition(0, 1), Pozition(1, 1), Pozition(1, 2), Pozition(2, 1)};
        cells[2] = {Pozition(1, 0), Pozition(1, 1), Pozition(1, 2), Pozition(2, 1)};
        cells[3] = {Pozition(0, 1), Pozition(1, 0), Pozition(1, 1), Pozition(2, 1)};
       Move(0,3);
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        cells[0] = {Pozition(0, 0), Pozition(0, 1), Pozition(1, 1), Pozition(1, 2)};
        cells[1] = {Pozition(0, 2), Pozition(1, 1), Pozition(1, 2), Pozition(2, 1)};
        cells[2] = {Pozition(1, 0), Pozition(1, 1), Pozition(2, 1), Pozition(2, 2)};
        cells[3] = {Pozition(0, 1), Pozition(1, 0), Pozition(1, 1), Pozition(2, 0)};
        Move(0,3);
    }
};
