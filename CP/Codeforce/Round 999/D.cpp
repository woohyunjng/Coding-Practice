#include <bits/stdc++.h>
#define int long long

#define MAX 300000
using namespace std;

int A[MAX], B[MAX];
map<int, int> cnt;

void solve() {
    int N, M, K, V = 0;
    vector<int> X;

    bool res = false;

    cin >> N >> M;

    cnt.clear();
    for (int i = 1; i <= N; i++)
        cin >> A[i], cnt[A[i]]++;
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        if (cnt[B[i]])
            cnt[B[i]]--, V++;
        else
            X.push_back(B[i]);
    }

    while (!X.empty() && M <= N && V < N) {
        K = X.back(), X.pop_back();
        if (cnt[K])
            cnt[K]--, V++;
        else
            X.push_back(K / 2), X.push_back(K - K / 2), M++;
    }

    res = V == N;
    cout << (res ? "Yes" : "No") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}