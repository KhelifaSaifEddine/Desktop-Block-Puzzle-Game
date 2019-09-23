#define _MAIN_C
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include<string.h>
#include<SDL2/SDL_ttf.h>
#include "Declaration.h"
#include "LoadGame.h"
#include <time.h>
#include "BlockEngine.h"
#include <windows.h>

extern unsigned int SCORE;
//void Portion_Texture(SDL_Texture* texture){
//        pk.x =0; pk.y=0; pk.w=1620; pk.h=900;
//        clip[0][0] = SDL_CreateTexture(RENDERER, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
//        SDL_SetTextureBlendMode(clip[0][0], SDL_BLENDMODE_BLEND);
//        SDL_Rect rect = {x,y,200 ,200};
//        SDL_SetRenderTarget(RENDERER, clip[0][0]);
//        SDL_RenderCopy(RENDERER, texture, &rect, NULL);
//        SDL_SetRenderTarget(RENDERER, NULL);
//        SDL_SetRenderDrawColor( RENDERER, 0x00, 0x00,0x00,0x00);
//        SDL_RenderCopy(RENDERER,clip[0][0],&pk,&rect);
//
//
//}
//void Control_Init(int x1, int y1){
// x= x1;
// y =y1;
//}

int main(int argc, char *argv[])
{
//    for(i=0;i<10;i++){
//        for(j=0;j<10;j++){
//            T[i][j]= (rand() % 2);
//
//        }
//    }
//      printf("--------------------\n");
//
//  for(i=0;i<=9;i++){
//
//        for(j=0;j<=9;j++){
//            if(T[i][j]==1){
//                printf("O|");
//            }else{
//                printf(".|");
//            }
//        }
//        printf("\n");
//    }
//    printf("--------------------\n");

    srand(time(NULL));
    init();

//
    init_game();
    Main_Event_Control();
//    init_game();
//    insertBlock(1,1,1);
//    afficheGrille();
//
//    insertBlock(2,1,1);
//    afficheGrille();
//
//    insertBlock(3,1,1);
//    afficheGrille();
//
//    insertBlock(4,1,1);
//    afficheGrille();
//
//    insertBlock(5,1,1);
//    afficheGrille();
//
//    insertBlock(6,1,1);
//    afficheGrille();
//
//    insertBlock(7,1,1);
//    afficheGrille();
//
//    insertBlock(8,1,1);
//    afficheGrille();
//
//    insertBlock(9,,1);
//    afficheGrille();
//     surf = IMG_Load("A/Start.png");
//     width = surf->w;
//     height = surf->h;
//     texture = SDL_CreateTextureFromSurface(RENDERER,surf);
//
//SDL_FreeSurface(surf);
//
//Control_Init(200,0);
//Portion_Texture(texture);

while(1){
   // while(SDL_PollEvent(&e)) if(e.type == SDL_QUIT) quit = 1;

    SDL_RenderPresent(RENDERER);
}
}

