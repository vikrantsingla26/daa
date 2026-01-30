#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
using namespace std;

struct Point {
    int x, y;
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(vector<Point>& P, int l, int r) {
    double minDist = DBL_MAX;
    for (int i = l; i <= r; i++)
        for (int j = i + 1; j <= r; j++)
            minDist = min(minDist, dist(P[i], P[j]));
    return minDist;
}

double stripClosest(vector<Point>& strip, double d) {
    double minD = d;
    sort(strip.begin(), strip.end(),
         [](Point a, Point b) { return a.y < b.y; });

    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1; j < strip.size() &&
             (strip[j].y - strip[i].y) < minD; j++)
            minD = min(minD, dist(strip[i], strip[j]));

    return minD;
}

double closestUtil(vector<Point>& P, int l, int r) {
    if (r - l <= 3)
        return bruteForce(P, l, r);

    int mid = (l + r) / 2;
    Point midPoint = P[mid];

    double dl = closestUtil(P, l, mid);
    double dr = closestUtil(P, mid + 1, r);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = l; i <= r; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);

    return min(d, stripClosest(strip, d));
}

int main() {
    vector<Point> P = {
        {9,3},{2,6},{15,3},{5,1},{1,2},{12,4},{7,2},{4,7},
        {16,5},{3,3},{10,5},{6,4},{14,6},{8,6},{11,1},{13,2}
    };

    sort(P.begin(), P.end(),
         [](Point a, Point b) { return a.x < b.x; });

    cout << closestUtil(P, 0, P.size() - 1);
}