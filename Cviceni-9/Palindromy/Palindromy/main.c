//
//  main.c
//  Palindromy
//
//  Created by Евгений on 11/21/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(char* str) {
    printf("%c", str[0]);
    return 0;
}

int main(int argc, const char * argv[]) {
    char *str = NULL;
    size_t len = 0;
    while(getline(&str, &len , stdin) != -1) {
        printf("%zd\n",strlen(str));
        check(str);
    }
    return 0;
}
