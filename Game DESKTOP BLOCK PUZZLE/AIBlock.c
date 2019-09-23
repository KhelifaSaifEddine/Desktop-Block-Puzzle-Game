#include <stdlib.h>
#include <stdio.h>
#include "AIBlock.h"
#include "BlockEngine.h"

int AIGrille[10][10];
int AIMulGameGr[10][10];
int *MulGr; //POITE VERS LA GRILLE A JOUER AVEC (grille si no Multijoueur et AIMulGameGr si Multijoueur)
int isMul;
int MulSCORE;
AIPossib possTab[3];
extern int grille[10][10];
extern propsedBlock prpBlck[3];
propsedBlock AIMulPrpBlck[3];
propsedBlock* MulPrpPtr;
extern unsigned int SCORE;
int I;
int J;

int AIcanFitBlock_1x1_XY(const int i, const int j,int testGrille[10][10]){
    if(i<=9 && j<= 9){
        if(testGrille[i][j]==0){
            return 10;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_1x2_XY(const int i, const int j,int testGrille[10][10]){
    if(i<=9 && j<9){
        if(testGrille[i][j]==0 && testGrille[i][j+1]==0){
            return 20;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_1x3_XY(const int i, const int j,int testGrille[10][10]){
    if(i<=9 && j<8){
        if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i][j+2]==0){
            return 30;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_L_3_XY(const int i, const int j,int testGrille[10][10]){
    if(i<9 && j<9){
        if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i+1][j+1]==0){
            return 30;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_2x2_XY(const int i, const int j,int testGrille[10][10]){
    if(i<9 && j<9){
        if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i+1][j]==0 && testGrille[i+1][j+1]==0){
            return 40;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_T_3_XY(const int i, const int j,int testGrille[10][10]){
    if(i<8 && j<9){
        if(testGrille[i][j]==0 && testGrille[i+1][j]==0 && testGrille[i+1][j+1]==0 && testGrille[i+2][j]==0){
            return 40;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_4x1_XY(const int i, const int j,int testGrille[10][10]){
    if(i<7 && j<=9){
        if(testGrille[i][j]==0 && testGrille[i+1][j]==0 && testGrille[i+2][j]==0 && testGrille[i+3][j]==0){
            return 40;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_5x1_XY(const int i, const int j,int testGrille[10][10]){
    if(i<6 && j<=9){
        if(testGrille[i][j]==0 && testGrille[i+1][j]==0 && testGrille[i+2][j]==0 && testGrille[i+3][j]==0 && testGrille[i+4][j]==0){
            return 50;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_L_5_XY(const int i, const int j,int testGrille[10][10]){
    if(i<8 && j<8){
        if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i][j+2]==0 && testGrille[i+1][j+2]==0 && testGrille[i+2][j+2]==0){
            return 50;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_E_5_XY(const int i, const int j,int testGrille[10][10]){
    if(i<8 && j<9){
        if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i+1][j+1]==0 && testGrille[i+2][j]==0 && testGrille[i+2][j+1]==0){
            return 50;
        }else{
            return 0;
        }
    }else{
        return -1;
    }

}

int AIcanFitBlock_3x3_XY(const int i, const int j,int testGrille[10][10]){
    if(i<8 && j<8){
        if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i][j+2]==0 && testGrille[i+1][j]==0 && testGrille[i+1][j+1]==0 && testGrille[i+1][j+2]==0 && testGrille[i+2][j]==0 && testGrille[i+2][j+1]==0 && testGrille[i+2][j+2]==0){
            return 90;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}

int AIcanFitBlock_1x1(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(testGrille[i][j]==0){
                res++;
            }
        }
    }
    return res;
}

int AIcanFitBlock_1x2(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(j<9){
                if(testGrille[i][j]==0 && testGrille[i][j+1]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_1x3(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(j<8){
                if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i][j+2]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_L_3(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<9 && j<9){
                if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i+1][j+1]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_2x2(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<9 && j<9){
                if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i+1][j]==0 && testGrille[i+1][j+1]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_T_3(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<8 && j<9){
                if(testGrille[i][j]==0 && testGrille[i+1][j]==0 && testGrille[i+1][j+1]==0 && testGrille[i+2][j]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_4x1(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<7){
                if(testGrille[i][j]==0 && testGrille[i+1][j]==0 && testGrille[i+2][j]==0 && testGrille[i+3][j]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_5x1(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<6){
                if(testGrille[i][j]==0 && testGrille[i+1][j]==0 && testGrille[i+2][j]==0 && testGrille[i+3][j]==0 && testGrille[i+4][j]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_L_5(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<8 && j<8){
                if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i][j+2]==0 && testGrille[i+1][j+2]==0 && testGrille[i+2][j+2]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_E_5(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<8 && j<9){
                if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i+1][j+1]==0 && testGrille[i+2][j]==0 && testGrille[i+2][j+1]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFitBlock_3x3(int testGrille[10][10]){
    int res=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i<8 && j<8){
                if(testGrille[i][j]==0 && testGrille[i][j+1]==0 && testGrille[i][j+2]==0 && testGrille[i+1][j]==0 && testGrille[i+1][j+1]==0 && testGrille[i+1][j+2]==0 && testGrille[i+2][j]==0 && testGrille[i+2][j+1]==0 && testGrille[i+2][j+2]==0){
                    res++;
                }
            }
        }
    }
    return res;
}

int AIcanFit(const int blk_type){
    switch(blk_type){
        case block_1x1:
        return AIcanFitBlock_1x1(AIMulGameGr);
        break;
        case block_1x2:
        return AIcanFitBlock_1x2(AIMulGameGr);
        break;
        case block_1x3:
        return AIcanFitBlock_1x3(AIMulGameGr);
        break;
        case block_L_3:
        return AIcanFitBlock_L_3(AIMulGameGr);
        break;
        case block_2x2:
        return AIcanFitBlock_2x2(AIMulGameGr);
        break;
        case block_T_3:
        return AIcanFitBlock_T_3(AIMulGameGr);
        break;
        case block_4x1:
        return AIcanFitBlock_4x1(AIMulGameGr);
        break;
        case block_5x1:
        return AIcanFitBlock_5x1(AIMulGameGr);
        break;
        case block_L_5:
        return AIcanFitBlock_L_5(AIMulGameGr);
        break;
        case block_E_5:
        return AIcanFitBlock_E_5(AIMulGameGr);
        break;
        case block_3x3:
        return AIcanFitBlock_3x3(AIMulGameGr);
        break;
        default:
            return -1;
        break;
    }
}

void updateAIGrille(){
    //printf("UPDATING GRILLE\n");
    if(!isMul){
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                AIGrille[i][j]=grille[i][j];
            }
        }
    }else{
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                AIGrille[i][j]=AIMulGameGr[i][j];
            }
        }
    }
}

void updateAIPoss(){
    //printf("UPDATING POSSIBLITIES\n");
    if(!isMul){
        for(int i=0;i<=2;i++){
            possTab[i].blk=prpBlck[i].blockType;
            possTab[i].score=0;
            possTab[i].isBlocked=prpBlck[i].isBlocked;
        }
    }else{
        for(int i=0;i<=2;i++){
            possTab[i].blk=AIMulPrpBlck[i].blockType;
            possTab[i].score=0;
            possTab[i].isBlocked=AIMulPrpBlck[i].isBlocked;
        }
    }
}

int AIcalculePoss(const int blk,int tab[10][10]){
    int (*func_fit)(const int,const int,int[10][10]);//FUNCTION POINTER
    switch(blk){
        case block_1x1:
            func_fit=&AIcanFitBlock_1x1_XY;
        break;
        case block_1x2:
            func_fit=&AIcanFitBlock_1x2_XY;
        break;
        case block_1x3:
            func_fit=&AIcanFitBlock_1x3_XY;
        break;
        case block_L_3:
            func_fit=&AIcanFitBlock_L_3_XY;
        break;
        case block_2x2:
            func_fit=&AIcanFitBlock_2x2_XY;
        break;
        case block_T_3:
            func_fit=&AIcanFitBlock_T_3_XY;
        break;
        case block_4x1:
            func_fit=&AIcanFitBlock_4x1_XY;
        break;
        case block_5x1:
            func_fit=&AIcanFitBlock_5x1_XY;
        break;
        case block_L_5:
            func_fit=&AIcanFitBlock_L_5_XY;
        break;
        case block_E_5:
            func_fit=&AIcanFitBlock_E_5_XY;
        break;
        case block_3x3:
            func_fit=&AIcanFitBlock_3x3_XY;
        break;
        default:
            //printf("IN FUNCTION CALCUL POSS : WRONG PARAM\n");
            return -1;
        break;
    }
    int scr=0;
    int buff=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            buff=func_fit(i,j,tab);
            if(buff>0){
                buff+=AIInsertTest(blk,i,j,tab);
            }
            if(buff>scr){
                scr=buff;
                I=i;
                J=j;
            }
            buff=0;
        }
    }
    return scr;
}

int AIInsertTest(const int blk_type,const int i,const int j,int testGrille[10][10]){
    if(!(blk_type>=1 && blk_type<=11)){
        //printf("WRONG blk param\n");
        return -1;
    }
    int scr=0;
    switch(blk_type){
        case block_1x1:
        if(!isMul){
            if(canFitBlock_1x1_XY(i,j)){
                testGrille[i][j]=1;
                scr=10;
            }
        }else{
            if(AIcanFitBlock_1x1_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                scr=10;
            }
        }
        break;
        case block_1x2:
        if(!isMul){
            if(canFitBlock_1x2_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                scr=20;
            }
        }else{
            if(AIcanFitBlock_1x2_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                scr=20;
            }
        }
        break;
        case block_1x3:
        if(!isMul){
            if(canFitBlock_1x3_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i][j+2]=1;
                scr=30;
            }
        }else{
            if(AIcanFitBlock_1x3_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i][j+2]=1;
                scr=30;
            }
        }
        break;
        case block_L_3:
        if(!isMul){
            if(canFitBlock_L_3_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i+1][j+1]=1;
                scr=30;
            }
        }else{
            if(AIcanFitBlock_L_3_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i+1][j+1]=1;
                scr=30;
            }
        }
        break;
        case block_2x2:
        if(!isMul){
            if(canFitBlock_2x2_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i+1][j]=1;
                testGrille[i+1][j+1]=1;
                scr=40;
            }
        }else{
            if(AIcanFitBlock_2x2_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i+1][j]=1;
                testGrille[i+1][j+1]=1;
                scr=40;
            }
        }
        break;
        case block_T_3:
        if(!isMul){
            if(canFitBlock_T_3_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i+1][j]=1;
                testGrille[i+1][j+1]=1;
                testGrille[i+2][j]=1;
                scr=40;
            }
        }else{
            if(AIcanFitBlock_T_3_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i+1][j]=1;
                testGrille[i+1][j+1]=1;
                testGrille[i+2][j]=1;
                scr=40;
            }
        }
        break;
        case block_4x1:
        if(!isMul){
            if(canFitBlock_4x1_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i+1][j]=1;
                testGrille[i+2][j]=1;
                testGrille[i+3][j]=1;
                scr=40;
            }
        }else{
            if(AIcanFitBlock_4x1_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i+1][j]=1;
                testGrille[i+2][j]=1;
                testGrille[i+3][j]=1;
                scr=40;
            }
        }
        break;
        case block_5x1:
        if(!isMul){
            if(canFitBlock_5x1_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i+1][j]=1;
                testGrille[i+2][j]=1;
                testGrille[i+3][j]=1;
                testGrille[i+4][j]=1;
                scr=50;
            }
        }else{
            if(AIcanFitBlock_5x1_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i+1][j]=1;
                testGrille[i+2][j]=1;
                testGrille[i+3][j]=1;
                testGrille[i+4][j]=1;
                scr=50;
            }
        }
        break;
        case block_L_5:
        if(!isMul){
            if(canFitBlock_L_5_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i][j+2]=1;
                testGrille[i+1][j+2]=1;
                testGrille[i+2][j+2]=1;
                scr=50;
            }
        }else{
            if(AIcanFitBlock_L_5_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i][j+2]=1;
                testGrille[i+1][j+2]=1;
                testGrille[i+2][j+2]=1;
                scr=50;
            }
        }
        break;
        case block_E_5:
        if(!isMul){
            if(canFitBlock_E_5_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i+1][j+1]=1;
                testGrille[i+2][j]=1;
                testGrille[i+2][j+1]=1;
                scr=50;
            }
        }else{
            if(AIcanFitBlock_E_5_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i+1][j+1]=1;
                testGrille[i+2][j]=1;
                testGrille[i+2][j+1]=1;
                scr=50;
            }
        }
        break;
        case block_3x3:
        if(!isMul){
            if(canFitBlock_3x3_XY(i,j)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i][j+2]=1;
                testGrille[i+1][j]=1;
                testGrille[i+1][j+1]=1;
                testGrille[i+1][j+2]=1;
                testGrille[i+2][j]=1;
                testGrille[i+2][j+1]=1;
                testGrille[i+2][j+2]=1;
                scr=90;
            }
        }else{
            if(AIcanFitBlock_3x3_XY(i,j,AIMulGameGr)){
                testGrille[i][j]=1;
                testGrille[i][j+1]=1;
                testGrille[i][j+2]=1;
                testGrille[i+1][j]=1;
                testGrille[i+1][j+1]=1;
                testGrille[i+1][j+2]=1;
                testGrille[i+2][j]=1;
                testGrille[i+2][j+1]=1;
                testGrille[i+2][j+2]=1;
                scr=90;
            }
        }
        break;
        default:
            return -1;
        break;
    }
    //printf("|%d|",scr);
    return AIRefreshTestedGrille(testGrille)+scr;
}

void AIcalculDecis(){
    for(int i=0;i<=2;i++){
        if(!possTab[i].isBlocked){
            possTab[i].score=AIcalculePoss(possTab[i].blk,AIGrille);
            //printf("\n\tCALCUL SCORE = %d\n",possTab[i].score);
            possTab[i].i=I;
            possTab[i].j=J;
            //printf("CALCUL %d\n",i);
        }else{
            possTab[i].score=0;
            //printf("SCORE==0\n");
        }
    }
}

int AIRefreshTestedGrille(int testGrille[10][10]){
    int L=0;
    int L_a_supp[10]={0};
    int C_a_supp[10]={0};
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(testGrille[i][j]==1){
                L++;
            }
        }
        if(L==10){
            L_a_supp[i]=1;
        }
        L=0;
    }
    /*printf("\nL_a_supp : ");
    for(int i=0;i<=9;i++){
        printf("%d|",L_a_supp[i]);
    }*/
    L=0;
    for(int j=0;j<=9;j++){
        for(int i=0;i<=9;i++){
            if(testGrille[i][j]==1){
                L++;
            }
        }
        if(L==10){
            C_a_supp[j]=1;
        }
        L=0;
    }
    /*printf("\nC_a_supp : ");
    for(int i=0;i<=9;i++){
        printf("%d|",C_a_supp[i]);
    }*/
    int score=0;
    int mul=1;
    for(int i=0;i<=9;i++){
        if(L_a_supp[i]==1){
            for(int j=0;j<=9;j++){
                testGrille[i][j]=0;
            }
            score=score+(mul*100);
            //printf("R_L : %d\t",score);
            mul++;
            if(mul==6) mul=1;
        }
    }
    if(mul==6) mul=1;
    for(int j=0;j<=9;j++){
        if(C_a_supp[j]==1){
            for(int i=0;i<=9;i++){
                testGrille[i][j]=0;
            }
            score=score+(mul*100);
            //printf("R_C : %d\t",score);
            mul++;
            if(mul==6) mul=1;
        }
    }
    //printf("REFRESH : %d\t",score);
    return score;
}

void AIMakeDecis(){
    int scr=0;
    int choice=-1;
    for(int i=0;i<=2;i++){
        if(scr<possTab[i].score){
            scr=possTab[i].score;
            choice=i;
        }
    }
    //if(choice==-1)
    //printf("AI CHOICE == %d\n",choice);
    printf("INSERTING BLOCK : %d\n",AIInsertBlock(possTab[choice].i,possTab[choice].j,choice+1));
    updateAIGrille();
    updateAIPoss();
    //printAIStat();
    AIcalculDecis();
}

void init_AI(const int type){
    if(!type){
        MulGr=grille;
    }else{
        int i=0,j=0;
        for(i=0;i<=9;i++){
            for(j=0;j<=9;j++){
                AIMulGameGr[i][j]=0;
            }
        }
        MulGr=AIMulGameGr;
        MulUpdatePrpBlock(1);
        MulUpdatePrpBlock(2);
        MulUpdatePrpBlock(3);
    }
    isMul=type;
    MulSCORE=0;
    updateAIGrille();
    updateAIPoss();
    AIcalculDecis();
    //AIMakeDecis();
}

int MulRefreshGrille(){
    int L=0;
    int L_a_supp[10]={0};
    int C_a_supp[10]={0};
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(AIMulGameGr[i][j]==1){
                L++;
            }
        }
        if(L==10){
            L_a_supp[i]=1;
        }
        L=0;
    }
    L=0;
    for(int j=0;j<=9;j++){
        for(int i=0;i<=9;i++){
            if(AIMulGameGr[i][j]==1){
                L++;
            }
        }
        if(L==10){
            C_a_supp[j]=1;
        }
        L=0;
    }
    int score=0;
    int mul=1;
    for(int i=0;i<=9;i++){
        if(L_a_supp[i]==1){
            for(int j=0;j<=9;j++){
                AIMulGameGr[i][j]=0;
            }
            score=score+(mul*100);
            mul++;
            if(mul==6) mul=1;
        }
    }
    if(mul==6) mul=1;
    for(int j=0;j<=9;j++){
        if(C_a_supp[j]==1){
            for(int i=0;i<=9;i++){
                AIMulGameGr[i][j]=0;
            }
            score=score+(mul*100);
            mul++;
            if(mul==6) mul=1;
        }
    }
    MulSCORE+=score;
    return score;
}

void MulUpdatePrpBlock(const int in_choice){
    int tab_blk_res[8]={0};
    int exist=0;
    int in_blk=1;
    for(int i=0;i<=7;i++){
        for(int j=0;j<=2;j++){
            if(in_blk==AIMulPrpBlck[j].blockType){
                exist=1;
            }
        }
        if(!exist){
            tab_blk_res[i]=in_blk;
        }else i--;
        in_blk++;
        exist=0;
    }
    int nv_blk=tab_blk_res[(rand()%8)];
    if(in_choice>=1 && in_choice<=3){
        AIMulPrpBlck[in_choice-1].blockType=nv_blk;
    }
    for(int i=0;i<=2;i++){
        if(AIcanFit(AIMulPrpBlck[i].blockType)){
            AIMulPrpBlck[i].isBlocked=0;
        }else{
            AIMulPrpBlck[i].isBlocked=1;
        }
    }
}

int AIInsertBlock(const int i, const int j, const int choice_blk){
    if(!isMul){
        return insertBlock(i,j,choice_blk);
    }else{
        if(!(choice_blk>=1 && choice_blk<=3)){
            return -1;
        }
        int res=0;
        switch(AIMulPrpBlck[choice_blk-1].blockType){
            case block_1x1:
                if(AIcanFitBlock_1x1_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    res = 1;
                    MulSCORE += 10;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_1x1);
                    res = -1;
                }
            break;
            case block_1x2:
                if(AIcanFitBlock_1x2_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i][j+1]=1;
                    res = 1;
                    MulSCORE += 20;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_1x2);
                    res = -1;
                }
            break;
            case block_1x3:
                if(AIcanFitBlock_1x3_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i][j+1]=1;
                    AIMulGameGr[i][j+2]=1;
                    res = 1;
                    MulSCORE += 30;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_1x3);
                    res = -1;
                }
            break;
            case block_L_3:
                if(AIcanFitBlock_L_3_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i][j+1]=1;
                    AIMulGameGr[i+1][j+1]=1;
                    res = 1;
                    MulSCORE += 30;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_L_3);
                    res = -1;
                }
            break;
            case block_2x2:
                if(AIcanFitBlock_2x2_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i][j+1]=1;
                    AIMulGameGr[i+1][j]=1;
                    AIMulGameGr[i+1][j+1]=1;
                    res = 1;
                    MulSCORE += 40;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_2x2);
                    res = -1;
                }
            break;
            case block_T_3:
                if(AIcanFitBlock_T_3_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i+1][j]=1;
                    AIMulGameGr[i+1][j+1]=1;
                    AIMulGameGr[i+2][j]=1;
                    res = 1;
                    MulSCORE += 40;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_T_3);
                    res = -1;
                }
            break;
            case block_4x1:
                if(AIcanFitBlock_4x1_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i+1][j]=1;
                    AIMulGameGr[i+2][j]=1;
                    AIMulGameGr[i+3][j]=1;
                    res = 1;
                    MulSCORE += 40;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_4x1);
                    res = -1;
                }
            break;
            case block_5x1:
                if(AIcanFitBlock_5x1_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i+1][j]=1;
                    AIMulGameGr[i+2][j]=1;
                    AIMulGameGr[i+3][j]=1;
                    AIMulGameGr[i+4][j]=1;
                    res = 1;
                    MulSCORE += 50;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_5x1);
                    res = -1;
                }
            break;
            case block_L_5:
                if(AIcanFitBlock_L_5_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i][j+1]=1;
                    AIMulGameGr[i][j+2]=1;
                    AIMulGameGr[i+1][j+2]=1;
                    AIMulGameGr[i+2][j+2]=1;
                    res = 1;
                    MulSCORE += 50;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_L_5);
                    res = -1;
                }
            break;
            case block_E_5:
                if(AIcanFitBlock_E_5_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i][j+1]=1;
                    AIMulGameGr[i+1][j+1]=1;
                    AIMulGameGr[i+2][j]=1;
                    AIMulGameGr[i+2][j+1]=1;
                    MulSCORE += 50;
                    res = 1;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_E_5);
                    res = -1;
                }
            break;
            case block_3x3:
                if(AIcanFitBlock_3x3_XY(i,j,AIMulGameGr)){
                    AIMulGameGr[i][j]=1;
                    AIMulGameGr[i][j+1]=1;
                    AIMulGameGr[i][j+2]=1;
                    AIMulGameGr[i+1][j]=1;
                    AIMulGameGr[i+1][j+1]=1;
                    AIMulGameGr[i+1][j+2]=1;
                    AIMulGameGr[i+2][j]=1;
                    AIMulGameGr[i+2][j+1]=1;
                    AIMulGameGr[i+2][j+2]=1;
                    MulSCORE += 90;
                    res = 1;
                }else{
                    printf("\n\t\t\tBlock %d did not FIT !\n",block_3x3);
                    res = -1;
                }
            break;
            default:
                printf("DEFAULT---------------------------\n)");
                return -1;
            break;
        }
        MulRefreshGrille();
        if(res==1) MulUpdatePrpBlock(choice_blk);
        return res;
    }
}

/////TESTING FUNCTIONS

void printAIStat(){
    printf("\n");
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(!isMul){
                if(grille[i][j]==1)
                    printf("O|");
                else
                    printf(".|");
            }else{
                if(AIMulGameGr[i][j]==1)
                    printf("O|");
                else
                    printf(".|");
            }
        }
        printf("\n");
    }
    for(int i=0;i<=2;i++){
        printf("\n\t\t\t%d : %d,%d,%d",possTab[i].blk,possTab[i].i,possTab[i].j,possTab[i].score);
    }
    printf("\n\t\t\t");
    if(!isMul){
        for(int i=0;i<=2;i++){
            printf("[%d,%d]|",prpBlck[i].blockType,prpBlck[i].isBlocked);
        }
    }else{
        for(int i=0;i<=2;i++){
            printf("[%d,%d]|",AIMulPrpBlck[i].blockType,AIMulPrpBlck[i].isBlocked);
        }
    }
    //printf("\n");
    if(isMul){
        printf("SCORE = %d\n",MulSCORE);
    }else{
        printf("SCORE = %d\n",SCORE);
    }
}
