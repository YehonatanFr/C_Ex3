#include <stdio.h>

#define SIZE 50

void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);
void printArr(int* arr, int len);

void shift_element(int* arr, int i)
{
    int j =0;
    int temp[i];
    //Copy to temp array the numbers needs to move
    while(j < i)
    {
        *(temp+j) = *(arr + j);
        j++;
    }
    j=1;
    //Move one step right
    while(j<=i)
    {
        *(arr+j) = *(temp+j-1);
        j++;
    }
}

void insertion_sort(int* arr , int len)
{
    int j = 0, key ,count=1;
    for(int i = 0; i<len-1; i++)
    {
        key = *(arr + i);
        j = i+1;

        while(j < len)
        {
            while( *(arr + j) >= key && j < len)
            {
                j++;
                count++;
            }
            if(j < len)
            {
                int temp = *(arr + j);
                shift_element(arr+i, count);
                *(arr +i) = temp;
                key = *(arr + i);
                j++;
                count++;
            }
        }
        count = 1;

    }
}

void printArr(int* arr, int len)
{
    printf("%d",*arr);
    int j = 1;
    while(j < len)
    {
        printf(",%d", *(arr + j));
        j++;
    }
    printf("\n");
}


int main()
{
    int arr[SIZE];

    for(int i = 0; i<SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr,SIZE);
    printArr(arr, SIZE);

    return 0;
}