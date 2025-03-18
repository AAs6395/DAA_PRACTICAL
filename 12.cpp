#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int partition(vector<int>& arr, int low, int high, int pivotIndex) {
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); 
    int n = low;
    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[n]);
            n++;
        }
    }
    swap(arr[n], arr[high]);
    return n;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) return arr[low];
    int pivotIndex = low + (high - low) / 2;
    pivotIndex = partition(arr, low, high, pivotIndex);
    if (k == pivotIndex) return arr[k];
    else if (k < pivotIndex) return quickSelect(arr, low, pivotIndex - 1, k);
    else return quickSelect(arr, pivotIndex + 1, high, k);
}

int findKthElement(vector<int>& arr, int k) {
    int n = arr.size();
    if (k < 1 || k > n) return INT_MIN; 
    return quickSelect(arr, 0, n - 1, k - 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;
        
        int result = findKthElement(arr, k);
        if (result == INT_MIN)
            cout << "not present" << endl;
        else
            cout << result << endl;
    }
    return 0;
}
