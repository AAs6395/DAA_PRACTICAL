#include<iostream>
using namespace std;

void linearsearch(int arr[], int n, int key) {
    int comparisons = 0;
    bool found = false;  
for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            found = true;  
            break;         
        }
    }
    
    if (found) {
        cout << "Present " << comparisons << endl;  
    } else {
        cout << "Not present " << comparisons << endl;  
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;
    
    linearsearch(arr, n, key);
    
    return 0;
}
