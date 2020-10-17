//
//  main.c
//  Dvě kružnice
//
//  Created by Евгений on 10/17/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>

typedef struct Kruznice {
    double x;
    double y;
    double r;
} TKruznice;

void InitKruznice (TKruznice* kruznice, double x, double y, double r) {
    kruznice->x = x;
    kruznice->y = y;
    kruznice->r = r;
}

int main(int argc, const char * argv[]) {
    TKruznice k1,k2;
    double x, y, r;;
    printf("Zadejte parametry kruznice #1:\n");
    if (scanf("%lf %lf %lf", &x, &y, &r) != 3 || r == 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    InitKruznice(&k1, x, y, r);
    printf("Zadejte parametry kruznice #2:\n");
    if (scanf("%lf %lf %lf", &x, &y, &r) != 3 || r == 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    InitKruznice(&k2, x, y, r);
    printf("......");
    return 0;
}
