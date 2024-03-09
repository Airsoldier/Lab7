//Matthew Cardona
//Lab 7

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
    int numswaps;
} element;

element* numSwapsBubbleSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element) * size);
    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (swaps[j].data > swaps[j + 1].data) {
                // Swap elements
                element temp = swaps[j];
                swaps[j] = swaps[j + 1];
                swaps[j + 1] = temp;

                // Increment swap count for the swapped elements
                swaps[j].numswaps++;
                swaps[j + 1].numswaps++;
            }
        }
    }

    return swaps;
}

element* numSwapsSelectionSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element) * size);
    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (swaps[j].data < swaps[min_index].data) {
                min_index = j;
            }
        }

        // Swap elements
        element temp = swaps[i];
        swaps[i] = swaps[min_index];
        swaps[min_index] = temp;

        // Increment swap count for the swapped elements
        swaps[i].numswaps++;
        swaps[min_index].numswaps++;
    }

    return swaps;
}

void printSwaps(element* swaps, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", swaps[i].data, swaps[i].numswaps);
    }

    int totalSwaps = 0;
    for (int i = 0; i < size; i++) {
        totalSwaps += swaps[i].numswaps;
    }

    printf("Total # of swaps: %d\n\n", totalSwaps / 2);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    printf("array1 (Bubble Sort):\n");
    element* swaps1_bubble = numSwapsBubbleSort(array1, size1);
    printSwaps(swaps1_bubble, size1);

    printf("array2 (Bubble Sort):\n");
    element* swaps2_bubble = numSwapsBubbleSort(array2, size2);
    printSwaps(swaps2_bubble, size2);

    printf("array1 (Selection Sort):\n");
    element* swaps1_selection = numSwapsSelectionSort(array1, size1);
    printSwaps(swaps1_selection, size1);

    printf("array2 (Selection Sort):\n");
    element* swaps2_selection = numSwapsSelectionSort(array2, size2);
    printSwaps(swaps2_selection, size2);

    free(swaps1_bubble);
    free(swaps2_bubble);
    free(swaps1_selection);
    free(swaps2_selection);

    return 0;
}
