/*****************************************************************************/
/*  Автор         		: Дракончик				                             */
/*  Приставка     		: Sony PlayStation 2					             */
/*  ОС			  		: OSDSYS											 */
/*  Язык	      		: GNU C                                              */
/*                                                                           */
/*  Содержимое файла	: Стадия игровой детельности                         */
/*  Атрибут файла		: SOURCE                                             */
/*  Имя файла     		: gameState.c	                                     */
/*                                                                           */
/*****************************************************************************/

#include "include/gameState.h"
#include "include/menuState.h"
#include "include/overState.h"
#include "include/introState.h"
#include "include/textToGraphics.h"
#include "include/pad.h"
#include "include/musicManager.h"


extern StateMachine GameMachineState;

/****** User External Files ********/
#include "extern/gameState.ext"

/****** User Table Files ***********/


/****** User Define Files ***********/
#include "define/gameState.def"

GSTEXTURE GameBG;
BGM MikuSong;


void GameStart(GSGLOBAL* gsGlobal)
{
	char temp[4096];
	strcpy(temp, relativePath);
	strcat(temp, PickMusic(2));
	MikuSong.fileName = temp;
	
	LoadMusic(&MikuSong);

	char tempy[4096];
	strcpy(tempy, relativePath);
	strcat(tempy, GIRLBGIMAGE);
	gsKit_texture_png(gsGlobal, &GameBG,tempy);
	
	
	SetUpFont(gsGlobal);

}

void GameUpdate(GSGLOBAL* gsGlobal)
{
	// This part here plays the music
		PlayMusic(&MikuSong);
}

void GameDraw(GSGLOBAL* gsGlobal, u64 colour)
{
	gsKit_prim_sprite_texture(gsGlobal, &GameBG,0,  // X1
						0,  // Y2
						0.0f,  // U1
						0.0f,  // V1
						GameBG.Width * 2, // X2
						GameBG.Height * 2, // Y2
						GameBG.Width * 2, // U2
						GameBG.Height * 2, // V2
						2,
						colour);	
}

void GameEnd(GSGLOBAL* gsGlobal)
{

}

StateManager GameState =
{
	GameStart,
	GameUpdate,
	GameDraw,
	GameEnd
};
