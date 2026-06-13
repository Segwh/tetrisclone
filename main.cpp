#include <iostream>
#include <raylib.h>
#include "oyun.h"
#include "colors.h"

double lastUpdatetime =0;

bool EventTriggerd(double interval)
{
 double currnettime = GetTime();
 if (currnettime - lastUpdatetime>=interval)
 {
    lastUpdatetime=currnettime;
    return true;
 }
 return false;
}


int main()
{
	
	InitWindow(580, 610, "Tetris");

	SetTargetFPS(60);

  Font font = LoadFontEx("Font/monogram.ttf",64,0,0);

   Game game = Game();


	while (WindowShouldClose() == false )
	{

        UpdateMusicStream(game.music);
        game.inputs();
        if (EventTriggerd(0.20))
        {
            game.MoveBlocktodown();
        }
		BeginDrawing();
		ClearBackground(darkBlue);
        DrawTextEx(font,"Puan", {370,15}, 40,2 , WHITE);
        DrawTextEx(font,"Sonraki", {370,175}, 40,2 , WHITE);
        if(game.gameover)
        {
            DrawTextEx(font,"KAYBETTIN", {320,450}, 40,2 , WHITE);
        }

        DrawRectangleRounded({340,55,170,60},0.3,6, lightBlue);
        char scoreText[10];
        sprintf(scoreText,"%d",game.score);
        Vector2 textSize = MeasureTextEx(font,scoreText,38,2);

        DrawTextEx(font,scoreText, {320+(170 -textSize.x)/2,75}, 40,2 , WHITE);
        DrawRectangleRounded({340,215,170,180},0.3,6, lightBlue);
        game.Draw();


		EndDrawing();
	}

	CloseWindow();
}