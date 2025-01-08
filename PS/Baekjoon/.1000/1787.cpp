#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
using namespace std;

int pi[MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, j = 0, ans = 0, X = 0;
    string S;

    cin >> N >> S;

    for (int i = 1; i < N; i++) {
        while (j > 0 && S[i] != S[j])
            j = pi[j - 1];
        if (S[i] == S[j]) {
            pi[i] = ++j, res[i] = pi[i];
            if (res[res[i] - 1])
                res[i] = res[res[i] - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        if (res[i])
            ans += i + 1 - res[i];
    }

    cout << ans << '\n';

    return 0;
}