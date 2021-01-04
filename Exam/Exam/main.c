#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#endif /* __PROGTEST__ */

typedef struct TRecord {
    char* str;
    int u[2];
    int d[2];
} TRECORD;


int compareRecords (const void* a, const void* b) {
    TRECORD *r1 = (TRECORD*)a;
    TRECORD *r2 = (TRECORD*)b;
    if(strcmp(r1->str, r2->str) > 0) {
        return 1;
    } else if (strcmp(r1->str, r2->str) < 0) {
        return -1;
    } else {
        int res = ((r1->d[0] + r1->d[1]) - (r1->u[0] + r1->u[1])) - ((r2->d[0] + r2->d[1]) - (r2->u[0] + r2->u[1]));
        if (res > 0) {
            return 1;
        } else if (res < 0) {
            return -1;
        } else {
            int res = ((r1->d[0] + r1->d[1]) + (r1->u[0] + r1->u[1])) - ((r2->d[0] + r2->d[1]) + (r2->u[0] + r2->u[1]));
            if (res >0) {
                return 1;
            } else if(res<0) {
                return -1;
            } else {
                if ((r1->d[0]) > (r2->d[0])) {
                    return 1;
                } else if((r1->d[0]) < (r2->d[0])){
                    return -1;
                } else {
                    if ((r1->d[1]) > (r2->d[1])) {
                        return 1;
                    } else if((r1->d[1]) < (r2->d[1])){
                        return -1;
                    } else {
                        if ((r1->u[0]) > (r2->u[0])) {
                            return 1;
                        } else if((r1->u[0]) < (r2->u[0])){
                            return -1;
                        } else {
                            if ((r1->u[1]) > (r2->u[1])) {
                                return 1;
                            } else if((r1->u[1]) < (r2->u[1])){
                                return -1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}


int extendArray (TRECORD ** rec, int* size) {
    *size *= 1.5;
    *rec = (TRECORD*)realloc(*rec, *size*sizeof(TRECORD));
    return 0;
}

int is_empty(const char *s) {
  while (*s != '\0') {
    if (!isspace((unsigned char)*s))
      return 0;
    s++;
  }
  return 1;
}



int countCollectible ( const char * list )
{
    int size = 100;
    int counter = 0;
    int count_string = 100;
    char* buff = (char*)malloc(strlen(list)+1);
    strcpy(buff, list);
    TRECORD* arr = NULL;
    arr = (TRECORD*)malloc(size* sizeof(TRECORD));
    char** records = (char**)malloc(count_string*sizeof(char*));
    char* piece = strtok(buff, "{}");
    if (piece == NULL) {
        return 0;
    }
    if (!(is_empty(piece) == 1)) {
        records[counter] = (char*)malloc(strlen(piece) + 1);
        strcpy(records[counter], piece);
        counter++;
    }
    while (1) {
        piece = strtok(NULL, "{}");
        if(piece == NULL) break;
        if(!(is_empty(piece) == 1)) {
            records[counter] = (char*)malloc(strlen(piece)+1);
            strcpy(records[counter], piece);
            counter++;
            if(counter == count_string-2) {
                count_string*=1.5;
                records = (char**)realloc(records, count_string*sizeof(char*));
            }
        }
    }
    int i = 0;
    int lim = counter;
    counter = 0;
   
    
    while (1) {
        if (i == lim) {
            break;
        }
        char* name = strtok(records[i], "\'");
        if (is_empty(name) == 1) {
            name = strtok(NULL, "\'");
        }
        arr[counter].str = (char*)malloc(strlen(name) + 1);
        strcpy(arr[counter].str, name);
        char* least = strtok(NULL, "}");
        sscanf(least, " ; [ %d | %d ] ; [ %d | %d ] ", &arr[counter].u[0], &arr[counter].u[1], &arr[counter].d[0], &arr[counter].d[1]);
        counter++;
        
        if (counter == size - 1) {
            extendArray(&arr, &size);
        }
        i++;
    }
    for (int i = 0; i<lim; i++) {
        free(records[i]);
    }
    free(records);
    free(piece);
    free(buff);
    int count = 0;
    const char* s = "Segfault Limited";
    for (int i = 0; i<lim; i++) {
        if (strcmp(s, arr[i].str) == 0) {
            if (arr[i].d[0] + arr[i].d[1] == 51 && arr[i].u[0] + arr[i].u[1] != 51) {
                count++;
                continue;
            }
            if (arr[i].u[0] + arr[i].u[1] == 51 && arr[i].d[0] + arr[i].d[1] != 51) {
                count++;
                continue;
            }
        }
    }
    for (int i = 0; i<counter; i++) {
        free(arr[i].str);
    }
    free(arr);
    return count;
}

int countUnique  ( const char * list )
{
    int size = 100;
     int counter = 0;
     int count_string = 100;
     char* buff = (char*)malloc(strlen(list)+1);
     strcpy(buff, list);
     TRECORD* arr = NULL;
     arr = (TRECORD*)malloc(size* sizeof(TRECORD));
     char** records = (char**)malloc(count_string*sizeof(char*));
     char* piece = strtok(buff, "{}");
     if (piece == NULL) {
         return 0;
     }
     if (!(is_empty(piece) == 1)) {
         records[counter] = (char*)malloc(strlen(piece) + 1);
         strcpy(records[counter], piece);
         counter++;
     }
     while (1) {
         piece = strtok(NULL, "{}");
         if(piece == NULL) break;
         if(!(is_empty(piece) == 1)) {
             records[counter] = (char*)malloc(strlen(piece)+1);
             strcpy(records[counter], piece);
             counter++;
             if(counter == count_string-2) {
                 count_string*=1.5;
                 records = (char**)realloc(records, count_string*sizeof(char*));
             }
         }
     }
     int i = 0;
     int lim = counter;
     counter = 0;
    
     
     while (1) {
         if (i == lim) {
             break;
         }
         char* name = strtok(records[i], "\'");
         if (is_empty(name) == 1) {
             name = strtok(NULL, "\'");
         }
         arr[counter].str = (char*)malloc(strlen(name) + 1);
         strcpy(arr[counter].str, name);
         char* least = strtok(NULL, "}");
         int a,b,c,d;
         sscanf(least, " ; [ %d | %d ] ; [ %d | %d ] ", &a, &b, &c, &d);
         
         if (a + b > c + d) {
             if (a > b) {
                 arr[counter].d[0] = b;
                 arr[counter].d[1] = a;
                 if (c > d) {
                     arr[counter].u[0] = d;
                     arr[counter].u[1] = c;
                 } else {
                     arr[counter].u[0] = c;
                     arr[counter].u[1] = d;
                 }
             } else {
                 arr[counter].d[0] = a;
                 arr[counter].d[1] = b;
                 if (c > d) {
                     arr[counter].u[0] = d;
                     arr[counter].u[1] = c;
                 } else {
                     arr[counter].u[0] = c;
                     arr[counter].u[1] = d;
                 }
             }
         } else if (a + b < c + d){
             if (c > d) {
                 arr[counter].d[0] = d;
                 arr[counter].d[1] = c;
                 if (a > b) {
                     arr[counter].u[0] = b;
                     arr[counter].u[1] = a;
                 } else {
                     arr[counter].u[0] = a;
                     arr[counter].u[1] = b;
                 }
             } else {
                 arr[counter].d[0] = c;
                 arr[counter].d[1] = d;
                 if (a > b) {
                     arr[counter].u[0] = b;
                     arr[counter].u[1] = a;
                 } else {
                     arr[counter].u[0] = a;
                     arr[counter].u[1] = b;
                 }
             }
         } else {
             if (abs(b - a) > abs(d - c)) {
                 if (a > b) {
                     arr[counter].d[0] = b;
                     arr[counter].d[1] = a;
                     if (c > d) {
                         arr[counter].u[0] = d;
                         arr[counter].u[1] = c;
                     } else {
                         arr[counter].u[0] = c;
                         arr[counter].u[1] = d;
                     }
                 } else {
                     arr[counter].d[0] = a;
                     arr[counter].d[1] = b;
                     if (c > d) {
                         arr[counter].u[0] = d;
                         arr[counter].u[1] = c;
                     } else {
                         arr[counter].u[0] = c;
                         arr[counter].u[1] = d;
                     }
                 }
             } else {
                 if (c > d) {
                     arr[counter].d[0] = d;
                     arr[counter].d[1] = c;
                     if (a > b) {
                         arr[counter].u[0] = b;
                         arr[counter].u[1] = a;
                     } else {
                         arr[counter].u[0] = a;
                         arr[counter].u[1] = b;
                     }
                 } else {
                     arr[counter].d[0] = c;
                     arr[counter].d[1] = d;
                     if (a > b) {
                         arr[counter].u[0] = b;
                         arr[counter].u[1] = a;
                     } else {
                         arr[counter].u[0] = a;
                         arr[counter].u[1] = b;
                     }
                 }
             }
         }
       
         counter++;
         
         if (counter == size - 1) {
             extendArray(&arr, &size);
         }
         i++;
     }
     for (int i = 0; i<lim; i++) {
         free(records[i]);
     }
     free(records);
     free(piece);
     free(buff);
     qsort(arr, lim, sizeof(TRECORD), compareRecords);
     
    
    char* s = (char*)malloc(strlen(arr[0].str)+1);
    strcpy(s, arr[0].str);
    int a = arr[0].u[0],b=arr[0].u[1],c=arr[0].d[0],d=arr[0].d[1];
    int match = 0;
    int flag = 0;
    for (int i = 1; i<lim; i++) {
        if(arr[i].u[0] == a && arr[i].u[1] == b && arr[i].d[0] == c && arr[i].d[1] == d && strcmp(s, arr[i].str) == 0) {
            match++;
            flag = 1;
        } else {
            if(flag == 1) {
                flag = 0;
            }
            a = arr[i].u[0]; b=arr[i].u[1]; c=arr[i].d[0]; d=arr[i].d[1];
            s = (char*)realloc(s, strlen(arr[i].str)+1);
            strcpy(s, arr[i].str);
        }
    }
    for (int i = 0; i<counter; i++) {
        free(arr[i].str);
    }
    free(arr);
    free(s);
     return lim-match;
}

uint64_t countTowers ( const char * list )
{
  return 0;
}

#ifndef __PROGTEST__
int main ( void )
{
  const char * str1 =
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    "{ 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'Segfault Limited' ; [ 50 | 1 ] ; [ 1 | 4 ] }\n"
    
    ;
  const char * str2 =
    
    "{'MemLeak';[1|3];[2|2]}\n"
    "{'MemLeak';[1|3];[2|3]}\n"
    "{'MemLeak';[3|1];[2|2]}\n"
    "{'MemLeak';[1|2];[2|2]}\n"
    "{'MemLeak';[2|2];[1|3]}\n"
    ;
  const char * str3 =
    "{'-Wall -pedantic -Werror -Wno-long-long -O2';[2|2];[3|3]}\n"
    "{'-Wall -pedantic -Werror -Wno-long-long -O2';[2|2];[3|3]}\n"
    "{'-Wall -pedantic -Werror -Wno-long-long -O2';[2|2];[3|3]}\n";
  const char * str4 =
    "{'-fsanitize=address -g';[2|2];[2|2]}\n"
    "{'-fsanitize=address -g';[1|3];[3|1]}\n"
    "{'-fsanitize=address -g';[2|2];[2|2]}\n";

 // assert ( countCollectible ( str1 ) == 0 );
 // assert ( countUnique ( str1 ) == 3 );
  assert ( countUnique ( str2 ) == 4 );
  assert ( countUnique ( str3 ) == 3 );
  assert ( countUnique ( str4 ) == 5 );
  assert ( countTowers ( str3 ) == 10 );
  assert ( countTowers ( str4 ) == 114 );
  return 0;
}
#endif /* __PROGTEST__ */

