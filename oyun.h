#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game{

    public:
        Game();
        ~Game();
        Block Getrandomblock();
        std::vector<Block> Getallblocks();
        void Draw();
        void inputs();
        void MoveBlocktoleft();
        void MoveBlocktoright();
        void MoveBlocktodown();
        bool gameover;
        Grid grid;
        int score;
        Music music;

    private:
    bool isblockoutside();
    void DondurBlok();
    void LockBlock();
    bool bloksfits();
    void reset();
    void updatescore(int linescleard,int movedownpoints);
    Sound clearsound;
    Sound dondurmesesi;

    std::vector<Block>blocks;
    Block currentblock;
    Block nextblock;
};