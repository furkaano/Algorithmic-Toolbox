#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;

// The goal of this problem is to implement the algorithm for computing the edit distance between two
//strings.

int edit_distance(const string &str1, const string &str2) {
    int size1 = str1.size();
    int size2 = str2.size();

    vector< vector<int> > d(size1 + 1, vector<int>(size2 + 1, 0));
    for(int i = 0; i <= size1; ++i) {
        d[i][0] = i;
    }
    for(int i = 0; i <= size2; ++i) {
        d[0][i] = i;
    }

    int cost;
    for(int i = 1; i <= size1; ++i) {
        for(int j = 1; j <= size2; ++j) {
            if(str1[i-1] == str2[j-1])
                cost = 0;
            else
                cost = 1;
            d[i][j] = min(min(d[i-1][j],d[i][j-1]) + 1, d[i-1][j-1] + cost);
        }
    }

    return d[size1][size2];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
