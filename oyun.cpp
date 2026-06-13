#include "oyun.h"
#include <random>


Game::Game(){

    grid = Grid();
    blocks = Getallblocks();
    currentblock = Getrandomblock();
    nextblock   = Getrandomblock();
    gameover = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("muzik/tetris.mp3");
    PlayMusicStream(music);
    dondurmesesi = LoadSound("muzik/dbz.mp3");
    clearsound = LoadSound("muzik/mbwarband.mp3");
}

Game::~Game()
{
    UnloadSound(dondurmesesi);
    UnloadSound(clearsound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

Block Game::Getrandomblock() 
{

    if (blocks.empty())
    {
        blocks = Getallblocks();
    }
    
  int randomindex =rand() % blocks.size();
  Block block = blocks[randomindex];
  blocks.erase(blocks.begin()+randomindex);
  return block;
}

std::vector<Block> Game::Getallblocks()
{
    return {IBlock(),JBlock(),OBlock(),LeBlock(),SBlock(),TBlock(),ZBlock()};
}

void Game::Draw()
{
        grid.Draw();
        currentblock.Draw(1,1);
        nextblock.Draw(270,270);
}

void Game::inputs()
{
    int keyPressed = GetKeyPressed();
    if(gameover && keyPressed != 0)
    {
            gameover = false;
            reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlocktoleft();
    break;
    case KEY_RIGHT:
         MoveBlocktoright();
    break;
    case KEY_DOWN:
        MoveBlocktodown();
        updatescore(0,1);
    break;
    case KEY_UP:
    DondurBlok();
    break;
    }
}


void Game::MoveBlocktoleft()
{
    if(!gameover)
    {
    currentblock.Move(0,-1);
    if(isblockoutside()|| bloksfits()== false)
    {
        currentblock.Move(0,1);
    }
   }
}

void Game::MoveBlocktoright()
{
     if(!gameover)
     {
    currentblock.Move(0,1);
    if(isblockoutside()|| bloksfits()== false)
    {
        currentblock.Move(0,-1);
    }
    }
}


void Game::MoveBlocktodown()
{
     if(!gameover)
     {
    currentblock.Move(1,0);
    if(isblockoutside()|| bloksfits()== false)
    {
        currentblock.Move(-1,0);
        LockBlock();
    }
    }
}

bool Game::isblockoutside()
{
    std::vector<Pozition> tile = currentblock.GetCellPozition();
    for(Pozition item : tile)
    {
        if(grid.iscelloutofbounds(item.row, item.collom))
        {
            return true;
        }
        
    }
    return false;
}

void Game::DondurBlok()
{
     if(!gameover)
     {
    currentblock.don();
    if (isblockoutside()|| bloksfits()== false)
    {
        currentblock.donmeengelle();
    }
    else
    {
        PlaySound(dondurmesesi);
    }
    }
    
}

void Game::LockBlock()
{
    std::vector<Pozition> tile = currentblock.GetCellPozition();
    for ( Pozition item: tile)
    {
      grid.grid[item.row][item.collom] = currentblock.id;
    }
    currentblock=nextblock;
    if(bloksfits()== false)
    {
            gameover = true;
    }
    nextblock = Getrandomblock();
   int rowscleard =  grid.clearfullrows();
   if(rowscleard > 0)
   {
    PlaySound(clearsound);
    updatescore(rowscleard,0);
   }
  
    
}

bool Game::bloksfits()
{
   std::vector<Pozition> tile =currentblock.GetCellPozition();
   for (Pozition item : tile )
   {
    if ( grid.iscellempty(item.row,item.collom)== false )
    {
     return false;
    
   }
   
   
   }
    return true;
}


void Game:: reset()
{
 grid.Initilaize();
 blocks = Getallblocks();
 currentblock = Getrandomblock();
 nextblock=Getrandomblock();
 score = 0;
}

void Game::updatescore(int linescleard, int movedownpoints)
{

    switch (linescleard)
    {
    case 1:
        score+=10;
        break;
        case 2:
        score+=20;
        break;
        case 3:
        score+=40;
        break;
    
    default:
        break;
    }

    score+=movedownpoints;
}
