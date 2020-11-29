#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

/*
   Tato struktura deklaruje formát data a času.
   Používá se jako pole v jiných strukturách.
*/
typedef struct DateTime{
    int mon;
    int day;
    int hour;
    int minute;
} TDateTime;

/*
   Tato struktura se používá k reprezentaci dat pro výstup.
*/
typedef struct Output {
    TDateTime dt;
    int amount;
    int cams[1000];
} TOutput;

/*
   Tato struktura se používá k ukládání dat o záznamech z kamer.
*/
typedef struct Record {
    char rz[1001];
    TDateTime dt;
    int nCam;
} TRecord;

/*
   Tato struktura se používá k reprezentaci dotazu k vyhledání záznamů.
*/
typedef struct Request {
    char rz[1001];
    TDateTime dt;
} TRequest;

/*
   Funkce slouží k rozšíření pole typu TRecord.
*/
int extendArray (TRecord ** rec, int* size) {
    *size *= 1.5;
    *rec = (TRecord*)realloc(*rec, *size*sizeof(TRecord));
    return 0;
}

/*
   Funkce slouží k rozšíření pole typu TOutput.
*/
int extendTempArray (TOutput ** rec, int* size) {
    *size *= 1.5;
    *rec = (TOutput*)realloc(*rec, *size*sizeof(TOutput));
    return 0;
}

/*
   Toto je komparator pro TRecord.
   Používá se pro třídění hlavního pole qsort-em.
*/
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

/*
   Toto je funkce pro převod číselné reprezentace měsíce na slovní.
   Používá se pouze pro výstup.
*/
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

    strcpy(month, months[m-1]);
    return 0;
}

/*
   Toto je komparator pro TDateTime.
   Používá se pouze pro vyhledávání.
*/
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


/*
   Funkce funguje jako konstruktor pro TRecord.
*/
int initRecord (TRecord* recElem, int d, int hh, int mm, int nc, int m, char* nz) {
    recElem->dt.mon = m;
    recElem->dt.hour = hh;
    recElem->dt.minute = mm;
    recElem->dt.day = d;
    recElem->nCam = nc;
    strcpy(recElem->rz, nz);
    return 0;
}
/*
   Funkce funguje jako konstruktor pro TDateTime.
*/
int initdt (TDateTime* recElem, TDateTime selectedTime) {
    recElem->mon = selectedTime.mon;
    recElem->hour = selectedTime.hour;
    recElem->minute = selectedTime.minute;
    recElem->day = selectedTime.day;
    return 0;
}

/*
   Funkce funguje jako konstruktor pro TRequest.
*/
int initRequest (TRequest* recElem, int d, int hh, int mm, int m, char* nz) {
    recElem->dt.mon = m;
    recElem->dt.hour = hh;
    recElem->dt.minute = mm;
    recElem->dt.day = d;
    strcpy(recElem->rz, nz);
    return 0;
}
/*
    Funkce vytvoři pole TOutput pro hledání.
    Toto pole obsahuje pouze záznamy s požadovaným vozem.
    Tato metoda značně usnadňuje samotné hledání.
 */
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
                    extendTempArray(&tempArr, &buffSize);
                }
                initdt(&tempArr[count].dt, arr[i].dt);
                tempArr[count].amount = 1;
                tempArr[count].cams[0] = arr[i].nCam;
            }
            
        }
    }
    if (count == -1) {
        printf("> Automobil nenalezen.\n");
        free(tempArr);
        return 0;
    } else {
        for (int i = 0; i <= count; i++) {
            if (compareDates(&tempArr[i].dt, &request.dt) == 0) {
                printf("> Presne: %3s %d %02d:%02d, %dx [", m, request.dt.day, request.dt.hour, request.dt.minute, tempArr[i].amount);
                for (int j = 0; j< tempArr[i].amount; j++) {
                    if (tempArr[i].amount == 1 || j == tempArr[i].amount-1) {
                        printf("%d", tempArr[i].cams[j]);
                        continue;
                    }
                    
                    printf("%d, ", tempArr[i].cams[j]);
                }
                printf("]\n");
                free(tempArr);
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
                        if (tempArr[i].amount == 1 || j == tempArr[i].amount-1) {
                            printf("%d", tempArr[i].cams[j]);
                            continue;
                        }
                        
                        printf("%d, ", tempArr[i].cams[j]);
                        
                    }
                    printf("]\n");
                    i++;
                }

                    convertMonth(tempArr[i].dt.mon, m);
                    printf("> Pozdejsi: %3s %d %02d:%02d, %dx [", m, tempArr[i].dt.day, tempArr[i].dt.hour, tempArr[i].dt.minute, tempArr[i].amount);
                    for (int j = 0; j< tempArr[i].amount; j++) {
                        if (tempArr[i].amount == 1 || j == tempArr[i].amount-1) {
                            printf("%d", tempArr[i].cams[j]);
                            continue;
                        }
                        
                        printf("%d, ", tempArr[i].cams[j]);
                    }
                printf("]\n");
                free(tempArr);
                return 0;
            }
                
            if (i == count) {
                convertMonth(tempArr[i].dt.mon, m);
                printf("> Predchazejici: %3s %d %02d:%02d, %dx [", m, tempArr[i].dt.day, tempArr[i].dt.hour, tempArr[i].dt.minute, tempArr[i].amount);
                for (int j = 0; j< tempArr[i].amount; j++) {
                    if (tempArr[i].amount == 1 || j == tempArr[i].amount-1) {
                        printf("%d", tempArr[i].cams[j]);
                        continue;
                    }
                    
                    printf("%d, ", tempArr[i].cams[j]);
                }
                printf("]\n");
                printf("> Pozdejsi: N/A\n");
                free(tempArr);
                return 0;
            }
        }
    
    
    }
    
    return 0;
}

/*
   Funkce kontroluje správnost zadaných údajů.
*/
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



int main ( void )
 {
     int borderControlFlag = 0;
     
     printf("Data z kamer:\n");
     int count = 0;
     int size = SIZE;
     char c;
     int bytes_now;
     TRequest request;
     TRecord *arr = NULL;
     arr = (TRecord*)malloc(size* sizeof(TRecord));
     scanf( " %c%n",  &c, & bytes_now);
     if (borderControlFlag == 0 && c == '{'){
         borderControlFlag++;
     }
     int d, hh, mm, nc, month;
      
     char nz[1001];
     char m[4];
     int res;
    
     while ((res = scanf(" %d : %1000s %3s %d %d : %d %c%n",  &nc, nz, m, &d, &hh, &mm, &c, & bytes_now)) ){
                if (res == -1) {
                    break;
                }
                if (checkInput(d, hh, mm, 0, &month, nz, m) == 1 && res == 7) {
                    initRecord(&arr[count], d, hh, mm, nc, month, nz);
                    ++count;
                    if (c == '}') {
                        borderControlFlag++;
                        if (borderControlFlag == 1) {
                            printf("Nespravny vstup.\n");
                            free(arr);
                            return 0;
                        }
                        qsort(arr, count, sizeof(TRecord), compareRecords);
                        printf("Hledani:\n");
                    
                        while ((res = scanf(" %1000s %3s %d %d : %d %n", nz, m, &d, &hh, &mm, & bytes_now) )){
                            if (res == -1) {
                                break;
                            }
                            if (checkInput(d, hh, mm, 0, &month, nz, m) == 1 && res == 5) {
                                   initRequest(&request, d, hh, mm, month, nz);
                                   searchRecord(arr, request, count, m);
                            } else {
                                   printf("Nespravny vstup.\n");
                                   free(arr);
                                   return 0;
                            }
                        
                        }
                        
                        break;
                    }
                    if (c != ',') break;
                    if (count == size-8) {
                        extendArray(&arr, &size);
                    }

                }
     }
 
     if (borderControlFlag != 2) {
         printf("Nespravny vstup.\n");
         free(arr);
         return 0;
     }
     
     free(arr);
     return 0;
 }
