//
//  main.c
//  Konfigurace ústředny
//
//  Created by Евгений on 11/26/20.
//  Copyright © 2020 Евгений. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char *str = NULL;
    size_t len = 0;
    int d, hh, mm, nc, month;
     int bytes_now;
     char nz[1001];
     char m[4];
     char c2;
    
    while(scanf( " %d : %1000s %3s %d %d : %d %c%n",  &nc, nz, m, &d, &hh, &mm, &c2, & bytes_now) == 7) {
        
    }
    printf("Hello, World!\n");
    return 0;
}
