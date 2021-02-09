#include <iostream>
#include "vector"
using namespace std;

// The goal in this problem is to find the minimum number of coins needed to change the input value
//(an integer) into coins with denominations 1, 5, and 10.
int get_change(int m);

int main() {

    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';

    return 0;
}

int get_change(int m)
{
    vector<int> coins = {10, 5, 1};
    int counter = 0;
    for(int i = 0; i <= coins.size() - 1; i++)
        while(m >= coins.at(i)){
            m = m - coins.at(i);
            counter++;
        }
    return counter;
}