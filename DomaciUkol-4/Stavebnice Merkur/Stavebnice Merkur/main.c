//
//  main.c
//  Stavebnice Merkur
//
//  Created by Евгений on 11/13/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(long long x, long long y, long long z) {
    if (
    x + y > z
    && x + z > y
        && z + y > x) {
        return 1;
    } else {
        return 0;
    }
    
}
int binsrch(long long pp[], long long cislo,  int am) {
    int first = 0;
    int last = am;
    int middle = (first+last)/2;
    while (first <= last) {
       if (pp[middle] < cislo)
          first = middle + 1;
       else if (pp[middle] == cislo) {
          return 1;
          break;
       }
       else
          last = middle - 1;
       middle = (first + last)/2;
    }
    return 0;
}
void uniquearray(long long number[], long long amount) {
    long long arr2[50000];
    int count = 0;
    for(long long i=0; i<= amount; i++) {
        if(binsrch(arr2, number[i], count) == 0) {
            arr2[count] = number[i];
            count++;
        }
    }
    memcpy(number, arr2, 50000);
}

void quicksort(long long number[],long long first,long long last){
   long long i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
      

   }
}


  

long long findNumberOfTriangles(long long arr[], long long am[], int n)
{
    
    long long count = 0;
    long long x,y,z;
  
    
    for (int i = 0; i < n; i++) {
        x = arr[i];
        if (am[i]>1) {
            for (int j = i; j < n ; j++) {
                  y = arr[j];
                  if (am[j]>1 && j != i) {
                      for (int k = j; k < n; k++) {
                            z = arr[k];
                          if (check(x, y, z) == 1) {
                              count++;
                          }
                        }
                  } else {
                      for (int k = j+1; k < n; k++) {
                            z = arr[k];
                            if (check(x, y, z) == 1) {
                                count++;
                            }
                        }
                  }
                      
            
              }
        } else {
            for (int j = i+1; j < n ; j++) {
                  y = arr[j];
                  if (am[j]>1 && j != i) {
                      for (int k = j; k < n; k++) {
                          z = arr[k];
                        if (check(x, y, z) == 1) {
                            count++;
                        }
                      }
                      
                  } else {
                      for (int k = j+1; k < n; k++) {
                          z = arr[k];
                          if (check(x, y, z) == 1) {
                              count++;
                          }
                      }
                  }
                      
            
              }
        }
            
  
    }
    for (int i = 0; i < n; i++) {
        if(am[i]>2) {
            count++;
        }
    }
  
    return count;
}

int main(int argc, const char * argv[]) {
    long long arr[10000];
    int nv=0;
    long long a;
    int ind = 0;
    char c;
    int result;
    printf("Delky nosniku:\n");
    while ((result = (scanf("%lld", &a))) != EOF) {
        if(scanf("%c", &c) == 1 && ((c != ' ' && c != '\n') || (c == '-'))) {
            nv=1;
            break;
        }
        
        if (a<=0) {
            nv=1;
        }
        arr[ind] = a;
        ind++;
        if(ind > 9999) {
            nv = 1;
            break;
        }
        c='\0';
    }
    arr[ind] = -1;
    if(ind<3) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    if (nv == 1) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    quicksort(arr, 0,ind-1);
    int amount = 0;
    long long amountofsec[10000];
    int count = 0;
    for (int i = 0; i<ind; i++) {
        amount++;
        if(arr[i+1] != arr[i]) {
            amountofsec[count] = amount;
            count++;
            amount=0;
        }
            
    }
    uniquearray(arr, 10000);
    printf("Trojuhelniku: %lld\n", findNumberOfTriangles(arr, amountofsec, count));
    
    return 0;
}
