#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, S = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) {
        bool xv = A[x] <= B[x], yv = A[y] <= B[y];
        if (xv != yv)
            return xv;
        else if (!xv)
            return B[x] > B[y];
        else
            return A[x] <= A[y];
    });

    for (int i : arr)
        ans += max(0ll, A[i] - S), S = max(S - A[i], 0ll) + B[i];

    cout << ans << '\n';

    return 0;
}