#include <iostream>
#include <vector>

using namespace std;

// Compute the length of a longest common subsequence of two sequences.

int lcs2(vector<int> &a, vector<int> &b) {
    //write your code here
    vector<vector<int>> c(a.size() + 1, vector<int>(b.size() + 1, 0));

    for(size_t i = 0; i < a.size(); ++i)
        for (size_t j = 0; j < b.size(); ++j)
            if(a[i] == b[j])
                c[i+1][j+1] = c[i][j] + 1;
            else
                c[i+1][j+1] = max(c[i][j+1], c[i+1][j]);

    return c[a.size()][b.size()];
}

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    size_t m;
    cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << lcs2(a, b) << std::endl;
}

