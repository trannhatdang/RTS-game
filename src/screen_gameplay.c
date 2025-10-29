/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include "unit.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
//


static int framesCounter = 0;
static int finishScreen = 0;
static Unit* chosenUnit = NULL;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------
//
//
//

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
	// TODO: Update GAMEPLAY screen variables here!

	// Press enter or tap to change to ENDING screen
	
	Vector2 mousePos = GetMousePosition();
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 1;
		PlaySound(fxCoin);
	}
	if(IsKeyPressed(KEY_F))
	{
		Unit* unit = SpawnUnit(WARRIOR);
		PlaySound(fxCoin);
	}

	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		chosenUnit = FindCloseUnit(mousePos);
	}

	if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && chosenUnit != NULL)
	{
		chosenUnit->velocity = Vector2Normalize(mousePos - chosenUnit->position);
	}

	UpdateUnits();
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
	// TODO: Draw GAMEPLAY screen here!
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
	Vector2 pos = { 20, 10 };
	//DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, MAROON);
	//DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

	DrawRectangle(pos.x, pos.y, 10, 10, WHITE);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
	// TODO: Unload GAMEPLAY screen variables here!
	FreeUnits(units, numUnits);
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
