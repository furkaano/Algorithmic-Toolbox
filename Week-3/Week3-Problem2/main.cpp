#include <iostream>
#include <algorithm>
#include <iomanip>
#include "vector"

using namespace std;

//The goal of this code problem is to implement an algorithm for the fractional knapsack problem.

double get_optimal_value(double capacity, vector<double> weights, vector<double> values);

int main() {
    int n;
    double capacity;
    cin >> n >> capacity;
    vector<double> values(n);
    vector<double> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout<<fixed<<setprecision(10)<<optimal_value; // ad decimal point how many you want
    return 0;
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values)
{
    double value = 0.0;
    int n = weights.size();

    // this is for sorting and decreasing big-o from n^2 to n.log(n)
    vector< pair<double, double> > fk;
    for (int i = 0; i < n; i++)
        fk.push_back(make_pair(values[i] / weights[i], weights[i]));

    sort(fk.begin(), fk.end());

    int i = n - 1;
    while(capacity > 0 && i >= 0){
        if (fk[i].second >= capacity) {
            // add fractional quantity
            value += (double)(fk[i].first * capacity);
            capacity = 0.0;
            break;
        } else {
            // add everything
            value += (double)(fk[i].first * fk[i].second);
            capacity -= (fk[i].second);
        }
        i--;
    }
    return value;
}