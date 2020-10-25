//
//  main.c
//  Dvě kružnice
//
//  Created by Евгений on 10/17/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

typedef struct Kruznice {
    double x;
    double y;
    double r;
} TKruznice;

void InitKruznice (TKruznice* kruznice, double x, double y, double r) {
    kruznice->x = x;
    kruznice->y = y;
    kruznice->r = r;
}

int main(int argc, const char * argv[]) {
    TKruznice k1,k2;
    double x, y, r;
    long double d,   f1, f2;
    

    printf("Zadejte parametry kruznice #1:\n");
    if (scanf("%lf %lf %lf", &x, &y, &r) != 3 || r <= 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    InitKruznice(&k1, x, y, r);
    printf("Zadejte parametry kruznice #2:\n");
    if (scanf("%lg %lg %lg", &x, &y, &r) != 3 || r <= 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    InitKruznice(&k2, x, y, r);
    
    
    d = sqrt( pow( k1.x - k2.x, 2 ) + pow( k1.y - k2.y, 2 ));
    
    
    f1 = 2 * acos((pow(k1.r, 2) - pow(k2.r, 2) + pow(d, 2) )/(2*k1.r*d));
    f2 = 2 * acos((pow(k2.r, 2) - pow(k1.r, 2) + pow(d, 2) )/(2*k2.r*d));
    if (k1.x == k2.x && k1.y == k2.y && k1.r == k2.r) {
           long double s = M_PI * pow(k2.r, 2);
        printf("Kruznice splyvaji, prekryv: %.6Lf\n", s);
           return 0;
    }
    
   
    
    if (d < fabs(k1.r-k2.r) || fabsl (d-k1.r+k2.r) < 1000 * DBL_EPSILON * fabs (k1.r-k2.r) || fabsl (d+k1.r-k2.r) < 1000 * DBL_EPSILON * fabs (k1.r-k2.r)) {
        if (k1.r > k2.r) {
            long double s = M_PI * pow(k2.r, 2);
            if (fabsl (d-k1.r+k2.r) < 1000 * DBL_EPSILON * fabs (k1.r-k2.r)) {
                printf("Vnitrni dotyk, kruznice #2 lezi uvnitr kruznice #1, prekryv: %.6Lf\n", s);
                return 0;
            }
            printf("Kruznice #2 lezi uvnitr kruznice #1, prekryv: %.6Lf\n", s);
            return 0;
        } else {
            long double s = M_PI * pow(k1.r, 2);
            
            if (fabsl (d+k1.r-k2.r) < 1000 * DBL_EPSILON * fabs (k1.r-k2.r)) {
                printf("Vnitrni dotyk, kruznice #1 lezi uvnitr kruznice #2, prekryv: %.6Lf\n", s);
                return 0;
            }
            printf("Kruznice #1 lezi uvnitr kruznice #2, prekryv: %.6Lf\n", s);
            return 0;
        }
    }
    if (fabsl (d-(k1.r+k2.r)) < 1000 * DBL_EPSILON * fabs (k1.r+k2.r)) {
        printf("Vnejsi dotyk, zadny prekryv.\n");
        return 0;
    }
    if (d > k1.r+k2.r) {
        printf("Kruznice lezi vne sebe, zadny prekryv.\n");
        return 0;
    }
   
    

    long double s2 = (pow(k1.r, 2) * (f1 - sin(f1)))/2 + (pow(k2.r, 2) * (f2 - sin(f2)))/2 ;
    printf("Kruznice se protinaji, prekryv: %.6Lf\n", s2);
    
    return 0;
}
