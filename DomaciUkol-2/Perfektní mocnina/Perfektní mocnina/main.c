//
//  main.c
//  Perfektní mocnina
//
//  Created by Евгений on 10/26/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>

long long countn(long long a, long long b, long long pp[]) {
    int count = 0;

    for(long long k = a; k<=b; k++) {
        if(k==0){
            continue;
        }
        int first = 4;
        int last = 33000;
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

void swap(long long* xp, long long* yp)
{
    long long temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// Function to perform Selection Sort
void selectionSort(long long arr[], long long n)
{
    long long i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
  
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
  
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(int argc, const char * argv[]) {
    long long a,b;
    long long pp[33000-13];
    int count = 0;
    long long n = 1000000000;
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
    long long np = sizeof(pp) / sizeof(pp[0]);
    selectionSort(pp, np);
    
    printf("Intervaly:\n");
    while (scanf("%lld %lld", &a, &b) ) {
        if (a>b || a<0 || b<0) {
            printf("Nespravny vstup.\n");
            return 1;
        }
        printf("<%lld;%lld> -> %lld\n", a,b, b-a+1 -countn(a,b, pp));
    }
    return 0;
}
