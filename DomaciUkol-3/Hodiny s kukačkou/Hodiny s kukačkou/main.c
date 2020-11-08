//
//  main.c
//  Hodiny s kukačkou
//
//  Created by Евгений on 11/3/20.
//  Copyright © 2020 Евгений. All rights reserved.
//



#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>

#endif /* __PROGTEST__ */
int ifV(long long y) {
    if(y % 4 != 0) {
        return 0;
        
    } else {
        if (y % 100 == 0 && y % 400 != 0){
           return 0;
        }
        else if(y % 4000 ==0) {
            return 0;
        } else {
            return 1;
        }
    }
}

int checkInput(int y, int m, int d, int h, int i) {
    int isV = 0;
    if (y<1600 || m < 1 || m > 12 || h < 0 || h > 23 || i < 0 || i > 59 || d<1) {
        return 0;
    }
    if(y % 4 != 0) {
        if(m == 2 && d == 29) {
            return 0;
        }
        
    } else {
        if (y % 100 == 0 && y % 400 != 0){
            if(m == 2 && d == 29) {
                return 0;
            }
            
        }
        else if(y % 4000 ==0) {
            if(m == 2 && d > 28) {
                return 0;
            }
        } else {
            isV=1;
        }
    }
    switch (m) {
    case 1:
        if(d >31) {return 0;}
        break;
    case 2:
        if(isV == 0 && d > 28) {return 0;}
        if(isV == 1 && d > 29) {return 0;}
        break;
    case 3:
        if(d >31) {return 0;}
        break;
    case 4:
        if(d >30) {return 0;}
        break;
    case 5:
        if(d >31) {return 0;}
        break;
    case 6:
        if(d >30) {return 0;}
        break;
    case 7:
        if(d >31) {return 0;}
        break;
    case 8:
        if(d >31) {return 0;}
        break;
    case 9:
        if(d >30) {return 0;}
        break;
    case 10:
        if(d >31) {return 0;}
        break;
    case 11:
        if(d >30) {return 0;}
        break;
    case 12:
        if(d >31) {return 0;}
        break;
    default:
        break;
    }

    return 1;
}

long long count1 (int y, int m1, int m2, int d1, int d2, int h1, int h2, int i1, int i2) {
    int mam[12] = {31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
    if(ifV(y)==1) {mam[1]=29;};
    long long count = 0;
    if(m1 == m2) {
        if (d1 == d2) {
            for (int i = h2; i>h1; i--) {
                if(i>12) {
                    count+=i-12;
                } else {
                    count+=i;
                }
            }
            count+=h2-h1;
            if (i2>=30) {count++;};
            if (i1>30) {count--;};
            if (i1 == 0) {
                if(h1>12) {
                    count+=h1-12;
                } else if(h1==0) {
                    count+=12;
                }else {
                    count+=h1;
                }
            }
            return count;
            
        } else {
            for (int i = h2; i>0; i--) {
                if(i>12) {
                    count+=i-12;
                } else {
                    count+=i;
                }
            }
            count+=h2-0+12;
            if (i2>=30) {count++;};
            for (int i = h1; i<24; i++){
                if(i>12) {
                    count+=i-12;
                } else if(i==0) {
                    count+=12;
                }else {
                    count+=i;
                }
            }
            count+=24-h1;
            if(i1>1) {
                if(h1>12) {
                    count-=h1-12;
                } else if(h1==0) {
                    count-=12;
                }else {
                    count-=h1;
                }
            }
            if (i1>=30) {
                count--;
            }
            count+=((d2-d1-1)*180);
            return count;
        }
    } else {
        for (int i = h2; i>0; i--) {
            if(i>12) {
                count+=i-12;
            } else {
                count+=i;
            }
        }
        count+=h2-0+12;
        if (i2>=30) {count++;};
        for (int i = h1; i<24; i++){
            if(i>12) {
                count+=i-12;
            } else if(i==0) {
                count+=12;
            }else {
                count+=i;
            }
        }
        count+=24-h1;
        if(i1>1) {
            if(h1>12) {
                count-=h1-12;
            } else if(h1==0) {
                count-=12;
            }else {
                count-=h1;
            }
        }
        if (i1>=30) {
            count--;
        }
        count+=((d2-1)+(mam[m1-1]-d1))*180;
        for(int i = m1+1; i<m2; i++) {
            count+=mam[i-1]*180;
        }
        return count;
    }
}

long long count2(long long y1, long long y2, int m1, int m2, int d1, int d2, int h1, int h2, int i1, int i2, int dif) {
    int mam[12] = {31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
    if(ifV(y1)==1) {mam[1]=29;};
    long long count = 0;
    for (int i = h2; i>0; i--) {
        if(i>12) {
            count+=i-12;
        } else {
            count+=i;
        }
    }
    count+=h2-0+12;
    if (i2>=30) {count++;};
    for (int i = h1; i<24; i++){
        if(i>12) {
            count+=i-12;
        } else if(i==0) {
            count+=12;
        }else {
            count+=i;
        }
    }
    count+=24-h1;
    if(i1>1) {
        if(h1>12) {
            count-=h1-12;
        } else if(h1==0) {
            count-=12;
        }else {
            count-=h1;
        }
    }
    if (i1>=30) {
        count--;
    }
    count+=((d2-1)+(mam[m1-1]-d1))*180;
    for(int i = m1+1; i<13; i++) {
        count+=mam[i-1]*180;
    }
    if(ifV(y2)==1) {
        mam[1]=29;
    } else {
        mam[1]=28;
    }
    for(int i = 1; i<m2; i++) {
        count+=mam[i-1]*180;
    }
    
    
    if(dif == 1){
        long long vys = floor((y2-1)/4)-floor((y2-1)/100)+floor((y2-1)/400)-floor((y2-1)/4000)-(floor((y1)/4)-floor((y1)/100)+floor((y1)/400)-floor((y1)/4000));
        
        
        count+=((y2-y1-1-vys)*365+vys*366)*180;
    }
    
    return count;
}

int cuckooClock ( int y1, int m1, int d1, int h1, int i1,
                  int y2, int m2, int d2, int h2, int i2, long long int * cuckoo )
{
    if (checkInput(y1, m1, d1, h1, i1) == 0 || checkInput(y1, m2, d2, h2, i2) == 0 || y1>y2 || (y1 == y2 && m1>m2) || (y1 == y2 && m1==m2 && d1>d2) || (y1 == y2 && m1==m2 && d1==d2 && h1>h2) || (y1 == y2 && m1==m2 && d1==d2 && h1==h2 && i1>i2)) {
        return 0;
    }
    if(y2-y1 == 0) {
        *cuckoo=count1(y1, m1, m2, d1, d2, h1, h2, i1, i2);
        return 1;
    } else if (y2-y1 == 1) {
        *cuckoo=count2(y1,y2, m1, m2, d1, d2, h1, h2, i1, i2,0);
        return 1;
    } else {
        *cuckoo=count2(y1,y2, m1, m2, d1, d2, h1, h2, i1, i2,1);
        return 1;
    }
    
 
    return 0;
    
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  long long int cuckoo;
    assert(cuckooClock(2007, 9, 5, 23, 30, 2007, 9, 5, 23, 45, &cuckoo) == 1 && cuckoo == 1);
    assert(cuckooClock(2034, 7, 1, 23, 0, 2034, 7, 1, 23, 45, &cuckoo) == 1 && cuckoo == 12);
    assert(cuckooClock(2074, 3, 26, 2, 0, 2074, 3, 26, 2, 30, &cuckoo) == 1 && cuckoo == 3);
    assert(cuckooClock(1852, 1, -9, 0, 0, 2400, 1, 1, 0, 0, &cuckoo) == 0);
    assert(cuckooClock(2020, 10, 1, 13, 15, 2020, 10, 1, 18, 45, &cuckoo) == 1 && cuckoo == 26);
    assert(cuckooClock(2020, 10, 1, 13, 15, 2020, 10, 2, 11, 20, &cuckoo) == 1 && cuckoo == 165);
    assert(cuckooClock(2020, 1, 1, 13, 15, 2020, 10, 5, 11, 20, &cuckoo) == 1 && cuckoo == 50025);
    assert(cuckooClock(2019, 1, 1, 13, 15, 2019, 10, 5, 11, 20, &cuckoo) == 1 && cuckoo == 49845);
    assert(cuckooClock(1900, 1, 1, 13, 15, 1900, 10, 5, 11, 20, &cuckoo) == 1 && cuckoo == 49845);
    assert(cuckooClock(2020, 10, 1, 0, 0, 2020, 10, 1, 12, 0, &cuckoo) == 1 && cuckoo == 102);
    assert(cuckooClock(2020, 10, 1, 0, 15, 2020, 10, 1, 0, 25, &cuckoo) == 1 && cuckoo == 0);
    assert(cuckooClock(2020, 10, 1, 12, 0, 2020, 10, 1, 12, 0, &cuckoo) == 1 && cuckoo == 12);
    assert(cuckooClock(2020, 11, 1, 12, 0, 2020, 10, 1, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2020, 10, 32, 12, 0, 2020, 11, 10, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2100, 2, 29, 12, 0, 2100, 2, 29, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2400, 2, 29, 12, 0, 2400, 2, 29, 12, 0, &cuckoo) == 1 && cuckoo == 12);
    assert(cuckooClock(2100, 11, 30, 0, 0, 2100, 12, 29, 0, 0, &cuckoo) == 1 && cuckoo == 5232);
    assert(cuckooClock(2100, 12, 11, 0, 0, 2100, 12, 31, 0, 0, &cuckoo) == 1 && cuckoo == 3612);
    assert(cuckooClock(2020, 10, 32, 12, 0, 2020, 11, 10, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2181, 5, 18, 9, 34, 2062080312, 7, 22, 21, 16, &cuckoo) == 1 && cuckoo == 135568450135169);
    assert(cuckooClock(1924, 12, 21, 1, 2, 115041459, 8, 17, 21, 30, &cuckoo) == 1 && cuckoo == 7563113725823);
    assert(cuckooClock(1965, 7, 18, 23, 11, 1588631495, 2, 10, 8, 53, &cuckoo) == 1 && cuckoo == 104442232283158);
    assert(cuckooClock(1711, 10, 25, 0, 23, 457691589, 5, 2, 7, 47, &cuckoo) == 1 && cuckoo == 30090182520276);
    assert(cuckooClock(1792, 4, 31, 13, 27, 355871257, 9, 30, 18, 32, &cuckoo) == 0 && cuckoo == 30090182520276);
    assert(cuckooClock(1988, 9, 12, 23, 18, 741828622, 11, 29, 5, 44, &cuckoo) == 1 && cuckoo == 48770357217874);
    assert(cuckooClock(1664, 3, 17, 0, 49, 1294704329, 3, 20, 23, 26, &cuckoo) == 1 && cuckoo == 85118420600626);
    assert(cuckooClock(2045, 9, 4, 22, 30, 2045, 9, 4, 23, 30, &cuckoo) == 1 && cuckoo == 13);
    assert ( cuckooClock ( 1906, 3, 18, 13, 55,
    2177, 2, 19, 22, 54, &cuckoo ) == 1 && cuckoo == 17811963);
     
    assert ( cuckooClock ( 2000, 1, 1, 0, -9, 2000, 1, 2, 23, 59, &cuckoo ) == 0);

    assert ( cuckooClock ( 2045, 9, 4, 22, 30, 2045, 9, 4, 23, 30, &cuckoo ) == 1 && cuckoo == 13);
     
    assert(cuckooClock( 2100, 11, 30, 0, 0, 2100, 12, 9, 0, 0, &cuckoo) == 1 && cuckoo == 1632);

    assert ( cuckooClock ( 1908, 7, 30, 0, 43, 2027168706, 10, 6, 20, 45, &cuckoo ) == 1 && cuckoo == 133273253249054);

    assert (cuckooClock ( 2049, 5, 8, 23, 15, 2049, 5, 8, 23, 30, &cuckoo ) == 1 && cuckoo == 1);

    assert ( cuckooClock ( 1970, 6, 9, 8, 32,2091, 4, 5, 4, 54, &cuckoo ) == 1 && cuckoo == 7943370 );

    

    assert ( cuckooClock ( 1915, 1, 23, 15, 42, 2105, 11, 9, 5, 3, &cuckoo ) == 1 && cuckoo == 12543580 );

    assert (cuckooClock ( 2027, 5, 8, 23, 0, 2027, 5, 8, 23, 45, &cuckoo ) == 1 && cuckoo == 12);

    assert (cuckooClock ( 2084, 7, 11, 0, 0, 2084, 7, 11, 0, 0, &cuckoo ) == 1 && cuckoo == 12);

    assert ( cuckooClock ( 1942, 1, 21, 0, 46, 2135, 2, 7, 1, 20, &cuckoo ) == 1 && cuckoo == 12691621 );

    assert ( cuckooClock ( 1824, 1, 1, 0, 0, 1824, 1, 6, 0, 0, &cuckoo ) == 1 && cuckoo == 912 );
    assert ( cuckooClock ( 2013, 10,  1, 13, 15,
                           2013, 10,  1, 18, 45, &cuckoo ) == 1 && cuckoo == 26 );
    assert ( cuckooClock ( 2013, 10,  1, 13, 15,
                           2013, 10,  2, 11, 20, &cuckoo ) == 1 && cuckoo == 165 );
    assert ( cuckooClock ( 2013,  1,  1, 13, 15,
                           2013, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
    assert ( cuckooClock ( 2012,  1,  1, 13, 15,
                           2012, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 50025 );
    assert ( cuckooClock ( 1900,  1,  1, 13, 15,
                           1900, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
    assert ( cuckooClock ( 2013, 10,  1,  0,  0,
                           2013, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 102 );
    assert ( cuckooClock ( 2013, 10,  1,  0, 15,
                           2013, 10,  1,  0, 25, &cuckoo ) == 1 && cuckoo == 0 );
    assert ( cuckooClock ( 2013, 10,  1, 12,  0,
                           2013, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock ( 2013, 11,  1, 12,  0,
                           2013, 10,  1, 12,  0, &cuckoo ) == 0 );
    assert ( cuckooClock ( 2013, 10, 32, 12,  0,
                           2013, 11, 10, 12,  0, &cuckoo ) == 0 );
    assert ( cuckooClock ( 2100,  2, 29, 12,  0,
                           2100,  2, 29, 12,  0, &cuckoo ) == 0 );
    assert ( cuckooClock ( 2400,  2, 29, 12,  0,
                           2400,  2, 29, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock ( 1828, 2, 1, 0, 0,
                           1828, 2, 1, 0, 0, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock ( 1888, 8, 1, 0, 0,
                           1888, 8, 1, 0, 0, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock ( 1942, 1, 21, 0, 46,
                          2135, 2, 7, 1, 20, &cuckoo ) == 1 && cuckoo == 12691621 );
    assert ( cuckooClock ( 1599, 1, 21, 0, 46,
                          2135, 2, 7, 1, 20, &cuckoo ) == 0 );
    assert ( cuckooClock ( 1600, 1, 21, 0, 0,
                          1600, 3, 1, 0, 0, &cuckoo ) == 1 && cuckoo == 7212 );
    assert ( cuckooClock ( 2001, 1, 21, 0, 0,
                          2001, 1, 21, 0, 7, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock ( 2055, 4, 22, 0, 0,
                          2055, 4, 22, 1, 0, &cuckoo ) == 1 && cuckoo == 14 );
    assert ( cuckooClock ( 2000, 2, 29, 0, 0,
                          2000, 12, 19, 0, 0, &cuckoo ) == 1 && cuckoo == 52932 );
    assert ( cuckooClock ( 2020, 11, 1, 12, 0,
                          2020, 10, 1, 12, 0, &cuckoo ) == 0 );
    assert ( cuckooClock ( 2003, 2, 1, 22, 45,
                          2003, 2, 1, 23, 15, &cuckoo ) == 1 && cuckoo == 11 );
    assert ( cuckooClock ( 12345, 2, 29, 0, 0,
                          12345, 3, 21, 0, 7, &cuckoo ) == 0 );
    assert ( cuckooClock ( 2100, 12, 25, 0, 0,
                         2100, 12, 30, 0, 0, &cuckoo ) == 1 && cuckoo == 912 );
    assert ( cuckooClock ( 2100, 12, 25, 12, 15,
                         2100, 12, 26, 11, 45, &cuckoo ) == 1 && cuckoo == 168 );
    assert ( cuckooClock( 2089, 3, 25, 0, 0,
                         2089, 3, 25, 0, 0, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock( 2081, 4, 27, 0, 30,
                         2081, 4, 27, 1, 30, &cuckoo ) == 1 && cuckoo == 3 );
    assert ( cuckooClock ( 2027, 5, 8, 23, 0,
                         2027, 5, 8, 23, 45, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock ( 2084, 7, 11, 0, 0,
                         2084, 7, 11, 0, 0, &cuckoo ) == 1 && cuckoo == 12 );
    assert ( cuckooClock ( 2044, 2, 9, 0, 30,
                         2044, 2, 9, 1, 15, &cuckoo ) == 1 && cuckoo == 2 );
    assert ( cuckooClock ( 2048, 7, 19, 15, 45,
                         2030193556, 6, 22, 13, 48, &cuckoo ) == 1 && cuckoo == 133472108571293 );
    assert(cuckooClock(2007, 9, 5, 23, 30, 2007, 9, 5, 23, 45, &cuckoo) == 1 && cuckoo == 1);
    assert(cuckooClock(2034, 7, 1, 23, 0, 2034, 7, 1, 23, 45, &cuckoo) == 1 && cuckoo == 12);
    assert(cuckooClock(2074, 3, 26, 2, 0, 2074, 3, 26, 2, 30, &cuckoo) == 1 && cuckoo == 3);
    assert(cuckooClock(1852, 1, -9, 0, 0, 2400, 1, 1, 0, 0, &cuckoo) == 0);
    assert(cuckooClock(2020, 10, 1, 13, 15, 2020, 10, 1, 18, 45, &cuckoo) == 1 && cuckoo == 26);
    assert(cuckooClock(2020, 10, 1, 13, 15, 2020, 10, 2, 11, 20, &cuckoo) == 1 && cuckoo == 165);
    assert(cuckooClock(2020, 1, 1, 13, 15, 2020, 10, 5, 11, 20, &cuckoo) == 1 && cuckoo == 50025);
    assert(cuckooClock(2019, 1, 1, 13, 15, 2019, 10, 5, 11, 20, &cuckoo) == 1 && cuckoo == 49845);
    assert(cuckooClock(1900, 1, 1, 13, 15, 1900, 10, 5, 11, 20, &cuckoo) == 1 && cuckoo == 49845);
    assert(cuckooClock(2020, 10, 1, 0, 0, 2020, 10, 1, 12, 0, &cuckoo) == 1 && cuckoo == 102);
    assert(cuckooClock(2020, 10, 1, 0, 15, 2020, 10, 1, 0, 25, &cuckoo) == 1 && cuckoo == 0);
    assert(cuckooClock(2020, 10, 1, 12, 0, 2020, 10, 1, 12, 0, &cuckoo) == 1 && cuckoo == 12);
    assert(cuckooClock(2020, 11, 1, 12, 0, 2020, 10, 1, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2020, 10, 32, 12, 0, 2020, 11, 10, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2100, 2, 29, 12, 0, 2100, 2, 29, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2400, 2, 29, 12, 0, 2400, 2, 29, 12, 0, &cuckoo) == 1 && cuckoo == 12);
    assert(cuckooClock(2100, 11, 30, 0, 0, 2100, 12, 29, 0, 0, &cuckoo) == 1 && cuckoo == 5232);
    assert(cuckooClock(2100, 12, 11, 0, 0, 2100, 12, 31, 0, 0, &cuckoo) == 1 && cuckoo == 3612);
    assert(cuckooClock(2020, 10, 32, 12, 0, 2020, 11, 10, 12, 0, &cuckoo) == 0);
    assert(cuckooClock(2181, 5, 18, 9, 34, 2062080312, 7, 22, 21, 16, &cuckoo) == 1 && cuckoo == 135568450135169);
    assert(cuckooClock(2062080312, 7, 22, 21, 16, 2062080312, 7, 22, 21, 16, &cuckoo) == 1 && cuckoo == 0);
    assert(cuckooClock(1924, 12, 21, 1, 2, 115041459, 8, 17, 21, 30, &cuckoo) == 1 && cuckoo == 7563113725823);
    assert(cuckooClock(1965, 7, 18, 23, 11, 1588631495, 2, 10, 8, 53, &cuckoo) == 1 && cuckoo == 104442232283158);
    assert(cuckooClock(1711, 10, 25, 0, 23, 457691589, 5, 2, 7, 47, &cuckoo) == 1 && cuckoo == 30090182520276);
    assert(cuckooClock(1792, 4, 31, 13, 27, 355871257, 9, 30, 18, 32, &cuckoo) == 0 && cuckoo == 30090182520276);
    assert(cuckooClock(1988, 9, 12, 23, 18, 741828622, 11, 29, 5, 44, &cuckoo) == 1 && cuckoo == 48770357217874);
    assert(cuckooClock(1664, 3, 17, 0, 49, 1294704329, 3, 20, 23, 26, &cuckoo) == 1 && cuckoo == 85118420600626);
    assert(cuckooClock(2045, 9, 4, 22, 30, 2045, 9, 4, 23, 30, &cuckoo) == 1 && cuckoo == 13);
    assert ( cuckooClock ( 2044, 2, 8, 23, 00, 2044, 2, 8, 23, 15, &cuckoo ) == 1 && cuckoo == 11 );
 assert ( cuckooClock ( 1828, 2, 1, 0, 0, 1828, 2, 1, 0, 0, &cuckoo ) == 1 && cuckoo == 12 );
 assert ( cuckooClock ( 2078, 8, 5, 23, 30, 2078, 8, 5, 23, 45, &cuckoo ) == 1 && cuckoo == 1 );
  assert ( cuckooClock ( 2066, 6, 4, 0, 15, 2066, 6, 4, 0, 0, &cuckoo ) == 0);
  assert ( cuckooClock ( 1900,  1,  1, 13, 15,
                         1900, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
  assert ( cuckooClock ( 2020, 10,  1,  0,  0,
                         2020, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 102 );
  assert ( cuckooClock ( 2020, 10,  1,  0, 15,
                         2020, 10,  1,  0, 25, &cuckoo ) == 1 && cuckoo == 0 );
  assert ( cuckooClock ( 2020, 10,  1, 12,  0,
                         2020, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );
  assert ( cuckooClock ( 2020, 11,  1, 12,  0,
                         2020, 10,  1, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2020, 10, 32, 12,  0,
                         2020, 11, 10, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2100,  2, 29, 12,  0,
                         2100,  2, 29, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2400,  2, 29, 12,  0,
                         2400,  2, 29, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );

  
  return 0;
}
#endif /* __PROGTEST__ */

