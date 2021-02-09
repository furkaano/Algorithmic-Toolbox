#include <iostream>
#include <vector>

using namespace std;

//The goal of this problem is to represent a given positive integer 𝑛 as a sum of as many pairwise
//distinct positive integers as possible. That is, to find the maximum 𝑘 such that 𝑛 can be written as
//𝑎1 + 𝑎2 + · · · + 𝑎𝑘 where 𝑎1, . . . , 𝑎𝑘 are positive integers and 𝑎𝑖 ̸= 𝑎𝑗 for all 1 ≤ 𝑖 < 𝑗 ≤ 𝑘.

vector<int> optimal_summands(int n) {
    vector<int> summands;

    for (int i = 1; i <= n; i++) {
        n -= i;
        if (n <= i) {
            summands.push_back(n + i);
        } else if (n == 0) {
            summands.push_back(i);
            break;
        } else {
            summands.push_back(i);
        }
    }

    return summands;
}

int main() {
    int n;
    cin >> n;
    vector<int> summands = optimal_summands(n);
    cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        cout << summands[i] << ' ';
    }
}