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

typedef struct Output {
    TDateTime dt;
    int amount;
    int cams[1000];
} TOutput;

typedef struct Record {
    char rz[1001];
    TDateTime dt;
    int nCam;
} TRecord;

typedef struct Request {
    char rz[1001];
    TDateTime dt;
} TRequest;

int extendArray (TRecord * rec, int* size){
    *size *= 1.5;
    rec = (TRecord*)realloc(rec, *size*sizeof(TRecord));
    return 0;
}

int extendTempArray (TOutput * rec, int* size){
    *size *= 1.5;
    rec = (TOutput*)realloc(rec, *size*sizeof(TOutput));
    return 0;
}

int compareRecords (const void* a, const void* b) {
    TRecord *r1 = (TRecord*)a;
    TRecord *r2 = (TRecord*)b;
    if(r1->dt.mon > r2->dt.mon) {
        return 1;
    } else if (r1->dt.mon < r2->dt.mon) {
        return -1;
    } else {
        if(r1->dt.day > r2->dt.day) {
            return 1;
        } else if (r1->dt.day < r2->dt.day) {
            return -1;
        } else {
            if(r1->dt.hour > r2->dt.hour) {
                return 1;
            } else if (r1->dt.hour < r2->dt.hour) {
                return -1;
            } else {
                if(r1->dt.minute > r2->dt.minute) {
                    return 1;
                } else if (r1->dt.minute < r2->dt.minute) {
                    return -1;
                } else {
                    if(r1->nCam > r2->nCam) {
                        return 1;
                    } else if (r1->nCam < r2->nCam) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}

int convertMonth (int m, char* month) {
    char months[12][4] = {
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
    month = months[m-1];
    return 0;
}

int compareDates (const void* a, const void* b) {
    TDateTime *r1 = (TDateTime*)a;
    TDateTime *r2 = (TDateTime*)b;
    if(r1->mon > r2->mon) {
        return 1;
    } else if (r1->mon < r2->mon) {
        return -1;
    } else {
        if(r1->day > r2->day) {
            return 1;
        } else if (r1->day < r2->day) {
            return -1;
        } else {
            if(r1->hour > r2->hour) {
                return 1;
            } else if (r1->hour < r2->hour) {
                return -1;
            } else {
                if(r1->minute > r2->minute) {
                    return 1;
                } else if (r1->minute < r2->minute) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }
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

int initdt (TDateTime* recElem, TDateTime selectedTime) {
    recElem->mon = selectedTime.mon;
    recElem->hour = selectedTime.hour;
    recElem->minute = selectedTime.minute;
    recElem->day = selectedTime.day;
    return 0;
}

int initRequest (TRequest* recElem, int d, int hh, int mm, int m, char* nz) {
    recElem->dt.mon = m;
    recElem->dt.hour = hh;
    recElem->dt.minute = mm;
    recElem->dt.day = d;
    strcpy(recElem->rz, nz);
    return 0;
}

int searchRecord (TRecord* arr, TRequest request, int size, char* m) {
    int buffSize = SIZE;
    TOutput *tempArr = (TOutput*)malloc(buffSize*sizeof(TOutput));
    
    int count = -1;
    
    for (int i = 0; i < size; i++) {
        if (strcmp(request.rz, arr[i].rz) == 0) {
            if (count == -1) {
                count++;
                initdt(&tempArr[count].dt, arr[i].dt);
                tempArr[count].amount = 1;
                tempArr[count].cams[0] = arr[i].nCam;
                continue;
            }
            if (compareDates(&arr[i].dt, &tempArr[count].dt) == 0) {
                tempArr[count].cams[tempArr[count].amount] = arr[i].nCam;
                tempArr[count].amount++;
            } else {
                count++;
                if (count == buffSize-1) {
                    extendTempArray(tempArr, &buffSize);
                }
                initdt(&tempArr[count].dt, arr[i].dt);
                tempArr[count].amount = 1;
                tempArr[count].cams[0] = arr[i].nCam;
            }
            
        }
    }
    if (count == -1) {
        printf("> Automobil nenalezen.\n");
        return 0;
    } else {
        for (int i = 0; i <= count; i++) {
            if (compareDates(&tempArr[i].dt, &request.dt) == 0) {
                printf("> Presne: %3s %d %02d:%02d, %dx [", m, request.dt.day, request.dt.hour, request.dt.minute, tempArr[i].amount);
                for (int j = 0; j< tempArr[i].amount; j++) {
                    printf(" %d", tempArr[i].cams[j]);
                }
                printf("]\n");
                return 0;
            
            }
            if (compareDates(&tempArr[i].dt, &request.dt) == 1) {
                if (i == 0) {
                    printf("> Predchazejici: N/A\n");
                } else {
                    i--;
                    convertMonth(tempArr[i].dt.mon, m);
                    printf("> Predchazejici: %3s %d %02d:%02d, %dx [", m, tempArr[i].dt.day, tempArr[i].dt.hour, tempArr[i].dt.minute, tempArr[i].amount);
                    for (int j = 0; j< tempArr[i].amount; j++) {
                        printf(" %d", tempArr[i].cams[j]);
                    }
                    i++;
                }

                    convertMonth(tempArr[i].dt.mon, m);
                    printf("> Pozdejsi: %3s %d %02d:%02d, %dx [", m, tempArr[i].dt.day, tempArr[i].dt.hour, tempArr[i].dt.minute, tempArr[i].amount);
                    for (int j = 0; j< tempArr[i].amount; j++) {
                        printf(" %d", tempArr[i].cams[j]);
                    }
                return 0;
            }
                
            if (i == count) {
                convertMonth(tempArr[i].dt.mon, m);
                printf("> Predchazejici: %3s %d %02d:%02d, %dx [", m, tempArr[i].dt.day, tempArr[i].dt.hour, tempArr[i].dt.minute, tempArr[i].amount);
                for (int j = 0; j< tempArr[i].amount; j++) {
                    printf(" %d", tempArr[i].cams[j]);
                }
                printf("> Pozdejsi: N/A\n");
                return 0;
            }
        }
    
    
    }
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
             borderControlFlag++;
         }
         if (strchr(str, '}') != NULL) {
             borderControlFlag++;
             res = parse(arr, &size, str, &count);
             if (res == 0) {
                 printf("Nespravny vstup.\n");
                 return 0;
             }
             break;
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
             borderControlFlag++;
         }
     }
     if (borderControlFlag == 1) {
         printf("Nespravny vstup.\n");
         return 0;
     }
     
     qsort(arr, count, sizeof(TRecord), compareRecords);
     printf("Hledani:\n");
     TRequest request;
     int d, hh, mm, month;
     
     char nz[1001];
     char m[4];
     while(getline(&str, &len , stdin) != -1) {
         if(sscanf(str, "  %1000s %3s %d %d : %d ", nz, m, &d, &hh, &mm) == 5){
                    if (checkInput(d, hh, mm, 0, &month, nz, m) == 1) {
                        initRequest(&request, d, hh, mm, month, nz);
                        searchRecord(arr, request, count, m);
                    } else {
                        printf("Nespravny vstup.\n");
                        return 0;
                    }
                } else {
                    printf("Nespravny vstup.\n");
                    return 0;
                }
     }
     
     
     free(str);
     free(arr);
     return 0;
 }
