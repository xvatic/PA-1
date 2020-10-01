//
//  main.c
//  Ukol3
//
//  Created by Евгений on 10/1/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char ft[] = "";
    fgets(ft, 11 , stdin);
    char * hh = strtok(ft, ":");
    char * mm = strtok(NULL, ":");
    char * ss = strtok(NULL, ":");
    
    
    if(atoi(hh) <= 12 && atoi(mm) <= 59 && atoi(ss) <= 59)
    {
        if (strstr(ss, "PM") != NULL){
            int hha = atoi(hh)+12;
            printf("%d:%s:%c%c\n", hha,mm, ss[0],ss[1] );
        }
        if (strstr(ss, "AM") != NULL){
            printf("%s:%s:%c%c\n", hh,mm, ss[0],ss[1] );
        }
        
    }
    else
    {
        printf("wrong format\n");
    }
    
    
    return 0;
}
