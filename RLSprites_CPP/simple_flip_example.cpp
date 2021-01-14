/**********************************************************************************************
*
*   raylibExtras * Utilities and Shared Components for Raylib
*
*   RLSprite * Simple Sprite Managment System for Raylib
*
*   LICENSE: MIT
*
*   Copyright (c) 2020 Jeffery Myers
*
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*   of this software and associated documentation files (the "Software"), to deal
*   in the Software without restriction, including without limitation the rights
*   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*   copies of the Software, and to permit persons to whom the Software is
*   furnished to do so, subject to the following conditions:
*
*   The above copyright notice and this permission notice shall be included in all
*   copies or substantial portions of the Software.
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*   SOFTWARE.
*
**********************************************************************************************/

#include "raylib.h"
#include "RLSprites.h"

using namespace RLSprites;

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    Sprite baseSprite;
    baseSprite.AddImage("resources/scarfy.png", 6, 1);
    baseSprite.AddFlipFrames(0, 5, true, false);

    baseSprite.AddAnimation("walk", DIRECTION_RIGHT, 0, 5);
    baseSprite.AddAnimation("walk", DIRECTION_LEFT, 6, 11);
    baseSprite.SetAnimationLoop("walk", true);
    baseSprite.SetAnimationSpeed("walk", 12);

    baseSprite.AddAnimation("idle", DIRECTION_RIGHT, 2, 2);
    baseSprite.AddAnimation("idle", DIRECTION_LEFT, 8, 8);
    baseSprite.SetAnimationLoop("idle", true);
    baseSprite.SetAnimationSpeed("idle", 1);

    SpriteInstance sprite(baseSprite);
    sprite.SetAimation("idle");
    sprite.Direction = DIRECTION_LEFT;

    sprite.OriginX = OriginLocations::Center;
    sprite.OriginY = OriginLocations::Center;

    sprite.Postion = Vector2{ 100,100 };
    sprite.Scale = 1.0f;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        float speed = GetFrameTime() * 400;

        bool moving = true;
        if (IsKeyDown(KEY_LEFT))
        {
            sprite.Direction = DIRECTION_LEFT;
            moving = true;
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            sprite.Direction = DIRECTION_RIGHT;
            moving = true;
        }
        else
            moving = false;

        if (IsKeyDown(KEY_LEFT_SHIFT) && moving)
            sprite.Speed = 2;
        else
            sprite.Speed = 1;

        if (IsKeyDown(KEY_LEFT))
        {
            sprite.Postion.x -= speed * sprite.Speed;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            sprite.Postion.x += speed * sprite.Speed;
        }

        sprite.SetAimation(moving ? "walk" : "idle");

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);

        sprite.UpdateRender();

        DrawText("(c) Scarfy sprite by Eiden Marsal", screenWidth - 200, screenHeight - 20, 10, GRAY);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}