#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> get_pi(vector<int> P) {
    int size = P.size(), j = 0;
    vector<int> pi(size, 0);

    for (int i = 1; i < size; i++) {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }
    return pi;
}

bool kmp(vector<int> S, vector<int> P, vector<int> pi) {
    bool ans = false;
    int S_size = S.size(), P_size = P.size(), j = 0;

    for (int i = 0; i < S_size; i++) {
        while (j > 0 && S[i] != P[j])
            j = pi[j - 1];
        if (S[i] == P[j]) {
            if (j == P_size - 1) {
                ans = true;
                break;
            } else
                j++;
        }
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, A;
    bool res = false, val;
    cin >> N >> K;

    vector<vector<int>> v(N + 1), pi(N + 1);
    vector<int> S;

    for (int i = 1; i <= N; i++) {
        cin >> M;
        for (int j = 1; j <= M; j++) {
            cin >> A;
            v[i].push_back(A);
        }
        pi[i] = get_pi(v[i]);
    }

    for (int i = 0; i <= v[1].size() - K; i++) {
        S.clear();
        for (int j = 0; j < K; j++)
            S.push_back(v[1][i + j]);
        val = true;
        for (int i = 2; i <= N; i++) {
            val = val && (kmp(v[i], S, pi[i]) || kmp(vector<int>(v[i].rbegin(), v[i].rend()), S, pi[i]));
        }
        res = res || val;
    }

    cout << (res ? "YES" : "NO");

    return 0;
}