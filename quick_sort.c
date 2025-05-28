#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap khiikh funkts
void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Tulkhuur elementiig sanamsargui songokh (Randomized Partition)
int randomizedPartition(int arr[], int low, int high) {
    srand(time(NULL)); //Sanamsargui utga uusgegchiig ekhluulekh
    int randomIndex = low+rand()%(high-low+1);
    swap(&arr[randomIndex], &arr[high]); //Sanamsargui elementiig suuld bairluulna

    int pivot=arr[high];
    int i=low-1;

    for (int j=low; j<high; j++) {
        if (arr[j]<pivot) { 
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// Quick Sort 
void quickSort(int arr[], int low, int high) {
    if (low<high) {
        int pi=randomizedPartition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int n;
    
    // Oroltiin buruu esekhiig shalgakh
    if (scanf("%d", &n)!=1 || n <= 0) {
        printf("Error: Zubkhun eyreg bukhel too oruulna uu.\n");
        return 1;
    }

    //Dinamic sanakh oig ashiglakh
    int *arr=(int *)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("Sankah oi usgekh uyd aldaa garlaa\n");
        return 1;
    }
    for (int i=0; i<n; i++) {
        if (scanf("%d", &arr[i])!=1) {
            printf("Error: Zubkhun bukhel too oruulna uu.\n");
            free(arr);
            return 1;
        }
    }

    quickSort(arr, 0, n-1);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); //Sanakh oig chuluulukh
    return 0;
}
