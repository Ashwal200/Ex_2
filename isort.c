#include <stdio.h>
#include <stdlib.h>

#define SIZE 50



void print(int arr[]){
    for (int i = 0; i < SIZE; i++)
    {
        if (i == 0)
        {
            printf("%d" , arr[0]);
        }
        printf(",%d" , arr[i]);
        if (i==24)
        {
            printf("\n");
        }
        
    }
    printf("\n");
}


void shift_element(int* arr, int i){
    for (int k = i ; k > 0; k--)
        {   
            *(arr+k) = *(arr +k-1);
        } 
}

void insertion_sort(int* arr , int len){
    int* ptr = arr;
    for (int j = 1; j < len; j++)
    {
        int key = *(ptr+j);
        int i = j-1;
        
        while (i>=0 && *(ptr+i) > key)
        {
            shift_element((ptr+i) , 1);
            i--;
        }
        *(arr+i+1) = key;
        
       
    }
    

}


int main(){

    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d" , & arr[i]);
    }
    int* ptr = arr;
    insertion_sort(ptr , SIZE);
    print(arr);
}