#include <iostream>
#include <vector>

using namespace std;

//Compute the length of a longest common subsequence of three sequences.

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {

    vector<vector<vector<int>>> d(a.size()+1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1, 0)));

    for(size_t i = 0; i < a.size(); i++)
        for(size_t j = 0; j < b.size(); ++j)
            for(size_t k = 0; k < c.size(); ++k)
                if(a[i] == b[j] && b[j] == c[k])
                    d[i+1][j+1][k+1] = d[i][j][k] + 1;
                else
                    d[i+1][j+1][k+1] = max(max(d[i][j+1][k+1], d[i+1][j][k+1]), d[i+1][j+1][k]);
    return d[a.size()][b.size()][c.size()];
}

int main() {
    size_t an;
    cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        cin >> a[i];
    }
    size_t bn;
    cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        cin >> b[i];
    }
    size_t cn;
    cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        cin >> c[i];
    }
    cout << lcs3(a, b, c) << endl;
}
