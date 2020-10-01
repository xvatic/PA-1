//
//  main.c
//  Ukol1
//
//  Created by Евгений on 10/1/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    int a = 0;
    
    scanf("%d", &a);
    for (int i=1; i<=a; i++) {
        int c =a;
        int n =0;
        if ((i%3)==0) {
            while ((c/=10)>0) {
                n++;
            }
            if (n<9){
                for (int j =0 ; j<(9-n); j++) {
                    printf("%d", 0);
                }
                printf("%d\n", i);
            }
        }
        
    }
    return 0;
}

