#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int X[MAX], Y[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, K;
    vector<int> A, B;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        A.push_back(Y[i] - X[i]), B.push_back(X[i] + Y[i]);
    }

    sort(A.begin(), A.end()), A.erase(unique(A.begin(), A.end()), A.end());
    sort(B.begin(), B.end()), B.erase(unique(B.begin(), B.end()), B.end());

    ans = A.size() + B.size();
    for (int i : A) {
        K = lower_bound(B.begin(), B.end(), -i) - B.begin();
        if (K < B.size() && B[K] == -i)
            ans--;
        ans += B.end() - upper_bound(B.begin(), B.end(), -i);
    }

    cout << ans << '\n';

    return 0;
}