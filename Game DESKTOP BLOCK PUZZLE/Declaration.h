#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <string.h>
#include <SDL2/SDL_ttf.h>
//    struct Position{
//    int x;
//    int y;
//        };
//    const Position P1 = {};
//    const Position P2 = {};
//    const Position P3 = {};
int condition;
int size_need, pos1, pos2, pos3, k;
SDL_Color color;
SDL_Window *Block_Puzzle;
SDL_Renderer *RENDERER;
SDL_Texture *image, *save, *replay, *ret_game, *ButtonNot, *Button, *Gameover;
SDL_Rect pimage,pscore;
SDL_Texture *play, *no_start, *no_play, *solo_start, *solo_play, *ai_play,*j_vs_ai_play, *ai_play_score_pan,*Best;
SDL_Rect pplay, p6, preplay, psave, pret, pblock1, pblock2, pblock3, pblock4, pblock5, pblock6, pblock7, pblock8, pblock9, pblock10, pblock11, pMatrix,pMatrixVSAI, pchoice, pscoor, pbutton, pgame,pback,pscoor1,pbest;
SDL_Texture *gr, *BSc;
SDL_Texture *texture;
SDL_Surface *surf;
SDL_Texture *K01, *K02, *K03, *K04, *K05, *K06, *K07, *K08, *K09, *K10, *K11, *K12, *Blanck, *Sc, *Sco;
SDL_Rect pgr;
SDL_Rect pk;
SDL_Texture *jeu;
int w, h, wid, hit, width, height, x, y, i, j, j2, new_game, game_over, im_blocked_heeeeelp;
SDL_Event e;
SDL_Texture *clip[2][2];
int T[10][10];
SDL_Surface *surface;
