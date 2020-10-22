//
//  main.c
//  Ukol2
//
//  Created by Евгений on 10/22/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>



int isPrime(int number) {
    int i;
    for (i=2; i<number; i++) {
        if (number % i == 0 && i != number) return 0;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    int a;
    if (scanf(" %d", &a) != 1) {
        printf("Nespravny vstup\n");
        return 1;
    }
    int c = a;
    printf("%d =", c);
    for (int i = 2; isPrime(a)!=1; i++) {
        int moc = 0;
        if(a % i == 0 && i !=a){
            while(a%i==0) {
                a = a/i;
                moc++;
            }
            
            printf(" %d ^ %d *", i, moc);
        }
       
    }
    printf(" %d ^ %d\n", a, 1);
   
}
