//
// Created by CLGADEL on 31/03/2016.
//

#ifndef TAREA_1_LIFEGAME_H
#define TAREA_1_LIFEGAME_H

void printLongLongFormattedBoard(unsigned long long m, int printBoard);
unsigned long long transicion(unsigned long long m);
int isAliveNextCycle(unsigned long long m, int row, int col);
int getNeighbourCount(unsigned long long m, int row, int col);
int isValidBorderCondition(int row, int col);
int getBoardBit(unsigned long long m, int row, int col);
int getBit(unsigned long long m, int bit);

#endif //TAREA_1_LIFEGAME_H
