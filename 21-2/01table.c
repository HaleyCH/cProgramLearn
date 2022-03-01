/*
 * Name: table
 * Date: 21 Feb. 2022
 * LastUpdate: 27 Feb. 2022
 * Author: Chen ZiRui
 * CopyRight: all rights reserved
 * Version: 0.0.3 F
 */
#include "stdio.h"
#include "stdlib.h"
#include <time.h>

// Structs are here
struct ListNode {
    int val;
    struct ListNode *next;
};


// StructFunctions
void insertNode(struct ListNode *n, int val);

void removeNextNode(struct ListNode *n);

void clearNodes(struct ListNode *n);

void swapNode(struct ListNode *a, struct ListNode *b);

int isEmpty(struct ListNode *head);

// MainDisplayFunctions
void drawMainMenu();

void displayTable(struct ListNode *head);

// MenuRelatedFunctions
void showStatusMain(struct ListNode *head);
/* Each Function that need to display information should add a `getchar();` at the end of the function.
 */

// ProgramInnerFunctions
void createTable(struct ListNode *head);

void clearTable(struct ListNode *head);

void sortTable(struct ListNode *head);

void findByIndex(struct ListNode *head);

void findByValue(struct ListNode *head);

void insertByIndex(struct ListNode *head);

void removeByIndex(struct ListNode *head);

void removeByValue(struct ListNode *head);

void removeDuplicate(struct ListNode *head);

void invertTable(struct ListNode *head);

void partitionList(struct ListNode *head);

void importFromFile(struct ListNode *head);

void exportToFile(struct ListNode *head);

void maxPlatform(struct ListNode *head);


int main() {
    system("color 09");
    printf("Press enter to enter...");
    // Initial
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->next = NULL;
    head->val = -1;

    time_t t;
    srand((unsigned) time(&t));

    int usrInput = 999;
    while (usrInput != 0) {
        getchar();
        system("cls");
        drawMainMenu();
        // InformationFunctions( Not essential)
        displayTable(head);
        scanf("%d", &usrInput);
        // CheckFunctions( For safety reasons)
        if (usrInput == 1)
            createTable(head);
        if (usrInput == 2)
            showStatusMain(head);
        if (usrInput == 3)
            clearTable(head);
        if (usrInput == 4)
            sortTable(head);
        if (usrInput == 5)
            findByIndex(head);
        if (usrInput == 6)
            findByValue(head);
        if (usrInput == 7)
            insertByIndex(head);
        if (usrInput == 8)
            removeByIndex(head);
        if (usrInput == 9)
            removeByValue(head);
        if (usrInput == 10)
            removeDuplicate(head);
        if (usrInput == 11)
            invertTable(head);
        if (usrInput == 12)
            partitionList(head);
        if (usrInput == 13)
            importFromFile(head);
        if (usrInput == 14)
            exportToFile(head);
        if (usrInput == 15)
            maxPlatform(head);

        fflush(stdin);
    }
    clearNodes(head);
}

void drawMainMenu() {
    printf("\n==============================================");
    printf("\n   1.createList            2.showStatus       ");
    printf("\n   3.clearList             4.sortList         ");
    printf("\n   5.findByIndex           6.findByValue      ");
    printf("\n   7.insertByIndex         8.removeByIndex    ");
    printf("\n   9.removeByValue         10.removeDuplicate ");
    printf("\n   11.invertList           12.partitionList   ");
    printf("\n   13.importFromFile       14.exportToFile    ");
    printf("\n   15.maxPlatform          0.exit             ");
    printf("\n==============================================\n");
}

// StructFunctions
void insertNode(struct ListNode *n, int val) {
    struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *tmp = NULL;
    tmp = n->next;
    n->next = newNode;
    newNode->next = tmp;
    newNode->val = val;
}

void removeNextNode(struct ListNode *n) {
    struct ListNode *tmp, *delNode = NULL;
    delNode = n->next;
    tmp = delNode->next;
    n->next = tmp;
    free(delNode);
    delNode = NULL;
}

void clearNodes(struct ListNode *n) {
//    if (n->next!=NULL&&n->next->next!=NULL){
//        clearNodes(n->next->next);
//    }
//    free(n->next);
//    n->next=NULL;

    if (n->next == NULL)
        return;
    struct ListNode *p = n, *tmp;
    while (n->next != NULL) {
        tmp = n->next;
        free(n);
        n = tmp;
    }
    free(n);
    p->next = NULL;
}

void swapNode(struct ListNode *a, struct ListNode *b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}

int isEmpty(struct ListNode *head) {
    if (head->next == NULL) {
        return 1;
    }
    return 0;
}

// MainDisplayFunctions
void displayTable(struct ListNode *head) {
    if (isEmpty(head)) {
        printf("\nEmpty Table, please press 1 to create a new table.");
        return;
    }
    int ctr = 0;
    struct ListNode *p = head->next;
    while (p != NULL) {
        if (ctr % 7 == 0) {
            printf("\n");
        }
        printf("%2d  ", p->val);
        ctr++;
        p = p->next;
    }
    printf("\n");
}


// MenuRelatedFunctions
void showStatusMain(struct ListNode *head) {
    system("cls");
    int ctr = 0;
    struct ListNode *p = head->next;
    while (p->next != NULL) {
        if (ctr % 7 == 0) {
            printf("\n");
        }
        printf("%2d  ", p->val);
        ctr++;
        p = p->next;
    }
    getchar();
}

// ProgramInnerFunctions
void createTable(struct ListNode *head) {
    clearNodes(head);
    head->val = -1;
    for (int i = 0; i < 39; i++) {
        insertNode(head, rand() % 9 + 1);
    }
}

void clearTable(struct ListNode *head) {
    clearNodes(head);
}

void sortTable(struct ListNode *head) {
    struct ListNode *p = head->next, *tmp;
    int max;
    while (p->next != NULL) {
        tmp = p->next;
        while (tmp != NULL) {
            if (p->val < tmp->val) {
                swapNode(p, tmp);
            }
            tmp = tmp->next;
        }
        p = p->next;
    }
}

void findByIndex(struct ListNode *head) {
    int i;
    struct ListNode *p = head->next;
    fflush(stdin);
    printf("\nPlease input the index:");
    scanf("%d", &i);
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    printf("\nThe value of the %dth node is %2d.", i, p->val);
}

void findByValue(struct ListNode *head) {
    int i;
    struct ListNode *p = head->next;
    fflush(stdin);
    printf("\nPlease input the value:");
    scanf("%d", &i);
    printf("\nThe position(s) of value %d is/are:", i);
    int ctr = 0;
    while (p->next != NULL) {
        if (i == p->val) {
            printf(" %d ", ctr);
        }
        p = p->next;
        ctr++;
    }
    printf(".");
}

void insertByIndex(struct ListNode *head) {
    int i, v;
    struct ListNode *p = head;
    fflush(stdin);
    printf("\nPlease input the index of the node you want to insert before:");
    scanf("%d", &i);
    printf("\nPlease input the value:");
    scanf("%d", &v);

    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    insertNode(p, v);
}

void removeByIndex(struct ListNode *head) {
    int i;
    struct ListNode *p = head;
    fflush(stdin);
    printf("\nPlease input the index:");
    scanf("%d", &i);
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    removeNextNode(p);
}

void removeByValue(struct ListNode *head) {
    int i;
    struct ListNode *p = head;
    fflush(stdin);
    printf("\nPlease input the value:");
    scanf("%d", &i);

    while (p->next != NULL) {
        if (p->next->val != i) {
            p = p->next;
            continue;
        }
        removeNextNode(p);
    }
}

void removeDuplicate(struct ListNode *head) {
    // O(n^2)
    struct ListNode *p = head, *tmp;
    while (p != NULL) {
        tmp = p;
        while (tmp->next != NULL) {
            if (tmp->next->val != p->val) {
                tmp = tmp->next;
                continue;
            }
            removeNextNode(tmp);
        }
        p = p->next;
    }
}

void invertTable(struct ListNode *head) {
    struct ListNode *newHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p = head->next;
    newHead->next = NULL;
    newHead->val = -1;
    while (p != NULL) {
        insertNode(newHead, p->val);
        p = p->next;
    }
    clearNodes(head);
    head->next = newHead->next;
    free(newHead);
    newHead = NULL;
}

void partitionList(struct ListNode *head) {
    struct ListNode *newHead = (struct ListNode *) malloc(sizeof(struct ListNode)), *p = head->next, *tmp;
    newHead->val = -1;
    newHead->next = NULL;

    int breakPos = 0, v;
    fflush(stdin);
    printf("\nPlease input the value you want to break:");
    scanf("%d", &v);

    while (p != NULL) {
        insertNode(newHead, p->val);
        p = p->next;
    }
    sortTable(newHead);
    clearTable(head);
//    displayTable(newHead);
    p = newHead;
    while (p->next != NULL && p->next->val >= v) {
        p = p->next;
        breakPos++;
    }
    tmp = p->next;
    p->next = NULL;
    p = tmp;
    while (p!=NULL){
        insertNode(newHead,p->val);
        p = p->next;
    }
    clearNodes(tmp);
    head->next = newHead->next;
    free(newHead);
}

void importFromFile(struct ListNode *head) {
    fflush(stdin);
    char fp[30];
    printf("\nPlease input the file path you want to import from:");
    scanf("%s", fp);
    FILE *f = fopen(fp, "r");

    clearTable(head);
    int v;
    fscanf(f, "-1 %d ", &v);
    insertNode(head, v);
    while (fscanf(f, "%d ", &v) >= 1) {
        insertNode(head, v);
    }
    fclose(f);
    invertTable(head);
}

void exportToFile(struct ListNode *head) {
    fflush(stdin);
    char fp[30];
    printf("\nPlease input the file path you want to export to:");
    scanf("%s", fp);
    FILE *f = fopen(fp, "w");

    struct ListNode *p = head;
    while (p != NULL) {
        fprintf(f, "%d ", p->val);
        p = p->next;
    }
    fclose(f);
}

void maxPlatform(struct ListNode *head) {
    int startPos = 0, maxLen = 0, lenPlatform = 0, ctr, maxPos;
    struct ListNode *p = head->next, *tmp;

    while (p->next != NULL) {
        ctr = 0;
        tmp = p;
        while (tmp->val == p->val) {
            ctr++;
            tmp = tmp->next;
        }
        if (ctr > maxLen) {
            maxPos = startPos;
            maxLen = ctr;
        }
        p = p->next;
        startPos++;
    }
    printf("\nThe max platform start at index %d, its length is %d.", maxPos, maxLen);
}

//