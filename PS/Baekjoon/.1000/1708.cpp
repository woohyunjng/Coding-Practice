#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

int CCW(pr A, pr B, pr C) { return (A[0] * B[1] + B[0] * C[1] + C[0] * A[1]) - (A[0] * C[1] + B[0] * A[1] + C[0] * B[1]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<pr> arr, upper, lower, hull;
    int N, X, Y;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        arr.push_back({X, Y});
    }

    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        while (upper.size() > 1 && CCW(upper[upper.size() - 2], upper[upper.size() - 1], i) <= 0)
            upper.pop_back();
        upper.push_back(i);
    }

    reverse(arr.begin(), arr.end());

    for (pr i : arr) {
        while (lower.size() > 1 && CCW(lower[lower.size() - 2], lower[lower.size() - 1], i) <= 0)
            lower.pop_back();
        lower.push_back(i);
    }

    hull = upper;
    for (int i = 1; i < lower.size() - 1; i++)
        hull.push_back(lower[i]);

    cout << hull.size() << '\n';

    return 0;
}