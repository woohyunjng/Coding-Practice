#include <bits/stdc++.h>
#define int long long

#define MAX 200000
using namespace std;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, X, res;
    vector<int> arr;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i])
            arr.push_back(i);
    }

    cin >> Q;
    while (Q--) {
        cin >> L >> R, res = 0;
        X = upper_bound(arr.begin(), arr.end(), R) - arr.begin() - 1;
        if (X < 0 || arr[X] < L)
            res = R - L + 1;
        else
            res = R - arr[X];
        res = (res & 1) ^ 1;
        cout << res << '\n';
    }

    return 0;
}