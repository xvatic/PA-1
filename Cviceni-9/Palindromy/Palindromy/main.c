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
#include <ctype.h>
int check(char* str) {
    int i = 0;
    int j = (int)strlen(str)-2;
    if ((int)strlen(str)-2 == 0) {
        return 2;
    }
    if ((int)strlen(str)-2 == 1) {
        if (str[i] == str[j]) {
            return 2;
        }
        if (tolower(str[i]) == tolower(str[j])) {
            return 1;
        }
        return 0;
    }
    while(1) {
       
        if ((i == j && (strlen(str)-1)%2!=0) || (i+1 == j && (strlen(str)-1)%2==0)) {
            return 2;
        }
        if (isspace(str[i]) != 0) {
            i++;
            continue;
        }
        if (isspace(str[j]) != 0) {
            j--;
            continue;
        }
        if (str[i] != str[j]) {
            break;
        }
        i++;
        j--;
        if ((i == j && (strlen(str)-1)%2!=0) || (i+1 == j && (strlen(str)-1)%2==0)) {
            return 2;
        }
    }
    for(int i = 0; i<(int)strlen(str)-1; i++){
      str[i] = tolower(str[i]);
    }
    i = 0;
    j = (int)strlen(str)-2;
    while(1) {
        if ((i == j && (strlen(str)-1)%2!=0)|| (i+1 == j && (strlen(str)-1)%2==0)) {
            return 1;
        }
        if (isspace(str[i]) != 0) {
            i++;
            continue;
        }
        if (isspace(str[j]) != 0) {
            j--;
            continue;
        }
        if (str[i] != str[j]) {
            return 0;
        }
        i++;
        j--;
        if ((i == j && (strlen(str)-1)%2!=0)|| (i+1 == j && (strlen(str)-1)%2==0)) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    char s[12] = "abcde";
    int res = strlen(s);
    printf("%d", res);
    res = sizeof(s);
    printf("%d", res);
    char *str = NULL;
    size_t len = 0;
    printf("Zadejte retezec:\n");
    while(getline(&str, &len , stdin) != -1) {
        if (str[strlen(str)-1] != '\n') {
            printf("Nespravny vstup.\n");
            return 1;
        }
        if(strlen(str) == 1) {
            printf("Nespravny vstup.\n");
            return 1;
        }
        for(int i = 0; i<(int)strlen(str)-1; i++) {
            if(isspace(str[i]) == 0) {
                break;
            }
            if (i == (int)strlen(str)-2) {
                printf("Nespravny vstup.\n");
                return 1;
            }
        }
        
        int res = check(str);
        if (res == 0) {
            printf("Retezec neni palindrom.\n");
            
        } else if (res == 2) {
            printf("Retezec je palindrom (case-sensitive).\n");
            
        } else {
            printf("Retezec je palindrom (case-insensitive).\n");
            
        }
            
    }
    free(str);
    return 0;
}
