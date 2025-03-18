#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int key, int &comparisons) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;  

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

int main() {
    int n, key, comparisons = 0;
    
    cout << "Enter size of array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter key to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key, comparisons);
    if (result != -1)
        cout << "Key found at index " << result << endl;
    else
        cout << "Key not found in array" << endl;

    cout << "Total comparisons: " << comparisons << endl;

    return 0;
}
