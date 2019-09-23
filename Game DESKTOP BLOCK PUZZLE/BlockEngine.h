#ifndef BLOCKENGINE_H_INCLUDED
#define BLOCKENGINE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

#define block_1x1 1
#define block_1x2 5
#define block_1x3 10
#define block_L_3 4
#define block_2x2 2
#define block_T_3 8
#define block_4x1 11
#define block_5x1 3
#define block_L_5 9
#define block_E_5 6
#define block_3x3 7

typedef struct scoreEnreg scoreEnreg;
struct scoreEnreg
{
    char name[20];
    int score;
    int day;
    int month;
    int year;
};
typedef struct possib possib;
typedef struct propsedBlock propsedBlock;
struct possib
{
    int i;
    int j;
    possib *suiv;
};

struct propsedBlock
{
    int blockType;
    int isBlocked;
};

propsedBlock prpBlck[3];
int grille[10][10];
scoreEnreg bestScore[5];

int canFit(const int n_block);
int canFitBlock_1x1();
int canFitBlock_1x2();
int canFitBlock_1x3();
int canFitBlock_L_3();
int canFitBlock_2x2();
int canFitBlock_T_3();
int canFitBlock_4x1();
int canFitBlock_5x1();
int canFitBlock_L_5();
int canFitBlock_E_5();
int canFitBlock_3x3();
int canFitBlock_1x1_XY(const int i, const int j);
int canFitBlock_1x2_XY(const int i, const int j);
int canFitBlock_1x3_XY(const int i, const int j);
int canFitBlock_L_3_XY(const int i, const int j);
int canFitBlock_2x2_XY(const int i, const int j);
int canFitBlock_T_3_XY(const int i, const int j);
int canFitBlock_4x1_XY(const int i, const int j);
int canFitBlock_5x1_XY(const int i, const int j);
int canFitBlock_L_5_XY(const int i, const int j);
int canFitBlock_E_5_XY(const int i, const int j);
int canFitBlock_3x3_XY(const int i, const int j);
void addPoss(const int i, const int j, possib **L);
void resetPoss(possib **L);
possib *blockToList(const int blk);
int insertBlock(const int i, const int j, const int type_blk);
int refreshGrille();
void updatePrpBlock(const int in_choice);
int init_game();
void saveGame();
int loadGame();
int updateBestScore(const char *name, const int score);

///////////////////////TESTING FUNCTIONS

void afficheGrille();
void fillGrille();
void printList(possib *L);
void printPrpBlck();
void printStat();
int choose();
void saveGame();
int loadGame();

#endif // BLOCKENGINE_H_INCLUDED
