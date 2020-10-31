//
//  main.c
//  Perfektní mocnina
//
//  Created by Евгений on 10/26/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


long long countn(long long a, long long b, long long pp[]) {
    int count = 0;

    for(long long k = a; k<=b; k++) {
        if(k==0){
            continue;
        }
        int first = 0;
        int last = 46381;
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
    long long pp[46382];
    pp[0] = 1;
    int count = 1;
    long long n = 2000000000;
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
    
    quicksort(pp, 0, 46381);
    int result;
    printf("Intervaly:\n");
    while ( (result = (scanf("%lld %lld", &a, &b))) != EOF  || (result = (scanf("%lld", &a))) != EOF) {
        
        if ((a>b && b!=-1) || a<0 || b<0  || result != 2 ) {
            printf("Nespravny vstup.\n");
            return 1;
        }
        
        printf("<%lld;%lld> -> %lld\n", a,b, b-a+1 -countn(a,b, pp));
    }
    return 0;
}
