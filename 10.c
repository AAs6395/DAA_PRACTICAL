#include <stdio.h>

int comparisons = 0, inversions = 0;  
void print(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge(int A[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1; 
    int k = low;
    int B[high + 1];  

    while (i <= mid && j <= high) {
        comparisons++;  
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
            inversions += (mid - i + 1);  
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}
void mergesort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    int T;
    scanf("%d", &T);  

    while (T--) {
        int n;
        scanf("%d", &n);  
        int A[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        comparisons = 0;
        inversions = 0;
        mergesort(A, 0, n - 1);
        print(A, n);
        printf("Comparisons = %d\n", comparisons);
        printf("Inversions = %d\n", inversions);
    }

    return 0;
}
