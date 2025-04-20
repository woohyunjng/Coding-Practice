#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 101;

int ans[MAX];

void solve() {
    int N;
    string S;

    cin >> N >> S;
    ans[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (S[i - 2] == '>')
            ans[i] = i;
        else {
            ans[i] = 0;
            for (int j = 1; j <= i; j++)
                ans[j]++;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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