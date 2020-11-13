//
//  main.c
//  Stavebnice Merkur
//
//  Created by Евгений on 11/13/20.
//  Copyright © 2020 Евгений. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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


  

int findNumberOfTriangles(long long arr[], int n)
{
    
    int count = 0;
    int am = 0;
  
    
    for (int i = 0; i < n - 1; ++i) {
        
        am++;
        if(arr[i+1] != arr[i]) {
            
        }
  
    }
  
    return count;
}

int main(int argc, const char * argv[]) {
    long long arr[50000];
    long long a;
    int ind = 0;
    char c;
    int result;
    printf("Delky nosniku:\n");
    while ((result = (scanf("%lld", &a))) != EOF) {
        if(scanf("%c", &c) == 1 && c != ' ' && c != '\n') {
            printf("Nespravny vstup.\n");
            return 1;
        }
        if (a<=0) {
            printf("Nespravny vstup.\n");
            return 1;
        }
        arr[ind] = a;
        ind++;
    }
    arr[ind] = -1;
    if(ind<3) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    quicksort(arr, 0,ind-1);
    
    return 0;
}
