//
//  main.c
//  Perfektní mocnina
//
//  Created by Евгений on 10/26/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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
    long long arr2[48036];
    int count = 0;
    for(long long i=0; i<= amount; i++) {
        if(binsrch(arr2, number[i], count) == 0) {
            arr2[count] = number[i];
            count++;
        }
    }
    memcpy(number, arr2, 48037);
}

long long countn1(long long a, long long b, long long pp[]) {
    long long count = 0;
    int b1=0, b2=0;
    for(int i = 0; i<= 48036; i++) {
        if(a<pp[i]) {b1=i;};
        if(pp[i]==a) {
            b1=i;
            
        };
        if(pp[i]>b) {b2=i;break;};
        if(pp[i]==b) {
            b2=i;break;
            
        }
    }
    
    return b2-b1;
}


long long countn(long long a, long long b, long long pp[]) {
    long long count = 0;

    for(long long k = a; k<=b; k++) {
        if(k==0){
            continue;
        }
        int first = 0;
        int last = 48036;
        int middle = (first+last)/2;
        while (first <= last) {
           if (pp[middle] < k)
              first = middle + 1;
           else if (pp[middle] == k) {
              count++;
              break;
           }
           else
              last = middle - 1;
           middle = (first + last)/2;
        }
    }
    return count;
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



int main(int argc, const char * argv[]) {
    long long a,b = -1;
    long long pp[48037];
    char c;
    int i;
    
    pp[0] = 1;
    int count = 1;
    long long n = INT_MAX;
    for (long long i = 2; i * i <= n; i++) {
        long long j = i * i;
        pp[count]=j;
        count++;
        while (j * i <= n) {
            pp[count]=j;
            count++;
            j = j * i;
        }
    }
    quicksort(pp, 0, 48036);
    uniquearray(pp, 48036);
    
    
    int result;
    printf("Intervaly:\n");
    while ((result = (scanf("%lld", &a))) != EOF) {
        b=-1;
        
        scanf("%c", &c);
        if(c == '\n') {
            printf("Nespravny vstup.\n");
            return 1;
        }
        scanf("%lld", &b);
        if (a>b || a<=0 || b<=0  ) {
            printf("Nespravny vstup.\n");
            return 1;
        }
        
        printf("<%lld;%lld> -> %lld\n", a,b, b-a+1 -countn1(a,b, pp));
    }
    return 0;
}
