//
// Created by CLGADEL on 31/03/2016.
//
#include <stdio.h>
#include "lifegame.h"

const int True = 1;
const int False = 0;
const int Width = 8;
const int Height = 8;

//unsigned long long transicion(unsigned long long m);

int main() {

    unsigned long long m = 1792;
    int count = 10;

    printf("Source: %lld \n", m);
    printLongLongFormattedBoard(m, True);


    for (int i = 0; i < count; ++i) {
        m = transicion(m);
        printf("Iteracion: %d Calculado: %lld \n", i, m);
        printLongLongFormattedBoard(m, True);
    }
}

unsigned long long transicion(unsigned long long m) {
    unsigned long long newM = 0;
    for (unsigned int row = 0; row < Height; row++) {
        for (unsigned int col = 0; col < Width; col++) {
            newM += ((unsigned long long) isAliveNextCycle(m, row, col) << (unsigned long long) ((row << 3) + col));
        }
    }
    return newM;
}

int getBit(unsigned long long m, int bit) {
    return m >> bit & 1;
}

int getBoardBit(unsigned long long m, int row, int col) {
    return getBit(m, (row << 3) + col);
}

//Checks if the current cell's next cycle state:
int isAliveNextCycle(unsigned long long m, int row, int col) {
    int neighbourCount = getNeighbourCount(m, row, col);
    int currentValue = getBoardBit(m, row, col);

    //Game of Life conditions for survival:
    if (currentValue == True && neighbourCount == 2)
        return True;

    //Game of Life conditions for life spawn:
    if (neighbourCount == 3)
        return True;

    //Game of Life conditions for extinction:
    if (neighbourCount < 2 || neighbourCount >= 4 || (currentValue == False && neighbourCount == 2))
        return False;
}

//Get alive neighbours' count:
int getNeighbourCount(unsigned long long m, int row, int col) {
    int neighbourCount = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (isValidBorderCondition(row + i, col + j) && !(i == 0 && j == 0)) {
                neighbourCount += getBoardBit(m, row + i, col + j);
            }
        }
    }
    return neighbourCount;
}

//Check Border Conditions, out of Board's Width & Height;
int isValidBorderCondition(int i, int j) {
    if ((i >= 0 && i < Height) && (j >= 0 && j < Width))
        return True;
    return False;
}

void printLongLongFormattedBoard(unsigned long long m, int printBoard) {

    //Foreach Row:
    for (int row = Height - 1; row >= 0; row--) {

        //Print board marks:
        if (printBoard) {
            printf("%d| ", row);
        }

        //Foreach Column:
        for (int col = Width - 1; col >= 0; col--) {
            printf("%d ", getBoardBit(m, row, col));
        }

        //EndOfColumn:
        printf("\n");
    }

    //Print board marks:
    if (printBoard) {
        printf(" -----------------\n");
        printf("   ");
        for (int col = Width - 1; col >= 0; col--) {
            printf("%d ", col);
        }
        printf("\n");
    }

    //EndOfBoard:
    printf("\n");
}
