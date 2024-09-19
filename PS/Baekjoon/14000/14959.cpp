#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res = INF, res_k, res_p, X;
    string S = "", A;
    vector<int> pi;

    cin >> N;

    res = N, res_k = N - 1, res_p = 1;

    for (int i = 0; i < N; i++) {
        cin >> A;
        while (A.size() < 6)
            A = '0' + A;

        S += A;
        if (i < N - 1)
            S.push_back('.');
    }

    reverse(S.begin(), S.end());

    K = S.size();
    pi.resize(K, 0);

    for (int i = 1, j = 0; i < K; i++) {
        while (j > 0 && S[i] != S[j])
            j = pi[j - 1];
        if (S[i] == S[j])
            pi[i] = ++j;
    }

    for (int i = 1; i <= N; i++) {
        if (pi[6 * i + (i - 1) - 1] >= 6) {
            X = (pi[6 * i + (i - 1) - 1] + 1) / 7;
            if (res > i - X + N - i) {
                res = N - X;
                res_k = N - i;
                res_p = i - X;
            }
        }
    }

    cout << res_k << ' ' << res_p;

    return 0;
}