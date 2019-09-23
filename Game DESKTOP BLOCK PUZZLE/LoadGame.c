#define _MAIN_C
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <string.h>
#include <SDL2/SDL_ttf.h>
#include "Declaration.h"
#include <time.h>
#include "BlockEngine.h"
#include <math.h>
#include <windows.h>
#include "AIBlock.h"

extern unsigned int SCORE;
extern propsedBlock prpBlck[3];
extern propsedBlock AIMulPrpBlck[3];
extern int AIMulGameGr[10][10];
extern int MulSCORE;
SDL_Texture *Type_Choice(int choice)
{
    switch (choice)
    {
    case 1:
        return K02;
    case 2:
        return K03;
    case 3:
        return K04;
    case 4:
        return K05;
    case 5:
        return K06;
    case 6:
        return K07;
    case 7:
        return K08;
    case 8:
        return K09;
    case 9:
        return K10;
    case 10:
        return K11;
    case 11:
        return K12;
    default:
        return NULL;
    }
}

SDL_Rect Block_Type_Choice(int choice)
{
    switch (choice)
    {
    case 1:
        return pblock1;
    case 2:
        return pblock2;
    case 3:
        return pblock3;
    case 4:
        return pblock4;
    case 5:
        return pblock5;
    case 6:
        return pblock6;
    case 7:
        return pblock7;
    case 8:
        return pblock8;
    case 9:
        return pblock9;
    case 10:
        return pblock10;
    case 11:
        return pblock11;
    }
}

void LoadStartBar()
{
    pgr.x = 0;
    pgr.y = 0;
    pgr.h = h;
    pgr.w = w;
    SDL_RenderCopy(RENDERER, image, NULL, &pgr);
    SDL_QueryTexture(play, NULL, NULL, &pplay.w, &pplay.h);
    pplay.x = w / 2 - (pplay.w / 2);
    pplay.y = 5 * h / 10 - (pplay.h / 2) + 130;
    SDL_RenderCopy(RENDERER, play, NULL, &pplay);
    SDL_RenderPresent(RENDERER);
}

void init()
{
    SDL_Init(SDL_INIT_VIDEO);
    w = 1366;
    h = 768;
    TTF_Init();
    Block_Puzzle = SDL_CreateWindow("Block_Puzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
    RENDERER = SDL_CreateRenderer(Block_Puzzle, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    new_game = 1;
    game_over = 0;
    im_blocked_heeeeelp = 0;
    TTF_Font *font;
    font = TTF_OpenFont("A\\Polices.ttf", 48);
    if (font == NULL)
    {
        exit(-1);
    }
    SDL_Color color = {105, 0, 230, 0};
    //surface = TTF_RenderText_Solid(font, "Play", color);
    //play = SDL_CreateTextureFromSurface(RENDERER, surface);
    font = TTF_OpenFont("A\\Polices.ttf", 48);
    if (font == NULL)
    {
        exit(-1);
    }
    surface = TTF_RenderText_Solid(font, "Gameover", color);
    Gameover = SDL_CreateTextureFromSurface(RENDERER, surface);
    SDL_QueryTexture(Gameover, NULL, NULL, &pgame.w, &pgame.h);
    pgame.x = w / 2;
    pgame.y = h / 2;
    ///INSTIALISE LES POSITION DES BLOCK SUGGERER ///

    Blocker_Size_init();
    init_score3();
    ///-----------------------------------------------///
    replay = IMG_LoadTexture(RENDERER, "A/Restore.png");
    save = IMG_LoadTexture(RENDERER, "A/Save.png");
    ret_game = IMG_LoadTexture(RENDERER, "A/Play.png");
    no_start = IMG_LoadTexture(RENDERER, "A/back_nostart.png");
    ai_play = IMG_LoadTexture(RENDERER, "A/AIonly.png");
    no_play = IMG_LoadTexture(RENDERER, "A/back_noplay.png");
    j_vs_ai_play = IMG_LoadTexture(RENDERER, "A/JvsIA.png");
    solo_start = IMG_LoadTexture(RENDERER, "A/MENU.png");
    solo_play = IMG_LoadTexture(RENDERER, "A/play_menu.png");
    K01 = IMG_LoadTexture(RENDERER, "A/Start.png");
    ButtonNot = IMG_LoadTexture(RENDERER, "A/ButtonNot.png");
    Button = IMG_LoadTexture(RENDERER, "A/Button.png");
    gr = IMG_LoadTexture(RENDERER, "A/Grille.png");
    K02 = IMG_LoadTexture(RENDERER, "A/element1.png");
    K03 = IMG_LoadTexture(RENDERER, "A/element2.png");
    K04 = IMG_LoadTexture(RENDERER, "A/element3.png");
    K05 = IMG_LoadTexture(RENDERER, "A/element4.png");
    K06 = IMG_LoadTexture(RENDERER, "A/element5.png");
    K07 = IMG_LoadTexture(RENDERER, "A/element6.png");
    K08 = IMG_LoadTexture(RENDERER, "A/element7.png");
    K09 = IMG_LoadTexture(RENDERER, "A/element8.png");
    K10 = IMG_LoadTexture(RENDERER, "A/element9.png");
    K11 = IMG_LoadTexture(RENDERER, "A/element10.png");
    K12 = IMG_LoadTexture(RENDERER, "A/element11.png");
    Blanck = IMG_LoadTexture(RENDERER, "A/s.png");
    image = IMG_LoadTexture(RENDERER, "A/intro.png");
}

void LoadGame()
{

    SDL_RenderClear(RENDERER);
    pgr.x = 0;
    pgr.y = 0;
    pgr.h = h;
    pgr.w = w;

    psave.x = 169 - 50;
    psave.y = 346 - 50;
    psave.h = 100;
    psave.w = 100;

    preplay = psave;
    preplay.x = psave.x + (318 - 169);

    pret = preplay;
    pret.x = preplay.x + (318 - 169);
    pbutton.y = 130 - (49 + 49 / 2) - 49 / 3;
    pbutton.x = (795 + 490) - 49 / 3;
    pbutton.h = 65;
    pbutton.w = 65;
    SDL_RenderCopy(RENDERER, K01, NULL, &pgr);
    SDL_RenderCopy(RENDERER, save, NULL, &psave);
    SDL_RenderCopy(RENDERER, replay, NULL, &preplay);
    SDL_RenderCopy(RENDERER, ret_game, NULL, &pret);
    SDL_RenderCopy(RENDERER, Button, NULL, &pbutton);
    showMatrix();
   // Show_score2();
    SDL_RenderPresent(RENDERER);
}

void Main_Event_Control()
{
    /*updateBestScore("jhghb",35464);
    updateBestScore("jhghb",35464);
    updateBestScore("jhghb",35464);*/
    LoadStartBar();

    condition = 1;
    while (condition)
    {
        SDL_WaitEvent(&e);
        switch (e.type)
        {
        case SDL_MOUSEBUTTONDOWN:
        {
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                if (e.button.x < 464 && e.button.x > 100 && e.button.y < 165 && e.button.y > 88)
                {
                    LoadGame_Event_Control();
                }
                if (e.button.x < 464 && e.button.x > 100 && e.button.y < 292 && e.button.y > 215)
                {
                    //PARTIE I.A
                    switch_image_play_for_AI_only();
                    AI_play_alone();
                }
                if (e.button.x < 464 && e.button.x > 100 && e.button.y < 424 && e.button.y > 343)
                {
                    switch_image_play_for_J_VS_AI();
                    J_VS_AI_play();
                    //PARTIE Joueur vs I.A
                }
                if (e.button.x < 464 && e.button.x > 100 && e.button.y < 677 && e.button.y > 600)
                {
                    SDL_Quit();
                    exit(0);
                }
                //                       if(e.button.x<w/2+(p7.w/2)&&e.button.x>w/2-(p7.w/2)&&e.button.y<6*h/10+(p6.h/2)&&e.button.y>6*h/10-(p6.h/2))
                //                       {
                //
                //                       }
                //                        if(e.button.x<w/2+(p11.w/2)&&e.button.x>w/2-(p11.w/2)&&e.button.y<8*h/10+(p6.h/2)&&e.button.y>8*h/10-(p6.h/2))
                //   button quitt�              {
                //                            exit(-1);
                //                        }
                break;
            }
        }
        break;

        case SDL_QUIT:
            condition = 0;
            break;
        }
    }
}

void showMatrix()
{
    pMatrix.h = 491;
    pMatrix.w = 491;
    pMatrix.x = (1366 - 491) - (49 / 2) * 3 - (49 / 5);
    pMatrix.y = (768 - 491) - (49 / 2) * 6;
    SDL_SetTextureColorMod(gr, 255, 255, 255);
    SDL_RenderCopy(RENDERER, gr, NULL, &pMatrix);
    pgr.h = 49;
    pgr.w = 49;
    pgr.x = (1366 - 491) - (49 / 2) * 3 - (49 / 5);
    pgr.y = (768 - 491) - (49 / 2) * 6;
    int IH=0,JV=0;
    for (IH = 0; IH <= 9; IH++)
    {
        pgr.x = ((1366 - 491) - (49 / 2) * 3 - (49 / 5)) + 49 * IH;
        for (JV = 0; JV <= 9; JV++)
        {
            if (grille[JV][IH] == 1)
            {

                pgr.y = ((768 - 491) - (49 / 2) * 6) + 49 * JV;
                SDL_SetTextureColorMod(K02, 255, 255, 255);
                SDL_RenderCopy(RENDERER, K02, NULL, &pgr);
            }
        }
    }
    //afficheGrille();
}

void showMatrix_VS()
{
    pMatrixVSAI.h = 491;
    pMatrixVSAI.w = 491;
    pMatrixVSAI.x = (49 / 2) * 3 - (49 / 5);
    pMatrixVSAI.y = (768 - 491) - (49 / 2) * 6;
    SDL_SetTextureColorMod(gr, 255, 255, 255);
    SDL_RenderCopy(RENDERER, gr, NULL, &pMatrixVSAI);
    pgr.h = 49;
    pgr.w = 49;
    pgr.x = (49 / 2) * 3 - (49 / 5);
    pgr.y = (768 - 491) - (49 / 2) * 6;
    int IH=0,JV=0;
    for (IH = 0; IH <= 9; IH++)
    {
        pgr.x = ((49 / 2) * 3 - (49 / 5)) + 49 * IH;
        for (JV = 0; JV <= 9; JV++)
        {
            if (AIMulGameGr[JV][IH] == 1)
            {

                pgr.y = ((768 - 491) - (49 / 2) * 6) + 49 * JV;
                SDL_SetTextureColorMod(K02, 255, 255, 255);
                SDL_RenderCopy(RENDERER, K02, NULL, &pgr);
            }
        }
    }
    //afficheGrille();
}

void showMatrix_with_Transparancy(int i)
{

    pMatrix.h = 491;
    pMatrix.w = 491;
    pMatrix.x = (1366 - 491) - (49 / 2) * 3 - (49 / 5);
    pMatrix.y = (768 - 491) - (49 / 2) * 6;
    SDL_SetTextureColorMod(gr, i, i, i);
    SDL_RenderCopy(RENDERER, gr, NULL, &pMatrix);
    pgr.h = 49;
    pgr.w = 49;
    pgr.x = (1366 - 491) - (49 / 2) * 3 - (49 / 5);
    pgr.y = (768 - 491) - (49 / 2) * 6;

    for (k = 0; k <= 9; k++)
    {
        pgr.x = ((1366 - 491) - (49 / 2) * 3 - (49 / 5)) + 49 * k;
        for (j = 0; j <= 9; j++)
        {
            if (grille[j][k] == 1)
            {

                pgr.y = ((768 - 491) - (49 / 2) * 6) + 49 * j;
                SDL_SetTextureColorMod(K02, i, i, i);
                SDL_RenderCopy(RENDERER, K02, NULL, &pgr);
            }
        }
    }
    Sleep(9);
}

void Bring_Blocks(int pos, int First, int oldpos, SDL_Texture *tex, SDL_Rect re)
{
    if (First == 1)
    {

        j = 0;
        for (i = 1200; i >= pos; i = i - 50)
        {

            re.x = i;
            SDL_SetTextureAlphaMod(tex, 255);
            SDL_RenderCopy(RENDERER, tex, NULL, &re);
            SDL_RenderPresent(RENDERER);
            j = j + 25;
            SDL_RenderCopy(RENDERER, Blanck, NULL, &re);
        }
        SDL_RenderCopy(RENDERER, tex, NULL, &re);
        SDL_RenderPresent(RENDERER);
    }
    else
    {
        j = 0;
        for (i = oldpos; i >= pos; i = i - 50)
        {
            SDL_RenderCopy(RENDERER, Blanck, NULL, &re);
            re.x = i;
            SDL_SetTextureAlphaMod(K03, +5);
            SDL_RenderCopy(RENDERER, K03, NULL, &re);
            SDL_RenderPresent(RENDERER);
            j = j + 25;
        }
    }
    return;
}

void Bring_Blocks_VS(int pos, int First, int oldpos, SDL_Texture *tex, SDL_Rect re)
{
    if (First == 1)
    {

        j = 0;
        for (i = 1200-750; i >= pos; i = i - 50)
        {

            re.x = i;
            SDL_SetTextureAlphaMod(tex, 255);
            SDL_RenderCopy(RENDERER, tex, NULL, &re);
            SDL_RenderPresent(RENDERER);
            j = j + 25;
            SDL_RenderCopy(RENDERER, Blanck, NULL, &re);
        }
        SDL_RenderCopy(RENDERER, tex, NULL, &re);
        SDL_RenderPresent(RENDERER);
    }
    else
    {
        j = 0;
        for (i = oldpos; i >= pos; i = i - 50)
        {
            SDL_RenderCopy(RENDERER, Blanck, NULL, &re);
            re.x = i;
            SDL_SetTextureAlphaMod(K03, +5);
            SDL_RenderCopy(RENDERER, K03, NULL, &re);
            SDL_RenderPresent(RENDERER);
            j = j + 25;
        }
    }
    return;
}

void LoadGame_Event_Control()
{
    updateBestScore("",0);


    switch_image_play();
 Show_Best_Score();
      Show_Best();

    condition = 1;
    while (condition)
    {

        SDL_WaitEvent(&e);
        switch (e.type)
        {

        case SDL_MOUSEBUTTONDOWN:
        {
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:

                if (e.button.x < preplay.x + 80 && e.button.x > preplay.x && e.button.y<preplay.y + 80 && e.button.y> preplay.y)
                {

                    //updatePrpBlock(1);
                    //updatePrpBlock(2);
                    //updatePrpBlock(3);

                    init_game();

                    new_game = 1;
                    PLAY_GAME();
                    ///Evenement De LoadGame//
                }
                if (e.button.x < pret.x + 80 && e.button.x > pret.x && e.button.y<pret.y + 80 && e.button.y> pret.y)
                {
                    loadGame();
                    PLAY_GAME();
                    ///Evenement De LoadGame//
                }
                if (e.button.x < psave.x + 80 && e.button.x > psave.x && e.button.y<psave.y + 80 && e.button.y> psave.y)
                {
                    saveGame();
                    //PLAY_GAME();
                    ///Evenement De LoadGame//
                }
                break;
            }
        }
        break;

        case SDL_QUIT:
            condition = 0;
            break;
        }
    }
}

void GetBestScore(){
    SDL_Window *win;
    updateBestScore("",0);
    char nameInput[100];
    strcpy(nameInput,"");
    win=NULL;
    win = SDL_CreateWindow("Inserer Best Score",w/2-200,h/2-50,400,100,SDL_WINDOW_RESIZABLE);
    SDL_Renderer *RENDERER_1;
    RENDERER_1 = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    int get=1;
    int cIn=0;
    char let[1];
    strcpy(let,"");
    SDL_Event eve;

    SDL_Color color = {105, 0, 230, 0};
    SDL_Rect wPos,tPos;
    SDL_Texture *whiteRect,*texTex,*whiteness;
    whiteRect = IMG_LoadTexture(RENDERER_1,"A\\whiteRect.png");
//    whit = IMG_LoadTexture(RENDERER_1,"A\\images.png");
    TTF_Font *nameGr;
    nameGr = TTF_OpenFont("A\\Polices.ttf", 50);
    //surface = TTF_RenderText_Solid(font, "dkhl", color);

    //SDL_QueryTexture(whiteRect,NULL,NULL,&wPos.w,&wPos.h);

    tPos.h=30;//wPos.h;
    tPos.w=30;//wPos.w;
    tPos.x=20;
    tPos.y=20;
    wPos.x =0;
    wPos.y =0;
    wPos.h=100;
    wPos.w=400;
    while(get){
        SDL_WaitEvent(&eve);
        switch(eve.type){
        case SDL_KEYDOWN:
            if(eve.key.keysym.sym==SDLK_RETURN){
                if(strcmp(nameInput,"")!=0){
                    updateBestScore(nameInput,SCORE);
                }
                SDL_DestroyWindow(win);
                return;
            }else if(eve.key.keysym.sym==SDLK_BACKSPACE){
                //printf("<Effacement>\n");
                nameInput[cIn]='\0';
                if(cIn>0){
                    cIn--;
                }
                printf("%s\n",nameInput);
                surface = TTF_RenderText_Solid(nameGr, nameInput, color);

                tPos.w =  14*(cIn + 1);
                texTex = SDL_CreateTextureFromSurface(RENDERER_1, surface);
            }
            else{
                //printf("%c",(char)eve.key.keysym.sym);
                let[0] = (char)eve.key.keysym.sym;
                strcat(nameInput,let);
                printf("%s\n",nameInput);
                surface = TTF_RenderText_Solid(nameGr, nameInput, color);

                tPos.w =  14*(cIn + 1);
                texTex = SDL_CreateTextureFromSurface(RENDERER_1, surface);
                cIn++;
            }
            //AFFICHAGE DU NOM
            break;
        case SDL_QUIT:
            get=0;
            break;
        }
        SDL_RenderCopy(RENDERER_1,whiteRect,NULL,&wPos);
        SDL_RenderCopy(RENDERER_1,texTex,NULL,&tPos);
        SDL_RenderPresent(RENDERER_1);
    }
    SDL_DestroyWindow(win);
    updateBestScore(nameInput,SCORE);
}

void PLAY_GAME()
{

    updateBestScore("",0);
    condition = 1;

    LoadGame();
    //Show_Best_Score();
    Show_score();
    // showMatrix();
    SDL_RenderPresent(RENDERER);
    RE_FILL_Choice(1);
    int cp_t=0;
    if (prpBlck[0].isBlocked == 1)
        {
            SDL_RenderClear(RENDERER);
            Block_Blocked(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 120, 800);
        if (prpBlck[1].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
            else{
                Completment_Block2(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
        if (prpBlck[2].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }
            SDL_RenderPresent(RENDERER);
        }
        if (prpBlck[1].isBlocked == 1)
        {
            SDL_RenderClear(RENDERER);
            Block_Blocked(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 120, 970);
            if (prpBlck[0].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }
            if (prpBlck[2].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }

            SDL_RenderPresent(RENDERER);
        }
        if (prpBlck[2].isBlocked == 1)
        {
            SDL_RenderClear(RENDERER);
            Block_Blocked(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 120, 1200);
            if (prpBlck[1].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
            if (prpBlck[0].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }

            SDL_RenderPresent(RENDERER);
        }
    while (condition)
    {

        if(prpBlck[0].isBlocked==1 && prpBlck[1].isBlocked==1 && prpBlck[2].isBlocked==1){
            while(strcmp(bestScore[cp_t].name,"")!=0){
                cp_t++;
                if(SCORE>bestScore[cp_t].score){
                    break;
                }
            }
            GetBestScore();
            LoadGame_Event_Control();
        }

        SDL_WaitEvent(&e);
        switch (e.type)
        {

        case SDL_MOUSEBUTTONDOWN:
        {
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                if (e.button.x < 800 + 70 && e.button.x > 800 && e.button.y<710 && e.button.y> 630 && new_game == 1)
                {

                    SELECTED_ITEM_POS(1);
                    im_blocked_heeeeelp = 0;
                    PLAY_GAME();
                }
                else
                {
                    if (e.button.x < 800 + 70 && e.button.x > 800 && e.button.y<710 && e.button.y> 630)
                    {
                        if (prpBlck[0].isBlocked == 0)
                        {
                            SELECTED_ITEM_POS(1);
                            im_blocked_heeeeelp = 0;
                            PLAY_GAME();
                        }
                    }
                }
                if (e.button.x < 800 + 70 && e.button.x > 800 && e.button.y<710 && e.button.y> 630 && new_game == 1)
                {

                    SELECTED_ITEM_POS(2);
                    im_blocked_heeeeelp = 0;
                    PLAY_GAME();
                }
                else
                {
                    if (e.button.x < 970 + 70 && e.button.x > 970 && e.button.y<710 && e.button.y> 630)
                    {
                        if (prpBlck[1].isBlocked == 0)
                        {
                            im_blocked_heeeeelp = 0;
                            SELECTED_ITEM_POS(2);
                            PLAY_GAME();
                        }
                    }
                }
                if (e.button.x < 1200 + 70 && e.button.x > 1200 && e.button.y<710 && e.button.y> 630 && new_game == 1)
                {

                    im_blocked_heeeeelp = 0;
                    SELECTED_ITEM_POS(3);
                    PLAY_GAME();
                }

                else
                {
                    if (e.button.x < 1200 + 70 && e.button.x > 1200 && e.button.y<710 && e.button.y> 630)
                    {
                        if (prpBlck[2].isBlocked == 0)
                        {
                            im_blocked_heeeeelp = 0;
                            SELECTED_ITEM_POS(3);
                            PLAY_GAME();
                        }
                    }
                }
                if (e.button.x < pbutton.x + 40 && e.button.x > pbutton.x && e.button.y<pbutton.y + 40 && e.button.y> pbutton.y)
                {

                    printf("Normalement pause\n");
                    LoadGame_Event_Control();
                    return;
                }

            }
            break;
        }
        break;
        }
    }
}

void SELECTED_ITEM_POS(int choice)
{
    condition = 1;
    while (condition)
    {
        SDL_WaitEvent(&e);
        switch (e.type)
        {
        case SDL_MOUSEBUTTONDOWN:
        {
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:

                if (e.button.x < pMatrix.x + 490 && e.button.x > pMatrix.x && e.button.y<pMatrix.y + 490 && e.button.y> pMatrix.y)
                {
                    printf("\ni  %d \n ", ((int)((e.button.y - 130) / 49)) - 1);
                    printf(" j  %d\n ", ((int)((e.button.x - 792) / 49)) - 1);

                    if (insertBlock(((int)((e.button.y - 130) / 49)), ((int)((e.button.x - 792) / 49)), choice) != -1)
                    {
                        new_game = 0;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                break;
            }
        }
        break;
        }
    }
}

void RE_FILL_Choice(int First)
{

    if (First == 1)
    {
        Bring_Blocks(800, 1, 0, Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType));
        Bring_Blocks(970, 1, 0, Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType));
        Bring_Blocks(1200, 1, 0, Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType));
    }
}

void RE_FILL_Choice_VS(int First)
{

    if (First == 1)
    {
        Bring_Blocks_VS(800-750, 1, 0, Type_Choice(AIMulPrpBlck[0].blockType), Block_Type_Choice(AIMulPrpBlck[0].blockType));
        Bring_Blocks_VS(970-750, 1, 0, Type_Choice(AIMulPrpBlck[1].blockType), Block_Type_Choice(AIMulPrpBlck[1].blockType));
        Bring_Blocks_VS(1200-750, 1, 0, Type_Choice(AIMulPrpBlck[2].blockType), Block_Type_Choice(AIMulPrpBlck[2].blockType));
    }
}

void Blocker_Size_init()
{
    size_need = 20;
    ///BLOCK 1 _ 2x2 _L_2*2//
    pblock2.y = (768 - 491) - (49 / 2) * 6;

    pblock2.y = pblock2.y + 49 * 10 + size_need / 2;
    pblock2.h = 49 * 2 - size_need;
    pblock2.w = 49 * 2 - size_need;
    pblock4 = pblock2;
    pblock9 = pblock4;
    pblock7 = pblock4;
    ///------------------------///

    ///BLOCK 3 _ 1x5//
    pblock3.y = (768 - 491) - (49 / 2) * 6;

    pblock3.y = pblock3.y + 49 * 10 + size_need / 2;
    pblock3.h = 49 * 5 - size_need - 143;
    pblock3.w = 49 * 1 - size_need - 13;
    ///------------------------///
    ///BLOCK 1 _ 1x4 //
    pblock10.y = (768 - 491) - (49 / 2) * 5;

    pblock10.y = pblock10.y + 49 * 10 + size_need / 2;
    pblock10.h = 49 * 1 - size_need;
    pblock10.w = 49 * 4 - size_need - 80;
    ///------------------------///
    ///BLOCK 1 _ 2x1 //
    pblock5.y = (768 - 491) - (49 / 2) * 5;

    pblock5.y = pblock5.y + 49 * 10 + size_need / 2;
    pblock5.h = 49 * 1 - size_need;
    pblock5.w = 49 * 2 - size_need - 20;
    ///------------------------///

    ///------------------------///
    ///BLOCK 1 _ 2x3_T_E //
    pblock8.y = (768 - 491) - (49 / 2) * 6;

    pblock8.y = pblock8.y + 49 * 10 + size_need / 2;
    pblock8.h = 49 * 3 - size_need - 47;
    pblock8.w = 49 * 2 - size_need - 20;
    pblock6 = pblock8;
    ///------------------------///
    ///BLOCK 1 _ 3x1 //
    pblock11.y = (768 - 491) - (49 / 2) * 6;

    pblock11.y = pblock11.y + 49 * 10 + size_need / 2;
    pblock11.h = 49 * 3 - size_need - 47;
    pblock11.w = 49 * 1 - size_need - 10;
    ///------------------------///
    ///BLOCK 1 _ 1x1 //
    pblock1.y = (768 - 491) - (49 / 2) * 5;

    pblock1.y = pblock1.y + 49 * 10 + size_need / 2;
    pblock1.h = 49 * 1 - size_need;
    pblock1.w = 49 * 1 - size_need;
    ///------------------------///
}

void Block_Blocked_Condition_effect_1()
{

    return;
}

void Block_Blocked_Condition_effect_2()
{

    return;
}

void Block_Blocked_Condition_effect_3()
{

    return;
}

void Block_Blocked(SDL_Texture *tex, SDL_Rect r, int alpha, int on)
{
    r.x = on;

    SDL_SetTextureAlphaMod(tex, alpha);

    pgr.x = 0;
    pgr.y = 0;
    pgr.h = h;
    pgr.w = w;

    psave.x = 169 - 50;
    psave.y = 346 - 50;
    psave.h = 100;
    psave.w = 100;

    preplay = psave;
    preplay.x = psave.x + (318 - 169);

    pret = preplay;
    pret.x = preplay.x + (318 - 169);
    init_score();
    SDL_QueryTexture(Sc, NULL, NULL, &pscoor.w, &pscoor.h);
    pscoor.x = 795 + 49 + 49 / 2;
    pscoor.y = 130 - 49 - 49 / 2;

    SDL_RenderCopy(RENDERER, K01, NULL, &pgr);
    SDL_RenderCopy(RENDERER, save, NULL, &psave);
    SDL_RenderCopy(RENDERER, replay, NULL, &preplay);
    SDL_RenderCopy(RENDERER, ret_game, NULL, &pret);
    SDL_RenderCopy(RENDERER, Sc, NULL, &pscoor);
    SDL_RenderCopy(RENDERER, Button,NULL,&pbutton);
    showMatrix();
    SDL_RenderCopy(RENDERER, tex, NULL, &r);
}

void Block_Blocked2(SDL_Texture *tex, SDL_Rect r, int alpha, int on)
{
    r.x = on;

    SDL_SetTextureAlphaMod(tex, alpha);

    pgr.x = 0;
    pgr.y = 0;
    pgr.h = h;
    pgr.w = w;

    psave.x = 169 - 50;
    psave.y = 346 - 50;
    psave.h = 100;
    psave.w = 100;

    preplay = psave;
    preplay.x = psave.x + (318 - 169);

    pret = preplay;
    pret.x = preplay.x + (318 - 169);
    init_score();
    SDL_QueryTexture(Sc, NULL, NULL, &pscoor.w, &pscoor.h);
    pscoor.x = 795 + 49 + 49 / 2;
    pscoor.y = 130 - 49 - 49 / 2;

    pgr.x = 0;
    pgr.y = 0;
    pgr.h = h;
    pgr.w = w;
    SDL_Rect gri;
    gri.h = 491;
    gri.w = 491;
    gri.x = (1366 - 491) - (49 / 2) * 3 - (49 / 5);
    gri.y = (768 - 491) - (49 / 2) * 6;

    SDL_RenderCopy(RENDERER, ai_play, NULL, &pgr);
    SDL_RenderCopy(RENDERER, gr , NULL, &gri);
     AIMakeDecis();
        showMatrix();
        //afficheGrille();
        Show_score();

    SDL_RenderCopy(RENDERER, tex, NULL, &r);
}

void Completment_Block(SDL_Texture *tex, SDL_Rect rossa, int on)
{
    rossa.x = on;
    SDL_RenderCopy(RENDERER, tex, NULL, &rossa);
}

void Completment_Block2(SDL_Texture *tex, SDL_Rect rossa, int on)
{
    rossa.x = on;
    SDL_SetTextureAlphaMod(tex, 120);
    SDL_RenderCopy(RENDERER, tex, NULL, &rossa);
}

void Show_score()
{
    init_score();
    SDL_QueryTexture(Sc, NULL, NULL, &pscoor.w, &pscoor.h);
    pscoor.x = 795 + 49 + 20;
    pscoor.y = 130 - (49 + 49 / 2);
    SDL_RenderCopy(RENDERER, Sc, NULL, &pscoor);
}

void init_score()
{
    char *str;
    str = (char *)malloc(sizeof(100000000));
    sprintf(str, "%d", SCORE);
  //  printf("%s", str);
    TTF_Font *font;
    font = TTF_OpenFont("A\\Polices.ttf", 48);
    if (font == NULL)
    {
        exit(-1);
    }
    SDL_Color color = {105, 0, 230, 0};
    surface = TTF_RenderText_Solid(font, str, color);
    Sc = SDL_CreateTextureFromSurface(RENDERER, surface);
}

void Show_score3()
{
    init_score3();
    SDL_QueryTexture(Sco, NULL, NULL, &pscoor1.w, &pscoor1.h);
    pscoor1.x = psave.x+149;
    pscoor1.y = 130 - (49 + 49 / 2);
    SDL_RenderCopy(RENDERER, Sco, NULL, &pscoor1);
}

void init_score3()
{
    char *str;
    str = (char *)malloc(sizeof(100000000));
    sprintf(str, "%d",MulSCORE);
  //  printf("%s", str);
    TTF_Font *font;
    font = TTF_OpenFont("A\\Polices.ttf", 48);
    if (font == NULL)
    {
        exit(-1);
    }
    SDL_Color color = {105, 0, 230, 0};
    surface = TTF_RenderText_Solid(font, str, color);
    Sco = SDL_CreateTextureFromSurface(RENDERER, surface);
}


void switch_image_play()
{
    for (i = 0; i <= 90; i = i + 10)
    {
        SDL_RenderClear(RENDERER);
        pgr.x = 0;
        pgr.y = 0;
        pgr.h = h;
        pgr.w = w;

        psave.x = 169 - 50;
        psave.y = 346 - 50;
        psave.h = 100;
        psave.w = 100;

        preplay = psave;
        preplay.x = psave.x + (318 - 169);

        pret = preplay;
        pret.x = preplay.x + (318 - 169);

        SDL_SetTextureColorMod(no_start, i, i, i);
        SDL_RenderCopy(RENDERER, no_start, NULL, &pgr);

        SDL_RenderCopy(RENDERER, save, NULL, &psave);

        SDL_RenderCopy(RENDERER, replay, NULL, &preplay);

        SDL_RenderCopy(RENDERER, ret_game, NULL, &pret);
        SDL_RenderCopy(RENDERER, solo_start, NULL, &pgr);
        Show_score2();

        showMatrix_with_Transparancy(i);

        pbutton.y = 130 - (49 + 49 / 2) - 49 / 3;
        pbutton.x = (795 + 490) - 49 / 3;
        pbutton.h = 65;
        pbutton.w = 65;

        SDL_SetTextureColorMod(ButtonNot, i, i, i);
        SDL_RenderCopy(RENDERER, ButtonNot, NULL, &pbutton);
        SDL_RenderPresent(RENDERER);

        Sleep(1);
    }
     Show_Best_Score();

}

void switch_image_play_for_AI_only()
{
    SDL_RenderClear(RENDERER);
    pgr.x = 0;
    pgr.y = 0;
    pgr.h = h;
    pgr.w = w;
    SDL_Rect gri;
    gri.h = 491;
    gri.w = 491;
    gri.x = (1366 - 491) - (49 / 2) * 3 - (49 / 5);
    gri.y = (768 - 491) - (49 / 2) * 6;

    SDL_RenderCopy(RENDERER, ai_play, NULL, &pgr);
    SDL_RenderCopy(RENDERER, gr , NULL, &gri);
   // SDL_RenderPresent(RENDERER);
}

void switch_image_play_for_J_VS_AI()
{
    SDL_RenderClear(RENDERER);
    pgr.x = 0;
    pgr.y = 0;
    pgr.h = h;
    pgr.w = w;
    SDL_Rect gri_AI,gri_J;
    gri_J.h = 491;
    gri_J.w = 491;
    gri_J.x = (1366 - 491) - (49 / 2) * 3 - (49 / 5);
    gri_J.y = (768 - 491) - (49 / 2) * 6;
    gri_AI.h = 491;
    gri_AI.w = 491;
    gri_AI.x = (49 / 2) * 3 - (49 / 5);
    gri_AI.y = (768 - 491) - (49 / 2) * 6;

    SDL_RenderCopy(RENDERER, j_vs_ai_play, NULL, &pgr);
    SDL_RenderCopy(RENDERER, gr , NULL, &gri_AI);
    SDL_RenderCopy(RENDERER, gr , NULL, &gri_J);
    SDL_RenderPresent(RENDERER);
}

void AI_play_alone()
{
    init_game();
    init_AI(0);
     switch_image_play_for_AI_only(); /// Na7itlk RENDER_PRESENT MN HED FONCTION///

    while(1){
        if (prpBlck[0].isBlocked == 1)
        {
            SDL_RenderClear(RENDERER);
            Block_Blocked2(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 120, 800);
        if (prpBlck[1].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
            else{
                Completment_Block2(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
        if (prpBlck[2].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }
            SDL_RenderPresent(RENDERER);
        }
        if (prpBlck[1].isBlocked == 1)
        {
            SDL_RenderClear(RENDERER);
           Block_Blocked2(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 120, 970);
            if (prpBlck[0].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }
            if (prpBlck[2].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 1200);
            }

            SDL_RenderPresent(RENDERER);
        }
        if (prpBlck[2].isBlocked == 1)
        {
            SDL_RenderClear(RENDERER);
            Block_Blocked2(Type_Choice(prpBlck[2].blockType), Block_Type_Choice(prpBlck[2].blockType), 120, 1200);
            if (prpBlck[1].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[1].blockType), Block_Type_Choice(prpBlck[1].blockType), 980);
            }
            if (prpBlck[0].isBlocked == 0)
            {
                Completment_Block(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }
            else
            {
                Completment_Block2(Type_Choice(prpBlck[0].blockType), Block_Type_Choice(prpBlck[0].blockType), 800);
            }

            SDL_RenderPresent(RENDERER);
        }else{

        switch_image_play_for_AI_only(); /// Na7itlk RENDER_PRESENT MN HED FONCTION///
        AIMakeDecis();
        showMatrix();
        afficheGrille();
        Show_score();
            RE_FILL_Choice(1);
        }
      //   AIMakeDecis();
       // showMatrix();
      //  switch_image_play_for_AI_only(); /// Na7itlk RENDER_PRESENT MN HED FONCTION///

  //   RE_FILL_Choice(1);
        SDL_RenderPresent(RENDERER);
        printf("AI playing ...\n");
        printStat();
        Sleep(250);

        if(prpBlck[0].isBlocked==1 && prpBlck[1].isBlocked==1 && prpBlck[2].isBlocked==1) break;
    }
    printf("AI STOP playing ...\n");
}

void J_VS_AI_play()
{
    init_game();
    init_AI(1);
    int clickedChoice=0;
    int choosing=0;
    int playing=1;
    SDL_Event event;

    RE_FILL_Choice(1);
    RE_FILL_Choice_VS(1);
    //AIMakeDecis();
    showMatrix();
    showMatrix_VS();
    //afficheGrille();
    Show_score();
    Show_score3();
    SDL_RenderPresent(RENDERER);
    printf("Partie VS playing ...\n");
    //printStat();
    printAIStat();

    while(playing){
        if(choosing==0){
            SDL_WaitEvent(&event);
            switch (event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                    //switch (event.button.button)
                    //{
                        //case SDL_BUTTON_LEFT:
                            if (event.button.x < 800 + 70 && event.button.x > 800 && event.button.y<710 && event.button.y> 630)
                            {
                                clickedChoice=1;
                                choosing=1;
                            }else if (event.button.x < 970 + 70 && event.button.x > 970 && event.button.y<710 && event.button.y> 630)
                            {
                                clickedChoice=2;
                                choosing=1;
                            }else if (event.button.x < 1200 + 70 && event.button.x > 1200 && event.button.y<710 && event.button.y> 630)
                            {
                                clickedChoice=3;
                                choosing=1;
                            }else{
                                //if(clickedChoice==0)
                                    choosing=0;
                            }
                    //}
                break;
            }
        }
        if(choosing){
            SDL_WaitEvent(&event);
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:
                    //printf("\t\t\tChoosing (%d )=(%d : %d) \n",event.button.x,pMatrix.x,pMatrix.x+490);
                    //printf("\t\t\tChoosing (%d )=(%d : %d) \n",event.button.y,pMatrix.y,pMatrix.y+490);
                    if (event.button.x < pMatrix.x + 490 && event.button.x > pMatrix.x && event.button.y<pMatrix.y + 490 && event.button.y> pMatrix.y)
                    {
                        insertBlock(((int)((event.button.y - 130) / 49)), ((int)((event.button.x - 792) / 49)), clickedChoice);
                        AIMakeDecis();
                        showMatrix();
                        showMatrix_VS();
                        RE_FILL_Choice(1);
                        RE_FILL_Choice_VS(1);
                        //afficheGrille();

                        Show_score();
                        Show_score3();
                        SDL_RenderPresent(RENDERER);
                        //printStat();
                        printAIStat();
                        choosing=0;
                    }
                break;
            }
        }
        //Sleep(400);
        if((prpBlck[0].isBlocked==1 && prpBlck[1].isBlocked==1 && prpBlck[2].isBlocked==1) ||  (AIMulPrpBlck[0].isBlocked==1 && AIMulPrpBlck[1].isBlocked==1 && AIMulPrpBlck[2].isBlocked==1)) break;
        /*RE_FILL_Choice(1);
        AIMakeDecis();
        showMatrix();
        showMatrix_VS();
        //afficheGrille();
        Show_score();
        SDL_RenderPresent(RENDERER);
        printf("Partie VS playing ...\n");
        printStat();
        //Sleep(400);
        if((prpBlck[0].isBlocked==1 && prpBlck[1].isBlocked==1 && prpBlck[2].isBlocked==1) ||  (AIMulPrpBlck[0].isBlocked==1 && AIMulPrpBlck[1].isBlocked==1 && AIMulPrpBlck[2].isBlocked==1)) break;*/
    SDL_RenderClear(RENDERER);
    pback.x=0;
    pback.y=0;
    pback.w= 1366;
    pback.h= 768;
    SDL_RenderCopy(RENDERER,j_vs_ai_play,NULL,&pback);

    }
    printf("Partie VS Stoped...\n");
}

void switch_image_play2()
{
    for (i = 0; i <= 90; i = i + 10)
    {

        SDL_RenderClear(RENDERER);
        pgr.x = 0;
        pgr.y = 0;
        pgr.h = h;
        pgr.w = w;

        psave.x = 169 - 50;
        psave.y = 346 - 50;
        psave.h = 100;
        psave.w = 100;

        preplay = psave;
        preplay.x = psave.x + (318 - 169);

        pret = preplay;
        pret.x = preplay.x + (318 - 169);

        SDL_SetTextureColorMod(no_start, i, i, i);
        SDL_RenderCopy(RENDERER, no_start, NULL, &pgr);
        SDL_SetTextureColorMod(save, i, i, i);
        SDL_RenderCopy(RENDERER, save, NULL, &psave);
        SDL_SetTextureColorMod(replay, i, i, i);
        SDL_RenderCopy(RENDERER, replay, NULL, &preplay);
        SDL_SetTextureColorMod(ret_game, i, i, i);
        SDL_RenderCopy(RENDERER, ret_game, NULL, &pret);
        SDL_SetTextureColorMod(solo_start, i, i, i);
        SDL_RenderCopy(RENDERER, solo_start, NULL, &pgr);
        showMatrix_with_Transparancy(i);

        pbutton.y = 130 - (49 + 49 / 2) - 49 / 3;
        pbutton.x = (795 + 490) - 49 / 3;
        pbutton.h = 65;
        pbutton.w = 65;
        SDL_SetTextureColorMod(ButtonNot, i, i, i);
        SDL_RenderCopy(RENDERER, ButtonNot, NULL, &pbutton);
        SDL_RenderPresent(RENDERER);
        Show_score2();
        Sleep(1);
    }
}

void Show_score2()
{
    init_score();
    SDL_QueryTexture(Sc, NULL, NULL, &pscoor.w, &pscoor.h);
    pscoor.x = preplay.x + 49 * 2;
    pscoor.y = preplay.y - (49 * 3 + 49 / 2);
    SDL_RenderCopy(RENDERER, Sc, NULL, &pscoor);
}

void Show_Best_Score(){
    printf("SHOW BEST SCORE");
    char *str;
    str = (char *)malloc(sizeof(100000000));
    pscore = psave;
    pscore.x = pscore.x - 10 ;
    pscore.y = pscore.y + 140;
    int incr,incr2;
    incr =0;
    TTF_Font *font;
    SDL_Surface *s;
    SDL_Color color = {105, 0, 0, 0};
    font = TTF_OpenFont("A\\Polices.ttf", 30);
    while(strcmp(bestScore[incr].name,"") && incr <=4){

                    pscoor.x = pscore.x + 180;
                    sprintf(str, "%s\t%d\t%d/%d/%d",bestScore[incr].name,bestScore[incr].score,bestScore[incr].day,bestScore[incr].month,bestScore[incr].year);
                    s = TTF_RenderText_Solid(font, str, color);
                    BSc = SDL_CreateTextureFromSurface(RENDERER, s);
                    SDL_QueryTexture(BSc, NULL, NULL, &pscore.w, &pscore.h);
                    SDL_RenderCopy(RENDERER, BSc, NULL, &pscore);
                    pscore.x = psave.x;
                    pscore.y = pscore.y + 50;
                    SDL_RenderPresent(RENDERER);
                    incr++;
}
}
void Show_Best()
{
    init_BEST();
    SDL_QueryTexture(Best, NULL, NULL, &pbest.w, &pbest.h);
    printf("jsprrrrrrrrrrr");
    pbest.x = preplay.x + 49 * 2 -20;
    pbest.y = preplay.y - (49 * 3 + 49 / 2) + 120;
    SDL_RenderCopy(RENDERER, Best, NULL, &pbest);
    SDL_RenderPresent(RENDERER);
}
void init_BEST()
{
    SDL_Surface *s;

    char *str;
    str = (char *)malloc(sizeof(100000000));
        TTF_Font *font;
    if(strcmp(bestScore[0].name,"") != 0){
    sprintf(str, "%d", bestScore[0].score);
    printf("%s",str);
  //  printf("%s", str);

    font = TTF_OpenFont("A\\Polices.ttf", 48);
    if (font == NULL)
    {
        exit(-1);
    }
    SDL_Color color = {105, 0, 230, 0};
    s = TTF_RenderText_Solid(font, str, color);
    Best = SDL_CreateTextureFromSurface(RENDERER, s);
    }
}
