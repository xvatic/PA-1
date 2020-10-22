//
//  main.c
//  Ukol3
//
//  Created by Евгений on 10/22/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>

int count_1(int n) {
    
    int count=0;
    int rem;
    while (n != 0) {
        rem = n % 2;
        if(rem == 1) {
            count++;
        }
        n /= 2;
        
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int x,y;
    char z1,z2,r;
    int count = 0;
    if (scanf("%c%d%c%d%c", &z1,&x,&r,&y, &z2) != 5 || r != ';' || z1 != '<' || z2 != '>' || x<0 || x> 255 || y<0 || y>255) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    for(int i=x; i<=y; i++) {
        count+=count_1(i);
    }
    printf("%d", (y-x+1)*8 - count);
    
    
    return 0;
}
