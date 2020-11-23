#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct DateTime{
    int mon;
    int day;
    int hour;
    int minute;
} TDateTime;

typedef struct Record {
    char rz[1001];
    TDateTime dt;
    int nCam;
} TRecord;

int extendArray (TRecord * rec, int* size){
    *size *= 1.5;
    rec = (TRecord*)realloc(rec, *size*sizeof(TRecord));
    return 0;
}

int searchRecord (TRecord* arr, TRecord request) {
    return 0;
}

int initRecord (TRecord* recElem, int d, int hh, int mm, int nc, int m, char* nz) {
    recElem->dt.mon = m;
    recElem->dt.hour = hh;
    recElem->dt.minute = mm;
    recElem->dt.day = d;
    recElem->nCam = nc;
    strcpy(recElem->rz, nz);
    return 0;
}

int checkInput (int d, int hh, int mm, int nc, int* month, char* nz, char* m) {
    if (hh > 23 || hh < 0 || mm > 59 || mm < 0 || d < 1) {
        return 0;
    }
    const char months[12][4] = {
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
    };
    
    const int amountOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(m[0] >= 'A' && m[0] <= 'Z')
    {
        for (int i = 0; i<12; i++) {
            if (strcmp(m, months[i]) == 0) {
                *month = i + 1;
                break;
            }
            if (i == 11) {
                return 0;
            }
        }
        if (d > amountOfDays[*month-1]) {
            return 0;
        }
        return 1;
    } else {
        return 0;
    }

}
//sscanf(str, "%d : %1000s %3s %d %d : %d", &nc, &nz, &m, &d, &hh, &mm) == 6
int parse(TRecord* rec, int* size, char* str, int* count) {
    int d, hh, mm, nc, month;
    
    char nz[1001];
    char m[4];
    char* piece =  strtok(str,"[,{}]");
    
    while(piece != NULL) {
        if (strlen(piece) < 15) {
            piece =  strtok(NULL,"[,{}]");
            continue;
        }
        if(sscanf(piece, " %d : %1000s %3s %d %d : %d ", &nc, nz, m, &d, &hh, &mm) == 6){
            if (checkInput(d, hh, mm, nc, &month, nz, m) == 1) {
                initRecord(&rec[*count], d, hh, mm, nc, month, nz);
                ++*count;
            } else {
                return 0;
            }
            if (count == size-1) {
                extendArray(rec, size);
            }
        } else {
            return 0;
        }
        
        piece =  strtok(NULL,"[,{}]");
    }
    return 1;
}

int main ( void )
 {
     int borderControlFlag = 0;
     char *str = NULL;
     size_t len = 0;
     printf("Data z kamer:\n");
     int count = 0;
     int res = 0;
     int size = SIZE;
     TRecord *arr = NULL;
     arr = (TRecord*)malloc(size* sizeof(TRecord));
     while(getline(&str, &len , stdin) != -1) {
         if (strchr(str, '{') != NULL) {
             borderControlFlag = 1;
         }
         if (strchr(str, '}') != NULL) {
             borderControlFlag = 2;
             res = parse(arr, &size, str, &count);
             if (res == 0) {
                 printf("Nespravny vstup.\n");
                 return 0;
             }
             continue;
         }
         res = parse(arr, &size, str, &count);
         if (res == 0) {
             printf("Nespravny vstup.\n");
             return 0;
         }
         if (borderControlFlag == 0 || borderControlFlag == 2) {
             printf("Nespravny vstup.\n");
             return 0;
         }
         if (strchr(str, '}') != NULL) {
             borderControlFlag = 2;
         }
     }
     if (borderControlFlag == 1) {
         printf("Nespravny vstup.\n");
         return 0;
     }
     printf("Hledani:\n");
     while(getline(&str, &len , stdin) != -1) {
         
     }
     
     
     free(str);
     free(arr);
     return 0;
 }
