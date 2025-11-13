#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int S[MAX], T[MAX], V[MAX];

void solve() {
    int N, K_max, X;
    bool chk = true;

    string _S, _T, K;
    vector<string> ans;

    vector<int> arr, tmp;

    cin >> N >> K_max, X = N;
    cin >> _S >> _T;

    fill(V, V + N + 1, 0);
    for (int i = 1; i <= N; i++)
        S[i] = _S[i - 1] - 'a' + 1, T[i] = _T[i - 1] - 'a' + 1;

    for (int i = N; i >= 1; i--) {
        while (X >= 1 && S[X] != T[i])
            X--;
        V[X] = max(V[X], i), chk &= X > 0, X = min(X, i - 1);
    }

    for (int i = 1; i <= N; i++) {
        if (V[i] == 0)
            continue;
        V[i] -= i, chk &= V[i] <= K_max;
        if (V[i])
            arr.push_back(i);
    }

    if (!chk) {
        cout << -1 << '\n';
        return;
    }

    while (!arr.empty()) {
        tmp = arr, arr.clear(), K = "";
        sort(tmp.rbegin(), tmp.rend());
        for (int i : tmp) {
            S[i + 1] = S[i];
            if (V[i] > 1)
                arr.push_back(i + 1), V[i + 1] = V[i] - 1;
        }

        for (int i = 1; i <= N; i++)
            K += (char)(S[i] + 'a' - 1);
        ans.push_back(K);
    }

    cout << ans.size() << '\n';
    for (string i : ans)
        cout << i << '\n';
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