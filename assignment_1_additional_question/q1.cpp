#include <iostream>
#include <vector>
using namespace std;

bool canDivide(vector<int>& A, int M, int maxOR) {
    int segments = 1;
    int currOR = 0;

    for (int x : A) {
        if ((currOR | x) <= maxOR) {
            currOR |= x;
        } else {
            segments++;
            currOR = x;
        }
    }
    return segments <= M;
}

int minimizeMaxOR(vector<int>& A, int M) {
    int low = 0, high = 0;
    for (int x : A) high |= x;

    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canDivide(A, M, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    int M = 2;
    cout << minimizeMaxOR(A, M);
}