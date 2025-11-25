#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, M, X;
    bool ans = true;

    string S, res = "";
    char C;

    cin >> N >> K >> M >> S, X = M;

    vector<int> arr[26];

    for (int i = 0; i < K; i++)
        arr[i].push_back(-1);
    for (int i = 0; i < M; i++)
        arr[S[i] - 'a'].push_back(i);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++)
            if (arr[j].back() < X)
                X = arr[j].back(), C = 'a' + j;
        res += C;

        for (int j = 0; j < K; j++) {
            while (!arr[j].empty() && arr[j].back() >= X)
                arr[j].pop_back();
        }

        if (X < 0) {
            ans = false;
            break;
        }
    }

    while (res.size() < N)
        res += 'a';
    reverse(res.begin(), res.end());

    cout << (ans ? "YES" : "NO") << '\n';
    if (!ans)
        cout << res << '\n';
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