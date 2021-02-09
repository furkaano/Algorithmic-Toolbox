#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// The goal in this code problem is to implement the binary search algorithm.

int binary_search(const vector<int> &a, int x) {
    long long left = 0;
    long long right = (int)a.size() - 1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (x == a[mid])
        {
            return mid;
        }
        if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    //write your code here
    // int mid = left + right / 2;
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        cout << binary_search(a, b[i]) << ' ';
        //cout << linear_search(a, b[i]) << ' ';
    }
}
