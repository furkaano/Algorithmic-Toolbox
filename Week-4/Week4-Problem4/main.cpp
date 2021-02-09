#include <iostream>
#include <vector>

using std::vector;

// The goal in this problem is to count the number of inversions of a given sequence.

int merge_count(vector<int> &arr, vector<int> &aux, size_t low, size_t mid, size_t high){
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;

    // While there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
            inversionCount += (mid - i); // NOTE
        }
    }

    // Copy remaining elements
    while (i <= mid)
        aux[k++] = arr[i++];

    // Don't need to copy second half

    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++)
        arr[i] = aux[i];

    return inversionCount;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    long long number_of_inversions = 0;
    if (right <= left + 1)
        return number_of_inversions;
    size_t middle = (right + left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, middle);
    number_of_inversions += get_number_of_inversions(a, b, middle + 1, right);
    number_of_inversions += merge_count(a, b, left, middle, right);
    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
