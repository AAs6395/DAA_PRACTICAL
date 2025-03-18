#include <iostream>
#include <unordered_set>
using namespace std;

void countPairsWithDifference(int arr[], int n, int K) {
    unordered_set<int> elements;
    int count = 0;

    // Insert all elements into the set
    for (int i = 0; i < n; i++) {
        elements.insert(arr[i]);
    }

    // Check for each element if (arr[i] + K) exists in the set
    for (int i = 0; i < n; i++) {
        if (elements.find(arr[i] + K) != elements.end()) {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    int T; 
    cin >> T;  // Number of test cases

    while (T--) {
        int n, K;
        cin >> n; // Size of array
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Input array elements
        }

        cin >> K; // Input key difference

        countPairsWithDifference(arr, n, K);
    }

    return 0;
}
