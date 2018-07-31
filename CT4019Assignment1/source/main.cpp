//\===========================================================================================================================================
//\ Filename: main.cpp
//\ Author  : SamBaker_s1704633
//\ Date    : 04/07/18
//\ Brief   : This is the cpp file that is the main entry to our Breakout remake game.
//\===========================================================================================================================================

//includes to allow use of the UG Framework
#include "UGFW.h"
#include "UG_Defines.h"

#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

//Screen Dimensions
int g_iScreenWidth = 0;
int g_iScreenHeight = 0;

//\===========================================================================================================================================
//\ Main entry point into our application 
//\  argv - this is the number of command line arguments that are present when we open our application 
//\			if we open this exe by clicking on it with a mouse this number is 1. 
//\  argc - this is a varadic string argument, the number of items in the array is defined by the value in argv
//\===========================================================================================================================================

int main(int argv, char* argc[])
{
	// If statement used to create an instance of the framework
	// If this returns 0 the framework could not be created and
	// the application will terminate with an error state
	if (!UG::Create(1024, 768, false, "1976 Breakout Remake", 100, 100)) return 1;

	//UG function call to set the background color for the applications render window
	//SColour is a structure that defines a colour with a hex code - in this case to teal.
	UG::SetBackgroundColor(UG::SColour(0x00, 0x00, 0x00, 0x00));

	UG::GetScreenSize(g_iScreenWidth, g_iScreenHeight);

	//Setting up the player
	unsigned int iPlayer = UG::CreateSprite("./sprites/player.png", 59, 16, true);

	//Setting up the sprites for all the bricks
	unsigned int iBricks[88] = { UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //0
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //1
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //2
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //3
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //4
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //5
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //6
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //7
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //8
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //9
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //10

		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //11
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //12
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //13
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //14
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //15
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //16
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //17
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //18
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //19
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //20
		UG::CreateSprite("./sprites/redblock.png", 81, 24, true), //21

		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //22
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //23
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //24
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //25
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //26
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //27
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //28
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //29
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //30
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //31
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //32

		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //33
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //34
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //35
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //36
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //37
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //38
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //39
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //40
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //41
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //42
		UG::CreateSprite("./sprites/orangeblock.png", 81, 24, true), //43

		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //44
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //45
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //46
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //47
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //48
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //49
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //50
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //51
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //52
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //53
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //54

		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //55
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //56
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //57
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //58
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //59
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //60
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //61
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //62
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //63
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //64
		UG::CreateSprite("./sprites/greenblock.png", 81, 24, true), //65

		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //66
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //67
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //68
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //69
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //70
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //71
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //72
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //73
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //74
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //75
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //76

		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //77
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //78
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //79
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //80
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //81
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //82
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //83
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //84
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //85
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true), //86
		UG::CreateSprite("./sprites/yellowblock.png", 81, 24, true) //87
	};
	
	//Setting up ints for our score counters. We have 3 because we arent printing the score directly to screen
	//	but we are using 3 counters that tick once on reaches 10
	int s = 0;
	int s1 = 0;
	int s2 = 0;
	
	//Our 3 score arrays these are displayed in units of one and change depending on the score.
	unsigned int score1[10] =
	{
		UG::CreateSprite("./sprites/0.png", 45, 45, true),
		UG::CreateSprite("./sprites/1.png", 45, 45, true),
		UG::CreateSprite("./sprites/2.png", 45, 45, true),
		UG::CreateSprite("./sprites/3.png", 45, 45, true),
		UG::CreateSprite("./sprites/4.png", 45, 45, true),
		UG::CreateSprite("./sprites/5.png", 45, 45, true),
		UG::CreateSprite("./sprites/6.png", 45, 45, true),
		UG::CreateSprite("./sprites/7.png", 45, 45, true),
		UG::CreateSprite("./sprites/8.png", 45, 45, true),
		UG::CreateSprite("./sprites/9.png", 45, 45, true)
	};
	unsigned int score2[10] =
	{
		UG::CreateSprite("./sprites/0.png", 45, 45, true),
		UG::CreateSprite("./sprites/1.png", 45, 45, true),
		UG::CreateSprite("./sprites/2.png", 45, 45, true),
		UG::CreateSprite("./sprites/3.png", 45, 45, true),
		UG::CreateSprite("./sprites/4.png", 45, 45, true),
		UG::CreateSprite("./sprites/5.png", 45, 45, true),
		UG::CreateSprite("./sprites/6.png", 45, 45, true),
		UG::CreateSprite("./sprites/7.png", 45, 45, true),
		UG::CreateSprite("./sprites/8.png", 45, 45, true),
		UG::CreateSprite("./sprites/9.png", 45, 45, true)
	};
	unsigned int score3[10] =
	{
		UG::CreateSprite("./sprites/0.png", 45, 45, true),
		UG::CreateSprite("./sprites/1.png", 45, 45, true),
		UG::CreateSprite("./sprites/2.png", 45, 45, true),
		UG::CreateSprite("./sprites/3.png", 45, 45, true),
		UG::CreateSprite("./sprites/4.png", 45, 45, true),
		UG::CreateSprite("./sprites/5.png", 45, 45, true),
		UG::CreateSprite("./sprites/6.png", 45, 45, true),
		UG::CreateSprite("./sprites/7.png", 45, 45, true),
		UG::CreateSprite("./sprites/8.png", 45, 45, true),
		UG::CreateSprite("./sprites/9.png", 45, 45, true)
	};

	//This is our array that holds the sprites for our death counter
	unsigned int deathstext[5] =
	{ 
		UG::CreateSprite("./sprites/1.png", 45, 45, true),
		UG::CreateSprite("./sprites/2.png", 45, 45, true),
		UG::CreateSprite("./sprites/3.png", 45, 45, true),
		UG::CreateSprite("./sprites/4.png", 45, 45, true),
		UG::CreateSprite("./sprites/5.png", 45, 45, true)
	};

	//For loop before the game starts to make sure that all block are able to be collided with
	bool bIsDetectable[88];
	for (int i = 0; i < 88; i++)
	{
		bIsDetectable[i] = true;
	}

	//Setting up the sprite for the ball
	unsigned int iBall = UG::CreateSprite("./sprites/ball.png", 10, 10, true);
	
	//Setting up the end screen sprite
	unsigned int iEndScreen = UG::CreateSprite("./sprites/endscreen.png", g_iScreenWidth, g_iScreenHeight, true);

	//Setting the start position for our player
	float fPlayerPos[2] = { g_iScreenWidth * 0.5f, 50.0f };
	UG::SetSpritePosition(iPlayer, fPlayerPos[0], fPlayerPos[1]);
	//Setting more variables for the ball
	float fOldX;
	float fOldY;
	float fSpeed = 4.0f;
	float fBallDX = 0.0f;
	float fBallDY = 0.0f;

	//Setting the deaths to 0
	int deaths = 0;

	//Setting up the start position for our ball
	float fBallPos[2] = { 512.0f, 150.0f };
	UG::SetSpritePosition(iBall, fBallPos[0], fBallPos[1]);
	//Setting up variables for the ball


	//Setting up arrays for the x and y position for the destroyable blocks
	float fBlockX[11] = {61.0f, 150.0f, 239.0f, 328.0f, 417.0f, 506.0f, 595.0f, 684.0f, 773.0f, 862.0f, 951.0f};
	float fBlockY[8] = {665.0f, 633.0f, 601.0f, 569.0f, 537.0f, 505.0f, 473.0f, 441.0f};

	/////////////////////////////////////////////////////////////
	//Setting all the sprite positions for the destroyable boxes//
	UG::SetSpritePosition(iBricks[0], fBlockX[0], fBlockY[0]);
	UG::SetSpritePosition(iBricks[1], fBlockX[1], fBlockY[0]);
	UG::SetSpritePosition(iBricks[2], fBlockX[2], fBlockY[0]);
	UG::SetSpritePosition(iBricks[3], fBlockX[3], fBlockY[0]);
	UG::SetSpritePosition(iBricks[4], fBlockX[4], fBlockY[0]);
	UG::SetSpritePosition(iBricks[5], fBlockX[5], fBlockY[0]);
	UG::SetSpritePosition(iBricks[6], fBlockX[6], fBlockY[0]);
	UG::SetSpritePosition(iBricks[7], fBlockX[7], fBlockY[0]);
	UG::SetSpritePosition(iBricks[8], fBlockX[8], fBlockY[0]);
	UG::SetSpritePosition(iBricks[9], fBlockX[9], fBlockY[0]);
	UG::SetSpritePosition(iBricks[10], fBlockX[10], fBlockY[0]);
	UG::SetSpritePosition(iBricks[11], fBlockX[0], fBlockY[1]);
	UG::SetSpritePosition(iBricks[12], fBlockX[1], fBlockY[1]);
	UG::SetSpritePosition(iBricks[13], fBlockX[2], fBlockY[1]);
	UG::SetSpritePosition(iBricks[14], fBlockX[3], fBlockY[1]);
	UG::SetSpritePosition(iBricks[15], fBlockX[4], fBlockY[1]);
	UG::SetSpritePosition(iBricks[16], fBlockX[5], fBlockY[1]);
	UG::SetSpritePosition(iBricks[17], fBlockX[6], fBlockY[1]);
	UG::SetSpritePosition(iBricks[18], fBlockX[7], fBlockY[1]);
	UG::SetSpritePosition(iBricks[19], fBlockX[8], fBlockY[1]);
	UG::SetSpritePosition(iBricks[20], fBlockX[9], fBlockY[1]);
	UG::SetSpritePosition(iBricks[21], fBlockX[10], fBlockY[1]);
	UG::SetSpritePosition(iBricks[22], fBlockX[0], fBlockY[2]);
	UG::SetSpritePosition(iBricks[23], fBlockX[1], fBlockY[2]);
	UG::SetSpritePosition(iBricks[24], fBlockX[2], fBlockY[2]);
	UG::SetSpritePosition(iBricks[25], fBlockX[3], fBlockY[2]);
	UG::SetSpritePosition(iBricks[26], fBlockX[4], fBlockY[2]);
	UG::SetSpritePosition(iBricks[27], fBlockX[5], fBlockY[2]);
	UG::SetSpritePosition(iBricks[28], fBlockX[6], fBlockY[2]);
	UG::SetSpritePosition(iBricks[29], fBlockX[7], fBlockY[2]);
	UG::SetSpritePosition(iBricks[30], fBlockX[8], fBlockY[2]);
	UG::SetSpritePosition(iBricks[31], fBlockX[9], fBlockY[2]);
	UG::SetSpritePosition(iBricks[32], fBlockX[10], fBlockY[2]);
	UG::SetSpritePosition(iBricks[33], fBlockX[0], fBlockY[3]);
	UG::SetSpritePosition(iBricks[34], fBlockX[1], fBlockY[3]);
	UG::SetSpritePosition(iBricks[35], fBlockX[2], fBlockY[3]);
	UG::SetSpritePosition(iBricks[36], fBlockX[3], fBlockY[3]);
	UG::SetSpritePosition(iBricks[37], fBlockX[4], fBlockY[3]);
	UG::SetSpritePosition(iBricks[38], fBlockX[5], fBlockY[3]);
	UG::SetSpritePosition(iBricks[39], fBlockX[6], fBlockY[3]);
	UG::SetSpritePosition(iBricks[40], fBlockX[7], fBlockY[3]);
	UG::SetSpritePosition(iBricks[41], fBlockX[8], fBlockY[3]);
	UG::SetSpritePosition(iBricks[42], fBlockX[9], fBlockY[3]);
	UG::SetSpritePosition(iBricks[43], fBlockX[10], fBlockY[3]);
	UG::SetSpritePosition(iBricks[44], fBlockX[0], fBlockY[4]);
	UG::SetSpritePosition(iBricks[45], fBlockX[1], fBlockY[4]);
	UG::SetSpritePosition(iBricks[46], fBlockX[2], fBlockY[4]);
	UG::SetSpritePosition(iBricks[47], fBlockX[3], fBlockY[4]);
	UG::SetSpritePosition(iBricks[48], fBlockX[4], fBlockY[4]);
	UG::SetSpritePosition(iBricks[49], fBlockX[5], fBlockY[4]);
	UG::SetSpritePosition(iBricks[50], fBlockX[6], fBlockY[4]);
	UG::SetSpritePosition(iBricks[51], fBlockX[7], fBlockY[4]);
	UG::SetSpritePosition(iBricks[52], fBlockX[8], fBlockY[4]);
	UG::SetSpritePosition(iBricks[53], fBlockX[9], fBlockY[4]);
	UG::SetSpritePosition(iBricks[54], fBlockX[10], fBlockY[4]);
	UG::SetSpritePosition(iBricks[55], fBlockX[0], fBlockY[5]);
	UG::SetSpritePosition(iBricks[56], fBlockX[1], fBlockY[5]);
	UG::SetSpritePosition(iBricks[57], fBlockX[2], fBlockY[5]);
	UG::SetSpritePosition(iBricks[58], fBlockX[3], fBlockY[5]);
	UG::SetSpritePosition(iBricks[59], fBlockX[4], fBlockY[5]);
	UG::SetSpritePosition(iBricks[60], fBlockX[5], fBlockY[5]);
	UG::SetSpritePosition(iBricks[61], fBlockX[6], fBlockY[5]);
	UG::SetSpritePosition(iBricks[62], fBlockX[7], fBlockY[5]);
	UG::SetSpritePosition(iBricks[63], fBlockX[8], fBlockY[5]);
	UG::SetSpritePosition(iBricks[64], fBlockX[9], fBlockY[5]);
	UG::SetSpritePosition(iBricks[65], fBlockX[10], fBlockY[5]);
	UG::SetSpritePosition(iBricks[66], fBlockX[0], fBlockY[6]);
	UG::SetSpritePosition(iBricks[67], fBlockX[1], fBlockY[6]);
	UG::SetSpritePosition(iBricks[68], fBlockX[2], fBlockY[6]);
	UG::SetSpritePosition(iBricks[69], fBlockX[3], fBlockY[6]);
	UG::SetSpritePosition(iBricks[70], fBlockX[4], fBlockY[6]);
	UG::SetSpritePosition(iBricks[71], fBlockX[5], fBlockY[6]);
	UG::SetSpritePosition(iBricks[72], fBlockX[6], fBlockY[6]);
	UG::SetSpritePosition(iBricks[73], fBlockX[7], fBlockY[6]);
	UG::SetSpritePosition(iBricks[74], fBlockX[8], fBlockY[6]);
	UG::SetSpritePosition(iBricks[75], fBlockX[9], fBlockY[6]);
	UG::SetSpritePosition(iBricks[76], fBlockX[10], fBlockY[6]);
	UG::SetSpritePosition(iBricks[77], fBlockX[0], fBlockY[7]);
	UG::SetSpritePosition(iBricks[78], fBlockX[1], fBlockY[7]);
	UG::SetSpritePosition(iBricks[79], fBlockX[2], fBlockY[7]);
	UG::SetSpritePosition(iBricks[80], fBlockX[3], fBlockY[7]);
	UG::SetSpritePosition(iBricks[81], fBlockX[4], fBlockY[7]);
	UG::SetSpritePosition(iBricks[82], fBlockX[5], fBlockY[7]);
	UG::SetSpritePosition(iBricks[83], fBlockX[6], fBlockY[7]);
	UG::SetSpritePosition(iBricks[84], fBlockX[7], fBlockY[7]);
	UG::SetSpritePosition(iBricks[85], fBlockX[8], fBlockY[7]);
	UG::SetSpritePosition(iBricks[86], fBlockX[9], fBlockY[7]);
	UG::SetSpritePosition(iBricks[87], fBlockX[10], fBlockY[7]);

	//Setting up booleans to tell the ball which way it needs to rebound
	bool up = true;
	bool right = true;


	// This is the start of our main game loop, we are using a do while loop (these loops are covered in a lecture!)
	do 
	{
		//Clearing the screen
		UG::ClearScreen();
		
		//Drawing our player, ball and all the bricks
		UG::DrawSprite(iPlayer);
		UG::DrawSprite(iBall);
		UG::DrawSprite(iBricks[0]);
		UG::DrawSprite(iBricks[1]);
		UG::DrawSprite(iBricks[2]);
		UG::DrawSprite(iBricks[3]);
		UG::DrawSprite(iBricks[4]);
		UG::DrawSprite(iBricks[5]);
		UG::DrawSprite(iBricks[6]);
		UG::DrawSprite(iBricks[7]);
		UG::DrawSprite(iBricks[8]);
		UG::DrawSprite(iBricks[9]);
		UG::DrawSprite(iBricks[10]);
		UG::DrawSprite(iBricks[11]);
		UG::DrawSprite(iBricks[12]);
		UG::DrawSprite(iBricks[13]);
		UG::DrawSprite(iBricks[14]);
		UG::DrawSprite(iBricks[15]);
		UG::DrawSprite(iBricks[16]);
		UG::DrawSprite(iBricks[17]);
		UG::DrawSprite(iBricks[18]);
		UG::DrawSprite(iBricks[19]);
		UG::DrawSprite(iBricks[20]);
		UG::DrawSprite(iBricks[21]);
		UG::DrawSprite(iBricks[22]);
		UG::DrawSprite(iBricks[23]);
		UG::DrawSprite(iBricks[24]);
		UG::DrawSprite(iBricks[25]);
		UG::DrawSprite(iBricks[26]);
		UG::DrawSprite(iBricks[27]);
		UG::DrawSprite(iBricks[28]);
		UG::DrawSprite(iBricks[29]);
		UG::DrawSprite(iBricks[30]);
		UG::DrawSprite(iBricks[31]);
		UG::DrawSprite(iBricks[32]);
		UG::DrawSprite(iBricks[33]);
		UG::DrawSprite(iBricks[34]);
		UG::DrawSprite(iBricks[35]);
		UG::DrawSprite(iBricks[36]);
		UG::DrawSprite(iBricks[37]);
		UG::DrawSprite(iBricks[38]);
		UG::DrawSprite(iBricks[39]);
		UG::DrawSprite(iBricks[40]);
		UG::DrawSprite(iBricks[41]);
		UG::DrawSprite(iBricks[42]);
		UG::DrawSprite(iBricks[43]);
		UG::DrawSprite(iBricks[44]);
		UG::DrawSprite(iBricks[45]);
		UG::DrawSprite(iBricks[46]);
		UG::DrawSprite(iBricks[47]);
		UG::DrawSprite(iBricks[48]);
		UG::DrawSprite(iBricks[49]);
		UG::DrawSprite(iBricks[50]);
		UG::DrawSprite(iBricks[51]);
		UG::DrawSprite(iBricks[52]);
		UG::DrawSprite(iBricks[53]);
		UG::DrawSprite(iBricks[54]);
		UG::DrawSprite(iBricks[55]);
		UG::DrawSprite(iBricks[56]);
		UG::DrawSprite(iBricks[57]);
		UG::DrawSprite(iBricks[58]);
		UG::DrawSprite(iBricks[59]);
		UG::DrawSprite(iBricks[60]);
		UG::DrawSprite(iBricks[61]);
		UG::DrawSprite(iBricks[62]);
		UG::DrawSprite(iBricks[63]);
		UG::DrawSprite(iBricks[64]);
		UG::DrawSprite(iBricks[65]);
		UG::DrawSprite(iBricks[66]);
		UG::DrawSprite(iBricks[67]);
		UG::DrawSprite(iBricks[68]);
		UG::DrawSprite(iBricks[69]);
		UG::DrawSprite(iBricks[70]);
		UG::DrawSprite(iBricks[71]);
		UG::DrawSprite(iBricks[72]);
		UG::DrawSprite(iBricks[73]);
		UG::DrawSprite(iBricks[74]);
		UG::DrawSprite(iBricks[75]);
		UG::DrawSprite(iBricks[76]);
		UG::DrawSprite(iBricks[77]);
		UG::DrawSprite(iBricks[78]);
		UG::DrawSprite(iBricks[79]);
		UG::DrawSprite(iBricks[80]);
		UG::DrawSprite(iBricks[81]);
		UG::DrawSprite(iBricks[82]);
		UG::DrawSprite(iBricks[83]);
		UG::DrawSprite(iBricks[84]);
		UG::DrawSprite(iBricks[85]);
		UG::DrawSprite(iBricks[86]);
		UG::DrawSprite(iBricks[87]);

		//Setting the position of the ball to be the arrays for the ball position
		UG::SetSpritePosition(iBall, fBallPos[0], fBallPos[1]);

		//Setting the position for our score and drawing it to the screen
		UG::SetSpritePosition(score1[s], 130, 720);
		UG::SetSpritePosition(score2[s1], 79, 720);
		UG::SetSpritePosition(score3[s2], 28, 720);
		UG::DrawSprite(score1[s]);
		UG::DrawSprite(score2[s1]);
		UG::DrawSprite(score3[s2]);
		//Setting the position for our deaths and drawing it to the screen
		UG::SetSpritePosition(deathstext[deaths], 974, 720);
		UG::DrawSprite(deathstext[deaths]);
		
		//Setting the balls start direction
		float fAng = 0.5f;
		float fBallDX = cosf(fAng);
		float fBallDY = sinf(fAng);
		//Giving the ball movement
		fOldX = fBallPos[0];
		fOldY = fBallPos[1];
	
		if (fBallPos[1] < 0)
		{
			deaths++;
			fSpeed = 3.0f;
			fBallPos[0] = 512.0f;
			fBallPos[1] = 150.0f;
			up = true;
		}
		else if (fBallPos[0] < 20)
		//if (UG::IsKeyDown(UG::KEY_Z))
		{
			fBallPos[0] += fBallDX * fSpeed;
			fBallPos[1] += fBallDY * fSpeed;
			UG::SetSpritePosition(iBall, fBallPos[0], fBallPos[1]);
			right = true;
		}
		else if (fBallPos[0] > 990)
		{
			fBallPos[0] += -fBallDX * fSpeed;
			fBallPos[1] += fBallDY * fSpeed;
			UG::SetSpritePosition(iBall, fBallPos[0], fBallPos[1]);
			right = false;
		}
		else if (fBallPos[1] > (g_iScreenHeight - 75))
		{
			fBallPos[0] += fBallDX * fSpeed;
			fBallPos[1] += -fBallDY * fSpeed;
			UG::SetSpritePosition(iBall, fBallPos[0], fBallPos[1]);
			up = false;
		}
		else 
		{
			if (right)
			{
				fBallPos[0] += fBallDX * fSpeed;

			}
			if (!right)
			{
				fBallPos[0] += -fBallDX * fSpeed;
			}
			if (up)
			{
				fBallPos[1] += fBallDY * fSpeed;
			}
			if (!up)
			{
				fBallPos[1] += -fBallDY * fSpeed;
			}			
		}

		/*cout << "BallAngle: " << fAng << "\n";
		cout << "BallX: " << fBallPos[0] << "\n";
		cout << "BallY: " << fBallPos[1] <<  "\n";
		cout << "DX: " << fBallDX << "\n";
		cout << "DX: " << fBallDY << "\n\n\n";*/

		//cout << fPlayerPos[0] << ", " << fPlayerPos[1] << "\n";
		//cout << round(fBallPos[0]) << ", " << round(fBallPos[1]) << "\n";

		int iBallCollidingPointsX[11]=
		{
			round(fBallPos[0]) - 5,
			round(fBallPos[0]) - 4,
			round(fBallPos[0]) - 3,
			round(fBallPos[0]) - 2,
			round(fBallPos[0]) - 5,
			round (fBallPos[0]),
			round(fBallPos[0]) + 1,
			round(fBallPos[0]) + 2,
			round(fBallPos[0]) + 3,
			round(fBallPos[0]) + 4,
			round(fBallPos[0]) + 5,
		};
		int iBallCollidingPointsY[11] =
		{
			round(fBallPos[1]) - 5,
			round(fBallPos[1]) - 4,
			round(fBallPos[1]) - 3,
			round(fBallPos[1]) - 2,
			round(fBallPos[1]) - 5,
			round(fBallPos[1]),
			round(fBallPos[1]) + 1,
			round(fBallPos[1]) + 2,
			round(fBallPos[1]) + 3,
			round(fBallPos[1]) + 4,
			round(fBallPos[1]) + 5
		};

		int iPlayerCollidingPointsX[60] =
		{
			round(fPlayerPos[0]) - -30,
			round(fPlayerPos[0]) - 29,
			round(fPlayerPos[0]) - 28,
			round(fPlayerPos[0]) - 27,
			round(fPlayerPos[0]) - 26,
			round(fPlayerPos[0]) - 25,
			round(fPlayerPos[0]) - 24,
			round(fPlayerPos[0]) - 23,
			round(fPlayerPos[0]) - 22,
			round(fPlayerPos[0]) - 21,
			round(fPlayerPos[0]) - 20,
			round(fPlayerPos[0]) - 19,
			round(fPlayerPos[0]) - 18,
			round(fPlayerPos[0]) - 17,
			round(fPlayerPos[0]) - 16,
			round(fPlayerPos[0]) - 15,
			round(fPlayerPos[0]) - 14,
			round(fPlayerPos[0]) - 13,
			round(fPlayerPos[0]) - 12,
			round(fPlayerPos[0]) - 11,
			round(fPlayerPos[0]) - 10,
			round(fPlayerPos[0]) - 9,
			round(fPlayerPos[0]) - 8,
			round(fPlayerPos[0]) - 7,
			round(fPlayerPos[0]) - 6,
			round(fPlayerPos[0]) - 5,
			round(fPlayerPos[0]) - 4,
			round(fPlayerPos[0]) - 3,
			round(fPlayerPos[0]) - 2,
			round(fPlayerPos[0]) - 1,
			round(fPlayerPos[0]),
			round(fPlayerPos[0]) + 1,
			round(fPlayerPos[0]) + 2,
			round(fPlayerPos[0]) + 3,
			round(fPlayerPos[0]) + 4,
			round(fPlayerPos[0]) + 5,
			round(fPlayerPos[0]) + 6,
			round(fPlayerPos[0]) + 7,
			round(fPlayerPos[0]) + 8,
			round(fPlayerPos[0]) + 9,
			round(fPlayerPos[0]) + 10,
			round(fPlayerPos[0]) + 11,
			round(fPlayerPos[0]) + 12,
			round(fPlayerPos[0]) + 13,
			round(fPlayerPos[0]) + 14,
			round(fPlayerPos[0]) + 15,
			round(fPlayerPos[0]) + 16,
			round(fPlayerPos[0]) + 17,
			round(fPlayerPos[0]) + 18,
			round(fPlayerPos[0]) + 19,
			round(fPlayerPos[0]) + 20,
			round(fPlayerPos[0]) + 21,
			round(fPlayerPos[0]) + 22,
			round(fPlayerPos[0]) + 23,
			round(fPlayerPos[0]) + 24,
			round(fPlayerPos[0]) + 25,
			round(fPlayerPos[0]) + 26,
			round(fPlayerPos[0]) + 27,
			round(fPlayerPos[0]) + 28,
			round(fPlayerPos[0]) + 29
		};

		int iPlayerRebound;
		if ((fBallPos[1] < 60) && (fBallPos[1] > 40) )
		{
			for (int i = 0; i < 60; i++)
			{
				iPlayerRebound = iPlayerCollidingPointsX[i];
				//cout << iPlayerRebound << "\n";
				if (iPlayerRebound == round(fBallPos[0]))
				{
					//cout << "PlayerX: " << iPlayerRebound << "  ||  BallX: " << round(fBallPos[0]) << "\n";

					if (UG::IsKeyDown(UG::KEY_A) || UG::IsKeyDown(UG::KEY_D))
					{
						int r = rand() % 2 + 1;
						if (r = 1)
						{
							fSpeed = rand() % 5 + (fSpeed);
						}
					}
					else {
						fSpeed = 4.0f;
					}
					up = true;
				}
			}
		}
		
		/*int iBX = 0;
		int iBY = 0;
		int iBL = 0;
		
		for (int l = 0; l < 88; l++)
		{
			for (int k = 0; k < 8; k++)
			{
				for (int j = 0; j < 11; j++)
				{
					iBX = fBlockX[j];
					iBY = fBlockY[k];
					if (round(fBallPos[0]) > (iBX - 40) && round(fBallPos[0]) < (iBX + 40) &&
						round(fBallPos[1]) < (iBY + 22) && round(fBallPos[1]) > (iBY - 22))
					{
						iBL = iBricks[l];
						UG::DestroySprite(iBL);
						up = false;
					}
				}
			}
		}
		cout << "iBL: " << iBL << "\n";
		cout << "iBX: " << iBX << "\n";
		cout << "iBY: " << iBY << "\n\n\n";*/

		//Playing a sound for every block that has been destroyed


		// Bottom Row (Yellow)
		if (bIsDetectable[87])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[87]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[87] = false;
			}
		}
		if (bIsDetectable[86])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[86]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[86] = false;
			}
		}
		if (bIsDetectable[85])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[85]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[85] = false;
			}
		}
		if (bIsDetectable[84])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[84]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[84] = false;
			}
		}
		if (bIsDetectable[83])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[83]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[83] = false;
			}
		}
		if (bIsDetectable[82])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[82]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[82] = false;
			}
		}
		if (bIsDetectable[81])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[81]);
				if (round(fBallPos[0]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[81] = false;
			}
		}
		if (bIsDetectable[80])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[80]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[80] = false;
			}
		}
		if (bIsDetectable[79])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[79]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[79] = false;
			}
		}
		if (bIsDetectable[78])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[78]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[78] = false;
			}
		}
		if (bIsDetectable[77])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[7] + 22) && round(fBallPos[1]) > (fBlockY[7] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[77]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[7] + 21) && round(fBallPos[1]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[77] = false;
			}
		}

		// Top Row (Yellow)
		if (bIsDetectable[76])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[76]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[76] = false;
			}
		}
		if (bIsDetectable[75])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[75]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[75] = false;
			}
		}
		if (bIsDetectable[74])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[74]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[74] = false;
			}
		}
		if (bIsDetectable[73])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[73]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[73] = false;
			}
		}
		if (bIsDetectable[72])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[72]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[72] = false;
			}
		}
		if (bIsDetectable[71])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[71]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[71] = false;
			}
		}
		if (bIsDetectable[70])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[70]);
				if (round(fBallPos[0]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[70] = false;
			}
		}
		if (bIsDetectable[69])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[69]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[69] = false;
			}
		}
		if (bIsDetectable[68])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[68]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[68] = false;
			}
		}
		if (bIsDetectable[67])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[67]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[6]) > (fBlockY[7] - 21))
				{
					right = !right;
				}
				bIsDetectable[67] = false;
			}
		}
		if (bIsDetectable[66])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[6] + 22) && round(fBallPos[1]) > (fBlockY[6] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s++;
				UG::DestroySprite(iBricks[66]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[6] + 21) && round(fBallPos[1]) > (fBlockY[6] - 21))
				{
					right = !right;
				}
				bIsDetectable[66] = false;
			}
		}

		// Bottom Row (Green)
		if (bIsDetectable[65])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[65]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[65] = false;
			}
		}
		if (bIsDetectable[64])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[64]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[64] = false;
			}
		}
		if (bIsDetectable[63])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[63]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[63] = false;
			}
		}
		if (bIsDetectable[62])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[62]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[62] = false;
			}
		}
		if (bIsDetectable[61])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[61]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[61] = false;
			}
		}
		if (bIsDetectable[60])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[60]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[60] = false;
			}
		}
		if (bIsDetectable[59])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[59]);
				if (round(fBallPos[0]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[59] = false;
			}
		}
		if (bIsDetectable[58])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[58]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[58] = false;
			}
		}
		if (bIsDetectable[57])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[57]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[57] = false;
			}
		}
		if (bIsDetectable[56])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[56]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[56] = false;
			}
		}
		if (bIsDetectable[55])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[5] + 22) && round(fBallPos[1]) > (fBlockY[5] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[55]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[5] + 21) && round(fBallPos[1]) > (fBlockY[5] - 21))
				{
					right = !right;
				}
				bIsDetectable[55] = false;
			}
		}

		// Top Row (Green)
		if (bIsDetectable[54])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[54]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[54] = false;
			}
		}
		if (bIsDetectable[53])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[53]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[53] = false;
			}
		}
		if (bIsDetectable[52])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[52]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[52] = false;
			}
		}
		if (bIsDetectable[51])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[51]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[51] = false;
			}
		}
		if (bIsDetectable[50])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[50]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[50] = false;
			}
		}
		if (bIsDetectable[49])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[49]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[49] = false;
			}
		}
		if (bIsDetectable[48])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[48]);
				if (round(fBallPos[0]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[48] = false;
			}
		}
		if (bIsDetectable[47])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[47]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[47] = false;
			}
		}
		if (bIsDetectable[46])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[46]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[46] = false;
			}
		}
		if (bIsDetectable[45])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[45]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[6]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[45] = false;
			}
		}
		if (bIsDetectable[44])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[4] + 22) && round(fBallPos[1]) > (fBlockY[4] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[44]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[4] + 21) && round(fBallPos[1]) > (fBlockY[4] - 21))
				{
					right = !right;
				}
				bIsDetectable[44] = false;
			}
		}

		// Bottom Row (Orange)
		if (bIsDetectable[43])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[43]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[43] = false;
			}
		}
		if (bIsDetectable[42])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[42]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[42] = false;
			}
		}
		if (bIsDetectable[41])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[41]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[41] = false;
			}
		}
		if (bIsDetectable[40])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[40]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[40] = false;
			}
		}
		if (bIsDetectable[39])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[39]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[39] = false;
			}
		}
		if (bIsDetectable[38])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[38]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[38] = false;
			}
		}
		if (bIsDetectable[37])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[37]);
				if (round(fBallPos[0]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[37] = false;
			}
		}
		if (bIsDetectable[36])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[36]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[36] = false;
			}
		}
		if (bIsDetectable[35])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[35]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[35] = false;
			}
		}
		if (bIsDetectable[34])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[34]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[34] = false;
			}
		}
		if (bIsDetectable[33])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[3] + 22) && round(fBallPos[1]) > (fBlockY[3] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[33]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[3] + 21) && round(fBallPos[1]) > (fBlockY[3] - 21))
				{
					right = !right;
				}
				bIsDetectable[33] = false;
			}
		}

		// Top Row (Orange)
		if (bIsDetectable[32])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[32]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[32] = false;
			}
		}
		if (bIsDetectable[31])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[31]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[31] = false;
			}
		}
		if (bIsDetectable[30])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[30]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[30] = false;
			}
		}
		if (bIsDetectable[29])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[29]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[29] = false;
			}
		}
		if (bIsDetectable[28])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[28]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[28] = false;
			}
		}
		if (bIsDetectable[27])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[27]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[27] = false;
			}
		}
		if (bIsDetectable[26])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[26]);
				if (round(fBallPos[0]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[26] = false;
			}
		}
		if (bIsDetectable[25])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[25]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[25] = false;
			}
		}
		if (bIsDetectable[24])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[24]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[24] = false;
			}
		}
		if (bIsDetectable[23])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[23]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[6]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[23] = false;
			}
		}
		if (bIsDetectable[22])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[2] + 22) && round(fBallPos[1]) > (fBlockY[2] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=3;
				UG::DestroySprite(iBricks[22]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[2] + 21) && round(fBallPos[1]) > (fBlockY[2] - 21))
				{
					right = !right;
				}
				bIsDetectable[22] = false;
			}
		}

		// Bottom Row (Red)
		if (bIsDetectable[21])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[21]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[21] = false;
			}
		}
		if (bIsDetectable[20])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[20]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[20] = false;
			}
		}
		if (bIsDetectable[19])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[19]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[19] = false;
			}
		}
		if (bIsDetectable[18])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[18]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[18] = false;
			}
		}
		if (bIsDetectable[17])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[17]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[17] = false;
			}
		}
		if (bIsDetectable[16])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[16]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[16] = false;
			}
		}
		if (bIsDetectable[15])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[15]);
				if (round(fBallPos[0]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[15] = false;
			}
		}
		if (bIsDetectable[14])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[14]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[14] = false;
			}
		}
		if (bIsDetectable[13])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[13]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[13] = false;
			}
		}
		if (bIsDetectable[12])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[12]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[12] = false;
			}
		}
		if (bIsDetectable[11])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[1] + 22) && round(fBallPos[1]) > (fBlockY[1] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[11]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[1] + 21) && round(fBallPos[1]) > (fBlockY[1] - 21))
				{
					right = !right;
				}
				bIsDetectable[11] = false;
			}
		}

		// Top Row (Red)
		if (bIsDetectable[10])
		{
			if (round(fBallPos[0]) > (fBlockX[10] - 40) && round(fBallPos[0]) < (fBlockX[10] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[10]);
				if (round(fBallPos[0]) > (fBlockX[10] - 39) && round(fBallPos[0]) < (fBlockX[10] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[10] = false;
			}
		}
		if (bIsDetectable[9])
		{
			if (round(fBallPos[0]) > (fBlockX[9] - 40) && round(fBallPos[0]) < (fBlockX[9] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[9]);
				if (round(fBallPos[0]) > (fBlockX[9] - 39) && round(fBallPos[0]) < (fBlockX[9] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[9] = false;
			}
		}
		if (bIsDetectable[8])
		{
			if (round(fBallPos[0]) > (fBlockX[8] - 40) && round(fBallPos[0]) < (fBlockX[8] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[8]);
				if (round(fBallPos[0]) > (fBlockX[8] - 39) && round(fBallPos[0]) < (fBlockX[8] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[8] = false;
			}
		}
		if (bIsDetectable[7])
		{
			if (round(fBallPos[0]) > (fBlockX[7] - 40) && round(fBallPos[0]) < (fBlockX[7] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[7]);
				if (round(fBallPos[0]) > (fBlockX[7] - 39) && round(fBallPos[0]) < (fBlockX[7] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[7] = false;
			}
		}
		if (bIsDetectable[6])
		{
			if (round(fBallPos[0]) > (fBlockX[6] - 40) && round(fBallPos[0]) < (fBlockX[6] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[6]);
				if (round(fBallPos[0]) > (fBlockX[6] - 39) && round(fBallPos[0]) < (fBlockX[6] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[6] = false;
			}
		}
		if (bIsDetectable[5])
		{
			if (round(fBallPos[0]) > (fBlockX[5] - 40) && round(fBallPos[0]) < (fBlockX[5] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[5]);
				if (round(fBallPos[0]) > (fBlockX[5] - 39) && round(fBallPos[0]) < (fBlockX[5] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[5] = false;
			}
		}
		if (bIsDetectable[4])
		{
			if (round(fBallPos[0]) > (fBlockX[4] - 40) && round(fBallPos[0]) < (fBlockX[4] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[4]);
				if (round(fBallPos[4]) > (fBlockX[4] - 39) && round(fBallPos[0]) < (fBlockX[4] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[4] = false;
			}
		}
		if (bIsDetectable[3])
		{
			if (round(fBallPos[0]) > (fBlockX[3] - 40) && round(fBallPos[0]) < (fBlockX[3] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[3]);
				if (round(fBallPos[0]) > (fBlockX[3] - 39) && round(fBallPos[0]) < (fBlockX[3] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[3] = false;
			}
		}
		if (bIsDetectable[2])
		{
			if (round(fBallPos[0]) > (fBlockX[2] - 40) && round(fBallPos[0]) < (fBlockX[2] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[2]);
				if (round(fBallPos[0]) > (fBlockX[2] - 39) && round(fBallPos[0]) < (fBlockX[2] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[2] = false;
			}
		}
		if (bIsDetectable[1])
		{
			if (round(fBallPos[0]) > (fBlockX[1] - 40) && round(fBallPos[0]) < (fBlockX[1] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[1]);
				if (round(fBallPos[0]) > (fBlockX[1] - 39) && round(fBallPos[0]) < (fBlockX[1] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[1] = false;
			}
		}
		if (bIsDetectable[0])
		{
			if (round(fBallPos[0]) > (fBlockX[0] - 40) && round(fBallPos[0]) < (fBlockX[0] + 40) &&
				round(fBallPos[1]) < (fBlockY[0] + 22) && round(fBallPos[1]) > (fBlockY[0] - 22))
			{
				PlaySound(TEXT("./sound/blip.wav"), NULL, SND_ASYNC);
				s+=7;
				UG::DestroySprite(iBricks[0]);
				if (round(fBallPos[0]) > (fBlockX[0] - 39) && round(fBallPos[0]) < (fBlockX[0] + 39))
				{
					up = !up;
				}
				if (round(fBallPos[1]) < (fBlockY[0] + 21) && round(fBallPos[1]) > (fBlockY[0] - 21))
				{
					right = !right;
				}
				bIsDetectable[0] = false;
			}
		}


		/*for (int p = 0; p < 22; p++)
		{
			if (p == 0)
			{
				cout << "####################\n####################\n####################\n####################\n";
			}
			cout << p << ": " << bIsDetectable[(p)] << "  #  " << p+22 << ": " << bIsDetectable[(p+22)] << "   #   " << p + 44 << ": " << bIsDetectable[(p+44)] << "   #   " << p+66 << ": " << bIsDetectable[(p+66)] << "\n";
			if (p == 21)
			{
				cout << "####################\n####################\n####################\n####################\n";
			}
		}*/

		if (s >= 10)
		{
			s = (s-=10);
			s1++;
		}
		if (s1 >= 10)
		{
			s1 = (s1-=10);
			s2++;
		}
		if (s2 >= 10)
		{
			s2 = (s2-=10);
		}

		//cout << s2 << s1 << s << "\n";

		//cout << "BallX: " << round(fBallPos[0]) << "  ||  Block88X: " << fBlockX[10] << "\n";

		//The left and right movement of the player
		if (UG::IsKeyDown(UG::KEY_A))
		{
			if (fPlayerPos[0] > 40)
			{
				fPlayerPos[0] = fPlayerPos[0] - 7.0f;
				UG::SetSpritePosition(iPlayer, fPlayerPos[0], fPlayerPos[1]);
			}
		}
		if (UG::IsKeyDown(UG::KEY_D))
		{
			if (fPlayerPos[0] < 980)
			{
				fPlayerPos[0] = fPlayerPos[0] + 7.0f;
				UG::SetSpritePosition(iPlayer, fPlayerPos[0], fPlayerPos[1]);
			}
		}

		if (deaths == 4)
		{
			fSpeed = 0.0f;
			/*fBallPos[0] = 512.0f;
			fBallPos[1] = 150.0f;
			up = true;*/
			UG::SetSpritePosition(iEndScreen, (g_iScreenWidth/2), (g_iScreenHeight/2));
			UG::DrawSprite(iEndScreen);
			UG::SetSpritePosition(score1[s], ((g_iScreenWidth / 2) + 51), (g_iScreenHeight / 2));
			UG::SetSpritePosition(score2[s1], (g_iScreenWidth / 2), (g_iScreenHeight / 2));
			UG::SetSpritePosition(score3[s2], ((g_iScreenWidth / 2)-51), (g_iScreenHeight / 2));
			UG::DrawSprite(score1[s]);
			UG::DrawSprite(score2[s1]);
			UG::DrawSprite(score3[s2]);
		}
		

		/*fPlayerPos[0] = fBallPos[0];
		UG::SetSpritePosition(iPlayer, fPlayerPos[0], fPlayerPos[1]);*/

		// Quit our application when escape is pressed
		if (UG::IsKeyDown(UG::KEY_ESCAPE))
			UG::Close();

	} while (UG::Process());

	//Close down the framework by calling dispose.
	UG::Dispose();

	return 0;
}
