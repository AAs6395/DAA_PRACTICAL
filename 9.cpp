#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool hasDuplicates(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return true;  
        }
    }
    return false; 
}

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int n;  
        cin >> n;
      vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (hasDuplicates(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
