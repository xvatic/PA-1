//
//  main.c
//  Cviceni5
//
//  Created by Евгений on 10/24/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b;
    printf("Zadejte pocet poli:\n");
    if (scanf("%d", &a) != 1 || a<=0) {
        printf("Nespravny vstup.\n");
        return 1;
    };
    printf("Zadejte velikost pole:\n");
    if (scanf("%d", &b) != 1 || b<=0) {
        printf("Nespravny vstup.\n");
        return 1;
    };
    int l = a*b;
    printf("+");
    for (int i = 1; i<=l; i++) {
        printf("-");
    }
    printf("+\n");
    
    return 0;
}
