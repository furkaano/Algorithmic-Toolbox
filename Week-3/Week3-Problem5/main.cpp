#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

//Problem Introduction
//You are responsible for collecting signatures from all tenants of a certain building.
//For each tenant, you know a period of time when he or she is at home.
//You would like to collect all signatures by visiting the building as few times as
//possible.
//The mathematical model for this problem is the following. You are given a set
//of segments on a line and your goal is to mark as few points on a line as possible
//so that each segment contains at least one marked point.

using namespace std;

struct Segment {
    int start, end;
};

bool compare(struct Segment a , struct Segment b)
{
    return a.end < b.end; // It checks end and then compare
}

vector<int> optimal_points(vector<Segment> &segments) {
    /*
    cout << "BEFORE THE SORT" << endl;
    for (int i = 0; i < segments.size(); ++i) {
        cout << segments[i].start << " ";
        cout << segments[i].end;
        cout << "\n";
    }

    sort(segments.begin() , segments.end() , compare);
    /*
    cout << "AFTER THE SORT" << endl;
    for (int i = 0; i < segments.size(); ++i) {
        cout << segments[i].start << " ";
        cout << segments[i].end;
        cout << "\n";
    }
    */
    vector<int> points;
    sort(segments.begin() , segments.end() , compare);
    int point = segments[0].end;
    points.push_back(point);

    for (int i = 1; i < segments.size(); ++i)
        if (point < segments[i].start || point > segments[i].end)
        {
            point = segments[i].end;
            points.push_back(point);
        }
    return points;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].start >> segments[i].end;
    }

    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
}
