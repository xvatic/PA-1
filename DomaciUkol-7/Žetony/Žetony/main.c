#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Ret{
    int a;
    int b;
    char* s;
} TRet;



TRet cascade (int m[], int l, int r, int type, int priority) {
    TRet ret;
    ret.a = 0;
    ret.b = 0;
    ret.s = "";

    if (priority == 0) {
        if (type == 1) {
            ret.a+=m[l];
            l++;
        } else if (type == 2) {
            ret.a+=m[r];
            r--;
        } else if (type == 3) {
            ret.a+=m[l];
            ret.a+=m[r];
            l++;
            r--;
        } else if (type == 4) {
            ret.a+=m[l];
            l++;
            ret.a+=m[l];
            l++;
        } else if (type == 5) {
            ret.a+=m[r];
            r--;
            ret.a+=m[r];
            r--;
        }
        if(r<l) {
            return ret;
        } else if (r == l) {
            ret.b+=m[r];
            return ret;
        }
        
        TRet max = cascade(m, l, r, 1, 1);
        for (int i = 2; i<6; i++) {
            TRet res = cascade(m, l, r, i, 1);
            if ((res.b - res.a) > (max.b - max.a)) {
                max = res;
            }
        }
        ret.a += max.a;
        ret.b += max.b;
        return ret;
    } else {
        if (type == 1) {
            ret.b+=m[l];
            l++;
        } else if (type == 2) {
            ret.b+=m[r];
            r--;
        } else if (type == 3) {
            ret.b+=m[l];
            ret.b+=m[r];
            l++;
            r--;
        } else if (type == 4) {
            ret.b+=m[l];
            l++;
            ret.b+=m[l];
            l++;
        } else if (type == 5) {
            ret.b+=m[r];
            r--;
            ret.b+=m[r];
            r--;
        }
        if(r<l) {
            return ret;
        } else if (r == l) {
            ret.a+=m[r];
            return ret;
        }
        TRet max = cascade(m, l, r, 1, 0);
        for (int i = 2; i<6; i++) {
            TRet res = cascade(m, l, r, i, 0);
            if ((res.a - res.b) > (max.a - max.b)) {
                max = res;
            }
        }
        ret.a += max.a;
        ret.b += max.b;
        return ret;
        
    }
}

int rec ( int l, int r ,int m[])
{
    TRet r1 = cascade(m, l, r, 1, 0);
    TRet r2 = cascade(m, l, r, 2, 0);
    TRet r3 = cascade(m, l, r, 3, 0);
    TRet r4 = cascade(m, l, r, 4, 0);
    TRet r5 = cascade(m, l, r, 5, 0);
    return 0;
}

int digits_only(const char *s)
{
    while (*s) {
        if (isdigit(*s) == 0 && (*s != '-')) return 0;
        s++;
    }

    return 1;
}

int main ( void )
{
    int m[100];
    int count = 0;
    printf("Zetony:\n");
    char* str = NULL;
    size_t len= 0;
    char* piece = NULL;
    getline(&str, &len, stdin);
    piece = strtok(str, " \t\n\r");
    if (digits_only(piece) == 1) {
        m[count] = atoi(piece);
        count++;
    } else {
        printf("Nespravny vstup.\n");
        return 0;
    }
    while((piece = strtok(NULL, " \t\n\r")) != NULL) {
        if (digits_only(piece) == 1) {
            if (count == 100) {
                printf("Nespravny vstup.\n");
                return 0;
            }
            m[count] = atoi(piece);
            count++;
        } else {
            printf("Nespravny vstup.\n");
            return 0;
        }
    }
    
    rec(0, count-1, m);
    return 0;
}
