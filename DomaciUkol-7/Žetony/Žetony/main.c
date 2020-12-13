#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Ret{
    int a;
    int b;
    char s[100];
} TRet;

int is_empty(const char *s) {
  while (*s != '\0') {
    if (!isspace((unsigned char)*s))
      return 0;
    s++;
  }
  return 1;
}

TRet cascade (int m[], int l, int r, int type, int priority) {
    TRet ret;
    ret.a = 0;
    ret.b = 0;
    strcpy(ret.s, "");

    if (priority == 0) {
        if (type == 1) {
            ret.a+=m[l];
            l++;
            strcat(ret.s, "1");
        } else if (type == 2) {
            ret.a+=m[r];
            r--;
            strcat(ret.s, "2");
        } else if (type == 3) {
            ret.a+=m[l];
            ret.a+=m[r];
            l++;
            r--;
            strcat(ret.s, "3");
        } else if (type == 4) {
            ret.a+=m[l];
            l++;
            ret.a+=m[l];
            l++;
            strcat(ret.s, "4");
        } else if (type == 5) {
            ret.a+=m[r];
            r--;
            ret.a+=m[r];
            r--;
            strcat(ret.s, "5");
        }
        if(r<l) {
            strcat(ret.s, "0");
            return ret;
        } else if (r == l) {
            ret.b+=m[r];
            strcat(ret.s, "1");
            strcat(ret.s, "0");
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
        strcat(ret.s, max.s);
        return ret;
    } else {
        if (type == 1) {
            ret.b+=m[l];
            l++;
            strcat(ret.s, "1");
        } else if (type == 2) {
            ret.b+=m[r];
            r--;
            strcat(ret.s, "2");
        } else if (type == 3) {
            ret.b+=m[l];
            ret.b+=m[r];
            l++;
            r--;
            strcat(ret.s, "3");
        } else if (type == 4) {
            ret.b+=m[l];
            l++;
            ret.b+=m[l];
            l++;
            strcat(ret.s, "4");
        } else if (type == 5) {
            ret.b+=m[r];
            r--;
            ret.b+=m[r];
            r--;
            strcat(ret.s, "5");
        }
        if(r<l) {
            strcat(ret.s, "0");
            return ret;
        } else if (r == l) {
            ret.a+=m[r];
            strcat(ret.s, "1");
            strcat(ret.s, "0");
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
        strcat(ret.s, max.s);
        return ret;
        
    }
}

int rec ( int l, int r ,int m[])
{
    if (l == r) {
        printf("A %d (%d)\n", r, m[r]);
        printf("A: %d, B: %d\n", m[r], 0);
        return 0;
    }
    TRet max = cascade(m, l, r, 1, 0);
    for (int i = 2; i<6; i++) {
        TRet res = cascade(m, l, r, i, 0);
        if ((res.a - res.b) > (max.a - max.b)) {
            max = res;
        }
    }
    for (int i = 0; i<100; i+=2) {
        if(max.s[i] == '1') {
            printf("A %d (%d)\n", l, m[l]);
            l++;
        } else if (max.s[i] == '2') {
            printf("A %d (%d)\n", r, m[r]);
            r--;
        } else if (max.s[i] == '3') {
            printf("A %d, %d (%d,%d)\n", r, l, m[r], m[l]);
            l++;
            r--;
        } else if (max.s[i] == '4') {
            printf("A %d, %d (%d,%d)\n", l, l+1, m[l], m[l+1]);
            l+=2;
        } else if (max.s[i] == '5') {
            printf("A %d, %d (%d,%d)\n", r, r-1, m[r], m[r-1]);
            r-=2;
        } else {
            break;
        }
        if(max.s[i+1] == '1') {
            printf("B %d (%d)\n", l, m[l]);
            l++;
        } else if (max.s[i+1] == '2') {
            printf("B %d (%d)\n", r, m[r]);
            r--;
        } else if (max.s[i+1] == '3') {
            printf("B %d, %d (%d,%d)\n", r, l, m[r], m[l]);
            l++;
            r--;
        } else if (max.s[i+1] == '4') {
            printf("B %d, %d (%d,%d)\n", l, l+1, m[l], m[l+1]);
            l+=2;
        } else if (max.s[i+1] == '5') {
            printf("B %d, %d (%d,%d)\n", r, r-1, m[r], m[r-1]);
            r-=2;
        } else {
            break;
        }
        
    }
    printf("A: %d, B: %d\n", max.a, max.b);
    
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
    if (is_empty(str) == 1) {
        printf("Nespravny vstup.\n");
        return 0;
    }
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
