#include <iostream>
#include <vector>
using namespace std;
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if the target is not found
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 3;
    int index = linearSearch(arr, target);
    
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}