#include <iostream>
#include <cstdlib> 
using namespace std;

int comparisons = 0, swaps = 0;
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    swaps++;
    int temp = a;
    a = b;
    b = temp;
}
int partition(int A[], int low, int high) {
    // Random pivot selection
    int randomIndex = low + rand() % (high - low + 1);
    swap(A[randomIndex], A[high]); 

    int pivot = A[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        comparisons++; 
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]); 
        }
    }
    swap(A[i + 1], A[high]); 
    return i + 1; 
}
void quickSort(int A[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main() {
    int T;
    cin >> T; 
    
    while (T--) {
        int n;
        cin >> n; 
        int A[n];

        for (int i = 0; i < n; i++)
            cin >> A[i]; 

        comparisons = swaps = 0; 
        quickSort(A, 0, n - 1);

        printArray(A, n);
        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }
    return 0;
}
