#include <iostream>
#include <vector>
#include <algorithm>

#define MIN(a,b) (a<b ? a:b)

using namespace std;

// Given an integer 𝑛, compute the minimum number of operations needed to obtain the number 𝑛
//starting from the number 1.

vector<int> optimal_sequence(int n) {
    vector<int> sequence;
    vector<int>  a(n+1);
    for(int i =1; i< a.size(); i++)
    {
        a[i] = a[i-1] + 1;
        if (i%2 == 0)
            a[i] = MIN(1 + a[i/2], a[i]);
        if (i%3 == 0)
            a[i] = MIN(1 + a[i/3], a[i]);
    }

    int i = n;
    while (i>=1) {
        sequence.push_back(i);
        if (a[i-1] == a[i]-1)
            i = i-1;
        else if (i%2 == 0 && (a[i/2] == a[i]-1))
            i = i/2;
        else if (i%3 == 0 && (a[i/3] == a[i]-1))
            i = i/3;
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence = optimal_sequence(n);
    cout << sequence.size() - 1<< std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
    }
}