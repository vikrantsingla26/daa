#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> A = {1, 2, 3, 4, 5};

    sort(A.begin(), A.end());
    int n = A.size();

    cout << A[n-1] + A[n-2];
}