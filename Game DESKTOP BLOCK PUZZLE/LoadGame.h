#define _MAIN_C
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <string.h>
#include <SDL2/SDL_ttf.h>
#include "Declaration.h"
#define pos1 970
#define pos2 80
#define pos3 20
#include <time.h>
#include "BlockEngine.h"

void init();
void LoadGame();
void showMatrix();
void showMatrix_with_Transparancy(int k);
void Bring_Blocks(int pos, int First, int oldpos, SDL_Texture *tex, SDL_Rect re);
void Move_Blocks();
void Break_Blocks();
void RE_FILL_Choice(int First);
void Blocker_Size_init();
SDL_Rect Block_Type_Choice(int choice);
SDL_Texture *Type_Choice(int choice);
void SELECTED_ITEM_POS(int choice);
void PLAY_GAME();
void LoadGame_Event_Control();
Block_Blocked_Condition_effect_1();
Block_Blocked_Condition_effect_2();
Block_Blocked_Condition_effect_3();
void Block_Blocked(SDL_Texture *tex, SDL_Rect r, int alpha, int on);
void Completment_Block(SDL_Texture *tex, SDL_Rect rossa, int on);
void Completment_Block2(SDL_Texture *tex, SDL_Rect rossa, int on);
void switch_image_play_for_AI_only();
void AI_play_alone();
void switch_image_play_for_J_VS_AI();
void showMatrix_VS();
void Show_Best_Score();
