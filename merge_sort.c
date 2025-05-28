#include <stdio.h>
#include <stdlib.h>

// Merge function for merge sort
// 2 hesegt huvaagdsan khusnegt uudig negtgeh function
void merge(int arr[], int left, int mid, int right) {
    int n1=mid-left+1;
    int n2=right-mid;
    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));
    
    // Left, Right 2 tusdaa khusnegt uusgeh
    for (int i=0; i<n1; i++)
        L[i]=arr[left+i];
    for (int j=0; j<n2; j++)
        R[j]=arr[mid+1+j];
    
    int i=0, j=0, k=left;
    // 2 khusnegtee haritsuulj, baga utgatai elementiig khiikh
    while (i<n1 && j<n2) {
        if (L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    
    // Left khusnegt dotor uldsen elementuudig nemj oruulah
    while (i<n1) {
        arr[k]=L[i];
        i++;
        k++;
    }
    
    // Right khusnegt dotor uldsen elementuudig nemj oruulah
    while (j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// Merge sort function
// Recursive merge sort function - khusnegtee 2 hesegt huvaagaad erembeleh
void mergeSort(int arr[], int left, int right) {
    if (left<right) {
        int mid=left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n); // Hereglegchees elementiig too oruulah
    int *arr=(int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]); // Khusnegt dotorh elementuudig oruulah
    
    mergeSort(arr, 0, n-1); // Merge sort ashiglan erembeleh
    
    // Erembelegdsen khusnegtee hewleh
    for (int i=0; i<n; i++) {
        if (i>0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}
