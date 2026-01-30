#include <iostream>
#include <vector>
using namespace std;

int specialty(vector<int>& A, int k) {
    int n = A.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        vector<int> pref(n + 1, 0);
        for (int j = 0; j < n; j++)
            pref[j + 1] = pref[j] + (A[j] > A[i]);

        bool ok = false;
        for (int l = 0; l < n && !ok; l++) {
            for (int r = l + 1; r <= n; r++) {
                if (pref[r] - pref[l] == k) {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) sum += A[i];
    }
    return sum;
}

int main() {
    vector<int> A = {1, 3, 2, 5, 4};
    int k = 2;
    cout << specialty(A, k);
}