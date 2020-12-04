#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10


typedef struct DateTime{
    int mon;
    int day;
    int hour;
    int minute;
} TDateTime;

typedef struct Output {
    TDateTime dt;
    int amount;
    int cams[1000];
} TOutput;


typedef struct Record {
    char* numb;
    char* name;
} TRecord;


typedef struct Request {
    char rz[1001];
    TDateTime dt;
} TRequest;


int extendArray (TRecord ** rec, int* size) {
    *size *= 1.5;
    *rec = (TRecord*)realloc(*rec, *size*sizeof(TRecord));
    return 0;
}


int extendTempArray (char ** rec, int size) {
    *rec = (char*)realloc(*rec, size*sizeof(TOutput));
    return 0;
}

int convertT9(const char* str, char* par) {
    char* tmp = (char *) calloc((strlen(str)+1),sizeof(char));
    for(int i = 0; str[i]; i++){
      tmp[i] = tolower(str[i]);
    }
    for (int i = 0; i<strlen(str); i++) {
        if(tmp[i] == 32 || tmp[i] == '1') {
            tmp[i] = '1';
        } else if ((tmp[i] > 96 && tmp[i] < 100) || tmp[i] == '2') {
            tmp[i] = '2';
        } else if ((tmp[i] > 99 && tmp[i] < 103) || tmp[i] == '3') {
            tmp[i] = '3';
        } else if ((tmp[i] > 102 && tmp[i] < 106) || tmp[i] == '4') {
            tmp[i] = '4';
        } else if ((tmp[i] > 105 && tmp[i] < 109) || tmp[i] == '5') {
            tmp[i] = '5';
        } else if ((tmp[i] > 108 && tmp[i] < 112) || tmp[i] == '6') {
            tmp[i] = '6';
        } else if ((tmp[i] > 111 && tmp[i] < 116) || tmp[i] == '7') {
            tmp[i] = '7';
        } else if ((tmp[i] > 115 && tmp[i] < 119) || tmp[i] == '8') {
            tmp[i] = '8';
        } else if ((tmp[i] > 118 && tmp[i] < 123) || tmp[i] == '9') {
            tmp[i] = '9';
        } else {
            tmp[i] = '0';
        }
        
    }
    
        if (strcmp(tmp, par) == 0) {
            free(tmp);
            return 0;
        }
    
    
    free(tmp);
    return 1;
}

int deleteUser (TRecord* arr, int count, char* param) {
    int countOverlaps = 0;
    for (int i = 0; i<count; i++) {
        if(strcmp(arr[i].numb, param) == 0) {
            extendTempArray(&arr[i].numb, 1);
            strcpy(arr[i].numb, "");
            extendTempArray(&arr[i].name, 1);
            strcpy(arr[i].name, "");
            countOverlaps++;
            break;
        }
    }
    return countOverlaps;
}


int search(TRecord* arr, int count, char* param, int* overlap) {
    int countOverlaps = 0;
    for (int i = 0; i<count; i++) {
        if(strcmp(arr[i].numb, param) == 0) {
            *overlap = i;
            countOverlaps++;
        }
    }
    for (int i = 0; i<count; i++) {
        if(i == *overlap) continue;
        if (strlen(param) != strlen(arr[i].name)){
            continue;
        }
        if (convertT9(arr[i].name, param) == 0){
                *overlap = i;
                countOverlaps++;
        }
    }
    return countOverlaps;
}

int digits_only(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }

    return 1;
}

int is_empty(const char *s) {
  while (*s != '\0') {
    if (!isspace((unsigned char)*s))
      return 0;
    s++;
  }
  return 1;
}

int searchExistingperson(TRecord* arr, int count, char *s) {
    for (int i = 0; i<count; i++) {
        if(strcmp(arr[i].numb, s) == 0) {
            return i;
        }
    }
    return -1;
}


int main ( void )
 {

     printf("PBX configuration (+ = set, - = delete, ? = test, EOF = quit):\n");
     char* str = NULL;
     size_t len= 0;
     int count = 0;
     int size = SIZE;
     char c;
     int bytes_now;
     int res;
     TRecord *arr = NULL;
     arr = (TRecord*)malloc(size* sizeof(TRecord));
     char* least = NULL;
     

    while(getline(&str, &len, stdin) != EOF){
        sscanf(str, "%c%n", &c, &bytes_now);
        
        if (c == '+') {
            char* piece = strtok(str, " ");
            if (strlen(piece) != 1 || piece[0] != c) {
                printf("INVALID COMMAND\n");
                continue;
            }
            piece = strtok(NULL, " ");
            if (digits_only(piece) == 0) {
                printf("INVALID COMMAND\n");
                continue;
            }
            res = searchExistingperson(arr, count, piece);
            if (res != -1) {
                piece = strtok(NULL, "\"");
                if (is_empty(piece) == 1) {
                    piece = strtok(NULL, "\"");
                }
                least = strtok(NULL, "\"");
                if (least == NULL || is_empty(least) == 0) {
                    printf("INVALID COMMAND\n");
                    
                    continue;
                }
                extendTempArray(&arr[res].name, (int)(strlen(piece)+1));
                strcpy(arr[res].name, piece);
                printf("UPDATED\n");
                
                continue;
            }
            arr[count].numb = (char *) malloc((strlen(piece)+1)*sizeof(char));
            strcpy(arr[count].numb, piece);
            piece = strtok(NULL, "\"");
            if (is_empty(piece) == 1) {
                piece = strtok(NULL, "\"");
            }
            least = strtok(NULL, "\"");
            if (least == NULL || is_empty(least) == 0) {
                printf("INVALID COMMAND\n");
                
                continue;
            }
            arr[count].name = (char *) malloc((strlen(piece)+1)*sizeof(char));
            strcpy(arr[count].name, piece);
            count++;
            if (count == size-8) {
                extendArray(&arr, &size);
            }
            printf("NEW\n");
            
        } else if (c == '?') {
            char* piece = strtok(str, " ");
            if (strlen(piece) != 1 || piece[0] != c) {
                printf("INVALID COMMAND\n");
                
                continue;
            }
            piece = strtok(NULL, " \n");
            
            int overlap = -1;
            if (digits_only(piece) == 0) {
                printf("INVALID COMMAND\n");
                
                continue;
            }
            least = strtok(NULL, " ");
            if (least != NULL) {
                if (is_empty(least) == 0) {
                    printf("INVALID COMMAND\n");
                    
                    continue;
                }
            }
            
            res = search(arr, count, piece, &overlap);
            if (res == 0) {
                printf("NOT FOUND\n");
            } else if (res == 1 ) {
                printf("FOUND %s (%s)\n", arr[overlap].numb, arr[overlap].name);
            } else if(res > 1) {
                printf("AMBIGUOUS (%d matches)\n", res);
            }
            
            continue;
            
        } else if (c == '-') {
            char* piece = strtok(str, " ");
            if (strlen(piece) != 1 || piece[0] != c) {
                printf("INVALID COMMAND\n");
                
                continue;
            }
            piece = strtok(NULL, " \n");
            
            if (digits_only(piece) == 0) {
                printf("INVALID COMMAND\n");
                
                continue;
            }
            least = strtok(NULL, " ");
            if (least != NULL) {
                if (is_empty(least) == 0) {
                    printf("INVALID COMMAND\n");
                    
                    continue;
                }
            }
            
            res = deleteUser(arr, count, piece);
            if (res == 0) {
                printf("NOT FOUND\n");
            } else if (res == 1 ) {
                printf("DELETED\n");
            }
            
            
            continue;
        } else {
            printf("INVALID COMMAND\n");
            continue;
        }
        
     }
     
     for (int i = 0; i<count; i++) {
         free(arr[i].name);
         free(arr[i].numb);
     }
     
     free(arr);
     free(str);
     free(least);
     
     
     return 0;
 }
