#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

int A[MAX];

void solve() {
    int N, V;
    bool ans = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1);

    vector<int> arr;

    for (int i = 2; i <= N; i++) {
        if (A[i] % A[1] == 0)
            arr.push_back(A[i]);
    }

    ans &= arr.size() > 0;
    if (!arr.empty()) {
        V = arr[0];
        for (int i = 1; i < arr.size(); i++)
            V = gcd(V, arr[i]);
        ans &= V == A[1];
    }

    cout << (ans ? "YES" : "NO") << '\n';
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