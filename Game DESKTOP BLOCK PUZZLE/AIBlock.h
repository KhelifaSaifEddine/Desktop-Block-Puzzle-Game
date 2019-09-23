#ifndef AIBLOCK_H_INCLUDED
#define AIBLOCK_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct AIPossib AIPossib;
struct AIPossib{
    int i;
    int j;
    int blk;
    int isBlocked;
    int score;
};

int AIcanFitBlock_1x1_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_1x2_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_1x3_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_L_3_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_2x2_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_T_3_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_4x1_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_5x1_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_L_5_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_E_5_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_3x3_XY(const int i, const int j,int testGrille[10][10]);
int AIcanFitBlock_1x1(int testGrille[10][10]);
int AIcanFitBlock_1x2(int testGrille[10][10]);
int AIcanFitBlock_1x3(int testGrille[10][10]);
int AIcanFitBlock_L_3(int testGrille[10][10]);
int AIcanFitBlock_2x2(int testGrille[10][10]);
int AIcanFitBlock_T_3(int testGrille[10][10]);
int AIcanFitBlock_4x1(int testGrille[10][10]);
int AIcanFitBlock_5x1(int testGrille[10][10]);
int AIcanFitBlock_L_5(int testGrille[10][10]);
int AIcanFitBlock_E_5(int testGrille[10][10]);
int AIcanFitBlock_3x3(int testGrille[10][10]);
int AIcanFit(const int blk_type);
void updateAIGrille();
void updateAIPoss();
int AIcalculePoss(const int blk,int tab[10][10]);
void AIcalculDecis();
int AIInsertTest(const int blk_type,const int i,const int j,int testGrille[10][10]);
int AIRefreshTestedGrille(int testGrille[10][10]);
void AIMakeDecis();
void init_AI(const int type);
int AIInsertBlock(const int i, const int j, const int type_blk);
void MulUpdatePrpBlock(const int in_choice);

/////TESTING FUNCTIONS

void printAIStat();

#endif // AIBLOCK_H_INCLUDED
