/*
   File:        Sprites.h
  Description: Handles game sprites and fonts
  Program:     BlockOut
  Author:      Jean-Luc PONS

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/
#include "Types.h"
#include "GLApp/GLSprite.h"

class Sprites {

  public:
    Sprites();

    // Create Sprites device objects
    int Create(DWORD width,DWORD height);

    // Release device objects
    void InvalidateDeviceObjects();

    // Render score,level and cube
    void RenderScore(DWORD score,DWORD level,DWORD cubes);

    // Render High score, pit dimension, game mode and block set
    void RenderInfo(DWORD highScore,int x,int y,int z,int blockSet);

    // Render "Game Over" and "PAUSED"
    void RenderGameMode(int mode);

    // Render "Replay"
    void RenderReplay();
    
    // Render "Demo"
    void RenderDemo();

    // Render "Practice"
    void RenderPractice();

    // Render "On Line"
    void RenderOnLine();

    void RenderPitLevels(int level, int depth, int style);


  private:
    void RenderNumbers(float x, float y, char *strMumber);
    void RenderLevel(int level);
    void RenderBlockSet(int blockSet);
    void RenderMode(int mode);
    int GetNumberWidth(char number);

    Sprite2D baseSprite;
    Sprite2D gameOverSprite;
    Sprite2D pitLevelsSprite;

    // Coordinates
    float xScore;
    float yScore;
    float xCube;
    float yCube;
    float xhScore;
    float yhScore;
    float xPit;
    float yPit;
    float xBlock;
    float yBlock;
    float wScore;
    float hScore;

    float xLevel;
    float yLevel;
    float wLevel;
    float hLevel;

    float xReplay;
    float yReplay;
    float wReplay;
    float hReplay;

    float xOnline;
    float yOnline;
    float wOnline;
    float hOnline;

    float xGOver;
    float yGOver;
    float wGOver;
    float hGOver;

    int numberWidth[10];

};
