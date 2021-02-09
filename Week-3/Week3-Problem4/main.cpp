#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//Problem Introduction
//You have 𝑛 ads to place on a popular Internet page. For each ad, you know how
//much is the advertiser willing to pay for one click on this ad. You have set up 𝑛
//slots on your page and estimated the expected number of clicks per day for each
//slot. Now, your goal is to distribute the ads among the slots to maximize the
//total revenue.

long long max_dot_product(vector<int> a, vector<int> b);

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << max_dot_product(a, b) << endl;
    return 0;
}

long long max_dot_product(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        result += ((long long) a[i]) * b[i];
    }
    return result;
}