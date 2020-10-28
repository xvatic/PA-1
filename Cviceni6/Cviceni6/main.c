//
//  main.c
//  Cviceni6
//
//  Created by Евгений on 10/28/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int dateToIndex(int day, int month, int year, int *idx) {
    int vys=0;
    if (day<1 || day>31 || month<1 || month>12 || year<2000) {
        return 0;
    }
    
    if(year % 4 != 0) {
        if(month == 2 && day == 29) {
            return 0;
        }
        
    } else {
        if (year % 100 == 0 && year % 400 != 0){
            if(month == 2 && day == 29) {
                return 0;
            }
            
        }
        else if(year % 4000 ==0) {
            if(month == 2 && day > 28) {
                return 0;
            }
        } else {
            vys=1;
        }
        
        
    }
    switch (month) {
        case 1:
            if(day >31) {return 0;}
            break;
        case 2:
            if(vys == 0 && day > 28) {return 0;}
            if(vys == 1 && day > 29) {return 0;}
            day+=31;
            break;
        case 3:
            if(day >31) {return 0;}
            day+=59;
            break;
        case 4:
            if(day >30) {return 0;}
            day+=90;
            break;
        case 5:
            if(day >31) {return 0;}
            day+=120;
            break;
        case 6:
            if(day >30) {return 0;}
            day+=151;
            break;
        case 7:
            if(day >31) {return 0;}
            day+=181;
            break;
        case 8:
            if(day >31) {return 0;}
            day+=212;
            break;
        case 9:
            if(day >30) {return 0;}
            day+=243;
            break;
        case 10:
            if(day >31) {return 0;}
            day+=273;
            break;
        case 11:
            if(day >30) {return 0;}
            day+=304;
            break;
        case 12:
            if(day >31) {return 0;}
            day+=334;
            break;
        default:
            break;
            
    }
    if (vys == 1 && month>2) {
        day+=1;
    }
    *idx=day;
    
    return 1;
}

#ifndef __PROGTEST__
int main (int argc, char * argv []) {
    int idx;

    assert(dateToIndex( 1,  1, 2000, &idx) == 1 && idx == 1);
    assert(dateToIndex( 1,  2, 2000, &idx) == 1 && idx == 32);
    assert(dateToIndex(29,  2, 2000, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 2001, &idx) == 0);
    assert(dateToIndex( 1, 12, 2000, &idx) == 1 && idx == 336);
    assert(dateToIndex(31, 12, 2000, &idx) == 1 && idx == 366);
    assert(dateToIndex( 1,  1, 1999, &idx) == 0);
    assert(dateToIndex( 6,  7, 3600, &idx) == 1 && idx == 188);
    assert(dateToIndex(29,  2, 3600, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 4000, &idx) == 0);
    return 0;
}
#endif /* __PROGTEST__ */


