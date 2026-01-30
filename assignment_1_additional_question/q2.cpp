#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestGoodSubsequence(vector<int>& A) {
    sort(A.begin(), A.end());
    int l = 0, ans = 0;

    for (int r = 0; r < A.size(); r++) {
        while (A[r] - A[l] > 10)
            l++;
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main() {
    vector<int> A = {1, 5, 6, 7, 12, 13, 14};
    cout << longestGoodSubsequence(A);
}