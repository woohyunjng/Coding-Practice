#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, X, ans;
    vector<int> arr;

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> S[i + 1], arr.push_back(S[i + 1]);
        S[i + 1] += S[i];
    }

    while (Q--) {
        cin >> L >> R, ans = 0;
        L = lower_bound(arr.begin(), arr.end(), L) - arr.begin() + 1;
        R = upper_bound(arr.begin(), arr.end(), R) - arr.begin();

        ans = max(S[R] - S[L - 1] - (S[L] - S[L - 1]) * (R - L + 1), (S[R] - S[R - 1]) * (R - L + 1) - (S[R] - S[L - 1]));
        ans -= (S[R] - S[(L + R) / 2]) - (S[(L + R - 1) / 2] - S[L - 1]);

        ans = L > R ? 0 : ans;
        cout << ans << '\n';
    }

    return 0;
}