#include <iostream>
#include <limits>

using namespace std;

// Money Change Again

int get_change(int m) {
    int coins[] = {1, 3, 4};
    int MinNumCoins[m + 1];
    MinNumCoins[0] = 0;
    int NumCoins;

    for(int i = 1; i <= m; i++){
        MinNumCoins[i] = 9999999;
        for(int j = 0; j < 3; j++)
            if(i >= coins[j]){
                NumCoins = MinNumCoins[i - coins[j]] + 1;
                if(NumCoins < MinNumCoins[i])
                    MinNumCoins[i] = NumCoins;
            }
    }
    return MinNumCoins[m];
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
