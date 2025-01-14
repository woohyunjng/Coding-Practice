#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<string, string> pr;

map<pr, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    string S, A, B;

    cin >> N >> S;

    for (int i = 0; i < (1 << N); i++) {
        A = B = "";
        for (int j = 0; j < N; j++) {
            if (i & (1 << j))
                A += S[j];
            else
                B += S[j];
        }
        cnt[{A, B}]++;
    }

    S = S.substr(N);
    reverse(S.begin(), S.end());

    for (int i = 0; i < (1 << N); i++) {
        A = B = "";
        for (int j = 0; j < N; j++) {
            if (i & (1 << j))
                A += S[j];
            else
                B += S[j];
        }
        res += cnt[{A, B}];
    }

    cout << res << '\n';

    return 0;
}