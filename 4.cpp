#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search and find the first or last occurrence of the key
int binarySearch(const vector<int>& arr, int key, bool findFirst) {
    int low = 0, high = arr.size() - 1;
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            result = mid;
            if (findFirst) {
                high = mid - 1;  // Move left to find the first occurrence
            } else {
                low = mid + 1;  // Move right to find the last occurrence
            }
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

// Function to count the occurrences of the key in the sorted array
int countOccurrences(const vector<int>& arr, int key) {
    // Find the first and last occurrence of the key
    int firstIndex = binarySearch(arr, key, true);
    if (firstIndex == -1) {
        return 0;  // Key not found
    }
    
    int lastIndex = binarySearch(arr, key, false);
    return lastIndex - firstIndex + 1;
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cout<<"enter the no";
        cin >> n;  // Size of array
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];  // Array elements
        }
        cout<<"enter the key to be searched ";
        int key;
        cin >> key;  // Key element to search
        
        // Count occurrences of the key element
        int count = countOccurrences(arr, key);
        
        if (count > 0) {
            cout << key << " - " << count << endl;  // Output key and its count
        } else {
            cout << "Key not present" << endl;  // If key is not present
        }
    }
    
    return 0;
}
