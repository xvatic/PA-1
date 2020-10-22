//
//  main.c
//  Ukol1
//
//  Created by Евгений on 10/22/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char posl[]="";
    int count=0;
    
    scanf("%s", &posl);
    for(int i=0; posl[i]!= '\0'; i++) {
        if(posl[i]!='0' && posl[i]!='1') {
            printf("%c", posl[i]);
            printf("Nespravny vstup\n");
           
        }
        
    }
    char buf = posl[0];
    for(int i=1; posl[i]!= '\0'; i++) {
        if(buf != posl[i]){
            buf=posl[i];
            count++;
        }
        
    }
    printf("%d\n", count);
    return 0;
}
