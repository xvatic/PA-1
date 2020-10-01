//
//  main.c
//  Ukol2
//
//  Created by Евгений on 10/1/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

int convert(char * binary, int n) {
    int val=0;
    
    if (binary[0] == '0') {
        for(int i=n-1; i>0; i--) {
            val+=(int)(binary[i]-'0')*pow(2, n-i-1);
        }
        
    } else if(binary[0] == '1') {
        for(int i=1; i<=10; i++) {
            if(binary[i] == '0') binary[i]='1';
            else if(binary[i] == '1') binary[i]='0';
        }
        for(int i=n-1; i>=1; i--) {
            val+=(int)(binary[i]-'0')*pow(2, n-i-1);
        }
        val++;
        val = -val;
    } else {printf("wrong format");}
        
    return val;
}


int main(int argc, const char * argv[]) {
    int n = 0;
    scanf("%d\n", &n);
    
    char x[n+1];
    char y[n+1];
    fgets(x,sizeof(x), stdin);
    fgets(y,sizeof(y), stdin);
    
    printf("%d\n%d\n", convert(x, n), convert(y, n));
    
    

    return 0;
}
