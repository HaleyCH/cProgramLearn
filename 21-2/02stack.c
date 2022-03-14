/*
 * Name: 02Stack
 * Date: 1 Mar. 2022
 * LastUpdate: 14 Mar. 2022
 * Author: Chen ZiRui
 * CopyRight: all rights reserved
 * Version: 0.1.15 F
 */
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// Structs are here
typedef struct Elem {
    int val;
    int val2;
    int val3;
    int val4;
} Elem;

typedef struct SeqStack {
    int bufSize, top, bottom;
    Elem *arr;
} SeqStack;

typedef struct HanoiProb {
    int len, from, to;
} HanoiProb;

typedef struct HanoiSeqStack {
    int bufSize, top, bottom;
    HanoiProb *arr;
} HanoiSeqStack;

// StructFunctions
SeqStack *createSeqStack(int bufSize);

const Elem *sPeek(SeqStack *sStack);

SeqStack *sPush(SeqStack *sStack, Elem val);

Elem *sPop(SeqStack *sStack);

void sShow(SeqStack *sStack);

int sIsEmpty(SeqStack *sStack);

HanoiSeqStack *createHSeqStack(int bufSize);

const HanoiProb *hPeek(HanoiSeqStack *sStack);

HanoiSeqStack *hPush(HanoiSeqStack *sStack, HanoiProb val);

HanoiProb *hPop(HanoiSeqStack *sStack);

int hIsEmpty(HanoiSeqStack *sStack);

// MainDisplayFunctions
void drawMainMenu();
// MenuRelatedFunctions
/* Each Function that need to display information should add a `getchar();` at the end of the function.
 */
void createSeqStackMain(SeqStack *sStack);

void showStackMain(SeqStack *sStack);

void pushMain(SeqStack *sStack);

void popMain(SeqStack *sStack);

void peekMain(SeqStack *sStack);

void clearMain(SeqStack *sStack);

void palindromeStringMain();

void numberConversionMain();

void palindromeNumberMain();

void bracketsMatchingMain();

void hanoiTowerMain();

void expressionValueMain();

void backpackProblemMain();

void nQueensProblemMain();

void mazeProblemMain();

// ProgramInnerFunctions
void showStack(SeqStack *sStack);

int getIndex(const char alphabet[], char v);

void numberConversion(int srcB, int dstB, char *srcS, char alphabets[], char outS[]);

int canSetQueen(int arr[], int v);

int canWalk(int map[20][20], SeqStack *sStack, Elem e);

void render(int map[20][20]);

void showWay(int map[20][20], SeqStack *wayStack);

int getPriority(char c);

int calc(int a, int b, char c);

int main() {
    system("color 09");
    printf("Press enter to enter...");
    // Initial
    int usrInput = 999;
    SeqStack sStack = {-1, -1, -1};


    while (usrInput != 0) {
        getchar();
        system("cls");
        drawMainMenu();
        // InformationFunctions( Not essential)
        if (sStack.top != -1) {
            printf("\n======CurrentStack============================\n");
            showStack(&sStack);
            printf("\n==============================================\n");
        }
        scanf("%d", &usrInput);
        // CheckFunctions( For safety reasons)
        if (usrInput == 1)
            createSeqStackMain(&sStack);
        if (usrInput == 2)
            showStackMain(&sStack);
        if (usrInput == 3)
            pushMain(&sStack);
        if (usrInput == 4)
            popMain(&sStack);
        if (usrInput == 5)
            peekMain(&sStack);
        if (usrInput == 6)
            clearMain(&sStack);
        if (usrInput == 7)
            palindromeStringMain();
        if (usrInput == 8)
            numberConversionMain();
        if (usrInput == 9)
            palindromeNumberMain();
        if (usrInput == 10)
            bracketsMatchingMain();
        if (usrInput == 11)
            hanoiTowerMain();
        if (usrInput == 12)
            expressionValueMain();
        if (usrInput == 13)
            backpackProblemMain();
        if (usrInput == 14)
            nQueensProblemMain();
        if (usrInput == 15)
            mazeProblemMain();

        fflush(stdin);
    }
}

void drawMainMenu() {
    printf("\n==============================================");
    printf("\n   1.createSeqStack        2.showStack        ");
    printf("\n   3.push                  4.pop              ");
    printf("\n   5.peek                  6.clear            ");
    printf("\n   7.palindromeString      8.numberConversion ");
    printf("\n   9.palindromeNumber      10.bracketsMatching");
    printf("\n   11.hanoiTower           12.expressionValue ");
    printf("\n   13.backpackProblem      14.nQueensProblem  ");
    printf("\n   15.mazeProblem          0.exit             ");
    // printf("\n==============================================\n");
}

// StructFunctions
SeqStack *createSeqStack(int bufSize) {
    SeqStack *newSeqStack = (SeqStack *) malloc(sizeof(SeqStack));
    newSeqStack->top = 0;
    newSeqStack->bottom = 0;
    newSeqStack->bufSize = bufSize;
    Elem *newArr = (Elem *) malloc(sizeof(Elem) * newSeqStack->bufSize + 1);
    newSeqStack->arr = newArr;
    return newSeqStack;
}

const Elem *sPeek(SeqStack *sStack) {
    if (sStack->top == sStack->bottom || sStack->top < 0) {
        return NULL;
    }
    return &sStack->arr[sStack->top];
}

SeqStack *sPush(SeqStack *sStack, Elem val) {
    if (sStack->top + 1 >= sStack->bufSize) {// raiseError
        return sStack;
    }
    (sStack->top)++;
    sStack->arr[sStack->top] = val;

    return sStack;
};

Elem *sPop(SeqStack *sStack) {
    if (sStack->top == sStack->bottom) {
        return NULL;
    }
    Elem *newElem = (Elem *) malloc(sizeof(Elem));
    newElem->val = sStack->arr[sStack->top].val;
    newElem->val2 = sStack->arr[sStack->top].val2;
    newElem->val3 = sStack->arr[sStack->top].val3;
    newElem->val4 = sStack->arr[sStack->top].val4;
    sStack->top--;
    return newElem;
}

void sShow(SeqStack *sStack) {
    int tmp = sStack->top;
    for (int i = sStack->top; i > sStack->bottom; i--) {
        printf("%d ", sStack->arr[i].val);
    }
}

int sIsEmpty(SeqStack *sStack) {
    if (sStack->top == sStack->bottom) {
        return 1;
    }
    return 0;
}

HanoiSeqStack *createHSeqStack(int bufSize) {
    HanoiSeqStack *newSeqStack = (HanoiSeqStack *) malloc(sizeof(HanoiSeqStack));
    newSeqStack->top = 0;
    newSeqStack->bottom = 0;
    newSeqStack->bufSize = bufSize;
    HanoiProb *newArr = (HanoiProb *) malloc(sizeof(HanoiProb) * newSeqStack->bufSize);
    newSeqStack->arr = newArr;
    return newSeqStack;
}

const HanoiProb *hPeek(HanoiSeqStack *sStack) {
    if (sStack->top == sStack->bottom || sStack->top < 0) {
        return NULL;
    }
    return &sStack->arr[sStack->top];
}

HanoiSeqStack *hPush(HanoiSeqStack *sStack, HanoiProb val) {
    if (sStack->top + 1 >= sStack->bufSize) {// raiseError
        return sStack;
    }
    (sStack->top)++;
    sStack->arr[sStack->top] = val;

    return sStack;
};

HanoiProb *hPop(HanoiSeqStack *sStack) {
    if (sStack->top == sStack->bottom) {
        return NULL;
    }
    HanoiProb *newElem = (HanoiProb *) malloc(sizeof(HanoiProb));
    newElem->from = sStack->arr[sStack->top].from;
    newElem->to = sStack->arr[sStack->top].to;
    newElem->len = sStack->arr[sStack->top].len;
    sStack->top--;
    return newElem;
}

int hIsEmpty(HanoiSeqStack *sStack) {
    if (sStack->top == sStack->bottom) {
        return 1;
    }
    return 0;
}

// MainDisplayFunctions
// MenuRelatedFunctions
void createSeqStackMain(SeqStack *sStack) {
    int bufSize;
    printf("\n======createSeqStack==========================");
    printf("\nPlease input the buf size of the stack: ");
    fflush(stdin);
    scanf("%d", &bufSize);
    *sStack = *createSeqStack(bufSize);
    printf("\nFinished.");
}

void showStackMain(SeqStack *sStack) {
    printf("\n======showStack===============================\n");
    showStack(sStack);
    printf("\n");
}

void pushMain(SeqStack *sStack) {
    Elem e;
    printf("\n======push====================================");
    printf("\nPlease input the value you want to push:");
    fflush(stdin);
    scanf("%d", &e.val);
    sPush(sStack, e);
}

void popMain(SeqStack *sStack) {
    printf("\n======pop=====================================");
    Elem *e;
    e = sPop(sStack);
    printf("\nThe value popped is: %d", e->val);
    printf("\n Now the stack is:");
    showStack(sStack);
    free(e);
}

void peekMain(SeqStack *sStack) {
    printf("\n======peek====================================");
    printf("\n The top of the stack is: %d", sPeek(sStack)->val);
}

void clearMain(SeqStack *sStack) {
    printf("\n======clear===================================");
    sStack->top = sStack->bottom;
    printf("\n Finished. After clear:");
    showStack(sStack);
}

void palindromeStringMain() {
    printf("\n======palindromeString========================");
    int arr[64], len = 0;
    char c;
    SeqStack *sStack = createSeqStack(64);
    printf("\nPlease input the string:");
    fflush(stdin);
    while (scanf("%c", &c) >= 1) {
        if (c == '\n') {
            break;
        }
        arr[len++] = (int) c;
    }
    for (int i = 0; i < (len / 2); i++) {
        Elem e;
        e.val = arr[i];
        sPush(sStack, e);
    }
    for (int i = (len / 2); i < len; i++) {
        if (sPeek(sStack)->val == arr[i]) {
            free(sPop(sStack));
        }
    }
    if (sIsEmpty(sStack)) {
        printf("\nIt is a palindrome string.");
    } else {
        printf("\nIt is not a palindrome string.");
    }
    free(sStack);
}

void numberConversionMain() {
    printf("\n======NumberConversion========================");
    int srcB, dstB, val, carry = 0, pos = 0;
    char alphabet[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", c, outC[128], inputC[64];
    SeqStack *sStack, *sAfterConv;
    sStack = createSeqStack(64);
    sAfterConv = createSeqStack(128);
    printf("\nPlease input the source base:");
    fflush(stdin);
    scanf("%d", &srcB);
    printf("\nPlease input the target base:");
    fflush(stdin);
    scanf("%d", &dstB);
    fflush(stdin);
    printf("\nPlease input the Number:");
    fflush(stdin);
    scanf("%s", inputC);
    numberConversion(srcB, dstB, inputC, alphabet, outC);
    printf("\nAfter convert:\n%s", outC);

}

void palindromeNumberMain() {
    printf("\n======palindromeNumber========================");
    int srcB, dstB, val, carry = 0, pos = 0;
    char alphabet[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", c, outC[128], inputC[64];
    SeqStack *sStack, *sAfterConv;
    sStack = createSeqStack(64);
    sAfterConv = createSeqStack(128);
    printf("\nPlease input the source base:");
    fflush(stdin);
    scanf("%d", &srcB);
    printf("\nPlease input the target base:");
    fflush(stdin);
    scanf("%d", &dstB);
    fflush(stdin);
    printf("\nPlease input the Number:");
    fflush(stdin);
    scanf("%s", inputC);
    numberConversion(srcB, dstB, inputC, alphabet, outC);

    int lenS = 0;
    while (outC[lenS++] != '\0') {
    }

    for (int i = 0; i < (lenS / 2); i++) {
        Elem e;
        e.val = (int) outC[i];
        sPush(sStack, e);
    }
    for (int i = (lenS / 2); i < lenS; i++) {
        if (sPeek(sStack)->val == outC[i]) {
            free(sPop(sStack));
        }
    }
    if (sIsEmpty(sStack)) {
        printf("\n%s :\n is a palindrome string.", (char *) outC);
    } else {
        printf("\n%s :\n is not a palindrome string.", (char *) outC);
    }
    free(sStack);
}

void bracketsMatchingMain() {
    printf("\n======bracketsMatching========================");
    char c;
    SeqStack *sStack;
    sStack = createSeqStack(64);
    fflush(stdin);
    printf("\nPlease input a string:");
    while (scanf("%c", &c) >= 1) {
        if (c == '\n') {
            break;
        }
        if (c == '(' || c == '[' || c == '{') {
            Elem e = {(int) c};
            sPush(sStack, e);
        }
        if (c == ')' && sPeek(sStack)->val == (int) '(')
            free(sPop(sStack));
        if (c == ']' && sPeek(sStack)->val == (int) '[')
            free(sPop(sStack));
        if (c == '}' && sPeek(sStack)->val == (int) '{')
            free(sPop(sStack));
    }
    if (sIsEmpty(sStack)) {
        printf("\nMatch!");
    } else {
        printf("\nNot match!");
    }
    free(sStack);
}

void hanoiTowerMain() {
    printf("\n======hanoiTower==============================");
    int n;

    printf("\nPlease input the height of the Hanoi tower:");
    fflush(stdin);
    scanf("%d", &n);
    HanoiSeqStack *sTodo;
    sTodo = createHSeqStack(256);
    HanoiProb h0 = {n, 1, 3}, *tmp;
    hPush(sTodo, h0);
    while (!hIsEmpty(sTodo)) {
        tmp = hPop(sTodo);
        if (tmp->len == 1) {
            printf("\nmove from %d to %d", tmp->from, tmp->to);
            free(tmp);
            tmp = NULL;
            continue;
        }
        HanoiProb h1, h2 = {1, tmp->from, tmp->to}, h3;
        h1.len = tmp->len - 1;
        h1.to = tmp->to;
        if (tmp->from * tmp->to == 2) {
            h1.from = 3;
        } else if (tmp->from * tmp->to == 3) {
            h1.from = 2;
        } else {
            h1.from = 1;
        }
        h3.len = tmp->len - 1;
        h3.from = tmp->from;
        if (tmp->from * tmp->to == 2) {
            h3.to = 3;
        } else if (tmp->from * tmp->to == 3) {
            h3.to = 2;
        } else {
            h3.to = 1;
        }
        hPush(sTodo, h1);
        hPush(sTodo, h2);
        hPush(sTodo, h3);

    }

    free(sTodo);
}

void expressionValueMain(){
    printf("\n======expressionValueMain=====================");
    char exp[128];
    printf("\nPlease input the expression:");
    fflush(stdin);
    scanf("%s",exp);
    SeqStack *numStack, *expStack; // ()==4 ^==3 */==2 +-==1
    numStack = createSeqStack(64);
    expStack = createSeqStack(64);
    Elem e0={'@', -1};
    sPush(expStack,e0);
    int tmpVal=0,pos=0,a,b,tmp;
    char c,tmpC;
    while (exp[pos]!='\0'){
        if (exp[pos]>='0'&&exp[pos]<='9'){

            tmpVal = exp[pos]-'0';
            pos++;
            while (exp[pos]>='0'&&exp[pos]<='9'){
                tmpVal = tmpVal*10 +exp[pos]-'0';
                pos++;
            }
            Elem e={tmpVal};
            sPush(numStack, e);
            continue;
        } else {
            if(exp[pos]==')'){
                while(sPeek(expStack)->val!=(int)'('){
                    a= sPeek(numStack)->val;
                    free(sPop(numStack));
                    b= sPeek(numStack)->val;
                    free(sPop(numStack));
                    c= (char)sPeek(expStack)->val;
                    free(sPop(expStack));
                    Elem e={calc(a,b,c)};
                    sPush(numStack,e);
                }
                free(sPop(expStack));
                pos++;
                continue;
            } // ) end
            if(exp[pos]=='('){
                Elem e={(int)exp[pos], getPriority(exp[pos])};
                sPush(expStack,e);
                pos++;
                continue;
            }
            if (sPeek(expStack)->val2< getPriority(exp[pos])){
                Elem e={(int)exp[pos], getPriority(exp[pos])};
                sPush(expStack,e);
            }else{
                tmpC=exp[pos];
                while (getPriority(tmpC)<= sPeek(expStack)->val2&& sPeek(expStack)->val!='('){
                    a= sPeek(numStack)->val;
                    free(sPop(numStack));
                    b= sPeek(numStack)->val;
                    free(sPop(numStack));
                    c= (char)sPeek(expStack)->val;
                    free(sPop(expStack));
                    Elem e={calc(a,b,c)};
                    sPush(numStack,e);
                }
                Elem e2 = {tmpC, getPriority(tmpC)};
                sPush(expStack, e2);
            } // calc end
        }
        pos++;
    } // while end
    while (!sIsEmpty(numStack)){
        a= sPeek(numStack)->val;
        free(sPop(numStack));
        b= sPeek(numStack)->val;
        free(sPop(numStack));
        c= (char)sPeek(expStack)->val;
        free(sPop(expStack));
        Elem e={calc(a,b,c)};
        if (sIsEmpty(numStack)){
            printf("\nAnswer: %d",e.val);
            break;
        }
        sPush(numStack,e);
    }

    free(numStack);
    free(expStack);
}

void backpackProblemMain() {
    printf("\n======backpackProblem=========================");
    int T = 10, N = 6, W[6] = {1, 8, 4, 3, 5, 2};
    SeqStack *sStack;
    sStack = createSeqStack(N);

    for (int i = 0; i < N; i++) {
        sStack->top = sStack->bottom; // clear
        Elem e0 = {W[i], T - W[i], i + 1};
        sPush(sStack, e0);
        while (!sIsEmpty(sStack)) {
            for (int j = sPeek(sStack)->val3; j <= N && sPeek(sStack)->val2 > 0 && sPeek(sStack)->val3 <= N; j++) {
                Elem e = {W[sPeek(sStack)->val3], sPeek(sStack)->val2 - W[sPeek(sStack)->val3],
                          sPeek(sStack)->val3 + 1};
                sPush(sStack, e);
            }
            if (sPeek(sStack)->val2 == 0) {
                sShow(sStack);
                printf("\n");
            }
            if (sPeek(sStack)->val3 > N) {
                free(sPop(sStack));
            }
            if (sIsEmpty(sStack)) {
                break;
            }
            Elem *ps = sPop(sStack), nextE;
            nextE.val = W[ps->val3];
            if (sIsEmpty(sStack)) {
                break;
            }
            // nextE.val2 =sIsEmpty(sStack)?ps->val2 - nextE.val: sPeek(sStack)->val2 - nextE.val;
            nextE.val2 = sPeek(sStack)->val2 - nextE.val;
            nextE.val3 = ps->val3 + 1;
            free(ps);
            sPush(sStack, nextE);

        }
    }
}

void nQueensProblemMain() {
    printf("\n======nQueenProblem===========================");
    int n, ctr = 0;
    printf("\nPlease input the number of the table:");
    fflush(stdin);
    scanf("%d", &n);
    int sStack[20] = {0};
    int top = 0;
    ++top;
    sStack[top] = 0;
    while (top > 0) {
        sStack[top] += 1;
        while (sStack[top] <= n && !canSetQueen(sStack, top)) {
            sStack[top] += 1;
        }
        if (sStack[top] == n + 1) {
            sStack[top] = 0;
            --top;
            continue;
        }
        if (top == n) {
            ++ctr;
            --top; // ?
        } else {
            ++top;
            sStack[top] = 0;
        }
    }

    printf("%d", ctr);
}

void mazeProblemMain() {
    printf("\n======mazeProblem=============================");
    // 0 == road, 1== wall, -1 == target
    int map[20][20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
                       1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1,
                       1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1,
                       1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1,
                       1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    SeqStack *sStack;
    sStack = createSeqStack(400);
    Elem e = {1, 1, 0}; // 1 right 2 down 3 left 4 up
    sPush(sStack, e);
    render(map);
    int solves=0;
    while (!sIsEmpty(sStack)) {
        // next
        sStack->arr[sStack->top].val3 += 1;
        Elem newE = {0, 0, 0};
        if (sPeek(sStack)->val3 == 1) {
            newE.val = sPeek(sStack)->val + 1;
            newE.val2 = sPeek(sStack)->val2;
        }
        if (sPeek(sStack)->val3 == 2) {
            newE.val = sPeek(sStack)->val;
            newE.val2 = sPeek(sStack)->val2 + 1;
        }
        if (sPeek(sStack)->val3 == 3) {
            newE.val = sPeek(sStack)->val - 1;
            newE.val2 = sPeek(sStack)->val2;
        }
        if (sPeek(sStack)->val3 == 4) {
            newE.val = sPeek(sStack)->val;
            newE.val2 = sPeek(sStack)->val2 - 1;
        }
        // check
        while (!canWalk(map, sStack, newE) && sStack->arr[sStack->top].val3 <= 4) {
            sStack->arr[sStack->top].val3 += 1;
            if (sPeek(sStack)->val3 == 1) {
                newE.val = sPeek(sStack)->val + 1;
                newE.val2 = sPeek(sStack)->val2;
            }
            if (sPeek(sStack)->val3 == 2) {
                newE.val = sPeek(sStack)->val;
                newE.val2 = sPeek(sStack)->val2 + 1;
            }
            if (sPeek(sStack)->val3 == 3) {
                newE.val = sPeek(sStack)->val - 1;
                newE.val2 = sPeek(sStack)->val2;
            }
            if (sPeek(sStack)->val3 == 4) {
                newE.val = sPeek(sStack)->val;
                newE.val2 = sPeek(sStack)->val2 - 1;
            }
        }
        // failed to find a way, back
        if (sPeek(sStack)->val3 > 4&&map[sPeek(sStack)->val][sPeek(sStack)->val2]!=-1) {
            free(sPop(sStack));
            continue;
        }
        // find a way, push it
        if (sPeek(sStack)->val3 <= 4) {
            sPush(sStack, newE);
            continue;
        }
        if (map[sPeek(sStack)->val][sPeek(sStack)->val2] == -1) { // find target, output ( and break?)
            printf("\nRoute %d\n",solves++);
            showWay(map, sStack);
            free(sPop(sStack));
        }
    }

}

// ProgramInnerFunctions
void showStack(SeqStack *sStack) {
    int ctr = 0;
    int top;
    top=sStack->top;
    while (top>sStack->bottom){
        printf("%d ",sStack->arr[top--].val);
    }

}

int getIndex(const char alphabet[], char v) {
    int index = 0;
    while (alphabet[index] != '\0' && alphabet[index] != v) {
        index++;
    }
    return index;
}

void numberConversion(int srcB, int dstB, char srcS[], char alphabets[], char outS[]) {
    int oVal = 0, len = 0;
    SeqStack *resStack;
    resStack = createSeqStack(128);
    while (srcS[len] != '\0') {
        oVal = oVal * srcB + getIndex(alphabets, srcS[len]);
        len++;
    }
    while (oVal != 0) {
        Elem e = {oVal % dstB};
        oVal = oVal / dstB;
        sPush(resStack, e);
    }
    len = 0;
    while (!sIsEmpty(resStack)) {
        Elem *e = sPop(resStack);
        outS[len++] = alphabets[e->val];
        free(e);
    }
    outS[len] = '\0';
}

int canSetQueen(int arr[], int v) {
    for (int i = 1; i < v; i++) {
        if (arr[i] == arr[v] || abs(arr[i] - arr[v]) == abs(i - v))
            return 0;
    }
    return 1;
}

int canWalk(int map[20][20], SeqStack *sStack, Elem e) {
    // chk map
    if (map[e.val][e.val2] == 1) {// wall
        return 0;
    }
    for (int i = 1; i <= sStack->top; i++) {
        if (e.val == sStack->arr[i].val && e.val2 == sStack->arr[i].val2) {
            return 0;
        }
    }
    return 1;
}

void render(int map[20][20]) { // 0==road, 1==wall, -1==target, >=2 way;
    char outString[(20 + 1) * 20 + 1];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            outString[i * 21 + j] = (map[i][j] == 0) ? ' ' : ((map[i][j] == 1) ? '#' : '*');
        }
        outString[(i+1) * 21 - 1] = '\n';
    }
    outString[(20 + 1) * 20] = '\0';
    printf("%s", outString);
}

void showWay(int map[20][20], SeqStack *wayStack) {
    int tmpMap[20][20];
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            tmpMap[x][y] = map[x][y];
        }
    }
    for (int i = 1; i <= wayStack->top; i++) {
        tmpMap[wayStack->arr[i].val][wayStack->arr[i].val2] = i + 2;
    }
    render(tmpMap);
}

int getPriority(char c){
    if (c=='('||c==')')
        return 4;
    if (c=='^')
        return 3;
    if (c=='*'||c=='/')
        return 2;
    if (c=='+'||c=='-')
        return 1;
    return 0;
}

int calc(int a, int b, char c){
    if (c=='+')
        return a+b;
    if (c=='-')
        return a-b;
    if (c=='*')
        return a*b;
    if (c=='/')
        return (int)a/b;
    if (c=='^')
        return (int)pow((double )a, (double )b);
    return a;
}