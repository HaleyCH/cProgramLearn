/*
 * Name:
 * Date:
 * LastUpdate:
 * Author: Chen ZiRui
 * CopyRight: all rights reserved
 * Version:
 */
#include "stdio.h"
#include "stdlib.h"

void drawMainMenu();
// MenuRelatedFunctions
/* Each Function that need to display information should add a `getchar();` at the end of the function.
 */

// ProgramInnerFunctions

int main() {
    system("color 09");
    printf("Press enter to enter...");
    // Initial
    int usrInput = 999;


    while (usrInput != 0) {
        getchar();
        system("cls");
        drawMainMenu();
        // InformationFunctions( Not essential)
        scanf("%d", &usrInput);
        // CheckFunctions( For safety reasons)
        if (usrInput == 1)
            continue;
        fflush(stdin);
    }
}

void drawMainMenu(){
    printf("\n==========TICKET_SYSTEM=======================");
    printf("\n   1.createTheater         2.showStatus       ");
    printf("\n   3.buy/sell              4.refund           ");
    printf("\n   5.book                  6.cancellation     ");
    printf("\n   7.search                0.exit             ");
    // printf("\n==============================================\n");
}

// MenuRelatedFunctions
// ProgramInnerFunctions