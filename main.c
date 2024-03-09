#include <stdio.h>

void printArray(int arr[], int size, int count[])
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d: %d\n", arr[i], count[arr[i]]);
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    printf("\narray1 bubble sort:\n");
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int count[max + 1];
    int total_swaps = 0;
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        int swaps = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            { //then swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                total_swaps++;
            }
            count[arr[j]]++;
        }
        printf("Iteration %d: Swaps = %d\n", i + 1, swaps);
    }
    printf("Total Swaps = %d\n", total_swaps);
    printArray(arr, n, count);
}

void selectionSort(int arr[], int n)
{
    printf("\narray1 selection sort:\n");
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int count[max + 1];
    int total_swaps = 0;
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        int swaps = 0;
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        swaps++;
        total_swaps++;

        count[arr[i]]++;
        printf("Iteration %d: Swaps = %d\n", i + 1, swaps);
    }
    printf("Total Swaps = %d\n", total_swaps);
    printArray(arr, n, count);
}

int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    bubbleSort(array1, n1);
    bubbleSort(array2, n2);

    selectionSort(array1, n1);
    selectionSort(array2, n2);

    return 0;
}
