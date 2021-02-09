#include <iostream>
#include <vector>

using namespace std;

// Problem Introduction
//You are going to travel to another city that is located 𝑑 miles away from your home city. Your car can travel
//at most 𝑚 miles on a full tank and you start with a full tank. Along your way, there are gas stations at
//distances stop1, stop2, . . . , stop𝑛 from your home city. What is the minimum number of refills needed?

int compute_min_refills(int dist, int tank, vector<int> & stops);

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;
}

int compute_min_refills(int dist, int tank, vector<int> & stops)
{
    int numRefills = 0;
    int currentRefills = 0;
    int lastRefills;

    while(currentRefills < stops.size() - 1){
        lastRefills = currentRefills;
        while((currentRefills < stops.size() - 1) &&
             ((stops.at(currentRefills + 1) - stops.at(lastRefills)) <= tank))
             currentRefills++;
        if(currentRefills == lastRefills)
            return -1;
        if(currentRefills <= stops.size() - 1)
            numRefills++;
    }
    return numRefills;
}