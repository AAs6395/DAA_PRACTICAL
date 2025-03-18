#include <iostream>
#include <vector>
using namespace std;

void findSequence(const vector<int>& arr, int n) {
    bool found = false;
    
    // Iterate for each possible k (the last element in the equation arr[i] + arr[j] = arr[k])
    for (int k = 2; k < n; ++k) {
        int i = 0, j = k - 1;
        
        // Use two pointers to find i and j such that arr[i] + arr[j] = arr[k]
        while (i < j) {
            int sum = arr[i] + arr[j];
            
            if (sum == arr[k]) {
                cout << i + 1 << ", " << j + 1 << ", " << k + 1 << endl;  // Output indices in 1-based index
                found = true;
                break;
            } else if (sum < arr[k]) {
                ++i;  // Increase i if the sum is smaller than arr[k]
            } else {
                --j;  // Decrease j if the sum is greater than arr[k]
            }
        }
        
        if (found) break;  // If we found a solution, stop the search
    }
    
    if (!found) {
        cout << "No sequence found" << endl;  // No sequence was found
    }
}

int main() {
    int T;
    cin >> T;  // Number of test cases
    
    while (T--) {
        int n;
        cin >> n;  // Size of the array
        vector<int> arr(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];  // Array elements
        }
        
        findSequence(arr, n);  // Find and print the sequence (if any)
    }
    
    return 0;
}
