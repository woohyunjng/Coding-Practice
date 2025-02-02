#include <bits/stdc++.h>
#define int long long

#define MAX 100
using namespace std;

void solve() {
    int N, X;
    vector<int> A, B;
    bool ans = true;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X, A.push_back(X);
    sort(A.begin(), A.end()), A.erase(unique(A.begin(), A.end()), A.end());

    for (int i = 1; i <= N; i++)
        cin >> X, B.push_back(X);
    sort(B.begin(), B.end()), B.erase(unique(B.begin(), B.end()), B.end());

    ans = (int)A.size() * (int)B.size() >= 3;
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