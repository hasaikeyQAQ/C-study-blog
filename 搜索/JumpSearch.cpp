#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);  // 最优步长
    
    int prev = 0;
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    
    // 在区间内线性搜索
    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n)) return -1;
    }
    
    return (arr[prev] == target) ? prev : -1;
}

int main() {
    vector<int> data = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int target = 55;
    
    int index = jumpSearch(data, target);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}