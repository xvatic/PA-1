//
//  main.c
//  Zahrivajici uloha
//
//  Created by Евгений on 10/21/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    printf("ml' nob:\n");
    if (scanf(" %d", &a) != 1 || a<1 || a >5) {
        printf("luj\n");
        return 1;
    }
    printf("Qapla'\n");
    switch (a){
        case 1:
            printf("noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
            break;
            
        case 2:
            printf("Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
            break;
        case 3:
            printf("qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
            break;
        case 4:
            printf("Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
            break;
        case 5:
            printf("leghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
            break;
    }
    return 0;
}
