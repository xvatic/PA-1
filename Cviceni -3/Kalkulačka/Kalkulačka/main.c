//
//  main.c
//  Kalkulačka
//
//  Created by Евгений on 10/12/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double a,b ;
    double c = 0.0;
    char op, r;
    printf("Zadejte vzorec:\n");
    if (scanf(" %lf %c %lf %c", &a, &op, &b, &r) != 4 || (op != '+' && op != '-' && op != '*'&& op != '/') || r != '=') {
        printf("Nespravny vstup.\n");
        return 1;
    }
    
    switch (op){
        case '+':
            c = a+b;
            break;
            
        case '-':
            c = a-b;
            break;
        case '*':
            c = a*b;
            break;
        case '/':
            c = a/b;
            break;
    }
    if (floor(c) == c ){
        printf("%d\n",(int) (floor(c)));
    } else{
        printf("%lf\n", c);
    }

    
    return 0;
}
