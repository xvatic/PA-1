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
int ifV(int y) {
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
    if (y<1600 || m < 1 || m > 12 || h < 0 || h > 23 || i < 0 || i > 59) {
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
            if (i1>=30) {count--;};
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
        count+=((d2-1)+(mam[m1]-d1))*180;
        for(int i = m1+1; i<m2; i++) {
            count+=mam[i-1]*180;
        }
        return count;
    }
}

int cuckooClock ( int y1, int m1, int d1, int h1, int i1,
                  int y2, int m2, int d2, int h2, int i2, long long int * cuckoo )
{
    if (checkInput(y1, m1, d1, h1, i1) == 0 || checkInput(y1, m2, d2, h2, i2) == 0 || y1>y2 || (y1 == y2 && m1>m2) ) {
        return 0;
    }
    if(y2-y1 == 0) {
        *cuckoo=count1(y1, m1, m2, d1, d2, h1, h2, i1, i2);
        return 1;
    } else if (y2-y1 == 1) {
        
    } else {
        
    }
    
 
    return 0;
    
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  long long int cuckoo;
  
  assert ( cuckooClock ( 2020, 10,  1, 13, 15,
                         2020, 10,  1, 18, 45, &cuckoo ) == 1 && cuckoo == 26 );
  assert ( cuckooClock ( 2020, 10,  1, 13, 15,
                         2020, 10,  2, 11, 20, &cuckoo ) == 1 && cuckoo == 165 );
  assert ( cuckooClock ( 2020,  1,  1, 13, 15,
                         2020, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 50025 );
  assert ( cuckooClock ( 2019,  1,  1, 13, 15,
                         2019, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
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

